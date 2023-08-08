

#define ACTGHASH_SOURCE

#include "actConfig.hpp"
#include "actIGHash.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTGHASH_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

# if(actGHASH_SPEED_UP == 0)

# elif(actGHASH_SPEED_UP < 4)

VSECPRIM_ROM(VSECPRIM_LOCAL, actU16) R[16] = {
      0x0000, 0x1c20, 0x3840, 0x2460, 0x7080, 0x6ca0, 0x48c0, 0x54e0,
      0xe100, 0xfd20, 0xd940, 0xc560, 0x9180, 0x8da0, 0xa9c0, 0xb5e0
};

# else

VSECPRIM_ROM(VSECPRIM_LOCAL, actU16) R[256] =
{
      0x0000, 0x01c2, 0x0384, 0x0246, 0x0708, 0x06ca, 0x048c, 0x054e,
      0x0e10, 0x0fd2, 0x0d94, 0x0c56, 0x0918, 0x08da, 0x0a9c, 0x0b5e,
      0x1c20, 0x1de2, 0x1fa4, 0x1e66, 0x1b28, 0x1aea, 0x18ac, 0x196e,
      0x1230, 0x13f2, 0x11b4, 0x1076, 0x1538, 0x14fa, 0x16bc, 0x177e,
      0x3840, 0x3982, 0x3bc4, 0x3a06, 0x3f48, 0x3e8a, 0x3ccc, 0x3d0e,
      0x3650, 0x3792, 0x35d4, 0x3416, 0x3158, 0x309a, 0x32dc, 0x331e,
      0x2460, 0x25a2, 0x27e4, 0x2626, 0x2368, 0x22aa, 0x20ec, 0x212e,
      0x2a70, 0x2bb2, 0x29f4, 0x2836, 0x2d78, 0x2cba, 0x2efc, 0x2f3e,
      0x7080, 0x7142, 0x7304, 0x72c6, 0x7788, 0x764a, 0x740c, 0x75ce,
      0x7e90, 0x7f52, 0x7d14, 0x7cd6, 0x7998, 0x785a, 0x7a1c, 0x7bde,
      0x6ca0, 0x6d62, 0x6f24, 0x6ee6, 0x6ba8, 0x6a6a, 0x682c, 0x69ee,
      0x62b0, 0x6372, 0x6134, 0x60f6, 0x65b8, 0x647a, 0x663c, 0x67fe,
      0x48c0, 0x4902, 0x4b44, 0x4a86, 0x4fc8, 0x4e0a, 0x4c4c, 0x4d8e,
      0x46d0, 0x4712, 0x4554, 0x4496, 0x41d8, 0x401a, 0x425c, 0x439e,
      0x54e0, 0x5522, 0x5764, 0x56a6, 0x53e8, 0x522a, 0x506c, 0x51ae,
      0x5af0, 0x5b32, 0x5974, 0x58b6, 0x5df8, 0x5c3a, 0x5e7c, 0x5fbe,
      0xe100, 0xe0c2, 0xe284, 0xe346, 0xe608, 0xe7ca, 0xe58c, 0xe44e,
      0xef10, 0xeed2, 0xec94, 0xed56, 0xe818, 0xe9da, 0xeb9c, 0xea5e,
      0xfd20, 0xfce2, 0xfea4, 0xff66, 0xfa28, 0xfbea, 0xf9ac, 0xf86e,
      0xf330, 0xf2f2, 0xf0b4, 0xf176, 0xf438, 0xf5fa, 0xf7bc, 0xf67e,
      0xd940, 0xd882, 0xdac4, 0xdb06, 0xde48, 0xdf8a, 0xddcc, 0xdc0e,
      0xd750, 0xd692, 0xd4d4, 0xd516, 0xd058, 0xd19a, 0xd3dc, 0xd21e,
      0xc560, 0xc4a2, 0xc6e4, 0xc726, 0xc268, 0xc3aa, 0xc1ec, 0xc02e,
      0xcb70, 0xcab2, 0xc8f4, 0xc936, 0xcc78, 0xcdba, 0xcffc, 0xce3e,
      0x9180, 0x9042, 0x9204, 0x93c6, 0x9688, 0x974a, 0x950c, 0x94ce,
      0x9f90, 0x9e52, 0x9c14, 0x9dd6, 0x9898, 0x995a, 0x9b1c, 0x9ade,
      0x8da0, 0x8c62, 0x8e24, 0x8fe6, 0x8aa8, 0x8b6a, 0x892c, 0x88ee,
      0x83b0, 0x8272, 0x8034, 0x81f6, 0x84b8, 0x857a, 0x873c, 0x86fe,
      0xa9c0, 0xa802, 0xaa44, 0xab86, 0xaec8, 0xaf0a, 0xad4c, 0xac8e,
      0xa7d0, 0xa612, 0xa454, 0xa596, 0xa0d8, 0xa11a, 0xa35c, 0xa29e,
      0xb5e0, 0xb422, 0xb664, 0xb7a6, 0xb2e8, 0xb32a, 0xb16c, 0xb0ae,
      0xbbf0, 0xba32, 0xb874, 0xb9b6, 0xbcf8, 0xbd3a, 0xbf7c, 0xbebe
};

