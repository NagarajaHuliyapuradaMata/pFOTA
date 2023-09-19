

#define ESLIB_SHAKE_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actISHAKE.hpp"

#if(VSECPRIM_SHA3_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHAKE(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHAKE) workSpace
   ,  const eslt_Length strength){
  eslt_ErrorCode  retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_SHAKE)) != ESL_ERC_NO_ERROR){
  }
  else if((strength != 128u) && (strength != 256u)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    (void)actSHAKEInit(&workSpace->wsSHAKE, strength);

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SHAKE);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHAKE(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHAKE) workSpace,
const  eslt_Length inputSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode  retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SHAKE, ESL_WST_ALGO_SHAKE)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actSHAKEUpdate(&workSpace->wsSHAKE, input, (actLengthType)inputSize, workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_MODE){
      retVal = ESL_ERC_STATE_INVALID;
    }

  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_getXOFDigestSHAKE(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHAKE) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest,
const eslt_Length digestLength){
  eslt_ErrorCode  retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SHA3, ESL_WST_ALGO_SHA3)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actSHAKEGetXOFDigest (&workSpace->wsSHAKE, messageDigest, (actLengthType)digestLength, workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_INVALID_LENGTH;
    }

  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHAKE(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHAKE) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest,
VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength){
  eslt_ErrorCode  retVal;

  if((workSpace == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SHA3, ESL_WST_ALGO_SHA3)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(messageDigest != NULL_PTR){
      if(messageDigestLength == NULL_PTR)
      {
        retVal = ESL_ERC_PARAMETER_INVALID;
      }
      else
      {
        if(*messageDigestLength >= (eslt_Length)(Esl_BitsToBytes(2u * workSpace->wsSHAKE.strength)))
        {
          (void)actSHAKEFinalize(&workSpace->wsSHAKE, messageDigest, workSpace->header.watchdog);
          *messageDigestLength = (eslt_Length)(Esl_BitsToBytes(2u * workSpace->wsSHAKE.strength));
        }
        else
        {
          (void)actSHAKEFinalize(&workSpace->wsSHAKE, workSpace->wsSHAKE.digest, workSpace->header.watchdog);
          actMemCpyByteArray(messageDigest, workSpace->wsSHAKE.digest, *messageDigestLength);
        }
      }
    }

    if(retVal == ESL_ERC_NO_ERROR){
      esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSHAKE);
    }
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

