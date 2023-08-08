

#ifndef ACTIGHASH_H
# define ACTIGHASH_H

# include "actConfig.hpp"
# include "actITypes.hpp"
# include "actIAES.hpp"

# define GF128POLY                                                    (0xE1000000u)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
extern "C"
{
# endif

  VSECPRIM_FUNC(actRETURNCODE) actGHashReset(VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info);

VSECPRIM_FUNC(actRETURNCODE) actGHashInit (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) H,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actGHashUpdate (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) X,
   actLengthType X_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actGHashZeroPad (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actGHashFinalize (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   actU8 hash[actGHASH_BLOCK_SIZE],
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus
}
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

