

#define ESLIB_RSA_OAEP_DEC_SHA256_SOURCE

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

VSECPRIM_FUNC(eslt_ErrorCode) esl_initDecryptRSASHA256_OAEP(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPdec) workSpace,
                                                            eslt_Length keyPairModuleSize, VSECPRIM_P2CONST_PARA(eslt_Byte) keyPairModule, eslt_Length privateKeyExponentSize, VSECPRIM_P2CONST_PARA(eslt_Byte) privateKeyExponent){
  eslt_ErrorCode returnValue;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    if(workSpace->header.size < ESL_MAXSIZEOF_WS_RSA_OAEP_DEC){
      returnValue = ESL_ERC_WS_TOO_SMALL;
    }
    else{
      workSpace->wsHashUnion.SHA256ws.header.size = ESL_SIZEOF_WS_HASHUNION_RSA;
      workSpace->wsHashUnion.SHA256ws.header.watchdog = workSpace->header.watchdog;

      workSpace->wsRSADecPrim.header.size = (eslt_Length)(sizeof(eslt_WorkSpaceRSAdec_prim) - sizeof(eslt_WorkSpaceHeader));
      workSpace->wsRSADecPrim.header.watchdog = workSpace->header.watchdog;
      returnValue = esl_initDecryptRSA_prim(&(workSpace->wsRSADecPrim), keyPairModuleSize, keyPairModule, privateKeyExponentSize, privateKeyExponent);
    }

    if(ESL_ERC_NO_ERROR == returnValue){
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_RSA);

      workSpace->modulusSizeInformation = keyPairModuleSize;
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decodeRSASHA256_OAEP(VSECPRIM_P2VAR_PARA(eslt_WorkSpace) workSpace, eslt_Length encodedMessageSize,
                                                       eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label,
                                                       VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message){
  eslt_ErrorCode returnValue;
  eslt_Length index;
  eslt_Byte combinedValue;
  eslt_Length dummy;
  eslt_Length psLength;
  eslt_Length dbLength;
  eslt_Length messageLength;
  VSECPRIM_P2VAR_PARA(eslt_Byte) encodedMessage;
  VSECPRIM_P2VAR_PARA(eslt_Byte) db;
  VSECPRIM_P2CONST_PARA(eslt_Byte) maskedDb;
  VSECPRIM_P2VAR_PARA(eslt_Byte) maskedSeed;
  VSECPRIM_P2CONST_PARA(eslt_Byte) ps;

  returnValue = ESL_ERC_NO_ERROR;

  if((workSpace == NULL_PTR) || ((label == NULL_PTR) && (labelSize > 0u)) || (messageSize == NULL_PTR) || (message == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    encodedMessage = workSpace->encodedMessageBufferPtr->encodedMessage;
    db = workSpace->encodedMessageBufferPtr->dataBlock;

    if(encodedMessageSize < (2u * (ESL_RSA_OAEP_SIZEOF_HASH + 1u))){
      returnValue = ESL_ERC_RSA_MESSAGE_OUT_OF_RANGE;
    }

    if(ESL_ERC_NO_ERROR == returnValue){
      dbLength = encodedMessageSize - (ESL_RSA_OAEP_SIZEOF_HASH + 1u);

      maskedDb = &encodedMessage[ESL_RSA_OAEP_SIZEOF_HASH + 1u];

      maskedSeed = &encodedMessage[1u];

      returnValue = esl_generateMaskMGF1RSASHA256_PSS(&(workSpace->wsHashUnionPtr->SHA256ws), workSpace->encodedMessageBufferPtr->tempVariables,
                                                      dbLength, maskedDb, ESL_RSA_OAEP_SIZEOF_HASH, db);

      if(ESL_ERC_NO_ERROR == returnValue)
      {
        actXOR(maskedSeed, db, ESL_RSA_OAEP_SIZEOF_HASH);

        returnValue = esl_generateMaskMGF1RSASHA256_PSS(&(workSpace->wsHashUnionPtr->SHA256ws), workSpace->encodedMessageBufferPtr->tempVariables,
                                                        ESL_RSA_OAEP_SIZEOF_HASH, maskedSeed, dbLength, db);
      }

      if(ESL_ERC_NO_ERROR == returnValue)
      {
        actXOR(db, maskedDb, dbLength);

        ESL_RSA_OAEP_INIT_HASH_FCT(&(workSpace->wsHashUnionPtr->SHA256ws));

        if(labelSize > 0u)
        {
          if(actOK != ESL_RSA_OAEP_UPDATE_HASH_FCT(&(workSpace->wsHashUnionPtr->SHA256ws), labelSize, label))
          {
            returnValue = ESL_ERC_SHA256_TOTAL_LENGTH_OVERFLOW;
          }
        }

        if(ESL_ERC_NO_ERROR == returnValue)
        {
          ESL_RSA_OAEP_FINALIZE_HASH_FCT(&(workSpace->wsHashUnionPtr->SHA256ws), maskedSeed);
        }
      }

      if(ESL_ERC_NO_ERROR == returnValue)
      {
        ps = &db[ESL_RSA_OAEP_SIZEOF_HASH];

        psLength = 0u;
        dummy = 0u;
        combinedValue = 0x00u;

        for (index = 0u; index < (dbLength - ESL_RSA_OAEP_SIZEOF_HASH); index++)
        {
          combinedValue |= ps[index];

          if(0x00u == combinedValue)
          {
            psLength++;
          }
          else
          {
            dummy++;
          }
        }

        if(0x01u != ps[psLength])
        {
          returnValue = ESL_ERC_RSA_ENCODING_INVALID;
        }

        else if(0x00u != encodedMessage[0u])
        {
          returnValue = ESL_ERC_RSA_ENCODING_INVALID;
        }

        else if(TRUE != actMemcmp(db, maskedSeed, ESL_RSA_OAEP_SIZEOF_HASH))
        {
          returnValue = ESL_ERC_RSA_ENCODING_INVALID;
        }
        else
        {
          messageLength = dbLength - (psLength + ESL_RSA_OAEP_SIZEOF_HASH + 1u);

          if(*messageSize < messageLength)
          {
            returnValue = ESL_ERC_OUTPUT_SIZE_TOO_SHORT;
          }
          else
          {
            *messageSize = messageLength;
            actMemCpyByteArray(message, &ps[psLength + 1u], messageLength);
          }
        }
      }
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSASHA256_OAEP_Label(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPdec) workSpace,
                                                              eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher,
                                                              eslt_Length labelSize, VSECPRIM_P2CONST_PARA(eslt_Byte) label,
                                                              VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message){
  eslt_ErrorCode returnValue;

  VSECPRIM_P2VAR_PARA(eslt_Byte) encodedMessage;
  eslt_Length keyPairModuleSize;
  eslt_Length encodedMessageSize;

  if(workSpace == NULL_PTR){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    keyPairModuleSize = workSpace->modulusSizeInformation;
    encodedMessage = workSpace->encodedMessageBuffer.encodedMessage;

    encodedMessageSize = keyPairModuleSize;

    returnValue = esl_decryptRSA_prim(&(workSpace->wsRSADecPrim), cipherSize, cipher, &encodedMessageSize, encodedMessage);

    if(ESL_ERC_NO_ERROR == returnValue){
      eslt_WorkSpace wsDecoding;
      wsDecoding.encodedMessageBufferPtr = &(workSpace->encodedMessageBuffer);
      wsDecoding.wsHashUnionPtr = &(workSpace->wsHashUnion);
      wsDecoding.modulusInformationPtr = &(workSpace->modulusSizeInformation);

      returnValue = esl_decodeRSASHA256_OAEP(&wsDecoding, encodedMessageSize, labelSize, label, messageSize, message);
    }
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_decryptRSASHA256_OAEP(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRSAOAEPdec) workSpace,
                                                        eslt_Length cipherSize, VSECPRIM_P2CONST_PARA(eslt_Byte) cipher,
                                                        VSECPRIM_P2VAR_PARA(eslt_Length) messageSize, VSECPRIM_P2VAR_PARA(eslt_Byte) message){
  return esl_decryptRSASHA256_OAEP_Label(workSpace, cipherSize, cipher, 0u, NULL_PTR, messageSize, message);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

