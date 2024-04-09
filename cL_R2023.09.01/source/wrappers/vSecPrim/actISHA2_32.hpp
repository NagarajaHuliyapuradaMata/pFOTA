

#ifndef ACTISHA2_32_H
#define ACTISHA2_32_H

#include "actITypes.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

VSECPRIM_FUNC(actRETURNCODE) actSHA224Init(VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info);

VSECPRIM_FUNC(actRETURNCODE) actSHA256Init(VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info);

VSECPRIM_FUNC(actRETURNCODE) actSHA224Update(
  VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHA256Update(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHA224Finalize(
  VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHA256Finalize(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
  }
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

