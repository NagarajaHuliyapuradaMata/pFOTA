

#define ACTHASHMACRMD160_SOURCE

#include "actIHashMACRMD160.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTHASHMACRMD160_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actHashMACRMD160Init(
   VSECPRIM_P2VAR_PARA(actHASHMACRMD160STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   VSECPRIM_P2VAR_PARA(actRMD160STRUCT) rmd160 = &info->rmd160;
   VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->rmd160.buffer;
   actRETURNCODE retVal = actOK;
   actLengthType i;

   if(key_length < 1u){
      retVal = actEXCEPTION_LENGTH;
   }
   else if(key_length <= actHASH_BLOCK_SIZE_RMD160){
      actMemCpyByteArray(info->key_buf, key, key_length);
      info->key_length = key_length;
   }
   else{
      (void)actRMD160Init(rmd160);
      (void)actRMD160Update(rmd160, key, key_length, watchdog);
      (void)actRMD160Finalize(rmd160, info->key_buf, watchdog);
      info->key_length = actHASH_SIZE_RMD160;
   }

   if(retVal == actOK){
     actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length));
     actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_RMD160 - info->key_length));
     for (i = 0u; i < actHASH_BLOCK_SIZE_RMD160; ++i)
     {
       tmp_block[i] ^= (actU8)(0x36u);
     }

     (void)actRMD160Init(rmd160);
     (void)actRMD160Update(rmd160, tmp_block, actHASH_BLOCK_SIZE_RMD160, watchdog);
   }

   return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actHashMACRMD160Update(
   VSECPRIM_P2VAR_PARA(actHASHMACRMD160STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   return actRMD160Update(&info->rmd160, dataIN, length, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actHashMACRMD160Finalize(
   VSECPRIM_P2VAR_PARA(actHASHMACRMD160STRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   VSECPRIM_P2VAR_PARA(actRMD160STRUCT) rmd160 = &info->rmd160;
   VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->rmd160.buffer;
   actLengthType i;

   (void)actRMD160Finalize(rmd160, hash, watchdog);

   actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length));
   actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_RMD160 - info->key_length));
   for (i=0u; i < actHASH_BLOCK_SIZE_RMD160; ++i){
      tmp_block[i] ^= (actU8)(0x5cu);
   }

   (void)actRMD160Init(rmd160);
   (void)actRMD160Update(rmd160, tmp_block, actHASH_BLOCK_SIZE_RMD160, watchdog);
   (void)actRMD160Update(rmd160, hash, actHASH_SIZE_RMD160, watchdog);
   (void)actRMD160Finalize(rmd160, hash, watchdog);

   return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif
