

#define ACTTDES_SOURCE

#include "actTDES.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"
#include "actConfig.hpp"

#if(VSECPRIM_ACTTDES_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actTDESInit(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len,
   actU8 crypt_mode, VSECPRIM_P2CONST_PARA(actU8) iv,
   actU8 block_mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   info->mode = block_mode;
   info->buffer_used = 0u;
   switch(block_mode){
      case actDES_ECB:
      {
         break;
      }
      case actDES_CBC:
      {
         if(iv == NULL_PTR)
         {
            actMemset(info->prev_block, 0u, actDES_BLOCK_SIZE);
         }
         else
         {
            actMemCpyByteArray(info->prev_block, iv, actDES_BLOCK_SIZE);
         }
         break;
      }
      default:
      {
         return actEXCEPTION_ALGOID;
      }
   }

   return actTDESKeySetup(info, key, key_len, crypt_mode, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actTDESKeySetup(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len,
   actU8 crypt_mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
      info->k1_ptr = key;
      info->k2_ptr = key + 8u;
      if(key_len == 24u)
      {
         info->k3_ptr = key + 16u;
      }
      else
      {
         info->k3_ptr = key;
      }

      if(crypt_mode == EN0)
      {
         actDESKeySetup(&info->k1, info->k1_ptr, EN0, watchdog);
         actDESKeySetup(&info->k2, info->k2_ptr, DE1, watchdog);
         actDESKeySetup(&info->k3, info->k3_ptr, EN0, watchdog);
      }
      else
      {
         actDESKeySetup(&info->k1, info->k3_ptr, DE1, watchdog);
         actDESKeySetup(&info->k2, info->k2_ptr, EN0, watchdog);
         actDESKeySetup(&info->k3, info->k1_ptr, DE1, watchdog);
      }

      return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actTDESInitEncrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8  key_len,
   VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   return actTDESInit(info, key, key_len, EN0, iv, mode, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actTDESEncrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length,
   boolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   actLengthType out_size = (actLengthType)((in_length+info->buffer_used)/actDES_BLOCK_SIZE) * actDES_BLOCK_SIZE;

   if(in_length > (0xFFFFFFFFuL - actDES_BLOCK_SIZE)){
     return actEXCEPTION_LENGTH;
   }

   if(final == FALSE){
      if(*out_length < out_size)
      {
         return actEXCEPTION_LENGTH;
      }
      *out_length = out_size;
   }
   else{
      if(*out_length < (actLengthType)(out_size+actDES_BLOCK_SIZE))
      {
         return actEXCEPTION_LENGTH;
      }
      *out_length = out_size + actDES_BLOCK_SIZE;
   }

   if(in_length > 0u){
      actTDESTransform(info, in, in_length, out_buffer, actTDESEncryptMultipleBlocks, watchdog);
   }

   if(final == TRUE){
      actU8 pad = (actU8)(actDES_BLOCK_SIZE - info->buffer_used);
      actMemset(info->buffer + info->buffer_used, pad, (actLengthType)pad);

      actTDESEncryptMultipleBlocks(info, info->buffer, out_buffer + out_size, 1u, watchdog);
   }

   actL1trigger(watchdog);
   return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actTDESInitDecrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len,
   VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   return actTDESInit(info, key, key_len, DE1, iv, mode, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actTDESDecrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length,
   boolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType total_bytes = (actLengthType)(in_length + info->buffer_used);
  actLengthType out_size;

   if(final == TRUE){
      if((total_bytes == 0u) || ((total_bytes % actDES_BLOCK_SIZE) != 0u))
      {
         return actEXCEPTION_INPUT_LENGTH;
      }
   }

   if(total_bytes > 0u){
     out_size = ((total_bytes-1u) / actDES_BLOCK_SIZE) * actDES_BLOCK_SIZE;
   }
   else{
     out_size = 0u;
   }

   if(*out_length < out_size){
      return actEXCEPTION_LENGTH;
   }

   if(in_length > 0u){
      if(total_bytes <= actDES_BLOCK_SIZE)
      {
         actMemCpyByteArray(info->buffer + info->buffer_used, in, (actLengthType)in_length);
         info->buffer_used += in_length;
      }
      else
      {
         if((total_bytes % actDES_BLOCK_SIZE) == 0u)
         {
            actTDESTransform(info, in, (actLengthType) (in_length-actDES_BLOCK_SIZE), out_buffer, actTDESDecryptMultipleBlocks, watchdog);
            actMemCpyByteArray(info->buffer, in + in_length - actDES_BLOCK_SIZE, actDES_BLOCK_SIZE);
            info->buffer_used = actDES_BLOCK_SIZE;
         }
         else
         {
            actTDESTransform(info, in, in_length, out_buffer, actTDESDecryptMultipleBlocks, watchdog);
         }
      }
   }

   if(final == TRUE){
      actTDESDecryptMultipleBlocks(info, info->buffer, info->buffer, 1u, watchdog);
      {
         actU8 unpad = (actU8)(actDES_BLOCK_SIZE - info->buffer[actDES_BLOCK_SIZE-1u]);
         if(unpad >= actDES_BLOCK_SIZE)
         {
            return actEXCEPTION_PADDING;
         }
         else
         {
            if((*out_length) < (out_size+unpad))
            {
               return actEXCEPTION_LENGTH;
            }
            actMemCpyByteArray(out_buffer + out_size, info->buffer, (actLengthType)unpad);
            *out_length = out_size + unpad;
         }
      }
   }
   else{
      *out_length = out_size;
   }

   actL1trigger(watchdog);
   return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actTDESInitEncryptBlock(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   return actTDESKeySetup(info, key, key_len, EN0, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actTDESInitDecryptBlock(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8  key_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   return actTDESKeySetup(info, key, key_len, DE1, watchdog);
}

VSECPRIM_FUNC(void) actTDESCryptBlock(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   actU8 tmp_block[actDES_BLOCK_SIZE];

   actDESCryptBlock(&info->k1, in_block, out_block, watchdog);
   actDESCryptBlock(&info->k2, out_block, tmp_block, watchdog);
   actDESCryptBlock(&info->k3, tmp_block, out_block, watchdog);

}

VSECPRIM_FUNC(void) actTDESEncryptMultipleBlocks(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
   actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   VSECPRIM_P2VAR_PARA(actU8) prev_block = info->prev_block;
   actLengthType i, bcount;

   switch(info->mode){
      case actDES_CBC:
      {
         for (bcount = 0u; bcount < blocks; ++bcount)
         {
            for (i = 0u; i < actDES_BLOCK_SIZE; ++i)
            {
               out_buffer[i] = (actU8)(prev_block[i] ^ *in++);
            }

            actTDESCryptBlock(info, out_buffer, out_buffer, watchdog);

            for (i = 0u; i < actDES_BLOCK_SIZE; ++i)
            {
               prev_block[i] = *out_buffer++;
            }
         }
         break;
      }
      default:
      {
         for (bcount = 0u; bcount < blocks; ++bcount, in += actDES_BLOCK_SIZE, out_buffer += actDES_BLOCK_SIZE)
         {
            actTDESCryptBlock(info, in, out_buffer, watchdog);
         }
         break;
      }
   }
}

VSECPRIM_FUNC(void) actTDESDecryptMultipleBlocks(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
  actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   VSECPRIM_P2VAR_PARA(actU8) prev_block = info->prev_block;
   actLengthType i, bcount;

   switch(info->mode){
      case actDES_CBC:
      {
         for (bcount = 0u; bcount<blocks; ++bcount)
         {
             actTDESCryptBlock(info, in, out_buffer, watchdog);

             for (i = 0u; i < actDES_BLOCK_SIZE; ++i)
             {
                *out_buffer++ ^= prev_block[i];
                 prev_block[i] = *in++;
             }
         }
         break;
      }
      default:
      {
         for (bcount = 0u; bcount < blocks; ++bcount, in += actDES_BLOCK_SIZE, out_buffer += actDES_BLOCK_SIZE)
         {
            actTDESCryptBlock(info, in, out_buffer, watchdog);
         }
         break;
      }
   }
}

VSECPRIM_FUNC(void) actTDESTransform(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, actTDESTransformFctType transform,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType blocks, bytes, diff = 0u;

   if((info->buffer_used > 0u) && (info->buffer_used <= actDES_BLOCK_SIZE)){
      diff = actMin(in_length, (actLengthType)(actDES_BLOCK_SIZE - info->buffer_used));
      actMemCpyByteArray(&info->buffer[info->buffer_used], in, diff);
      info->buffer_used += diff;
      if(info->buffer_used < actDES_BLOCK_SIZE)
      {
         return;
      }
      else
      {
# ifdef actNO_INDIRECT_CALLS
         if(transform == actTDESEncryptMultipleBlocks)
         {
           actTDESEncryptMultipleBlocks(info, info->buffer, out_buffer, 1u, watchdog);
         }
         else
         {
           actTDESDecryptMultipleBlocks(info, info->buffer, out_buffer, 1u, watchdog);
         }
# else
         transform(info, info->buffer, out_buffer, 1u, watchdog);
# endif
         in += diff; out_buffer += actDES_BLOCK_SIZE;
      }
   }

   blocks = (in_length-diff)/actDES_BLOCK_SIZE;
   bytes = actDES_BLOCK_SIZE*blocks;
# ifdef actNO_INDIRECT_CALLS
   if(transform == actTDESEncryptMultipleBlocks){
     actTDESEncryptMultipleBlocks(info, in, out_buffer, blocks, watchdog);
   }
   else{
     actTDESDecryptMultipleBlocks(info, in, out_buffer, blocks, watchdog);
   }
# else
   transform(info, in, out_buffer, blocks, watchdog);
# endif

   info->buffer_used = in_length - (diff + bytes);
   actMemCpyByteArray(info->buffer, in + bytes, (actLengthType)(info->buffer_used));
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif
