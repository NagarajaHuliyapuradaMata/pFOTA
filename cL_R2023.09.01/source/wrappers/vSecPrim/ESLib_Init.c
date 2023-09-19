

#define ESLIB_INIT_SOURCE

#include "ESLib.hpp"
#include "ESLib_types.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initESCryptoLib(void){
  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initWorkSpaceHeader(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHeader) workSpaceHeader
   ,  const eslt_Length workSpaceSize
   ,  esl_WatchdogFuncPtr watchdog){
  eslt_ErrorCode retVal;

  if(workSpaceHeader == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    workSpaceHeader->size = workSpaceSize;
    workSpaceHeader->status = ESL_WST_ALLOCATED;
    workSpaceHeader->watchdog = watchdog;

    workSpaceHeader->checkSum = 0u;

    retVal = ESL_ERC_NO_ERROR;
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

