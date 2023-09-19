

#define ACTBNMODDIV2_SOURCE

#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTBNMODDIV2_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actBNModDiv2(
   VSECPRIM_P2VAR_PARA(actBNDIGIT) a, VSECPRIM_P2CONST_PARA(actBNRING) Ring
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType length = Ring->m_length;
  actU8 first_carry = 0u;

  actL2trigger(watchdog);

  if( actBNIsOdd(a) == TRUE){
    first_carry = (actU8) actBNAdd(a, Ring->m, a, length);
  }

  actBNDiv2(a, first_carry, length);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

