

#define ACTUTILITIES_SOURCE

#include "actUtilities.hpp"

#if(VSECPRIM_ACTUTILITIES_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_INLINE_FUNC(void) actMemSet(VSECPRIM_P2VAR_PARA(void) dest, actU8 fill, actLengthType count){
  VSECPRIM_P2VAR_PARA(actU8) dest_tmp = (VSECPRIM_P2VAR_PARA(actU8))dest;
  actLengthType i = count;
  while(i > 0u){
    --i;
    dest_tmp[i] = fill;
  }
}

VSECPRIM_INLINE_FUNC(void) actMemcpy(VSECPRIM_P2VAR_PARA(void) dest, VSECPRIM_P2CONST_PARA(void) src, actU32 count){
  VSECPRIM_P2VAR_PARA(actU8) dest_tmp = (VSECPRIM_P2VAR_PARA(actU8))dest;
  VSECPRIM_P2CONST_PARA(actU8) src_tmp = (VSECPRIM_P2CONST_PARA(actU8))src;
  actU32 i = count;
  while(i > 0u){
    --i;
    dest_tmp[i] = src_tmp[i];
  }
}

VSECPRIM_INLINE_FUNC(void) actMemcpy_ROM(VSECPRIM_P2VAR_PARA(void) dest, VSECPRIM_P2CONST_PARA(void) src, actLengthType count){
  VSECPRIM_P2VAR_PARA(actU8) dest_tmp = (VSECPRIM_P2VAR_PARA(actU8))dest;
  VSECPRIM_P2CONST_PARA(actU8) src_tmp = (VSECPRIM_P2CONST_PARA(actU8))src;
  actLengthType i = count;
  while(i > 0u){
    --i;
    dest_tmp[i] = ACT_ROM_BYT(&src_tmp[i]);
  }
}

VSECPRIM_INLINE_FUNC(void) actMemcpy_ROMRAM(VSECPRIM_P2VAR_PARA(void) dest, VSECPRIM_P2ROMCONST_PARA(actU8) src, actLengthType count){
  VSECPRIM_P2VAR_PARA(actU8) dest_tmp = (VSECPRIM_P2VAR_PARA(actU8))dest;
  actLengthType i = count;
  while(i > 0u){
    --i;
    dest_tmp[i] = src[i];
  }
}

VSECPRIM_FUNC(void) actWatchdogTriggerFunction(VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  if(watchdog != NULL_PTR){
    (*watchdog)();
  }
}

VSECPRIM_INLINE_FUNC(actU8) actMemcmp(VSECPRIM_P2CONST_PARA(void) buf1, VSECPRIM_P2CONST_PARA(void) buf2, actLengthType count){
  VSECPRIM_P2CONST_PARA(actU8) buf1_tmp = (VSECPRIM_P2CONST_PARA(actU8))buf1;
  VSECPRIM_P2CONST_PARA(actU8) buf2_tmp = (VSECPRIM_P2CONST_PARA(actU8))buf2;
  actLengthType i;
  boolean isEqual = TRUE;

  for(i = 0; i < count; ++i){
    isEqual &= (buf1_tmp[i] == buf2_tmp[i]) ? (TRUE) : (FALSE);
  }

  return isEqual;
}

VSECPRIM_INLINE_FUNC(actU8) actMemcmp_ROM(VSECPRIM_P2ROMCONST_PARA(actU8) buf1, VSECPRIM_P2ROMCONST_PARA(actU8) buf2, actLengthType count){
  actLengthType i;
  boolean isEqual = TRUE;

  for(i = 0; i < count; ++i){
    isEqual &= ((ACT_ROM_BYT(&buf1[i]) == ACT_ROM_BYT(&buf2[i]))) ? (TRUE) : (FALSE);
  }

  return isEqual;
}

