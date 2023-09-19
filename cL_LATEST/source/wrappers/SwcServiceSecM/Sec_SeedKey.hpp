

#ifndef SEC_SEEDKEY_H
#define SEC_SEEDKEY_H

#define SECACCESS_API_VERSION_MAJOR       0x01u

#define SECACCESS_API_VERSION_MINOR       0x02u

#define SECACCESS_API_VERSION_RELEASE     0x00u

#include "Sec_Inc.hpp"

#if defined( SEC_ENABLE_SEEDKEY )

#include "Sec_SeedKey_Cfg.hpp"

#if defined( SEC_BYTE_ARRAY_SEED )

#if(SEC_SEED_LENGTH < SEC_WORD_TYPE_SIZE)
#define SEC_INITIAL_SEED_LENGTH   SEC_SEED_LENGTH
#else
#define SEC_INITIAL_SEED_LENGTH   SEC_WORD_TYPE_SIZE
#endif
#elif defined( SEC_WORD_ARRAY_SEED )
#define SEC_INITIAL_SEED_LENGTH    SEC_WORD_TYPE_SIZE

#define SEC_SEED_WORD_LENGTH       (((SEC_SEED_LENGTH - 1u) / SEC_WORD_TYPE_SIZE) + 1u)
#else
#define SEC_INITIAL_SEED_LENGTH    (SEC_WORD_TYPE_SIZE * 2u)
#endif

#if defined( SEC_BYTE_ARRAY_KEY )

typedef SecM_ByteType      SecM_KeyBaseType;

typedef SecM_KeyBaseType   SecM_KeyStorageType[SEC_KEY_LENGTH];
#else

typedef SecM_WordType      SecM_KeyBaseType;

typedef SecM_KeyBaseType   SecM_KeyStorageType;
#endif

#if defined( SEC_BYTE_ARRAY_SEED )

typedef SecM_ByteType      SecM_SeedBaseType;

typedef SecM_SeedBaseType  SecM_SeedStorageType[SEC_SEED_LENGTH];
#elif defined( SEC_WORD_ARRAY_SEED )

typedef SecM_WordType      SecM_SeedBaseType;

typedef SecM_SeedBaseType  SecM_SeedStorageType[SEC_SEED_WORD_LENGTH];
#else

typedef struct{
   SecM_WordType seedX;
   SecM_WordType seedY;
}SecM_SeedBaseType;

typedef SecM_SeedBaseType  SecM_SeedStorageType;
#endif

typedef SecM_WordType      SecM_ConstBaseType;

#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API ) || \
    defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )

typedef struct{
   SecM_WorkspaceType   workspace;

   FL_WDTriggerFctType  wdTriggerFct;
}SecM_SeedKeyContextType;
#endif

#if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
typedef SecM_SeedKeyContextType  SecM_GenerateSeedParamType;
#endif

#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )

typedef SecM_SeedKeyContextType  SecM_ComputeKeyParamType;

typedef struct{
   SecM_ComputeKeyParamType   common;

   SecM_SymKeyType            secretKey;
}SecM_ComputeKeySymParamType;

typedef struct{
   SecM_ComputeKeyParamType   common;

   SecM_AsymKeyType           publicKey;
}SecM_ComputeKeyAsymParamType;

typedef struct{
   SecM_ConstBaseType   constant;

   SecM_VoidPtrType     context;
}SecM_ConstType;
#else

typedef SecM_ConstBaseType SecM_ConstType;
#endif

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )

typedef enum{
   SEC_RNG_UNINTIALIZED
   ,  SEC_RNG_INTIALIZED
}SecM_RngState;

typedef struct{
   SecM_ByteType     data[SEC_ENTROPY_POOL_SIZE];
   SecM_LengthType   fillLevel;
   SecM_LengthType   offset;
   SecM_RngState     state;
   SecM_VoidPtrType  context;
}SecM_EntropyPoolType;
#endif

#if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )

typedef struct{
   V_MEMRAM1 SecM_SeedBaseType V_MEMRAM2 V_MEMRAM3 *     data;
   V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 *  entropyPool;
}SecM_SeedType;
#else
typedef SecM_SeedStorageType  SecM_SeedType;
#endif

