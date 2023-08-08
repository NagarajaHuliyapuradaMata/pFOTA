

#define ACTIECBD_SOURCE

#include "actIECBD.hpp"
#include "actECTools.hpp"
#include "actECPoint.hpp"
#include "actECLengthInfo.hpp"

#if(VSECPRIM_ACTECBD_GENERIC_ENABLED == STD_ON)

typedef struct{
    VSECPRIM_P2VAR_PARA(actBNDIGIT) ai;
    actECPOINT   Zi;
    actECPOINT   Xi;
    actECPOINT   TP;
}actECBDscratch;

# define thisECU(ws)                                                  (     (ws)->bd.ecuID)
# define leftECU(ws)                                                  ((1u == (ws)->bd.ecuID) ? (ws)->bd.nECUs : ((ws)->bd.ecuID -1u))
# define ecuOff(ecu, ws)                                              (((ws)->bd.nECUs + (ecu) - (ws)->bd.ecuID) % (ws)->bd.nECUs)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC( void )           initScratch  (VSECPRIM_P2VAR_PARA( actECBDscratch ) scratch, VSECPRIM_P2VAR_PARA( actECBDstruct ) ws);

VSECPRIM_LOCAL_FUNC( void )          actECPImport (VSECPRIM_P2VAR_PARA( actECPOINT ) P,
                                                    VSECPRIM_P2CONST_PARA( actU8 ) x,
                                                    VSECPRIM_P2CONST_PARA( actU8 ) y,
                                                    VSECPRIM_P2CONST_PARA( actECCURVE ) curve,
                                                    VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC( actRETURNCODE ) actECPExport (VSECPRIM_P2VAR_PARA( actU8 ) x,
                                                    VSECPRIM_P2VAR_PARA( actU8 ) y,
                                                    VSECPRIM_P2VAR_PARA( actECPOINT ) P,
                                                    VSECPRIM_P2VAR_PARA( actECPOINT )TP,
                                                    VSECPRIM_P2VAR_PARA( actECCURVE ) curve,
                                                    VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC( actRETURNCODE ) actECBDinit (VSECPRIM_P2VAR_PARA( actECBDstruct ) ws,
                     const actLengthType    wsSize,
                     const actU32              nECUs,
                     const actU32              ecuID,
                     VSECPRIM_P2ROMCONST_PARA(actU8) domain,
                     VSECPRIM_P2ROMCONST_PARA(actU8) domainExt,
                     VSECPRIM_P2ROMCONST_PARA(actU8) speedupExt) {
    VSECPRIM_P2VAR_PARA(actECPBasicStruct) ecWS     = &ws->baseData;
    actLengthType ecWSSize = wsSize - sizeof (ws->bd);

    ws->bd.nECUs     = nECUs;
    ws->bd.ecuID     = ecuID;

    return actECInit (domain, domainExt, speedupExt, actEC_ALGO_FLAG_BDKA, ecWS, ecWSSize);
}

VSECPRIM_FUNC( actRETURNCODE ) actECBDgenKeyPair(VSECPRIM_P2VAR_PARA( actECBDstruct ) ws,
                                                 VSECPRIM_P2VAR_PARA( actU8 ) privKey,
                                                 VSECPRIM_P2VAR_PARA( actU8 ) pubKey_x,
                                                 VSECPRIM_P2VAR_PARA( actU8 ) pubKey_y,
                                                 VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
    actECBDscratch  scratch;
    actRETURNCODE   rc;

    if(NULL_PTR == ws){
      return actEXCEPTION_NULL;
    }

    initScratch ((VSECPRIM_P2VAR_PARA( actECBDscratch ))&scratch, ws);

    rc = actBNModRandomize(scratch.ai, &ws->baseData.Curve.n_field, ws->baseData.Curve.t, watchdog);
    if(rc != actOK){
        actBNSetZero (scratch.ai, ws->baseData.Curve.n_field.m_length);
        return rc;
    }

    actECPMultG (scratch.ai, &scratch.TP, &scratch.Zi, &ws->baseData.Curve, watchdog);

    rc = actECPExport (pubKey_x, pubKey_y, &scratch.Zi, NULL_PTR, &ws->baseData.Curve, watchdog);

    if(actOK != rc){
        actBNSetZero (scratch.ai,      ws->baseData.Curve.n_field.m_length);
        actBNSetZero (scratch.Zi.x, (3u*ws->baseData.Curve.p_field.m_length));
    }
    else{
      if(NULL_PTR != privKey)
      {
        actBNOctetString(privKey, ws->baseData.Curve.n_field.m_byte_length, scratch.ai, ws->baseData.Curve.n_field.m_length);
      }
    }

    return rc;
}

VSECPRIM_FUNC( actRETURNCODE ) actECBDcalcXi(VSECPRIM_P2VAR_PARA( actECBDstruct ) ws,
                                             VSECPRIM_P2CONST_PARA( actU8 ) ZiLeft_x,
                                             VSECPRIM_P2CONST_PARA( actU8 ) ZiLeft_y,
                                             VSECPRIM_P2CONST_PARA( actU8 ) ZiRight_x,
                                             VSECPRIM_P2CONST_PARA( actU8 ) ZiRight_y,
                                             VSECPRIM_P2VAR_PARA( actU8 ) Xi_x,
                                             VSECPRIM_P2VAR_PARA( actU8 ) Xi_y,
                                             VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
    actECBDscratch  scratch;
    actRETURNCODE   rc;

    if(NULL_PTR == ws){
      return actEXCEPTION_NULL;
    }

    initScratch (&scratch, ws);

    actECPImport (&scratch.Zi, ZiLeft_x,  ZiLeft_y,  &ws->baseData.Curve, watchdog);

    actECPImport (&scratch.TP, ZiRight_x, ZiRight_y, &ws->baseData.Curve, watchdog);

    actECPSub    (&scratch.TP, &scratch.Zi,              &ws->baseData.Curve, watchdog);
    actECPMult   (&scratch.TP,  scratch.ai, &scratch.Xi, &ws->baseData.Curve, watchdog);

    rc = actECPExport (Xi_x, Xi_y, &scratch.Xi, &scratch.TP, &ws->baseData.Curve, watchdog);
    if(actOK != rc){
        actBNSetZero (scratch.ai,      ws->baseData.Curve.n_field.m_length);
        actBNSetZero (scratch.Zi.x, (6u* ws->baseData.Curve.p_field.m_length));
    }

    actBNSetZero     (scratch.TP.x, (3u* ws->baseData.Curve.p_field.m_length));

    return rc;
}

VSECPRIM_FUNC( actRETURNCODE ) actECBDinitK(VSECPRIM_P2VAR_PARA( actECBDstruct ) ws,
                                            VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)) {
    actECBDscratch  scratch;

    if(NULL_PTR == ws){
      return actEXCEPTION_NULL;
    }

    initScratch (&scratch, ws);

    actECPMult      (&scratch.Zi, scratch.ai,      &scratch.TP, &ws->baseData.Curve, watchdog);
    actECPMultShort (&scratch.TP, ws->bd.nECUs,    &scratch.Zi, &ws->baseData.Curve, watchdog);
    actECPMultShort (&scratch.Xi, (ws->bd.nECUs - 1u), &scratch.TP, &ws->baseData.Curve, watchdog);
    actECPAdd       (&scratch.Zi, &scratch.TP,                  &ws->baseData.Curve, watchdog);

    actBNSetZero (scratch.ai,      ws->baseData.Curve.n_field.m_length);
    actBNSetZero (scratch.Xi.x, (6u* ws->baseData.Curve.p_field.m_length));

    return actOK;
}

VSECPRIM_FUNC( actRETURNCODE ) actECBDupdateK(VSECPRIM_P2VAR_PARA( actECBDstruct ) ws,
                        const actU32         ecuID,
                        VSECPRIM_P2CONST_PARA(actU8) Xi_x,
                        VSECPRIM_P2CONST_PARA(actU8) Xi_y,
                        VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)) {
    actECBDscratch  scratch;
    actU32          tmp;

    if(NULL_PTR == ws){
      return actEXCEPTION_NULL;
    }

    initScratch (&scratch, ws);

    if((ecuID == thisECU(ws))
      || (ecuID == leftECU(ws)))

    {
      return actOK;
    }

    actECPImport (&scratch.Xi, Xi_x,  Xi_y,  &ws->baseData.Curve, watchdog);

    tmp = (ws->bd.nECUs -1u) - ecuOff (ecuID, ws);
    actECPMultShort (&scratch.Xi, tmp, &scratch.TP, &ws->baseData.Curve, watchdog);
    actECPAdd       (&scratch.Zi,      &scratch.TP, &ws->baseData.Curve, watchdog);

    actBNSetZero (scratch.Xi.x, (6u* ws->baseData.Curve.p_field.m_length));

    return actOK;
}

