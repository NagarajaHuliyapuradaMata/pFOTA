#if !defined (MCALCRY_CFG_H)
#define MCALCRY_CFG_H

#include "Types_SwcServiceCsm.hpp"
#include "ESLib.hpp"

#ifndef MCALCRY_USE_DUMMY_STATEMENT
#define MCALCRY_USE_DUMMY_STATEMENT STD_ON
#endif
#ifndef MCALCRY_DUMMY_STATEMENT
#define MCALCRY_DUMMY_STATEMENT(v) (v)=(v)
#endif
#ifndef MCALCRY_DUMMY_STATEMENT_CONST
#define MCALCRY_DUMMY_STATEMENT_CONST(v) (void)(v)
#endif
#ifndef MCALCRY_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define MCALCRY_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF
#endif
#ifndef MCALCRY_ATOMIC_VARIABLE_ACCESS
#define MCALCRY_ATOMIC_VARIABLE_ACCESS 8u
#endif
#ifndef MCALCRY_PROCESSOR_RH850_1013
#define MCALCRY_PROCESSOR_RH850_1013
#endif
#ifndef MCALCRY_COMP_GREENHILLS
#define MCALCRY_COMP_GREENHILLS
#endif
#ifndef MCALCRY_GEN_GENERATOR_MSR
#define MCALCRY_GEN_GENERATOR_MSR
#endif
#ifndef MCALCRY_CPUTYPE_BITORDER_LSB2MSB
#define MCALCRY_CPUTYPE_BITORDER_LSB2MSB
#endif
#ifndef MCALCRY_CONFIGURATION_VARIANT_PRECOMPILE
#define MCALCRY_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef MCALCRY_CONFIGURATION_VARIANT_LINKTIME
#define MCALCRY_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef MCALCRY_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define MCALCRY_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef MCALCRY_CONFIGURATION_VARIANT
#define MCALCRY_CONFIGURATION_VARIANT MCALCRY_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef MCALCRY_POSTBUILD_VARIANT_SUPPORT
#define MCALCRY_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#define MCALCRY_VERSION_INFO_API                                                            STD_OFF
#define MCALCRY_USE_VSTD_LIB                                                                STD_ON
#define MCALCRY_KEY_ELEMENT_DELETE                                                          STD_OFF
#define MCALCRY_ALIGN_KEY_STORAGE                                                           STD_OFF
#define MCALCRY_NV_MENABLE_SET_RAM_BLOCK_STATUS                                             STD_OFF
#define MCALCRY_REDIRECTION                                                                 STD_OFF
#define MCALCRY_DEFAULT_RANDOM_MAX_RETRIES                                                  10u
#define MCALCRY_NUMBER_OF_LONG_TERM_PRIMITIVE_WORKSPACE                                     0u
#define MCALCRY_CMAC_AES_ROUNDKEY_REUSE                                                     STD_OFF
#define MCALCRY_ENABLE_AES256                                                               STD_OFF
#define MCALCRY_KEY_GENERATE_MAX_LENGTH                                                     32u
#define MCALCRY_SHE_ENABLE_FID                                                              STD_ON
#define MCALCRY_SHE_ENABLE_COUNTER                                                          STD_ON
#define MCALCRY_SHE_DEBUG_CMD                                                               STD_OFF
#define MCALCRY_SHE_KEY_UPDATE                                                              STD_OFF
#define MCALCRY_NV_MANAGEMENT_DATA_PER_KEY                                                  4u

#define CryptoConf_CryptoDriverObject_McalCry_Aes                                           0u
#define CryptoConf_CryptoDriverObject_McalCry                                               1u
#define CryptoConf_CryptoKeyElement_McalCry_Aead_ChaCha_Key                                 1u
#define CryptoConf_CryptoKeyElement_McalCry_Cipher_Key                                      1u
#define CryptoConf_CryptoKeyElement_McalCry_Cipher_Key_She                                  1u
#define CryptoConf_CryptoKeyElement_McalCry_Cipher_Key_She_Ram                              1u
#define CryptoConf_CryptoKeyElement_McalCry_Fbl_Decrypt_Aes128_Key                          1u
#define CryptoConf_CryptoKeyElement_McalCry_Fbl_Signature_ClassC                            1u
#define CryptoConf_CryptoKeyElement_McalCry_Fbl_Signature_Ed25519                           1u
#define CryptoConf_CryptoKeyElement_McalCry_Hash_Result                                     1u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Password                          1u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_SharedValue                         1u
#define CryptoConf_CryptoKeyElement_McalCry_KeyGenerate_Key                                 1u
#define CryptoConf_CryptoKeyElement_McalCry_Mac_Key                                         1u
#define CryptoConf_CryptoKeyElement_McalCry_Mac_Key_She                                     1u
#define CryptoConf_CryptoKeyElement_McalCry_Mac_Key_She_Ram                                 1u
#define CryptoConf_CryptoKeyElement_McalCry_Signature_Key                                   1u
#define CryptoConf_CryptoKeyElement_McalCry_Mac_Proof                                       2u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Seed                                     3u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Seed_Nist_800_90A_DRBG_AES128            3u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Seed_Nist_800_90A_DRBG_AES256            3u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Seed_Nist_800_90A_DRBG_HASH_SHA2_512     3u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Algorithm                                4u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Algorithm_Fips186_Sha1                   4u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Algorithm_Nist_800_90A_DRBG_AES128       4u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF    4u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Algorithm_Nist_800_90A_DRBG_AES256       4u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Algorithm_Nist_800_90A_DRBG_AES256Df     4u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Algorithm_Nist_800_90A_DRBG_HASH_SHA2_512 4u
#define CryptoConf_CryptoKeyElement_McalCry_Aead_ChaCha_Nonce                               5u
#define CryptoConf_CryptoKeyElement_McalCry_Cipher_IV                                       5u
#define CryptoConf_CryptoKeyElement_McalCry_Fbl_Decrypt_Aes128_IV                           5u
#define CryptoConf_CryptoKeyElement_McalCry_Cipher_Proof                                    6u
#define CryptoConf_CryptoKeyElement_McalCry_Cipher_2NDKey                                   7u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_Base                                8u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_PrivKey                             9u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_OwnPubKey                           10u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_Algorithm_ANSIP256R1                12u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_Algorithm_NISTP224R1_BD             12u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_Algorithm_SECP256R1                 12u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_Algorithm_SECP384R1                 12u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_Algorithm_Spake2Plus_Suite8         12u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_Algorithm_Spake2Plus_Suite8_1       12u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_Algorithm_X25519                    12u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Salt                              13u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Iterations_HKDF                   14u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Iterations_PBKDF2                 14u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Algorithm_ASM_NISTFIPS1864        15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Algorithm_HKDF_HMAC_SHA256        15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Algorithm_HKDF_Option1_SHA256     15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Algorithm_ISO15118                15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Algorithm_KDF_X963_SHA256         15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Algorithm_KDF_X963_SHA512         15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Algorithm_NIST80056A              15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Algorithm_PBKDF2_HMAC_SHA1        15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Algorithm_PBKDF2_HMAC_SHA256      15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Algorithm_SYM_NIST800108          15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Algorithm_Spake2Plus_P256R1       15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerive_Algorithm                             15u
#define CryptoConf_CryptoKeyElement_McalCry_KeyGenerate_Seed                                16u
#define CryptoConf_CryptoKeyElement_McalCry_KeyGenerate_Algorithm                           17u
#define CryptoConf_CryptoKeyElement_McalCry_KeyGenerate_Algorithm_Ansi_Nist_Sec_P256R1      17u
#define CryptoConf_CryptoKeyElement_McalCry_KeyGenerate_Algorithm_Ed25519                   17u
#define CryptoConf_CryptoKeyElement_McalCry_KeyGenerate_Algorithm_Nist_Sec_P384R1           17u
#define CryptoConf_CryptoKeyElement_McalCry_KeyGenerate_Algorithm_Symmetric_Generic         17u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_Label                             130u
#define CryptoConf_CryptoKeyElement_McalCry_AdditionalInfo                                  131u
#define CryptoConf_CryptoKeyElement_McalCry_KeyDerivation_AdditionalInfo                    131u
#define CryptoConf_CryptoKeyElement_McalCry_Fbl_Signature_Rsa1024_Mod                       160u
#define CryptoConf_CryptoKeyElement_McalCry_Fbl_Signature_Rsa2048_Mod                       160u
#define CryptoConf_CryptoKeyElement_McalCry_Fbl_Signature_Rsa3072_Mod                       160u
#define CryptoConf_CryptoKeyElement_McalCry_Rsa_Modulus                                     160u
#define CryptoConf_CryptoKeyElement_McalCry_Fbl_Signature_Rsa1024_Exp                       161u
#define CryptoConf_CryptoKeyElement_McalCry_Fbl_Signature_Rsa2048_Exp                       161u
#define CryptoConf_CryptoKeyElement_McalCry_Fbl_Signature_Rsa3072_Exp                       161u
#define CryptoConf_CryptoKeyElement_McalCry_Rsa_Pub_Exponent                                161u
#define CryptoConf_CryptoKeyElement_McalCry_Rsa_Priv_Exponent                               162u
#define CryptoConf_CryptoKeyElement_McalCry_Rsa_Salt                                        163u
#define CryptoConf_CryptoKeyElement_McalCry_Rsa_SaltLength                                  164u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_PartnerPubKey                       3003u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_PartnerPubKey_2                     3004u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_Intermediate                        3005u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_NumEcu                              3006u
#define CryptoConf_CryptoKeyElement_McalCry_KeyExchange_EcuId                               3007u
#define CryptoConf_CryptoKeyElement_McalCry_SCC_Contract_PubKey                             3013u
#define CryptoConf_CryptoKeyElement_McalCry_SCC_IV_And_Encrypted_PrivKey                    3014u
#define CryptoConf_CryptoKeyElement_McalCry_Random_PrivateString                            3015u
#define CryptoConf_CryptoKeyElement_McalCry_Random_AdditionalInput                          3016u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Nonce                                    3017u
#define CryptoConf_CryptoKeyElement_McalCry_Random_Reseed_Counter                           3018u
#define CryptoConf_CryptoKeyElement_McalCry_She_Counter                                     3019u
#define CryptoConf_CryptoKeyElement_McalCry_She_UId                                         3021u
#define CryptoConf_CryptoKeyElement_McalCry_Rsa_PrimeP                                      3051u
#define CryptoConf_CryptoKeyElement_McalCry_Rsa_PrimeQ                                      3052u
#define CryptoConf_CryptoKeyElement_McalCry_Rsa_ExponentDp                                  3053u
#define CryptoConf_CryptoKeyElement_McalCry_Rsa_ExponentDq                                  3054u
#define CryptoConf_CryptoKeyElement_McalCry_Rsa_InverseQi                                   3055u
#define CryptoConf_CryptoKeyElement_McalCry_She_BootProtection                              3056u
#define CryptoConf_CryptoKeyElement_McalCry_She_DebuggerProtection                          3057u
#define CryptoConf_CryptoKeyElement_McalCry_Label                                           3058u
#define CryptoConf_CryptoKeyElement_McalCry_W0                                              3084u
#define CryptoConf_CryptoKeyElement_McalCry_W1                                              3085u
#define CryptoConf_CryptoKeyElement_McalCry_L                                               3086u
#define CryptoConf_CryptoKeyElement_McalCry_Verification                                    3087u
#define CryptoConf_CryptoKeyElement_McalCry_Verification_Result                             3088u
#define CryptoConf_CryptoKey_CryptoKey_Fbl_Decrypt_Aes128                                           0u
#define CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Class_C                                        1u
#define CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Ed25519                                        2u
#define CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Rsa1024                                        3u
#define CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Rsa2048                                        4u
#define CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Rsa3072                                        5u
#define CryptoConf_CryptoKey_CryptoKey_Fbl_HashDummy                                                6u

#define MCALCRY_NV_PROCESSING_DEFERRED                                                      0x00u
#define MCALCRY_NV_PROCESSING_IMMEDIATE                                                     0x01u
#define MCALCRY_NV_CONSISTENCY_LEVEL_DETECT                                                 0x00u
#define MCALCRY_NV_CONSISTENCY_LEVEL_NONE                                                   0x01u

#define MCALCRY_RAM_KEY_EXPORT                                                              STD_OFF

#define MCALCRYPERSIST_SIZE                                                                 0
#ifndef MCALCRY_DEV_ERROR_DETECT
#define MCALCRY_DEV_ERROR_DETECT STD_ON
#endif
#ifndef MCALCRY_DEV_ERROR_REPORT
#define MCALCRY_DEV_ERROR_REPORT STD_ON
#endif

#define MCALCRY_SERVICE_AEADDECRYPT                                                         STD_OFF
#define MCALCRY_SERVICE_AEADENCRYPT                                                         STD_OFF
#define MCALCRY_SERVICE_CERIFICATE_PARSE                                                    STD_OFF
#define MCALCRY_SERVICE_CERTIFICATE_VERIFY                                                  STD_OFF
#define MCALCRY_SERVICE_DECRYPT                                                             STD_ON
#define MCALCRY_SERVICE_ENCRYPT                                                             STD_OFF
#define MCALCRY_SERVICE_HASH                                                                STD_ON
#define MCALCRY_SERVICE_KEY_DERIVE                                                          STD_OFF
#define MCALCRY_SERVICE_KEY_EXCHANGE_CALC_PUBVAL                                            STD_OFF
#define MCALCRY_SERVICE_KEY_EXCHANGE_CALC_SECRET                                            STD_OFF
#define MCALCRY_SERVICE_KEY_GENERATE                                                        STD_OFF
#define MCALCRY_SERVICE_KEY_SET_VALID                                                       STD_OFF
#define MCALCRY_SERVICE_MAC_GENERATE                                                        STD_OFF
#define MCALCRY_SERVICE_MAC_VERIFY                                                          STD_ON
#define MCALCRY_SERVICE_RANDOM                                                              STD_OFF
#define MCALCRY_SERVICE_RANDOM_SEED                                                         STD_OFF
#define MCALCRY_SERVICE_SIGNATURE_GENERATE                                                  STD_OFF
#define MCALCRY_SERVICE_SIGNATURE_VERIFY                                                    STD_ON

#define MCALCRY_RA_ALLOWED                                                                  0x00u
#define MCALCRY_RA_ENCRYPTED                                                                0x01u
#define MCALCRY_RA_INTERNAL_COPY                                                            0x02u
#define MCALCRY_RA_DENIED                                                                   0x03u
#define MCALCRY_WA_ALLOWED                                                                  0x00u
#define MCALCRY_WA_ENCRYPTED                                                                0x01u
#define MCALCRY_WA_INTERNAL_COPY                                                            0x02u
#define MCALCRY_WA_DENIED                                                                   0x03u

#define MCALCRY_KEY_DERIVE_ALGORITHM                                                        STD_OFF
#define MCALCRY_KDF_ALGO_ASYM_NIST_FIPS_186_4_ERB_ENABLED                                   STD_OFF
#define MCALCRY_KDF_ALGO_SYM_NIST_800_108_CNT_MODE_SHA256_ENABLED                           STD_OFF
#define MCALCRY_KDF_ALGO_ISO_15118_CERTIFICATE_HANDLING_ENABLED                             STD_OFF
#define MCALCRY_KDF_ALGO_NIST_800_56_A_ONE_PASS_C1E1S_SINGLE_STEP_KDF_SHA256_ENABLED        STD_OFF
#define MCALCRY_KDF_ALGO_X963_SHA256_ENABLED                                                STD_OFF
#define MCALCRY_KDF_ALGO_PBKDF2_HMAC_SHA1_ENABLED                                           STD_OFF
#define MCALCRY_KDF_ALGO_PBKDF2_HMAC_SHA256_ENABLED                                         STD_OFF
#define MCALCRY_KDF_ALGO_X963_SHA512_ENABLED                                                STD_OFF
#define MCALCRY_KDF_ALGO_HKDF_HMAC_SHA256_ENABLED                                           STD_OFF
#define MCALCRY_KDF_ALGO_SPAKE2_PLUS_P256R1_ENABLED                                         STD_OFF
#define MCALCRY_KDF_ALGO_HKDF_OPTION1_SHA256_ENABLED                                        STD_OFF

#define MCALCRY_KEY_EXCHANGE_ALGORITHM                                                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_ALGORITHM_X25519_ENABLED                                       STD_OFF
#define MCALCRY_KEY_EXCHANGE_ALGORITHM_ANSIP256R1_ENABLED                                   STD_OFF
#define MCALCRY_KEY_EXCHANGE_ALGORITHM_SECP256R1_ENABLED                                    STD_OFF
#define MCALCRY_KEY_EXCHANGE_ALGORITHM_SECP384R1_ENABLED                                    STD_OFF
#define MCALCRY_KEY_EXCHANGE_ALGORITHM_SPAKE2_PLUS_CIPHERSUITE_8_ENABLED                    STD_OFF
#define MCALCRY_KEY_EXCHANGE_ALGORITHM_NISTP224R1_BD_ENABLED                                STD_OFF

#define MCALCRY_KEY_GENERATE_ALGORITHM                                                      STD_OFF
#define MCALCRY_KEY_GENERATE_ALGORITHM_SYMMETRIC_GENERIC_ENABLED                            STD_OFF
#define MCALCRY_KEY_GENERATE_ALGORITHM_ANSI_NIST_SEC_P256R1_ENABLED                         STD_OFF
#define MCALCRY_KEY_GENERATE_ALGORITHM_NIST_SEC_P384R1_ENABLED                              STD_OFF
#define MCALCRY_KEY_GENERATE_ALGORITHM_ED25519_ENABLED                                      STD_OFF

#define MCALCRY_VSEC_PRIM_ESLT_LENGTH_32                                                    STD_ON

#define MCALCRY_AEADDECRYPT_AES                                                             STD_OFF
#define MCALCRY_AEADDECRYPT_AES_CUSTOM_CCM_NOT_SET                                          STD_OFF
#define MCALCRY_AEADDECRYPT_AES_GCM_NOT_SET                                                 STD_OFF
#define MCALCRY_AEADDECRYPT_CHACHA                                                          STD_OFF
#define MCALCRY_AEADDECRYPT_CHACHA_20ROUNDS_CUSTOM_POLY_1305                                STD_OFF
#define MCALCRY_AEADDECRYPT_SECFAM_CUSTOM_POLY_1305                                         STD_OFF
#define MCALCRY_AEADDECRYPT_SECFAM_NOT_SET                                                  STD_OFF
#define MCALCRY_AEADENCRYPT_AES                                                             STD_OFF
#define MCALCRY_AEADENCRYPT_AES_CUSTOM_CCM_NOT_SET                                          STD_OFF
#define MCALCRY_AEADENCRYPT_AES_GCM_NOT_SET                                                 STD_OFF
#define MCALCRY_AEADENCRYPT_CHACHA                                                          STD_OFF
#define MCALCRY_AEADENCRYPT_CHACHA_20ROUNDS_CUSTOM_POLY_1305                                STD_OFF
#define MCALCRY_AEADENCRYPT_SECFAM_CUSTOM_POLY_1305                                         STD_OFF
#define MCALCRY_AEADENCRYPT_SECFAM_NOT_SET                                                  STD_OFF
#define MCALCRY_DECRYPT_AES                                                                 STD_ON
#define MCALCRY_DECRYPT_AES_CBC_CUSTOM_PADDING_PKCS7                                        STD_ON
#define MCALCRY_DECRYPT_AES_CBC_NOT_SET                                                     STD_ON
#define MCALCRY_DECRYPT_AES_CBC_PADDING_ONEWITHZEROS                                        STD_ON
#define MCALCRY_DECRYPT_AES_CBC_PADDING_PKCS7                                               STD_OFF
#define MCALCRY_DECRYPT_AES_CTR_CUSTOM_PADDING_PKCS7                                        STD_ON
#define MCALCRY_DECRYPT_AES_CTR_NOT_SET                                                     STD_ON
#define MCALCRY_DECRYPT_AES_CTR_PADDING_ONEWITHZEROS                                        STD_ON
#define MCALCRY_DECRYPT_AES_CTR_PADDING_PKCS7                                               STD_OFF
#define MCALCRY_DECRYPT_AES_ECB_CUSTOM_PADDING_PKCS7                                        STD_ON
#define MCALCRY_DECRYPT_AES_ECB_NOT_SET                                                     STD_ON
#define MCALCRY_DECRYPT_AES_ECB_PADDING_ONEWITHZEROS                                        STD_ON
#define MCALCRY_DECRYPT_AES_ECB_PADDING_PKCS7                                               STD_OFF
#define MCALCRY_DECRYPT_RSA                                                                 STD_OFF
#define MCALCRY_DECRYPT_RSA_CUSTOM_RSAES_OAEP_CRT_SHA1                                      STD_OFF
#define MCALCRY_DECRYPT_RSA_CUSTOM_RSAES_OAEP_CRT_SHA2_256                                  STD_OFF
#define MCALCRY_DECRYPT_RSA_RSAES_OAEP_SHA1                                                 STD_OFF
#define MCALCRY_DECRYPT_RSA_RSAES_OAEP_SHA2_256                                             STD_OFF
#define MCALCRY_DECRYPT_RSA_RSAES_PKCS1_v1_5_NOT_SET                                        STD_OFF
#define MCALCRY_DECRYPT_SECFAM_CUSTOM_PADDING_PKCS7                                         STD_ON
#define MCALCRY_DECRYPT_SECFAM_NOT_SET                                                      STD_ON
#define MCALCRY_DECRYPT_SECFAM_PADDING_ONEWITHZEROS                                         STD_ON
#define MCALCRY_DECRYPT_SECFAM_PADDING_PKCS7                                                STD_OFF
#define MCALCRY_DECRYPT_SECFAM_SHA1                                                         STD_OFF
#define MCALCRY_DECRYPT_SECFAM_SHA2_256                                                     STD_OFF
#define MCALCRY_ENCRYPT_AES                                                                 STD_OFF
#define MCALCRY_ENCRYPT_AES_CBC_CUSTOM_PADDING_PKCS7                                        STD_OFF
#define MCALCRY_ENCRYPT_AES_CBC_NOT_SET                                                     STD_OFF
#define MCALCRY_ENCRYPT_AES_CBC_PADDING_ONEWITHZEROS                                        STD_OFF
#define MCALCRY_ENCRYPT_AES_CBC_PADDING_PKCS7                                               STD_OFF
#define MCALCRY_ENCRYPT_AES_CTR_CUSTOM_PADDING_PKCS7                                        STD_OFF
#define MCALCRY_ENCRYPT_AES_CTR_NOT_SET                                                     STD_OFF
#define MCALCRY_ENCRYPT_AES_CTR_PADDING_ONEWITHZEROS                                        STD_OFF
#define MCALCRY_ENCRYPT_AES_CTR_PADDING_PKCS7                                               STD_OFF
#define MCALCRY_ENCRYPT_AES_ECB_CUSTOM_PADDING_PKCS7                                        STD_OFF
#define MCALCRY_ENCRYPT_AES_ECB_NOT_SET                                                     STD_OFF
#define MCALCRY_ENCRYPT_AES_ECB_PADDING_ONEWITHZEROS                                        STD_OFF
#define MCALCRY_ENCRYPT_AES_ECB_PADDING_PKCS7                                               STD_OFF
#define MCALCRY_ENCRYPT_RSA                                                                 STD_OFF
#define MCALCRY_ENCRYPT_RSA_RSAES_OAEP_SHA1                                                 STD_OFF
#define MCALCRY_ENCRYPT_RSA_RSAES_OAEP_SHA2_256                                             STD_OFF
#define MCALCRY_ENCRYPT_RSA_RSAES_PKCS1_v1_5_NOT_SET                                        STD_OFF
#define MCALCRY_ENCRYPT_SECFAM_CUSTOM_PADDING_PKCS7                                         STD_OFF
#define MCALCRY_ENCRYPT_SECFAM_NOT_SET                                                      STD_OFF
#define MCALCRY_ENCRYPT_SECFAM_PADDING_ONEWITHZEROS                                         STD_OFF
#define MCALCRY_ENCRYPT_SECFAM_PADDING_PKCS7                                                STD_OFF
#define MCALCRY_ENCRYPT_SECFAM_SHA1                                                         STD_OFF
#define MCALCRY_ENCRYPT_SECFAM_SHA2_256                                                     STD_OFF
#define MCALCRY_HASH_CUSTOM_MD5                                                             STD_OFF
#define MCALCRY_HASH_CUSTOM_MD5_NOT_SET_NOT_SET                                             STD_OFF
#define MCALCRY_HASH_RIPEMD160                                                              STD_OFF
#define MCALCRY_HASH_RIPEMD160_NOT_SET_NOT_SET                                              STD_OFF
#define MCALCRY_HASH_SECFAM_NOT_SET                                                         STD_ON
#define MCALCRY_HASH_SHA1                                                                   STD_OFF
#define MCALCRY_HASH_SHA1_NOT_SET_NOT_SET                                                   STD_OFF
#define MCALCRY_HASH_SHA2_256                                                               STD_OFF
#define MCALCRY_HASH_SHA2_256_NOT_SET_NOT_SET                                               STD_OFF
#define MCALCRY_HASH_SHA2_384                                                               STD_OFF
#define MCALCRY_HASH_SHA2_384_NOT_SET_NOT_SET                                               STD_OFF
#define MCALCRY_HASH_SHA2_512                                                               STD_ON
#define MCALCRY_HASH_SHA2_512_NOT_SET_NOT_SET                                               STD_ON
#define MCALCRY_HASH_SHA3_256                                                               STD_OFF
#define MCALCRY_HASH_SHA3_256_NOT_SET_NOT_SET                                               STD_OFF
#define MCALCRY_KEY_DERIVE_CUSTOM_FIPS186                                                   STD_OFF
#define MCALCRY_KEY_DERIVE_CUSTOM_FIPS186_NOT_SET_SHA2_256                                  STD_OFF
#define MCALCRY_KEY_DERIVE_CUSTOM_HKDF                                                      STD_OFF
#define MCALCRY_KEY_DERIVE_CUSTOM_HKDF_HMAC_SHA2_256                                        STD_OFF
#define MCALCRY_KEY_DERIVE_CUSTOM_HKDF_NOT_SET_SHA2_256                                     STD_OFF
#define MCALCRY_KEY_DERIVE_CUSTOM_ISO15118                                                  STD_OFF
#define MCALCRY_KEY_DERIVE_CUSTOM_ISO15118_NOT_SET_NOT_SET                                  STD_OFF
#define MCALCRY_KEY_DERIVE_CUSTOM_SPAKE2_PLUS                                               STD_OFF
#define MCALCRY_KEY_DERIVE_CUSTOM_SPAKE2_PLUS_CUSTOM_P256R1_NOT_SET                         STD_OFF
#define MCALCRY_KEY_DERIVE_DH                                                               STD_OFF
#define MCALCRY_KEY_DERIVE_DH_CUSTOM_P256R1_SHA2_256                                        STD_OFF
#define MCALCRY_KEY_DERIVE_FIPS186                                                          STD_OFF
#define MCALCRY_KEY_DERIVE_FIPS186_NOT_SET_SHA2_256                                         STD_OFF
#define MCALCRY_KEY_DERIVE_KDFX963                                                          STD_OFF
#define MCALCRY_KEY_DERIVE_KDFX963_NOT_SET_SHA2_256                                         STD_OFF
#define MCALCRY_KEY_DERIVE_KDFX963_NOT_SET_SHA2_512                                         STD_OFF
#define MCALCRY_KEY_DERIVE_NOT_SET                                                          STD_OFF
#define MCALCRY_KEY_DERIVE_NOT_SET_CTR_SHA2_256                                             STD_OFF
#define MCALCRY_KEY_DERIVE_PBKDF2                                                           STD_OFF
#define MCALCRY_KEY_DERIVE_PBKDF2_HMAC_SHA1                                                 STD_OFF
#define MCALCRY_KEY_DERIVE_PBKDF2_HMAC_SHA2_256                                             STD_OFF
#define MCALCRY_KEY_DERIVE_SECFAM_NOT_SET                                                   STD_OFF
#define MCALCRY_KEY_DERIVE_SECFAM_SHA1                                                      STD_OFF
#define MCALCRY_KEY_DERIVE_SECFAM_SHA2_256                                                  STD_OFF
#define MCALCRY_KEY_DERIVE_SECFAM_SHA2_512                                                  STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCANSI                                     STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET               STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCSEC                                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_SPAKE2_PLUS                                 STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_SPAKE2_PLUS_CUSTOM_MODE_1_CUSTOM_CIPHER_SUITE_8 STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_SPAKE2_PLUS_NOT_SET_CUSTOM_CIPHER_SUITE_8   STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_X25519                                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_X25519_NOT_SET_NOT_SET                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ECCANSI                                            STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ECCANSI_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST                                            STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST_CUSTOM_P224R1_CUSTOM_BD                    STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST_CUSTOM_P384R1_NOT_SET                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC                                             STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC_CUSTOM_P224R1_CUSTOM_BD                     STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC_CUSTOM_P256R1_NOT_SET                       STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC_CUSTOM_P384R1_NOT_SET                       STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ED25519                                            STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_ED25519_NOT_SET_NOT_SET                            STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_SECFAM_CUSTOM_BD                                   STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_SECFAM_CUSTOM_CIPHER_SUITE_8                       STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_PUBVAL_SECFAM_NOT_SET                                     STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCANSI                                     STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET               STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCSEC                                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_CUSTOM_SPAKE2_PLUS                                 STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_CUSTOM_SPAKE2_PLUS_CUSTOM_MODE_1_CUSTOM_CIPHER_SUITE_8 STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_CUSTOM_SPAKE2_PLUS_NOT_SET_CUSTOM_CIPHER_SUITE_8   STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_CUSTOM_X25519                                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_CUSTOM_X25519_NOT_SET_NOT_SET                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_ECCANSI                                            STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_ECCANSI_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_ECCNIST                                            STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_ECCNIST_CUSTOM_P224R1_CUSTOM_BD                    STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_ECCNIST_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_ECCNIST_CUSTOM_P384R1_NOT_SET                      STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_ECCSEC                                             STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_ECCSEC_CUSTOM_P224R1_CUSTOM_BD                     STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_ECCSEC_CUSTOM_P256R1_NOT_SET                       STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_ECCSEC_CUSTOM_P384R1_NOT_SET                       STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_SECFAM_CUSTOM_BD                                   STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_SECFAM_CUSTOM_CIPHER_SUITE_8                       STD_OFF
#define MCALCRY_KEY_EXCHANGE_CALC_SECRET_SECFAM_NOT_SET                                     STD_OFF
#define MCALCRY_KEY_GENERATE_CUSTOM_ECCANSI                                                 STD_OFF
#define MCALCRY_KEY_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET                           STD_OFF
#define MCALCRY_KEY_GENERATE_CUSTOM_ECCSEC                                                  STD_OFF
#define MCALCRY_KEY_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                            STD_OFF
#define MCALCRY_KEY_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                            STD_OFF
#define MCALCRY_KEY_GENERATE_ECCANSI                                                        STD_OFF
#define MCALCRY_KEY_GENERATE_ECCANSI_CUSTOM_P256R1_NOT_SET                                  STD_OFF
#define MCALCRY_KEY_GENERATE_ECCNIST                                                        STD_OFF
#define MCALCRY_KEY_GENERATE_ECCNIST_CUSTOM_P256R1_NOT_SET                                  STD_OFF
#define MCALCRY_KEY_GENERATE_ECCNIST_CUSTOM_P384R1_NOT_SET                                  STD_OFF
#define MCALCRY_KEY_GENERATE_ECCSEC                                                         STD_OFF
#define MCALCRY_KEY_GENERATE_ECCSEC_CUSTOM_P256R1_NOT_SET                                   STD_OFF
#define MCALCRY_KEY_GENERATE_ECCSEC_CUSTOM_P384R1_NOT_SET                                   STD_OFF
#define MCALCRY_KEY_GENERATE_ED25519                                                        STD_OFF
#define MCALCRY_KEY_GENERATE_ED25519_NOT_SET_NOT_SET                                        STD_OFF
#define MCALCRY_KEY_GENERATE_NOT_SET                                                        STD_OFF
#define MCALCRY_KEY_GENERATE_NOT_SET_NOT_SET_NOT_SET                                        STD_OFF
#define MCALCRY_KEY_GENERATE_SECFAM_NOT_SET                                                 STD_OFF
#define MCALCRY_KEY_SET_VALID_NOT_SET                                                       STD_OFF
#define MCALCRY_KEY_SET_VALID_NOT_SET_NOT_SET_NOT_SET                                       STD_OFF
#define MCALCRY_KEY_SET_VALID_SECFAM_NOT_SET                                                STD_OFF
#define MCALCRY_MAC_GENERATE_AES                                                            STD_OFF
#define MCALCRY_MAC_GENERATE_AES_CMAC_CUSTOM_CMD_GET_ID                                     STD_OFF
#define MCALCRY_MAC_GENERATE_AES_CMAC_NOT_SET                                               STD_OFF
#define MCALCRY_MAC_GENERATE_AES_GMAC_NOT_SET                                               STD_OFF
#define MCALCRY_MAC_GENERATE_RIPEMD160                                                      STD_OFF
#define MCALCRY_MAC_GENERATE_RIPEMD160_HMAC_NOT_SET                                         STD_OFF
#define MCALCRY_MAC_GENERATE_SECFAM_CUSTOM_CMD_GET_ID                                       STD_OFF
#define MCALCRY_MAC_GENERATE_SECFAM_NOT_SET                                                 STD_OFF
#define MCALCRY_MAC_GENERATE_SHA1                                                           STD_OFF
#define MCALCRY_MAC_GENERATE_SHA1_HMAC_NOT_SET                                              STD_OFF
#define MCALCRY_MAC_GENERATE_SHA2_256                                                       STD_OFF
#define MCALCRY_MAC_GENERATE_SHA2_256_HMAC_NOT_SET                                          STD_OFF
#define MCALCRY_MAC_GENERATE_SHA2_384                                                       STD_OFF
#define MCALCRY_MAC_GENERATE_SHA2_384_HMAC_NOT_SET                                          STD_OFF
#define MCALCRY_MAC_GENERATE_SIPHASH                                                        STD_OFF
#define MCALCRY_MAC_GENERATE_SIPHASH_SIPHASH_2_4_NOT_SET                                    STD_OFF
#define MCALCRY_MAC_VERIFY_AES                                                              STD_OFF
#define MCALCRY_MAC_VERIFY_AES_CMAC_NOT_SET                                                 STD_OFF
#define MCALCRY_MAC_VERIFY_AES_GMAC_NOT_SET                                                 STD_OFF
#define MCALCRY_MAC_VERIFY_RIPEMD160                                                        STD_OFF
#define MCALCRY_MAC_VERIFY_RIPEMD160_HMAC_NOT_SET                                           STD_OFF
#define MCALCRY_MAC_VERIFY_SECFAM_NOT_SET                                                   STD_ON
#define MCALCRY_MAC_VERIFY_SHA1                                                             STD_ON
#define MCALCRY_MAC_VERIFY_SHA1_HMAC_NOT_SET                                                STD_ON
#define MCALCRY_MAC_VERIFY_SHA2_256                                                         STD_OFF
#define MCALCRY_MAC_VERIFY_SHA2_256_HMAC_NOT_SET                                            STD_OFF
#define MCALCRY_MAC_VERIFY_SHA2_384                                                         STD_OFF
#define MCALCRY_MAC_VERIFY_SHA2_384_HMAC_NOT_SET                                            STD_OFF
#define MCALCRY_MAC_VERIFY_SIPHASH                                                          STD_OFF
#define MCALCRY_MAC_VERIFY_SIPHASH_SIPHASH_2_4_NOT_SET                                      STD_OFF
#define MCALCRY_RANDOM_CUSTOM_DRBG                                                          STD_OFF
#define MCALCRY_RANDOM_CUSTOM_DRBG_CUSTOM_USE_DF_AES                                        STD_OFF
#define MCALCRY_RANDOM_CUSTOM_DRBG_NOT_SET_AES                                              STD_OFF
#define MCALCRY_RANDOM_CUSTOM_DRBG_NOT_SET_SHA2_512                                         STD_OFF
#define MCALCRY_RANDOM_CUSTOM_FIPS186                                                       STD_OFF
#define MCALCRY_RANDOM_CUSTOM_FIPS186_NOT_SET_NOT_SET                                       STD_OFF
#define MCALCRY_RANDOM_CUSTOM_FIPS186_NOT_SET_SHA1                                          STD_OFF
#define MCALCRY_RANDOM_DRBG                                                                 STD_OFF
#define MCALCRY_RANDOM_DRBG_CUSTOM_USE_DF_AES                                               STD_OFF
#define MCALCRY_RANDOM_DRBG_NOT_SET_AES                                                     STD_OFF
#define MCALCRY_RANDOM_DRBG_NOT_SET_SHA2_512                                                STD_OFF
#define MCALCRY_RANDOM_FIPS186                                                              STD_OFF
#define MCALCRY_RANDOM_FIPS186_NOT_SET_NOT_SET                                              STD_OFF
#define MCALCRY_RANDOM_FIPS186_NOT_SET_SHA1                                                 STD_OFF
#define MCALCRY_RANDOM_RNG                                                                  STD_OFF
#define MCALCRY_RANDOM_RNG_CUSTOM_USE_DF_AES                                                STD_OFF
#define MCALCRY_RANDOM_RNG_NOT_SET_AES                                                      STD_OFF
#define MCALCRY_RANDOM_RNG_NOT_SET_NOT_SET                                                  STD_OFF
#define MCALCRY_RANDOM_RNG_NOT_SET_SHA1                                                     STD_OFF
#define MCALCRY_RANDOM_SECFAM_AES                                                           STD_OFF
#define MCALCRY_RANDOM_SECFAM_NOT_SET                                                       STD_OFF
#define MCALCRY_RANDOM_SECFAM_SHA1                                                          STD_OFF
#define MCALCRY_RANDOM_SECFAM_SHA2_512                                                      STD_OFF
#define MCALCRY_RANDOM_SEED_CUSTOM_DRBG                                                     STD_OFF
#define MCALCRY_RANDOM_SEED_CUSTOM_DRBG_CUSTOM_USE_DF_AES                                   STD_OFF
#define MCALCRY_RANDOM_SEED_CUSTOM_DRBG_NOT_SET_AES                                         STD_OFF
#define MCALCRY_RANDOM_SEED_CUSTOM_DRBG_NOT_SET_SHA2_512                                    STD_OFF
#define MCALCRY_RANDOM_SEED_CUSTOM_FIPS186                                                  STD_OFF
#define MCALCRY_RANDOM_SEED_CUSTOM_FIPS186_NOT_SET_NOT_SET                                  STD_OFF
#define MCALCRY_RANDOM_SEED_CUSTOM_FIPS186_NOT_SET_SHA1                                     STD_OFF
#define MCALCRY_RANDOM_SEED_DRBG                                                            STD_OFF
#define MCALCRY_RANDOM_SEED_DRBG_CUSTOM_USE_DF_AES                                          STD_OFF
#define MCALCRY_RANDOM_SEED_DRBG_NOT_SET_AES                                                STD_OFF
#define MCALCRY_RANDOM_SEED_DRBG_NOT_SET_SHA2_512                                           STD_OFF
#define MCALCRY_RANDOM_SEED_FIPS186                                                         STD_OFF
#define MCALCRY_RANDOM_SEED_FIPS186_NOT_SET_NOT_SET                                         STD_OFF
#define MCALCRY_RANDOM_SEED_FIPS186_NOT_SET_SHA1                                            STD_OFF
#define MCALCRY_RANDOM_SEED_RNG                                                             STD_OFF
#define MCALCRY_RANDOM_SEED_RNG_CUSTOM_USE_DF_AES                                           STD_OFF
#define MCALCRY_RANDOM_SEED_RNG_NOT_SET_AES                                                 STD_OFF
#define MCALCRY_RANDOM_SEED_RNG_NOT_SET_NOT_SET                                             STD_OFF
#define MCALCRY_RANDOM_SEED_RNG_NOT_SET_SHA1                                                STD_OFF
#define MCALCRY_RANDOM_SEED_SECFAM_AES                                                      STD_OFF
#define MCALCRY_RANDOM_SEED_SECFAM_NOT_SET                                                  STD_OFF
#define MCALCRY_RANDOM_SEED_SECFAM_SHA1                                                     STD_OFF
#define MCALCRY_RANDOM_SEED_SECFAM_SHA2_512                                                 STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCANSI                                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET                     STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA1                        STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_256                    STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_384                    STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_512                    STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC                                            STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P160R1_NOT_SET                      STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA1                         STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_256                     STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_384                     STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_512                     STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                      STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA1                         STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_256                     STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_384                     STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_512                     STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCANSI                                                  STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_NOT_SET                            STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA1                               STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA2_256                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA2_384                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA2_512                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCNIST                                                  STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_NOT_SET                            STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA1                               STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA2_256                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA2_384                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA2_512                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_NOT_SET                            STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA1                               STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA2_256                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA2_384                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA2_512                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC                                                   STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P160R1_NOT_SET                             STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_NOT_SET                             STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA1                                STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA2_256                            STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA2_384                            STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA2_512                            STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_NOT_SET                             STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA1                                STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA2_256                            STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA2_384                            STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA2_512                            STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ED25519                                                  STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ED25519_NOT_SET_NOT_SET                                  STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_ED25519_NOT_SET_SHA2_512                                 STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_RSA                                                      STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_RSA_CUSTOM_RSASSA_PKCS1_v1_5_CRT_SHA1                    STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_RSA_CUSTOM_RSASSA_PKCS1_v1_5_CRT_SHA2_256                STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_RSA_RSASSA_PKCS1_v1_5_SHA1                               STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_RSA_RSASSA_PKCS1_v1_5_SHA2_256                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_RSA_RSASSA_PSS_SHA1                                      STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_RSA_RSASSA_PSS_SHA2_256                                  STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_SECFAM_NOT_SET                                           STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_SECFAM_SHA1                                              STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_SECFAM_SHA2_256                                          STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_SECFAM_SHA2_384                                          STD_OFF
#define MCALCRY_SIGNATURE_GENERATE_SECFAM_SHA2_512                                          STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCANSI                                             STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET                       STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA1                          STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_256                      STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_384                      STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_512                      STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC                                              STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P160R1_NOT_SET                        STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                        STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA1                           STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_256                       STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_384                       STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_512                       STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                        STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA1                           STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_256                       STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_384                       STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_512                       STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCANSI                                                    STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_NOT_SET                              STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA1                                 STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA2_256                             STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA2_384                             STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA2_512                             STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCNIST                                                    STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_NOT_SET                              STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA1                                 STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA2_256                             STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA2_384                             STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA2_512                             STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_NOT_SET                              STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA1                                 STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA2_256                             STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA2_384                             STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA2_512                             STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC                                                     STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P160R1_NOT_SET                               STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_NOT_SET                               STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA1                                  STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA2_256                              STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA2_384                              STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA2_512                              STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_NOT_SET                               STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA1                                  STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA2_256                              STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA2_384                              STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA2_512                              STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ED25519                                                    STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ED25519_NOT_SET_NOT_SET                                    STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_ED25519_NOT_SET_SHA2_512                                   STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_RSA                                                        STD_ON
#define MCALCRY_SIGNATURE_VERIFY_RSA_RSASSA_PKCS1_v1_5_SHA1                                 STD_ON
#define MCALCRY_SIGNATURE_VERIFY_RSA_RSASSA_PKCS1_v1_5_SHA2_256                             STD_ON
#define MCALCRY_SIGNATURE_VERIFY_RSA_RSASSA_PSS_SHA1                                        STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_RSA_RSASSA_PSS_SHA2_256                                    STD_ON
#define MCALCRY_SIGNATURE_VERIFY_SECFAM_NOT_SET                                             STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_SECFAM_SHA1                                                STD_ON
#define MCALCRY_SIGNATURE_VERIFY_SECFAM_SHA2_256                                            STD_ON
#define MCALCRY_SIGNATURE_VERIFY_SECFAM_SHA2_384                                            STD_OFF
#define MCALCRY_SIGNATURE_VERIFY_SECFAM_SHA2_512                                            STD_OFF
#define MCALCRY_DEFAULT_RANDOM_SOURCE                                                       STD_OFF
#define MCALCRY_RANDOM_SOURCE_DRBG_AES                                                      STD_OFF
#define MCALCRY_RANDOM_SOURCE_DRBG_HASH                                                     STD_OFF

