

#define ACTBNMODSUB_SOURCE

#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTBNMODSUB_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actBNModSub(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) c,
  VSECPRIM_P2CONST_PARA(actBNRING) Ring,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType length = Ring->m_length;

  actL2trigger(watchdog);

  if(actBNCompare(a, b, length) == actCOMPARE_SMALLER){
    actBNSub(b, a, c, length);
    actBNSub(Ring->m, c, c, length);
  }
  else{
    actBNSub(a, b, c, length);
  }
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

