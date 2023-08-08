

#define ACT_DRBG_COMMON_SOURCE

#include "actDRBGCommon.hpp"

#if((VSECPRIM_ACTCTRDRBG_ENABLED == STD_ON) || (VSECPRIM_ACTHASHDRBG_ENABLED == STD_ON))

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actDrbgIncrementBlock(
  VSECPRIM_P2VAR_PARA(actU8) block,
  actLengthType blockLength){
  uint32 i = blockLength;
  actU8 result;

  while (i != 0u){
    i--;

    ++block[i];
    result = block[i];

    if(result != 0u){
      break;
    }
  }
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

