

#define ACTBNODDINVMODBASE_SOURCE

#include "actBigNum.hpp"

#if(VSECPRIM_ACTBNODDINVMODBASE_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actBNOddInvModBase(VSECPRIM_P2VAR_PARA(actBNDIGIT) inverse, VSECPRIM_P2CONST_PARA(actBNDIGIT) value){
  actBNDDIGIT d = 1;
  actBNDDIGIT power = 1;
  actBNDIGIT tempVal = *value;
  actU8 i;

  *inverse = 0u;
  for (i = 0u; i < actBN_BITS_PER_DIGIT; ++i){
    power <<= 1;
    if((d % power) != 0u){
      d = (actBNDDIGIT) (d + tempVal);

      (*inverse) = (actBNDIGIT) ((*inverse) + (actBNDIGIT) (power >> 1));
    }
    tempVal <<= 1;
  }
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

