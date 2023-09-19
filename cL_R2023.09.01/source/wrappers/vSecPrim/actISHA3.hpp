

#ifndef ACTISHA3_H
#define ACTISHA3_H

#include "actITypes.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
    extern "C" {
#endif

VSECPRIM_FUNC(actRETURNCODE) actSHA3Init(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info
   ,  const actU32 strength);

VSECPRIM_FUNC(actRETURNCODE) actSHA3Update(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) data
   ,  const actLengthType dataLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSHA3Finalize(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) digest
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
    }
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

