

#ifndef ACTKECCAKC_H
#define ACTKECCAKC_H

#include "actITypes.hpp"

#define KECCAKc_PHASE                                                (0x0Fu)
#define KECCAKc_PHASE_UNDEFINED                                      (0x00u)
#define KECCAKc_PHASE_INITIAL                                        (0x01u)
#define KECCAKc_PHASE_ABSORB                                         (0x02u)
#define KECCAKc_PHASE_SQUEEZE                                        (0x03u)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
    extern "C" {
#endif

VSECPRIM_FUNC(actRETURNCODE) actKECCAKcInit(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info
   ,  const actU32       strength
   ,  const actU8        pad1);

VSECPRIM_FUNC(actRETURNCODE) actKECCAKcAbsorb(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) data
   ,  const actLengthType dataLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actKECCAKcSqueeze(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) digest
   ,  const actLengthType digestSize
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actKECCAKcZEROPadToRate(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
    }
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

