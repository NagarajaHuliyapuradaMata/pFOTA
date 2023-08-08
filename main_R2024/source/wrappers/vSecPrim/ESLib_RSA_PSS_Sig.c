

#define ESLIB_RSA_PSS_SIG_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "ESLib_RSA_Common.hpp"

#include "actIRSA.hpp"
#include "actBigNum.hpp"

#if(VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON)
# define VSECPRIM_WRAPPER_SHA1
#endif
#if(VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON)
# define VSECPRIM_WRAPPER_SHA256
#endif
#if(VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON)
# define VSECPRIM_WRAPPER_RIPEMD160
#endif

#if((VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON) )

# define ESL_RSA_PSS_TRAILER                                          (0xBCu)

typedef eslt_WorkSpaceUnionHashFunctions_RSA eslt_WorkSpaceUnionHashFunctions;
# include "actHashFctWrappers_Implementation.hpp"

# define VSECPRIM_START_SEC_CONST_8BIT
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_NONE, eslt_Byte) esl_RSAPSSEncodingMask[8] =
{
  0xFFu, 0x01u, 0x03u, 0x07u, 0x0Fu, 0x1Fu, 0x3Fu, 0x7Fu
};

# define VSECPRIM_STOP_SEC_CONST_8BIT
# include "CompilerCfg_vSecPrim.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkSaltSizeSig(
  eslt_Length saltSize,
  eslt_Length dbLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkSignatureSize(
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
  eslt_Length emLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_FillDataBlock(
  VSECPRIM_P2VAR_PARA(eslt_Byte) db,
  VSECPRIM_P2VAR_PARA(eslt_Byte) dbSalt,
  eslt_Length saltSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
  eslt_Length psLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initSignRSA_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
   eslt_Length keyPairModuleSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule,
   eslt_Length privateKeyExponentSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent,
   eslt_HashAlgorithm hashID);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_updateSignRSA_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
   eslt_Length inputSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
   eslt_HashAlgorithm hashID);

