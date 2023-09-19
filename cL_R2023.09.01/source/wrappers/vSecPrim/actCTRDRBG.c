

#define ACT_CTRDRBG_SOURCE

#include "actIDRBG.hpp"
#include "actDRBGCommon.hpp"
#include "actIAES.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTCTRDRBG_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, actU8) tempKey[actCTRDRBG_AES256_KEY_LEN] =
{
  0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u, 0x09u, 0x0Au, 0x0Bu, 0x0Cu, 0x0Du, 0x0Eu, 0x0Fu
   ,  0x10u, 0x11u, 0x12u, 0x13u, 0x14u, 0x15u, 0x16u, 0x17u, 0x18u, 0x19u, 0x1Au, 0x1Bu, 0x1Cu, 0x1Du, 0x1Eu, 0x1Fu
};

#define VSECPRIM_STOP_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_INLINE_FUNC(void) actAesCtrDrbgConstructS(
  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) inputString
   ,  VSECPRIM_P2VAR_PARA(actU8) outputString
   ,  actLengthType inputStringLength
   ,  VSECPRIM_P2VAR_PARA(actU8) nextElement
   ,  VSECPRIM_P2VAR_PARA(actLengthType) nextIndex
   ,  actLengthType numberOfBytesToReturn
   ,  boolean isFirstBlock);

VSECPRIM_LOCAL_INLINE_FUNC(void) actAesCtrDrbgBcc(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2CONST_PARA(actU8) IV
   ,  actLengthType Slength
   ,  actLengthType totalInputLength
   ,  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) inputString
   ,  VSECPRIM_P2VAR_PARA(actU8) outputString
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actAesCtrDrbgEncryptBlock(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2VAR_PARA(actU8) outputData
   ,  actLengthType dataLength
   ,  actLengthType keyLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actAesCtrDrbgBlockUpdate(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2CONST_PARA(actU8) inputData
   ,  actLengthType keyLength
   ,  actLengthType seedLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actAesCtrDrbgDF(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) inputString
   ,  VSECPRIM_P2VAR_PARA(actU8) outputString
   ,  actLengthType keyLength
   ,  actLengthType seedLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_INLINE_FUNC(void) actAesCtrDrbgNoDF(
  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) inputString
   ,  VSECPRIM_P2VAR_PARA(actU8) outputString);

VSECPRIM_LOCAL_INLINE_FUNC(actRETURNCODE) actAesCtrDrbgGenerateSetInput(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2CONST_PARA(actU8) additionalInputPtr
   ,  actLengthType additionalInputLength
   ,  actLengthType keyLength
   ,  actLengthType seedLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_INLINE_FUNC(void) actAesCtrDrbgConstructS(
  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) inputString
   ,  VSECPRIM_P2VAR_PARA(actU8) outputString
   ,  actLengthType inputStringLength
   ,  VSECPRIM_P2VAR_PARA(actU8) nextElement
   ,  VSECPRIM_P2VAR_PARA(actLengthType) nextIndex
   ,  actLengthType numberOfBytesToReturn
   ,  boolean isFirstBlock){
  actLengthType j, k, nextIndexLocal;
  actU8 i, nextElementLocal;
  actLengthType offset = 0u;
  actLengthType remainingBytesInBuffer = actCTRDRBG_BLOCK_LEN;

  j = 0u;
  k = *nextIndex;
  nextElementLocal = *nextElement;
  nextIndexLocal = *nextIndex;

  if(isFirstBlock == TRUE){
    actU32toBE(&outputString[0u], inputStringLength);

    actU32toBE(&outputString[actDRBG_SIZEOF_INPUTLENGTH], numberOfBytesToReturn);

    offset = actAESCTRDRBG_DF_BUFFER_OFFSET;
    remainingBytesInBuffer = actCTRDRBG_BLOCK_LEN - actAESCTRDRBG_DF_BUFFER_OFFSET;
  }

  for(i = *nextElement; ((i < inputString->elements) && (remainingBytesInBuffer > 0u)); i++){
    while((k < inputString->input[i].length) && (remainingBytesInBuffer > 0u)){
      outputString[offset + j] = inputString->input[i].dataPtr[k];
      j++;
      k++;
      nextElementLocal = i;
      nextIndexLocal = k;
      remainingBytesInBuffer--;
    }
    k = 0u;
  }

  *nextElement = nextElementLocal;
  *nextIndex = nextIndexLocal;

  if(((nextElementLocal == (inputString->elements - 1u)) &&
    (nextIndexLocal == inputString->input[nextElementLocal].length) &&
    (remainingBytesInBuffer > 0u))){
    outputString[offset + j] = 0x80u;

    if((remainingBytesInBuffer - 1u) > 0u){
      actMemClear(&outputString[offset + j + 1u], remainingBytesInBuffer - 1u);
    }
  }

}

VSECPRIM_LOCAL_INLINE_FUNC(void) actAesCtrDrbgBcc(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2CONST_PARA(actU8) IV
   ,  actLengthType Slength
   ,  actLengthType totalInputLength
   ,  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) inputString
   ,  VSECPRIM_P2VAR_PARA(actU8) outputString
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType i, j;
  actLengthType numberOfBytesToReturn, localKeyLength;
  VSECPRIM_P2VAR_PARA(actU8) blockOfS = workSpace->tempBlocks.blockOfS;

  VSECPRIM_P2VAR_PARA(actU8) tempResult = workSpace->BCCUpdateTmpBuffer.BCCTmpBuffer.result;
  VSECPRIM_P2VAR_PARA(actU8) tempInput = workSpace->BCCUpdateTmpBuffer.BCCTmpBuffer.input;

  actU8 nextInputElement = 0u;
  actLengthType nextIndexInInputElement = 0u;

  if((workSpace->mode & actDRBG_ALGSIZE_MASK) == actCTRDRBG_ALGSIZE_AES128){
    numberOfBytesToReturn = actAES128CTRDRBG_SEED_LEN;
    localKeyLength = actAES128_KEY_SIZE;
  }
  else{
    numberOfBytesToReturn = actAES256CTRDRBG_SEED_LEN;
    localKeyLength = actAES256_KEY_SIZE;
  }

  (void)actAESInitEncryptBlock(&workSpace->wsAES, tempKey, localKeyLength, watchdog);

  actAESEncryptBlock(&workSpace->wsAES, IV, tempResult, watchdog);

  actMemClear(blockOfS, actCTRDRBG_BLOCK_LEN);

  for(i = 0u; i < Slength; i += actCTRDRBG_BLOCK_LEN){
    if(i == 0u){
      actAesCtrDrbgConstructS(inputString, blockOfS, totalInputLength, &nextInputElement, &nextIndexInInputElement, numberOfBytesToReturn, TRUE);
    }
    else{
      actAesCtrDrbgConstructS(inputString, blockOfS, totalInputLength, &nextInputElement, &nextIndexInInputElement, numberOfBytesToReturn, FALSE);
    }

    for(j = 0u; j < actCTRDRBG_BLOCK_LEN; j++){
      tempInput[j] = tempResult[j] ^ blockOfS[j];
    }

    actAESEncryptBlock(&workSpace->wsAES, tempInput, tempResult, watchdog);
  }

  actMemCpyByteArray(outputString, tempResult, actCTRDRBG_BLOCK_LEN);

}

