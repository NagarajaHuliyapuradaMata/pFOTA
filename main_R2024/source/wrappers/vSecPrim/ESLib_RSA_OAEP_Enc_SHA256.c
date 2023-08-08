

#define ESLIB_RSA_OAEP_ENC_SHA256_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIRSA.hpp"
#include "actISHA2_32.hpp"

#if(VSECPRIM_RSA_OAEP_SHA2_256_ENABLED == STD_ON)

# define ESL_RSA_OAEP_INIT_HASH_FCT(workspace)                        (void)actSHA256Init(&((workspace)->wsSHA256))

# define ESL_RSA_OAEP_UPDATE_HASH_FCT(workspace, inputSize, input)    actSHA256Update(&((workspace)->wsSHA256), (VSECPRIM_P2CONST_PARA(actU8))(input), (actLengthType)(inputSize), (workspace)->header.watchdog)

# define ESL_RSA_OAEP_FINALIZE_HASH_FCT(workspace, messageDigest)     (void)actSHA256Finalize(&((workspace)->wsSHA256), (VSECPRIM_P2VAR_PARA(actU8))(messageDigest),  (workspace)->header.watchdog)

# define ESL_RSA_OAEP_SIZEOF_HASH                                     ESL_SIZEOF_SHA256_DIGEST

# define ESL_WS_RSA_OAEP_ED_BUFFERLENGTH                              ESL_WS_RSA_OAEP_ED_SHA256_BUFFERLENGTH

