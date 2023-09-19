

#define ESLIB_RSA_MGF1_SOURCE

#include "ESLib_RSA_Common.hpp"
#include "ESLib_Helper.hpp"

#if((VSECPRIM_RSA_OAEP_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_ENABLED == STD_ON))

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#if(VSECPRIM_RSA_HASHALGORITHM_SHA1_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateMaskMGF1RSASHA1_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA1) wsHash
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tempHash
   ,  eslt_Length seedLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) seed
   ,  eslt_Length maskLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) mask){
  eslt_ErrorCode returnValue;

  if((wsHash == NULL_PTR) || (tempHash == NULL_PTR) || (seed == NULL_PTR) || (mask == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&wsHash->header, ESL_MINSIZEOF_WS_SHA1)) != ESL_ERC_NO_ERROR){
  }
  else{
    eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
    wsHashUnion.SHA1ws = *wsHash;

    returnValue = esl_generateMaskMGF1(ESL_HA_SHA1, &wsHashUnion
   ,     tempHash, ESL_SIZEOF_SHA1_DIGEST, seedLength, seed, maskLength, mask);
  }

  return returnValue;
}
#endif

#if(VSECPRIM_RSA_HASHALGORITHM_SHA2_256_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateMaskMGF1RSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA256) wsHash
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tempHash
   ,  eslt_Length seedLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) seed
   ,  eslt_Length maskLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) mask){
  eslt_ErrorCode returnValue;

  if((wsHash == NULL_PTR) || (tempHash == NULL_PTR) || (seed == NULL_PTR) || (mask == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&wsHash->header, ESL_MINSIZEOF_WS_SHA256)) != ESL_ERC_NO_ERROR){
  }
  else{
    eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
    wsHashUnion.SHA256ws = *wsHash;

    returnValue = esl_generateMaskMGF1(ESL_HA_SHA2_256, &wsHashUnion
   ,     tempHash, ESL_SIZEOF_SHA256_DIGEST, seedLength, seed, maskLength, mask);
  }

  return returnValue;
}
#endif

#if(VSECPRIM_RSA_HASHALGORITHM_RIPEMD160_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateMaskMGF1RSARIPEMD160_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRIPEMD160) wsHash
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tempHash
   ,  eslt_Length seedLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) seed
   ,  eslt_Length maskLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) mask){
  eslt_ErrorCode returnValue;

  if((wsHash == NULL_PTR) || (tempHash == NULL_PTR) || (seed == NULL_PTR) || (mask == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&wsHash->header, ESL_MINSIZEOF_WS_RIPEMD160)) != ESL_ERC_NO_ERROR){
  }
  else{
    eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
    wsHashUnion.RIPEMD160ws = *wsHash;

    returnValue = esl_generateMaskMGF1(ESL_HA_RMD160, &wsHashUnion
   ,     tempHash, ESL_SIZEOF_RIPEMD160_DIGEST, seedLength, seed, maskLength, mask);
  }

  return returnValue;
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

