

#ifndef ESLIB_H
#define ESLIB_H

#include "ESLib_t.hpp"
#include "ESLib_ERC.hpp"
#include "ESLib_RNG.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef NULL
#define NULL                                                        ((void*)0)
#endif

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initESCryptoLib(void);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initWorkSpaceHeader(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHeader) workSpaceHeader
   ,  const eslt_Length workSpaceSize
   ,  esl_WatchdogFuncPtr watchdog);

#if(VSECPRIM_FIPS186_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initFIPS186(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceFIPS186) workSpace,
const eslt_Length entropyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) entropy,
VSECPRIM_P2VAR_PARA(eslt_Byte) savedState);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_getBytesFIPS186(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceFIPS186) workSpace,
const eslt_Length targetLength, VSECPRIM_P2VAR_PARA(eslt_Byte) target);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_stirFIPS186(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceFIPS186) workSpace,
const eslt_Length inputLength, VSECPRIM_P2VAR_PARA(eslt_Byte) input);

#endif

#if(VSECPRIM_CTR_DRBG_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_initCTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  eslt_DRBGMode modeDRBG);

VSECPRIM_FUNC(eslt_ErrorCode) esl_seedCTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) noncePtr
   ,  eslt_Length nonceLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) personalizationStringPtr
   ,  eslt_Length personalizationStringLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength);

VSECPRIM_FUNC(eslt_ErrorCode) esl_getBytesCTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  eslt_Length requestedLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) outputBuffer
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength);

VSECPRIM_FUNC(eslt_ErrorCode) esl_getStateCTRDRBG(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) internalStateBuffer
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) internalStateBufferLength
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGReseedCounterType) reseedCounter
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGSeedStatusType) seedStatus
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGMode) modeDRBG);

VSECPRIM_FUNC(eslt_ErrorCode) esl_restoreStateCTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) internalStateBuffer
   ,  eslt_Length internalStateBufferLength
   ,  eslt_DRBGReseedCounterType reseedCounter
   ,  eslt_DRBGSeedStatusType seedStatus
   ,  eslt_DRBGMode modeDRBG);
#endif

#if(VSECPRIM_HASH_DRBG_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_initHASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  eslt_DRBGMode modeDRBG);

VSECPRIM_FUNC(eslt_ErrorCode) esl_seedHASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) noncePtr
   ,  eslt_Length nonceLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) personalizationStringPtr
   ,  eslt_Length personalizationStringLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength);

VSECPRIM_FUNC(eslt_ErrorCode) esl_getBytesHASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  eslt_Length requestedLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) outputBuffer
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength);

VSECPRIM_FUNC(eslt_ErrorCode) esl_getStateHASHDRBG(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) internalStateBuffer
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) internalStateBufferLength
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGReseedCounterType) reseedCounter
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGSeedStatusType) seedStatus
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGMode) modeDRBG);

VSECPRIM_FUNC(eslt_ErrorCode) esl_restoreStateHASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) internalStateBuffer
   ,  eslt_Length internalStateBufferLength
   ,  eslt_DRBGReseedCounterType reseedCounter
   ,  eslt_DRBGSeedStatusType seedStatus
   ,  eslt_DRBGMode modeDRBG);

#endif

#if(VSECPRIM_AES128_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptAES128(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptAES128(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128) workSpace
   ,  const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptAES128(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptAES128(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptAES128(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128) workSpace
   ,  const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptAES128(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptAES128Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128Block) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptAES128Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128Block) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptAES128Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES128Block) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptAES128Block(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceAES128Block) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);
#endif

#if(VSECPRIM_AES192_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptAES192(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptAES192(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192) workSpace
   ,  const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptAES192(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptAES192(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptAES192(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192) workSpace
   ,  const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptAES192(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptAES192Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192Block) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptAES192Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192Block) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptAES192Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192Block) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptAES192Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES192Block) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);

#endif

#if(VSECPRIM_AES256_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptAES256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES256) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptAES256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES256) workSpace
   ,  const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptAES256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES256) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptAES256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES256) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptAES256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES256) workSpace
   ,  const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptAES256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES256) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptAES256Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES256Block) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptAES256Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES256Block) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptAES256Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES256Block) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptAES256Block(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAES256Block) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);

#endif

#if(VSECPRIM_DES_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyDES(VSECPRIM_P2VAR_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDES) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key,
const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode,
VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDES) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDES) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDES) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key,
const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode,
VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDES) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDES) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptDESBlock(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDESBlock) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptDESBlock(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDESBlock) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptDESBlock(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDESBlock) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptDESBlock(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceDESBlock) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);

#endif

#if(VSECPRIM_TDES_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKey3TDES(VSECPRIM_P2VAR_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKey2TDES(VSECPRIM_P2VAR_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptTDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDES) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Byte key_len,
const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode,
VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptTDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDES) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptTDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDES) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptTDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDES) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Byte key_len,
const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode,
VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptTDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDES) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptTDES(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDES) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptTDESBlock(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDESBlock) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Byte key_len);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptTDESBlock(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDESBlock) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptTDESBlock(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDESBlock) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Byte key_len);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptTDESBlock(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceTDESBlock) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);

#endif

#if(VSECPRIM_RC2_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyRC2(VSECPRIM_P2VAR_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptRC2(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Length key_len, const eslt_Length eff_key_len,
const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode,
VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRC2(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptRC2(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRC2(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Length key_len, const eslt_Length eff_key_len,
const eslt_BlockMode blockMode, const eslt_PaddingMode paddingMode,
VSECPRIM_P2CONST_PARA(eslt_Byte) initializationVector);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRC2(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptRC2(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Length) outputSize, VSECPRIM_P2VAR_PARA(eslt_Byte) output);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptRC2Block(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2Block) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Length key_len, const eslt_Length eff_key_len);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRC2Block(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2Block) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRC2Block(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2Block) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Length key_len, const eslt_Length eff_key_len);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRC2Block(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRC2Block) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) inputBlock, VSECPRIM_P2VAR_PARA(eslt_Byte) outputBlock);

#endif

#if(VSECPRIM_GMAC_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initGMAC(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace,
const eslt_Length keyLength,
VSECPRIM_P2CONST_PARA(eslt_Byte) key,
const eslt_Length ivLength,
VSECPRIM_P2CONST_PARA(eslt_Byte) iv);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateGMAC(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace,
const eslt_Length inputLength,
VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeGMAC(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) tag);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyGMAC(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) tag);

#endif

#if(VSECPRIM_GCM_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptGCM(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  const eslt_Length keyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) iv
   ,  const eslt_Length ivLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptGCM(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  const eslt_Length keyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) iv
   ,  const eslt_Length ivLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateAuthDataEncryptGCM(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  const eslt_Length inputLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateAuthDataDecryptGCM(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  const eslt_Length inputLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updatePlaintextEncryptGCM(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  const eslt_Length inputLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) output
   ,  VSECPRIM_P2VAR_PARA(eslt_Size32) bytes_out);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateCiphertextDecryptGCM(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  const eslt_Length inputLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) output
   ,  VSECPRIM_P2VAR_PARA(eslt_Size32) bytes_out);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptGCM(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) output
   ,  VSECPRIM_P2VAR_PARA(eslt_Size32) bytes_out
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tag);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptGCM(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGCM) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) output
   ,  VSECPRIM_P2VAR_PARA(eslt_Size32) bytes_out
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) tag);
#endif

#if(VSECPRIM_AES_CCM_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initAESCCM(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAESCCM) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  const eslt_Length keyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte)nonce
   ,  const eslt_Length nonceLength
   ,  const eslt_Length aadLength
   ,  const eslt_Length msgLength
   ,  const eslt_Byte authenticationFieldSize
   ,  const eslt_Byte lengthFieldSize);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateAESCCMEncrypt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAESCCM) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) aad
   ,  const eslt_Length aadSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) msg
   ,  const eslt_Length msgSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte)out
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outSize);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateAESCCMDecrypt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAESCCM) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) aad
   ,  const eslt_Length aadSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) encMsg
   ,  const eslt_Length encMsgSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte)out
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outSize);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeAESCCMEncrypt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAESCCM) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) out
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tag
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) tagLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeAESCCMDecrypt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceAESCCM) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) out
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) tag);

#endif

#if(VSECPRIM_SHA1_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHA1(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA1) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHA1(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA1) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHA1(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA1) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

#endif

