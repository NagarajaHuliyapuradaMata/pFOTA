

#define ESLIB_KDF2_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "actITypes.hpp"

#include "actIKDF2.hpp"

#if(VSECPRIM_PKCS5_ENABLED == STD_ON || VSECPRIM_PKCS5_HMAC_SHA256_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initKDF2(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2) workSpace,
  const eslt_Length iterationCount,
  eslt_Length workSpaceSize,
  eslt_WSStatus algo);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_deriveKeyKDF2(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2) workSpace,
  const eslt_Length secretLength, VSECPRIM_P2CONST_PARA(eslt_Byte) secret,
  const eslt_Length infoLength, VSECPRIM_P2CONST_PARA(eslt_Byte) info,
  const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key,
  eslt_Byte SHAid, const eslt_Length SHAsize, eslt_WSStatus algo);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initKDF2(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2) workSpace,
  const eslt_Length iterationCount,
  eslt_Length workSpaceSize,
  eslt_WSStatus algo){
  eslt_ErrorCode retVal;

  if(iterationCount == 0u){
    retVal = ESL_ERC_KDF_ITERATION_COUNT_OUT_OF_RANGE;
  }

  else if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, workSpaceSize)) != ESL_ERC_NO_ERROR){
  }

  else{
    (void)actKDF2Init((VSECPRIM_P2VAR_PARA(actKDF2STRUCT)) &(workSpace->wsKDF2HMACSHA), iterationCount);
    esl_SetWorkspaceStatus(&workSpace->header, algo);

  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_deriveKeyKDF2(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2) workSpace,
  const eslt_Length secretLength, VSECPRIM_P2CONST_PARA(eslt_Byte) secret,
  const eslt_Length infoLength, VSECPRIM_P2CONST_PARA(eslt_Byte) info,
  const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key,
  eslt_Byte SHAid, const eslt_Length SHAsize, eslt_WSStatus algo){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (secret == NULL_PTR) || (key == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((secretLength == 0u) || (keyLength == 0u)){
    retVal = ESL_ERC_INPUT_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_KDF2HMACSHA1, algo)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actKDF2Derive((VSECPRIM_P2VAR_PARA(actKDF2STRUCT)) &(workSpace->wsKDF2HMACSHA), secret, secretLength,
      info, infoLength, key, keyLength, SHAid, SHAsize);

  }

  return retVal;
}

# if(VSECPRIM_PKCS5_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_initKDF2HMACSHA1(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2HMACSHA1) workSpace,
  const eslt_Length iterationCount){
  return esl_initKDF2(workSpace, iterationCount, ESL_MAXSIZEOF_WS_KDF2HMACSHA1, ESL_WST_ALGO_KDF2HMACSHA1);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyKDF2HMACSHA1(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2HMACSHA1) workSpace,
  const eslt_Length secretLength, VSECPRIM_P2CONST_PARA(eslt_Byte) secret,
  const eslt_Length infoLength, VSECPRIM_P2CONST_PARA(eslt_Byte) info,
  const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  return esl_deriveKeyKDF2(workSpace, secretLength, secret, infoLength, info, keyLength, key, actHASHMACSHA1_ALGO_ID, actHASH_SIZE_SHA, ESL_WST_ALGO_KDF2HMACSHA1);
}
# endif

# if(VSECPRIM_PKCS5_HMAC_SHA256_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_initKDF2HMACSHA256(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2HMACSHA256) workSpace,
  const eslt_Length iterationCount){
  return esl_initKDF2(workSpace, iterationCount, ESL_MAXSIZEOF_WS_KDF2HMACSHA256, ESL_WST_ALGO_KDF2HMACSHA256);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyKDF2HMACSHA256(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2HMACSHA256) workSpace,
  const eslt_Length secretLength, VSECPRIM_P2CONST_PARA(eslt_Byte) secret,
  const eslt_Length infoLength, VSECPRIM_P2CONST_PARA(eslt_Byte) info,
  const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  return esl_deriveKeyKDF2(workSpace, secretLength, secret,
    infoLength, info, keyLength, key, actHASHMACSHA256_ALGO_ID, actHASH_SIZE_SHA256, ESL_WST_ALGO_KDF2HMACSHA256);
}
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

