

#define ESLIB_RSA_V15_DEC_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "ESLib_ASN_1.hpp"

#include "actIRSA.hpp"

#if(VSECPRIM_RSA_V15_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_decryptInternal(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message, eslt_Byte blockType);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_decryptInternal(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec) workSpace
   ,                                                        eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,                                                        VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message, eslt_Byte blockType){
  eslt_ErrorCode returnValue;
  eslt_Length keyPairModuleSize;
  VSECPRIM_P2VAR_PARA(eslt_Byte) messageBuf;
  eslt_Length i;

  if((workSpace == NULL_PTR) || (messageSize == NULL_PTR) || (message == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }

  else{
    keyPairModuleSize = workSpace->modulusSizeInformation;
    messageBuf = workSpace->messageBuffer;

    i = keyPairModuleSize;
    returnValue = esl_decryptRSA_prim(&(workSpace->wsRSADecPrim), cipherSize, cipher, &i, messageBuf);

    if(ESL_ERC_NO_ERROR == returnValue){
      if(i != keyPairModuleSize)
      {
        returnValue = ESL_ERC_RSA_ENCODING_INVALID;
      }
      else if((returnValue = esl_verifyPaddingRSAEM_V15(messageBuf, &i, blockType)) != ESL_ERC_NO_ERROR)
      {
      }
      else
      {
        if(i == keyPairModuleSize)
        {
          *messageSize = 0u;
        }
        else if(*messageSize < (keyPairModuleSize - i))
        {
          returnValue = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
        }
        else
        {
          *messageSize = keyPairModuleSize - i;
          actMemCpyByteArray(message, &messageBuf[(keyPairModuleSize - *messageSize)], *messageSize);

        }
      }
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSA_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec) workSpace
   ,                                                    eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule, eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent){
  eslt_ErrorCode returnValue;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    if(workSpace->header.size < ESL_MAXSIZEOF_WS_RSA_DEC){
      returnValue = ESL_ERC_WS_TOO_SMALL;
    }
    else{
      workSpace->wsRSADecPrim.header.size = ESL_MAXSIZEOF_WS_RSA_DEC_PRIM;
      workSpace->wsRSADecPrim.header.watchdog = workSpace->header.watchdog;
      returnValue = esl_initDecryptRSA_prim(&(workSpace->wsRSADecPrim), keyPairModuleSize, keyPairModule, privateKeyExponentSize, privateKeyExponent);
    }
    if(ESL_ERC_NO_ERROR == returnValue){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);

      workSpace->modulusSizeInformation = keyPairModuleSize;
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptPubRSA_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec) workSpace
   ,                                                   eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,                                                   VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message){
  return esl_decryptInternal(workSpace, cipherSize, cipher, messageSize, message, ASN1_PADDING_BLOCK_TYPE_PRIVATE);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptPrivRSA_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec) workSpace
   ,                                                    eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,                                                    VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message){
  return esl_decryptInternal(workSpace, cipherSize, cipher, messageSize, message, ASN1_PADDING_BLOCK_TYPE_PUBLIC);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSA_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec) workSpace
   ,                                                eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher, VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message){
  return esl_decryptPrivRSA_V15(workSpace, cipherSize, cipher, messageSize, message);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

