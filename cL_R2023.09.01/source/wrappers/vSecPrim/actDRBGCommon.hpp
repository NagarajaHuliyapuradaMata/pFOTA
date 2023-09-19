

#ifndef ACTDRBGCOMMON_H
#define ACTDRBGCOMMON_H

#include "actITypes.hpp"

#if((VSECPRIM_ACTCTRDRBG_ENABLED == STD_ON) || (VSECPRIM_ACTHASHDRBG_ENABLED == STD_ON))

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actDrbgIncrementBlock(
  VSECPRIM_P2VAR_PARA(actU8) block
   ,  actLengthType blockLength);

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

#endif

