

#define ACTSHA_SOURCE

#include "actISHA.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"
#include "actConfig.hpp"

#if(VSECPRIM_ACTSHA_ENABLED == STD_ON)

#define actSHA_WORD_SIZE                                             (4u)

#define f1(x, y, z)                                                  ((z)^((x)&((y)^(z))))
#define f2(x, y, z)                                                  ((x)^(y)^(z))
#define f3(x, y, z)                                                  (((x)&(y))|((z)&((x)|(y))))
#define f4(x, y, z)                                                  ((x)^(y)^(z))

#define blk0(W, i)                                                   ((W)[(i)])
#if(actSHA_SPEED_UP > 2)

#define blk1(W, i)                                                  actRotl((W)[((i)+13u)&15u]^(W)[((i)+8u)&15u]^(W)[((i)+2u)&15u]^(W)[(i)&15u], 1u)
#endif

#if(actSHA_SPEED_UP > 0)

#define actRotl5(x)                                                 (actRotl((x), 5))
#define actRotl30(x)                                                (actRotl((x), 30))
#endif

#define R0(v, w, x, y, z, i)                                         ((z) += f1((w), (x), (y)) + blk0(W, (i)) + 0x5A827999uL + actRotl5((v)))
#define R1(v, w, x, y, z, i)                                         ((W)[(i)&15u]) = blk1(W, (i)); ((z) += f1((w), (x), (y)) + ((W)[(i)&15u]) + 0x5A827999uL + actRotl5((v)))
#define R2(v, w, x, y, z, i)                                         ((W)[(i)&15u]) = blk1(W, (i)); ((z) += f2((w), (x), (y)) + ((W)[(i)&15u]) + 0x6ED9EBA1uL + actRotl5((v)))
#define R3(v, w, x, y, z, i)                                         ((W)[(i)&15u]) = blk1(W, (i)); ((z) += f3((w), (x), (y)) + ((W)[(i)&15u]) + 0x8F1BBCDCuL + actRotl5((v)))
#define R4(v, w, x, y, z, i)                                         ((W)[(i)&15u]) = blk1(W, (i)); ((z) += f4((w), (x), (y)) + ((W)[(i)&15u]) + 0xCA62C1D6uL + actRotl5((v)))

#define RL(w)                                                        ((w)=actRotl30((w)))

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actSHATransform(
  VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU32) H
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#if(!(actSHA_SPEED_UP > 2))

VSECPRIM_LOCAL_FUNC(actU32) blk1(VSECPRIM_P2CONST_PARA(actU32) W, actU32 i);
#endif

#if(actSHA_SPEED_UP == 0u)

VSECPRIM_LOCAL_FUNC(actU32) actRotl5(actU32 x);

VSECPRIM_LOCAL_FUNC(actU32) actRotl30(actU32 x);
#endif

VSECPRIM_LOCAL_FUNC(void) actSHATransform(
  VSECPRIM_P2CONST_PARA(actU8) in
   ,  VSECPRIM_P2VAR_PARA(actU32) H
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU32 W[16] = { 0u };
#if(actSHA_SPEED_UP < 2u)
  actU32 t;
  actLengthType i;
#endif

  actU32 Aval = H[0];
  actU32 Bval = H[1];
  actU32 Cval = H[2];
  actU32 Dval = H[3];
  actU32 Eval = H[4];

  actL1trigger(watchdog);

   actCpyBEtoU32 (W, in, actHASH_BLOCK_SIZE_SHA);

#if(actSHA_SPEED_UP > 1)

   R0(Aval, Bval, Cval, Dval, Eval, 0u); RL(Bval); actL3trigger(watchdog);   R0(Eval, Aval, Bval, Cval, Dval, 1u); RL(Aval); actL3trigger(watchdog);   R0(Dval, Eval, Aval, Bval, Cval, 2u); RL(Eval); actL3trigger(watchdog);   R0(Cval, Dval, Eval, Aval, Bval, 3u); RL(Dval); actL3trigger(watchdog);
   R0(Bval, Cval, Dval, Eval, Aval, 4u); RL(Cval); actL3trigger(watchdog);   R0(Aval, Bval, Cval, Dval, Eval, 5u); RL(Bval); actL3trigger(watchdog);   R0(Eval, Aval, Bval, Cval, Dval, 6u); RL(Aval); actL3trigger(watchdog);   R0(Dval, Eval, Aval, Bval, Cval, 7u); RL(Eval); actL3trigger(watchdog);
   R0(Cval, Dval, Eval, Aval, Bval, 8u); RL(Dval); actL3trigger(watchdog);   R0(Bval, Cval, Dval, Eval, Aval, 9u); RL(Cval); actL3trigger(watchdog);   R0(Aval, Bval, Cval, Dval, Eval, 10u); RL(Bval); actL3trigger(watchdog);   R0(Eval, Aval, Bval, Cval, Dval, 11u); RL(Aval); actL3trigger(watchdog);
   R0(Dval, Eval, Aval, Bval, Cval, 12u); RL(Eval); actL3trigger(watchdog);   R0(Cval, Dval, Eval, Aval, Bval, 13u); RL(Dval); actL3trigger(watchdog);   R0(Bval, Cval, Dval, Eval, Aval, 14u); RL(Cval); actL3trigger(watchdog);   R0(Aval, Bval, Cval, Dval, Eval, 15u); RL(Bval); actL3trigger(watchdog);
   R1(Eval, Aval, Bval, Cval, Dval, 16u); RL(Aval); actL3trigger(watchdog);   R1(Dval, Eval, Aval, Bval, Cval, 17u); RL(Eval); actL3trigger(watchdog);   R1(Cval, Dval, Eval, Aval, Bval, 18u); RL(Dval); actL3trigger(watchdog);   R1(Bval, Cval, Dval, Eval, Aval, 19u); RL(Cval);
   actL2trigger(watchdog);

   R2(Aval, Bval, Cval, Dval, Eval, 20u); RL(Bval); actL3trigger(watchdog);   R2(Eval, Aval, Bval, Cval, Dval, 21u); RL(Aval); actL3trigger(watchdog);   R2(Dval, Eval, Aval, Bval, Cval, 22u); RL(Eval); actL3trigger(watchdog);   R2(Cval, Dval, Eval, Aval, Bval, 23u); RL(Dval); actL3trigger(watchdog);
   R2(Bval, Cval, Dval, Eval, Aval, 24u); RL(Cval); actL3trigger(watchdog);   R2(Aval, Bval, Cval, Dval, Eval, 25u); RL(Bval); actL3trigger(watchdog);   R2(Eval, Aval, Bval, Cval, Dval, 26u); RL(Aval); actL3trigger(watchdog);   R2(Dval, Eval, Aval, Bval, Cval, 27u); RL(Eval); actL3trigger(watchdog);
   R2(Cval, Dval, Eval, Aval, Bval, 28u); RL(Dval); actL3trigger(watchdog);   R2(Bval, Cval, Dval, Eval, Aval, 29u); RL(Cval); actL3trigger(watchdog);   R2(Aval, Bval, Cval, Dval, Eval, 30u); RL(Bval); actL3trigger(watchdog);   R2(Eval, Aval, Bval, Cval, Dval, 31u); RL(Aval); actL3trigger(watchdog);
   R2(Dval, Eval, Aval, Bval, Cval, 32u); RL(Eval); actL3trigger(watchdog);   R2(Cval, Dval, Eval, Aval, Bval, 33u); RL(Dval); actL3trigger(watchdog);   R2(Bval, Cval, Dval, Eval, Aval, 34u); RL(Cval); actL3trigger(watchdog);   R2(Aval, Bval, Cval, Dval, Eval, 35u); RL(Bval); actL3trigger(watchdog);
   R2(Eval, Aval, Bval, Cval, Dval, 36u); RL(Aval); actL3trigger(watchdog);   R2(Dval, Eval, Aval, Bval, Cval, 37u); RL(Eval); actL3trigger(watchdog);   R2(Cval, Dval, Eval, Aval, Bval, 38u); RL(Dval); actL3trigger(watchdog);   R2(Bval, Cval, Dval, Eval, Aval, 39u); RL(Cval);
   actL2trigger(watchdog);

   R3(Aval, Bval, Cval, Dval, Eval, 40u); RL(Bval); actL3trigger(watchdog);   R3(Eval, Aval, Bval, Cval, Dval, 41u); RL(Aval); actL3trigger(watchdog);   R3(Dval, Eval, Aval, Bval, Cval, 42u); RL(Eval); actL3trigger(watchdog);   R3(Cval, Dval, Eval, Aval, Bval, 43u); RL(Dval); actL3trigger(watchdog);
   R3(Bval, Cval, Dval, Eval, Aval, 44u); RL(Cval); actL3trigger(watchdog);   R3(Aval, Bval, Cval, Dval, Eval, 45u); RL(Bval); actL3trigger(watchdog);   R3(Eval, Aval, Bval, Cval, Dval, 46u); RL(Aval); actL3trigger(watchdog);   R3(Dval, Eval, Aval, Bval, Cval, 47u); RL(Eval); actL3trigger(watchdog);
   R3(Cval, Dval, Eval, Aval, Bval, 48u); RL(Dval); actL3trigger(watchdog);   R3(Bval, Cval, Dval, Eval, Aval, 49u); RL(Cval); actL3trigger(watchdog);   R3(Aval, Bval, Cval, Dval, Eval, 50u); RL(Bval); actL3trigger(watchdog);   R3(Eval, Aval, Bval, Cval, Dval, 51u); RL(Aval); actL3trigger(watchdog);
   R3(Dval, Eval, Aval, Bval, Cval, 52u); RL(Eval); actL3trigger(watchdog);   R3(Cval, Dval, Eval, Aval, Bval, 53u); RL(Dval); actL3trigger(watchdog);   R3(Bval, Cval, Dval, Eval, Aval, 54u); RL(Cval); actL3trigger(watchdog);   R3(Aval, Bval, Cval, Dval, Eval, 55u); RL(Bval); actL3trigger(watchdog);
   R3(Eval, Aval, Bval, Cval, Dval, 56u); RL(Aval); actL3trigger(watchdog);   R3(Dval, Eval, Aval, Bval, Cval, 57u); RL(Eval); actL3trigger(watchdog);   R3(Cval, Dval, Eval, Aval, Bval, 58u); RL(Dval); actL3trigger(watchdog);   R3(Bval, Cval, Dval, Eval, Aval, 59u); RL(Cval);
   actL2trigger(watchdog);

   R4(Aval, Bval, Cval, Dval, Eval, 60u); RL(Bval); actL3trigger(watchdog);   R4(Eval, Aval, Bval, Cval, Dval, 61u); RL(Aval); actL3trigger(watchdog);   R4(Dval, Eval, Aval, Bval, Cval, 62u); RL(Eval); actL3trigger(watchdog);   R4(Cval, Dval, Eval, Aval, Bval, 63u); RL(Dval); actL3trigger(watchdog);
   R4(Bval, Cval, Dval, Eval, Aval, 64u); RL(Cval); actL3trigger(watchdog);   R4(Aval, Bval, Cval, Dval, Eval, 65u); RL(Bval); actL3trigger(watchdog);   R4(Eval, Aval, Bval, Cval, Dval, 66u); RL(Aval); actL3trigger(watchdog);   R4(Dval, Eval, Aval, Bval, Cval, 67u); RL(Eval); actL3trigger(watchdog);
   R4(Cval, Dval, Eval, Aval, Bval, 68u); RL(Dval); actL3trigger(watchdog);   R4(Bval, Cval, Dval, Eval, Aval, 69u); RL(Cval); actL3trigger(watchdog);   R4(Aval, Bval, Cval, Dval, Eval, 70u); RL(Bval); actL3trigger(watchdog);   R4(Eval, Aval, Bval, Cval, Dval, 71u); RL(Aval); actL3trigger(watchdog);
   R4(Dval, Eval, Aval, Bval, Cval, 72u); RL(Eval); actL3trigger(watchdog);   R4(Cval, Dval, Eval, Aval, Bval, 73u); RL(Dval); actL3trigger(watchdog);   R4(Bval, Cval, Dval, Eval, Aval, 74u); RL(Cval); actL3trigger(watchdog);   R4(Aval, Bval, Cval, Dval, Eval, 75u); RL(Bval); actL3trigger(watchdog);
   R4(Eval, Aval, Bval, Cval, Dval, 76u); RL(Aval); actL3trigger(watchdog);   R4(Dval, Eval, Aval, Bval, Cval, 77u); RL(Eval); actL3trigger(watchdog);   R4(Cval, Dval, Eval, Aval, Bval, 78u); RL(Dval); actL3trigger(watchdog);   R4(Bval, Cval, Dval, Eval, Aval, 79u); RL(Cval);
#else

  for(i = 0u; i < 16u; ++i){
    R0(Aval, Bval, Cval, Dval, Eval, i);
    t = Eval;
    Eval = Dval;
    Dval = Cval;
    Cval = actRotl30(Bval);
    Bval = Aval;
    Aval = t;
    actL3trigger(watchdog);
  }
  for(; i < 20u; ++i){
    R1(Aval, Bval, Cval, Dval, Eval, i);
    t = Eval;
    Eval = Dval;
    Dval = Cval;
    Cval = actRotl30(Bval);
    Bval = Aval;
    Aval = t;
    actL3trigger(watchdog);
  }
  actL2trigger(watchdog);

  for(; i < 40u; ++i){
    R2(Aval, Bval, Cval, Dval, Eval, i);
    t = Eval;
    Eval = Dval;
    Dval = Cval;
    Cval = actRotl30(Bval);
    Bval = Aval;
    Aval = t;
    actL3trigger(watchdog);
  }
  actL2trigger(watchdog);

  for(; i < 60u; ++i){
    R3(Aval, Bval, Cval, Dval, Eval, i);
    t = Eval;
    Eval = Dval;
    Dval = Cval;
    Cval = actRotl30(Bval);
    Bval = Aval;
    Aval = t;
    actL3trigger(watchdog);
  }
  actL2trigger(watchdog);

  for(; i < 80u; ++i){
    R4(Aval, Bval, Cval, Dval, Eval, i);
    t = Eval;
    Eval = Dval;
    Dval = Cval;
    Cval = actRotl30(Bval);
    Bval = Aval;
    Aval = t;
    actL3trigger(watchdog);
  }
#endif

  actL1trigger(watchdog);

  H[0] += Aval;
  H[1] += Bval;
  H[2] += Cval;
  H[3] += Dval;
  H[4] += Eval;
}

