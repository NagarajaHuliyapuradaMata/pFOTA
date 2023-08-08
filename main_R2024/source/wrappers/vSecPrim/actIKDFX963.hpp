

#ifndef ACTIKDFX963_H
# define ACTIKDFX963_H

# include "actITypes.hpp"
# include "actISHA.hpp"

# ifdef __cplusplus
extern "C" {
# endif

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actKDFX963Derive(
   VSECPRIM_P2VAR_PARA(actKDFX963STRUCT) info,
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

