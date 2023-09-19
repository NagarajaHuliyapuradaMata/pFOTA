

#ifndef ACTIAEAD7539_H
#define ACTIAEAD7539_H

#include "actITypes.hpp"
#include "actIChaCha20.hpp"
#include "actIPoly1305.hpp"

#define PHASE                                                        1u
#define PHASE_AAD                                                    0u
#define PHASE_DATA                                                   1u
#define DIRECTION                                                    2u
#define DIRECTION_ENCRYPT                                            0u
#define DIRECTION_DECRYPT                                            2u

typedef struct{
  actU32 mode;
  actU8 data[16];
  actU32 aadLenLO, aadLenHI;
  actU32 dataLenLO, dataLenHI;
  actChaCha20Context cc20;
  actPoly1305Context p130;
}actAEAD7539Context;

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

extern VSECPRIM_FUNC(void) actAEAD7539Init(VSECPRIM_P2VAR_PARA(actAEAD7539Context) ctx
   ,  VSECPRIM_P2CONST_PARA(actU8) key
   ,  VSECPRIM_P2CONST_PARA(actU8) nonce
   ,  const actU32 mode
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actRETURNCODE) actAEAD7539Update(VSECPRIM_P2VAR_PARA(actAEAD7539Context) ctx
   ,  VSECPRIM_P2CONST_PARA(actU8) in
   ,  const actLengthType iLen
   ,  VSECPRIM_P2VAR_PARA(actU8) out
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actAEAD7539SwitchToData(VSECPRIM_P2VAR_PARA(actAEAD7539Context) ctx);

VSECPRIM_FUNC(void) actAEAD7539Finalize(VSECPRIM_P2VAR_PARA(actAEAD7539Context) ctx
   ,  VSECPRIM_P2VAR_PARA(actU8) tag
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

