

#define ESIB_RSA_PRIM_ENC_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIRSA.hpp"

#if(VSECPRIM_RSA_CIPHER_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptRSA_prim(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAenc_prim) workSpace,
                                                      eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule, eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent){
  eslt_ErrorCode retVal;
  actRETURNCODE result;

  if((workSpace == NULL_PTR) || (keyPairModule == NULL_PTR) || (publicKeyExponent == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    result = actRSAInitPublicKeyOperation(keyPairModule, keyPairModuleSize, publicKeyExponent, publicKeyExponentSize,
                                          &(workSpace->wsRSAPrimBuf), workSpace->header.watchdog);
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
        retVal = ESL_ERC_RSA_PUBKEY_INVALID;
      }
    }
    else{
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);
      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSA_prim(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAenc_prim) workSpace,
                                                  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message, VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher){
  eslt_ErrorCode retVal;
  actRETURNCODE result;
  actLengthType cipherLen;

  if((workSpace == NULL_PTR) || (message == NULL_PTR) || (cipherSize == NULL_PTR) || (cipher == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_RSA_ENC_PRIM, ESL_WST_ALGO_RSA)) != ESL_ERC_NO_ERROR){
  }
  else{
    cipherLen = *cipherSize;
    result = actRSAPublicKeyOperation(message, messageSize, cipher, &cipherLen,
                                      &(workSpace->wsRSAPrimBuf), workSpace->header.watchdog);

    if(result != actOK){
      if(result == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
      }
      else
      {
        retVal = ESL_ERC_RSA_MESSAGE_OUT_OF_RANGE;
      }
    }
    else{
      *cipherSize = (eslt_Length)(cipherLen & 0xFFFFu);
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

