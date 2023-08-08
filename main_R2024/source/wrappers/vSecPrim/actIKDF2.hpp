

#ifndef ACTIKDF2_H
# define ACTIKDF2_H

# include "actITypes.hpp"
# include "actIHashMAC.hpp"
# include "actIHashMACSHA256.hpp"

# ifdef __cplusplus
extern "C" {
# endif

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actKDF2Init(VSECPRIM_P2VAR_PARA(actKDF2STRUCT) info, actLengthType iteration_count);

VSECPRIM_FUNC(actRETURNCODE) actKDF2Derive(
  VSECPRIM_P2VAR_PARA(actKDF2STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) passwd, actLengthType passwd_length,
  VSECPRIM_P2CONST_PARA(actU8) salt, actLengthType salt_length,
  VSECPRIM_P2VAR_PARA(actU8) key, actLengthType key_length,
  actU8 hashMACidx, actLengthType sizeSHA);

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
}
# endif

#endif

