

#define ACTSHA2_32_SOURCE

#include "actISHA2_32.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"
#include "actConfig.hpp"

#if(VSECPRIM_ACTSHA2_32_ENABLED == STD_ON)

# define actSHA256_WORD_SIZE                                          (4u)

# define S0(x)                                                        (actRotr((x), 2u)^actRotr((x), 13u)^actRotr((x), 22u))
# define S1(x)                                                        (actRotr((x), 6u)^actRotr((x), 11u)^actRotr((x), 25u))
# define s0(x)                                                        (actRotr((x), 7u)^actRotr((x), 18u)^((x)>>3u))
# define s1(x)                                                        (actRotr((x), 17u)^actRotr((x), 19u)^((x)>>10u))

# define blk0(i)                                                      (W[(i)])
# define blk2(i)                                                      (W[(i)&15u]+=s1(W[((i)-2u)&15u])+W[((i)-7u)&15u]+s0(W[((i)-15u)&15u]))

# define Ch(x, y, z)                                                  ((z)^((x)&((y)^(z))))
# define Maj(x, y, z)                                                 (((x)&(y))|((z)&((x)|(y))))

# define a(i)                                                         (T[(0u-(i))&7u])
# define b(i)                                                         (T[(1u-(i))&7u])
# define c(i)                                                         (T[(2u-(i))&7u])
# define d(i)                                                         (T[(3u-(i))&7u])
# define e(i)                                                         (T[(4u-(i))&7u])
# define f(i)                                                         (T[(5u-(i))&7u])
# define g(i)                                                         (T[(6u-(i))&7u])
# define h(i)                                                         (T[(7u-(i))&7u])

# define Ra0(i, j)                                                    (h(i) += S1(e(i)) + Ch(e(i), f(i), g(i)) + ACT_ROM_R_DWD(actSHA2_32_K[(i) + (j)]) + blk0(i))
# define Ra2(i, j)                                                    blk2(i); \
                                                                      (h(i) = (h(i) + S1(e(i)) + Ch(e(i), f(i), g(i)) + ACT_ROM_R_DWD(actSHA2_32_K[(i) + (j)]) + W[(i)&15u])&0xFFFFFFFFu)
