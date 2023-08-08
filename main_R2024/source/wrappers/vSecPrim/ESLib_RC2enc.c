

#define ESLIB_RC2ENC_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actRC2.hpp"

#if(VSECPRIM_RC2_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptRC2(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2) workSpace,
                                                 VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Length key_len, const eslt_Length eff_key_len,
                                                 const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode, VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector){
  if((workSpace == NULL_PTR) || (key == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if(workSpace->header.size < ESL_MINSIZEOF_WS_RC2){
    return ESL_ERC_WS_TOO_SMALL;
  }

  if(paddingMode != ESL_PM_PKCS5){
    return ESL_ERC_MODE_INVALID;
  }

  if(key_len < actRC2_MIN_KEY_SIZE){
    return ESL_ERC_INPUT_INVALID;
  }

  if(blockMode == ESL_BM_ECB){
    actRC2Init((VSECPRIM_P2VAR_PARA(actRC2STRUCT)) workSpace->wsRC2, key, (actLengthType)key_len, (actLengthType)eff_key_len, initializationVector, actRC2_ECB, workSpace->header.watchdog);
  }
  else if(blockMode == ESL_BM_CBC){
    actRC2Init((VSECPRIM_P2VAR_PARA(actRC2STRUCT)) workSpace->wsRC2, key, (actLengthType)key_len, (actLengthType)eff_key_len, initializationVector, actRC2_CBC, workSpace->header.watchdog);
  }
  else{
    return ESL_ERC_MODE_INVALID;
  }

  workSpace->header.status = (ESL_WST_ALGO_RC2 | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRC2(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2) workSpace,
                                             const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input, VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output){
  if((workSpace == NULL_PTR) || (input == NULL_PTR) || (output == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_RC2){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((workSpace->header.status & ESL_WST_M_RUNNING) == 0u){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((inputSize % ESL_SIZEOF_RC2_BLOCK) == 0u){
    if(workSpace->header.size < ESL_MINSIZEOF_WS_RC2){
      return ESL_ERC_WS_TOO_SMALL;
    }
  }
  else{
    if(workSpace->header.size < ESL_MAXSIZEOF_WS_RC2){
      return ESL_ERC_WS_TOO_SMALL;
    }
  }

  {
    actRETURNCODE result;
    actLengthType enc_len = *outputSize;

    result = actRC2Encrypt((VSECPRIM_P2VAR_PARA(actRC2STRUCT)) workSpace->wsRC2, input, (actLengthType)inputSize, output, &enc_len, FALSE, workSpace->header.watchdog);
    if(result == actEXCEPTION_LENGTH){
      return ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
    }
    else{
      *outputSize = (eslt_Length)(enc_len);
    }
  }

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptRC2(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2) workSpace, VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output){
  actRETURNCODE result;
  actLengthType enc_len;

  if((workSpace == NULL_PTR) || (output == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_RC2){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((workSpace->header.status & ESL_WST_M_RUNNING) == 0u){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if(workSpace->header.size < ESL_MAXSIZEOF_WS_RC2){
    return ESL_ERC_WS_TOO_SMALL;
  }

  enc_len = *outputSize;

  result = actRC2Encrypt((VSECPRIM_P2VAR_PARA(actRC2STRUCT)) workSpace->wsRC2, (VSECPRIM_P2CONST_PARA(eslt_Byte)) NULL_PTR, 0u, output, &enc_len, TRUE, workSpace->header.watchdog);
  if(result == actEXCEPTION_LENGTH){
    return ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
  }
  else{
    *outputSize = (eslt_Length)enc_len;
  }

  esl_ResetAndClearWorkspace(&workSpace->header, workSpace->wsRC2);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptRC2Block(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2Block) workSpace,
                                                      VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Length key_len, const eslt_Length eff_key_len){
  if((workSpace == NULL_PTR) || (key == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if(workSpace->header.size < ESL_MAXSIZEOF_WS_RC2BLOCK){
    return ESL_ERC_WS_TOO_SMALL;
  }

  if(key_len < actRC2_MIN_KEY_SIZE){
    return ESL_ERC_INPUT_INVALID;
  }

  actRC2InitCryptBlock((VSECPRIM_P2VAR_PARA(actRC2STRUCT)) workSpace->wsRC2Block, key, (actLengthType)key_len, (actLengthType)eff_key_len, workSpace->header.watchdog);

  workSpace->header.status = (ESL_WST_ALGO_RC2 | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRC2Block(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2Block) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock){
  if((workSpace == NULL_PTR) || (inputBlock == NULL_PTR) || (outputBlock == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_RC2){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((workSpace->header.status & ESL_WST_M_RUNNING) == 0u){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if(workSpace->header.size < ESL_MAXSIZEOF_WS_RC2BLOCK){
    return ESL_ERC_WS_TOO_SMALL;
  }

  actRC2EncryptBlock((VSECPRIM_P2VAR_PARA(actRC2STRUCT)) workSpace->wsRC2Block, inputBlock, outputBlock, workSpace->header.watchdog);

  return ESL_ERC_NO_ERROR;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

