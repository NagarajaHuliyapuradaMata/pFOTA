

#define ESLIB_HASHMACSHA384KEY_SOURCE

#include "ESLib.hpp"

#include "actIHashMACSHA384.hpp"

#if(VSECPRIM_HMAC_SHA2_384_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyHashMACSHA384(const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  return esl_getBytesRNG(keyLength, key);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

