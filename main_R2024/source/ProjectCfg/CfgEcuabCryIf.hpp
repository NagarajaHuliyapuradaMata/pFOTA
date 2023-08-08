

#if !defined (CRYIF_CFG_H)
#define CRYIF_CFG_H

#include "Csm_Types.hpp"

#ifndef CRYIF_USE_DUMMY_STATEMENT
#define CRYIF_USE_DUMMY_STATEMENT STD_ON
#endif
#ifndef CRYIF_DUMMY_STATEMENT
#define CRYIF_DUMMY_STATEMENT(v) (v)=(v)
#endif
#ifndef CRYIF_DUMMY_STATEMENT_CONST
#define CRYIF_DUMMY_STATEMENT_CONST(v) (void)(v)
#endif
#ifndef CRYIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CRYIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF
#endif
#ifndef CRYIF_ATOMIC_VARIABLE_ACCESS
#define CRYIF_ATOMIC_VARIABLE_ACCESS 8u
#endif
#ifndef CRYIF_PROCESSOR_RH850_1013
#define CRYIF_PROCESSOR_RH850_1013
#endif
#ifndef CRYIF_COMP_GREENHILLS
#define CRYIF_COMP_GREENHILLS
#endif
#ifndef CRYIF_GEN_GENERATOR_MSR
#define CRYIF_GEN_GENERATOR_MSR
#endif
#ifndef CRYIF_CPUTYPE_BITORDER_LSB2MSB
#define CRYIF_CPUTYPE_BITORDER_LSB2MSB
#endif
#ifndef CRYIF_CONFIGURATION_VARIANT_PRECOMPILE
#define CRYIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CRYIF_CONFIGURATION_VARIANT_LINKTIME
#define CRYIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CRYIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CRYIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CRYIF_CONFIGURATION_VARIANT
#define CRYIF_CONFIGURATION_VARIANT CRYIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CRYIF_POSTBUILD_VARIANT_SUPPORT
#define CRYIF_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#define CRYIF_VERSION_INFO_API                                                                      STD_OFF
#define CRYIF_MAX_NUMBER_OF_KEY_ELEMENTS                                                            10u
#define CRYIF_MAX_SIZE_OF_KEY_ELEMENT                                                               32u
#define CRYIF_REDIRECTION                                                                           STD_OFF

#define CryIfConf_CryIfChannel_CryIfChannel_CryptoCv_Fbl_Aes                                        0u
#define CryIfConf_CryIfChannel_CryIfChannel_CryptoCv_Fbl_Signature                                  1u
#define CryIfConf_CryIfKey_CryIfKey_Fbl_Decrypt_Aes128                                              0u
#define CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_ClassC                                            1u
#define CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Ed25519                                           2u
#define CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Rsa1024                                           3u
#define CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Rsa2048                                           4u
#define CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Rsa3072                                           5u
#define CryIfConf_CryIfKey_CryIfKey_Fbl_HashDummy                                                   6u

#ifndef CRYIF_DEV_ERROR_DETECT
#define CRYIF_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CRYIF_DEV_ERROR_REPORT
#define CRYIF_DEV_ERROR_REPORT STD_ON
#endif

