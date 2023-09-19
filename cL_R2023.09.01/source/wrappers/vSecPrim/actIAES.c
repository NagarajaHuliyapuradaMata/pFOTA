

#define ACTIAES_SOURCE

#include "actIAES.hpp"
#include "actAES.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"
#include "actConfig.hpp"

#if(VSECPRIM_ACTIAES_ENABLED == STD_ON)

#define actAES_WORD_SIZE                                             (4u)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actAESInitEncryptBlock(
  VSECPRIM_P2VAR_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actAESKeySetup(info, key, key_len, watchdog);
}

VSECPRIM_FUNC(void) actAESEncryptBlock(
   VSECPRIM_P2CONST_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2CONST_PARA(actU32) k_ptr = info->e_key;
  actU32 b0[4], b1[4];
  actLengthType i, iterations = 4u + ((info->key_dword_len - 4u) / 2u);

  actL1trigger(watchdog);

  actCpyLEtoU32(b0, in_block, actAES_BLOCK_SIZE);

  for(i = 0u; i < 4u; ++i){
    b0[i] ^= k_ptr[i];

  }
  k_ptr = &k_ptr[4];
  for(i = 0u; i < iterations; ++i){
    actAESEncryptionRound(b1, b0, k_ptr);
    k_ptr = &k_ptr[4];
    actAESEncryptionRound(b0, b1, k_ptr);
    k_ptr = &k_ptr[4];
    actL2trigger(watchdog);
  }
  actAESEncryptionRound(b1, b0, k_ptr);
  k_ptr = &k_ptr[4];
  actAESEncryptionFinalRound(b0, b1, k_ptr);

  actCpyU32toLE (out_block, b0, actAES_BLOCK_SIZE /actAES_WORD_SIZE);

  actL1trigger(watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actAESInitDecryptBlock(
   VSECPRIM_P2VAR_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE result = actAESKeySetup(info, key, key_len, watchdog);

  if(result == actOK){
    actAESMakeDecryptionKey(info);
  }

  return result;
}

VSECPRIM_FUNC(void) actAESDecryptBlock(
   VSECPRIM_P2CONST_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2CONST_PARA(actU32) k_ptr = &info->e_key[((4u * info->key_dword_len) + 20u)];
  actU32 b0[4], b1[4];
  actLengthType i, iterations = 4u + ((info->key_dword_len - 4u) / 2u);
  actLengthType arrayIndex = ((4u * info->key_dword_len) + 20u);

  actL1trigger(watchdog);

  actCpyLEtoU32 (b0, in_block, actAES_BLOCK_SIZE);

  for(i = 0u; i < 4u; ++i){
    b0[i] ^= k_ptr[i + 4u];
  }
  for(i = 0u; i < iterations; ++i){
    actAESDecryptionRound(b1, b0, k_ptr);
    arrayIndex -= 4u;
    k_ptr = &info->e_key[arrayIndex];
    actAESDecryptionRound(b0, b1, k_ptr);
    arrayIndex -= 4u;
    k_ptr = &info->e_key[arrayIndex];
    actL2trigger(watchdog);
  }
  actAESDecryptionRound(b1, b0, k_ptr);
  arrayIndex -= 4u;
  k_ptr = &info->e_key[arrayIndex];
  actAESDecryptionFinalRound(b0, b1, k_ptr);

  actCpyU32toLE(out_block, b0, actAES_BLOCK_SIZE /actAES_WORD_SIZE);

  actL1trigger(watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actAESInitEncrypt(
   VSECPRIM_P2VAR_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len, VSECPRIM_P2CONST_PARA(actU8) iv
   ,  actU8 mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE result;

  result = actPaddingInit(mode & actPADDING_PM_MASK);

  if(result == actOK){
    result = actAESInit(info, key, key_len, iv, mode, watchdog);
  }

  return result;
}

VSECPRIM_FUNC(actRETURNCODE) actAESEncrypt(
  VSECPRIM_P2VAR_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length
   ,  VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length
   ,  actBoolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE result = actOK;

  actLengthType out_size = ((in_length + info->buffer_used) / actAES_BLOCK_SIZE) * actAES_BLOCK_SIZE;

  if(in_length > (0xFFFFFFFFuL - actAES_BLOCK_SIZE)){
    result = actEXCEPTION_LENGTH;
  }
  else if((final == TRUE) && ((info->mode & actAES_BM_MASK) == actAES_BM_CTR) && ((info->mode & actPADDING_PM_MASK) == actPADDING_PM_OFF)){
    if(*out_length < info->buffer_used){
      result = actEXCEPTION_LENGTH;
    }
    else{
      *out_length = info->buffer_used;
    }
  }
  else if((final == FALSE) || ((info->mode & actPADDING_PM_MASK) == actPADDING_PM_OFF)){
    if(*out_length < out_size){
      result = actEXCEPTION_LENGTH;
    }
    else{
      *out_length = out_size;
    }
  }
  else{
    if(*out_length < (actLengthType) (out_size + actAES_BLOCK_SIZE)){
      result = actEXCEPTION_LENGTH;
    }
    else{
      *out_length = out_size + actAES_BLOCK_SIZE;
    }
  }

  if(result == actOK){
    if(in_length > 0u){
      actAESTransform(info, in, in_length, out_buffer, actAESEncryptMultipleBlocks, watchdog);
    }

    if(final == TRUE){
      if(((info->mode & actAES_BM_MASK) != actAES_BM_CTR) || ((info->mode & actPADDING_PM_MASK) != actPADDING_PM_OFF))
      {
        result = actPaddingPad(info->mode & actPADDING_PM_MASK, actAES_BLOCK_SIZE, &(info->buffer_used), info->buffer);
      }

      if((result == actOK) && (info->buffer_used > 0u))
      {
        actAESEncryptMultipleBlocks(info, info->buffer, &out_buffer[out_size], 1, watchdog);
      }
    }

    actL1trigger(watchdog);
  }

  return result;
}

VSECPRIM_FUNC(actRETURNCODE) actAESInitDecrypt(
   VSECPRIM_P2VAR_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len, VSECPRIM_P2CONST_PARA(actU8) iv
   ,  actU8 mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE result;

  result = actPaddingInit(mode & actPADDING_PM_MASK);

  if(result == actOK){
    result = actAESInit(info, key, key_len, iv, mode, watchdog);

    if(result == actOK){
      if((info->mode & actAES_BM_MASK) != actAES_BM_CTR)
      {
        actAESMakeDecryptionKey(info);
      }
    }
  }

  return result;
}

VSECPRIM_FUNC(actRETURNCODE) actAESDecrypt(
  VSECPRIM_P2VAR_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length
   ,  VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length
   ,  actBoolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE result = actOK;
  actLengthType total_bytes = in_length + info->buffer_used;
  actLengthType out_size;

  if(final == TRUE){
     if(((info->mode & actAES_BM_MASK) != actAES_BM_CTR) || ((info->mode & actPADDING_PM_MASK) != actPADDING_PM_OFF))
     {
       if((total_bytes == 0u) || ((total_bytes % actAES_BLOCK_SIZE) != 0u))
       {
         result = actEXCEPTION_INPUT_LENGTH;
       }
     }
  }

  if(result == actOK){
    if(total_bytes > 0u){
      out_size = ((total_bytes - 1u) / actAES_BLOCK_SIZE) * actAES_BLOCK_SIZE;
    }
    else{
      out_size = 0u;
    }

    if(*out_length < out_size){
      result = actEXCEPTION_LENGTH;
    }

    if(result == actOK){
      if(in_length > 0u)
      {
        if(total_bytes <= actAES_BLOCK_SIZE)
        {
          actMemCpyByteArray(&info->buffer[info->buffer_used], in, (actU32)in_length);
          info->buffer_used += in_length;
        }
        else
        {
          if((total_bytes % actAES_BLOCK_SIZE) == 0u)
          {
            actAESTransform(info, in, (actLengthType)(in_length - actAES_BLOCK_SIZE), out_buffer, actAESDecryptMultipleBlocks, watchdog);
            actMemCpyByteArray(info->buffer, &in[(in_length - actAES_BLOCK_SIZE)], actAES_BLOCK_SIZE);
            info->buffer_used = actAES_BLOCK_SIZE;
          }
          else
          {
            actAESTransform(info, in, in_length, out_buffer, actAESDecryptMultipleBlocks, watchdog);
          }
        }
      }

      if(final == TRUE)
      {
        actAESDecryptMultipleBlocks(info, info->buffer, info->buffer, 1u, watchdog);

        if(((info->mode & actAES_BM_MASK) != actAES_BM_CTR) || ((info->mode & actPADDING_PM_MASK) != actPADDING_PM_OFF))
        {
          result = actPaddingUnpad(info->mode & actPADDING_PM_MASK, actAES_BLOCK_SIZE, &(info->buffer_used), info->buffer);
        }

        if(result == actOK)
        {
          if(*out_length < (out_size + info->buffer_used))
          {
            result = actEXCEPTION_LENGTH;
          }
          else
          {
            actMemCpyByteArray(&out_buffer[out_size], info->buffer, info->buffer_used);
            *out_length = out_size + info->buffer_used;
          }
        }
      }
      else
      {
        *out_length = out_size;
      }

      actL1trigger(watchdog);
    }
  }

  return result;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

