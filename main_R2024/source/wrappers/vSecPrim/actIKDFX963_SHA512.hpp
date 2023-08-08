

#ifndef ACTIKDFX963SHA512_H
# define ACTIKDFX963SHA512_H

# include "actITypes.hpp"
# include "actISHA2_64.hpp"

# ifdef __cplusplus
extern "C" {
# endif

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actKDFX963_SHA512_Derive(
   VSECPRIM_P2VAR_PARA(actKDFX963SHA512) info,
   VSECPRIM_P2CONST_PARA(actU8) passwd, actLengthType passwd_length,
   VSECPRIM_P2CONST_PARA(actU8) salt, actLengthType salt_length,
   VSECPRIM_P2VAR_PARA(actU8) key, actLengthType key_length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
}
# endif

#endif

