

#ifndef ACTKECCAKF32_H
# define ACTKECCAKF32_H

# include "actITypes.hpp"
# include "actUtilities.hpp"

# define KECCAK_ROUNDS                                                (24u)
# define SLICE_LENGTH_UINT32                                          (10u)
# define WORD_NUMBER_64BITWORD_UINT32                                 (2u)

# define VSECPRIM_START_SEC_CONST_32BIT
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) RC[] =
{
  0x00000001uL, 0x00000000uL, 0x00008082uL, 0x00000000uL, 0x0000808AuL, 0x80000000uL, 0x80008000uL, 0x80000000uL,
  0x0000808BuL, 0x00000000uL, 0x80000001uL, 0x00000000uL, 0x80008081uL, 0x80000000uL, 0x00008009uL, 0x80000000uL,
  0x0000008AuL, 0x00000000uL, 0x00000088uL, 0x00000000uL, 0x80008009uL, 0x00000000uL, 0x8000000AuL, 0x00000000uL,
  0x8000808BuL, 0x00000000uL, 0x0000008BuL, 0x80000000uL, 0x00008089uL, 0x80000000uL, 0x00008003uL, 0x80000000uL,
  0x00008002uL, 0x80000000uL, 0x00000080uL, 0x80000000uL, 0x0000800AuL, 0x00000000uL, 0x8000000AuL, 0x80000000uL,
  0x80008081uL, 0x80000000uL, 0x00008080uL, 0x80000000uL, 0x80000001uL, 0x00000000uL, 0x80008008uL, 0x80000000uL
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) pi_lane[] =
{
      0u,
      6u,
     12u,
     18u,
     24u,
      3u,
      9u,
     10u,
     16u,
     22u,
      1u,
      7u,
     13u,
     19u,
     20u,
      4u,
      5u,
     11u,
     17u,
     23u,
      2u,
      8u,
     14u,
     15u,
     21u
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) rho_offset[] =
{
       0u,
       1u,
      62u,
      28u,
      27u,
      36u,
      44u,
       6u,
      55u,
      20u,
       3u,
      10u,
      43u,
      25u,
      39u,
      41u,
      45u,
      15u,
      21u,
       8u,
      18u,
       2u,
      61u,
      56u,
      14u
};

# define VSECPRIM_STOP_SEC_CONST_32BIT
# include "CompilerCfg_vSecPrim.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actKECCAKcAbsorbData(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) data);

VSECPRIM_LOCAL_FUNC(void) actKECCAKcSqueezeData(
  VSECPRIM_P2CONST_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) data);

VSECPRIM_LOCAL_FUNC(void) actKECCAKRotL64(
  VSECPRIM_P2VAR_PARA(actU32) tgt,
  VSECPRIM_P2CONST_PARA(actU32) x,
  const actU32 n);

VSECPRIM_LOCAL_FUNC(void) actKECCAKCpy64(
  VSECPRIM_P2VAR_PARA(actU32) tgt,
  VSECPRIM_P2CONST_PARA(actU32) src);

VSECPRIM_LOCAL_FUNC(void) actKECCAKNot64(
  VSECPRIM_P2VAR_PARA(actU32) tgt,
  VSECPRIM_P2CONST_PARA(actU32) val);

VSECPRIM_LOCAL_FUNC(void) actKECCAKAnd64(
  VSECPRIM_P2VAR_PARA(actU32) tgt,
  VSECPRIM_P2CONST_PARA(actU32) val);

VSECPRIM_LOCAL_FUNC(void) actKECCAKXor64(
  VSECPRIM_P2VAR_PARA(actU32) tgt,
  VSECPRIM_P2CONST_PARA(actU32) val);

VSECPRIM_LOCAL_FUNC(void) actKECCAKfPermutationRhoPi(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU32) lane10);

VSECPRIM_LOCAL_FUNC(void) actKECCAKcAbsorbData(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) data){
  info->state[(info->rUsed * 2u)] ^= actLEtoU32(&((data)[0]));
  info->state[(info->rUsed * 2u) + 1u] ^= actLEtoU32(&((data)[4]));
}

VSECPRIM_LOCAL_FUNC(void) actKECCAKcSqueezeData(
  VSECPRIM_P2CONST_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) data){
  actU32toLE(&((data)[0]), info->state[info->rUsed * 2u]);
  actU32toLE(&((data)[4]), info->state[(info->rUsed * 2u) + 1u]);
}

VSECPRIM_LOCAL_FUNC(void) actKECCAKRotL64(
  VSECPRIM_P2VAR_PARA(actU32) tgt,
  VSECPRIM_P2CONST_PARA(actU32) x,
  const actU32 n){
  if(n <= 32u){
    (tgt)[0] = (((x)[0] << (n)) | ((x)[1] >> (32u - (n))));
    (tgt)[1] = (((x)[1] << (n)) | ((x)[0] >> (32u - (n))));
  }
  else{
    (tgt)[1] = (((x)[0] << (n - 32u)) | ((x)[1] >> (32u - (n - 32u))));
    (tgt)[0] = (((x)[1] << (n - 32u)) | ((x)[0] >> (32u - (n - 32u))));
  }
}

