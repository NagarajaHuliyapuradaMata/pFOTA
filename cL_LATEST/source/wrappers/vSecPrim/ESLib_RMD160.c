

#define ESLIB_RMD160_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIRMD160.hpp"

#if(VSECPRIM_RIPEMD160_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initRIPEMD160(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRIPEMD160) workSpace){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MINSIZEOF_WS_RIPEMD160)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actRMD160Init(&workSpace->wsRIPEMD160);

    workSpace->header.status = (ESL_WST_ALGO_RIPEMD160 | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateRIPEMD160(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRIPEMD160) workSpace, const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_RIPEMD160, ESL_WST_ALGO_RIPEMD160)) != ESL_ERC_NO_ERROR){
  }

  else{
    actRETURNCODE result = actRMD160Update(&workSpace->wsRIPEMD160
   ,                                          input, inputSize, workSpace->header.watchdog);
    if(result == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_RIPEMD160_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeRIPEMD160(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRIPEMD160) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_RIPEMD160, ESL_WST_ALGO_RIPEMD160)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actRMD160Finalize(&workSpace->wsRIPEMD160, messageDigest, workSpace->header.watchdog);

    esl_ResetAndClearWorkspace(&workSpace->header, &(workSpace->wsRIPEMD160));
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

