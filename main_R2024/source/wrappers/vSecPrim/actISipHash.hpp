

#ifndef ACTISIPHASH_H
# define ACTISIPHASH_H

# include "actITypes.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# if defined ACT_PLATFORM_UINT64_AVAILABLE

VSECPRIM_FUNC(actRETURNCODE) actSipHashInit(
  VSECPRIM_P2VAR_PARA(actSipHashSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key,
  actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog) (void));

VSECPRIM_FUNC(actRETURNCODE) actSipHashUpdate(
  VSECPRIM_P2VAR_PARA(actSipHashSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog) (void));

VSECPRIM_FUNC(actRETURNCODE) actSipHashFinalize(
  VSECPRIM_P2VAR_PARA(actSipHashSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU64) mac,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog) (void));
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

