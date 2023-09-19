

#define ACTCMACAES_SOURCE

#include "actICMACAES.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTCMACAES_ENABLED == STD_ON)

#define CMAC_CONST_RB                                                (0x87u)

#define CMAC_MSB                                                     (0x80u)

#define CMAC_NOT_FINAL                                               (0x00u)

#define CMAC_FINAL                                                   (0x01u)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actCMACAESProcess(
  VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actLengthType length
   ,  actU8 final
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actCMACAESGenerateSubKey(
  VSECPRIM_P2CONST_PARA(actCMACAESSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) subKey
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actCMACAESProcess(
  VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actLengthType length
   ,  actU8 final
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE result = actOK;

  actLengthType used;
  actLengthType xorLength;
  actLengthType offset = 0u;
  actLengthType rest = length;
  boolean processLastBlock = FALSE;

  if(final == CMAC_NOT_FINAL){
    used = info->buffer_used;
  }
  else{
    processLastBlock = TRUE;
    used = 0u;
  }

  while((rest > 0u) || (processLastBlock == TRUE)){
    if(used == actAES_BLOCK_SIZE){
      actAESEncryptBlock(info, info->buffer, info->buffer, watchdog);
      used = 0u;
      processLastBlock = FALSE;
    }
    else{
      xorLength = actMin(actAES_BLOCK_SIZE - used, rest);

      actXOR(&info->buffer[used], &dataIN[offset], (actU32)xorLength);

      used += xorLength;
      offset += xorLength;
      rest -= xorLength;
    }
  }

  info->buffer_used = used;

  return result;
}

VSECPRIM_LOCAL_FUNC(void) actCMACAESGenerateSubKey(
  VSECPRIM_P2CONST_PARA(actCMACAESSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) subKey
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 msb;
  actU8 index;
  actU8 keyIndex;
  actU8 keyCount;

  actMemset(subKey, 0u, actAES_BLOCK_SIZE);
  actAESEncryptBlock(info, subKey, subKey, watchdog);

  if(info->buffer_used == actAES_BLOCK_SIZE){
    keyCount = 1u;
  }
  else{
    keyCount = 2u;
  }

  for(keyIndex = 0u; keyIndex < keyCount; keyIndex++){
    msb = subKey[0] & CMAC_MSB;

    for(index = 0; index < (actAES_BLOCK_SIZE - 1u); index++){
      subKey[index] = (actU8) (((subKey[index] << 1) | (subKey[index + 1u] >> 7)) & 0xFFu);
    }

    subKey[index] = (actU8) ((subKey[index] << 1) & 0xFFu);

    if(msb != 0u){
      subKey[index] ^= CMAC_CONST_RB;
    }
  }
}

VSECPRIM_FUNC(actRETURNCODE) actCMACAESInit (
   VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE result;

  result = actAESInitEncryptBlock(info, key, key_length, watchdog);

  actMemset(info->buffer, 0u, actAES_BLOCK_SIZE);
  info->buffer_used = 0u;

  return result;
}

VSECPRIM_FUNC(actRETURNCODE) actCMACAESUpdate (
   VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actCMACAESProcess(info, dataIN, length, CMAC_NOT_FINAL, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actCMACAESFinalize (
   VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) info, VSECPRIM_P2VAR_PARA(actU8) mac
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actU8) subKey;
  actRETURNCODE result;
  actLengthType used;

  subKey = info->prev_block;
  used = info->buffer_used;

  actCMACAESGenerateSubKey(info, subKey, watchdog);

  if(used < actAES_BLOCK_SIZE){
    subKey[used] ^= CMAC_MSB;
  }

  result = actCMACAESProcess(info, subKey, actAES_BLOCK_SIZE, CMAC_FINAL, watchdog);

  actMemCpyByteArray(mac, info->buffer, actAES_BLOCK_SIZE);

  return result;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