#define CRYIF_CHANNEL                                                                               STD_ON
#define CRYIF_CRYPTOFUNCTIONSIDXOFCHANNEL                                                           STD_ON
#define CRYIF_DRIVEROBJECTREFOFCHANNEL                                                              STD_ON
#define CRYIF_IDOFCHANNEL                                                                           STD_ON
#define CRYIF_CRYPTOFUNCTIONS                                                                       STD_ON
#define EcuabCryIf_CancelJobOFCRYPTOFUNCTIONS                                                            STD_ON
#define EcuabCryIf_CancelJobWITHINFOTYPEOFCRYPTOFUNCTIONS                                                STD_OFF
#define CRYIF_CERTIFICATEPARSEOFCRYPTOFUNCTIONS                                                     STD_ON
#define CRYIF_CERTIFICATEVERIFYOFCRYPTOFUNCTIONS                                                    STD_ON
#define CRYIF_KEYCOPYOFCRYPTOFUNCTIONS                                                              STD_ON
#define CRYIF_KEYDERIVEOFCRYPTOFUNCTIONS                                                            STD_ON
#define CRYIF_KEYELEMENTCOPYOFCRYPTOFUNCTIONS                                                       STD_ON
#define CRYIF_KEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                                STD_ON
#define CRYIF_KEYELEMENTGETOFCRYPTOFUNCTIONS                                                        STD_ON
#define CRYIF_KEYELEMENTIDSGETOFCRYPTOFUNCTIONS                                                     STD_ON
#define CRYIF_KEYELEMENTSETOFCRYPTOFUNCTIONS                                                        STD_ON
#define CRYIF_KEYEXCHANGECALCPUBVALOFCRYPTOFUNCTIONS                                                STD_ON
#define CRYIF_KEYEXCHANGECALCSECRETOFCRYPTOFUNCTIONS                                                STD_ON
#define EcuabCryIf_KeyGenerateOFCRYPTOFUNCTIONS                                                          STD_ON
#define CRYIF_KEYVALIDSETOFCRYPTOFUNCTIONS                                                          STD_ON
#define EcuabCryIf_ProcessJobOFCRYPTOFUNCTIONS                                                           STD_ON
#define EcuabCryIf_RandomSeedOFCRYPTOFUNCTIONS                                                           STD_ON
#define CRYIF_SUPPORTSKEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                        STD_ON
#define CRYIF_EXPECTEDCOMPATIBILITYVERSION                                                          STD_OFF
#define CRYIF_FINALMAGICNUMBER                                                                      STD_OFF
#define CRYIF_GENERATORCOMPATIBILITYVERSION                                                         STD_OFF
#define CRYIF_INITDATAHASHCODE                                                                      STD_OFF
#define CRYIF_KEY                                                                                   STD_ON
#define CRYIF_CRYPTOFUNCTIONSIDXOFKEY                                                               STD_ON
#define CRYIF_REFOFKEY                                                                              STD_ON
#define CRYIF_MAXNUMBEROFKEYELEMENTSOFGENERAL                                                       STD_ON
#define CRYIF_MAXSIZEOFKEYELEMENTOFGENERAL                                                          STD_ON
#define CRYIF_REDIRECTIONOFGENERAL                                                                  STD_ON
#define CRYIF_SIZEOFCHANNEL                                                                         STD_ON
#define CRYIF_SIZEOFCRYPTOFUNCTIONS                                                                 STD_ON
#define CRYIF_SIZEOFKEY                                                                             STD_ON
#define CRYIF_VERSIONINFOAPIOFGENERAL                                                               STD_ON
#define CRYIF_PCCONFIG                                                                              STD_ON
#define CRYIF_CHANNELOFPCCONFIG                                                                     STD_ON
#define CRYIF_CRYPTOFUNCTIONSOFPCCONFIG                                                             STD_ON
#define CRYIF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                                STD_OFF
#define CRYIF_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF
#define CRYIF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                               STD_OFF
#define CRYIF_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF
#define CRYIF_KEYOFPCCONFIG                                                                         STD_ON
#define CRYIF_MAXNUMBEROFKEYELEMENTSOFGENERALOFPCCONFIG                                             STD_ON
#define CRYIF_MAXSIZEOFKEYELEMENTOFGENERALOFPCCONFIG                                                STD_ON
#define CRYIF_REDIRECTIONOFGENERALOFPCCONFIG                                                        STD_ON
#define CRYIF_SIZEOFCHANNELOFPCCONFIG                                                               STD_ON
#define CRYIF_SIZEOFCRYPTOFUNCTIONSOFPCCONFIG                                                       STD_ON
#define CRYIF_SIZEOFKEYOFPCCONFIG                                                                   STD_ON
#define CRYIF_VERSIONINFOAPIOFGENERALOFPCCONFIG                                                     STD_ON

