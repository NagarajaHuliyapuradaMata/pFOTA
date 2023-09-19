

#ifndef ACTICMACAES_H
#define ACTICMACAES_H

#include "actITypes.hpp"
#include "actAES.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actCMACAESInit(
   VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actCMACAESUpdate(
   VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actCMACAESFinalize(
   VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) info, VSECPRIM_P2VAR_PARA(actU8) mac
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"
#endif

