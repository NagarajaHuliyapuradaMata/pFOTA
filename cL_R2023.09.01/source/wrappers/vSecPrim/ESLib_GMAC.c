

#define ESLIB_GMAC_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIGCM.hpp"

#if(VSECPRIM_GMAC_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initGMAC(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace
   ,                                          const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Length ivLength, VSECPRIM_P2CONST_PARA(eslt_Byte) iv){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (key == NULL_PTR) || (iv == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_GMAC)) != ESL_ERC_NO_ERROR){
  }

  else if((keyLength != ESL_SIZEOF_AES128_KEY) && (keyLength != ESL_SIZEOF_AES192_KEY) && (keyLength != ESL_SIZEOF_AES256_KEY)){
    retVal = ESL_ERC_GCM_INVALID_KEY_LENGTH;
  }

  else if(ivLength < 1u){
    retVal = ESL_ERC_INVALID_IV_LENGTH;
  }
  else{
    (void)actGCMInit(&workSpace->wsGMAC, key, keyLength, iv, ivLength, workSpace->header.watchdog);

    workSpace->header.status = (ESL_WST_ALGO_GMAC | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateGMAC(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace, const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GMAC, ESL_WST_ALGO_GMAC)) != ESL_ERC_NO_ERROR){
  }

  else{
    actRETURNCODE result = actGCMTransform(&workSpace->wsGMAC, input, inputLength, NULL_PTR, NULL_PTR, 0u, workSpace->header.watchdog);
    if(result == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_GCM_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeGMAC(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) tag){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (tag == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GMAC, ESL_WST_ALGO_GMAC)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actGMACFinalize(&workSpace->wsGMAC, tag, workSpace->header.watchdog);

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsGMAC);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyGMAC(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) tag){
  eslt_ErrorCode retVal;
  eslt_Byte tmpTag[ESL_SIZEOF_GCM_TAG];
  actMemClear(tmpTag, ESL_SIZEOF_GCM_TAG);

  if((workSpace == NULL_PTR) || (tag == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GMAC, ESL_WST_ALGO_GMAC)) != ESL_ERC_NO_ERROR){
  }

  else{
    (void)actGMACFinalize(&workSpace->wsGMAC, tmpTag, workSpace->header.watchdog);
    if(actMemcmp(tmpTag, tag, ESL_SIZEOF_GCM_TAG) != TRUE){
      retVal = ESL_ERC_GCM_TAG_VERIFICATION_FAILED;
    }

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsGMAC);
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

