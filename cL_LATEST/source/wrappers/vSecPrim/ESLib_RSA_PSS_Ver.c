

#define ESLIB_RSA_PSS_VER_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "ESLib_RSA_Common.hpp"
#include "actIRSA.hpp"

#if(VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON)
#define VSECPRIM_WRAPPER_SHA1
#endif
#if(VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON)
#define VSECPRIM_WRAPPER_SHA256
#endif
#if(VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON)
#define VSECPRIM_WRAPPER_RIPEMD160
#endif

#if((VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON) )

#define ESL_RSA_PSS_TRAILER                                          (0xBCu)

typedef eslt_WorkSpaceUnionHashFunctions_RSA eslt_WorkSpaceUnionHashFunctions;
#include "actHashFctWrappers_Implementation.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkSaltSizeVer(
  VSECPRIM_P2VAR_PARA(eslt_Length) saltSize
   ,  eslt_Length dbLength
   ,  eslt_Length estimatedPSLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkStandardConditionsEncodedMessage(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceRSAver_prim) workSpace
   ,  eslt_Length signatureSize
   ,  eslt_Length keyPairModuleSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) encodedMessage
   ,  VSECPRIM_P2VAR_PARA(eslt_Size32) emBits
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) emLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initVerifyRSA_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length keyPairModuleSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent
   ,  eslt_HashAlgorithm hashID);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_updateVerifyRSA_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length inputSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  eslt_HashAlgorithm hashID);

