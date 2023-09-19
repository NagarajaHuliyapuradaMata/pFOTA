

#define ACTKDFX963_SHA512_SOURCE

#include "actIKDFX963_SHA512.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTKDFX963SHA512_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actKDFX963_SHA512_Derive(
  VSECPRIM_P2VAR_PARA(actKDFX963SHA512) info
   ,  VSECPRIM_P2CONST_PARA(actU8) passwd, actLengthType passwd_length
   ,  VSECPRIM_P2CONST_PARA(actU8) salt, actLengthType salt_length
   ,  VSECPRIM_P2VAR_PARA(actU8) key, actLengthType key_length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) sha = &info->actwsHash;

  actU8   counter[4];
  actLengthType     blocks, remain, b;

  blocks = (key_length + actHASH_SIZE_SHA512 - 1u) / actHASH_SIZE_SHA512;
  remain = key_length % actHASH_SIZE_SHA512;

  for(b = 1u; b <= blocks; ++b) {
    actU32toBE(counter, (actU32)b);

    (void)actSHA512Init(sha);
    (void)actSHA512Update(sha, passwd, passwd_length, watchdog);
    (void)actSHA512Update(sha, counter, sizeof(counter), watchdog);
    (void)actSHA512Update(sha, salt, salt_length, watchdog);

    if((b != blocks)
      || (0u == remain)) {
      (void)actSHA512Finalize(sha, &key[actHASH_SIZE_SHA512 * (b - 1u)], watchdog);
    }
    else{
      (void)actSHA512Finalize(sha, info->hashBuf, watchdog);
      actMemCpyByteArray(&key[actHASH_SIZE_SHA512 * (b - 1u)], info->hashBuf, remain);
    }
  }

}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif
