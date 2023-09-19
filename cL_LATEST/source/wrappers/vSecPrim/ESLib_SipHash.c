

#define ESLIB_SIPHASH_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actISipHash.hpp"

#if(VSECPRIM_SIP_HASH_ENABLED == STD_ON)

#ifndef ACT_PLATFORM_UINT64_AVAILABLE
#error ACT_PLATFORM_UINT64_AVAILABLE must be defined
#endif

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSipHash(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSipHash) workSpace, const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_SIPHASH)) != ESL_ERC_NO_ERROR){
  }
  else if(key == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if(keyLength != ESL_SIZEOF_SIPHASH_KEY){
    retVal = ESL_ERC_HMAC_KEY_LENGTH_OUT_OF_RANGE;
  }
  else{
    (void)actSipHashInit(&workSpace->wsSipHash, key, ESL_SIZEOF_SIPHASH_KEY, workSpace->header.watchdog);

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SIPHASH);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSipHash(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSipHash) workSpace, const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SIPHASH, ESL_WST_ALGO_SIPHASH)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(actSipHashUpdate(&workSpace->wsSipHash, input, (actLengthType)inputLength, workSpace->header.watchdog) == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_INPUT_INVALID;
    }
  }
  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSipHash(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSipHash) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageMAC){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (messageMAC == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SIPHASH, ESL_WST_ALGO_SIPHASH)) != ESL_ERC_NO_ERROR){
  }
  else{
    actU64 mac64;

    (void)actSipHashFinalize(&workSpace->wsSipHash, &mac64, workSpace->header.watchdog);

    messageMAC[0] = (eslt_Byte) (mac64 & 0xFFuLL);
    messageMAC[1] = (eslt_Byte) ((mac64 >> 8) & 0xFFuLL);
    messageMAC[2] = (eslt_Byte) ((mac64 >> 16) & 0xFFuLL);
    messageMAC[3] = (eslt_Byte) ((mac64 >> 24) & 0xFFuLL);
    messageMAC[4] = (eslt_Byte) ((mac64 >> 32) & 0xFFuLL);
    messageMAC[5] = (eslt_Byte) ((mac64 >> 40) & 0xFFuLL);
    messageMAC[6] = (eslt_Byte) ((mac64 >> 48) & 0xFFuLL);
    messageMAC[7] = (eslt_Byte) (mac64 >> 56);

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsSipHash);
  }
  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySipHash(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSipHash) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageMAC){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (messageMAC == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_SIPHASH, ESL_WST_ALGO_SIPHASH)) != ESL_ERC_NO_ERROR){
  }
  else{
    eslt_Byte tmpMAC[sizeof(actU64)];

    (void)esl_finalizeSipHash(workSpace, tmpMAC);

    if(actMemcmp(tmpMAC, messageMAC, sizeof(actU64)) != TRUE){
      retVal = ESL_ERC_HMAC_INCORRECT_MAC;
    }
  }
  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

