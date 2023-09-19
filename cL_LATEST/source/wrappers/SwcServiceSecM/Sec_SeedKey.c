

#define SEC_SEEDKEY_SOURCE

#include "Sec_Inc.hpp"

#if defined( SEC_ENABLE_SEEDKEY )

#include "Sec_Types.hpp"

#include "Sec_SeedKey.hpp"

#include "Sec.hpp"

#if defined( SECACCESS_API_REFERENCE_VERSION_MAJOR ) && \
    defined( SECACCESS_API_REFERENCE_VERSION_MINOR )
#else
# error "Error in Sec_SeedKey.c: Interface version requirements not defined!"
#endif

#if( SECACCESS_API_REFERENCE_VERSION_MAJOR != SECACCESS_API_VERSION_MAJOR) || \
    ( SECACCESS_API_REFERENCE_VERSION_MINOR > SECACCESS_API_VERSION_MINOR)
# error "Error in Sec_SeedKey.c: Interface version compatibility check failed!"
#endif

#if defined( SEC_COMPARE_SIZE )
# undef SEC_COMPARE_SIZE
#endif

#if defined( SEC_BYTE_ARRAY_KEY )

#define SEC_COMPARE_SIZE    SEC_KEY_LENGTH
#endif
#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )

#define SEC_COMPARE_VALUE   key.data
#else

#define SEC_COMPARE_VALUE   key
#endif

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL ) && \
    defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )

#if defined( SEC_BYTE_ARRAY_SEED ) || \
     defined( SEC_WORD_ARRAY_SEED )
#define SEC_BASE_SEED(seed)  ((seed).data)
#else
#define SEC_BASE_SEED(seed)  (*((seed).data))
#endif
#else

#define SEC_BASE_SEED(seed)  (seed)
#endif

#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )

#define SEC_BASE_KEY(key)    ((key).data)
#else

#define SEC_BASE_KEY(key)    (key)
#endif

typedef SecM_KeyStorageType   SecM_CompareType;

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

static SecM_StatusType SecM_GenerateRandom( V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pRandom, SecM_WordType length );
#if defined( SEC_ENABLE_SEED_KEY_PRNG_LCG )
static SecM_WordType SecM_LcgRandom( SecM_WordType input );
static SecM_StatusType SecM_GenerateRandomLcg( V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pRandom
   ,  V_MEMRAM1 SecM_WordType V_MEMRAM2 V_MEMRAM3 * pLength );
#endif

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
static SecM_StatusType SecM_ConsumeEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool
   ,  SecM_LengthType consumed );
#if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
#else
static void SecM_InitEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool );
#endif
#endif

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
#if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
#else
#define SECM_RAMCODE_START_SEC_CODE
#include "MemMap.hpp"
static void SecM_ProvideEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool
   ,  V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * entropy, SecM_LengthType length );
#define SECM_RAMCODE_STOP_SEC_CODE
#include "MemMap.hpp"
#endif
#endif

#define SECM_START_SEC_VAR
#include "MemMap.hpp"

#define SECM_STOP_SEC_VAR
#include "MemMap.hpp"

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

static SecM_StatusType SecM_GenerateRandom( V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pRandom, SecM_WordType length ){
   SecM_StatusType result = SECM_NOT_OK;
   SecM_WordType localLength = length;
   SecM_WordType * pLength = &localLength;

   if(SEC_PRNG_GENERATE_RANDOM(pRandom, pLength) == SECM_OK){
      if(length == localLength)
      {
         result = SECM_OK;
      }
   }

   return result;
}

#if defined( SEC_ENABLE_SEED_KEY_PRNG_LCG )

static SecM_WordType SecM_LcgRandom( SecM_WordType input ){
   SecM_WordType  output;

   output = (input * SEC_LCG_RANDOM_MULTIPLIER) + SEC_LCG_RANDOM_INCREMENT;

   return output;
}

static SecM_StatusType SecM_GenerateRandomLcg( V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pRandom
   ,  V_MEMRAM1 SecM_WordType V_MEMRAM2 V_MEMRAM3 * pLength ){
   SecM_ShortFastType   index;
   SecM_ShortFastType   remainderLength;
   SecM_ShortFastType   byteCount;
   SecM_WordType        randomWord;

   byteCount = *pLength;
   if(byteCount > SEC_WORD_TYPE_SIZE){
      byteCount = SEC_WORD_TYPE_SIZE;
   }

   randomWord = SecM_GetInteger(byteCount, pRandom);

   remainderLength = *pLength;

   index = 0u;

   while(remainderLength > 0u){
      randomWord = SecM_LcgRandom(randomWord);

      if(remainderLength < SEC_WORD_TYPE_SIZE)
      {
         byteCount = remainderLength;
      }
      else
      {
         byteCount = SEC_WORD_TYPE_SIZE;
      }

      SecM_SetInteger(byteCount, randomWord, &pRandom[index]);

      index += SEC_WORD_TYPE_SIZE;
      remainderLength -= byteCount;
   }

   return SECM_OK;
}
#endif

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )

static SecM_StatusType SecM_ConsumeEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool
   ,  SecM_LengthType consumed ){
   SecM_StatusType      result;
   SecM_ShortFastType   index;
   SecM_LengthType      offset;
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pSource;
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pTarget;

   result = SECM_OK;

   if(consumed > pEntropyPool->fillLevel){
      result = SECM_NOT_OK;
   }
   else{
      if(consumed > 0u)
      {
         pSource = &pEntropyPool->data[consumed];
         pTarget = pEntropyPool->data;

         for(index = 0u; index < (SEC_ENTROPY_POOL_SIZE - (SecM_ShortFastType)consumed); index++)
         {
            pTarget[index] = pSource[index];
         }

         pEntropyPool->fillLevel -= consumed;

         offset = pEntropyPool->fillLevel;
         if(offset >= SEC_ENTROPY_POOL_SIZE)
         {
            offset = 0u;
         }

         pEntropyPool->offset = offset;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )

#if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
void SecM_InitEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool )
#else
static void SecM_InitEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool )
#endif
{
   SecM_SizeType index;
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pPool;

   pEntropyPool->fillLevel = 0u;
   pEntropyPool->offset    = 0u;
   pEntropyPool->state     = SEC_RNG_UNINTIALIZED;

   pPool = pEntropyPool->data;
   for(index = 0u; index < SEC_ENTROPY_POOL_SIZE; index++){
      pPool[index] = 0x00u;
   }
}
#endif

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
#define SECM_RAMCODE_START_SEC_CODE
#include "MemMap.hpp"

#if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
void SecM_ProvideEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool
   ,  V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * entropy, SecM_LengthType length )
#else
static void SecM_ProvideEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool
   ,  V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * entropy, SecM_LengthType length )
#endif
{
   SecM_ShortFastType   index;
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pPool;
   SecM_LengthType      fillLevel;
   SecM_LengthType      offset;

   pPool       = pEntropyPool->data;
   fillLevel   = pEntropyPool->fillLevel;
   offset      = pEntropyPool->offset;

   for(index = 0u; index < length; index++){
      pPool[offset] ^= entropy[index];

      offset++;
      if(offset >= SEC_ENTROPY_POOL_SIZE)
      {
         offset = 0u;
      }

      if(fillLevel < SEC_ENTROPY_POOL_SIZE)
      {
         fillLevel++;
      }
   }

   pEntropyPool->fillLevel = fillLevel;
   pEntropyPool->offset    = offset;
}
#define SECM_RAMCODE_STOP_SEC_CODE
#include "MemMap.hpp"
#endif

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

SecM_StatusType SecM_GenerateSeed( V_MEMRAM1 SecM_SeedType V_MEMRAM2 V_MEMRAM3 * seed ){
   SecM_StatusType result;
   V_MEMRAM1 SecM_SeedBaseType V_MEMRAM2 V_MEMRAM3 * pBaseSeed;
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pRandom;
#if defined( SEC_BYTE_ARRAY_SEED )
#else
   SecM_ByteType        randomBuffer[SEC_INITIAL_SEED_LENGTH];
#if defined( SEC_WORD_ARRAY_SEED )
   SecM_ShortFastType   index;
#endif
#endif

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
   V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pPool;
#if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
#else
   SecM_EntropyPoolType entropyPool;
#endif
#endif

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL ) && \
    defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
   pBaseSeed = seed->data;
#else

   pBaseSeed = (V_MEMRAM1 SecM_SeedBaseType V_MEMRAM2 V_MEMRAM3 *)seed;
#endif

#if defined( SEC_BYTE_ARRAY_SEED )

   pRandom = pBaseSeed;
#else

   pRandom = randomBuffer;

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL ) && \
     defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
#else

#if defined( SEC_WORD_ARRAY_SEED )
   SecM_SetInteger(SEC_INITIAL_SEED_LENGTH, pBaseSeed[0], randomBuffer);
#else
   SecM_SetInteger(SEC_WORD_TYPE_SIZE, pBaseSeed->seedX, &randomBuffer[0u]);
   SecM_SetInteger(SEC_WORD_TYPE_SIZE, pBaseSeed->seedY, &randomBuffer[SEC_WORD_TYPE_SIZE]);
#endif
#endif
#endif

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
#if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )

   pPool = seed->entropyPool;
#else

   pPool = &entropyPool;

   SecM_InitEntropy(pPool);

   SecM_ProvideEntropy(pPool, pRandom, SEC_INITIAL_SEED_LENGTH);
#endif

   result = SECM_OK;

   if(SEC_RNG_UNINTIALIZED == pPool->state){
      if(pPool->fillLevel == 0u)
      {
         result = SECM_NOT_OK;
      }
      else
      {
         pPool->fillLevel = (SecM_LengthType)SEC_ENTROPY_POOL_SIZE;
         result = SEC_PRNG_INIT_ENTROPY(pPool);

         if(SecM_ConsumeEntropy(pPool, pPool->fillLevel) != SECM_OK)
         {
            result = SECM_NOT_OK;
         }

#if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
         if(result == SECM_OK)
         {
            pPool->state = SEC_RNG_INTIALIZED;
         }
#endif
      }
   }
   else{
      if(pPool->fillLevel >= (SecM_LengthType)SEC_ENTROPY_POOL_SIZE)
      {
         result = SEC_PRNG_STIR_ENTROPY(pPool);

         if(SecM_ConsumeEntropy(pPool, pPool->fillLevel) != SECM_OK)
         {
            result = SECM_NOT_OK;
         }
      }
   }

   if(result == SECM_OK)
#endif
   {
#if defined( SEC_BYTE_ARRAY_SEED )

      result = SecM_GenerateRandom(pRandom, SEC_SEED_LENGTH);

#elif defined( SEC_WORD_ARRAY_SEED )

      for(index = 0u; index < SEC_SEED_WORD_LENGTH; index++)
      {
         result = SecM_GenerateRandom(pRandom, SEC_WORD_TYPE_SIZE);

         pBaseSeed[index]  = SecM_GetInteger(SEC_WORD_TYPE_SIZE, pRandom);

         if(result != SECM_OK)
         {
            break;
         }
      }
#else

      result = SecM_GenerateRandom(pRandom, SEC_WORD_TYPE_SIZE);
      pBaseSeed->seedX = SecM_GetInteger(SEC_WORD_TYPE_SIZE, pRandom);

      if(result == SECM_OK)
      {
         result = SecM_GenerateRandom(pRandom, SEC_WORD_TYPE_SIZE);
         pBaseSeed->seedY = SecM_GetInteger(SEC_WORD_TYPE_SIZE, pRandom);

      }
#endif

      if(result == SECM_OK)
      {
         SecM_StartKeyTimer();
      }
   }

   return result;
}

#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
#else

SecM_StatusType SecM_ComputeKey( SecM_SeedStorageType inputSeed, SecM_ConstType constant
   ,  V_MEMRAM1 SecM_KeyStorageType V_MEMRAM2 V_MEMRAM3 * computedKey ){
   SecM_StatusType result;

   result = SecM_ComputeKeyVendor(inputSeed, constant, computedKey);

   return result;
}
#endif

SecM_StatusType SecM_CompareKey( SecM_KeyType key, SecM_SeedType lastSeed ){
   SecM_StatusType      result;
   SecM_ConstType       keyConstant;

#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
#else
   volatile SecM_CompareType computeVal;
#if defined( SEC_COMPARE_SIZE )
   SecM_ShortFastType   index;
#endif

#if defined( SEC_COMPARE_SIZE )
   for(index = 0u; index < SEC_COMPARE_SIZE; index++){
      computeVal[index] = 0u;
   }
#else
   computeVal = 0u;
#endif
#endif

   result = SECM_NOT_OK;

   if(SecM_GetKeyTimer() > 0u){
#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )

      keyConstant.constant = SEC_ECU_KEY;

      keyConstant.context  = key.context;
#else

      keyConstant = SEC_ECU_KEY;
#endif

#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
      result = SecM_CompareKeyVendor(SEC_BASE_KEY(key), SEC_BASE_SEED(lastSeed), keyConstant);
#else
      result = SecM_ComputeKey(SEC_BASE_SEED(lastSeed), keyConstant, (SecM_CompareType*)&computeVal);

#if defined( SEC_COMPARE_SIZE )
      for(index = 0u; index < SEC_COMPARE_SIZE; index++)
      {
         if(computeVal[index] != SEC_COMPARE_VALUE[index])
         {
            result = SECM_NOT_OK;
         }
      }
#else
      if(computeVal != SEC_COMPARE_VALUE)
      {
         result = SECM_NOT_OK;
      }
#endif
#endif

      SecM_StopKeyTimer();
   }

#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
#else

#if defined( SEC_COMPARE_SIZE )
   for(index = 0u; index < SEC_COMPARE_SIZE; index++){
      computeVal[index] = 0u;
   }
#else
   computeVal = 0u;
#endif
#endif

   return result;
}

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#endif

