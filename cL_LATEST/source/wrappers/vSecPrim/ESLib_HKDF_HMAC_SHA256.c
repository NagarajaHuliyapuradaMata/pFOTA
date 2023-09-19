

#define ESLIB_HKDFHMACSHA256_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIHKDF_HMAC_SHA256.hpp"

#if(VSECPRIM_HKDF_HMAC_SHA256_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initHKDF_HMAC_SHA256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHMAC) workSpace
   ,  eslt_HKDFMode mode){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_HKDF_HMAC)) != ESL_ERC_NO_ERROR){
  }
  else if((mode != ESL_HKDF_ONE_STEP_VARIANT) && (mode != ESL_HKDF_TWO_STEP_VARIANT)){
    retVal = ESL_ERC_MODE_INVALID;
  }
  else{
    workSpace->wsHKDF.methodID = mode;
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HKDF_HMAC_SHA256);
  }
  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyHKDF_HMAC_SHA256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHMAC) workSpace
   ,  const eslt_Length secretLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) secret
   ,  const eslt_Length saltLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  const eslt_Length infoLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) info
   ,  const eslt_Length keyLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (secret == NULL_PTR) || ((salt == NULL_PTR) && (saltLength > 0u)) || ((info == NULL_PTR) && (infoLength > 0u)) || (key == NULL_PTR) ){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((secretLength == 0u) || (keyLength == 0u)){
    retVal = ESL_ERC_INPUT_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HKDF_HMAC, ESL_WST_ALGO_HKDF_HMAC_SHA256)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(workSpace->wsHKDF.methodID == ESL_HKDF_ONE_STEP_VARIANT){
      actRetVal = actHKDF_HMAC_SHA256_OneStepDerive(&workSpace->wsHKDF, secret, secretLength, salt, saltLength, info, infoLength, key, keyLength, workSpace->header.watchdog);
    }
    else{
      actHKDF_HMAC_SHA256_Extract(&workSpace->wsHKDF, secret, (actLengthType)secretLength, salt, (actLengthType)saltLength, workSpace->header.watchdog);
      actRetVal = actHKDF_HMAC_SHA256_Expand(&workSpace->wsHKDF, info, (actLengthType)infoLength, key, (actLengthType)keyLength, workSpace->header.watchdog);
    }

    if(actRetVal == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

