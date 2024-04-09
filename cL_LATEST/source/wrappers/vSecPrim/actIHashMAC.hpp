

#ifndef ACTIHASHMAC_H
#define ACTIHASHMAC_H

#include "actITypes.hpp"
#include "actISHA.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

VSECPRIM_FUNC(actRETURNCODE) actHashMACInit(
   VSECPRIM_P2VAR_PARA(actHASHMACSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actHashMACUpdate(
   VSECPRIM_P2VAR_PARA(actHASHMACSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actHashMACFinalize(
   VSECPRIM_P2VAR_PARA(actHASHMACSTRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

