

#define SEC_JOB_SOURCE

#include "Sec.hpp"

#include "CfgSwcServiceSecM.hpp"

#if defined ( SEC_ENABLE_CSM )
#include "SwcServiceCsm.hpp"
#endif

#if defined( SEC_ENABLE_JOB_MACVERIFY )         || \
    defined( SEC_ENABLE_JOB_MACGENERATE )       || \
    defined( SEC_ENABLE_JOB_ENCRYPTION )        || \
    defined( SEC_ENABLE_JOB_DECRYPTION )        || \
    defined( SEC_ENABLE_JOB_AEADDECRYPT )       || \
    defined( SEC_ENABLE_JOB_SIGNATUREVERIFY )   || \
    defined( SEC_ENABLE_JOB_KEYDERIVE )
#define SEC_ENABLE_JOB_INITKEY
#else
#define SEC_DISABLE_JOB_INITKEY
#endif

#if defined( SEC_ENABLE_JOB_AEADDECRYPT )
V_MEMRAM0 static V_MEMRAM1 SecM_ByteType V_MEMRAM2 SecM_AuthBufferData[SEC_BUFFER_AUTHDATA_SIZE];
V_MEMRAM0 static V_MEMRAM1 SecM_ByteType V_MEMRAM2 SecM_TagBufferData[SEC_BUFFER_TAGDATA_SIZE];
V_MEMRAM0 static V_MEMRAM1 SecM_RamBufferProcessingType V_MEMRAM2 SecM_AuthBuffer;
V_MEMRAM0 static V_MEMRAM1 SecM_RamBufferProcessingType V_MEMRAM2 SecM_TagBuffer;
V_MEMRAM0 static V_MEMRAM1 SecM_DecrStatusFsm V_MEMRAM2 SecM_AeadFsmSts;
V_MEMRAM0 static V_MEMRAM1 SecM_ByteType V_MEMRAM2 SecM_AeadAuthDataSent;
#endif

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

#if defined( SEC_ENABLE_JOB_INITKEY )
#if defined( SEC_ENABLE_JOB_INITKEY_AES )
static SecM_StatusType SecM_InitKeyAes(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr);
#endif
#if defined( SEC_ENABLE_JOB_INITKEY_MAC )
static SecM_StatusType SecM_InitKeyMac(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr);
#endif
#if defined( SEC_ENABLE_JOB_INITKEY_SYMMETRIC )
static SecM_StatusType SecM_InitKeySymmetric(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr);
#endif
#if defined( SEC_ENABLE_JOB_INITKEY_ASYMMETRIC )
static SecM_StatusType SecM_InitKeyAsymmetric(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr);
#endif
#if defined( SEC_ENABLE_JOB_INITKEY_PBKDF2 )
static SecM_StatusType SecM_InitKeyPBKDF2(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr);
#endif
static SecM_StatusType SecM_InitKey(SecM_JobInfoPtrType pJobInfo, SecM_VoidPtrType keyPtr);
#endif

#if defined( SEC_ENABLE_JOB_AEADDECRYPT )
static void SecM_DecryptAEADInit(SecM_JobInfoPtrType pJobInfo);
static SecM_StatusType SecM_DecryptAEAD(SecM_WordType jobId, V_MEMRAM1 SecM_OperationModeType V_MEMRAM2 V_MEMRAM3 * localMode
   ,  SecM_ConstRamDataType dataPtr, SecM_RamWordType dataLength, SecM_RamDataType resultPtr, SecM_RamWordType resultLengthPtr);
#endif

#if defined( SEC_ENABLE_JOB_INITKEY )
#if defined( SEC_ENABLE_JOB_INITKEY_AES )

static SecM_StatusType SecM_InitKeyAes(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr){
   SecM_StatusType result = SECM_OK;
   Std_ReturnType csmResult = E_OK;
   SecM_AesKeyType * aesKey;
   SecM_CryptographicKeyValuePtrType ivKeyElement;
   SecM_CryptographicKeyValuePtrType aesKeyElement;

   if(smhKeyId < SecM_GetSizeOfCryptogrphicKeys()){
      aesKey = (SecM_AesKeyType*)keyPtr;
      ivKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_CIPHER_IV);
      aesKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_CIPHER_KEY);

      if(ivKeyElement != NULL_PTR)
      {
         if((aesKey != NULL_PTR) && (aesKey->iv.size == ivKeyElement->size))
         {
            csmResult = Csm_KeyElementSet(csmKeyId, ivKeyElement->cryptoElementId, aesKey->iv.data, aesKey->iv.size);
         }
         else if(ivKeyElement->data != NULL_PTR)
         {
            csmResult = Csm_KeyElementSet(csmKeyId, ivKeyElement->cryptoElementId, ivKeyElement->data, ivKeyElement->size);
         }
         else
         {
         }
      }

      if(aesKeyElement != NULL_PTR)
      {
         if((aesKey != NULL_PTR) && (aesKey->key.size == aesKeyElement->size))
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, aesKeyElement->cryptoElementId, aesKey->key.data, aesKey->key.size);
         }
         else if(aesKeyElement->data != NULL_PTR)
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, aesKeyElement->cryptoElementId, aesKeyElement->data, aesKeyElement->size);
         }
         else
         {
         }
      }
   }

   if(csmResult != E_OK){
      result = SECM_NOT_OK;
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_INITKEY_MAC )

