

#define ESLIB_DRBG_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIDRBG.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#if(VSECPRIM_CTR_DRBG_ENABLED == STD_ON)

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_CTRDRBG_checkMode(
  eslt_DRBGMode modeDRBG);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_seedCTRDRBG_checkEntropySize(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  eslt_Length entropyLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_CTRDRBG_checkInputLengthNoDF(
  eslt_DRBGMode modeDRBG
   ,  eslt_Length inputLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_seedCTRDRBG_checkInput(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  eslt_Length entropyLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_getBytesCTRDRBG_checkInput(
  eslt_DRBGMode modeDRBG
   ,  eslt_Length requestedLength
   ,  eslt_Length maxRequestLength
   ,  eslt_Length additionalInputLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initialSeed_CTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) noncePtr
   ,  eslt_Length nonceLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) personalizationStringPtr
   ,  eslt_Length personalizationStringLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_reseed_CTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength);

#endif

#if(VSECPRIM_HASH_DRBG_ENABLED == STD_ON)

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_seedHASHDRBG_checkInput(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  eslt_Length entropyLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_getBytesHASHDRBG_checkInput(
  eslt_DRBGMode modeDRBG
   ,  eslt_Length requestedLength
   ,  eslt_Length maxRequestLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initialSeed_HASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) noncePtr
   ,  eslt_Length nonceLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) personalizationStringPtr
   ,  eslt_Length personalizationStringLength);

VSECPRIM_LOCAL_FUNC(void) esl_reseed_HASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength);

#endif

#if(VSECPRIM_CTR_DRBG_ENABLED == STD_ON)

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_CTRDRBG_checkMode(
  eslt_DRBGMode modeDRBG){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  if( ((actDRBG_ALGSIZE_MASK & modeDRBG) != actCTRDRBG_ALGSIZE_AES128) &&
    ((actDRBG_ALGSIZE_MASK & modeDRBG) != actCTRDRBG_ALGSIZE_AES256)){
    retVal = ESL_ERC_MODE_INVALID;
  }
  else{
    if(((actDRBG_DFMODE_MASK & modeDRBG) != actCTRDRBG_DFMODE_USE_BLOCKCIPHER_DF) &&
      ((actDRBG_DFMODE_MASK & modeDRBG) != actCTRDRBG_DFMODE_USE_NO_DF)){
      retVal = ESL_ERC_MODE_INVALID;
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_CTRDRBG_checkInputLengthNoDF(
  eslt_DRBGMode modeDRBG
   ,  eslt_Length inputLength){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  if((actDRBG_DFMODE_MASK & modeDRBG) == actCTRDRBG_DFMODE_USE_NO_DF){
    if((modeDRBG == actCTRDRBG_ALGSIZE_AES128) && (inputLength > ESL_CTRDRBG_AES128_SEEDLEN)){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else if((modeDRBG == actCTRDRBG_ALGSIZE_AES256) && (inputLength > ESL_CTRDRBG_AES256_SEEDLEN)){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else{
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_seedCTRDRBG_checkEntropySize(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  eslt_Length entropyLength){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;
  eslt_Length requiredEntropyLengthNoDF, requiredEntropyLengthDF;

  if((actDRBG_ALGSIZE_MASK & workSpace->wsDRBG.mode) == actCTRDRBG_ALGSIZE_AES128){
    requiredEntropyLengthDF = actBitsToBytes(actAES128CTRDRBG_SECURITY_STRENGTH);
    requiredEntropyLengthNoDF = ESL_CTRDRBG_AES128_SEEDLEN;
  }
  else{
    requiredEntropyLengthDF = actBitsToBytes(actAES256CTRDRBG_SECURITY_STRENGTH);
    requiredEntropyLengthNoDF = ESL_CTRDRBG_AES256_SEEDLEN;
  }

  if((actDRBG_DFMODE_MASK & workSpace->wsDRBG.mode) == actCTRDRBG_DFMODE_USE_BLOCKCIPHER_DF){
    if(entropyLength < requiredEntropyLengthDF){
      retVal = ESL_ERC_RNG_ENTROPY_TOO_SMALL;
    }
  }
  else{
    if(entropyLength != requiredEntropyLengthNoDF){
      retVal = ESL_ERC_RNG_ENTROPY_TOO_SMALL;
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_seedCTRDRBG_checkInput(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  eslt_Length entropyLength){
  eslt_ErrorCode retVal;

  retVal = esl_CTRDRBG_checkMode(workSpace->wsDRBG.mode);

  if(retVal == ESL_ERC_NO_ERROR){
    retVal = esl_seedCTRDRBG_checkEntropySize(workSpace, entropyLength);
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_getBytesCTRDRBG_checkInput(
  eslt_DRBGMode modeDRBG
   ,  eslt_Length requestedLength
   ,  eslt_Length maxRequestLength
   ,  eslt_Length additionalInputLength){
  eslt_ErrorCode retVal;

  retVal = esl_CTRDRBG_checkMode(modeDRBG);

  if(retVal == ESL_ERC_NO_ERROR){
    if(requestedLength > maxRequestLength){
      retVal = ESL_ERC_REQUESTED_LENGTH_INVALID;
    }
  }

  if(retVal == ESL_ERC_NO_ERROR){
    retVal = esl_CTRDRBG_checkInputLengthNoDF(modeDRBG, additionalInputLength);
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_reseed_CTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;
  actRETURNCODE actRetVal;
  actDrbgSeedInputType dataInput;

  dataInput.input[actDRBGSEED_INPUT_PARAM1].dataPtr = entropyPtr;
  dataInput.input[actDRBGSEED_INPUT_PARAM1].length = (actLengthType)entropyLength;
  dataInput.elements = 1u;

  if(additionalInputPtr != NULL_PTR){
    retVal = esl_CTRDRBG_checkInputLengthNoDF(workSpace->wsDRBG.mode, additionalInputLength);
    if(retVal == ESL_ERC_NO_ERROR){
      dataInput.input[actDRBGSEED_INPUT_PARAM2].dataPtr = additionalInputPtr;
      dataInput.input[actDRBGSEED_INPUT_PARAM2].length = (actLengthType)additionalInputLength;
      dataInput.elements++;
    }
  }

  if(retVal == ESL_ERC_NO_ERROR){
    actRetVal = actAesCtrDrbgInstantiation(&(workSpace->wsDRBG), &dataInput, TRUE, workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_INPUT_LENGTH){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else{
      workSpace->wsDRBG.seedState = ESL_DRBG_SEED_STATUS_SEEDED;

    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initialSeed_CTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) noncePtr
   ,  eslt_Length nonceLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) personalizationStringPtr
   ,  eslt_Length personalizationStringLength){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;
  actRETURNCODE actRetVal;
  actDrbgSeedInputType dataInput;

  dataInput.input[actDRBGSEED_INPUT_PARAM1].dataPtr = entropyPtr;
  dataInput.input[actDRBGSEED_INPUT_PARAM1].length = (actLengthType)entropyLength;
  dataInput.elements = 1u;

  if((actDRBG_DFMODE_MASK & workSpace->wsDRBG.mode) == actCTRDRBG_DFMODE_USE_BLOCKCIPHER_DF){
    if(noncePtr != NULL_PTR){
      dataInput.input[actDRBGSEED_INPUT_PARAM2].dataPtr = noncePtr;
      dataInput.input[actDRBGSEED_INPUT_PARAM2].length = (actLengthType)nonceLength;
      dataInput.elements++;
    }
    else{
      retVal = ESL_ERC_PARAMETER_INVALID;
    }
  }

  if(retVal == ESL_ERC_NO_ERROR){
    if(personalizationStringPtr != NULL_PTR){
      retVal = esl_CTRDRBG_checkInputLengthNoDF(workSpace->wsDRBG.mode, personalizationStringLength);

      if(retVal == ESL_ERC_NO_ERROR)
      {
        dataInput.input[dataInput.elements].dataPtr = personalizationStringPtr;
        dataInput.input[dataInput.elements].length = (actLengthType)personalizationStringLength;
        dataInput.elements++;
      }
    }
  }

  if(retVal == ESL_ERC_NO_ERROR){
    actRetVal = actAesCtrDrbgInstantiation(&(workSpace->wsDRBG), &dataInput, FALSE, workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_INPUT_LENGTH){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else{
      workSpace->wsDRBG.seedState = ESL_DRBG_SEED_STATUS_SEEDED;

    }
  }

  return retVal;
}

#endif

#if(VSECPRIM_HASH_DRBG_ENABLED == STD_ON)

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_seedHASHDRBG_checkInput(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  eslt_Length entropyLength){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  if(workSpace->wsDRBG.mode != actDRBGMODE_HASHDRBG_SHA512){
    retVal = ESL_ERC_MODE_INVALID;
  }
  else{
    if(entropyLength < actBitsToBytes(actHASHDRBG_SECURITY_STRENGTH)){
      retVal = ESL_ERC_RNG_ENTROPY_TOO_SMALL;
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_getBytesHASHDRBG_checkInput(
  eslt_DRBGMode modeDRBG
   ,  eslt_Length requestedLength
   ,  eslt_Length maxRequestLength){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  if(modeDRBG != actDRBGMODE_HASHDRBG_SHA512){
    retVal = ESL_ERC_MODE_INVALID;
  }
  else{
    if(requestedLength > maxRequestLength){
      retVal = ESL_ERC_REQUESTED_LENGTH_INVALID;
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initialSeed_HASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) noncePtr
   ,  eslt_Length nonceLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) personalizationStringPtr
   ,  eslt_Length personalizationStringLength){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;
  actDrbgSeedInputType dataInput;

  if(noncePtr == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    dataInput.input[actDRBGSEED_INPUT_PARAM1].dataPtr = entropyPtr;
    dataInput.input[actDRBGSEED_INPUT_PARAM1].length = (actLengthType)entropyLength;

    dataInput.input[actDRBGSEED_INPUT_PARAM2].dataPtr = noncePtr;
    dataInput.input[actDRBGSEED_INPUT_PARAM2].length = (actLengthType)nonceLength;
    dataInput.elements = 2u;

    if(personalizationStringPtr != NULL_PTR){
      dataInput.input[actDRBGSEED_INPUT_PARAM3].dataPtr = personalizationStringPtr;
      dataInput.input[actDRBGSEED_INPUT_PARAM3].length = (actLengthType)personalizationStringLength;
      dataInput.elements++;
    }

    actHashDrbgInstantiation(&(workSpace->wsDRBG), &dataInput, workSpace->header.watchdog);

    workSpace->wsDRBG.seedState = ESL_DRBG_SEED_STATUS_SEEDED;

  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(void) esl_reseed_HASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength){
  actDrbgSeedInputType dataInput;
  actU8 firstElementToHash = actHASHDRBG_SEEDING_PREFIX2;

  dataInput.input[actDRBGSEED_INPUT_PARAM1].dataPtr = &firstElementToHash;
  dataInput.input[actDRBGSEED_INPUT_PARAM1].length = 1u;

  dataInput.input[actDRBGSEED_INPUT_PARAM2].dataPtr = workSpace->wsDRBG.variable;
  dataInput.input[actDRBGSEED_INPUT_PARAM2].length = ESL_HASHDRBG_SHA512_SEED_LEN;

  dataInput.input[actDRBGSEED_INPUT_PARAM3].dataPtr = entropyPtr;
  dataInput.input[actDRBGSEED_INPUT_PARAM3].length = (actLengthType)entropyLength;
  dataInput.elements = 3u;

  if(additionalInputPtr != NULL_PTR){
    dataInput.input[actDRBGSEED_INPUT_PARAM4].dataPtr = additionalInputPtr;
    dataInput.input[actDRBGSEED_INPUT_PARAM4].length = (actLengthType)additionalInputLength;
    dataInput.elements++;
  }

  actHashDrbgInstantiation(&(workSpace->wsDRBG), &dataInput, workSpace->header.watchdog);

  workSpace->wsDRBG.seedState = ESL_DRBG_SEED_STATUS_SEEDED;

}

#endif

#if VSECPRIM_CTR_DRBG_ENABLED == STD_ON

VSECPRIM_FUNC(eslt_ErrorCode) esl_initCTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  eslt_DRBGMode modeDRBG){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_CTRDRBG)) != ESL_ERC_NO_ERROR){
  }
  else{
    workSpace->wsDRBG.seedState = ESL_DRBG_SEED_STATUS_UNSEEDED;

    switch(modeDRBG){
    case ESL_DRBGMODE_CTRDRBG_AES128_NODF:
    case ESL_DRBGMODE_CTRDRBG_AES128_DF:
    case ESL_DRBGMODE_CTRDRBG_AES256_NODF:
    case ESL_DRBGMODE_CTRDRBG_AES256_DF:
      workSpace->wsDRBG.mode = modeDRBG;
      break;
    default:
      retVal = ESL_ERC_MODE_INVALID;
      break;
    }

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_CTRDRBG);

  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_seedCTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) noncePtr
   ,  eslt_Length nonceLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) personalizationStringPtr
   ,  eslt_Length personalizationStringLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (entropyPtr == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_CTRDRBG, ESL_WST_ALGO_CTRDRBG)) != ESL_ERC_NO_ERROR){
  }

  else if((retVal = esl_seedCTRDRBG_checkInput(workSpace, entropyLength)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(workSpace->wsDRBG.seedState == ESL_DRBG_SEED_STATUS_UNSEEDED){
      retVal = esl_initialSeed_CTRDRBG(workSpace, entropyPtr, entropyLength
   ,                                      noncePtr, nonceLength
   ,                                      personalizationStringPtr, personalizationStringLength);
    }

    else{
      retVal = esl_reseed_CTRDRBG(workSpace, entropyPtr, entropyLength
   ,                                 additionalInputPtr, additionalInputLength);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_getBytesCTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  eslt_Length requestedLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) outputBuffer
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (outputBuffer == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_CTRDRBG, ESL_WST_ALGO_CTRDRBG)) != ESL_ERC_NO_ERROR){
  }
  else if((retVal = esl_getBytesCTRDRBG_checkInput(workSpace->wsDRBG.mode, requestedLength, actAESCTRDRBG_MAX_OUTPUT_SIZE, additionalInputLength)) != ESL_ERC_NO_ERROR){
  }
  else if(workSpace->wsDRBG.seedState != ESL_DRBG_SEED_STATUS_SEEDED){
    retVal = ESL_ERC_ENTROPY_EXHAUSTION;
  }
  else{
    actRetVal = actAesCtrDrbgGenerate(&workSpace->wsDRBG, (actLengthType)requestedLength, outputBuffer
   ,                                     additionalInputPtr, (actLengthType)additionalInputLength
   ,                                     workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_ENTROPY_EXHAUSTION){
      retVal = ESL_ERC_ENTROPY_EXHAUSTION;
    }
    else if(actRetVal == actEXCEPTION_INPUT_LENGTH){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else{
      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_getStateCTRDRBG(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) internalStateBuffer
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) internalStateBufferLength
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGReseedCounterType) reseedCounter
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGSeedStatusType) seedStatus
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGMode) modeDRBG){
  eslt_ErrorCode retVal;
  eslt_Length localSeedLength, localKeyLength;

  if((workSpace == NULL_PTR) || (internalStateBuffer == NULL_PTR) || (internalStateBufferLength == NULL_PTR) ||
      (reseedCounter == NULL_PTR) || (seedStatus == NULL_PTR) || (modeDRBG == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    if((workSpace->wsDRBG.mode & actDRBG_ALGSIZE_MASK) == actCTRDRBG_ALGSIZE_AES128){
      localSeedLength = ESL_CTRDRBG_AES128_SEEDLEN;
      localKeyLength = ESL_SIZEOF_CTRDRBG_AES128_KEY;
    }
    else{
      localSeedLength = ESL_CTRDRBG_AES256_SEEDLEN;
      localKeyLength = ESL_SIZEOF_CTRDRBG_AES256_KEY;
    }

    if(*internalStateBufferLength < localSeedLength){
      retVal = ESL_ERC_BUFFER_TOO_SMALL;
    }
    else{
      if(workSpace->wsDRBG.seedState == ESL_DRBG_SEED_STATUS_UNSEEDED)
      {
        actMemClear(internalStateBuffer, localSeedLength);
        *reseedCounter = 0u;
      }
      else
      {
        actMemCpyByteArray(internalStateBuffer, workSpace->wsDRBG.key, localKeyLength);
        actMemCpyByteArray(&internalStateBuffer[localKeyLength], workSpace->wsDRBG.variable, ESL_SIZEOF_CTRDRBG_BLOCK);
        *reseedCounter = workSpace->wsDRBG.reseedCount;
      }

      *seedStatus = workSpace->wsDRBG.seedState;
      *modeDRBG = workSpace->wsDRBG.mode;
      *internalStateBufferLength = localSeedLength;
      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_restoreStateCTRDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceCTRDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) internalStateBuffer
   ,  eslt_Length internalStateBufferLength
   ,  eslt_DRBGReseedCounterType reseedCounter
   ,  eslt_DRBGSeedStatusType seedStatus
   ,  eslt_DRBGMode modeDRBG){
  eslt_ErrorCode retVal;
  eslt_Length localSeedLength, localKeyLength;

  if((workSpace == NULL_PTR) || (internalStateBuffer == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    if((workSpace->wsDRBG.mode & actDRBG_ALGSIZE_MASK) == actCTRDRBG_ALGSIZE_AES128){
      localSeedLength = ESL_CTRDRBG_AES128_SEEDLEN;
      localKeyLength = ESL_SIZEOF_CTRDRBG_AES128_KEY;
    }
    else{
      localSeedLength = ESL_CTRDRBG_AES256_SEEDLEN;
      localKeyLength = ESL_SIZEOF_CTRDRBG_AES256_KEY;
    }

    if(internalStateBufferLength != localSeedLength){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else{
      actMemCpyByteArray(workSpace->wsDRBG.key, internalStateBuffer, localKeyLength);
      actMemCpyByteArray(workSpace->wsDRBG.variable, &internalStateBuffer[localKeyLength], ESL_SIZEOF_CTRDRBG_BLOCK);
      workSpace->wsDRBG.reseedCount = reseedCounter;
      workSpace->wsDRBG.seedState = seedStatus;
      workSpace->wsDRBG.mode = modeDRBG;

      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

#endif

#if VSECPRIM_HASH_DRBG_ENABLED == STD_ON

VSECPRIM_FUNC(eslt_ErrorCode) esl_initHASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  eslt_DRBGMode modeDRBG){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_HASHDRBG)) != ESL_ERC_NO_ERROR){
  }
  else{
    workSpace->wsDRBG.seedState = ESL_DRBG_SEED_STATUS_UNSEEDED;

    switch(modeDRBG){
    case ESL_DRBGMODE_HASHDRBG_SHA512:
      workSpace->wsDRBG.mode = modeDRBG;
      break;
    default:
      retVal = ESL_ERC_MODE_INVALID;
      break;
    }

    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HASHDRBG);
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_seedHASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropyPtr
   ,  eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) noncePtr
   ,  eslt_Length nonceLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) personalizationStringPtr
   ,  eslt_Length personalizationStringLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (entropyPtr == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HASHDRBG, ESL_WST_ALGO_HASHDRBG)) != ESL_ERC_NO_ERROR){
  }
  else if((retVal = esl_seedHASHDRBG_checkInput(workSpace, entropyLength)) != ESL_ERC_NO_ERROR){
  }
  else{
    if(workSpace->wsDRBG.seedState == ESL_DRBG_SEED_STATUS_UNSEEDED){
      retVal = esl_initialSeed_HASHDRBG(workSpace, entropyPtr, entropyLength, noncePtr, nonceLength
   ,       personalizationStringPtr, personalizationStringLength);
    }

    else{
      esl_reseed_HASHDRBG(workSpace, entropyPtr, entropyLength, additionalInputPtr, additionalInputLength);

    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_getBytesHASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  eslt_Length requestedLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) outputBuffer
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) additionalInputPtr
   ,  eslt_Length additionalInputLength){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (outputBuffer == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HASHDRBG, ESL_WST_ALGO_HASHDRBG)) != ESL_ERC_NO_ERROR){
  }
  else if((retVal = esl_getBytesHASHDRBG_checkInput(workSpace->wsDRBG.mode, requestedLength, actHASHDRBG_MAX_OUTPUT_SIZE)) != ESL_ERC_NO_ERROR){
  }
  else if(workSpace->wsDRBG.seedState != ESL_DRBG_SEED_STATUS_SEEDED){
    retVal = ESL_ERC_ENTROPY_EXHAUSTION;
  }
  else{
    actRetVal = actHashDrbgGenerate(&workSpace->wsDRBG, requestedLength, outputBuffer
   ,     additionalInputPtr, additionalInputLength, workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_ENTROPY_EXHAUSTION){
      retVal = ESL_ERC_ENTROPY_EXHAUSTION;
    }
    else{
      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_getStateHASHDRBG(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) internalStateBuffer
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) internalStateBufferLength
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGReseedCounterType) reseedCounter
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGSeedStatusType) seedStatus
   ,  VSECPRIM_P2VAR_PARA(eslt_DRBGMode) modeDRBG){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (internalStateBuffer == NULL_PTR) || (internalStateBufferLength == NULL_PTR) ||
    (reseedCounter == NULL_PTR) || (seedStatus == NULL_PTR) || (modeDRBG == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    if(*internalStateBufferLength < (2u*ESL_HASHDRBG_SHA512_SEED_LEN)){
      retVal = ESL_ERC_BUFFER_TOO_SMALL;
    }
    else{
      if(workSpace->wsDRBG.seedState == ESL_DRBG_SEED_STATUS_UNSEEDED)
      {
        actMemClear(internalStateBuffer, (2u* ESL_HASHDRBG_SHA512_SEED_LEN));
        *reseedCounter = 0u;
      }
      else
      {
        actMemCpyByteArray(internalStateBuffer, workSpace->wsDRBG.constant, ESL_HASHDRBG_SHA512_SEED_LEN);
        actMemCpyByteArray(&internalStateBuffer[ESL_HASHDRBG_SHA512_SEED_LEN], workSpace->wsDRBG.variable, ESL_HASHDRBG_SHA512_SEED_LEN);
        *reseedCounter = workSpace->wsDRBG.reseedCount;
      }

      *seedStatus = workSpace->wsDRBG.seedState;
      *modeDRBG = workSpace->wsDRBG.mode;
      *internalStateBufferLength = 2u*ESL_HASHDRBG_SHA512_SEED_LEN;
      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_restoreStateHASHDRBG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHASHDRBG) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) internalStateBuffer
   ,  eslt_Length internalStateBufferLength
   ,  eslt_DRBGReseedCounterType reseedCounter
   ,  eslt_DRBGSeedStatusType seedStatus
   ,  eslt_DRBGMode modeDRBG){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (internalStateBuffer == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    if(internalStateBufferLength < (2u * ESL_HASHDRBG_SHA512_SEED_LEN)){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
    else{
      actMemCpyByteArray(workSpace->wsDRBG.constant, internalStateBuffer, ESL_HASHDRBG_SHA512_SEED_LEN);
      actMemCpyByteArray(workSpace->wsDRBG.variable, &internalStateBuffer[ESL_HASHDRBG_SHA512_SEED_LEN], ESL_HASHDRBG_SHA512_SEED_LEN);
      workSpace->wsDRBG.reseedCount = reseedCounter;
      workSpace->wsDRBG.seedState = seedStatus;
      workSpace->wsDRBG.mode = modeDRBG;

      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

