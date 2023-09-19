#if !defined(SECM_CFG_H)
#define SECM_CFG_H

#define SEC_CLASS_DDD                         0u
#define SEC_CLASS_C                           1u
#define SEC_CLASS_CCC                         2u
#define SEC_CLASS_VENDOR                      3u
#define SEC_DEVELOPMENT                       1u
#define SEC_PRODUCTION                        2u
#define SEC_ADDRESS                           1u
#define SEC_FILE                              2u
#define SEC_CRC_SPEED_OPTIMIZED               0u
#define SEC_CRC_SIZE_OPTIMIZED                1u
#define SEC_CRC_MODE_NON_REFLECTED            0u
#define SEC_CRC_MODE_REFLECTED                1u
#define SEC_RIPEMD160                         0u
#define SEC_SHA1                              1u
#define SEC_SHA256                            2u
#define SEC_SHA512                            3u
#define SEC_AES128                            0u
#define SEC_AES192                            1u
#define SEC_AES256                            2u
#define SEC_CRC16_CCITT                       1u
#define SEC_CRC16                             SEC_CRC16_CCITT
#define SEC_CRC32                             0u
#define SEC_CRC64                             2u
#define SEC_CHECKSUM_TYPE_CRC                 0u
#define SEC_CHECKSUM_TYPE_HASH                1u
#define SEC_RSA_KEY_LENGTH_1024               0u
#define SEC_RSA_KEY_LENGTH_1536               1u
#define SEC_RSA_KEY_LENGTH_2048               2u
#define SEC_RSA_KEY_LENGTH_3072               3u
#define SEC_RSA_KEY_LENGTH_4096               4u
#define SEC_SIGNATURE_SCHEME_RSA_V15          0u
#define SEC_SIGNATURE_SCHEME_RSA_PSS          1u
#define SEC_SIGNATURE_SCHEME_ECDSA_CURVE25519 2u
#define SEC_SIGNATURE_SCHEME_ECDSA_CURVEP256  3u
#define SEC_INVALID_SMH_KEY_ID                0xFFFFFFFFu
#define SEC_INVALID_SMH_JOB_ID                0xFFFFFFFFu
#define SEC_INVALID_CSM_KEY_ID                0xFFFFFFFFu
#define SEC_INVALID_CSM_JOB_ID                0xFFFFFFFFu
#define SEC_CRC_OPT                                 SEC_CRC_SPEED_OPTIMIZED
#define SmhConf_SmhDecryption_SmhDecryptionConfig                        0x00000000u
#define SmhConf_SmhStreamVerificationCrc_SmhSecurityClassDDDConfig       0x00000000u
#define SmhConf_SmhStreamVerificationMac_SmhSecurityClassCConfig         0x00000000u
#define SmhConf_SmhStreamVerificationSignature_SmhSecurityClassCCCConfig 0x00000000u
#define SmhConf_SmhJob_SmhJob_AesDecryption                              0x00000000u
#define SmhConf_SmhJob_SmhJob_Verify_ClassC                              0x00000001u
#define SmhConf_SmhJob_SmhJob_Verify_ClassCCC                            0x00000002u
#define SmhConf_SmhJob_SmhJob_Verify_DummySha512                         0x00000003u
#define SmhConf_SmhCryptographicKeys_AesKey                              0x00000000u
#define SmhConf_SmhCryptographicKeys_ClassCCC_Ed25519Key                 0x00000001u
#define SmhConf_SmhCryptographicKeys_ClassC_Key                          0x00000002u
#define SmhConf_SmhCryptographicKeys_ClassCCC_Rsa1024Key                 0x00000003u
#define SmhConf_SmhCryptographicKeys_ClassCCC_Rsa2048Key                 0x00000004u
#define SmhConf_SmhCryptographicKeys_ClassCCC_Rsa3072Key                 0x00000005u
#define SecM_GetSizeOfDecryptionPrimitives() 0x00000001u
#define SecM_GetSizeOfCrcPrimitives()        0x00000001u
#define SecM_GetSizeOfHashPrimitives()       0x00000000u
#define SecM_GetSizeOfMacPrimitives()        0x00000001u
#define SecM_GetSizeOfSignaturePrimitives()  0x00000001u
#define SecM_GetSizeOfJobInfo()              0x00000004u
#define SecM_GetSizeOfCryptogrphicKeys()     0x00000006u
#define SEC_MODE                 SEC_PRODUCTION
#define SEC_WATCHDOG_CYCLE_COUNT 0x00000020u
#define SEC_DISABLE_KEY_LOCATION_RAM
#define SEC_ENABLE_CRYPTOGRAPHIC_KEYS
#define SEC_ENABLE_CSM
#define SEC_SIZE_CHECKSUM_CRC SEC_SIZE_CHECKSUM_CRC_32
#define SEC_CRC_32_OPT        SEC_CRC_SPEED_OPTIMIZED
#define SEC_CRC_32_INITIAL    0xFFFFFFFFu
#define SEC_CRC_32_POLYNOMIAL 0xEDB88320u
#define SEC_CRC_32_MODE       SEC_CRC_MODE_REFLECTED
#define SEC_CRC_32_FINAL      0xFFFFFFFFu
#define SEC_CRC_TYPE          SEC_CRC32
#define SEC_ENABLE_CRC
#define SEC_DISABLE_CRC_TYPE_CRC16
#define SEC_ENABLE_CRC_TYPE_CRC32
#define SEC_DISABLE_CRC_TYPE_CRC64
#define SEC_KEY_TIMEOUT               100u
#define SEC_CALL_CYCLE                10u
#define SEC_DEFAULT_DECRYPTION_CONFIG SmhConf_SmhDecryption_SmhDecryptionConfig
#define SEC_ENABLE_DECRYPTION
#define SEC_DISABLE_ENCRYPTION
#define SEC_SECURITY_CLASS_VERIFY SEC_CLASS_CCC
#define SecM_VerifySignature      SecM_VerifyClass_CCC
#define SecM_VerifyClassDDD       SecM_VerifyClass_DDD
#define SecM_VerifyClassC         SecM_Verify_ClassC
#define SecM_VerifyClassCCC       SecM_VerifyClass_CCC
#define SEC_ENABLE_VERIFY_CRC
#define SEC_DISABLE_VERIFY_HASH
#define SEC_ENABLE_VERIFY_MAC
#define SEC_DISABLE_VERIFY_MAC_CONTEXT_HANDLING
#define SEC_ENABLE_VERIFY_SIGNATURE
#define SEC_DISABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING
#define SEC_DISABLE_VERIFICATION_DISCRETE_HASH_CALC
#define SecM_Verification                    SecM_Verification_ClassCCC
#define SEC_SECURITY_CLASS_VERIFICATION      SEC_CLASS_CCC
#define SEC_SECURITY_CLASS                   SEC_SECURITY_CLASS_VERIFICATION
#define SEC_VER_SIG_OFFSET                   0x00000000u
#define SEC_VER_CRC_OFFSET                   0x00000000u
#define SecM_VerificationClassDDD            SecM_VerificationClassDDD
#define SecM_VerificationClassC              SecM_Verification_ClassC
#define SecM_VerificationClassCCC            SecM_Verification_ClassCCC
#define SEC_VERIFY_CLASS_C_DIGEST_SIZE       SEC_SIZE_HASH_SHA1
#define SEC_VERIFY_CLASS_C_VERIFY_SIZE       SEC_SIZE_HASH_SHA1
#define SEC_VERIFY_CLASS_C_VERIFY_OFFSET     0x00000000u
#define SEC_VERIFY_CLASS_C_CHECKSUM_OFFSET   SEC_VERIFY_CLASS_C_VERIFY_SIZE
#define SEC_SIZE_SIG_RSA                     SEC_SIZE_SIG_RSA2048
#define SEC_VERIFY_CLASS_CCC_VERIFY_SIZE     SEC_SIZE_SIG_RSA2048
#define SEC_VERIFY_CLASS_CCC_VERIFY_OFFSET   0x00000000u
#define SEC_VERIFY_CLASS_CCC_CHECKSUM_OFFSET SEC_VERIFY_CLASS_CCC_VERIFY_SIZE
#define SEC_VERIFY_CLASS_DDD_DIGEST_SIZE     SEC_SIZE_CHECKSUM_CRC_32
#define SEC_VERIFY_CLASS_DDD_VERIFY_SIZE     SEC_SIZE_CHECKSUM_CRC_32
#define SEC_VERIFY_CLASS_DDD_VERIFY_OFFSET   0x00000000u
#define SEC_VERIFY_CLASS_DDD_CHECKSUM_OFFSET SEC_VERIFY_CLASS_DDD_VERIFY_SIZE
#define SEC_MEMORY_ACCESS                    SEC_ADDRESS
#define SEC_VERIFY_BYTES                     0x0040u
#define SEC_VER_MAX_CONFIG_COUNT             0x0004u
#define SEC_ENABLE_SECURITY_CLASS_DDD
#define SEC_ENABLE_SECURITY_CLASS_C
#define SEC_ENABLE_SECURITY_CLASS_CCC
#define SEC_DISABLE_CRC_TOTAL
#define SEC_DISABLE_CRC_WRITTEN
#define SEC_DISABLE_CRC_WRITTEN_GET
#define SEC_DISABLE_VERIFICATION_ASSERT_READ_COUNT
#define SEC_DISABLE_VERIFICATION_RANGE_CHECK
#define SEC_DISABLE_VERIFICATION_WRAPPER
#define SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH
#define SEC_ENABLE_VERIFICATION_DATA_LENGTH
#define SEC_DISABLE_VENDOR_CHECKSUM
#define SEC_ENABLE_JOB_INITKEY_AES
#define SEC_ENABLE_JOB_INITKEY_MAC
#define SEC_DISABLE_JOB_INITKEY_SYMMETRIC
#define SEC_ENABLE_JOB_INITKEY_ASYMMETRIC
#define SEC_DISABLE_JOB_INITKEY_PBKDF2
#define SEC_ENABLE_JOB_HASH
#define SEC_DISABLE_JOB_RANDOMGENERATE
#define SEC_ENABLE_JOB_MACVERIFY
#define SEC_DISABLE_JOB_MACGENERATE
#define SEC_DISABLE_JOB_ENCRYPTION
#define SEC_ENABLE_JOB_DECRYPTION
#define SEC_ENABLE_JOB_SIGNATUREVERIFY
#define SEC_DISABLE_JOB_RANDOMSEED
#define SEC_DISABLE_JOB_AEADENCRYPT
#define SEC_DISABLE_JOB_AEADDECRYPT
#define SEC_DISABLE_JOB_KEYDERIVE
#define SEC_ENTROPY_POOL_SIZE                      0x00000000u
#define SEC_LCG_RANDOM_INCREMENT                   0x2AA01D31u
#define SEC_LCG_RANDOM_MULTIPLIER                  0x7FF8A3EDu
#define SEC_PRNG_GENERATE_RANDOM(pRandom, pLength) SecM_GenerateRandomLcg((pRandom), (pLength))
#define SEC_ECU_KEY                                0xFFFFFFFFu
#define SEC_SECRET_KEY_LENGTH                      0x00000000u
#define SEC_ENABLE_SEEDKEY
#define SEC_DISABLE_SEED_KEY_ENTROPY_POOL
#define SEC_DISABLE_SEED_KEY_IMPLICIT_ENTROPY
#define SEC_DISABLE_SEED_KEY_EXPLICIT_ENTROPY
#define SEC_ENABLE_SEED_KEY_PRNG_LCG
#define SEC_DISABLE_SEED_KEY_EXTERNAL_COMPARISION
#define SEC_DISABLE_SEED_KEY_EXTENDED_API
#define SEC_DISABLE_SEED_KEY_ASYMMETRIC
#define SEC_KE_RSA_MODULUS          160u
#define SEC_KE_RSA_PUBLIC_EXPONENT  161u
#define SEC_KE_RSA_PRIVATE_EXPONENT 162u
#define SEC_DISABLE_KEY_OPERATION_ACCESS
#define SEC_DISABLE_KEY_OPERATION_COPY
#define SEC_DISABLE_KEY_OPERATION_ELEMENT_COPY
#define SEC_DISABLE_SAVE_RESTORE_CONTEXT

#endif

