

#ifndef SECM_TYPES_H
#define SECM_TYPES_H

#include "v_cfg.hpp"
#include "Fbl_Cfg.hpp"

#include "v_def.hpp"

#include "Std_Types.hpp"
#if defined( SEC_ENABLE_CSM )
# include "Csm_Types.hpp"
#endif

#if defined( SEC_WATCHDOG_CYCLE_COUNT )
#else

# define SEC_WATCHDOG_CYCLE_COUNT   (0x20u)
#endif

#define SECM_OK      0x00u

#define SECM_NOT_OK  0xFFu

#if defined( SEC_CALL_TYPE )
#else

# define SEC_CALL_TYPE
#endif

#define SEC_RAM_DATA_NULL              ((SecM_RamDataType)V_NULL)

#define SEC_DEFAULT_WORKSPACE          ((SecM_WorkspacePtrType)V_NULL)

#define SEC_DEFAULT_WORKSPACE_SIZE     0u

#define SEC_DEFAULT_KEY_SIZE           0u

#define SEC_WATCHDOG_NONE              ((FL_WDTriggerFctType)0u)

#define SEC_WATCHDOG_TRIGGER(function)    \
   if((SEC_WATCHDOG_NONE) != (function)) \
   {                                      \
      (function)();                       \
   }

#if( SEC_WATCHDOG_CYCLE_COUNT == 1uL )

# define SEC_WATCHDOG_CYCLE_TRIGGER(function, cycle)           \
   {                                                           \
      SEC_WATCHDOG_TRIGGER(function);                          \
   }
#else

# define SEC_WATCHDOG_CYCLE_TRIGGER(function, cycle)           \
   if(((cycle) & (SEC_WATCHDOG_CYCLE_COUNT - 1u)) == 0x00u)   \
   {                                                           \
      SEC_WATCHDOG_TRIGGER(function);                          \
   }
#endif

#define SEC_BYTE_TYPE_SIZE    1u

#define SEC_SHORT_TYPE_SIZE   2u

#define SEC_WORD_TYPE_SIZE    4u

typedef vuint32 SecM_WordType;

typedef vuint8  SecM_ByteType;

typedef vuint16 SecM_ShortType;

typedef V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 *       SecM_RamDataType;

typedef V_MEMRAM1 SecM_ShortType V_MEMRAM2 V_MEMRAM3 *      SecM_RamShortType;

typedef V_MEMRAM1 SecM_WordType V_MEMRAM2 V_MEMRAM3 *       SecM_RamWordType;

typedef const V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * SecM_ConstRamDataType;

typedef const V_MEMRAM1 SecM_WordType V_MEMRAM2 V_MEMRAM3 * SecM_ConstRamWordType;

typedef V_MEMROM1 SecM_ByteType V_MEMROM2 V_MEMROM3 *       SecM_RomDataType;

typedef V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 *                SecM_VoidPtrType;

typedef const V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 *          SecM_ConstVoidPtrType;

typedef V_MEMROM1 void V_MEMROM2 V_MEMROM3 *                SecM_RomVoidPtrType;

typedef SecM_ByteType SecM_StatusType;

typedef SecM_ShortType SecM_LengthType;

typedef SecM_WordType SecM_AddrType;

typedef SecM_WordType SecM_SizeType;

typedef struct{
   SecM_AddrType transferredAddress;
   SecM_AddrType targetAddress;
   SecM_SizeType length;
}FL_SegmentInfoType;

typedef struct{
   SecM_WordType        nrOfSegments;

   V_MEMRAM1 FL_SegmentInfoType V_MEMRAM2 V_MEMRAM3 * segmentInfo;
}FL_SegmentListType;

typedef void (* FL_WDTriggerFctType)( void );

typedef SecM_SizeType (* FL_ReadMemoryFctType)( SecM_AddrType address, SecM_RamDataType buffer, SecM_SizeType length );

#if defined( C_CPUTYPE_8BIT )

typedef SecM_ByteType   SecM_ByteFastType;

typedef SecM_ShortType  SecM_ShortFastType;
#elif defined( C_CPUTYPE_16BIT )
typedef SecM_ShortType  SecM_ByteFastType;
typedef SecM_ShortType  SecM_ShortFastType;
#elif defined( C_CPUTYPE_32BIT )
typedef SecM_WordType   SecM_ByteFastType;
typedef SecM_WordType   SecM_ShortFastType;
#endif

typedef SecM_ShortFastType SecM_LengthFastType;

typedef struct{
   SecM_ConstRamDataType   data;

   SecM_LengthType         size;
}SecM_RamBufferType;

typedef struct{
   SecM_RomDataType  data;

   SecM_LengthType   size;
}SecM_RomBufferType;

typedef struct{
   SecM_RamDataType buffer;

   SecM_ShortType pos;

   SecM_LengthType size;
}SecM_RamBufferProcessingType;

typedef V_MEMRAM1 SecM_RamBufferProcessingType V_MEMRAM2 V_MEMRAM3 * SecM_RamBufferProcessingPtrType;

