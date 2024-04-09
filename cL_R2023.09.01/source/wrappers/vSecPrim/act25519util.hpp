

#ifndef ACT25519UTIL_H
#define ACT25519UTIL_H

#include "actBigNum.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

extern VSECPRIM_FUNC(void) act25519_initCore(VSECPRIM_P2VAR_PARA(actCurve25519ws) ws);

extern VSECPRIM_FUNC(void) act25519_reduceP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) a);

extern VSECPRIM_FUNC(void) act25519_reduceQ(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) a);

extern VSECPRIM_FUNC(void) act25519_addModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b);

extern VSECPRIM_FUNC(void) act25519_subModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b);

extern VSECPRIM_FUNC(void) act25519_mulModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b);

extern VSECPRIM_FUNC(void) act25519_powModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) act25519_invModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actU8) act25519_sqrtModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) act25519_addModQ(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b);

extern VSECPRIM_FUNC(void) act25519_mulModQ(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b);

extern VSECPRIM_FUNC(void) act25519_encodePoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actU8) buffer
   ,  VSECPRIM_P2CONST_PARA(actPoint) point
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actRETURNCODE) act25519_decodePoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actPoint) point
   ,  VSECPRIM_P2CONST_PARA(actU8) buffer
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) act25519_addPoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actPoint) r
   ,  VSECPRIM_P2CONST_PARA(actPoint) p
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) act25519_mulPoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actPoint) r
   ,  VSECPRIM_P2VAR_PARA(actPoint) p
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) s
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) act25519_mulAddPoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actPoint) r
   ,  VSECPRIM_P2VAR_PARA(actPoint) p
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) s
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) act25519_mulBasePoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2VAR_PARA(actPoint) r
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) s
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actRETURNCODE) act25519_comparePoints(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws
   ,  VSECPRIM_P2CONST_PARA(actPoint) p
   ,  VSECPRIM_P2CONST_PARA(actPoint) q
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