#if(VSECPRIM_SHA2_256_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHA224(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA224) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHA224(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA224) workSpace
   ,  const eslt_Length inputSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHA224(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA224) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHA256(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA256) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA256) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA256) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);
#endif

#if(VSECPRIM_SHA2_512_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHA384(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA384) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHA384(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA384) workSpace
   ,  const eslt_Length inputSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHA384(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA384) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHA512(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA512) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHA512(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA512) workSpace,
const eslt_Length inputSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHA512(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA512) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHA512_224(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA512_224) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHA512_224(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA512_224) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHA512_224(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA512_224) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHA512_256(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA512_256) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHA512_256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA512_256) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHA512_256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA512_256) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

#endif

#if(VSECPRIM_SHA3_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHA3(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA3) workSpace
   ,  const eslt_Length bitLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHA3(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA3) workSpace
   ,  const eslt_Length inputSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHA3(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA3) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSHAKE(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHAKE) workSpace
   ,  const eslt_Length strength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSHAKE(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHAKE) workSpace
   ,  const eslt_Length inputSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_getXOFDigestSHAKE(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHAKE) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest
   ,  const eslt_Length digestLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSHAKE(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHAKE) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength);

#endif

#if(VSECPRIM_RIPEMD160_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initRIPEMD160(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRIPEMD160) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateRIPEMD160(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRIPEMD160) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeRIPEMD160(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRIPEMD160) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

#endif

#if(VSECPRIM_MD5_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initMD5(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceMD5) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateMD5(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceMD5) workSpace,
const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeMD5(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceMD5) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);
#endif

#if(VSECPRIM_HMAC_SHA1_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyHashMACSHA1(
const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initHashMACSHA1(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA1) workSpace,
const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateHashMACSHA1(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA1) workSpace,
const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashMACSHA1(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA1) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageHashMAC);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyHashMACSHA1(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA1) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageHashMAC);
#endif

#if(VSECPRIM_HMAC_RMD160_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyHashMACRIPEMD160(
const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initHashMACRIPEMD160(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACRIPEMD160) workSpace,
const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateHashMACRIPEMD160(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACRIPEMD160) workSpace,
const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashMACRIPEMD160(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACRIPEMD160) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageHashMAC);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyHashMACRIPEMD160(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACRIPEMD160) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageHashMAC);
#endif

#if(VSECPRIM_HMAC_SHA2_256_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyHashMACSHA256(
const eslt_Length keyLength,
VSECPRIM_P2VAR_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
const eslt_Length keyLength,
VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
const eslt_Length inputLength,
VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) messageHashMAC);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageHashMAC);
#endif

#if(VSECPRIM_HMAC_SHA2_384_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyHashMACSHA384(
  const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initHashMACSHA384(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace
   ,  const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateHashMACSHA384(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace
   ,  const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashMACSHA384(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageHashMAC);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyHashMACSHA384(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageHashMAC);
#endif

#if(VSECPRIM_CMAC_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initCMACAES128(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace
   ,  const eslt_Length keyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initExpandedCMACAES128(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) expandedKey
   ,  const eslt_Length expandedKeyLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_getExpandedKeyCMACAES128(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceCMACAES) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) keyPtr
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) keyLengthPtr);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateCMACAES128(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace
   ,  const eslt_Length inputLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeCMACAES128(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) messageCMAC);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyCMACAES128(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageCMAC);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initCMACAES256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace
   ,  const eslt_Length keyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initExpandedCMACAES256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) expandedKey
   ,  const eslt_Length expandedKeyLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_getExpandedKeyCMACAES256(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceCMACAES) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) keyPtr
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) keyLengthPtr);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateCMACAES256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace
   ,  const eslt_Length inputLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeCMACAES256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageCMAC
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageCMACLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyCMACAES256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCMACAES) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageCMAC);

#endif

#if(VSECPRIM_SIP_HASH_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSipHash(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSipHash) workSpace
   ,  const eslt_Length keyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSipHash(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSipHash) workSpace
   ,  const eslt_Length inputLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSipHash(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSipHash) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageMAC);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySipHash(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSipHash) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageMAC);
#endif

#if(VSECPRIM_ANSI_X963_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initKDFX963SHA1(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDFX963SHA1) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyKDFX963SHA1(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDFX963SHA1) workSpace
   ,  const eslt_Length secretLength, VSECPRIM_P2CONST_PARA(eslt_Byte) secret
   ,  const eslt_Length infoLength, VSECPRIM_P2CONST_PARA(eslt_Byte) info
   ,  const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key);
#endif

#if(VSECPRIM_ANSI_X963_SHA256_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initKDFX963SHA256(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDFX963SHA256) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyKDFX963SHA256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDFX963SHA256) workSpace
   ,  const eslt_Length secretLength, VSECPRIM_P2CONST_PARA(eslt_Byte) secret
   ,  const eslt_Length infoLength, VSECPRIM_P2CONST_PARA(eslt_Byte) info
   ,  const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key);
#endif

#if(VSECPRIM_ANSI_X963_SHA512_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initKDFX963SHA512(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDFX963SHA512) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyKDFX963SHA512(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDFX963SHA512) workSpace
   ,  const eslt_Length secretLength, VSECPRIM_P2CONST_PARA(eslt_Byte) secret
   ,  const eslt_Length infoLength, VSECPRIM_P2CONST_PARA(eslt_Byte) info
   ,  const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key);
#endif

#if(VSECPRIM_PKCS5_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initKDF2HMACSHA1(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2HMACSHA1) workSpace, const eslt_Length iterationCount);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyKDF2HMACSHA1(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2HMACSHA1) workSpace
   ,  const eslt_Length secretLength, VSECPRIM_P2CONST_PARA(eslt_Byte) secret
   ,  const eslt_Length infoLength, VSECPRIM_P2CONST_PARA(eslt_Byte) info
   ,  const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key);
#endif

#if(VSECPRIM_HKDF_SHA2_256_ONESTEP_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initHKDF_Hash_OneStep(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHASH) workSpace
   ,  eslt_HashAlgorithm hashID);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyHKDF_Hash_OneStep(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHASH) workSpace
   ,  const eslt_Length secretLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) secret
   ,  const eslt_Length infoLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) info
   ,  const eslt_Length keyLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) key);
#endif

#if(VSECPRIM_HKDF_HMAC_SHA256_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initHKDF_HMAC_SHA256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHMAC) workSpace
   ,  eslt_HKDFMode mode);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyHKDF_HMAC_SHA256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHKDFHMAC) workSpace
   ,  const eslt_Length secretLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) secret
   ,  const eslt_Length saltLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  const eslt_Length infoLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) info
   ,  const eslt_Length keyLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) key);
#endif

#if(VSECPRIM_PKCS5_HMAC_SHA256_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initKDF2HMACSHA256(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2HMACSHA256) workSpace, const eslt_Length iterationCount);

 extern VSECPRIM_FUNC(eslt_ErrorCode) esl_deriveKeyKDF2HMACSHA256(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceKDF2HMACSHA256) workSpace
   ,  const eslt_Length secretLength, VSECPRIM_P2CONST_PARA(eslt_Byte) secret
   ,  const eslt_Length infoLength, VSECPRIM_P2CONST_PARA(eslt_Byte) info
   ,  const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key);

#endif
#if(VSECPRIM_ESLGETLENGTHECP_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_Length) esl_getMaxLengthOfEcPmessage(VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain);

extern VSECPRIM_FUNC(eslt_Length) esl_getLengthOfEcPpublicKey_comp(VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain);

extern VSECPRIM_FUNC(eslt_Length) esl_getLengthOfEcPprivateKey(VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain);

extern VSECPRIM_FUNC(eslt_Length) esl_getLengthOfEcPsignature_comp(VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain);

extern VSECPRIM_FUNC(eslt_Length) esl_getLengthOfEcPsecret_comp(VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain);
#endif

#if(VSECPRIM_ECCENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initGenerateKeyEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace, VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain
   ,  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt, VSECPRIM_P2ROMCONST_PARA(eslt_EccSpeedUpExt) speedUpExt);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) privateKey
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey_x, VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey_y);
#endif

#if(VSECPRIM_ECDSA_GENERIC_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignDSAEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace, VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain
   ,  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt, VSECPRIM_P2ROMCONST_PARA(eslt_EccSpeedUpExt) speedUpExt);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_signDSAEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace
   ,  eslt_Length messageLength, VSECPRIM_P2CONST_PARA(eslt_Byte) message, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signature_rLength, VSECPRIM_P2VAR_PARA(eslt_Byte) signature_r
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signature_sLength, VSECPRIM_P2VAR_PARA(eslt_Byte) signature_s);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyDSAEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace
   ,  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain, VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyDSAEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace
   ,  eslt_Length messageLength, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_x, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_y
   ,  eslt_Length signature_rLength, VSECPRIM_P2CONST_PARA(eslt_Byte) signature_r
   ,  eslt_Length signature_sLength, VSECPRIM_P2CONST_PARA(eslt_Byte) signature_s);
