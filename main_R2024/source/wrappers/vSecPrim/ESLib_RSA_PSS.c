

#define ESLIB_RSA_PSS_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "ESLib_RSA_Common.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#if(VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSaltedHashRSASHA1_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA1) wsHash,
eslt_Length saltSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
VSECPRIM_P2VAR_PARA(eslt_Byte) saltedHash){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  if((wsHash == NULL_PTR) || (saltedHash == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&wsHash->header, ESL_MINSIZEOF_WS_SHA1)) != ESL_ERC_NO_ERROR){
  }
  else{
    eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
    wsHashUnion.SHA1ws = *wsHash;

    returnValue = esl_calcSaltedHashRSA_PSS(&wsHashUnion, saltSize,
      salt, messageDigest, ESL_SIZEOF_SHA1_DIGEST, saltedHash, ESL_HA_SHA1);

    if(returnValue == ESL_ERC_TOTAL_LENGTH_OVERFLOW){
      returnValue = ESL_ERC_SHA1_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return returnValue;
}
#endif

#if(VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSaltedHashRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA256) wsHash,
  eslt_Length saltSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
  VSECPRIM_P2VAR_PARA(eslt_Byte) saltedHash){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if((wsHash == NULL_PTR) || (salt == NULL_PTR) || (messageDigest == NULL_PTR) || (saltedHash == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&wsHash->header, ESL_MINSIZEOF_WS_SHA256)) != ESL_ERC_NO_ERROR){
  }
  else{
    eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
    wsHashUnion.SHA256ws = *wsHash;

    returnValue = esl_calcSaltedHashRSA_PSS(&wsHashUnion, saltSize,
      salt, messageDigest, ESL_SIZEOF_SHA256_DIGEST, saltedHash, ESL_HA_SHA2_256);

    if(returnValue == ESL_ERC_TOTAL_LENGTH_OVERFLOW){
      returnValue = ESL_ERC_SHA256_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return returnValue;
}
#endif

#if(VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSaltedHashRSARIPEMD160_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRIPEMD160) wsHash,
eslt_Length saltSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
VSECPRIM_P2VAR_PARA(eslt_Byte) saltedHash){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if((wsHash == NULL_PTR) || (saltedHash == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&wsHash->header, ESL_MINSIZEOF_WS_RIPEMD160)) != ESL_ERC_NO_ERROR){
  }
  else{
    eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
    wsHashUnion.RIPEMD160ws = *wsHash;

    returnValue = esl_calcSaltedHashRSA_PSS(&wsHashUnion, saltSize,
      salt, messageDigest, ESL_SIZEOF_RIPEMD160_DIGEST, saltedHash, ESL_HA_RMD160);

    if(returnValue == ESL_ERC_TOTAL_LENGTH_OVERFLOW){
      returnValue = ESL_ERC_RIPEMD160_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return returnValue;
}

#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