# define Rb(i)                                                        (d(i) += h(i))
# define Rc(i)                                                        (h(i) += S0(a(i)) + Maj(a(i), b(i), c(i)))

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) actSHA2_32_K[64] = {
  0x428a2f98uL, 0x71374491uL, 0xb5c0fbcfuL, 0xe9b5dba5uL, 0x3956c25buL, 0x59f111f1uL, 0x923f82a4uL, 0xab1c5ed5uL,
  0xd807aa98uL, 0x12835b01uL, 0x243185beuL, 0x550c7dc3uL, 0x72be5d74uL, 0x80deb1feuL, 0x9bdc06a7uL, 0xc19bf174uL,
  0xe49b69c1uL, 0xefbe4786uL, 0x0fc19dc6uL, 0x240ca1ccuL, 0x2de92c6fuL, 0x4a7484aauL, 0x5cb0a9dcuL, 0x76f988dauL,
  0x983e5152uL, 0xa831c66duL, 0xb00327c8uL, 0xbf597fc7uL, 0xc6e00bf3uL, 0xd5a79147uL, 0x06ca6351uL, 0x14292967uL,
  0x27b70a85uL, 0x2e1b2138uL, 0x4d2c6dfcuL, 0x53380d13uL, 0x650a7354uL, 0x766a0abbuL, 0x81c2c92euL, 0x92722c85uL,
  0xa2bfe8a1uL, 0xa81a664buL, 0xc24b8b70uL, 0xc76c51a3uL, 0xd192e819uL, 0xd6990624uL, 0xf40e3585uL, 0x106aa070uL,
  0x19a4c116uL, 0x1e376c08uL, 0x2748774cuL, 0x34b0bcb5uL, 0x391c0cb3uL, 0x4ed8aa4auL, 0x5b9cca4fuL, 0x682e6ff3uL,
  0x748f82eeuL, 0x78a5636fuL, 0x84c87814uL, 0x8cc70208uL, 0x90befffauL, 0xa4506cebuL, 0xbef9a3f7uL, 0xc67178f2uL
};

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actSHA2_32_Transform(
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU32) H,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_32_Update(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_32_Finalize(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actSHA2_32_Transform(
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU32) H,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU32 W[16];
  actU32 T[8];
  actU32 i, j;

  for (i = 0u; i < 8u; ++i){
    T[i] = H[i];
  }

  actCpyBEtoU32(W, in, actHASH_BLOCK_SIZE_SHA256);

  actL2trigger(watchdog);

  for (j = 0u; j < 64u; j += 16u){
# if(actSHA256_SPEED_UP > 0)

    if(j == 0u) {
      Ra0(0u, j); Rb(0u); Rc(0u); Ra0(1u, j); Rb(1u); Rc(1u);
      Ra0(2u, j); Rb(2u); Rc(2u); Ra0(3u, j); Rb(3u); Rc(3u);
      Ra0(4u, j); Rb(4u); Rc(4u); Ra0(5u, j); Rb(5u); Rc(5u);
      Ra0(6u, j); Rb(6u); Rc(6u); Ra0(7u, j); Rb(7u); Rc(7u);
      Ra0(8u, j); Rb(8u); Rc(8u); Ra0(9u, j); Rb(9u); Rc(9u);
      Ra0(10u, j); Rb(10u); Rc(10u); Ra0(11u, j); Rb(11u); Rc(11u);
      Ra0(12u, j); Rb(12u); Rc(12u); Ra0(13u, j); Rb(13u); Rc(13u);
      Ra0(14u, j); Rb(14u); Rc(14u); Ra0(15u, j); Rb(15u); Rc(15u);
      actL3trigger(watchdog);
    }
    else{
      Ra2(0u, j); Rb(0u); Rc(0u); Ra2(1u, j); Rb(1u); Rc(1u);
      Ra2(2u, j); Rb(2u); Rc(2u); Ra2(3u, j); Rb(3u); Rc(3u);
      Ra2(4u, j); Rb(4u); Rc(4u); Ra2(5u, j); Rb(5u); Rc(5u);
      Ra2(6u, j); Rb(6u); Rc(6u); Ra2(7u, j); Rb(7u); Rc(7u);
      Ra2(8u, j); Rb(8u); Rc(8u); Ra2(9u, j); Rb(9u); Rc(9u);
      Ra2(10u, j); Rb(10u); Rc(10u); Ra2(11u, j); Rb(11u); Rc(11u);
      Ra2(12u, j); Rb(12u); Rc(12u); Ra2(13u, j); Rb(13u); Rc(13u);
      Ra2(14u, j); Rb(14u); Rc(14u); Ra2(15u, j); Rb(15u); Rc(15u);
      actL3trigger(watchdog);
    }
# else
    if(j == 0u) {
      for (i = 0u; i < 16u; ++i)
      {
        Ra0(i, j);
        Rb(i);
        Rc(i);

        actL3trigger(watchdog);
      }
    }
    else{
      for (i = 0u; i < 16u; ++i)
      {
        Ra2(i, j);
        Rb(i);
        Rc(i);

        actL3trigger(watchdog);
      }
    }
# endif
    actL2trigger(watchdog);
  }

  actL1trigger(watchdog);

  for (i = 0u; i < 8u; ++i){
    H[i] += T[i];
  }
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_32_Update(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actU32) Hptr = info->H;
  VSECPRIM_P2VAR_PARA(actU8) bufferPtr = info->buffer;
  actLengthType diff = 0u;
  actRETURNCODE retVal = actOK;
  actLengthType lastBlockEnd;
  actLengthType bcount;
  actU8 finished = FALSE;

  actL1trigger(watchdog);

  if((info->low_count + (actU32)length) < info->low_count){
    info->hi_count++;
    if((info->hi_count) == ((actU32)1u << 29)){
      retVal = actEXCEPTION_LENGTH;
    }
  }

  if(retVal == actOK){
    info->low_count += (actU32)length;

    if(info->buffer_used > 0u){
      diff = (actLengthType)actMin(length, (actHASH_BLOCK_SIZE_SHA256 - info->buffer_used));
      actMemCpyByteArray(&bufferPtr[info->buffer_used], dataIN, diff);
      info->buffer_used += (actU16)(diff & 0xFFu);
      if(info->buffer_used < actHASH_BLOCK_SIZE_SHA256)
      {
        retVal = actOK;
        finished = TRUE;
      }
      else
      {
        actSHA2_32_Transform(bufferPtr, Hptr, watchdog);
      }
    }

    if(finished == FALSE){
      lastBlockEnd = (actLengthType)((length - diff) / actHASH_BLOCK_SIZE_SHA256);
      lastBlockEnd = (lastBlockEnd*actHASH_BLOCK_SIZE_SHA256) + diff;

      for (bcount = diff; bcount < lastBlockEnd; bcount += actHASH_BLOCK_SIZE_SHA256)
      {
        actSHA2_32_Transform(&dataIN[bcount], Hptr, watchdog);
      }

      info->buffer_used = (actLengthType)(length - lastBlockEnd);
      actMemCpyByteArray(bufferPtr, &dataIN[lastBlockEnd], info->buffer_used);

      actL1trigger(watchdog);
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_32_Finalize(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actU8) tempBuffer = (VSECPRIM_P2VAR_PARA(actU8))info->buffer;
  VSECPRIM_P2VAR_PARA(actU32) digest = (VSECPRIM_P2VAR_PARA(actU32))info->H;
  actU32 low_bitcount = info->low_count << 3;
  actU32 hi_bitcount = (info->hi_count << 3) | (info->low_count >> 29);
  actLengthType len = info->low_count & 0x3Fu;
  actLengthType pad_len = (actLengthType)(actHASH_BLOCK_SIZE_SHA256 - (2u * actSHA256_WORD_SIZE));

  actL1trigger(watchdog);

  tempBuffer[len] = 0x80u;
  len = len + 1u;

  actMemset(&tempBuffer[len], 0u, (actLengthType)(actHASH_BLOCK_SIZE_SHA256 - len));
  if(len > pad_len){
    actSHA2_32_Transform((VSECPRIM_P2CONST_PARA(actU8))tempBuffer, digest, watchdog);
    actMemset(tempBuffer, 0u, (actLengthType)pad_len);
  }

  actU32toBE(&tempBuffer[pad_len],                      hi_bitcount);
  actU32toBE(&tempBuffer[pad_len+actSHA256_WORD_SIZE], low_bitcount);

  actSHA2_32_Transform((VSECPRIM_P2CONST_PARA(actU8))tempBuffer, digest, watchdog);

  actCpyU32toBE(hash, digest, (actU32)info->result_length / actSHA256_WORD_SIZE);

  actMemset((VSECPRIM_P2VAR_PARA(actU8))&info->buffer[0], 0u, actHASH_BLOCK_SIZE_SHA256);

  actL1trigger(watchdog);

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actSHA224Init(VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info){
  info->H[0] = 0xc1059ed8UL;
  info->H[1] = 0x367cd507UL;
  info->H[2] = 0x3070dd17UL;
  info->H[3] = 0xf70e5939UL;
  info->H[4] = 0xffc00b31UL;
  info->H[5] = 0x68581511UL;
  info->H[6] = 0x64f98fa7UL;
  info->H[7] = 0xbefa4fa4UL;

  info->low_count = 0u;
  info->hi_count = 0u;
  info->buffer_used = 0u;
  info->result_length = actHASH_SIZE_SHA224;

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actSHA224Update(
  VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHA2_32_Update((VSECPRIM_P2VAR_PARA(actSHA256STRUCT))info, dataIN, length, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA224Finalize(
  VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHA2_32_Finalize((VSECPRIM_P2VAR_PARA(actSHA256STRUCT)) info, hash, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA256Init(VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info){
  info->H[0] = 0x6a09e667UL;
  info->H[1] = 0xbb67ae85UL;
  info->H[2] = 0x3c6ef372UL;
  info->H[3] = 0xa54ff53aUL;
  info->H[4] = 0x510e527fUL;
  info->H[5] = 0x9b05688cUL;
  info->H[6] = 0x1f83d9abUL;
  info->H[7] = 0x5be0cd19UL;

  info->low_count = 0u;
  info->hi_count = 0u;
  info->buffer_used = 0u;
  info->result_length = actHASH_SIZE_SHA256;

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actSHA256Update(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHA2_32_Update((VSECPRIM_P2VAR_PARA(actSHA256STRUCT)) info, dataIN, length, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA256Finalize(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHA2_32_Finalize((VSECPRIM_P2VAR_PARA(actSHA256STRUCT)) info, hash, watchdog);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