typedef struct{
   SecM_ByteType  digest[1];
   SecM_WordType  dummy;
}SecM_BasicWkspType;

typedef V_MEMRAM1 SecM_BasicWkspType V_MEMRAM2 V_MEMRAM3 * SecM_WorkspacePtrType;

typedef struct{
   SecM_WorkspacePtrType   data;

   SecM_LengthType         size;
}SecM_WorkspaceType;

typedef struct{
   SecM_ByteType   *data;

   SecM_WordType size;
}SecM_VerificationWksp;

#if defined( SEC_ENABLE_KEY_LOCATION_RAM )
typedef SecM_RamBufferType SecM_CryptKeyType;
#else
typedef SecM_RomBufferType SecM_CryptKeyType;
#endif

typedef SecM_RamBufferType SecM_SymKeyType;

typedef struct{
   SecM_CryptKeyType shared;

   SecM_CryptKeyType individual;
}SecM_AsymKeyType;

typedef struct{
   SecM_CryptKeyType key;

   SecM_CryptKeyType iv;
}SecM_AesKeyType;

typedef struct{
   SecM_CryptKeyType    iterations;
   SecM_CryptKeyType    salt;
   SecM_CryptKeyType    password;
   SecM_CryptKeyType    function;
}SecM_PBKDF2KeyType;

typedef struct{
   SecM_RomDataType  data;

   SecM_LengthType   size;

   uint32 cryptoElementId;
}SecM_CryptographicKeyValueType;

typedef V_MEMROM1 SecM_CryptographicKeyValueType V_MEMROM2 V_MEMROM3 * SecM_CryptographicKeyValuePtrType;

typedef struct{
   SecM_ByteType count;
   SecM_CryptographicKeyValuePtrType keyValues;
}SecM_CryptographicKeyType;

typedef V_MEMROM1 SecM_CryptographicKeyType V_MEMROM2 V_MEMROM3 * SecM_CryptographicKeyPtrType;

typedef enum{
   SECM_HASH,
   SECM_MACVERIFY,
   SECM_MACGENERATE,
   SECM_ENCRYPTION,
   SECM_DECRYPTION,
   SECM_RANDOMGENERATE,
   SECM_RANDOMSEED,
   SECM_SIGNATUREVERIFY,
   SECM_AEADENCRYPT,
   SECM_AEADDECRYPT,
   SECM_KEYDERIVE
}SecM_JobServiceType;

typedef enum{
   SEC_KEY_TYPE_NONE,
   SEC_KEY_TYPE_AES,
   SEC_KEY_TYPE_MAC,
   SEC_KEY_TYPE_SYMMETRIC,
   SEC_KEY_TYPE_ASYMMETRIC,
   SEC_KEY_TYPE_PBKDF2
}SecM_JobKeyType;

typedef enum{
   SEC_BUFF_UNTIL_FULL,
   SEC_BUFF_FIFO
}SecM_BufferMode;

typedef enum{
   SEC_BUFF_OK,
   SEC_BUFF_FULL
}SecM_BufferRetType;

typedef enum{
   SECM_DECRAEAD_AUTHDATA,
   SECM_DECRAEAD_DECRYPT
}SecM_DecrStatusFsm;

typedef struct{
   SecM_ShortType                   authDataLength;
   SecM_ShortType                   dataTagLength;
}SecM_JobDecryptionAEADParamTypes;

typedef struct{
   SecM_JobServiceType service;
   uint32 csmJobId;
   uint32 csmKeyId;
   SecM_WordType smhKeyId;
   SecM_JobKeyType keyType;
   SecM_RomVoidPtrType jobParam;
}SecM_JobInfoType;

typedef V_MEMROM1 SecM_JobInfoType V_MEMROM2 V_MEMROM3 * SecM_JobInfoPtrType;

#if defined( SEC_ENABLE_CSM )
typedef Crypto_OperationModeType SecM_OperationModeType;
# define SECM_OPERATIONMODE_NONE           (0u)
# define SECM_OPERATIONMODE_START          CRYPTO_OPERATIONMODE_START
# define SECM_OPERATIONMODE_IV             (0x10u)
# define SECM_OPERATIONMODE_UPDATE         CRYPTO_OPERATIONMODE_UPDATE
# define SECM_OPERATIONMODE_FINISH         CRYPTO_OPERATIONMODE_FINISH
# define SECM_OPERATIONMODE_STREAMSTART    CRYPTO_OPERATIONMODE_STREAMSTART
# define SECM_OPERATIONMODE_SINGLECALL     CRYPTO_OPERATIONMODE_SINGLECALL
#endif

#if defined( SEC_ENABLE_ENCRYPTION ) || defined( SEC_ENABLE_DECRYPTION )

typedef struct{
   SecM_ConstRamDataType   DataBuffer;
   SecM_LengthType         Length;
}SecM_DecInputParamType;

typedef struct{
   SecM_RamDataType        DataBuffer;
   SecM_LengthType         Length;
}SecM_DecOutputParamType;

