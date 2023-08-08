

#define ACTIECDH_SOURCE

#include "actIECDH.hpp"
#include "actIECKey.hpp"
#include "actIKDF2.hpp"
#include "actECTools.hpp"
#include "actECDH.hpp"
#include "actECPoint.hpp"
#include "actECLengthInfo.hpp"
#include "actUtilities.hpp"
#include "actConfig.hpp"

#if(VSECPRIM_ACTIECDH_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actLengthType) actECDSAGetSecretCompLength(VSECPRIM_P2ROMCONST_PARA(actU8) domain){
  return actECGetPublicKeyCompLength(domain);
}

VSECPRIM_FUNC(actRETURNCODE) actECDHInitGetSecret(VSECPRIM_P2ROMCONST_PARA(actU8) domain, VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp, actLengthType wksp_len){
  return actECInit(domain, domain_ext, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR, actEC_ALGO_FLAG_DH_PRIM, &(wksp->baseData), wksp_len);
}

VSECPRIM_FUNC(actRETURNCODE) actECDHGetSecret(VSECPRIM_P2CONST_PARA(actU8) privatekey,
                                              VSECPRIM_P2CONST_PARA(actU8) publickey_x, VSECPRIM_P2CONST_PARA(actU8) publickey_y,
                                              VSECPRIM_P2VAR_PARA(actU8) secret_x, VSECPRIM_P2VAR_PARA(actU8) secret_y, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
                                              VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE returncode;
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve = &(wksp->baseData.Curve);
  actLengthType p_length = Curve->p_field.m_length;
  actLengthType p_bytes = Curve->p_field.m_byte_length;
  actLengthType n_length = Curve->n_field.m_length;
  actLengthType n_bytes = Curve->n_field.m_byte_length;
  actECPOINT Q, point;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) d;

  if((privatekey == NULL_PTR) || (publickey_x == NULL_PTR) || (publickey_y == NULL_PTR) || (secret_x == NULL_PTR)){
    return actEXCEPTION_NULL;
  }

  d = wksp->dataPair.privKeys.privKey;
  Q.x = wksp->public_key_x;
  Q.y = wksp->public_key_y;
  point.x = wksp->multG.kG.xcoord;
  point.y = wksp->multG.kG.ycoord;
  point.z = wksp->multG.kG.zcoord;

  actBNSetOctetString(d, n_length, privatekey, n_bytes);

  if(actBNIsZero(d, n_length) == TRUE){
    return actEXCEPTION_PRIVKEY;
  }
  if(actBNCompare(d, Curve->n_field.m, n_length) >= actCOMPARE_EQUAL){
    return actEXCEPTION_PRIVKEY;
  }

  actBNSetOctetString(Q.x, p_length, publickey_x, p_bytes);
  actBNSetOctetString(Q.y, p_length, publickey_y, p_bytes);
  Q.is_affine = TRUE;
  Q.is_infinity = FALSE;

  returncode = actECDHp(d, &Q, &point, Curve, watchdog);

  if(returncode == actOK){
    actBNOctetString(secret_x, p_bytes, point.x, p_length);

    if(secret_y != NULL_PTR){
      actBNOctetString(secret_y, p_bytes, point.y, p_length);
    }
  }

  actBNSetZero(d, n_length);

  return returncode;
}

VSECPRIM_FUNC(actRETURNCODE) actECDHInitKeyDerive(VSECPRIM_P2ROMCONST_PARA(actU8) domain, VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp, actLengthType wksp_len){
  return actECInit(domain, domain_ext, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR, actEC_ALGO_FLAG_DH, &(wksp->baseData), wksp_len);
}

VSECPRIM_FUNC(actRETURNCODE) actECDHKeyDerive(VSECPRIM_P2CONST_PARA(actU8) privatekey, VSECPRIM_P2CONST_PARA(actU8) publickey_x,
                                              VSECPRIM_P2CONST_PARA(actU8) publickey_y, actLengthType iteration_count,
                                              VSECPRIM_P2CONST_PARA(actU8) salt, actLengthType salt_length, VSECPRIM_P2VAR_PARA(actU8) key, actLengthType key_length, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
                                              VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE returncode;
  actLengthType p_length = wksp->baseData.Curve.p_field.m_length;
  VSECPRIM_P2VAR_PARA(actU8) secret_x = (VSECPRIM_P2VAR_PARA(actU8))(wksp->msg.secret_x);

  returncode = actECDHGetSecret(privatekey, publickey_x, publickey_y, secret_x, (VSECPRIM_P2VAR_PARA(actU8)) NULL_PTR, wksp, watchdog);
  if(returncode != actOK){
    return returncode;
  }

  returncode = actKDF2Init((VSECPRIM_P2VAR_PARA(actKDF2STRUCT)) wksp, iteration_count);
  if(returncode != actOK){
    return returncode;
  }
  returncode = actKDF2Derive((VSECPRIM_P2VAR_PARA(actKDF2STRUCT)) wksp, secret_x, p_length, salt, salt_length, key, key_length, actHASHMACSHA1_ALGO_ID, actHASH_SIZE_SHA);
  if(returncode != actOK){
    return returncode;
  }

  return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

