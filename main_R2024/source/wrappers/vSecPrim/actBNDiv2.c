

#define ACTBNDIV2_SOURCE

#include "actBigNum.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTBNDIV2_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actBNDiv2(VSECPRIM_P2VAR_PARA(actBNDIGIT) a, actU8 first_carry, actLengthType length){
  actLengthType tmpLength;
  actU8 carry1 = first_carry, carry2;
  actBNDIGIT tmp;
  uint32 i;

  for (i = 0u; i < length; i++){
    tmpLength = (length - i) - 1u;
    tmp = a[tmpLength];
    carry2 = (actU8) (tmp & 1u);
    tmp >>= 1;
    tmp |= (((actBNDIGIT) carry1) << (actBN_BITS_PER_DIGIT - 1u));
    carry1 = carry2;
    a[tmpLength] = tmp;
  }
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