#define CRYIF_NO_EXPECTEDCOMPATIBILITYVERSION                                                       65535u

#define CRYIF_ISDEF_CRYPTOFUNCTIONSIDXOFCHANNEL                                                     STD_OFF
#define CRYIF_ISDEF_DRIVEROBJECTREFOFCHANNEL                                                        STD_OFF
#define CRYIF_ISDEF_IDOFCHANNEL                                                                     STD_OFF
#define CRYIF_ISDEF_CANCELJOBOFCRYPTOFUNCTIONS                                                      STD_OFF
#define CRYIF_ISDEF_CANCELJOBWITHINFOTYPEOFCRYPTOFUNCTIONS                                          STD_OFF
#define CRYIF_ISDEF_CERTIFICATEPARSEOFCRYPTOFUNCTIONS                                               STD_OFF
#define CRYIF_ISDEF_CERTIFICATEVERIFYOFCRYPTOFUNCTIONS                                              STD_OFF
#define CRYIF_ISDEF_KEYCOPYOFCRYPTOFUNCTIONS                                                        STD_OFF
#define CRYIF_ISDEF_KEYDERIVEOFCRYPTOFUNCTIONS                                                      STD_OFF
#define CRYIF_ISDEF_KEYELEMENTCOPYOFCRYPTOFUNCTIONS                                                 STD_OFF
#define CRYIF_ISDEF_KEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                          STD_OFF
#define CRYIF_ISDEF_KEYELEMENTGETOFCRYPTOFUNCTIONS                                                  STD_OFF
#define CRYIF_ISDEF_KEYELEMENTIDSGETOFCRYPTOFUNCTIONS                                               STD_OFF
#define CRYIF_ISDEF_KEYELEMENTSETOFCRYPTOFUNCTIONS                                                  STD_OFF
#define CRYIF_ISDEF_KEYEXCHANGECALCPUBVALOFCRYPTOFUNCTIONS                                          STD_OFF
#define CRYIF_ISDEF_KEYEXCHANGECALCSECRETOFCRYPTOFUNCTIONS                                          STD_OFF
#define CRYIF_ISDEF_KEYGENERATEOFCRYPTOFUNCTIONS                                                    STD_OFF
#define CRYIF_ISDEF_KEYVALIDSETOFCRYPTOFUNCTIONS                                                    STD_OFF
#define CRYIF_ISDEF_PROCESSJOBOFCRYPTOFUNCTIONS                                                     STD_OFF
#define CRYIF_ISDEF_RANDOMSEEDOFCRYPTOFUNCTIONS                                                     STD_OFF
#define CRYIF_ISDEF_SUPPORTSKEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                  STD_OFF
#define CRYIF_ISDEF_CRYPTOFUNCTIONSIDXOFKEY                                                         STD_OFF
#define CRYIF_ISDEF_REFOFKEY                                                                        STD_OFF
#define CRYIF_ISDEF_CHANNELOFPCCONFIG                                                               STD_ON
#define CRYIF_ISDEF_CRYPTOFUNCTIONSOFPCCONFIG                                                       STD_ON
#define CRYIF_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                          STD_OFF
#define CRYIF_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                      STD_OFF
#define CRYIF_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                         STD_OFF
#define CRYIF_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                      STD_OFF
#define CRYIF_ISDEF_KEYOFPCCONFIG                                                                   STD_ON