VSECPRIM_INLINE_FUNC(actU8) actMemcmp_ROMRAM(VSECPRIM_P2CONST_PARA(void) buf1, VSECPRIM_P2ROMCONST_PARA(actU8) buf2, actLengthType count){
  VSECPRIM_P2CONST_PARA(actU8) buf1_tmp = (VSECPRIM_P2CONST_PARA(actU8))buf1;
  actLengthType i;
  boolean isEqual = TRUE;

  for(i = 0; i < count; ++i){
    isEqual &= (buf1_tmp[i] == ACT_ROM_BYT(&buf2[i])) ? (TRUE) : (FALSE);
  }

  return isEqual;
}

VSECPRIM_INLINE_FUNC(void) actXOR(VSECPRIM_P2VAR_PARA(void) buf1, VSECPRIM_P2CONST_PARA(void) buf2, actU32 count){
  VSECPRIM_P2VAR_PARA(actU8) buf1_tmp = (VSECPRIM_P2VAR_PARA(actU8))buf1;
  VSECPRIM_P2CONST_PARA(actU8) buf2_tmp = (VSECPRIM_P2CONST_PARA(actU8))buf2;
  actU32 i = count;
  while(i > 0u){
    --i;

    buf1_tmp[i] ^= buf2_tmp[i];
  }
}

VSECPRIM_INLINE_FUNC(actU8) actAddBE(VSECPRIM_P2VAR_PARA(actU8) tgt, VSECPRIM_P2CONST_PARA(actU8) src, const actU32 length, const actU8 carry){
  actU8 cy = carry;
  actU16 tmp;
  actU32 i;
  VSECPRIM_P2VAR_PARA(actU8) tmpTgt;
  VSECPRIM_P2CONST_PARA(actU8) tmpSrc;

  for(i = 0u; i < length; i++){
    tmpSrc = &src[(length - 1u) - i];
    tmpTgt = &tgt[(length - 1u) - i];

    tmp = (actU16)(((actU16) *tmpTgt) + ((actU16) *tmpSrc) + cy);
    *tmpTgt = (actU8)actLOW_BYTE(tmp);
    cy = (actU8)actLOW_BYTE(tmp >> 8);
  }

  return cy;
}

VSECPRIM_INLINE_FUNC(actU8)  actLEtoU8(VSECPRIM_P2CONST_PARA(actU8) src){
  return actLOW_BYTE(*src);
}

VSECPRIM_INLINE_FUNC(void) actU8toLE(VSECPRIM_P2VAR_PARA(actU8) tgt, const actU8 in){
  *tgt = (actU8)actLOW_BYTE(in);
}

VSECPRIM_INLINE_FUNC(actU16) actLEtoU16(VSECPRIM_P2CONST_PARA(actU8) src){
  VSECPRIM_REGISTER actU16  u16;

  u16  = ((actU16)actLOW_BYTE(src[0]));
  u16 |= ((actU16)actLOW_BYTE(src[1])) << 8;

  return u16;
}

VSECPRIM_INLINE_FUNC(void) actU16toLE(
  VSECPRIM_P2VAR_PARA(actU8) tgt
   ,  const actU16 src){
  tgt[0] = (actU8)actLOW_BYTE(src);
  tgt[1] = (actU8)actLOW_BYTE(src >> 8);
}

VSECPRIM_INLINE_FUNC(void) actCpyLEtoU16(
  VSECPRIM_P2VAR_PARA(actU16) tgt
   ,  VSECPRIM_P2CONST_PARA(actU8) src
   ,  const actU32 length){
  actU32  i;

  for(i = 0u; i < (length / 2u); i++){
    tgt[i] = actLEtoU16(&src[i * 2u]);
  }
}

VSECPRIM_INLINE_FUNC(void) actCpyU16toLE(
  VSECPRIM_P2VAR_PARA(actU8) tgt
   ,  VSECPRIM_P2CONST_PARA(actU16)src
   ,  const actU32 length){
  actU32 i;

  for(i = 0u; i < (length / 2u); i++){
    actU16toLE(&tgt[i * 2u], src[i]);
  }
}

