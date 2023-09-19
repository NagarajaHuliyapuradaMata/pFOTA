

#define ACTBNFIELDINVERSION_SOURCE

#include "actBigNum.hpp"
#if(VSECPRIM_ACTBNEUCLID_ENABLED == STD_ON)
#include "actBigNumGCD.hpp"
#endif
#include "actUtilities.hpp"

#if(VSECPRIM_ACTBNFIELDINVERSION_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actBNFieldInversion(
   VSECPRIM_P2CONST_PARA(actBNDIGIT) gR, VSECPRIM_P2VAR_PARA(actBNDIGIT) g_invR
   ,  VSECPRIM_P2CONST_PARA(actBNRING) Field, VSECPRIM_P2VAR_PARA(actBNDIGIT) t[]
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
#if(VSECPRIM_ACTBNEUCLID_ENABLED == STD_ON)

  VSECPRIM_P2VAR_PARA(actBNDIGIT) tmp = t[4];

  actBNSetZero(t[3], Field->m_length);
  (t[3])[0] = (actBNDIGIT) 1;
  actBNMontMul(gR, t[3], tmp, Field, watchdog);

  actBNGCDix(tmp, g_invR, Field, t);

  actBNMontMulCopy(g_invR, Field->RR, tmp, Field, watchdog);

#else

  actLengthType p_length = Field->m_length;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) e;
#if(actBN_MOD_EXP_WINDOW_SIZE == 0)
  e = t[1 << (Field->window_size - 1)];
#else
  e = t[1u << (actBN_MOD_EXP_WINDOW_SIZE - 1u)];
#endif

  actBNSetZero(e, p_length);
  e[0] = 2;
  actBNSub(Field->m, e, e, p_length);

  actBNModExp(gR, e, g_invR, Field, t, watchdog);
#endif
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

