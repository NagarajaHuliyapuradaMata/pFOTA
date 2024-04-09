

#ifndef ACTIHASHMAC256_H
#define ACTIHASHMAC256_H

#include "actITypes.hpp"
#include "actISHA2_32.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA256Init(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA256STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key
   ,  actLengthType key_length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA256Update(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA256STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA256Finalize(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA256STRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
}
#endif

#endif

