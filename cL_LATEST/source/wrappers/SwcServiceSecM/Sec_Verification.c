

#define SEC_VERIFICATION_SOURCE

#include "Sec.hpp"

#include "Sec_Verification.hpp"

#if defined ( SEC_ENABLE_CSM )
#include "SwcServiceCsm.hpp"
#endif

#define SEC_ADDRESS_LENGTH_INPUT_SIZE    4u

#if defined( SEC_ENABLE_CRC_TOTAL )
#define SEC_OPERATION_SIZE_CRC_TOTAL           1u
#else
#define SEC_OPERATION_SIZE_CRC_TOTAL           0u
#endif
#if defined( SEC_ENABLE_CRC_WRITTEN )
#define SEC_OPERATION_SIZE_CRC_WRITTEN         1u
#else
#define SEC_OPERATION_SIZE_CRC_WRITTEN         0u
#endif
#if defined( SEC_ENABLE_VENDOR_CHECKSUM )
#define SEC_OPERATION_SIZE_VENDOR_CHECKSUM     1u
#else
#define SEC_OPERATION_SIZE_VENDOR_CHECKSUM     0u
#endif

#define SEC_OPERATION_SIZE                      (SEC_OPERATION_SIZE_CRC_TOTAL + SEC_OPERATION_SIZE_CRC_WRITTEN + SEC_OPERATION_SIZE_VENDOR_CHECKSUM + 1u)

#if defined( SEC_VER_MAX_CONFIG_COUNT )
#else
#define SEC_VER_MAX_CONFIG_COUNT               SEC_OPERATION_SIZE
#endif

#define SEC_VER_ARRAY_SIZE(arr)                 (sizeof(arr) / sizeof((arr)[0]))

#define SEC_READ_COUNT_RESULT_IGNORE            SECM_VER_OK

#define SEC_READ_COUNT_RESULT_ASSERT            SECM_VER_ERROR

#define SEC_READ_COUNT_MASK_IGNORE              0x00u

#define SEC_READ_COUNT_MASK_ASSERT              0xFFFFFFFFuL

#define SEC_MEMORY_READ_ACCESS_WIDTH           1u

typedef struct{
   FL_ReadMemoryFctType       readMemory;
   SecM_AddrType              verifyAddress;
   SecM_SizeType              remainingBytes;
   SecM_SignatureParamType    sigParam;
#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT ) && \
    defined( SEC_ENABLE_CRC_TOTAL )
   SecM_SizeType              readCountMask;
   SecM_StatusType            readCountResult;
#endif
}SecM_VerifyContextType;

typedef struct{
   SecM_VerifyConfigType   pPrimitives[SEC_VER_MAX_CONFIG_COUNT];
   SecM_ByteFastType       count;
}SecM_VerifyConfigPairType;

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

#if defined( SEC_ENABLE_VERIFICATION_RANGE_CHECK )
static SecM_StatusType SecM_CheckRangeOverflow( SecM_AddrType address, SecM_SizeType length );
#endif

static SecM_StatusType SecM_VerifyWrapper( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam
   ,  V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList );
static SecM_StatusType SecM_UpdateSegment( V_MEMRAM1 SecM_VerifyContextType V_MEMRAM2 V_MEMRAM3 * pContext
   ,  V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList );

#if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )
static SecM_StatusType SecM_UpdateSegmentAddress( V_MEMRAM1 SecM_VerifyContextType V_MEMRAM2 V_MEMRAM3 * pContext
   ,  V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList
   ,  const V_MEMRAM1 FL_SegmentInfoType V_MEMRAM2 V_MEMRAM3 * pSegmentInfo );
#endif

static void SecM_PopulateCfgList( const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pSourceList
   ,  V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pTargetList, SecM_ByteType mask );

#if defined( SEC_ENABLE_VERIFICATION_WRAPPER )
#else
static SecM_StatusType SecM_VerificationWrapper ( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam
   ,  const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList );
#endif

#if defined( SEC_ENABLE_VERIFY_HASH )
static SecM_StatusType SecM_CopyDigest(SecM_ConstRamDataType pCalculatedData, SecM_LengthType calculatedSize
   ,  SecM_RamDataType pOutputData, SecM_LengthType outputSize);
static SecM_StatusType SecM_CompareDigest(SecM_ConstRamDataType pCalculatedData, SecM_LengthType calculatedSize
   ,  SecM_ConstRamDataType pProvidedData, SecM_LengthType providedSize);
#endif
#if defined( SEC_ENABLE_VERIFY_CRC )
static SecM_StatusType SecM_CopyCrcParam(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam
   ,  SecM_ByteType crcAction, V_MEMROM1 SecM_CrcPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive);
#endif
#if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING ) || \
    defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )
static SecM_StatusType SecM_VerifyContextHandling( SecM_WordType jobId, SecM_WordType ctxBuffSize, SecM_WordType *pSize, SecM_ByteType *pData );
#endif
#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#define SECM_START_SEC_CONST
#include "MemMap.hpp"

#if defined( SEC_ENABLE_CRC )

