

#define ESLIB_KDFX963SHA512_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIKDFX963_SHA512.hpp"

#if(VSECPRIM_ANSI_X963_SHA512_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initKDFX963SHA512(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDFX963SHA512) workSpace){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_KDFX963SHA512)) != ESL_ERC_NO_ERROR){
  }
  else{
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_KDFX963SHA512);
  }
  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyKDFX963SHA512(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDFX963SHA512) workSpace,
  const eslt_Length secretLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) secret,
  const eslt_Length infoLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) info,
  const eslt_Length keyLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (secret == NULL_PTR) || (key == NULL_PTR) || ((infoLength != 0u) && (info == NULL_PTR))){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((secretLength == 0u) || (keyLength == 0u)){
    retVal = ESL_ERC_INPUT_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_KDFX963SHA512, ESL_WST_ALGO_KDFX963SHA512)) != ESL_ERC_NO_ERROR){
  }
  else{
    actKDFX963_SHA512_Derive(&workSpace->wsKDFX963SHA512, secret, secretLength, info, infoLength, key, keyLength, workSpace->header.watchdog);
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

