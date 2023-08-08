

#define ESLIB_EDDSA_SOURCE

#include "ESLib_Config.hpp"
#include "ESLib.hpp"

#include "actIEd25519.hpp"

#if(VSECPRIM_ECDSA_25519_ENABLED == STD_ON)

# include "ESLib_Helper.hpp"

# ifndef ESL_SUPPORT_CURVE25519
#  error "Curve25519 Support must be enabled"
# endif

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_validateKeyLengthEdDSA(
  eslt_LengthConstRef secretKeyLength,
  eslt_LengthConstRef publicKeyLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkInstanceContext(
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
  const eslt_Size16 curve,
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_validateKeyLengthEdDSA(eslt_LengthConstRef secretKeyLength, eslt_LengthConstRef publicKeyLength){
  eslt_ErrorCode retVal = esl_checkLengthRef(secretKeyLength, ESL_SIZEOF_Ed25519_SECRET_KEY);

  if(retVal == ESL_ERC_NO_ERROR){
    retVal = esl_checkLengthRef(publicKeyLength, ESL_SIZEOF_Ed25519_PUBLIC_KEY);
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkInstanceContext(
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  if((ESL_INSTANCE_Ed25519 != instance)
      && (ESL_INSTANCE_Ed25519ctx != instance)
      && (ESL_INSTANCE_Ed25519ph != instance)){
    retVal = ESL_ERC_INSTANCE_NOT_SUPPORTED;
  }

  else if((ESL_INSTANCE_Ed25519 != instance) && (context != NULL_PTR) && (contextLength > 255u)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
  const eslt_Size16 curve,
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_Ed25519)) != ESL_ERC_NO_ERROR){
  }

  else if(curve != ESL_Curve25519){
    retVal = ESL_ERC_CURVE_NOT_SUPPORTED;
  }
  else{
    (void)actEd25519Init(&workSpace->wsEd25519buffer, instance, context, contextLength);

    workSpace->wsEd25519 = (VSECPRIM_P2VAR_PARA(eslt_Byte))&(workSpace->wsEd25519buffer);

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_Ed25519);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
  eslt_Size16 curve,
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength){
  eslt_ErrorCode retVal = esl_checkInstanceContext(instance, context, contextLength);

  if(retVal == ESL_ERC_NO_ERROR){
    retVal = esl_initEdDSA(workSpace, curve, instance, context, contextLength);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_signEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
  eslt_Length inputLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) secretKey,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureLength){
  eslt_ErrorCode retVal;

  if((NULL_PTR == workSpace) || ((NULL_PTR == input) && (inputLength != 0u)) || (NULL_PTR == secretKey) || (NULL_PTR == signature) || (NULL_PTR == signatureLength)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if(ESL_ERC_NO_ERROR != esl_checkLengthRef(signatureLength, ESL_SIZEOF_Ed25519_SIGNATURE)){
    retVal = ESL_ERC_BUFFER_TOO_SMALL;
  }

  else if(ESL_ERC_NO_ERROR != (retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_Ed25519, ESL_WST_ALGO_Ed25519))){
  }
  else{
    switch(actEd25519Sign(&workSpace->wsEd25519buffer, input, inputLength, secretKey, publicKey, signature, workSpace->header.watchdog)){
    case actOK:
      *signatureLength = ESL_SIZEOF_Ed25519_SIGNATURE;
      break;

    case actEXCEPTION_LENGTH:
      retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
      break;

    default:
      retVal = ESL_ERC_ERROR;
      break;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
  eslt_Size16 curve,
  const eslt_Byte instance,
  VSECPRIM_P2CONST_PARA(eslt_Byte) context,
  const eslt_Length contextLength){
  eslt_ErrorCode retVal = esl_checkInstanceContext(instance, context, contextLength);

  if(retVal == ESL_ERC_NO_ERROR){
    retVal = esl_initEdDSA(workSpace, curve, instance, context, contextLength);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
  eslt_Length inputLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey,
  VSECPRIM_P2CONST_PARA(eslt_Byte) signature,
  eslt_Length signatureLength){
  eslt_ErrorCode retVal;

  if((NULL_PTR == workSpace) || ((NULL_PTR == input) && (inputLength != 0u)) || (NULL_PTR == publicKey) || (NULL_PTR == signature)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if(signatureLength < ESL_SIZEOF_Ed25519_SIGNATURE){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if(ESL_ERC_NO_ERROR != (retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_Ed25519, ESL_WST_ALGO_Ed25519))){
  }
  else{
    switch(actEd25519Verify(&workSpace->wsEd25519buffer, input, inputLength, publicKey, signature, workSpace->header.watchdog)){
      case actOK:
      {
        break;
      }
      case actEXCEPTION_LENGTH:
      {
        retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
        break;
      }
      default:
      {
        retVal = ESL_ERC_SIGNATURE_INVALID;
        break;
      }
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateEdDSA(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) input, eslt_Length inputLength){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_Ed25519, ESL_WST_ALGO_Ed25519)) != ESL_ERC_NO_ERROR){
  }
  else{
    switch(actEd25519Update(&workSpace->wsEd25519buffer, input, inputLength, workSpace->header.watchdog)){
      case actOK:
      {
        break;
      }
      case actEXCEPTION_LENGTH:
      {
        retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
        break;
      }
      default:
      {
        retVal = ESL_ERC_WS_STATE_INVALID;
        break;
      }
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initGenerateKeyPairEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
  eslt_Size16 curve){
  return esl_initEdDSA(workSpace, curve, ESL_INSTANCE_Ed25519, NULL_PTR, 0);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyPairEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Byte) secretKey,
  VSECPRIM_P2VAR_PARA(eslt_Length) secretKeyLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey,
  VSECPRIM_P2VAR_PARA(eslt_Length) publicKeyLength){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (secretKey == NULL_PTR) || (secretKeyLength == NULL_PTR) || (publicKey == NULL_PTR) || (publicKeyLength == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if(ESL_ERC_NO_ERROR != (retVal = esl_validateKeyLengthEdDSA(secretKeyLength, publicKeyLength))){
  }

  else if(ESL_ERC_NO_ERROR != (retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_Ed25519, ESL_WST_ALGO_Ed25519))){
  }
  else{
    if(actEd25519GenKeyPair(&workSpace->wsEd25519buffer, secretKey, publicKey, workSpace->header.watchdog) == actOK){
      *secretKeyLength = ESL_SIZEOF_Ed25519_SECRET_KEY;
      *publicKeyLength = ESL_SIZEOF_Ed25519_PUBLIC_KEY;
    }
    else{
      retVal = ESL_ERC_RNG_FAILED;
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