# endif

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) gf128_zero(VSECPRIM_P2VAR_PARA(actU32) Z);

VSECPRIM_LOCAL_FUNC(void) gf128_add(
  VSECPRIM_P2VAR_PARA(actU32) Z,
  VSECPRIM_P2CONST_PARA(actU32) X,
  VSECPRIM_P2CONST_PARA(actU32) Y);

VSECPRIM_LOCAL_FUNC(void) gf128_double(
  VSECPRIM_P2VAR_PARA(actU32) Z,
  VSECPRIM_P2CONST_PARA(actU32) X);

# if(actGHASH_SPEED_UP == 0)

VSECPRIM_LOCAL_FUNC(void) actGF128Mul(
  VSECPRIM_P2CONST_PARA(actGHASHSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU32) Z,
  VSECPRIM_P2CONST_PARA(actU8) X);

# elif(actGHASH_SPEED_UP < 4)

VSECPRIM_LOCAL_FUNC(actU8) gf128_rightshift_4(VSECPRIM_P2VAR_PARA(actU32) block);

VSECPRIM_LOCAL_FUNC(void) actGF128Mul(
  VSECPRIM_P2CONST_PARA(actGHASHSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU32) Z,
  VSECPRIM_P2CONST_PARA(actU8) X);

# else

VSECPRIM_LOCAL_FUNC(actU8) gf128_rightshift_8(VSECPRIM_P2VAR_PARA(actU32) block);

VSECPRIM_LOCAL_FUNC(void) actGF128Mul(
  VSECPRIM_P2CONST_PARA(actGHASHSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU32) Z,
  VSECPRIM_P2CONST_PARA(actU8) X);

# endif

VSECPRIM_LOCAL_FUNC(void) actGHashTransformBlock(
  VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) X);

VSECPRIM_LOCAL_FUNC(void) gf128_zero(VSECPRIM_P2VAR_PARA(actU32) Z){
  Z[3] = 0;
  Z[2] = 0;
  Z[1] = 0;
  Z[0] = 0;
}

VSECPRIM_LOCAL_FUNC(void) gf128_add (
   VSECPRIM_P2VAR_PARA(actU32) Z,
   VSECPRIM_P2CONST_PARA(actU32) X,
   VSECPRIM_P2CONST_PARA(actU32) Y){
  Z[3] = X[3] ^ Y[3];
  Z[2] = X[2] ^ Y[2];
  Z[1] = X[1] ^ Y[1];
  Z[0] = X[0] ^ Y[0];
}

