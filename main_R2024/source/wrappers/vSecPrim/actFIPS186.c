

#define ACTFIPS186_SOURCE

#include "actFIPS186.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTFIPS186_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) pseudoRandom(
   VSECPRIM_P2VAR_PARA(actFIPS186STRUCT) info, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) pseudoRandom(
  VSECPRIM_P2VAR_PARA(actFIPS186STRUCT) info,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) sha1 = &(info->sha1);
  VSECPRIM_P2VAR_PARA(actU8) X = info->sha1.buffer;
  VSECPRIM_P2VAR_PARA(actU8) X_KEY = info->X_KEY;

  actMemCpyByteArray(X, X_KEY, actFIPS186_BASE_LENGTH);

  if(actOK == actSHAInit(sha1)){
    if(actOK == actSHAUpdate(sha1, (VSECPRIM_P2CONST_PARA(actU8)) X, actHASH_BLOCK_SIZE_SHA, watchdog)){
      actSHAGetDigest(sha1, X, watchdog);

      (void)actAddBE(X_KEY, (VSECPRIM_P2CONST_PARA(actU8))X, actFIPS186_BASE_LENGTH, 1u);

      info->bytes_remain = actFIPS186_BASE_LENGTH;
    }
  }
}

VSECPRIM_FUNC(void) actInitializeFIPS186(VSECPRIM_P2VAR_PARA(actFIPS186STRUCT) info, VSECPRIM_P2CONST_PARA(actU8) seed){
  actMemCpyByteArray(info->X_KEY, seed, actFIPS186_BASE_LENGTH);
  actMemset(info->sha1.buffer, 0u, actHASH_BLOCK_SIZE_SHA);
  info->bytes_remain = 0u;
}

VSECPRIM_FUNC(void) actGetFIPS186(
  VSECPRIM_P2VAR_PARA(actFIPS186STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) output, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2CONST_PARA(actU8) X = info->sha1.buffer;
  actLengthType i = 0u;

  while (i < length){
    if(info->bytes_remain > 0u){
      output[i] = X[actFIPS186_BASE_LENGTH - info->bytes_remain];
      i++;
      info->bytes_remain--;
    }
    else{
      pseudoRandom(info, watchdog);
    }
  }
}

VSECPRIM_FUNC(void) actWriteFIPS186(
  VSECPRIM_P2VAR_PARA(actFIPS186STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) new_seed){
  actU8 i;

  for (i = 0u; i < actFIPS186_BASE_LENGTH; ++i){
    info->X_KEY[i] ^= new_seed[i];
  }
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