#endif

#if(VSECPRIM_ECDH_GENERIC_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initExchangeKeyDHEcP_key(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace
   ,  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain, VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_exchangeKeyDHEcP_key(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_x, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_y
   ,  eslt_Length infoLength, VSECPRIM_P2CONST_PARA(eslt_Byte) info, eslt_Length iterationCount
   ,  eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initGenerateSharedSecretDHEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace
   ,  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain, VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateSharedSecretDHEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_x, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey_y
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) secret_x, VSECPRIM_P2VAR_PARA(eslt_Byte) secret_y);
#endif

#if(VSECPRIM_SPAKE2_P_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSPAKE2PPreamble(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2PPreamble) wsSpakePre
   ,  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain
   ,  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSPAKE2PPreamble(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2PPreamble) wsSpakePre
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) pbkdfOutput
   ,  const eslt_Length pbkdfOutputLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) w0
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) w0Length
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) w1
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) w1Length
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) pointL
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) pointLLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace
   ,  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain
   ,  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) pointM
   ,  const eslt_Length mlength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) pointN
   ,  const eslt_Length nlength
   ,  eslt_SPAKE2PMode ciphersuite);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_setPreambleDataPartyASPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) w0
   ,  const eslt_Length w0length
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) w1
   ,  const eslt_Length w1length);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_setPreambleDataPartyBSPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) w0
   ,  const eslt_Length w0length
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) pointL
   ,  const eslt_Length pointLLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_calcPubValSPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) pubVal_x
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) pubVal_y
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) pubValLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_setAdditionalInformationSPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) infoA
   ,  const eslt_Length infoALength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) infoB
   ,  const eslt_Length infoBLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) aad
   ,  const eslt_Length aadLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSharedSecretSPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) pubVal_x
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) pubVal_y
   ,  const eslt_Length pubValLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) sharedSecret
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) sharedSecretLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) confirmationMAC
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) confirmationMACLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_confirmKeySPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) mac
   ,  const eslt_Length macLength);
#endif

#if(VSECPRIM_RSA_CIPHER_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSA_prim(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec_prim) workSpace
   ,   eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,   eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSA_prim(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec_prim) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSACRT_prim(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTdec_prim) workSpace
   ,  eslt_Length   keyPairPrimePSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeP
   ,  eslt_Length   keyPairPrimeQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeQ
   ,  eslt_Length   privateKeyExponentDPSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDP
   ,  eslt_Length   privateKeyExponentDQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDQ
   ,  eslt_Length   privateKeyInverseQISize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyInverseQI);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSACRT_prim(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTdec_prim) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);
#endif

#if(VSECPRIM_RSA_SIGNATURE_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSA_prim(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig_prim) workSpace
   ,    eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,    eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_signRSA_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig_prim) workSpace
   ,  eslt_Length messageSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

#if(VSECPRIM_RSACRT == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSACRT_prim(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig_prim) workSpace
   ,  eslt_Length keyPairPrimePSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeP
   ,  eslt_Length keyPairPrimeQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeQ
   ,  eslt_Length privateKeyExponentDPSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDP
   ,  eslt_Length privateKeyExponentDQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDQ
   ,  eslt_Length privateKeyInverseQISize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyInverseQI);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_signRSACRT_prim(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig_prim) workSpace
   ,  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize, VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

#endif
#endif

#if(VSECPRIM_RSA_CIPHER_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptRSA_prim(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAenc_prim) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSA_prim(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAenc_prim) workSpace
   ,  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher);
#endif

#if(VSECPRIM_RSA_SIGNATURE_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSA_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver_prim) workSpace
   ,  eslt_Length keyPairModuleSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyRSA_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver_prim) workSpace
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) message);
#endif

