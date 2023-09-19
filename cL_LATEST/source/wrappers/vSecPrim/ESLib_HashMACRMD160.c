

#define ESLIB_HASHMACRMD160_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIHashMACRMD160.hpp"

#if(VSECPRIM_HMAC_RMD160_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initHashMACRIPEMD160(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACRIPEMD160) workSpace, const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (key == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_HMACRIPEMD160)) != ESL_ERC_NO_ERROR){
  }

  else if(keyLength == 0u){
    retVal = ESL_ERC_HMAC_KEY_LENGTH_OUT_OF_RANGE;
  }
  else{
    (void)actHashMACRMD160Init(&workSpace->wsHMACRIPEMD160, key, keyLength, workSpace->header.watchdog);

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HMACRIPEMD160);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateHashMACRIPEMD160(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACRIPEMD160) workSpace, const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACRIPEMD160, ESL_WST_ALGO_HMACRIPEMD160)) != ESL_ERC_NO_ERROR){
  }

  else{
    actRETURNCODE result = actHashMACRMD160Update(&workSpace->wsHMACRIPEMD160
   ,                                                 input, inputLength, workSpace->header.watchdog);
    if(result == actEXCEPTION_LENGTH){
      retVal = ESL_ERC_RIPEMD160_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashMACRIPEMD160(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACRIPEMD160) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageHashMAC){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACRIPEMD160, ESL_WST_ALGO_HMACRIPEMD160)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)actHashMACRMD160Finalize(&workSpace->wsHMACRIPEMD160, messageHashMAC, workSpace->header.watchdog);

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsHMACRIPEMD160);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyHashMACRIPEMD160(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACRIPEMD160) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageHashMAC){
  eslt_ErrorCode retVal;
  eslt_Byte tmpMAC[ESL_SIZEOF_RIPEMD160_DIGEST];

  actMemClear(tmpMAC, ESL_SIZEOF_RIPEMD160_DIGEST);

  if((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACRIPEMD160, ESL_WST_ALGO_HMACRIPEMD160)) != ESL_ERC_NO_ERROR){
  }
  else{
    (void)esl_finalizeHashMACRIPEMD160(workSpace, tmpMAC);
    if(actMemcmp(tmpMAC, messageHashMAC, ESL_SIZEOF_RIPEMD160_DIGEST) != TRUE){
      retVal = ESL_ERC_HMAC_INCORRECT_MAC;
    }
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

