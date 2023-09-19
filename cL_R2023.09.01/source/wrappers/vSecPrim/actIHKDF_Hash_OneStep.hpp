

#ifndef ACTIHKDFHASH_ONESTEP_H
#define ACTIHKDFHASH_ONESTEP_H

#include "actITypes.hpp"
#include "actISHA2_32.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actHKDF_Hash_OneStepDerive(
  VSECPRIM_P2VAR_PARA(actHKDFHASHSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) secret
   ,  actLengthType secretLength
   ,  VSECPRIM_P2CONST_PARA(actU8) addInput
   ,  actLengthType addInputLength
   ,  VSECPRIM_P2VAR_PARA(actU8) derivedKey
   ,  const actLengthType derivedKeyLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
}
#endif

#endif