#define MCALCRY_AEADCHACHAPOLY1305DECRYPT                                                   STD_OFF
#define MCALCRY_WORKSPACEOFAEADCHACHAPOLY1305DECRYPT                                        STD_OFF
#define MCALCRY_AEADCHACHAPOLY1305ENCRYPT                                                   STD_OFF
#define MCALCRY_WORKSPACEOFAEADCHACHAPOLY1305ENCRYPT                                        STD_OFF
#define MCALCRY_AESCCMDECRYPT                                                               STD_OFF
#define MCALCRY_WORKSPACEOFAESCCMDECRYPT                                                    STD_OFF
#define MCALCRY_AESCCMENCRYPT                                                               STD_OFF
#define MCALCRY_WORKSPACEOFAESCCMENCRYPT                                                    STD_OFF
#define MCALCRY_AESDECRYPT                                                                  STD_ON
#define MCALCRY_WORKSPACEOFAESDECRYPT                                                       STD_ON
#define MCALCRY_AESENCRYPT                                                                  STD_OFF
#define MCALCRY_WORKSPACEOFAESENCRYPT                                                       STD_OFF
#define MCALCRY_AESGCMDECRYPT                                                               STD_OFF
#define MCALCRY_WORKSPACEOFAESGCMDECRYPT                                                    STD_OFF
#define MCALCRY_AESGCMENCRYPT                                                               STD_OFF
#define MCALCRY_WORKSPACEOFAESGCMENCRYPT                                                    STD_OFF
#define MCALCRY_ALIGNKEYSTORAGEOFGENERAL                                                    STD_ON
#define MCALCRY_BUFFERLENGTH                                                                STD_ON
#define MCALCRY_CMACAESGENERATE                                                             STD_OFF
#define MCALCRY_WORKSPACEOFCMACAESGENERATE                                                  STD_OFF
#define MCALCRY_CMACAESROUNDKEYREUSEOFMACPRIMITIVES                                         STD_ON
#define MCALCRY_CMACAESVERIFY                                                               STD_OFF
#define MCALCRY_WORKSPACEOFCMACAESVERIFY                                                    STD_OFF
#define MCALCRY_DRBGAES                                                                     STD_OFF
#define MCALCRY_WORKSPACEOFDRBGAES                                                          STD_OFF
#define MCALCRY_DRBGHASHSHA512                                                              STD_OFF
#define MCALCRY_WORKSPACEOFDRBGHASHSHA512                                                   STD_OFF
#define MCALCRY_DEFAULTRANDOMMAXRETRIESOFGENERAL                                            STD_ON
#define MCALCRY_DRIVEROBJECTSTATE                                                           STD_ON
#define MCALCRY_ECP160GENERATE                                                              STD_OFF
#define MCALCRY_WORKSPACEOFECP160GENERATE                                                   STD_OFF
#define MCALCRY_ECP160VERIFY                                                                STD_OFF
#define MCALCRY_WORKSPACEOFECP160VERIFY                                                     STD_OFF
#define MCALCRY_ECP256GENERATE                                                              STD_OFF
#define MCALCRY_WORKSPACEOFECP256GENERATE                                                   STD_OFF
#define MCALCRY_ECP256VERIFY                                                                STD_OFF
#define MCALCRY_WORKSPACEOFECP256VERIFY                                                     STD_OFF
#define MCALCRY_ECP384GENERATE                                                              STD_OFF
#define MCALCRY_WORKSPACEOFECP384GENERATE                                                   STD_OFF
#define MCALCRY_ECP384VERIFY                                                                STD_OFF
#define MCALCRY_WORKSPACEOFECP384VERIFY                                                     STD_OFF
#define MCALCRY_ED25519GENERATE                                                             STD_OFF
#define MCALCRY_WORKSPACEOFED25519GENERATE                                                  STD_OFF
#define MCALCRY_ED25519VERIFY                                                               STD_OFF
#define MCALCRY_WORKSPACEOFED25519VERIFY                                                    STD_OFF
#define MCALCRY_ENABLEAES256OFCIPHERPRIMITIVES                                              STD_ON
#define MCALCRY_EXPECTEDCOMPATIBILITYVERSION                                                STD_OFF
#define MCALCRY_FINALMAGICNUMBER                                                            STD_OFF
#define MCALCRY_FIPS186                                                                     STD_OFF
#define MCALCRY_WORKSPACEOFFIPS186                                                          STD_OFF
#define MCALCRY_GENERATORCOMPATIBILITYVERSION                                               STD_OFF
#define MCALCRY_GMACAESGENERATE                                                             STD_OFF
#define MCALCRY_WORKSPACEOFGMACAESGENERATE                                                  STD_OFF
#define MCALCRY_GMACAESVERIFY                                                               STD_OFF
#define MCALCRY_WORKSPACEOFGMACAESVERIFY                                                    STD_OFF
#define MCALCRY_HMACRIPEMD160GENERATE                                                       STD_OFF
#define MCALCRY_WORKSPACEOFHMACRIPEMD160GENERATE                                            STD_OFF
#define MCALCRY_HMACRIPEMD160VERIFY                                                         STD_OFF
#define MCALCRY_WORKSPACEOFHMACRIPEMD160VERIFY                                              STD_OFF
#define MCALCRY_HMACSHA1GENERATE                                                            STD_OFF
#define MCALCRY_WORKSPACEOFHMACSHA1GENERATE                                                 STD_OFF
#define MCALCRY_HMACSHA1VERIFY                                                              STD_ON
#define MCALCRY_WORKSPACEOFHMACSHA1VERIFY                                                   STD_ON
#define MCALCRY_HMACSHA256GENERATE                                                          STD_OFF
#define MCALCRY_WORKSPACEOFHMACSHA256GENERATE                                               STD_OFF
#define MCALCRY_HMACSHA256VERIFY                                                            STD_OFF
#define MCALCRY_WORKSPACEOFHMACSHA256VERIFY                                                 STD_OFF
#define MCALCRY_HMACSHA384GENERATE                                                          STD_OFF
#define MCALCRY_WORKSPACEOFHMACSHA384GENERATE                                               STD_OFF
#define MCALCRY_HMACSHA384VERIFY                                                            STD_OFF
#define MCALCRY_WORKSPACEOFHMACSHA384VERIFY                                                 STD_OFF
#define MCALCRY_INITDATAHASHCODE                                                            STD_OFF
#define MCALCRY_INITVALUE                                                                   STD_OFF
#define MCALCRY_KEY                                                                         STD_ON
#define MCALCRY_KEYELEMENTSENDIDXOFKEY                                                      STD_ON
#define MCALCRY_KEYELEMENTSSTARTIDXOFKEY                                                    STD_ON
#define MCALCRY_NVBLOCKIDXOFKEY                                                             STD_OFF
#define MCALCRY_NVBLOCKUSEDOFKEY                                                            STD_OFF
#define MCALCRY_KEYDERIVEHKDFHMACSHA256                                                     STD_OFF
#define MCALCRY_WORKSPACEOFKEYDERIVEHKDFHMACSHA256                                          STD_OFF
#define MCALCRY_KEYDERIVEHKDFHASHOPTION1                                                    STD_OFF
#define MCALCRY_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1                                         STD_OFF
#define MCALCRY_KEYDERIVEISO15118                                                           STD_OFF
#define MCALCRY_WORKSPACEOFKEYDERIVEISO15118                                                STD_OFF
#define MCALCRY_KEYDERIVEKDF2HMACSHA1                                                       STD_OFF
#define MCALCRY_WORKSPACEOFKEYDERIVEKDF2HMACSHA1                                            STD_OFF
#define MCALCRY_KEYDERIVEKDF2HMACSHA256                                                     STD_OFF
#define MCALCRY_WORKSPACEOFKEYDERIVEKDF2HMACSHA256                                          STD_OFF
#define MCALCRY_KEYDERIVENIST800108CNT                                                      STD_OFF
#define MCALCRY_WORKSPACEOFKEYDERIVENIST800108CNT                                           STD_OFF
#define MCALCRY_KEYDERIVENIST80056AONEPASS                                                  STD_OFF
#define MCALCRY_WORKSPACEOFKEYDERIVENIST80056AONEPASS                                       STD_OFF
#define MCALCRY_KEYDERIVENISTFIPS186ERB                                                     STD_OFF
#define MCALCRY_WORKSPACEOFKEYDERIVENISTFIPS186ERB                                          STD_OFF
#define MCALCRY_KEYDERIVESPAKE2P                                                            STD_OFF
#define MCALCRY_WORKSPACEOFKEYDERIVESPAKE2P                                                 STD_OFF
#define MCALCRY_KEYDERIVEX963SHA256                                                         STD_OFF
#define MCALCRY_WORKSPACEOFKEYDERIVEX963SHA256                                              STD_OFF
#define MCALCRY_KEYDERIVEX963SHA512                                                         STD_OFF
#define MCALCRY_WORKSPACEOFKEYDERIVEX963SHA512                                              STD_OFF
#define MCALCRY_KEYELEMENTDELETEOFGENERAL                                                   STD_ON
#define MCALCRY_KEYELEMENTINFO                                                              STD_ON
#define MCALCRY_IDOFKEYELEMENTINFO                                                          STD_ON
#define MCALCRY_INITVALUEENDIDXOFKEYELEMENTINFO                                             STD_OFF
#define MCALCRY_INITVALUESTARTIDXOFKEYELEMENTINFO                                           STD_OFF
#define MCALCRY_INITVALUEUSEDOFKEYELEMENTINFO                                               STD_OFF
#define MCALCRY_LENGTHOFKEYELEMENTINFO                                                      STD_ON
#define MCALCRY_MASKEDBITSOFKEYELEMENTINFO                                                  STD_ON
#define MCALCRY_ONCEOFKEYELEMENTINFO                                                        STD_ON
#define MCALCRY_PARTIALOFKEYELEMENTINFO                                                     STD_ON
#define MCALCRY_PERSISTOFKEYELEMENTINFO                                                     STD_ON
#define MCALCRY_READOFKEYELEMENTINFO                                                        STD_ON
#define MCALCRY_WRITEOFKEYELEMENTINFO                                                       STD_ON
#define MCALCRY_KEYELEMENTS                                                                 STD_ON
#define MCALCRY_IDOFKEYELEMENTS                                                             STD_ON
#define MCALCRY_KEYELEMENTINFOIDXOFKEYELEMENTS                                              STD_ON
#define MCALCRY_KEYSTORAGEENDIDXOFKEYELEMENTS                                               STD_ON
#define MCALCRY_KEYSTORAGEEXTENSIONIDXOFKEYELEMENTS                                         STD_ON
#define MCALCRY_KEYSTORAGESTARTIDXOFKEYELEMENTS                                             STD_ON
#define MCALCRY_KEYSTORAGEVALIDIDXOFKEYELEMENTS                                             STD_ON
#define MCALCRY_KEYSTORAGEWRITTENLENGTHENDIDXOFKEYELEMENTS                                  STD_ON
#define MCALCRY_KEYSTORAGEWRITTENLENGTHSTARTIDXOFKEYELEMENTS                                STD_ON
#define MCALCRY_KEYGENED25519                                                               STD_OFF
#define MCALCRY_WORKSPACEOFKEYGENED25519                                                    STD_OFF
#define MCALCRY_KEYGENP256R1                                                                STD_OFF
#define MCALCRY_WORKSPACEOFKEYGENP256R1                                                     STD_OFF
#define MCALCRY_KEYGENP384R1                                                                STD_OFF
#define MCALCRY_WORKSPACEOFKEYGENP384R1                                                     STD_OFF
#define MCALCRY_KEYGENSYMGENERIC                                                            STD_OFF
#define MCALCRY_WORKSPACEOFKEYGENSYMGENERIC                                                 STD_OFF
#define MCALCRY_KEYGENERATEMAXLENGTHOFKEYGENERATEPRIMITIVES                                 STD_ON
#define MCALCRY_KEYLOCK                                                                     STD_ON
#define MCALCRY_KEYP224R1BDPUBVAL                                                           STD_OFF
#define MCALCRY_WORKSPACEOFKEYP224R1BDPUBVAL                                                STD_OFF
#define MCALCRY_KEYP224R1BDSECRET                                                           STD_OFF
#define MCALCRY_WORKSPACEOFKEYP224R1BDSECRET                                                STD_OFF
#define MCALCRY_KEYP256R1PUBVAL                                                             STD_OFF
#define MCALCRY_WORKSPACEOFKEYP256R1PUBVAL                                                  STD_OFF
#define MCALCRY_KEYP256R1SECRET                                                             STD_OFF
#define MCALCRY_WORKSPACEOFKEYP256R1SECRET                                                  STD_OFF
#define MCALCRY_KEYP384R1PUBVAL                                                             STD_OFF
#define MCALCRY_WORKSPACEOFKEYP384R1PUBVAL                                                  STD_OFF
#define MCALCRY_KEYP384R1SECRET                                                             STD_OFF
#define MCALCRY_WORKSPACEOFKEYP384R1SECRET                                                  STD_OFF
#define MCALCRY_KEYSEEDDRBGAES                                                              STD_OFF
#define MCALCRY_WORKSPACEOFKEYSEEDDRBGAES                                                   STD_OFF
#define MCALCRY_KEYSEEDDRBGHASHSHA512                                                       STD_OFF
#define MCALCRY_WORKSPACEOFKEYSEEDDRBGHASHSHA512                                            STD_OFF
#define MCALCRY_KEYSEEDFIPS186                                                              STD_OFF
#define MCALCRY_WORKSPACEOFKEYSEEDFIPS186                                                   STD_OFF
#define MCALCRY_KEYSETVALID                                                                 STD_OFF
#define MCALCRY_WORKSPACEOFKEYSETVALID                                                      STD_OFF
#define MCALCRY_KEYSPAKE2PPUBVAL                                                            STD_OFF
#define MCALCRY_WORKSPACEOFKEYSPAKE2PPUBVAL                                                 STD_OFF
#define MCALCRY_KEYSPAKE2PSECRET                                                            STD_OFF
#define MCALCRY_WORKSPACEOFKEYSPAKE2PSECRET                                                 STD_OFF
#define MCALCRY_KEYSTORAGE                                                                  STD_ON
#define MCALCRY_KEYVALIDITYSETCALLOUTFCTNAMEOFCONFIGURABLECALLOUTS                          STD_OFF
#define MCALCRY_KEYVALUECHANGEDCALLOUTFCTNAMEOFCONFIGURABLECALLOUTS                         STD_OFF
#define MCALCRY_KEYX25519PUBVAL                                                             STD_OFF
#define MCALCRY_WORKSPACEOFKEYX25519PUBVAL                                                  STD_OFF
#define MCALCRY_KEYX25519SECRET                                                             STD_OFF
#define MCALCRY_WORKSPACEOFKEYX25519SECRET                                                  STD_OFF
#define MCALCRY_LASTJOB                                                                     STD_OFF
#define MCALCRY_FAMILYOFLASTJOB                                                             STD_OFF
#define MCALCRY_KEYIDOFLASTJOB                                                              STD_OFF
#define MCALCRY_MODEOFLASTJOB                                                               STD_OFF
#define MCALCRY_LOCK                                                                        STD_ON
#define MCALCRY_LONGTERMWS                                                                  STD_OFF
#define MCALCRY_LONGTERMWSLOCK                                                              STD_OFF
#define MCALCRY_MD5                                                                         STD_OFF
#define MCALCRY_WORKSPACEOFMD5                                                              STD_OFF
#define MCALCRY_MAINFUNCTIONPERIODOFGENERAL                                                 STD_ON
#define MCALCRY_NUMBEROFLONGTERMPRIMITIVEWORKSPACEOFGENERAL                                 STD_ON
#define MCALCRY_NVBLOCK                                                                     STD_OFF
#define MCALCRY_CONSISTENCYLEVELOFNVBLOCK                                                   STD_OFF
#define MCALCRY_CRCOFNVBLOCK                                                                STD_OFF
#define MCALCRY_DESCRIPTOROFNVBLOCK                                                         STD_OFF
#define MCALCRY_IDOFNVBLOCK                                                                 STD_OFF
#define MCALCRY_KEYSTORAGEENDIDXOFNVBLOCK                                                   STD_OFF
#define MCALCRY_KEYSTORAGESTARTIDXOFNVBLOCK                                                 STD_OFF
#define MCALCRY_LENGTHOFNVBLOCK                                                             STD_OFF
#define MCALCRY_PROCESSINGOFNVBLOCK                                                         STD_OFF
#define MCALCRY_NVMENABLESETRAMBLOCKSTATUSOFGENERAL                                         STD_ON
#define MCALCRY_NVMANAGEMENTDATAPERKEYOFNVSTORAGE                                           STD_ON
#define MCALCRY_NVWRITEBLOCKFCTNAMEOFNVSTORAGE                                              STD_ON
#define MCALCRY_OBJECTINFO                                                                  STD_ON
#define MCALCRY_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO                                    STD_OFF
#define MCALCRY_AEADCHACHAPOLY1305DECRYPTUSEDOFOBJECTINFO                                   STD_OFF
#define MCALCRY_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO                                    STD_OFF
#define MCALCRY_AEADCHACHAPOLY1305ENCRYPTUSEDOFOBJECTINFO                                   STD_OFF
#define MCALCRY_AESCCMDECRYPTIDXOFOBJECTINFO                                                STD_OFF
#define MCALCRY_AESCCMDECRYPTUSEDOFOBJECTINFO                                               STD_OFF
#define MCALCRY_AESCCMENCRYPTIDXOFOBJECTINFO                                                STD_OFF
#define MCALCRY_AESCCMENCRYPTUSEDOFOBJECTINFO                                               STD_OFF
#define MCALCRY_AESDECRYPTIDXOFOBJECTINFO                                                   STD_ON
#define MCALCRY_AESDECRYPTUSEDOFOBJECTINFO                                                  STD_ON
#define MCALCRY_AESENCRYPTIDXOFOBJECTINFO                                                   STD_OFF
#define MCALCRY_AESENCRYPTUSEDOFOBJECTINFO                                                  STD_OFF
#define MCALCRY_AESGCMDECRYPTIDXOFOBJECTINFO                                                STD_OFF
#define MCALCRY_AESGCMDECRYPTUSEDOFOBJECTINFO                                               STD_OFF
#define MCALCRY_AESGCMENCRYPTIDXOFOBJECTINFO                                                STD_OFF
#define MCALCRY_AESGCMENCRYPTUSEDOFOBJECTINFO                                               STD_OFF
#define MCALCRY_CMACAESGENERATEIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_CMACAESGENERATEUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_CMACAESVERIFYIDXOFOBJECTINFO                                                STD_OFF
#define MCALCRY_CMACAESVERIFYUSEDOFOBJECTINFO                                               STD_OFF
#define MCALCRY_DRBGAESIDXOFOBJECTINFO                                                      STD_OFF
#define MCALCRY_DRBGAESUSEDOFOBJECTINFO                                                     STD_OFF
#define MCALCRY_DRBGHASHSHA512IDXOFOBJECTINFO                                               STD_OFF
#define MCALCRY_DRBGHASHSHA512USEDOFOBJECTINFO                                              STD_OFF
#define MCALCRY_ECP160GENERATEIDXOFOBJECTINFO                                               STD_OFF
#define MCALCRY_ECP160GENERATEUSEDOFOBJECTINFO                                              STD_OFF
#define MCALCRY_ECP160VERIFYIDXOFOBJECTINFO                                                 STD_OFF
#define MCALCRY_ECP160VERIFYUSEDOFOBJECTINFO                                                STD_OFF
#define MCALCRY_ECP256GENERATEIDXOFOBJECTINFO                                               STD_OFF
#define MCALCRY_ECP256GENERATEUSEDOFOBJECTINFO                                              STD_OFF
#define MCALCRY_ECP256VERIFYIDXOFOBJECTINFO                                                 STD_OFF
#define MCALCRY_ECP256VERIFYUSEDOFOBJECTINFO                                                STD_OFF
#define MCALCRY_ECP384GENERATEIDXOFOBJECTINFO                                               STD_OFF
#define MCALCRY_ECP384GENERATEUSEDOFOBJECTINFO                                              STD_OFF
#define MCALCRY_ECP384VERIFYIDXOFOBJECTINFO                                                 STD_OFF
#define MCALCRY_ECP384VERIFYUSEDOFOBJECTINFO                                                STD_OFF
#define MCALCRY_ED25519GENERATEIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_ED25519GENERATEUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_ED25519VERIFYIDXOFOBJECTINFO                                                STD_OFF
#define MCALCRY_ED25519VERIFYUSEDOFOBJECTINFO                                               STD_OFF
#define MCALCRY_FIPS186IDXOFOBJECTINFO                                                      STD_OFF
#define MCALCRY_FIPS186USEDOFOBJECTINFO                                                     STD_OFF
#define MCALCRY_GMACAESGENERATEIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_GMACAESGENERATEUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_GMACAESVERIFYIDXOFOBJECTINFO                                                STD_OFF
#define MCALCRY_GMACAESVERIFYUSEDOFOBJECTINFO                                               STD_OFF
#define MCALCRY_HMACRIPEMD160GENERATEIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_HMACRIPEMD160GENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_HMACRIPEMD160VERIFYIDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_HMACRIPEMD160VERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_HMACSHA1GENERATEIDXOFOBJECTINFO                                             STD_OFF
#define MCALCRY_HMACSHA1GENERATEUSEDOFOBJECTINFO                                            STD_OFF
#define MCALCRY_HMACSHA1VERIFYIDXOFOBJECTINFO                                               STD_ON
#define MCALCRY_HMACSHA1VERIFYUSEDOFOBJECTINFO                                              STD_ON
#define MCALCRY_HMACSHA256GENERATEIDXOFOBJECTINFO                                           STD_OFF
#define MCALCRY_HMACSHA256GENERATEUSEDOFOBJECTINFO                                          STD_OFF
#define MCALCRY_HMACSHA256VERIFYIDXOFOBJECTINFO                                             STD_OFF
#define MCALCRY_HMACSHA256VERIFYUSEDOFOBJECTINFO                                            STD_OFF
#define MCALCRY_HMACSHA384GENERATEIDXOFOBJECTINFO                                           STD_OFF
#define MCALCRY_HMACSHA384GENERATEUSEDOFOBJECTINFO                                          STD_OFF
#define MCALCRY_HMACSHA384VERIFYIDXOFOBJECTINFO                                             STD_OFF
#define MCALCRY_HMACSHA384VERIFYUSEDOFOBJECTINFO                                            STD_OFF
#define MCALCRY_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO                                      STD_OFF
#define MCALCRY_KEYDERIVEHKDFHMACSHA256USEDOFOBJECTINFO                                     STD_OFF
#define MCALCRY_KEYDERIVEHKDFHASHOPTION1IDXOFOBJECTINFO                                     STD_OFF
#define MCALCRY_KEYDERIVEHKDFHASHOPTION1USEDOFOBJECTINFO                                    STD_OFF
#define MCALCRY_KEYDERIVEISO15118IDXOFOBJECTINFO                                            STD_OFF
#define MCALCRY_KEYDERIVEISO15118USEDOFOBJECTINFO                                           STD_OFF
#define MCALCRY_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_KEYDERIVEKDF2HMACSHA1USEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO                                      STD_OFF
#define MCALCRY_KEYDERIVEKDF2HMACSHA256USEDOFOBJECTINFO                                     STD_OFF
#define MCALCRY_KEYDERIVENIST800108CNTIDXOFOBJECTINFO                                       STD_OFF
#define MCALCRY_KEYDERIVENIST800108CNTUSEDOFOBJECTINFO                                      STD_OFF
#define MCALCRY_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO                                   STD_OFF
#define MCALCRY_KEYDERIVENIST80056AONEPASSUSEDOFOBJECTINFO                                  STD_OFF
#define MCALCRY_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO                                      STD_OFF
#define MCALCRY_KEYDERIVENISTFIPS186ERBUSEDOFOBJECTINFO                                     STD_OFF
#define MCALCRY_KEYDERIVESPAKE2PIDXOFOBJECTINFO                                             STD_OFF
#define MCALCRY_KEYDERIVESPAKE2PUSEDOFOBJECTINFO                                            STD_OFF
#define MCALCRY_KEYDERIVEX963SHA256IDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_KEYDERIVEX963SHA256USEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_KEYDERIVEX963SHA512IDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_KEYDERIVEX963SHA512USEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_KEYGENED25519IDXOFOBJECTINFO                                                STD_OFF
#define MCALCRY_KEYGENED25519USEDOFOBJECTINFO                                               STD_OFF
#define MCALCRY_KEYGENP256R1IDXOFOBJECTINFO                                                 STD_OFF
#define MCALCRY_KEYGENP256R1USEDOFOBJECTINFO                                                STD_OFF
#define MCALCRY_KEYGENP384R1IDXOFOBJECTINFO                                                 STD_OFF
#define MCALCRY_KEYGENP384R1USEDOFOBJECTINFO                                                STD_OFF
#define MCALCRY_KEYGENSYMGENERICIDXOFOBJECTINFO                                             STD_OFF
#define MCALCRY_KEYGENSYMGENERICUSEDOFOBJECTINFO                                            STD_OFF
#define MCALCRY_KEYP224R1BDPUBVALIDXOFOBJECTINFO                                            STD_OFF
#define MCALCRY_KEYP224R1BDPUBVALUSEDOFOBJECTINFO                                           STD_OFF
#define MCALCRY_KEYP224R1BDSECRETIDXOFOBJECTINFO                                            STD_OFF
#define MCALCRY_KEYP224R1BDSECRETUSEDOFOBJECTINFO                                           STD_OFF
#define MCALCRY_KEYP256R1PUBVALIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_KEYP256R1PUBVALUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_KEYP256R1SECRETIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_KEYP256R1SECRETUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_KEYP384R1PUBVALIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_KEYP384R1PUBVALUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_KEYP384R1SECRETIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_KEYP384R1SECRETUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_KEYSEEDDRBGAESIDXOFOBJECTINFO                                               STD_OFF
#define MCALCRY_KEYSEEDDRBGAESUSEDOFOBJECTINFO                                              STD_OFF
#define MCALCRY_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_KEYSEEDDRBGHASHSHA512USEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_KEYSEEDFIPS186IDXOFOBJECTINFO                                               STD_OFF
#define MCALCRY_KEYSEEDFIPS186USEDOFOBJECTINFO                                              STD_OFF
#define MCALCRY_KEYSETVALIDIDXOFOBJECTINFO                                                  STD_OFF
#define MCALCRY_KEYSETVALIDUSEDOFOBJECTINFO                                                 STD_OFF
#define MCALCRY_KEYSPAKE2PPUBVALIDXOFOBJECTINFO                                             STD_OFF
#define MCALCRY_KEYSPAKE2PPUBVALUSEDOFOBJECTINFO                                            STD_OFF
#define MCALCRY_KEYSPAKE2PSECRETIDXOFOBJECTINFO                                             STD_OFF
#define MCALCRY_KEYSPAKE2PSECRETUSEDOFOBJECTINFO                                            STD_OFF
#define MCALCRY_KEYX25519PUBVALIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_KEYX25519PUBVALUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_KEYX25519SECRETIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_KEYX25519SECRETUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_MD5IDXOFOBJECTINFO                                                          STD_OFF
#define MCALCRY_MD5USEDOFOBJECTINFO                                                         STD_OFF
#define MCALCRY_QUEUEIDXOFOBJECTINFO                                                        STD_ON
#define MCALCRY_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_RANDOMSEEDBUFFERUSEDOFOBJECTINFO                                            STD_OFF
#define MCALCRY_RIPEMD160IDXOFOBJECTINFO                                                    STD_OFF
#define MCALCRY_RIPEMD160USEDOFOBJECTINFO                                                   STD_OFF
#define MCALCRY_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_RSAOAEPCRTSHA1DECRYPTUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO                                      STD_OFF
#define MCALCRY_RSAOAEPCRTSHA256DECRYPTUSEDOFOBJECTINFO                                     STD_OFF
#define MCALCRY_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO                                           STD_OFF
#define MCALCRY_RSAOAEPSHA1DECRYPTUSEDOFOBJECTINFO                                          STD_OFF
#define MCALCRY_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO                                           STD_OFF
#define MCALCRY_RSAOAEPSHA1ENCRYPTUSEDOFOBJECTINFO                                          STD_OFF
#define MCALCRY_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO                                         STD_OFF
#define MCALCRY_RSAOAEPSHA256DECRYPTUSEDOFOBJECTINFO                                        STD_OFF
#define MCALCRY_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO                                         STD_OFF
#define MCALCRY_RSAOAEPSHA256ENCRYPTUSEDOFOBJECTINFO                                        STD_OFF
#define MCALCRY_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_RSAPKCS1CRTGENERATEUSEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_RSAPKCS1DECRYPTIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_RSAPKCS1DECRYPTUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_RSAPKCS1ENCRYPTIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_RSAPKCS1ENCRYPTUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_RSAPKCS1GENERATEIDXOFOBJECTINFO                                             STD_OFF
#define MCALCRY_RSAPKCS1GENERATEUSEDOFOBJECTINFO                                            STD_OFF
#define MCALCRY_RSAPKCS1VERIFYIDXOFOBJECTINFO                                               STD_ON
#define MCALCRY_RSAPKCS1VERIFYUSEDOFOBJECTINFO                                              STD_ON
#define MCALCRY_RSAPSSGENERATEIDXOFOBJECTINFO                                               STD_OFF
#define MCALCRY_RSAPSSGENERATEUSEDOFOBJECTINFO                                              STD_OFF
#define MCALCRY_RSAPSSVERIFYIDXOFOBJECTINFO                                                 STD_ON
#define MCALCRY_RSAPSSVERIFYUSEDOFOBJECTINFO                                                STD_ON
#define MCALCRY_SHA1IDXOFOBJECTINFO                                                         STD_OFF
#define MCALCRY_SHA1USEDOFOBJECTINFO                                                        STD_OFF
#define MCALCRY_SHA256IDXOFOBJECTINFO                                                       STD_OFF
#define MCALCRY_SHA256USEDOFOBJECTINFO                                                      STD_OFF
#define MCALCRY_SHA384IDXOFOBJECTINFO                                                       STD_OFF
#define MCALCRY_SHA384USEDOFOBJECTINFO                                                      STD_OFF
#define MCALCRY_SHA3_256IDXOFOBJECTINFO                                                     STD_OFF
#define MCALCRY_SHA3_256USEDOFOBJECTINFO                                                    STD_OFF
#define MCALCRY_SHA512IDXOFOBJECTINFO                                                       STD_ON
#define MCALCRY_SHA512USEDOFOBJECTINFO                                                      STD_ON
#define MCALCRY_SHECMDGETIDIDXOFOBJECTINFO                                                  STD_OFF
#define MCALCRY_SHECMDGETIDUSEDOFOBJECTINFO                                                 STD_OFF
#define MCALCRY_SIPHASHGENERATEIDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_SIPHASHGENERATEUSEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_SIPHASHVERIFYIDXOFOBJECTINFO                                                STD_OFF
#define MCALCRY_SIPHASHVERIFYUSEDOFOBJECTINFO                                               STD_OFF
#define MCALCRY_WORKSPACEADDROFOBJECTINFO                                                   STD_ON
#define MCALCRY_WORKSPACELENGTHOFOBJECTINFO                                                 STD_ON
#define MCALCRY_OBJECTINFOIND                                                               STD_ON
#define MCALCRY_PRIMITIVEFCT                                                                STD_ON
#define MCALCRY_DISPATCHOFPRIMITIVEFCT                                                      STD_ON
#define MCALCRY_OBJECTINFOINDENDIDXOFPRIMITIVEFCT                                           STD_ON
#define MCALCRY_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT                                         STD_ON
#define MCALCRY_OBJECTINFOINDUSEDOFPRIMITIVEFCT                                             STD_ON
#define MCALCRY_PRIMITIVEINFO                                                               STD_ON
#define MCALCRY_COMBINEDOFPRIMITIVEINFO                                                     STD_ON
#define MCALCRY_CONTEXTOFPRIMITIVEINFO                                                      STD_ON
#define MCALCRY_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO                                          STD_ON
#define MCALCRY_MASKEDBITSOFPRIMITIVEINFO                                                   STD_ON
#define MCALCRY_PRIMITIVEFCTIDXOFPRIMITIVEINFO                                              STD_ON
#define MCALCRY_PRIMITIVESERVICEINFO                                                        STD_ON
#define MCALCRY_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO                                   STD_ON
#define MCALCRY_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO                                 STD_ON
#define MCALCRY_PRIMITIVEINFOUSEDOFPRIMITIVESERVICEINFO                                     STD_ON
#define MCALCRY_QUEUE                                                                       STD_ON
#define MCALCRY_RANDOMSEEDBUFFER                                                            STD_OFF
#define MCALCRY_REDIRECTIONOFGENERAL                                                        STD_ON
#define MCALCRY_RIPEMD160                                                                   STD_OFF
#define MCALCRY_WORKSPACEOFRIPEMD160                                                        STD_OFF
#define MCALCRY_RSAOAEPCRTSHA1DECRYPT                                                       STD_OFF
#define MCALCRY_WORKSPACEOFRSAOAEPCRTSHA1DECRYPT                                            STD_OFF
#define MCALCRY_RSAOAEPCRTSHA256DECRYPT                                                     STD_OFF
#define MCALCRY_WORKSPACEOFRSAOAEPCRTSHA256DECRYPT                                          STD_OFF
#define MCALCRY_RSAOAEPSHA1DECRYPT                                                          STD_OFF
#define MCALCRY_WORKSPACEOFRSAOAEPSHA1DECRYPT                                               STD_OFF
#define MCALCRY_RSAOAEPSHA1ENCRYPT                                                          STD_OFF
#define MCALCRY_WORKSPACEOFRSAOAEPSHA1ENCRYPT                                               STD_OFF
#define MCALCRY_RSAOAEPSHA256DECRYPT                                                        STD_OFF
#define MCALCRY_WORKSPACEOFRSAOAEPSHA256DECRYPT                                             STD_OFF
#define MCALCRY_RSAOAEPSHA256ENCRYPT                                                        STD_OFF
#define MCALCRY_WORKSPACEOFRSAOAEPSHA256ENCRYPT                                             STD_OFF
#define MCALCRY_RSAPKCS1CRTGENERATE                                                         STD_OFF
#define MCALCRY_WORKSPACEOFRSAPKCS1CRTGENERATE                                              STD_OFF
#define MCALCRY_RSAPKCS1DECRYPT                                                             STD_OFF
#define MCALCRY_WORKSPACEOFRSAPKCS1DECRYPT                                                  STD_OFF
#define MCALCRY_RSAPKCS1ENCRYPT                                                             STD_OFF
#define MCALCRY_WORKSPACEOFRSAPKCS1ENCRYPT                                                  STD_OFF
#define MCALCRY_RSAPKCS1GENERATE                                                            STD_OFF
#define MCALCRY_WORKSPACEOFRSAPKCS1GENERATE                                                 STD_OFF
#define MCALCRY_RSAPKCS1VERIFY                                                              STD_ON
#define MCALCRY_WORKSPACEOFRSAPKCS1VERIFY                                                   STD_ON
#define MCALCRY_RSAPSSGENERATE                                                              STD_OFF
#define MCALCRY_WORKSPACEOFRSAPSSGENERATE                                                   STD_OFF
#define MCALCRY_RSAPSSVERIFY                                                                STD_ON
#define MCALCRY_WORKSPACEOFRSAPSSVERIFY                                                     STD_ON
#define MCALCRY_SHA1                                                                        STD_OFF
#define MCALCRY_WORKSPACEOFSHA1                                                             STD_OFF
#define MCALCRY_SHA256                                                                      STD_OFF
#define MCALCRY_WORKSPACEOFSHA256                                                           STD_OFF
#define MCALCRY_SHA384                                                                      STD_OFF
#define MCALCRY_WORKSPACEOFSHA384                                                           STD_OFF
#define MCALCRY_SHA3_256                                                                    STD_OFF
#define MCALCRY_WORKSPACEOFSHA3_256                                                         STD_OFF
#define MCALCRY_SHA512                                                                      STD_ON
#define MCALCRY_WORKSPACEOFSHA512                                                           STD_ON
#define MCALCRY_SAVEANDRESTOREWORKSPACE                                                     STD_OFF
#define MCALCRY_LENGTHOFSAVEANDRESTOREWORKSPACE                                             STD_OFF
#define MCALCRY_SHECMDGETID                                                                 STD_OFF
#define MCALCRY_WORKSPACEOFSHECMDGETID                                                      STD_OFF
#define MCALCRY_SHEDEBUGCMDOFSHEKEYUPDATE                                                   STD_OFF
#define MCALCRY_SHEENABLECOUNTEROFSHEKEYUPDATE                                              STD_OFF
#define MCALCRY_SHEENABLEFIDOFSHEKEYUPDATE                                                  STD_OFF
#define MCALCRY_SHEINFOKEYREFOFSHEKEYUPDATE                                                 STD_OFF
#define MCALCRY_SHEKEYS                                                                     STD_OFF
#define MCALCRY_SIPHASHGENERATE                                                             STD_OFF
#define MCALCRY_WORKSPACEOFSIPHASHGENERATE                                                  STD_OFF
#define MCALCRY_SIPHASHVERIFY                                                               STD_OFF
#define MCALCRY_WORKSPACEOFSIPHASHVERIFY                                                    STD_OFF
#define MCALCRY_SIZEOFAESDECRYPT                                                            STD_ON
#define MCALCRY_SIZEOFBUFFERLENGTH                                                          STD_ON
#define MCALCRY_SIZEOFDRIVEROBJECTSTATE                                                     STD_ON
#define MCALCRY_SIZEOFHMACSHA1VERIFY                                                        STD_ON
#define MCALCRY_SIZEOFKEY                                                                   STD_ON
#define MCALCRY_SIZEOFKEYELEMENTINFO                                                        STD_ON
#define MCALCRY_SIZEOFKEYELEMENTS                                                           STD_ON
#define MCALCRY_SIZEOFKEYLOCK                                                               STD_ON
#define MCALCRY_SIZEOFKEYSTORAGE                                                            STD_ON
#define MCALCRY_SIZEOFLOCK                                                                  STD_ON
#define MCALCRY_SIZEOFOBJECTINFO                                                            STD_ON
#define MCALCRY_SIZEOFOBJECTINFOIND                                                         STD_ON
#define MCALCRY_SIZEOFPRIMITIVEFCT                                                          STD_ON
#define MCALCRY_SIZEOFPRIMITIVEINFO                                                         STD_ON
#define MCALCRY_SIZEOFPRIMITIVESERVICEINFO                                                  STD_ON
#define MCALCRY_SIZEOFQUEUE                                                                 STD_ON
#define MCALCRY_SIZEOFRSAPKCS1VERIFY                                                        STD_ON
#define MCALCRY_SIZEOFRSAPSSVERIFY                                                          STD_ON
#define MCALCRY_SIZEOFSHA512                                                                STD_ON
#define MCALCRY_SIZEOFWRITTENLENGTH                                                         STD_ON
#define MCALCRY_UNIONWS_MCALCRY                                                     STD_ON
#define MCALCRY_UNIONWS_MCALCRY_AES                                                 STD_ON
#define MCALCRY_USEVSTDLIBOFGENERAL                                                         STD_ON
#define MCALCRY_VERSIONINFOAPIOFGENERAL                                                     STD_ON
#define MCALCRY_WATCHDOGTRIGGERFUNCTIONOFGENERAL                                            STD_ON
#define MCALCRY_WRITTENLENGTH                                                               STD_ON
#define MCALCRY_PCCONFIG                                                                    STD_ON
#define MCALCRY_AESDECRYPTOFPCCONFIG                                                        STD_ON
#define MCALCRY_ALIGNKEYSTORAGEOFGENERALOFPCCONFIG                                          STD_ON
#define MCALCRY_BUFFERLENGTHOFPCCONFIG                                                      STD_ON
#define MCALCRY_CMACAESROUNDKEYREUSEOFMACPRIMITIVESOFPCCONFIG                               STD_ON
#define MCALCRY_DEFAULTRANDOMMAXRETRIESOFGENERALOFPCCONFIG                                  STD_ON
#define MCALCRY_DRIVEROBJECTSTATEOFPCCONFIG                                                 STD_ON
#define MCALCRY_ENABLEAES256OFCIPHERPRIMITIVESOFPCCONFIG                                    STD_ON
#define MCALCRY_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                      STD_OFF
#define MCALCRY_FINALMAGICNUMBEROFPCCONFIG                                                  STD_OFF
#define MCALCRY_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                     STD_OFF
#define MCALCRY_HMACSHA1VERIFYOFPCCONFIG                                                    STD_ON
#define MCALCRY_INITDATAHASHCODEOFPCCONFIG                                                  STD_OFF
#define MCALCRY_KEYELEMENTDELETEOFGENERALOFPCCONFIG                                         STD_ON
#define MCALCRY_KEYELEMENTINFOOFPCCONFIG                                                    STD_ON
#define MCALCRY_KEYELEMENTSOFPCCONFIG                                                       STD_ON
#define MCALCRY_KEYGENERATEMAXLENGTHOFKEYGENERATEPRIMITIVESOFPCCONFIG                       STD_ON
#define MCALCRY_KEYLOCKOFPCCONFIG                                                           STD_ON
#define MCALCRY_KEYOFPCCONFIG                                                               STD_ON
#define MCALCRY_KEYSTORAGEOFPCCONFIG                                                        STD_ON
#define MCALCRY_KEYVALIDITYSETCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG                STD_OFF
#define MCALCRY_KEYVALUECHANGEDCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG               STD_OFF
#define MCALCRY_LOCKOFPCCONFIG                                                              STD_ON
#define MCALCRY_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                       STD_ON
#define MCALCRY_NUMBEROFLONGTERMPRIMITIVEWORKSPACEOFGENERALOFPCCONFIG                       STD_ON
#define MCALCRY_NVMENABLESETRAMBLOCKSTATUSOFGENERALOFPCCONFIG                               STD_ON
#define MCALCRY_NVMANAGEMENTDATAPERKEYOFNVSTORAGEOFPCCONFIG                                 STD_ON
#define MCALCRY_NVWRITEBLOCKFCTNAMEOFNVSTORAGEOFPCCONFIG                                    STD_ON
#define MCALCRY_OBJECTINFOINDOFPCCONFIG                                                     STD_ON
#define MCALCRY_OBJECTINFOOFPCCONFIG                                                        STD_ON
#define MCALCRY_PRIMITIVEFCTOFPCCONFIG                                                      STD_ON
#define MCALCRY_PRIMITIVEINFOOFPCCONFIG                                                     STD_ON
#define MCALCRY_PRIMITIVESERVICEINFOOFPCCONFIG                                              STD_ON
#define MCALCRY_QUEUEOFPCCONFIG                                                             STD_ON
#define MCALCRY_REDIRECTIONOFGENERALOFPCCONFIG                                              STD_ON
#define MCALCRY_RSAPKCS1VERIFYOFPCCONFIG                                                    STD_ON
#define MCALCRY_RSAPSSVERIFYOFPCCONFIG                                                      STD_ON
#define MCALCRY_SHA512OFPCCONFIG                                                            STD_ON
#define MCALCRY_SHEDEBUGCMDOFSHEKEYUPDATEOFPCCONFIG                                         STD_OFF
#define MCALCRY_SHEENABLECOUNTEROFSHEKEYUPDATEOFPCCONFIG                                    STD_OFF
#define MCALCRY_SHEENABLEFIDOFSHEKEYUPDATEOFPCCONFIG                                        STD_OFF
#define MCALCRY_SHEINFOKEYREFOFSHEKEYUPDATEOFPCCONFIG                                       STD_OFF
#define MCALCRY_SIZEOFAESDECRYPTOFPCCONFIG                                                  STD_ON
#define MCALCRY_SIZEOFBUFFERLENGTHOFPCCONFIG                                                STD_ON
#define MCALCRY_SIZEOFDRIVEROBJECTSTATEOFPCCONFIG                                           STD_ON
#define MCALCRY_SIZEOFHMACSHA1VERIFYOFPCCONFIG                                              STD_ON
#define MCALCRY_SIZEOFKEYELEMENTINFOOFPCCONFIG                                              STD_ON
#define MCALCRY_SIZEOFKEYELEMENTSOFPCCONFIG                                                 STD_ON
#define MCALCRY_SIZEOFKEYLOCKOFPCCONFIG                                                     STD_ON
#define MCALCRY_SIZEOFKEYOFPCCONFIG                                                         STD_ON
#define MCALCRY_SIZEOFKEYSTORAGEOFPCCONFIG                                                  STD_ON
#define MCALCRY_SIZEOFLOCKOFPCCONFIG                                                        STD_ON
#define MCALCRY_SIZEOFOBJECTINFOINDOFPCCONFIG                                               STD_ON
#define MCALCRY_SIZEOFOBJECTINFOOFPCCONFIG                                                  STD_ON
#define MCALCRY_SIZEOFPRIMITIVEFCTOFPCCONFIG                                                STD_ON
#define MCALCRY_SIZEOFPRIMITIVEINFOOFPCCONFIG                                               STD_ON
#define MCALCRY_SIZEOFPRIMITIVESERVICEINFOOFPCCONFIG                                        STD_ON
#define MCALCRY_SIZEOFQUEUEOFPCCONFIG                                                       STD_ON
#define MCALCRY_SIZEOFRSAPKCS1VERIFYOFPCCONFIG                                              STD_ON
#define MCALCRY_SIZEOFRSAPSSVERIFYOFPCCONFIG                                                STD_ON
#define MCALCRY_SIZEOFSHA512OFPCCONFIG                                                      STD_ON
#define MCALCRY_SIZEOFWRITTENLENGTHOFPCCONFIG                                               STD_ON
#define MCALCRY_UNIONWS_MCALCRYOFPCCONFIG                                           STD_ON
#define MCALCRY_UNIONWS_MCALCRY_AESOFPCCONFIG                                       STD_ON
#define MCALCRY_USEVSTDLIBOFGENERALOFPCCONFIG                                               STD_ON
#define MCALCRY_VERSIONINFOAPIOFGENERALOFPCCONFIG                                           STD_ON
#define MCALCRY_WATCHDOGTRIGGERFUNCTIONOFGENERALOFPCCONFIG                                  STD_ON
#define MCALCRY_WRITTENLENGTHOFPCCONFIG                                                     STD_ON