VSECPRIM_INLINE_FUNC(actU32) actBEtoU32(VSECPRIM_P2CONST_PARA(actU8) src){
  VSECPRIM_REGISTER actU32  u32;

  u32  = ((actU32)actLOW_BYTE(src[0])) << 24;
  u32 |= ((actU32)actLOW_BYTE(src[1])) << 16;
  u32 |= ((actU32)actLOW_BYTE(src[2])) << 8;
  u32 |= ((actU32)actLOW_BYTE(src[3]));

  return u32;
}

VSECPRIM_INLINE_FUNC(actU32) actLEtoU32(VSECPRIM_P2CONST_PARA(actU8) src){
  VSECPRIM_REGISTER actU32  u32;

  u32  = ((actU32)actLOW_BYTE(src[0]));
  u32 |= ((actU32)actLOW_BYTE(src[1])) << 8;
  u32 |= ((actU32)actLOW_BYTE(src[2])) << 16;
  u32 |= ((actU32)actLOW_BYTE(src[3] )) << 24;

  return u32;
}

VSECPRIM_INLINE_FUNC(void) actU32toBE(VSECPRIM_P2VAR_PARA(actU8) tgt, const actU32 src){
  tgt[0] = (actU8)actLOW_BYTE(src >> 24);
  tgt[1] = (actU8)actLOW_BYTE(src >> 16);
  tgt[2] = (actU8)actLOW_BYTE(src >> 8);
  tgt[3] = (actU8)actLOW_BYTE(src);
}

VSECPRIM_INLINE_FUNC(void) actU32toLE(
  VSECPRIM_P2VAR_PARA(actU8) tgt
   ,  const actU32 src){
  tgt[0] = (actU8)actLOW_BYTE(src);
  tgt[1] = (actU8)actLOW_BYTE(src >> 8);
  tgt[2] = (actU8)actLOW_BYTE(src >> 16);
  tgt[3] = (actU8)actLOW_BYTE(src >> 24);
}

VSECPRIM_INLINE_FUNC(void) actCpyBEtoU32(
  VSECPRIM_P2VAR_PARA(actU32) tgt
   ,  VSECPRIM_P2CONST_PARA(actU8) src
   ,  const actU32 length){
  actU32  i;

  for(i = 0u; i < (length / 4u); i++){
    tgt[i] = actBEtoU32(&src[(i * 4u)]);
  }
}

VSECPRIM_INLINE_FUNC(void) actCpyLEtoU32(
  VSECPRIM_P2VAR_PARA(actU32) tgt
   ,  VSECPRIM_P2CONST_PARA(actU8) src
   ,  const actU32 length){
  actU32  i;

  for(i = 0u; i < (length / 4u); i++){
    tgt[i] = actLEtoU32(&src[(i * 4u)]);
  }
}

VSECPRIM_INLINE_FUNC(void) actCpyU32toBE(
  VSECPRIM_P2VAR_PARA(actU8) tgt
   ,  VSECPRIM_P2CONST_PARA(actU32)src
   ,  const actU32 length){
  actU32 i;

  for(i = 0u; i < length; i++){
    actU32toBE(&tgt[(i * 4u)], src[i]);
  }
}

VSECPRIM_INLINE_FUNC(void) actCpyU32toLE(
  VSECPRIM_P2VAR_PARA(actU8) tgt
   ,  VSECPRIM_P2CONST_PARA(actU32) src
   ,  const actU32 length){
  actU32 i;

  for(i = 0u; i < length; i++){
    actU32toLE(&tgt[(i * 4u)], src[i]);
  }
}

#ifdef ACT_PLATFORM_UINT64_AVAILABLE

VSECPRIM_INLINE_FUNC(actU64) actBEtoU64(VSECPRIM_P2CONST_PARA(actU8) src){
  VSECPRIM_REGISTER actU64  u64;

  u64  = ((actU64)actLOW_BYTE(src[0])) << 56;
  u64 |= ((actU64)actLOW_BYTE(src[1])) << 48;
  u64 |= ((actU64)actLOW_BYTE(src[2])) << 40;
  u64 |= ((actU64)actLOW_BYTE(src[3])) << 32;
  u64 |= ((actU64)actLOW_BYTE(src[4])) << 24;
  u64 |= ((actU64)actLOW_BYTE(src[5])) << 16;
  u64 |= ((actU64)actLOW_BYTE(src[6])) << 8;
  u64 |= ((actU64)actLOW_BYTE(src[7]));

  return u64;
}

VSECPRIM_INLINE_FUNC(void) actU64toBE(
  VSECPRIM_P2VAR_PARA(actU8) tgt
   ,  const actU64 src){
  tgt[0] = (actU8)actLOW_BYTE(src >> 56);
  tgt[1] = (actU8)actLOW_BYTE(src >> 48);
  tgt[2] = (actU8)actLOW_BYTE(src >> 40);
  tgt[3] = (actU8)actLOW_BYTE(src >> 32);
  tgt[4] = (actU8)actLOW_BYTE(src >> 24);
  tgt[5] = (actU8)actLOW_BYTE(src >> 16);
  tgt[6] = (actU8)actLOW_BYTE(src >> 8);
  tgt[7] = (actU8)actLOW_BYTE(src);
}

VSECPRIM_INLINE_FUNC(void) actCpyBEtoU64(
  VSECPRIM_P2VAR_PARA(actU64) tgt
   ,  VSECPRIM_P2CONST_PARA(actU8) src
   ,  const actU32 length){
  actU32 i;

  for(i = 0u; i < (length / 8u); i++){
    tgt[i] = actBEtoU64(&src[(i * 8u)]);
  }
}

VSECPRIM_INLINE_FUNC(void)  actCpyU64toBE(
  VSECPRIM_P2VAR_PARA(actU8) tgt
   ,  VSECPRIM_P2CONST_PARA(actU64) src
   ,  const actU32 length){
  actU32 i;

  for(i = 0; i < length; i++){
    actU64toBE(&tgt[(i * 8u)], src[i]);
  }
}

VSECPRIM_INLINE_FUNC(actU64) actLEtoU64(VSECPRIM_P2CONST_PARA(actU8) src){
  VSECPRIM_REGISTER actU64  u64;

  u64 = ((actU64)actLOW_BYTE(src[0]));
  u64 |= ((actU64)actLOW_BYTE(src[1])) << 8;
  u64 |= ((actU64)actLOW_BYTE(src[2])) << 16;
  u64 |= ((actU64)actLOW_BYTE(src[3])) << 24;
  u64 |= ((actU64)actLOW_BYTE(src[4])) << 32;
  u64 |= ((actU64)actLOW_BYTE(src[5])) << 40;
  u64 |= ((actU64)actLOW_BYTE(src[6])) << 48;
  u64 |= ((actU64)actLOW_BYTE(src[7])) << 56;

  return u64;
}

VSECPRIM_INLINE_FUNC(void) actU64toLE(
  VSECPRIM_P2VAR_PARA(actU8) tgt
   ,  const actU64 src){
  tgt[0] = (actU8)actLOW_BYTE(src);
  tgt[1] = (actU8)actLOW_BYTE(src >> 8);
  tgt[2] = (actU8)actLOW_BYTE(src >> 16);
  tgt[3] = (actU8)actLOW_BYTE(src >> 24);
  tgt[4] = (actU8)actLOW_BYTE(src >> 32);
  tgt[5] = (actU8)actLOW_BYTE(src >> 40);
  tgt[6] = (actU8)actLOW_BYTE(src >> 48);
  tgt[7] = (actU8)actLOW_BYTE(src >> 56);
}

#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

