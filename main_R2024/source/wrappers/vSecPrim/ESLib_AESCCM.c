

#define ESLIB_AESCCM_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIAESCCM.hpp"

#if(VSECPRIM_AES_CCM_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initAESCCMLengthCheck(
  const eslt_Length keyLength,
  const eslt_Length nonceLength,
  const eslt_Length msgLength,
  const eslt_Byte authenticationFieldSize,
  const eslt_Byte lengthFieldSize);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initAESCCMLengthFieldCheck(
  const eslt_Length msgLength,
  const eslt_Byte lengthFieldSize);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initAESCCMLengthCheck(
  const eslt_Length keyLength,
  const eslt_Length nonceLength,
  const eslt_Length msgLength,
  const eslt_Byte authenticationFieldSize,
  const eslt_Byte lengthFieldSize){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;
  eslt_Byte expectedNonceLength = (eslt_Byte)15u - lengthFieldSize;

  if(keyLength != ESL_SIZEOF_AES128_KEY){
    retVal = ESL_ERC_INVALID_LENGTH;
  }

  if(retVal == ESL_ERC_NO_ERROR){
    if(authenticationFieldSize < 4u){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else{
      if((authenticationFieldSize > 16u) || ((authenticationFieldSize % 2u) != 0u))
      {
        retVal = ESL_ERC_INVALID_LENGTH;
      }
    }
  }

  if(retVal == ESL_ERC_NO_ERROR){
    retVal = esl_initAESCCMLengthFieldCheck(msgLength, lengthFieldSize);
  }

  if(retVal == ESL_ERC_NO_ERROR){
    if(nonceLength != (eslt_Length)(expectedNonceLength)){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initAESCCMLengthFieldCheck(
  const eslt_Length msgLength,
  const eslt_Byte lengthFieldSize){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  if((lengthFieldSize < 2u) || (lengthFieldSize > 8u)){
    retVal = ESL_ERC_INVALID_LENGTH;
  }

# if(vSecPrim_GetSizeOfEsltLengthOfGeneral() == VSECPRIM_SIZE_UINT32)
  if(retVal == ESL_ERC_NO_ERROR){
    if((lengthFieldSize == 2u) && (msgLength > 0xFFFFu)){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else{
      if((lengthFieldSize == 3u) && (msgLength > 0x00FFFFFFu))
      {
        retVal = ESL_ERC_INVALID_LENGTH;
      }
    }
  }
# else
  VSECPRIM_DUMMY_STATEMENT_CONST(msgLength);
# endif

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initAESCCM (
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAESCCM) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) key,
  const eslt_Length keyLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte)nonce,
  const eslt_Length nonceLength,
  const eslt_Length aadLength,
  const eslt_Length msgLength,
  const eslt_Byte authenticationFieldSize,
  const eslt_Byte lengthFieldSize){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (key == NULL_PTR) || (nonce == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_initAESCCMLengthCheck(keyLength, nonceLength, msgLength, authenticationFieldSize, lengthFieldSize)) != ESL_ERC_NO_ERROR){
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_AESCCM)) != ESL_ERC_NO_ERROR){
  }
  else{
    actAESCCMInit(&workSpace->wsAESCCM, key, (actLengthType)keyLength,
                  nonce, (actLengthType)nonceLength, (actLengthType)aadLength, (actLengthType)msgLength,
                  authenticationFieldSize, lengthFieldSize, workSpace->header.watchdog);

    workSpace->header.status = (ESL_WST_ALGO_AES128CCM | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateAESCCMEncrypt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAESCCM) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) aad,
  const eslt_Length aadSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) msg,
  const eslt_Length msgSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte)out,
  VSECPRIM_P2VAR_PARA(eslt_Length) outSize){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) ||
      ((aad == NULL_PTR) && (aadSize > 0u)) ||
      ((msg == NULL_PTR) && (msgSize > 0u)) ||
      (out == NULL_PTR) || (outSize == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_AESCCM, ESL_WST_ALGO_AES128CCM)) != ESL_ERC_NO_ERROR){
  }
  else if(*outSize < (msgSize - (msgSize % ESL_SIZEOF_AES_BLOCK))){
    retVal = ESL_ERC_BUFFER_TOO_SMALL;
  }
  else{
    actRetVal = actAESCCMUpdateEncrypt(&workSpace->wsAESCCM, aad, (actLengthType)aadSize, msg, (actLengthType)msgSize, out, workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_CCM_TOTAL_LENGTH_OVERFLOW;
      *outSize = 0u;
    }
    else if(actRetVal == actEXCEPTION_INPUT_LENGTH){
      retVal = ESL_ERC_PARAMETER_INVALID;
      *outSize = 0u;
    }
    else if(actRetVal == actEXCEPTION_MODE){
      retVal = ESL_ERC_STATE_INVALID;
      *outSize = 0u;
    }
    else{
      *outSize = (msgSize - (msgSize % ESL_SIZEOF_AES_BLOCK));
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateAESCCMDecrypt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAESCCM) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) aad,
  const eslt_Length aadSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) encMsg,
  const eslt_Length encMsgSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte)out,
  VSECPRIM_P2VAR_PARA(eslt_Length) outSize){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) ||
    ((encMsg == NULL_PTR) && (encMsgSize > 0u)) ||
    ((aad == NULL_PTR) && (aadSize > 0u)) ||
    (out == NULL_PTR) ||  (outSize == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_AESCCM, ESL_WST_ALGO_AES128CCM)) != ESL_ERC_NO_ERROR){
  }
  else if(*outSize < (encMsgSize - (encMsgSize % ESL_SIZEOF_AES_BLOCK))){
    retVal = ESL_ERC_BUFFER_TOO_SMALL;
  }
  else{
    actRetVal = actAESCCMUpdateDecrypt(&workSpace->wsAESCCM, aad, (actLengthType)aadSize, encMsg, (actLengthType)encMsgSize, out, workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_CCM_TOTAL_LENGTH_OVERFLOW;
      *outSize = 0u;
    }
    else if(actRetVal == actEXCEPTION_INPUT_LENGTH){
      retVal = ESL_ERC_PARAMETER_INVALID;
      *outSize = 0u;
    }
    else if(actRetVal == actEXCEPTION_MODE){
      retVal = ESL_ERC_STATE_INVALID;
      *outSize = 0u;
    }
    else{
      *outSize = (encMsgSize - (encMsgSize % ESL_SIZEOF_AES_BLOCK));
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeAESCCMEncrypt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAESCCM) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Byte) out,
  VSECPRIM_P2VAR_PARA(eslt_Length) outLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) tag,
  VSECPRIM_P2VAR_PARA(eslt_Length) tagLength){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (outLength == NULL_PTR) || (tag == NULL_PTR) || (tagLength == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((out == NULL_PTR) && (*outLength > 0u)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if(*outLength < workSpace->wsAESCCM.remainingLen){
    retVal = ESL_ERC_BUFFER_TOO_SMALL;
  }
  else if(*tagLength < workSpace->wsAESCCM.authFieldSize){
    retVal = ESL_ERC_BUFFER_TOO_SMALL;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_AESCCM, ESL_WST_ALGO_AES128CCM)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actAESCCMFinalizeEncrypt(&workSpace->wsAESCCM, out, tag, workSpace->header.watchdog);

    if(actRetVal == actOK){
      *outLength = (eslt_Length)workSpace->wsAESCCM.remainingLen;
      *tagLength = (eslt_Length)workSpace->wsAESCCM.authFieldSize;

    }
    else{
      *outLength = 0u;
      *tagLength = 0u;
      retVal = ESL_ERC_INVALID_LENGTH;
    }

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsAESCCM);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeAESCCMDecrypt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAESCCM) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Byte) out,
  VSECPRIM_P2VAR_PARA(eslt_Length) outLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) tag){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  actU8 tmpTag[ESL_SIZEOF_CCM_TAG];

  if((workSpace == NULL_PTR) || (outLength == NULL_PTR) || (tag == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((out == NULL_PTR) && (*outLength > 0u)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if(*outLength < workSpace->wsAESCCM.remainingLen){
    retVal = ESL_ERC_BUFFER_TOO_SMALL;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_AESCCM, ESL_WST_ALGO_AES128CCM)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actAESCCMFinalizeDecrypt(&workSpace->wsAESCCM, out, tmpTag, workSpace->header.watchdog);

    if(actRetVal == actOK){
      if(actMemcmp(tmpTag, tag, workSpace->wsAESCCM.authFieldSize) != TRUE)
      {
        retVal = ESL_ERC_INCORRECT_TAG;
      }

      *outLength = (eslt_Length)workSpace->wsAESCCM.remainingLen;
    }
    else{
      *outLength = 0u;
      retVal = ESL_ERC_INVALID_LENGTH;
    }

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsAESCCM);
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

