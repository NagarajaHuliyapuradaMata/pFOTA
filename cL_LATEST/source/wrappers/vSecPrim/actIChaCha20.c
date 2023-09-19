

#define ACTIChaCha20_SOURCE

#include "actIChaCha20.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTCHACHA20_ENABLED == STD_ON)

#define CHACHA_0                                                     0x61707865
#define CHACHA_1                                                     0x3320646e
#define CHACHA_2                                                     0x79622d32
#define CHACHA_3                                                     0x6b206574

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL VSECPRIM_FUNC(void) dotheChaCha(VSECPRIM_P2VAR_PARA( actChaCha20Context ) ctx, VSECPRIM_P2FUNC( VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actChaCha20Init(VSECPRIM_P2VAR_PARA(actChaCha20Context) ctx, VSECPRIM_P2CONST_PARA(actU8) key, VSECPRIM_P2CONST_PARA(actU8) nonce, const actU32 bCount, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  ctx->iState[0] = CHACHA_0;
  ctx->iState[1] = CHACHA_1;
  ctx->iState[2] = CHACHA_2;
  ctx->iState[3] = CHACHA_3;
  actCpyLEtoU32(&(ctx->iState[4]), key, 32);
  ctx->iState[12] = bCount;
  actCpyLEtoU32(&(ctx->iState[13]), nonce, 12);

  ctx->c = 64;

  actL1trigger(watchdog);
}

VSECPRIM_FUNC(void) actChaCha20Cipher(VSECPRIM_P2VAR_PARA(actChaCha20Context) ctx, VSECPRIM_P2CONST_PARA(actU8) in, const actLengthType iLen, VSECPRIM_P2VAR_PARA(actU8) out, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType i;

  for(i = 0u; i < iLen; i++){
    if(ctx->c >= 64u){
      dotheChaCha(ctx, watchdog);
      ctx->c = 0;
    }
    out[i] = in[i] ^ ctx->cipher[ctx->c];
    ctx->c++;
  }

  actL1trigger(watchdog);
}

VSECPRIM_FUNC(void) actChaCha20NextBlock(VSECPRIM_P2VAR_PARA(actChaCha20Context) ctx, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  dotheChaCha(ctx, watchdog);
}

VSECPRIM_FUNC(void) actChaCha20EatBlock(VSECPRIM_P2VAR_PARA(actChaCha20Context) ctx){
  ctx->c = 64;
}

#if actChaCha20_SPEED_UP >= 1
#define doQRound(state, a, b, c, d)                                 \
                                                                      state [a] += state [b]; state [d] ^= state [a]; state [d] = actRotl (state [d], 16); \
                                                                      state [c] += state [d]; state [b] ^= state [c]; state [b] = actRotl (state [b], 12); \
                                                                      state [a] += state [b]; state [d] ^= state [a]; state [d] = actRotl (state [d],  8); \
                                                                      state [c] += state [d]; state [b] ^= state [c]; state [b] = actRotl (state [b],  7);
#else

VSECPRIM_LOCAL VSECPRIM_FUNC(void) doQRound(VSECPRIM_P2VAR_PARA(actU32) state, actLengthType a, actLengthType b, actLengthType c, actLengthType d){
  state[a] += state[b]; state[d] ^= state[a]; state[d] = actRotl(state[d], 16);
  state[c] += state[d]; state[b] ^= state[c]; state[b] = actRotl(state[b], 12);
  state[a] += state[b]; state[d] ^= state[a]; state[d] = actRotl(state[d], 8);
  state[c] += state[d]; state[b] ^= state[c]; state[b] = actRotl(state[b], 7);
}
#endif

VSECPRIM_LOCAL VSECPRIM_FUNC(void) dotheChaCha(VSECPRIM_P2VAR_PARA(actChaCha20Context) ctx, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU32  cState[16];

  actLengthType i;

  for(i = 0u; i <= 15u; i++){
    cState[i] = ctx->iState[i];
  }

#if actChaCha20_SPEED_UP >= 2
  for(i = 0u; i < 5u; i++) {
    doQRound (cState,  0,  4,  8, 12);
    doQRound (cState,  1,  5,  9, 13);
    doQRound (cState,  2,  6, 10, 14);
    doQRound (cState,  3,  7, 11, 15);
    doQRound (cState,  0,  5, 10, 15);
    doQRound (cState,  1,  6, 11, 12);
    doQRound (cState,  2,  7,  8, 13);
    doQRound (cState,  3,  4,  9, 14);
    doQRound (cState,  0,  4,  8, 12);
    doQRound (cState,  1,  5,  9, 13);
    doQRound (cState,  2,  6, 10, 14);
    doQRound (cState,  3,  7, 11, 15);
    doQRound (cState,  0,  5, 10, 15);
    doQRound (cState,  1,  6, 11, 12);
    doQRound (cState,  2,  7,  8, 13);
    doQRound (cState,  3,  4,  9, 14);

    actL2trigger(watchdog);
  }
#else
  for(i = 0u; i < 10u; i++){
    doQRound(cState, 0, 4, 8, 12);
    doQRound(cState, 1, 5, 9, 13);
    doQRound(cState, 2, 6, 10, 14);
    doQRound(cState, 3, 7, 11, 15);
    doQRound(cState, 0, 5, 10, 15);
    doQRound(cState, 1, 6, 11, 12);
    doQRound(cState, 2, 7, 8, 13);
    doQRound(cState, 3, 4, 9, 14);

    actL2trigger(watchdog);
  }
#endif

  for(i = 0u; i <= 15u; i++){
    cState[i] += ctx->iState[i];
  }
  actCpyU32toLE(ctx->cipher, cState, 16);

  ctx->iState[12]++;

  actL1trigger(watchdog);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

