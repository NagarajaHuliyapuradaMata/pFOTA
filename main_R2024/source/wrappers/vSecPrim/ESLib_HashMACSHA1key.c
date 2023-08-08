

#define ESLIB_HASHMACSHA1KEY_SOURCE

#include "ESLib.hpp"

#include "actIHashMAC.hpp"

#if(VSECPRIM_HMAC_SHA1_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyHashMACSHA1(const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  return esl_getBytesRNG(keyLength, key);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

