

#define ESLIB_TDESENC_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actTDES.hpp"

#if(VSECPRIM_TDES_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptTDES(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDES) workSpace,
                                                  VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Byte key_len,
                                                  const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode, VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector){
  if((workSpace == NULL_PTR) || (key == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((key_len != ESL_SIZEOF_2TDES_KEY) && (key_len != ESL_SIZEOF_3TDES_KEY)){
    return ESL_ERC_TDES_KEY_LENGTH_INVALID;
  }

  if(workSpace->header.size < ESL_MINSIZEOF_WS_TDES){
    return ESL_ERC_WS_TOO_SMALL;
  }

  if(paddingMode != ESL_PM_PKCS5){
    return ESL_ERC_MODE_INVALID;
  }

  if(blockMode == ESL_BM_ECB){
    actTDESInitEncrypt((VSECPRIM_P2VAR_PARA(actTDESSTRUCT)) workSpace->wsTDES, key, (actU8)key_len, initializationVector, actDES_ECB, workSpace->header.watchdog);
  }
  else if(blockMode == ESL_BM_CBC){
    actTDESInitEncrypt((VSECPRIM_P2VAR_PARA(actTDESSTRUCT)) workSpace->wsTDES, key, (actU8)key_len, initializationVector, actDES_CBC, workSpace->header.watchdog);
  }
  else{
    return ESL_ERC_MODE_INVALID;
  }

  workSpace->header.status = (ESL_WST_ALGO_TDES | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptTDES(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDES) workSpace,
                                              const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input, VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output){
  if((workSpace == NULL_PTR) || (input == NULL_PTR) || (output == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_TDES){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((workSpace->header.status & ESL_WST_M_RUNNING) == 0u){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((inputSize % ESL_SIZEOF_DES_BLOCK) == 0u){
    if(workSpace->header.size < ESL_MINSIZEOF_WS_TDES){
      return ESL_ERC_WS_TOO_SMALL;
    }
  }
  else{
    if(workSpace->header.size < ESL_MAXSIZEOF_WS_TDES){
      return ESL_ERC_WS_TOO_SMALL;
    }
  }

  {
    actRETURNCODE result;
    actLengthType enc_len = *outputSize;

    result = actTDESEncrypt((VSECPRIM_P2VAR_PARA(actTDESSTRUCT)) workSpace->wsTDES, input, (actLengthType)inputSize, output, &enc_len, FALSE, workSpace->header.watchdog);
    if(result == actEXCEPTION_LENGTH){
      return ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
    }
    else{
      *outputSize = (eslt_Length)enc_len;
    }
  }

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptTDES(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDES) workSpace, VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output){
  if((workSpace == NULL_PTR) || (output == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_TDES){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((workSpace->header.status & ESL_WST_M_RUNNING) == 0u){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if(workSpace->header.size < ESL_MAXSIZEOF_WS_TDES){
    return ESL_ERC_WS_TOO_SMALL;
  }

  {
    actRETURNCODE result;
    actLengthType enc_len = *outputSize;

    result = actTDESEncrypt((VSECPRIM_P2VAR_PARA(actTDESSTRUCT)) workSpace->wsTDES, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR, 0u, output, &enc_len, TRUE, workSpace->header.watchdog);
    if(result == actEXCEPTION_LENGTH){
      return ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
    }
    else{
      *outputSize = (eslt_Length)enc_len;
    }
  }

  esl_ResetAndClearWorkspace(&workSpace->header, workSpace->wsTDES);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptTDESBlock(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDESBlock) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Byte key_len){
  if((workSpace == NULL_PTR) || (key == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((key_len != ESL_SIZEOF_2TDES_KEY) && (key_len != ESL_SIZEOF_3TDES_KEY)){
    return ESL_ERC_TDES_KEY_LENGTH_INVALID;
  }

  if(workSpace->header.size < ESL_MAXSIZEOF_WS_TDESBLOCK){
    return ESL_ERC_WS_TOO_SMALL;
  }

  actTDESInitEncryptBlock((VSECPRIM_P2VAR_PARA(actTDESSTRUCT)) workSpace->wsTDESBlock, key, (actU8)key_len, workSpace->header.watchdog);

  workSpace->header.status = (ESL_WST_ALGO_TDES | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptTDESBlock(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDESBlock) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock){
  if((workSpace == NULL_PTR) || (inputBlock == NULL_PTR) || (outputBlock == NULL_PTR)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((workSpace->header.status & ESL_WST_M_ALGO) != ESL_WST_ALGO_TDES){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if((workSpace->header.status & ESL_WST_M_RUNNING) == 0u){
    return ESL_ERC_WS_STATE_INVALID;
  }
  if(workSpace->header.size < ESL_MAXSIZEOF_WS_TDESBLOCK){
    return ESL_ERC_WS_TOO_SMALL;
  }

  actTDESCryptBlock((VSECPRIM_P2VAR_PARA(actTDESSTRUCT)) workSpace->wsTDESBlock, inputBlock, outputBlock, workSpace->header.watchdog);

  return ESL_ERC_NO_ERROR;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