#define CRYIF_EQ2_CRYPTOFUNCTIONSIDXOFCHANNEL
#define CRYIF_EQ2_DRIVEROBJECTREFOFCHANNEL
#define CRYIF_EQ2_IDOFCHANNEL
#define CRYIF_EQ2_CANCELJOBOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_CANCELJOBWITHINFOTYPEOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_CERTIFICATEPARSEOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_CERTIFICATEVERIFYOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_KEYCOPYOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_KEYDERIVEOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_KEYELEMENTCOPYOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_KEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_KEYELEMENTGETOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_KEYELEMENTIDSGETOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_KEYELEMENTSETOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_KEYEXCHANGECALCPUBVALOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_KEYEXCHANGECALCSECRETOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_KEYGENERATEOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_KEYVALIDSETOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_PROCESSJOBOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_RANDOMSEEDOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_SUPPORTSKEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS
#define CRYIF_EQ2_CRYPTOFUNCTIONSIDXOFKEY
#define CRYIF_EQ2_REFOFKEY
#define CRYIF_EQ2_CHANNELOFPCCONFIG                                                                 CryIf_Channel
#define CRYIF_EQ2_CRYPTOFUNCTIONSOFPCCONFIG                                                         CryIf_CryptoFunctions
#define CRYIF_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG
#define CRYIF_EQ2_FINALMAGICNUMBEROFPCCONFIG
#define CRYIF_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG
#define CRYIF_EQ2_INITDATAHASHCODEOFPCCONFIG
#define CRYIF_EQ2_KEYOFPCCONFIG                                                                     CryIf_Key

#define CryIf_Config_Ptr                                                                            NULL_PTR

#define CryIf_Config                                                                                NULL_PTR

#define CRYIF_CHECK_INIT_POINTER                                                                    STD_OFF
#define CRYIF_FINAL_MAGIC_NUMBER                                                                    0xFF1Eu
#define CRYIF_INDIVIDUAL_POSTBUILD                                                                  STD_OFF
#define CRYIF_INIT_DATA                                                                             CRYIF_CONST
#define CRYIF_INIT_DATA_HASH_CODE                                                                   -1579120385
#define CRYIF_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF
#define CRYIF_USE_INIT_POINTER                                                                      STD_OFF

#define CRYIF_PBCONFIG                                                                              STD_OFF
#define CRYIF_LTCONFIGIDXOFPBCONFIG                                                                 STD_OFF
#define CRYIF_PCCONFIGIDXOFPBCONFIG                                                                 STD_OFF

#define CRYIF_ISDEF_LTCONFIGIDXOFPBCONFIG                                                           STD_OFF
#define CRYIF_ISDEF_PCCONFIGIDXOFPBCONFIG                                                           STD_OFF

#define CRYIF_EQ2_LTCONFIGIDXOFPBCONFIG
#define CRYIF_EQ2_PCCONFIGIDXOFPBCONFIG

#define CryIf_GetExpectedCompatibilityVersionOfPCConfig()
#define CryIf_GetFinalMagicNumberOfPCConfig()
#define CryIf_GetGeneratorCompatibilityVersionOfPCConfig()
#define CryIf_GetInitDataHashCodeOfPCConfig()

#define CryIf_GetChannelOfPCConfig()                                                                CryIf_Channel
#define CryIf_GetCryptoFunctionsOfPCConfig()                                                        CryIf_CryptoFunctions
#define CryIf_GetKeyOfPCConfig()                                                                    CryIf_Key
#define CryIf_GetMaxNumberOfKeyElementsOfGeneralOfPCConfig()                                        10u
#define CryIf_GetMaxSizeOfKeyElementOfGeneralOfPCConfig()                                           32u
#define CryIf_IsRedirectionOfGeneralOfPCConfig()                                                    (((FALSE)) != FALSE)
#define CryIf_GetSizeOfChannelOfPCConfig()                                                          2u
#define CryIf_GetSizeOfCryptoFunctionsOfPCConfig()                                                  1u
#define CryIf_GetSizeOfKeyOfPCConfig()                                                              7u
#define CryIf_IsVersionInfoApiOfGeneralOfPCConfig()                                                 (((FALSE)) != FALSE)

