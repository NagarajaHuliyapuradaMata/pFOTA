

#define ESLIB_AES192DEC_SOURCE

#include "ESLib_AES_common.hpp"

#if(VSECPRIM_AES192_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptAES192(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,                                                   const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode, VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector){
  actU8 targetMode = actPADDING_PM_OFF;
  eslt_ErrorCode retVal = esl_AES_CommonInit(&targetMode, workSpace, ESL_MAXSIZEOF_WS_AES192, key, blockMode, paddingMode);

  if(retVal == ESL_ERC_NO_ERROR){
    if(actOK == actAESInitDecrypt(&workSpace->wsAES, key, ESL_SIZEOF_AES192_KEY, initializationVector, targetMode, workSpace->header.watchdog)){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_AES192);
    }
    else{
      retVal = ESL_ERC_PARAMETER_INVALID;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptAES192(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192) workSpace
   ,                                               const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input, VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output){
  eslt_ErrorCode retVal = esl_AES_CommonProcChecks(workSpace, ESL_WST_ALGO_AES192, ESL_MAXSIZEOF_WS_AES192, input, output);

  if(retVal != ESL_ERC_NO_ERROR){
  }
  else if(outputSize == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else{
    actRETURNCODE result;
    actLengthType dec_len = *outputSize;

    result = actAESDecrypt(&workSpace->wsAES, input, (actLengthType)inputSize, output, &dec_len, FALSE, workSpace->header.watchdog);

    if(result == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
    }
    else{
      *outputSize = (eslt_Length)(dec_len);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptAES192(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192) workSpace, VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (outputSize == NULL_PTR) || (output == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_AES192, ESL_WST_ALGO_AES192)) != ESL_ERC_NO_ERROR){
  }

  else{
    actRETURNCODE result;
    actLengthType dec_len = *outputSize;

    result = actAESDecrypt(&workSpace->wsAES, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR, 0, output, &dec_len, TRUE, workSpace->header.watchdog);

    if(result == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
    }
    else if(result == actEXCEPTION_INPUT_LENGTH){
      retVal = ESL_ERC_INPUT_INVALID;
    }
    else if(result == actEXCEPTION_PADDING){
      retVal = ESL_ERC_AES_PADDING_INVALID;
    }
    else{
      *outputSize = (eslt_Length)(dec_len);

      esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsAES);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptAES192Block(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192Block) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal = esl_AES_CommonInitChecks(workSpace, ESL_MAXSIZEOF_WS_AES192BLOCK, key);

  if(retVal == ESL_ERC_NO_ERROR){
    if(actOK == actAESInitDecryptBlock(&workSpace->wsAES, key, ESL_SIZEOF_AES192_KEY, workSpace->header.watchdog)){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_AES192);
    }
    else{
      retVal = ESL_ERC_PARAMETER_INVALID;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptAES192Block(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192Block) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock){
  eslt_ErrorCode retVal = esl_AES_CommonProcChecks(workSpace, ESL_WST_ALGO_AES192, ESL_MAXSIZEOF_WS_AES192BLOCK, inputBlock, outputBlock);

  if(retVal == ESL_ERC_NO_ERROR){
    actAESDecryptBlock(&workSpace->wsAES, inputBlock, outputBlock, workSpace->header.watchdog);
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

