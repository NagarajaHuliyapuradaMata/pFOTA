

#ifndef ACTIChaCha20_H
#define ACTIChaCha20_H

#include "actITypes.hpp"

typedef struct{
  actU32 iState[16];
  actU8 cipher[64];
  actLengthType c;
}actChaCha20Context;

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

extern VSECPRIM_FUNC(void) actChaCha20Init(VSECPRIM_P2VAR_PARA( actChaCha20Context ) ctx
   ,  VSECPRIM_P2CONST_PARA( actU8 ) key
   ,  VSECPRIM_P2CONST_PARA( actU8 ) nonce
   ,  const actU32 bCount
   ,  VSECPRIM_P2FUNC( VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) actChaCha20Cipher(VSECPRIM_P2VAR_PARA( actChaCha20Context ) ctx
   ,  VSECPRIM_P2CONST_PARA( actU8 ) in
   ,  const actLengthType iLen
   ,  VSECPRIM_P2VAR_PARA( actU8 ) out
   ,  VSECPRIM_P2FUNC( VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actChaCha20NextBlock(VSECPRIM_P2VAR_PARA( actChaCha20Context ) ctx
   ,  VSECPRIM_P2FUNC( VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actChaCha20EatBlock(VSECPRIM_P2VAR_PARA( actChaCha20Context ) ctx);

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

