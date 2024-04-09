

#ifndef ACTIED25519_H
#define ACTIED25519_H

#include "actITypes.hpp"
#include "actISHA2_64.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

extern VSECPRIM_FUNC(actRETURNCODE) actEd25519Init(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  const actU8 instance
   ,  VSECPRIM_P2CONST_PARA(actU8) context
   ,  const actLengthType ctxLen);

extern VSECPRIM_FUNC(actRETURNCODE) actEd25519Update(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) message
   ,  const actLengthType msgLen
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actRETURNCODE) actEd25519Sign(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) message
   ,  const actLengthType msgLen
   ,  VSECPRIM_P2CONST_PARA(actU8) secretKey
   ,  VSECPRIM_P2CONST_PARA(actU8) publicKey
   ,  VSECPRIM_P2VAR_PARA(actU8) signature
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actRETURNCODE) actEd25519Verify(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) message
   ,  const actLengthType msgLen
   ,  VSECPRIM_P2CONST_PARA(actU8) publicKey
   ,  VSECPRIM_P2CONST_PARA(actU8) signature
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actRETURNCODE) actEd25519GenKeyPair(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2VAR_PARA(actU8) secretKey
   ,  VSECPRIM_P2VAR_PARA(actU8) publicKey
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

