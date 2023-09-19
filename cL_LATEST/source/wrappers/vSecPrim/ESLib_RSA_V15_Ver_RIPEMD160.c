

#define ESLIB_RSA_V15_VER_RIPEMD160_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "ESLib_ASN_1.hpp"

#include "actIRSA.hpp"
#include "actIRMD160.hpp"

#if(VSECPRIM_RSA_V15_RIPEMD160_ENABLED == STD_ON)

#define ESL_RSA_V15_INIT_HASH_FCT(workspace)                         actRMD160Init(&((workspace)->wsRIPEMD160))

#define ESL_RSA_V15_UPDATE_HASH_FCT(workspace, inputSize, input)     actRMD160Update(&((workspace)->wsRIPEMD160), (VSECPRIM_P2CONST_PARA(actU8))(input), (inputSize),  (workspace)->header.watchdog)

#define ESL_RSA_V15_FINALIZE_HASH_FCT(workspace, messageDigest)      actRMD160Finalize(&((workspace)->wsRIPEMD160), (VSECPRIM_P2VAR_PARA(actU8))(messageDigest), (workspace)->header.watchdog)

#define VSECPRIM_START_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, eslt_Byte) eslt_VERIFY_RSA_RIPEMD160_V15_ASN1_DIGESTINFO[] = ASN1_DIGESTINFO_RIPEMD160;

#define VSECPRIM_STOP_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSARIPEMD160_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace
   ,                                                            eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule, eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent){
  eslt_ErrorCode returnValue;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    if(workSpace->header.size < ESL_MAXSIZEOF_WS_RSA_VER){
      returnValue = ESL_ERC_WS_TOO_SMALL;
    }
    else{
      workSpace->wsHashUnion.RIPEMD160ws.header.size = ESL_MAXSIZEOF_WS_RIPEMD160;
      workSpace->wsHashUnion.RIPEMD160ws.header.watchdog = workSpace->header.watchdog;

      (void)ESL_RSA_V15_INIT_HASH_FCT(&(workSpace->wsHashUnion.RIPEMD160ws));

      workSpace->wsRSAVerPrim.header.size = ESL_MAXSIZEOF_WS_RSA_PRIM;
      workSpace->wsRSAVerPrim.header.watchdog = workSpace->header.watchdog;
      returnValue = esl_initVerifyRSA_prim(&(workSpace->wsRSAVerPrim), keyPairModuleSize, keyPairModule, publicKeyExponentSize, publicKeyExponent);
    }
    if(ESL_ERC_NO_ERROR == returnValue){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);

      workSpace->modulusSizeInformation = keyPairModuleSize;
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateVerifyRSARIPEMD160_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace, eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode returnValue;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_RSA_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    if(actOK != ESL_RSA_V15_UPDATE_HASH_FCT(&(workSpace->wsHashUnion.RIPEMD160ws), inputSize, input)){
      returnValue = ESL_ERC_RIPEMD160_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashVerifyRSARIPEMD160_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode returnValue;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_RSA_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    (void)ESL_RSA_V15_FINALIZE_HASH_FCT(&(workSpace->wsHashUnion.RIPEMD160ws), messageDigest);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSARIPEMD160_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace
   ,                                                                 VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest, eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue;
  eslt_Length keyPairModuleSize, i;
  VSECPRIM_P2VAR_PARA(eslt_Byte) messageBuf;

  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    messageBuf = workSpace->messageBuffer;
    keyPairModuleSize = workSpace->modulusSizeInformation;

    returnValue = esl_verifyRSA_prim(&(workSpace->wsRSAVerPrim), signatureSize, signature, &keyPairModuleSize, messageBuf);

    if(ESL_ERC_NO_ERROR == returnValue){
      if(keyPairModuleSize < (ESL_SIZEOF_RIPEMD160_DIGEST + ((eslt_Length) sizeof(eslt_VERIFY_RSA_RIPEMD160_V15_ASN1_DIGESTINFO))))
      {
        returnValue = ESL_ERC_RSA_MODULE_OUT_OF_RANGE;
      }
      else
      {
        i = keyPairModuleSize - ESL_SIZEOF_RIPEMD160_DIGEST - ((eslt_Length) sizeof(eslt_VERIFY_RSA_RIPEMD160_V15_ASN1_DIGESTINFO));
        returnValue = esl_verifyPaddingRSAEM_V15(messageBuf, &i, ASN1_PADDING_BLOCK_TYPE_PRIVATE);

        if((signatureSize != keyPairModuleSize) || (returnValue != ESL_ERC_NO_ERROR))
        {
          returnValue = ESL_ERC_RSA_SIGNATURE_INVALID;
        }
        else
        {
          if(FALSE == actMemcmp_ROMRAM((VSECPRIM_P2CONST_PARA(actU8)) &messageBuf[i], eslt_VERIFY_RSA_RIPEMD160_V15_ASN1_DIGESTINFO, sizeof(eslt_VERIFY_RSA_RIPEMD160_V15_ASN1_DIGESTINFO)))
          {
            returnValue = ESL_ERC_RSA_SIGNATURE_INVALID;
          }
          else
          {
            i += ((eslt_Length) sizeof(eslt_VERIFY_RSA_RIPEMD160_V15_ASN1_DIGESTINFO));

            if(FALSE == actMemcmp((VSECPRIM_P2CONST_PARA(actU8)) messageDigest, (VSECPRIM_P2CONST_PARA(actU8))&messageBuf[i], ESL_SIZEOF_RIPEMD160_DIGEST))
            {
              returnValue = ESL_ERC_RSA_SIGNATURE_INVALID;
            }
          }
        }
      }
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSARIPEMD160_V15(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace, eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue;
  eslt_Byte hash[ESL_SIZEOF_RIPEMD160_DIGEST];

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_finalizeHashVerifyRSARIPEMD160_V15(workSpace, hash);
    if(returnValue == ESL_ERC_NO_ERROR){
      returnValue = esl_verifySigVerifyRSARIPEMD160_V15(workSpace, hash, signatureSize, signature);
    }
  }

  return returnValue;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

