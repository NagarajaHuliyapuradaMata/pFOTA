

#ifndef ESLIB_HELPER_H
#define ESLIB_HELPER_H

#include "ESLib.hpp"
#include "ESLib_types.hpp"

#include "actUtilities.hpp"

#define Esl_MemSet(dest, fill, count)                                (actMemset(dest, fill, count))
#define Esl_MemClear(dest, count)                                    (actMemClear(dest, count))
#define Esl_MemCpyByteArray(dest, src, count)                        (actMemCpyByteArray(dest, src, count))
#define Esl_MemCpyWordArray(dest, src, count)                        (actMemCpyWordArray(dest, src, count))

typedef VSECPRIM_P2VAR_PARA(eslt_WorkSpace) eslt_WorkSpaceRefType;
typedef VSECPRIM_P2CONST_PARA(eslt_WorkSpace) eslt_WorkSpaceConstRefType;

typedef VSECPRIM_P2CONST_PARA(eslt_Length) eslt_LengthConstRef;

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) esl_ResetAndClearWorkspace(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHeader) workSpaceHeader
   ,  VSECPRIM_P2VAR_PARA(void) workSpaceBuffer);

VSECPRIM_FUNC(void) esl_SetWorkspaceStatus(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHeader) workSpaceHeader
   ,  eslt_WSStatus algo);

VSECPRIM_FUNC(void) esl_SetWorkspaceSize(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHeader) workSpaceHeader
   ,  const eslt_Length workSpaceSize);

VSECPRIM_FUNC(eslt_ErrorCode) esl_CheckWorkSpaceHeader(VSECPRIM_P2CONST_PARA(eslt_WorkSpaceHeader) workSpaceHeader
   ,  eslt_Length minSize);

VSECPRIM_FUNC(eslt_ErrorCode) esl_CheckWorkSpaceState(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceHeader) workSpaceHeader
   ,  eslt_WSStatus algo);

VSECPRIM_FUNC(eslt_ErrorCode) esl_CheckWorkSpaceHeaderAndState(VSECPRIM_P2CONST_PARA(eslt_WorkSpaceHeader) workSpaceHeader
   ,  eslt_Length minSize
   ,  eslt_WSStatus algo);

VSECPRIM_FUNC(eslt_ErrorCode) esl_checkLengthRef(eslt_LengthConstRef lenRef
   ,  eslt_Length lengthValue);

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