VSECPRIM_LOCAL_FUNC(void) actAesCtrDrbgEncryptBlock(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2VAR_PARA(actU8) outputData
   ,  actLengthType dataLength
   ,  actLengthType keyLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  uint32 i = 0u;

  (void)actAESInitEncryptBlock(&workSpace->wsAES, workSpace->key, keyLength, watchdog);

  if(dataLength >= actCTRDRBG_BLOCK_LEN){
    for(i = 0u; i <= (dataLength - actCTRDRBG_BLOCK_LEN); i += actCTRDRBG_BLOCK_LEN){
      actDrbgIncrementBlock(workSpace->variable, actCTRDRBG_BLOCK_LEN);

      actAESEncryptBlock(&workSpace->wsAES, workSpace->variable, &outputData[i], watchdog);
    }
  }

  if(i < dataLength){
    actDrbgIncrementBlock(workSpace->variable, actCTRDRBG_BLOCK_LEN);

    actAESEncryptBlock(&workSpace->wsAES, workSpace->variable, workSpace->tempBlocks.tempAesBlock, watchdog);
    actMemCpyByteArray(&outputData[i], workSpace->tempBlocks.tempAesBlock, (actLengthType)(dataLength - i));
  }
}

VSECPRIM_LOCAL_FUNC(void) actAesCtrDrbgBlockUpdate(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2CONST_PARA(actU8) inputData
   ,  actLengthType keyLength
   ,  actLengthType seedLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType i;
  VSECPRIM_P2VAR_PARA(actU8) tempBuffer = workSpace->BCCUpdateTmpBuffer.blockUpdateTmpBuffer;

  actAesCtrDrbgEncryptBlock(workSpace, tempBuffer, seedLength, keyLength, watchdog);

  for(i = 0u; i < seedLength; i++){
    tempBuffer[i] ^= inputData[i];
  }

  actMemCpyByteArray(workSpace->key, &tempBuffer[0], keyLength);

  actMemCpyByteArray(workSpace->variable, &tempBuffer[keyLength], actCTRDRBG_BLOCK_LEN);

}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actAesCtrDrbgDF(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) inputString
   ,  VSECPRIM_P2VAR_PARA(actU8) outputString
   ,  actLengthType keyLength
   ,  actLengthType seedLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;

  actLengthType j, totalInputLength, totalInputLengthControlValue;
  actLengthType bccInputLength;

  VSECPRIM_P2VAR_PARA(actU8) IV = workSpace->DFIV;
  VSECPRIM_P2VAR_PARA(actU8) encryptBuffer = workSpace->DFencryptBuffer;

  actU32 i = 0u;

  actMemClear(IV, actCTRDRBG_BLOCK_LEN);

  actMemClear(encryptBuffer, actAESCTRDRBG_SEED_LEN);

  totalInputLength = 0u;
  for(j = 0u; j < inputString->elements; j++){
    totalInputLengthControlValue = totalInputLength;
    totalInputLength += inputString->input[j].length;

    if(totalInputLength < totalInputLengthControlValue){
      retVal = actEXCEPTION_INPUT_LENGTH;
    }
  }

  if((totalInputLength + (actLengthType)(actAESCTRDRBG_DF_BUFFER_OFFSET) + 1u) < totalInputLength){
    retVal = actEXCEPTION_INPUT_LENGTH;
  }

  if(retVal == actOK){
    bccInputLength = ((((actAESCTRDRBG_DF_BUFFER_OFFSET + totalInputLength) / actCTRDRBG_BLOCK_LEN) + 1u) * actCTRDRBG_BLOCK_LEN);

    for(j = 0u; j < seedLength; j += actCTRDRBG_BLOCK_LEN){
      actAesCtrDrbgBcc(workSpace, IV, bccInputLength, totalInputLength, inputString, &encryptBuffer[j], watchdog);

      i++;
      actU32toBE(IV, i);
    }

    (void)actAESInitEncryptBlock(&workSpace->wsAES, encryptBuffer, keyLength, watchdog);

    for(j = 0u; j <= (seedLength - actCTRDRBG_BLOCK_LEN); j += actCTRDRBG_BLOCK_LEN){
      actAESEncryptBlock(&workSpace->wsAES, &encryptBuffer[keyLength], &encryptBuffer[keyLength], watchdog);

      actMemCpyByteArray(&outputString[j], &encryptBuffer[keyLength], actCTRDRBG_BLOCK_LEN);
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_INLINE_FUNC(void) actAesCtrDrbgNoDF(
  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) inputString
   ,  VSECPRIM_P2VAR_PARA(actU8) outputString){
  uint32 i;
  VSECPRIM_P2CONST_PARA(actU8) entropyPtr;
  VSECPRIM_P2CONST_PARA(actU8) personalStrPtr;
  actLengthType entropyLength, personalStrLength;

  entropyPtr = inputString->input[0u].dataPtr;
  entropyLength = inputString->input[0u].length;

  actMemCpyByteArray(outputString, entropyPtr, entropyLength);

  if(1u < inputString->elements){
    personalStrPtr = inputString->input[1u].dataPtr;
    personalStrLength = inputString->input[1u].length;

    for(i = 0u; i < personalStrLength; i++){
      outputString[i] ^= personalStrPtr[i];
    }
  }
}

VSECPRIM_LOCAL_INLINE_FUNC(actRETURNCODE) actAesCtrDrbgGenerateSetInput(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2CONST_PARA(actU8) additionalInputPtr
   ,  actLengthType additionalInputLength
   ,  actLengthType keyLength
   ,  actLengthType seedLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;
  actDrbgSeedInputType seedInput;
  VSECPRIM_P2VAR_PARA(actU8) additionalInputPrepared = workSpace->tmpBuffer.additionalInputPrepared;

  if((additionalInputPtr != NULL_PTR) && (additionalInputLength > 0u)){
    if((actDRBG_DFMODE_MASK & workSpace->mode) == actCTRDRBG_DFMODE_USE_BLOCKCIPHER_DF){
      seedInput.input[actDRBGSEED_INPUT_PARAM1].dataPtr = additionalInputPtr;
      seedInput.input[actDRBGSEED_INPUT_PARAM1].length = additionalInputLength;
      seedInput.elements = 1u;

      retVal = actAesCtrDrbgDF(workSpace, &seedInput, additionalInputPrepared, keyLength, seedLength, watchdog);
    }
    else{
      actMemCpyByteArray(additionalInputPrepared, additionalInputPtr, additionalInputLength);
      actMemClear(&additionalInputPrepared[additionalInputLength], ((actLengthType)(actAESCTRDRBG_SEED_LEN)-additionalInputLength));
    }

    if(retVal == actOK){
      actAesCtrDrbgBlockUpdate(workSpace, additionalInputPrepared, keyLength, seedLength, watchdog);
    }
  }
  else{
    actMemClear(additionalInputPrepared, actAESCTRDRBG_SEED_LEN);
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actAesCtrDrbgInstantiation(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) dataInput
   ,  boolean reseedFlag
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;

  actLengthType localSeedLength, localKeyLength;
  VSECPRIM_P2VAR_PARA(actU8) seedData = workSpace->tmpBuffer.seedData;

  if((workSpace->mode & actDRBG_ALGSIZE_MASK) == actCTRDRBG_ALGSIZE_AES128){
    localSeedLength = actAES128CTRDRBG_SEED_LEN;
    localKeyLength = actAES128_KEY_SIZE;
  }

  else{
    localSeedLength = actAES256CTRDRBG_SEED_LEN;
    localKeyLength = actAES256_KEY_SIZE;
  }

  if((actDRBG_DFMODE_MASK & workSpace->mode) == actCTRDRBG_DFMODE_USE_BLOCKCIPHER_DF){
    retVal = actAesCtrDrbgDF(workSpace, dataInput, seedData, localKeyLength, localSeedLength, watchdog);
  }
  else{
    actAesCtrDrbgNoDF(dataInput, seedData);
  }

  if(retVal == actOK){
    if(reseedFlag != TRUE){
      actMemClear(workSpace->key, actAESCTRDRBG_MAX_KEY_LEN);

      actMemClear(workSpace->variable, actCTRDRBG_BLOCK_LEN);
    }

    actAesCtrDrbgBlockUpdate(workSpace, seedData, localKeyLength, localSeedLength, watchdog);

    workSpace->reseedCount = 1u;
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actAesCtrDrbgGenerate(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  actLengthType requestedLength
   ,  VSECPRIM_P2VAR_PARA(actU8) outputBuffer
   ,  VSECPRIM_P2CONST_PARA(actU8) additionalInputPtr
   ,  actLengthType additionalInputLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;

  actLengthType localSeedLength, localKeyLength;

  if((workSpace->mode & actDRBG_ALGSIZE_MASK) == actCTRDRBG_ALGSIZE_AES128){
    localSeedLength = actAES128CTRDRBG_SEED_LEN;
    localKeyLength = actAES128_KEY_SIZE;
  }

  else{
    localSeedLength = actAES256CTRDRBG_SEED_LEN;
    localKeyLength = actAES256_KEY_SIZE;
  }

  if(actCTRDRBG_AES128_RESEED_INTERVAL > workSpace->reseedCount){
    retVal = actAesCtrDrbgGenerateSetInput(workSpace, additionalInputPtr, additionalInputLength, localKeyLength, localSeedLength, watchdog);

    if(retVal == actOK){
      actMemClear(outputBuffer, requestedLength);

      actAesCtrDrbgEncryptBlock(workSpace, outputBuffer, requestedLength, localKeyLength, watchdog);

      actAesCtrDrbgBlockUpdate(workSpace, workSpace->tmpBuffer.additionalInputPrepared, localKeyLength, localSeedLength, watchdog);

      workSpace->reseedCount++;

    }
  }
  else{
    workSpace->seedState = actDRBG_SEED_STATE_NEED_RESEED;
    retVal = actEXCEPTION_ENTROPY_EXHAUSTION;
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

