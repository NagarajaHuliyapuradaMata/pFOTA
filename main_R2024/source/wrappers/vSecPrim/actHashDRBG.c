

#define ACT_HASHDRBG_SOURCE

#include "actIDRBG.hpp"
#include "actDRBGCommon.hpp"
#include "actISHA2_64.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTHASHDRBG_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actHashDrbgAdd(
  VSECPRIM_P2CONST_PARA(actU8) bufferA,
  VSECPRIM_P2CONST_PARA(actU8) bufferB,
  actLengthType bufferBLength,
  VSECPRIM_P2VAR_PARA(actU8) result);

VSECPRIM_LOCAL_FUNC(void) actHashDrbgAddWorkSpaceValues(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace);

VSECPRIM_LOCAL_FUNC(void) actHashDrbgDF(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) inputString,
  actLengthType numberOfBitsToReturn,
  VSECPRIM_P2VAR_PARA(actU8) outputString,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actHashDrbgGeneratePrepareV(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actU8) additionalInputPtr,
  actLengthType additionalInputLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actHashDrbgHashGen(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace,
  actLengthType requestedLength,
  VSECPRIM_P2VAR_PARA(actU8) outputBuffer,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actHashDrbgAdd(
  VSECPRIM_P2CONST_PARA(actU8) bufferA,
  VSECPRIM_P2CONST_PARA(actU8) bufferB,
  actLengthType bufferBLength,
  VSECPRIM_P2VAR_PARA(actU8) result){
  actLengthType i;
  actU16 tmp = 0u;

  for (i = 1; i <= bufferBLength; i++){
    tmp = ((actU16)bufferA[actHASHDRBG_SHA512_SEED_LEN - i]) + bufferB[bufferBLength - i] + actGetU8fromU16(tmp, 2u);
    result[actHASHDRBG_SHA512_SEED_LEN - i] = (actU8)tmp;
  }

  for (i = bufferBLength + 1u; i <= actHASHDRBG_SHA512_SEED_LEN; i++){
    tmp = ((actU16)bufferA[actHASHDRBG_SHA512_SEED_LEN - i]) + actGetU8fromU16(tmp, 2u);
    result[actHASHDRBG_SHA512_SEED_LEN - i] = (actU8)tmp;
  }
}

VSECPRIM_LOCAL_FUNC(void) actHashDrbgAddWorkSpaceValues(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace){
  actU8 reseedCounter[actDRBG_SIZEOF_INPUTLENGTH];

  actHashDrbgAdd(workSpace->variable, workSpace->tmpdigest, actHASH_SIZE_SHA512, workSpace->variable);

  actHashDrbgAdd(workSpace->variable, workSpace->constant, actHASHDRBG_SHA512_SEED_LEN, workSpace->variable);

  actU32toBE(reseedCounter, workSpace->reseedCount);
  actHashDrbgAdd(workSpace->variable, reseedCounter, actDRBG_SIZEOF_INPUTLENGTH, workSpace->variable);
}

VSECPRIM_LOCAL_FUNC(void) actHashDrbgDF(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) inputString,
  actLengthType numberOfBitsToReturn,
  VSECPRIM_P2VAR_PARA(actU8) outputString,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 i, counter;
  actLengthType j, len;
  actU8 startHashData[actDRBG_SIZEOF_INPUTLENGTH + 1u];

  actMemClear(workSpace->DFtmp, (2u * actHASH_SIZE_SHA512));

  len = ((numberOfBitsToReturn + actBytesToBits(actHASHDRBG_SHA512_OUTLEN) - 1u) / actBytesToBits(actHASHDRBG_SHA512_OUTLEN));

  counter = 0x01u;

  actU32toBE(&startHashData[1], numberOfBitsToReturn);

  for (j = 0u; j < len; j++){
    startHashData[0] = counter;

    (void)actSHA512Init(&workSpace->wsSHA512);
    (void)actSHA512Update(&workSpace->wsSHA512, startHashData, (actDRBG_SIZEOF_INPUTLENGTH + 1u), watchdog);

    for (i = 0u; i < inputString->elements; i++){
      (void)actSHA512Update(&workSpace->wsSHA512, inputString->input[i].dataPtr, inputString->input[i].length, watchdog);
    }

    (void)actSHA512Finalize(&workSpace->wsSHA512, &workSpace->DFtmp[j*actHASH_SIZE_SHA512], watchdog);
    counter += 1u;
  }

  actMemCpyByteArray(outputString, workSpace->DFtmp, actBitsToBytes(numberOfBitsToReturn));

}

