

#define ESLIB_RSA_PRIM_SIGN_CRT_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIRSA.hpp"
#if( (VSECPRIM_RSA_SIGNATURE_ENABLED == STD_ON) && (VSECPRIM_RSAPSSONLY_SIGNATURE_ENABLED == STD_OFF) )

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSACRT_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig_prim) workSpace,
  eslt_Length keyPairPrimePSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeP,
  eslt_Length keyPairPrimeQSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeQ,
  eslt_Length privateKeyExponentDPSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDP,
  eslt_Length privateKeyExponentDQSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDQ,
  eslt_Length privateKeyInverseQISize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyInverseQI){
  eslt_ErrorCode returnValue;

  if((workSpace == NULL_PTR) || (keyPairPrimeP == NULL_PTR) || (keyPairPrimeQ == NULL_PTR) ||
      (privateKeyExponentDP == NULL_PTR) || (privateKeyExponentDQ == NULL_PTR) || (privateKeyInverseQI == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    actRETURNCODE result = actRSAInitPrivateKeyOperationCRT(keyPairPrimeP, keyPairPrimePSize, keyPairPrimeQ,
                                                            keyPairPrimeQSize, privateKeyExponentDP,
                                                            privateKeyExponentDPSize, privateKeyExponentDQ,
                                                            privateKeyExponentDQSize, privateKeyInverseQI,
                                                            privateKeyInverseQISize, &(workSpace->CRTStruct),
                                                            workSpace->header.watchdog);

    if(result != actOK){
      if(result == actEXCEPTION_MEMORY)
      {
        returnValue = ESL_ERC_WS_TOO_SMALL;
      }
      else if(result == actRSA_PARAM_OUT_OF_RANGE)
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
      returnValue = ESL_ERC_NO_ERROR;
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_signRSACRT_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig_prim) workSpace,
  eslt_Length messageSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) message,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue;
  actRETURNCODE actReturnValue;
  actLengthType signatureLen;

  if((workSpace == NULL_PTR) || (message == NULL_PTR) || (signature == NULL_PTR) || (signatureSize == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_CRT_SIG_PRIM, ESL_WST_ALGO_RSA)) != ESL_ERC_NO_ERROR){
  }
  else{
    signatureLen = *signatureSize;
    actReturnValue = actRSAPrivateKeyOperationCRT(message, messageSize, signature, &signatureLen, &(workSpace->CRTStruct),
                                                  workSpace->header.watchdog);

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

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

