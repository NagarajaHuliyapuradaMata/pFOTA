

#define ACTKDFX963_SHA256_SOURCE

#include "actIKDFX963_SHA256.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTKDFX963SHA256_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actKDFX963_SHA256_Derive(
  VSECPRIM_P2VAR_PARA(actKDFX963SHA256) info
   ,  VSECPRIM_P2CONST_PARA(actU8) passwd, actLengthType passwd_length
   ,  VSECPRIM_P2CONST_PARA(actU8) salt, actLengthType salt_length
   ,  VSECPRIM_P2VAR_PARA(actU8) key, actLengthType key_length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) sha = &info->actwsHash;

  actU8   counter[4];
  actLengthType     blocks, remain, b;

  blocks = (key_length + actHASH_SIZE_SHA256 - 1u) / actHASH_SIZE_SHA256;
  remain = key_length % actHASH_SIZE_SHA256;

  for(b = 1u; b <= blocks; ++b) {
    actU32toBE(counter, (actU32)b);

    (void)actSHA256Init(sha);
    (void)actSHA256Update(sha, passwd, passwd_length, watchdog);
    (void)actSHA256Update(sha, counter, sizeof(counter), watchdog);
    (void)actSHA256Update(sha, salt, salt_length, watchdog);

    if((b != blocks)
      || (0u == remain)) {
      (void)actSHA256Finalize(sha, &key[actHASH_SIZE_SHA256 * (b - 1u)], watchdog);
    }
    else{
      (void)actSHA256Finalize(sha, info->hashBuf, watchdog);
      actMemCpyByteArray(&key[actHASH_SIZE_SHA256 * (b - 1u)], info->hashBuf, remain);
    }
  }

}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif
