

#define ACTHASHMAC_SOURCE

#include "actIHashMAC.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTHASHMAC_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actHashMACInit(
   VSECPRIM_P2VAR_PARA(actHASHMACSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) sha = &info->sha;
  VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->sha.buffer;
  actRETURNCODE retVal = actOK;
  actLengthType i;

  if(key_length < 1u){
    retVal = actEXCEPTION_LENGTH;
  }
  else if(key_length <= actHASH_BLOCK_SIZE_SHA){
    actMemCpyByteArray(info->key_buf, key, key_length);
    info->key_length = key_length;
  }
  else{
    (void)actSHAInit(sha);
    (void)actSHAUpdate(sha, key, key_length, watchdog);
    (void)actSHAFinalize(sha, info->key_buf, watchdog);
    info->key_length = actHASH_SIZE_SHA;
  }

  if(retVal == actOK){
    actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length));
    actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_SHA - info->key_length));
    for (i = 0u; i < actHASH_BLOCK_SIZE_SHA; ++i){
      tmp_block[i] ^= (actU8)(0x36u);
    }

    (void)actSHAInit(sha);
    (void)actSHAUpdate(sha, tmp_block, actHASH_BLOCK_SIZE_SHA, watchdog);
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actHashMACUpdate(
   VSECPRIM_P2VAR_PARA(actHASHMACSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHAUpdate(&info->sha, dataIN, length, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actHashMACFinalize(
   VSECPRIM_P2VAR_PARA(actHASHMACSTRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) sha = &info->sha;
  VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->sha.buffer;
   actLengthType i;

  (void)actSHAFinalize(sha, hash, watchdog);

  actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length));
  actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_SHA - info->key_length));
  for (i = 0u; i < actHASH_BLOCK_SIZE_SHA; ++i){
    tmp_block[i] ^= (actU8)(0x5cu);
  }

  (void)actSHAInit(sha);
  (void)actSHAUpdate(sha, tmp_block, actHASH_BLOCK_SIZE_SHA, watchdog);
  (void)actSHAUpdate(sha, hash, actHASH_SIZE_SHA, watchdog);
  (void)actSHAFinalize(sha, hash, watchdog);

  return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

