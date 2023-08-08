

#define ACTGCM_SOURCE

#include "actConfig.hpp"
#include "actIGCM.hpp"
#include "actIGHash.hpp"
#include "actIAES.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTGCM_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actGCMTransformBlock(
  VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) input,
  VSECPRIM_P2VAR_PARA(actU8) output,
  uint8 mode,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actGCMTransformBlock (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) input,
   VSECPRIM_P2VAR_PARA(actU8) output,
   uint8 mode,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType block_len;

  if(info->buffer_used == 0u){
    block_len = actGCM_BLOCK_SIZE;
  }
  else{
    block_len = info->buffer_used;
  }

  if(mode == MODE_DEC){
    (void)actGHashUpdate(&info->ghash, input, block_len, watchdog);
  }

  actU32toBE(&info->J[12], actBEtoU32(&info->J[12]) + 1u);
  actAESEncryptBlock(&info->aes, info->J, info->encJ, watchdog);
  actXOR(info->encJ, input, block_len);
  actMemCpyByteArray(output, info->encJ, block_len);

  if(mode == MODE_ENC){
    (void)actGHashUpdate(&info->ghash, output, block_len, watchdog);
  }
}

VSECPRIM_FUNC(actRETURNCODE) actGCMInit (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key,
   actLengthType key_len,
   VSECPRIM_P2CONST_PARA(actU8) IV,
   actLengthType IV_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actAESSTRUCT) KeyGen   = &info->aes;
  VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) ghash  = &info->ghash;
  VSECPRIM_P2VAR_PARA(actU8) H               =  info->J0;
  VSECPRIM_P2VAR_PARA(actU32) len            =  info->count;

  len[0] = 0;

  len[1] = IV_len * 8u;

  actMemset(H, 0, actGCM_BLOCK_SIZE);
  (void)actAESInitEncryptBlock(KeyGen, key, key_len, watchdog);

  (void)actAESEncryptBlock(KeyGen, H, H, watchdog);

  (void)actGHashInit(ghash, H, watchdog);

  if(IV_len == actGCM_IV_DEFAULT_SIZE){
    actMemCpyByteArray(info->J, IV, IV_len);

    actU32toBE(&info->J[IV_len], 1);
  }
  else{
    (void)actGHashUpdate(ghash, IV, IV_len, watchdog);
    (void)actGHashZeroPad(ghash, watchdog);

    actMemset(&H[0], 0, 8);
    actCpyU32toBE(&H[8], len, 2);

    (void)actGHashUpdate(ghash, H, actGCM_BLOCK_SIZE, watchdog);
    (void)actGHashFinalize(ghash, info->J, watchdog);

    (void)actGHashReset(ghash);
  }

  actAESEncryptBlock(KeyGen, info->J, info->J0, watchdog);

  info->state = STATE_AAD;
  info->buffer_used = 0;
  info->count[AAD_HI] = 0;

  info->count[AAD_LO] = 0;
  info->count[Data_HI] = 0;

  info->count[Data_LO] = 0;

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actGCMTransform (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) input,
   const actLengthType in_len,
   VSECPRIM_P2VAR_PARA(actU8) output,
   VSECPRIM_P2VAR_PARA(actLengthType) bytes_out,
   const uint8 encORdec,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE result = actOK;

  switch(info->state){
    case STATE_AAD:
    {
      actU32 hi = info->count [AAD_HI],
      lo = info->count [AAD_LO];

      lo += (actU32) in_len;
      if(lo < info->count[AAD_LO])
      {
        hi++;
      }

      if(hi > 0x1FFFFFFFuL)
      {
        result = actEXCEPTION_LENGTH;
      }
      else
      {
        info->count[AAD_HI] = hi;
        info->count[AAD_LO] = lo;

        (void)actGHashUpdate(&info->ghash, input, in_len, watchdog);
      }
      break;
    }

    case STATE_CIPHERTEXT:
    {
      boolean isTransformFinished = FALSE;
      actLengthType diff = 0, output_idx = 0;
      actU32 hi = info->count [Data_HI],
      lo = info->count [Data_LO];

      lo += (actU32) in_len;
      if(lo < info->count [Data_LO])
      {
        hi++;
      }

      if((hi >  0x0000000FuL)
        || ((hi == 0x0000000FuL) && (lo > 0xFFFFFFE0uL)))
      {
        isTransformFinished = TRUE;
        result = actEXCEPTION_LENGTH;
      }
      else
      {
        info->count[Data_HI] = hi;
        info->count[Data_LO] = lo;

        if(info->buffer_used > 0u)
        {
          diff = actMin(in_len, (actLengthType)(actGCM_BLOCK_SIZE - info->buffer_used));
          actMemCpyByteArray(&info->buffer[info->buffer_used], input, diff);
          info->buffer_used += diff;
          if(info->buffer_used < actGCM_BLOCK_SIZE)
          {
            isTransformFinished = TRUE;
          }
          else
          {
            actGCMTransformBlock(info, info->buffer, output, encORdec, watchdog);
            output_idx += actGCM_BLOCK_SIZE;
            *bytes_out += actGCM_BLOCK_SIZE;
          }
        }
      }

      if(isTransformFinished == FALSE)
      {
        actLengthType i, blocks, input_idx;

        blocks = (in_len - diff) / actGCM_BLOCK_SIZE;
        input_idx = diff;

        for (i = blocks; i > 0u; --i)
        {
          actGCMTransformBlock(info, &input[input_idx], &output[output_idx], encORdec, watchdog);
          input_idx += actGCM_BLOCK_SIZE;
          output_idx += actGCM_BLOCK_SIZE;
          *bytes_out += actGCM_BLOCK_SIZE;
        }

        info->buffer_used = in_len - (diff + (actGCM_BLOCK_SIZE * blocks));
        actMemCpyByteArray(info->buffer, &input[input_idx], info->buffer_used);
      }
      break;
    }

    default:
      result = actEXCEPTION_UNKNOWN;
      break;
  }

  return result;
}

