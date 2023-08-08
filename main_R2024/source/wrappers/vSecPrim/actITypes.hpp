

#ifndef ACTITYPES_H
# define ACTITYPES_H

# include "actPlatformTypes.hpp"
# include "actConfig.hpp"

typedef actPlatformUint8 actU8;
typedef actPlatformUint16 actU16;
typedef actPlatformUint32 actU32;
# ifdef ACT_PLATFORM_UINT64_AVAILABLE
typedef actPlatformUint64 actU64;
# endif

# ifndef TRUE
#  define TRUE                                                        (1u)
# endif

# ifndef FALSE
#  define FALSE                                                       (0u)
# endif

typedef actU32 actLengthType;
typedef actLengthType actBNLENGTH;
typedef unsigned char actBoolean;

typedef actLengthType actDRBGReseedCounterType;

VSECPRIM_P2CONST_TYPE(VSECPRIM_NONE, actU8) actPKey;
VSECPRIM_P2ROMCONST_TYPE(VSECPRIM_NONE, actU8) actPROMU8;

# define actBN_BITS_PER_DIGIT                                         (ACT_PLATFORM_BITS_PER_DIGIT)
# define actBN_BYTES_PER_DIGIT                                        ((actBN_BITS_PER_DIGIT)>>3)

# define actBNGetDigitLengthFromBit(bit_len)                          (((bit_len)+actBN_BITS_PER_DIGIT-1u)/actBN_BITS_PER_DIGIT)

# if(actBN_BITS_PER_DIGIT == 8)
#  define actBN_BITS_PER_DIGIT_IS_VALID

typedef actU8 actBNDIGIT;
typedef actU16 actBNDDIGIT;
# endif
# if(actBN_BITS_PER_DIGIT == 16)
#  define actBN_BITS_PER_DIGIT_IS_VALID

typedef actU16 actBNDIGIT;
typedef actU32 actBNDDIGIT;
# endif
# if(actBN_BITS_PER_DIGIT == 32)
#  define actBN_BITS_PER_DIGIT_IS_VALID

#  if defined(ACT_PLATFORM_UINT64_AVAILABLE)
typedef actU32 actBNDIGIT;
typedef actU64 actBNDDIGIT;
#  else
#   error UNABLE TO DEFINE 64 BIT DOUBLE DIGIT TYPE (NOT AVAILABLE)
#  endif
# endif
# ifndef actBN_BITS_PER_DIGIT_IS_VALID
#  error actBN_BITS_PER_DIGIT value unsupported
# endif

typedef actU32 actRETURNCODE;

# define actOK                                                        (0x00u)

# define actDONE                                                      (0x02u)

# define actEXCEPTION_UNKNOWN                                         (0x01u)

# define actCOMPARE_SMALLER                                           (0x10u)
# define actCOMPARE_EQUAL                                             (0x11u)
# define actCOMPARE_LARGER                                            (0x12u)

# define actEXCEPTION_NULL                                            (0xFFu)

# define actEXCEPTION_DOMAIN                                          (0xFEu)
# define actEXCEPTION_DOMAIN_EXT                                      (0xFDu)
# define actEXCEPTION_SPEEDUP_EXT                                     (0xFCu)

# define actEXCEPTION_PRIVKEY                                         (0xFBu)

# define actEXCEPTION_POINT                                           (0xFAu)

# define actEXCEPTION_PUBKEY                                          (0xF9u)

# define actEXCEPTION_LENGTH                                          (0xF8u)

# define actEXCEPTION_ALGOID                                          (0xF7u)

# define actEXCEPTION_PADDING                                         (0xF6u)

# define actEXCEPTION_INPUT_LENGTH                                    (0xF5u)

# define actEXCEPTION_MEMORY                                          (0xF4u)

# define actVERIFICATION_FAILED                                       (0xF3u)

# define actEXCEPTION_MODE                                            (0xF2u)

# define actEXCEPTION_RANDOM                                          (0xF1u)

# define actEXCEPTION_ENTROPY_EXHAUSTION                              (0xF0u)

# define actEXCEPTION_OUTPUT_BUFFER                                   (0xEFu)

# define actPADDING_PM_OFF                                            (0x00u)
# define actPADDING_PM_ONEWITHZEROES                                  (0x10u)

# define actPADDING_PM_PKCS7                                          (0x20u)

# define actPADDING_PM_MASK                                           (0xF0u)

# define actAES_BLOCK_SIZE                                            (16u)

# define actAES_BM_ECB                                                (0x00u)

# define actAES_BM_CBC                                                (0x01u)

# define actAES_BM_CTR                                                (0x04u)

# define actAES_BM_MASK                                               (0x0Fu)

# if((actAES_BM_MASK & actPADDING_PM_MASK) != 0x00u)
#  error Bits of actAES_BM_MASK and actPADDING_PM_MASK overlap
# endif

# define actAES_ECB                                                   (actAES_BM_ECB | actPADDING_PM_PKCS7)

# define actAES_CBC                                                   (actAES_BM_CBC | actPADDING_PM_PKCS7)

# define actHASH_SIZE_SHA                                             (20u)
# define actHASH_BLOCK_SIZE_SHA                                       (64u)

# define actHASH_SIZE_SHA224                                          (28u)
# define actHASH_SIZE_SHA256                                          (32u)
# define actHASH_BLOCK_SIZE_SHA256                                    (64u)

# define actHASH_SIZE_SHA512_224                                      (28u)
# define actHASH_SIZE_SHA512_256                                      (32u)
# define actHASH_SIZE_SHA384                                          (48u)
# define actHASH_SIZE_SHA512                                          (64u)
# define actHASH_BLOCK_SIZE_SHA512                                    (128u)

# define actHASH_SIZE_SHA3_224                                        (224u / 8u)
# define actHASH_SIZE_SHA3_256                                        (256u / 8u)
# define actHASH_SIZE_SHA3_384                                        (384u / 8u)
# define actHASH_SIZE_SHA3_512                                        (512u / 8u)

# define actHASH_SHA3_WIDTH                                           (1600u)
# define actHASH_SHA3_LANE                                            (64u)

# define actHASH_SHA3_PAD_1_SHA3                                      (0x06)
# define actHASH_SHA3_PAD_1_SHAKE                                     (0x1F)
# define actHASH_SHA3_PAD_1_cSHAKE                                    (0x04)
# define actHASH_SHA3_PAD_2                                           (0x80)

# define actHASH_SIZE_RMD160                                          (20u)
# define actHASH_BLOCK_SIZE_RMD160                                    (64u)

# ifdef actHASH_SIZE_SHA_KDF
# else
#  if VSECPRIM_ACTKDF2HMACSHA256_ENABLED
#   define actHASH_SIZE_SHA_KDF                                       actHASH_SIZE_SHA256
#  else
#   define actHASH_SIZE_SHA_KDF                                       actHASH_SIZE_SHA
#  endif
# endif

# define actHKDF_ONESTEPMETHOD                                        (0x01u)
# define actHKDF_TWOSTEPMETHOD                                        (0x02u)

# define actHASHMACSHA1_ALGO_ID                                       (0u)
# define actHASHMACSHA256_ALGO_ID                                     (1u)

# if((VSECPRIM_ACTKDF2HMACSHA1_ENABLED == STD_ON) || (VSECPRIM_ACTKDF2HMACSHA256_ENABLED == STD_ON))
#  define VSECPRIM_ACTKDF2_ENABLED                                    STD_ON
# else
#  define VSECPRIM_ACTKDF2_ENABLED                                    STD_OFF
# endif

# define actFIPS186_BASE_LENGTH                                       (20u)
# define actFIPS186_SEED_SIZE                                         actFIPS186_BASE_LENGTH

# define actITypesMax(x, y)                                           (((x)>(y))? (x):(y))

# define actCTRDRBG_ALGSIZE_AES128                                    (0x01u)
# define actCTRDRBG_ALGSIZE_AES256                                    (0x03u)
# define actHASHDRBG_ALGSIZE_SHA512                                   (0x05u)

# define actCTRDRBG_DFMODE_USE_NO_DF                                  (0x00u)
# define actCTRDRBG_DFMODE_USE_BLOCKCIPHER_DF                         (0x10u)

# define actDRBG_ALGSIZE_MASK                                         (0x0Fu)
# define actDRBG_DFMODE_MASK                                          (0xF0u)

# define actDRBGMODE_CTRDRBG_AES128_DF                                (actCTRDRBG_DFMODE_USE_BLOCKCIPHER_DF + actCTRDRBG_ALGSIZE_AES128)
# define actDRBGMODE_CTRDRBG_AES128_NODF                              (actCTRDRBG_DFMODE_USE_NO_DF + actCTRDRBG_ALGSIZE_AES128)
# define actDRBGMODE_CTRDRBG_AES256_DF                                (actCTRDRBG_DFMODE_USE_BLOCKCIPHER_DF + actCTRDRBG_ALGSIZE_AES256)
# define actDRBGMODE_CTRDRBG_AES256_NODF                              (actCTRDRBG_DFMODE_USE_NO_DF + actCTRDRBG_ALGSIZE_AES256)

# define actDRBGMODE_HASHDRBG_SHA512                                  (actHASHDRBG_ALGSIZE_SHA512)

# define actDRBG_SEED_STATE_UNSEEDED                                  (0x00u)
# define actDRBG_SEED_STATE_SEEDED                                    (0x01u)
# define actDRBG_SEED_STATE_NEED_RESEED                               (0x02u)

# define actAES128_KEY_SIZE                                           (16u)
# define actAES256_KEY_SIZE                                           (32u)
# define actCTRDRBG_AES128_KEY_LEN                                    (actAES128_KEY_SIZE)
# define actCTRDRBG_AES256_KEY_LEN                                    (actAES256_KEY_SIZE)

# define actCTRDRBG_BLOCK_LEN                                         (actAES_BLOCK_SIZE)

# define actAESCTRDRBG_MAX_KEY_LEN                                    actCTRDRBG_AES256_KEY_LEN

# define actAES128CTRDRBG_SEED_LEN                                    (actCTRDRBG_AES128_KEY_LEN + actCTRDRBG_BLOCK_LEN)
# define actAES256CTRDRBG_SEED_LEN                                    (actCTRDRBG_AES256_KEY_LEN + actCTRDRBG_BLOCK_LEN)

# define actAESCTRDRBG_SEED_LEN                                       (actAESCTRDRBG_MAX_KEY_LEN + actCTRDRBG_BLOCK_LEN)

# define actDRBG_SIZEOF_INPUTLENGTH                                   (sizeof(actLengthType))

# define actAESCTRDRBG_DF_BUFFER_OFFSET                               (actDRBG_SIZEOF_INPUTLENGTH * 2u)

# define actAESCTRDRBG_MAX_OUTPUT_SIZE                                (1024u)

# define actCTRDRBG_AES128_RESEED_INTERVAL                            VSECPRIM_DRBG_RESEED_INTERVAL
# define actHASHDRBG_RESEED_INTERVAL                                  VSECPRIM_DRBG_RESEED_INTERVAL

# define actHASHDRBG_SHA512_SEED_LEN                                  (111u)
# define actHASHDRBG_SHA512_OUTLEN                                    (64u)
# define actHASHDRBG_MAX_OUTPUT_SIZE                                  (65535u)

# if(VSECPRIM_ACTBNEUCLID_ENABLED == STD_ON)

#  define actEC_BIGNUM_TMP                                            actMax((actEC_MOD_EXP_TMP+2u), 6u)
# else

#  define actEC_BIGNUM_TMP                                            actITypesMax((actEC_MOD_EXP_TMP+2u), 4u)
# endif

# define actEd25519_KEY_SIZE                                          (32u)
# define actEd25519pure                                               (0u)
# define actEd25519ctx                                                (1u)
# define actEd25519ph                                                 (2u)
# define actX25519_KEY_SIZE                                           (32u)

# define BNDIGITS_256                                                 (256u /8u /sizeof (actBNDIGIT))
# define BNDIGITS_512                                                 (512u /8u /sizeof (actBNDIGIT))
# define BNBYTES_256                                                  (256u /8u /sizeof (actU8))
# define BNBYTES_512                                                  (512u /8u /sizeof (actU8))
# define MASK_MSBit                                                   (0x7FFFFFFFuL >> (32u - actBN_BITS_PER_DIGIT))

# define actSPAKE2P_MAX_AAD_SIZE                                      VSECPRIM_SPAKE2_P_MAX_AADSIZE

# define actSPAKE2P_HASH_MASK                                         (0x0000Fu)
# define actSPAKE2P_KDF_MASK                                          (0x000F0u)
# define actSPAKE2P_MAC_MASK                                          (0x00F00u)
# define actSPAKE2P_VERSION_MASK                                      (0x0F000u)
# define actSPAKE2P_CURVE_MASK                                        (0xF0000u)

# define actSPAKE2P_HASHFCT_SHA256                                    (0x0001u)
# define actSPAKE2P_KDF_HKDF_HMAC_SHA256                              (0x0010u)
# define actSPAKE2P_MAC_CMAC128                                       (0x0100u)

# define actSPAKE2P_VERSION_KEY_A_FIRST                               (0x1000u)
# define actSPAKE2P_VERSION_KEY_B_FIRST                               (0x2000u)

# define actSPAKE2P_CURVE_P256                                        (0x30000u)

# define actSPAKE2P_MODE_CIPHERSUITE_8_1                              (actSPAKE2P_CURVE_P256 + actSPAKE2P_VERSION_KEY_A_FIRST + actSPAKE2P_HASHFCT_SHA256 + actSPAKE2P_KDF_HKDF_HMAC_SHA256 + actSPAKE2P_MAC_CMAC128)
# define actSPAKE2P_MODE_CIPHERSUITE_8_2                              (actSPAKE2P_CURVE_P256 + actSPAKE2P_VERSION_KEY_B_FIRST + actSPAKE2P_HASHFCT_SHA256 + actSPAKE2P_KDF_HKDF_HMAC_SHA256 + actSPAKE2P_MAC_CMAC128)

# define actSPAKE2P_PREAMBLE_OKM_LENGTH                               (VSECPRIM_SPAKE2_P_PREAMBLE_OKMLENGTH)

# define actSPAKE2P_PREAMBLE_WDIGIT_LENGTH                            ((((actSPAKE2P_PREAMBLE_OKM_LENGTH + 1u)/2u) + actBN_BYTES_PER_DIGIT - 1u)/actBN_BYTES_PER_DIGIT)

# define ACT_SIPHASH_CROUNDS                                          (2u)
# define ACT_SIPHASH_DROUNDS                                          (4u)

# define actSIPHASH_BLOCK_SIZE                                        (8u)

# if(actGHASH_SPEED_UP > 1)
#  define actGHASH_SPEED_UP                                           1
# endif

# define actGHASH_BLOCK_SIZE                                          (16u)
# define actGHASH_WORD_SIZE                                           (4u)
# define actGHASH_WORDS_PER_BLOCK                                     (actGHASH_BLOCK_SIZE/actGHASH_WORD_SIZE)

# define actGCM_BLOCK_SIZE                                            16u
# define actGCM_BYTE_SIZE                                             8u
# define actGCM_IV_DEFAULT_SIZE                                       12u
# define actGCM_TAG_LENGTH                                            16u

# if(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_512)
#  define actRSA_MAX_KEY_SIZE_IN_DIGIT                                (512u/actBN_BITS_PER_DIGIT)
# elif(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_1024)
#  define actRSA_MAX_KEY_SIZE_IN_DIGIT                                (1024u/actBN_BITS_PER_DIGIT)
# elif(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_1536)
#  define actRSA_MAX_KEY_SIZE_IN_DIGIT                                (1536u/actBN_BITS_PER_DIGIT)
# elif(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_2048)
#  define actRSA_MAX_KEY_SIZE_IN_DIGIT                                (2048u/actBN_BITS_PER_DIGIT)
# elif(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_3072)
#  define actRSA_MAX_KEY_SIZE_IN_DIGIT                                (3072u/actBN_BITS_PER_DIGIT)
# elif(vSecPrim_GetRSAMaxKeySizeOfGeneral() == VSECPRIM_RSA_MAX_KEY_SIZE_4096)
#  define actRSA_MAX_KEY_SIZE_IN_DIGIT                                (4096u/actBN_BITS_PER_DIGIT)
# else
#  error Invalid maximum Key size for RSA selected
# endif

# define actRSA_CRT_PRIME_SIZE                                        (((actRSA_MAX_KEY_SIZE_IN_DIGIT + 1u) / 2u) + (32u / actBN_BITS_PER_DIGIT))

# define actRSA_CRT_PRIMEPAIR_SIZE                                    (actRSA_MAX_KEY_SIZE_IN_DIGIT + (32u / actBN_BITS_PER_DIGIT))

# if(vSecPrim_GetECPMaxKeySizeOfGeneral() >= VSECPRIM_ECP_MAX_KEY_SIZE_521)
#  define actECC_MAX_P_DIGIT_LEN                                      (actBNGetDigitLengthFromBit(521u))
#  define actECC_MAX_N_DIGIT_LEN                                      (actBNGetDigitLengthFromBit(521u))
#  define actECC_MAX_DIGIT_LEN                                        (actBNGetDigitLengthFromBit(521u))
#  define actECC_MAX_BYTE_LEN                                         (66u)
# elif(vSecPrim_GetECPMaxKeySizeOfGeneral() >= VSECPRIM_ECP_MAX_KEY_SIZE_512)
#  define actECC_MAX_P_DIGIT_LEN                                      (512u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_N_DIGIT_LEN                                      (512u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_DIGIT_LEN                                        (512u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_BYTE_LEN                                         (64u)
# elif(vSecPrim_GetECPMaxKeySizeOfGeneral() >= VSECPRIM_ECP_MAX_KEY_SIZE_384)
#  define actECC_MAX_P_DIGIT_LEN                                      (384u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_N_DIGIT_LEN                                      (384u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_DIGIT_LEN                                        (384u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_BYTE_LEN                                         (48u)
# elif(vSecPrim_GetECPMaxKeySizeOfGeneral() >= VSECPRIM_ECP_MAX_KEY_SIZE_320)
#  define actECC_MAX_P_DIGIT_LEN                                      (320u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_N_DIGIT_LEN                                      (320u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_DIGIT_LEN                                        (320u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_BYTE_LEN                                         (40u)
# elif(vSecPrim_GetECPMaxKeySizeOfGeneral() >= VSECPRIM_ECP_MAX_KEY_SIZE_256)
#  define actECC_MAX_P_DIGIT_LEN                                      (256u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_N_DIGIT_LEN                                      (256u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_DIGIT_LEN                                        (256u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_BYTE_LEN                                         (32u)
# elif(vSecPrim_GetECPMaxKeySizeOfGeneral() >= VSECPRIM_ECP_MAX_KEY_SIZE_224)
#  define actECC_MAX_P_DIGIT_LEN                                      (224u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_N_DIGIT_LEN                                      (224u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_DIGIT_LEN                                        (224u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_BYTE_LEN                                         (28u)
# elif(vSecPrim_GetECPMaxKeySizeOfGeneral() >= VSECPRIM_ECP_MAX_KEY_SIZE_192)
#  define actECC_MAX_P_DIGIT_LEN                                      (192u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_N_DIGIT_LEN                                      (192u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_DIGIT_LEN                                        (192u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_BYTE_LEN                                         (24u)
# else
#  define actECC_MAX_P_DIGIT_LEN                                      (160u/actBN_BITS_PER_DIGIT)
#  define actECC_MAX_N_DIGIT_LEN                                      (actBNGetDigitLengthFromBit(161u))
#  define actECC_MAX_DIGIT_LEN                                        (actBNGetDigitLengthFromBit(161u))
#  define actECC_MAX_BYTE_LEN                                         (21u)
# endif

# if(8 == actBN_BITS_PER_DIGIT)
#  define DIGITs(value)                                               ((actBNDIGIT) ((value) >>  0)), \
                                                                      ((actBNDIGIT)((value) >> 8)), \
                                                                      ((actBNDIGIT)((value) >> 16)), \
                                                                      ((actBNDIGIT)((value) >> 24))
# elif(16 == actBN_BITS_PER_DIGIT)
#  define DIGITs(value)                                               ((actBNDIGIT) ((value) >>  0)), \
                                                                      ((actBNDIGIT)((value) >> 16))
# elif(32 == actBN_BITS_PER_DIGIT)
#  define DIGITs(value)                                               (value)
# else
#  error actBN_BITS_PER_DIGIT value unsupported
# endif

typedef struct{
  actU32 e_key[64];
  actLengthType key_dword_len;
  actLengthType buffer_used;
  actU8 prev_block[actAES_BLOCK_SIZE];
  actU8 buffer[actAES_BLOCK_SIZE];
  actU8 mode;
}actAESSTRUCT;

typedef actAESSTRUCT actCMACAESSTRUCT;

typedef struct{
  actU32 H[5];
  actU32 low_count, hi_count;
  actLengthType buffer_used;
  actU8 buffer[actHASH_BLOCK_SIZE_SHA];
}actSHASTRUCT;

typedef struct{
  actU32 H[8];
  actU32 low_count, hi_count;
  actLengthType buffer_used;
  actU16 result_length;
  actU8 buffer[actHASH_BLOCK_SIZE_SHA256];
}actSHA224STRUCT, actSHA256STRUCT;

typedef struct{
# ifdef ACT_PLATFORM_UINT64_AVAILABLE
  actU64 H[8];
  actU64 count_L, count_H;
# else
  actU32 H[16];
  actU32 count_L, count_2, count_3, count_H;
# endif
  actLengthType buffer_used;
  actU16 result_length;
  actU8 buffer[actHASH_BLOCK_SIZE_SHA512];
}actSHA512_224STRUCT, actSHA512_256STRUCT, actSHA384STRUCT, actSHA512STRUCT;

# ifdef ACT_PLATFORM_UINT64_AVAILABLE
typedef struct{
  actU64  state[actHASH_SHA3_WIDTH/64u];
  actLengthType  strength;
  actLengthType  rUsed;
  actLengthType  dUsed;
  actLengthType  rate;
  actU8   digest[actHASH_SIZE_SHA3_512];
  actU8   data[actHASH_SHA3_LANE >> 3];
  actU8   pad1;
  actU8   phase;
}actKECCAKcSTRUCT;
# else
typedef struct{
  actU32  state[actHASH_SHA3_WIDTH/32u];
  actLengthType strength;
  actLengthType  rUsed;
  actLengthType  dUsed;
  actLengthType  rate;
  actU8   digest[actHASH_SIZE_SHA3_512];
  actU8   data[actHASH_SHA3_LANE >> 3];
  actU8   pad1;
  actU8   phase;
}actKECCAKcSTRUCT;
# endif

typedef struct{
   actU32 H[5];
   actU32 low_count, hi_count;
   actLengthType buffer_used;
   actU8 buffer[actHASH_BLOCK_SIZE_RMD160];
}actRMD160STRUCT;

typedef struct{
  actSHASTRUCT sha;
  actU8 key_buf[actHASH_BLOCK_SIZE_SHA];
  actLengthType key_length;
}actHASHMACSTRUCT;

typedef struct{
  actSHA256STRUCT sha256;
  actU8 key_buf[actHASH_BLOCK_SIZE_SHA256];
  actLengthType key_length;
}actHASHMACSHA256STRUCT;

typedef struct{
   actSHA384STRUCT sha384;
   actU8 key_buf[actHASH_BLOCK_SIZE_SHA512];
   actLengthType key_length;
}actHASHMACSHA384STRUCT;

typedef struct{
   actRMD160STRUCT rmd160;
   actU8 key_buf[actHASH_BLOCK_SIZE_RMD160];
   actLengthType key_length;
}actHASHMACRMD160STRUCT;

typedef union
{
# if VSECPRIM_ACTKDF2HMACSHA256_ENABLED == STD_ON
  actHASHMACSHA256STRUCT hmac_sha256;
# endif
  actHASHMACSTRUCT hmac_sha1;
}actHASHMACUNION_KDF2;

typedef struct{
  actU32 iteration_count;
  actHASHMACUNION_KDF2 hmac;

  actU8 U_buf[actHASH_SIZE_SHA_KDF];
  actU8 F_buf[actHASH_SIZE_SHA_KDF];
}actKDF2STRUCT;

typedef struct{
  actSHASTRUCT actwsHash;
  actU8 hashBuf[actHASH_SIZE_SHA];
}actKDFX963STRUCT;

typedef struct{
  actSHA256STRUCT actwsHash;
  actU8           hashBuf[actHASH_SIZE_SHA256];
}actKDFX963SHA256;

typedef struct{
  actSHA512STRUCT actwsHash;
  actU8           hashBuf[actHASH_SIZE_SHA512];
}actKDFX963SHA512;

typedef struct{
  actHASHMACSHA256STRUCT actwsHmac;
  union
  {
    actU8 tmpKey[actHASH_SIZE_SHA256];
    actU8 blockT[actHASH_SIZE_SHA256];
  }tmpBlock;
  actU8 keyDerivationKey[actHASH_SIZE_SHA256];
  actU8 methodID;
}actHKDFSTRUCT;

typedef struct{
  actSHA256STRUCT actwsSha;
  actU8 blockT[actHASH_SIZE_SHA256];
  actU8 hashID;
}actHKDFHASHSTRUCT;

typedef struct{
  actLengthType bytes_remain;
  actU8 X_KEY[actFIPS186_BASE_LENGTH];
  actSHASTRUCT sha1;
}actFIPS186STRUCT;

typedef struct{
  actU8 result[actCTRDRBG_BLOCK_LEN];
  actU8 input[actCTRDRBG_BLOCK_LEN];
}actCTRDRBGTmpBufferStruct;

typedef struct{
  actAESSTRUCT wsAES;
  union
  {
    actU8 additionalInputPrepared[actAESCTRDRBG_SEED_LEN];
    actU8 seedData[actAESCTRDRBG_SEED_LEN];
  } tmpBuffer;
  union
  {
    actU8 blockUpdateTmpBuffer[actAESCTRDRBG_SEED_LEN];
    actCTRDRBGTmpBufferStruct BCCTmpBuffer;
  } BCCUpdateTmpBuffer;
  actU8 DFencryptBuffer[actAESCTRDRBG_SEED_LEN];
  actU8 DFIV[actCTRDRBG_BLOCK_LEN];
  union
  {
    actU8 blockOfS[actCTRDRBG_BLOCK_LEN];
    actU8 tempAesBlock[actCTRDRBG_BLOCK_LEN];
  } tempBlocks;
  actU8 key[actAESCTRDRBG_MAX_KEY_LEN];
  actU8 variable[actCTRDRBG_BLOCK_LEN];
  actDRBGReseedCounterType reseedCount;
  actU8 mode;
  actU8 seedState;
}actCTRDRBGSTRUCT;

typedef struct{
  actSHA512STRUCT wsSHA512;
  actU8 DFtmp[2u * actHASH_SIZE_SHA512];
  actU8 hashdata[actHASH_BLOCK_SIZE_SHA512];
  actU8 tmpdigest[actHASH_SIZE_SHA512];
  actU8 constant[actHASHDRBG_SHA512_SEED_LEN];
  actU8 variable[actHASHDRBG_SHA512_SEED_LEN];
  actU32 reseedCount;
  actU8 mode;
  actU8 seedState;
}actHASHDRBGSTRUCT;

typedef struct{
  actBNDIGIT x[BNDIGITS_256];
  actBNDIGIT y[BNDIGITS_256];
  actBNDIGIT z[BNDIGITS_256];
  actBNDIGIT t[BNDIGITS_256];
}actPoint;

typedef struct{
  VSECPRIM_P2VAR_PARA(actBNDIGIT) m;
  actLengthType m_length;
  actLengthType m_byte_length;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) RR;
  actBNDIGIT m_bar;
# if(actBN_MONT_MUL_VERSION==1)
  actU32 prime_structure;
# endif
# if(actBN_MOD_EXP_WINDOW_SIZE==0)
  actU32 window_size;
# endif
}actBNRING;

typedef struct{
  actBNRING p_field;
  actBNRING n_field;
  VSECPRIM_P2ROMCONST_PARA(actU8) a_R;
  VSECPRIM_P2ROMCONST_PARA(actU8) b_R;
  VSECPRIM_P2ROMCONST_PARA(actU8) G_R;
  boolean a_equals_p_minus_3;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) t[actEC_BIGNUM_TMP];
  actLengthType groups;
  VSECPRIM_P2ROMCONST_PARA(actU8) prec_first;
}actECCURVE;

typedef struct{
  actBNDIGIT privKey[actECC_MAX_N_DIGIT_LEN];
  actBNDIGIT ephKey[actECC_MAX_N_DIGIT_LEN];
}actECPPrivateKeys;

typedef struct{
  actBNDIGIT u1[actECC_MAX_N_DIGIT_LEN + 1u];
  actBNDIGIT u2[actECC_MAX_N_DIGIT_LEN + 1u];
}actECPTmpVarVerify;