#if((VSECPRIM_RSA_V15_SHA1_ENABLED == STD_ON) || (VSECPRIM_RSA_V15_ENABLED == STD_ON))

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSA_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptPubRSA_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptPrivRSA_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSA_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSACRT_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTdec) workSpace
   ,  eslt_Length keyPairPrimePSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeP
   ,  eslt_Length keyPairPrimeQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeQ
   ,  eslt_Length privateKeyExponentDPSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDP
   ,  eslt_Length privateKeyExponentDQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDQ
   ,  eslt_Length privateKeyInverseQISize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyInverseQI);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSACRT_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSASHA1_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSASHA1_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace
   ,  eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA1_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize, VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSACRTSHA1_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig) workSpace
   ,  eslt_Length keyPairPrimePSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeP
   ,  eslt_Length keyPairPrimeQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeQ
   ,  eslt_Length privateKeyExponentDPSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDP
   ,  eslt_Length privateKeyExponentDQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDQ
   ,  eslt_Length privateKeyInverseQISize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyInverseQI);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSACRTSHA1_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig) workSpace
   ,  const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSACRTSHA1_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize, VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptRSA_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAenc) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSA_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAenc) workSpace
   ,  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSASHA1_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateVerifyRSASHA1_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace
   ,  eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashVerifyRSASHA1_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA1_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA1_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);
#endif

#if(VSECPRIM_RSA_V15_RIPEMD160_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSARIPEMD160_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSARIPEMD160_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace
   ,  eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSARIPEMD160_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize, VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSACRTRIPEMD160_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig) workSpace
   ,  eslt_Length keyPairPrimePSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeP
   ,  eslt_Length keyPairPrimeQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeQ
   ,  eslt_Length privateKeyExponentDPSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDP
   ,  eslt_Length privateKeyExponentDQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDQ
   ,  eslt_Length privateKeyInverseQISize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyInverseQI);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSACRTRIPEMD160_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig) workSpace
   ,  const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSACRTRIPEMD160_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize, VSECPRIM_P2VAR_PARA(eslt_Byte  ) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSARIPEMD160_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateVerifyRSARIPEMD160_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace
   ,  eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashVerifyRSARIPEMD160_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSARIPEMD160_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSARIPEMD160_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);
#endif

#if(VSECPRIM_RSA_V15_SHA2_256_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSASHA256_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent   );

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSASHA256_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace
   ,  eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA256_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize, VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSACRTSHA256_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig) workSpace
   ,  eslt_Length keyPairPrimePSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeP
   ,  eslt_Length keyPairPrimeQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeQ
   ,  eslt_Length privateKeyExponentDPSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDP
   ,  eslt_Length privateKeyExponentDQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDQ
   ,  eslt_Length privateKeyInverseQISize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyInverseQI);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSACRTSHA256_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig) workSpace
   ,  const eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSACRTSHA256_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize, VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSASHA256_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateVerifyRSASHA256_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace
   ,  eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashVerifyRSASHA256_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA256_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA256_V15(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAver) workSpace
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);
#endif

#if(VSECPRIM_RSA_OAEP_SHA1_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptRSASHA1_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA1_OAEP_Label_Seed(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace
   ,  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label
   ,  eslt_Length inSeedSize, VSECPRIM_P2CONST_PARA(eslt_Byte) inSeed
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA1_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace
   ,  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA1_OAEP_Seed(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace
   ,  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  eslt_Length inSeedSize, VSECPRIM_P2CONST_PARA(eslt_Byte) inSeed
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA1_OAEP_Label(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace
   ,  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSASHA1_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPdec) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decodeRSASHA1_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpace) workSpace, eslt_Length encodedMessageSize
   ,  eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSASHA1_OAEP_Label(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSASHA1_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSACRTSHA1_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTOAEPdec) workSpace
   ,  eslt_Length keyPairPrimePSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeP
   ,  eslt_Length keyPairPrimeQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeQ
   ,  eslt_Length privateKeyExponentDPSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDP
   ,  eslt_Length privateKeyExponentDQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDQ
   ,  eslt_Length privateKeyInverseQISize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyInverseQI);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSACRTSHA1_OAEP_Label(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTOAEPdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSACRTSHA1_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTOAEPdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);
#endif

