

#define ESLIB_HASHMACSHA256KEY_SOURCE

#include "ESLib.hpp"

#include "actIHashMACSHA256.hpp"

#if(VSECPRIM_HMAC_SHA2_256_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyHashMACSHA256(const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  return esl_getBytesRNG(keyLength, key);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

