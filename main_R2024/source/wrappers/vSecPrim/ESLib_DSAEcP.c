

#define ESLIB_DSAECP_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIECDSA.hpp"

#if(VSECPRIM_ECDSA_GENERIC_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignDSAEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccSpeedUpExt) speedUpExt){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (domain == NULL_PTR) || (domainExt == NULL_PTR) || (speedUpExt == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_ECP)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actECDSAInitSign(domain, domainExt, speedUpExt, &(workSpace->wsEcP), workSpace->header.size);

    if(actRetVal != actOK){
      if(actRetVal == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_WS_TOO_SMALL;
      }
      else if(actRetVal == actEXCEPTION_DOMAIN)
      {
        retVal = ESL_ERC_ECC_DOMAIN_INVALID;
      }
      else if(actRetVal == actEXCEPTION_DOMAIN_EXT)
      {
        retVal = ESL_ERC_ECC_DOMAINEXT_INVALID;
      }
      else
      {
        retVal = ESL_ERC_ECC_SPEEDUPEXT_INVALID;
      }
    }
    else{
      retVal = ESL_ERC_NO_ERROR;

      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_ECP);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_signDSAEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace,
  eslt_Length messageLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) message,
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey,
  VSECPRIM_P2VAR_PARA(eslt_Length) signature_rLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature_r,
  VSECPRIM_P2VAR_PARA(eslt_Length) signature_sLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature_s){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  actLengthType r_len;
  actLengthType s_len;

  if((workSpace == NULL_PTR) || (message == NULL_PTR) || (privateKey == NULL_PTR) ||
    (signature_rLength == NULL_PTR) || (signature_r == NULL_PTR) || (signature_sLength == NULL_PTR) || (signature_s == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_ECP, ESL_WST_ALGO_ECP)) != ESL_ERC_NO_ERROR){
  }
  else{
    r_len = (actLengthType)(*signature_rLength);
    s_len = (actLengthType)(*signature_sLength);

    actRetVal = actECDSASign(message, messageLength, privateKey, signature_r, &r_len,
      signature_s, &s_len, &(workSpace->wsEcP), workSpace->header.watchdog);

    if(actRetVal != actOK){
      if(actRetVal == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
      }
      else if(actRetVal == actEXCEPTION_LENGTH)
      {
        retVal = ESL_ERC_ECC_MESSAGE_TOO_LONG;
      }
      else if(actRetVal == actEXCEPTION_PRIVKEY)
      {
        retVal = ESL_ERC_ECC_PRIVKEY_INVALID;
      }
      else if(actRetVal == actEXCEPTION_UNKNOWN)
      {
        retVal = ESL_ERC_ECC_INTERNAL_ERROR;
      }
      else
      {
        retVal = (eslt_ErrorCode)actRetVal;
      }
    }
    else{
      retVal = ESL_ERC_NO_ERROR;
      *signature_rLength = (eslt_Length)r_len;
      *signature_sLength = (eslt_Length)s_len;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyDSAEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (domain == NULL_PTR) || (domainExt == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_ECP)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRETURNCODE actRetVal = actECDSAInitVerify(domain, domainExt, &(workSpace->wsEcP), workSpace->header.size);

    if(actRetVal != actOK){
      if(actRetVal == actEXCEPTION_DOMAIN)
      {
        retVal = ESL_ERC_ECC_DOMAIN_INVALID;
      }
      else
      {
        retVal = ESL_ERC_ECC_DOMAINEXT_INVALID;
      }
    }
    else{
      retVal = ESL_ERC_NO_ERROR;

      workSpace->header.status = (ESL_WST_ALGO_ECP | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyDSAEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace,
  eslt_Length messageLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) message,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_x,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_y,
  eslt_Length signature_rLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) signature_r,
  eslt_Length signature_sLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) signature_s){
  actRETURNCODE actRetVal;
  eslt_ErrorCode retVal = ESL_ERC_ECC_SIGNATURE_INVALID;

  if((workSpace == NULL_PTR) || (message == NULL_PTR) || (publicKey_x == NULL_PTR) ||
      (publicKey_y == NULL_PTR) || (signature_r == NULL_PTR) || (signature_s == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_ECP, ESL_WST_ALGO_ECP)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actECDSAVerify(message, messageLength, signature_r, signature_rLength,
                               signature_s, signature_sLength, publicKey_x, publicKey_y, &(workSpace->wsEcP), workSpace->header.watchdog);
    if(actRetVal != actOK){
      if(actRetVal == actEXCEPTION_LENGTH)
      {
        retVal = ESL_ERC_ECC_MESSAGE_TOO_LONG;
      }
      else if(actRetVal == actEXCEPTION_PUBKEY)
      {
        retVal = ESL_ERC_ECC_PUBKEY_INVALID;
      }
      else if((actRetVal == actSIGNATURE_OUT_OF_RANGE) || (actRetVal == actSIGNATURE_INVALID))
      {
        retVal = ESL_ERC_ECC_SIGNATURE_INVALID;
      }
      else
      {
        retVal = ESL_ERC_ECC_INTERNAL_ERROR;
      }
    }
    else{
      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

