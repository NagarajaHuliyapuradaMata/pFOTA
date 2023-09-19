

#ifndef ACTBIGNUM_H
#define ACTBIGNUM_H

#include "actITypes.hpp"
#include "actConfig.hpp"

#define actBN_BASE                                                   ((actBNDDIGIT)(1) << actBN_BITS_PER_DIGIT)

#define actBN_MAX_DIGIT                                              ((actBNDIGIT)(actBN_BASE - 1))

#define actBN_MAX_BIT                                                ((actBNDDIGIT)(1u) << (actBN_BITS_PER_DIGIT-1u))

#define actBN_HIGH_MAX                                               ((actBNDDIGIT)(actBN_MAX_DIGIT) << actBN_BITS_PER_DIGIT)

#define actBNSetZero(a, length)                                      actBNSet ((a), (length), ((actBNDIGIT) 0))

#define actBNSetOne(a, length)                                       actBNSet ((a), (length), ((actBNDIGIT) 1))

#define actBNGetDigitLength(byte_len)                                \
                                                                      (((byte_len)+actBN_BYTES_PER_DIGIT-1u)/actBN_BYTES_PER_DIGIT)

#define actBNGetBitOfDigit(digit, i)                                 \
                                                                      ( (((digit) & ((actBNDIGIT)(1u)<<(i))) != (actBNDIGIT)0u)  ? TRUE:FALSE)

#define actBNGetBit(a, i)                                            \
                                                                      (actBNGetBitOfDigit((a)[(i)/actBN_BITS_PER_DIGIT], ((i)%actBN_BITS_PER_DIGIT)))
#define actBNIsOdd(a)                                                ( ((a[0] & (actBNDIGIT)1u) == ((actBNDIGIT)1u)) ? TRUE:FALSE)
#define actBNIsEven(a)                                               ( ((a[0] & (actBNDIGIT)1u) != ((actBNDIGIT)1u)) ? TRUE:FALSE)

#define actBNLoWord(ddigit)                                          ((actBNDIGIT)(ddigit))

#define actBNHiWord(ddigit)                                          ((actBNDIGIT)((ddigit) >> actBN_BITS_PER_DIGIT))

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

extern VSECPRIM_FUNC(void) actBNLoadLE(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) bigNum
   ,  VSECPRIM_P2CONST_PARA(actU8) bytes
   ,  const actU32 byteLength);

extern VSECPRIM_FUNC(void) actBNStoreLE(
  VSECPRIM_P2VAR_PARA(actU8) bytes
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) bigNum
   ,  const actLengthType bnLength);

VSECPRIM_FUNC(void) actBNCopy(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b
   ,  const actLengthType length);

VSECPRIM_FUNC(actLengthType) actBNGetBitLength(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  const actLengthType length);

VSECPRIM_FUNC(actRETURNCODE) actBNSetBit(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a
   ,  const actLengthType length
   ,  const actLengthType bit_pos);

VSECPRIM_FUNC(void) actBNSet(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a
   ,  const actLengthType  length
   ,  const actBNDIGIT   value);

VSECPRIM_FUNC(actU8) actBNIsZero(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  const actLengthType length);

VSECPRIM_FUNC(actRETURNCODE) actBNCompare(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b
   ,  const actLengthType length);

VSECPRIM_FUNC(void) actBNSetOctetString(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a
   ,  actLengthType length
   ,  VSECPRIM_P2CONST_PARA(actU8) in
   ,  const actLengthType in_len);

VSECPRIM_FUNC(void) actBNSetOctetStringROM(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a
   ,  actLengthType length
   ,  VSECPRIM_P2CONST_PARA(actU8) in
   ,  const actLengthType in_len);

VSECPRIM_FUNC(void) actBNOctetString(
  VSECPRIM_P2VAR_PARA(actU8) out
   ,  actLengthType out_len
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  const actLengthType length);

VSECPRIM_FUNC(actU8) actBNAdd(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) c
   ,  const actLengthType length);

VSECPRIM_FUNC(void) actBNSub(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) c
   ,  const actLengthType length);

VSECPRIM_FUNC(void) actBNSubDigit(
  VSECPRIM_P2CONST_PARA(actBNDIGIT)  a
   ,  const actBNDIGIT b
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) c
   ,  const actBNLENGTH length);

VSECPRIM_FUNC(void) actBNMult(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  const actLengthType a_length
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b
   ,  const actLengthType b_length
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) c
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actBNDiv2(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a
   ,  actU8 first_carry
   ,  actLengthType length);

VSECPRIM_FUNC(actRETURNCODE) actBNReduce(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a
   ,  actLengthType a_length
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) b
   ,  actLengthType b_length
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actBNModAdd(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) c
   ,  VSECPRIM_P2CONST_PARA(actBNRING) Ring
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actBNModSub(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) c
   ,  VSECPRIM_P2CONST_PARA(actBNRING) Ring
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actBNModDiv2(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNRING) Ring
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actBNMontMul(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) x
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) y
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) A
   ,  VSECPRIM_P2CONST_PARA(actBNRING) Ring
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actBNMontMulCopy(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) x
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) y
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) A
   ,  VSECPRIM_P2CONST_PARA(actBNRING) Ring
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actBNModExp(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) gR
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) e
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) AR
   ,  VSECPRIM_P2CONST_PARA(actBNRING) Ring
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) t[]
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actBNModRandomize(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) x
   ,  VSECPRIM_P2CONST_PARA(actBNRING) Ring
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) t[]
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actBNFieldInversion(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) gR
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) g_invR
   ,  VSECPRIM_P2CONST_PARA(actBNRING) Field
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) t[]
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actBNOddInvModBase(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) inverse
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) value);

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

