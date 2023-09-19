

#define ESLIB_RC2KEY_SOURCE

#include "ESLib.hpp"

#include "actRC2.hpp"

#if(VSECPRIM_RC2_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyRC2(VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  return esl_getBytesRNG(ESL_SIZEOF_RC2_KEY, key);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

