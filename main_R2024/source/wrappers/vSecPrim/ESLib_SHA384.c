

#define ESLIB_SHA384_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actISHA2_64.hpp"

#if(VSECPRIM_SHA2_512_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHA384(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA384) workSpace){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_SHA384)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actSHA384Init(&workSpace->wsSHA384);
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SHA384);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHA384(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA384) workSpace,
  const eslt_Length inputSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SHA384, ESL_WST_ALGO_SHA384)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRETURNCODE result = actSHA384Update(&workSpace->wsSHA384,
                                           (VSECPRIM_P2CONST_PARA(actU8))input,
                                           (actLengthType)inputSize,
                                           workSpace->header.watchdog);
    if(result == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHA384(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA384) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SHA384, ESL_WST_ALGO_SHA384)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actSHA384Finalize(&workSpace->wsSHA384,
      (VSECPRIM_P2VAR_PARA(actU8))messageDigest,
      workSpace->header.watchdog);

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSHA384);
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

