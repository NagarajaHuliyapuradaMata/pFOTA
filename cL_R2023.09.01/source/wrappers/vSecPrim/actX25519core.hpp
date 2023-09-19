

#ifndef ACTX25519CORE_H
#define ACTX25519CORE_H

#include "act25519util.hpp"
#include "actIX25519.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

extern VSECPRIM_FUNC(void) actX25519_initCore(VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws);

extern VSECPRIM_FUNC(actRETURNCODE) actX25519_eval(
  VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

