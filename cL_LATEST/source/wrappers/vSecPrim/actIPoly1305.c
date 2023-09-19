

#define ACTIPOLY1305_SOURCE

#include "actIPoly1305.hpp"
#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTPOLY1305_ENABLED == STD_ON)

#define BLOCK                                                        16u

#include "actPoly1305core.hpp"

#define poly_initCore(ws,  key)                                      actPoly1305_init   ((ws), (key))
#define poly_calcBlock(ws, data, pad, wd)                            actPoly1305_block  ((ws), (data), (pad), (wd))
#define poly_finalize(ws,  tag)                                      actPoly1305_finish ((ws), (tag))

#define VSECPRIM_START_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, actU8) padding[BLOCK] = {
  1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u
};

#define VSECPRIM_STOP_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actPoly1305Init(VSECPRIM_P2VAR_PARA(actPoly1305Context) ctx, VSECPRIM_P2CONST_PARA(actU8) key){
  poly_initCore(ctx, key);

  ctx->rLen = 0;
}

VSECPRIM_FUNC(void) actPoly1305Update(VSECPRIM_P2VAR_PARA(actPoly1305Context) ctx, VSECPRIM_P2CONST_PARA(actU8) data, const actLengthType dLen, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType len = dLen;
  actLengthType pos = 0u;

  if((BLOCK - ctx->rLen) > len){
    actMemCpyByteArray(&(ctx->remains[ctx->rLen]), data, len);
    ctx->rLen += len;

    return;
  }

  if(0u != ctx->rLen){
    actLengthType rLen = (BLOCK - ctx->rLen);

    actMemCpyByteArray(&(ctx->remains[ctx->rLen]), data, rLen);
    poly_calcBlock(ctx, ctx->remains, 1, watchdog);
    actL2trigger(watchdog);

    len -= rLen;
    pos = rLen;
  }

  while(BLOCK <= len){
    poly_calcBlock(ctx, &(data[pos]), 1, watchdog);
    actL2trigger(watchdog);

    len -= BLOCK;
    pos += BLOCK;
  }

  if(0u != len){
    actMemCpyByteArray(ctx->remains, &(data[pos]), len);
  }
  ctx->rLen = len;

  actL1trigger(watchdog);
}

VSECPRIM_FUNC(void) actPoly1305HandleRemains(VSECPRIM_P2VAR_PARA(actPoly1305Context) ctx, const actU8 fillUp, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 pad = ((fillUp != 0u) ? 1u : 0u);

  if(0u != ctx->rLen){
    VSECPRIM_P2VAR_PARA(actU8) t = &(ctx->remains[ctx->rLen]);
    VSECPRIM_P2ROMCONST_PARA(actU8) p = &(padding[pad]);

    actMemCpyByteArray(t, p, (BLOCK - ctx->rLen));
    poly_calcBlock(ctx, ctx->remains, pad, watchdog);
    ctx->rLen = 0;

    actL2trigger(watchdog);
  }
}

VSECPRIM_FUNC(void) actPoly1305Finalize(VSECPRIM_P2VAR_PARA(actPoly1305Context) ctx, VSECPRIM_P2VAR_PARA(actU8) tag, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actPoly1305HandleRemains(ctx, 0, watchdog);
  poly_finalize(ctx, tag);

  actMemset(ctx->opaque, 0, sizeof(ctx->opaque));
  actL1trigger(watchdog);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