#if(!(actSHA_SPEED_UP > 2))

VSECPRIM_LOCAL_FUNC(actU32) blk1(VSECPRIM_P2CONST_PARA(actU32) W, actU32 i){
  actU32 t = W[(i + 13u) & 15u] ^ W[(i + 8u) & 15u] ^ W[(i + 2u) & 15u] ^ W[i & 15u];
  t = (t << 1) | (((t & 0x80000000uL) == 0x80000000uL) ? 1u : 0u);
  return t;
}
#endif

#if(actSHA_SPEED_UP == 0)

VSECPRIM_LOCAL_FUNC(actU32) actRotl5(actU32 x){
  actU8 t_hi5 = (actU8) actGetByte(x, 3u);
  t_hi5 >>= 3;
  return (x << 5) | (actU32) t_hi5;
}

VSECPRIM_LOCAL_FUNC(actU32) actRotl30(actU32 x){
  actU8 t_lo2 = (actU8) actGetByte(x, 0u);
  t_lo2 <<= 6u;
  return ((actU32) t_lo2 << 24u) | (x >> 2u);
}
#endif

VSECPRIM_FUNC(actRETURNCODE) actSHAInit(VSECPRIM_P2VAR_PARA(actSHASTRUCT) info){
  info->H[0] = 0x67452301UL;
  info->H[1] = 0xEFCDAB89UL;
  info->H[2] = 0x98BADCFEUL;
  info->H[3] = 0x10325476UL;
  info->H[4] = 0xC3D2E1F0UL;

  info->low_count = 0u;
  info->hi_count = 0u;
  info->buffer_used = 0u;

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actSHAUpdate(
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actU32) H = info->H;
  VSECPRIM_P2VAR_PARA(actU8) buffer = info->buffer;
  actLengthType diff = 0u;
  actRETURNCODE retVal = actOK;
  actLengthType lastBlockEnd;
  actLengthType bcount;
  actU8 finished = FALSE;

  actL1trigger(watchdog);

  if((info->low_count + (actU32) length) < info->low_count){
    info->hi_count++;
    if((info->hi_count) == ((actU32) 1u << 29)){
      retVal = actEXCEPTION_LENGTH;
    }
  }

  if(retVal == actOK){
    info->low_count += (actU32) length;

    if(info->buffer_used > 0u){
      diff = (actLengthType)actMin(length, (actHASH_BLOCK_SIZE_SHA - info->buffer_used));
      actMemCpyByteArray(&buffer[info->buffer_used], dataIN, diff);
      info->buffer_used += (actU16)(diff & 0xFFu);
      if(info->buffer_used < actHASH_BLOCK_SIZE_SHA)
      {
        retVal = actOK;
        finished = TRUE;
      }
      else
      {
        actSHATransform(buffer, H, watchdog);
      }
    }

    if(finished == FALSE){
      lastBlockEnd = (actLengthType)((length - diff) / actHASH_BLOCK_SIZE_SHA);
      lastBlockEnd = (lastBlockEnd*actHASH_BLOCK_SIZE_SHA) + diff;

      for(bcount = diff; bcount < lastBlockEnd; bcount += actHASH_BLOCK_SIZE_SHA)
      {
        actSHATransform(&dataIN[bcount], H, watchdog);
      }

      info->buffer_used = (actLengthType)(length - lastBlockEnd);
      actMemCpyByteArray(buffer, &dataIN[lastBlockEnd], (actLengthType)(info->buffer_used));

      actL1trigger(watchdog);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actSHAFinalize(
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actU8) tempBuffer = (VSECPRIM_P2VAR_PARA(actU8))info->buffer;
  VSECPRIM_P2VAR_PARA(actU32) digest = (VSECPRIM_P2VAR_PARA(actU32))info->H;
  actU32 low_bitcount = info->low_count << 3;
  actU32 hi_bitcount = (info->hi_count << 3) | (info->low_count >> 29);
  actLengthType len = info->low_count & 0x3Fu;
  actLengthType pad_len = (actLengthType)(actHASH_BLOCK_SIZE_SHA - (2u * actSHA_WORD_SIZE));

  actL1trigger(watchdog);

  tempBuffer[len] = 0x80u;
  len = len + 1u;

  actMemset(&tempBuffer[len], 0u, (actLengthType)(actHASH_BLOCK_SIZE_SHA - len));
  if(len > pad_len){
    actSHATransform((VSECPRIM_P2CONST_PARA(actU8))tempBuffer, digest, watchdog);
    actMemset(tempBuffer, 0u, (actLengthType)pad_len);
  }

  actU32toBE (&tempBuffer[pad_len],                   hi_bitcount);
  actU32toBE (&tempBuffer[pad_len+actSHA_WORD_SIZE], low_bitcount);

  actSHATransform((VSECPRIM_P2CONST_PARA(actU8))tempBuffer, digest, watchdog);

  actCpyU32toBE (hash, digest, actHASH_SIZE_SHA /actSHA_WORD_SIZE);

  actMemset(tempBuffer, 0u, actHASH_BLOCK_SIZE_SHA);

  actL1trigger(watchdog);

  return actOK;
}

VSECPRIM_FUNC(void) actSHAGetDigest(
  VSECPRIM_P2CONST_PARA(actSHASTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actCpyU32toBE(hash, info->H, actHASH_SIZE_SHA /actSHA_WORD_SIZE);

  actL3trigger(watchdog);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

