

#define ESLIB_HASHMACSHA256_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIHashMACSHA256.hpp"

#if(VSECPRIM_HMAC_SHA2_256_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
const eslt_Length keyLength,
VSECPRIM_P2CONST_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (key == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA256)) != ESL_ERC_NO_ERROR){
  }

  else if(keyLength == 0u){
    retVal = ESL_ERC_HMAC_KEY_LENGTH_OUT_OF_RANGE;
  }
  else{
    (void)actHashMACSHA256Init(&workSpace->wsHMACSHA256, key, keyLength, workSpace->header.watchdog);

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HMACSHA256);

  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
const eslt_Length inputLength,
VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA256, ESL_WST_ALGO_HMACSHA256)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(actEXCEPTION_LENGTH == actHashMACSHA256Update(&workSpace->wsHMACSHA256, input, (actLengthType)inputLength, workSpace->header.watchdog)){
      retVal = ESL_ERC_SHA256_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) messageHashMAC){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA256, ESL_WST_ALGO_HMACSHA256)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actHashMACSHA256Finalize(&workSpace->wsHMACSHA256, messageHashMAC, workSpace->header.watchdog);

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsHMACSHA256);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageHashMAC){
  eslt_Byte tmpMAC[ESL_SIZEOF_SHA256_DIGEST];
  eslt_ErrorCode retVal;

  actMemClear(tmpMAC, ESL_SIZEOF_SHA256_DIGEST);

  if((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA256, ESL_WST_ALGO_HMACSHA256)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)esl_finalizeHashMACSHA256(workSpace, tmpMAC);

    if(actMemcmp(tmpMAC, messageHashMAC, ESL_SIZEOF_SHA256_DIGEST) != TRUE){
      retVal = ESL_ERC_HMAC_INCORRECT_MAC;
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