VSECPRIM_LOCAL_FUNC(void) esl_finalizeHashVerifyRSA_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest
   ,  eslt_HashAlgorithm hashID);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSA_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length hashDigestSize
   ,  eslt_Length saltSize
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature
   ,  eslt_HashAlgorithm hashID);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkSaltSizeVer(
  VSECPRIM_P2VAR_PARA(eslt_Length) saltSize
   ,  eslt_Length dbLength
   ,  eslt_Length estimatedPSLength){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  if(*saltSize == (eslt_Length)-1){
    *saltSize = (dbLength - 1u) - estimatedPSLength;
  }

  if((*saltSize + 1u) > dbLength){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }

  return returnValue;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkStandardConditionsEncodedMessage(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceRSAver_prim) workSpace
   ,  eslt_Length signatureSize
   ,  eslt_Length keyPairModuleSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) encodedMessage
   ,  VSECPRIM_P2VAR_PARA(eslt_Size32) emBits
   ,  VSECPRIM_P2VAR_PARA(eslt_Length) emLength){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  if((signatureSize != keyPairModuleSize) || (ESL_RSA_PSS_TRAILER != encodedMessage[keyPairModuleSize - 1u])){
    returnValue = ESL_ERC_RSA_SIGNATURE_INVALID;
  }
  else{
    *emBits = actRSAPublicKeyGetBitLength(&(workSpace->wsRSAPrimBuf.wsRSARing)) - 1u;
    *emLength = (eslt_Length)((*emBits + 7u) / 8u);

    if((encodedMessage[0u] & (esl_RSAPSSEncodingMask[*emBits & 0x07u] ^ 0xFFu)) != 0x00u){
      returnValue = ESL_ERC_RSA_SIGNATURE_INVALID;
    }
  }

  return returnValue;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initVerifyRSA_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length keyPairModuleSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent
   ,  eslt_HashAlgorithm hashID){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  actRETURNCODE actReturnValue;

  if((keyPairModule == NULL_PTR) || (publicKeyExponent == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    actReturnValue = actHashInit(&(workSpace->wsHashUnion), hashID);

    if(actReturnValue == actOK){
      workSpace->wsRSAVerPrim.header.size = (eslt_Length)(ESL_MAXSIZEOF_WS_RSA_PRIM);
      workSpace->wsRSAVerPrim.header.watchdog = workSpace->header.watchdog;
      returnValue = esl_initVerifyRSA_prim(&(workSpace->wsRSAVerPrim), keyPairModuleSize, keyPairModule
   ,                                          publicKeyExponentSize, publicKeyExponent);
    }

    if(returnValue == ESL_ERC_NO_ERROR){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);

      workSpace->modulusSizeInformation = keyPairModuleSize;
    }
  }

  return returnValue;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_updateVerifyRSA_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length inputSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input
   ,  eslt_HashAlgorithm hashID){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;
  actRETURNCODE actReturnValue;

  if(input == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    actReturnValue = actHashUpdate(&(workSpace->wsHashUnion), input, inputSize, hashID);

    if(actReturnValue != actOK){
      returnValue = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return returnValue;
}

VSECPRIM_LOCAL_FUNC(void) esl_finalizeHashVerifyRSA_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest
   ,  eslt_HashAlgorithm hashID){
  (void)actHashFinalize(&(workSpace->wsHashUnion), messageDigest, hashID);
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSA_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length hashDigestSize
   ,  eslt_Length saltSize
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature
   ,  eslt_HashAlgorithm hashID){
  eslt_ErrorCode returnValue;
  eslt_Length keyPairModuleSize, saltLength;
  eslt_Length i;
  eslt_Size32 emBits = 0u;
  eslt_Length emLength = 0u;
  eslt_Length psLength, dbLength;

  VSECPRIM_P2CONST_PARA(eslt_Byte) saltedHash;
  VSECPRIM_P2VAR_PARA(eslt_Byte) db;
  VSECPRIM_P2CONST_PARA(eslt_Byte) dbSalt;
  VSECPRIM_P2VAR_PARA(eslt_Byte) tempHash;

  db = &(workSpace->encodedMessageBuffer.dataBlock[0]);
  tempHash = &(workSpace->encodedMessageBuffer.tempVariables[0]);

  saltLength = saltSize;
  keyPairModuleSize = workSpace->modulusSizeInformation;

  returnValue = esl_verifyRSA_prim(&(workSpace->wsRSAVerPrim), signatureSize, signature
   ,                                   &keyPairModuleSize, workSpace->encodedMessageBuffer.encodedMessage);

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_checkStandardConditionsEncodedMessage(&(workSpace->wsRSAVerPrim)
   ,                                                           signatureSize, keyPairModuleSize
   ,                                                           workSpace->encodedMessageBuffer.encodedMessage
   ,                                                           &emBits, &emLength);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    if(emLength < (hashDigestSize + 2u)){
      returnValue = ESL_ERC_RSA_ENCODING_INVALID;
    }
    else{
      dbLength = emLength - hashDigestSize - 1u;
      saltedHash = &(workSpace->encodedMessageBuffer.encodedMessage[dbLength]);

      returnValue = esl_generateMaskMGF1(hashID, &(workSpace->wsHashUnion), tempHash, hashDigestSize, hashDigestSize
   ,       saltedHash, dbLength, db);

      if(returnValue == ESL_ERC_NO_ERROR)
      {
        actXOR(db, workSpace->encodedMessageBuffer.encodedMessage, dbLength);

        db[0u] &= esl_RSAPSSEncodingMask[emBits & 0x07u];

        for(i = 0u; i < (dbLength - 1u); i++)
        {
          if(0x00u != db[i])
          {
            break;
          }
        }

        returnValue = esl_checkSaltSizeVer(&saltLength, dbLength, i);

        if(returnValue == ESL_ERC_NO_ERROR)
        {
          psLength = dbLength - saltLength - 1u;

          dbSalt = &db[psLength + 1u];

          if((i != psLength) || (db[psLength] != 0x01u))
          {
            returnValue = ESL_ERC_RSA_SIGNATURE_INVALID;
          }
          else
          {
            returnValue = esl_calcSaltedHashRSA_PSS(&(workSpace->wsHashUnion), saltLength, dbSalt
   ,             messageDigest, hashDigestSize, tempHash, hashID);
          }
        }
      }

      if(returnValue == ESL_ERC_NO_ERROR)
      {
        if(actMemcmp(saltedHash, tempHash, hashDigestSize) != TRUE)
        {
          returnValue = ESL_ERC_RSA_SIGNATURE_INVALID;
        }
      }
    }
  }

  return returnValue;
}

