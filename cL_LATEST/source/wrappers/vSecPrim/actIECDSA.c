

#define ACTIECDSA_SOURCE

#include "actIECDSA.hpp"
#include "actIECKey.hpp"
#include "actECTools.hpp"
#include "actECDSA.hpp"
#include "actECPoint.hpp"
#include "actECLengthInfo.hpp"
#include "actUtilities.hpp"
#include "actConfig.hpp"

#if(VSECPRIM_ACTIECDSA_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actLengthType) actECDSAGetSignatureCompLength(VSECPRIM_P2ROMCONST_PARA(actU8) domain){
  return actECGetPrivateKeyLength(domain);
}

VSECPRIM_FUNC(actRETURNCODE) actECDSAInitVerify(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp
   ,  actLengthType wksp_len){
  return actECInit(domain, domain_ext, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR, actEC_ALGO_FLAG_VP, &(wksp->baseData), wksp_len);
}

VSECPRIM_FUNC(actRETURNCODE) actECDSAVerify(
  VSECPRIM_P2CONST_PARA(actU8) message
   ,  actLengthType message_len
   ,  VSECPRIM_P2CONST_PARA(actU8) signature_r
   ,  actLengthType signature_r_len
   ,  VSECPRIM_P2CONST_PARA(actU8) signature_s
   ,  actLengthType signature_s_len
   ,  VSECPRIM_P2CONST_PARA(actU8) publickey_x
   ,  VSECPRIM_P2CONST_PARA(actU8) publickey_y
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;
  actRETURNCODE resultCompareInputX, resultCompareInputY;
  actLengthType p_length = wksp->baseData.Curve.p_field.m_length;
  actLengthType p_bytes  = wksp->baseData.Curve.p_field.m_byte_length;
  actLengthType n_length = wksp->baseData.Curve.n_field.m_length;
  actLengthType n_bytes  = wksp->baseData.Curve.n_field.m_byte_length;
  actECPOINT Q;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) e;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) s;

  e = wksp->msg.hashed_message;
  r = wksp->signature_r;
  s = wksp->signature_s;
  Q.x = wksp->public_key_x;
  Q.y = wksp->public_key_y;

  if((message_len <= 0u) || (message_len > n_bytes)){
    retVal = actEXCEPTION_LENGTH;
  }

  if(retVal == actOK){
    actBNSetOctetString(e, n_length, message, message_len);
    if(message_len == n_bytes){
      if(actBNGetBitLength(e, n_length) > actBNGetBitLength(wksp->baseData.Curve.n_field.m, n_length))
      {
        retVal = actEXCEPTION_LENGTH;
      }
    }
  }

  if(retVal == actOK){
    if((signature_r_len <= 0u) || (signature_r_len > n_bytes) || (signature_s_len <= 0u) || (signature_s_len > n_bytes)){
      retVal = actSIGNATURE_OUT_OF_RANGE;
    }
    else{
      actBNSetOctetString(r, n_length, signature_r, signature_r_len);
      actBNSetOctetString(s, n_length, signature_s, signature_s_len);

      resultCompareInputX = actBNCompare(r, wksp->baseData.Curve.n_field.m, n_length);
      resultCompareInputY = actBNCompare(s, wksp->baseData.Curve.n_field.m, n_length);

      if((actBNIsZero(r, n_length) == TRUE) || (resultCompareInputX >= actCOMPARE_EQUAL))
      {
        retVal = actSIGNATURE_OUT_OF_RANGE;
      }
      else if((actBNIsZero(s, n_length) == TRUE) || (resultCompareInputY >= actCOMPARE_EQUAL))
      {
        retVal = actSIGNATURE_OUT_OF_RANGE;
      }
      else
      {
        actBNSetOctetString(Q.x, p_length, publickey_x, p_bytes);
        actBNSetOctetString(Q.y, p_length, publickey_y, p_bytes);
        Q.is_affine = TRUE;
        Q.is_infinity = FALSE;

        resultCompareInputX = actBNCompare(Q.x, wksp->baseData.Curve.p_field.m, p_length);
        resultCompareInputY = actBNCompare(Q.y, wksp->baseData.Curve.p_field.m, p_length);

        if((resultCompareInputX < actCOMPARE_EQUAL) && (resultCompareInputY < actCOMPARE_EQUAL))
        {
          retVal = actECDSAvp(e, r, s, &Q, wksp, watchdog);
        }
        else
        {
          retVal = actEXCEPTION_PUBKEY;
        }
      }
    }
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actECDSAInitSign(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) speedup_ext
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp
   ,  actLengthType wksp_len){
  return actECInit(domain, domain_ext, speedup_ext, actEC_ALGO_FLAG_SP, &(wksp->baseData), wksp_len);
}

VSECPRIM_FUNC(actRETURNCODE) actECDSASign(
  VSECPRIM_P2CONST_PARA(actU8) message
   ,  actLengthType message_len
   ,  VSECPRIM_P2CONST_PARA(actU8) privatekey
   ,  VSECPRIM_P2VAR_PARA(actU8) signature_r
   ,  VSECPRIM_P2VAR_PARA(actLengthType) signature_r_len
   ,  VSECPRIM_P2VAR_PARA(actU8) signature_s
   ,  VSECPRIM_P2VAR_PARA(actLengthType) signature_s_len
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;
  actRETURNCODE resultCompareDN;
  actLengthType n_length = wksp->baseData.Curve.n_field.m_length;
  actLengthType n_bytes = wksp->baseData.Curve.n_field.m_byte_length;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) e;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) d;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) s;

  if((*signature_r_len < n_bytes) || (*signature_s_len < n_bytes)){
    retVal = actEXCEPTION_MEMORY;
  }
  else if((message_len <= 0u) || (message_len > n_bytes)){
    retVal = actEXCEPTION_LENGTH;
  }
  else{
    e = wksp->msg.hashed_message;
    d = wksp->dataPair.privKeys.privKey;
    r = wksp->signature_r;
    s = wksp->signature_s;

    actBNSetOctetString(d, n_length, privatekey, n_bytes);
    actBNSetOctetString(e, n_length, message, message_len);

    resultCompareDN = actBNCompare(d, wksp->baseData.Curve.n_field.m, n_length);

    if((actBNIsZero(d, n_length) == TRUE) || (resultCompareDN >= actCOMPARE_EQUAL)){
      retVal = actEXCEPTION_PRIVKEY;
    }
    else if(message_len == n_bytes){
      if(actBNGetBitLength(e, n_length) > actBNGetBitLength(wksp->baseData.Curve.n_field.m, n_length))
      {
        retVal = actEXCEPTION_LENGTH;
      }
    }
    else{
    }

    if(retVal == actOK){
      retVal = actECDSAsp(e, d, r, s, wksp, watchdog);

      if(retVal == actOK)
      {
        actBNOctetString(signature_r, n_bytes, r, n_length);
        actBNOctetString(signature_s, n_bytes, s, n_length);
        *signature_r_len = n_bytes;
        *signature_s_len = n_bytes;
      }

      actBNSetZero(d, n_length);
    }
  }

  return retVal;

}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

