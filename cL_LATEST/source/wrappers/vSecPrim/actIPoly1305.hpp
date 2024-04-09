

#ifndef ACTIPoly1305_H
#define ACTIPoly1305_H

#include "actITypes.hpp"
#include "actBigNum.hpp"

typedef struct{
  actU8 remains[16];
  actU32 rLen;

  actU8 opaque[140];

}actPoly1305Context;

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

extern VSECPRIM_FUNC(void) actPoly1305Init(VSECPRIM_P2VAR_PARA(actPoly1305Context) ctx
   ,  VSECPRIM_P2CONST_PARA(actU8) key);

extern VSECPRIM_FUNC(void) actPoly1305Update(VSECPRIM_P2VAR_PARA(actPoly1305Context) ctx
   ,  VSECPRIM_P2CONST_PARA(actU8) data
   ,  const actLengthType dLen
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) actPoly1305HandleRemains(VSECPRIM_P2VAR_PARA(actPoly1305Context) ctx
   ,  const actU8 fillUp
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) actPoly1305Finalize(VSECPRIM_P2VAR_PARA(actPoly1305Context) ctx
   ,  VSECPRIM_P2VAR_PARA(actU8) tag
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"
#endif

