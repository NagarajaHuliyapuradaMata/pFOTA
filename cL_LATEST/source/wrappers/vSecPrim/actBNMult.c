

#define ACTBNMULT_SOURCE

#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTBNMULT_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actBNMult(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  const actLengthType a_length
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b
   ,  const actLengthType b_length
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) c
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType i, j, c_length = a_length + b_length;
  actBNDDIGIT tmp;
  actBNDIGIT carry;

  actL2trigger(watchdog);

  actBNSetZero(c, c_length);

  for(i = 0u; i < b_length; ++i){
    carry = 0u;
    for(j = 0u; j < a_length; ++j){
      tmp = (((actBNDDIGIT) a[j]) * b[i]) + c[(i + j)] + carry;
      c[(i + j)] = actBNLoWord(tmp);
      carry = actBNHiWord(tmp);
    }
    c[(i + a_length)] = carry;
  }
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

