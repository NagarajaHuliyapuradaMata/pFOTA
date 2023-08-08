

#define ESLIB_RSA_OAEP_DEC_CRT_SHA256_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIRSA.hpp"

#if(VSECPRIM_RSA_OAEP_SHA2_256_ENABLED == STD_ON)

# define ESL_RSA_OAEP_SIZEOF_HASH                                     ESL_SIZEOF_SHA256_DIGEST

# define ESL_WS_RSA_OAEP_ED_BUFFERLENGTH                              ESL_WS_RSA_OAEP_ED_SHA256_BUFFERLENGTH

# define ESL_WS_RSA_OAEP_ED_BUFFER                                    ESL_WS_RSA_OAEP_ED_SHA256_BUFFER

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSACRTSHA256_OAEP(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTOAEPdec) workSpace,
                                                               eslt_Length keyPairPrimePSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeP,
                                                               eslt_Length keyPairPrimeQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeQ,
                                                               eslt_Length privateKeyExponentDPSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDP,
                                                               eslt_Length privateKeyExponentDQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDQ,
                                                               eslt_Length privateKeyInverseQISize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyInverseQI){
  eslt_ErrorCode returnValue;
  eslt_Length keyPairModuleSize;
  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    keyPairModuleSize = keyPairPrimePSize + keyPairPrimeQSize;

    if(workSpace->header.size < ESL_MAXSIZEOF_WS_RSA_CRT_OAEP_DEC){
      returnValue = ESL_ERC_WS_TOO_SMALL;
    }
    else{
      workSpace->wsHashUnion.SHA256ws.header.size = ESL_SIZEOF_WS_HASHUNION_RSA;
      workSpace->wsHashUnion.SHA256ws.header.watchdog = workSpace->header.watchdog;

      workSpace->wsRSACRTDecPrim.header.size = (eslt_Length)(ESL_MAXSIZEOF_WS_RSA_CRT_DEC_PRIM);
      workSpace->wsRSACRTDecPrim.header.watchdog = workSpace->header.watchdog;
      returnValue = esl_initDecryptRSACRT_prim(&(workSpace->wsRSACRTDecPrim),
                                               keyPairPrimePSize, keyPairPrimeP,
                                               keyPairPrimeQSize, keyPairPrimeQ,
                                               privateKeyExponentDPSize, privateKeyExponentDP, privateKeyExponentDQSize, privateKeyExponentDQ, privateKeyInverseQISize, privateKeyInverseQI);
    }

    if(ESL_ERC_NO_ERROR == returnValue){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);

      workSpace->modulusSizeInformation = keyPairModuleSize;
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSACRTSHA256_OAEP_Label(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTOAEPdec) workSpace,
                                                                 eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher,
                                                                 eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label,
                                                                 VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message){
  eslt_ErrorCode returnValue;
  eslt_Length keyPairModuleSize;
  eslt_Length encodedMessageSize;
  VSECPRIM_P2VAR_PARA(eslt_Byte) encodedMessage;
  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    keyPairModuleSize = (eslt_Length)(workSpace->modulusSizeInformation);
    encodedMessage = workSpace->encodedMessageBuffer.encodedMessage;

    encodedMessageSize = keyPairModuleSize;

    returnValue = esl_decryptRSACRT_prim(&(workSpace->wsRSACRTDecPrim), cipherSize, cipher, &encodedMessageSize, encodedMessage);

    if(ESL_ERC_NO_ERROR == returnValue){
      eslt_WorkSpace wsDecoding;
      wsDecoding.encodedMessageBufferPtr = &(workSpace->encodedMessageBuffer);
      wsDecoding.wsHashUnionPtr = &(workSpace->wsHashUnion);
      wsDecoding.modulusInformationPtr = &(workSpace->modulusSizeInformation);

      returnValue = esl_decodeRSASHA256_OAEP(&wsDecoding, encodedMessageSize, labelSize, label, messageSize, message);
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSACRTSHA256_OAEP(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTOAEPdec) workSpace,
                                                           eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher,
                                                           VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message){
  return esl_decryptRSACRTSHA256_OAEP_Label(workSpace, cipherSize, cipher, 0u, NULL_PTR, messageSize, message);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

