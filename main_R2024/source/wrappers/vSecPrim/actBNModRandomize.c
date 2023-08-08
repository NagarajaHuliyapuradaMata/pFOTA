

#define ACTBNMODRANDOMIZE_SOURCE

#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actExternRandom.hpp"

#if(VSECPRIM_ACTBNMODRANDOMIZE_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actBNModRandomize(VSECPRIM_P2VAR_PARA(actBNDIGIT) x,
  VSECPRIM_P2CONST_PARA(actBNRING) Ring,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) t[],
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType m_length = Ring->m_length;
  actRETURNCODE retVal = actOK;

  do
  {
    retVal = actGetExternRandom(((VSECPRIM_P2VAR_PARA(actU8)) x), m_length * actBN_BYTES_PER_DIGIT);

    if(retVal == actOK){
      retVal = actGetExternRandom(((VSECPRIM_P2VAR_PARA(actU8)) t[0]), m_length * actBN_BYTES_PER_DIGIT);

      if(retVal == actOK)
      {
        actBNMontMulCopy(x, t[0], t[1], Ring, watchdog);
        actBNMontMulCopy(x, Ring->RR, t[0], Ring, watchdog);
      }
    }
  }
  while((actBNIsZero(x, m_length) == TRUE) && (retVal == actOK));

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

