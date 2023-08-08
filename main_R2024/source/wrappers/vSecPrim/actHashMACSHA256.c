

#define ACTHASHMACSHA256_SOURCE

#include "actIHashMACSHA256.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTHASHMACSHA256_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA256Init(
  VSECPRIM_P2VAR_PARA(actHASHMACSHA256STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key,
  actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) sha256 = &info->sha256;
  VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->sha256.buffer;
  actRETURNCODE retVal = actOK;
  actLengthType i;

  if(key_length < 1u){
    retVal = actEXCEPTION_LENGTH;
  }
  else if(key_length <= actHASH_BLOCK_SIZE_SHA256){
    actMemCpyByteArray(info->key_buf, key, key_length);
    info->key_length = key_length;
  }
  else{
    (void)actSHA256Init(sha256);
    (void)actSHA256Update(sha256, key, key_length, watchdog);
    (void)actSHA256Finalize(sha256, info->key_buf, watchdog);
    info->key_length = actHASH_SIZE_SHA256;
  }

  if(retVal == actOK){
    actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length));
    actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_SHA256 - info->key_length));
    for (i = 0u; i < actHASH_BLOCK_SIZE_SHA256; ++i){
      tmp_block[i] ^= (actU8)(0x36u);
    }

    (void)actSHA256Init(sha256);
    (void)actSHA256Update(sha256, tmp_block, actHASH_BLOCK_SIZE_SHA256, watchdog);
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA256Update(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA256STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN,
   actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   return actSHA256Update(&info->sha256, dataIN, length, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA256Finalize(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA256STRUCT) info,
   VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   VSECPRIM_P2VAR_PARA(actSHA256STRUCT) sha256 = &info->sha256;
   VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->sha256.buffer;
   actLengthType i;

   (void)actSHA256Finalize(sha256, hash, watchdog);

   actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length));
   actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_SHA256 - info->key_length));
   for (i=0u; i < actHASH_BLOCK_SIZE_SHA256; ++i){
      tmp_block[i] ^= (actU8)(0x5c);
   }

   (void)actSHA256Init(sha256);
   (void)actSHA256Update(sha256, tmp_block, actHASH_BLOCK_SIZE_SHA256, watchdog);
   (void)actSHA256Update(sha256, hash, actHASH_SIZE_SHA256, watchdog);
   (void)actSHA256Finalize(sha256, hash, watchdog);

   return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

