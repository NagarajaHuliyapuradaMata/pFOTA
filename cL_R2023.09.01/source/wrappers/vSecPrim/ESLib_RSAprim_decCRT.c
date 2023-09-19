

#define ESLIB_RSA_PRIM_DEC_CRT_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIRSA.hpp"

#if(VSECPRIM_RSA_CIPHER_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSACRT_prim(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTdec_prim) workSpace
   ,                                                        eslt_Length keyPairPrimePSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeP
   ,                                                        eslt_Length keyPairPrimeQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeQ
   ,                                                        eslt_Length privateKeyExponentDPSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDP
   ,                                                        eslt_Length privateKeyExponentDQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDQ
   ,                                                        eslt_Length privateKeyInverseQISize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyInverseQI){
  eslt_ErrorCode retVal;
  actRETURNCODE result;

  if((workSpace == NULL_PTR) || (keyPairPrimeP == NULL_PTR) || (keyPairPrimeQ == NULL_PTR) ||
      (privateKeyExponentDP == NULL_PTR) || (privateKeyExponentDQ == NULL_PTR) || (privateKeyInverseQI == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    result = actRSAInitPrivateKeyOperationCRT(keyPairPrimeP, keyPairPrimePSize, keyPairPrimeQ
   ,                                             keyPairPrimeQSize, privateKeyExponentDP
   ,                                             privateKeyExponentDPSize, privateKeyExponentDQ
   ,                                             privateKeyExponentDQSize, privateKeyInverseQI
   ,                                             privateKeyInverseQISize, &(workSpace->CRTStruct)
   ,                                             workSpace->header.watchdog);

    if(result != actOK){
      if(result == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_WS_TOO_SMALL;
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

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSACRT_prim(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTdec_prim) workSpace
   ,                                                    eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,                                                    VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message){
  eslt_ErrorCode returnValue;
  actRETURNCODE result;
  actLengthType messageLen;

  if((workSpace == NULL_PTR) || (messageSize == NULL_PTR) || (message == NULL_PTR) || (cipher == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }

  else if((returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_CRT_DEC_PRIM, ESL_WST_ALGO_RSA)) != ESL_ERC_NO_ERROR){
  }
  else{
    messageLen = *messageSize;
    result = actRSAPrivateKeyOperationCRT(cipher, cipherSize, message, &messageLen, &(workSpace->CRTStruct), workSpace->header.watchdog);

    if(result != actOK){
      if(result == actEXCEPTION_MEMORY)
      {
        returnValue = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
      }
      else
      {
        returnValue = ESL_ERC_RSA_CODE_OUT_OF_RANGE;
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

