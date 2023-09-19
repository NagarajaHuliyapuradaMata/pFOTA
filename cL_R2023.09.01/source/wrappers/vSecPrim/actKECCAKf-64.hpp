

#ifndef ACTKECCAKF64_H
#define ACTKECCAKF64_H

#include "actITypes.hpp"
#include "actUtilities.hpp"

#define KECCAK_ROUNDS                                                (24u)
#define SLICE_LENGTH                                                 (5u)

#define VSECPRIM_START_SEC_CONST_64BIT
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, actU64) RC[] =
{
  0x0000000000000001ULL, 0x0000000000008082ULL, 0x800000000000808AULL, 0x8000000080008000ULL
   ,  0x000000000000808BULL, 0x0000000080000001ULL, 0x8000000080008081ULL, 0x8000000000008009ULL
   ,  0x000000000000008AULL, 0x0000000000000088ULL, 0x0000000080008009ULL, 0x000000008000000AULL
   ,  0x000000008000808BULL, 0x800000000000008BULL, 0x8000000000008089ULL, 0x8000000000008003ULL
   ,  0x8000000000008002ULL, 0x8000000000000080ULL, 0x000000000000800AULL, 0x800000008000000AULL
   ,  0x8000000080008081ULL, 0x8000000000008080ULL, 0x0000000080000001ULL, 0x8000000080008008ULL
};

#define VSECPRIM_STOP_SEC_CONST_64BIT
#include "CompilerCfg_vSecPrim.hpp"

#define VSECPRIM_START_SEC_CONST_32BIT
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) pi_lane[] =
{
      0u
   ,     6u
   ,    12u
   ,    18u
   ,    24u
   ,     3u
   ,     9u
   ,    10u
   ,    16u
   ,    22u
   ,     1u
   ,     7u
   ,    13u
   ,    19u
   ,    20u
   ,     4u
   ,     5u
   ,    11u
   ,    17u
   ,    23u
   ,     2u
   ,     8u
   ,    14u
   ,    15u
   ,    21u
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) rho_offset[] =
{
       0u
   ,      1u
   ,     62u
   ,     28u
   ,     27u
   ,     36u
   ,     44u
   ,      6u
   ,     55u
   ,     20u
   ,      3u
   ,     10u
   ,     43u
   ,     25u
   ,     39u
   ,     41u
   ,     45u
   ,     15u
   ,     21u
   ,      8u
   ,     18u
   ,      2u
   ,     61u
   ,     56u
   ,     14u
};

#define VSECPRIM_STOP_SEC_CONST_32BIT
#include "CompilerCfg_vSecPrim.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actKECCAKcAbsorbData(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) data);

VSECPRIM_LOCAL_FUNC(void) actKECCAKcSqueezeData(
  VSECPRIM_P2CONST_PARA(actKECCAKcSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) data);

VSECPRIM_LOCAL_FUNC(void) actKECCAKcAbsorbData(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) data){
  info->state[info->rUsed] ^= actLEtoU64(data);
}

VSECPRIM_LOCAL_FUNC(void) actKECCAKcSqueezeData(
  VSECPRIM_P2CONST_PARA(actKECCAKcSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) data){
  actU64toLE((data), info->state[info->rUsed]);
}

VSECPRIM_LOCAL_FUNC(void) KECCAKf(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) KECCAKf(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU32 dst, src, x, y, r;
  actU64 Dx, C[SLICE_LENGTH];

  actL1trigger (watchdog);

  for(r = 0u; r < KECCAK_ROUNDS; r++){
    for(x = 0u; x < SLICE_LENGTH; x++){
      C[x] = info->state[x] ^ info->state[x + SLICE_LENGTH] ^ info->state[x + (2u * SLICE_LENGTH)] ^
             info->state[x + (3u * SLICE_LENGTH)] ^ info->state[x + (4u * SLICE_LENGTH)];
    }

    for(x = 0u; x < SLICE_LENGTH; x++){
      Dx = C [(x + 4u) % SLICE_LENGTH] ^ actRotl64 (C [(x + 1u) % SLICE_LENGTH], 1u);

      for(y = 0u; y <= (SLICE_LENGTH * (SLICE_LENGTH - 1u)); y += SLICE_LENGTH)
      {
        info->state[y + x] ^= Dx;
      }
    }

    Dx = actRotl64(info->state[1], rho_offset[1]);

    dst = 1u;
    src = pi_lane[1];

    while(src != 1u){
      info->state[dst] = actRotl64(info->state[src], rho_offset[src]);
      dst = src;
      src = pi_lane[dst];
    }

    info->state[dst] = Dx;

    for(y = 0u; y <= (SLICE_LENGTH * (SLICE_LENGTH - 1u)); y += SLICE_LENGTH){
      for(x = 0u; x < SLICE_LENGTH; x++)
      {
        C[x] = info->state[y + x];
      }

      for(x = 0u; x < SLICE_LENGTH; x++)
      {
        info->state[y + x] ^= (~C[(x + 1u) % SLICE_LENGTH]) & C[(x + 2u) % SLICE_LENGTH];
      }
    }

    info->state[0] ^= RC[r];

    actL2trigger (watchdog);
  }

  actL1trigger (watchdog);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

