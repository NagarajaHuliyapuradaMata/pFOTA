

#include "ESLib_t.hpp"

#if(VSECPRIM_SPAKE2_P_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CONST_8BIT
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM_EXTERN(eslt_Byte) esl_SPAKE2P_pointM_P256[65];
VSECPRIM_ROM_EXTERN(eslt_Byte) esl_SPAKE2P_pointN_P256[65];

# define VSECPRIM_STOP_SEC_CONST_8BIT
# include "CompilerCfg_vSecPrim.hpp"

#endif