#define MCALCRY_MIN_BUFFERLENGTH                                                            0u
#define MCALCRY_MIN_DRIVEROBJECTSTATE                                                       0u
#define MCALCRY_MIN_KEYLOCK                                                                 0u
#define MCALCRY_MIN_KEYSTORAGE                                                              0u
#define MCALCRY_MIN_KEYIDOFLASTJOB                                                          0u
#define MCALCRY_MIN_LOCK                                                                    0u
#define MCALCRY_MIN_LONGTERMWSLOCK                                                          0u
#define MCALCRY_MIN_RANDOMSEEDBUFFER                                                        0u
#define MCALCRY_MIN_LENGTHOFSAVEANDRESTOREWORKSPACE                                         0u
#define MCALCRY_MIN_WRITTENLENGTH                                                           0u

#define MCALCRY_MAX_BUFFERLENGTH                                                            4294967295u
#define MCALCRY_MAX_DRIVEROBJECTSTATE                                                       255u
#define MCALCRY_MAX_KEYLOCK                                                                 255u
#define MCALCRY_MAX_KEYSTORAGE                                                              255u
#define MCALCRY_MAX_KEYIDOFLASTJOB                                                          4294967295u
#define MCALCRY_MAX_LOCK                                                                    4294967295u
#define MCALCRY_MAX_LONGTERMWSLOCK                                                          4294967295u
#define MCALCRY_MAX_RANDOMSEEDBUFFER                                                        255u
#define MCALCRY_MAX_LENGTHOFSAVEANDRESTOREWORKSPACE                                         4294967295u
#define MCALCRY_MAX_WRITTENLENGTH                                                           4294967295u

#define MCALCRY_NO_INITVALUE                                                                255u
#define MCALCRY_NO_NVBLOCKIDXOFKEY                                                          255u
#define MCALCRY_NO_INITVALUEENDIDXOFKEYELEMENTINFO                                          255u
#define MCALCRY_NO_INITVALUESTARTIDXOFKEYELEMENTINFO                                        255u
#define MCALCRY_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO                                 255u
#define MCALCRY_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO                                 255u
#define MCALCRY_NO_AESCCMDECRYPTIDXOFOBJECTINFO                                             255u
#define MCALCRY_NO_AESCCMENCRYPTIDXOFOBJECTINFO                                             255u
#define MCALCRY_NO_AESDECRYPTIDXOFOBJECTINFO                                                255u
#define MCALCRY_NO_AESENCRYPTIDXOFOBJECTINFO                                                255u
#define MCALCRY_NO_AESGCMDECRYPTIDXOFOBJECTINFO                                             255u
#define MCALCRY_NO_AESGCMENCRYPTIDXOFOBJECTINFO                                             255u
#define MCALCRY_NO_CMACAESGENERATEIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_CMACAESVERIFYIDXOFOBJECTINFO                                             255u
#define MCALCRY_NO_DRBGAESIDXOFOBJECTINFO                                                   255u
#define MCALCRY_NO_DRBGHASHSHA512IDXOFOBJECTINFO                                            255u
#define MCALCRY_NO_ECP160GENERATEIDXOFOBJECTINFO                                            255u
#define MCALCRY_NO_ECP160VERIFYIDXOFOBJECTINFO                                              255u
#define MCALCRY_NO_ECP256GENERATEIDXOFOBJECTINFO                                            255u
#define MCALCRY_NO_ECP256VERIFYIDXOFOBJECTINFO                                              255u
#define MCALCRY_NO_ECP384GENERATEIDXOFOBJECTINFO                                            255u
#define MCALCRY_NO_ECP384VERIFYIDXOFOBJECTINFO                                              255u
#define MCALCRY_NO_ED25519GENERATEIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_ED25519VERIFYIDXOFOBJECTINFO                                             255u
#define MCALCRY_NO_FIPS186IDXOFOBJECTINFO                                                   255u
#define MCALCRY_NO_GMACAESGENERATEIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_GMACAESVERIFYIDXOFOBJECTINFO                                             255u
#define MCALCRY_NO_HMACRIPEMD160GENERATEIDXOFOBJECTINFO                                     255u
#define MCALCRY_NO_HMACRIPEMD160VERIFYIDXOFOBJECTINFO                                       255u
#define MCALCRY_NO_HMACSHA1GENERATEIDXOFOBJECTINFO                                          255u
#define MCALCRY_NO_HMACSHA1VERIFYIDXOFOBJECTINFO                                            255u
#define MCALCRY_NO_HMACSHA256GENERATEIDXOFOBJECTINFO                                        255u
#define MCALCRY_NO_HMACSHA256VERIFYIDXOFOBJECTINFO                                          255u
#define MCALCRY_NO_HMACSHA384GENERATEIDXOFOBJECTINFO                                        255u
#define MCALCRY_NO_HMACSHA384VERIFYIDXOFOBJECTINFO                                          255u
#define MCALCRY_NO_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO                                   255u
#define MCALCRY_NO_KEYDERIVEHKDFHASHOPTION1IDXOFOBJECTINFO                                  255u
#define MCALCRY_NO_KEYDERIVEISO15118IDXOFOBJECTINFO                                         255u
#define MCALCRY_NO_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO                                     255u
#define MCALCRY_NO_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO                                   255u
#define MCALCRY_NO_KEYDERIVENIST800108CNTIDXOFOBJECTINFO                                    255u
#define MCALCRY_NO_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO                                255u
#define MCALCRY_NO_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO                                   255u
#define MCALCRY_NO_KEYDERIVESPAKE2PIDXOFOBJECTINFO                                          255u
#define MCALCRY_NO_KEYDERIVEX963SHA256IDXOFOBJECTINFO                                       255u
#define MCALCRY_NO_KEYDERIVEX963SHA512IDXOFOBJECTINFO                                       255u
#define MCALCRY_NO_KEYGENED25519IDXOFOBJECTINFO                                             255u
#define MCALCRY_NO_KEYGENP256R1IDXOFOBJECTINFO                                              255u
#define MCALCRY_NO_KEYGENP384R1IDXOFOBJECTINFO                                              255u
#define MCALCRY_NO_KEYGENSYMGENERICIDXOFOBJECTINFO                                          255u
#define MCALCRY_NO_KEYP224R1BDPUBVALIDXOFOBJECTINFO                                         255u
#define MCALCRY_NO_KEYP224R1BDSECRETIDXOFOBJECTINFO                                         255u
#define MCALCRY_NO_KEYP256R1PUBVALIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_KEYP256R1SECRETIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_KEYP384R1PUBVALIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_KEYP384R1SECRETIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_KEYSEEDDRBGAESIDXOFOBJECTINFO                                            255u
#define MCALCRY_NO_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO                                     255u
#define MCALCRY_NO_KEYSEEDFIPS186IDXOFOBJECTINFO                                            255u
#define MCALCRY_NO_KEYSETVALIDIDXOFOBJECTINFO                                               255u
#define MCALCRY_NO_KEYSPAKE2PPUBVALIDXOFOBJECTINFO                                          255u
#define MCALCRY_NO_KEYSPAKE2PSECRETIDXOFOBJECTINFO                                          255u
#define MCALCRY_NO_KEYX25519PUBVALIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_KEYX25519SECRETIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_MD5IDXOFOBJECTINFO                                                       255u
#define MCALCRY_NO_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO                                       255u
#define MCALCRY_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO                                     255u
#define MCALCRY_NO_RIPEMD160IDXOFOBJECTINFO                                                 255u
#define MCALCRY_NO_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO                                     255u
#define MCALCRY_NO_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO                                   255u
#define MCALCRY_NO_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO                                        255u
#define MCALCRY_NO_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO                                        255u
#define MCALCRY_NO_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO                                      255u
#define MCALCRY_NO_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO                                      255u
#define MCALCRY_NO_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO                                       255u
#define MCALCRY_NO_RSAPKCS1DECRYPTIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_RSAPKCS1ENCRYPTIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_RSAPKCS1GENERATEIDXOFOBJECTINFO                                          255u
#define MCALCRY_NO_RSAPKCS1VERIFYIDXOFOBJECTINFO                                            255u
#define MCALCRY_NO_RSAPSSGENERATEIDXOFOBJECTINFO                                            255u
#define MCALCRY_NO_RSAPSSVERIFYIDXOFOBJECTINFO                                              255u
#define MCALCRY_NO_SHA1IDXOFOBJECTINFO                                                      255u
#define MCALCRY_NO_SHA256IDXOFOBJECTINFO                                                    255u
#define MCALCRY_NO_SHA384IDXOFOBJECTINFO                                                    255u
#define MCALCRY_NO_SHA3_256IDXOFOBJECTINFO                                                  255u
#define MCALCRY_NO_SHA512IDXOFOBJECTINFO                                                    255u
#define MCALCRY_NO_SHECMDGETIDIDXOFOBJECTINFO                                               255u
#define MCALCRY_NO_SIPHASHGENERATEIDXOFOBJECTINFO                                           255u
#define MCALCRY_NO_SIPHASHVERIFYIDXOFOBJECTINFO                                             255u
#define MCALCRY_NO_OBJECTINFOINDENDIDXOFPRIMITIVEFCT                                        255u
#define MCALCRY_NO_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT                                      255u
#define MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO                                255u
#define MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO                              255u
#define MCALCRY_NO_EXPECTEDCOMPATIBILITYVERSION                                             65535u

#define MCALCRY_ONCEOFKEYELEMENTINFO_MASK                                                   0x04u
#define MCALCRY_PARTIALOFKEYELEMENTINFO_MASK                                                0x02u
#define MCALCRY_PERSISTOFKEYELEMENTINFO_MASK                                                0x01u
#define MCALCRY_CONTEXTOFPRIMITIVEINFO_MASK                                                 0x02u
#define MCALCRY_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO_MASK                                     0x01u

#define MCALCRY_ISDEF_WORKSPACEOFAEADCHACHAPOLY1305DECRYPT                                  STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFAEADCHACHAPOLY1305ENCRYPT                                  STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFAESCCMDECRYPT                                              STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFAESCCMENCRYPT                                              STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFAESDECRYPT                                                 STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFAESENCRYPT                                                 STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFAESGCMDECRYPT                                              STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFAESGCMENCRYPT                                              STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFCMACAESGENERATE                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFCMACAESVERIFY                                              STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFDRBGAES                                                    STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFDRBGHASHSHA512                                             STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFECP160GENERATE                                             STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFECP160VERIFY                                               STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFECP256GENERATE                                             STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFECP256VERIFY                                               STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFECP384GENERATE                                             STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFECP384VERIFY                                               STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFED25519GENERATE                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFED25519VERIFY                                              STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFFIPS186                                                    STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFGMACAESGENERATE                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFGMACAESVERIFY                                              STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFHMACRIPEMD160GENERATE                                      STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFHMACRIPEMD160VERIFY                                        STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFHMACSHA1GENERATE                                           STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFHMACSHA1VERIFY                                             STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFHMACSHA256GENERATE                                         STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFHMACSHA256VERIFY                                           STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFHMACSHA384GENERATE                                         STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFHMACSHA384VERIFY                                           STD_OFF
#define MCALCRY_ISDEF_INITVALUE                                                             STD_OFF
#define MCALCRY_ISDEF_KEYELEMENTSENDIDXOFKEY                                                STD_OFF
#define MCALCRY_ISDEF_KEYELEMENTSSTARTIDXOFKEY                                              STD_OFF
#define MCALCRY_ISDEF_NVBLOCKIDXOFKEY                                                       STD_OFF
#define MCALCRY_ISDEF_NVBLOCKUSEDOFKEY                                                      STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYDERIVEHKDFHMACSHA256                                    STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1                                   STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYDERIVEISO15118                                          STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYDERIVEKDF2HMACSHA1                                      STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYDERIVEKDF2HMACSHA256                                    STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYDERIVENIST800108CNT                                     STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYDERIVENIST80056AONEPASS                                 STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYDERIVENISTFIPS186ERB                                    STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYDERIVESPAKE2P                                           STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYDERIVEX963SHA256                                        STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYDERIVEX963SHA512                                        STD_OFF
#define MCALCRY_ISDEF_IDOFKEYELEMENTINFO                                                    STD_OFF
#define MCALCRY_ISDEF_INITVALUEENDIDXOFKEYELEMENTINFO                                       STD_OFF
#define MCALCRY_ISDEF_INITVALUESTARTIDXOFKEYELEMENTINFO                                     STD_OFF
#define MCALCRY_ISDEF_INITVALUEUSEDOFKEYELEMENTINFO                                         STD_OFF
#define MCALCRY_ISDEF_LENGTHOFKEYELEMENTINFO                                                STD_OFF
#define MCALCRY_ISDEF_MASKEDBITSOFKEYELEMENTINFO                                            STD_OFF
#define MCALCRY_ISDEF_ONCEOFKEYELEMENTINFO                                                  STD_OFF
#define MCALCRY_ISDEF_PARTIALOFKEYELEMENTINFO                                               STD_OFF
#define MCALCRY_ISDEF_PERSISTOFKEYELEMENTINFO                                               STD_OFF
#define MCALCRY_ISDEF_READOFKEYELEMENTINFO                                                  STD_OFF
#define MCALCRY_ISDEF_WRITEOFKEYELEMENTINFO                                                 STD_OFF
#define MCALCRY_ISDEF_IDOFKEYELEMENTS                                                       STD_OFF
#define MCALCRY_ISDEF_KEYELEMENTINFOIDXOFKEYELEMENTS                                        STD_OFF
#define MCALCRY_ISDEF_KEYSTORAGEENDIDXOFKEYELEMENTS                                         STD_OFF
#define MCALCRY_ISDEF_KEYSTORAGEEXTENSIONIDXOFKEYELEMENTS                                   STD_OFF
#define MCALCRY_ISDEF_KEYSTORAGESTARTIDXOFKEYELEMENTS                                       STD_OFF
#define MCALCRY_ISDEF_KEYSTORAGEVALIDIDXOFKEYELEMENTS                                       STD_OFF
#define MCALCRY_ISDEF_KEYSTORAGEWRITTENLENGTHENDIDXOFKEYELEMENTS                            STD_OFF
#define MCALCRY_ISDEF_KEYSTORAGEWRITTENLENGTHSTARTIDXOFKEYELEMENTS                          STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYGENED25519                                              STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYGENP256R1                                               STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYGENP384R1                                               STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYGENSYMGENERIC                                           STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYP224R1BDPUBVAL                                          STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYP224R1BDSECRET                                          STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYP256R1PUBVAL                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYP256R1SECRET                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYP384R1PUBVAL                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYP384R1SECRET                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYSEEDDRBGAES                                             STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYSEEDDRBGHASHSHA512                                      STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYSEEDFIPS186                                             STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYSETVALID                                                STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYSPAKE2PPUBVAL                                           STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYSPAKE2PSECRET                                           STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYX25519PUBVAL                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFKEYX25519SECRET                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFMD5                                                        STD_OFF
#define MCALCRY_ISDEF_CONSISTENCYLEVELOFNVBLOCK                                             STD_OFF
#define MCALCRY_ISDEF_CRCOFNVBLOCK                                                          STD_OFF
#define MCALCRY_ISDEF_DESCRIPTOROFNVBLOCK                                                   STD_OFF
#define MCALCRY_ISDEF_IDOFNVBLOCK                                                           STD_OFF
#define MCALCRY_ISDEF_KEYSTORAGEENDIDXOFNVBLOCK                                             STD_OFF
#define MCALCRY_ISDEF_KEYSTORAGESTARTIDXOFNVBLOCK                                           STD_OFF
#define MCALCRY_ISDEF_LENGTHOFNVBLOCK                                                       STD_OFF
#define MCALCRY_ISDEF_PROCESSINGOFNVBLOCK                                                   STD_OFF
#define MCALCRY_ISDEF_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO                              STD_OFF
#define MCALCRY_ISDEF_AEADCHACHAPOLY1305DECRYPTUSEDOFOBJECTINFO                             STD_OFF
#define MCALCRY_ISDEF_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO                              STD_OFF
#define MCALCRY_ISDEF_AEADCHACHAPOLY1305ENCRYPTUSEDOFOBJECTINFO                             STD_OFF
#define MCALCRY_ISDEF_AESCCMDECRYPTIDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_AESCCMDECRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_AESCCMENCRYPTIDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_AESCCMENCRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_AESDECRYPTIDXOFOBJECTINFO                                             STD_OFF
#define MCALCRY_ISDEF_AESDECRYPTUSEDOFOBJECTINFO                                            STD_OFF
#define MCALCRY_ISDEF_AESENCRYPTIDXOFOBJECTINFO                                             STD_OFF
#define MCALCRY_ISDEF_AESENCRYPTUSEDOFOBJECTINFO                                            STD_OFF
#define MCALCRY_ISDEF_AESGCMDECRYPTIDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_AESGCMDECRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_AESGCMENCRYPTIDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_AESGCMENCRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_CMACAESGENERATEIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_CMACAESGENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_CMACAESVERIFYIDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_CMACAESVERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_DRBGAESIDXOFOBJECTINFO                                                STD_OFF
#define MCALCRY_ISDEF_DRBGAESUSEDOFOBJECTINFO                                               STD_OFF
#define MCALCRY_ISDEF_DRBGHASHSHA512IDXOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_DRBGHASHSHA512USEDOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_ECP160GENERATEIDXOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_ECP160GENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_ECP160VERIFYIDXOFOBJECTINFO                                           STD_OFF
#define MCALCRY_ISDEF_ECP160VERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_ECP256GENERATEIDXOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_ECP256GENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_ECP256VERIFYIDXOFOBJECTINFO                                           STD_OFF
#define MCALCRY_ISDEF_ECP256VERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_ECP384GENERATEIDXOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_ECP384GENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_ECP384VERIFYIDXOFOBJECTINFO                                           STD_OFF
#define MCALCRY_ISDEF_ECP384VERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_ED25519GENERATEIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_ED25519GENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_ED25519VERIFYIDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_ED25519VERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_FIPS186IDXOFOBJECTINFO                                                STD_OFF
#define MCALCRY_ISDEF_FIPS186USEDOFOBJECTINFO                                               STD_OFF
#define MCALCRY_ISDEF_GMACAESGENERATEIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_GMACAESGENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_GMACAESVERIFYIDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_GMACAESVERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_HMACRIPEMD160GENERATEIDXOFOBJECTINFO                                  STD_OFF
#define MCALCRY_ISDEF_HMACRIPEMD160GENERATEUSEDOFOBJECTINFO                                 STD_OFF
#define MCALCRY_ISDEF_HMACRIPEMD160VERIFYIDXOFOBJECTINFO                                    STD_OFF
#define MCALCRY_ISDEF_HMACRIPEMD160VERIFYUSEDOFOBJECTINFO                                   STD_OFF
#define MCALCRY_ISDEF_HMACSHA1GENERATEIDXOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_HMACSHA1GENERATEUSEDOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_HMACSHA1VERIFYIDXOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_HMACSHA1VERIFYUSEDOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_HMACSHA256GENERATEIDXOFOBJECTINFO                                     STD_OFF
#define MCALCRY_ISDEF_HMACSHA256GENERATEUSEDOFOBJECTINFO                                    STD_OFF
#define MCALCRY_ISDEF_HMACSHA256VERIFYIDXOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_HMACSHA256VERIFYUSEDOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_HMACSHA384GENERATEIDXOFOBJECTINFO                                     STD_OFF
#define MCALCRY_ISDEF_HMACSHA384GENERATEUSEDOFOBJECTINFO                                    STD_OFF
#define MCALCRY_ISDEF_HMACSHA384VERIFYIDXOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_HMACSHA384VERIFYUSEDOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO                                STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEHKDFHMACSHA256USEDOFOBJECTINFO                               STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEHKDFHASHOPTION1IDXOFOBJECTINFO                               STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEHKDFHASHOPTION1USEDOFOBJECTINFO                              STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEISO15118IDXOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEISO15118USEDOFOBJECTINFO                                     STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO                                  STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEKDF2HMACSHA1USEDOFOBJECTINFO                                 STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO                                STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEKDF2HMACSHA256USEDOFOBJECTINFO                               STD_OFF
#define MCALCRY_ISDEF_KEYDERIVENIST800108CNTIDXOFOBJECTINFO                                 STD_OFF
#define MCALCRY_ISDEF_KEYDERIVENIST800108CNTUSEDOFOBJECTINFO                                STD_OFF
#define MCALCRY_ISDEF_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO                             STD_OFF
#define MCALCRY_ISDEF_KEYDERIVENIST80056AONEPASSUSEDOFOBJECTINFO                            STD_OFF
#define MCALCRY_ISDEF_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO                                STD_OFF
#define MCALCRY_ISDEF_KEYDERIVENISTFIPS186ERBUSEDOFOBJECTINFO                               STD_OFF
#define MCALCRY_ISDEF_KEYDERIVESPAKE2PIDXOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_KEYDERIVESPAKE2PUSEDOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEX963SHA256IDXOFOBJECTINFO                                    STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEX963SHA256USEDOFOBJECTINFO                                   STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEX963SHA512IDXOFOBJECTINFO                                    STD_OFF
#define MCALCRY_ISDEF_KEYDERIVEX963SHA512USEDOFOBJECTINFO                                   STD_OFF
#define MCALCRY_ISDEF_KEYGENED25519IDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_KEYGENED25519USEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_KEYGENP256R1IDXOFOBJECTINFO                                           STD_OFF
#define MCALCRY_ISDEF_KEYGENP256R1USEDOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_KEYGENP384R1IDXOFOBJECTINFO                                           STD_OFF
#define MCALCRY_ISDEF_KEYGENP384R1USEDOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_KEYGENSYMGENERICIDXOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_KEYGENSYMGENERICUSEDOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_KEYP224R1BDPUBVALIDXOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_KEYP224R1BDPUBVALUSEDOFOBJECTINFO                                     STD_OFF
#define MCALCRY_ISDEF_KEYP224R1BDSECRETIDXOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_KEYP224R1BDSECRETUSEDOFOBJECTINFO                                     STD_OFF
#define MCALCRY_ISDEF_KEYP256R1PUBVALIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_KEYP256R1PUBVALUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_KEYP256R1SECRETIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_KEYP256R1SECRETUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_KEYP384R1PUBVALIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_KEYP384R1PUBVALUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_KEYP384R1SECRETIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_KEYP384R1SECRETUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_KEYSEEDDRBGAESIDXOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_KEYSEEDDRBGAESUSEDOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO                                  STD_OFF
#define MCALCRY_ISDEF_KEYSEEDDRBGHASHSHA512USEDOFOBJECTINFO                                 STD_OFF
#define MCALCRY_ISDEF_KEYSEEDFIPS186IDXOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_KEYSEEDFIPS186USEDOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_KEYSETVALIDIDXOFOBJECTINFO                                            STD_OFF
#define MCALCRY_ISDEF_KEYSETVALIDUSEDOFOBJECTINFO                                           STD_OFF
#define MCALCRY_ISDEF_KEYSPAKE2PPUBVALIDXOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_KEYSPAKE2PPUBVALUSEDOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_KEYSPAKE2PSECRETIDXOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_KEYSPAKE2PSECRETUSEDOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_KEYX25519PUBVALIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_KEYX25519PUBVALUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_KEYX25519SECRETIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_KEYX25519SECRETUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_MD5IDXOFOBJECTINFO                                                    STD_OFF
#define MCALCRY_ISDEF_MD5USEDOFOBJECTINFO                                                   STD_OFF
#define MCALCRY_ISDEF_QUEUEIDXOFOBJECTINFO                                                  STD_OFF
#define MCALCRY_ISDEF_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO                                    STD_OFF
#define MCALCRY_ISDEF_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO                                  STD_OFF
#define MCALCRY_ISDEF_RANDOMSEEDBUFFERUSEDOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_RIPEMD160IDXOFOBJECTINFO                                              STD_OFF
#define MCALCRY_ISDEF_RIPEMD160USEDOFOBJECTINFO                                             STD_OFF
#define MCALCRY_ISDEF_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO                                  STD_OFF
#define MCALCRY_ISDEF_RSAOAEPCRTSHA1DECRYPTUSEDOFOBJECTINFO                                 STD_OFF
#define MCALCRY_ISDEF_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO                                STD_OFF
#define MCALCRY_ISDEF_RSAOAEPCRTSHA256DECRYPTUSEDOFOBJECTINFO                               STD_OFF
#define MCALCRY_ISDEF_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO                                     STD_OFF
#define MCALCRY_ISDEF_RSAOAEPSHA1DECRYPTUSEDOFOBJECTINFO                                    STD_OFF
#define MCALCRY_ISDEF_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO                                     STD_OFF
#define MCALCRY_ISDEF_RSAOAEPSHA1ENCRYPTUSEDOFOBJECTINFO                                    STD_OFF
#define MCALCRY_ISDEF_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO                                   STD_OFF
#define MCALCRY_ISDEF_RSAOAEPSHA256DECRYPTUSEDOFOBJECTINFO                                  STD_OFF
#define MCALCRY_ISDEF_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO                                   STD_OFF
#define MCALCRY_ISDEF_RSAOAEPSHA256ENCRYPTUSEDOFOBJECTINFO                                  STD_OFF
#define MCALCRY_ISDEF_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO                                    STD_OFF
#define MCALCRY_ISDEF_RSAPKCS1CRTGENERATEUSEDOFOBJECTINFO                                   STD_OFF
#define MCALCRY_ISDEF_RSAPKCS1DECRYPTIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_RSAPKCS1DECRYPTUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_RSAPKCS1ENCRYPTIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_RSAPKCS1ENCRYPTUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_RSAPKCS1GENERATEIDXOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_RSAPKCS1GENERATEUSEDOFOBJECTINFO                                      STD_OFF
#define MCALCRY_ISDEF_RSAPKCS1VERIFYIDXOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_RSAPKCS1VERIFYUSEDOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_RSAPSSGENERATEIDXOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_RSAPSSGENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_RSAPSSVERIFYIDXOFOBJECTINFO                                           STD_OFF
#define MCALCRY_ISDEF_RSAPSSVERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_SHA1IDXOFOBJECTINFO                                                   STD_OFF
#define MCALCRY_ISDEF_SHA1USEDOFOBJECTINFO                                                  STD_OFF
#define MCALCRY_ISDEF_SHA256IDXOFOBJECTINFO                                                 STD_OFF
#define MCALCRY_ISDEF_SHA256USEDOFOBJECTINFO                                                STD_OFF
#define MCALCRY_ISDEF_SHA384IDXOFOBJECTINFO                                                 STD_OFF
#define MCALCRY_ISDEF_SHA384USEDOFOBJECTINFO                                                STD_OFF
#define MCALCRY_ISDEF_SHA3_256IDXOFOBJECTINFO                                               STD_OFF
#define MCALCRY_ISDEF_SHA3_256USEDOFOBJECTINFO                                              STD_OFF
#define MCALCRY_ISDEF_SHA512IDXOFOBJECTINFO                                                 STD_OFF
#define MCALCRY_ISDEF_SHA512USEDOFOBJECTINFO                                                STD_OFF
#define MCALCRY_ISDEF_SHECMDGETIDIDXOFOBJECTINFO                                            STD_OFF
#define MCALCRY_ISDEF_SHECMDGETIDUSEDOFOBJECTINFO                                           STD_OFF
#define MCALCRY_ISDEF_SIPHASHGENERATEIDXOFOBJECTINFO                                        STD_OFF
#define MCALCRY_ISDEF_SIPHASHGENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define MCALCRY_ISDEF_SIPHASHVERIFYIDXOFOBJECTINFO                                          STD_OFF
#define MCALCRY_ISDEF_SIPHASHVERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define MCALCRY_ISDEF_WORKSPACEADDROFOBJECTINFO                                             STD_OFF
#define MCALCRY_ISDEF_WORKSPACELENGTHOFOBJECTINFO                                           STD_OFF
#define MCALCRY_ISDEF_OBJECTINFOIND                                                         STD_OFF
#define MCALCRY_ISDEF_DISPATCHOFPRIMITIVEFCT                                                STD_OFF
#define MCALCRY_ISDEF_OBJECTINFOINDENDIDXOFPRIMITIVEFCT                                     STD_OFF
#define MCALCRY_ISDEF_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT                                   STD_OFF
#define MCALCRY_ISDEF_OBJECTINFOINDUSEDOFPRIMITIVEFCT                                       STD_OFF
#define MCALCRY_ISDEF_COMBINEDOFPRIMITIVEINFO                                               STD_OFF
#define MCALCRY_ISDEF_CONTEXTOFPRIMITIVEINFO                                                STD_OFF
#define MCALCRY_ISDEF_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO                                    STD_OFF
#define MCALCRY_ISDEF_MASKEDBITSOFPRIMITIVEINFO                                             STD_OFF
#define MCALCRY_ISDEF_PRIMITIVEFCTIDXOFPRIMITIVEINFO                                        STD_OFF
#define MCALCRY_ISDEF_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO                             STD_OFF
#define MCALCRY_ISDEF_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO                           STD_OFF
#define MCALCRY_ISDEF_PRIMITIVEINFOUSEDOFPRIMITIVESERVICEINFO                               STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRIPEMD160                                                  STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAOAEPCRTSHA1DECRYPT                                      STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAOAEPCRTSHA256DECRYPT                                    STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAOAEPSHA1DECRYPT                                         STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAOAEPSHA1ENCRYPT                                         STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAOAEPSHA256DECRYPT                                       STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAOAEPSHA256ENCRYPT                                       STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAPKCS1CRTGENERATE                                        STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAPKCS1DECRYPT                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAPKCS1ENCRYPT                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAPKCS1GENERATE                                           STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAPKCS1VERIFY                                             STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAPSSGENERATE                                             STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFRSAPSSVERIFY                                               STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFSHA1                                                       STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFSHA256                                                     STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFSHA384                                                     STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFSHA3_256                                                   STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFSHA512                                                     STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFSHECMDGETID                                                STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFSIPHASHGENERATE                                            STD_OFF
#define MCALCRY_ISDEF_WORKSPACEOFSIPHASHVERIFY                                              STD_OFF
#define MCALCRY_ISDEF_AESDECRYPTOFPCCONFIG                                                  STD_ON
#define MCALCRY_ISDEF_BUFFERLENGTHOFPCCONFIG                                                STD_ON
#define MCALCRY_ISDEF_DRIVEROBJECTSTATEOFPCCONFIG                                           STD_ON
#define MCALCRY_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                STD_OFF
#define MCALCRY_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                            STD_OFF
#define MCALCRY_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                               STD_OFF
#define MCALCRY_ISDEF_HMACSHA1VERIFYOFPCCONFIG                                              STD_ON
#define MCALCRY_ISDEF_INITDATAHASHCODEOFPCCONFIG                                            STD_OFF
#define MCALCRY_ISDEF_KEYELEMENTINFOOFPCCONFIG                                              STD_ON
#define MCALCRY_ISDEF_KEYELEMENTSOFPCCONFIG                                                 STD_ON
#define MCALCRY_ISDEF_KEYLOCKOFPCCONFIG                                                     STD_ON
#define MCALCRY_ISDEF_KEYOFPCCONFIG                                                         STD_ON
#define MCALCRY_ISDEF_KEYSTORAGEOFPCCONFIG                                                  STD_ON
#define MCALCRY_ISDEF_KEYVALIDITYSETCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG          STD_OFF
#define MCALCRY_ISDEF_KEYVALUECHANGEDCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG         STD_OFF
#define MCALCRY_ISDEF_LOCKOFPCCONFIG                                                        STD_ON
#define MCALCRY_ISDEF_OBJECTINFOINDOFPCCONFIG                                               STD_ON
#define MCALCRY_ISDEF_OBJECTINFOOFPCCONFIG                                                  STD_ON
#define MCALCRY_ISDEF_PRIMITIVEFCTOFPCCONFIG                                                STD_ON
#define MCALCRY_ISDEF_PRIMITIVEINFOOFPCCONFIG                                               STD_ON
#define MCALCRY_ISDEF_PRIMITIVESERVICEINFOOFPCCONFIG                                        STD_ON
#define MCALCRY_ISDEF_QUEUEOFPCCONFIG                                                       STD_ON
#define MCALCRY_ISDEF_RSAPKCS1VERIFYOFPCCONFIG                                              STD_ON
#define MCALCRY_ISDEF_RSAPSSVERIFYOFPCCONFIG                                                STD_ON
#define MCALCRY_ISDEF_SHA512OFPCCONFIG                                                      STD_ON
#define MCALCRY_ISDEF_SHEDEBUGCMDOFSHEKEYUPDATEOFPCCONFIG                                   STD_OFF
#define MCALCRY_ISDEF_SHEENABLECOUNTEROFSHEKEYUPDATEOFPCCONFIG                              STD_OFF
#define MCALCRY_ISDEF_SHEENABLEFIDOFSHEKEYUPDATEOFPCCONFIG                                  STD_OFF
#define MCALCRY_ISDEF_SHEINFOKEYREFOFSHEKEYUPDATEOFPCCONFIG                                 STD_OFF
#define MCALCRY_ISDEF_UNIONWS_MCALCRYOFPCCONFIG                                     STD_ON
#define MCALCRY_ISDEF_UNIONWS_MCALCRY_AESOFPCCONFIG                                 STD_ON
#define MCALCRY_ISDEF_WRITTENLENGTHOFPCCONFIG                                               STD_ON

#define MCALCRY_EQ2_WORKSPACEOFAEADCHACHAPOLY1305DECRYPT
#define MCALCRY_EQ2_WORKSPACEOFAEADCHACHAPOLY1305ENCRYPT
#define MCALCRY_EQ2_WORKSPACEOFAESCCMDECRYPT
#define MCALCRY_EQ2_WORKSPACEOFAESCCMENCRYPT
#define MCALCRY_EQ2_WORKSPACEOFAESDECRYPT
#define MCALCRY_EQ2_WORKSPACEOFAESENCRYPT
#define MCALCRY_EQ2_WORKSPACEOFAESGCMDECRYPT
#define MCALCRY_EQ2_WORKSPACEOFAESGCMENCRYPT
#define MCALCRY_EQ2_WORKSPACEOFCMACAESGENERATE
#define MCALCRY_EQ2_WORKSPACEOFCMACAESVERIFY
#define MCALCRY_EQ2_WORKSPACEOFDRBGAES
#define MCALCRY_EQ2_WORKSPACEOFDRBGHASHSHA512
#define MCALCRY_EQ2_WORKSPACEOFECP160GENERATE
#define MCALCRY_EQ2_WORKSPACEOFECP160VERIFY
#define MCALCRY_EQ2_WORKSPACEOFECP256GENERATE
#define MCALCRY_EQ2_WORKSPACEOFECP256VERIFY
#define MCALCRY_EQ2_WORKSPACEOFECP384GENERATE
#define MCALCRY_EQ2_WORKSPACEOFECP384VERIFY
#define MCALCRY_EQ2_WORKSPACEOFED25519GENERATE
#define MCALCRY_EQ2_WORKSPACEOFED25519VERIFY
#define MCALCRY_EQ2_WORKSPACEOFFIPS186
#define MCALCRY_EQ2_WORKSPACEOFGMACAESGENERATE
#define MCALCRY_EQ2_WORKSPACEOFGMACAESVERIFY
#define MCALCRY_EQ2_WORKSPACEOFHMACRIPEMD160GENERATE
#define MCALCRY_EQ2_WORKSPACEOFHMACRIPEMD160VERIFY
#define MCALCRY_EQ2_WORKSPACEOFHMACSHA1GENERATE
#define MCALCRY_EQ2_WORKSPACEOFHMACSHA1VERIFY
#define MCALCRY_EQ2_WORKSPACEOFHMACSHA256GENERATE
#define MCALCRY_EQ2_WORKSPACEOFHMACSHA256VERIFY
#define MCALCRY_EQ2_WORKSPACEOFHMACSHA384GENERATE
#define MCALCRY_EQ2_WORKSPACEOFHMACSHA384VERIFY
#define MCALCRY_EQ2_INITVALUE
#define MCALCRY_EQ2_KEYELEMENTSENDIDXOFKEY
#define MCALCRY_EQ2_KEYELEMENTSSTARTIDXOFKEY
#define MCALCRY_EQ2_NVBLOCKIDXOFKEY
#define MCALCRY_EQ2_NVBLOCKUSEDOFKEY
#define MCALCRY_EQ2_WORKSPACEOFKEYDERIVEHKDFHMACSHA256
#define MCALCRY_EQ2_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1
#define MCALCRY_EQ2_WORKSPACEOFKEYDERIVEISO15118
#define MCALCRY_EQ2_WORKSPACEOFKEYDERIVEKDF2HMACSHA1
#define MCALCRY_EQ2_WORKSPACEOFKEYDERIVEKDF2HMACSHA256
#define MCALCRY_EQ2_WORKSPACEOFKEYDERIVENIST800108CNT
#define MCALCRY_EQ2_WORKSPACEOFKEYDERIVENIST80056AONEPASS
#define MCALCRY_EQ2_WORKSPACEOFKEYDERIVENISTFIPS186ERB
#define MCALCRY_EQ2_WORKSPACEOFKEYDERIVESPAKE2P
#define MCALCRY_EQ2_WORKSPACEOFKEYDERIVEX963SHA256
#define MCALCRY_EQ2_WORKSPACEOFKEYDERIVEX963SHA512
#define MCALCRY_EQ2_IDOFKEYELEMENTINFO
#define MCALCRY_EQ2_INITVALUEENDIDXOFKEYELEMENTINFO
#define MCALCRY_EQ2_INITVALUESTARTIDXOFKEYELEMENTINFO
#define MCALCRY_EQ2_INITVALUEUSEDOFKEYELEMENTINFO
#define MCALCRY_EQ2_LENGTHOFKEYELEMENTINFO
#define MCALCRY_EQ2_MASKEDBITSOFKEYELEMENTINFO
#define MCALCRY_EQ2_ONCEOFKEYELEMENTINFO
#define MCALCRY_EQ2_PARTIALOFKEYELEMENTINFO
#define MCALCRY_EQ2_PERSISTOFKEYELEMENTINFO
#define MCALCRY_EQ2_READOFKEYELEMENTINFO
#define MCALCRY_EQ2_WRITEOFKEYELEMENTINFO
#define MCALCRY_EQ2_IDOFKEYELEMENTS
#define MCALCRY_EQ2_KEYELEMENTINFOIDXOFKEYELEMENTS
#define MCALCRY_EQ2_KEYSTORAGEENDIDXOFKEYELEMENTS
#define MCALCRY_EQ2_KEYSTORAGEEXTENSIONIDXOFKEYELEMENTS
#define MCALCRY_EQ2_KEYSTORAGESTARTIDXOFKEYELEMENTS
#define MCALCRY_EQ2_KEYSTORAGEVALIDIDXOFKEYELEMENTS
#define MCALCRY_EQ2_KEYSTORAGEWRITTENLENGTHENDIDXOFKEYELEMENTS
#define MCALCRY_EQ2_KEYSTORAGEWRITTENLENGTHSTARTIDXOFKEYELEMENTS
#define MCALCRY_EQ2_WORKSPACEOFKEYGENED25519
#define MCALCRY_EQ2_WORKSPACEOFKEYGENP256R1
#define MCALCRY_EQ2_WORKSPACEOFKEYGENP384R1
#define MCALCRY_EQ2_WORKSPACEOFKEYGENSYMGENERIC
#define MCALCRY_EQ2_WORKSPACEOFKEYP224R1BDPUBVAL
#define MCALCRY_EQ2_WORKSPACEOFKEYP224R1BDSECRET
#define MCALCRY_EQ2_WORKSPACEOFKEYP256R1PUBVAL
#define MCALCRY_EQ2_WORKSPACEOFKEYP256R1SECRET
#define MCALCRY_EQ2_WORKSPACEOFKEYP384R1PUBVAL
#define MCALCRY_EQ2_WORKSPACEOFKEYP384R1SECRET
#define MCALCRY_EQ2_WORKSPACEOFKEYSEEDDRBGAES
#define MCALCRY_EQ2_WORKSPACEOFKEYSEEDDRBGHASHSHA512
#define MCALCRY_EQ2_WORKSPACEOFKEYSEEDFIPS186
#define MCALCRY_EQ2_WORKSPACEOFKEYSETVALID
#define MCALCRY_EQ2_WORKSPACEOFKEYSPAKE2PPUBVAL
#define MCALCRY_EQ2_WORKSPACEOFKEYSPAKE2PSECRET
#define MCALCRY_EQ2_WORKSPACEOFKEYX25519PUBVAL
#define MCALCRY_EQ2_WORKSPACEOFKEYX25519SECRET
#define MCALCRY_EQ2_WORKSPACEOFMD5
#define MCALCRY_EQ2_CONSISTENCYLEVELOFNVBLOCK
#define MCALCRY_EQ2_CRCOFNVBLOCK
#define MCALCRY_EQ2_DESCRIPTOROFNVBLOCK
#define MCALCRY_EQ2_IDOFNVBLOCK
#define MCALCRY_EQ2_KEYSTORAGEENDIDXOFNVBLOCK
#define MCALCRY_EQ2_KEYSTORAGESTARTIDXOFNVBLOCK
#define MCALCRY_EQ2_LENGTHOFNVBLOCK
#define MCALCRY_EQ2_PROCESSINGOFNVBLOCK
#define MCALCRY_EQ2_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_AEADCHACHAPOLY1305DECRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_AEADCHACHAPOLY1305ENCRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_AESCCMDECRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_AESCCMDECRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_AESCCMENCRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_AESCCMENCRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_AESDECRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_AESDECRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_AESENCRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_AESENCRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_AESGCMDECRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_AESGCMDECRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_AESGCMENCRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_AESGCMENCRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_CMACAESGENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_CMACAESGENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_CMACAESVERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_CMACAESVERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_DRBGAESIDXOFOBJECTINFO
#define MCALCRY_EQ2_DRBGAESUSEDOFOBJECTINFO
#define MCALCRY_EQ2_DRBGHASHSHA512IDXOFOBJECTINFO
#define MCALCRY_EQ2_DRBGHASHSHA512USEDOFOBJECTINFO
#define MCALCRY_EQ2_ECP160GENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_ECP160GENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_ECP160VERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_ECP160VERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_ECP256GENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_ECP256GENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_ECP256VERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_ECP256VERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_ECP384GENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_ECP384GENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_ECP384VERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_ECP384VERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_ED25519GENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_ED25519GENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_ED25519VERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_ED25519VERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_FIPS186IDXOFOBJECTINFO
#define MCALCRY_EQ2_FIPS186USEDOFOBJECTINFO
#define MCALCRY_EQ2_GMACAESGENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_GMACAESGENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_GMACAESVERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_GMACAESVERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_HMACRIPEMD160GENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_HMACRIPEMD160GENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_HMACRIPEMD160VERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_HMACRIPEMD160VERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA1GENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA1GENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA1VERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA1VERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA256GENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA256GENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA256VERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA256VERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA384GENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA384GENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA384VERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_HMACSHA384VERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEHKDFHMACSHA256USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEHKDFHASHOPTION1IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEHKDFHASHOPTION1USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEISO15118IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEISO15118USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEKDF2HMACSHA1USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEKDF2HMACSHA256USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVENIST800108CNTIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVENIST800108CNTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVENIST80056AONEPASSUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVENISTFIPS186ERBUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVESPAKE2PIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVESPAKE2PUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEX963SHA256IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEX963SHA256USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEX963SHA512IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYDERIVEX963SHA512USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYGENED25519IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYGENED25519USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYGENP256R1IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYGENP256R1USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYGENP384R1IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYGENP384R1USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYGENSYMGENERICIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYGENSYMGENERICUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYP224R1BDPUBVALIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYP224R1BDPUBVALUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYP224R1BDSECRETIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYP224R1BDSECRETUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYP256R1PUBVALIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYP256R1PUBVALUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYP256R1SECRETIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYP256R1SECRETUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYP384R1PUBVALIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYP384R1PUBVALUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYP384R1SECRETIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYP384R1SECRETUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYSEEDDRBGAESIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYSEEDDRBGAESUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYSEEDDRBGHASHSHA512USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYSEEDFIPS186IDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYSEEDFIPS186USEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYSETVALIDIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYSETVALIDUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYSPAKE2PPUBVALIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYSPAKE2PPUBVALUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYSPAKE2PSECRETIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYSPAKE2PSECRETUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYX25519PUBVALIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYX25519PUBVALUSEDOFOBJECTINFO
#define MCALCRY_EQ2_KEYX25519SECRETIDXOFOBJECTINFO
#define MCALCRY_EQ2_KEYX25519SECRETUSEDOFOBJECTINFO
#define MCALCRY_EQ2_MD5IDXOFOBJECTINFO
#define MCALCRY_EQ2_MD5USEDOFOBJECTINFO
#define MCALCRY_EQ2_QUEUEIDXOFOBJECTINFO
#define MCALCRY_EQ2_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO
#define MCALCRY_EQ2_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO
#define MCALCRY_EQ2_RANDOMSEEDBUFFERUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RIPEMD160IDXOFOBJECTINFO
#define MCALCRY_EQ2_RIPEMD160USEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPCRTSHA1DECRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPCRTSHA256DECRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPSHA1DECRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPSHA1ENCRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPSHA256DECRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAOAEPSHA256ENCRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAPKCS1CRTGENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAPKCS1DECRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAPKCS1DECRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAPKCS1ENCRYPTIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAPKCS1ENCRYPTUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAPKCS1GENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAPKCS1GENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAPKCS1VERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAPKCS1VERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAPSSGENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAPSSGENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_RSAPSSVERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_RSAPSSVERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_SHA1IDXOFOBJECTINFO
#define MCALCRY_EQ2_SHA1USEDOFOBJECTINFO
#define MCALCRY_EQ2_SHA256IDXOFOBJECTINFO
#define MCALCRY_EQ2_SHA256USEDOFOBJECTINFO
#define MCALCRY_EQ2_SHA384IDXOFOBJECTINFO
#define MCALCRY_EQ2_SHA384USEDOFOBJECTINFO
#define MCALCRY_EQ2_SHA3_256IDXOFOBJECTINFO
#define MCALCRY_EQ2_SHA3_256USEDOFOBJECTINFO
#define MCALCRY_EQ2_SHA512IDXOFOBJECTINFO
#define MCALCRY_EQ2_SHA512USEDOFOBJECTINFO
#define MCALCRY_EQ2_SHECMDGETIDIDXOFOBJECTINFO
#define MCALCRY_EQ2_SHECMDGETIDUSEDOFOBJECTINFO
#define MCALCRY_EQ2_SIPHASHGENERATEIDXOFOBJECTINFO
#define MCALCRY_EQ2_SIPHASHGENERATEUSEDOFOBJECTINFO
#define MCALCRY_EQ2_SIPHASHVERIFYIDXOFOBJECTINFO
#define MCALCRY_EQ2_SIPHASHVERIFYUSEDOFOBJECTINFO
#define MCALCRY_EQ2_WORKSPACEADDROFOBJECTINFO
#define MCALCRY_EQ2_WORKSPACELENGTHOFOBJECTINFO
#define MCALCRY_EQ2_OBJECTINFOIND
#define MCALCRY_EQ2_DISPATCHOFPRIMITIVEFCT
#define MCALCRY_EQ2_OBJECTINFOINDENDIDXOFPRIMITIVEFCT
#define MCALCRY_EQ2_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT
#define MCALCRY_EQ2_OBJECTINFOINDUSEDOFPRIMITIVEFCT
#define MCALCRY_EQ2_COMBINEDOFPRIMITIVEINFO
#define MCALCRY_EQ2_CONTEXTOFPRIMITIVEINFO
#define MCALCRY_EQ2_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO
#define MCALCRY_EQ2_MASKEDBITSOFPRIMITIVEINFO
#define MCALCRY_EQ2_PRIMITIVEFCTIDXOFPRIMITIVEINFO
#define MCALCRY_EQ2_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO
#define MCALCRY_EQ2_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO
#define MCALCRY_EQ2_PRIMITIVEINFOUSEDOFPRIMITIVESERVICEINFO
#define MCALCRY_EQ2_WORKSPACEOFRIPEMD160
#define MCALCRY_EQ2_WORKSPACEOFRSAOAEPCRTSHA1DECRYPT
#define MCALCRY_EQ2_WORKSPACEOFRSAOAEPCRTSHA256DECRYPT
#define MCALCRY_EQ2_WORKSPACEOFRSAOAEPSHA1DECRYPT
#define MCALCRY_EQ2_WORKSPACEOFRSAOAEPSHA1ENCRYPT
#define MCALCRY_EQ2_WORKSPACEOFRSAOAEPSHA256DECRYPT
#define MCALCRY_EQ2_WORKSPACEOFRSAOAEPSHA256ENCRYPT
#define MCALCRY_EQ2_WORKSPACEOFRSAPKCS1CRTGENERATE
#define MCALCRY_EQ2_WORKSPACEOFRSAPKCS1DECRYPT
#define MCALCRY_EQ2_WORKSPACEOFRSAPKCS1ENCRYPT
#define MCALCRY_EQ2_WORKSPACEOFRSAPKCS1GENERATE
#define MCALCRY_EQ2_WORKSPACEOFRSAPKCS1VERIFY
#define MCALCRY_EQ2_WORKSPACEOFRSAPSSGENERATE
#define MCALCRY_EQ2_WORKSPACEOFRSAPSSVERIFY
#define MCALCRY_EQ2_WORKSPACEOFSHA1
#define MCALCRY_EQ2_WORKSPACEOFSHA256
#define MCALCRY_EQ2_WORKSPACEOFSHA384
#define MCALCRY_EQ2_WORKSPACEOFSHA3_256
#define MCALCRY_EQ2_WORKSPACEOFSHA512
#define MCALCRY_EQ2_WORKSPACEOFSHECMDGETID
#define MCALCRY_EQ2_WORKSPACEOFSIPHASHGENERATE
#define MCALCRY_EQ2_WORKSPACEOFSIPHASHVERIFY
#define MCALCRY_EQ2_AESDECRYPTOFPCCONFIG                                                    McalCry_AesDecrypt
#define MCALCRY_EQ2_BUFFERLENGTHOFPCCONFIG                                                  McalCry_BufferLength
#define MCALCRY_EQ2_DRIVEROBJECTSTATEOFPCCONFIG                                             McalCry_DriverObjectState
#define MCALCRY_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG
#define MCALCRY_EQ2_FINALMAGICNUMBEROFPCCONFIG
#define MCALCRY_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG
#define MCALCRY_EQ2_HMACSHA1VERIFYOFPCCONFIG                                                McalCry_HmacSha1Verify
#define MCALCRY_EQ2_INITDATAHASHCODEOFPCCONFIG
#define MCALCRY_EQ2_KEYELEMENTINFOOFPCCONFIG                                                McalCry_KeyElementInfo
#define MCALCRY_EQ2_KEYELEMENTSOFPCCONFIG                                                   McalCry_KeyElements
#define MCALCRY_EQ2_KEYLOCKOFPCCONFIG                                                       McalCry_KeyLock.raw
#define MCALCRY_EQ2_KEYOFPCCONFIG                                                           McalCry_Key
#define MCALCRY_EQ2_KEYSTORAGEOFPCCONFIG                                                    McalCry_KeyStorage
#define MCALCRY_EQ2_KEYVALIDITYSETCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG
#define MCALCRY_EQ2_KEYVALUECHANGEDCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG
#define MCALCRY_EQ2_LOCKOFPCCONFIG                                                          McalCry_Lock
#define MCALCRY_EQ2_OBJECTINFOINDOFPCCONFIG                                                 McalCry_ObjectInfoInd
#define MCALCRY_EQ2_OBJECTINFOOFPCCONFIG                                                    McalCry_ObjectInfo
#define MCALCRY_EQ2_PRIMITIVEFCTOFPCCONFIG                                                  McalCry_PrimitiveFct
#define MCALCRY_EQ2_PRIMITIVEINFOOFPCCONFIG                                                 McalCry_PrimitiveInfo
#define MCALCRY_EQ2_PRIMITIVESERVICEINFOOFPCCONFIG                                          McalCry_PrimitiveServiceInfo
#define MCALCRY_EQ2_QUEUEOFPCCONFIG                                                         McalCry_Queue.raw
#define MCALCRY_EQ2_RSAPKCS1VERIFYOFPCCONFIG                                                McalCry_RsaPkcs1Verify
#define MCALCRY_EQ2_RSAPSSVERIFYOFPCCONFIG                                                  McalCry_RsaPssVerify
#define MCALCRY_EQ2_SHA512OFPCCONFIG                                                        McalCry_SHA512
#define MCALCRY_EQ2_SHEDEBUGCMDOFSHEKEYUPDATEOFPCCONFIG
#define MCALCRY_EQ2_SHEENABLECOUNTEROFSHEKEYUPDATEOFPCCONFIG
#define MCALCRY_EQ2_SHEENABLEFIDOFSHEKEYUPDATEOFPCCONFIG
#define MCALCRY_EQ2_SHEINFOKEYREFOFSHEKEYUPDATEOFPCCONFIG
#define MCALCRY_EQ2_UNIONWS_MCALCRYOFPCCONFIG                                       (&(McalCry_UnionWS_McalCry))
#define MCALCRY_EQ2_UNIONWS_MCALCRY_AESOFPCCONFIG                                   (&(McalCry_UnionWS_McalCry_Aes))
#define MCALCRY_EQ2_WRITTENLENGTHOFPCCONFIG                                                 McalCry_WrittenLength

#define McalCry_Config_Ptr                                                                  NULL_PTR

#define McalCry_Config                                                                      NULL_PTR

#define MCALCRY_CHECK_INIT_POINTER                                                          STD_OFF
#define MCALCRY_FINAL_MAGIC_NUMBER                                                          0xFF1Eu
#define MCALCRY_INDIVIDUAL_POSTBUILD                                                        STD_OFF
#define MCALCRY_INIT_DATA                                                                   MCALCRY_CONST
#define MCALCRY_INIT_DATA_HASH_CODE                                                         2027971617
#define MCALCRY_USE_ECUM_BSW_ERROR_HOOK                                                     STD_OFF
#define MCALCRY_USE_INIT_POINTER                                                            STD_OFF

#define MCALCRY_PBCONFIG                                                                    STD_OFF
#define MCALCRY_LTCONFIGIDXOFPBCONFIG                                                       STD_OFF
#define MCALCRY_PCCONFIGIDXOFPBCONFIG                                                       STD_OFF

#define MCALCRY_ISDEF_LTCONFIGIDXOFPBCONFIG                                                 STD_OFF
#define MCALCRY_ISDEF_PCCONFIGIDXOFPBCONFIG                                                 STD_OFF

#define MCALCRY_EQ2_LTCONFIGIDXOFPBCONFIG
#define MCALCRY_EQ2_PCCONFIGIDXOFPBCONFIG

#define McalCry_GetExpectedCompatibilityVersionOfPCConfig()
#define McalCry_GetFinalMagicNumberOfPCConfig()
#define McalCry_GetGeneratorCompatibilityVersionOfPCConfig()
#define McalCry_GetInitDataHashCodeOfPCConfig()
#define McalCry_GetKeyValiditySetCalloutFctNameOfConfigurableCalloutsOfPCConfig()
#define McalCry_GetKeyValueChangedCalloutFctNameOfConfigurableCalloutsOfPCConfig()
#define McalCry_IsSheDebugCmdOfSheKeyUpdateOfPCConfig()
#define McalCry_IsSheEnableCounterOfSheKeyUpdateOfPCConfig()
#define McalCry_IsSheEnableFidOfSheKeyUpdateOfPCConfig()
#define McalCry_GetSheInfoKeyRefOfSheKeyUpdateOfPCConfig()

#define McalCry_GetAesDecryptOfPCConfig()                                                   McalCry_AesDecrypt
#define McalCry_IsAlignKeyStorageOfGeneralOfPCConfig()                                      (((FALSE)) != FALSE)
#define McalCry_GetBufferLengthOfPCConfig()                                                 McalCry_BufferLength
#define McalCry_IsCmacAesRoundkeyReuseOfMacPrimitivesOfPCConfig()                           (((FALSE)) != FALSE)
#define McalCry_GetDefaultRandomMaxRetriesOfGeneralOfPCConfig()                             10u
#define McalCry_GetDriverObjectStateOfPCConfig()                                            McalCry_DriverObjectState
#define McalCry_IsEnableAES256OfCipherPrimitivesOfPCConfig()                                (((FALSE)) != FALSE)
#define McalCry_GetHmacSha1VerifyOfPCConfig()                                               McalCry_HmacSha1Verify
#define McalCry_IsKeyElementDeleteOfGeneralOfPCConfig()                                     (((FALSE)) != FALSE)
#define McalCry_GetKeyElementInfoOfPCConfig()                                               McalCry_KeyElementInfo
#define McalCry_GetKeyElementsOfPCConfig()                                                  McalCry_KeyElements
#define McalCry_GetKeyGenerateMaxLengthOfKeyGeneratePrimitivesOfPCConfig()                  32u
#define McalCry_GetKeyLockOfPCConfig()                                                      McalCry_KeyLock.raw
#define McalCry_GetKeyOfPCConfig()                                                          McalCry_Key
#define McalCry_GetKeyStorageOfPCConfig()                                                   McalCry_KeyStorage
#define McalCry_GetLockOfPCConfig()                                                         McalCry_Lock
#define McalCry_GetMainFunctionPeriodOfGeneralOfPCConfig()                                  1u
#define McalCry_GetNumberOfLongTermPrimitiveWorkspaceOfGeneralOfPCConfig()                  0u
#define McalCry_IsNvMEnableSetRamBlockStatusOfGeneralOfPCConfig()                           (((FALSE)) != FALSE)
#define McalCry_GetNvManagementDataPerKeyOfNvStorageOfPCConfig()                            4u
#define McalCry_GetNvWriteBlockFctNameOfNvStorageOfPCConfig()                               NvM_WriteBlock
#define McalCry_GetObjectInfoIndOfPCConfig()                                                McalCry_ObjectInfoInd
#define McalCry_GetObjectInfoOfPCConfig()                                                   McalCry_ObjectInfo
#define McalCry_GetPrimitiveFctOfPCConfig()                                                 McalCry_PrimitiveFct
#define McalCry_GetPrimitiveInfoOfPCConfig()                                                McalCry_PrimitiveInfo
#define McalCry_GetPrimitiveServiceInfoOfPCConfig()                                         McalCry_PrimitiveServiceInfo
#define McalCry_GetQueueOfPCConfig()                                                        McalCry_Queue.raw
#define McalCry_IsRedirectionOfGeneralOfPCConfig()                                          (((FALSE)) != FALSE)
#define McalCry_GetRsaPkcs1VerifyOfPCConfig()                                               McalCry_RsaPkcs1Verify
#define McalCry_GetRsaPssVerifyOfPCConfig()                                                 McalCry_RsaPssVerify
#define McalCry_GetSHA512OfPCConfig()                                                       McalCry_SHA512
#define McalCry_GetSizeOfAesDecryptOfPCConfig()                                             1u
#define McalCry_GetSizeOfHmacSha1VerifyOfPCConfig()                                         1u
#define McalCry_GetSizeOfKeyElementInfoOfPCConfig()                                         11u
#define McalCry_GetSizeOfKeyElementsOfPCConfig()                                            11u
#define McalCry_GetSizeOfKeyOfPCConfig()                                                    7u
#define McalCry_GetSizeOfKeyStorageOfPCConfig()                                             924u
#define McalCry_GetSizeOfObjectInfoIndOfPCConfig()                                          5u
#define McalCry_GetSizeOfObjectInfoOfPCConfig()                                             2u
#define McalCry_GetSizeOfPrimitiveFctOfPCConfig()                                           5u
#define McalCry_GetSizeOfPrimitiveInfoOfPCConfig()                                          14u
#define McalCry_GetSizeOfPrimitiveServiceInfoOfPCConfig()                                   20u
#define McalCry_GetSizeOfQueueOfPCConfig()                                                  2u
#define McalCry_GetSizeOfRsaPkcs1VerifyOfPCConfig()                                         1u
#define McalCry_GetSizeOfRsaPssVerifyOfPCConfig()                                           1u
#define McalCry_GetSizeOfSHA512OfPCConfig()                                                 1u
#define McalCry_GetUnionWS_McalCryOfPCConfig()                                      (&(McalCry_UnionWS_McalCry))
#define McalCry_GetUnionWS_McalCry_AesOfPCConfig()                                  (&(McalCry_UnionWS_McalCry_Aes))
#define McalCry_IsUseVStdLibOfGeneralOfPCConfig()                                           (((TRUE)) != FALSE)
#define McalCry_IsVersionInfoApiOfGeneralOfPCConfig()                                       (((FALSE)) != FALSE)
#define McalCry_GetWatchdogTriggerFunctionOfGeneralOfPCConfig()                             FblLookForWatchdogVoid
#define McalCry_GetWrittenLengthOfPCConfig()                                                McalCry_WrittenLength

#define McalCry_GetSizeOfBufferLengthOfPCConfig()                                           McalCry_GetSizeOfObjectInfoOfPCConfig()
#define McalCry_GetSizeOfDriverObjectStateOfPCConfig()                                      McalCry_GetSizeOfObjectInfoOfPCConfig()
#define McalCry_GetSizeOfKeyLockOfPCConfig()                                                McalCry_GetSizeOfKeyOfPCConfig()
#define McalCry_GetSizeOfLockOfPCConfig()                                                   McalCry_GetSizeOfObjectInfoOfPCConfig()
#define McalCry_GetSizeOfWrittenLengthOfPCConfig()                                          McalCry_GetSizeOfObjectInfoOfPCConfig()

#define McalCry_GetWorkspaceOfAEADChaChaPoly1305Decrypt(Index)
#define McalCry_GetWorkspaceOfAEADChaChaPoly1305Encrypt(Index)
#define McalCry_GetWorkspaceOfAesCcmDecrypt(Index)
#define McalCry_GetWorkspaceOfAesCcmEncrypt(Index)
#define McalCry_GetWorkspaceOfAesDecrypt(Index)                                             (McalCry_GetAesDecryptOfPCConfig()[(Index)].WorkspaceOfAesDecrypt)
#define McalCry_GetWorkspaceOfAesEncrypt(Index)
#define McalCry_GetWorkspaceOfAesGcmDecrypt(Index)
#define McalCry_GetWorkspaceOfAesGcmEncrypt(Index)
#define McalCry_GetBufferLength(Index)                                                      (McalCry_GetBufferLengthOfPCConfig()[(Index)])
#define McalCry_GetWorkspaceOfCmacAesGenerate(Index)
#define McalCry_GetWorkspaceOfCmacAesVerify(Index)
#define McalCry_GetWorkspaceOfDRBGAES(Index)
#define McalCry_GetWorkspaceOfDRBGHashSha512(Index)
#define McalCry_GetDriverObjectState(Index)                                                 (McalCry_GetDriverObjectStateOfPCConfig()[(Index)])
#define McalCry_GetWorkspaceOfEcP160Generate(Index)
#define McalCry_GetWorkspaceOfEcP160Verify(Index)
#define McalCry_GetWorkspaceOfEcP256Generate(Index)
#define McalCry_GetWorkspaceOfEcP256Verify(Index)
#define McalCry_GetWorkspaceOfEcP384Generate(Index)
#define McalCry_GetWorkspaceOfEcP384Verify(Index)
#define McalCry_GetWorkspaceOfEd25519Generate(Index)
#define McalCry_GetWorkspaceOfEd25519Verify(Index)
#define McalCry_GetWorkspaceOfFips186(Index)
#define McalCry_GetWorkspaceOfGmacAesGenerate(Index)
#define McalCry_GetWorkspaceOfGmacAesVerify(Index)
#define McalCry_GetWorkspaceOfHmacRipeMd160Generate(Index)
#define McalCry_GetWorkspaceOfHmacRipeMd160Verify(Index)
#define McalCry_GetWorkspaceOfHmacSha1Generate(Index)
#define McalCry_GetWorkspaceOfHmacSha1Verify(Index)                                         (McalCry_GetHmacSha1VerifyOfPCConfig()[(Index)].WorkspaceOfHmacSha1Verify)
#define McalCry_GetWorkspaceOfHmacSha256Generate(Index)
#define McalCry_GetWorkspaceOfHmacSha256Verify(Index)
#define McalCry_GetWorkspaceOfHmacSha384Generate(Index)
#define McalCry_GetWorkspaceOfHmacSha384Verify(Index)
#define McalCry_GetInitValue(Index)
#define McalCry_GetKeyElementsEndIdxOfKey(Index)                                            (McalCry_GetKeyOfPCConfig()[(Index)].KeyElementsEndIdxOfKey)
#define McalCry_GetKeyElementsStartIdxOfKey(Index)                                          (McalCry_GetKeyOfPCConfig()[(Index)].KeyElementsStartIdxOfKey)
#define McalCry_GetNvBlockIdxOfKey(Index)
#define McalCry_IsNvBlockUsedOfKey(Index)
#define McalCry_GetWorkspaceOfKeyDeriveHKDFHMACSHA256(Index)
#define McalCry_GetWorkspaceOfKeyDeriveHKDFHashOption1(Index)
#define McalCry_GetWorkspaceOfKeyDeriveISO15118(Index)
#define McalCry_GetWorkspaceOfKeyDeriveKDF2HMACSHA1(Index)
#define McalCry_GetWorkspaceOfKeyDeriveKDF2HMACSHA256(Index)
#define McalCry_GetWorkspaceOfKeyDeriveNist800108Cnt(Index)
#define McalCry_GetWorkspaceOfKeyDeriveNist80056AOnePass(Index)
#define McalCry_GetWorkspaceOfKeyDeriveNistFips186Erb(Index)
#define McalCry_GetWorkspaceOfKeyDeriveSpake2P(Index)
#define McalCry_GetWorkspaceOfKeyDeriveX963SHA256(Index)
#define McalCry_GetWorkspaceOfKeyDeriveX963SHA512(Index)
#define McalCry_GetIdOfKeyElementInfo(Index)                                                (McalCry_GetKeyElementInfoOfPCConfig()[(Index)].IdOfKeyElementInfo)
#define McalCry_GetInitValueEndIdxOfKeyElementInfo(Index)
#define McalCry_GetInitValueStartIdxOfKeyElementInfo(Index)
#define McalCry_IsInitValueUsedOfKeyElementInfo(Index)
#define McalCry_GetLengthOfKeyElementInfo(Index)                                            (McalCry_GetKeyElementInfoOfPCConfig()[(Index)].LengthOfKeyElementInfo)
#define McalCry_GetMaskedBitsOfKeyElementInfo(Index)                                        (McalCry_GetKeyElementInfoOfPCConfig()[(Index)].MaskedBitsOfKeyElementInfo)
#define McalCry_GetReadOfKeyElementInfo(Index)                                              (McalCry_GetKeyElementInfoOfPCConfig()[(Index)].ReadOfKeyElementInfo)
#define McalCry_GetWriteOfKeyElementInfo(Index)                                             (McalCry_GetKeyElementInfoOfPCConfig()[(Index)].WriteOfKeyElementInfo)
#define McalCry_GetIdOfKeyElements(Index)                                                   (McalCry_GetKeyElementsOfPCConfig()[(Index)].IdOfKeyElements)
#define McalCry_GetKeyStorageEndIdxOfKeyElements(Index)                                     (McalCry_GetKeyElementsOfPCConfig()[(Index)].KeyStorageEndIdxOfKeyElements)
#define McalCry_GetKeyStorageStartIdxOfKeyElements(Index)                                   (McalCry_GetKeyElementsOfPCConfig()[(Index)].KeyStorageStartIdxOfKeyElements)
#define McalCry_GetWorkspaceOfKeyGenEd25519(Index)
#define McalCry_GetWorkspaceOfKeyGenP256R1(Index)
#define McalCry_GetWorkspaceOfKeyGenP384R1(Index)
#define McalCry_GetWorkspaceOfKeyGenSymGeneric(Index)
#define McalCry_GetKeyLock(Index)                                                           (McalCry_GetKeyLockOfPCConfig()[(Index)])
#define McalCry_GetWorkspaceOfKeyP224R1BDPubVal(Index)
#define McalCry_GetWorkspaceOfKeyP224R1BDSecret(Index)
#define McalCry_GetWorkspaceOfKeyP256R1PubVal(Index)
#define McalCry_GetWorkspaceOfKeyP256R1Secret(Index)
#define McalCry_GetWorkspaceOfKeyP384R1PubVal(Index)
#define McalCry_GetWorkspaceOfKeyP384R1Secret(Index)
#define McalCry_GetWorkspaceOfKeySeedDRBGAES(Index)
#define McalCry_GetWorkspaceOfKeySeedDRBGHashSha512(Index)
#define McalCry_GetWorkspaceOfKeySeedFips186(Index)
#define McalCry_GetWorkspaceOfKeySetValid(Index)
#define McalCry_GetWorkspaceOfKeySpake2PPubVal(Index)
#define McalCry_GetWorkspaceOfKeySpake2PSecret(Index)
#define McalCry_GetKeyStorage(Index)                                                        (McalCry_GetKeyStorageOfPCConfig()[(Index)])
#define McalCry_GetWorkspaceOfKeyX25519PubVal(Index)
#define McalCry_GetWorkspaceOfKeyX25519Secret(Index)
#define McalCry_GetFamilyOfLastJob(Index)
#define McalCry_GetKeyIdOfLastJob(Index)
#define McalCry_GetModeOfLastJob(Index)
#define McalCry_GetLock(Index)                                                              (McalCry_GetLockOfPCConfig()[(Index)])
#define McalCry_GetLongTermWs(Index)
#define McalCry_GetLongTermWsLock(Index)
#define McalCry_GetWorkspaceOfMD5(Index)
#define McalCry_GetConsistencyLevelOfNvBlock(Index)
#define McalCry_GetCrcOfNvBlock(Index)
#define McalCry_GetDescriptorOfNvBlock(Index)
#define McalCry_GetIdOfNvBlock(Index)
#define McalCry_GetKeyStorageEndIdxOfNvBlock(Index)
#define McalCry_GetKeyStorageStartIdxOfNvBlock(Index)
#define McalCry_GetLengthOfNvBlock(Index)
#define McalCry_GetProcessingOfNvBlock(Index)
#define McalCry_GetAEADChaChaPoly1305DecryptIdxOfObjectInfo(Index)
#define McalCry_IsAEADChaChaPoly1305DecryptUsedOfObjectInfo(Index)
#define McalCry_GetAEADChaChaPoly1305EncryptIdxOfObjectInfo(Index)
#define McalCry_IsAEADChaChaPoly1305EncryptUsedOfObjectInfo(Index)
#define McalCry_GetAesCcmDecryptIdxOfObjectInfo(Index)
#define McalCry_IsAesCcmDecryptUsedOfObjectInfo(Index)
#define McalCry_GetAesCcmEncryptIdxOfObjectInfo(Index)
#define McalCry_IsAesCcmEncryptUsedOfObjectInfo(Index)
#define McalCry_GetAesDecryptIdxOfObjectInfo(Index)                                         (McalCry_GetObjectInfoOfPCConfig()[(Index)].AesDecryptIdxOfObjectInfo)
#define McalCry_GetAesEncryptIdxOfObjectInfo(Index)
#define McalCry_IsAesEncryptUsedOfObjectInfo(Index)
#define McalCry_GetAesGcmDecryptIdxOfObjectInfo(Index)
#define McalCry_IsAesGcmDecryptUsedOfObjectInfo(Index)
#define McalCry_GetAesGcmEncryptIdxOfObjectInfo(Index)
#define McalCry_IsAesGcmEncryptUsedOfObjectInfo(Index)
#define McalCry_GetCmacAesGenerateIdxOfObjectInfo(Index)
#define McalCry_IsCmacAesGenerateUsedOfObjectInfo(Index)
#define McalCry_GetCmacAesVerifyIdxOfObjectInfo(Index)
#define McalCry_IsCmacAesVerifyUsedOfObjectInfo(Index)
#define McalCry_GetDRBGAESIdxOfObjectInfo(Index)
#define McalCry_IsDRBGAESUsedOfObjectInfo(Index)
#define McalCry_GetDRBGHashSha512IdxOfObjectInfo(Index)
#define McalCry_IsDRBGHashSha512UsedOfObjectInfo(Index)
#define McalCry_GetEcP160GenerateIdxOfObjectInfo(Index)
#define McalCry_IsEcP160GenerateUsedOfObjectInfo(Index)
#define McalCry_GetEcP160VerifyIdxOfObjectInfo(Index)
#define McalCry_IsEcP160VerifyUsedOfObjectInfo(Index)
#define McalCry_GetEcP256GenerateIdxOfObjectInfo(Index)
#define McalCry_IsEcP256GenerateUsedOfObjectInfo(Index)
#define McalCry_GetEcP256VerifyIdxOfObjectInfo(Index)
#define McalCry_IsEcP256VerifyUsedOfObjectInfo(Index)
#define McalCry_GetEcP384GenerateIdxOfObjectInfo(Index)
#define McalCry_IsEcP384GenerateUsedOfObjectInfo(Index)
#define McalCry_GetEcP384VerifyIdxOfObjectInfo(Index)
#define McalCry_IsEcP384VerifyUsedOfObjectInfo(Index)
#define McalCry_GetEd25519GenerateIdxOfObjectInfo(Index)
#define McalCry_IsEd25519GenerateUsedOfObjectInfo(Index)
#define McalCry_GetEd25519VerifyIdxOfObjectInfo(Index)
#define McalCry_IsEd25519VerifyUsedOfObjectInfo(Index)
#define McalCry_GetFips186IdxOfObjectInfo(Index)
#define McalCry_IsFips186UsedOfObjectInfo(Index)
#define McalCry_GetGmacAesGenerateIdxOfObjectInfo(Index)
#define McalCry_IsGmacAesGenerateUsedOfObjectInfo(Index)
#define McalCry_GetGmacAesVerifyIdxOfObjectInfo(Index)
#define McalCry_IsGmacAesVerifyUsedOfObjectInfo(Index)
#define McalCry_GetHmacRipeMd160GenerateIdxOfObjectInfo(Index)
#define McalCry_IsHmacRipeMd160GenerateUsedOfObjectInfo(Index)
#define McalCry_GetHmacRipeMd160VerifyIdxOfObjectInfo(Index)
#define McalCry_IsHmacRipeMd160VerifyUsedOfObjectInfo(Index)
#define McalCry_GetHmacSha1GenerateIdxOfObjectInfo(Index)
#define McalCry_IsHmacSha1GenerateUsedOfObjectInfo(Index)
#define McalCry_GetHmacSha1VerifyIdxOfObjectInfo(Index)                                     (McalCry_GetObjectInfoOfPCConfig()[(Index)].HmacSha1VerifyIdxOfObjectInfo)
#define McalCry_GetHmacSha256GenerateIdxOfObjectInfo(Index)
#define McalCry_IsHmacSha256GenerateUsedOfObjectInfo(Index)
#define McalCry_GetHmacSha256VerifyIdxOfObjectInfo(Index)
#define McalCry_IsHmacSha256VerifyUsedOfObjectInfo(Index)
#define McalCry_GetHmacSha384GenerateIdxOfObjectInfo(Index)
#define McalCry_IsHmacSha384GenerateUsedOfObjectInfo(Index)
#define McalCry_GetHmacSha384VerifyIdxOfObjectInfo(Index)
#define McalCry_IsHmacSha384VerifyUsedOfObjectInfo(Index)
#define McalCry_GetKeyDeriveHKDFHMACSHA256IdxOfObjectInfo(Index)
#define McalCry_IsKeyDeriveHKDFHMACSHA256UsedOfObjectInfo(Index)
#define McalCry_GetKeyDeriveHKDFHashOption1IdxOfObjectInfo(Index)
#define McalCry_IsKeyDeriveHKDFHashOption1UsedOfObjectInfo(Index)
#define McalCry_GetKeyDeriveISO15118IdxOfObjectInfo(Index)
#define McalCry_IsKeyDeriveISO15118UsedOfObjectInfo(Index)
#define McalCry_GetKeyDeriveKDF2HMACSHA1IdxOfObjectInfo(Index)
#define McalCry_IsKeyDeriveKDF2HMACSHA1UsedOfObjectInfo(Index)
#define McalCry_GetKeyDeriveKDF2HMACSHA256IdxOfObjectInfo(Index)
#define McalCry_IsKeyDeriveKDF2HMACSHA256UsedOfObjectInfo(Index)
#define McalCry_GetKeyDeriveNist800108CntIdxOfObjectInfo(Index)
#define McalCry_IsKeyDeriveNist800108CntUsedOfObjectInfo(Index)
#define McalCry_GetKeyDeriveNist80056AOnePassIdxOfObjectInfo(Index)
#define McalCry_IsKeyDeriveNist80056AOnePassUsedOfObjectInfo(Index)
#define McalCry_GetKeyDeriveNistFips186ErbIdxOfObjectInfo(Index)
#define McalCry_IsKeyDeriveNistFips186ErbUsedOfObjectInfo(Index)
#define McalCry_GetKeyDeriveSpake2PIdxOfObjectInfo(Index)
#define McalCry_IsKeyDeriveSpake2PUsedOfObjectInfo(Index)
#define McalCry_GetKeyDeriveX963SHA256IdxOfObjectInfo(Index)
#define McalCry_IsKeyDeriveX963SHA256UsedOfObjectInfo(Index)
#define McalCry_GetKeyDeriveX963SHA512IdxOfObjectInfo(Index)
#define McalCry_IsKeyDeriveX963SHA512UsedOfObjectInfo(Index)
#define McalCry_GetKeyGenEd25519IdxOfObjectInfo(Index)
#define McalCry_IsKeyGenEd25519UsedOfObjectInfo(Index)
#define McalCry_GetKeyGenP256R1IdxOfObjectInfo(Index)
#define McalCry_IsKeyGenP256R1UsedOfObjectInfo(Index)
#define McalCry_GetKeyGenP384R1IdxOfObjectInfo(Index)
#define McalCry_IsKeyGenP384R1UsedOfObjectInfo(Index)
#define McalCry_GetKeyGenSymGenericIdxOfObjectInfo(Index)
#define McalCry_IsKeyGenSymGenericUsedOfObjectInfo(Index)
#define McalCry_GetKeyP224R1BDPubValIdxOfObjectInfo(Index)
#define McalCry_IsKeyP224R1BDPubValUsedOfObjectInfo(Index)
#define McalCry_GetKeyP224R1BDSecretIdxOfObjectInfo(Index)
#define McalCry_IsKeyP224R1BDSecretUsedOfObjectInfo(Index)
#define McalCry_GetKeyP256R1PubValIdxOfObjectInfo(Index)
#define McalCry_IsKeyP256R1PubValUsedOfObjectInfo(Index)
#define McalCry_GetKeyP256R1SecretIdxOfObjectInfo(Index)
#define McalCry_IsKeyP256R1SecretUsedOfObjectInfo(Index)
#define McalCry_GetKeyP384R1PubValIdxOfObjectInfo(Index)
#define McalCry_IsKeyP384R1PubValUsedOfObjectInfo(Index)
#define McalCry_GetKeyP384R1SecretIdxOfObjectInfo(Index)
#define McalCry_IsKeyP384R1SecretUsedOfObjectInfo(Index)
#define McalCry_GetKeySeedDRBGAESIdxOfObjectInfo(Index)
#define McalCry_IsKeySeedDRBGAESUsedOfObjectInfo(Index)
#define McalCry_GetKeySeedDRBGHashSha512IdxOfObjectInfo(Index)
#define McalCry_IsKeySeedDRBGHashSha512UsedOfObjectInfo(Index)
#define McalCry_GetKeySeedFips186IdxOfObjectInfo(Index)
#define McalCry_IsKeySeedFips186UsedOfObjectInfo(Index)
#define McalCry_GetKeySetValidIdxOfObjectInfo(Index)
#define McalCry_IsKeySetValidUsedOfObjectInfo(Index)
#define McalCry_GetKeySpake2PPubValIdxOfObjectInfo(Index)
#define McalCry_IsKeySpake2PPubValUsedOfObjectInfo(Index)
#define McalCry_GetKeySpake2PSecretIdxOfObjectInfo(Index)
#define McalCry_IsKeySpake2PSecretUsedOfObjectInfo(Index)
#define McalCry_GetKeyX25519PubValIdxOfObjectInfo(Index)
#define McalCry_IsKeyX25519PubValUsedOfObjectInfo(Index)
#define McalCry_GetKeyX25519SecretIdxOfObjectInfo(Index)
#define McalCry_IsKeyX25519SecretUsedOfObjectInfo(Index)
#define McalCry_GetMD5IdxOfObjectInfo(Index)
#define McalCry_IsMD5UsedOfObjectInfo(Index)
#define McalCry_GetQueueIdxOfObjectInfo(Index)                                              (McalCry_GetObjectInfoOfPCConfig()[(Index)].QueueIdxOfObjectInfo)
#define McalCry_GetRandomSeedBufferEndIdxOfObjectInfo(Index)
#define McalCry_GetRandomSeedBufferStartIdxOfObjectInfo(Index)
#define McalCry_IsRandomSeedBufferUsedOfObjectInfo(Index)
#define McalCry_GetRipeMd160IdxOfObjectInfo(Index)
#define McalCry_IsRipeMd160UsedOfObjectInfo(Index)
#define McalCry_GetRsaOaepCrtSha1DecryptIdxOfObjectInfo(Index)
#define McalCry_IsRsaOaepCrtSha1DecryptUsedOfObjectInfo(Index)
#define McalCry_GetRsaOaepCrtSha256DecryptIdxOfObjectInfo(Index)
#define McalCry_IsRsaOaepCrtSha256DecryptUsedOfObjectInfo(Index)
#define McalCry_GetRsaOaepSha1DecryptIdxOfObjectInfo(Index)
#define McalCry_IsRsaOaepSha1DecryptUsedOfObjectInfo(Index)
#define McalCry_GetRsaOaepSha1EncryptIdxOfObjectInfo(Index)
#define McalCry_IsRsaOaepSha1EncryptUsedOfObjectInfo(Index)
#define McalCry_GetRsaOaepSha256DecryptIdxOfObjectInfo(Index)
#define McalCry_IsRsaOaepSha256DecryptUsedOfObjectInfo(Index)
#define McalCry_GetRsaOaepSha256EncryptIdxOfObjectInfo(Index)
#define McalCry_IsRsaOaepSha256EncryptUsedOfObjectInfo(Index)
#define McalCry_GetRsaPkcs1CrtGenerateIdxOfObjectInfo(Index)
#define McalCry_IsRsaPkcs1CrtGenerateUsedOfObjectInfo(Index)
#define McalCry_GetRsaPkcs1DecryptIdxOfObjectInfo(Index)
#define McalCry_IsRsaPkcs1DecryptUsedOfObjectInfo(Index)
#define McalCry_GetRsaPkcs1EncryptIdxOfObjectInfo(Index)
#define McalCry_IsRsaPkcs1EncryptUsedOfObjectInfo(Index)
#define McalCry_GetRsaPkcs1GenerateIdxOfObjectInfo(Index)
#define McalCry_IsRsaPkcs1GenerateUsedOfObjectInfo(Index)
#define McalCry_GetRsaPkcs1VerifyIdxOfObjectInfo(Index)                                     (McalCry_GetObjectInfoOfPCConfig()[(Index)].RsaPkcs1VerifyIdxOfObjectInfo)
#define McalCry_GetRsaPssGenerateIdxOfObjectInfo(Index)
#define McalCry_IsRsaPssGenerateUsedOfObjectInfo(Index)
#define McalCry_GetRsaPssVerifyIdxOfObjectInfo(Index)                                       (McalCry_GetObjectInfoOfPCConfig()[(Index)].RsaPssVerifyIdxOfObjectInfo)
#define McalCry_GetSHA1IdxOfObjectInfo(Index)
#define McalCry_IsSHA1UsedOfObjectInfo(Index)
#define McalCry_GetSHA256IdxOfObjectInfo(Index)
#define McalCry_IsSHA256UsedOfObjectInfo(Index)
#define McalCry_GetSHA384IdxOfObjectInfo(Index)
#define McalCry_IsSHA384UsedOfObjectInfo(Index)
#define McalCry_GetSHA3_256IdxOfObjectInfo(Index)
#define McalCry_IsSHA3_256UsedOfObjectInfo(Index)
#define McalCry_GetSHA512IdxOfObjectInfo(Index)                                             (McalCry_GetObjectInfoOfPCConfig()[(Index)].SHA512IdxOfObjectInfo)
#define McalCry_GetSheCmdGetIdIdxOfObjectInfo(Index)
#define McalCry_IsSheCmdGetIdUsedOfObjectInfo(Index)
#define McalCry_GetSipHashGenerateIdxOfObjectInfo(Index)
#define McalCry_IsSipHashGenerateUsedOfObjectInfo(Index)
#define McalCry_GetSipHashVerifyIdxOfObjectInfo(Index)
#define McalCry_IsSipHashVerifyUsedOfObjectInfo(Index)
#define McalCry_GetWorkspaceAddrOfObjectInfo(Index)                                         (McalCry_GetObjectInfoOfPCConfig()[(Index)].WorkspaceAddrOfObjectInfo)
#define McalCry_GetWorkspaceLengthOfObjectInfo(Index)                                       (McalCry_GetObjectInfoOfPCConfig()[(Index)].WorkspaceLengthOfObjectInfo)
#define McalCry_GetObjectInfoInd(Index)                                                     (McalCry_GetObjectInfoIndOfPCConfig()[(Index)])
#define McalCry_GetDispatchOfPrimitiveFct(Index)                                            (McalCry_GetPrimitiveFctOfPCConfig()[(Index)].DispatchOfPrimitiveFct)
#define McalCry_GetObjectInfoIndEndIdxOfPrimitiveFct(Index)                                 (McalCry_GetPrimitiveFctOfPCConfig()[(Index)].ObjectInfoIndEndIdxOfPrimitiveFct)
#define McalCry_GetObjectInfoIndStartIdxOfPrimitiveFct(Index)                               (McalCry_GetPrimitiveFctOfPCConfig()[(Index)].ObjectInfoIndStartIdxOfPrimitiveFct)
#define McalCry_GetCombinedOfPrimitiveInfo(Index)                                           (McalCry_GetPrimitiveInfoOfPCConfig()[(Index)].CombinedOfPrimitiveInfo)
#define McalCry_GetMaskedBitsOfPrimitiveInfo(Index)                                         (McalCry_GetPrimitiveInfoOfPCConfig()[(Index)].MaskedBitsOfPrimitiveInfo)
#define McalCry_GetPrimitiveFctIdxOfPrimitiveInfo(Index)                                    (McalCry_GetPrimitiveInfoOfPCConfig()[(Index)].PrimitiveFctIdxOfPrimitiveInfo)
#define McalCry_GetPrimitiveInfoEndIdxOfPrimitiveServiceInfo(Index)                         (McalCry_GetPrimitiveServiceInfoOfPCConfig()[(Index)].PrimitiveInfoEndIdxOfPrimitiveServiceInfo)
#define McalCry_GetPrimitiveInfoStartIdxOfPrimitiveServiceInfo(Index)                       (McalCry_GetPrimitiveServiceInfoOfPCConfig()[(Index)].PrimitiveInfoStartIdxOfPrimitiveServiceInfo)
#define McalCry_GetQueue(Index)                                                             (McalCry_GetQueueOfPCConfig()[(Index)])
#define McalCry_GetRandomSeedBuffer(Index)
#define McalCry_GetWorkspaceOfRipeMd160(Index)
#define McalCry_GetWorkspaceOfRsaOaepCrtSha1Decrypt(Index)
#define McalCry_GetWorkspaceOfRsaOaepCrtSha256Decrypt(Index)
#define McalCry_GetWorkspaceOfRsaOaepSha1Decrypt(Index)
#define McalCry_GetWorkspaceOfRsaOaepSha1Encrypt(Index)
#define McalCry_GetWorkspaceOfRsaOaepSha256Decrypt(Index)
#define McalCry_GetWorkspaceOfRsaOaepSha256Encrypt(Index)
#define McalCry_GetWorkspaceOfRsaPkcs1CrtGenerate(Index)
#define McalCry_GetWorkspaceOfRsaPkcs1Decrypt(Index)
#define McalCry_GetWorkspaceOfRsaPkcs1Encrypt(Index)
#define McalCry_GetWorkspaceOfRsaPkcs1Generate(Index)
#define McalCry_GetWorkspaceOfRsaPkcs1Verify(Index)                                         (McalCry_GetRsaPkcs1VerifyOfPCConfig()[(Index)].WorkspaceOfRsaPkcs1Verify)
#define McalCry_GetWorkspaceOfRsaPssGenerate(Index)
#define McalCry_GetWorkspaceOfRsaPssVerify(Index)                                           (McalCry_GetRsaPssVerifyOfPCConfig()[(Index)].WorkspaceOfRsaPssVerify)
#define McalCry_GetWorkspaceOfSHA1(Index)
#define McalCry_GetWorkspaceOfSHA256(Index)
#define McalCry_GetWorkspaceOfSHA384(Index)
#define McalCry_GetWorkspaceOfSHA3_256(Index)
#define McalCry_GetWorkspaceOfSHA512(Index)                                                 (McalCry_GetSHA512OfPCConfig()[(Index)].WorkspaceOfSHA512)
#define McalCry_GetLengthOfSaveAndRestoreWorkspace(Index)
#define McalCry_GetWorkspaceOfSheCmdGetId(Index)
#define McalCry_GetWorkspaceOfSipHashGenerate(Index)
#define McalCry_GetWorkspaceOfSipHashVerify(Index)
#define McalCry_GetUnionWS_McalCry()                                                ((*(McalCry_GetUnionWS_McalCryOfPCConfig())))
#define McalCry_GetUnionWS_McalCry_Aes()                                            ((*(McalCry_GetUnionWS_McalCry_AesOfPCConfig())))
#define McalCry_GetWrittenLength(Index)                                                     (McalCry_GetWrittenLengthOfPCConfig()[(Index)])

#define McalCry_IsOnceOfKeyElementInfo(Index)                                               (MCALCRY_ONCEOFKEYELEMENTINFO_MASK == (McalCry_GetMaskedBitsOfKeyElementInfo(Index) & MCALCRY_ONCEOFKEYELEMENTINFO_MASK))
#define McalCry_IsPartialOfKeyElementInfo(Index)                                            (MCALCRY_PARTIALOFKEYELEMENTINFO_MASK == (McalCry_GetMaskedBitsOfKeyElementInfo(Index) & MCALCRY_PARTIALOFKEYELEMENTINFO_MASK))
#define McalCry_IsPersistOfKeyElementInfo(Index)                                            (MCALCRY_PERSISTOFKEYELEMENTINFO_MASK == (McalCry_GetMaskedBitsOfKeyElementInfo(Index) & MCALCRY_PERSISTOFKEYELEMENTINFO_MASK))
#define McalCry_IsContextOfPrimitiveInfo(Index)                                             (MCALCRY_CONTEXTOFPRIMITIVEINFO_MASK == (McalCry_GetMaskedBitsOfPrimitiveInfo(Index) & MCALCRY_CONTEXTOFPRIMITIVEINFO_MASK))
#define McalCry_IsDefaultRandomSourceOfPrimitiveInfo(Index)                                 (MCALCRY_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO_MASK == (McalCry_GetMaskedBitsOfPrimitiveInfo(Index) & MCALCRY_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO_MASK))

#define McalCry_IsAlignKeyStorageOfGeneral()                                                McalCry_IsAlignKeyStorageOfGeneralOfPCConfig()
#define McalCry_IsCmacAesRoundkeyReuseOfMacPrimitives()                                     McalCry_IsCmacAesRoundkeyReuseOfMacPrimitivesOfPCConfig()
#define McalCry_GetDefaultRandomMaxRetriesOfGeneral()                                       McalCry_GetDefaultRandomMaxRetriesOfGeneralOfPCConfig()
#define McalCry_IsEnableAES256OfCipherPrimitives()                                          McalCry_IsEnableAES256OfCipherPrimitivesOfPCConfig()
#define McalCry_GetExpectedCompatibilityVersion()
#define McalCry_GetFinalMagicNumber()
#define McalCry_GetGeneratorCompatibilityVersion()
#define McalCry_GetInitDataHashCode()
#define McalCry_IsKeyElementDeleteOfGeneral()                                               McalCry_IsKeyElementDeleteOfGeneralOfPCConfig()
#define McalCry_GetKeyElementInfoIdxOfKeyElements(Index)                                    ((McalCry_KeyElementInfoIdxOfKeyElementsType)((Index)))
#define McalCry_GetKeyStorageExtensionIdxOfKeyElements(Index)                               ((McalCry_KeyStorageExtensionIdxOfKeyElementsType)((McalCry_GetKeyStorageStartIdxOfKeyElements(Index) - 1u)))
#define McalCry_GetKeyStorageValidIdxOfKeyElements(Index)                                   ((McalCry_KeyStorageValidIdxOfKeyElementsType)((McalCry_GetKeyStorageStartIdxOfKeyElements(Index) - 2u)))
#define McalCry_GetKeyStorageWrittenLengthEndIdxOfKeyElements(Index)                        ((McalCry_KeyStorageWrittenLengthEndIdxOfKeyElementsType)((McalCry_GetKeyStorageStartIdxOfKeyElements(Index) - 2u)))
#define McalCry_GetKeyStorageWrittenLengthStartIdxOfKeyElements(Index)                      ((McalCry_KeyStorageWrittenLengthStartIdxOfKeyElementsType)((McalCry_GetKeyStorageStartIdxOfKeyElements(Index) - 4u)))
#define McalCry_GetKeyGenerateMaxLengthOfKeyGeneratePrimitives()                            McalCry_GetKeyGenerateMaxLengthOfKeyGeneratePrimitivesOfPCConfig()
#define McalCry_GetKeyValiditySetCalloutFctNameOfConfigurableCallouts()
#define McalCry_GetKeyValueChangedCalloutFctNameOfConfigurableCallouts()
#define McalCry_GetMainFunctionPeriodOfGeneral()                                            McalCry_GetMainFunctionPeriodOfGeneralOfPCConfig()
#define McalCry_GetNumberOfLongTermPrimitiveWorkspaceOfGeneral()                            McalCry_GetNumberOfLongTermPrimitiveWorkspaceOfGeneralOfPCConfig()
#define McalCry_IsNvMEnableSetRamBlockStatusOfGeneral()                                     McalCry_IsNvMEnableSetRamBlockStatusOfGeneralOfPCConfig()
#define McalCry_GetNvManagementDataPerKeyOfNvStorage()                                      McalCry_GetNvManagementDataPerKeyOfNvStorageOfPCConfig()
#define McalCry_GetNvWriteBlockFctNameOfNvStorage()                                         McalCry_GetNvWriteBlockFctNameOfNvStorageOfPCConfig()
#define McalCry_IsAesDecryptUsedOfObjectInfo(Index)                                         (((boolean)(McalCry_GetAesDecryptIdxOfObjectInfo(Index) != MCALCRY_NO_AESDECRYPTIDXOFOBJECTINFO)) != FALSE)
#define McalCry_IsHmacSha1VerifyUsedOfObjectInfo(Index)                                     (((boolean)(McalCry_GetHmacSha1VerifyIdxOfObjectInfo(Index) != MCALCRY_NO_HMACSHA1VERIFYIDXOFOBJECTINFO)) != FALSE)
#define McalCry_IsRsaPkcs1VerifyUsedOfObjectInfo(Index)                                     (((boolean)(McalCry_GetRsaPkcs1VerifyIdxOfObjectInfo(Index) != MCALCRY_NO_RSAPKCS1VERIFYIDXOFOBJECTINFO)) != FALSE)
#define McalCry_IsRsaPssVerifyUsedOfObjectInfo(Index)                                       (((boolean)(McalCry_GetRsaPssVerifyIdxOfObjectInfo(Index) != MCALCRY_NO_RSAPSSVERIFYIDXOFOBJECTINFO)) != FALSE)
#define McalCry_IsSHA512UsedOfObjectInfo(Index)                                             (((boolean)(McalCry_GetSHA512IdxOfObjectInfo(Index) != MCALCRY_NO_SHA512IDXOFOBJECTINFO)) != FALSE)
#define McalCry_IsObjectInfoIndUsedOfPrimitiveFct(Index)                                    (((boolean)(McalCry_GetObjectInfoIndStartIdxOfPrimitiveFct(Index) != MCALCRY_NO_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT)) != FALSE)
#define McalCry_IsPrimitiveInfoUsedOfPrimitiveServiceInfo(Index)                            (((boolean)(McalCry_GetPrimitiveInfoStartIdxOfPrimitiveServiceInfo(Index) != MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO)) != FALSE)
#define McalCry_IsRedirectionOfGeneral()                                                    McalCry_IsRedirectionOfGeneralOfPCConfig()
#define McalCry_IsSheDebugCmdOfSheKeyUpdate()
#define McalCry_IsSheEnableCounterOfSheKeyUpdate()
#define McalCry_IsSheEnableFidOfSheKeyUpdate()
#define McalCry_GetSheInfoKeyRefOfSheKeyUpdate()
#define McalCry_GetSizeOfAesDecrypt()                                                       McalCry_GetSizeOfAesDecryptOfPCConfig()
#define McalCry_GetSizeOfBufferLength()                                                     McalCry_GetSizeOfBufferLengthOfPCConfig()
#define McalCry_GetSizeOfDriverObjectState()                                                McalCry_GetSizeOfDriverObjectStateOfPCConfig()
#define McalCry_GetSizeOfHmacSha1Verify()                                                   McalCry_GetSizeOfHmacSha1VerifyOfPCConfig()
#define McalCry_GetSizeOfKey()                                                              McalCry_GetSizeOfKeyOfPCConfig()
#define McalCry_GetSizeOfKeyElementInfo()                                                   McalCry_GetSizeOfKeyElementInfoOfPCConfig()
#define McalCry_GetSizeOfKeyElements()                                                      McalCry_GetSizeOfKeyElementsOfPCConfig()
#define McalCry_GetSizeOfKeyLock()                                                          McalCry_GetSizeOfKeyLockOfPCConfig()
#define McalCry_GetSizeOfKeyStorage()                                                       McalCry_GetSizeOfKeyStorageOfPCConfig()
#define McalCry_GetSizeOfLock()                                                             McalCry_GetSizeOfLockOfPCConfig()
#define McalCry_GetSizeOfObjectInfo()                                                       McalCry_GetSizeOfObjectInfoOfPCConfig()
#define McalCry_GetSizeOfObjectInfoInd()                                                    McalCry_GetSizeOfObjectInfoIndOfPCConfig()
#define McalCry_GetSizeOfPrimitiveFct()                                                     McalCry_GetSizeOfPrimitiveFctOfPCConfig()
#define McalCry_GetSizeOfPrimitiveInfo()                                                    McalCry_GetSizeOfPrimitiveInfoOfPCConfig()
#define McalCry_GetSizeOfPrimitiveServiceInfo()                                             McalCry_GetSizeOfPrimitiveServiceInfoOfPCConfig()
#define McalCry_GetSizeOfQueue()                                                            McalCry_GetSizeOfQueueOfPCConfig()
#define McalCry_GetSizeOfRsaPkcs1Verify()                                                   McalCry_GetSizeOfRsaPkcs1VerifyOfPCConfig()
#define McalCry_GetSizeOfRsaPssVerify()                                                     McalCry_GetSizeOfRsaPssVerifyOfPCConfig()
#define McalCry_GetSizeOfSHA512()                                                           McalCry_GetSizeOfSHA512OfPCConfig()
#define McalCry_GetSizeOfWrittenLength()                                                    McalCry_GetSizeOfWrittenLengthOfPCConfig()
#define McalCry_IsUseVStdLibOfGeneral()                                                     McalCry_IsUseVStdLibOfGeneralOfPCConfig()
#define McalCry_IsVersionInfoApiOfGeneral()                                                 McalCry_IsVersionInfoApiOfGeneralOfPCConfig()
#define McalCry_GetWatchdogTriggerFunctionOfGeneral()                                       McalCry_GetWatchdogTriggerFunctionOfGeneralOfPCConfig()

#define McalCry_SetBufferLength(Index, Value)                                               McalCry_GetBufferLengthOfPCConfig()[(Index)] = (Value)
#define McalCry_SetDriverObjectState(Index, Value)                                          McalCry_GetDriverObjectStateOfPCConfig()[(Index)] = (Value)
#define McalCry_SetKeyLock(Index, Value)                                                    McalCry_GetKeyLockOfPCConfig()[(Index)] = (Value)
#define McalCry_SetKeyStorage(Index, Value)                                                 McalCry_GetKeyStorageOfPCConfig()[(Index)] = (Value)
#define McalCry_SetFamilyOfLastJob(Index, Value)
#define McalCry_SetKeyIdOfLastJob(Index, Value)
#define McalCry_SetModeOfLastJob(Index, Value)
#define McalCry_SetLock(Index, Value)                                                       McalCry_GetLockOfPCConfig()[(Index)] = (Value)
#define McalCry_SetLongTermWs(Index, Value)
#define McalCry_SetLongTermWsLock(Index, Value)
#define McalCry_SetQueue(Index, Value)                                                      McalCry_GetQueueOfPCConfig()[(Index)] = (Value)
#define McalCry_SetRandomSeedBuffer(Index, Value)
#define McalCry_SetLengthOfSaveAndRestoreWorkspace(Index, Value)
#define McalCry_SetUnionWS_McalCry(Value)                                           (*(McalCry_GetUnionWS_McalCryOfPCConfig())) = (Value)
#define McalCry_SetUnionWS_McalCry_Aes(Value)                                       (*(McalCry_GetUnionWS_McalCry_AesOfPCConfig())) = (Value)
#define McalCry_SetWrittenLength(Index, Value)                                              McalCry_GetWrittenLengthOfPCConfig()[(Index)] = (Value)

#define McalCry_GetAddrInitValue(Index)
#define McalCry_GetAddrKeyStorage(Index)                                                    (&McalCry_GetKeyStorage(Index))
#define McalCry_GetAddrUnionWS_McalCry()                                            (&McalCry_GetUnionWS_McalCry())
#define McalCry_GetAddrUnionWS_McalCry_Aes()                                        (&McalCry_GetUnionWS_McalCry_Aes())

#define McalCry_HasAEADChaChaPoly1305Decrypt()
#define McalCry_HasWorkspaceOfAEADChaChaPoly1305Decrypt()
#define McalCry_HasAEADChaChaPoly1305Encrypt()
#define McalCry_HasWorkspaceOfAEADChaChaPoly1305Encrypt()
#define McalCry_HasAesCcmDecrypt()
#define McalCry_HasWorkspaceOfAesCcmDecrypt()
#define McalCry_HasAesCcmEncrypt()
#define McalCry_HasWorkspaceOfAesCcmEncrypt()
#define McalCry_HasAesDecrypt()                                                             (TRUE != FALSE)
#define McalCry_HasWorkspaceOfAesDecrypt()                                                  (TRUE != FALSE)
#define McalCry_HasAesEncrypt()
#define McalCry_HasWorkspaceOfAesEncrypt()
#define McalCry_HasAesGcmDecrypt()
#define McalCry_HasWorkspaceOfAesGcmDecrypt()
#define McalCry_HasAesGcmEncrypt()
#define McalCry_HasWorkspaceOfAesGcmEncrypt()
#define McalCry_HasAlignKeyStorageOfGeneral()                                               (TRUE != FALSE)
#define McalCry_HasBufferLength()                                                           (TRUE != FALSE)
#define McalCry_HasCmacAesGenerate()
#define McalCry_HasWorkspaceOfCmacAesGenerate()
#define McalCry_HasCmacAesRoundkeyReuseOfMacPrimitives()                                    (TRUE != FALSE)
#define McalCry_HasCmacAesVerify()
#define McalCry_HasWorkspaceOfCmacAesVerify()
#define McalCry_HasDRBGAES()
#define McalCry_HasWorkspaceOfDRBGAES()
#define McalCry_HasDRBGHashSha512()
#define McalCry_HasWorkspaceOfDRBGHashSha512()
#define McalCry_HasDefaultRandomMaxRetriesOfGeneral()                                       (TRUE != FALSE)
#define McalCry_HasDriverObjectState()                                                      (TRUE != FALSE)
#define McalCry_HasEcP160Generate()
#define McalCry_HasWorkspaceOfEcP160Generate()
#define McalCry_HasEcP160Verify()
#define McalCry_HasWorkspaceOfEcP160Verify()
#define McalCry_HasEcP256Generate()
#define McalCry_HasWorkspaceOfEcP256Generate()
#define McalCry_HasEcP256Verify()
#define McalCry_HasWorkspaceOfEcP256Verify()
#define McalCry_HasEcP384Generate()
#define McalCry_HasWorkspaceOfEcP384Generate()
#define McalCry_HasEcP384Verify()
#define McalCry_HasWorkspaceOfEcP384Verify()
#define McalCry_HasEd25519Generate()
#define McalCry_HasWorkspaceOfEd25519Generate()
#define McalCry_HasEd25519Verify()
#define McalCry_HasWorkspaceOfEd25519Verify()
#define McalCry_HasEnableAES256OfCipherPrimitives()                                         (TRUE != FALSE)
#define McalCry_HasExpectedCompatibilityVersion()
#define McalCry_HasFinalMagicNumber()
#define McalCry_HasFips186()
#define McalCry_HasWorkspaceOfFips186()
#define McalCry_HasGeneratorCompatibilityVersion()
#define McalCry_HasGmacAesGenerate()
#define McalCry_HasWorkspaceOfGmacAesGenerate()
#define McalCry_HasGmacAesVerify()
#define McalCry_HasWorkspaceOfGmacAesVerify()
#define McalCry_HasHmacRipeMd160Generate()
#define McalCry_HasWorkspaceOfHmacRipeMd160Generate()
#define McalCry_HasHmacRipeMd160Verify()
#define McalCry_HasWorkspaceOfHmacRipeMd160Verify()
#define McalCry_HasHmacSha1Generate()
#define McalCry_HasWorkspaceOfHmacSha1Generate()
#define McalCry_HasHmacSha1Verify()                                                         (TRUE != FALSE)
#define McalCry_HasWorkspaceOfHmacSha1Verify()                                              (TRUE != FALSE)
#define McalCry_HasHmacSha256Generate()
#define McalCry_HasWorkspaceOfHmacSha256Generate()
#define McalCry_HasHmacSha256Verify()
#define McalCry_HasWorkspaceOfHmacSha256Verify()
#define McalCry_HasHmacSha384Generate()
#define McalCry_HasWorkspaceOfHmacSha384Generate()
#define McalCry_HasHmacSha384Verify()
#define McalCry_HasWorkspaceOfHmacSha384Verify()
#define McalCry_HasInitDataHashCode()
#define McalCry_HasInitValue()
#define McalCry_HasKey()                                                                    (TRUE != FALSE)
#define McalCry_HasKeyElementsEndIdxOfKey()                                                 (TRUE != FALSE)
#define McalCry_HasKeyElementsStartIdxOfKey()                                               (TRUE != FALSE)
#define McalCry_HasNvBlockIdxOfKey()
#define McalCry_HasNvBlockUsedOfKey()
#define McalCry_HasKeyDeriveHKDFHMACSHA256()
#define McalCry_HasWorkspaceOfKeyDeriveHKDFHMACSHA256()
#define McalCry_HasKeyDeriveHKDFHashOption1()
#define McalCry_HasWorkspaceOfKeyDeriveHKDFHashOption1()
#define McalCry_HasKeyDeriveISO15118()
#define McalCry_HasWorkspaceOfKeyDeriveISO15118()
#define McalCry_HasKeyDeriveKDF2HMACSHA1()
#define McalCry_HasWorkspaceOfKeyDeriveKDF2HMACSHA1()
#define McalCry_HasKeyDeriveKDF2HMACSHA256()
#define McalCry_HasWorkspaceOfKeyDeriveKDF2HMACSHA256()
#define McalCry_HasKeyDeriveNist800108Cnt()
#define McalCry_HasWorkspaceOfKeyDeriveNist800108Cnt()
#define McalCry_HasKeyDeriveNist80056AOnePass()
#define McalCry_HasWorkspaceOfKeyDeriveNist80056AOnePass()
#define McalCry_HasKeyDeriveNistFips186Erb()
#define McalCry_HasWorkspaceOfKeyDeriveNistFips186Erb()
#define McalCry_HasKeyDeriveSpake2P()
#define McalCry_HasWorkspaceOfKeyDeriveSpake2P()
#define McalCry_HasKeyDeriveX963SHA256()
#define McalCry_HasWorkspaceOfKeyDeriveX963SHA256()
#define McalCry_HasKeyDeriveX963SHA512()
#define McalCry_HasWorkspaceOfKeyDeriveX963SHA512()
#define McalCry_HasKeyElementDeleteOfGeneral()                                              (TRUE != FALSE)
#define McalCry_HasKeyElementInfo()                                                         (TRUE != FALSE)
#define McalCry_HasIdOfKeyElementInfo()                                                     (TRUE != FALSE)
#define McalCry_HasInitValueEndIdxOfKeyElementInfo()
#define McalCry_HasInitValueStartIdxOfKeyElementInfo()
#define McalCry_HasInitValueUsedOfKeyElementInfo()
#define McalCry_HasLengthOfKeyElementInfo()                                                 (TRUE != FALSE)
#define McalCry_HasMaskedBitsOfKeyElementInfo()                                             (TRUE != FALSE)
#define McalCry_HasOnceOfKeyElementInfo()                                                   (TRUE != FALSE)
#define McalCry_HasPartialOfKeyElementInfo()                                                (TRUE != FALSE)
#define McalCry_HasPersistOfKeyElementInfo()                                                (TRUE != FALSE)
#define McalCry_HasReadOfKeyElementInfo()                                                   (TRUE != FALSE)
#define McalCry_HasWriteOfKeyElementInfo()                                                  (TRUE != FALSE)
#define McalCry_HasKeyElements()                                                            (TRUE != FALSE)
#define McalCry_HasIdOfKeyElements()                                                        (TRUE != FALSE)
#define McalCry_HasKeyElementInfoIdxOfKeyElements()                                         (TRUE != FALSE)
#define McalCry_HasKeyStorageEndIdxOfKeyElements()                                          (TRUE != FALSE)
#define McalCry_HasKeyStorageExtensionIdxOfKeyElements()                                    (TRUE != FALSE)
#define McalCry_HasKeyStorageStartIdxOfKeyElements()                                        (TRUE != FALSE)
#define McalCry_HasKeyStorageValidIdxOfKeyElements()                                        (TRUE != FALSE)
#define McalCry_HasKeyStorageWrittenLengthEndIdxOfKeyElements()                             (TRUE != FALSE)
#define McalCry_HasKeyStorageWrittenLengthStartIdxOfKeyElements()                           (TRUE != FALSE)
#define McalCry_HasKeyGenEd25519()
#define McalCry_HasWorkspaceOfKeyGenEd25519()
#define McalCry_HasKeyGenP256R1()
#define McalCry_HasWorkspaceOfKeyGenP256R1()
#define McalCry_HasKeyGenP384R1()
#define McalCry_HasWorkspaceOfKeyGenP384R1()
#define McalCry_HasKeyGenSymGeneric()
#define McalCry_HasWorkspaceOfKeyGenSymGeneric()
#define McalCry_HasKeyGenerateMaxLengthOfKeyGeneratePrimitives()                            (TRUE != FALSE)
#define McalCry_HasKeyLock()                                                                (TRUE != FALSE)
#define McalCry_HasKeyP224R1BDPubVal()
#define McalCry_HasWorkspaceOfKeyP224R1BDPubVal()
#define McalCry_HasKeyP224R1BDSecret()
#define McalCry_HasWorkspaceOfKeyP224R1BDSecret()
#define McalCry_HasKeyP256R1PubVal()
#define McalCry_HasWorkspaceOfKeyP256R1PubVal()
#define McalCry_HasKeyP256R1Secret()
#define McalCry_HasWorkspaceOfKeyP256R1Secret()
#define McalCry_HasKeyP384R1PubVal()
#define McalCry_HasWorkspaceOfKeyP384R1PubVal()
#define McalCry_HasKeyP384R1Secret()
#define McalCry_HasWorkspaceOfKeyP384R1Secret()
#define McalCry_HasKeySeedDRBGAES()
#define McalCry_HasWorkspaceOfKeySeedDRBGAES()
#define McalCry_HasKeySeedDRBGHashSha512()
#define McalCry_HasWorkspaceOfKeySeedDRBGHashSha512()
#define McalCry_HasKeySeedFips186()
#define McalCry_HasWorkspaceOfKeySeedFips186()
#define McalCry_HasKeySetValid()
#define McalCry_HasWorkspaceOfKeySetValid()
#define McalCry_HasKeySpake2PPubVal()
#define McalCry_HasWorkspaceOfKeySpake2PPubVal()
#define McalCry_HasKeySpake2PSecret()
#define McalCry_HasWorkspaceOfKeySpake2PSecret()
#define McalCry_HasKeyStorage()                                                             (TRUE != FALSE)
#define McalCry_HasKeyValiditySetCalloutFctNameOfConfigurableCallouts()
#define McalCry_HasKeyValueChangedCalloutFctNameOfConfigurableCallouts()
#define McalCry_HasKeyX25519PubVal()
#define McalCry_HasWorkspaceOfKeyX25519PubVal()
#define McalCry_HasKeyX25519Secret()
#define McalCry_HasWorkspaceOfKeyX25519Secret()
#define McalCry_HasLastJob()
#define McalCry_HasFamilyOfLastJob()
#define McalCry_HasKeyIdOfLastJob()
#define McalCry_HasModeOfLastJob()
#define McalCry_HasLock()                                                                   (TRUE != FALSE)
#define McalCry_HasLongTermWs()
#define McalCry_HasLongTermWsLock()
#define McalCry_HasMD5()
#define McalCry_HasWorkspaceOfMD5()
#define McalCry_HasMainFunctionPeriodOfGeneral()                                            (TRUE != FALSE)
#define McalCry_HasNumberOfLongTermPrimitiveWorkspaceOfGeneral()                            (TRUE != FALSE)
#define McalCry_HasNvBlock()
#define McalCry_HasConsistencyLevelOfNvBlock()
#define McalCry_HasCrcOfNvBlock()
#define McalCry_HasDescriptorOfNvBlock()
#define McalCry_HasIdOfNvBlock()
#define McalCry_HasKeyStorageEndIdxOfNvBlock()
#define McalCry_HasKeyStorageStartIdxOfNvBlock()
#define McalCry_HasLengthOfNvBlock()
#define McalCry_HasProcessingOfNvBlock()
#define McalCry_HasNvMEnableSetRamBlockStatusOfGeneral()                                    (TRUE != FALSE)
#define McalCry_HasNvManagementDataPerKeyOfNvStorage()                                      (TRUE != FALSE)
#define McalCry_HasNvWriteBlockFctNameOfNvStorage()                                         (TRUE != FALSE)
#define McalCry_HasObjectInfo()                                                             (TRUE != FALSE)
#define McalCry_HasAEADChaChaPoly1305DecryptIdxOfObjectInfo()
#define McalCry_HasAEADChaChaPoly1305DecryptUsedOfObjectInfo()
#define McalCry_HasAEADChaChaPoly1305EncryptIdxOfObjectInfo()
#define McalCry_HasAEADChaChaPoly1305EncryptUsedOfObjectInfo()
#define McalCry_HasAesCcmDecryptIdxOfObjectInfo()
#define McalCry_HasAesCcmDecryptUsedOfObjectInfo()
#define McalCry_HasAesCcmEncryptIdxOfObjectInfo()
#define McalCry_HasAesCcmEncryptUsedOfObjectInfo()
#define McalCry_HasAesDecryptIdxOfObjectInfo()                                              (TRUE != FALSE)
#define McalCry_HasAesDecryptUsedOfObjectInfo()                                             (TRUE != FALSE)
#define McalCry_HasAesEncryptIdxOfObjectInfo()
#define McalCry_HasAesEncryptUsedOfObjectInfo()
#define McalCry_HasAesGcmDecryptIdxOfObjectInfo()
#define McalCry_HasAesGcmDecryptUsedOfObjectInfo()
#define McalCry_HasAesGcmEncryptIdxOfObjectInfo()
#define McalCry_HasAesGcmEncryptUsedOfObjectInfo()
#define McalCry_HasCmacAesGenerateIdxOfObjectInfo()
#define McalCry_HasCmacAesGenerateUsedOfObjectInfo()
#define McalCry_HasCmacAesVerifyIdxOfObjectInfo()
#define McalCry_HasCmacAesVerifyUsedOfObjectInfo()
#define McalCry_HasDRBGAESIdxOfObjectInfo()
#define McalCry_HasDRBGAESUsedOfObjectInfo()
#define McalCry_HasDRBGHashSha512IdxOfObjectInfo()
#define McalCry_HasDRBGHashSha512UsedOfObjectInfo()
#define McalCry_HasEcP160GenerateIdxOfObjectInfo()
#define McalCry_HasEcP160GenerateUsedOfObjectInfo()
#define McalCry_HasEcP160VerifyIdxOfObjectInfo()
#define McalCry_HasEcP160VerifyUsedOfObjectInfo()
#define McalCry_HasEcP256GenerateIdxOfObjectInfo()
#define McalCry_HasEcP256GenerateUsedOfObjectInfo()
#define McalCry_HasEcP256VerifyIdxOfObjectInfo()
#define McalCry_HasEcP256VerifyUsedOfObjectInfo()
#define McalCry_HasEcP384GenerateIdxOfObjectInfo()
#define McalCry_HasEcP384GenerateUsedOfObjectInfo()
#define McalCry_HasEcP384VerifyIdxOfObjectInfo()
#define McalCry_HasEcP384VerifyUsedOfObjectInfo()
#define McalCry_HasEd25519GenerateIdxOfObjectInfo()
#define McalCry_HasEd25519GenerateUsedOfObjectInfo()
#define McalCry_HasEd25519VerifyIdxOfObjectInfo()
#define McalCry_HasEd25519VerifyUsedOfObjectInfo()
#define McalCry_HasFips186IdxOfObjectInfo()
#define McalCry_HasFips186UsedOfObjectInfo()
#define McalCry_HasGmacAesGenerateIdxOfObjectInfo()
#define McalCry_HasGmacAesGenerateUsedOfObjectInfo()
#define McalCry_HasGmacAesVerifyIdxOfObjectInfo()
#define McalCry_HasGmacAesVerifyUsedOfObjectInfo()
#define McalCry_HasHmacRipeMd160GenerateIdxOfObjectInfo()
#define McalCry_HasHmacRipeMd160GenerateUsedOfObjectInfo()
#define McalCry_HasHmacRipeMd160VerifyIdxOfObjectInfo()
#define McalCry_HasHmacRipeMd160VerifyUsedOfObjectInfo()
#define McalCry_HasHmacSha1GenerateIdxOfObjectInfo()
#define McalCry_HasHmacSha1GenerateUsedOfObjectInfo()
#define McalCry_HasHmacSha1VerifyIdxOfObjectInfo()                                          (TRUE != FALSE)
#define McalCry_HasHmacSha1VerifyUsedOfObjectInfo()                                         (TRUE != FALSE)
#define McalCry_HasHmacSha256GenerateIdxOfObjectInfo()
#define McalCry_HasHmacSha256GenerateUsedOfObjectInfo()
#define McalCry_HasHmacSha256VerifyIdxOfObjectInfo()
#define McalCry_HasHmacSha256VerifyUsedOfObjectInfo()
#define McalCry_HasHmacSha384GenerateIdxOfObjectInfo()
#define McalCry_HasHmacSha384GenerateUsedOfObjectInfo()
#define McalCry_HasHmacSha384VerifyIdxOfObjectInfo()
#define McalCry_HasHmacSha384VerifyUsedOfObjectInfo()
#define McalCry_HasKeyDeriveHKDFHMACSHA256IdxOfObjectInfo()
#define McalCry_HasKeyDeriveHKDFHMACSHA256UsedOfObjectInfo()
#define McalCry_HasKeyDeriveHKDFHashOption1IdxOfObjectInfo()
#define McalCry_HasKeyDeriveHKDFHashOption1UsedOfObjectInfo()
#define McalCry_HasKeyDeriveISO15118IdxOfObjectInfo()
#define McalCry_HasKeyDeriveISO15118UsedOfObjectInfo()
#define McalCry_HasKeyDeriveKDF2HMACSHA1IdxOfObjectInfo()
#define McalCry_HasKeyDeriveKDF2HMACSHA1UsedOfObjectInfo()
#define McalCry_HasKeyDeriveKDF2HMACSHA256IdxOfObjectInfo()
#define McalCry_HasKeyDeriveKDF2HMACSHA256UsedOfObjectInfo()
#define McalCry_HasKeyDeriveNist800108CntIdxOfObjectInfo()
#define McalCry_HasKeyDeriveNist800108CntUsedOfObjectInfo()
#define McalCry_HasKeyDeriveNist80056AOnePassIdxOfObjectInfo()
#define McalCry_HasKeyDeriveNist80056AOnePassUsedOfObjectInfo()
#define McalCry_HasKeyDeriveNistFips186ErbIdxOfObjectInfo()
#define McalCry_HasKeyDeriveNistFips186ErbUsedOfObjectInfo()
#define McalCry_HasKeyDeriveSpake2PIdxOfObjectInfo()
#define McalCry_HasKeyDeriveSpake2PUsedOfObjectInfo()
#define McalCry_HasKeyDeriveX963SHA256IdxOfObjectInfo()
#define McalCry_HasKeyDeriveX963SHA256UsedOfObjectInfo()
#define McalCry_HasKeyDeriveX963SHA512IdxOfObjectInfo()
#define McalCry_HasKeyDeriveX963SHA512UsedOfObjectInfo()
#define McalCry_HasKeyGenEd25519IdxOfObjectInfo()
#define McalCry_HasKeyGenEd25519UsedOfObjectInfo()
#define McalCry_HasKeyGenP256R1IdxOfObjectInfo()
#define McalCry_HasKeyGenP256R1UsedOfObjectInfo()
#define McalCry_HasKeyGenP384R1IdxOfObjectInfo()
#define McalCry_HasKeyGenP384R1UsedOfObjectInfo()
#define McalCry_HasKeyGenSymGenericIdxOfObjectInfo()
#define McalCry_HasKeyGenSymGenericUsedOfObjectInfo()
#define McalCry_HasKeyP224R1BDPubValIdxOfObjectInfo()
#define McalCry_HasKeyP224R1BDPubValUsedOfObjectInfo()
#define McalCry_HasKeyP224R1BDSecretIdxOfObjectInfo()
#define McalCry_HasKeyP224R1BDSecretUsedOfObjectInfo()
#define McalCry_HasKeyP256R1PubValIdxOfObjectInfo()
#define McalCry_HasKeyP256R1PubValUsedOfObjectInfo()
#define McalCry_HasKeyP256R1SecretIdxOfObjectInfo()
#define McalCry_HasKeyP256R1SecretUsedOfObjectInfo()
#define McalCry_HasKeyP384R1PubValIdxOfObjectInfo()
#define McalCry_HasKeyP384R1PubValUsedOfObjectInfo()
#define McalCry_HasKeyP384R1SecretIdxOfObjectInfo()
#define McalCry_HasKeyP384R1SecretUsedOfObjectInfo()
#define McalCry_HasKeySeedDRBGAESIdxOfObjectInfo()
#define McalCry_HasKeySeedDRBGAESUsedOfObjectInfo()
#define McalCry_HasKeySeedDRBGHashSha512IdxOfObjectInfo()
#define McalCry_HasKeySeedDRBGHashSha512UsedOfObjectInfo()
#define McalCry_HasKeySeedFips186IdxOfObjectInfo()
#define McalCry_HasKeySeedFips186UsedOfObjectInfo()
#define McalCry_HasKeySetValidIdxOfObjectInfo()
#define McalCry_HasKeySetValidUsedOfObjectInfo()
#define McalCry_HasKeySpake2PPubValIdxOfObjectInfo()
#define McalCry_HasKeySpake2PPubValUsedOfObjectInfo()
#define McalCry_HasKeySpake2PSecretIdxOfObjectInfo()
#define McalCry_HasKeySpake2PSecretUsedOfObjectInfo()
#define McalCry_HasKeyX25519PubValIdxOfObjectInfo()
#define McalCry_HasKeyX25519PubValUsedOfObjectInfo()
#define McalCry_HasKeyX25519SecretIdxOfObjectInfo()
#define McalCry_HasKeyX25519SecretUsedOfObjectInfo()
#define McalCry_HasMD5IdxOfObjectInfo()
#define McalCry_HasMD5UsedOfObjectInfo()
#define McalCry_HasQueueIdxOfObjectInfo()                                                   (TRUE != FALSE)
#define McalCry_HasRandomSeedBufferEndIdxOfObjectInfo()
#define McalCry_HasRandomSeedBufferStartIdxOfObjectInfo()
#define McalCry_HasRandomSeedBufferUsedOfObjectInfo()
#define McalCry_HasRipeMd160IdxOfObjectInfo()
#define McalCry_HasRipeMd160UsedOfObjectInfo()
#define McalCry_HasRsaOaepCrtSha1DecryptIdxOfObjectInfo()
#define McalCry_HasRsaOaepCrtSha1DecryptUsedOfObjectInfo()
#define McalCry_HasRsaOaepCrtSha256DecryptIdxOfObjectInfo()
#define McalCry_HasRsaOaepCrtSha256DecryptUsedOfObjectInfo()
#define McalCry_HasRsaOaepSha1DecryptIdxOfObjectInfo()
#define McalCry_HasRsaOaepSha1DecryptUsedOfObjectInfo()
#define McalCry_HasRsaOaepSha1EncryptIdxOfObjectInfo()
#define McalCry_HasRsaOaepSha1EncryptUsedOfObjectInfo()
#define McalCry_HasRsaOaepSha256DecryptIdxOfObjectInfo()
#define McalCry_HasRsaOaepSha256DecryptUsedOfObjectInfo()
#define McalCry_HasRsaOaepSha256EncryptIdxOfObjectInfo()
#define McalCry_HasRsaOaepSha256EncryptUsedOfObjectInfo()
#define McalCry_HasRsaPkcs1CrtGenerateIdxOfObjectInfo()
#define McalCry_HasRsaPkcs1CrtGenerateUsedOfObjectInfo()
#define McalCry_HasRsaPkcs1DecryptIdxOfObjectInfo()
#define McalCry_HasRsaPkcs1DecryptUsedOfObjectInfo()
#define McalCry_HasRsaPkcs1EncryptIdxOfObjectInfo()
#define McalCry_HasRsaPkcs1EncryptUsedOfObjectInfo()
#define McalCry_HasRsaPkcs1GenerateIdxOfObjectInfo()
#define McalCry_HasRsaPkcs1GenerateUsedOfObjectInfo()
#define McalCry_HasRsaPkcs1VerifyIdxOfObjectInfo()                                          (TRUE != FALSE)
#define McalCry_HasRsaPkcs1VerifyUsedOfObjectInfo()                                         (TRUE != FALSE)
#define McalCry_HasRsaPssGenerateIdxOfObjectInfo()
#define McalCry_HasRsaPssGenerateUsedOfObjectInfo()
#define McalCry_HasRsaPssVerifyIdxOfObjectInfo()                                            (TRUE != FALSE)
#define McalCry_HasRsaPssVerifyUsedOfObjectInfo()                                           (TRUE != FALSE)
#define McalCry_HasSHA1IdxOfObjectInfo()
#define McalCry_HasSHA1UsedOfObjectInfo()
#define McalCry_HasSHA256IdxOfObjectInfo()
#define McalCry_HasSHA256UsedOfObjectInfo()
#define McalCry_HasSHA384IdxOfObjectInfo()
#define McalCry_HasSHA384UsedOfObjectInfo()
#define McalCry_HasSHA3_256IdxOfObjectInfo()
#define McalCry_HasSHA3_256UsedOfObjectInfo()
#define McalCry_HasSHA512IdxOfObjectInfo()                                                  (TRUE != FALSE)
#define McalCry_HasSHA512UsedOfObjectInfo()                                                 (TRUE != FALSE)
#define McalCry_HasSheCmdGetIdIdxOfObjectInfo()
#define McalCry_HasSheCmdGetIdUsedOfObjectInfo()
#define McalCry_HasSipHashGenerateIdxOfObjectInfo()
#define McalCry_HasSipHashGenerateUsedOfObjectInfo()
#define McalCry_HasSipHashVerifyIdxOfObjectInfo()
#define McalCry_HasSipHashVerifyUsedOfObjectInfo()
#define McalCry_HasWorkspaceAddrOfObjectInfo()                                              (TRUE != FALSE)
#define McalCry_HasWorkspaceLengthOfObjectInfo()                                            (TRUE != FALSE)
#define McalCry_HasObjectInfoInd()                                                          (TRUE != FALSE)
#define McalCry_HasPrimitiveFct()                                                           (TRUE != FALSE)
#define McalCry_HasDispatchOfPrimitiveFct()                                                 (TRUE != FALSE)
#define McalCry_HasObjectInfoIndEndIdxOfPrimitiveFct()                                      (TRUE != FALSE)
#define McalCry_HasObjectInfoIndStartIdxOfPrimitiveFct()                                    (TRUE != FALSE)
#define McalCry_HasObjectInfoIndUsedOfPrimitiveFct()                                        (TRUE != FALSE)
#define McalCry_HasPrimitiveInfo()                                                          (TRUE != FALSE)
#define McalCry_HasCombinedOfPrimitiveInfo()                                                (TRUE != FALSE)
#define McalCry_HasContextOfPrimitiveInfo()                                                 (TRUE != FALSE)
#define McalCry_HasDefaultRandomSourceOfPrimitiveInfo()                                     (TRUE != FALSE)
#define McalCry_HasMaskedBitsOfPrimitiveInfo()                                              (TRUE != FALSE)
#define McalCry_HasPrimitiveFctIdxOfPrimitiveInfo()                                         (TRUE != FALSE)
#define McalCry_HasPrimitiveServiceInfo()                                                   (TRUE != FALSE)
#define McalCry_HasPrimitiveInfoEndIdxOfPrimitiveServiceInfo()                              (TRUE != FALSE)
#define McalCry_HasPrimitiveInfoStartIdxOfPrimitiveServiceInfo()                            (TRUE != FALSE)
#define McalCry_HasPrimitiveInfoUsedOfPrimitiveServiceInfo()                                (TRUE != FALSE)
#define McalCry_HasQueue()                                                                  (TRUE != FALSE)
#define McalCry_HasRandomSeedBuffer()
#define McalCry_HasRedirectionOfGeneral()                                                   (TRUE != FALSE)
#define McalCry_HasRipeMd160()
#define McalCry_HasWorkspaceOfRipeMd160()
#define McalCry_HasRsaOaepCrtSha1Decrypt()
#define McalCry_HasWorkspaceOfRsaOaepCrtSha1Decrypt()
#define McalCry_HasRsaOaepCrtSha256Decrypt()
#define McalCry_HasWorkspaceOfRsaOaepCrtSha256Decrypt()
#define McalCry_HasRsaOaepSha1Decrypt()
#define McalCry_HasWorkspaceOfRsaOaepSha1Decrypt()
#define McalCry_HasRsaOaepSha1Encrypt()
#define McalCry_HasWorkspaceOfRsaOaepSha1Encrypt()
#define McalCry_HasRsaOaepSha256Decrypt()
#define McalCry_HasWorkspaceOfRsaOaepSha256Decrypt()
#define McalCry_HasRsaOaepSha256Encrypt()
#define McalCry_HasWorkspaceOfRsaOaepSha256Encrypt()
#define McalCry_HasRsaPkcs1CrtGenerate()
#define McalCry_HasWorkspaceOfRsaPkcs1CrtGenerate()
#define McalCry_HasRsaPkcs1Decrypt()
#define McalCry_HasWorkspaceOfRsaPkcs1Decrypt()
#define McalCry_HasRsaPkcs1Encrypt()
#define McalCry_HasWorkspaceOfRsaPkcs1Encrypt()
#define McalCry_HasRsaPkcs1Generate()
#define McalCry_HasWorkspaceOfRsaPkcs1Generate()
#define McalCry_HasRsaPkcs1Verify()                                                         (TRUE != FALSE)
#define McalCry_HasWorkspaceOfRsaPkcs1Verify()                                              (TRUE != FALSE)
#define McalCry_HasRsaPssGenerate()
#define McalCry_HasWorkspaceOfRsaPssGenerate()
#define McalCry_HasRsaPssVerify()                                                           (TRUE != FALSE)
#define McalCry_HasWorkspaceOfRsaPssVerify()                                                (TRUE != FALSE)
#define McalCry_HasSHA1()
#define McalCry_HasWorkspaceOfSHA1()
#define McalCry_HasSHA256()
#define McalCry_HasWorkspaceOfSHA256()
#define McalCry_HasSHA384()
#define McalCry_HasWorkspaceOfSHA384()
#define McalCry_HasSHA3_256()
#define McalCry_HasWorkspaceOfSHA3_256()
#define McalCry_HasSHA512()                                                                 (TRUE != FALSE)
#define McalCry_HasWorkspaceOfSHA512()                                                      (TRUE != FALSE)
#define McalCry_HasSaveAndRestoreWorkspace()
#define McalCry_HasLengthOfSaveAndRestoreWorkspace()
#define McalCry_HasSheCmdGetId()
#define McalCry_HasWorkspaceOfSheCmdGetId()
#define McalCry_HasSheDebugCmdOfSheKeyUpdate()
#define McalCry_HasSheEnableCounterOfSheKeyUpdate()
#define McalCry_HasSheEnableFidOfSheKeyUpdate()
#define McalCry_HasSheInfoKeyRefOfSheKeyUpdate()
#define McalCry_HasSheKeys()
#define McalCry_HasSipHashGenerate()
#define McalCry_HasWorkspaceOfSipHashGenerate()
#define McalCry_HasSipHashVerify()
#define McalCry_HasWorkspaceOfSipHashVerify()
#define McalCry_HasSizeOfAesDecrypt()                                                       (TRUE != FALSE)
#define McalCry_HasSizeOfBufferLength()                                                     (TRUE != FALSE)
#define McalCry_HasSizeOfDriverObjectState()                                                (TRUE != FALSE)
#define McalCry_HasSizeOfHmacSha1Verify()                                                   (TRUE != FALSE)
#define McalCry_HasSizeOfKey()                                                              (TRUE != FALSE)
#define McalCry_HasSizeOfKeyElementInfo()                                                   (TRUE != FALSE)
#define McalCry_HasSizeOfKeyElements()                                                      (TRUE != FALSE)
#define McalCry_HasSizeOfKeyLock()                                                          (TRUE != FALSE)
#define McalCry_HasSizeOfKeyStorage()                                                       (TRUE != FALSE)
#define McalCry_HasSizeOfLock()                                                             (TRUE != FALSE)
#define McalCry_HasSizeOfObjectInfo()                                                       (TRUE != FALSE)
#define McalCry_HasSizeOfObjectInfoInd()                                                    (TRUE != FALSE)
#define McalCry_HasSizeOfPrimitiveFct()                                                     (TRUE != FALSE)
#define McalCry_HasSizeOfPrimitiveInfo()                                                    (TRUE != FALSE)
#define McalCry_HasSizeOfPrimitiveServiceInfo()                                             (TRUE != FALSE)
#define McalCry_HasSizeOfQueue()                                                            (TRUE != FALSE)
#define McalCry_HasSizeOfRsaPkcs1Verify()                                                   (TRUE != FALSE)
#define McalCry_HasSizeOfRsaPssVerify()                                                     (TRUE != FALSE)
#define McalCry_HasSizeOfSHA512()                                                           (TRUE != FALSE)
#define McalCry_HasSizeOfWrittenLength()                                                    (TRUE != FALSE)
#define McalCry_HasUnionWS_McalCry()                                                (TRUE != FALSE)
#define McalCry_HasUnionWS_McalCry_Aes()                                            (TRUE != FALSE)
#define McalCry_HasUseVStdLibOfGeneral()                                                    (TRUE != FALSE)
#define McalCry_HasVersionInfoApiOfGeneral()                                                (TRUE != FALSE)
#define McalCry_HasWatchdogTriggerFunctionOfGeneral()                                       (TRUE != FALSE)
#define McalCry_HasWrittenLength()                                                          (TRUE != FALSE)
#define McalCry_HasPCConfig()                                                               (TRUE != FALSE)
#define McalCry_HasAesDecryptOfPCConfig()                                                   (TRUE != FALSE)
#define McalCry_HasAlignKeyStorageOfGeneralOfPCConfig()                                     (TRUE != FALSE)
#define McalCry_HasBufferLengthOfPCConfig()                                                 (TRUE != FALSE)
#define McalCry_HasCmacAesRoundkeyReuseOfMacPrimitivesOfPCConfig()                          (TRUE != FALSE)
#define McalCry_HasDefaultRandomMaxRetriesOfGeneralOfPCConfig()                             (TRUE != FALSE)
#define McalCry_HasDriverObjectStateOfPCConfig()                                            (TRUE != FALSE)
#define McalCry_HasEnableAES256OfCipherPrimitivesOfPCConfig()                               (TRUE != FALSE)
#define McalCry_HasExpectedCompatibilityVersionOfPCConfig()
#define McalCry_HasFinalMagicNumberOfPCConfig()
#define McalCry_HasGeneratorCompatibilityVersionOfPCConfig()
#define McalCry_HasHmacSha1VerifyOfPCConfig()                                               (TRUE != FALSE)
#define McalCry_HasInitDataHashCodeOfPCConfig()
#define McalCry_HasKeyElementDeleteOfGeneralOfPCConfig()                                    (TRUE != FALSE)
#define McalCry_HasKeyElementInfoOfPCConfig()                                               (TRUE != FALSE)
#define McalCry_HasKeyElementsOfPCConfig()                                                  (TRUE != FALSE)
#define McalCry_HasKeyGenerateMaxLengthOfKeyGeneratePrimitivesOfPCConfig()                  (TRUE != FALSE)
#define McalCry_HasKeyLockOfPCConfig()                                                      (TRUE != FALSE)
#define McalCry_HasKeyOfPCConfig()                                                          (TRUE != FALSE)
#define McalCry_HasKeyStorageOfPCConfig()                                                   (TRUE != FALSE)
#define McalCry_HasKeyValiditySetCalloutFctNameOfConfigurableCalloutsOfPCConfig()
#define McalCry_HasKeyValueChangedCalloutFctNameOfConfigurableCalloutsOfPCConfig()
#define McalCry_HasLockOfPCConfig()                                                         (TRUE != FALSE)
#define McalCry_HasMainFunctionPeriodOfGeneralOfPCConfig()                                  (TRUE != FALSE)
#define McalCry_HasNumberOfLongTermPrimitiveWorkspaceOfGeneralOfPCConfig()                  (TRUE != FALSE)
#define McalCry_HasNvMEnableSetRamBlockStatusOfGeneralOfPCConfig()                          (TRUE != FALSE)
#define McalCry_HasNvManagementDataPerKeyOfNvStorageOfPCConfig()                            (TRUE != FALSE)
#define McalCry_HasNvWriteBlockFctNameOfNvStorageOfPCConfig()                               (TRUE != FALSE)
#define McalCry_HasObjectInfoIndOfPCConfig()                                                (TRUE != FALSE)
#define McalCry_HasObjectInfoOfPCConfig()                                                   (TRUE != FALSE)
#define McalCry_HasPrimitiveFctOfPCConfig()                                                 (TRUE != FALSE)
#define McalCry_HasPrimitiveInfoOfPCConfig()                                                (TRUE != FALSE)
#define McalCry_HasPrimitiveServiceInfoOfPCConfig()                                         (TRUE != FALSE)
#define McalCry_HasQueueOfPCConfig()                                                        (TRUE != FALSE)
#define McalCry_HasRedirectionOfGeneralOfPCConfig()                                         (TRUE != FALSE)
#define McalCry_HasRsaPkcs1VerifyOfPCConfig()                                               (TRUE != FALSE)
#define McalCry_HasRsaPssVerifyOfPCConfig()                                                 (TRUE != FALSE)
#define McalCry_HasSHA512OfPCConfig()                                                       (TRUE != FALSE)
#define McalCry_HasSheDebugCmdOfSheKeyUpdateOfPCConfig()
#define McalCry_HasSheEnableCounterOfSheKeyUpdateOfPCConfig()
#define McalCry_HasSheEnableFidOfSheKeyUpdateOfPCConfig()
#define McalCry_HasSheInfoKeyRefOfSheKeyUpdateOfPCConfig()
#define McalCry_HasSizeOfAesDecryptOfPCConfig()                                             (TRUE != FALSE)
#define McalCry_HasSizeOfBufferLengthOfPCConfig()                                           (TRUE != FALSE)
#define McalCry_HasSizeOfDriverObjectStateOfPCConfig()                                      (TRUE != FALSE)
#define McalCry_HasSizeOfHmacSha1VerifyOfPCConfig()                                         (TRUE != FALSE)
#define McalCry_HasSizeOfKeyElementInfoOfPCConfig()                                         (TRUE != FALSE)
#define McalCry_HasSizeOfKeyElementsOfPCConfig()                                            (TRUE != FALSE)
#define McalCry_HasSizeOfKeyLockOfPCConfig()                                                (TRUE != FALSE)
#define McalCry_HasSizeOfKeyOfPCConfig()                                                    (TRUE != FALSE)
#define McalCry_HasSizeOfKeyStorageOfPCConfig()                                             (TRUE != FALSE)
#define McalCry_HasSizeOfLockOfPCConfig()                                                   (TRUE != FALSE)
#define McalCry_HasSizeOfObjectInfoIndOfPCConfig()                                          (TRUE != FALSE)
#define McalCry_HasSizeOfObjectInfoOfPCConfig()                                             (TRUE != FALSE)
#define McalCry_HasSizeOfPrimitiveFctOfPCConfig()                                           (TRUE != FALSE)
#define McalCry_HasSizeOfPrimitiveInfoOfPCConfig()                                          (TRUE != FALSE)
#define McalCry_HasSizeOfPrimitiveServiceInfoOfPCConfig()                                   (TRUE != FALSE)
#define McalCry_HasSizeOfQueueOfPCConfig()                                                  (TRUE != FALSE)
#define McalCry_HasSizeOfRsaPkcs1VerifyOfPCConfig()                                         (TRUE != FALSE)
#define McalCry_HasSizeOfRsaPssVerifyOfPCConfig()                                           (TRUE != FALSE)
#define McalCry_HasSizeOfSHA512OfPCConfig()                                                 (TRUE != FALSE)
#define McalCry_HasSizeOfWrittenLengthOfPCConfig()                                          (TRUE != FALSE)
#define McalCry_HasUnionWS_McalCryOfPCConfig()                                      (TRUE != FALSE)
#define McalCry_HasUnionWS_McalCry_AesOfPCConfig()                                  (TRUE != FALSE)
#define McalCry_HasUseVStdLibOfGeneralOfPCConfig()                                          (TRUE != FALSE)
#define McalCry_HasVersionInfoApiOfGeneralOfPCConfig()                                      (TRUE != FALSE)
#define McalCry_HasWatchdogTriggerFunctionOfGeneralOfPCConfig()                             (TRUE != FALSE)
#define McalCry_HasWrittenLengthOfPCConfig()                                                (TRUE != FALSE)

#define McalCry_IncBufferLength(Index)                                                      McalCry_GetBufferLength(Index)++
#define McalCry_IncDriverObjectState(Index)                                                 McalCry_GetDriverObjectState(Index)++
#define McalCry_IncKeyLock(Index)                                                           McalCry_GetKeyLock(Index)++
#define McalCry_IncKeyStorage(Index)                                                        McalCry_GetKeyStorage(Index)++
#define McalCry_IncFamilyOfLastJob(Index)
#define McalCry_IncKeyIdOfLastJob(Index)
#define McalCry_IncModeOfLastJob(Index)
#define McalCry_IncLock(Index)                                                              McalCry_GetLock(Index)++
#define McalCry_IncLongTermWs(Index)
#define McalCry_IncLongTermWsLock(Index)
#define McalCry_IncQueue(Index)                                                             McalCry_GetQueue(Index)++
#define McalCry_IncRandomSeedBuffer(Index)
#define McalCry_IncLengthOfSaveAndRestoreWorkspace(Index)
#define McalCry_IncUnionWS_McalCry()                                                McalCry_GetUnionWS_McalCry()++
#define McalCry_IncUnionWS_McalCry_Aes()                                            McalCry_GetUnionWS_McalCry_Aes()++
#define McalCry_IncWrittenLength(Index)                                                     McalCry_GetWrittenLength(Index)++

#define McalCry_DecBufferLength(Index)                                                      McalCry_GetBufferLength(Index)--
#define McalCry_DecDriverObjectState(Index)                                                 McalCry_GetDriverObjectState(Index)--
#define McalCry_DecKeyLock(Index)                                                           McalCry_GetKeyLock(Index)--
#define McalCry_DecKeyStorage(Index)                                                        McalCry_GetKeyStorage(Index)--
#define McalCry_DecFamilyOfLastJob(Index)
#define McalCry_DecKeyIdOfLastJob(Index)
#define McalCry_DecModeOfLastJob(Index)
#define McalCry_DecLock(Index)                                                              McalCry_GetLock(Index)--
#define McalCry_DecLongTermWs(Index)
#define McalCry_DecLongTermWsLock(Index)
#define McalCry_DecQueue(Index)                                                             McalCry_GetQueue(Index)--
#define McalCry_DecRandomSeedBuffer(Index)
#define McalCry_DecLengthOfSaveAndRestoreWorkspace(Index)
#define McalCry_DecUnionWS_McalCry()                                                McalCry_GetUnionWS_McalCry()--
#define McalCry_DecUnionWS_McalCry_Aes()                                            McalCry_GetUnionWS_McalCry_Aes()--
#define McalCry_DecWrittenLength(Index)                                                     McalCry_GetWrittenLength(Index)--

#define McalCry_AddBufferLength(Index, Value)                                               McalCry_SetBufferLength(Index, (McalCry_GetBufferLength(Index) + Value))
#define McalCry_AddDriverObjectState(Index, Value)                                          McalCry_SetDriverObjectState(Index, (McalCry_GetDriverObjectState(Index) + Value))
#define McalCry_AddKeyLock(Index, Value)                                                    McalCry_SetKeyLock(Index, (McalCry_GetKeyLock(Index) + Value))
#define McalCry_AddKeyStorage(Index, Value)                                                 McalCry_SetKeyStorage(Index, (McalCry_GetKeyStorage(Index) + Value))
#define McalCry_AddFamilyOfLastJob(Index, Value)
#define McalCry_AddKeyIdOfLastJob(Index, Value)
#define McalCry_AddModeOfLastJob(Index, Value)
#define McalCry_AddLock(Index, Value)                                                       McalCry_SetLock(Index, (McalCry_GetLock(Index) + Value))
#define McalCry_AddLongTermWs(Index, Value)
#define McalCry_AddLongTermWsLock(Index, Value)
#define McalCry_AddQueue(Index, Value)                                                      McalCry_SetQueue(Index, (McalCry_GetQueue(Index) + Value))
#define McalCry_AddRandomSeedBuffer(Index, Value)
#define McalCry_AddLengthOfSaveAndRestoreWorkspace(Index, Value)
#define McalCry_AddUnionWS_McalCry(Value)                                           McalCry_SetUnionWS_McalCry((McalCry_GetUnionWS_McalCry() + Value))
#define McalCry_AddUnionWS_McalCry_Aes(Value)                                       McalCry_SetUnionWS_McalCry_Aes((McalCry_GetUnionWS_McalCry_Aes() + Value))
#define McalCry_AddWrittenLength(Index, Value)                                              McalCry_SetWrittenLength(Index, (McalCry_GetWrittenLength(Index) + Value))

#define McalCry_SubBufferLength(Index, Value)                                               McalCry_SetBufferLength(Index, (McalCry_GetBufferLength(Index) - Value))
#define McalCry_SubDriverObjectState(Index, Value)                                          McalCry_SetDriverObjectState(Index, (McalCry_GetDriverObjectState(Index) - Value))
#define McalCry_SubKeyLock(Index, Value)                                                    McalCry_SetKeyLock(Index, (McalCry_GetKeyLock(Index) - Value))
#define McalCry_SubKeyStorage(Index, Value)                                                 McalCry_SetKeyStorage(Index, (McalCry_GetKeyStorage(Index) - Value))
#define McalCry_SubFamilyOfLastJob(Index, Value)
#define McalCry_SubKeyIdOfLastJob(Index, Value)
#define McalCry_SubModeOfLastJob(Index, Value)
#define McalCry_SubLock(Index, Value)                                                       McalCry_SetLock(Index, (McalCry_GetLock(Index) - Value))
#define McalCry_SubLongTermWs(Index, Value)
#define McalCry_SubLongTermWsLock(Index, Value)
#define McalCry_SubQueue(Index, Value)                                                      McalCry_SetQueue(Index, (McalCry_GetQueue(Index) - Value))
#define McalCry_SubRandomSeedBuffer(Index, Value)
#define McalCry_SubLengthOfSaveAndRestoreWorkspace(Index, Value)
#define McalCry_SubUnionWS_McalCry(Value)                                           McalCry_SetUnionWS_McalCry((McalCry_GetUnionWS_McalCry() - Value))
#define McalCry_SubUnionWS_McalCry_Aes(Value)                                       McalCry_SetUnionWS_McalCry_Aes((McalCry_GetUnionWS_McalCry_Aes() - Value))
#define McalCry_SubWrittenLength(Index, Value)                                              McalCry_SetWrittenLength(Index, (McalCry_GetWrittenLength(Index) - Value))

#define McalCry_GetLTConfigIdxOfPBConfig()
#define McalCry_GetPCConfigIdxOfPBConfig()

#define McalCry_HasPBConfig()
#define McalCry_HasLTConfigIdxOfPBConfig()
#define McalCry_HasPCConfigIdxOfPBConfig()

#define McalCry_FreeLock(lockIdx) McalCry_SetLock((lockIdx), 0xFFFFFFFFUL)
#define McalCry_IsLockFree(lockIdx) (McalCry_GetLock((lockIdx))) == 0xFFFFFFFFUL
#define McalCry_IsLockOccupiedByJob(lockIdx, jobId) (McalCry_GetLock((lockIdx))) == (jobId)

typedef union
{
  eslt_WorkSpaceSHA1 wsSHA1;
  eslt_WorkSpaceSHA256 wsSHA256;
  eslt_WorkSpaceSHA384 wsSHA384;
  eslt_WorkSpaceSHA512 wsSHA512;
}McalCry_UnionWS_PreHash;

typedef union
{
  eslt_WorkSpaceEcP wsEcP;
  McalCry_UnionWS_PreHash wsPreHash;
}McalCry_WorkSpaceEcP;

typedef union
{
  eslt_WorkSpaceAES128 wsAES128;
}McalCry_WorkSpaceAESSubType;

typedef struct{
  uint8 mode;
  McalCry_WorkSpaceAESSubType wsAES;
}McalCry_WorkSpaceAES;

typedef struct{
  uint8 mode;
  eslt_WorkSpaceCMACAES wsCMACAES;
}McalCry_WorkSpaceCMACAES;

typedef union
{
  eslt_WorkSpaceEcP wsEcP;
  eslt_WorkSpaceSHA256 wsSHA256;
  eslt_WorkSpaceAES128 wsAes;
}McalCry_WorkSpaceISO15118;

typedef uint8 McalCry_WorkSpaceKeySetValid;

typedef uint8 McalCry_WorkSpaceKeyGenerateSymmetric;

typedef P2FUNC(Std_ReturnType, MCALCRY_CODE, McalCry_DispatchFctPtrType)(uint32 objectId, P2VAR(Crypto_JobType, AUTOMATIC, MCALCRY_APPL_VAR) job,  Crypto_OperationModeType mode);

typedef P2VAR(uint8, AUTOMATIC, MCALCRY_APPL_VAR) McalCry_SaveAndRestoreWorkspaceAddressType;

typedef P2VAR(Crypto_JobType, TYPEDEF, MCALCRY_APPL_VAR) McalCry_JobPtrType;

typedef union
{
  McalCry_WorkSpaceAES AesDecrypt;
}McalCry_UnionWS_McalCry_Aes_Type;

typedef struct sMcalCry_WS_McalCry_Aes_Type{
#if(MCALCRY_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  McalCry_UnionWS_McalCry_Aes_Type primWS;
}McalCry_WS_McalCry_Aes_Type;

typedef union
{
  eslt_WorkSpaceSHA512 SHA512;
  eslt_WorkSpaceHMACSHA1 HmacSha1Verify;
  eslt_WorkSpaceRSAPSSver RsaPssVerify;
  eslt_WorkSpaceRSAver RsaPkcs1Verify;
}McalCry_UnionWS_McalCry_Type;

typedef struct sMcalCry_WS_McalCry_Type{
#if(MCALCRY_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  McalCry_UnionWS_McalCry_Type primWS;
}McalCry_WS_McalCry_Type;

typedef P2VAR(McalCry_WorkSpaceAES, MCALCRY_CONST, MCALCRY_VAR_NOINIT) McalCry_McalCry_WorkSpaceAES_PtrType;
typedef P2VAR(eslt_WorkSpaceSHA512, MCALCRY_CONST, MCALCRY_VAR_NOINIT) McalCry_eslt_WorkSpaceSHA512_PtrType;
typedef P2VAR(eslt_WorkSpaceHMACSHA1, MCALCRY_CONST, MCALCRY_VAR_NOINIT) McalCry_eslt_WorkSpaceHMACSHA1_PtrType;
typedef P2VAR(eslt_WorkSpaceRSAPSSver, MCALCRY_CONST, MCALCRY_VAR_NOINIT) McalCry_eslt_WorkSpaceRSAPSSver_PtrType;
typedef P2VAR(eslt_WorkSpaceRSAver, MCALCRY_CONST, MCALCRY_VAR_NOINIT) McalCry_eslt_WorkSpaceRSAver_PtrType;

typedef uint8_least McalCry_AesDecryptIterType;

typedef uint8_least McalCry_HmacSha1VerifyIterType;

typedef uint8_least McalCry_KeyIterType;

typedef uint8_least McalCry_KeyElementInfoIterType;

typedef uint8_least McalCry_KeyElementsIterType;

typedef uint16_least McalCry_KeyStorageIterType;

typedef uint8_least McalCry_ObjectInfoIterType;

typedef uint8_least McalCry_ObjectInfoIndIterType;

typedef uint8_least McalCry_PrimitiveFctIterType;

typedef uint8_least McalCry_PrimitiveInfoIterType;

typedef uint8_least McalCry_PrimitiveServiceInfoIterType;

typedef uint8_least McalCry_QueueIterType;

typedef uint8_least McalCry_RsaPkcs1VerifyIterType;

typedef uint8_least McalCry_RsaPssVerifyIterType;

typedef uint8_least McalCry_SHA512IterType;

typedef McalCry_ObjectInfoIterType McalCry_BufferLengthIterType;

typedef McalCry_ObjectInfoIterType McalCry_DriverObjectStateIterType;

typedef McalCry_KeyIterType McalCry_KeyLockIterType;

typedef McalCry_ObjectInfoIterType McalCry_LockIterType;

typedef McalCry_ObjectInfoIterType McalCry_WrittenLengthIterType;

typedef boolean McalCry_AlignKeyStorageOfGeneralType;

typedef uint32 McalCry_BufferLengthType;

typedef boolean McalCry_CmacAesRoundkeyReuseOfMacPrimitivesType;

typedef uint8 McalCry_DefaultRandomMaxRetriesOfGeneralType;

typedef uint8 McalCry_DriverObjectStateType;

typedef boolean McalCry_EnableAES256OfCipherPrimitivesType;

typedef uint8 McalCry_KeyElementsEndIdxOfKeyType;

typedef uint8 McalCry_KeyElementsStartIdxOfKeyType;

typedef boolean McalCry_KeyElementDeleteOfGeneralType;

typedef uint8 McalCry_IdOfKeyElementInfoType;

typedef uint16 McalCry_LengthOfKeyElementInfoType;

typedef uint8 McalCry_MaskedBitsOfKeyElementInfoType;

typedef boolean McalCry_OnceOfKeyElementInfoType;

typedef boolean McalCry_PartialOfKeyElementInfoType;

typedef boolean McalCry_PersistOfKeyElementInfoType;

typedef uint8 McalCry_ReadOfKeyElementInfoType;

typedef uint8 McalCry_WriteOfKeyElementInfoType;

typedef uint8 McalCry_IdOfKeyElementsType;

typedef uint8 McalCry_KeyElementInfoIdxOfKeyElementsType;

typedef uint16 McalCry_KeyStorageEndIdxOfKeyElementsType;

typedef uint16 McalCry_KeyStorageExtensionIdxOfKeyElementsType;

typedef uint16 McalCry_KeyStorageStartIdxOfKeyElementsType;

typedef uint16 McalCry_KeyStorageValidIdxOfKeyElementsType;

typedef uint16 McalCry_KeyStorageWrittenLengthEndIdxOfKeyElementsType;

typedef uint16 McalCry_KeyStorageWrittenLengthStartIdxOfKeyElementsType;

typedef uint8 McalCry_KeyGenerateMaxLengthOfKeyGeneratePrimitivesType;

typedef uint8 McalCry_KeyLockType;

typedef uint8 McalCry_KeyStorageType;

typedef uint32 McalCry_LockType;

typedef uint8 McalCry_MainFunctionPeriodOfGeneralType;

typedef uint8 McalCry_NumberOfLongTermPrimitiveWorkspaceOfGeneralType;

typedef boolean McalCry_NvMEnableSetRamBlockStatusOfGeneralType;

typedef uint8 McalCry_NvManagementDataPerKeyOfNvStorageType;

typedef uint32 McalCry_NvWriteBlockFctNameOfNvStorageType;

typedef uint8 McalCry_AesDecryptIdxOfObjectInfoType;

typedef boolean McalCry_AesDecryptUsedOfObjectInfoType;

typedef uint8 McalCry_HmacSha1VerifyIdxOfObjectInfoType;

typedef boolean McalCry_HmacSha1VerifyUsedOfObjectInfoType;

typedef uint8 McalCry_QueueIdxOfObjectInfoType;

typedef uint8 McalCry_RsaPkcs1VerifyIdxOfObjectInfoType;

typedef boolean McalCry_RsaPkcs1VerifyUsedOfObjectInfoType;

typedef uint8 McalCry_RsaPssVerifyIdxOfObjectInfoType;

typedef boolean McalCry_RsaPssVerifyUsedOfObjectInfoType;

typedef uint8 McalCry_SHA512IdxOfObjectInfoType;

typedef boolean McalCry_SHA512UsedOfObjectInfoType;

typedef uint32 McalCry_WorkspaceLengthOfObjectInfoType;

typedef uint8 McalCry_ObjectInfoIndType;

typedef uint8 McalCry_ObjectInfoIndEndIdxOfPrimitiveFctType;

typedef uint8 McalCry_ObjectInfoIndStartIdxOfPrimitiveFctType;

typedef boolean McalCry_ObjectInfoIndUsedOfPrimitiveFctType;

typedef uint32 McalCry_CombinedOfPrimitiveInfoType;

typedef boolean McalCry_ContextOfPrimitiveInfoType;

typedef boolean McalCry_DefaultRandomSourceOfPrimitiveInfoType;

typedef uint8 McalCry_MaskedBitsOfPrimitiveInfoType;

typedef uint8 McalCry_PrimitiveFctIdxOfPrimitiveInfoType;

typedef uint8 McalCry_PrimitiveInfoEndIdxOfPrimitiveServiceInfoType;

typedef uint8 McalCry_PrimitiveInfoStartIdxOfPrimitiveServiceInfoType;

typedef boolean McalCry_PrimitiveInfoUsedOfPrimitiveServiceInfoType;

typedef boolean McalCry_RedirectionOfGeneralType;

typedef uint8 McalCry_SizeOfAesDecryptType;

typedef uint8 McalCry_SizeOfBufferLengthType;

typedef uint8 McalCry_SizeOfDriverObjectStateType;

typedef uint8 McalCry_SizeOfHmacSha1VerifyType;

typedef uint8 McalCry_SizeOfKeyType;

typedef uint8 McalCry_SizeOfKeyElementInfoType;

typedef uint8 McalCry_SizeOfKeyElementsType;

typedef uint8 McalCry_SizeOfKeyLockType;

typedef uint16 McalCry_SizeOfKeyStorageType;

typedef uint8 McalCry_SizeOfLockType;

typedef uint8 McalCry_SizeOfObjectInfoType;

typedef uint8 McalCry_SizeOfObjectInfoIndType;

typedef uint8 McalCry_SizeOfPrimitiveFctType;

typedef uint8 McalCry_SizeOfPrimitiveInfoType;

typedef uint8 McalCry_SizeOfPrimitiveServiceInfoType;

typedef uint8 McalCry_SizeOfQueueType;

typedef uint8 McalCry_SizeOfRsaPkcs1VerifyType;

typedef uint8 McalCry_SizeOfRsaPssVerifyType;

typedef uint8 McalCry_SizeOfSHA512Type;

typedef uint8 McalCry_SizeOfWrittenLengthType;

typedef boolean McalCry_UseVStdLibOfGeneralType;

typedef boolean McalCry_VersionInfoApiOfGeneralType;

typedef uint32 McalCry_WatchdogTriggerFunctionOfGeneralType;

typedef uint32 McalCry_WrittenLengthType;

typedef struct sMcalCry_AesDecryptType{
  McalCry_McalCry_WorkSpaceAES_PtrType WorkspaceOfAesDecrypt;
}McalCry_AesDecryptType;

typedef struct sMcalCry_HmacSha1VerifyType{
  McalCry_eslt_WorkSpaceHMACSHA1_PtrType WorkspaceOfHmacSha1Verify;
}McalCry_HmacSha1VerifyType;

typedef struct sMcalCry_KeyType{
  McalCry_KeyElementsEndIdxOfKeyType KeyElementsEndIdxOfKey;
  McalCry_KeyElementsStartIdxOfKeyType KeyElementsStartIdxOfKey;
}McalCry_KeyType;

typedef struct sMcalCry_KeyElementInfoType{
  McalCry_LengthOfKeyElementInfoType LengthOfKeyElementInfo;
  McalCry_IdOfKeyElementInfoType IdOfKeyElementInfo;
  McalCry_MaskedBitsOfKeyElementInfoType MaskedBitsOfKeyElementInfo;
  McalCry_ReadOfKeyElementInfoType ReadOfKeyElementInfo;
  McalCry_WriteOfKeyElementInfoType WriteOfKeyElementInfo;
}McalCry_KeyElementInfoType;

typedef struct sMcalCry_KeyElementsType{
  McalCry_KeyStorageEndIdxOfKeyElementsType KeyStorageEndIdxOfKeyElements;
  McalCry_KeyStorageStartIdxOfKeyElementsType KeyStorageStartIdxOfKeyElements;
  McalCry_IdOfKeyElementsType IdOfKeyElements;
}McalCry_KeyElementsType;

typedef struct sMcalCry_ObjectInfoType{
  McalCry_WorkspaceLengthOfObjectInfoType WorkspaceLengthOfObjectInfo;
  McalCry_AesDecryptIdxOfObjectInfoType AesDecryptIdxOfObjectInfo;
  McalCry_HmacSha1VerifyIdxOfObjectInfoType HmacSha1VerifyIdxOfObjectInfo;
  McalCry_QueueIdxOfObjectInfoType QueueIdxOfObjectInfo;
  McalCry_RsaPkcs1VerifyIdxOfObjectInfoType RsaPkcs1VerifyIdxOfObjectInfo;
  McalCry_RsaPssVerifyIdxOfObjectInfoType RsaPssVerifyIdxOfObjectInfo;
  McalCry_SHA512IdxOfObjectInfoType SHA512IdxOfObjectInfo;
  P2VAR(uint8, AUTOMATIC, MCALCRY_VAR_NOINIT)  WorkspaceAddrOfObjectInfo;
}McalCry_ObjectInfoType;

typedef struct sMcalCry_PrimitiveFctType{
  McalCry_ObjectInfoIndEndIdxOfPrimitiveFctType ObjectInfoIndEndIdxOfPrimitiveFct;
  McalCry_ObjectInfoIndStartIdxOfPrimitiveFctType ObjectInfoIndStartIdxOfPrimitiveFct;
  McalCry_DispatchFctPtrType DispatchOfPrimitiveFct;
}McalCry_PrimitiveFctType;

typedef struct sMcalCry_PrimitiveInfoType{
  McalCry_CombinedOfPrimitiveInfoType CombinedOfPrimitiveInfo;
  McalCry_MaskedBitsOfPrimitiveInfoType MaskedBitsOfPrimitiveInfo;
  McalCry_PrimitiveFctIdxOfPrimitiveInfoType PrimitiveFctIdxOfPrimitiveInfo;
}McalCry_PrimitiveInfoType;

typedef struct sMcalCry_PrimitiveServiceInfoType{
  McalCry_PrimitiveInfoEndIdxOfPrimitiveServiceInfoType PrimitiveInfoEndIdxOfPrimitiveServiceInfo;
  McalCry_PrimitiveInfoStartIdxOfPrimitiveServiceInfoType PrimitiveInfoStartIdxOfPrimitiveServiceInfo;
}McalCry_PrimitiveServiceInfoType;

typedef struct sMcalCry_RsaPkcs1VerifyType{
  McalCry_eslt_WorkSpaceRSAver_PtrType WorkspaceOfRsaPkcs1Verify;
}McalCry_RsaPkcs1VerifyType;

typedef struct sMcalCry_RsaPssVerifyType{
  McalCry_eslt_WorkSpaceRSAPSSver_PtrType WorkspaceOfRsaPssVerify;
}McalCry_RsaPssVerifyType;

typedef struct sMcalCry_SHA512Type{
  McalCry_eslt_WorkSpaceSHA512_PtrType WorkspaceOfSHA512;
}McalCry_SHA512Type;

typedef struct McalCry_KeyLockStructSTag{
  McalCry_KeyLockType CryptoKey_Fbl_Decrypt_Aes128;
  McalCry_KeyLockType CryptoKey_Fbl_Signature_Class_C;
  McalCry_KeyLockType CryptoKey_Fbl_Signature_Ed25519;
  McalCry_KeyLockType CryptoKey_Fbl_Signature_Rsa1024;
  McalCry_KeyLockType CryptoKey_Fbl_Signature_Rsa2048;
  McalCry_KeyLockType CryptoKey_Fbl_Signature_Rsa3072;
  McalCry_KeyLockType CryptoKey_Fbl_HashDummy;
}McalCry_KeyLockStructSType;

typedef struct McalCry_QueueStructSTag{
  McalCry_JobPtrType McalCry_Aes;
  McalCry_JobPtrType McalCry;
}McalCry_QueueStructSType;

typedef union McalCry_KeyLockUTag{
  McalCry_KeyLockType raw[7];
  McalCry_KeyLockStructSType str;
}McalCry_KeyLockUType;

typedef union McalCry_QueueUTag{
  McalCry_JobPtrType raw[2];
  McalCry_QueueStructSType str;
}McalCry_QueueUType;

typedef P2CONST(McalCry_AesDecryptType, TYPEDEF, MCALCRY_CONST) McalCry_AesDecryptPtrType;

typedef P2VAR(McalCry_BufferLengthType, TYPEDEF, MCALCRY_VAR_NOINIT) McalCry_BufferLengthPtrType;

typedef P2VAR(McalCry_DriverObjectStateType, TYPEDEF, MCALCRY_VAR_NOINIT) McalCry_DriverObjectStatePtrType;

typedef P2CONST(McalCry_HmacSha1VerifyType, TYPEDEF, MCALCRY_CONST) McalCry_HmacSha1VerifyPtrType;

typedef P2CONST(McalCry_KeyType, TYPEDEF, MCALCRY_CONST) McalCry_KeyPtrType;

typedef P2CONST(McalCry_KeyElementInfoType, TYPEDEF, MCALCRY_CONST) McalCry_KeyElementInfoPtrType;

typedef P2CONST(McalCry_KeyElementsType, TYPEDEF, MCALCRY_CONST) McalCry_KeyElementsPtrType;

typedef P2VAR(McalCry_KeyLockType, TYPEDEF, MCALCRY_VAR_NOINIT) McalCry_KeyLockPtrType;

typedef P2VAR(McalCry_KeyStorageType, TYPEDEF, MCALCRY_VAR_NOINIT) McalCry_KeyStoragePtrType;

typedef P2VAR(McalCry_LockType, TYPEDEF, MCALCRY_VAR_NOINIT) McalCry_LockPtrType;

typedef P2CONST(McalCry_ObjectInfoType, TYPEDEF, MCALCRY_CONST) McalCry_ObjectInfoPtrType;

typedef P2CONST(McalCry_ObjectInfoIndType, TYPEDEF, MCALCRY_CONST) McalCry_ObjectInfoIndPtrType;

typedef P2CONST(McalCry_PrimitiveFctType, TYPEDEF, MCALCRY_CONST) McalCry_PrimitiveFctPtrType;

typedef P2CONST(McalCry_PrimitiveInfoType, TYPEDEF, MCALCRY_CONST) McalCry_PrimitiveInfoPtrType;

typedef P2CONST(McalCry_PrimitiveServiceInfoType, TYPEDEF, MCALCRY_CONST) McalCry_PrimitiveServiceInfoPtrType;

typedef P2VAR(McalCry_JobPtrType, TYPEDEF, MCALCRY_VAR_NOINIT) McalCry_QueuePtrType;

typedef P2CONST(McalCry_RsaPkcs1VerifyType, TYPEDEF, MCALCRY_CONST) McalCry_RsaPkcs1VerifyPtrType;

typedef P2CONST(McalCry_RsaPssVerifyType, TYPEDEF, MCALCRY_CONST) McalCry_RsaPssVerifyPtrType;

typedef P2CONST(McalCry_SHA512Type, TYPEDEF, MCALCRY_CONST) McalCry_SHA512PtrType;

typedef P2VAR(McalCry_WS_McalCry_Type, TYPEDEF, MCALCRY_VAR_NOINIT) McalCry_UnionWS_McalCryPtrType;

typedef P2VAR(McalCry_WS_McalCry_Aes_Type, TYPEDEF, MCALCRY_VAR_NOINIT) McalCry_UnionWS_McalCry_AesPtrType;

typedef P2VAR(McalCry_WrittenLengthType, TYPEDEF, MCALCRY_VAR_NOINIT) McalCry_WrittenLengthPtrType;

typedef P2CONST(McalCry_NvWriteBlockFctNameOfNvStorageType, TYPEDEF, MCALCRY_CONST) McalCry_NvWriteBlockFctNameOfNvStorageOfPCConfigPtrType;

typedef P2CONST(McalCry_WatchdogTriggerFunctionOfGeneralType, TYPEDEF, MCALCRY_CONST) McalCry_WatchdogTriggerFunctionOfGeneralOfPCConfigPtrType;

typedef struct sMcalCry_PCConfigType{
  uint8 McalCry_PCConfigNeverUsed;
}McalCry_PCConfigType;

typedef McalCry_PCConfigType McalCry_ConfigType;

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_AesDecryptType, MCALCRY_CONST) McalCry_AesDecrypt[1];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_HmacSha1VerifyType, MCALCRY_CONST) McalCry_HmacSha1Verify[1];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_KeyType, MCALCRY_CONST) McalCry_Key[7];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_KeyElementInfoType, MCALCRY_CONST) McalCry_KeyElementInfo[11];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_KeyElementsType, MCALCRY_CONST) McalCry_KeyElements[11];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_ObjectInfoType, MCALCRY_CONST) McalCry_ObjectInfo[2];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_8BIT

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_ObjectInfoIndType, MCALCRY_CONST) McalCry_ObjectInfoInd[5];
#define MCALCRY_STOP_SEC_CONST_8BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_PrimitiveFctType, MCALCRY_CONST) McalCry_PrimitiveFct[5];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_PrimitiveInfoType, MCALCRY_CONST) McalCry_PrimitiveInfo[14];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_PrimitiveServiceInfoType, MCALCRY_CONST) McalCry_PrimitiveServiceInfo[20];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_RsaPkcs1VerifyType, MCALCRY_CONST) McalCry_RsaPkcs1Verify[1];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_RsaPssVerifyType, MCALCRY_CONST) McalCry_RsaPssVerify[1];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern CONST(McalCry_SHA512Type, MCALCRY_CONST) McalCry_SHA512[1];
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

extern VAR(McalCry_BufferLengthType, MCALCRY_VAR_NOINIT) McalCry_BufferLength[2];
#define MCALCRY_STOP_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

extern VAR(McalCry_DriverObjectStateType, MCALCRY_VAR_NOINIT) McalCry_DriverObjectState[2];
#define MCALCRY_STOP_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

extern VAR(McalCry_KeyLockUType, MCALCRY_VAR_NOINIT) McalCry_KeyLock;
#define MCALCRY_STOP_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

extern VAR(McalCry_KeyStorageType, MCALCRY_VAR_NOINIT) McalCry_KeyStorage[924];
#define MCALCRY_STOP_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

extern VAR(McalCry_LockType, MCALCRY_VAR_NOINIT) McalCry_Lock[2];
#define MCALCRY_STOP_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern VAR(McalCry_QueueUType, MCALCRY_VAR_NOINIT) McalCry_Queue;
#define MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern VAR(McalCry_WS_McalCry_Type, MCALCRY_VAR_NOINIT) McalCry_UnionWS_McalCry;
#define MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

extern VAR(McalCry_WS_McalCry_Aes_Type, MCALCRY_VAR_NOINIT) McalCry_UnionWS_McalCry_Aes;
#define MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

extern VAR(McalCry_WrittenLengthType, MCALCRY_VAR_NOINIT) McalCry_WrittenLength[2];
#define MCALCRY_STOP_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

extern FUNC(void, MCALCRY_APPL_CODE) FblLookForWatchdogVoid(void);

#if !defined (MCALCRY_NOUNIT_CSLUNIT)

#endif

#endif

