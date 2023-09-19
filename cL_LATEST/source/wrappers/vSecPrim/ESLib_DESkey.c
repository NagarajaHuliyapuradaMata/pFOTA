

#define ESLIB_DESKEY_SOURCE

#include "ESLib.hpp"

#include "actDES.hpp"

#if(VSECPRIM_DES_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyDES(VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  return esl_getBytesRNG(ESL_SIZEOF_DES_KEY, key);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

