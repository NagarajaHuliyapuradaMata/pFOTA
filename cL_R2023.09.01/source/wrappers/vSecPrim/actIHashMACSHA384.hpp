

#ifndef ACTIHASHMAC384_H
#define ACTIHASHMAC384_H

#include "actITypes.hpp"
#include "actISHA2_64.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA384Init(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA384STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA384Update(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA384STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA384Finalize(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA384STRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
}
#endif

#endif