VSECPRIM_FUNC( actRETURNCODE ) actECBDretrieveK (VSECPRIM_P2VAR_PARA( actECBDstruct ) ws,
                                VSECPRIM_P2VAR_PARA(actU8) K_x,
                                VSECPRIM_P2VAR_PARA(actU8) K_y,
                                VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)) {
    actECBDscratch  scratch;
    actRETURNCODE   rc;

    if(NULL_PTR == ws){
      return actEXCEPTION_NULL;
    }

    initScratch (&scratch, ws);

    rc = actECPExport (K_x, K_y, &scratch.Zi, NULL_PTR, &ws->baseData.Curve, watchdog);

    actBNSetZero (scratch.Zi.x, (3u* ws->baseData.Curve.p_field.m_length));

    return rc;
}

VSECPRIM_LOCAL_FUNC( void ) initScratch(VSECPRIM_P2VAR_PARA( actECBDscratch )scratch, VSECPRIM_P2VAR_PARA( actECBDstruct ) ws) {
    scratch->ai = ws->ai;
    scratch->Zi.x = ws->Zi_x;
    scratch->Zi.y = ws->Zi_y;
    scratch->Zi.z = ws->Zi_z;
    scratch->Xi.x = ws->Xi_x;
    scratch->Xi.y = ws->Xi_y;
    scratch->Xi.z = ws->Xi_z;
    scratch->TP.x = ws->TP_x;
    scratch->TP.y = ws->TP_y;
    scratch->TP.z = ws->TP_z;

    scratch->Zi.is_affine = FALSE;
    scratch->Zi.is_infinity = FALSE;
    scratch->Xi.is_affine = FALSE;
    scratch->Xi.is_infinity = FALSE;
}

