

#define ACTBNADD_SOURCE

#include "actBigNum.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTBNADD_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actU8) actBNAdd(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) c,
  const actLengthType length){
  actLengthType i;
  actBNDDIGIT tmp = 0u;

  for (i = 0u; i < length; ++i){
    tmp = ((actBNDDIGIT) a[i]) + b[i] + actBNHiWord(tmp);
    c[i] = actBNLoWord(tmp);
  }

  return (actU8)actBNHiWord(tmp);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

