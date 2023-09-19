

#ifndef ACTED25519_H
#define ACTED25519_H

#include "actITypes.hpp"
#include "actIEd25519.hpp"
#include "actISHA2_64.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

VSECPRIM_FUNC(actRETURNCODE) act25519_hashPM(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) act25519_hashRAM(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) R
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