#if(VSECPRIM_RSA_OAEP_SHA2_256_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptRSASHA256_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA256_OAEP_Label_Seed(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace
   ,  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label
   ,  eslt_Length inSeedSize, VSECPRIM_P2CONST_PARA(eslt_Byte) inSeed
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA256_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace
   ,  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA256_OAEP_Seed(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace
   ,  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  eslt_Length inSeedSize, VSECPRIM_P2CONST_PARA(eslt_Byte) inSeed
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA256_OAEP_Label(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace
   ,  eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSASHA256_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPdec) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decodeRSASHA256_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpace) workSpace, eslt_Length encodedMessageSize
   ,  eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSASHA256_OAEP_Label(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSASHA256_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSACRTSHA256_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTOAEPdec) workSpace
   ,  eslt_Length keyPairPrimePSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeP
   ,  eslt_Length keyPairPrimeQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairPrimeQ
   ,  eslt_Length privateKeyExponentDPSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDP
   ,  eslt_Length privateKeyExponentDQSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponentDQ
   ,  eslt_Length privateKeyInverseQISize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyInverseQI);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSACRTSHA256_OAEP_Label(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTOAEPdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSACRTSHA256_OAEP(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSACRTOAEPdec) workSpace
   ,  eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message);
#endif

#if(VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSASHA1_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSASHA1_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashSignRSASHA1_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA1_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length saltSize, VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA1_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA1_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA1_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  eslt_Length saltSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA1_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA1_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSASHA1_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateVerifyRSASHA1_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashVerifyRSASHA1_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA1_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length saltSize
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA1_PSS_AutoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA1_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA1_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA1_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length saltSize, eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA1_PSS_AutoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA1_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA1_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSaltedHashRSASHA1_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA1) wsHash
   ,  eslt_Length saltSize, VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) saltedHash);
#endif

#if(VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSARIPEMD160_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSARIPEMD160_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashSignRSARIPEMD160_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSARIPEMD160_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length saltSize, VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSARIPEMD160_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSARIPEMD160_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSARIPEMD160_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  eslt_Length saltSize, VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSARIPEMD160_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSARIPEMD160_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSARIPEMD160_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateVerifyRSARIPEMD160_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length inputSize, VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashVerifyRSARIPEMD160_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSARIPEMD160_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length saltSize
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSARIPEMD160_PSS_AutoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSARIPEMD160_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSARIPEMD160_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSARIPEMD160_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length saltSize, eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSARIPEMD160_PSS_AutoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSARIPEMD160_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSARIPEMD160_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize, VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSaltedHashRSARIPEMD160_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRIPEMD160) wsHash
   ,  eslt_Length saltSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) saltedHash);
#endif

#if(VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  eslt_Length keyPairModuleSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length privateKeyExponentSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSASHA256_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  eslt_Length inputSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashSignRSASHA256_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA256_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length saltSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA256_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA256_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA256_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  eslt_Length saltSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA256_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA256_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length keyPairModuleSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateVerifyRSASHA256_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length inputSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashVerifyRSASHA256_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA256_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length saltSize
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA256_PSS_AutoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA256_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA256_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA256_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length saltSize
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA256_PSS_AutoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA256_PSS_NoSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA256_PSS_DigestLengthSalt(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSaltedHashRSASHA256_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA256) wsHash
   ,  eslt_Length saltSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) saltedHash);
#endif

#if(VSECPRIM_RSA_HASHALGORITHM_RIPEMD160_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateMaskMGF1RSARIPEMD160_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRIPEMD160) wsHash
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tempHash
   ,  eslt_Length seedLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) seed
   ,  eslt_Length maskLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) mask);
#endif

#if(VSECPRIM_RSA_HASHALGORITHM_SHA1_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateMaskMGF1RSASHA1_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA1) wsHash
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tempHash
   ,  eslt_Length seedLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) seed
   ,  eslt_Length maskLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) mask);
#endif

#if(VSECPRIM_RSA_HASHALGORITHM_SHA2_256_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateMaskMGF1RSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSHA256) wsHash
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tempHash
   ,  eslt_Length seedLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) seed
   ,  eslt_Length maskLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) mask);
#endif

#if(VSECPRIM_RSA_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyPaddingRSAEM_V15(
  VSECPRIM_P2CONST_PARA(eslt_Byte) message, VSECPRIM_P2VAR_PARA(eslt_Length) paddingLength, eslt_Byte blockType);
#endif