#if(VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSASHA1_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length keyPairModuleSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule,
eslt_Length publicKeyExponentSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER)) != ESL_ERC_NO_ERROR){
  }
  else{
    workSpace->wsHashUnion.SHA1ws.header.size = ESL_MAXSIZEOF_WS_SHA1;
    workSpace->wsHashUnion.SHA1ws.header.watchdog = workSpace->header.watchdog;
    returnValue = esl_initVerifyRSA_PSS(workSpace, keyPairModuleSize, keyPairModule
   ,                                       publicKeyExponentSize, publicKeyExponent, ESL_HA_SHA1);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateVerifyRSASHA1_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length inputSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_updateVerifyRSA_PSS(workSpace, inputSize, input, ESL_HA_SHA1);
    if(returnValue == ESL_ERC_TOTAL_LENGTH_OVERFLOW){
      returnValue = ESL_ERC_SHA1_TOTAL_LENGTH_OVERFLOW;
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashVerifyRSASHA1_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    esl_finalizeHashVerifyRSA_PSS(workSpace, messageDigest, ESL_HA_SHA1);
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA1_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
eslt_Length saltSize,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR) || (signature == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_verifySigVerifyRSA_PSS(workSpace, messageDigest, ESL_SIZEOF_SHA1_DIGEST, saltSize
   ,                                            signatureSize, signature, ESL_HA_SHA1);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA1_PSS_AutoSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_verifySigVerifyRSASHA1_PSS(workSpace, messageDigest, (eslt_Length)-1, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA1_PSS_NoSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_verifySigVerifyRSASHA1_PSS(workSpace, messageDigest, 0u, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA1_PSS_DigestLengthSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_verifySigVerifyRSASHA1_PSS(workSpace, messageDigest, ESL_SIZEOF_SHA1_DIGEST
   ,                                              signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA1_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length saltSize,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  eslt_Byte hash[ESL_SIZEOF_SHA1_DIGEST];

  actMemClear(hash, ESL_SIZEOF_SHA1_DIGEST);

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    (void)esl_finalizeHashVerifyRSASHA1_PSS(workSpace, hash);
    returnValue = esl_verifySigVerifyRSASHA1_PSS(workSpace, hash, saltSize, signatureSize, signature);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA1_PSS_AutoSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeVerifyRSASHA1_PSS(workSpace, (eslt_Length)-1, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA1_PSS_NoSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeVerifyRSASHA1_PSS(workSpace, 0u, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA1_PSS_DigestLengthSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeVerifyRSASHA1_PSS(workSpace, ESL_SIZEOF_SHA1_DIGEST, signatureSize, signature);
  return returnValue;
}
#endif

#if(VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length keyPairModuleSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule
   ,  eslt_Length publicKeyExponentSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER)) != ESL_ERC_NO_ERROR){
  }
  else{
    workSpace->wsHashUnion.SHA256ws.header.size = ESL_MAXSIZEOF_WS_SHA256;
    workSpace->wsHashUnion.SHA256ws.header.watchdog = workSpace->header.watchdog;
    returnValue = esl_initVerifyRSA_PSS(workSpace, keyPairModuleSize, keyPairModule
   ,                                       publicKeyExponentSize, publicKeyExponent, ESL_HA_SHA2_256);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateVerifyRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length inputSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_updateVerifyRSA_PSS(workSpace, inputSize, input, ESL_HA_SHA2_256);
    if(returnValue == ESL_ERC_TOTAL_LENGTH_OVERFLOW){
      returnValue = ESL_ERC_SHA256_TOTAL_LENGTH_OVERFLOW;
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashVerifyRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;
  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    esl_finalizeHashVerifyRSA_PSS(workSpace, messageDigest, ESL_HA_SHA2_256);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length saltSize
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR) || (signature == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_verifySigVerifyRSA_PSS(workSpace, messageDigest, ESL_SIZEOF_SHA256_DIGEST
   ,                                            saltSize, signatureSize, signature, ESL_HA_SHA2_256);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA256_PSS_AutoSalt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue =esl_verifySigVerifyRSASHA256_PSS(workSpace, messageDigest, (eslt_Length)-1, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA256_PSS_NoSalt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_verifySigVerifyRSASHA256_PSS(workSpace, messageDigest, 0u, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSASHA256_PSS_DigestLengthSalt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_verifySigVerifyRSASHA256_PSS(workSpace, messageDigest, ESL_SIZEOF_SHA256_DIGEST
   ,                                                signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length saltSize
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  eslt_Byte hash[ESL_SIZEOF_SHA256_DIGEST];

  actMemClear(hash, ESL_SIZEOF_SHA256_DIGEST);

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    (void)esl_finalizeHashVerifyRSASHA256_PSS(workSpace, hash);
    returnValue = esl_verifySigVerifyRSASHA256_PSS(workSpace, hash, saltSize, signatureSize, signature);
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA256_PSS_AutoSalt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeVerifyRSASHA256_PSS(workSpace, (eslt_Length)-1, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA256_PSS_NoSalt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeVerifyRSASHA256_PSS(workSpace, 0u, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSASHA256_PSS_DigestLengthSalt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace
   ,  eslt_Length signatureSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeVerifyRSASHA256_PSS(workSpace, ESL_SIZEOF_SHA256_DIGEST, signatureSize, signature);
  return returnValue;
}

#endif

#if(VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_initVerifyRSARIPEMD160_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length keyPairModuleSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule,
eslt_Length publicKeyExponentSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER)) != ESL_ERC_NO_ERROR){
  }
  else{
    workSpace->wsHashUnion.RIPEMD160ws.header.size = ESL_MAXSIZEOF_WS_RIPEMD160;
    workSpace->wsHashUnion.RIPEMD160ws.header.watchdog = workSpace->header.watchdog;
    returnValue = esl_initVerifyRSA_PSS(workSpace, keyPairModuleSize, keyPairModule
   ,                                       publicKeyExponentSize, publicKeyExponent, ESL_HA_RMD160);
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateVerifyRSARIPEMD160_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length inputSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_updateVerifyRSA_PSS(workSpace, inputSize, input, ESL_HA_RMD160);
    if(returnValue == ESL_ERC_TOTAL_LENGTH_OVERFLOW){
      returnValue = ESL_ERC_RIPEMD160_TOTAL_LENGTH_OVERFLOW;
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashVerifyRSARIPEMD160_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;
  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    esl_finalizeHashVerifyRSA_PSS(workSpace, messageDigest, ESL_HA_RMD160);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSARIPEMD160_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
eslt_Length saltSize,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR) || (signature == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_verifySigVerifyRSA_PSS(workSpace, messageDigest, ESL_SIZEOF_RIPEMD160_DIGEST
   ,                                            saltSize, signatureSize, signature, ESL_HA_RMD160);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSARIPEMD160_PSS_AutoSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_verifySigVerifyRSARIPEMD160_PSS(workSpace, messageDigest, (eslt_Length)-1, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSARIPEMD160_PSS_NoSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_verifySigVerifyRSARIPEMD160_PSS(workSpace, messageDigest, 0u, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifySigVerifyRSARIPEMD160_PSS_DigestLengthSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_verifySigVerifyRSARIPEMD160_PSS(workSpace, messageDigest, ESL_SIZEOF_RIPEMD160_DIGEST
   ,                                                   signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSARIPEMD160_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length saltSize,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  eslt_Byte hash[ESL_SIZEOF_RIPEMD160_DIGEST];

  actMemClear(hash, ESL_SIZEOF_RIPEMD160_DIGEST);

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_VER, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    (void)esl_finalizeHashVerifyRSARIPEMD160_PSS(workSpace, hash);
    returnValue = esl_verifySigVerifyRSARIPEMD160_PSS(workSpace, hash, saltSize, signatureSize, signature);
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSARIPEMD160_PSS_AutoSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeVerifyRSARIPEMD160_PSS(workSpace, (eslt_Length)-1, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSARIPEMD160_PSS_NoSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeVerifyRSARIPEMD160_PSS(workSpace, 0u, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeVerifyRSARIPEMD160_PSS_DigestLengthSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSver) workSpace,
eslt_Length signatureSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeVerifyRSARIPEMD160_PSS(workSpace, ESL_SIZEOF_RIPEMD160_DIGEST, signatureSize, signature);
  return returnValue;
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

