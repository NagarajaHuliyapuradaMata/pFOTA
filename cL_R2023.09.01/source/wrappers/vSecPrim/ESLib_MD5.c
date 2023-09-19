

#define ESLIB_MD5_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIMD5.hpp"

#if(VSECPRIM_MD5_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initMD5(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceMD5) workSpace){
  if(workSpace == NULL_PTR){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if(workSpace->header.size < ESL_MINSIZEOF_WS_MD5){
    return ESL_ERC_WS_TOO_SMALL;
  }

  (void)actMD5Init((VSECPRIM_P2VAR_PARA(actMD5STRUCT)) workSpace->wsMD5);

  workSpace->header.status = (ESL_WST_ALGO_MD5 | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateMD5(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceMD5) workSpace, const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_MD5){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((workSpace->header.status & ESL_WST_M_RUNNING) == 0u){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((inputSize % ESL_SIZEOF_MD5_BLOCK) == 0u){
    if(workSpace->header.size < ESL_MINSIZEOF_WS_MD5){
      return ESL_ERC_WS_TOO_SMALL;
    }
  }
  else{
    if(workSpace->header.size < ESL_MAXSIZEOF_WS_MD5){
      return ESL_ERC_WS_TOO_SMALL;
    }
  }

  (void)actMD5Update((VSECPRIM_P2VAR_PARA(actMD5STRUCT)) workSpace->wsMD5, input, inputSize, workSpace->header.watchdog);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeMD5(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceMD5) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_MD5){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((workSpace->header.status & ESL_WST_M_RUNNING) == 0u){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if(workSpace->header.size < ESL_MAXSIZEOF_WS_MD5){
    return ESL_ERC_WS_TOO_SMALL;
  }

  (void)actMD5Finalize((VSECPRIM_P2VAR_PARA(actMD5STRUCT)) workSpace->wsMD5, messageDigest, workSpace->header.watchdog);

  esl_ResetAndClearWorkspace(&workSpace->header, workSpace->wsMD5);

  return ESL_ERC_NO_ERROR;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