static SecM_StatusType SecM_InitKeyMac(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr){
   SecM_StatusType result = SECM_OK;
   Std_ReturnType csmResult = E_OK;
   SecM_SymKeyType * macKey;
   SecM_CryptographicKeyValuePtrType macKeyElement;

   if(smhKeyId < SecM_GetSizeOfCryptogrphicKeys()){
      macKey = (SecM_SymKeyType*)keyPtr;
      macKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_MAC_KEY);

      if(macKeyElement != NULL_PTR)
      {
         if((macKey != NULL_PTR) && (macKey->size == macKeyElement->size))
         {
            csmResult = Csm_KeyElementSet(csmKeyId, macKeyElement->cryptoElementId, macKey->data, macKey->size);
         }
         else if(macKeyElement->data != NULL_PTR)
         {
            csmResult = Csm_KeyElementSet(csmKeyId, macKeyElement->cryptoElementId, macKeyElement->data, macKeyElement->size);
         }
         else
         {
         }
      }
   }

   if(csmResult != E_OK){
      result = SECM_NOT_OK;
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_INITKEY_SYMMETRIC )

static SecM_StatusType SecM_InitKeySymmetric(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr){
   SecM_StatusType result = SECM_OK;
   Std_ReturnType csmResult = E_OK;
   SecM_SymKeyType * symKey;
   SecM_CryptographicKeyValuePtrType symKeyElement;

   if(smhKeyId < SecM_GetSizeOfCryptogrphicKeys()){
      symKey = (SecM_SymKeyType*)keyPtr;
      symKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_SIGNATURE_KEY);

      if(symKeyElement != NULL_PTR)
      {
         if((symKey != NULL_PTR) && (symKey->size == symKeyElement->size))
         {
            csmResult = Csm_KeyElementSet(csmKeyId, symKeyElement->cryptoElementId, symKey->data, symKey->size);
         }
         else if(symKeyElement->data != NULL_PTR)
         {
            csmResult = Csm_KeyElementSet(csmKeyId, symKeyElement->cryptoElementId, symKeyElement->data, symKeyElement->size);
         }
         else
         {
         }
      }
   }

   if(csmResult != E_OK){
      result = SECM_NOT_OK;
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_INITKEY_ASYMMETRIC )

static SecM_StatusType SecM_InitKeyAsymmetric(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr){
   SecM_StatusType result = SECM_OK;
   Std_ReturnType csmResult = E_OK;
   SecM_AsymKeyType * asymKey;
   SecM_CryptographicKeyValuePtrType sharedKeyElement;
   SecM_CryptographicKeyValuePtrType publicKeyElement;
   SecM_CryptographicKeyValuePtrType privateKeyElement;

   if(smhKeyId < SecM_GetSizeOfCryptogrphicKeys()){
      asymKey = (SecM_AsymKeyType*)keyPtr;
      sharedKeyElement = SecM_GetKeyValueByElementId(smhKeyId, SEC_KE_RSA_MODULUS);
      publicKeyElement = SecM_GetKeyValueByElementId(smhKeyId, SEC_KE_RSA_PUBLIC_EXPONENT);
      privateKeyElement = SecM_GetKeyValueByElementId(smhKeyId, SEC_KE_RSA_PRIVATE_EXPONENT);

      if(sharedKeyElement != NULL_PTR)
      {
         if((asymKey != NULL_PTR) && (asymKey->shared.size == sharedKeyElement->size))
         {
            csmResult = Csm_KeyElementSet(csmKeyId, sharedKeyElement->cryptoElementId, asymKey->shared.data, asymKey->shared.size);
         }
         else if(sharedKeyElement->data != NULL_PTR)
         {
            csmResult = Csm_KeyElementSet(csmKeyId, sharedKeyElement->cryptoElementId, sharedKeyElement->data, sharedKeyElement->size);
         }
         else
         {
         }
      }

      if(publicKeyElement != NULL_PTR)
      {
         if((asymKey != NULL_PTR) && (asymKey->individual.size == publicKeyElement->size))
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, publicKeyElement->cryptoElementId, asymKey->individual.data, asymKey->individual.size);
         }
         else if(publicKeyElement->data != NULL_PTR)
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, publicKeyElement->cryptoElementId, publicKeyElement->data, publicKeyElement->size);
         }
         else
         {
         }
      }

      if(privateKeyElement != NULL_PTR)
      {
         if((asymKey != NULL_PTR) && (asymKey->individual.size == privateKeyElement->size))
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, privateKeyElement->cryptoElementId, asymKey->individual.data, asymKey->individual.size);
         }
         else if(privateKeyElement->data != NULL_PTR)
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, privateKeyElement->cryptoElementId, privateKeyElement->data, privateKeyElement->size);
         }
         else
         {
         }
      }
   }

   if(csmResult != E_OK){
      result = SECM_NOT_OK;
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_INITKEY_PBKDF2 )

