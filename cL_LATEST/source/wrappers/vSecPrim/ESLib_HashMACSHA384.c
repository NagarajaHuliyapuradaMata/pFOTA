

#define ESLIB_HASHMACSHA384_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIHashMACSHA384.hpp"

#if(VSECPRIM_HMAC_SHA2_384_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initHashMACSHA384(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace, const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (key == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA384)) != ESL_ERC_NO_ERROR){
  }

  else if(keyLength == 0u){
    retVal = ESL_ERC_HMAC_KEY_LENGTH_OUT_OF_RANGE;
  }
  else{
    if(actOK == actHashMACSHA384Init(&workSpace->wsHMACSHA384, key, keyLength, workSpace->header.watchdog)){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HMACSHA384);
    }
    else{
      retVal = ESL_ERC_ERROR;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateHashMACSHA384(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace, const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA384, ESL_WST_ALGO_HMACSHA384)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(actEXCEPTION_LENGTH == actHashMACSHA384Update(&workSpace->wsHMACSHA384, input, inputLength, workSpace->header.watchdog)){
      retVal = ESL_ERC_SHA384_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashMACSHA384(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageHashMAC){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA384, ESL_WST_ALGO_HMACSHA384)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(actOK != actHashMACSHA384Finalize(&workSpace->wsHMACSHA384, messageHashMAC, workSpace->header.watchdog)){
      retVal = ESL_ERC_ERROR;
    }

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsHMACSHA384);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyHashMACSHA384(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageHashMAC){
  eslt_Byte tmpMAC[ESL_SIZEOF_SHA384_DIGEST];
  eslt_ErrorCode retVal;

  actMemClear(tmpMAC, ESL_SIZEOF_SHA384_DIGEST);

  if((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA384, ESL_WST_ALGO_HMACSHA384)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(ESL_ERC_NO_ERROR == esl_finalizeHashMACSHA384(workSpace, tmpMAC)){
      if(actMemcmp(tmpMAC, messageHashMAC, ESL_SIZEOF_SHA384_DIGEST) != TRUE)
      {
        retVal = ESL_ERC_HMAC_INCORRECT_MAC;
      }
    }
    else{
      retVal = ESL_ERC_ERROR;
    }
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

