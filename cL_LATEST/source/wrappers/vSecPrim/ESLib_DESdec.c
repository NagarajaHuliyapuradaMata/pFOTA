

#define ESLIB_DESDEC_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "actITypes.hpp"

#include "actDES.hpp"

#if(VSECPRIM_DES_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptDES(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDES) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,                                                const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode, VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector){
  if((workSpace == NULL_PTR) || (key == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if(workSpace->header.size < ESL_MINSIZEOF_WS_DES){
    return ESL_ERC_WS_TOO_SMALL;
  }

  if(paddingMode != ESL_PM_PKCS5){
    return ESL_ERC_MODE_INVALID;
  }

  if(blockMode == ESL_BM_ECB){
    actDESInitDecrypt((VSECPRIM_P2VAR_PARA(actDESSTRUCT)) workSpace->wsDES, key, initializationVector, actDES_ECB, workSpace->header.watchdog);
  }
  else if(blockMode == ESL_BM_CBC){
    actDESInitDecrypt((VSECPRIM_P2VAR_PARA(actDESSTRUCT)) workSpace->wsDES, key, initializationVector, actDES_CBC, workSpace->header.watchdog);
  }
  else{
    return ESL_ERC_MODE_INVALID;
  }

  workSpace->header.status = (ESL_WST_ALGO_DES | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptDES(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDES) workSpace
   ,                                            const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input, VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output){
  if((workSpace == NULL_PTR) || (input == NULL_PTR) || (output == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_DES){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((workSpace->header.status & ESL_WST_M_RUNNING) == 0u){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((inputSize % ESL_SIZEOF_DES_BLOCK) == 0u){
    if(workSpace->header.size < ESL_MINSIZEOF_WS_DES){
      return ESL_ERC_WS_TOO_SMALL;
    }
  }
  else{
    if(workSpace->header.size < ESL_MAXSIZEOF_WS_DES){
      return ESL_ERC_WS_TOO_SMALL;
    }
  }

  {
    actRETURNCODE result;
    actLengthType dec_len = *outputSize;

    result = actDESDecrypt((VSECPRIM_P2VAR_PARA(actDESSTRUCT)) workSpace->wsDES, input, (actLengthType) inputSize, output, &dec_len, FALSE, workSpace->header.watchdog);
    if(result == actEXCEPTION_LENGTH){
      return ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
    }
    else{
      *outputSize = (eslt_Length)(dec_len);
    }
  }

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptDES(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDES) workSpace, VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output){
  if((workSpace == NULL_PTR) || (output == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_DES){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((workSpace->header.status & ESL_WST_M_RUNNING) == 0u){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if(workSpace->header.size < ESL_MAXSIZEOF_WS_DES){
    return ESL_ERC_WS_TOO_SMALL;
  }

  {
    actRETURNCODE result;
    actLengthType dec_len = *outputSize;

    result = actDESDecrypt((VSECPRIM_P2VAR_PARA(actDESSTRUCT)) workSpace->wsDES, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR, 0u, output, &dec_len, TRUE, workSpace->header.watchdog);
    if(result == actEXCEPTION_LENGTH){
      return ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
    }
    else if(result == actEXCEPTION_INPUT_LENGTH){
      return ESL_ERC_INPUT_INVALID;
    }
    else if(result == actEXCEPTION_PADDING){
      return ESL_ERC_DES_PADDING_INVALID;
    }
    else{
      *outputSize = (eslt_Length)dec_len;
    }
  }

  esl_ResetAndClearWorkspace(&workSpace->header, workSpace->wsDES);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptDESBlock(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDESBlock) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key){
  if((workSpace == NULL_PTR) || (key == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if(workSpace->header.size < ESL_MAXSIZEOF_WS_DESBLOCK){
    return ESL_ERC_WS_TOO_SMALL;
  }

  actDESInitDecryptBlock((VSECPRIM_P2VAR_PARA(actDESSTRUCT)) workSpace->wsDESBlock, key, workSpace->header.watchdog);

  workSpace->header.status = (ESL_WST_ALGO_DES | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptDESBlock(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDESBlock) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock){
  if((workSpace == NULL_PTR) || (inputBlock == NULL_PTR) || (outputBlock == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_DES){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((workSpace->header.status & ESL_WST_M_RUNNING) == 0u){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if(workSpace->header.size < ESL_MAXSIZEOF_WS_DESBLOCK){
    return ESL_ERC_WS_TOO_SMALL;
  }

  actDESCryptBlock((VSECPRIM_P2VAR_PARA(actDESSTRUCT)) workSpace->wsDESBlock, inputBlock, outputBlock, workSpace->header.watchdog);

  return ESL_ERC_NO_ERROR;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