#define CryIf_GetCryptoFunctionsIdxOfChannel(Index)                                                 (CryIf_GetChannelOfPCConfig()[(Index)].CryptoFunctionsIdxOfChannel)
#define CryIf_GetDriverObjectRefOfChannel(Index)                                                    (CryIf_GetChannelOfPCConfig()[(Index)].DriverObjectRefOfChannel)
#define CryIf_GetIdOfChannel(Index)                                                                 (CryIf_GetChannelOfPCConfig()[(Index)].IdOfChannel)
#define CryIf_GetCancelJobOfCryptoFunctions(Index)                                                  (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].CancelJobOfCryptoFunctions)
#define CryIf_GetCancelJobWithInfoTypeOfCryptoFunctions(Index)
#define CryIf_GetCertificateParseOfCryptoFunctions(Index)                                           (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].CertificateParseOfCryptoFunctions)
#define CryIf_GetCertificateVerifyOfCryptoFunctions(Index)                                          (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].CertificateVerifyOfCryptoFunctions)
#define CryIf_GetKeyCopyOfCryptoFunctions(Index)                                                    (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyCopyOfCryptoFunctions)
#define CryIf_GetKeyDeriveOfCryptoFunctions(Index)                                                  (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyDeriveOfCryptoFunctions)
#define CryIf_GetKeyElementCopyOfCryptoFunctions(Index)                                             (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementCopyOfCryptoFunctions)
#define CryIf_GetKeyElementCopyPartialOfCryptoFunctions(Index)                                      (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementCopyPartialOfCryptoFunctions)
#define CryIf_GetKeyElementGetOfCryptoFunctions(Index)                                              (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementGetOfCryptoFunctions)
#define CryIf_GetKeyElementIdsGetOfCryptoFunctions(Index)                                           (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementIdsGetOfCryptoFunctions)
#define CryIf_GetKeyElementSetOfCryptoFunctions(Index)                                              (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementSetOfCryptoFunctions)
#define CryIf_GetKeyExchangeCalcPubValOfCryptoFunctions(Index)                                      (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyExchangeCalcPubValOfCryptoFunctions)
#define CryIf_GetKeyExchangeCalcSecretOfCryptoFunctions(Index)                                      (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyExchangeCalcSecretOfCryptoFunctions)
#define CryIf_GetKeyGenerateOfCryptoFunctions(Index)                                                (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyGenerateOfCryptoFunctions)
#define CryIf_GetKeyValidSetOfCryptoFunctions(Index)                                                (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyValidSetOfCryptoFunctions)
#define CryIf_GetProcessJobOfCryptoFunctions(Index)                                                 (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].ProcessJobOfCryptoFunctions)
#define CryIf_GetRandomSeedOfCryptoFunctions(Index)                                                 (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].RandomSeedOfCryptoFunctions)
#define CryIf_IsSupportsKeyElementCopyPartialOfCryptoFunctions(Index)                               ((CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].SupportsKeyElementCopyPartialOfCryptoFunctions) != FALSE)
#define CryIf_GetCryptoFunctionsIdxOfKey(Index)                                                     (CryIf_GetKeyOfPCConfig()[(Index)].CryptoFunctionsIdxOfKey)
#define CryIf_GetRefOfKey(Index)                                                                    (CryIf_GetKeyOfPCConfig()[(Index)].RefOfKey)

#define CryIf_GetExpectedCompatibilityVersion()
#define CryIf_GetFinalMagicNumber()
#define CryIf_GetGeneratorCompatibilityVersion()
#define CryIf_GetInitDataHashCode()
#define CryIf_GetMaxNumberOfKeyElementsOfGeneral()                                                  CryIf_GetMaxNumberOfKeyElementsOfGeneralOfPCConfig()
#define CryIf_GetMaxSizeOfKeyElementOfGeneral()                                                     CryIf_GetMaxSizeOfKeyElementOfGeneralOfPCConfig()
#define CryIf_IsRedirectionOfGeneral()                                                              CryIf_IsRedirectionOfGeneralOfPCConfig()
#define CryIf_GetSizeOfChannel()                                                                    CryIf_GetSizeOfChannelOfPCConfig()
#define CryIf_GetSizeOfCryptoFunctions()                                                            CryIf_GetSizeOfCryptoFunctionsOfPCConfig()
#define CryIf_GetSizeOfKey()                                                                        CryIf_GetSizeOfKeyOfPCConfig()
#define CryIf_IsVersionInfoApiOfGeneral()                                                           CryIf_IsVersionInfoApiOfGeneralOfPCConfig()

#define CryIf_HasChannel()                                                                          (TRUE != FALSE)
#define CryIf_HasCryptoFunctionsIdxOfChannel()                                                      (TRUE != FALSE)
#define CryIf_HasDriverObjectRefOfChannel()                                                         (TRUE != FALSE)
#define CryIf_HasIdOfChannel()                                                                      (TRUE != FALSE)
#define CryIf_HasCryptoFunctions()                                                                  (TRUE != FALSE)
#define CryIf_HasCancelJobOfCryptoFunctions()                                                       (TRUE != FALSE)
#define CryIf_HasCancelJobWithInfoTypeOfCryptoFunctions()
#define CryIf_HasCertificateParseOfCryptoFunctions()                                                (TRUE != FALSE)
#define CryIf_HasCertificateVerifyOfCryptoFunctions()                                               (TRUE != FALSE)
#define CryIf_HasKeyCopyOfCryptoFunctions()                                                         (TRUE != FALSE)
#define CryIf_HasKeyDeriveOfCryptoFunctions()                                                       (TRUE != FALSE)
#define CryIf_HasKeyElementCopyOfCryptoFunctions()                                                  (TRUE != FALSE)
#define CryIf_HasKeyElementCopyPartialOfCryptoFunctions()                                           (TRUE != FALSE)
#define CryIf_HasKeyElementGetOfCryptoFunctions()                                                   (TRUE != FALSE)
#define CryIf_HasKeyElementIdsGetOfCryptoFunctions()                                                (TRUE != FALSE)
#define CryIf_HasKeyElementSetOfCryptoFunctions()                                                   (TRUE != FALSE)
#define CryIf_HasKeyExchangeCalcPubValOfCryptoFunctions()                                           (TRUE != FALSE)
#define CryIf_HasKeyExchangeCalcSecretOfCryptoFunctions()                                           (TRUE != FALSE)
#define CryIf_HasKeyGenerateOfCryptoFunctions()                                                     (TRUE != FALSE)
#define CryIf_HasKeyValidSetOfCryptoFunctions()                                                     (TRUE != FALSE)
#define CryIf_HasProcessJobOfCryptoFunctions()                                                      (TRUE != FALSE)
#define CryIf_HasRandomSeedOfCryptoFunctions()                                                      (TRUE != FALSE)
#define CryIf_HasSupportsKeyElementCopyPartialOfCryptoFunctions()                                   (TRUE != FALSE)
#define CryIf_HasExpectedCompatibilityVersion()
#define CryIf_HasFinalMagicNumber()
#define CryIf_HasGeneratorCompatibilityVersion()
#define CryIf_HasInitDataHashCode()
#define CryIf_HasKey()                                                                              (TRUE != FALSE)
#define CryIf_HasCryptoFunctionsIdxOfKey()                                                          (TRUE != FALSE)
#define CryIf_HasRefOfKey()                                                                         (TRUE != FALSE)
#define CryIf_HasMaxNumberOfKeyElementsOfGeneral()                                                  (TRUE != FALSE)
#define CryIf_HasMaxSizeOfKeyElementOfGeneral()                                                     (TRUE != FALSE)
#define CryIf_HasRedirectionOfGeneral()                                                             (TRUE != FALSE)
#define CryIf_HasSizeOfChannel()                                                                    (TRUE != FALSE)
#define CryIf_HasSizeOfCryptoFunctions()                                                            (TRUE != FALSE)
#define CryIf_HasSizeOfKey()                                                                        (TRUE != FALSE)
#define CryIf_HasVersionInfoApiOfGeneral()                                                          (TRUE != FALSE)
#define CryIf_HasPCConfig()                                                                         (TRUE != FALSE)
#define CryIf_HasChannelOfPCConfig()                                                                (TRUE != FALSE)
#define CryIf_HasCryptoFunctionsOfPCConfig()                                                        (TRUE != FALSE)
#define CryIf_HasExpectedCompatibilityVersionOfPCConfig()
#define CryIf_HasFinalMagicNumberOfPCConfig()
#define CryIf_HasGeneratorCompatibilityVersionOfPCConfig()
#define CryIf_HasInitDataHashCodeOfPCConfig()
#define CryIf_HasKeyOfPCConfig()                                                                    (TRUE != FALSE)
#define CryIf_HasMaxNumberOfKeyElementsOfGeneralOfPCConfig()                                        (TRUE != FALSE)
#define CryIf_HasMaxSizeOfKeyElementOfGeneralOfPCConfig()                                           (TRUE != FALSE)
#define CryIf_HasRedirectionOfGeneralOfPCConfig()                                                   (TRUE != FALSE)
#define CryIf_HasSizeOfChannelOfPCConfig()                                                          (TRUE != FALSE)
#define CryIf_HasSizeOfCryptoFunctionsOfPCConfig()                                                  (TRUE != FALSE)
#define CryIf_HasSizeOfKeyOfPCConfig()                                                              (TRUE != FALSE)
#define CryIf_HasVersionInfoApiOfGeneralOfPCConfig()                                                (TRUE != FALSE)

#define CryIf_GetLTConfigIdxOfPBConfig()
#define CryIf_GetPCConfigIdxOfPBConfig()

#define CryIf_HasPBConfig()
#define CryIf_HasLTConfigIdxOfPBConfig()
#define CryIf_HasPCConfigIdxOfPBConfig()

typedef P2FUNC (Std_ReturnType, CRYIF_CODE, EcuabCryIf_ProcessJobFuncType)(uint32 objectId, Crypto_JobType* job);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyElementSetFuncType)(uint32 cryptoKeyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyValidSetFuncType)(uint32 cryptoKeyId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyElementGetFuncType)(uint32 cryptoKeyId, uint32 keyElementId, uint8* resultPtr, uint32* resultLengthPtr);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyElementCopyFuncType)(uint32 cryptoKeyId, uint32 keyElementId, uint32 targetCryptoKeyId, uint32 targetKeyElementId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyElementCopyPartialFuncType)(uint32 cryptoKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetCryptoKeyId, uint32 targetKeyElementId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyElementIdsGetFuncType)(uint32 cryptoKeyId, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyCopyFuncType)(uint32 cryptoKeyId, uint32 targetCryptoKeyId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, EcuabCryIf_RandomSeedFuncType)(uint32 cryptoKeyId, const uint8* entropyPtr, uint32 entropyLength);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, EcuabCryIf_KeyGenerateFuncType)(uint32 cryptoKeyId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyDeriveFuncType)(uint32 cryptoKeyId, uint32 targetCryptoKeyId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyExchangeCalcPubValFuncType)(uint32 cryptoKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyExchangeCalcSecretFuncType)(uint32 cryptoKeyId, const uint8* partnerPublicValuePtr, uint32 partnerPublicValueLength);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_CertificateParseFuncType)(uint32 cryptoKeyId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_CertificateVerifyFuncType)(uint32 cryptoKeyId, uint32 verifyCryptoKeyId, Crypto_VerifyResultType* verifyPtr);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, EcuabCryIf_CancelJobFuncType)(uint32 objectId, Crypto_JobType* job);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, EcuabCryIf_CancelJobFuncWithInfoType)(uint32 objectId, Crypto_JobInfoType* job);

typedef uint8_least CryIf_ChannelIterType;

typedef uint8_least CryIf_CryptoFunctionsIterType;

typedef uint8_least CryIf_KeyIterType;

typedef uint8 CryIf_CryptoFunctionsIdxOfChannelType;

typedef uint32 CryIf_DriverObjectRefOfChannelType;

typedef uint8 CryIf_IdOfChannelType;

typedef boolean CryIf_SupportsKeyElementCopyPartialOfCryptoFunctionsType;

