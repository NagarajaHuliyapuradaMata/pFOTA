

#define ESLIB_HASHMACRMD160KEY_SOURCE

#include "ESLib.hpp"

#include "actIHashMACRMD160.hpp"

#if(VSECPRIM_HMAC_RMD160_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyHashMACRIPEMD160(const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  return esl_getBytesRNG(keyLength, key);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

