

#define ESLIB_SHA1_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actISHA3.hpp"

#if(VSECPRIM_SHA3_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHA3(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA3) workSpace,
  const eslt_Length          bitLength){
  eslt_ErrorCode  retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_SHA3)) != ESL_ERC_NO_ERROR){
  }

  else if((bitLength != 224u) && (bitLength != 256u) && (bitLength != 384u) && (bitLength != 512u)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    (void)actSHA3Init (&workSpace->wsSHA3, bitLength);

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SHA3);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHA3(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA3) workSpace,
  const  eslt_Length          inputSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode  retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SHA3, ESL_WST_ALGO_SHA3)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actSHA3Update (&workSpace->wsSHA3, input, (actLengthType)inputSize, workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_MODE){
      retVal = ESL_ERC_STATE_INVALID;
    }

  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHA3(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA3) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest,
  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength){
  eslt_ErrorCode  retVal;

  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR) || (messageDigestLength == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SHA3, ESL_WST_ALGO_SHA3)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(*messageDigestLength >= (eslt_Length)(Esl_BitsToBytes(workSpace->wsSHA3.strength))){
      (void)actSHA3Finalize(&workSpace->wsSHA3, messageDigest, workSpace->header.watchdog);
      *messageDigestLength = (eslt_Length)(Esl_BitsToBytes(workSpace->wsSHA3.strength));
    }
    else{
      (void)actSHA3Finalize(&workSpace->wsSHA3, workSpace->wsSHA3.digest, workSpace->header.watchdog);
      actMemCpyByteArray(messageDigest, workSpace->wsSHA3.digest, *messageDigestLength);
    }

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSHA3);
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

