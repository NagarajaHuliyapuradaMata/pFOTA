#ifndef SEC_VERIFICATION_H
#define SEC_VERIFICATION_H

#ifndef SEC_ENABLE_VERIFY_SIGNATURE
#define SEC_ENABLE_VERIFY_SIGNATURE
#endif

#include "Sec_Inc.hpp"

#include "Sec_Crc.hpp"

#define SECM_VER_OK        0x00u
#define SECM_VER_ERROR     0x01u
#define SECM_VER_CRC       0x02u
#define SECM_VER_SIG       0x04u

#define kHashInit          0x01u
#define kHashCompute       0x02u
#define kHashFinalize      0x03u
#define kSigVerify         0x04u

#define SEC_HASH_NONE      0x00u
#define SEC_HASH_INIT      kHashInit
#define SEC_HASH_COMPUTE   kHashCompute
#define SEC_HASH_FINALIZE  kHashFinalize
#define SEC_SIG_VERIFY     kSigVerify
#define SEC_CRC_RESTORE    5u

#define SEC_UPDATE_OPERATION_DEFAULT         0x00u
#define SEC_UPDATE_OPERATION_ADDRESS_LENGTH  0x01u
#define SEC_UPDATE_OPERATION_INTER_SEGMENT   0x02u
#define SEC_UPDATE_OPERATION_VERIFICATION    0x04u

#define SEC_DATA_LENGTH_NULL     ((V_MEMRAM1 SecM_SizeType V_MEMRAM2 V_MEMRAM3 *)V_NULL)

#define SEC_VERIFY_KEY_NULL      ((SecM_VerifyKeyType)V_NULL)

#if defined( SEC_VER_ENABLE_CRC_TOTAL )
# ifndef SEC_ENABLE_CRC_TOTAL

#  define SEC_ENABLE_CRC_TOTAL
# endif
#endif
#if defined( SEC_VER_DISABLE_CRC_TOTAL )
# ifndef SEC_DISABLE_CRC_TOTAL

#  define SEC_DISABLE_CRC_TOTAL
# endif
#endif

#if defined( SEC_VER_ENABLE_LENGTH_AND_ADDRESS_INPUT )
# ifndef SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH

#  define SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH
# endif
#endif
#if defined( SEC_VER_DISABLE_LENGTH_AND_ADDRESS_INPUT )
# ifndef SEC_DISABLE_VERIFICATION_ADDRESS_LENGTH

#  define SEC_DISABLE_VERIFICATION_ADDRESS_LENGTH
# endif
#endif

#if defined( SECM_VER_SIG_OFFSET )
# ifndef SEC_VER_SIG_OFFSET

#  define SEC_VER_SIG_OFFSET  SECM_VER_SIG_OFFSET
# endif
#endif
#if defined( SECM_VER_CRC_OFFSET )
# ifndef SEC_VER_CRC_OFFSET

#  define SEC_VER_CRC_OFFSET  SECM_VER_CRC_OFFSET
# endif
#endif

#define SEC_SIZE_HASH_MD5              16u

#define SEC_SIZE_HASH_SHA1             20u

#define SEC_SIZE_HASH_SHA224           28u

#define SEC_SIZE_HASH_SHA256           32u

#define SEC_SIZE_HASH_SHA384           48u

#define SEC_SIZE_HASH_SHA512           64u

#define SEC_SIZE_HASH_RMD160           20u

#define SEC_SIZE_CMAC_AES              16u

#define SEC_SIZE_SIG_RSA512            64u

#define SEC_SIZE_SIG_RSA1024           128u

#define SEC_SIZE_SIG_RSA1536           192u

#define SEC_SIZE_SIG_RSA2048           256u

#define SEC_SIZE_SIG_RSA3072           384u

#define SEC_SIZE_SIG_RSA4096           512u

#define SEC_SIZE_SIG_ECDSA_CURVE25519  64u

#define SEC_SIZE_SIG_ECDSA_CURVEP224   56u

#define SEC_SIZE_SIG_ECDSA_CURVEP256   64u

#define SEC_SIZE_SIG_ECDSA_CURVEP384   96u

#if defined( SEC_SIZE_CHECKSUM_VENDOR )
#else
# define SEC_SIZE_CHECKSUM_VENDOR      1u
#endif

#define SEC_SIZE_KEY_ECDSA_CURVE25519  32u

#define SEC_SIZE_KEY_ECDSA_CURVEP256   64u

typedef SecM_ConstVoidPtrType   SecM_VerifyInitType;

typedef SecM_ConstVoidPtrType   SecM_VerifyDeinitType;

typedef SecM_StatusType SEC_CALL_TYPE (*pSecInitVerificationFct)     (SecM_VerifyInitType init);
typedef SecM_StatusType SEC_CALL_TYPE (*pSecDeinitVerificationFct)   (SecM_VerifyDeinitType deinit);
typedef SecM_StatusType SEC_CALL_TYPE (*pSecVerificationFct)         (V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
typedef SecM_StatusType SEC_CALL_TYPE (*pSecVerifySignatureFct)      (V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);

typedef struct{
   pSecVerifySignatureFct  pFunction;
   SecM_LengthType         length;
   SecM_LengthFastType     offset;
   SecM_ByteType           mask;
}SecM_VerifyOperationType;

typedef struct{
   V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 V_MEMROM3 * pOperation;
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 *  pContext;
}SecM_VerifyConfigType;

typedef struct{
   SecM_VerifyConfigType   pPrimitives;
   SecM_ByteFastType       count;
}SecM_VerifyConfigListType;

#if defined( __cplusplus )
extern "C" {
#endif

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

void            SecM_InitPowerOnVerification ( void );
SecM_StatusType SecM_InitVerification        ( SecM_VerifyInitType init );
SecM_StatusType SecM_DeinitVerification      ( SecM_VerifyDeinitType deinit );

#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
void SecM_UpdateDataLength                   ( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam );
#endif
#if defined( SEC_ENABLE_VERIFICATION_WRAPPER )
SecM_StatusType SecM_VerificationWrapper     ( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
   const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList );
#endif
SecM_StatusType SecM_VerificationBase(V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
   const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList);

#if defined( SEC_ENABLE_CRC_TOTAL ) || \
    defined( SEC_ENABLE_CRC_WRITTEN )
SecM_StatusType SecM_VerifyChecksumCrc(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
#endif

#if defined( SEC_ENABLE_VERIFY_CRC )
SecM_StatusType SecM_VerifyCrc(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId);
#endif
#if defined( SEC_ENABLE_VERIFY_HASH )
SecM_StatusType SecM_VerifyHash(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId);
#endif
#if defined( SEC_ENABLE_VERIFY_MAC )
SecM_StatusType SecM_VerifyMac(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId);
#endif
#if defined( SEC_ENABLE_VERIFY_SIGNATURE )
SecM_StatusType SecM_VerifySig(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId);
#endif

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#if defined( __cplusplus )
}
#endif

#if( SEC_VERIFY_BYTES > 0xFFFFu )
# error "Error in configuration: SEC_VERIFY_BYTES exceeds valid range"
#endif

#endif

