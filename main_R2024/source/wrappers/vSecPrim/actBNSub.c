

#define ACTBNSUB_SOURCE

#include "actBigNum.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTBNSUB_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actBNSub(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) c,
  const actLengthType length){
  actLengthType i;
  actBNDDIGIT tmp = actBN_BASE;

  for (i = 0; i < length; ++i){
     tmp = (actBNDDIGIT)(actBN_BASE | a[i]) - b[i] - (1u - (actBNDDIGIT)actBNHiWord(tmp));
    c[i] = actBNLoWord(tmp);
  }
}

VSECPRIM_FUNC(void) actBNSubDigit(
  VSECPRIM_P2CONST_PARA(actBNDIGIT)  a,
  const actBNDIGIT b,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) c,
  const actBNLENGTH length){
  actBNLENGTH  i;
  actBNDDIGIT  tmp;
  actBNDDIGIT  carry = b;

  for (i = 0u; ((carry != 0u) && (i < length)); ++i){
    tmp = (actBNDDIGIT)a[i] - carry;
    c[i] = actBNLoWord(tmp);

    if(actBNHiWord(tmp) != 0u){
      carry = 1u;
    }
    else{
      carry = 0u;
    }
  }
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