V_MEMROM0 static V_MEMROM1 SecM_CRCType V_MEMROM2 crcZeroValue = SEC_ZERO_VALUE;
#endif

#define SECM_STOP_SEC_CONST
#include "MemMap.hpp"

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

#if defined( SEC_ENABLE_VERIFICATION_RANGE_CHECK )

static SecM_StatusType SecM_CheckRangeOverflow( SecM_AddrType address, SecM_SizeType length ){
   SecM_StatusType result;

   result = SECM_OK;

   if(length > 0u){
      if(address > (0xFFFFFFFFuL - (length - 1u)))
      {
         result = SECM_NOT_OK;
      }
   }

   return result;
}
#endif

static SecM_StatusType SecM_VerifyWrapper( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam
   ,                                          V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList ){
   SecM_StatusType            result;
   SecM_ByteFastType          index;
   SecM_ByteFastType          cfgCount;
   SecM_ByteType              action;
   SecM_LengthType            byteCount;
   SecM_LengthFastType        sourceOffset;
   V_MEMRAM1 SecM_VerifyConfigType V_MEMRAM2 V_MEMRAM3 *    pConfig;
   V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 V_MEMROM3 * pOperation;
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 *  pParam;

   result = SECM_VER_OK;

   action         = pVerifyParam->sigState;
   byteCount      = pVerifyParam->sigByteCount;

   sourceOffset   = 0u;

   if(SEC_HASH_INIT == action){
      pConfig  = &pCfgList->pPrimitives[0u];
      pParam   = pConfig->pContext;

      pParam->key = pVerifyParam->key;
   }

   cfgCount = pCfgList->count;

   for(index = 0u; index < cfgCount; index++){
      pConfig     = &pCfgList->pPrimitives[index];
      pOperation  = pConfig->pOperation;
      pParam      = pConfig->pContext;

      if(SEC_SIG_VERIFY == action)
      {
         sourceOffset   = pOperation->offset;
         byteCount      = pOperation->length;
      }

      pParam->sigState        = action;
      pParam->sigSourceBuffer = &pVerifyParam->sigSourceBuffer[sourceOffset];
      pParam->sigByteCount    = byteCount;
      pParam->wdTriggerFct    = pVerifyParam->wdTriggerFct;

      result = pOperation->pFunction(pParam);

      if(SECM_VER_OK != result)
      {
         break;
      }
   }

   return result;
}

static SecM_StatusType SecM_UpdateSegment( V_MEMRAM1 SecM_VerifyContextType V_MEMRAM2 V_MEMRAM3 * pContext
   ,  V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList ){
   SecM_StatusType   result;
   SecM_AddrType     currentAddress;
   SecM_SizeType     remainderLength;
   SecM_SizeType     verifyCount;
   SecM_SizeType     readCount;
#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT ) && \
    defined( SEC_ENABLE_CRC_TOTAL )
   SecM_SizeType     countMask;
   SecM_StatusType   countResult;
#endif
   SecM_ByteType     verifyBuffer[SEC_VERIFY_BYTES];
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam;

   result = SECM_VER_OK;

   if(pCfgList->count > 0u){
      currentAddress  = pContext->verifyAddress;
      remainderLength = pContext->remainingBytes;

#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT ) && \
    defined( SEC_ENABLE_CRC_TOTAL )
      countMask      = pContext->readCountMask;
      countResult    = pContext->readCountResult;
#endif

#if defined( SEC_ENABLE_VERIFICATION_RANGE_CHECK )

      if(SECM_OK != SecM_CheckRangeOverflow(currentAddress, remainderLength))
      {
         result = SECM_VER_ERROR;
      }
      else
#endif
      {
         pVerifyParam = &pContext->sigParam;

         pVerifyParam->sigSourceBuffer  = verifyBuffer;
         pVerifyParam->sigState         = SEC_HASH_COMPUTE;

         while(remainderLength > 0u)
         {
            SEC_WATCHDOG_TRIGGER(pVerifyParam->wdTriggerFct);

            verifyCount = SEC_VERIFY_BYTES / SEC_MEMORY_READ_ACCESS_WIDTH;
            if(remainderLength < (SEC_VERIFY_BYTES / SEC_MEMORY_READ_ACCESS_WIDTH))
            {
               verifyCount = remainderLength;
            }

            readCount = pContext->readMemory(currentAddress, verifyBuffer, verifyCount);

#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT )
#if defined( SEC_ENABLE_CRC_TOTAL )

            if( (readCount > 0u)

#if( SEC_MEMORY_READ_ACCESS_WIDTH == 1u )
              && ((readCount & countMask) == (verifyCount & countMask)))
#else
              && ((readCount & countMask) == ((SEC_MEMORY_READ_ACCESS_WIDTH * verifyCount) & countMask)))
#endif
#else

            if(readCount == (SEC_MEMORY_READ_ACCESS_WIDTH * verifyCount))
#endif
#else

            if(readCount > 0u)
#endif
            {
               pVerifyParam->sigByteCount = (SecM_LengthType)readCount;
               result = SecM_VerifyWrapper(pVerifyParam, pCfgList);
            }
            else
            {
#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT )
#if defined( SEC_ENABLE_CRC_TOTAL )

               result = countResult;
#else

               result = SECM_VER_ERROR;
#endif
#else

#endif
            }

            currentAddress  += verifyCount;
            remainderLength -= verifyCount;

            if(SECM_VER_OK != result)
            {
               break;
            }
         }
      }
   }
   else{
   }

   return result;
}

