

#define ESLIB_ECDH_SOURCE

#include "ESLib_Config.hpp"
#include "ESLib.hpp"

#include "actIX25519.hpp"

#if(VSECPRIM_ECDH_25519_ENABLED == STD_ON)

#include "ESLib_Helper.hpp"

#ifndef ESL_SUPPORT_CURVE25519
#error "Curve25519 Support must be enabled"
#endif

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_validateKeyLength(eslt_LengthConstRef publicKeyLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_validateCSLength(eslt_LengthConstRef sharedSecretLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_validateKeyLength(eslt_LengthConstRef publicKeyLength){
  return esl_checkLengthRef(publicKeyLength, ESL_SIZEOF_X25519_PUBLIC_KEY);
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_validateCSLength(eslt_LengthConstRef sharedSecretLength){
  return esl_checkLengthRef(sharedSecretLength, ESL_SIZEOF_X25519_SHARED_SECRET);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initECDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceX25519) workSpace
   ,  eslt_Size16 curve){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_X25519)) != ESL_ERC_NO_ERROR){
  }
  else if(curve != ESL_Curve25519){
    retVal = ESL_ERC_CURVE_NOT_SUPPORTED;
  }
  else{
    VSECPRIM_P2VAR_PARA(eslt_WorkSpaceX25519) wsPtr = (VSECPRIM_P2VAR_PARA(eslt_WorkSpaceX25519)) workSpace;

    (void)actX25519Init(&wsPtr->wsX25519buffer);

    workSpace->wsX25519 = (VSECPRIM_P2VAR_PARA(eslt_Byte))&(workSpace->wsX25519buffer);

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_X25519);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateEphemeralKeyPairECDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceX25519) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) publicKeyLength){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (publicKey == NULL_PTR) || (publicKeyLength == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_X25519, ESL_WST_ALGO_X25519)) != ESL_ERC_NO_ERROR){
  }
  else if(ESL_ERC_NO_ERROR != (retVal = esl_validateKeyLength(publicKeyLength))){
  }
  else{
    switch(actX25519GenKeyPair(&workSpace->wsX25519buffer, publicKey, workSpace->header.watchdog)){
      case actOK:
      {
        *publicKeyLength = ESL_SIZEOF_X25519_PUBLIC_KEY;
        break;
      }

      case actEXCEPTION_PRIVKEY:
      {
        retVal = ESL_ERC_RNG_FAILED;
        break;
      }

      default:
      {
        retVal = ESL_ERC_UNRECOVERABLE_ERROR;
        break;
      }
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_importStaticPrivateKeyECDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceX25519) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (privateKey == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_X25519, ESL_WST_ALGO_X25519)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(actX25519ImportPrivateKey(&workSpace->wsX25519buffer, privateKey, workSpace->header.watchdog) != actOK){
      retVal = ESL_ERC_UNRECOVERABLE_ERROR;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateSharedSecretECDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceX25519) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) sharedSecret
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) sharedSecretLength){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (publicKey == NULL_PTR) || (sharedSecret == NULL_PTR) || (sharedSecretLength == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_X25519, ESL_WST_ALGO_X25519)) != ESL_ERC_NO_ERROR){
  }
  else if(ESL_ERC_NO_ERROR != (retVal = esl_validateCSLength(sharedSecretLength))){
  }
  else{
    (void)actX25519GenSecret(&workSpace->wsX25519buffer, publicKey, sharedSecret, workSpace->header.watchdog);
    *sharedSecretLength = ESL_SIZEOF_X25519_SHARED_SECRET;
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