#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )

typedef struct{
   V_MEMRAM1 SecM_KeyBaseType V_MEMRAM2 V_MEMRAM3 *   data;

   SecM_VoidPtrType                                   context;
}SecM_KeyType;
#else

typedef SecM_KeyStorageType   SecM_KeyType;
#endif

typedef SecM_StatusType SEC_CALL_TYPE (* pSecGenerateSeedFct)( V_MEMRAM1 SecM_SeedType V_MEMRAM2 V_MEMRAM3 * seed );
#if defined( SEC_ENABLE_SEED_KEY_ASYMMETRIC )
typedef SecM_StatusType SEC_CALL_TYPE (* pSecComputeKeyFct)( SecM_KeyStorageType inputKey, SecM_ConstType constant
   ,  V_MEMRAM1 SecM_SeedStorageType V_MEMRAM2 V_MEMRAM3 * computedSeed );
#else
typedef SecM_StatusType SEC_CALL_TYPE (* pSecComputeKeyFct)( SecM_SeedStorageType inputSeed, SecM_ConstType constant
   ,  V_MEMRAM1 SecM_KeyStorageType V_MEMRAM2 V_MEMRAM3 * computedKey );
#endif
typedef SecM_StatusType SEC_CALL_TYPE (* pSecCompareKeyFct)( SecM_KeyType key, SecM_SeedType lastSeed );

#if defined( __cplusplus )
extern "C" {
#endif

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

extern SecM_StatusType SecM_GenerateSeed( V_MEMRAM1 SecM_SeedType V_MEMRAM2 V_MEMRAM3 * seed );
#if defined( SEC_ENABLE_SEED_KEY_ASYMMETRIC )
extern SecM_StatusType SecM_ComputeKey( SecM_KeyStorageType inputKey, SecM_ConstType constant
   ,  V_MEMRAM1 SecM_SeedStorageType V_MEMRAM2 V_MEMRAM3 * computedSeed );
#else
extern SecM_StatusType SecM_ComputeKey( SecM_SeedStorageType inputSeed, SecM_ConstType constant
   ,  V_MEMRAM1 SecM_KeyStorageType V_MEMRAM2 V_MEMRAM3 * computedKey );
#endif
extern SecM_StatusType SecM_CompareKey( SecM_KeyType key, SecM_SeedType lastSeed );

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL ) && \
    defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
void SecM_InitEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool );

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#define SECM_RAMCODE_START_SEC_CODE
#include "MemMap.hpp"
void SecM_ProvideEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool
   ,  V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * entropy, SecM_LengthType length );
#define SECM_RAMCODE_STOP_SEC_CODE
#include "MemMap.hpp"

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

#endif

#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
extern SecM_StatusType SecM_CompareKeyVendor( SecM_KeyStorageType key, SecM_SeedStorageType seed, SecM_ConstType constant );
#else
#if defined( SEC_ENABLE_SEED_KEY_ASYMMETRIC )
extern SecM_StatusType SecM_ComputeKeyVendor( SecM_KeyStorageType inputKey, SecM_ConstType constant
   ,  V_MEMRAM1 SecM_SeedStorageType V_MEMRAM2 V_MEMRAM3 * computedSeed );
#else
extern SecM_StatusType SecM_ComputeKeyVendor( SecM_SeedStorageType inputSeed, SecM_ConstType constant
   ,  V_MEMRAM1 SecM_KeyStorageType V_MEMRAM2 V_MEMRAM3 * computedKey );
#endif
#endif

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#if defined( __cplusplus )
}
#endif

#if defined( SEC_WORD_ARRAY_SEED )
#if( (SEC_SEED_LENGTH % 4u) != 0u )
#error "Error in configuration: Seed lengths (in bytes) has to be a multiple of 4!"
#endif
#endif

#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )
#if defined( SEC_BYTE_ARRAY_SEED ) || \
     defined( SEC_WORD_ARRAY_SEED )
#else
#error "Error in configuration: Asymmetric seed/key calculation only supports seed data stored as array!"
#endif
#endif
#endif
#endif

