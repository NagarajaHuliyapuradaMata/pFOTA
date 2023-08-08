

#define ESLIB_CMACAES128_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actICMACAES.hpp"

#if(VSECPRIM_CMAC_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initCMACAES128(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace, const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_CMACAES)) != ESL_ERC_NO_ERROR){
  }
  else if(key == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if(keyLength != ESL_SIZEOF_AES128_KEY){
    retVal = ESL_ERC_HMAC_KEY_LENGTH_OUT_OF_RANGE;
  }
  else{
    (void)actCMACAESInit(&workSpace->wsCMACAESbuffer, key, ESL_SIZEOF_AES128_KEY, workSpace->header.watchdog);

    workSpace->wsCMACAES = (VSECPRIM_P2VAR_PARA(eslt_Byte))&(workSpace->wsCMACAESbuffer);

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_CMACAES128);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_getExpandedKeyCMACAES128(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceCMACAES) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Byte) keyPtr,
  VSECPRIM_P2VAR_PARA(eslt_Length) keyLengthPtr){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  if((workSpace == NULL_PTR) || (keyLengthPtr == NULL_PTR) || (keyPtr == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((workSpace->header.status & ESL_WST_M_RUNNING) != ESL_WST_M_RUNNING){
    retVal = ESL_ERC_WS_STATE_INVALID;
  }
  else if(*keyLengthPtr < 256u){
    retVal = ESL_ERC_INPUT_INVALID;
  }
  else{
    *keyLengthPtr = 256u;
    actMemCpyByteArray(keyPtr, workSpace->wsCMACAESbuffer.e_key, *keyLengthPtr);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initExpandedCMACAES128(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) expandedKey, const eslt_Length expandedKeyLength){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;
  VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) internalWorkspace;

  if((workSpace == NULL_PTR) || (expandedKey == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if(workSpace->header.size < ESL_MAXSIZEOF_WS_CMACAES){
    retVal = ESL_ERC_WS_TOO_SMALL;
  }

  else if(expandedKeyLength != 256u){
    retVal = ESL_ERC_HMAC_KEY_LENGTH_OUT_OF_RANGE;
  }
  else{
    internalWorkspace = &workSpace->wsCMACAESbuffer;
    actMemset(internalWorkspace->buffer, 0x00u, actAES_BLOCK_SIZE);
    internalWorkspace->buffer_used = 0u;
    internalWorkspace->key_dword_len = 4u;
    actMemCpyByteArray(internalWorkspace->e_key, expandedKey, expandedKeyLength);

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_CMACAES128);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateCMACAES128(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace, const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_CMACAES, ESL_WST_ALGO_CMACAES128)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actCMACAESUpdate(&workSpace->wsCMACAESbuffer, input, (actLengthType)inputLength, workSpace->header.watchdog);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeCMACAES128(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageCMAC){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (messageCMAC == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_CMACAES, ESL_WST_ALGO_CMACAES128)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actCMACAESFinalize(&workSpace->wsCMACAESbuffer, messageCMAC, workSpace->header.watchdog);

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsCMACAESbuffer);
  }
  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyCMACAES128(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageCMAC){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (messageCMAC == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_CMACAES, ESL_WST_ALGO_CMACAES128)) != ESL_ERC_NO_ERROR){
  }
  else{
    eslt_Byte tmpMAC[ESL_SIZEOF_AES128_BLOCK];
    actMemClear(tmpMAC, ESL_SIZEOF_AES256_BLOCK);

    (void)esl_finalizeCMACAES128(workSpace, tmpMAC);

    if(actMemcmp(tmpMAC, messageCMAC, ESL_SIZEOF_AES128_BLOCK) == FALSE){
      retVal = ESL_ERC_HMAC_INCORRECT_MAC;
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

