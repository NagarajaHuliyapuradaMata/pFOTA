

#define ESLIB_GCM_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIGCM.hpp"

#if(VSECPRIM_GCM_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptGCM(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,                                                VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) iv, const eslt_Length ivLength){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (key == NULL_PTR) || (iv == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_GCM)) != ESL_ERC_NO_ERROR){
  }

  else if((keyLength != ESL_SIZEOF_AES128_KEY) && (keyLength != ESL_SIZEOF_AES192_KEY) && (keyLength != ESL_SIZEOF_AES256_KEY)){
    retVal = ESL_ERC_GCM_INVALID_KEY_LENGTH;
  }

  else if(ivLength < 1u){
    retVal = ESL_ERC_INVALID_IV_LENGTH;
  }
  else{
    (void)actGCMInit(&workSpace->wsGCM, key, (actLengthType) keyLength, iv, (actLengthType) ivLength, workSpace->header.watchdog);

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_GCM);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateAuthDataEncryptGCM(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) input, const eslt_Length inputLength){
  eslt_ErrorCode retVal;
  VSECPRIM_P2VAR_PARA(actU8) output = NULL_PTR;
  actLengthType bytes_out;

  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GCM, ESL_WST_ALGO_GCM)) != ESL_ERC_NO_ERROR){
  }

  else if(STATE_AAD != workSpace->wsGCM.state){
    retVal = ESL_ERC_GCM_STATE_INVALID;
  }

  else if(actEXCEPTION_LENGTH == actGCMEncryptUpdate(&workSpace->wsGCM, input, (actLengthType)inputLength, output, &bytes_out, workSpace->header.watchdog)){
    retVal = ESL_ERC_GCM_TOTAL_LENGTH_OVERFLOW;
  }
  else{
    retVal = ESL_ERC_NO_ERROR;
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updatePlaintextEncryptGCM(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,                                                           VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,                                                           const eslt_Length inputLength, VSECPRIM_P2VAR_PARA(eslt_Byte) output, VSECPRIM_P2VAR_PARA(eslt_Size32) bytes_out){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (input == NULL_PTR) || (output == NULL_PTR) || (bytes_out == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GCM, ESL_WST_ALGO_GCM)) != ESL_ERC_NO_ERROR){
  }

  else{
    if(STATE_CIPHERTEXT != workSpace->wsGCM.state){
      retVal = (actGCMTriggerState(&workSpace->wsGCM, workSpace->header.watchdog) == actOK) ? ESL_ERC_NO_ERROR : ESL_ERC_WS_STATE_INVALID;
    }

    if(retVal == ESL_ERC_NO_ERROR){
      if(actEXCEPTION_LENGTH ==
        actGCMEncryptUpdate(&workSpace->wsGCM, input, (actLengthType)inputLength, output, (VSECPRIM_P2VAR_PARA(actLengthType)) bytes_out, workSpace->header.watchdog))
      {
        retVal = ESL_ERC_GCM_TOTAL_LENGTH_OVERFLOW;
      }
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptGCM(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,                                                    VSECPRIM_P2VAR_PARA(eslt_Byte) output, VSECPRIM_P2VAR_PARA(eslt_Size32) bytes_out, VSECPRIM_P2VAR_PARA(eslt_Byte) tag){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (output == NULL_PTR) || (bytes_out == NULL_PTR) || (tag == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GCM, ESL_WST_ALGO_GCM)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actGCMEncryptFinalize(&workSpace->wsGCM, output, (VSECPRIM_P2VAR_PARA(actLengthType)) bytes_out, tag, workSpace->header.watchdog);
    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsGCM);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptGCM(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,                                                VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) iv, const eslt_Length ivLength){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (key == NULL_PTR) || (iv == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_GCM)) != ESL_ERC_NO_ERROR){
  }

  else if((keyLength != ESL_SIZEOF_AES128_KEY) && (keyLength != ESL_SIZEOF_AES192_KEY) && (keyLength != ESL_SIZEOF_AES256_KEY)){
    retVal = ESL_ERC_GCM_INVALID_KEY_LENGTH;
  }

  else if(ivLength < 1u){
    retVal = ESL_ERC_INVALID_IV_LENGTH;
  }
  else{
    (void)actGCMInit(&workSpace->wsGCM, key, (actLengthType)keyLength, iv, (actLengthType)ivLength, workSpace->header.watchdog);

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_GCM);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateAuthDataDecryptGCM(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) input, const eslt_Length inputLength){
  eslt_ErrorCode retVal;
  actU8 *output = NULL_PTR;
  actLengthType bytes_out;

  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GCM, ESL_WST_ALGO_GCM)) != ESL_ERC_NO_ERROR){
  }

  else if(STATE_AAD != workSpace->wsGCM.state){
    retVal = ESL_ERC_GCM_STATE_INVALID;
  }

  else if(actEXCEPTION_LENGTH == actGCMDecryptUpdate(&workSpace->wsGCM, input, (actLengthType)inputLength, output, &bytes_out, workSpace->header.watchdog)){
    retVal = ESL_ERC_GCM_TOTAL_LENGTH_OVERFLOW;
  }
  else{
    retVal = ESL_ERC_NO_ERROR;
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateCiphertextDecryptGCM(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,                                                            VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,                                                            const eslt_Length inputLength, VSECPRIM_P2VAR_PARA(eslt_Byte) output, VSECPRIM_P2VAR_PARA(eslt_Size32) bytes_out){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (input == NULL_PTR) || (output == NULL_PTR) || (bytes_out == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GCM, ESL_WST_ALGO_GCM)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(STATE_CIPHERTEXT != workSpace->wsGCM.state){
      retVal = (actGCMTriggerState(&workSpace->wsGCM, workSpace->header.watchdog) == actOK) ? ESL_ERC_NO_ERROR : ESL_ERC_WS_STATE_INVALID;
    }

    if(retVal == ESL_ERC_NO_ERROR){
      if(actEXCEPTION_LENGTH ==
         actGCMDecryptUpdate(&workSpace->wsGCM, input, (actLengthType)inputLength, output, (VSECPRIM_P2VAR_PARA(actLengthType)) bytes_out, workSpace->header.watchdog))
      {
        retVal = ESL_ERC_GCM_TOTAL_LENGTH_OVERFLOW;
      }
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptGCM(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,                                                    VSECPRIM_P2VAR_PARA(eslt_Byte) output, VSECPRIM_P2VAR_PARA(eslt_Size32) bytes_out, VSECPRIM_P2CONST_PARA(eslt_Byte) tag){
  eslt_ErrorCode retVal;
  eslt_Byte tmpTag[ESL_SIZEOF_GCM_TAG];

  if((workSpace == NULL_PTR) || (output == NULL_PTR) || (bytes_out == NULL_PTR) || (tag == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GCM, ESL_WST_ALGO_GCM)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actGCMDecryptFinalize(&workSpace->wsGCM, output, (VSECPRIM_P2VAR_PARA(actLengthType)) bytes_out, tmpTag, workSpace->header.watchdog);

    if(actMemcmp(tmpTag, tag, ESL_SIZEOF_GCM_TAG) != TRUE){
      retVal = ESL_ERC_GCM_TAG_VERIFICATION_FAILED;
    }

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsGCM);
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

