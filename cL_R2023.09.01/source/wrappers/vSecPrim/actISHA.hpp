

#ifndef ACTISHA_H
#define ACTISHA_H

#include "actITypes.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

VSECPRIM_FUNC(actRETURNCODE) actSHAInit(VSECPRIM_P2VAR_PARA(actSHASTRUCT) info);

VSECPRIM_FUNC(actRETURNCODE) actSHAUpdate(
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHAFinalize(
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actSHAGetDigest(
  VSECPRIM_P2CONST_PARA(actSHASTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