typedef struct{
   SecM_AddrType           segmentAddress;

   SecM_SizeType           segmentLength;

   SecM_ByteType           mode;

   FL_WDTriggerFctType     wdTriggerFct;

   SecM_SymKeyType         key;
}SecM_DecParamType;

typedef SecM_StatusType(*SecM_JobDecryptionType)     (SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_RamDataType resultPtr, SecM_WordType * resultLengthPtr);

typedef struct{
   SecM_JobDecryptionType           func;
   SecM_WordType                    jobId;
}SecM_DecPrimitiveType;

#endif

#if defined( SEC_ENABLE_CRC )

typedef SecM_ShortType  SecM_Crc16Type;
typedef SecM_WordType   SecM_Crc32Type;
typedef SecM_WordType   SecM_Crc64BaseType;
typedef struct{
   SecM_Crc64BaseType   highWord;
   SecM_Crc64BaseType   lowWord;
}SecM_Crc64Type;

# if(SEC_CRC_TYPE == SEC_CRC16 )
typedef SecM_Crc16Type        SecM_CRCType;
# elif( SEC_CRC_TYPE == SEC_CRC32 )
typedef SecM_Crc32Type        SecM_CRCType;
# elif( SEC_CRC_TYPE == SEC_CRC64 )
typedef SecM_Crc64Type        SecM_CRCType;
# else
#  error "Unknown CRC type."
# endif

typedef void * SecM_CRCParamGenericType;
typedef SecM_StatusType(*SecM_CRCFunctionGenericType) (void * crcParam);

typedef struct{
   SecM_ByteType crcType;
   SecM_CRCFunctionGenericType pCrcFunc;
   SecM_ByteType crcSize;
   boolean computationOnly;
   boolean updateVerifiedData;
}SecM_CrcPrimitiveType;
#else
typedef SecM_WordType   SecM_CRCType;
#endif

typedef struct{
   SecM_WordType jobId;
   SecM_RamDataType digest;
   SecM_LengthType digestLength;
   boolean computationOnly;
   boolean updateVerifiedData;
}SecM_HashPrimitiveType;

typedef struct{
   SecM_WordType jobId;
   SecM_WordType contextBufferSize;
   V_MEMRAM1 SecM_VerificationWksp V_MEMRAM2 V_MEMRAM3 * pVerWks;
   boolean computationOnly;
   boolean updateVerifiedData;
}SecM_MacPrimitiveType;

typedef struct{
   SecM_WordType jobId;
   SecM_WordType hashJobId;
   SecM_RamDataType hashDigest;
   SecM_LengthType hashDigestLength;
   SecM_WordType contextBufferSize;
   V_MEMRAM1 SecM_VerificationWksp V_MEMRAM2 V_MEMRAM3 * pVerWks;
   boolean updateVerifiedData;
}SecM_SigPrimitiveType;

typedef struct{
   SecM_WordType  jobId;
   uint32         targetKeyId;
}SecM_KeyDerivePrimitiveType;

typedef SecM_SizeType         SecM_ResultBufferType;

typedef SecM_VoidPtrType      SecM_VerifyKeyType;

typedef SecM_RamDataType      SecM_VerifyDataType;

typedef struct{
   FL_SegmentListType   segmentList;

   SecM_AddrType        blockStartAddress;

   SecM_SizeType        blockLength;

   SecM_VerifyDataType  verificationData;

   SecM_CRCType         crcTotal;

   FL_WDTriggerFctType  wdTriggerFct;

   FL_ReadMemoryFctType readMemory;

   SecM_WorkspaceType   workspace;

   SecM_VerifyKeyType   key;
}SecM_VerifyParamType;

typedef struct{
   SecM_ResultBufferType sigResultBuffer;
   SecM_SizeType         length;
}SecM_SignatureType;

typedef struct{
   SecM_SignatureType   currentHash;

   V_MEMRAM1 SecM_SizeType V_MEMRAM2 V_MEMRAM3 * currentDataLength;

   SecM_StatusType      sigState;

   SecM_VerifyDataType  sigSourceBuffer;

   SecM_LengthType      sigByteCount;

   FL_WDTriggerFctType  wdTriggerFct;

   SecM_VerifyKeyType   key;
}SecM_SignatureParamType;

typedef enum{
   CRC_WORKSPACE_UNDEF,
   CRC_WORKSPACE_INIT
}SecM_CrcWorkspaceStateType;

typedef struct{
   SecM_ResultBufferType workspacePtr;
   SecM_SizeType workspaceLength;
   SecM_CrcWorkspaceStateType state;
}SecM_CrcWorkspaceInfoType;

#if( 0u == SEC_WATCHDOG_CYCLE_COUNT ) || \
    ( (SEC_WATCHDOG_CYCLE_COUNT & (SEC_WATCHDOG_CYCLE_COUNT - 1u)) != 0u )
# error "Error in SEC_TYPES.H: Watchdog cycle count has to be a power of two (2^n)!"
#endif

#endif

