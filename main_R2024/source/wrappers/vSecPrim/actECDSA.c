

#define ACTECDSA_SOURCE

#include "actECDSA.hpp"
#include "actECLengthInfo.hpp"

#if(VSECPRIM_ACTECDSA_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actECReduceXModN(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) n,
  actLengthType n_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) x,
  actLengthType p_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) Nval);

VSECPRIM_LOCAL_FUNC(void) actECReduceXModN(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) n,
  actLengthType n_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) x,
  actLengthType p_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) Nval){
  if(p_length >= n_length){
    actBNSetZero(Nval, p_length);
    actBNCopy(Nval, n, n_length);

    while (actBNCompare(x, Nval, p_length) >= actCOMPARE_EQUAL){
       actBNSub(x, Nval, x, p_length);
    }
  }
}

VSECPRIM_FUNC(actRETURNCODE) actECDSAvp(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) e,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) s,
  VSECPRIM_P2CONST_PARA(actECPOINT) Q,
  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp_ptr,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;

   actECPOINT G, QG, point;
   VSECPRIM_P2CONST_PARA(actBNRING) n_field = &wksp_ptr->baseData.Curve.n_field;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) x1     = wksp_ptr->baseData.Curve.t[0];
   VSECPRIM_P2VAR_PARA(actBNDIGIT) s_inv  = wksp_ptr->baseData.Curve.t[actEC_BIGNUM_TMP-1u];
   actLengthType p_length = wksp_ptr->baseData.Curve.p_field.m_length;
   actLengthType p_bytes  = wksp_ptr->baseData.Curve.p_field.m_byte_length;
   actLengthType n_length = wksp_ptr->baseData.Curve.n_field.m_length;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) u1;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) u2;

   u1 = wksp_ptr->dataPair.u12.u1;
   u2 = wksp_ptr->dataPair.u12.u2;
   G.x = wksp_ptr->curvePoint.basePoint.xcoord;
   G.y = wksp_ptr->curvePoint.basePoint.ycoord;
   QG.x = wksp_ptr->multG.QG.xcoord;
   QG.y = wksp_ptr->multG.QG.ycoord;
   QG.z = wksp_ptr->multG.QG.zcoord;
   point.x = wksp_ptr->Q.xcoord;
   point.y = wksp_ptr->Q.ycoord;
   point.z = wksp_ptr->Q.zcoord;

   actBNSetOctetStringROM(G.x, p_length, wksp_ptr->baseData.Curve.G_R, p_bytes);
   actBNSetOctetStringROM(G.y, p_length, &(wksp_ptr->baseData.Curve.G_R[p_bytes]), p_bytes);
   G.is_affine   = TRUE;
   G.is_infinity = FALSE;

   actECPToMont(Q, &(wksp_ptr->baseData.Curve), watchdog);

   if(actECPointIsOnCurve(Q, &(wksp_ptr->baseData.Curve), watchdog) != actOK){
      retVal = actEXCEPTION_PUBKEY;
   }

   if(retVal == actOK){
     actBNMontMul(s, n_field->RR, u1, n_field, watchdog);

     actBNFieldInversion(u1, s_inv, n_field, wksp_ptr->baseData.Curve.t, watchdog);

     actBNMontMul(e, s_inv, u1, n_field, watchdog);

     actBNMontMul(r, s_inv, u2, n_field, watchdog);

     actECPSimMult(&G, Q, u1, u2, &QG, &point, &(wksp_ptr->baseData.Curve), watchdog);

     if(actECPToAffineFromMont(&point, &(wksp_ptr->baseData.Curve), 0, watchdog) != actOK)
     {
       retVal = actEXCEPTION_UNKNOWN;
     }

     if(retVal == actOK)
     {
       actBNCopy(x1, point.x, p_length);

       actECReduceXModN(n_field->m, n_length, x1, p_length, wksp_ptr->baseData.Curve.t[1]);

       if(actBNCompare(x1, r, n_length) != actCOMPARE_EQUAL)
       {
         retVal = actSIGNATURE_INVALID;
       }
     }
   }

   return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actECDSAsp(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) e,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) d,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) s,
  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;
   actRETURNCODE rng_callback_error;

   actECPOINT Prec, Q;
   VSECPRIM_P2CONST_PARA(actBNRING) n_field = &(wksp->baseData.Curve.n_field);
   actLengthType n_length = n_field->m_length;
   actLengthType p_length = wksp->baseData.Curve.p_field.m_length;
   VSECPRIM_P2CONST_PARA(actBNDIGIT) RR     = n_field->RR;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) x1     = wksp->baseData.Curve.t[0];
   VSECPRIM_P2VAR_PARA(actBNDIGIT) k_inv  = wksp->baseData.Curve.t[actEC_BIGNUM_TMP-1u];
   VSECPRIM_P2VAR_PARA(actBNDIGIT) t0     = wksp->baseData.Curve.t[0];
   VSECPRIM_P2VAR_PARA(actBNDIGIT) t1     = wksp->baseData.Curve.t[1];
   VSECPRIM_P2VAR_PARA(actBNDIGIT) k;

   actBoolean found = FALSE;

   k = wksp->dataPair.privKeys.ephKey;
   Q.x = wksp->multG.kG.xcoord;
   Q.y = wksp->multG.kG.ycoord;
   Q.z = wksp->multG.kG.zcoord;
   Prec.x = wksp->curvePoint.precomputedPoint.xcoord;
   Prec.y = wksp->curvePoint.precomputedPoint.ycoord;

   while (found == FALSE){
      rng_callback_error = actBNModRandomize(k, n_field, wksp->baseData.Curve.t, watchdog);
      if(rng_callback_error != actOK)
      {
        found = TRUE;
        retVal = rng_callback_error;
      }

      if(retVal == actOK)
      {
        actECPMultG(k, &Prec, &Q, &(wksp->baseData.Curve), watchdog);

        if(actECPToAffineFromMont(&Q, &(wksp->baseData.Curve), 0, watchdog) != actOK)
        {
          found = TRUE;
          retVal = actEXCEPTION_UNKNOWN;
        }

        if(retVal == actOK)
        {
          actBNCopy(x1, Q.x, p_length);

          actECReduceXModN(n_field->m, n_length, x1, p_length, wksp->baseData.Curve.t[1]);

          actBNSetZero(r, n_length);
          actBNCopy(r, x1, n_length);
          if(actBNIsZero(r, n_length) == FALSE)
          {
            actBNMontMulCopy(k, RR, t0, n_field, watchdog);

            actBNFieldInversion(k, k_inv, n_field, wksp->baseData.Curve.t, watchdog);

            actBNMontMul(d, r, t0, n_field, watchdog);

            actBNMontMul(t0, RR, t1, n_field, watchdog);

            actBNModAdd(e, t1, t0, n_field, watchdog);

            actBNMontMul(k_inv, t0, t1, n_field, watchdog);

            actBNSetZero(s, n_length);
            actBNCopy(s, t1, n_length);

            if(actBNIsZero(s, n_length) == FALSE)
            {
              found = TRUE;
            }
            else
            {
              found = FALSE;
            }
          }
        }
      }
   }

   return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