VSECPRIM_LOCAL_FUNC(void) gf128_double (
   VSECPRIM_P2VAR_PARA(actU32) Z,
   VSECPRIM_P2CONST_PARA(actU32) X){
  actU8 carry = (actU8)(X[3] & 1uL);

  Z[3] = (X[3] >> 1) | ((X[2] & 1uL) << 31);
  Z[2] = (X[2] >> 1) | ((X[1] & 1uL) << 31);
  Z[1] = (X[1] >> 1) | ((X[0] & 1uL) << 31);
  Z[0] = (X[0] >> 1);
  if(carry > 0u){
    Z[0] ^= GF128POLY;
  }
}

# if(actGHASH_SPEED_UP == 0)

VSECPRIM_LOCAL_FUNC(void) actGF128Mul (
   VSECPRIM_P2CONST_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2VAR_PARA(actU32) Z,
   VSECPRIM_P2CONST_PARA(actU8) X){
   actU32 H [actGHASH_WORDS_PER_BLOCK];
   actU8 i;
   actU8 j;
   actU8 X_i;

   gf128_zero (Z);

   gf128_add  (H, Z, info->H);

   for (i = 0; i < actGHASH_BLOCK_SIZE; i++){
      X_i = X [i];
      j = actGCM_BYTE_SIZE;

      do
      {
         j--;
         if((X_i & 0x80u) == 0x80u)
         {
            gf128_add(Z, Z, H);
         }
         X_i <<= 1;

         gf128_double(H, H);
      } while (j > 0u);
   }
}

# elif(actGHASH_SPEED_UP < 4)

VSECPRIM_LOCAL_FUNC(actU8) gf128_rightshift_4(VSECPRIM_P2VAR_PARA(actU32) block){
  actU8 v = (actU8)(block[actGHASH_WORDS_PER_BLOCK - 1u] & 0xFu);

   block[3] = (block[3] >> 4) | ((block[2] & 0xFuL) << 28);
   block[2] = (block[2] >> 4) | ((block[1] & 0xFuL) << 28);
   block[1] = (block[1] >> 4) | ((block[0] & 0xFuL) << 28);
   block[0] >>= 4;

   return v;
}

VSECPRIM_LOCAL_FUNC(void) actGF128Mul (
  VSECPRIM_P2CONST_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2VAR_PARA(actU32) Z,
   VSECPRIM_P2CONST_PARA(actU8) X){
  actU8 i;
  actU8 X_i, A;

  gf128_zero (Z);

  i = actGHASH_BLOCK_SIZE;
  do
  {
    i--;
    X_i = X[i];

    A = gf128_rightshift_4 (Z);

    Z [0] ^= (((actU32) R [A]) << 16);

    gf128_add (Z, Z, info->M [X_i & 0xfu]);

    A = gf128_rightshift_4 (Z);

    Z [0] ^= (((actU32) R [A]) << 16);

    gf128_add (Z, Z, info->M [X_i >> 4]);
  } while (i > 0u);
}

# else

VSECPRIM_LOCAL_FUNC(actU8) gf128_rightshift_8(VSECPRIM_P2VAR_PARA(actU32) block){
  actU8 v = (actU8)(block[actGHASH_WORDS_PER_BLOCK - 1u] & 0xffu);

  block[3] = (block[3] >> 8) | ((block[2] & 0xffu) << 24);
  block[2] = (block[2] >> 8) | ((block[1] & 0xffu) << 24);
  block[1] = (block[1] >> 8) | ((block[0] & 0xffu) << 24);
  block[0] >>= 8;

  return v;
}

VSECPRIM_LOCAL_FUNC(void) actGF128Mul (
  VSECPRIM_P2CONST_PARA(actGHASHSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU32) Z,
  VSECPRIM_P2CONST_PARA(actU8) X){
  actU8 i, A;

  gf128_zero(Z);

  i = actGHASH_BLOCK_SIZE;

  do
  {
    i--;

    A = gf128_rightshift_8(Z);

    Z[0] ^= (((actU32)R[A]) << 16);

    gf128_add(Z, Z, info->M[X[i]]);
  } while (i > 0u);
}

# endif