# define ESL_WS_RSA_OAEP_ED_BUFFER                                    ESL_WS_RSA_OAEP_ED_SHA256_BUFFER

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initEncryptRSASHA256_OAEP(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace,
                                                            eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule, eslt_Length publicKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) publicKeyExponent){
  eslt_ErrorCode returnValue;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    if(workSpace->header.size < ESL_MAXSIZEOF_WS_RSA_OAEP_ENC){
      returnValue = ESL_ERC_WS_TOO_SMALL;
    }
    else{
      workSpace->wsHashUnion.SHA256ws.header.size = ESL_SIZEOF_WS_HASHUNION_RSA;
      workSpace->wsHashUnion.SHA256ws.header.watchdog = workSpace->header.watchdog;

      workSpace->wsRSAEncPrim.header.size = (eslt_Length)(sizeof(eslt_WorkSpaceRSAenc_prim) - sizeof(eslt_WorkSpaceHeader));
      workSpace->wsRSAEncPrim.header.watchdog = workSpace->header.watchdog;
      returnValue = esl_initEncryptRSA_prim(&(workSpace->wsRSAEncPrim), keyPairModuleSize, keyPairModule, publicKeyExponentSize, publicKeyExponent);
    }

    if(ESL_ERC_NO_ERROR == returnValue){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);

      workSpace->modulusSizeInformation = keyPairModuleSize;
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA256_OAEP_Label_Seed(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace,
                                                                   eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message,
                                                                   eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label,
                                                                   eslt_Length inSeedSize, VSECPRIM_P2CONST_PARA(eslt_Byte) inSeed,
                                                                   VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher){
  eslt_ErrorCode returnValue;
  eslt_Length keyPairModuleSize;
  eslt_Length psLength;
  eslt_Length dbLength;
  eslt_Byte randomSeed[ESL_RSA_OAEP_SIZEOF_HASH];
  VSECPRIM_P2VAR_PARA(eslt_Byte) encodedMessage;
  VSECPRIM_P2VAR_PARA(eslt_Byte) db;
  VSECPRIM_P2VAR_PARA(eslt_Byte) maskedDb;
  VSECPRIM_P2VAR_PARA(eslt_Byte) maskedSeed;
  VSECPRIM_P2CONST_PARA(eslt_Byte) seed;
  VSECPRIM_P2VAR_PARA(eslt_Byte) ps;

  returnValue = ESL_ERC_NO_ERROR;

  if((workSpace == NULL_PTR) || (message == NULL_PTR) || ((label == NULL_PTR) && (labelSize > 0u))){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    keyPairModuleSize = workSpace->modulusSizeInformation;

    encodedMessage = workSpace->encodedMessageBuffer.encodedMessage;
    db = workSpace->encodedMessageBuffer.dataBlock;

    maskedSeed = &encodedMessage[1u];

    if(keyPairModuleSize < (2u * (ESL_RSA_OAEP_SIZEOF_HASH + 1u))){
      returnValue = ESL_ERC_RSA_MODULE_OUT_OF_RANGE;
    }
    else if(messageSize > (keyPairModuleSize - (2u * (ESL_RSA_OAEP_SIZEOF_HASH + 1u)))){
      returnValue = ESL_ERC_RSA_MESSAGE_OUT_OF_RANGE;
    }
    else{
      if(ESL_RSA_OAEP_SIZEOF_HASH != inSeedSize)
      {
        returnValue = ESL_ERC_PARAMETER_INVALID;
      }
    }

    if(ESL_ERC_NO_ERROR == returnValue){
      ESL_RSA_OAEP_INIT_HASH_FCT(&(workSpace->wsHashUnion.SHA256ws));

      if(labelSize > 0u)
      {
        if(actOK != ESL_RSA_OAEP_UPDATE_HASH_FCT(&(workSpace->wsHashUnion.SHA256ws), labelSize, label))
        {
          returnValue = ESL_ERC_SHA256_TOTAL_LENGTH_OVERFLOW;
        }
      }

      if(ESL_ERC_NO_ERROR == returnValue)
      {
        ESL_RSA_OAEP_FINALIZE_HASH_FCT(&(workSpace->wsHashUnion.SHA256ws), db);
      }
    }

    if(ESL_ERC_NO_ERROR == returnValue){
      dbLength = keyPairModuleSize - (ESL_RSA_OAEP_SIZEOF_HASH + 1u);

      maskedDb = &encodedMessage[ESL_RSA_OAEP_SIZEOF_HASH + 1u];

      psLength = dbLength - (messageSize + ESL_RSA_OAEP_SIZEOF_HASH + 1u);

      ps = &db[ESL_RSA_OAEP_SIZEOF_HASH];

      actMemClear(ps, psLength);
      ps[psLength] = 0x01u;

      actMemCpyByteArray(&ps[psLength + 1u], message, messageSize);

      if(inSeed == NULL_PTR)
      {
        returnValue = esl_getBytesRNG(ESL_RSA_OAEP_SIZEOF_HASH, randomSeed);
        seed = randomSeed;
      }
      else
      {
        seed = inSeed;
      }

      if(ESL_ERC_NO_ERROR == returnValue)
      {
        returnValue = esl_generateMaskMGF1RSASHA256_PSS(&(workSpace->wsHashUnion.SHA256ws), workSpace->encodedMessageBuffer.tempVariables,
                                                        ESL_RSA_OAEP_SIZEOF_HASH, seed, dbLength, maskedDb);
      }

      if(ESL_ERC_NO_ERROR == returnValue)
      {
        actXOR(maskedDb, db, dbLength);

        returnValue = esl_generateMaskMGF1RSASHA256_PSS(&(workSpace->wsHashUnion.SHA256ws), workSpace->encodedMessageBuffer.tempVariables,
                                                       dbLength, maskedDb, ESL_RSA_OAEP_SIZEOF_HASH, maskedSeed);
      }

      if(ESL_ERC_NO_ERROR == returnValue)
      {
        actXOR(maskedSeed, seed, ESL_RSA_OAEP_SIZEOF_HASH);

        encodedMessage[0u] = 0x00u;

        returnValue = esl_encryptRSA_prim(&(workSpace->wsRSAEncPrim), keyPairModuleSize, encodedMessage, cipherSize, cipher);
      }
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA256_OAEP(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace,
                                                        eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message,
                                                        VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher){
  return esl_encryptRSASHA256_OAEP_Label_Seed(workSpace, messageSize, message, 0u, NULL_PTR, ESL_RSA_OAEP_SIZEOF_HASH, NULL_PTR, cipherSize, cipher);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA256_OAEP_Seed(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace,
                                                             eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message,
                                                             eslt_Length inSeedSize, VSECPRIM_P2CONST_PARA(eslt_Byte) inSeed,
                                                             VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher){
  return esl_encryptRSASHA256_OAEP_Label_Seed(workSpace, messageSize, message, 0u, NULL_PTR, inSeedSize, inSeed, cipherSize, cipher);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_encryptRSASHA256_OAEP_Label(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPenc) workSpace,
                                                              eslt_Length messageSize, VSECPRIM_P2CONST_PARA(eslt_Byte) message,
                                                              eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label,
                                                              VSECPRIM_P2VAR_PARA(eslt_Length) cipherSize, VSECPRIM_P2VAR_PARA(eslt_Byte) cipher){
  return esl_encryptRSASHA256_OAEP_Label_Seed(workSpace, messageSize, message, labelSize, label, ESL_RSA_OAEP_SIZEOF_HASH, NULL_PTR, cipherSize, cipher);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

