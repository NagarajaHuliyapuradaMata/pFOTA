

#ifndef ACTECPOINT_H
# define ACTECPOINT_H

# include "actUtilities.hpp"
# include "actBigNum.hpp"

typedef struct{
  VSECPRIM_P2VAR_PARA(actBNDIGIT) x;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) y;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) z;
  boolean is_affine;
  boolean is_infinity;
}actECPOINT;

typedef actBNDIGIT actEcTempType[10];

# define actECPIsInfinity(Q, Curve)                                   (actBNIsZero((Q)->z, (Curve)->p_field->m_length) == TRUE)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
extern "C" {
# endif

VSECPRIM_FUNC( void ) actECPAssign (
  VSECPRIM_P2VAR_PARA( actECPOINT ) Q1,
  VSECPRIM_P2CONST_PARA( actECPOINT ) Q2,
  VSECPRIM_P2CONST_PARA( actECCURVE ) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actECPToMont(
  VSECPRIM_P2CONST_PARA(actECPOINT) Q,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actECPToAffineFromMont(
  VSECPRIM_P2VAR_PARA(actECPOINT) Q,
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
  boolean transformToAffineOnly,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actECPointIsOnCurve(
  VSECPRIM_P2CONST_PARA(actECPOINT) Q,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actECPDouble(
  VSECPRIM_P2VAR_PARA(actECPOINT) Q,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actECPAdd(
   VSECPRIM_P2VAR_PARA(actECPOINT) Q1,
   VSECPRIM_P2CONST_PARA(actECPOINT) Q2,
   VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC( void ) actECPSub (
  VSECPRIM_P2VAR_PARA( actECPOINT ) Q1,
  VSECPRIM_P2CONST_PARA( actECPOINT ) Q2,
  VSECPRIM_P2CONST_PARA( actECCURVE ) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC( void ) actECPMult(
  VSECPRIM_P2CONST_PARA( actECPOINT ) Q,
  VSECPRIM_P2CONST_PARA( actBNDIGIT ) k,
  VSECPRIM_P2VAR_PARA( actECPOINT ) R,
  VSECPRIM_P2CONST_PARA( actECCURVE ) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC( void ) actECPMultShort(
  VSECPRIM_P2CONST_PARA( actECPOINT ) Q,
  const actU32 k,
  VSECPRIM_P2VAR_PARA( actECPOINT ) R,
  VSECPRIM_P2CONST_PARA( actECCURVE ) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actECPMultG(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) k,
  VSECPRIM_P2VAR_PARA(actECPOINT) Prec,
  VSECPRIM_P2VAR_PARA(actECPOINT) R,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actECPSimMult(
  VSECPRIM_P2CONST_PARA(actECPOINT) Q1,
  VSECPRIM_P2CONST_PARA(actECPOINT) Q2,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) k1,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) k2,
  VSECPRIM_P2VAR_PARA(actECPOINT) Q12,
  VSECPRIM_P2VAR_PARA(actECPOINT) R,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus
}
# endif
# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