#if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )

static SecM_StatusType SecM_UpdateSegmentAddress( V_MEMRAM1 SecM_VerifyContextType V_MEMRAM2 V_MEMRAM3 * pContext
   ,  V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList
   ,  const V_MEMRAM1 FL_SegmentInfoType V_MEMRAM2 V_MEMRAM3 * pSegmentInfo ){
   SecM_StatusType   result;
   SecM_ByteType     addressBuffer[2u * SEC_ADDRESS_LENGTH_INPUT_SIZE];
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam;

   result = SECM_VER_OK;

   if(pCfgList->count > 0u){
      SecM_SetInteger(SEC_ADDRESS_LENGTH_INPUT_SIZE, pSegmentInfo->transferredAddress, &addressBuffer[0]);
      SecM_SetInteger(SEC_ADDRESS_LENGTH_INPUT_SIZE, pSegmentInfo->length, &addressBuffer[SEC_ADDRESS_LENGTH_INPUT_SIZE]);

      pVerifyParam = &pContext->sigParam;

      pVerifyParam->sigSourceBuffer = addressBuffer;
      pVerifyParam->sigByteCount    = 2u * SEC_ADDRESS_LENGTH_INPUT_SIZE;
      pVerifyParam->sigState        = SEC_HASH_COMPUTE;

      result = SecM_VerifyWrapper(pVerifyParam, pCfgList);
   }
   else{
   }

   return result;
}
#endif

static void SecM_PopulateCfgList( const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pSourceList
   ,  V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pTargetList, SecM_ByteType mask ){
   SecM_ByteFastType inIndex;
   SecM_ByteFastType outIndex;
   V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 V_MEMROM3 * pSourceOperation;
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 *  pSourceParam;
   V_MEMRAM1 SecM_VerifyConfigType V_MEMRAM2 V_MEMRAM3 *    pTarget;

   outIndex = 0u;

   for(inIndex = 0u; inIndex < pSourceList->count; inIndex++){
      pSourceOperation  = &pSourceList->pPrimitives.pOperation[inIndex];
      pSourceParam      = &pSourceList->pPrimitives.pContext[inIndex];

      if(mask == (pSourceOperation->mask & mask))
      {
         pTarget = &pTargetList->pPrimitives[outIndex];

         pTarget->pOperation  = pSourceOperation;
         pTarget->pContext    = pSourceParam;

         outIndex++;
      }
   }

   pTargetList->count = outIndex;
}

#if defined( SEC_ENABLE_VERIFICATION_WRAPPER )
SecM_StatusType SecM_VerificationWrapper( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam
   ,  const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList )
#else
static SecM_StatusType SecM_VerificationWrapper( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam
   ,  const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList )
#endif
{
   SecM_StatusType            result;

   SecM_VerifyContextType     context;
   SecM_ByteFastType          index;

   V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * pSegmentList;

   V_MEMRAM1 FL_SegmentInfoType V_MEMRAM2 V_MEMRAM3 * pSegmentInfo;

   SecM_VerifyConfigPairType  cfgListAll = {0};

   SecM_VerifyConfigPairType  cfgListVerify = {0};
#if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )

   SecM_VerifyConfigPairType   cfgListAddr = {0};
#endif
#if defined( SEC_ENABLE_CRC_TOTAL )

   SecM_VerifyConfigPairType  cfgListInter = {0};

   V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgListUpdate;
   SecM_AddrType              currentAddress;
   SecM_SizeType              remainderLength;
   SecM_SizeType              currentLength;
#endif

#if defined( SEC_ENABLE_VERIFICATION_WRAPPER )
   result = SECM_VER_ERROR;

   if((pCfgList->count > 0u) && (pCfgList->count <= SEC_VER_MAX_CONFIG_COUNT))
#endif
   {
      SecM_PopulateCfgList(pCfgList, &cfgListAll,     SEC_UPDATE_OPERATION_DEFAULT);

      SecM_PopulateCfgList(pCfgList, &cfgListVerify,  SEC_UPDATE_OPERATION_VERIFICATION);
#if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )

      SecM_PopulateCfgList(pCfgList, &cfgListAddr,    SEC_UPDATE_OPERATION_ADDRESS_LENGTH);
#endif
#if defined( SEC_ENABLE_CRC_TOTAL )

      SecM_PopulateCfgList(pCfgList, &cfgListInter,   SEC_UPDATE_OPERATION_INTER_SEGMENT);
#endif

      pSegmentList = &pVerifyParam->segmentList;

      context.sigParam.sigState           = SEC_HASH_INIT;
      context.sigParam.sigByteCount       = 0u;
      context.sigParam.wdTriggerFct       = pVerifyParam->wdTriggerFct;
      context.readMemory                  = pVerifyParam->readMemory;
#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      context.sigParam.currentDataLength  = SEC_DATA_LENGTH_NULL;
#endif

      context.sigParam.key = pVerifyParam->key;

      context.sigParam.currentHash.sigResultBuffer  = (SecM_ResultBufferType)pVerifyParam->workspace.data;
      context.sigParam.currentHash.length           = pVerifyParam->workspace.size;

      result = SecM_VerifyWrapper(&context.sigParam, &cfgListAll);

      if(SECM_VER_OK == result)
      {
#if defined( SEC_ENABLE_CRC_TOTAL )

         currentAddress  = pVerifyParam->blockStartAddress;
         remainderLength = pVerifyParam->blockLength;

#if defined( SEC_ENABLE_VERIFICATION_RANGE_CHECK )
         if(SECM_OK == SecM_CheckRangeOverflow(currentAddress, remainderLength))
         {
            result = SECM_VER_ERROR;
         }
         else
#endif
         {
            index = 0u;

            while(remainderLength > 0u)
            {
               pCfgListUpdate = &cfgListInter;
#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT )

               context.readCountMask   = SEC_READ_COUNT_MASK_IGNORE;

               context.readCountResult = SEC_READ_COUNT_RESULT_IGNORE;
#endif

               if(index < pSegmentList->nrOfSegments)
               {
                  pSegmentInfo = &pSegmentList->segmentInfo[index];

                  if(currentAddress < pSegmentInfo->targetAddress)
                  {
                     currentLength = pSegmentInfo->targetAddress - currentAddress;
                  }
                  else
                  {
                     currentLength = pSegmentInfo->length;

                     pCfgListUpdate = &cfgListAll;
#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT )

                     context.readCountMask   = SEC_READ_COUNT_MASK_ASSERT;

                     context.readCountResult = SEC_READ_COUNT_RESULT_ASSERT;
#endif

#if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )

                     result = SecM_UpdateSegmentAddress(&context, &cfgListAddr, pSegmentInfo);
#endif

                     index++;
                  }
               }
               else
               {
                  currentLength = remainderLength;
               }

               if(SECM_VER_OK == result)
               {
                  context.verifyAddress   = currentAddress;
                  context.remainingBytes  = currentLength;

                  result = SecM_UpdateSegment(&context, pCfgListUpdate);

                  if(currentLength < remainderLength)
                  {
                     remainderLength -= currentLength;
                     currentAddress  += currentLength;
                  }
                  else
                  {
                     remainderLength = 0u;
                  }
               }

               if(SECM_VER_OK != result)
               {
                  break;
               }
            }
         }
#else

         for(index = 0u; index < pSegmentList->nrOfSegments; index++)
         {
            pSegmentInfo = &pSegmentList->segmentInfo[index];

            context.verifyAddress  = pSegmentInfo->targetAddress;
            context.remainingBytes = pSegmentInfo->length;

#if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )

            result = SecM_UpdateSegmentAddress(&context, &cfgListAddr, pSegmentInfo);

            if(SECM_VER_OK == result)
#endif
            {
               result = SecM_UpdateSegment(&context, &cfgListAll);
            }

            if(SECM_VER_OK != result)
            {
               break;
            }
         }
#endif
      }

      if(SECM_VER_OK == result)
      {
         context.sigParam.sigState        = SEC_HASH_FINALIZE;

         result = SecM_VerifyWrapper(&context.sigParam, &cfgListAll);

         if(SECM_VER_OK == result)
         {
            context.sigParam.sigSourceBuffer = pVerifyParam->verificationData;
            context.sigParam.sigState        = SEC_SIG_VERIFY;

            result = SecM_VerifyWrapper(&context.sigParam, &cfgListVerify);
         }
      }
   }

   return result;
}

#if defined( SEC_ENABLE_VERIFY_HASH )

static SecM_StatusType SecM_CopyDigest( SecM_ConstRamDataType pCalculatedData, SecM_LengthType calculatedSize
   ,  SecM_RamDataType pOutputData, SecM_LengthType outputSize ){
   SecM_StatusType result;

   result = SECM_VER_ERROR;

   if(outputSize >= calculatedSize){
      SecM_CopyBuffer(pCalculatedData, pOutputData, calculatedSize);

      result = SECM_VER_OK;
   }

   return result;
}