static SecM_StatusType SecM_InitKeyPBKDF2(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr){
   SecM_StatusType result = SECM_OK;
   Std_ReturnType csmResult = E_OK;
   SecM_PBKDF2KeyType * PBKDF2Key;
   SecM_CryptographicKeyValuePtrType iterationsKeyElement;
   SecM_CryptographicKeyValuePtrType saltKeyElement;
   SecM_CryptographicKeyValuePtrType passwordKeyElement;
   SecM_CryptographicKeyValuePtrType functionKeyElement;

   if(smhKeyId < SecM_GetSizeOfCryptogrphicKeys()){
      PBKDF2Key = (SecM_PBKDF2KeyType*)keyPtr;
      iterationsKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_KEYDERIVATION_ITERATIONS);
      saltKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_KEYDERIVATION_SALT);
      passwordKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD);
      functionKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_KEYDERIVATION_ALGORITHM);

      if(iterationsKeyElement != NULL_PTR)
      {
         if((PBKDF2Key != NULL_PTR) && (PBKDF2Key->iterations.size == iterationsKeyElement->size))
         {
            csmResult = Csm_KeyElementSet(csmKeyId, iterationsKeyElement->cryptoElementId, PBKDF2Key->iterations.data, PBKDF2Key->iterations.size);
         }
         else if(iterationsKeyElement->data != NULL_PTR)
         {
            csmResult = Csm_KeyElementSet(csmKeyId, iterationsKeyElement->cryptoElementId, iterationsKeyElement->data, iterationsKeyElement->size);
         }
         else
         {
         }
      }

      if(saltKeyElement != NULL_PTR)
      {
         if((PBKDF2Key != NULL_PTR) && (PBKDF2Key->salt.size == saltKeyElement->size))
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, saltKeyElement->cryptoElementId, PBKDF2Key->salt.data, PBKDF2Key->salt.size);
         }
         else if(saltKeyElement->data != NULL_PTR)
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, saltKeyElement->cryptoElementId, saltKeyElement->data, saltKeyElement->size);
         }
         else
         {
         }
      }

      if(passwordKeyElement != NULL_PTR)
      {
         if((PBKDF2Key != NULL_PTR) && (PBKDF2Key->password.size == passwordKeyElement->size))
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, passwordKeyElement->cryptoElementId, PBKDF2Key->password.data, PBKDF2Key->password.size);
         }
         else if(passwordKeyElement->data != NULL_PTR)
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, passwordKeyElement->cryptoElementId, passwordKeyElement->data, passwordKeyElement->size);
         }
         else
         {
         }
      }

      if(functionKeyElement != NULL_PTR)
      {
         if((PBKDF2Key != NULL_PTR) && (PBKDF2Key->function.size == functionKeyElement->size))
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, functionKeyElement->cryptoElementId, PBKDF2Key->function.data, PBKDF2Key->function.size);
         }
         else if(functionKeyElement->data != NULL_PTR)
         {
            csmResult |= Csm_KeyElementSet(csmKeyId, functionKeyElement->cryptoElementId, functionKeyElement->data, functionKeyElement->size);
         }
         else
         {
         }
      }
   }

   if(csmResult != E_OK){
      result = SECM_NOT_OK;
   }

   return result;
}
#endif

static SecM_StatusType SecM_InitKey(SecM_JobInfoPtrType pJobInfo, SecM_VoidPtrType keyPtr){
   SecM_StatusType result = SECM_OK;

#if !defined( SEC_ENABLE_JOB_INITKEY_AES )        && \
     !defined( SEC_ENABLE_JOB_INITKEY_MAC )        && \
     !defined( SEC_ENABLE_JOB_INITKEY_SYMMETRIC )  && \
     !defined( SEC_ENABLE_JOB_INITKEY_ASYMMETRIC )
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )

   (void)keyPtr;
