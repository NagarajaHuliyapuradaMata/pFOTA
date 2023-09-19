

#define ESLIB_RSA_PRIM_VER_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "actIRSA.hpp"

#if(VSECPRIM_RSA_SIGNATURE_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSA_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver_prim) workSpace
   ,  eslt_Length keyPairModuleSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  if((workSpace == NULL_PTR) || (keyPairModule == NULL_PTR) || (publicKeyExponent == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_RSA_PRIM)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRETURNCODE actReturnValue = actRSAInitPublicKeyOperation(keyPairModule, keyPairModuleSize, publicKeyExponent
   ,     publicKeyExponentSize, &(workSpace->wsRSAPrimBuf), workSpace->header.watchdog);

    if(actReturnValue != actOK){
      if(actReturnValue == actEXCEPTION_MEMORY)
      {
        returnValue = ESL_ERC_WS_TOO_SMALL;
      }
      else if(actReturnValue == actRSA_PARAM_OUT_OF_RANGE)
      {
        returnValue = ESL_ERC_PARAMETER_INVALID;
      }
      else
      {
        returnValue = ESL_ERC_RSA_PUBKEY_INVALID;
      }
    }
    else{
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyRSA_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver_prim) workSpace
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) message){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  if((workSpace == NULL_PTR) || (messageSize == NULL_PTR) || (message == NULL_PTR) || (signature == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }

  else if((returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PRIM, ESL_WST_ALGO_RSA)) != ESL_ERC_NO_ERROR){
  }
  else{
    actLengthType messageLen = *messageSize;
    actRETURNCODE actReturnValue = actRSAPublicKeyOperation(signature, signatureSize, message, &messageLen
   ,                                                           &(workSpace->wsRSAPrimBuf), workSpace->header.watchdog);

    if(actReturnValue != actOK){
      if(actReturnValue == actEXCEPTION_MEMORY)
      {
        returnValue = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
      }
      else
      {
        returnValue = ESL_ERC_RSA_SIGNATURE_OUT_OF_RANGE;
      }
    }
    else{
      *messageSize = (eslt_Length)(messageLen & 0xFFFFu);
    }
  }

  return returnValue;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