VSECPRIM_LOCAL_FUNC(void) esl_finalizeHashSignRSA_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
   VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest,
   eslt_HashAlgorithm hashID);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSA_PSS(
   VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
   VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
   eslt_Length hashDigestSize,
   eslt_Length saltSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
   VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
   VSECPRIM_P2VAR_PARA(eslt_Byte) signature,
   eslt_HashAlgorithm hashID);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkSaltSizeSig(
  eslt_Length saltSize,
  eslt_Length dbLength){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  if((saltSize + 1u) > dbLength){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }

  return returnValue;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_checkSignatureSize(
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
  eslt_Length emLength){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  if(*signatureSize < emLength){
    returnValue = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
  }
  else{
    *signatureSize = emLength;
  }

  return returnValue;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_FillDataBlock(
  VSECPRIM_P2VAR_PARA(eslt_Byte) db,
  VSECPRIM_P2VAR_PARA(eslt_Byte) dbSalt,
  eslt_Length saltSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
  eslt_Length psLength){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  actMemClear(db, psLength);
  db[psLength] = 0x01u;

  if(saltSize > 0u){
    if(salt == NULL_PTR){
      returnValue = esl_getBytesRNG(saltSize, dbSalt);
    }
    else{
      actMemCpyByteArray(dbSalt, salt, saltSize);
    }
  }

  return returnValue;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initSignRSA_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  eslt_Length keyPairModuleSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule,
  eslt_Length privateKeyExponentSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent,
  eslt_HashAlgorithm hashID){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if((keyPairModule == NULL_PTR) || (privateKeyExponent == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    (void)actHashInit(&(workSpace->wsHashUnion), hashID);

    workSpace->wsRSASigPrim.header.size = (eslt_Length)(ESL_MAXSIZEOF_WS_RSA_PRIM);
    workSpace->wsRSASigPrim.header.watchdog = workSpace->header.watchdog;
    returnValue = esl_initSignRSA_prim(&(workSpace->wsRSASigPrim),
                                       keyPairModuleSize, keyPairModule,
                                       privateKeyExponentSize, privateKeyExponent);

    if(returnValue == ESL_ERC_NO_ERROR){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);

      workSpace->modulusSizeInformation = keyPairModuleSize;
    }
  }
  return returnValue;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_updateSignRSA_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  eslt_Length inputSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
  eslt_HashAlgorithm hashID){
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

VSECPRIM_LOCAL_FUNC(void) esl_finalizeHashSignRSA_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest,
  eslt_HashAlgorithm hashID){
  (void)actHashFinalize(&(workSpace->wsHashUnion), messageDigest, hashID);
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSA_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
  eslt_Length hashDigestSize,
  eslt_Length saltSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature,
  eslt_HashAlgorithm hashID){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  eslt_Length saltLength;
  eslt_Size32 emBits;
  eslt_Length emLength, psLength, dbLength = 0u;

  VSECPRIM_P2VAR_PARA(eslt_Byte) saltedHash;
  VSECPRIM_P2VAR_PARA(eslt_Byte) db;
  VSECPRIM_P2VAR_PARA(eslt_Byte) dbSalt;

  saltLength = ((saltSize == (eslt_Length)-1) ? hashDigestSize : saltSize);
  db = &(workSpace->encodedMessageBuffer.dataBlock[0]);

  emBits = actRSAPrivateKeyGetBitLength(&(workSpace->wsRSASigPrim.wsRSAPrimBuf.wsRSARing)) - 1u;
  emLength = actMin((eslt_Length)((emBits + 7u) / 8u), Esl_BitsToBytes(ESL_RSA_KEYSIZE));
  returnValue = esl_checkSignatureSize(signatureSize, emLength);

  if(returnValue == ESL_ERC_NO_ERROR){
    if(emLength < (hashDigestSize + 1u)){
      returnValue = ESL_ERC_RSA_ENCODING_INVALID;
    }
    else{
      dbLength = emLength - hashDigestSize - 1u;
      saltedHash = &(workSpace->encodedMessageBuffer.encodedMessage[dbLength]);

      returnValue = esl_checkSaltSizeSig(saltLength, dbLength);

      if(returnValue == ESL_ERC_NO_ERROR)
      {
        psLength = dbLength - saltLength - 1u;

        dbSalt = &db[psLength + 1u];
        returnValue = esl_FillDataBlock(db, dbSalt, saltLength, salt, psLength);

        if(returnValue == ESL_ERC_NO_ERROR)
        {
          returnValue = esl_calcSaltedHashRSA_PSS(&(workSpace->wsHashUnion), saltLength, dbSalt,
            messageDigest, hashDigestSize, saltedHash, hashID);
        }
      }

      if(returnValue == ESL_ERC_NO_ERROR)
      {
        returnValue = esl_generateMaskMGF1(hashID, &(workSpace->wsHashUnion),
          workSpace->encodedMessageBuffer.tempVariables, hashDigestSize,
          hashDigestSize, saltedHash, dbLength,
          workSpace->encodedMessageBuffer.encodedMessage);
      }
    }
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    actXOR(workSpace->encodedMessageBuffer.encodedMessage, db, dbLength);

    (workSpace->encodedMessageBuffer.encodedMessage)[0u] &= esl_RSAPSSEncodingMask[emBits & 0x07u];

    (workSpace->encodedMessageBuffer.encodedMessage)[emLength - 1u] = ESL_RSA_PSS_TRAILER;

    returnValue = esl_signRSA_prim(&(workSpace->wsRSASigPrim), workSpace->modulusSizeInformation,
      workSpace->encodedMessageBuffer.encodedMessage, signatureSize, signature);
  }

  return returnValue;
}

# if(VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSASHA1_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  eslt_Length keyPairModuleSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule,
  eslt_Length privateKeyExponentSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_RSA_PSS_SIG)) != ESL_ERC_NO_ERROR){
  }
  else{
    workSpace->wsHashUnion.SHA1ws.header.size = ESL_MAXSIZEOF_WS_SHA1;
    workSpace->wsHashUnion.SHA1ws.header.watchdog = workSpace->header.watchdog;
    returnValue = esl_initSignRSA_PSS(workSpace, keyPairModuleSize, keyPairModule,
                                      privateKeyExponentSize, privateKeyExponent, ESL_HA_SHA1);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSASHA1_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
eslt_Length inputSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_updateSignRSA_PSS(workSpace, inputSize, input, ESL_HA_SHA1);
    if(returnValue == ESL_ERC_TOTAL_LENGTH_OVERFLOW){
      returnValue = ESL_ERC_SHA1_TOTAL_LENGTH_OVERFLOW;
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashSignRSASHA1_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;

  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    esl_finalizeHashSignRSA_PSS(workSpace, messageDigest, ESL_HA_SHA1);
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA1_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
eslt_Length saltSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  if((workSpace == NULL_PTR) || (signatureSize == NULL_PTR) || (signature == NULL_PTR) || (messageDigest == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_finalizeSigSignRSA_PSS(workSpace, messageDigest, ESL_SIZEOF_SHA1_DIGEST, saltSize,
                                             salt, signatureSize, signature, ESL_HA_SHA1);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA1_PSS_NoSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSigSignRSASHA1_PSS(workSpace, messageDigest, 0u, NULL_PTR, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA1_PSS_DigestLengthSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSigSignRSASHA1_PSS(workSpace, messageDigest, ESL_SIZEOF_SHA1_DIGEST, NULL_PTR,
                                               signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA1_PSS(VSECPRIM_P2VAR_PARA(
  eslt_WorkSpaceRSAPSSsig) workSpace,
  eslt_Length saltSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  eslt_Byte hash[ESL_SIZEOF_SHA1_DIGEST];

  actMemClear(hash, ESL_SIZEOF_SHA1_DIGEST);

  if((workSpace == NULL_PTR) || (signatureSize == NULL_PTR) || (signature == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    (void)esl_finalizeHashSignRSASHA1_PSS(workSpace, hash);
    returnValue = esl_finalizeSigSignRSASHA1_PSS(workSpace, hash, saltSize, salt, signatureSize, signature);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA1_PSS_NoSalt(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
                                                                 VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
                                                                 VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSignRSASHA1_PSS(workSpace, 0u, NULL_PTR, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA1_PSS_DigestLengthSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSignRSASHA1_PSS(workSpace, ESL_SIZEOF_SHA1_DIGEST, NULL_PTR, signatureSize, signature);
  return returnValue;
}
# endif

# if(VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  eslt_Length keyPairModuleSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule,
  eslt_Length privateKeyExponentSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_RSA_PSS_SIG)) != ESL_ERC_NO_ERROR){
  }
  else{
    workSpace->wsHashUnion.SHA256ws.header.size = ESL_MAXSIZEOF_WS_SHA256;
    workSpace->wsHashUnion.SHA256ws.header.watchdog = workSpace->header.watchdog;
    returnValue = esl_initSignRSA_PSS(workSpace, keyPairModuleSize, keyPairModule,
                                      privateKeyExponentSize, privateKeyExponent, ESL_HA_SHA2_256);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  eslt_Length inputSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_updateSignRSA_PSS(workSpace, inputSize, input, ESL_HA_SHA2_256);
    if(returnValue == ESL_ERC_TOTAL_LENGTH_OVERFLOW){
      returnValue = ESL_ERC_SHA256_TOTAL_LENGTH_OVERFLOW;
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashSignRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;
  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    esl_finalizeHashSignRSA_PSS(workSpace, messageDigest, ESL_HA_SHA2_256);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
  eslt_Length saltSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  if((workSpace == NULL_PTR) || (signatureSize == NULL_PTR) || (signature == NULL_PTR) || (messageDigest == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_finalizeSigSignRSA_PSS(workSpace, messageDigest, ESL_SIZEOF_SHA256_DIGEST, saltSize,
                                             salt, signatureSize, signature, ESL_HA_SHA2_256);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA256_PSS_NoSalt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSigSignRSASHA256_PSS(workSpace, messageDigest, 0u, NULL_PTR, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSASHA256_PSS_DigestLengthSalt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSigSignRSASHA256_PSS(workSpace, messageDigest, ESL_SIZEOF_SHA256_DIGEST,
                                                 NULL_PTR, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA256_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  eslt_Length saltSize,
  VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  eslt_Byte hash[ESL_SIZEOF_SHA256_DIGEST];

  actMemClear(hash, ESL_SIZEOF_SHA256_DIGEST);

  if((workSpace == NULL_PTR) || (signatureSize == NULL_PTR) || (signature == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    (void)esl_finalizeHashSignRSASHA256_PSS(workSpace, hash);
     returnValue = esl_finalizeSigSignRSASHA256_PSS(workSpace, hash, saltSize, salt, signatureSize, signature);
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA256_PSS_NoSalt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSignRSASHA256_PSS(workSpace, 0u, NULL_PTR, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSASHA256_PSS_DigestLengthSalt(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
  VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSignRSASHA256_PSS(workSpace, ESL_SIZEOF_SHA256_DIGEST, NULL_PTR, signatureSize, signature);
  return returnValue;
}
# endif

# if(VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON)

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSignRSARIPEMD160_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
eslt_Length keyPairModuleSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule,
eslt_Length privateKeyExponentSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else if((returnValue = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_RSA_PSS_SIG)) != ESL_ERC_NO_ERROR){
  }
  else{
    workSpace->wsHashUnion.RIPEMD160ws.header.size = ESL_MAXSIZEOF_WS_RIPEMD160;
    workSpace->wsHashUnion.RIPEMD160ws.header.watchdog = workSpace->header.watchdog;
    returnValue = esl_initSignRSA_PSS(workSpace, keyPairModuleSize, keyPairModule,
                                      privateKeyExponentSize, privateKeyExponent, ESL_HA_RMD160);
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_updateSignRSARIPEMD160_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
eslt_Length inputSize,
VSECPRIM_P2CONST_PARA(eslt_Byte) input){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_updateSignRSA_PSS(workSpace, inputSize, input, ESL_HA_RMD160);
    if(returnValue == ESL_ERC_TOTAL_LENGTH_OVERFLOW){
      returnValue = ESL_ERC_RIPEMD160_TOTAL_LENGTH_OVERFLOW;
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashSignRSARIPEMD160_PSS(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;
  if((workSpace == NULL_PTR) || (messageDigest == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    esl_finalizeHashSignRSA_PSS(workSpace, messageDigest, ESL_HA_RMD160);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSARIPEMD160_PSS(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
                                                                  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
                                                                  eslt_Length saltSize,
                                                                  VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
                                                                  VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
                                                                  VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  if((workSpace == NULL_PTR) || (signatureSize == NULL_PTR) || (signature == NULL_PTR) || (messageDigest == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    returnValue = esl_finalizeSigSignRSA_PSS(workSpace, messageDigest, ESL_SIZEOF_RIPEMD160_DIGEST, saltSize,
      salt, signatureSize, signature, ESL_HA_RMD160);
  }
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSARIPEMD160_PSS_NoSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSigSignRSARIPEMD160_PSS(workSpace, messageDigest, 0u, NULL_PTR, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSigSignRSARIPEMD160_PSS_DigestLengthSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest,
VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSigSignRSARIPEMD160_PSS(workSpace, messageDigest, ESL_SIZEOF_RIPEMD160_DIGEST, NULL_PTR,
                                              signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSARIPEMD160_PSS(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
                                                               eslt_Length saltSize,
                                                               VSECPRIM_P2CONST_PARA(eslt_Byte) salt,
                                                               VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
                                                               VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  eslt_Byte hash[ESL_SIZEOF_RIPEMD160_DIGEST];

  actMemClear(hash, ESL_SIZEOF_RIPEMD160_DIGEST);

  if((workSpace == NULL_PTR) || (signatureSize == NULL_PTR) || (signature == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    returnValue = esl_CheckWorkSpaceHeaderAndState(&(workSpace->header), ESL_MAXSIZEOF_WS_RSA_PSS_SIG, ESL_WST_ALGO_RSA);
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    (void)esl_finalizeHashSignRSARIPEMD160_PSS(workSpace, hash);
    returnValue = esl_finalizeSigSignRSARIPEMD160_PSS(workSpace, hash, saltSize, salt, signatureSize, signature);
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSARIPEMD160_PSS_NoSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSignRSARIPEMD160_PSS(workSpace, 0u, NULL_PTR, signatureSize, signature);
  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeSignRSARIPEMD160_PSS_DigestLengthSalt(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAPSSsig) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Length) signatureSize,
VSECPRIM_P2VAR_PARA(eslt_Byte) signature){
  eslt_ErrorCode returnValue = ESL_ERC_ERROR;
  returnValue = esl_finalizeSignRSARIPEMD160_PSS(workSpace, ESL_SIZEOF_RIPEMD160_DIGEST,
                                                 NULL_PTR, signatureSize, signature);
  return returnValue;
}
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

