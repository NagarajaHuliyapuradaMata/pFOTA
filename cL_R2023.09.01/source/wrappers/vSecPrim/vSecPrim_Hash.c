

#define VSECPRIM_HASH_SOURCE

#include "vSecPrim.hpp"

#if(VSECPRIM_HASH_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, eslt_Byte) vSecPrim_digestSizes[VSECPRIM_NUMBER_OF_HASH_FUNCTIONS] = {
    ESL_SIZEOF_SHA1_DIGEST
   ,   ESL_SIZEOF_SHA224_DIGEST
   ,   ESL_SIZEOF_SHA256_DIGEST
   ,   ESL_SIZEOF_SHA384_DIGEST
   ,   ESL_SIZEOF_SHA512_DIGEST
   ,   ESL_SIZEOF_SHA512_224_DIGEST
   ,   ESL_SIZEOF_SHA512_256_DIGEST
   ,   ESL_SIZEOF_SHA3_224_DIGEST
   ,   ESL_SIZEOF_SHA3_256_DIGEST
   ,   ESL_SIZEOF_SHA3_384_DIGEST
   ,   ESL_SIZEOF_SHA3_512_DIGEST
   ,   ESL_SIZEOF_SHAKE128_DIGEST
   ,   ESL_SIZEOF_SHAKE256_DIGEST
   ,   ESL_SIZEOF_RIPEMD160_DIGEST
   ,   ESL_SIZEOF_MD5_DIGEST
};

#define VSECPRIM_STOP_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) vSecPrim_switchHashIDInit(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  vSecPrimType_HashAlgorithm hashID);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) vSecPrim_switchHashIDUpdate(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  eslt_Length inputLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) vSecPrim_switchHashIDFinalize(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) vSecPrim_finalizeHashWithLengthHandling(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest
   ,  const eslt_Length maxDigestLength);

VSECPRIM_LOCAL_FUNC(void) vSecPrim_updateHashMapReturnValue(
  VSECPRIM_P2VAR_PARA(eslt_ErrorCode) retVal
   ,  eslt_ErrorCode referenceRetVal);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) vSecPrim_finalizeHashLengthCheck(
  VSECPRIM_P2CONST_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength
   ,  const eslt_Length maxDigestLength
   ,  VSECPRIM_P2VAR_PARA(boolean) truncateDigest);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) vSecPrim_switchHashIDInit(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  vSecPrimType_HashAlgorithm hashID){
  eslt_ErrorCode retVal = ESL_ERC_NO_ERROR;

  switch(hashID){
#if(VSECPRIM_SHA1_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_SHA1:

    (void)esl_initWorkSpaceHeader(&(workSpace->wsHash.wsSHA1.header), ESL_MAXSIZEOF_WS_SHA1, (workSpace->header.watchdog));

    (void)esl_initSHA1(&(workSpace->wsHash.wsSHA1));
    break;
#endif

#if(VSECPRIM_SHA2_256_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_SHA2_224:

    (void)esl_initWorkSpaceHeader(&(workSpace->wsHash.wsSHA2_224.header), ESL_MAXSIZEOF_WS_SHA224, (workSpace->header.watchdog));

    (void)esl_initSHA224(&(workSpace->wsHash.wsSHA2_224));
    break;

  case VSECPRIM_DIGEST_SHA2_256:

    (void)esl_initWorkSpaceHeader(&(workSpace->wsHash.wsSHA2_256.header), ESL_MAXSIZEOF_WS_SHA256, (workSpace->header.watchdog));

    (void)esl_initSHA256(&(workSpace->wsHash.wsSHA2_256));
    break;
#endif

#if(VSECPRIM_SHA2_512_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_SHA2_384:

    (void)esl_initWorkSpaceHeader(&(workSpace->wsHash.wsSHA2_384.header), ESL_MAXSIZEOF_WS_SHA384, (workSpace->header.watchdog));

    (void)esl_initSHA384(&(workSpace->wsHash.wsSHA2_384));
    break;

  case VSECPRIM_DIGEST_SHA2_512:

    (void)esl_initWorkSpaceHeader(&(workSpace->wsHash.wsSHA2_512.header), ESL_MAXSIZEOF_WS_SHA512, (workSpace->header.watchdog));

    (void)esl_initSHA512(&(workSpace->wsHash.wsSHA2_512));
    break;

  case VSECPRIM_DIGEST_SHA2_512_224:

    (void)esl_initWorkSpaceHeader(&(workSpace->wsHash.wsSHA2_512_224.header), ESL_MAXSIZEOF_WS_SHA512_224, (workSpace->header.watchdog));

    (void)esl_initSHA512_224(&(workSpace->wsHash.wsSHA2_512_224));
    break;

  case VSECPRIM_DIGEST_SHA2_512_256:

    (void)esl_initWorkSpaceHeader(&(workSpace->wsHash.wsSHA2_512_256.header), ESL_MAXSIZEOF_WS_SHA512_256, (workSpace->header.watchdog));

    (void)esl_initSHA512_256(&(workSpace->wsHash.wsSHA2_512_256));
    break;
#endif

#if(VSECPRIM_SHA3_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_SHA3_224:
  case VSECPRIM_DIGEST_SHA3_256:
  case VSECPRIM_DIGEST_SHA3_384:
  case VSECPRIM_DIGEST_SHA3_512:

    (void)esl_initWorkSpaceHeader(&(workSpace->wsHash.wsSHA3.header), ESL_MAXSIZEOF_WS_SHA3, (workSpace->header.watchdog));

    (void)esl_initSHA3(&(workSpace->wsHash.wsSHA3), (Esl_BytesToBits((eslt_Length)vSecPrim_digestSizes[hashID])));
    break;

  case VSECPRIM_DIGEST_SHAKE_128:
  case VSECPRIM_DIGEST_SHAKE_256:

    (void)esl_initWorkSpaceHeader(&(workSpace->wsHash.wsSHAKE.header), ESL_MAXSIZEOF_WS_SHAKE, (workSpace->header.watchdog));

    (void)esl_initSHAKE(&(workSpace->wsHash.wsSHAKE), (Esl_BytesToBits(Esl_DivideByTwo((eslt_Length)(vSecPrim_digestSizes[hashID])))));
    break;
#endif

#if(VSECPRIM_RIPEMD160_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_RIPEMD160:

    (void)esl_initWorkSpaceHeader(&(workSpace->wsHash.wsRIPEMD160.header), ESL_MAXSIZEOF_WS_RIPEMD160, (workSpace->header.watchdog));

    (void)esl_initRIPEMD160(&(workSpace->wsHash.wsRIPEMD160));
    break;
#endif

#if(VSECPRIM_MD5_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_MD5:

    (void)esl_initWorkSpaceHeader(&(workSpace->wsHash.wsMD5.header), ESL_MAXSIZEOF_WS_MD5, (workSpace->header.watchdog));

    (void)esl_initMD5(&(workSpace->wsHash.wsMD5));
    break;
#endif

  default:
    retVal = ESL_ERC_INPUT_INVALID;
    break;
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) vSecPrim_switchHashIDUpdate(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  eslt_Length inputLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;

  switch(workSpace->hashID){
#if(VSECPRIM_SHA1_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_SHA1:
    retVal = esl_updateSHA1(&(workSpace->wsHash.wsSHA1), inputLength, input);
    vSecPrim_updateHashMapReturnValue(&retVal, ESL_ERC_SHA1_TOTAL_LENGTH_OVERFLOW);
    break;
#endif

#if(VSECPRIM_SHA2_256_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_SHA2_224:
    retVal = esl_updateSHA224(&(workSpace->wsHash.wsSHA2_224), inputLength, input);
    vSecPrim_updateHashMapReturnValue(&retVal, ESL_ERC_SHA256_TOTAL_LENGTH_OVERFLOW);
    break;

  case VSECPRIM_DIGEST_SHA2_256:
    retVal = esl_updateSHA256(&(workSpace->wsHash.wsSHA2_256), inputLength, input);
    vSecPrim_updateHashMapReturnValue(&retVal, ESL_ERC_SHA256_TOTAL_LENGTH_OVERFLOW);
    break;
#endif

#if(VSECPRIM_SHA2_512_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_SHA2_384:
    retVal = esl_updateSHA384(&(workSpace->wsHash.wsSHA2_384), inputLength, input);
    vSecPrim_updateHashMapReturnValue(&retVal, ESL_ERC_SHA384_TOTAL_LENGTH_OVERFLOW);
    break;

  case VSECPRIM_DIGEST_SHA2_512:
    retVal = esl_updateSHA512(&(workSpace->wsHash.wsSHA2_512), inputLength, input);
    break;

  case VSECPRIM_DIGEST_SHA2_512_224:
    retVal = esl_updateSHA512_224(&(workSpace->wsHash.wsSHA2_512_224), inputLength, input);
    break;

  case VSECPRIM_DIGEST_SHA2_512_256:
    retVal = esl_updateSHA512_256(&(workSpace->wsHash.wsSHA2_512_256), inputLength, input);
    break;
#endif

#if(VSECPRIM_SHA3_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_SHA3_224:
  case VSECPRIM_DIGEST_SHA3_256:
  case VSECPRIM_DIGEST_SHA3_384:
  case VSECPRIM_DIGEST_SHA3_512:
    retVal = esl_updateSHA3(&(workSpace->wsHash.wsSHA3), inputLength, input);
    break;

  case VSECPRIM_DIGEST_SHAKE_128:
  case VSECPRIM_DIGEST_SHAKE_256:

    retVal = esl_updateSHAKE(&(workSpace->wsHash.wsSHAKE), inputLength, input);
    break;
#endif

#if(VSECPRIM_RIPEMD160_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_RIPEMD160:
    retVal = esl_updateRIPEMD160(&(workSpace->wsHash.wsRIPEMD160), inputLength, input);
    vSecPrim_updateHashMapReturnValue(&retVal, ESL_ERC_RIPEMD160_TOTAL_LENGTH_OVERFLOW);
    break;
#endif

#if(VSECPRIM_MD5_ENABLED == STD_ON)
  case VSECPRIM_DIGEST_MD5:
    retVal = esl_updateMD5(&(workSpace->wsHash.wsMD5), inputLength, input);
    break;
#endif

  default:
    retVal = ESL_ERC_INPUT_INVALID;
    break;

  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) vSecPrim_switchHashIDFinalize(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode retVal;
  boolean truncateDigest = FALSE;

  if(messageDigest == NULL_PTR){
    *messageDigestLength = vSecPrim_digestSizes[workSpace->hashID];
    retVal = ESL_ERC_NO_ERROR;
  }
  else{
#if(VSECPRIM_SHA3_ENABLED == STD_ON)

    switch(workSpace->hashID){
    case VSECPRIM_DIGEST_SHA3_224:
    case VSECPRIM_DIGEST_SHA3_256:
    case VSECPRIM_DIGEST_SHA3_384:
    case VSECPRIM_DIGEST_SHA3_512:

      retVal = vSecPrim_finalizeHashLengthCheck(workSpace, messageDigestLength
   ,       vSecPrim_digestSizes[workSpace->hashID], &truncateDigest);

      if(retVal == ESL_ERC_NO_ERROR)
      {
        retVal = esl_finalizeSHA3(&(workSpace->wsHash.wsSHA3), messageDigest, messageDigestLength);
      }

      break;

    case VSECPRIM_DIGEST_SHAKE_128:
    case VSECPRIM_DIGEST_SHAKE_256:

      retVal = vSecPrim_finalizeHashLengthCheck(workSpace, messageDigestLength
   ,       vSecPrim_digestSizes[workSpace->hashID], &truncateDigest);

      if(retVal == ESL_ERC_NO_ERROR)
      {
        retVal = esl_finalizeSHAKE(&(workSpace->wsHash.wsSHAKE), messageDigest, messageDigestLength);
      }

      break;

    default:
#else
    switch(workSpace->hashID){
    default:
#endif

      retVal = vSecPrim_finalizeHashWithLengthHandling(workSpace, messageDigestLength, messageDigest, vSecPrim_digestSizes[vSecPrimMin(workSpace->hashID, (VSECPRIM_NUMBER_OF_HASH_FUNCTIONS-1u))]);
      VSECPRIM_DUMMY_STATEMENT(truncateDigest);
      break;
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) vSecPrim_finalizeHashWithLengthHandling(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest
   ,  const eslt_Length maxDigestLength){
  eslt_ErrorCode retVal;
  boolean truncateDigest;
  VSECPRIM_P2VAR_PARA(eslt_Byte) outputBuffer;

  retVal = vSecPrim_finalizeHashLengthCheck(workSpace, messageDigestLength, maxDigestLength, &truncateDigest);

  if(truncateDigest == TRUE){
    outputBuffer = workSpace->tempHash;
  }
  else{
    outputBuffer = messageDigest;
  }

  if(retVal == ESL_ERC_NO_ERROR){
    switch(workSpace->hashID){
#if(VSECPRIM_SHA1_ENABLED == STD_ON)
    case VSECPRIM_DIGEST_SHA1:

      retVal = esl_finalizeSHA1(&(workSpace->wsHash.wsSHA1), outputBuffer);
      break;
#endif

#if(VSECPRIM_SHA2_256_ENABLED == STD_ON)
    case VSECPRIM_DIGEST_SHA2_224:
      retVal = esl_finalizeSHA224(&(workSpace->wsHash.wsSHA2_224), outputBuffer);
      break;

    case VSECPRIM_DIGEST_SHA2_256:
      retVal = esl_finalizeSHA256(&(workSpace->wsHash.wsSHA2_256), outputBuffer);
      break;
#endif

#if(VSECPRIM_SHA2_512_ENABLED == STD_ON)
    case VSECPRIM_DIGEST_SHA2_384:
      retVal = esl_finalizeSHA384(&(workSpace->wsHash.wsSHA2_384), outputBuffer);
      break;

    case VSECPRIM_DIGEST_SHA2_512:
      retVal = esl_finalizeSHA512(&(workSpace->wsHash.wsSHA2_512), outputBuffer);
      break;

    case VSECPRIM_DIGEST_SHA2_512_224:
      retVal = esl_finalizeSHA512_224(&(workSpace->wsHash.wsSHA2_512_224), outputBuffer);
      break;

    case VSECPRIM_DIGEST_SHA2_512_256:
      retVal = esl_finalizeSHA512_256(&(workSpace->wsHash.wsSHA2_512_256), outputBuffer);
      break;
#endif

#if(VSECPRIM_RIPEMD160_ENABLED == STD_ON)
    case VSECPRIM_DIGEST_RIPEMD160:
      retVal = esl_finalizeRIPEMD160(&(workSpace->wsHash.wsRIPEMD160), outputBuffer);
      break;
#endif

#if(VSECPRIM_MD5_ENABLED == STD_ON)
    case VSECPRIM_DIGEST_MD5:
      retVal = esl_finalizeMD5(&(workSpace->wsHash.wsMD5), outputBuffer);
      break;
#endif

    default:
      retVal = ESL_ERC_INPUT_INVALID;
      break;
    }

    if((retVal == ESL_ERC_NO_ERROR) && (truncateDigest == TRUE)){
      Esl_MemCpyByteArray(messageDigest, outputBuffer, *messageDigestLength);
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(void) vSecPrim_updateHashMapReturnValue(
  VSECPRIM_P2VAR_PARA(eslt_ErrorCode) retVal
   ,  eslt_ErrorCode referenceRetVal){
  if(*retVal == referenceRetVal){
    *retVal = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
  }
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) vSecPrim_finalizeHashLengthCheck(
  VSECPRIM_P2CONST_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength
   ,  const eslt_Length maxDigestLength
   ,  VSECPRIM_P2VAR_PARA(boolean) truncateDigest){
  eslt_ErrorCode retVal;
  *truncateDigest = FALSE;

  if((workSpace->outputLengthFlag == VSECPRIM_PROVIDED_BUFFER_LENGTH_MATCHES_DESIRED_OUTPUT_LENGTH) &&
    (*messageDigestLength != maxDigestLength)){
    retVal = ESL_ERC_INPUT_INVALID;
  }

  else if((workSpace->outputLengthFlag == VSECPRIM_PROVIDED_BUFFER_LENGTH_MATCHES_OR_EXCEEDS_DESIRED_OUTPUT_LENGTH) &&
    (*messageDigestLength < maxDigestLength)){
    retVal = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
  }
  else{
    *messageDigestLength = vSecPrimMin(*messageDigestLength, maxDigestLength);

    if(*messageDigestLength < maxDigestLength){
      *truncateDigest = TRUE;
    }

    retVal = ESL_ERC_NO_ERROR;
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) vSecPrim_initHash(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  vSecPrimType_HashAlgorithm hashID
   ,  vSecPrimType_OutputBufferFlag outputLengthFlag){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((outputLengthFlag != VSECPRIM_PROVIDED_BUFFER_LENGTH_MATCHES_DESIRED_OUTPUT_LENGTH) &&
    (outputLengthFlag != VSECPRIM_PROVIDED_BUFFER_LENGTH_MATCHES_OR_EXCEEDS_DESIRED_OUTPUT_LENGTH) &&
    (outputLengthFlag != VSECPRIM_OUTPUT_TRUNCATION_ALLOWED)){
    retVal = ESL_ERC_INPUT_INVALID;
  }
  else{
    retVal = vSecPrim_switchHashIDInit(workSpace, hashID);

    if(retVal == ESL_ERC_NO_ERROR){
      workSpace->hashID = hashID;
      workSpace->outputLengthFlag = outputLengthFlag;

      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HASH);
      esl_SetWorkspaceSize(&workSpace->header, VSECPRIM_SIZEOF_WS_HASH);
      workSpace->updateCalled = VSECPRIM_UPDATE_NOT_YET_CALLED;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) vSecPrim_updateHash(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  const eslt_Length inputLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceState(&workSpace->header, ESL_WST_ALGO_HASH)) != ESL_ERC_NO_ERROR){
  }
  else{
    retVal = vSecPrim_switchHashIDUpdate(workSpace, inputLength, input);

    workSpace->updateCalled = VSECPRIM_UPDATE_CALLED;
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) vSecPrim_finalizeHash(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (messageDigestLength == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = (esl_CheckWorkSpaceState(&workSpace->header, ESL_WST_ALGO_HASH))) != ESL_ERC_NO_ERROR){
  }
  else{
    retVal = vSecPrim_switchHashIDFinalize(workSpace, messageDigestLength, messageDigest);

    if(messageDigest != NULL_PTR){
      esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsHash);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) vSecPrim_digestHash(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace
   ,  const eslt_Length inputLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (input == NULL_PTR) || (messageDigestLength == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }

  else if((retVal = esl_CheckWorkSpaceState(&workSpace->header, ESL_WST_ALGO_HASH)) != ESL_ERC_NO_ERROR){
  }

  else if(workSpace->updateCalled != VSECPRIM_UPDATE_NOT_YET_CALLED){
    retVal = ESL_ERC_WS_STATE_INVALID;
  }
  else if(messageDigest == NULL_PTR){
    retVal = vSecPrim_switchHashIDFinalize(workSpace, messageDigestLength, messageDigest);
  }
  else{
    retVal = vSecPrim_switchHashIDUpdate(workSpace, inputLength, input);

    if(retVal == ESL_ERC_NO_ERROR){
      retVal = vSecPrim_switchHashIDFinalize(workSpace, messageDigestLength, messageDigest);
      esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsHash);
    }
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

