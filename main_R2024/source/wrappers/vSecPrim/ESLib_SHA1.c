

#define ESLIB_SHA1_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actISHA.hpp"

#if(VSECPRIM_SHA1_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHA1(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA1) workSpace){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MINSIZEOF_WS_SHA1)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actSHAInit(&workSpace->wsSHA1);
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SHA1);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHA1(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA1) workSpace,
  const eslt_Length inputSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SHA1, ESL_WST_ALGO_SHA1)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRETURNCODE result = actSHAUpdate(&workSpace->wsSHA1,
                                        (VSECPRIM_P2CONST_PARA(actU8)) input,
                                        (actLengthType)inputSize,
                                        workSpace->header.watchdog);
    if(result == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_SHA1_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHA1(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA1) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SHA1, ESL_WST_ALGO_SHA1)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actSHAFinalize(&workSpace->wsSHA1,
                         (VSECPRIM_P2VAR_PARA(actU8))messageDigest,
                         workSpace->header.watchdog);

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSHA1);
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

