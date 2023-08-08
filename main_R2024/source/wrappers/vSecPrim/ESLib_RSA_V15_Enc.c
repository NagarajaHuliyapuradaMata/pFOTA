

#define ESLIB_RSA_V15_ENC_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "ESLib_ASN_1.hpp"

#include "actIRSA.hpp"

#if(VSECPRIM_RSA_V15_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptRSA_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAenc) workSpace,
                                                     eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule, eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent){
  eslt_ErrorCode returnValue;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    if(workSpace->header.size < ESL_MAXSIZEOF_WS_RSA_ENC){
      returnValue = ESL_ERC_WS_TOO_SMALL;
    }
    else{
      workSpace->wsRSAEncPrim.header.size = ESL_MAXSIZEOF_WS_RSA_ENC_PRIM;
      workSpace->wsRSAEncPrim.header.watchdog = workSpace->header.watchdog;
      returnValue = esl_initEncryptRSA_prim(&(workSpace->wsRSAEncPrim), keyPairModuleSize, keyPairModule, publicKeyExponentSize, publicKeyExponent);
    }
    if(ESL_ERC_NO_ERROR == returnValue){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);

      workSpace->modulusSizeInformation = keyPairModuleSize;
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSA_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAenc) workSpace,
                                                 eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message, VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher){
  eslt_ErrorCode returnValue;
  eslt_Length keyPairModuleSize;
  eslt_Length rnd_BytesNeeded;
  eslt_Length i;
  VSECPRIM_P2VAR_PARA(eslt_Byte) messageBuf;

  rnd_BytesNeeded = 0u;

  if((workSpace == NULL_PTR) || (message == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    keyPairModuleSize = workSpace->modulusSizeInformation;
    messageBuf = workSpace->messageBuffer;

    if(ESL_WST_ALGO_RSA != (workSpace->header.status & ESL_WST_M_ALGO)){
      returnValue = ESL_ERC_WS_STATE_INVALID;
    }
    else if(0u == (workSpace->header.status & ESL_WST_M_RUNNING)){
      returnValue = ESL_ERC_WS_STATE_INVALID;
    }
    else if(keyPairModuleSize < ASN1_SIZEOF_MINIMAL_PADDING){
      returnValue = ESL_ERC_RSA_MODULE_OUT_OF_RANGE;
    }
    else if(messageSize > (keyPairModuleSize - ASN1_SIZEOF_MINIMAL_PADDING)){
      returnValue = ESL_ERC_RSA_MESSAGE_OUT_OF_RANGE;
    }
    else{
      rnd_BytesNeeded = keyPairModuleSize - messageSize - 3u;

      messageBuf[0] = 0x00;
      messageBuf[1] = 0x02;

      returnValue = esl_getBytesRNG(rnd_BytesNeeded, &messageBuf[2]);
      if(returnValue == ESL_ERC_NO_ERROR)
      {
        for (i = 0u; i < rnd_BytesNeeded; i++)
        {
          while ((returnValue == ESL_ERC_NO_ERROR) && (messageBuf[i+2u] == 0x00u))
          {
            returnValue = esl_getBytesRNG(1u, &messageBuf[i+2u]);
          }
        }
      }

    }

    if(ESL_ERC_NO_ERROR == returnValue){
      messageBuf[rnd_BytesNeeded + 2u] = 0x00u;
      actMemCpyByteArray(&messageBuf[rnd_BytesNeeded + 3u], message, messageSize);

      returnValue = esl_encryptRSA_prim(&(workSpace->wsRSAEncPrim), keyPairModuleSize, messageBuf, cipherSize, cipher);
    }
  }
  return returnValue;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

