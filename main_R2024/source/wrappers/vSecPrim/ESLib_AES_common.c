

#define ESLIB_AES_COMMON_SOURCE

#include "ESLib_AES_common.hpp"

#if((VSECPRIM_AES128_ENABLED == STD_ON) || (VSECPRIM_AES192_ENABLED == STD_ON) || (VSECPRIM_AES256_ENABLED == STD_ON))

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_AES_setBlockAndPaddingModes(VSECPRIM_P2VAR_PARA(eslt_Byte) target, eslt_BlockMode extBlockMode, eslt_PaddingMode extPaddingMode){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;
  *target = actPADDING_PM_OFF;

  switch(extPaddingMode){
    case ESL_PM_PKCS5:
    {
      *target = actPADDING_PM_PKCS7;
      break;
    }
    case ESL_PM_OFF:
    {
      break;
    }
    case ESL_PM_ONEWITHZEROES:
    {
      *target = actPADDING_PM_ONEWITHZEROES;
      break;
    }
    default:
    {
      retVal = ESL_ERC_MODE_INVALID;
      break;
    }
  }

  switch(extBlockMode){
    case ESL_BM_ECB:
    {
      *target |= actAES_BM_ECB;
      break;
    }
    case ESL_BM_CBC:
    {
      *target |= actAES_BM_CBC;
      break;
    }
    case ESL_BM_CTR:
    {
      *target |= actAES_BM_CTR;
      break;
    }
    default:
    {
      retVal = ESL_ERC_MODE_INVALID;
      break;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_AES_CommonInitChecks(VSECPRIM_P2CONST_PARA(eslt_WorkSpaceAES) workSpace, eslt_Length wsSize, VSECPRIM_P2CONST_PARA(eslt_Byte) key){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    retVal = esl_CheckWorkSpaceHeader(&workSpace->header, wsSize);
    if((retVal == ESL_ERC_NO_ERROR) && (key == NULL_PTR)){
      retVal = ESL_ERC_PARAMETER_INVALID;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_AES_CommonInit(VSECPRIM_P2VAR_PARA(eslt_Byte) targetMode, VSECPRIM_P2CONST_PARA(eslt_WorkSpaceAES) workSpace, eslt_Length wsSize, VSECPRIM_P2CONST_PARA(eslt_Byte) key,
                                                        eslt_BlockMode blockMode, eslt_PaddingMode paddingMode){
  eslt_ErrorCode retVal = esl_AES_CommonInitChecks(workSpace, wsSize, key);

  if(retVal == ESL_ERC_NO_ERROR){
    retVal = esl_AES_setBlockAndPaddingModes(targetMode, blockMode, paddingMode);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_AES_CommonProcChecks(VSECPRIM_P2CONST_PARA(eslt_WorkSpaceAES) workSpace, eslt_WSStatus algo, eslt_Length wsSize, VSECPRIM_P2CONST_PARA(eslt_Byte) inBuffer, VSECPRIM_P2CONST_PARA(eslt_Byte) outBuffer){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (inBuffer == NULL_PTR) || (outBuffer == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, wsSize, algo);
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

