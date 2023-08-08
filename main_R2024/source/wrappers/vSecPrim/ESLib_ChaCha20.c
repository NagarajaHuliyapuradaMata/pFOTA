

#define ESLIB_CHACHA20_SOURCE
#include "ESLib_Helper.hpp"

#include "actIChaCha20.hpp"

#if(VSECPRIM_CHA_CHA20_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL VSECPRIM_FUNC( eslt_ErrorCode ) initChaCha20   (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaCha20 ) workSpace, VSECPRIM_P2CONST_PARA( eslt_Byte ) key, VSECPRIM_P2CONST_PARA( eslt_Byte ) nonce, const eslt_Size32 blockCount);
VSECPRIM_LOCAL VSECPRIM_FUNC( eslt_ErrorCode ) cipherChaCha20 (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaCha20 ) workSpace, VSECPRIM_P2CONST_PARA( eslt_Byte ) in, const eslt_Length inSize, VSECPRIM_P2VAR_PARA( eslt_Byte ) out, VSECPRIM_P2VAR_PARA( eslt_Length ) outSize);

VSECPRIM_FUNC( eslt_ErrorCode ) esl_initEncryptChaCha20 (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaCha20 ) workSpace,
                                                         VSECPRIM_P2CONST_PARA( eslt_Byte ) key,
                                                         VSECPRIM_P2CONST_PARA( eslt_Byte ) nonce,
                                                         const eslt_Size32 blockCount){
  return initChaCha20 (workSpace, key, nonce, blockCount);
}

VSECPRIM_FUNC( eslt_ErrorCode ) esl_initDecryptChaCha20 (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaCha20 ) workSpace,
                                                         VSECPRIM_P2CONST_PARA( eslt_Byte ) key,
                                                         VSECPRIM_P2CONST_PARA( eslt_Byte ) nonce,
                                                         const eslt_Size32 blockCount){
  return initChaCha20 (workSpace, key, nonce, blockCount);
}

VSECPRIM_FUNC( eslt_ErrorCode ) esl_encryptChaCha20 (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaCha20 ) workSpace,
                                                     VSECPRIM_P2CONST_PARA( eslt_Byte )       in,
                                                     const eslt_Length      inSize,
                                                     VSECPRIM_P2VAR_PARA( eslt_Byte )       out,
                                                     VSECPRIM_P2VAR_PARA( eslt_Length )     outSize){
  return cipherChaCha20 (workSpace, in, inSize, out, outSize);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptChaCha20(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaCha20) workSpace,
                                                          VSECPRIM_P2CONST_PARA(eslt_Byte)       in,
                                                          const eslt_Length      inSize,
                                                          VSECPRIM_P2VAR_PARA(eslt_Byte)       out,
                                                          VSECPRIM_P2VAR_PARA(eslt_Length)     outSize){
  eslt_ErrorCode  result;

  result = esl_encryptChaCha20(workSpace, in, inSize, out, outSize);

  esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsChaCha20);

  return result;
}

VSECPRIM_FUNC( eslt_ErrorCode ) esl_decryptChaCha20 (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaCha20 ) workSpace,
                                                     VSECPRIM_P2CONST_PARA( eslt_Byte )       in,
                                                     const eslt_Length      inSize,
                                                     VSECPRIM_P2VAR_PARA( eslt_Byte )       out,
                                                     VSECPRIM_P2VAR_PARA( eslt_Length )     outSize){
  return cipherChaCha20 (workSpace, in, inSize, out, outSize);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptChaCha20(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaCha20) workSpace,
                                                          VSECPRIM_P2CONST_PARA(eslt_Byte)       in,
                                                          const eslt_Length      inSize,
                                                          VSECPRIM_P2VAR_PARA(eslt_Byte)       out,
                                                          VSECPRIM_P2VAR_PARA(eslt_Length)     outSize){
  eslt_ErrorCode  result;

  result = esl_decryptChaCha20(workSpace, in, inSize, out, outSize);

  esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsChaCha20);

  return result;
}

VSECPRIM_LOCAL VSECPRIM_FUNC( eslt_ErrorCode ) initChaCha20 (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaCha20 ) workSpace,
                                                     VSECPRIM_P2CONST_PARA( eslt_Byte ) key,
                                                     VSECPRIM_P2CONST_PARA( eslt_Byte ) nonce,
                                                     const eslt_Size32 blockCount){
  if((NULL == workSpace)
    || (NULL == key)
    || (NULL == nonce)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if(ESL_SIZEOF_WS_ChaCha20 > workSpace->header.size){
    return ESL_ERC_WS_TOO_SMALL;
  }

  actChaCha20Init ((VSECPRIM_P2VAR_PARA( actChaCha20Context )) workSpace->wsChaCha20, key, nonce, blockCount, workSpace->header.watchdog);

  workSpace->header.status = (ESL_WST_ALGO_ChaCha20 | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_LOCAL VSECPRIM_FUNC(eslt_ErrorCode) cipherChaCha20(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaCha20) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte)       in,
  const eslt_Length      inSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte)       out,
  VSECPRIM_P2VAR_PARA(eslt_Length)     outSize){
  if((NULL == workSpace)
    || (NULL == in)
    || (NULL == out) || (NULL == outSize)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if(*outSize < inSize){
    return ESL_ERC_BUFFER_TOO_SMALL;
  }

  if((ESL_WST_ALGO_ChaCha20 != (workSpace->header.status & ESL_WST_M_ALGO))
    || (ESL_WST_M_RUNNING != (workSpace->header.status & ESL_WST_M_RUNNING))){
    return ESL_ERC_WS_STATE_INVALID;
  }

  actChaCha20Cipher ((VSECPRIM_P2VAR_PARA( actChaCha20Context )) workSpace->wsChaCha20, in, inSize, out, workSpace->header.watchdog);

  *outSize = inSize;

  return ESL_ERC_NO_ERROR;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

