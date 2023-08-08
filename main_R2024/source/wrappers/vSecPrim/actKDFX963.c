

#define ACTKDFX963_SOURCE

#include "actIKDFX963.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTKDFX963_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actKDFX963Derive(
  VSECPRIM_P2VAR_PARA(actKDFX963STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) passwd, actLengthType passwd_length,
  VSECPRIM_P2CONST_PARA(actU8) salt, actLengthType salt_length,
  VSECPRIM_P2VAR_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) sha = &info->actwsHash;
  VSECPRIM_P2VAR_PARA(actU8) keyPtr = key;
  actU8 counter[4];
  actLengthType l, r, i;

  l = (key_length + actHASH_SIZE_SHA - 1u) / actHASH_SIZE_SHA;
  r = key_length - ((l - 1u) * actHASH_SIZE_SHA);

  for (i = 1u; i <= l; ++i){
    (void)actSHAInit(sha);
    (void)actSHAUpdate(sha, passwd, passwd_length, watchdog);
    actU32toBE(counter, (actU32)i);
    (void)actSHAUpdate(sha, counter, sizeof(counter), watchdog);
    (void)actSHAUpdate(sha, salt, salt_length, watchdog);

    if(i != l){
      (void)actSHAFinalize(sha, &keyPtr[actHASH_SIZE_SHA * (i - 1u)], watchdog);
    }
    else{
      (void)actSHAFinalize(sha, info->hashBuf, watchdog);
      actMemCpyByteArray(&keyPtr[actHASH_SIZE_SHA * (i - 1u)], info->hashBuf, r);
    }
  }

}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif
