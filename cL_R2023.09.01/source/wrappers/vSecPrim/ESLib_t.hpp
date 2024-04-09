

#ifndef ESLIB_T_H
#define ESLIB_T_H

#include "actConfig.hpp"
#include "actITypes.hpp"

#define ESL_UNCOMPRESSED_POINT_ENCODING_BYTE                         (0x04u)

#define Esl_BitsToBytes(x)                                           ((x) >> 3)
#define Esl_BytesToBits(x)                                           ((x) << 3)

#define Esl_ValueIsEven(x)                                           (((x % 2u) == 0u) ? TRUE:FALSE)
#define Esl_ValueIsOdd(x)                                            (((x % 2u) == 1u) ? TRUE:FALSE)

#define Esl_DivideByTwo(x)                                           ((x) >> 1)

#define ESL_BITS_PER_DIGIT                                           (ACT_PLATFORM_BITS_PER_DIGIT)

typedef actPlatformUint8 eslt_Size8;
typedef actPlatformUint16 eslt_Size16;
typedef actPlatformUint32 eslt_Size32;
#ifdef ACT_PLATFORM_UINT64_AVAILABLE
typedef actPlatformUint64 eslt_Size64;
#endif

typedef eslt_Size8 eslt_Byte;
#if(vSecPrim_GetSizeOfEsltLengthOfGeneral() == VSECPRIM_SIZE_UINT32)
typedef eslt_Size32 eslt_Length;
#else
typedef eslt_Size16 eslt_Length;
#endif
typedef eslt_Size8 eslt_Mode;
typedef eslt_Size16 eslt_WSStatus;
typedef eslt_Size32 eslt_WSCheckSum;

#define eslt_pRomByte                                                VSECPRIM_P2CONST_PARA(eslt_Byte)

#if defined (ESL_MAX_KEY_SIZE_ECP)
#else
#if(vSecPrim_GetECPMaxKeySizeOfGeneral() == VSECPRIM_ECP_MAX_KEY_SIZE_160)
#define ESL_MAX_KEY_SIZE_ECP                                       160
#  elif(vSecPrim_GetECPMaxKeySizeOfGeneral() == VSECPRIM_ECP_MAX_KEY_SIZE_192)
#define ESL_MAX_KEY_SIZE_ECP                                       192
#  elif(vSecPrim_GetECPMaxKeySizeOfGeneral() == VSECPRIM_ECP_MAX_KEY_SIZE_224)
#define ESL_MAX_KEY_SIZE_ECP                                       224
#  elif(vSecPrim_GetECPMaxKeySizeOfGeneral() == VSECPRIM_ECP_MAX_KEY_SIZE_256)
#define ESL_MAX_KEY_SIZE_ECP                                       256
#  elif(vSecPrim_GetECPMaxKeySizeOfGeneral() == VSECPRIM_ECP_MAX_KEY_SIZE_320)
#define ESL_MAX_KEY_SIZE_ECP                                       320
#  elif(vSecPrim_GetECPMaxKeySizeOfGeneral() == VSECPRIM_ECP_MAX_KEY_SIZE_384)
#define ESL_MAX_KEY_SIZE_ECP                                       384
#  elif(vSecPrim_GetECPMaxKeySizeOfGeneral() == VSECPRIM_ECP_MAX_KEY_SIZE_512)
#define ESL_MAX_KEY_SIZE_ECP                                       512
#  elif(vSecPrim_GetECPMaxKeySizeOfGeneral() == VSECPRIM_ECP_MAX_KEY_SIZE_521)
#define ESL_MAX_KEY_SIZE_ECP                                       521
#else
#   error Invalid maximum Key size for ECP selected
#endif
#endif

#if defined (ESL_RSA_KEYSIZE)
#else
#if(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_512)
#define ESL_RSA_KEYSIZE                                            512u
#  elif(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_1024)
#define ESL_RSA_KEYSIZE                                            1024u
#  elif(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_1536)
#define ESL_RSA_KEYSIZE                                            1536u
#  elif(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_2048)
#define ESL_RSA_KEYSIZE                                            2048u
#  elif(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_3072)
#define ESL_RSA_KEYSIZE                                            3072u
#  elif(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_4096)
#define ESL_RSA_KEYSIZE                                            4096u
#else
#   error Invalid maximum Key size for RSA selected
#endif
#endif

#if(VSECPRIM_RSA_V15_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_OAEP_SHA1_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_OAEP_SHA2_256_ENABLED == STD_ON)
#define VSECPRIM_RSA_CIPHER_ENABLED                                 STD_ON
#else
#define VSECPRIM_RSA_CIPHER_ENABLED                                 STD_OFF
#endif

#if(VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_V15_RIPEMD160_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_V15_SHA2_256_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_V15_SHA1_ENABLED == STD_ON)
#define VSECPRIM_RSA_SIGNATURE_ENABLED                              STD_ON
#else
#define VSECPRIM_RSA_SIGNATURE_ENABLED                              STD_OFF
#endif

#if( (VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON)) \
     && ((VSECPRIM_RSA_V15_RIPEMD160_ENABLED == STD_OFF) \
     && (VSECPRIM_RSA_V15_SHA2_256_ENABLED == STD_OFF) \
     && (VSECPRIM_RSA_V15_SHA1_ENABLED == STD_OFF))
#define VSECPRIM_RSAPSSONLY_SIGNATURE_ENABLED                       STD_ON
#else
#define VSECPRIM_RSAPSSONLY_SIGNATURE_ENABLED                       STD_OFF
#endif

#if(VSECPRIM_RSA_CIPHER_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_V15_RIPEMD160_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_V15_SHA2_256_ENABLED == STD_ON) \
     || (VSECPRIM_RSA_V15_SHA1_ENABLED == STD_ON)
#define VSECPRIM_RSA_ENABLED                                        STD_ON
#else
#define VSECPRIM_RSA_ENABLED                                        STD_OFF
#endif

#if(VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON)
#define VSECPRIM_RSA_HASHALGORITHM_RIPEMD160_ENABLED                STD_ON
#else
#define VSECPRIM_RSA_HASHALGORITHM_RIPEMD160_ENABLED                STD_OFF
#endif

#if(VSECPRIM_RSA_OAEP_SHA1_ENABLED == STD_ON) || ( VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON)
#define VSECPRIM_RSA_HASHALGORITHM_SHA1_ENABLED                     STD_ON
#else
#define VSECPRIM_RSA_HASHALGORITHM_SHA1_ENABLED                     STD_OFF
#endif

#if(VSECPRIM_RSA_OAEP_SHA2_256_ENABLED == STD_ON) || ( VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON)
#define VSECPRIM_RSA_HASHALGORITHM_SHA2_256_ENABLED                 STD_ON
#else
#define VSECPRIM_RSA_HASHALGORITHM_SHA2_256_ENABLED                 STD_OFF
#endif

#if((VSECPRIM_RSA_OAEP_SHA1_ENABLED == STD_ON) || (VSECPRIM_RSA_OAEP_SHA2_256_ENABLED == STD_ON))
#define VSECPRIM_RSA_OAEP_ENABLED                                   STD_ON
#else
#define VSECPRIM_RSA_OAEP_ENABLED                                   STD_OFF
#endif

#if((VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON) || ( VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON))
#define VSECPRIM_RSA_PSS_ENABLED                                    STD_ON
#else
#define VSECPRIM_RSA_PSS_ENABLED                                    STD_OFF
#endif

#if((VSECPRIM_RSA_OAEP_ENABLED == STD_ON) || (VSECPRIM_RSA_V15_ENABLED == STD_ON) || (VSECPRIM_RSA_V15_RIPEMD160_ENABLED == STD_ON) || (VSECPRIM_RSA_V15_SHA2_256_ENABLED == STD_ON)  || (VSECPRIM_RSA_V15_SHA1_ENABLED == STD_ON))
#define VSECPRIM_RSACRT                                             STD_ON
#else
#define VSECPRIM_RSACRT                                             STD_OFF
#endif

typedef struct{
  VSECPRIM_P2ROMCONST(VSECPRIM_NONE, char) parameter;
  eslt_Size16 value;
}eslt_Version;

typedef eslt_Mode eslt_PaddingMode;
#define ESL_PM_PKCS5                                                 0x01u
#define ESL_PM_OFF                                                   0x02u
#define ESL_PM_ONEWITHZEROES                                         0x04u

typedef eslt_Mode eslt_HashAlgorithm;
#define ESL_HA_SHA1                                                  (0x00u)
#define ESL_HA_SHA2_224                                              (0x01u)
#define ESL_HA_SHA2_256                                              (0x02u)
#define ESL_HA_SHA2_384                                              (0x03u)
#define ESL_HA_SHA2_512                                              (0x04u)
#define ESL_HA_SHA2_512_224                                          (0x05u)
#define ESL_HA_SHA2_512_256                                          (0x06u)

#define ESL_HA_SHA3_224                                              (0x07u)
#define ESL_HA_SHA3_256                                              (0x08u)
#define ESL_HA_SHA3_384                                              (0x09u)
#define ESL_HA_SHA3_512                                              (0x0Au)

#define ESL_HA_SHAKE_128                                             (0x0Bu)
#define ESL_HA_SHAKE_256                                             (0x0Cu)
#define ESL_HA_RMD160                                                (0x0Du)
#define ESL_HA_MD5                                                   (0x0Eu)

typedef eslt_Mode eslt_BlockMode;
#define ESL_BM_ECB                                                   0x00u
#define ESL_BM_CBC                                                   0x01u

#define ESL_BM_CTR                                                   0x04u

typedef eslt_Mode eslt_DRBGMode;
#define ESL_DRBGMODE_CTRDRBG_AES128_DF                               (actDRBGMODE_CTRDRBG_AES128_DF)
#define ESL_DRBGMODE_CTRDRBG_AES128_NODF                             (actDRBGMODE_CTRDRBG_AES128_NODF)
#define ESL_DRBGMODE_CTRDRBG_AES256_DF                               (actDRBGMODE_CTRDRBG_AES256_DF)
#define ESL_DRBGMODE_CTRDRBG_AES256_NODF                             (actDRBGMODE_CTRDRBG_AES256_NODF)
#define ESL_DRBGMODE_HASHDRBG_SHA512                                 (actDRBGMODE_HASHDRBG_SHA512)

typedef eslt_Size32 eslt_DRBGReseedCounterType;

typedef eslt_Byte eslt_DRBGSeedStatusType;
#define ESL_DRBG_SEED_STATUS_UNSEEDED                                (actDRBG_SEED_STATE_UNSEEDED)
#define ESL_DRBG_SEED_STATUS_SEEDED                                  (actDRBG_SEED_STATE_SEEDED)
#define ESL_DRBG_SEED_STATUS_NEED_RESEED                             (actDRBG_SEED_STATE_NEED_RESEED)

typedef eslt_Size32 eslt_SPAKE2PMode;
#define ESL_SPAKE2P_CURVE_P256                                       (actSPAKE2P_CURVE_P256)
#define ESL_SPAKE2P_HASHFCT_SHA256                                   (actSPAKE2P_HASHFCT_SHA256)
#define ESL_SPAKE2P_KDF_HKDF_HMAC_SHA256                             (actSPAKE2P_KDF_HKDF_HMAC_SHA256)
#define ESL_SPAKE2P_MAC_CMAC128                                      (actSPAKE2P_MAC_CMAC128)

#define ESL_SPAKE2P_VERSION_KEY_A_FIRST                              (actSPAKE2P_VERSION_KEY_A_FIRST)
#define ESL_SPAKE2P_VERSION_KEY_B_FIRST                              (actSPAKE2P_VERSION_KEY_B_FIRST)

#define ESL_SPAKE2P_MODE_CIPHERSUITE_8_1                             (ESL_SPAKE2P_CURVE_P256 + ESL_SPAKE2P_VERSION_KEY_A_FIRST + ESL_SPAKE2P_HASHFCT_SHA256 + ESL_SPAKE2P_KDF_HKDF_HMAC_SHA256 + ESL_SPAKE2P_MAC_CMAC128)
#define ESL_SPAKE2P_MODE_CIPHERSUITE_8_2                             (ESL_SPAKE2P_CURVE_P256 + ESL_SPAKE2P_VERSION_KEY_B_FIRST + ESL_SPAKE2P_HASHFCT_SHA256 + ESL_SPAKE2P_KDF_HKDF_HMAC_SHA256 + ESL_SPAKE2P_MAC_CMAC128)

#define ESL_SPAKE2P_PREAMBLE_DATA_NOT_SET                            (0x00u)
#define ESL_SPAKE2P_PREAMBLE_DATA_SET                                (0x01u)
#define ESL_SPAKE2P_PUBLIC_VALUE_CALCULATED                          (0x02u)
#define ESL_SPAKE2P_SHARED_SECRET_CALCULATED                         (0x03u)

typedef eslt_Byte eslt_HKDFMode;
#define ESL_HKDF_ONE_STEP_VARIANT                                    (actHKDF_ONESTEPMETHOD)
#define ESL_HKDF_TWO_STEP_VARIANT                                    (actHKDF_TWOSTEPMETHOD)

#define ESL_SIZEOF_AES_BLOCK                                         16u

#define ESL_SIZEOF_AES128_KEY                                        16u
#define ESL_SIZEOF_AES128_BLOCK                                      ESL_SIZEOF_AES_BLOCK

#define ESL_SIZEOF_AES192_KEY                                        24u
#define ESL_SIZEOF_AES192_BLOCK                                      ESL_SIZEOF_AES_BLOCK

#define ESL_SIZEOF_AES256_KEY                                        32u
#define ESL_SIZEOF_AES256_BLOCK                                      ESL_SIZEOF_AES_BLOCK

#define ESL_SIZEOF_SIPHASH_KEY                                       16u

#define ESL_SIZEOF_DES_KEY                                           8u
#define ESL_SIZEOF_DES_BLOCK                                         8u
#define ESL_SIZEOF_2TDES_KEY                                         16u
#define ESL_SIZEOF_3TDES_KEY                                         24u

#define ESL_SIZEOF_RC2_KEY                                           16u
#define ESL_SIZEOF_RC2_EFF_KEY                                       16u
#define ESL_SIZEOF_RC2_BLOCK                                         8u

#define ESL_SIZEOF_GCM_BLOCK                                         ESL_SIZEOF_AES_BLOCK
#define ESL_SIZEOF_GCM_TAG                                           ESL_SIZEOF_AES_BLOCK

#define ESL_SIZEOF_CCM_TAG                                           ESL_SIZEOF_AES_BLOCK

#define ESL_SIZEOF_SHA1_BLOCK                                        64u
#define ESL_SIZEOF_SHA1_DIGEST                                       20u

#define ESL_SIZEOF_RIPEMD160_BLOCK                                   64u
#define ESL_SIZEOF_RIPEMD160_DIGEST                                  20u

#define ESL_SIZEOF_SHA256_BLOCK                                      64u
#define ESL_SIZEOF_SHA224_DIGEST                                     28u
#define ESL_SIZEOF_SHA256_DIGEST                                     32u

#define ESL_SIZEOF_SHA512_BLOCK                                      128u
#define ESL_SIZEOF_SHA512_224_DIGEST                                 ESL_SIZEOF_SHA224_DIGEST
#define ESL_SIZEOF_SHA512_256_DIGEST                                 ESL_SIZEOF_SHA256_DIGEST
#define ESL_SIZEOF_SHA384_DIGEST                                     48u
#define ESL_SIZEOF_SHA512_DIGEST                                     64u

#define ESL_SIZEOF_KECCAK_STATE                                      (1600u / 8u)

#define ESL_SIZEOF_SHA3_224_DIGEST                                   (224u / 8u)
#define ESL_SIZEOF_SHA3_256_DIGEST                                   (256u / 8u)
#define ESL_SIZEOF_SHA3_384_DIGEST                                   (384u / 8u)
#define ESL_SIZEOF_SHA3_512_DIGEST                                   (512u / 8u)
#define ESL_SIZEOF_SHAKE128_DIGEST                                   (128u * 2u / 8u)
#define ESL_SIZEOF_SHAKE256_DIGEST                                   (256u * 2u / 8u)

#define ESL_SIZEOF_SHAKE128_STRENGTH                                 (128u)
#define ESL_SIZEOF_SHAKE256_STRENGTH                                 (256u)

#define ESL_SIZEOF_MD5_BLOCK                                         64u
#define ESL_SIZEOF_MD5_DIGEST                                        16u

#define ESL_SIZEOF_Ed25519_KEY                                       32u
#define ESL_SIZEOF_Ed25519_SECRET_KEY                                ESL_SIZEOF_Ed25519_KEY
#define ESL_SIZEOF_Ed25519_PUBLIC_KEY                                ESL_SIZEOF_Ed25519_KEY
#define ESL_SIZEOF_Ed25519_SIGNATURE                                 64u
#define ESL_INSTANCE_Ed25519                                         0u
#define ESL_INSTANCE_Ed25519ctx                                      1u
#define ESL_INSTANCE_Ed25519ph                                       2u

#define ESL_SIZEOF_X25519_KEY                                        32u
#define ESL_SIZEOF_X25519_PRIVATE_KEY                                ESL_SIZEOF_X25519_KEY
#define ESL_SIZEOF_X25519_PUBLIC_KEY                                 ESL_SIZEOF_X25519_KEY
#define ESL_SIZEOF_X25519_SHARED_SECRET                              ESL_SIZEOF_X25519_KEY

#define ESL_Curve25519                                               25519u
#define ESL_Curve448                                                 448u

#define ESL_SIZEOF_ChaCha20_KEY                                      32u
#define ESL_SIZEOF_ChaCha20_NONCE                                    12u

#define ESL_SIZEOF_Poly1305_KEY                                      32u
#define ESL_SIZEOF_Poly1305_TAG                                      16u

#define ESL_SIZEOF_RNGFIPS186_STATE                                  (ESL_SIZEOF_SHA1_DIGEST)

#define ESL_KDF2_DEFAULT_ITERATION_COUNT                             1u

#define ESL_SIZEOF_RSA_PSS_PADDING1                                  8u

#define ESL_CTRDRBG_AES128_SEEDLEN                                   32u
#define ESL_CTRDRBG_AES256_SEEDLEN                                   48u
#define ESL_HASHDRBG_SHA512_SEED_LEN                                 111u

#define ESL_SIZEOF_CTRDRBG_AES128_KEY                                ESL_SIZEOF_AES128_KEY
#define ESL_SIZEOF_CTRDRBG_AES256_KEY                                ESL_SIZEOF_AES256_KEY
#define ESL_SIZEOF_CTRDRBG_BLOCK                                     ESL_SIZEOF_AES_BLOCK

typedef eslt_Byte eslt_EccDomain;

typedef eslt_Byte eslt_EccDomainExt;

typedef eslt_Byte eslt_EccSpeedUpExt;

typedef VSECPRIM_P2FUNC(VSECPRIM_NONE, void, esl_WatchdogFuncPtr)(void);

typedef struct{
  eslt_Length size;
  eslt_WSStatus status;
  esl_WatchdogFuncPtr watchdog;
  eslt_WSCheckSum checkSum;
}eslt_WorkSpaceHeader;

#ifdef ACT_PLATFORM_ALIGNMENT
#if(ACT_PLATFORM_ALIGNMENT == 1u) || (ACT_PLATFORM_ALIGNMENT == 2u) || (ACT_PLATFORM_ALIGNMENT == 4u) || (ACT_PLATFORM_ALIGNMENT == 8u)

#define ACT_ALIGN(size)                                            ((((size) +((ACT_PLATFORM_ALIGNMENT) - 1u))/(ACT_PLATFORM_ALIGNMENT))*(ACT_PLATFORM_ALIGNMENT))
#else
#   error Unknown alignment
#endif
#else
#error Alignment is not specified
#endif

#define ACT_MAX_ALIGN_OFFSET                                         (ACT_PLATFORM_ALIGNMENT-1u)

#define ESL_MAXSIZEOF_WS_AES128BLOCK                                 (260u)

#define ESL_MAXSIZEOF_WS_AES128                                      (sizeof(actAESSTRUCT))

#define ESL_MINSIZEOF_WS_AES128                                      (sizeof(actAESSTRUCT))

#define ESL_MAXSIZEOF_WS_AES192BLOCK                                 (260u)

#define ESL_MAXSIZEOF_WS_AES192                                      (sizeof(actAESSTRUCT))

#define ESL_MINSIZEOF_WS_AES192                                      (sizeof(actAESSTRUCT))

#define ESL_MAXSIZEOF_WS_AES256BLOCK                                 (260u)

#define ESL_MAXSIZEOF_WS_AES256                                      (sizeof(actAESSTRUCT))

#define ESL_MINSIZEOF_WS_AES256                                      (sizeof(actAESSTRUCT))

#define ESL_MAXSIZEOF_WS_DESBLOCK                                    (200u)

#define ESL_MAXSIZEOF_WS_DES                                         (ESL_MAXSIZEOF_WS_DESBLOCK + (2u * ESL_SIZEOF_DES_BLOCK) + 8u)

#define ESL_MINSIZEOF_WS_DES                                         (ESL_MAXSIZEOF_WS_DES - ESL_SIZEOF_DES_BLOCK)

#define ESL_MAXSIZEOF_WS_TDESBLOCK                                   (500u)

#define ESL_MAXSIZEOF_WS_TDES                                        (ESL_MAXSIZEOF_WS_TDESBLOCK + (2u * ESL_SIZEOF_DES_BLOCK) + 8u)

#define ESL_MINSIZEOF_WS_TDES                                        (ESL_MAXSIZEOF_WS_TDES - ESL_SIZEOF_DES_BLOCK)

#define ESL_MAXSIZEOF_WS_RC2BLOCK                                    (200u)

#define ESL_MAXSIZEOF_WS_RC2                                         (ESL_MAXSIZEOF_WS_RC2BLOCK + (3u * ESL_SIZEOF_RC2_BLOCK) + 8u)

#define ESL_MINSIZEOF_WS_RC2                                         (ESL_MAXSIZEOF_WS_RC2 - ESL_SIZEOF_RC2_BLOCK)

#define ESL_SIZEOF_GHASH_SPEEDUP                                     (256u)

#define ESL_SIZEOF_WS_GHASH                                          ((3u * ESL_SIZEOF_GCM_TAG) + 4u + ESL_SIZEOF_GHASH_SPEEDUP)
#define ESL_MAXSIZEOF_WS_GMAC                                        (sizeof(actGCMSTRUCT))
#define ESL_MAXSIZEOF_WS_GCM                                         (sizeof(actGCMSTRUCT))

#define ESL_MAXSIZEOF_WS_SHA1                                        (sizeof(actSHASTRUCT))

#define ESL_MINSIZEOF_WS_SHA1                                        (sizeof(actSHASTRUCT))

#define ESL_MAXSIZEOF_WS_SHA224                                      (sizeof(actSHA224STRUCT))

#define ESL_MINSIZEOF_WS_SHA224                                      (sizeof(actSHA224STRUCT))

#define ESL_MAXSIZEOF_WS_SHA256                                      (sizeof(actSHA256STRUCT))

#define ESL_MINSIZEOF_WS_SHA256                                      (sizeof(actSHA256STRUCT))

#define ESL_MAXSIZEOF_WS_SHA512                                      (sizeof(actSHA512STRUCT))

#define ESL_MINSIZEOF_WS_SHA512                                      (sizeof(actSHA512STRUCT))

#define ESL_MAXSIZEOF_WS_SHA512_224                                  (sizeof(actSHA512_224STRUCT))

#define ESL_MINSIZEOF_WS_SHA512_224                                  (sizeof(actSHA512_224STRUCT))

#define ESL_MAXSIZEOF_WS_SHA512_256                                  (sizeof(actSHA512_256STRUCT))

#define ESL_MINSIZEOF_WS_SHA512_256                                  (sizeof(actSHA512_256STRUCT))

#define ESL_MAXSIZEOF_WS_SHA384                                      (sizeof(actSHA384STRUCT))

#define ESL_MINSIZEOF_WS_SHA384                                      (sizeof(actSHA384STRUCT))

#define ESL_MAXSIZEOF_WS_SHA3                                        (sizeof(actKECCAKcSTRUCT))

#define ESL_MAXSIZEOF_WS_SHAKE                                       ESL_MAXSIZEOF_WS_SHA3

#define ESL_MAXSIZEOF_WS_MD5                                         (ACT_ALIGN (ESL_SIZEOF_MD5_BLOCK + ESL_SIZEOF_MD5_DIGEST + 12u))

#define ESL_MINSIZEOF_WS_MD5                                         (ESL_MAXSIZEOF_WS_MD5 - ESL_SIZEOF_MD5_BLOCK)

#define ESL_MAXSIZEOF_WS_HMACSHA1                                    (sizeof(actHASHMACSTRUCT))

#define ESL_MAXSIZEOF_WS_HMACSHA256                                  (sizeof(actHASHMACSHA256STRUCT))

#define ESL_MAXSIZEOF_WS_HMACSHA384                                  (sizeof(actHASHMACSHA384STRUCT))

#define ESL_MAXSIZEOF_WS_RIPEMD160                                   (sizeof(actRMD160STRUCT))
#define ESL_MAXSIZEOF_WS_HMACRIPEMD160                               (sizeof(actHASHMACRMD160STRUCT))
#define ESL_MINSIZEOF_WS_RIPEMD160                                   (ESL_MAXSIZEOF_WS_RIPEMD160)

#define ESL_MAXSIZEOF_WS_CMACAES                                     (sizeof(actCMACAESSTRUCT))

#define ESL_MAXSIZEOF_WS_SIPHASH                                     (sizeof(actSipHashSTRUCT))

#define ESL_MAXSIZEOF_WS_KDF2HMACSHA1                                (sizeof(actKDF2STRUCT))
#define ESL_MAXSIZEOF_WS_KDF2HMACSHA256                              ESL_MAXSIZEOF_WS_KDF2HMACSHA1

#define ESL_MAXSIZEOF_WS_KDFX963SHA1                                 (sizeof(actKDFX963STRUCT))
#define ESL_MAXSIZEOF_WS_KDFX963SHA256                               (sizeof(actKDFX963SHA256))
#define ESL_MAXSIZEOF_WS_KDFX963SHA512                               (sizeof(actKDFX963SHA512))

#define ESL_MAXSIZEOF_WS_HKDF_HMAC                                   (sizeof(actHKDFSTRUCT))
#define ESL_MAXSIZEOF_WS_HKDF_HASH                                   (sizeof(actHKDFHASHSTRUCT))

#define ESL_MAXSIZEOF_WS_FIPS186                                     (sizeof(actFIPS186STRUCT))

#define ESL_MAXSIZEOF_WS_CTRDRBG                                     (sizeof(eslt_WorkSpaceCTRDRBG))
#define ESL_MAXSIZEOF_WS_HASHDRBG                                    (sizeof(eslt_WorkSpaceHASHDRBG))

#define ESL_SIZEOF_WS_ECP_160_KG                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_160_DH                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_160_SP                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_160_VP                                     sizeof(actECPSTRUCT)

#define ESL_SIZEOF_WS_ECP_192_KG                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_192_DH                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_192_SP                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_192_VP                                     sizeof(actECPSTRUCT)

#define ESL_SIZEOF_WS_ECP_224_KG                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_224_DH                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_224_SP                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_224_VP                                     sizeof(actECPSTRUCT)

#define ESL_SIZEOF_WS_ECP_256_KG                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_256_DH                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_256_SP                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_256_VP                                     sizeof(actECPSTRUCT)

#define ESL_SIZEOF_WS_ECP_320_KG                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_320_DH                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_320_SP                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_320_VP                                     sizeof(actECPSTRUCT)

#define ESL_SIZEOF_WS_ECP_384_KG                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_384_DH                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_384_SP                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_384_VP                                     sizeof(actECPSTRUCT)

#define ESL_SIZEOF_WS_ECP_512_KG                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_512_DH                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_512_SP                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_512_VP                                     sizeof(actECPSTRUCT)

#define ESL_SIZEOF_WS_ECP_521_KG                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_521_DH                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_521_SP                                     sizeof(actECPSTRUCT)
#define ESL_SIZEOF_WS_ECP_521_VP                                     sizeof(actECPSTRUCT)

#define ESL_MAXSIZEOF_WS_ECP_SMALL                                   ESL_SIZEOF_WS_ECP_256_VP

#define ESL_MAXSIZEOF_WS_ECP_LARGE                                   ESL_SIZEOF_WS_ECP_521_VP

#define ESL_SIZEOF_WS_ECBD_160                                       sizeof(actECBDstruct)
#define ESL_SIZEOF_WS_ECBD_192                                       sizeof(actECBDstruct)
#define ESL_SIZEOF_WS_ECBD_224                                       sizeof(actECBDstruct)
#define ESL_SIZEOF_WS_ECBD_256                                       sizeof(actECBDstruct)
#define ESL_SIZEOF_WS_ECBD_320                                       sizeof(actECBDstruct)
#define ESL_SIZEOF_WS_ECBD_384                                       sizeof(actECBDstruct)
#define ESL_SIZEOF_WS_ECBD_512                                       sizeof(actECBDstruct)
#define ESL_SIZEOF_WS_ECBD_521                                       sizeof(actECBDstruct)

#ifdef ESL_MAX_KEY_SIZE_ECP
#if(160 == ESL_MAX_KEY_SIZE_ECP)
#define ESL_MAXSIZEOF_WS_ECP                                       ESL_SIZEOF_WS_ECP_160_VP
#define ESL_MAXSIZEOF_WS_ECBD                                      ESL_SIZEOF_WS_ECBD_160
#  elif(192 == ESL_MAX_KEY_SIZE_ECP)
#define ESL_MAXSIZEOF_WS_ECP                                       ESL_SIZEOF_WS_ECP_192_VP
#define ESL_MAXSIZEOF_WS_ECBD                                      ESL_SIZEOF_WS_ECBD_192
#  elif(224 == ESL_MAX_KEY_SIZE_ECP)
#define ESL_MAXSIZEOF_WS_ECP                                       ESL_SIZEOF_WS_ECP_224_VP
#define ESL_MAXSIZEOF_WS_ECBD                                      ESL_SIZEOF_WS_ECBD_224
#  elif(256 == ESL_MAX_KEY_SIZE_ECP)
#define ESL_MAXSIZEOF_WS_ECP                                       ESL_SIZEOF_WS_ECP_256_VP
#define ESL_MAXSIZEOF_WS_ECBD                                      ESL_SIZEOF_WS_ECBD_256
#  elif(320 == ESL_MAX_KEY_SIZE_ECP)
#define ESL_MAXSIZEOF_WS_ECP                                       ESL_SIZEOF_WS_ECP_320_VP
#define ESL_MAXSIZEOF_WS_ECBD                                      ESL_SIZEOF_WS_ECBD_320
#  elif(384 == ESL_MAX_KEY_SIZE_ECP)
#define ESL_MAXSIZEOF_WS_ECP                                       ESL_SIZEOF_WS_ECP_384_VP
#define ESL_MAXSIZEOF_WS_ECBD                                      ESL_SIZEOF_WS_ECBD_384
#  elif(512 == ESL_MAX_KEY_SIZE_ECP)
#define ESL_MAXSIZEOF_WS_ECP                                       ESL_SIZEOF_WS_ECP_512_VP
#define ESL_MAXSIZEOF_WS_ECBD                                      ESL_SIZEOF_WS_ECBD_512
#  elif(521 == ESL_MAX_KEY_SIZE_ECP)
#define ESL_MAXSIZEOF_WS_ECP                                       ESL_SIZEOF_WS_ECP_521_VP
#define ESL_MAXSIZEOF_WS_ECBD                                      ESL_SIZEOF_WS_ECBD_521
#else
#define ESL_MAXSIZEOF_WS_ECP                                       ESL_SIZEOF_WS_ECP_256_VP
#define ESL_MAXSIZEOF_WS_ECBD                                      ESL_SIZEOF_WS_ECBD_256
#endif
#else
#define ESL_MAXSIZEOF_WS_ECP                                        ESL_SIZEOF_WS_ECP_256_VP
#define ESL_MAXSIZEOF_WS_ECBD                                       ESL_SIZEOF_WS_ECBD_256
#endif

#define ESL_MAXSIZEOF_WS_RSA_PRIM                                    (sizeof(actRSAPRIMSTRUCT))

#define ESL_SIZEOF_WS_HASHUNION_RSA                                  (sizeof(eslt_WorkSpaceUnionHashFunctions_RSA) - sizeof(eslt_WorkSpaceHeader))

#define ESL_SIZEOF_WS_RSA_PUB_512                                    ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_512                                   ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_CRT_512                               (sizeof(actRSACRTTMPSTRUCT))

#define ESL_SIZEOF_WS_RSA_PUB_1024                                   ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_1024                                  ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_CRT_1024                              (sizeof(actRSACRTTMPSTRUCT))

#define ESL_SIZEOF_WS_RSA_PUB_1536                                   ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_1536                                  ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_CRT_1536                              (sizeof(actRSACRTTMPSTRUCT))

#define ESL_SIZEOF_WS_RSA_PUB_2048                                   ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_2048                                  ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_CRT_2048                              (sizeof(actRSACRTTMPSTRUCT))

#define ESL_SIZEOF_WS_RSA_PUB_3072                                   ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_3072                                  ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_CRT_3072                              (sizeof(actRSACRTTMPSTRUCT))

#define ESL_SIZEOF_WS_RSA_PUB_4096                                   ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_4096                                  ESL_MAXSIZEOF_WS_RSA_PRIM
#define ESL_SIZEOF_WS_RSA_PRIV_CRT_4096                              (sizeof(actRSACRTTMPSTRUCT))

#define ESL_MAXSIZEOF_WS_RSA_ENC                                     (sizeof(eslt_WorkSpaceRSAenc)         - sizeof(eslt_WorkSpaceHeader))
#define ESL_MAXSIZEOF_WS_RSA_DEC                                     (sizeof(eslt_WorkSpaceRSAdec)         - sizeof(eslt_WorkSpaceHeader))

#define ESL_MAXSIZEOF_WS_RSA_ENC_PRIM                                (sizeof(actRSAPRIMSTRUCT))
#define ESL_MAXSIZEOF_WS_RSA_DEC_PRIM                                (sizeof(actRSAPRIMSTRUCT))

#define ESL_MAXSIZEOF_WS_RSA_SIG                                     (sizeof(eslt_WorkSpaceRSAsig)         - sizeof(eslt_WorkSpaceHeader))
#define ESL_MAXSIZEOF_WS_RSA_VER                                     (sizeof(eslt_WorkSpaceRSAver)         - sizeof(eslt_WorkSpaceHeader))

#define ESL_MAXSIZEOF_WS_RSA_CRT_DEC                                 (sizeof(eslt_WorkSpaceRSACRTdec)      - sizeof(eslt_WorkSpaceHeader))
#define ESL_MAXSIZEOF_WS_RSA_CRT_DEC_PRIM                            (sizeof(actRSACRTSTRUCT))
#define ESL_MAXSIZEOF_WS_RSA_CRT_SIG                                 (sizeof(eslt_WorkSpaceRSACRTsig)      - sizeof(eslt_WorkSpaceHeader))
#define ESL_MAXSIZEOF_WS_RSA_CRT_SIG_PRIM                            (sizeof(actRSACRTSTRUCT))

#define ESL_MAXSIZEOF_WS_RSA_SIG_PRIM                                (sizeof(actRSAPRIMSTRUCT))
#define ESL_MAXSIZEOF_WS_RSA_VER_PRIM                                (sizeof(actRSAPRIMSTRUCT))
#define ESL_MAXSIZEOF_WS_RSA_V15                                     ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_ENC_PRIM_512                               ESL_MAXSIZEOF_WS_RSA_ENC_PRIM
#define ESL_SIZEOF_WS_RSA_DEC_PRIM_512                               ESL_MAXSIZEOF_WS_RSA_DEC_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_DEC_PRIM_512                           ESL_MAXSIZEOF_WS_RSA_CRT_DEC_PRIM

#define ESL_SIZEOF_WS_RSA_SIG_PRIM_512                               ESL_MAXSIZEOF_WS_RSA_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_SIG_PRIM_512                           ESL_MAXSIZEOF_WS_RSA_CRT_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_VER_PRIM_512                               ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_PRIM_512                                   ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_ENC_PRIM_1024                              ESL_MAXSIZEOF_WS_RSA_ENC_PRIM
#define ESL_SIZEOF_WS_RSA_DEC_PRIM_1024                              ESL_MAXSIZEOF_WS_RSA_DEC_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_DEC_PRIM_1024                          ESL_MAXSIZEOF_WS_RSA_CRT_DEC_PRIM

#define ESL_SIZEOF_WS_RSA_SIG_PRIM_1024                              ESL_MAXSIZEOF_WS_RSA_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_SIG_PRIM_1024                          ESL_MAXSIZEOF_WS_RSA_CRT_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_VER_PRIM_1024                              ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_PRIM_1024                                  ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_ENC_PRIM_1536                              ESL_MAXSIZEOF_WS_RSA_ENC_PRIM
#define ESL_SIZEOF_WS_RSA_DEC_PRIM_1536                              ESL_MAXSIZEOF_WS_RSA_DEC_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_DEC_PRIM_1536                          ESL_MAXSIZEOF_WS_RSA_CRT_DEC_PRIM

#define ESL_SIZEOF_WS_RSA_SIG_PRIM_1536                              ESL_MAXSIZEOF_WS_RSA_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_SIG_PRIM_1536                          ESL_MAXSIZEOF_WS_RSA_CRT_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_VER_PRIM_1536                              ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_PRIM_1536                                  ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_ENC_PRIM_2048                              ESL_MAXSIZEOF_WS_RSA_ENC_PRIM
#define ESL_SIZEOF_WS_RSA_DEC_PRIM_2048                              ESL_MAXSIZEOF_WS_RSA_DEC_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_DEC_PRIM_2048                          ESL_MAXSIZEOF_WS_RSA_CRT_DEC_PRIM

#define ESL_SIZEOF_WS_RSA_SIG_PRIM_2048                              ESL_MAXSIZEOF_WS_RSA_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_SIG_PRIM_2048                          ESL_MAXSIZEOF_WS_RSA_CRT_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_VER_PRIM_2048                              ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_PRIM_2048                                  ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_ENC_PRIM_3072                              ESL_MAXSIZEOF_WS_RSA_ENC_PRIM
#define ESL_SIZEOF_WS_RSA_DEC_PRIM_3072                              ESL_MAXSIZEOF_WS_RSA_DEC_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_DEC_PRIM_3072                          ESL_MAXSIZEOF_WS_RSA_CRT_DEC_PRIM

#define ESL_SIZEOF_WS_RSA_SIG_PRIM_3072                              ESL_MAXSIZEOF_WS_RSA_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_SIG_PRIM_3072                          ESL_MAXSIZEOF_WS_RSA_CRT_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_VER_PRIM_3072                              ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_PRIM_3072                                  ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_ENC_PRIM_4096                              ESL_MAXSIZEOF_WS_RSA_ENC_PRIM
#define ESL_SIZEOF_WS_RSA_DEC_PRIM_4096                              ESL_MAXSIZEOF_WS_RSA_DEC_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_DEC_PRIM_4096                          ESL_MAXSIZEOF_WS_RSA_CRT_DEC_PRIM

#define ESL_SIZEOF_WS_RSA_SIG_PRIM_4096                              ESL_MAXSIZEOF_WS_RSA_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_CRT_SIG_PRIM_4096                          ESL_MAXSIZEOF_WS_RSA_CRT_SIG_PRIM
#define ESL_SIZEOF_WS_RSA_VER_PRIM_4096                              ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_PRIM_4096                                  ESL_MAXSIZEOF_WS_RSA_VER_PRIM

#define ESL_SIZEOF_WS_RSA_ENC_512                                    ESL_MAXSIZEOF_WS_RSA_ENC
#define ESL_SIZEOF_WS_RSA_DEC_512                                    ESL_MAXSIZEOF_WS_RSA_DEC
#define ESL_SIZEOF_WS_RSA_CRT_DEC_512                                ESL_MAXSIZEOF_WS_RSA_CRT_DEC

#define ESL_SIZEOF_WS_RSA_SIG_512                                    ESL_MAXSIZEOF_WS_RSA_SIG
#define ESL_SIZEOF_WS_RSA_CRT_SIG_512                                ESL_MAXSIZEOF_WS_RSA_CRT_SIG
#define ESL_SIZEOF_WS_RSA_VER_512                                    ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_V15_512                                    ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_ENC_1024                                   ESL_MAXSIZEOF_WS_RSA_ENC
#define ESL_SIZEOF_WS_RSA_DEC_1024                                   ESL_MAXSIZEOF_WS_RSA_DEC
#define ESL_SIZEOF_WS_RSA_CRT_DEC_1024                               ESL_MAXSIZEOF_WS_RSA_CRT_DEC

#define ESL_SIZEOF_WS_RSA_SIG_1024                                   ESL_MAXSIZEOF_WS_RSA_SIG
#define ESL_SIZEOF_WS_RSA_CRT_SIG_1024                               ESL_MAXSIZEOF_WS_RSA_CRT_SIG
#define ESL_SIZEOF_WS_RSA_VER_1024                                   ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_V15_1024                                   ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_ENC_1536                                   ESL_MAXSIZEOF_WS_RSA_ENC
#define ESL_SIZEOF_WS_RSA_DEC_1536                                   ESL_MAXSIZEOF_WS_RSA_DEC
#define ESL_SIZEOF_WS_RSA_CRT_DEC_1536                               ESL_MAXSIZEOF_WS_RSA_CRT_DEC

#define ESL_SIZEOF_WS_RSA_SIG_1536                                   ESL_MAXSIZEOF_WS_RSA_SIG
#define ESL_SIZEOF_WS_RSA_CRT_SIG_1536                               ESL_MAXSIZEOF_WS_RSA_CRT_SIG
#define ESL_SIZEOF_WS_RSA_VER_1536                                   ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_V15_1536                                   ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_ENC_2048                                   ESL_MAXSIZEOF_WS_RSA_ENC
#define ESL_SIZEOF_WS_RSA_DEC_2048                                   ESL_MAXSIZEOF_WS_RSA_DEC
#define ESL_SIZEOF_WS_RSA_CRT_DEC_2048                               ESL_MAXSIZEOF_WS_RSA_CRT_DEC

