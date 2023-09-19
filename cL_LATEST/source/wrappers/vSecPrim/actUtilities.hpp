

#ifndef ACTUTILITIES_H
#define ACTUTILITIES_H

#include "actITypes.hpp"
#include "actConfig.hpp"
#include "vstdlib.hpp"

#define actMin(x, y)                                                 (((x)<(y))? (x):(y))
#define actMax(x, y)                                                 (((x)>(y))? (x):(y))

#define actBitsToBytes(x)                                            (x >> 3u)
#define actBytesToBits(x)                                            (x << 3u)

#define actGetByte(x, n)                                             ((actU8)(((x)>>((n)<<3)) & 0xFFuL))

#define actGetLowByteFromU16(x)                                      ((actU8) actLOW_BYTE (x))
#define actGetU8fromU16(x, n)                                        ((actU8) actLOW_BYTE (((x) >> ((n) <<2u))))
#define actGetU8fromU32(x, n)                                        ((actU8) actLOW_BYTE (((x) >> ((n) <<3u))))
#define actGetU8fromU64(x, n)                                        ((actU8) actLOW_BYTE (((x) >> ((n) <<4u))))

#define actRotr(x, n)                                                (((x) >> ((actU32)(n))) | ((x) << (32uL - (actU32)(n))))
#define actRotl(x, n)                                                (((x) << ((actU32)(n))) | ((x) >> (32uL - (actU32)(n))))

#define actRotr16(x, n)                                              (((x) >> ((actU32)(n))) | ((x) << (16uL - (actU32)(n))))
#define actRotl16(x, n)                                              (((x) << ((actU32)(n))) | ((x) >> (16uL - (actU32)(n))))

#define actRotr64(x, n)                                              (((x) >> ((actU32)(n))) | ((x) << (64uL - (actU32)(n))))
#define actRotl64(x, n)                                              (((x) << ((actU32)(n))) | ((x) >> (64uL - (actU32)(n))))

#define actU8toU64(x)                                                \
                                                                      (((actU64)((x)[0])) | ((actU64)((x)[1]) << 8) | \
                                                                      ((actU64)((x)[2]) << 16) | ((actU64)((x)[3]) << 24) | \
                                                                      ((actU64)((x)[4]) << 32) | ((actU64)((x)[5]) << 40) | \
                                                                      ((actU64)((x)[6]) << 48) | ((actU64)((x)[7]) << 56))

#if(VSECPRIM_USE_VSTD_LIB == STD_ON)

#define actMemset(dest, fill, count)                                (VStdLib_MemSet((dest), (fill), (count)))
#define actMemClear(dest, count)                                    (VStdLib_MemClr((dest), (count)))
#define actMemCpyByteArray(dest, src, count)                        (VStdLib_MemCpy((dest), (src), (count)))

#if(actBN_BITS_PER_DIGIT == 32u)
#define actMemCpyWordArray(dest, src, count)                       (VStdLib_MemCpy32((VSECPRIM_P2VAR_PARA(actBNDIGIT))(dest), (VSECPRIM_P2CONST_PARA(actBNDIGIT))(src), (count)))
#endif

#if(actBN_BITS_PER_DIGIT == 16u)
#define actMemCpyWordArray(dest, src, count)                       (VStdLib_MemCpy16((VSECPRIM_P2VAR_PARA(actBNDIGIT))(dest), (VSECPRIM_P2CONST_PARA(actBNDIGIT))(src), (count)))
#endif

#if(actBN_BITS_PER_DIGIT == 8u)
#define actMemCpyWordArray(dest, src, count)                       (VStdLib_MemCpy((VSECPRIM_P2VAR_PARA(actBNDIGIT))(dest), (VSECPRIM_P2CONST_PARA(actBNDIGIT))(src), (count)))
#endif

#else

#define actMemset(dest, fill, count)                                (actMemSet((dest), fill, count))
#define actMemClear(dest, count)                                    (actMemSet((dest), 0u, count))
#define actMemCpyByteArray(dest, src, count)                        (actMemcpy((dest), (src), count))
#define actMemCpyWordArray(dest, src, count)                        (actBNCopy((VSECPRIM_P2VAR_PARA(actBNDIGIT))(dest), (VSECPRIM_P2CONST_PARA(actBNDIGIT))(src), count))

#endif

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

