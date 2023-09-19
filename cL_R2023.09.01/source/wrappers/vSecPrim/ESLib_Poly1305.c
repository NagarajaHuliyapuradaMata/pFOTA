

#define ESLIB_POLY1305_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIPoly1305.hpp"

#if(VSECPRIM_POLY1305_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initPoly1305(VSECPRIM_P2VAR_PARA( eslt_WorkSpacePoly1305 ) workSpace
   ,                                              VSECPRIM_P2CONST_PARA( eslt_Byte ) key){
  if((NULL == workSpace)
    || (NULL == key)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if(ESL_SIZEOF_WS_Poly1305 > workSpace->header.size){
    return ESL_ERC_WS_TOO_SMALL;
  }

  actPoly1305Init((VSECPRIM_P2VAR_PARA(actPoly1305Context)) workSpace->wsPoly1305, key);

  workSpace->header.status = (ESL_WST_ALGO_Poly1305 | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updatePoly1305(VSECPRIM_P2VAR_PARA( eslt_WorkSpacePoly1305 ) workSpace
   ,                                                VSECPRIM_P2CONST_PARA( eslt_Byte ) message
   ,                                                const eslt_Length msgSize){
  if((NULL == workSpace)
    || (NULL == message)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((ESL_WST_ALGO_Poly1305 != (workSpace->header.status & ESL_WST_M_ALGO))
    || (ESL_WST_M_RUNNING != (workSpace->header.status & ESL_WST_M_RUNNING))){
    return ESL_ERC_WS_STATE_INVALID;
  }

  actPoly1305Update((VSECPRIM_P2VAR_PARA( actPoly1305Context ))workSpace->wsPoly1305, message, msgSize, workSpace->header.watchdog);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizePoly1305 (VSECPRIM_P2VAR_PARA( eslt_WorkSpacePoly1305 ) workSpace
   ,                                                   VSECPRIM_P2VAR_PARA( eslt_Byte ) tag){
  if((NULL == workSpace)
    || (NULL == tag)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((ESL_WST_ALGO_Poly1305 != (workSpace->header.status & ESL_WST_M_ALGO))
    || (ESL_WST_M_RUNNING != (workSpace->header.status & ESL_WST_M_RUNNING))){
    return ESL_ERC_WS_STATE_INVALID;
  }

  actPoly1305Finalize ((VSECPRIM_P2VAR_PARA( actPoly1305Context )) workSpace->wsPoly1305, tag, workSpace->header.watchdog);

  esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsPoly1305);

  return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyPoly1305 (VSECPRIM_P2VAR_PARA( eslt_WorkSpacePoly1305 ) workSpace
   ,                                                 VSECPRIM_P2CONST_PARA( eslt_Byte ) tag){
  eslt_Byte tmpTag [ESL_SIZEOF_Poly1305_TAG];

  if((NULL == workSpace)
    || (NULL == tag)){
    return ESL_ERC_PARAMETER_INVALID;
  }

  if((ESL_WST_ALGO_Poly1305 != (workSpace->header.status & ESL_WST_M_ALGO))
    || (ESL_WST_M_RUNNING != (workSpace->header.status & ESL_WST_M_RUNNING))){
    return ESL_ERC_WS_STATE_INVALID;
  }

  actPoly1305Finalize ((VSECPRIM_P2VAR_PARA( actPoly1305Context )) workSpace->wsPoly1305, tmpTag, workSpace->header.watchdog);

  if(TRUE != actMemcmp(tmpTag, tag, ESL_SIZEOF_Poly1305_TAG)){
    return ESL_ERC_INCORRECT_TAG;
  }

  esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsPoly1305);

  return ESL_ERC_NO_ERROR;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