#if(VSECPRIM_ECDSA_25519_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace
   ,  eslt_Size16 curve
   ,  const eslt_Byte instance
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) context
   ,  const eslt_Length contextLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_signEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  eslt_Length inputLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) secretKey
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) signature
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) signatureLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace
   ,  eslt_Size16 curve
   ,  const eslt_Byte instance
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) context
   ,  const eslt_Length contextLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  eslt_Length inputLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKey
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature
   ,  eslt_Length signatureLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  eslt_Length inputLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initGenerateKeyPairEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace
   ,  eslt_Size16 curve);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyPairEdDSA(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEd25519) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) secretKey
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) secretKeyLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) publicKeyLength);

#endif

#if(VSECPRIM_ECDH_25519_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initECDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceX25519) workSpace
   ,  eslt_Size16 curve);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateEphemeralKeyPairECDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceX25519) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) publicKeyLength);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_importStaticPrivateKeyECDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceX25519) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKey);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateSharedSecretECDH(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceX25519) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) sharedSecret
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) sharedSecretLength);
#endif

#if(VSECPRIM_CHA_CHA20_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptChaCha20(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaCha20) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) nonce
   ,  const eslt_Size32 blockCount);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptChaCha20(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaCha20) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) nonce
   ,  const eslt_Size32 blockCount);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptChaCha20(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaCha20) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) in
   ,  const eslt_Length inSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) out
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outSize);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeEncryptChaCha20(
    VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaCha20) workSpace
   ,   VSECPRIM_P2CONST_PARA(eslt_Byte) in
   ,   const eslt_Length inSize
   ,   VSECPRIM_P2VAR_PARA(eslt_Byte) out
   ,   VSECPRIM_P2VAR_PARA(eslt_Length) outSize);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptChaCha20(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaCha20) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) in
   ,  const eslt_Length inSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) out
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outSize);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeDecryptChaCha20(
    VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaCha20) workSpace
   ,   VSECPRIM_P2CONST_PARA(eslt_Byte) in
   ,   const eslt_Length inSize
   ,   VSECPRIM_P2VAR_PARA(eslt_Byte) out
   ,   VSECPRIM_P2VAR_PARA(eslt_Length) outSize);
#endif

#if(VSECPRIM_POLY1305_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initPoly1305(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpacePoly1305) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) key);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updatePoly1305(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpacePoly1305) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) message
   ,  const eslt_Length msgSize);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizePoly1305(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpacePoly1305) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tag);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyPoly1305(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpacePoly1305) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) tag);
#endif

#if(VSECPRIM_AEAD_CHA_CHA20_POLY1305_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptChaChaPoly(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaChaPoly) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) nonce);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptChaChaPoly(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaChaPoly) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) key
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) nonce);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateAADChaChaPoly(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaChaPoly) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) aad
   ,  const eslt_Length aadSize);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateDataChaChaPoly(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaChaPoly) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) in
   ,  const eslt_Length inSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) out
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) outSize);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeChaChaPoly(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaChaPoly) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tag);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyChaChaPoly(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceChaChaPoly) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) tag);
#endif

#if(VSECPRIM_ECBD_GENERIC_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initECBD(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceECBD) workSpace
   ,  const eslt_Size32 nDevices
   ,  const eslt_Size32 deviceID
   ,  VSECPRIM_P2CONST_PARA(eslt_EccDomain) domain
   ,  VSECPRIM_P2CONST_PARA(eslt_EccDomainExt) domainExt
   ,  VSECPRIM_P2CONST_PARA(eslt_EccSpeedUpExt) speedUpExt);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_generateEphemeralKeyPairECBD(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceECBD) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) privateKey
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey_x
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey_y);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_calculateIntermediateECBD(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceECBD) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) pubKeyLeft_x
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) pubKeyLeft_y
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) pubKeyRight_x
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) pubKeyRight_y
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) intermediate_x
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) intermediate_y);

extern VSECPRIM_FUNC( eslt_ErrorCode ) esl_initSharedSecretECBD(
  VSECPRIM_P2VAR_PARA( eslt_WorkSpaceECBD ) workSpace);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSharedSecretECBD(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceECBD) workSpace
   ,  const eslt_Size32          deviceID
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) intermediate_x
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) intermediate_y);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_retrieveSharedSecretECBD(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceECBD) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) sharedSecret_x
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) sharedSecret_y);
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
}
#endif

#endif

