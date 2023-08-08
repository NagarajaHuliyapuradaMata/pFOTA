

#define ESLIB_DHECP_SOURCE

#include "ESLib_Helper.hpp"

#include "actIECDH.hpp"

#if(VSECPRIM_ECDH_GENERIC_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initGenerateSharedSecretDHEcP_prim(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace,
                                                                     VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain, VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (domain == NULL_PTR) || (domainExt == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_ECP)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRETURNCODE result = actECDHInitGetSecret(domain, domainExt, &workSpace->wsEcP, (workSpace->header.size));
    if(result != actOK){
      if(result == actEXCEPTION_NULL)
      {
        retVal = ESL_ERC_PARAMETER_INVALID;
      }
      else if(result == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_WS_TOO_SMALL;
      }
      else if(result == actEXCEPTION_DOMAIN)
      {
        retVal = ESL_ERC_ECC_DOMAIN_INVALID;
      }
      else
      {
        retVal = ESL_ERC_ECC_DOMAINEXT_INVALID;
      }
    }
    else{
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_ECP);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateSharedSecretDHEcP_prim(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey,
                                                                 VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_x, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_y,
                                                                 VSECPRIM_P2VAR_PARA(eslt_Byte) secret_x, VSECPRIM_P2VAR_PARA(eslt_Byte) secret_y){
  eslt_ErrorCode retVal;
  actRETURNCODE result;

  if((workSpace == NULL_PTR) || (privateKey == NULL_PTR) || (publicKey_x == NULL_PTR) || (publicKey_y == NULL_PTR) || (secret_x == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_ECP, ESL_WST_ALGO_ECP)) != ESL_ERC_NO_ERROR){
  }
  else{
    result = actECDHGetSecret(privateKey, publicKey_x, publicKey_y, secret_x, secret_y, &workSpace->wsEcP, workSpace->header.watchdog);
    if(result != actOK){
      if(result == actEXCEPTION_NULL)
      {
        retVal = ESL_ERC_PARAMETER_INVALID;
      }
      else if(result == actEXCEPTION_PUBKEY)
      {
        retVal = ESL_ERC_ECC_PUBKEY_INVALID;
      }
      else if(result == actEXCEPTION_PRIVKEY)
      {
        retVal = ESL_ERC_ECC_PRIVKEY_INVALID;
      }
      else
      {
        retVal = ESL_ERC_ECC_INTERNAL_ERROR;
      }
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initExchangeKeyDHEcP_key(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace,
                                                           VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain, VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (domain == NULL_PTR) || (domainExt == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_ECP)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRETURNCODE result = actECDHInitKeyDerive(domain, domainExt, &workSpace->wsEcP, (workSpace->header.size));
    if(result != actOK){
      if(result == actEXCEPTION_NULL)
      {
        retVal = ESL_ERC_PARAMETER_INVALID;
      }
      else if(result == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_WS_TOO_SMALL;
      }
      else if(result == actEXCEPTION_DOMAIN)
      {
        retVal = ESL_ERC_ECC_DOMAIN_INVALID;
      }
      else
      {
        retVal = ESL_ERC_ECC_DOMAINEXT_INVALID;
      }
    }
    else{
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_ECP);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_exchangeKeyDHEcP_key(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace,
                                                       VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey,
                                                       VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_x, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_y,
                                                       eslt_Length infoLength, VSECPRIM_P2CONST_PARA(eslt_Byte) info,
                                                       eslt_Length iterationCount, eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal;
  actRETURNCODE result;

  if((workSpace == NULL_PTR) || (privateKey == NULL_PTR) || (publicKey_x == NULL_PTR) || (publicKey_y == NULL_PTR) || (key == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_ECP, ESL_WST_ALGO_ECP)) != ESL_ERC_NO_ERROR){
  }
  else{
    result = actECDHKeyDerive(privateKey, publicKey_x, publicKey_y, iterationCount, info, infoLength, key, keyLength, &workSpace->wsEcP, workSpace->header.watchdog);
    if(result != actOK){
      if(result == actEXCEPTION_NULL)
      {
        retVal = ESL_ERC_PARAMETER_INVALID;
      }
      else if(result == actEXCEPTION_PUBKEY)
      {
        retVal = ESL_ERC_ECC_PUBKEY_INVALID;
      }
      else if(result == actEXCEPTION_PRIVKEY)
      {
        retVal = ESL_ERC_ECC_PRIVKEY_INVALID;
      }
      else
      {
        retVal = ESL_ERC_ECC_INTERNAL_ERROR;
      }
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

