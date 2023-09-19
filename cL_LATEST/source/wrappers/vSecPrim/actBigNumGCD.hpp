

#ifndef ACTBIGNUMGCD_H
#define ACTBIGNUMGCD_H

#include "actITypes.hpp"
#include "actConfig.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

VSECPRIM_FUNC(void) actBNGCDix(
   VSECPRIM_P2CONST_PARA(actBNDIGIT) a, VSECPRIM_P2VAR_PARA(actBNDIGIT) a_inv
   ,  VSECPRIM_P2CONST_PARA(actBNRING) Field, VSECPRIM_P2VAR_PARA(actBNDIGIT) t[]);

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