typedef struct{
  actBNDIGIT xcoord[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT ycoord[actECC_MAX_P_DIGIT_LEN];
}actECPaffinePointBuffer;

typedef struct{
  actBNDIGIT xcoord[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT ycoord[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT zcoord[actECC_MAX_P_DIGIT_LEN];
}actECPprojectivePointBuffer;

typedef struct{
  actECCURVE Curve;
  actBNDIGIT p_field_modulus[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT p_field_RR[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT n_field_modulus[actECC_MAX_N_DIGIT_LEN];
  actBNDIGIT n_field_RR[actECC_MAX_N_DIGIT_LEN];
  actBNDIGIT Curve_tmp0[actECC_MAX_DIGIT_LEN + 1u];
  actBNDIGIT Curve_tmp1[actECC_MAX_DIGIT_LEN + 1u];
  actBNDIGIT Curve_tmp2[actECC_MAX_DIGIT_LEN + 1u];
  actBNDIGIT Curve_tmp3[actECC_MAX_DIGIT_LEN + 1u];
}actECPBasicStruct;

typedef struct{
  actECPBasicStruct baseData;

  union
  {
    actECPTmpVarVerify u12;
    actECPPrivateKeys privKeys;
  } dataPair;

  union
  {
    actBNDIGIT hashed_message[actECC_MAX_N_DIGIT_LEN];
    actBNDIGIT secret_x[actECC_MAX_P_DIGIT_LEN];
  }msg;

  actBNDIGIT signature_r[actECC_MAX_N_DIGIT_LEN];
  actBNDIGIT signature_s[actECC_MAX_N_DIGIT_LEN];
  actBNDIGIT public_key_x[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT public_key_y[actECC_MAX_P_DIGIT_LEN];

  union
  {
    actECPprojectivePointBuffer kG;
    actECPprojectivePointBuffer QG;
  } multG;

  union
  {
    actECPaffinePointBuffer precomputedPoint;
    actECPaffinePointBuffer basePoint;
  } curvePoint;

  actECPprojectivePointBuffer Q;

}actECPSTRUCT;

typedef struct{
  actECPBasicStruct baseData;

  actECPprojectivePointBuffer M;
  actECPprojectivePointBuffer N;
  actECPprojectivePointBuffer L;
  actECPprojectivePointBuffer pA;
  actECPprojectivePointBuffer pB;
  actECPprojectivePointBuffer Z;
  actECPprojectivePointBuffer V;

  actECPprojectivePointBuffer kG;
  actECPprojectivePointBuffer tmp1;

  union
  {
    actECPprojectivePointBuffer tmp2;
    actU8 hashTT[actHASH_SIZE_SHA256];
  } tmpVariables;

  actECPaffinePointBuffer basePoint;

  actBNDIGIT w0[actECC_MAX_N_DIGIT_LEN];
  actBNDIGIT w1[actECC_MAX_N_DIGIT_LEN];

  actBNDIGIT randomNumber[actECC_MAX_N_DIGIT_LEN];

  actLengthType aadLength;
  actU32 ciphersuite;

  actU8 addInHKDF[16u + actSPAKE2P_MAX_AAD_SIZE];
  actU8 pointToByteString[actECC_MAX_BYTE_LEN];
  actU8 macKeys[2u * actAES128_KEY_SIZE];

  actU8 algoState;
  actU8 setAdditionalInformationWasCalled;
  actU8 isPartyA;
}actSPAKE2PSTRUCT;

typedef struct{
  actECPBasicStruct baseData;

  actECPprojectivePointBuffer L;
  actECPaffinePointBuffer basePoint;

  actBNDIGIT digitsW0[actSPAKE2P_PREAMBLE_WDIGIT_LENGTH + 1u];
  actBNDIGIT digitsW1[actSPAKE2P_PREAMBLE_WDIGIT_LENGTH + 1u];
  actBNDIGIT result[actECC_MAX_N_DIGIT_LEN + 1u];
}actSPAKE2PPreambleStruct;

typedef struct{
  actU32       nECUs;
  actU32       ecuID;
}actECBD;

typedef struct{
  actECBD      bd;

  actECPBasicStruct baseData;

  actBNDIGIT ai[actECC_MAX_N_DIGIT_LEN];
  actBNDIGIT Zi_x[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT Zi_y[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT Zi_z[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT Xi_x[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT Xi_y[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT Xi_z[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT TP_x[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT TP_y[actECC_MAX_P_DIGIT_LEN];
  actBNDIGIT TP_z[actECC_MAX_P_DIGIT_LEN];
}actECBDstruct;

typedef struct{
  actBNDIGIT tempA[BNDIGITS_256];
  actBNDIGIT tempB[BNDIGITS_256];
  actBNDIGIT tempC[BNDIGITS_256];
  actBNDIGIT tempD[BNDIGITS_256];
  actBNDIGIT tempE[BNDIGITS_256];
  actBNDIGIT tempF[BNDIGITS_256];
  actBNDIGIT tempG[BNDIGITS_256];
  actBNDIGIT tempH[BNDIGITS_256];
  actBNDIGIT temp1[BNDIGITS_512];
  actBNDIGIT tempQ[BNDIGITS_256];
}actTempType;

typedef struct{
  actBNDIGIT prime[BNDIGITS_256];
  actBNDIGIT order[BNDIGITS_256];
  actBNDIGIT orderB[BNDIGITS_256 + 1u];

  actBNRING pRing;
  actBNRING qRing;
  actTempType auxVar;
}actCurve25519ws;

typedef struct{
  actU32 instance;
  union
  {
    actSHA512STRUCT sha512;
    actPoint point_A;
    actPoint point_rB;
    actPoint point_sB;
  } shaWs;
  union
  {
    actU8 hashValue[actHASH_SIZE_SHA512];
    actBNDIGIT bnDigit_s;
    actBNDIGIT bnDigit_k;
  } hashBuf;
  actU8 privateKey[actHASH_SIZE_SHA512];
  union
  {
    actU8 publicKey[actEd25519_KEY_SIZE];
    actBNDIGIT bnDigit_a;
  } pubKeyBuf;
  VSECPRIM_P2CONST_PARA(actU8) message;
  actU32 msgLen;
  VSECPRIM_P2CONST_PARA(actU8) context;
  actU32 ctxLen;
  actCurve25519ws coreWS;
}actEd25519STRUCT;

typedef struct{
  actU8 privateKey[actX25519_KEY_SIZE];
  union
  {
    actU8 uCoord[actX25519_KEY_SIZE];
    actBNDIGIT bnDigit_x_1[BNDIGITS_256];
  } basePointBuf;
  actCurve25519ws coreWS;
}actX25519STRUCT;

typedef actX25519STRUCT actX25519Struct;
typedef actEd25519STRUCT actEd25519Struct;

typedef struct{
# if defined ACT_PLATFORM_UINT64_AVAILABLE
  actU64 v0;
  actU64 v1;
  actU64 v2;
  actU64 v3;
# endif
  actU8 buffer[actSIPHASH_BLOCK_SIZE];
  actU32 length;
  actU8 buffer_used;
}actSipHashSTRUCT;

typedef struct{
  actLengthType buffer_used;
  actU8 buffer[actGHASH_BLOCK_SIZE];
  actU32 H[actGHASH_WORDS_PER_BLOCK];
  actU8 Y[actGHASH_BLOCK_SIZE];
# if(actGHASH_SPEED_UP >= 4)
  actU32 M[256][4];
# elif(actGHASH_SPEED_UP >= 1)
  actU32 M[16][4];
# endif
}actGHASHSTRUCT;

typedef struct{
  actAESSTRUCT aes;
  actGHASHSTRUCT ghash;
  actU8 J0[actGCM_BLOCK_SIZE];
  actU8 J[actGCM_BLOCK_SIZE];
  actU8 encJ[actGCM_BLOCK_SIZE];
  actLengthType buffer_used;
  actU8 buffer[actGCM_BLOCK_SIZE];
  uint8 state;
  actU32 count[4];
}actGCMSTRUCT;

typedef struct{
  actAESSTRUCT wsAES;
  actLengthType aadLen;
  actLengthType msgLen;
  actLengthType remainingLen;
  actU8 AESCounter[actAES_BLOCK_SIZE];
  actU8 dataBlockB[actAES_BLOCK_SIZE];
  actU8 dataBlockIn[actAES_BLOCK_SIZE];
  actU8 dataBlockOut[actAES_BLOCK_SIZE];
  actU8 MAC[actAES_BLOCK_SIZE];
  actU8 nonce[actAES_BLOCK_SIZE - 1u];
  actU8 authFieldSize;
  actU8 lengthFieldSize;
  actU8 updateState;
}actAESCCMSTRUCT;

typedef struct{
  actBNDIGIT cipher[actRSA_MAX_KEY_SIZE_IN_DIGIT];
  actBNDIGIT message[actRSA_MAX_KEY_SIZE_IN_DIGIT + 1u];
}actRSACipherAndMSgStruct;

typedef struct{
  actBNRING  wsRSARing;

  union
  {
    actBNDIGIT tmpInit[(2u*actRSA_MAX_KEY_SIZE_IN_DIGIT) + 2u];
    actRSACipherAndMSgStruct cipherAndMsg;
  } tmp;

  actBNDIGIT RRBuffer[actRSA_MAX_KEY_SIZE_IN_DIGIT + 1u];
  actBNDIGIT exponent[actRSA_MAX_KEY_SIZE_IN_DIGIT];
  actBNDIGIT modulusBuffer[actRSA_MAX_KEY_SIZE_IN_DIGIT];
  actBNDIGIT tmpExp[actRSA_MAX_KEY_SIZE_IN_DIGIT + 1u];

}actRSAPRIMSTRUCT;

typedef struct{
    actBNDIGIT primeP[actRSA_CRT_PRIME_SIZE];
    actBNDIGIT primeQ[actRSA_CRT_PRIME_SIZE];
    actBNDIGIT primeDP[actRSA_CRT_PRIME_SIZE];
    actBNDIGIT primeDQ[actRSA_CRT_PRIME_SIZE];
    actBNDIGIT qInv[actRSA_CRT_PRIME_SIZE];
    actBNDIGIT one[actRSA_CRT_PRIME_SIZE];
}actCRTINITSTRUCT;

typedef struct{
  actBNDIGIT origCipherBeforeReduction[actRSA_MAX_KEY_SIZE_IN_DIGIT + 1u];
  actU8 reducedCipherInBytes[actRSA_CRT_PRIME_SIZE * actBN_BYTES_PER_DIGIT];
  actBNDIGIT reducedCipherInDigits[actRSA_CRT_PRIME_SIZE + 1u];
}actCRTCIPHERSTRUCT;

typedef struct{
  actBNDIGIT m1[actRSA_CRT_PRIME_SIZE];
  actBNDIGIT m2[actRSA_CRT_PRIME_SIZE + 1u];
}actCRTMSGSTRUCT;

typedef struct{
  actBNDIGIT m2Copy[actRSA_CRT_PRIME_SIZE + 1u];
  actBNDIGIT m2ModP[actRSA_CRT_PRIME_SIZE + 1u];
  actBNDIGIT m1m2[actRSA_CRT_PRIME_SIZE];
  actBNDIGIT qInv[actRSA_CRT_PRIME_SIZE];
  actBNDIGIT qInvM1M2R[actRSA_CRT_PRIME_SIZE + 1u];
  actBNDIGIT qInvM1M2[actRSA_CRT_PRIME_SIZE + 1u];
}actCRTSTEP3STRUCT;

typedef struct{
  actBNDIGIT m2Padded[actRSA_MAX_KEY_SIZE_IN_DIGIT];
  actBNDIGIT primeQ[actRSA_CRT_PRIME_SIZE];
  actBNDIGIT qInvM1M2q[2u* actRSA_CRT_PRIME_SIZE];
  actBNDIGIT msg[actRSA_MAX_KEY_SIZE_IN_DIGIT];
}actCRTSTEP4STRUCT;

typedef struct{
  union
  {
    actRSAPRIMSTRUCT wsRSAPrim;
    actCRTINITSTRUCT wsCRTInit;
    actCRTSTEP4STRUCT wsCRTSTEP4;
  } wsUnion1;

  union
  {
    actCRTCIPHERSTRUCT wsCRTCipherOperations;
    actCRTSTEP3STRUCT wsCRTStep3;
  } wsUnion2;

  union
  {
    actCRTMSGSTRUCT messages;
    actBNDIGIT fullModulus[2u * actRSA_CRT_PRIME_SIZE];
  } keySizeBuffer;

  actLengthType p_bytes;
  actLengthType q_bytes;
  actLengthType dp_bytes;
  actLengthType dq_bytes;
  actLengthType q_inv_bytes;
  actLengthType n_bytes;

  VSECPRIM_P2CONST_PARA(actU8) p;
  VSECPRIM_P2CONST_PARA(actU8) q;
  VSECPRIM_P2CONST_PARA(actU8) dp;
  VSECPRIM_P2CONST_PARA(actU8) dq;
  VSECPRIM_P2CONST_PARA(actU8) q_inv;

}actRSACRTSTRUCT;

#endif

