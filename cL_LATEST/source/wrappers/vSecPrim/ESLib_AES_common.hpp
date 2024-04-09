

#ifndef ESLIB_AES_COMMON_H
#define ESLIB_AES_COMMON_H

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIAES.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_AES_setBlockAndPaddingModes(VSECPRIM_P2VAR_PARA(eslt_Byte) target, eslt_BlockMode extBlockMode, eslt_PaddingMode extPaddingMode);

VSECPRIM_FUNC(eslt_ErrorCode) esl_AES_CommonInitChecks(VSECPRIM_P2CONST_PARA(eslt_WorkSpaceAES) workSpace, eslt_Length wsSize, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

VSECPRIM_FUNC(eslt_ErrorCode) esl_AES_CommonInit(VSECPRIM_P2VAR_PARA(eslt_Byte) targetMode, VSECPRIM_P2CONST_PARA(eslt_WorkSpaceAES) workSpace, eslt_Length wsSize, VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  eslt_BlockMode blockMode, eslt_PaddingMode paddingMode);

VSECPRIM_FUNC(eslt_ErrorCode) esl_AES_CommonProcChecks(VSECPRIM_P2CONST_PARA(eslt_WorkSpaceAES) workSpace, eslt_WSStatus algo, eslt_Length wsSize, VSECPRIM_P2CONST_PARA(eslt_Byte) inBuffer, VSECPRIM_P2CONST_PARA(eslt_Byte) outBuffer);

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

