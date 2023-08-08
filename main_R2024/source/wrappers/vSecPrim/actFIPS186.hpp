

#ifndef ACTFIPS186_H
# define ACTFIPS186_H

# include "actITypes.hpp"
# include "actISHA.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
extern "C"
{
# endif

VSECPRIM_FUNC(void) actInitializeFIPS186(VSECPRIM_P2VAR_PARA(actFIPS186STRUCT) info, VSECPRIM_P2CONST_PARA(actU8) seed);

VSECPRIM_FUNC(void) actGetFIPS186(
  VSECPRIM_P2VAR_PARA(actFIPS186STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) output,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actWriteFIPS186(
   VSECPRIM_P2VAR_PARA(actFIPS186STRUCT) info, VSECPRIM_P2CONST_PARA(actU8) new_seed);

# ifdef __cplusplus
}
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

