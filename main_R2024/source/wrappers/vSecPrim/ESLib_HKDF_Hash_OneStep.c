

#define ESLIB_HKDFHASHONESTEP_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIHKDF_Hash_OneStep.hpp"

#if(VSECPRIM_HKDF_SHA2_256_ONESTEP_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initHKDF_Hash_OneStep(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHASH) workSpace,
  eslt_HashAlgorithm hashID){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_HKDF_HASH)) != ESL_ERC_NO_ERROR){
  }
  else if(hashID != ESL_HA_SHA2_256){
    retVal = ESL_ERC_INPUT_INVALID;
  }
  else{
    workSpace->wsHKDF.hashID = hashID;
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HKDF_HASH_SHA256);
  }
  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyHKDF_Hash_OneStep(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHASH) workSpace,
  const eslt_Length secretLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) secret,
  const eslt_Length infoLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) info,
  const eslt_Length keyLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (secret == NULL_PTR) || ((info == NULL_PTR) && (infoLength > 0u)) || (key == NULL_PTR) ){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((secretLength == 0u) || (keyLength == 0u)){
    retVal = ESL_ERC_INPUT_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HKDF_HASH, ESL_WST_ALGO_HKDF_HASH_SHA256)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actHKDF_Hash_OneStepDerive(&workSpace->wsHKDF, secret, secretLength, info, infoLength, key, keyLength, workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

