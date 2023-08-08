

#define ESLIB_AEAD_CHACHA20_POLY1305_SOURCE
#include "ESLib_Helper.hpp"

#include "actIAEAD7539.hpp"

#if(VSECPRIM_AEAD_CHA_CHA20_POLY1305_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL VSECPRIM_FUNC( eslt_ErrorCode ) initChaChaPoly (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaChaPoly ) workSpace,
                                                       VSECPRIM_P2CONST_PARA( eslt_Byte ) key,
                                                       VSECPRIM_P2CONST_PARA( eslt_Byte ) nonce,
                                                       const eslt_Byte mode);

VSECPRIM_FUNC( eslt_ErrorCode ) esl_initEncryptChaChaPoly (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaChaPoly ) workSpace,
                                                           VSECPRIM_P2CONST_PARA( eslt_Byte ) key,
                                                           VSECPRIM_P2CONST_PARA( eslt_Byte )nonce){
  return initChaChaPoly (workSpace, key, nonce, DIRECTION_ENCRYPT);
}

VSECPRIM_FUNC( eslt_ErrorCode ) esl_initDecryptChaChaPoly (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaChaPoly ) workSpace,
                                                           VSECPRIM_P2CONST_PARA( eslt_Byte ) key,
                                                           VSECPRIM_P2CONST_PARA( eslt_Byte )nonce){
  return initChaChaPoly (workSpace, key, nonce, DIRECTION_DECRYPT);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateAADChaChaPoly(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaChaPoly) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) aad,
  const eslt_Length aadSize){
  VSECPRIM_P2VAR_PARA(actAEAD7539Context) ctx;
  actRETURNCODE rc;

  if((NULL == workSpace)
    || (NULL == aad)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((ESL_WST_ALGO_AEAD_7539 != (workSpace->header.status & ESL_WST_M_ALGO))
    || (ESL_WST_M_RUNNING != (workSpace->header.status & ESL_WST_M_RUNNING))){
    return ESL_ERC_WS_STATE_INVALID;
  }

  ctx = (VSECPRIM_P2VAR_PARA(actAEAD7539Context)) workSpace->wsAEADChaChaPoly;
  if(PHASE_AAD != (ctx->mode & PHASE)){
    return ESL_ERC_WS_STATE_INVALID;
  }

  rc = actAEAD7539Update(ctx, aad, aadSize, NULL, workSpace->header.watchdog);
  if(actOK != rc){
    if(actEXCEPTION_LENGTH == rc){
      return ESL_ERC_TOTAL_LENGTH_OVERFLOW;
    }
    if(actEXCEPTION_MODE == rc){
      return  ESL_ERC_WS_STATE_INVALID;
    }
    return ESL_ERC_ERROR;
  }

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateDataChaChaPoly(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaChaPoly) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) in,
  const eslt_Length inSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte)out,
  VSECPRIM_P2VAR_PARA(eslt_Length) outSize){
  VSECPRIM_P2VAR_PARA(actAEAD7539Context) ctx;
  actRETURNCODE rc;

  if((NULL == workSpace)
    || (NULL == in)
    || (NULL == out)
    || (NULL == outSize)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if(inSize > *outSize){
    return ESL_ERC_BUFFER_TOO_SMALL;
  }

  if((ESL_WST_ALGO_AEAD_7539 != (workSpace->header.status & ESL_WST_M_ALGO))
    || (ESL_WST_M_RUNNING != (workSpace->header.status & ESL_WST_M_RUNNING))){
    return ESL_ERC_WS_STATE_INVALID;
  }

  ctx = (VSECPRIM_P2VAR_PARA(actAEAD7539Context)) workSpace->wsAEADChaChaPoly;
  if(PHASE_DATA != (ctx->mode & PHASE)){
    actAEAD7539SwitchToData(ctx);
  }

  rc = actAEAD7539Update(ctx, in, inSize, out, workSpace->header.watchdog);
  if(actOK != rc){
    if(actEXCEPTION_LENGTH == rc){
      return ESL_ERC_TOTAL_LENGTH_OVERFLOW;
    }
    if(actEXCEPTION_MODE == rc){
      return ESL_ERC_WS_STATE_INVALID;
    }
    return ESL_ERC_ERROR;
  }

  *outSize = inSize;

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeChaChaPoly(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaChaPoly) workSpace,
                                                     VSECPRIM_P2VAR_PARA(eslt_Byte) tag){
  VSECPRIM_P2VAR_PARA(actAEAD7539Context) ctx;

  if((NULL == workSpace)
    || (NULL == tag)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((ESL_WST_ALGO_AEAD_7539 != (workSpace->header.status & ESL_WST_M_ALGO))
    || (ESL_WST_M_RUNNING != (workSpace->header.status & ESL_WST_M_RUNNING))){
    return ESL_ERC_WS_STATE_INVALID;
  }

  ctx = (VSECPRIM_P2VAR_PARA(actAEAD7539Context)) workSpace->wsAEADChaChaPoly;
  actAEAD7539Finalize(ctx, tag, workSpace->header.watchdog);

  esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsAEADChaChaPoly);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC( eslt_ErrorCode ) esl_verifyChaChaPoly (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaChaPoly ) workSpace,
                      VSECPRIM_P2CONST_PARA( eslt_Byte ) tag){
  actU8 tmpTag [ESL_SIZEOF_Poly1305_TAG];
  eslt_ErrorCode erc;

  erc = esl_finalizeChaChaPoly (workSpace, tmpTag);
  if(ESL_ERC_NO_ERROR != erc){
    return erc;
  }

  if(TRUE != actMemcmp(tmpTag, tag, ESL_SIZEOF_Poly1305_TAG)){
    return ESL_ERC_INCORRECT_TAG;
  }

  esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsAEADChaChaPoly);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_LOCAL VSECPRIM_FUNC( eslt_ErrorCode ) initChaChaPoly (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceChaChaPoly ) workSpace, VSECPRIM_P2CONST_PARA( eslt_Byte ) key, VSECPRIM_P2CONST_PARA( eslt_Byte ) nonce, const eslt_Byte mode){
  VSECPRIM_P2VAR_PARA( actAEAD7539Context ) ctx;

  if((NULL == workSpace)
    || (NULL == key)
    || (NULL == nonce)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if(ESL_SIZEOF_WS_AEAD_ChaCha_Poly > workSpace->header.size){
    return ESL_ERC_WS_TOO_SMALL;
  }

  ctx = (VSECPRIM_P2VAR_PARA( actAEAD7539Context )) workSpace->wsAEADChaChaPoly;
  actAEAD7539Init (ctx, key, nonce, mode, workSpace->header.watchdog);

  workSpace->header.status = (ESL_WST_ALGO_AEAD_7539 | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

  return ESL_ERC_NO_ERROR;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

