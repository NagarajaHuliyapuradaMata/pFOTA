

#ifndef ACTIX25519_H
#define ACTIX25519_H

#include "actITypes.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

extern VSECPRIM_FUNC(actRETURNCODE) actX25519Init(VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws);

extern VSECPRIM_FUNC(actRETURNCODE) actX25519GenKeyPair(
  VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws
   ,  VSECPRIM_P2VAR_PARA(actU8) publicKey
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actRETURNCODE) actX25519ImportPrivateKey(
  VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) privateKey
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actRETURNCODE) actX25519GenSecret(
  VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) publicKey
   ,  VSECPRIM_P2VAR_PARA(actU8) sharedSecret
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