VSECPRIM_FUNC(actRETURNCODE) actGCMEncryptUpdate (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) X,
   const actLengthType X_len,
   VSECPRIM_P2VAR_PARA(actU8) output,
   VSECPRIM_P2VAR_PARA(actLengthType) bytes_out,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actGCMTransform(info, X, X_len, output, bytes_out, MODE_ENC, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actGCMDecryptUpdate (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) X,
   const actLengthType X_len,
   VSECPRIM_P2VAR_PARA(actU8) output,
   VSECPRIM_P2VAR_PARA(actLengthType) bytes_out,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actGCMTransform(info, X, X_len, output, bytes_out, MODE_DEC, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actGCMTriggerState (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retCode = actEXCEPTION_UNKNOWN;

  if(info->state == STATE_AAD){
    (void)actGHashZeroPad(&info->ghash, watchdog);

    info->state = STATE_CIPHERTEXT;
    retCode = actOK;
  }

  return retCode;
}

VSECPRIM_FUNC(actRETURNCODE) actGMACFinalize (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info,
   VSECPRIM_P2VAR_PARA(actU8) tag,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   VSECPRIM_P2VAR_PARA(actU8) tmp = info->buffer;

  (void)actGHashZeroPad(&info->ghash, watchdog);

  info->count [AAD_HI]  = (info->count [AAD_HI]  << 3) + (info->count [AAD_LO]  >> 31);
  info->count [AAD_LO]  = (info->count [AAD_LO]  << 3);
  info->count [Data_HI] = (info->count [Data_HI] << 3) + (info->count [Data_LO] >> 31);
  info->count [Data_LO] = (info->count [Data_LO] << 3);
  actCpyU32toBE (tmp, info->count, 4);

  (void)actGHashUpdate(&info->ghash, tmp, actGCM_BLOCK_SIZE, watchdog);
  (void)actGHashFinalize(&info->ghash, tmp, watchdog);

  actXOR(tmp, info->J0, actGCM_BLOCK_SIZE);

  actMemCpyByteArray(tag, tmp, actGCM_TAG_LENGTH);

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actGCMEncryptFinalize (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info,
   VSECPRIM_P2VAR_PARA(actU8) output,
   VSECPRIM_P2VAR_PARA(actLengthType) bytes_out,
   VSECPRIM_P2VAR_PARA(actU8) tag,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  if(info->buffer_used > 0u){
    uint8 tmpBuffer[actGCM_BLOCK_SIZE];
    *bytes_out += info->buffer_used;
    actGCMTransformBlock(info, info->buffer, tmpBuffer, MODE_ENC, watchdog);
    actMemCpyByteArray(output, tmpBuffer, info->buffer_used);
  }

  return actGMACFinalize(info, tag, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actGCMDecryptFinalize (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info,
   VSECPRIM_P2VAR_PARA(actU8) output,
   VSECPRIM_P2VAR_PARA(actLengthType) bytes_out,
   VSECPRIM_P2VAR_PARA(actU8) tag,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  if(info->buffer_used > 0u){
    uint8 tmpBuffer[actGCM_BLOCK_SIZE];
    *bytes_out += info->buffer_used;
    actGCMTransformBlock(info, info->buffer, tmpBuffer, MODE_DEC, watchdog);
    actMemCpyByteArray(output, tmpBuffer, info->buffer_used);
  }

  return actGMACFinalize(info, tag, watchdog);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