VSECPRIM_FUNC(void) actWatchdogTriggerFunction(VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_INLINE_FUNC(void) actMemSet(VSECPRIM_P2VAR_PARA(void) dest, actU8 fill, actLengthType count);

VSECPRIM_INLINE_FUNC(void) actMemcpy(VSECPRIM_P2VAR_PARA(void) dest, VSECPRIM_P2CONST_PARA(void) src, actU32 count);

VSECPRIM_INLINE_FUNC(void) actMemcpy_ROM(VSECPRIM_P2VAR_PARA(void) dest, VSECPRIM_P2CONST_PARA(void) src, actLengthType count);

VSECPRIM_INLINE_FUNC(void) actMemcpy_ROMRAM(VSECPRIM_P2VAR_PARA(void) dest, VSECPRIM_P2ROMCONST_PARA(actU8) src, actLengthType count);

VSECPRIM_INLINE_FUNC(actU8) actMemcmp(VSECPRIM_P2CONST_PARA(void) buf1, VSECPRIM_P2CONST_PARA(void) buf2, actLengthType count);

VSECPRIM_INLINE_FUNC(actU8) actMemcmp_ROM(VSECPRIM_P2ROMCONST_PARA(actU8) buf1, VSECPRIM_P2ROMCONST_PARA(actU8) buf2, actLengthType count);

VSECPRIM_INLINE_FUNC(actU8) actMemcmp_ROMRAM(VSECPRIM_P2CONST_PARA(void) buf1, VSECPRIM_P2ROMCONST_PARA(actU8) buf2, actLengthType count);

VSECPRIM_INLINE_FUNC(void) actXOR(VSECPRIM_P2VAR_PARA(void) buf1, VSECPRIM_P2CONST_PARA(void) buf2, actU32 count);

VSECPRIM_INLINE_FUNC(actU8) actAddBE(VSECPRIM_P2VAR_PARA(actU8) tgt, VSECPRIM_P2CONST_PARA(actU8) src, const actU32 length, const actU8 carry);

VSECPRIM_INLINE_FUNC(actU8) actLEtoU8(VSECPRIM_P2CONST_PARA(actU8) src);

VSECPRIM_INLINE_FUNC(void) actU8toLE(VSECPRIM_P2VAR_PARA(actU8) tgt, const actU8 in);

VSECPRIM_INLINE_FUNC(void) actCpyLEtoU8(VSECPRIM_P2VAR_PARA(actU8) tgt, VSECPRIM_P2CONST_PARA(actU8) src, const actU32 length);

VSECPRIM_INLINE_FUNC(void) actCpyU8toLE(VSECPRIM_P2VAR_PARA(actU8) tgt, VSECPRIM_P2CONST_PARA(actU8) src, const actU32 length);

VSECPRIM_INLINE_FUNC(actU16) actLEtoU16(VSECPRIM_P2CONST_PARA(actU8) src);

VSECPRIM_INLINE_FUNC(void) actU16toLE(VSECPRIM_P2VAR_PARA(actU8) tgt, const actU16 src);

VSECPRIM_INLINE_FUNC(void) actCpyLEtoU16(VSECPRIM_P2VAR_PARA(actU16) tgt, VSECPRIM_P2CONST_PARA(actU8) src, const actU32 length);

VSECPRIM_INLINE_FUNC(void) actCpyU16toLE(VSECPRIM_P2VAR_PARA(actU8) tgt, VSECPRIM_P2CONST_PARA(actU16) src, const actU32 length);

VSECPRIM_INLINE_FUNC(actU32) actBEtoU32(VSECPRIM_P2CONST_PARA(actU8) src);

VSECPRIM_INLINE_FUNC(actU32) actLEtoU32(VSECPRIM_P2CONST_PARA(actU8) src);

VSECPRIM_INLINE_FUNC(void) actU32toBE(VSECPRIM_P2VAR_PARA(actU8) tgt, const actU32 src);

VSECPRIM_INLINE_FUNC(void) actU32toLE(VSECPRIM_P2VAR_PARA(actU8) tgt, const actU32 src);

VSECPRIM_INLINE_FUNC(void) actCpyBEtoU32(
  VSECPRIM_P2VAR_PARA(actU32) tgt
   ,  VSECPRIM_P2CONST_PARA(actU8) src
   ,  const actU32 length);

VSECPRIM_INLINE_FUNC(void) actCpyLEtoU32(
  VSECPRIM_P2VAR_PARA(actU32) tgt
   ,  VSECPRIM_P2CONST_PARA(actU8) src
   ,  const actU32 length);

VSECPRIM_INLINE_FUNC(void) actCpyU32toBE(
  VSECPRIM_P2VAR_PARA(actU8) tgt
   ,  VSECPRIM_P2CONST_PARA(actU32) src
   ,  const actU32 length);

VSECPRIM_INLINE_FUNC(void) actCpyU32toLE(
  VSECPRIM_P2VAR_PARA(actU8) tgt
   ,  VSECPRIM_P2CONST_PARA(actU32) src
   ,  const actU32 length);

#ifdef ACT_PLATFORM_UINT64_AVAILABLE

VSECPRIM_INLINE_FUNC(actU64) actBEtoU64 (VSECPRIM_P2CONST_PARA(actU8) src);

VSECPRIM_INLINE_FUNC(void) actU64toBE(VSECPRIM_P2VAR_PARA(actU8) tgt, const actU64 src);

VSECPRIM_INLINE_FUNC(void) actCpyBEtoU64(
  VSECPRIM_P2VAR_PARA(actU64) tgt
   ,  VSECPRIM_P2CONST_PARA(actU8) src
   ,  const actU32 length);

VSECPRIM_INLINE_FUNC(void) actCpyU64toBE(
  VSECPRIM_P2VAR_PARA(actU8) tgt
   ,  VSECPRIM_P2CONST_PARA(actU64) src
   ,  const actU32 length);

VSECPRIM_INLINE_FUNC(actU64) actLEtoU64(VSECPRIM_P2CONST_PARA(actU8) src);

VSECPRIM_INLINE_FUNC(void) actU64toLE(VSECPRIM_P2VAR_PARA(actU8) tgt, const actU64 src);
#endif

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