VSECPRIM_LOCAL_FUNC(void) actKECCAKCpy64(
  VSECPRIM_P2VAR_PARA(actU32) tgt,
  VSECPRIM_P2CONST_PARA(actU32) src){
  (tgt)[0] = (src)[0];
  (tgt)[1] = (src)[1];
}

VSECPRIM_LOCAL_FUNC(void) actKECCAKNot64(
  VSECPRIM_P2VAR_PARA(actU32) tgt,
  VSECPRIM_P2CONST_PARA(actU32) val){
  (tgt)[0] = ~(val)[0];
  (tgt)[1] = ~(val)[1];
}

VSECPRIM_LOCAL_FUNC(void) actKECCAKAnd64(
  VSECPRIM_P2VAR_PARA(actU32) tgt,
  VSECPRIM_P2CONST_PARA(actU32) val){
  (tgt)[0] &= (val)[0];
  (tgt)[1] &= (val)[1];
}

VSECPRIM_LOCAL_FUNC(void) actKECCAKXor64(
  VSECPRIM_P2VAR_PARA(actU32) tgt,
  VSECPRIM_P2CONST_PARA(actU32) val){
  (tgt)[0] ^= (val)[0];
  (tgt)[1] ^= (val)[1];
}

VSECPRIM_LOCAL_FUNC(void) actKECCAKfPermutationRhoPi(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU32) lane10){
  actU32 dst, src;

  actKECCAKRotL64(lane10, &(info->state[2]), rho_offset[1]);

  dst = 1u;
  src = pi_lane[1];
  while (src != 1u){
    if(rho_offset[src] <= 32u){
      actKECCAKRotL64(&(info->state[dst * 2u]), &(info->state[src * 2u]), rho_offset[src]);
    }
    else{
      actKECCAKRotL64(&(info->state[dst * 2u]), &(info->state[src * 2u]), rho_offset[src]);
    }

    dst = src;
    src = pi_lane[dst];
  }

  actKECCAKCpy64(&(info->state[dst * 2u]), lane10);
}

VSECPRIM_LOCAL_FUNC(void) KECCAKf(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) KECCAKf(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU32 x, y, r;
  actU32 Dx[WORD_NUMBER_64BITWORD_UINT32], C[SLICE_LENGTH_UINT32];

  actL1trigger (watchdog);

  for (r = 0u; r < KECCAK_ROUNDS; r++){
      for (x = 0u; x <= 8u; x += WORD_NUMBER_64BITWORD_UINT32)
      {
        actKECCAKCpy64 (&(C [x]), &(info->state [x]));

        actKECCAKXor64(&(C [x]), &(info->state [x + (1u *SLICE_LENGTH_UINT32)]));

        actKECCAKXor64(&(C [x]), &(info->state [x + (2u *SLICE_LENGTH_UINT32)]));

        actKECCAKXor64(&(C [x]), &(info->state [x + (3u *SLICE_LENGTH_UINT32)]));

        actKECCAKXor64(&(C [x]), &(info->state [x + (4u *SLICE_LENGTH_UINT32)]));
      }

      for (x = 0u; x <= 8u; x += WORD_NUMBER_64BITWORD_UINT32)
      {
        actKECCAKRotL64 (Dx, &(C [(x + 2u) % SLICE_LENGTH_UINT32]), 1u);
        actKECCAKXor64(Dx, &(C [(x + 8u) % SLICE_LENGTH_UINT32]));

        for (y = 0u; y <= (4u * SLICE_LENGTH_UINT32); y += SLICE_LENGTH_UINT32)
        {
          actKECCAKXor64(&(info->state[y + x]), Dx);
        }
      }

      actKECCAKfPermutationRhoPi(info, Dx);

      for (y = 0u; y <= (4u *SLICE_LENGTH_UINT32); y += SLICE_LENGTH_UINT32)
      {
        for (x = 0u; x <= 8u; x += WORD_NUMBER_64BITWORD_UINT32)
        {
          actKECCAKCpy64(&(C[x]), &(info->state[y + x]));
        }

        for (x = 0u; x <= 8u; x += WORD_NUMBER_64BITWORD_UINT32)
        {
          actKECCAKNot64 (Dx, &(C [(x + 2u) % SLICE_LENGTH_UINT32]));
          actKECCAKAnd64 (Dx, &(C [(x + 4u) % SLICE_LENGTH_UINT32]));
          actKECCAKXor64(&(info->state [y + x]), Dx);
        }

      }

      actKECCAKXor64(&(info->state [0]), &(RC [r * 2u]));

      actL2trigger (watchdog);
  }

  actL1trigger (watchdog);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

