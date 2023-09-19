

#ifndef ACTIHASHMACRMD160_H
#define ACTIHASHMACRMD160_H

#include "actITypes.hpp"
#include "actIRMD160.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actHashMACRMD160Init(
   VSECPRIM_P2VAR_PARA(actHASHMACRMD160STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actHashMACRMD160Update(
   VSECPRIM_P2VAR_PARA(actHASHMACRMD160STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actHashMACRMD160Finalize(
   VSECPRIM_P2VAR_PARA(actHASHMACRMD160STRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
}
#endif

#endif