static SecM_StatusType SecM_CompareDigest( SecM_ConstRamDataType pCalculatedData, SecM_LengthType calculatedSize
   ,  SecM_ConstRamDataType pProvidedData, SecM_LengthType providedSize ){
   SecM_StatusType result;
   SecM_LengthType index;
   SecM_ByteType   accumulated;

   result = SECM_VER_ERROR;

   if(calculatedSize == providedSize){
      accumulated = 0u;

      for(index = 0u; index < calculatedSize; index++)
      {
         accumulated |= pCalculatedData[index] ^ pProvidedData[index];
      }

      if(accumulated == 0u)
      {
         result = SECM_VER_OK;
      }
      else
      {
         result = SECM_VER_SIG;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_VERIFY_CRC )

static SecM_StatusType SecM_CopyCrcParam( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam
   ,  SecM_ByteType crcAction, V_MEMROM1 SecM_CrcPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive ){
   SecM_StatusType result = SECM_NOT_OK;

   if(pPrimitive->crcType == SEC_CRC16){
      if(pVerifyParam->currentHash.length == sizeof(SecM_CRC16ParamType))
      {
         SecM_CRC16ParamType * pCrcParam = (SecM_CRC16ParamType*)pVerifyParam->currentHash.sigResultBuffer;
         pCrcParam->crcByteCount = pVerifyParam->sigByteCount;
         pCrcParam->crcSourceBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->crcOutputBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->wdTriggerFct = pVerifyParam->wdTriggerFct;
         pCrcParam->crcState = crcAction;
         result = SECM_OK;
      }
   }
   else if(pPrimitive->crcType == SEC_CRC32){
      if(pVerifyParam->currentHash.length == sizeof(SecM_CRC32ParamType))
      {
         SecM_CRC32ParamType * pCrcParam = (SecM_CRC32ParamType*)pVerifyParam->currentHash.sigResultBuffer;
         pCrcParam->crcByteCount = pVerifyParam->sigByteCount;
         pCrcParam->crcSourceBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->crcOutputBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->wdTriggerFct = pVerifyParam->wdTriggerFct;
         pCrcParam->crcState = crcAction;
         result = SECM_OK;
      }
   }
   else if(pPrimitive->crcType == SEC_CRC64){
      if(pVerifyParam->currentHash.length == sizeof(SecM_CRC64ParamType))
      {
         SecM_CRC64ParamType * pCrcParam = (SecM_CRC64ParamType*)pVerifyParam->currentHash.sigResultBuffer;
         pCrcParam->crcByteCount = pVerifyParam->sigByteCount;
         pCrcParam->crcSourceBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->crcOutputBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->wdTriggerFct = pVerifyParam->wdTriggerFct;
         pCrcParam->crcState = crcAction;
         result = SECM_OK;
      }
   }
   else{
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING ) || \
     defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )

static SecM_StatusType SecM_VerifyContextHandling( SecM_WordType jobId, SecM_WordType ctxBuffSize, SecM_WordType *pSize, SecM_ByteType *pData ){
   SecM_StatusType result = SECM_VER_OK;

   if(*pSize == 0u){
      *pSize = ctxBuffSize;
#if defined ( SEC_ENABLE_CSM )
      if(Csm_SaveContextJob(SecM_JobInfo[jobId].csmJobId, pData, pSize) != E_OK)
#endif
      {
         result = SECM_VER_ERROR;
      }
   }
   else{
#if defined ( SEC_ENABLE_CSM )
      if(Csm_RestoreContextJob(SecM_JobInfo[jobId].csmJobId, pData, *pSize) != E_OK)
#endif
      {
         result = SECM_VER_ERROR;
      }
   }

   return result;
}
#endif

void SecM_InitPowerOnVerification(void){
#if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING ) || \
    defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )
   SecM_WordType idx;
#endif

#if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING )
   for(idx = 0; idx < SecM_GetSizeOfMacPrimitives(); idx++){
      if(SecM_MacPrimitives[idx].pVerWks != V_NULL)
      {
         SecM_MacPrimitives[idx].pVerWks->data = SecM_MacPrimitivesContextBuffs[idx];
         SecM_MacPrimitives[idx].pVerWks->size = 0u;
      }
   }
#endif

#if defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )
   for(idx = 0; idx < SecM_GetSizeOfSignaturePrimitives(); idx++){
      if(SecM_SignaturePrimitives[idx].pVerWks != V_NULL)
      {
         SecM_SignaturePrimitives[idx].pVerWks->data = SecM_SignaturePrimitivesContextBuffs[idx];
         SecM_SignaturePrimitives[idx].pVerWks->size = 0u;
      }
   }
#endif
}

SecM_StatusType SecM_VerificationBase( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam
   ,  const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList ){
   SecM_StatusType   result;
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyContext;
#if defined( SEC_ENABLE_CRC_TOTAL ) || \
    defined( SEC_ENABLE_CRC_WRITTEN )
   SecM_ByteFastType index;
   SecM_ByteFastType cfgCount;
#endif
#if defined( SEC_ENABLE_CRC_TOTAL )
   SecM_CRCParamType crcTotalParam;
#endif
#if defined( SEC_ENABLE_CRC_WRITTEN )
   SecM_CRCParamType crcWrittenParam;
#endif

   pVerifyContext = pCfgList->pPrimitives.pContext;

   pVerifyContext[0u].currentHash.sigResultBuffer  = (SecM_ResultBufferType)SEC_DEFAULT_WORKSPACE;
   pVerifyContext[0u].currentHash.length           = SEC_DEFAULT_WORKSPACE_SIZE;
#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
   pVerifyContext[0u].currentDataLength            = SEC_DATA_LENGTH_NULL;
#endif

#if defined( SEC_ENABLE_CRC_TOTAL ) || \
    defined( SEC_ENABLE_CRC_WRITTEN )
   cfgCount       = pCfgList->count;

   index          = 1u;
#endif

#if defined( SEC_ENABLE_CRC_TOTAL )

   crcTotalParam.currentCRC = crcZeroValue;

   if(index < cfgCount){
      pVerifyContext[index].currentHash.sigResultBuffer  = (SecM_ResultBufferType)&crcTotalParam;
      pVerifyContext[index].currentHash.length           = sizeof(SecM_CRCParamType);
#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      pVerifyContext[index].currentDataLength            = SEC_DATA_LENGTH_NULL;
#endif

#if defined( SEC_ENABLE_CRC_WRITTEN )

      index++;
#endif
   }
#endif

#if defined( SEC_ENABLE_CRC_WRITTEN )
#if defined( SEC_ENABLE_VENDOR_CHECKSUM )

   index++;
#endif

   if(index < cfgCount){
      pVerifyContext[index].currentHash.sigResultBuffer  = (SecM_ResultBufferType)&crcWrittenParam;
      pVerifyContext[index].currentHash.length           = sizeof(SecM_CRCParamType);
#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      pVerifyContext[index].currentDataLength            = SEC_DATA_LENGTH_NULL;
#endif
   }
#endif

   result = SecM_VerificationWrapper(pVerifyParam, pCfgList);
#if defined( SEC_ENABLE_CRC )
#if defined( SEC_ENABLE_CRC_TOTAL )

   pVerifyParam->crcTotal = crcTotalParam.currentCRC;
#else
   pVerifyParam->crcTotal = crcZeroValue;
#endif
#endif
   return result;
}

#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )

void SecM_UpdateDataLength( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam ){
   SecM_SizeType dataLength;

   if(SEC_DATA_LENGTH_NULL != pVerifyParam->currentDataLength){
      dataLength = *(pVerifyParam->currentDataLength);

      switch(pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
            dataLength = 0u;

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            dataLength += pVerifyParam->sigByteCount;

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            dataLength >>= 6u;

            break;
         }
         case SEC_SIG_VERIFY:
         default:
         {
            break;
         }
      }

      *(pVerifyParam->currentDataLength) = dataLength;
   }
}
#endif