#endif
#endif

   if(pJobInfo->smhKeyId != SEC_INVALID_SMH_KEY_ID){
      switch(pJobInfo->keyType)
      {
         case SEC_KEY_TYPE_NONE:
         {
            break;
         }
#if defined( SEC_ENABLE_JOB_INITKEY_AES )
         case SEC_KEY_TYPE_AES:
         {
            result = SecM_InitKeyAes(pJobInfo->csmKeyId, pJobInfo->smhKeyId, keyPtr);
            break;
         }
#endif
#if defined( SEC_ENABLE_JOB_INITKEY_MAC )
         case SEC_KEY_TYPE_MAC:
         {
            result = SecM_InitKeyMac(pJobInfo->csmKeyId, pJobInfo->smhKeyId, keyPtr);
            break;
         }
#endif
#if defined( SEC_ENABLE_JOB_INITKEY_SYMMETRIC )
         case SEC_KEY_TYPE_SYMMETRIC:
         {
            result = SecM_InitKeySymmetric(pJobInfo->csmKeyId, pJobInfo->smhKeyId, keyPtr);
            break;
         }
#endif
#if defined( SEC_ENABLE_JOB_INITKEY_ASYMMETRIC )
         case SEC_KEY_TYPE_ASYMMETRIC:
         {
            result = SecM_InitKeyAsymmetric(pJobInfo->csmKeyId, pJobInfo->smhKeyId, keyPtr);
            break;
         }
#endif
#if defined( SEC_ENABLE_JOB_INITKEY_PBKDF2 )
         case SEC_KEY_TYPE_PBKDF2:
         {
            result = SecM_InitKeyPBKDF2(pJobInfo->csmKeyId, pJobInfo->smhKeyId, keyPtr);
            break;
         }
#endif
         default:
         {
            result = SECM_NOT_OK;
            break;
         }
      }

      if(result == SECM_OK)
      {
         if(Csm_KeySetValid(pJobInfo->csmKeyId) != E_OK)
         {
            result = SECM_NOT_OK;
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_AEADDECRYPT )

static void SecM_DecryptAEADInit(SecM_JobInfoPtrType pJobInfo){
   SecM_AuthBuffer.buffer = SecM_AuthBufferData;
   SecM_AuthBuffer.pos = 0u;
   SecM_AuthBuffer.size = 0u;
   SecM_TagBuffer.buffer = SecM_TagBufferData;
   SecM_TagBuffer.pos = 0u;
   SecM_TagBuffer.size = 0u;

   SecM_InitBuffer(&SecM_AuthBuffer, ((const SecM_JobDecryptionAEADParamTypes*)pJobInfo->jobParam)->authDataLength);
   SecM_InitBuffer(&SecM_TagBuffer, ((const SecM_JobDecryptionAEADParamTypes*)pJobInfo->jobParam)->dataTagLength);
   SecM_AeadFsmSts = SECM_DECRAEAD_AUTHDATA;
   SecM_AeadAuthDataSent = 0u;
}

static SecM_StatusType SecM_DecryptAEAD(SecM_WordType jobId, V_MEMRAM1 SecM_OperationModeType V_MEMRAM2 V_MEMRAM3 * localMode
   ,  SecM_ConstRamDataType dataPtr, SecM_RamWordType dataLength, SecM_RamDataType resultPtr, SecM_RamWordType resultLengthPtr){
   SecM_JobInfoPtrType pJobInfo;
   const SecM_JobDecryptionAEADParamTypes *jobParamPtr;
   SecM_ByteType localFlushBuff[SEC_BUFFER_TAGDATA_SIZE];
   SecM_ShortType localFlushBuffSize;
   SecM_ShortType localDataLength;
   SecM_WordType buffLen;
   SecM_WordType localCurrentPos = 0u;
   SecM_StatusType result = SECM_OK;
   SecM_WordType outputLen = 0u;

   localDataLength = (SecM_ShortType)*dataLength;
   pJobInfo = &SecM_JobInfo[jobId];
   jobParamPtr = (const SecM_JobDecryptionAEADParamTypes *)pJobInfo->jobParam;

   switch(SecM_AeadFsmSts){
      case SECM_DECRAEAD_AUTHDATA:
      {
         if(SecM_AccumulateBufferStore(&SecM_AuthBuffer, dataPtr, &localDataLength) == SEC_BUFF_FULL)
         {
            SecM_AeadFsmSts = SECM_DECRAEAD_DECRYPT;
            SecM_AeadAuthDataSent = 0u;
            *dataLength = localDataLength;
         }
         *resultLengthPtr = 0u;
         break;
      }
      case SECM_DECRAEAD_DECRYPT:
      {
         (void)SecM_FifoBufferStore(&SecM_TagBuffer, dataPtr, &localDataLength, localFlushBuff, &localFlushBuffSize);

         if(SecM_AeadAuthDataSent == 0u)
         {
            *localMode |= SECM_OPERATIONMODE_START;
         }

         buffLen = *resultLengthPtr;

         if(localFlushBuffSize > 0u)
         {
            if(SecM_AEADDecrypt_Job(jobId, (*localMode & ~SECM_OPERATIONMODE_FINISH), localFlushBuff, localFlushBuffSize, SecM_AuthBuffer.buffer, SecM_AuthBuffer.pos, V_NULL, 0u, resultPtr, resultLengthPtr) != SECM_OK)
            {
               result = SECM_NOT_OK;
            }
            else
            {
               outputLen = *resultLengthPtr;
               localCurrentPos = *resultLengthPtr;
               buffLen -= *resultLengthPtr;
               if(SecM_AeadAuthDataSent == 0u)
               {
                  *localMode &= ~SECM_OPERATIONMODE_START;
                  SecM_InitBuffer(&SecM_AuthBuffer, jobParamPtr->authDataLength);
                  SecM_AeadAuthDataSent = 1u;
               }
            }
         }

         if(result == SECM_OK)
         {
            if(*dataLength > localDataLength)
            {
               *resultLengthPtr = buffLen;
               if(SecM_AEADDecrypt_Job(jobId, (*localMode & ~SECM_OPERATIONMODE_FINISH), dataPtr, (*dataLength - localDataLength), SecM_AuthBuffer.buffer, SecM_AuthBuffer.pos, V_NULL, 0u, &resultPtr[localCurrentPos], resultLengthPtr) != SECM_OK)
               {
                  result = SECM_NOT_OK;
               }
               else
               {
                  outputLen += *resultLengthPtr;
                  localCurrentPos += *resultLengthPtr;
                  buffLen -= *resultLengthPtr;
                  if(SecM_AeadAuthDataSent == 0u)
                  {
                     *localMode &= ~SECM_OPERATIONMODE_START;
                     SecM_InitBuffer(&SecM_AuthBuffer, jobParamPtr->authDataLength);
                     SecM_AeadAuthDataSent = 1u;
                  }
               }
            }
         }

         if(result == SECM_OK)
         {
            *resultLengthPtr = buffLen;
            if( (*localMode & SECM_OPERATIONMODE_FINISH) == SECM_OPERATIONMODE_FINISH )
            {
               if(SecM_AEADDecrypt_Job(jobId, SECM_OPERATIONMODE_FINISH, V_NULL, 0u, V_NULL, 0u, SecM_TagBuffer.buffer, SecM_TagBuffer.size, &resultPtr[localCurrentPos], resultLengthPtr) != SECM_OK)
               {
                  result = SECM_NOT_OK;
               }
               else
               {
                  outputLen += *resultLengthPtr;
               }
            }
         }
         *resultLengthPtr = outputLen;
         break;
      }
      default:
      {
         result = SECM_NOT_OK;
         break;
      }
   }

   return result;

}
#endif

#if defined( SEC_ENABLE_CRYPTOGRAPHIC_KEYS )

SecM_CryptographicKeyValuePtrType SecM_GetKeyValueByElementId(SecM_WordType smhKeyId, uint32 keyElementId){
   SecM_CryptographicKeyValuePtrType pKeyValue = NULL_PTR;

   if(smhKeyId < SecM_GetSizeOfCryptogrphicKeys()){
      SecM_ByteFastType index;
      SecM_CryptographicKeyPtrType pKey = &SecM_CryptographicKeys[smhKeyId];

      for(index = 0u; index < pKey->count; index++)
      {
         if(pKey->keyValues[index].cryptoElementId == keyElementId)
         {
            pKeyValue = &pKey->keyValues[index];
            break;
         }
      }
   }

   return pKeyValue;
}
#endif

#if defined( SEC_ENABLE_JOB_HASH )

SecM_StatusType SecM_HashJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_ConstRamDataType dataPtr
   ,  SecM_WordType dataLength, SecM_RamDataType hashPtr, SecM_WordType * hashLengthPtr){
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   if(jobId < SecM_GetSizeOfJobInfo()){
      pJobInfo = &SecM_JobInfo[jobId];

      if(pJobInfo->service == SECM_HASH)
      {
         if(Csm_Hash(pJobInfo->csmJobId, mode, dataPtr, dataLength, hashPtr, hashLengthPtr) == E_OK)
         {
            result = SECM_OK;
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_MACVERIFY )

SecM_StatusType SecM_MacVerifyJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr
   ,  SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_ConstRamDataType macPtr, SecM_WordType macLength){
   SecM_StatusType result = SECM_NOT_OK;
   Crypto_VerifyResultType verifyResult = CRYPTO_E_VER_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   if(jobId < SecM_GetSizeOfJobInfo()){
      pJobInfo = &SecM_JobInfo[jobId];

      if(pJobInfo->service == SECM_MACVERIFY)
      {
         if((mode & SECM_OPERATIONMODE_START) == SECM_OPERATIONMODE_START)
         {
            result = SecM_InitKey(pJobInfo, keyPtr);
         }
         else
         {
            result = SECM_OK;
         }

         if(result == SECM_OK)
         {
            if(Csm_MacVerify(pJobInfo->csmJobId, mode, dataPtr, dataLength, macPtr, macLength * 8u, &verifyResult) != E_OK)
            {
               result = SECM_NOT_OK;
            }
         }

         if((mode & SECM_OPERATIONMODE_FINISH) == SECM_OPERATIONMODE_FINISH)
         {
            if((result == SECM_OK) && (verifyResult != CRYPTO_E_VER_OK))
            {
               result = SECM_VER_SIG;
            }
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_MACGENERATE )

SecM_StatusType SecM_MacGenerateJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr
   ,  SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_RamDataType macPtr, SecM_WordType * macLengthPtr){
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   if(jobId < SecM_GetSizeOfJobInfo()){
      pJobInfo = &SecM_JobInfo[jobId];

      if(pJobInfo->service == SECM_MACGENERATE)
      {
         if((mode & SECM_OPERATIONMODE_START) == SECM_OPERATIONMODE_START)
         {
            result = SecM_InitKey(pJobInfo, keyPtr);
         }
         else
         {
            result = SECM_OK;
         }

         if(result == SECM_OK)
         {
            if(Csm_MacGenerate(pJobInfo->csmJobId, mode, dataPtr, dataLength, macPtr, macLengthPtr) != E_OK)
            {
               result = SECM_NOT_OK;
            }
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_ENCRYPTION )

SecM_StatusType SecM_EncryptionJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr
   ,  SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_RamDataType resultPtr, SecM_WordType * resultLengthPtr){
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;
   SecM_ByteType byteIndex;
   SecM_RamDataType outputData = resultPtr;
   SecM_WordType ivOutputLength = 0u;
   SecM_OperationModeType localMode = mode;
   SecM_ConstRamDataType localDataPtr = dataPtr;
   SecM_WordType localDataLength = dataLength;

   if(jobId < SecM_GetSizeOfJobInfo()){
      pJobInfo = &SecM_JobInfo[jobId];

      if(pJobInfo->service == SECM_ENCRYPTION)
      {
         if(SECM_OPERATIONMODE_IV == (localMode & SECM_OPERATIONMODE_IV))
         {
            if((keyPtr != NULL_PTR)
               && (resultLengthPtr != NULL_PTR))
            {
               SecM_CryptographicKeyValuePtrType ivKeyElement;
               SecM_AesKeyType * aesKey;

               ivKeyElement = SecM_GetKeyValueByElementId(pJobInfo->smhKeyId, CRYPTO_KE_CIPHER_IV);
               aesKey = (SecM_AesKeyType*)keyPtr;

               if((ivKeyElement != NULL_PTR) && (ivKeyElement->size <= localDataLength))
               {
                  if(*resultLengthPtr < ivKeyElement->size)
                  {
                  }
                  else
                  {
                     aesKey->iv.data = localDataPtr;
                     aesKey->iv.size = ivKeyElement->size;

                     localDataPtr = &localDataPtr[ivKeyElement->size];
                     localDataLength -= ivKeyElement->size;

                     if(localDataLength == 0u)
                     {
                        localMode &= ~(SECM_OPERATIONMODE_UPDATE);
                     }

                     for(byteIndex = 0u; byteIndex < ivKeyElement->size; byteIndex++)
                     {
                        outputData[byteIndex] = aesKey->iv.data[byteIndex];
                     }

                     outputData = &outputData[ivKeyElement->size];
                     *resultLengthPtr -= ivKeyElement->size;

                     ivOutputLength = ivKeyElement->size;

                     result = SECM_OK;
                  }
               }
            }
         }
         else
         {
            result = SECM_OK;
         }

         if(result == SECM_OK)
         {
            if((localMode & SECM_OPERATIONMODE_START) == SECM_OPERATIONMODE_START)
            {
               result = SecM_InitKey(pJobInfo, keyPtr);
            }
         }

         if(result == SECM_OK)
         {
            if(Csm_Encrypt(pJobInfo->csmJobId, localMode, localDataPtr, localDataLength, outputData, resultLengthPtr) != E_OK)
            {
               result = SECM_NOT_OK;
            }
         }

         if(result == SECM_OK)
         {
            if(ivOutputLength != 0u)
            {
               *resultLengthPtr += ivOutputLength;
            }
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_DECRYPTION ) ||\
    defined( SEC_ENABLE_JOB_AEADDECRYPT )

SecM_StatusType SecM_DecryptionJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr
   ,  SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_RamDataType resultPtr, SecM_WordType * resultLengthPtr){
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;
   SecM_OperationModeType localMode = mode;
   SecM_ConstRamDataType localDataPtr = dataPtr;
   SecM_WordType localDataLength = dataLength;

   if(jobId < SecM_GetSizeOfJobInfo()){
      pJobInfo = &SecM_JobInfo[jobId];

      if((pJobInfo->service == SECM_DECRYPTION) || (pJobInfo->service == SECM_AEADDECRYPT))
      {
         if(SECM_OPERATIONMODE_IV == (localMode & SECM_OPERATIONMODE_IV))
         {
            localMode &= ~(SECM_OPERATIONMODE_IV);

            if(keyPtr != NULL_PTR)
            {
               SecM_CryptographicKeyValuePtrType ivKeyElement;
               SecM_AesKeyType * aesKey;

               ivKeyElement = SecM_GetKeyValueByElementId(pJobInfo->smhKeyId, CRYPTO_KE_CIPHER_IV);
               aesKey = (SecM_AesKeyType*)keyPtr;

               if((ivKeyElement != NULL_PTR) && (ivKeyElement->size <= localDataLength))
               {
                  aesKey->iv.data = localDataPtr;
                  aesKey->iv.size = ivKeyElement->size;

                  localDataPtr = &localDataPtr[ivKeyElement->size];
                  localDataLength -= ivKeyElement->size;

                  if(localDataLength == 0u)
                  {
                     localMode &= ~(SECM_OPERATIONMODE_UPDATE);
                  }

                  result = SECM_OK;
               }
            }
         }
         else
         {
            result = SECM_OK;
         }

         if(result == SECM_OK)
         {
            if((localMode & SECM_OPERATIONMODE_START) == SECM_OPERATIONMODE_START)
            {
               result = SecM_InitKey(pJobInfo, keyPtr);
#if defined( SEC_ENABLE_JOB_AEADDECRYPT )

               if(pJobInfo->service == SECM_AEADDECRYPT)
               {
                  SecM_DecryptAEADInit(pJobInfo);
               }
#endif
            }
         }

         if(result == SECM_OK)
         {
#if defined( SEC_ENABLE_JOB_AEADDECRYPT )
            if(pJobInfo->service == SECM_AEADDECRYPT)
            {
               SecM_WordType currPos = 0u;
               SecM_WordType remData = 0u;
               SecM_WordType tempLength = *resultLengthPtr;
               remData = localDataLength;

               do
               {
                  *resultLengthPtr = tempLength;
                  if(SecM_DecryptAEAD(jobId, &localMode, &localDataPtr[currPos], &localDataLength, resultPtr, resultLengthPtr) != SECM_OK)
                  {
                     result = SECM_NOT_OK;
                  }
                  else
                  {
                     remData -= localDataLength;
                     currPos += localDataLength;
                     localDataLength = remData;
                  }
               } while((remData != 0u) && (result == SECM_OK));
            }
            else
#endif
            {
               if(Csm_Decrypt(pJobInfo->csmJobId, localMode, localDataPtr, localDataLength, resultPtr, resultLengthPtr) != E_OK)
               {
                  result = SECM_NOT_OK;
               }
            }
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_RANDOMGENERATE )

SecM_StatusType SecM_RandomGenerateJob(SecM_WordType jobId, SecM_RamDataType resultPtr, SecM_WordType * resultLengthPtr){
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   if(jobId < SecM_GetSizeOfJobInfo()){
      pJobInfo = &SecM_JobInfo[jobId];

      if(pJobInfo->service == SECM_RANDOMGENERATE)
      {
         if(Csm_RandomGenerate(pJobInfo->csmJobId, resultPtr, resultLengthPtr) == E_OK)
         {
            result = SECM_OK;
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_RANDOMSEED )

SecM_StatusType SecM_RandomSeedJob(SecM_WordType jobId, SecM_ConstRamDataType seedPtr, SecM_WordType seedLength){
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   if(jobId < SecM_GetSizeOfJobInfo()){
      pJobInfo = &SecM_JobInfo[jobId];

      if(pJobInfo->service == SECM_RANDOMSEED)
      {
         if(Csm_RandomSeed(pJobInfo->csmKeyId, seedPtr, seedLength) == E_OK)
         {
            result = SECM_OK;
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_SIGNATUREVERIFY )

SecM_StatusType SecM_SignatureVerifyJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr
   ,  SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_ConstRamDataType signaturePtr, SecM_WordType signatureLength){
   SecM_StatusType result = SECM_NOT_OK;
   Crypto_VerifyResultType verifyResult = CRYPTO_E_VER_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   if(jobId < SecM_GetSizeOfJobInfo()){
      pJobInfo = &SecM_JobInfo[jobId];

      if(pJobInfo->service == SECM_SIGNATUREVERIFY)
      {
         if((mode & SECM_OPERATIONMODE_START) == SECM_OPERATIONMODE_START)
         {
            result = SecM_InitKey(pJobInfo, keyPtr);
         }
         else
         {
            result = SECM_OK;
         }

         if(result == SECM_OK)
         {
            if(Csm_SignatureVerify(pJobInfo->csmJobId, mode, dataPtr, dataLength, signaturePtr, signatureLength, &verifyResult) != E_OK)
            {
               result = SECM_NOT_OK;
            }
         }

         if((mode & SECM_OPERATIONMODE_FINISH) == SECM_OPERATIONMODE_FINISH)
         {
            if((result == SECM_OK) && (verifyResult != CRYPTO_E_VER_OK))
            {
               result = SECM_VER_SIG;
            }
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_AEADENCRYPT )

SecM_StatusType SecM_AEADEncrypt_Job(SecM_WordType jobId,  SecM_OperationModeType mode
   ,  SecM_ConstRamDataType plaintextPtr, SecM_WordType plaintextLength
   ,  SecM_ConstRamDataType associatedDataPtr, SecM_WordType associatedDataLength
   ,  SecM_RamDataType ciphertextPtr, SecM_RamWordType ciphertextLengthPtr
   ,  SecM_RamDataType tagPtr, SecM_RamWordType tagLengthPtr){
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   if(jobId < SecM_GetSizeOfJobInfo()){
      pJobInfo = &SecM_JobInfo[jobId];

      if(pJobInfo->service == SECM_AEADENCRYPT)
      {
         if(Csm_AEADEncrypt(pJobInfo->csmJobId, mode, plaintextPtr, plaintextLength, associatedDataPtr
   ,           associatedDataLength, ciphertextPtr, ciphertextLengthPtr, tagPtr, tagLengthPtr) == E_OK)
         {
            result = SECM_OK;
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_AEADDECRYPT )

SecM_StatusType SecM_AEADDecrypt_Job(SecM_WordType jobId, SecM_OperationModeType mode
   ,  SecM_ConstRamDataType ciphertextPtr, SecM_WordType ciphertextLength
   ,  SecM_ConstRamDataType associatedDataPtr, SecM_WordType associatedDataLength 
   ,  SecM_ConstRamDataType tagPtr, SecM_WordType tagLength
   ,  SecM_RamDataType plaintextPtr, SecM_RamWordType plaintextLengthPtr){
   SecM_StatusType result = SECM_NOT_OK;
   Crypto_VerifyResultType verifyResult = CRYPTO_E_VER_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   if(jobId < SecM_GetSizeOfJobInfo()){
      pJobInfo = &SecM_JobInfo[jobId];

      if(pJobInfo->service == SECM_AEADDECRYPT)
      {
         if(Csm_AEADDecrypt(pJobInfo->csmJobId, mode, ciphertextPtr, ciphertextLength, associatedDataPtr
   ,           associatedDataLength, tagPtr, tagLength, plaintextPtr, plaintextLengthPtr, &verifyResult) == E_OK)
         {
            result = SECM_OK;
         }
         if((mode & SECM_OPERATIONMODE_FINISH) == SECM_OPERATIONMODE_FINISH)
         {
            if((result == SECM_OK) && (verifyResult != CRYPTO_E_VER_OK))
            {
               result = SECM_NOT_OK;
            }
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_JOB_KEYDERIVE )

SecM_StatusType SecM_KeyDeriveJob(SecM_WordType jobId, SecM_VoidPtrType keyPtr, SecM_RamDataType resultPtr, SecM_RamWordType resultLengthPtr){
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;
   vuintx idx;

   if(jobId < SecM_GetSizeOfJobInfo()){
      pJobInfo = &SecM_JobInfo[jobId];

      if(pJobInfo->service == SECM_KEYDERIVE)
      {
         result = SecM_InitKey(pJobInfo, keyPtr);
      }
   }

   if(result == SECM_OK){
      result = SECM_NOT_OK;

      for(idx = 0u; idx < SecM_GetSizeOfKeyDerivePrimitives(); idx++)
      {
         if(SecM_KeyDerivePrimitives[idx].jobId == jobId)
         {
            result = SECM_OK;
            break;
         }
      }
   }

   if(result == SECM_OK){
      if(Csm_JobKeyDerive(pJobInfo->csmJobId, pJobInfo->csmKeyId, SecM_KeyDerivePrimitives[idx].targetKeyId) != E_OK)
      {
         result = SECM_NOT_OK;
      }
   }

   if((result == SECM_OK) && (resultPtr != NULL_PTR) && (resultLengthPtr != NULL_PTR)){
      if(*resultLengthPtr != 0u)
      {
         if(Csm_KeyElementGet(SecM_KeyDerivePrimitives[idx].targetKeyId, 1u, resultPtr, resultLengthPtr) != E_OK)
         {
            result = SECM_NOT_OK;
         }
      }
   }
   return result;
}
#endif

#if defined( SEC_ENABLE_KEY_OPERATION_ACCESS )

SecM_StatusType SecM_KeyElementSet(uint32 csmKeyId, uint32 keyElementId, SecM_ConstRamDataType keyPtr, SecM_WordType keyLength){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_KeyElementSet(csmKeyId, keyElementId, keyPtr, keyLength) == E_OK){
      if(Csm_KeySetValid(csmKeyId) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}

SecM_StatusType SecM_KeyElementGet(uint32 csmKeyId, uint32 keyElementId, SecM_RamDataType keyPtr, SecM_RamWordType keyLengthPtr){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_KeyElementGet(csmKeyId, keyElementId, keyPtr, keyLengthPtr) == E_OK){
      result = SECM_OK;
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_KEY_OPERATION_COPY )

SecM_StatusType SecM_KeyCopy(uint32 csmSourceKeyId, uint32 csmTargetKeyId){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_KeyCopy(csmSourceKeyId, csmTargetKeyId) == E_OK){
      if(Csm_KeySetValid(csmTargetKeyId) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_KEY_OPERATION_ELEMENT_COPY )

SecM_StatusType SecM_KeyElementCopy(uint32 csmSourceKeyId, uint32 csmTargetKeyId, uint32 keyElementId){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_KeyElementCopy(csmSourceKeyId, keyElementId, csmTargetKeyId, keyElementId) == E_OK){
      if(Csm_KeySetValid(csmTargetKeyId) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_SAVE_RESTORE_CONTEXT ) && defined( SEC_ENABLE_CSM )

SecM_StatusType SecM_SaveContextCsm(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_RamWordType contextBufferLengthPtr){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_SaveContextJob(csmJobId, contextBuffer, contextBufferLengthPtr) == E_OK){
      result = SECM_OK;
   }

   return result;
}

#if defined( SEC_ENABLE_SAVE_RESTORE_HASH )

SecM_StatusType SecM_RestoreContextHash(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_Hash(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, NULL_PTR) == E_OK){
      if(Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_SAVE_RESTORE_ENCRYPT )

SecM_StatusType SecM_RestoreContextEncryption(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_Encrypt(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, NULL_PTR) == E_OK){
      if(Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_SAVE_RESTORE_DECRYPT )

SecM_StatusType SecM_RestoreContextDecryption(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_Decrypt(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, NULL_PTR) == E_OK){
      if(Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_SAVE_RESTORE_MAC_GENERATE )

SecM_StatusType SecM_RestoreContextMacGenerate(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_MacGenerate(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, NULL_PTR) == E_OK){
      if(Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_SAVE_RESTORE_MAC_VERIFY )

SecM_StatusType SecM_RestoreContextMacVerify(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_MacVerify(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR) == E_OK){
      if(Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_SAVE_RESTORE_SIG_VERIFY )

SecM_StatusType SecM_RestoreContextSignatureVerify(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_SignatureVerify(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR) == E_OK){
      if(Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_SAVE_RESTORE_AEAD_ENCRYPT )

SecM_StatusType SecM_RestoreContextAEADEncrypt(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_AEADEncrypt(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR) == E_OK){
      if(Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_SAVE_RESTORE_AEAD_DECRYPT )

SecM_StatusType SecM_RestoreContextAEADDecrypt(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength){
   SecM_StatusType result = SECM_NOT_OK;

   if(Csm_AEADDecrypt(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR, NULL_PTR, NULL_PTR) == E_OK){
      if(Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif
#endif

#if(defined( SEC_ENABLE_CSM ) && (SecM_GetSizeOfJobInfo() > 0u))

void SecM_CancelAllJobs(void){
   SecM_ByteFastType i;

   for(i = 0u; i < SecM_GetSizeOfJobInfo(); i++){
      if(SecM_JobInfo[i].csmJobId != SEC_INVALID_CSM_JOB_ID)
      {
         (void)Csm_CancelJob(SecM_JobInfo[i].csmJobId, 0u);
      }
   }
}
#endif

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

