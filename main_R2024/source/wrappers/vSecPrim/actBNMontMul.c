

#define ACTBNMONTMUL_SOURCE

#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTBNMONTMUL_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actBNMontMul(
   VSECPRIM_P2CONST_PARA(actBNDIGIT) x, VSECPRIM_P2CONST_PARA(actBNDIGIT) y,
   VSECPRIM_P2VAR_PARA(actBNDIGIT) A, VSECPRIM_P2CONST_PARA(actBNRING) Ring,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2CONST_PARA(actBNDIGIT) m = Ring->m;
  actLengthType n = Ring->m_length;
  actBNDIGIT m_bar = Ring->m_bar;

  actBNDIGIT u_i, x_i;
  actBNDDIGIT tmp1, tmp2;
  actLengthType i, j;

  actL1trigger(watchdog);

  actBNSetZero(A, n + 1u);

  for (i = 0u; i < n; i++){
    x_i = x[i];

    tmp1 = ( ((actBNDDIGIT)y[0]) * x_i ) + A[0];

    A[0] = actBNLoWord(tmp1);

    u_i = A[0] * m_bar;

    tmp2 = ( ((actBNDDIGIT)m[0]) * u_i ) + A[0];

    for (j = 1u; j < n; j++){
      tmp1 = ( ((actBNDDIGIT)(y[j])) * x_i ) + A[j] + actBNHiWord(tmp1);

      tmp2 = ( ((actBNDDIGIT)(m[j])) * u_i ) + actBNLoWord(tmp1) + actBNHiWord(tmp2);

      A[j-1u] = actBNLoWord(tmp2);

      actL3trigger(watchdog);
    }

    tmp1 = ((actBNDDIGIT)A[n]) + actBNHiWord(tmp1) + actBNHiWord(tmp2);
    A[n - 1u] = actBNLoWord(tmp1);
    A[n] = actBNHiWord(tmp1);

    actL2trigger(watchdog);
  }

  if(A[n] == 1u){
    actBNSub(A, m, A, n);
    A[n] = 0;
  }
  else{
    if(actBNCompare(A, m, n) >= actCOMPARE_EQUAL){
      actL2trigger(watchdog);
      actBNSub(A, m, A, n);
    }
  }

  actL1trigger(watchdog);
}

VSECPRIM_FUNC(void) actBNMontMulCopy(
   VSECPRIM_P2VAR_PARA(actBNDIGIT) x, VSECPRIM_P2CONST_PARA(actBNDIGIT) y,
   VSECPRIM_P2VAR_PARA(actBNDIGIT) A, VSECPRIM_P2CONST_PARA(actBNRING) Ring,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType i;

  actBNMontMul(x, y, A, Ring, watchdog);

  for (i = 0u; i < Ring->m_length; i++){
    x[i] = A[i];
  }
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