VSECPRIM_LOCAL_FUNC( void ) actECPImport (VSECPRIM_P2VAR_PARA( actECPOINT ) P, VSECPRIM_P2CONST_PARA( actU8 ) x, VSECPRIM_P2CONST_PARA( actU8 ) y, VSECPRIM_P2CONST_PARA( actECCURVE ) curve, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)) {
    actLengthType pDigits = curve->p_field.m_length;
    actLengthType pBytes  = curve->p_field.m_byte_length;

    actBNSetOctetString (P->x, pDigits, x, pBytes);
    actBNSetOctetString (P->y, pDigits, y, pBytes);
    actBNSetOne         (P->z, pDigits);
    P->is_affine   = FALSE;
    P->is_infinity = FALSE;

    actECPToMont (P, curve, watchdog);
}

VSECPRIM_LOCAL_FUNC( actRETURNCODE ) actECPExport (VSECPRIM_P2VAR_PARA( actU8 ) x, VSECPRIM_P2VAR_PARA( actU8 ) y, VSECPRIM_P2VAR_PARA( actECPOINT ) P, VSECPRIM_P2VAR_PARA( actECPOINT ) TP, VSECPRIM_P2VAR_PARA( actECCURVE ) curve, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actECPOINT) tempPoint;
  actLengthType pDigits = curve->p_field.m_length;
  actLengthType pBytes  = curve->p_field.m_byte_length;

  if(NULL_PTR != TP){
    tempPoint = TP;
    actECPAssign(TP, P, curve, watchdog);
  }
  else{
    tempPoint = P;
  }

  if(actECPToAffineFromMont(tempPoint, curve, 0, watchdog) != actOK){
    return actEXCEPTION_POINT;
  }

  if(NULL_PTR != x){
    actBNOctetString(x, pBytes, tempPoint->x, pDigits);
  }
  if(NULL_PTR != y){
    actBNOctetString(y, pBytes, tempPoint->y, pDigits);
  }

  return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

