

#ifndef ACTIRMD160_H
#define ACTIRMD160_H

#include "actITypes.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actRMD160Init(VSECPRIM_P2VAR_PARA(actRMD160STRUCT) info);

VSECPRIM_FUNC(actRETURNCODE) actRMD160Update(
   VSECPRIM_P2VAR_PARA(actRMD160STRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actRMD160Finalize(
   VSECPRIM_P2VAR_PARA(actRMD160STRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
}
#endif

#endif