VSECPRIM_LOCAL_FUNC(void) actHashDrbgHashGen(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace,
  actLengthType requestedLength,
  VSECPRIM_P2VAR_PARA(actU8) outputBuffer,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType i, m, remainingLength;

  VSECPRIM_P2VAR_PARA(actU8) data = workSpace->hashdata;
  VSECPRIM_P2VAR_PARA(actU8) w = workSpace->tmpdigest;

  actMemCpyByteArray(data, workSpace->variable, actHASHDRBG_SHA512_SEED_LEN);

  m = (requestedLength + actHASHDRBG_SHA512_OUTLEN - 1u) / actHASHDRBG_SHA512_OUTLEN;

  if(m > 0u){
    remainingLength = requestedLength;

    for (i = 0u; i < (m - 1u); i++){
      (void)actSHA512Init(&workSpace->wsSHA512);

      (void)actSHA512Update(&workSpace->wsSHA512, data, actHASHDRBG_SHA512_SEED_LEN, watchdog);
      (void)actSHA512Finalize(&workSpace->wsSHA512, &outputBuffer[i*actHASH_SIZE_SHA512], watchdog);
      actDrbgIncrementBlock(data, actHASHDRBG_SHA512_SEED_LEN);

      remainingLength -= actHASH_SIZE_SHA512;
    }

    (void)actSHA512Init(&workSpace->wsSHA512);
    (void)actSHA512Update(&workSpace->wsSHA512, data, actHASHDRBG_SHA512_SEED_LEN, watchdog);
    (void)actSHA512Finalize(&workSpace->wsSHA512, w, watchdog);
    actMemCpyByteArray(&outputBuffer[(m - 1u)*actHASH_SIZE_SHA512], w, remainingLength);

  }

}

VSECPRIM_LOCAL_FUNC(void) actHashDrbgGeneratePrepareV(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actU8) additionalInputPtr,
  actLengthType additionalInputLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actDrbgSeedInputType hashInputString;
  actLengthType j;
  actU8 firstElementToHash;

  firstElementToHash = actHASHDRBG_GENERATE_PREFIX1;

  hashInputString.input[actDRBGSEED_INPUT_PARAM1].dataPtr = &firstElementToHash;
  hashInputString.input[actDRBGSEED_INPUT_PARAM1].length = 1u;

  hashInputString.input[actDRBGSEED_INPUT_PARAM2].dataPtr = workSpace->variable;
  hashInputString.input[actDRBGSEED_INPUT_PARAM2].length = actHASHDRBG_SHA512_SEED_LEN;

  hashInputString.input[actDRBGSEED_INPUT_PARAM3].dataPtr = additionalInputPtr;
  hashInputString.input[actDRBGSEED_INPUT_PARAM3].length = additionalInputLength;
  hashInputString.elements = 3u;

  (void)actSHA512Init(&workSpace->wsSHA512);

  for (j = 0u; j < hashInputString.elements; j++){
    (void)actSHA512Update(&workSpace->wsSHA512, hashInputString.input[j].dataPtr, hashInputString.input[j].length, watchdog);
  }

  (void)actSHA512Finalize(&workSpace->wsSHA512, workSpace->tmpdigest, watchdog);

  actHashDrbgAdd(workSpace->variable, workSpace->tmpdigest, actHASH_SIZE_SHA512, workSpace->variable);
}

VSECPRIM_FUNC(void) actHashDrbgInstantiation(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace,
  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) seedMaterial,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actDrbgSeedInputType hashDFInputConstant;
  actU8 firstElementToHash = actHASHDRBG_SEEDING_PREFIX1;
  actLengthType seedLen = (actLengthType)actHASHDRBG_SHA512_SEED_LEN;
  actLengthType numberOfBitsToReturn = actBytesToBits(seedLen);

  actHashDrbgDF(workSpace, seedMaterial, numberOfBitsToReturn, workSpace->variable, watchdog);

  hashDFInputConstant.input[actDRBGSEED_INPUT_PARAM1].dataPtr = &firstElementToHash;
  hashDFInputConstant.input[actDRBGSEED_INPUT_PARAM1].length = 1u;

  hashDFInputConstant.input[actDRBGSEED_INPUT_PARAM2].dataPtr = workSpace->variable;
  hashDFInputConstant.input[actDRBGSEED_INPUT_PARAM2].length = actHASHDRBG_SHA512_SEED_LEN;
  hashDFInputConstant.elements = 2u;

  actHashDrbgDF(workSpace, &hashDFInputConstant, numberOfBitsToReturn, workSpace->constant, watchdog);

  workSpace->reseedCount = 1u;

}

VSECPRIM_FUNC(actRETURNCODE) actHashDrbgGenerate(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace,
  actLengthType requestedLength,
  VSECPRIM_P2VAR_PARA(actU8) outputBuffer,
  VSECPRIM_P2CONST_PARA(actU8) additionalInputPtr,
  actLengthType additionalInputLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;
  actU8 firstValueToHash = actHASHDRBG_GENERATE_PREFIX2;

  if(actHASHDRBG_RESEED_INTERVAL > workSpace->reseedCount){
    if((additionalInputPtr != NULL_PTR) && (additionalInputLength > 0u)){
      actHashDrbgGeneratePrepareV(workSpace, additionalInputPtr, additionalInputLength, watchdog);
    }

    actHashDrbgHashGen(workSpace, requestedLength, outputBuffer, watchdog);

    (void)actSHA512Init(&workSpace->wsSHA512);

    (void)actSHA512Update(&workSpace->wsSHA512, &firstValueToHash, 1u, watchdog);
    (void)actSHA512Update(&workSpace->wsSHA512, workSpace->variable, actHASHDRBG_SHA512_SEED_LEN, watchdog);
    (void)actSHA512Finalize(&workSpace->wsSHA512, workSpace->tmpdigest, watchdog);

    actHashDrbgAddWorkSpaceValues(workSpace);

    workSpace->reseedCount++;

  }
  else{
    workSpace->seedState = actDRBG_SEED_STATE_NEED_RESEED;
    retVal = actEXCEPTION_ENTROPY_EXHAUSTION;
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