typedef uint8 CryIf_CryptoFunctionsIdxOfKeyType;

typedef uint32 CryIf_RefOfKeyType;

typedef uint8 CryIf_MaxNumberOfKeyElementsOfGeneralType;

typedef uint8 CryIf_MaxSizeOfKeyElementOfGeneralType;

typedef boolean CryIf_RedirectionOfGeneralType;

typedef uint8 CryIf_SizeOfChannelType;

typedef uint8 CryIf_SizeOfCryptoFunctionsType;

typedef uint8 CryIf_SizeOfKeyType;

typedef boolean CryIf_VersionInfoApiOfGeneralType;

typedef struct sCryIf_ChannelType{
  CryIf_DriverObjectRefOfChannelType DriverObjectRefOfChannel;
  CryIf_CryptoFunctionsIdxOfChannelType CryptoFunctionsIdxOfChannel;
  CryIf_IdOfChannelType IdOfChannel;
}CryIf_ChannelType;

typedef struct sCryIf_CryptoFunctionsType{
  CryIf_SupportsKeyElementCopyPartialOfCryptoFunctionsType SupportsKeyElementCopyPartialOfCryptoFunctions;
  EcuabCryIf_CancelJobFuncType CancelJobOfCryptoFunctions;
  CryIf_CertificateParseFuncType CertificateParseOfCryptoFunctions;
  CryIf_CertificateVerifyFuncType CertificateVerifyOfCryptoFunctions;
  CryIf_KeyCopyFuncType KeyCopyOfCryptoFunctions;
  CryIf_KeyDeriveFuncType KeyDeriveOfCryptoFunctions;
  CryIf_KeyElementCopyFuncType KeyElementCopyOfCryptoFunctions;
  CryIf_KeyElementCopyPartialFuncType KeyElementCopyPartialOfCryptoFunctions;
  CryIf_KeyElementGetFuncType KeyElementGetOfCryptoFunctions;
  CryIf_KeyElementIdsGetFuncType KeyElementIdsGetOfCryptoFunctions;
  CryIf_KeyElementSetFuncType KeyElementSetOfCryptoFunctions;
  CryIf_KeyExchangeCalcPubValFuncType KeyExchangeCalcPubValOfCryptoFunctions;
  CryIf_KeyExchangeCalcSecretFuncType KeyExchangeCalcSecretOfCryptoFunctions;
  EcuabCryIf_KeyGenerateFuncType KeyGenerateOfCryptoFunctions;
  CryIf_KeyValidSetFuncType KeyValidSetOfCryptoFunctions;
  EcuabCryIf_ProcessJobFuncType ProcessJobOfCryptoFunctions;
  EcuabCryIf_RandomSeedFuncType RandomSeedOfCryptoFunctions;
}CryIf_CryptoFunctionsType;

typedef struct sCryIf_KeyType{
  CryIf_RefOfKeyType RefOfKey;
  CryIf_CryptoFunctionsIdxOfKeyType CryptoFunctionsIdxOfKey;
}CryIf_KeyType;

typedef P2CONST(CryIf_ChannelType, TYPEDEF, CRYIF_CONST) CryIf_ChannelPtrType;

typedef P2CONST(CryIf_CryptoFunctionsType, TYPEDEF, CRYIF_CONST) CryIf_CryptoFunctionsPtrType;

typedef P2CONST(CryIf_KeyType, TYPEDEF, CRYIF_CONST) CryIf_KeyPtrType;

typedef struct sCryIf_PCConfigType{
  uint8 CryIf_PCConfigNeverUsed;
}CryIf_PCConfigType;

typedef CryIf_PCConfigType CryIf_ConfigType;

#define CRYIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(CryIf_ChannelType, CRYIF_CONST) CryIf_Channel[2];
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CRYIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(CryIf_CryptoFunctionsType, CRYIF_CONST) CryIf_CryptoFunctions[1];
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CRYIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(CryIf_KeyType, CRYIF_CONST) CryIf_Key[7];
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#endif