SecM_StatusType SecM_InitVerification( SecM_VerifyInitType init ){
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )

   (void)init;
#endif

   return SECM_OK;
}

SecM_StatusType SecM_DeinitVerification( SecM_VerifyDeinitType deinit ){
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )

   (void)deinit;
#endif

   return SECM_OK;
}

#if defined( SEC_ENABLE_CRC_TOTAL ) || \
    defined( SEC_ENABLE_CRC_WRITTEN )

SecM_StatusType SecM_VerifyChecksumCrc( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam ){
   SecM_StatusType result;
   V_MEMRAM1 SecM_CRCParamType V_MEMRAM2 V_MEMRAM3 * pCrcParam;
   SecM_ByteType  crcAction;

   result      = SECM_VER_ERROR;
   crcAction   = SEC_CRC_NONE;

   if(pVerifyParam->currentHash.length >= sizeof(SecM_CRCParamType)){
      pCrcParam = (V_MEMRAM1 SecM_CRCParamType V_MEMRAM2 V_MEMRAM3 *)(pVerifyParam->currentHash.sigResultBuffer);

      switch(pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
            crcAction = SEC_CRC_INIT;

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            crcAction = SEC_CRC_COMPUTE;

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            crcAction = SEC_CRC_FINALIZE;

            break;
         }
         case SEC_SIG_VERIFY:
         {
#if defined( SEC_ENABLE_CRC_WRITTEN_GET )

            pCrcParam->crcOutputBuffer = pVerifyParam->sigSourceBuffer;
            crcAction = SEC_CRC_GET;
#else

            if(pVerifyParam->sigByteCount >= SEC_SIZE_CHECKSUM_CRC)
            {
               crcAction = SEC_CRC_VERIFY;
            }
#endif
            break;
         }
         default:
         {
            break;
         }
      }

      if(SEC_CRC_NONE != crcAction)
      {
         pCrcParam->crcByteCount    = pVerifyParam->sigByteCount;
         pCrcParam->crcSourceBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->wdTriggerFct    = pVerifyParam->wdTriggerFct;
         pCrcParam->crcState        = crcAction;

         result = SecM_ComputeCRC(pCrcParam);
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_VERIFY_CRC )

SecM_StatusType SecM_VerifyCrc( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId ){
   SecM_StatusType result;
   V_MEMROM1 SecM_CrcPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive;
   SecM_ByteType  crcAction;

   result = SECM_VER_ERROR;

   if(primitiveId < SecM_GetSizeOfCrcPrimitives()){
      pPrimitive = &SecM_CrcPrimitives[primitiveId];
      crcAction = SEC_CRC_NONE;

#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      if(pPrimitive->updateVerifiedData == TRUE)
      {
         SecM_UpdateDataLength(pVerifyParam);
      }
#endif

      switch(pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
            crcAction = SEC_CRC_INIT;

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            crcAction = SEC_CRC_COMPUTE;

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            crcAction = SEC_CRC_FINALIZE;

            break;
         }
         case SEC_SIG_VERIFY:
         {
            if(pVerifyParam->sigByteCount >= pPrimitive->crcSize)
            {
               if(pPrimitive->computationOnly == TRUE)
               {
                  if(pPrimitive->crcType == SEC_CRC_TYPE)
                  {
                     crcAction = SEC_CRC_GET;
                  }
               }
               else
               {
                  crcAction = SEC_CRC_VERIFY;
               }
            }

            break;
         }
         default:
         {
            break;
         }
      }

      if(SEC_CRC_NONE != crcAction)
      {
         if(SecM_CopyCrcParam(pVerifyParam, crcAction, pPrimitive) == SECM_OK)
         {
            result = pPrimitive->pCrcFunc((void*)pVerifyParam->currentHash.sigResultBuffer);
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_VERIFY_HASH )

SecM_StatusType SecM_VerifyHash( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId ){
   SecM_StatusType result;
   V_MEMROM1 SecM_HashPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive;

   result = SECM_VER_ERROR;

   if(primitiveId < SecM_GetSizeOfHashPrimitives()){
      pPrimitive = &SecM_HashPrimitives[primitiveId];

#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      if(pPrimitive->updateVerifiedData == TRUE)
      {
         SecM_UpdateDataLength(pVerifyParam);
      }
#endif

      switch(pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
            result = SecM_HashJob(pPrimitive->jobId, SECM_OPERATIONMODE_START, NULL_PTR, 0, NULL_PTR, NULL_PTR);

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            result = SecM_HashJob(pPrimitive->jobId, SECM_OPERATIONMODE_UPDATE, pVerifyParam->sigSourceBuffer
   ,              pVerifyParam->sigByteCount, NULL_PTR, NULL_PTR);

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            uint32 hashResultLength = pPrimitive->digestLength;

            if(SecM_HashJob(pPrimitive->jobId, SECM_OPERATIONMODE_FINISH, NULL_PTR, 0u, pPrimitive->digest
   ,              &hashResultLength) == SECM_OK)
            {
               if(hashResultLength == pPrimitive->digestLength)
               {
                  result = SECM_VER_OK;
               }
            }

            break;
         }
         case SEC_SIG_VERIFY:
         {
            if(pPrimitive->computationOnly == TRUE)
            {
               result = SecM_CopyDigest(pPrimitive->digest, pPrimitive->digestLength, pVerifyParam->sigSourceBuffer
   ,                 pVerifyParam->sigByteCount);

               pVerifyParam->sigByteCount = pPrimitive->digestLength;
            }
            else
            {
               result = SecM_CompareDigest(pPrimitive->digest, pPrimitive->digestLength
   ,                 pVerifyParam->sigSourceBuffer, pVerifyParam->sigByteCount);
            }

            break;
         }
         default:
         {
            break;
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_VERIFY_MAC )

SecM_StatusType SecM_VerifyMac( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId ){
   SecM_StatusType result;
   V_MEMROM1 SecM_MacPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive;

   result = SECM_VER_ERROR;

   if(primitiveId < SecM_GetSizeOfMacPrimitives()){
      pPrimitive = &SecM_MacPrimitives[primitiveId];

#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      if(pPrimitive->updateVerifiedData == TRUE)
      {
         SecM_UpdateDataLength(pVerifyParam);
      }
#endif

      switch(pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
#if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING )
            if(pPrimitive->pVerWks != V_NULL)
            {
               pPrimitive->pVerWks->size = 0u;
            }
#endif
            if(pPrimitive->computationOnly == TRUE)
            {
#if defined( SEC_ENABLE_JOB_MACGENERATE )

               result = SecM_MacGenerateJob(pPrimitive->jobId, SECM_OPERATIONMODE_START, pVerifyParam->key
   ,                 NULL_PTR, 0u, NULL_PTR, NULL_PTR);
#endif
            }
            else
            {
#if defined( SEC_ENABLE_JOB_MACVERIFY )

               result = SecM_MacVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_START, pVerifyParam->key
   ,                 NULL_PTR, 0u, NULL_PTR, 0u);
#endif
            }

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            if(pPrimitive->computationOnly == TRUE)
            {
#if defined( SEC_ENABLE_JOB_MACGENERATE )

               result = SecM_MacGenerateJob(pPrimitive->jobId, SECM_OPERATIONMODE_UPDATE, NULL_PTR, pVerifyParam->sigSourceBuffer
   ,                 pVerifyParam->sigByteCount, NULL_PTR, NULL_PTR);
#endif
            }
            else
            {
#if defined( SEC_ENABLE_JOB_MACVERIFY )

               result = SecM_MacVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_UPDATE, NULL_PTR, pVerifyParam->sigSourceBuffer
   ,                 pVerifyParam->sigByteCount, NULL_PTR, 0u);
#endif
            }

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            result = SECM_VER_OK;

            break;
         }
         case SEC_SIG_VERIFY:
         {
            SecM_StatusType ctxResult = SECM_VER_OK;

#if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING )
            if(pPrimitive->pVerWks != V_NULL)
            {
               ctxResult = SecM_VerifyContextHandling(pPrimitive->jobId, pPrimitive->contextBufferSize, &(pPrimitive->pVerWks->size), pPrimitive->pVerWks->data);
            }
#endif

            if(ctxResult == SECM_VER_OK)
            {
               if(pPrimitive->computationOnly == TRUE)
               {
#if defined( SEC_ENABLE_JOB_MACGENERATE )
                  SecM_WordType macResultLength = pVerifyParam->sigByteCount;

                  result = SecM_MacGenerateJob(pPrimitive->jobId, SECM_OPERATIONMODE_FINISH, NULL_PTR, NULL_PTR, 0
   ,                    pVerifyParam->sigSourceBuffer, &macResultLength);

                  pVerifyParam->sigByteCount = (SecM_LengthType)macResultLength;
#endif
               }
               else
               {
#if defined( SEC_ENABLE_JOB_MACVERIFY )
                  result = SecM_MacVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_FINISH, NULL_PTR, NULL_PTR, 0u, pVerifyParam->sigSourceBuffer
   ,                    pVerifyParam->sigByteCount);
#endif
               }
            }

            break;
         }
         default:
         {
            break;
         }
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_VERIFY_SIGNATURE )

SecM_StatusType SecM_VerifySig( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId ){
   SecM_StatusType result;
   V_MEMROM1 SecM_SigPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive;

   result = SECM_VER_ERROR;

   if(primitiveId < SecM_GetSizeOfSignaturePrimitives()){
      pPrimitive = &SecM_SignaturePrimitives[primitiveId];

#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      if(pPrimitive->updateVerifiedData == TRUE)
      {
         SecM_UpdateDataLength(pVerifyParam);
      }
#endif

      switch(pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
#if defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )

            if(pPrimitive->pVerWks != V_NULL)
            {
               pPrimitive->pVerWks->size = 0u;
            }
#endif
            if(pPrimitive->hashJobId == SEC_INVALID_SMH_JOB_ID)
            {
               result = SecM_SignatureVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_START, pVerifyParam->key
   ,                 NULL_PTR, 0u, NULL_PTR, 0u);
            }
#if defined( SEC_ENABLE_VERIFICATION_DISCRETE_HASH_CALC )
            else
            {
               result = SecM_HashJob(pPrimitive->hashJobId, SECM_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, NULL_PTR);
            }
#endif

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            if(pPrimitive->hashJobId == SEC_INVALID_SMH_JOB_ID)
            {
               result = SecM_SignatureVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_UPDATE, NULL_PTR
   ,                 pVerifyParam->sigSourceBuffer, pVerifyParam->sigByteCount, NULL_PTR, 0u);
            }
#if defined( SEC_ENABLE_VERIFICATION_DISCRETE_HASH_CALC )
            else
            {
               result = SecM_HashJob(pPrimitive->hashJobId, SECM_OPERATIONMODE_UPDATE
   ,                 pVerifyParam->sigSourceBuffer, pVerifyParam->sigByteCount, NULL_PTR, NULL_PTR);
            }
#endif

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            result = SECM_VER_OK;
            break;
         }
         case SEC_SIG_VERIFY:
         {
            SecM_StatusType ctxResult = SECM_VER_OK;
#if defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )
            SecM_WordType localJobId;

            if(pPrimitive->pVerWks != V_NULL)
            {
               localJobId = pPrimitive->jobId;
#if defined( SEC_ENABLE_VERIFICATION_DISCRETE_HASH_CALC )
               if(pPrimitive->hashJobId != SEC_INVALID_SMH_JOB_ID)
               {
                  localJobId = pPrimitive->hashJobId;
               }
#endif
               ctxResult = SecM_VerifyContextHandling(localJobId, pPrimitive->contextBufferSize, &(pPrimitive->pVerWks->size), pPrimitive->pVerWks->data);
            }
#endif

            if(ctxResult == SECM_VER_OK)
            {
               if(pPrimitive->hashJobId == SEC_INVALID_SMH_JOB_ID)
               {
                  SecM_ByteType dummy[1u] = { 0u };

                  result = SecM_SignatureVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_FINISH, NULL_PTR, dummy, 0u
   ,                    pVerifyParam->sigSourceBuffer, pVerifyParam->sigByteCount);
               }
#if defined( SEC_ENABLE_VERIFICATION_DISCRETE_HASH_CALC )
               else
               {
                  SecM_WordType hashLength = pPrimitive->hashDigestLength;

                  if(SecM_HashJob(pPrimitive->hashJobId, SECM_OPERATIONMODE_FINISH, NULL_PTR, 0u, pPrimitive->hashDigest, &hashLength) == SECM_OK)
                  {
                     if(hashLength == pPrimitive->hashDigestLength)
                     {
                        result = SecM_SignatureVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_SINGLECALL, pVerifyParam->key, pPrimitive->hashDigest, pPrimitive->hashDigestLength, pVerifyParam->sigSourceBuffer, pVerifyParam->sigByteCount);
                     }
                  }
               }
#endif
            }
            break;
         }
         default:
         {
            break;
         }
      }
   }

   return result;
}
#endif

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

