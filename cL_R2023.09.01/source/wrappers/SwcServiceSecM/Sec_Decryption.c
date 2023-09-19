

#define SEC_DECRYPTION_SOURCE

#include "Sec_Inc.hpp"

#include "Sec_Types.hpp"

#include "Sec_Decryption.hpp"

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

#if defined( SEC_ENABLE_DECRYPTION ) || defined( SEC_ENABLE_ENCRYPTION )

SecM_StatusType SecM_DecryptionUpdate(const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock
   ,  V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock
   ,  const V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pDecParam
   ,  SecM_WordType smhId){
   SecM_StatusType result;
   SecM_ByteType opMode;
   uint32 outLength;
   SecM_OperationModeType operationMode;
   SecM_AesKeyType aesKey;
   V_MEMROM1 SecM_DecPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive;

   result = SECM_NOT_OK;

   if(smhId < SecM_GetSizeOfDecryptionPrimitives()){
      opMode = pDecParam->mode;
      pPrimitive = &SecM_DecryptionPrimitives[smhId];
      operationMode = SECM_OPERATIONMODE_NONE;

      if(SEC_DECRYPTION_MODE_INIT == (opMode & SEC_DECRYPTION_MODE_INIT))
      {
         operationMode |= SECM_OPERATIONMODE_START;
         if(SEC_DECRYPTION_MODE_IV == (opMode & SEC_DECRYPTION_MODE_IV))
         {
            operationMode |= SECM_OPERATIONMODE_IV;
         }

         aesKey.key.data = pDecParam->key.data;
         aesKey.key.size = pDecParam->key.size;

      }

      if(pInBlock->Length != 0u)
      {
         operationMode |= SECM_OPERATIONMODE_UPDATE;
      }

      if(SEC_DECRYPTION_MODE_FINALIZE == (opMode & SEC_DECRYPTION_MODE_FINALIZE))
      {
         operationMode |= SECM_OPERATIONMODE_FINISH;
      }

      if(operationMode != 0u)
      {
         outLength = pOutBlock->Length;

         result = pPrimitive->func(pPrimitive->jobId, operationMode, (SecM_VoidPtrType)&aesKey, pInBlock->DataBuffer, pInBlock->Length, pOutBlock->DataBuffer, &outLength);
         pOutBlock->Length = (SecM_LengthType)outLength;
      }
   }

   return result;
}

SecM_StatusType SecM_InitDecryption( SecM_DecInitType init ){
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )

   (void)init;
#endif

#if defined( SEC_ENABLE_DECRYPTION )
   return SECM_OK;
#else
   return SECM_NOT_OK;
#endif
}

SecM_StatusType SecM_DeinitDecryption( SecM_DecDeinitType deinit ){
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )

   (void)deinit;
#endif

#if defined( SEC_ENABLE_DECRYPTION )
   return SECM_OK;
#else
   return SECM_NOT_OK;
#endif
}

SecM_StatusType SecM_Decryption( const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock
   ,  V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock
   ,  V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pDecParam ){
#if defined( SEC_ENABLE_DECRYPTION ) && defined( SEC_DEFAULT_DECRYPTION_CONFIG )
   return SecM_DecryptionUpdate(pInBlock, pOutBlock, pDecParam, SEC_DEFAULT_DECRYPTION_CONFIG);
#else
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )

   (void)pInBlock;
   (void)pOutBlock;
   (void)pDecParam;
#endif

   return SECM_NOT_OK;
#endif
}

SecM_StatusType SecM_InitEncryption( SecM_DecInitType init ){
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )

   (void)init;
#endif

#if defined( SEC_ENABLE_ENCRYPTION )
   return SECM_OK;
#else
   return SECM_NOT_OK;
#endif
}

SecM_StatusType SecM_DeinitEncryption( SecM_DecDeinitType deinit ){
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )

   (void)deinit;
#endif

#if defined( SEC_ENABLE_ENCRYPTION )
   return SECM_OK;
#else
   return SECM_NOT_OK;
#endif
}

SecM_StatusType SecM_Encryption( const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock
   ,  V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock
   ,  V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pEncParam ){
#if defined( SEC_ENABLE_ENCRYPTION ) && defined( SEC_DEFAULT_ENCRYPTION_CONFIG )
   return SecM_DecryptionUpdate(pInBlock, pOutBlock, pEncParam, SEC_DEFAULT_ENCRYPTION_CONFIG);
#else
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )

   (void)pInBlock;
   (void)pOutBlock;
   (void)pEncParam;
#endif

   return SECM_NOT_OK;
#endif
}
#endif
#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

