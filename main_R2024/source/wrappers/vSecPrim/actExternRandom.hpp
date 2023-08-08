

#ifndef ACTEXTERNRANDOM_H
# define ACTEXTERNRANDOM_H

# include "actITypes.hpp"
# include "actConfig.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
extern "C" {
# endif

extern VSECPRIM_FUNC(actRETURNCODE) actGetExternRandom(VSECPRIM_P2VAR_PARA(actU8) output, actLengthType length);

# ifdef __cplusplus
}
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

