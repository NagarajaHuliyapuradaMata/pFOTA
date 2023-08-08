

#define ACTIAEADAES128CCM_SOURCE

#include "actIAESCCM.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTCCM_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actAESCCMEncodeAadLen(
  VSECPRIM_P2CONST_PARA(actAESCCMSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) outBlock,
  VSECPRIM_P2VAR_PARA(actU8) encodingOffset);

VSECPRIM_LOCAL_FUNC(void) actAESCCMConstructBlockB0(
  VSECPRIM_P2CONST_PARA(actAESCCMSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) blockB0,
  VSECPRIM_P2VAR_PARA(actU8) encBlockB0,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actAES128CCMConstructBlock(
  VSECPRIM_P2CONST_PARA(actAESCCMSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) data,
  const actLengthType dataLen,
  VSECPRIM_P2VAR_PARA(actU8) blockOut,
  VSECPRIM_P2VAR_PARA(actLengthType) indexInData,
  boolean isFirstBlock,
  const actLengthType encodedLengthDataLen);

VSECPRIM_LOCAL_FUNC(void) actAESCCMIncrementCounter(
  VSECPRIM_P2VAR_PARA(actU8) block,
  const actLengthType blockLength);

VSECPRIM_LOCAL_FUNC(void) actAESCCMEncodeAadLen(
  VSECPRIM_P2CONST_PARA(actAESCCMSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) outBlock,
  VSECPRIM_P2VAR_PARA(actU8) encodingOffset){
  if(info->aadLen > 0u){
    if(info->aadLen < 0xFF00u){
      outBlock[0] = actGetU8fromU32(info->aadLen, 1u);
      outBlock[1] = (actU8)(info->aadLen);
      *encodingOffset = 2;
    }
    else{
      outBlock[0] = 0xFFu;
      outBlock[1] = 0xFEu;
      actU32toBE(&outBlock[2], info->aadLen);
      *encodingOffset = 6;
    }
  }
  else{
    *encodingOffset = 0u;
  }
}

VSECPRIM_LOCAL_FUNC(void) actAESCCMConstructBlockB0(
  VSECPRIM_P2CONST_PARA(actAESCCMSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) blockB0,
  VSECPRIM_P2VAR_PARA(actU8) encBlockB0,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 lengthBuffer[4];
  actLengthType nonceLength = 15u - (actLengthType)info->lengthFieldSize;
  actLengthType maxIndex = actMax((actAES_BLOCK_SIZE - (actLengthType)info->lengthFieldSize), (actAES_BLOCK_SIZE - 4u));

  actMemClear(blockB0, actAES_BLOCK_SIZE);

  blockB0[0] = ((actU8)8u * ((info->authFieldSize - (actU8)2u) / (actU8)2u)) + info->lengthFieldSize - (actU8)1u;

  if(info->aadLen > 0u){
    blockB0[0] += 64u;
  }

  actMemCpyByteArray(&blockB0[1], info->nonce, nonceLength);

  actU32toBE(lengthBuffer, info->msgLen);
  actMemCpyByteArray(&blockB0[maxIndex], &lengthBuffer[4u - (actAES_BLOCK_SIZE - maxIndex)], actAES_BLOCK_SIZE - maxIndex);

  actAESEncryptBlock(&info->wsAES, blockB0, encBlockB0, watchdog);
}

VSECPRIM_LOCAL_FUNC(void) actAES128CCMConstructBlock(
  VSECPRIM_P2CONST_PARA(actAESCCMSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) data,
  const actLengthType dataLen,
  VSECPRIM_P2VAR_PARA(actU8) blockOut,
  VSECPRIM_P2VAR_PARA(actLengthType) indexInData,
  boolean isFirstBlock,
  const actLengthType encodedLengthDataLen){
  const actU8 * dataWord = data;

  if(isFirstBlock == TRUE){
    actMemCpyByteArray(blockOut, info->dataBlockIn, encodedLengthDataLen);

    if(dataLen >= (actAES_BLOCK_SIZE - encodedLengthDataLen)){
      actMemCpyByteArray(&blockOut[encodedLengthDataLen], dataWord, actAES_BLOCK_SIZE - encodedLengthDataLen);
      *indexInData = actAES_BLOCK_SIZE - encodedLengthDataLen;
    }
    else{
      actMemCpyByteArray(&blockOut[encodedLengthDataLen], dataWord, dataLen);
      actMemClear(&blockOut[encodedLengthDataLen + dataLen], actAES_BLOCK_SIZE - encodedLengthDataLen - dataLen);
    }
  }
  else{
    if((*indexInData + actAES_BLOCK_SIZE) < dataLen){
      actMemCpyByteArray(blockOut, &dataWord[*indexInData], actAES_BLOCK_SIZE);
      *indexInData += actAES_BLOCK_SIZE;
    }
    else{
      actMemCpyByteArray(blockOut, &dataWord[*indexInData], dataLen - *indexInData);
      actMemClear(&blockOut[dataLen - *indexInData], actAES_BLOCK_SIZE - dataLen + *indexInData);
      *indexInData = dataLen - 1u;
    }
  }

}

VSECPRIM_LOCAL_FUNC(void) actAESCCMIncrementCounter(
  VSECPRIM_P2VAR_PARA(actU8) block,
  const actLengthType blockLength){
  uint32 i = blockLength;
  actU8 result;

  while (i != 0u){
    i--;

    ++block[i];
    result = block[i];

    if(result != 0u){
      break;
    }
  }
}

VSECPRIM_FUNC(void) actAESCCMInit(
  VSECPRIM_P2VAR_PARA(actAESCCMSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key,
  const actLengthType keyLength,
  VSECPRIM_P2CONST_PARA(actU8) nonce,
  const actLengthType nonceLength,
  const actLengthType aadLength,
  const actLengthType msgLength,
  const actU8 authenticationFieldSize,
  const actU8 lengthFieldSize,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  (void)actAESInitEncryptBlock(&info->wsAES, key, keyLength, watchdog);

  actMemClear(info->AESCounter, actAES_BLOCK_SIZE);

  actMemCpyByteArray(info->nonce, nonce, nonceLength);
  actMemClear(&info->nonce[nonceLength], actAES_BLOCK_SIZE - 1u - nonceLength);

  info->aadLen = aadLength;
  info->msgLen = msgLength;
  info->authFieldSize = authenticationFieldSize;
  info->lengthFieldSize = lengthFieldSize;

  info->updateState = actAESCCM_UPDATE_NOT_CALLED;

  actL1trigger(watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actAESCCMUpdateEncrypt(
  VSECPRIM_P2VAR_PARA(actAESCCMSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) aad,
  const actLengthType aadLength,
  VSECPRIM_P2CONST_PARA(actU8) msg,
  const actLengthType msgLength,
  VSECPRIM_P2VAR_PARA(actU8) out,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;

  actU8 j, encodingOffset;
  actLengthType i, numberAadBlocks, numberMsgBlocks;

  actU8 * block = info->dataBlockIn;

  actLengthType indexInData = 0u;
  actLengthType remainingLength = info->msgLen;
  actLengthType nonceLength = 15u - (actLengthType)info->lengthFieldSize;

  if(info->updateState == actAESCCM_UPDATE_CALLED){
    retVal = actEXCEPTION_MODE;
  }
  else if((aadLength != info->aadLen) || (msgLength != info->msgLen)){
    retVal = actEXCEPTION_INPUT_LENGTH;
  }
  else{
    actAESCCMConstructBlockB0(info, block, info->dataBlockOut, watchdog);

    actAESCCMEncodeAadLen(info, block, &encodingOffset);

    if((info->aadLen + encodingOffset + actAES_BLOCK_SIZE - 1u) < info->aadLen){
      retVal = actEXCEPTION_LENGTH;
    }
    else{
      numberAadBlocks = (info->aadLen + encodingOffset + actAES_BLOCK_SIZE - 1u) / actAES_BLOCK_SIZE;
      numberMsgBlocks = (info->msgLen) / actAES_BLOCK_SIZE;

      for (i = 0u; i < numberAadBlocks; i++)
      {
        actAES128CCMConstructBlock(info, aad, info->aadLen, info->dataBlockB, &indexInData, (i == 0u) ? TRUE : FALSE, encodingOffset);

        for (j = 0u; j < actAES_BLOCK_SIZE; j++)
        {
          block[j] = info->dataBlockOut[j] ^ info->dataBlockB[j];
        }

        actAESEncryptBlock(&info->wsAES, block, info->dataBlockOut, watchdog);
      }

      info->AESCounter[0] = info->lengthFieldSize - (actU8)1u;
      actMemCpyByteArray(&info->AESCounter[1], info->nonce, nonceLength);

      for (i = 0u; i < numberMsgBlocks; i++)
      {
        actAESCCMIncrementCounter(&info->AESCounter[nonceLength + 1u], actAES_BLOCK_SIZE - nonceLength - 1u);
        actAESEncryptBlock(&(info->wsAES), info->AESCounter, info->dataBlockB, watchdog);

        for (j = 0u; j < actAES_BLOCK_SIZE; j++)
        {
          block[j] = info->dataBlockOut[j] ^ msg[(actAES_BLOCK_SIZE * i) + j];

          out[(actAES_BLOCK_SIZE*i) + j] = msg[(actAES_BLOCK_SIZE * i) + j] ^ info->dataBlockB[j];
        }

        actAESEncryptBlock(&info->wsAES, block, info->dataBlockOut, watchdog);
        remainingLength -= actAES_BLOCK_SIZE;
      }

      actMemCpyByteArray(info->dataBlockIn, &msg[info->msgLen - remainingLength], remainingLength);
      info->remainingLen = remainingLength;
      info->updateState = actAESCCM_UPDATE_CALLED;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actAESCCMUpdateDecrypt(
  VSECPRIM_P2VAR_PARA(actAESCCMSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) aad,
  const actLengthType aadLength,
  VSECPRIM_P2CONST_PARA(actU8) msg,
  const actLengthType msgLength,
  VSECPRIM_P2VAR_PARA(actU8) out,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;

  actU8 j, encodingOffset;
  actLengthType i, numberAadBlocks, numberMsgBlocks;
  actLengthType indexInData = 0u;

  actU8 * block = info->dataBlockIn;
  actLengthType remainingLength = info->msgLen;
  actLengthType nonceLength = 15u - (actLengthType)info->lengthFieldSize;

  if(info->updateState == actAESCCM_UPDATE_CALLED){
    retVal = actEXCEPTION_MODE;
  }
  else if((aadLength != info->aadLen) || (msgLength != info->msgLen)){
    retVal = actEXCEPTION_INPUT_LENGTH;
  }
  else{
    actAESCCMConstructBlockB0(info, block, info->dataBlockOut, watchdog);

    actAESCCMEncodeAadLen(info, block, &encodingOffset);

    if((info->aadLen + encodingOffset + actAES_BLOCK_SIZE - 1u) < info->aadLen){
      retVal = actEXCEPTION_LENGTH;
    }
    else{
      numberAadBlocks = (info->aadLen + encodingOffset + actAES_BLOCK_SIZE - 1u) / actAES_BLOCK_SIZE;
      numberMsgBlocks = (info->msgLen) / actAES_BLOCK_SIZE;

      for (i = 0u; i < numberAadBlocks; i++)
      {
        actAES128CCMConstructBlock(info, aad, info->aadLen, info->dataBlockB, &indexInData, (i == 0u) ? TRUE : FALSE, encodingOffset);

        for (j = 0u; j < actAES_BLOCK_SIZE; j++)
        {
          block[j] = info->dataBlockOut[j] ^ info->dataBlockB[j];
        }

        actAESEncryptBlock(&info->wsAES, block, info->dataBlockOut, watchdog);
      }

      info->AESCounter[0] = info->lengthFieldSize - (actU8)1u;
      actMemCpyByteArray(&(info->AESCounter[1]), info->nonce, nonceLength);

      for (i = 0u; i < numberMsgBlocks; i++)
      {
        actAESCCMIncrementCounter(&info->AESCounter[nonceLength + 1u], actAES_BLOCK_SIZE - nonceLength - 1u);
        actAESEncryptBlock(&(info->wsAES), info->AESCounter, block, watchdog);

        for (j = 0; j < actMin(actAES_BLOCK_SIZE, remainingLength); j++)
        {
          out[(actAES_BLOCK_SIZE*i) + j] = msg[(actAES_BLOCK_SIZE * i) + j] ^ block[j];
        }

        for (j = 0u; j < actAES_BLOCK_SIZE; j++)
        {
          block[j] = out[(actAES_BLOCK_SIZE*i) + j] ^ info->dataBlockOut[j];
        }

        actAESEncryptBlock(&info->wsAES, block, info->dataBlockOut, watchdog);
        remainingLength -= actAES_BLOCK_SIZE;
      }

      actMemCpyByteArray(info->dataBlockIn, &msg[info->msgLen - remainingLength], remainingLength);
      info->remainingLen = remainingLength;
      info->updateState = actAESCCM_UPDATE_CALLED;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actAESCCMFinalizeEncrypt(
  VSECPRIM_P2VAR_PARA(actAESCCMSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) out,
  VSECPRIM_P2VAR_PARA(actU8) tag,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;
  actU8 j;
  actU8 * block = info->dataBlockB;
  actLengthType remainingLength = info->remainingLen;
  actLengthType nonceLength = 15u - (actLengthType)info->lengthFieldSize;

  if(remainingLength > actAES_BLOCK_SIZE){
    retVal = actEXCEPTION_LENGTH;
  }
  else{
    if(remainingLength > 0u){
      actMemClear(&info->dataBlockIn[remainingLength], actAES_BLOCK_SIZE - remainingLength);

      for (j = 0; j < actAES_BLOCK_SIZE; j++)
      {
        block[j] = info->dataBlockOut[j] ^ info->dataBlockIn[j];
      }

      actAESEncryptBlock(&(info->wsAES), block, info->dataBlockOut, watchdog);
    }

    actMemCpyByteArray(info->MAC, info->dataBlockOut, info->authFieldSize);

    actAESCCMIncrementCounter(&info->AESCounter[nonceLength + 1u], actAES_BLOCK_SIZE - nonceLength - 1u);
    actAESEncryptBlock(&(info->wsAES), info->AESCounter, info->dataBlockOut, watchdog);

    for (j = 0; j < remainingLength; j++){
      out[j] = info->dataBlockIn[j] ^ info->dataBlockOut[j];
    }

    actMemClear(info->AESCounter, actAES_BLOCK_SIZE);
    info->AESCounter[0] = info->lengthFieldSize - (actU8)1u;
    actMemCpyByteArray(&info->AESCounter[1], info->nonce, nonceLength);

    actAESEncryptBlock(&(info->wsAES), info->AESCounter, info->dataBlockOut, watchdog);

    for (j = 0; j < info->authFieldSize; j++){
      tag[j] = info->MAC[j] ^ info->dataBlockOut[j];
    }

    retVal = actOK;
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actAESCCMFinalizeDecrypt(
  VSECPRIM_P2VAR_PARA(actAESCCMSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) out,
  VSECPRIM_P2VAR_PARA(actU8) tag,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;
  actU8 j;
  actU8 * block = info->dataBlockB;
  actLengthType remainingLength = info->remainingLen;
  actLengthType nonceLength = 15u - (actLengthType)info->lengthFieldSize;

  if(remainingLength > actAES_BLOCK_SIZE){
    retVal = actEXCEPTION_LENGTH;
  }
  else{
    if(remainingLength > 0u){
      actAESCCMIncrementCounter(&info->AESCounter[nonceLength + 1u], actAES_BLOCK_SIZE - nonceLength - 1u);
      actAESEncryptBlock(&(info->wsAES), info->AESCounter, info->dataBlockB, watchdog);

      for (j = 0; j < remainingLength; j++)
      {
        info->dataBlockIn[j] ^= info->dataBlockB[j];
      }

      actMemCpyByteArray(out, info->dataBlockIn, remainingLength);

      actMemClear(&info->dataBlockIn[remainingLength], actAES_BLOCK_SIZE - remainingLength);

      for (j = 0; j < actAES_BLOCK_SIZE; j++)
      {
        block[j] = info->dataBlockIn[j] ^ info->dataBlockOut[j];
      }

      actAESEncryptBlock(&(info->wsAES), block, info->dataBlockOut, watchdog);
    }

    actMemCpyByteArray(info->MAC, info->dataBlockOut, info->authFieldSize);

    actMemClear(info->AESCounter, actAES_BLOCK_SIZE);
    info->AESCounter[0] = info->lengthFieldSize - (actU8)1u;
    actMemCpyByteArray(&info->AESCounter[1], info->nonce, nonceLength);

    actAESEncryptBlock(&(info->wsAES), info->AESCounter, info->dataBlockOut, watchdog);

    for (j = 0; j < info->authFieldSize; j++){
      tag[j] = info->MAC[j] ^ info->dataBlockOut[j];
    }

    retVal = actOK;
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