VSECPRIM_LOCAL_FUNC(void) actGHashTransformBlock (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) X){
  actU32 tmpY[actGHASH_WORDS_PER_BLOCK];

  actXOR(info->Y, X, actGHASH_BLOCK_SIZE);

  actGF128Mul(info, tmpY, info->Y);

  actCpyU32toBE (info->Y, tmpY, actGHASH_WORDS_PER_BLOCK);
}

VSECPRIM_FUNC(actRETURNCODE) actGHashReset(VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info){
  actMemset(info->Y, 0, actGHASH_BLOCK_SIZE);

  info->buffer_used = 0;

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actGHashInit (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) H,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
# if(actGHASH_SPEED_UP > 0)
  actU16 i, j;
# endif

   actCpyBEtoU32 (info->H, H, actGHASH_BLOCK_SIZE);

# if(actGHASH_SPEED_UP == 0)

# elif(actGHASH_SPEED_UP < 4)

   gf128_zero    (info->M [0]);
   actCpyBEtoU32 (info->M [8], H, actGHASH_BLOCK_SIZE);

   for (i = 4u; i > 0u; i /= 2u){
      gf128_double(info->M[i], info->M[2u * i]);
   }

   for (i = 2u; i <= 8u; i *= 2u){
      for (j = 1u; j < i; j++)
      {
         gf128_add(info->M[i+j], info->M[i], info->M[j]);
      }
   }

# else

   gf128_zero    (info->M [0]);
   actCpyBEtoU32 (info->M [128], H, actGHASH_BLOCK_SIZE);

   for (i = 64; i > 0u; i /= 2u){
      gf128_double(info->M[i], info->M[2u * i]);
   }

   for (i = 2; i <= 128u; i *= 2u){
      for (j = 1; j < i; j++)
      {
         gf128_add(info->M[i+j], info->M[i], info->M[j]);
      }
   }

# endif

  actL1trigger(watchdog);
  return actGHashReset(info);
}

VSECPRIM_FUNC(actRETURNCODE) actGHashUpdate (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) X,
   actLengthType X_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType diff = 0;
  boolean isUpdateFinished = FALSE;

  actL1trigger(watchdog);

  if(info->buffer_used > 0u){
    diff = actMin(X_len, (actLengthType)(actGHASH_BLOCK_SIZE - info->buffer_used));
    actMemCpyByteArray(&info->buffer[info->buffer_used], X, diff);
    info->buffer_used += diff;
    if(info->buffer_used < actGHASH_BLOCK_SIZE){
      isUpdateFinished = TRUE;
    }
    else{
      actGHashTransformBlock(info, info->buffer);
      actL2trigger(watchdog);
    }
  }

  if(isUpdateFinished == FALSE){
    actLengthType i, blocks, X_idx;

    blocks = (X_len - diff) / actGHASH_BLOCK_SIZE;
    X_idx = diff;

    for (i = blocks; i > 0u; --i){
      actGHashTransformBlock(info, &X[X_idx]);
      X_idx += actGHASH_BLOCK_SIZE;
      actL2trigger(watchdog);
    }

    info->buffer_used = X_len - (diff + (actGHASH_BLOCK_SIZE * blocks));
    actMemCpyByteArray(info->buffer, &X[X_idx], info->buffer_used);

    actL1trigger(watchdog);
  }

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actGHashZeroPad (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  if(info->buffer_used > 0u){
    actMemset(&info->buffer[info->buffer_used], 0, actGHASH_BLOCK_SIZE - info->buffer_used);

    actGHashTransformBlock(info, info->buffer);

    info->buffer_used = 0;
  }

  actL1trigger(watchdog);
  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actGHashFinalize (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   actU8 hash[actGHASH_BLOCK_SIZE],
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  if(info->buffer_used > 0u){
    (void)actGHashZeroPad(info, watchdog);
  }

  actMemCpyByteArray(hash, info->Y, actGHASH_BLOCK_SIZE);

  actL1trigger(watchdog);
  return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

