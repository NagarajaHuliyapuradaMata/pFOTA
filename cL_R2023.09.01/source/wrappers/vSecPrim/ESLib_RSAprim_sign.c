

#define ESLIB_RSA_PRIM_SIGN_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "actIRSA.hpp"

#if(VSECPRIM_RSA_SIGNATURE_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSA_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig_prim) workSpace
   ,  eslt_Length keyPairModuleSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length privateKeyExponentSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  if((workSpace == NULL_PTR) || (keyPairModule == NULL_PTR) || (privateKeyExponent == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_RSA_PRIM)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRETURNCODE actReturnValue = actRSAInitPrivateKeyOperation(keyPairModule, keyPairModuleSize
   ,     privateKeyExponent, privateKeyExponentSize
   ,     &(workSpace->wsRSAPrimBuf)
   ,     workSpace->header.watchdog);

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
        returnValue = ESL_ERC_RSA_PRIVKEY_INVALID;
      }
    }
    else{
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_signRSA_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig_prim) workSpace
   ,  eslt_Length messageSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  if((workSpace == NULL_PTR) || (signatureSize == NULL_PTR) || (signature == NULL_PTR) || (message == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PRIM, ESL_WST_ALGO_RSA)) != ESL_ERC_NO_ERROR){
  }
  else{
      actLengthType signatureLen = *signatureSize;
      actRETURNCODE actReturnValue = actRSAPrivateKeyOperation(message, messageSize, signature, &signatureLen
   ,       &(workSpace->wsRSAPrimBuf), workSpace->header.watchdog);

    if(actReturnValue != actOK){
      if(actReturnValue == actEXCEPTION_MEMORY)
      {
        returnValue = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
      }
      else
      {
        returnValue = ESL_ERC_RSA_MESSAGE_OUT_OF_RANGE;
      }
    }
    else{
      *signatureSize = (eslt_Length)(signatureLen & 0xFFFFu);
    }
  }

  return returnValue;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

