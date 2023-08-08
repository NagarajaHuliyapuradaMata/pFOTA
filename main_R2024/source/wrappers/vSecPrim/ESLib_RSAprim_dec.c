

#define ESLIB_RSA_PRIM_DEC_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIRSA.hpp"

#if(VSECPRIM_RSA_CIPHER_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSA_prim(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec_prim) workSpace,
                                                      eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule, eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent){
  eslt_ErrorCode retVal;
  actRETURNCODE result;

  if((workSpace == NULL_PTR) || (keyPairModule == NULL_PTR) || (privateKeyExponent == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    result = actRSAInitPrivateKeyOperation(keyPairModule, keyPairModuleSize, privateKeyExponent,
                                           privateKeyExponentSize, &(workSpace->wsRSAPrimBuf),
                                           workSpace->header.watchdog);
    if(result != actOK){
      if(result == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_WS_TOO_SMALL;
      }
      else if(result == actRSA_PARAM_OUT_OF_RANGE)
      {
        retVal = ESL_ERC_PARAMETER_INVALID;
      }
      else
      {
        retVal = ESL_ERC_RSA_PRIVKEY_INVALID;
      }
    }
    else{
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);
      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSA_prim(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec_prim) workSpace,
                                                  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher,
                                                  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message){
  eslt_ErrorCode retVal;
  actRETURNCODE result;
  actLengthType messageLen;

  if((workSpace == NULL_PTR) || (cipher == NULL_PTR) || (messageSize == NULL_PTR) || (message == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_RSA_DEC_PRIM, ESL_WST_ALGO_RSA)) != ESL_ERC_NO_ERROR){
  }
  else{
    messageLen = *messageSize;
    result = actRSAPrivateKeyOperation(cipher, cipherSize, message, &messageLen,
                                       &(workSpace->wsRSAPrimBuf), workSpace->header.watchdog);
    if(result != actOK){
      if(result == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
      }
      else
      {
        retVal = ESL_ERC_RSA_CODE_OUT_OF_RANGE;
      }
    }
    else{
      *messageSize = (eslt_Length)(messageLen & 0xFFFFu);
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

