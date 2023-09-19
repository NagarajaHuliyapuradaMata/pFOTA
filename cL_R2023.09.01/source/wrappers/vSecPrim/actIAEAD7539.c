

#define ACTIAEAD7539_SOURCE

#include "actIAEAD7539.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTAEAD7539_ENABLED == STD_ON)

#define SIZEOF_POLY1305_KEY                                          (32)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actAEAD7539Init(VSECPRIM_P2VAR_PARA(actAEAD7539Context) ctx, VSECPRIM_P2CONST_PARA(actU8) key, VSECPRIM_P2CONST_PARA(actU8) nonce, const actU32 mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  ctx->mode = ((DIRECTION_ENCRYPT == mode) ? DIRECTION_ENCRYPT : DIRECTION_DECRYPT);

  actChaCha20Init(&(ctx->cc20), key, nonce, 0u, watchdog);
  actChaCha20NextBlock(&(ctx->cc20), watchdog);
  actPoly1305Init(&(ctx->p130), (VSECPRIM_P2CONST_PARA(actU8))(ctx->cc20.cipher));
  actChaCha20EatBlock(&(ctx->cc20));

  ctx->aadLenHI = 0u;
  ctx->aadLenLO = 0u;
  ctx->dataLenHI = 0u;
  ctx->dataLenLO = 0u;

  actL1trigger(watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actAEAD7539Update(VSECPRIM_P2VAR_PARA(actAEAD7539Context) ctx, VSECPRIM_P2CONST_PARA(actU8) in, const actLengthType iLen, VSECPRIM_P2VAR_PARA(actU8) out, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;
  actU32 lo, hi;

  switch(ctx->mode){
  case PHASE_AAD | DIRECTION_ENCRYPT:
  case PHASE_AAD | DIRECTION_DECRYPT:

    hi = ctx->aadLenHI;
    lo = ctx->aadLenLO + iLen;
    if(lo < ctx->aadLenLO){
      hi += 1u;
      if(hi == 0u)
      {
        retVal = actEXCEPTION_LENGTH;
      }
    }

    if(retVal == actOK){
      ctx->aadLenHI = hi;
      ctx->aadLenLO = lo;

      actPoly1305Update(&(ctx->p130), in, iLen, watchdog);
    }

    break;

  case PHASE_DATA | DIRECTION_ENCRYPT:
  case PHASE_DATA | DIRECTION_DECRYPT:

    hi = ctx->dataLenHI;
    lo = ctx->dataLenLO + iLen;
    if(lo < ctx->dataLenLO){
      hi++;
    }

    if((hi > 0x0000003FUL)
      || ((hi == 0x0000003FUL) && (lo > 0xFFFFFFC0UL))){
      retVal = actEXCEPTION_LENGTH;
    }

    if(retVal == actOK){
      ctx->dataLenHI = hi;
      ctx->dataLenLO = lo;

      if(DIRECTION_ENCRYPT == (ctx->mode & DIRECTION))
      {
        actChaCha20Cipher(&(ctx->cc20), in, iLen, out, watchdog);

        actPoly1305Update(&(ctx->p130), out, iLen, watchdog);
      }
      else
      {
        actPoly1305Update(&(ctx->p130), in, iLen, watchdog);

        actChaCha20Cipher(&(ctx->cc20), in, iLen, out, watchdog);
      }
    }

    break;

  default:
    retVal = actEXCEPTION_MODE;
    break;
  }

  return retVal;
}

VSECPRIM_FUNC(void) actAEAD7539SwitchToData(VSECPRIM_P2VAR_PARA(actAEAD7539Context) ctx){
  actPoly1305HandleRemains(&(ctx->p130), 1u, NULL_PTR);

  ctx->mode &= DIRECTION;
  ctx->mode |= PHASE_DATA;
}

VSECPRIM_FUNC(void) actAEAD7539Finalize(VSECPRIM_P2VAR_PARA(actAEAD7539Context) ctx, VSECPRIM_P2VAR_PARA(actU8) tag, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actPoly1305HandleRemains(&(ctx->p130), 1, NULL_PTR);

  actU32toLE(&(ctx->data[0]), ctx->aadLenLO);
  actU32toLE(&(ctx->data[4]), ctx->aadLenHI);
  actU32toLE(&(ctx->data[8]), ctx->dataLenLO);
  actU32toLE(&(ctx->data[12]), ctx->dataLenHI);
  actPoly1305Update(&(ctx->p130), ctx->data, sizeof(ctx->data), watchdog);
  actPoly1305Finalize(&(ctx->p130), tag, watchdog);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

