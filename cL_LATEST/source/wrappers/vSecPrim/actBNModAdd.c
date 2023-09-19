

#define ACTBNMODADD_SOURCE

#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTBNMODADD_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actBNModAdd(
   VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) c
   ,  VSECPRIM_P2CONST_PARA(actBNRING) Ring
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType length = Ring->m_length;

  actL2trigger(watchdog);

  if(actBNAdd(a, b, c, length) == 1u){
    actBNSub(c, Ring->m, c, length);
  }
  else{
    if(actBNCompare(c, Ring->m, length) == actCOMPARE_LARGER){
      actBNSub(c, Ring->m, c, length);
    }
  }
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

