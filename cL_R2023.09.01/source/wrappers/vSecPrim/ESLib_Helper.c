

#define ESLIB_HELPER_SOURCE

#include "ESLib_Helper.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) esl_ResetAndClearWorkspace(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHeader) workSpaceHeader, VSECPRIM_P2VAR_PARA(void) workSpaceBuffer){
  workSpaceHeader->status = ESL_WST_ALLOCATED;
#if(VSECPRIM_CLEAR_WORKSPACE_ENABLED == STD_ON)

  actMemset(workSpaceBuffer, 0, workSpaceHeader->size);
#else
  VSECPRIM_DUMMY_STATEMENT(workSpaceBuffer);
#endif
}

VSECPRIM_FUNC(void) esl_SetWorkspaceStatus(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHeader) workSpaceHeader, eslt_WSStatus algo){
    workSpaceHeader->status = (algo | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);
}

VSECPRIM_FUNC(void) esl_SetWorkspaceSize(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHeader) workSpaceHeader, const eslt_Length workSpaceSize){
  workSpaceHeader->size = workSpaceSize;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_CheckWorkSpaceHeader(VSECPRIM_P2CONST_PARA(eslt_WorkSpaceHeader) workSpaceHeader, eslt_Length minSize){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  if(workSpaceHeader->size < minSize){
    retVal = ESL_ERC_WS_TOO_SMALL;
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_CheckWorkSpaceState(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceHeader) workSpaceHeader
   ,  eslt_WSStatus algo){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  if(((workSpaceHeader->status & ESL_WST_M_ALGO) != algo) || ((workSpaceHeader->status & ESL_WST_M_RUNNING) == 0u)){
    retVal = ESL_ERC_WS_STATE_INVALID;
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_CheckWorkSpaceHeaderAndState(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceHeader) workSpaceHeader
   ,  eslt_Length minSize, eslt_WSStatus algo){
  eslt_ErrorCode retVal = esl_CheckWorkSpaceHeader(workSpaceHeader, minSize);

  if(retVal != ESL_ERC_NO_ERROR){
  }
  else{
    retVal = esl_CheckWorkSpaceState(workSpaceHeader, algo);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_checkLengthRef(eslt_LengthConstRef lenRef, eslt_Length lengthValue){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  if(lenRef == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if(*lenRef < lengthValue){
    retVal = ESL_ERC_BUFFER_TOO_SMALL;
  }
  else{
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