#define ESL_SIZEOF_WS_RSA_SIG_2048                                   ESL_MAXSIZEOF_WS_RSA_SIG
#define ESL_SIZEOF_WS_RSA_CRT_SIG_2048                               ESL_MAXSIZEOF_WS_RSA_CRT_SIG
#define ESL_SIZEOF_WS_RSA_VER_2048                                   ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_V15_2048                                   ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_ENC_3072                                   ESL_MAXSIZEOF_WS_RSA_ENC
#define ESL_SIZEOF_WS_RSA_DEC_3072                                   ESL_MAXSIZEOF_WS_RSA_DEC
#define ESL_SIZEOF_WS_RSA_CRT_DEC_3072                               ESL_MAXSIZEOF_WS_RSA_CRT_DEC

#define ESL_SIZEOF_WS_RSA_SIG_3072                                   ESL_MAXSIZEOF_WS_RSA_SIG
#define ESL_SIZEOF_WS_RSA_CRT_SIG_3072                               ESL_MAXSIZEOF_WS_RSA_CRT_SIG
#define ESL_SIZEOF_WS_RSA_VER_3072                                   ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_V15_3072                                   ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_ENC_4096                                   ESL_MAXSIZEOF_WS_RSA_ENC
#define ESL_SIZEOF_WS_RSA_DEC_4096                                   ESL_MAXSIZEOF_WS_RSA_DEC
#define ESL_SIZEOF_WS_RSA_CRT_DEC_4096                               ESL_MAXSIZEOF_WS_RSA_CRT_DEC

#define ESL_SIZEOF_WS_RSA_SIG_4096                                   ESL_MAXSIZEOF_WS_RSA_SIG
#define ESL_SIZEOF_WS_RSA_CRT_SIG_4096                               ESL_MAXSIZEOF_WS_RSA_CRT_SIG
#define ESL_SIZEOF_WS_RSA_VER_4096                                   ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_SIZEOF_WS_RSA_V15_4096                                   ESL_MAXSIZEOF_WS_RSA_VER

#define ESL_MAXSIZEOF_WS_RSA_OAEP_ENC                                (sizeof(eslt_WorkSpaceRSAOAEPenc)    - sizeof(eslt_WorkSpaceHeader))
#define ESL_MAXSIZEOF_WS_RSA_OAEP_DEC                                (sizeof(eslt_WorkSpaceRSAOAEPdec)    - sizeof(eslt_WorkSpaceHeader))
#define ESL_MAXSIZEOF_WS_RSA_CRT_OAEP_DEC                            (sizeof(eslt_WorkSpaceRSACRTOAEPdec) - sizeof(eslt_WorkSpaceHeader))

#define ESL_MAXSIZEOF_WS_RSA_OAEP                                    ESL_MAXSIZEOF_WS_RSA_OAEP_ENC

#define ESL_SIZEOF_WS_RSA_OAEP_ENC_512                               ESL_MAXSIZEOF_WS_RSA_OAEP_ENC
#define ESL_SIZEOF_WS_RSA_OAEP_DEC_512                               ESL_MAXSIZEOF_WS_RSA_OAEP_DEC
#define ESL_SIZEOF_WS_RSA_CRT_OAEP_DEC_512                           ESL_MAXSIZEOF_WS_RSA_CRT_OAEP_DEC

#define ESL_SIZEOF_WS_RSA_OAEP_512                                   ESL_MAXSIZEOF_WS_RSA_OAEP_ENC

#define ESL_SIZEOF_WS_RSA_OAEP_ENC_1024                              ESL_MAXSIZEOF_WS_RSA_OAEP_ENC
#define ESL_SIZEOF_WS_RSA_OAEP_DEC_1024                              ESL_MAXSIZEOF_WS_RSA_OAEP_DEC
#define ESL_SIZEOF_WS_RSA_CRT_OAEP_DEC_1024                          ESL_MAXSIZEOF_WS_RSA_CRT_OAEP_DEC

#define ESL_SIZEOF_WS_RSA_OAEP_1024                                  ESL_MAXSIZEOF_WS_RSA_OAEP_ENC

#define ESL_SIZEOF_WS_RSA_OAEP_ENC_1536                              ESL_MAXSIZEOF_WS_RSA_OAEP_ENC
#define ESL_SIZEOF_WS_RSA_OAEP_DEC_1536                              ESL_MAXSIZEOF_WS_RSA_OAEP_DEC
#define ESL_SIZEOF_WS_RSA_CRT_OAEP_DEC_1536                          ESL_MAXSIZEOF_WS_RSA_CRT_OAEP_DEC

#define ESL_SIZEOF_WS_RSA_OAEP_1536                                  ESL_MAXSIZEOF_WS_RSA_OAEP_ENC

#define ESL_SIZEOF_WS_RSA_OAEP_ENC_2048                              ESL_MAXSIZEOF_WS_RSA_OAEP_ENC
#define ESL_SIZEOF_WS_RSA_OAEP_DEC_2048                              ESL_MAXSIZEOF_WS_RSA_OAEP_DEC
#define ESL_SIZEOF_WS_RSA_CRT_OAEP_DEC_2048                          ESL_MAXSIZEOF_WS_RSA_CRT_OAEP_DEC

#define ESL_SIZEOF_WS_RSA_OAEP_2048                                  ESL_MAXSIZEOF_WS_RSA_OAEP_ENC

#define ESL_SIZEOF_WS_RSA_OAEP_ENC_3072                              ESL_MAXSIZEOF_WS_RSA_OAEP_ENC
#define ESL_SIZEOF_WS_RSA_OAEP_DEC_3072                              ESL_MAXSIZEOF_WS_RSA_OAEP_DEC
#define ESL_SIZEOF_WS_RSA_CRT_OAEP_DEC_3072                          ESL_MAXSIZEOF_WS_RSA_CRT_OAEP_DEC

#define ESL_SIZEOF_WS_RSA_OAEP_3072                                  ESL_MAXSIZEOF_WS_RSA_OAEP_ENC

#define ESL_SIZEOF_WS_RSA_OAEP_ENC_4096                              ESL_MAXSIZEOF_WS_RSA_OAEP_ENC
#define ESL_SIZEOF_WS_RSA_OAEP_DEC_4096                              ESL_MAXSIZEOF_WS_RSA_OAEP_DEC
#define ESL_SIZEOF_WS_RSA_CRT_OAEP_DEC_4096                          ESL_MAXSIZEOF_WS_RSA_CRT_OAEP_DEC

#define ESL_SIZEOF_WS_RSA_OAEP_4096                                  ESL_MAXSIZEOF_WS_RSA_OAEP_ENC

#define ESL_MAXSIZEOF_WS_RSA_PSS_SIG                                 (sizeof(eslt_WorkSpaceRSAPSSsig)    - sizeof(eslt_WorkSpaceHeader))
#define ESL_MAXSIZEOF_WS_RSA_PSS_VER                                 (sizeof(eslt_WorkSpaceRSAPSSver)    - sizeof(eslt_WorkSpaceHeader))

#define ESL_MAXSIZEOF_WS_RSA_PSS_CRT_SIG                             (0u)
#define ESL_MAXSIZEOF_WS_RSA_PSS                                     (sizeof(eslt_WorkSpaceRSAPSSsig))

#define ESL_SIZEOF_WS_RSA_PSS_SIG_512                                ESL_MAXSIZEOF_WS_RSA_PSS_SIG
#define ESL_SIZEOF_WS_RSA_PSS_CRT_SIG_512                            ESL_MAXSIZEOF_WS_RSA_PSS_CRT_SIG
#define ESL_SIZEOF_WS_RSA_PSS_VER_512                                ESL_MAXSIZEOF_WS_RSA_PSS_VER
#define ESL_SIZEOF_WS_RSA_PSS_512                                    ESL_MAXSIZEOF_WS_RSA_PSS

#define ESL_SIZEOF_WS_RSA_PSS_SIG_1024                               ESL_MAXSIZEOF_WS_RSA_PSS_SIG
#define ESL_SIZEOF_WS_RSA_PSS_CRT_SIG_1024                           ESL_MAXSIZEOF_WS_RSA_PSS_CRT_SIG
#define ESL_SIZEOF_WS_RSA_PSS_VER_1024                               ESL_MAXSIZEOF_WS_RSA_PSS_VER
#define ESL_SIZEOF_WS_RSA_PSS_1024                                   ESL_MAXSIZEOF_WS_RSA_PSS

#define ESL_SIZEOF_WS_RSA_PSS_SIG_1536                               ESL_MAXSIZEOF_WS_RSA_PSS_SIG
#define ESL_SIZEOF_WS_RSA_PSS_CRT_SIG_1536                           ESL_MAXSIZEOF_WS_RSA_PSS_CRT_SIG
#define ESL_SIZEOF_WS_RSA_PSS_VER_1536                               ESL_MAXSIZEOF_WS_RSA_PSS_VER
#define ESL_SIZEOF_WS_RSA_PSS_1536                                   ESL_MAXSIZEOF_WS_RSA_PSS

#define ESL_SIZEOF_WS_RSA_PSS_SIG_2048                               ESL_MAXSIZEOF_WS_RSA_PSS_SIG
#define ESL_SIZEOF_WS_RSA_PSS_CRT_SIG_2048                           ESL_MAXSIZEOF_WS_RSA_PSS_CRT_SIG
#define ESL_SIZEOF_WS_RSA_PSS_VER_2048                               ESL_MAXSIZEOF_WS_RSA_PSS_VER
#define ESL_SIZEOF_WS_RSA_PSS_2048                                   ESL_MAXSIZEOF_WS_RSA_PSS

#define ESL_SIZEOF_WS_RSA_PSS_SIG_3072                               ESL_MAXSIZEOF_WS_RSA_PSS_SIG
#define ESL_SIZEOF_WS_RSA_PSS_CRT_SIG_3072                           ESL_MAXSIZEOF_WS_RSA_PSS_CRT_SIG
#define ESL_SIZEOF_WS_RSA_PSS_VER_3072                               ESL_MAXSIZEOF_WS_RSA_PSS_VER
#define ESL_SIZEOF_WS_RSA_PSS_3072                                   ESL_MAXSIZEOF_WS_RSA_PSS

#define ESL_SIZEOF_WS_RSA_PSS_SIG_4096                               ESL_MAXSIZEOF_WS_RSA_PSS_SIG
#define ESL_SIZEOF_WS_RSA_PSS_CRT_SIG_4096                           ESL_MAXSIZEOF_WS_RSA_PSS_CRT_SIG
#define ESL_SIZEOF_WS_RSA_PSS_VER_4096                               ESL_MAXSIZEOF_WS_RSA_PSS_VER
#define ESL_SIZEOF_WS_RSA_PSS_4096                                   ESL_MAXSIZEOF_WS_RSA_PSS

#define ESL_SIZEOF_WS_SPAKE2P                                        sizeof(eslt_WorkSpaceSPAKE2P) - sizeof(eslt_WorkSpaceHeader)
#define ESL_SIZEOF_WS_SPAKE2PPRE                                     sizeof(actSPAKE2PPreambleStruct)

#define ESL_SIZEOF_WS_Ed25519                                        (sizeof(actEd25519STRUCT))
#define ESL_SIZEOF_WS_X25519                                         (sizeof(actX25519STRUCT))

#define ESL_SIZEOF_WS_ChaCha20                                       (140u)
#define ESL_SIZEOF_WS_Poly1305                                       (180u)
#define ESL_SIZEOF_WS_AEAD_ChaCha_Poly                               (390u)

#define ESL_SIZEOF_WS_AESCCM                                         (sizeof(actAESCCMSTRUCT))

typedef struct{
  eslt_WorkSpaceHeader header;
  actAESSTRUCT wsAES;
}eslt_WorkSpaceAES;

typedef eslt_WorkSpaceAES eslt_WorkSpaceAES128;
typedef eslt_WorkSpaceAES eslt_WorkSpaceAES128Block;
typedef eslt_WorkSpaceAES eslt_WorkSpaceAES192;
typedef eslt_WorkSpaceAES eslt_WorkSpaceAES192Block;
typedef eslt_WorkSpaceAES eslt_WorkSpaceAES256;
typedef eslt_WorkSpaceAES eslt_WorkSpaceAES256Block;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsDES[ESL_MAXSIZEOF_WS_DES];
}eslt_WorkSpaceDES;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsDESBlock[ESL_MAXSIZEOF_WS_DESBLOCK];
}eslt_WorkSpaceDESBlock;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsTDES[ESL_MAXSIZEOF_WS_TDES];
}eslt_WorkSpaceTDES;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsTDESBlock[ESL_MAXSIZEOF_WS_TDESBLOCK];
}eslt_WorkSpaceTDESBlock;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsRC2[ESL_MAXSIZEOF_WS_RC2];
}eslt_WorkSpaceRC2;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsRC2Block[ESL_MAXSIZEOF_WS_RC2BLOCK];
}eslt_WorkSpaceRC2Block;

typedef struct{
  eslt_WorkSpaceHeader header;
  actGCMSTRUCT wsGCM;
}eslt_WorkSpaceGCM;

typedef struct{
  eslt_WorkSpaceHeader header;
  actGCMSTRUCT wsGMAC;
}eslt_WorkSpaceGMAC;

typedef struct{
  eslt_WorkSpaceHeader header;
  actSHASTRUCT wsSHA1;
}eslt_WorkSpaceSHA1;

typedef struct{
  eslt_WorkSpaceHeader header;
  actSHA224STRUCT wsSHA224;
}eslt_WorkSpaceSHA224;

typedef struct{
  eslt_WorkSpaceHeader header;
  actSHA256STRUCT wsSHA256;
}eslt_WorkSpaceSHA256;

typedef struct{
  eslt_WorkSpaceHeader header;
  actSHA512_224STRUCT wsSHA512_224;
}eslt_WorkSpaceSHA512_224;

typedef struct{
  eslt_WorkSpaceHeader header;
  actSHA512_256STRUCT wsSHA512_256;
}eslt_WorkSpaceSHA512_256;

typedef struct{
  eslt_WorkSpaceHeader header;
  actSHA384STRUCT wsSHA384;
}eslt_WorkSpaceSHA384;

typedef struct{
  eslt_WorkSpaceHeader header;
  actSHA512STRUCT wsSHA512;
}eslt_WorkSpaceSHA512;

typedef struct{
  eslt_WorkSpaceHeader header;
  actKECCAKcSTRUCT wsSHA3;
}eslt_WorkSpaceSHA3;

typedef struct{
  eslt_WorkSpaceHeader header;
  actKECCAKcSTRUCT wsSHAKE;
}eslt_WorkSpaceSHAKE;

typedef struct{
  eslt_WorkSpaceHeader header;
  actRMD160STRUCT wsRIPEMD160;
}eslt_WorkSpaceRIPEMD160;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsMD5[ESL_MAXSIZEOF_WS_MD5];
}eslt_WorkSpaceMD5;

typedef struct{
  eslt_WorkSpaceHeader header;
  actHASHMACSTRUCT wsHMACSHA1;
}eslt_WorkSpaceHMACSHA1;

typedef struct{
  eslt_WorkSpaceHeader header;
  actHASHMACSHA256STRUCT wsHMACSHA256;
}eslt_WorkSpaceHMACSHA256;

typedef struct{
  eslt_WorkSpaceHeader header;
  actHASHMACSHA384STRUCT wsHMACSHA384;
}eslt_WorkSpaceHMACSHA384;

typedef struct{
  eslt_WorkSpaceHeader header;
  actHASHMACRMD160STRUCT wsHMACRIPEMD160;
}eslt_WorkSpaceHMACRIPEMD160;

typedef struct{
  eslt_WorkSpaceHeader header;
  actCMACAESSTRUCT wsCMACAESbuffer;
  VSECPRIM_P2VAR_PARA(eslt_Byte) wsCMACAES;
}eslt_WorkSpaceCMACAES;

typedef struct{
  eslt_WorkSpaceHeader header;
  actSipHashSTRUCT wsSipHash;
}eslt_WorkSpaceSipHash;

typedef struct{
  eslt_WorkSpaceHeader header;
  actFIPS186STRUCT wsFIPS186buffer;
  VSECPRIM_P2VAR_PARA(eslt_Byte) wsFIPS186;
}eslt_WorkSpaceFIPS186;

typedef struct{
  eslt_WorkSpaceHeader header;
  actCTRDRBGSTRUCT wsDRBG;
}eslt_WorkSpaceCTRDRBG;

typedef struct{
  eslt_WorkSpaceHeader header;
  actHASHDRBGSTRUCT wsDRBG;
}eslt_WorkSpaceHASHDRBG;

typedef struct{
  eslt_WorkSpaceHeader header;
  actKDF2STRUCT wsKDF2HMACSHA;
}eslt_WorkSpaceKDF2;

#define eslt_WorkSpaceKDF2HMACSHA1                                   eslt_WorkSpaceKDF2
#define eslt_WorkSpaceKDF2HMACSHA256                                 eslt_WorkSpaceKDF2

typedef struct{
  eslt_WorkSpaceHeader header;
  actKDFX963STRUCT wsKDFX963SHA1;
}eslt_WorkSpaceKDFX963SHA1;

typedef struct{
  eslt_WorkSpaceHeader header;
  actKDFX963SHA256 wsKDFX963SHA256;
}eslt_WorkSpaceKDFX963SHA256;

typedef struct{
  eslt_WorkSpaceHeader header;
  actKDFX963SHA512 wsKDFX963SHA512;
}eslt_WorkSpaceKDFX963SHA512;

typedef struct{
  eslt_WorkSpaceHeader header;
  actHKDFHASHSTRUCT wsHKDF;
}eslt_WorkSpaceHKDFHASH;

typedef struct{
  eslt_WorkSpaceHeader header;
  actHKDFSTRUCT wsHKDF;
}eslt_WorkSpaceHKDFHMAC;

typedef struct{
  eslt_WorkSpaceHeader header;
  actECPSTRUCT wsEcP;
}eslt_WorkSpaceEcP;

typedef struct{
  eslt_WorkSpaceHeader header;
  actSPAKE2PSTRUCT workSpaceSpake;
  actCMACAESSTRUCT workSpaceCMAC;
  actHKDFSTRUCT workSpaceHKDF;
  actSHA256STRUCT workSpaceSHA;
}eslt_WorkSpaceSPAKE2P;

typedef struct{
  eslt_WorkSpaceHeader header;
  actSPAKE2PPreambleStruct wsSPAKEPreamble;
}eslt_WorkSpaceSPAKE2PPreamble;

typedef struct{
  eslt_WorkSpaceHeader header;
  actRSAPRIMSTRUCT wsRSAPrimBuf;
}eslt_WorkSpaceRSAenc_prim;

typedef struct{
  eslt_WorkSpaceHeader header;
  actRSAPRIMSTRUCT wsRSAPrimBuf;
}eslt_WorkSpaceRSAdec_prim;

typedef struct{
  eslt_WorkSpaceHeader header;
  actRSACRTSTRUCT CRTStruct;
}eslt_WorkSpaceRSACRTdec_prim;

typedef struct{
  eslt_WorkSpaceHeader header;
  actRSAPRIMSTRUCT wsRSAPrimBuf;
}eslt_WorkSpaceRSAsig_prim;

typedef struct{
  eslt_WorkSpaceHeader header;
  actRSACRTSTRUCT CRTStruct;
}eslt_WorkSpaceRSACRTsig_prim;

typedef struct{
  eslt_WorkSpaceHeader header;
  actRSAPRIMSTRUCT wsRSAPrimBuf;
}eslt_WorkSpaceRSAver_prim;

typedef union
{
#if( VSECPRIM_RSA_OAEP_SHA2_256_ENABLED == STD_ON || VSECPRIM_RSA_V15_SHA2_256_ENABLED == STD_ON || VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON )
  eslt_WorkSpaceSHA256 SHA256ws;
#endif
#if( VSECPRIM_RSA_V15_RIPEMD160_ENABLED == STD_ON || VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON )
  eslt_WorkSpaceRIPEMD160 RIPEMD160ws;
#endif
  eslt_WorkSpaceSHA1 SHA1ws;
}eslt_WorkSpaceUnionHashFunctions_RSA;

typedef struct{
  eslt_Byte encodedMessage[Esl_BitsToBytes(ESL_RSA_KEYSIZE)];
  eslt_Byte dataBlock[Esl_BitsToBytes(ESL_RSA_KEYSIZE) - ESL_SIZEOF_SHA1_DIGEST - 1u];
  eslt_Byte tempVariables[ESL_SIZEOF_SHA256_DIGEST];
}eslt_EMBuffer;

typedef struct{
  eslt_WorkSpaceHeader header;
  VSECPRIM_P2VAR_PARA(eslt_EMBuffer) encodedMessageBufferPtr;
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceUnionHashFunctions_RSA) wsHashUnionPtr;
  VSECPRIM_P2VAR_PARA(eslt_Length) modulusInformationPtr;
}eslt_WorkSpace;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte messageBuffer[Esl_BitsToBytes(ESL_RSA_KEYSIZE)];
  eslt_WorkSpaceRSAenc_prim wsRSAEncPrim;
  eslt_Length modulusSizeInformation;
}eslt_WorkSpaceRSAenc;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte messageBuffer[Esl_BitsToBytes(ESL_RSA_KEYSIZE)];
  eslt_WorkSpaceRSAdec_prim wsRSADecPrim;
  eslt_Length modulusSizeInformation;
}eslt_WorkSpaceRSAdec;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsEncoding[Esl_BitsToBytes(ESL_RSA_KEYSIZE)];
  eslt_WorkSpaceRSACRTdec_prim wsRSACRTDecPrim;
  eslt_Length primeSizesInformation;
}eslt_WorkSpaceRSACRTdec;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte messageBuffer[Esl_BitsToBytes(ESL_RSA_KEYSIZE)];
  eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
  eslt_WorkSpaceRSAsig_prim wsRSASigPrim;
  eslt_Length modulusSizeInformation;
}eslt_WorkSpaceRSAsig;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsEncoding[Esl_BitsToBytes(ESL_RSA_KEYSIZE)];
  eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
  eslt_WorkSpaceRSACRTsig_prim wsRSACRTSigPrim;
  eslt_Length primeSizesInformation;
}eslt_WorkSpaceRSACRTsig;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte messageBuffer[Esl_BitsToBytes(ESL_RSA_KEYSIZE)];
  eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
  eslt_WorkSpaceRSAver_prim wsRSAVerPrim;
  eslt_Length modulusSizeInformation;
}eslt_WorkSpaceRSAver;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_EMBuffer encodedMessageBuffer;
  eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
  eslt_WorkSpaceRSAenc_prim wsRSAEncPrim;
  eslt_Length modulusSizeInformation;
}eslt_WorkSpaceRSAOAEPenc;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_EMBuffer encodedMessageBuffer;
  eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
  eslt_WorkSpaceRSAdec_prim wsRSADecPrim;
  eslt_Length modulusSizeInformation;
}eslt_WorkSpaceRSAOAEPdec;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_EMBuffer encodedMessageBuffer;
  eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
  eslt_WorkSpaceRSACRTdec_prim wsRSACRTDecPrim;
  eslt_Length modulusSizeInformation;
}eslt_WorkSpaceRSACRTOAEPdec;

typedef struct{
  eslt_WorkSpaceHeader  header;
  eslt_EMBuffer encodedMessageBuffer;
  eslt_WorkSpaceRSAsig_prim wsRSASigPrim;
  eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
  eslt_Length modulusSizeInformation;
}eslt_WorkSpaceRSAPSSsig;

typedef struct{
  eslt_WorkSpaceHeader  header;
  eslt_EMBuffer encodedMessageBuffer;
  eslt_WorkSpaceRSAver_prim wsRSAVerPrim;
  eslt_WorkSpaceUnionHashFunctions_RSA wsHashUnion;
  eslt_Length modulusSizeInformation;
}eslt_WorkSpaceRSAPSSver;

typedef struct{
  eslt_WorkSpaceHeader header;
  actEd25519STRUCT wsEd25519buffer;
  VSECPRIM_P2VAR_PARA(eslt_Byte) wsEd25519;
}eslt_WorkSpaceEd25519;

typedef struct{
  eslt_WorkSpaceHeader header;
  actX25519STRUCT wsX25519buffer;
  VSECPRIM_P2VAR_PARA(eslt_Byte) wsX25519;
}eslt_WorkSpaceX25519;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsChaCha20 [ESL_SIZEOF_WS_ChaCha20];
}eslt_WorkSpaceChaCha20;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsPoly1305 [ESL_SIZEOF_WS_Poly1305];
}eslt_WorkSpacePoly1305;

typedef struct{
  eslt_WorkSpaceHeader header;
  eslt_Byte wsAEADChaChaPoly [ESL_SIZEOF_WS_AEAD_ChaCha_Poly];
}eslt_WorkSpaceChaChaPoly;

typedef struct{
  eslt_WorkSpaceHeader header;
  actAESCCMSTRUCT wsAESCCM;
}eslt_WorkSpaceAESCCM;

typedef struct{
  eslt_WorkSpaceHeader header;
  actECBDstruct wsECBD;
}eslt_WorkSpaceECBD;

#endif

