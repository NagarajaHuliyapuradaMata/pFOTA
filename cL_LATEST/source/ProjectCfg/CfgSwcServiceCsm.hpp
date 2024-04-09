

#if !defined (CSM_CFG_H)
#define CSM_CFG_H

#include "Types_SwcServiceCsm.hpp"
#include "McalCry_Custom.hpp"

#ifndef CSM_USE_DUMMY_STATEMENT
#define CSM_USE_DUMMY_STATEMENT STD_ON
#endif
#ifndef CSM_DUMMY_STATEMENT
#define CSM_DUMMY_STATEMENT(v) (v)=(v)
#endif
#ifndef CSM_DUMMY_STATEMENT_CONST
#define CSM_DUMMY_STATEMENT_CONST(v) (void)(v)
#endif
#ifndef CSM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CSM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF
#endif
#ifndef CSM_ATOMIC_VARIABLE_ACCESS
#define CSM_ATOMIC_VARIABLE_ACCESS 8u
#endif
#ifndef CSM_PROCESSOR_RH850_1013
#define CSM_PROCESSOR_RH850_1013
#endif
#ifndef CSM_COMP_GREENHILLS
#define CSM_COMP_GREENHILLS
#endif
#ifndef CSM_GEN_GENERATOR_MSR
#define CSM_GEN_GENERATOR_MSR
#endif
#ifndef CSM_CPUTYPE_BITORDER_LSB2MSB
#define CSM_CPUTYPE_BITORDER_LSB2MSB
#endif
#ifndef CSM_CONFIGURATION_VARIANT_PRECOMPILE
#define CSM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CSM_CONFIGURATION_VARIANT_LINKTIME
#define CSM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CSM_CONFIGURATION_VARIANT
#define CSM_CONFIGURATION_VARIANT CSM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CSM_POSTBUILD_VARIANT_SUPPORT
#define CSM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#define CSM_ASYNC_PROCESSING                                                                        STD_OFF

#define CSM_CALLBACKS                                                                               STD_OFF
#define CSM_ASYM_PRIVATE_KEY_MAX_LENGTH                                                             32u
#define CSM_ASYM_PUBLIC_KEY_MAX_LENGTH                                                              1024u
#define CSM_SYM_KEY_MAX_LENGTH                                                                      16u
#define CSM_USE_DEPRECATED                                                                          STD_OFF
#define CSM_VERSION_INFO_API                                                                        STD_OFF
#define CSM_CALLBACK_START_NOTIFICATION                                                             STD_OFF
#define CSM_CANCELATION_DURING_PROCESSING                                                           STD_OFF
#define CSM_JOBS                                                                                    STD_ON
#define CSM_KEYS                                                                                    STD_ON
#define CSM_QUEUES                                                                                  STD_ON
#define CSM_CALLOUTS                                                                                STD_OFF
#define CSM_IN_OUT_REDIRECTIONS                                                                     STD_OFF

#define CsmConf_CsmJob_CsmJob_DecryptionAes128NoneCbc                                               0u
#define CsmConf_CsmJob_CsmJob_SigAsymVer_DummySha512                                                1u
#define CsmConf_CsmJob_CsmJob_SigAsymVer_RsaPssSha256                                               2u
#define CsmConf_CsmJob_CsmJob_SigAsymVer_RsaV15Sha1                                                 3u
#define CsmConf_CsmJob_CsmJob_Signature_Class_C                                                     4u
#define CsmConf_CsmKey_CsmKey_Fbl_Decrypt_Aes128                                                    0u
#define CsmConf_CsmKey_CsmKey_Fbl_HashDummy                                                         1u
#define CsmConf_CsmKey_CsmKey_Fbl_Signature_Class_C                                                 2u
#define CsmConf_CsmKey_CsmKey_Fbl_Signature_Ed25519                                                 3u
#define CsmConf_CsmKey_CsmKey_Fbl_Signature_Rsa1024                                                 4u
#define CsmConf_CsmKey_CsmKey_Fbl_Signature_Rsa2048                                                 5u
#define CsmConf_CsmKey_CsmKey_Fbl_Signature_Rsa3072                                                 6u

#ifndef CSM_DEV_ERROR_DETECT
#define CSM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CSM_DEV_ERROR_REPORT
#define CSM_DEV_ERROR_REPORT STD_ON
#endif
#define CSM_EXIST_AEADDECRYPT                                                                       STD_OFF
#define CSM_EXIST_AEADENCRYPT                                                                       STD_OFF
#define CSM_EXIST_DECRYPT                                                                           STD_ON
#define CSM_EXIST_ENCRYPT                                                                           STD_OFF
#define CSM_EXIST_HASH                                                                              STD_ON
#define CSM_EXIST_MACGENERATE                                                                       STD_OFF
#define CSM_EXIST_MACVERIFY                                                                         STD_ON
#define CSM_EXIST_RANDOMGENERATE                                                                    STD_OFF
#define CSM_EXIST_SECURECOUNTER                                                                     STD_OFF
#define CSM_EXIST_SIGNATUREGENERATE                                                                 STD_OFF
#define CSM_EXIST_SIGNATUREVERIFY                                                                   STD_ON
#define CSM_EXIST_JOBKEYSETVALID                                                                    STD_OFF
#define CSM_EXIST_JOBKEYEXCHANGECALCPUBVAL                                                          STD_OFF
#define CSM_EXIST_JOBKEYEXCHANGECALCSECRET                                                          STD_OFF
#define CSM_EXIST_JOBKEYDERIVE                                                                      STD_OFF
#define CSM_EXIST_JOBRANDOMSEED                                                                     STD_OFF
#define CSM_EXIST_JOBKEYGENERATE                                                                    STD_OFF
#define CSM_EXIST_JOBCERTIFICATEPARSE                                                               STD_OFF
#define CSM_EXIST_JOBCERTIFICATEVERIFY                                                              STD_OFF
#define CSM_RTE_PORTS                                                                               STD_OFF
#define CSM_INVALID_KEYID                                                                           0xFFFFFFFFUL

#define CSM_ASYMPRIVATEKEYMAXLENGTHOFGENERAL                                                        STD_ON
#define CSM_ASYMPUBLICKEYMAXLENGTHOFGENERAL                                                         STD_ON
#define CSM_BSWCALLBACKS                                                                            STD_OFF
#define CSM_CALLBACKFUNC43OFBSWCALLBACKS                                                            STD_OFF
#define CSM_CALLBACKFUNC44OFBSWCALLBACKS                                                            STD_OFF
#define CSM_CALLBACKFUNC45OFBSWCALLBACKS                                                            STD_OFF
#define CSM_CALLBACKSTARTNOTIFICATIONOFGENERAL                                                      STD_ON
#define CSM_CALLOUT                                                                                 STD_OFF
#define CSM_POSTJOBCALLOUTFUNCOFCALLOUT                                                             STD_OFF
#define CSM_PREJOBCALLOUTFUNCOFCALLOUT                                                              STD_OFF
#define CSM_CALLOUTINFO                                                                             STD_OFF
#define CSM_CALLOUTIDXOFCALLOUTINFO                                                                 STD_OFF
#define CSM_JOBTABLEIDXOFCALLOUTINFO                                                                STD_OFF
#define CSM_CALLOUTSTATE                                                                            STD_OFF
#define CSM_CALLOUTSTATEOFCALLOUTSTATE                                                              STD_OFF
#define CSM_CANCELATIONDURINGPROCESSINGOFGENERAL                                                    STD_ON
#define CSM_EXPECTEDCOMPATIBILITYVERSION                                                            STD_OFF
#define CSM_FINALMAGICNUMBER                                                                        STD_OFF
#define CSM_GENERATORCOMPATIBILITYVERSION                                                           STD_OFF
#define CSM_INOUTJOBREDIRECTIONTABLE                                                                STD_OFF
#define CSM_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                             STD_OFF
#define CSM_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                                    STD_OFF
#define CSM_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                            STD_OFF
#define CSM_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                                   STD_OFF
#define CSM_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE                                        STD_OFF
#define CSM_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                    STD_OFF
#define CSM_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                           STD_OFF
#define CSM_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                   STD_OFF
#define CSM_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                          STD_OFF
#define CSM_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                     STD_OFF
#define CSM_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                            STD_OFF
#define CSM_INOUTREDIRECTION                                                                        STD_OFF
#define CSM_INOUTREDIRECTIONMAP                                                                     STD_OFF
#define CSM_INOUTJOBREDIRECTIONTABLEIDXOFINOUTREDIRECTIONMAP                                        STD_OFF
#define CSM_INVALIDHNDOFINOUTREDIRECTIONMAP                                                         STD_OFF
#define CSM_INITDATAHASHCODE                                                                        STD_OFF
#define CSM_JOB                                                                                     STD_ON
#define CSM_JOBINFO                                                                                 STD_ON
#define CSM_JOBPRIMITIVEINFO                                                                        STD_ON
#define CSM_JOBSTATE                                                                                STD_ON
#define CSM_JOBTABLE                                                                                STD_ON
#define CSM_ASYNCHRONOUSOFJOBTABLE                                                                  STD_ON
#define CSM_BSWCALLBACKSIDXOFJOBTABLE                                                               STD_OFF
#define CSM_BSWCALLBACKSUSEDOFJOBTABLE                                                              STD_OFF
#define CSM_CALLOUTINFOIDXOFJOBTABLE                                                                STD_OFF
#define CSM_CALLOUTINFOUSEDOFJOBTABLE                                                               STD_OFF
#define CSM_CSMKEYIDIDXOFJOBTABLE                                                                   STD_ON
#define CSM_INOUTREDIRECTIONMAPIDXOFJOBTABLE                                                        STD_OFF
#define CSM_INOUTREDIRECTIONMAPUSEDOFJOBTABLE                                                       STD_OFF
#define CSM_JOBIDXOFJOBTABLE                                                                        STD_OFF
#define CSM_JOBINFOIDXOFJOBTABLE                                                                    STD_ON
#define CSM_JOBPRIMITIVEINFOIDXOFJOBTABLE                                                           STD_ON
#define CSM_JOBUSEDOFJOBTABLE                                                                       STD_OFF
#define CSM_MASKEDBITSOFJOBTABLE                                                                    STD_ON
#define CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE                                           STD_ON
#define CSM_PRIORITYOFJOBTABLE                                                                      STD_ON
#define CSM_QUEUEREFIDXOFJOBTABLE                                                                   STD_ON
#define CSM_RTECALLBACKIDXOFJOBTABLE                                                                STD_OFF
#define CSM_RTECALLBACKUSEDOFJOBTABLE                                                               STD_OFF
#define CSM_JOBTOOBJMAP                                                                             STD_ON
#define CSM_KEY                                                                                     STD_ON
#define CSM_CRYIFKEYIDOFKEY                                                                         STD_ON
#define CSM_MAINFUNCTIONPERIODOFGENERAL                                                             STD_ON
#define CSM_PRIMITIVEINFO                                                                           STD_ON
#define CSM_QUEUE                                                                                   STD_ON
#define CSM_QUEUEINFO                                                                               STD_ON
#define CSM_CHANNELIDOFQUEUEINFO                                                                    STD_ON
#define CSM_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO                                                         STD_ON
#define CSM_JOBOBJSYNCHRONOUSUSEDOFQUEUEINFO                                                        STD_ON
#define CSM_JOBPOOLENDIDXOFQUEUEINFO                                                                STD_ON
#define CSM_JOBPOOLSTARTIDXOFQUEUEINFO                                                              STD_ON
#define CSM_JOBPOOLUSEDOFQUEUEINFO                                                                  STD_ON
#define CSM_JOBSHARINGOFQUEUEINFO                                                                   STD_ON
#define CSM_MASKEDBITSOFQUEUEINFO                                                                   STD_ON
#define CSM_QUEUEENDIDXOFQUEUEINFO                                                                  STD_ON
#define CSM_QUEUESTARTIDXOFQUEUEINFO                                                                STD_ON
#define CSM_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO                                                  STD_OFF
#define CSM_QUEUESTATE                                                                              STD_ON
#define CSM_LOCKOFQUEUESTATE                                                                        STD_ON
#define CSM_QUEUEIDXOFQUEUESTATE                                                                    STD_ON
#define CSM_RETRIGGERINGOFQUEUESTATE                                                                STD_OFF
#define CSM_RTECALLBACK                                                                             STD_OFF
#define CSM_RTECALLBACKOCCURRED                                                                     STD_OFF
#define CSM_RTERESULT                                                                               STD_OFF
#define CSM_SIZEOFJOB                                                                               STD_ON
#define CSM_SIZEOFJOBINFO                                                                           STD_ON
#define CSM_SIZEOFJOBPRIMITIVEINFO                                                                  STD_ON
#define CSM_SIZEOFJOBSTATE                                                                          STD_ON
#define CSM_SIZEOFJOBTABLE                                                                          STD_ON
#define CSM_SIZEOFJOBTOOBJMAP                                                                       STD_ON
#define CSM_SIZEOFKEY                                                                               STD_ON
#define CSM_SIZEOFPRIMITIVEINFO                                                                     STD_ON
#define CSM_SIZEOFQUEUE                                                                             STD_ON
#define CSM_SIZEOFQUEUEINFO                                                                         STD_ON
#define CSM_SIZEOFQUEUESTATE                                                                        STD_ON
#define CSM_SYMKEYMAXLENGTHOFGENERAL                                                                STD_ON
#define CSM_USEDEPRECATEDOFGENERAL                                                                  STD_ON
#define CSM_VERSIONINFOAPIOFGENERAL                                                                 STD_ON
#define CSM_PCCONFIG                                                                                STD_ON
#define CSM_ASYMPRIVATEKEYMAXLENGTHOFGENERALOFPCCONFIG                                              STD_ON
#define CSM_ASYMPUBLICKEYMAXLENGTHOFGENERALOFPCCONFIG                                               STD_ON
#define CSM_CALLBACKSTARTNOTIFICATIONOFGENERALOFPCCONFIG                                            STD_ON
#define CSM_CANCELATIONDURINGPROCESSINGOFGENERALOFPCCONFIG                                          STD_ON
#define CSM_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                                  STD_OFF
#define CSM_FINALMAGICNUMBEROFPCCONFIG                                                              STD_OFF
#define CSM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                                 STD_OFF
#define CSM_INITDATAHASHCODEOFPCCONFIG                                                              STD_OFF
#define CSM_JOBINFOOFPCCONFIG                                                                       STD_ON
#define CSM_JOBOFPCCONFIG                                                                           STD_ON
#define CSM_JOBPRIMITIVEINFOOFPCCONFIG                                                              STD_ON
#define CSM_JOBSTATEOFPCCONFIG                                                                      STD_ON
#define CSM_JOBTABLEOFPCCONFIG                                                                      STD_ON
#define CSM_JOBTOOBJMAPOFPCCONFIG                                                                   STD_ON
#define CSM_KEYOFPCCONFIG                                                                           STD_ON
#define CSM_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                                   STD_ON
#define CSM_PRIMITIVEINFOOFPCCONFIG                                                                 STD_ON
#define CSM_QUEUEINFOOFPCCONFIG                                                                     STD_ON
#define CSM_QUEUEOFPCCONFIG                                                                         STD_ON
#define CSM_QUEUESTATEOFPCCONFIG                                                                    STD_ON
#define CSM_SIZEOFJOBINFOOFPCCONFIG                                                                 STD_ON
#define CSM_SIZEOFJOBOFPCCONFIG                                                                     STD_ON
#define CSM_SIZEOFJOBPRIMITIVEINFOOFPCCONFIG                                                        STD_ON
#define CSM_SIZEOFJOBSTATEOFPCCONFIG                                                                STD_ON
#define CSM_SIZEOFJOBTABLEOFPCCONFIG                                                                STD_ON
#define CSM_SIZEOFJOBTOOBJMAPOFPCCONFIG                                                             STD_ON
#define CSM_SIZEOFKEYOFPCCONFIG                                                                     STD_ON
#define CSM_SIZEOFPRIMITIVEINFOOFPCCONFIG                                                           STD_ON
#define CSM_SIZEOFQUEUEINFOOFPCCONFIG                                                               STD_ON
#define CSM_SIZEOFQUEUEOFPCCONFIG                                                                   STD_ON
#define CSM_SIZEOFQUEUESTATEOFPCCONFIG                                                              STD_ON
#define CSM_SYMKEYMAXLENGTHOFGENERALOFPCCONFIG                                                      STD_ON
#define CSM_USEDEPRECATEDOFGENERALOFPCCONFIG                                                        STD_ON
#define CSM_VERSIONINFOAPIOFGENERALOFPCCONFIG                                                       STD_ON

#define CSM_MIN_CALLOUTSTATEOFCALLOUTSTATE                                                          0u
#define CSM_MIN_JOBSTATE                                                                            0u
#define CSM_MIN_LOCKOFQUEUESTATE                                                                    0u
#define CSM_MIN_QUEUEIDXOFQUEUESTATE                                                                0u
#define CSM_MIN_RETRIGGERINGOFQUEUESTATE                                                            0u

#define CSM_MAX_CALLOUTSTATEOFCALLOUTSTATE                                                          255u
#define CSM_MAX_JOBSTATE                                                                            255u
#define CSM_MAX_LOCKOFQUEUESTATE                                                                    65535u
#define CSM_MAX_QUEUEIDXOFQUEUESTATE                                                                255u
#define CSM_MAX_RETRIGGERINGOFQUEUESTATE                                                            255u

#define CSM_NO_BSWCALLBACKSIDXOFJOBTABLE                                                            255u
#define CSM_NO_CALLOUTINFOIDXOFJOBTABLE                                                             255u
#define CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE                                                     255u
#define CSM_NO_JOBIDXOFJOBTABLE                                                                     255u
#define CSM_NO_RTECALLBACKIDXOFJOBTABLE                                                             255u
#define CSM_NO_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO                                                      255u
#define CSM_NO_JOBPOOLENDIDXOFQUEUEINFO                                                             255u
#define CSM_NO_JOBPOOLSTARTIDXOFQUEUEINFO                                                           255u
#define CSM_NO_EXPECTEDCOMPATIBILITYVERSION                                                         65535u

#define CSM_ASYNCHRONOUSOFJOBTABLE_MASK                                                             0x02u
#define CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK                                      0x01u
#define CSM_JOBOBJSYNCHRONOUSUSEDOFQUEUEINFO_MASK                                                   0x04u
#define CSM_JOBPOOLUSEDOFQUEUEINFO_MASK                                                             0x02u
#define CSM_JOBSHARINGOFQUEUEINFO_MASK                                                              0x01u

#define CSM_ISDEF_CALLBACKFUNC43OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_CALLBACKFUNC44OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_CALLBACKFUNC45OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_POSTJOBCALLOUTFUNCOFCALLOUT                                                       STD_OFF
#define CSM_ISDEF_PREJOBCALLOUTFUNCOFCALLOUT                                                        STD_OFF
#define CSM_ISDEF_CALLOUTIDXOFCALLOUTINFO                                                           STD_OFF
#define CSM_ISDEF_JOBTABLEIDXOFCALLOUTINFO                                                          STD_OFF
#define CSM_ISDEF_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                       STD_OFF
#define CSM_ISDEF_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                              STD_OFF
#define CSM_ISDEF_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                      STD_OFF
#define CSM_ISDEF_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                             STD_OFF
#define CSM_ISDEF_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE                                  STD_OFF
#define CSM_ISDEF_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                              STD_OFF
#define CSM_ISDEF_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                     STD_OFF
#define CSM_ISDEF_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                             STD_OFF
#define CSM_ISDEF_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                    STD_OFF
#define CSM_ISDEF_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                               STD_OFF
#define CSM_ISDEF_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                      STD_OFF
#define CSM_ISDEF_INOUTJOBREDIRECTIONTABLEIDXOFINOUTREDIRECTIONMAP                                  STD_OFF
#define CSM_ISDEF_INVALIDHNDOFINOUTREDIRECTIONMAP                                                   STD_OFF
#define CSM_ISDEF_JOBINFO                                                                           STD_OFF
#define CSM_ISDEF_JOBPRIMITIVEINFO                                                                  STD_OFF
#define CSM_ISDEF_ASYNCHRONOUSOFJOBTABLE                                                            STD_OFF
#define CSM_ISDEF_BSWCALLBACKSIDXOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_BSWCALLBACKSUSEDOFJOBTABLE                                                        STD_OFF
#define CSM_ISDEF_CALLOUTINFOIDXOFJOBTABLE                                                          STD_OFF
#define CSM_ISDEF_CALLOUTINFOUSEDOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_CSMKEYIDIDXOFJOBTABLE                                                             STD_OFF
#define CSM_ISDEF_INOUTREDIRECTIONMAPIDXOFJOBTABLE                                                  STD_OFF
#define CSM_ISDEF_INOUTREDIRECTIONMAPUSEDOFJOBTABLE                                                 STD_OFF
#define CSM_ISDEF_JOBIDXOFJOBTABLE                                                                  STD_OFF
#define CSM_ISDEF_JOBINFOIDXOFJOBTABLE                                                              STD_OFF
#define CSM_ISDEF_JOBPRIMITIVEINFOIDXOFJOBTABLE                                                     STD_OFF
#define CSM_ISDEF_JOBUSEDOFJOBTABLE                                                                 STD_OFF
#define CSM_ISDEF_MASKEDBITSOFJOBTABLE                                                              STD_OFF
#define CSM_ISDEF_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE                                     STD_OFF
#define CSM_ISDEF_PRIORITYOFJOBTABLE                                                                STD_OFF
#define CSM_ISDEF_QUEUEREFIDXOFJOBTABLE                                                             STD_OFF
#define CSM_ISDEF_RTECALLBACKIDXOFJOBTABLE                                                          STD_OFF
#define CSM_ISDEF_RTECALLBACKUSEDOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_CRYIFKEYIDOFKEY                                                                   STD_OFF
#define CSM_ISDEF_PRIMITIVEINFO                                                                     STD_OFF
#define CSM_ISDEF_CHANNELIDOFQUEUEINFO                                                              STD_OFF
#define CSM_ISDEF_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO                                                   STD_OFF
#define CSM_ISDEF_JOBOBJSYNCHRONOUSUSEDOFQUEUEINFO                                                  STD_OFF
#define CSM_ISDEF_JOBPOOLENDIDXOFQUEUEINFO                                                          STD_OFF
#define CSM_ISDEF_JOBPOOLSTARTIDXOFQUEUEINFO                                                        STD_OFF
#define CSM_ISDEF_JOBPOOLUSEDOFQUEUEINFO                                                            STD_OFF
#define CSM_ISDEF_JOBSHARINGOFQUEUEINFO                                                             STD_OFF
#define CSM_ISDEF_MASKEDBITSOFQUEUEINFO                                                             STD_OFF
#define CSM_ISDEF_QUEUEENDIDXOFQUEUEINFO                                                            STD_OFF
#define CSM_ISDEF_QUEUESTARTIDXOFQUEUEINFO                                                          STD_OFF
#define CSM_ISDEF_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO                                            STD_OFF
#define CSM_ISDEF_RTECALLBACK                                                                       STD_OFF
#define CSM_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                            STD_OFF
#define CSM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                        STD_OFF
#define CSM_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                           STD_OFF
#define CSM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                        STD_OFF
#define CSM_ISDEF_JOBINFOOFPCCONFIG                                                                 STD_ON
#define CSM_ISDEF_JOBOFPCCONFIG                                                                     STD_ON
#define CSM_ISDEF_JOBPRIMITIVEINFOOFPCCONFIG                                                        STD_ON
#define CSM_ISDEF_JOBSTATEOFPCCONFIG                                                                STD_ON
#define CSM_ISDEF_JOBTABLEOFPCCONFIG                                                                STD_ON
#define CSM_ISDEF_JOBTOOBJMAPOFPCCONFIG                                                             STD_ON
#define CSM_ISDEF_KEYOFPCCONFIG                                                                     STD_ON
#define CSM_ISDEF_PRIMITIVEINFOOFPCCONFIG                                                           STD_ON
#define CSM_ISDEF_QUEUEINFOOFPCCONFIG                                                               STD_ON
#define CSM_ISDEF_QUEUEOFPCCONFIG                                                                   STD_ON
#define CSM_ISDEF_QUEUESTATEOFPCCONFIG                                                              STD_ON

#define CSM_EQ2_CALLBACKFUNC43OFBSWCALLBACKS
#define CSM_EQ2_CALLBACKFUNC44OFBSWCALLBACKS
#define CSM_EQ2_CALLBACKFUNC45OFBSWCALLBACKS
#define CSM_EQ2_POSTJOBCALLOUTFUNCOFCALLOUT
#define CSM_EQ2_PREJOBCALLOUTFUNCOFCALLOUT
#define CSM_EQ2_CALLOUTIDXOFCALLOUTINFO
#define CSM_EQ2_JOBTABLEIDXOFCALLOUTINFO
#define CSM_EQ2_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE
#define CSM_EQ2_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE
#define CSM_EQ2_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE
#define CSM_EQ2_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE
#define CSM_EQ2_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE
#define CSM_EQ2_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE
#define CSM_EQ2_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE
#define CSM_EQ2_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE
#define CSM_EQ2_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE
#define CSM_EQ2_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE
#define CSM_EQ2_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE
#define CSM_EQ2_INOUTJOBREDIRECTIONTABLEIDXOFINOUTREDIRECTIONMAP
#define CSM_EQ2_INVALIDHNDOFINOUTREDIRECTIONMAP
#define CSM_EQ2_JOBINFO
#define CSM_EQ2_JOBPRIMITIVEINFO
#define CSM_EQ2_ASYNCHRONOUSOFJOBTABLE
#define CSM_EQ2_BSWCALLBACKSIDXOFJOBTABLE
#define CSM_EQ2_BSWCALLBACKSUSEDOFJOBTABLE
#define CSM_EQ2_CALLOUTINFOIDXOFJOBTABLE
#define CSM_EQ2_CALLOUTINFOUSEDOFJOBTABLE
#define CSM_EQ2_CSMKEYIDIDXOFJOBTABLE
#define CSM_EQ2_INOUTREDIRECTIONMAPIDXOFJOBTABLE
#define CSM_EQ2_INOUTREDIRECTIONMAPUSEDOFJOBTABLE
#define CSM_EQ2_JOBIDXOFJOBTABLE
#define CSM_EQ2_JOBINFOIDXOFJOBTABLE
#define CSM_EQ2_JOBPRIMITIVEINFOIDXOFJOBTABLE
#define CSM_EQ2_JOBUSEDOFJOBTABLE
#define CSM_EQ2_MASKEDBITSOFJOBTABLE
#define CSM_EQ2_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE
#define CSM_EQ2_PRIORITYOFJOBTABLE
#define CSM_EQ2_QUEUEREFIDXOFJOBTABLE
#define CSM_EQ2_RTECALLBACKIDXOFJOBTABLE
#define CSM_EQ2_RTECALLBACKUSEDOFJOBTABLE
#define CSM_EQ2_CRYIFKEYIDOFKEY
#define CSM_EQ2_PRIMITIVEINFO
#define CSM_EQ2_CHANNELIDOFQUEUEINFO
#define CSM_EQ2_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO
#define CSM_EQ2_JOBOBJSYNCHRONOUSUSEDOFQUEUEINFO
#define CSM_EQ2_JOBPOOLENDIDXOFQUEUEINFO
#define CSM_EQ2_JOBPOOLSTARTIDXOFQUEUEINFO
#define CSM_EQ2_JOBPOOLUSEDOFQUEUEINFO
#define CSM_EQ2_JOBSHARINGOFQUEUEINFO
#define CSM_EQ2_MASKEDBITSOFQUEUEINFO
#define CSM_EQ2_QUEUEENDIDXOFQUEUEINFO
#define CSM_EQ2_QUEUESTARTIDXOFQUEUEINFO
#define CSM_EQ2_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO
#define CSM_EQ2_RTECALLBACK
#define CSM_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG
#define CSM_EQ2_FINALMAGICNUMBEROFPCCONFIG
#define CSM_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG
#define CSM_EQ2_INITDATAHASHCODEOFPCCONFIG
#define CSM_EQ2_JOBINFOOFPCCONFIG                                                                   Csm_JobInfo
#define CSM_EQ2_JOBOFPCCONFIG                                                                       Csm_Job
#define CSM_EQ2_JOBPRIMITIVEINFOOFPCCONFIG                                                          Csm_JobPrimitiveInfo
#define CSM_EQ2_JOBSTATEOFPCCONFIG                                                                  Csm_JobState
#define CSM_EQ2_JOBTABLEOFPCCONFIG                                                                  Csm_JobTable
#define CSM_EQ2_JOBTOOBJMAPOFPCCONFIG                                                               Csm_JobToObjMap
#define CSM_EQ2_KEYOFPCCONFIG                                                                       Csm_Key
#define CSM_EQ2_PRIMITIVEINFOOFPCCONFIG                                                             Csm_PrimitiveInfo
#define CSM_EQ2_QUEUEINFOOFPCCONFIG                                                                 Csm_QueueInfo
#define CSM_EQ2_QUEUEOFPCCONFIG                                                                     Csm_Queue.raw
#define CSM_EQ2_QUEUESTATEOFPCCONFIG                                                                Csm_QueueState

#define Csm_Config_Ptr                                                                              NULL_PTR

#define Csm_Config                                                                                  NULL_PTR

#define CSM_CHECK_INIT_POINTER                                                                      STD_OFF
#define CSM_FINAL_MAGIC_NUMBER                                                                      0xFF1Eu
#define CSM_INDIVIDUAL_POSTBUILD                                                                    STD_OFF
#define CSM_INIT_DATA                                                                               CSM_CONST
#define CSM_INIT_DATA_HASH_CODE                                                                     842809845
#define CSM_USE_ECUM_BSW_ERROR_HOOK                                                                 STD_OFF
#define CSM_USE_INIT_POINTER                                                                        STD_OFF

#define CSM_PBCONFIG                                                                                STD_OFF
#define CSM_LTCONFIGIDXOFPBCONFIG                                                                   STD_OFF
#define CSM_PCCONFIGIDXOFPBCONFIG                                                                   STD_OFF

#define CSM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                             STD_OFF
#define CSM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                             STD_OFF

#define CSM_EQ2_LTCONFIGIDXOFPBCONFIG
#define CSM_EQ2_PCCONFIGIDXOFPBCONFIG

#define Csm_GetExpectedCompatibilityVersionOfPCConfig()
#define Csm_GetFinalMagicNumberOfPCConfig()
#define Csm_GetGeneratorCompatibilityVersionOfPCConfig()
#define Csm_GetInitDataHashCodeOfPCConfig()

#define Csm_GetAsymPrivateKeyMaxLengthOfGeneralOfPCConfig()                                         32u
#define Csm_GetAsymPublicKeyMaxLengthOfGeneralOfPCConfig()                                          1024u
#define Csm_IsCallbackStartNotificationOfGeneralOfPCConfig()                                        (((FALSE)) != FALSE)
#define Csm_IsCancelationDuringProcessingOfGeneralOfPCConfig()                                      (((FALSE)) != FALSE)
#define Csm_GetJobInfoOfPCConfig()                                                                  Csm_JobInfo
#define Csm_GetJobOfPCConfig()                                                                      Csm_Job
#define Csm_GetJobPrimitiveInfoOfPCConfig()                                                         Csm_JobPrimitiveInfo
#define Csm_GetJobStateOfPCConfig()                                                                 Csm_JobState
#define Csm_GetJobTableOfPCConfig()                                                                 Csm_JobTable
#define Csm_GetJobToObjMapOfPCConfig()                                                              Csm_JobToObjMap
#define Csm_GetKeyOfPCConfig()                                                                      Csm_Key
#define Csm_GetMainFunctionPeriodOfGeneralOfPCConfig()                                              1u
#define Csm_GetPrimitiveInfoOfPCConfig()                                                            Csm_PrimitiveInfo
#define Csm_GetQueueInfoOfPCConfig()                                                                Csm_QueueInfo
#define Csm_GetQueueOfPCConfig()                                                                    Csm_Queue.raw
#define Csm_GetQueueStateOfPCConfig()                                                               Csm_QueueState
#define Csm_GetSizeOfJobInfoOfPCConfig()                                                            5u
#define Csm_GetSizeOfJobOfPCConfig()                                                                2u
#define Csm_GetSizeOfJobPrimitiveInfoOfPCConfig()                                                   5u
#define Csm_GetSizeOfJobTableOfPCConfig()                                                           5u
#define Csm_GetSizeOfKeyOfPCConfig()                                                                7u
#define Csm_GetSizeOfPrimitiveInfoOfPCConfig()                                                      5u
#define Csm_GetSizeOfQueueInfoOfPCConfig()                                                          2u
#define Csm_GetSizeOfQueueOfPCConfig()                                                              2u
#define Csm_GetSymKeyMaxLengthOfGeneralOfPCConfig()                                                 16u
#define Csm_IsUseDeprecatedOfGeneralOfPCConfig()                                                    (((FALSE)) != FALSE)
#define Csm_IsVersionInfoApiOfGeneralOfPCConfig()                                                   (((FALSE)) != FALSE)

#define Csm_GetSizeOfJobStateOfPCConfig()                                                           Csm_GetSizeOfJobTableOfPCConfig()
#define Csm_GetSizeOfJobToObjMapOfPCConfig()                                                        Csm_GetSizeOfJobTableOfPCConfig()
#define Csm_GetSizeOfQueueStateOfPCConfig()                                                         Csm_GetSizeOfQueueInfoOfPCConfig()

#define Csm_GetCallbackFunc43OfBswCallbacks(Index)
#define Csm_GetCallbackFunc44OfBswCallbacks(Index)
#define Csm_GetCallbackFunc45OfBswCallbacks(Index)
#define Csm_GetPostJobCalloutFuncOfCallout(Index)
#define Csm_GetPreJobCalloutFuncOfCallout(Index)
#define Csm_GetCalloutIdxOfCalloutInfo(Index)
#define Csm_GetJobTableIdxOfCalloutInfo(Index)
#define Csm_GetCalloutStateOfCalloutState(Index)
#define Csm_GetInputKeyElementIdOfInOutJobRedirectionTable(Index)
#define Csm_GetInputKeyIdOfInOutJobRedirectionTable(Index)
#define Csm_GetOutputKeyElementIdOfInOutJobRedirectionTable(Index)
#define Csm_GetOutputKeyIdOfInOutJobRedirectionTable(Index)
#define Csm_GetRedirectionConfigValueOfInOutJobRedirectionTable(Index)
#define Csm_GetSecondaryInputKeyElementIdOfInOutJobRedirectionTable(Index)
#define Csm_GetSecondaryInputKeyIdOfInOutJobRedirectionTable(Index)
#define Csm_GetSecondaryOutputKeyElementIdOfInOutJobRedirectionTable(Index)
#define Csm_GetSecondaryOutputKeyIdOfInOutJobRedirectionTable(Index)
#define Csm_GetTertiaryInputKeyElementIdOfInOutJobRedirectionTable(Index)
#define Csm_GetTertiaryInputKeyIdOfInOutJobRedirectionTable(Index)
#define Csm_GetInOutRedirection(Index)
#define Csm_GetInOutJobRedirectionTableIdxOfInOutRedirectionMap(Index)
#define Csm_IsInvalidHndOfInOutRedirectionMap(Index)
#define Csm_GetJob(Index)                                                                           (Csm_GetJobOfPCConfig()[(Index)])
#define Csm_GetJobInfo(Index)                                                                       (Csm_GetJobInfoOfPCConfig()[(Index)])
#define Csm_GetJobPrimitiveInfo(Index)                                                              (Csm_GetJobPrimitiveInfoOfPCConfig()[(Index)])
#define Csm_GetJobState(Index)                                                                      (Csm_GetJobStateOfPCConfig()[(Index)])
#define Csm_GetBswCallbacksIdxOfJobTable(Index)
#define Csm_IsBswCallbacksUsedOfJobTable(Index)
#define Csm_GetCalloutInfoIdxOfJobTable(Index)
#define Csm_IsCalloutInfoUsedOfJobTable(Index)
#define Csm_GetCsmKeyIdIdxOfJobTable(Index)                                                         (Csm_GetJobTableOfPCConfig()[(Index)].CsmKeyIdIdxOfJobTable)
#define Csm_GetInOutRedirectionMapIdxOfJobTable(Index)
#define Csm_IsInOutRedirectionMapUsedOfJobTable(Index)
#define Csm_GetJobIdxOfJobTable(Index)
#define Csm_IsJobUsedOfJobTable(Index)
#define Csm_GetPriorityOfJobTable(Index)                                                            (Csm_GetJobTableOfPCConfig()[(Index)].PriorityOfJobTable)
#define Csm_GetQueueRefIdxOfJobTable(Index)                                                         (Csm_GetJobTableOfPCConfig()[(Index)].QueueRefIdxOfJobTable)
#define Csm_GetRteCallbackIdxOfJobTable(Index)
#define Csm_IsRteCallbackUsedOfJobTable(Index)
#define Csm_GetJobToObjMap(Index)                                                                   (Csm_GetJobToObjMapOfPCConfig()[(Index)])
#define Csm_GetCryIfKeyIdOfKey(Index)                                                               (Csm_GetKeyOfPCConfig()[(Index)].CryIfKeyIdOfKey)
#define Csm_GetPrimitiveInfo(Index)                                                                 (Csm_GetPrimitiveInfoOfPCConfig()[(Index)])
#define Csm_GetQueue(Index)                                                                         (Csm_GetQueueOfPCConfig()[(Index)])
#define Csm_GetChannelIdOfQueueInfo(Index)                                                          (Csm_GetQueueInfoOfPCConfig()[(Index)].ChannelIdOfQueueInfo)
#define Csm_GetJobPoolStartIdxOfQueueInfo(Index)                                                    (Csm_GetQueueInfoOfPCConfig()[(Index)].JobPoolStartIdxOfQueueInfo)
#define Csm_GetMaskedBitsOfQueueInfo(Index)                                                         (Csm_GetQueueInfoOfPCConfig()[(Index)].MaskedBitsOfQueueInfo)
#define Csm_GetQueueEndIdxOfQueueInfo(Index)                                                        (Csm_GetQueueInfoOfPCConfig()[(Index)].QueueEndIdxOfQueueInfo)
#define Csm_IsTriggerAsynchJobsInCallbackOfQueueInfo(Index)
#define Csm_GetLockOfQueueState(Index)                                                              (Csm_GetQueueStateOfPCConfig()[(Index)].LockOfQueueState)
#define Csm_GetQueueIdxOfQueueState(Index)                                                          (Csm_GetQueueStateOfPCConfig()[(Index)].QueueIdxOfQueueState)
#define Csm_GetRetriggeringOfQueueState(Index)
#define Csm_GetRteCallback(Index)
#define Csm_IsRteCallbackOccurred()
#define Csm_GetRteResult(Index)

#define Csm_IsPrimitiveCallbackUpdateNotificationOfJobTable(Index)                                  (CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK == (Csm_GetMaskedBitsOfJobTable(Index) & CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK))
#define Csm_IsJobPoolUsedOfQueueInfo(Index)                                                         (CSM_JOBPOOLUSEDOFQUEUEINFO_MASK == (Csm_GetMaskedBitsOfQueueInfo(Index) & CSM_JOBPOOLUSEDOFQUEUEINFO_MASK))

#define Csm_GetAsymPrivateKeyMaxLengthOfGeneral()                                                   Csm_GetAsymPrivateKeyMaxLengthOfGeneralOfPCConfig()
#define Csm_GetAsymPublicKeyMaxLengthOfGeneral()                                                    Csm_GetAsymPublicKeyMaxLengthOfGeneralOfPCConfig()
#define Csm_IsCallbackStartNotificationOfGeneral()                                                  Csm_IsCallbackStartNotificationOfGeneralOfPCConfig()
#define Csm_IsCancelationDuringProcessingOfGeneral()                                                Csm_IsCancelationDuringProcessingOfGeneralOfPCConfig()
#define Csm_GetExpectedCompatibilityVersion()
#define Csm_GetFinalMagicNumber()
#define Csm_GetGeneratorCompatibilityVersion()
#define Csm_GetInitDataHashCode()
#define Csm_IsAsynchronousOfJobTable(Index)                                                         Csm_IsPrimitiveCallbackUpdateNotificationOfJobTable(Index)
#define Csm_GetJobInfoIdxOfJobTable(Index)                                                          ((Csm_JobInfoIdxOfJobTableType)((Index)))
#define Csm_GetJobPrimitiveInfoIdxOfJobTable(Index)                                                 ((Csm_JobPrimitiveInfoIdxOfJobTableType)((Index)))
#define Csm_GetMaskedBitsOfJobTable(Index)                                                          Csm_GetPriorityOfJobTable(Index)
#define Csm_GetMainFunctionPeriodOfGeneral()                                                        Csm_GetMainFunctionPeriodOfGeneralOfPCConfig()
#define Csm_GetJobObjSynchronousIdxOfQueueInfo(Index)                                               Csm_GetJobPoolStartIdxOfQueueInfo(Index)
#define Csm_IsJobObjSynchronousUsedOfQueueInfo(Index)                                               Csm_IsJobPoolUsedOfQueueInfo(Index)
#define Csm_GetJobPoolEndIdxOfQueueInfo(Index)                                                      Csm_GetQueueEndIdxOfQueueInfo(Index)
#define Csm_IsJobSharingOfQueueInfo(Index)                                                          Csm_IsJobPoolUsedOfQueueInfo(Index)
#define Csm_GetQueueStartIdxOfQueueInfo(Index)                                                      Csm_GetJobPoolStartIdxOfQueueInfo(Index)
#define Csm_GetSizeOfJob()                                                                          Csm_GetSizeOfJobOfPCConfig()
#define Csm_GetSizeOfJobInfo()                                                                      Csm_GetSizeOfJobInfoOfPCConfig()
#define Csm_GetSizeOfJobPrimitiveInfo()                                                             Csm_GetSizeOfJobPrimitiveInfoOfPCConfig()
#define Csm_GetSizeOfJobState()                                                                     Csm_GetSizeOfJobStateOfPCConfig()
#define Csm_GetSizeOfJobTable()                                                                     Csm_GetSizeOfJobTableOfPCConfig()
#define Csm_GetSizeOfJobToObjMap()                                                                  Csm_GetSizeOfJobToObjMapOfPCConfig()
#define Csm_GetSizeOfKey()                                                                          Csm_GetSizeOfKeyOfPCConfig()
#define Csm_GetSizeOfPrimitiveInfo()                                                                Csm_GetSizeOfPrimitiveInfoOfPCConfig()
#define Csm_GetSizeOfQueue()                                                                        Csm_GetSizeOfQueueOfPCConfig()
#define Csm_GetSizeOfQueueInfo()                                                                    Csm_GetSizeOfQueueInfoOfPCConfig()
#define Csm_GetSizeOfQueueState()                                                                   Csm_GetSizeOfQueueStateOfPCConfig()
#define Csm_GetSymKeyMaxLengthOfGeneral()                                                           Csm_GetSymKeyMaxLengthOfGeneralOfPCConfig()
#define Csm_IsUseDeprecatedOfGeneral()                                                              Csm_IsUseDeprecatedOfGeneralOfPCConfig()
#define Csm_IsVersionInfoApiOfGeneral()                                                             Csm_IsVersionInfoApiOfGeneralOfPCConfig()

#define Csm_SetCalloutStateOfCalloutState(Index, Value)
#define Csm_SetInOutRedirection(Index, Value)
#define Csm_SetJob(Index, Value)                                                                    Csm_GetJobOfPCConfig()[(Index)] = (Value)
#define Csm_SetJobState(Index, Value)                                                               Csm_GetJobStateOfPCConfig()[(Index)] = (Value)
#define Csm_SetJobToObjMap(Index, Value)                                                            Csm_GetJobToObjMapOfPCConfig()[(Index)] = (Value)
#define Csm_SetQueue(Index, Value)                                                                  Csm_GetQueueOfPCConfig()[(Index)] = (Value)
#define Csm_SetLockOfQueueState(Index, Value)                                                       Csm_GetQueueStateOfPCConfig()[(Index)].LockOfQueueState = (Value)
#define Csm_SetQueueIdxOfQueueState(Index, Value)                                                   Csm_GetQueueStateOfPCConfig()[(Index)].QueueIdxOfQueueState = (Value)
#define Csm_SetRetriggeringOfQueueState(Index, Value)
#define Csm_SetRteCallbackOccurred(Value)
#define Csm_SetRteResult(Index, Value)

#define Csm_GetAddrInOutRedirection(Index)
#define Csm_GetAddrJob(Index)                                                                       (&Csm_GetJob(Index))
#define Csm_GetAddrJobInfo(Index)                                                                   (&Csm_GetJobInfo(Index))
#define Csm_GetAddrJobPrimitiveInfo(Index)                                                          (&Csm_GetJobPrimitiveInfo(Index))
#define Csm_GetAddrPrimitiveInfo(Index)                                                             (&Csm_GetPrimitiveInfo(Index))
#define Csm_GetAddrQueue(Index)                                                                     (&Csm_GetQueue(Index))
#define Csm_GetAddrRteResult(Index)

#define Csm_HasAsymPrivateKeyMaxLengthOfGeneral()                                                   (TRUE != FALSE)
#define Csm_HasAsymPublicKeyMaxLengthOfGeneral()                                                    (TRUE != FALSE)
#define Csm_HasBswCallbacks()
#define Csm_HasCallbackFunc43OfBswCallbacks()
#define Csm_HasCallbackFunc44OfBswCallbacks()
#define Csm_HasCallbackFunc45OfBswCallbacks()
#define Csm_HasCallbackStartNotificationOfGeneral()                                                 (TRUE != FALSE)
#define Csm_HasCallout()
#define Csm_HasPostJobCalloutFuncOfCallout()
#define Csm_HasPreJobCalloutFuncOfCallout()
#define Csm_HasCalloutInfo()
#define Csm_HasCalloutIdxOfCalloutInfo()
#define Csm_HasJobTableIdxOfCalloutInfo()
#define Csm_HasCalloutState()
#define Csm_HasCalloutStateOfCalloutState()
#define Csm_HasCancelationDuringProcessingOfGeneral()                                               (TRUE != FALSE)
#define Csm_HasExpectedCompatibilityVersion()
#define Csm_HasFinalMagicNumber()
#define Csm_HasGeneratorCompatibilityVersion()
#define Csm_HasInOutJobRedirectionTable()
#define Csm_HasInputKeyElementIdOfInOutJobRedirectionTable()
#define Csm_HasInputKeyIdOfInOutJobRedirectionTable()
#define Csm_HasOutputKeyElementIdOfInOutJobRedirectionTable()
#define Csm_HasOutputKeyIdOfInOutJobRedirectionTable()
#define Csm_HasRedirectionConfigValueOfInOutJobRedirectionTable()
#define Csm_HasSecondaryInputKeyElementIdOfInOutJobRedirectionTable()
#define Csm_HasSecondaryInputKeyIdOfInOutJobRedirectionTable()
#define Csm_HasSecondaryOutputKeyElementIdOfInOutJobRedirectionTable()
#define Csm_HasSecondaryOutputKeyIdOfInOutJobRedirectionTable()
#define Csm_HasTertiaryInputKeyElementIdOfInOutJobRedirectionTable()
#define Csm_HasTertiaryInputKeyIdOfInOutJobRedirectionTable()
#define Csm_HasInOutRedirection()
#define Csm_HasInOutRedirectionMap()
#define Csm_HasInOutJobRedirectionTableIdxOfInOutRedirectionMap()
#define Csm_HasInvalidHndOfInOutRedirectionMap()
#define Csm_HasInitDataHashCode()
#define Csm_HasJob()                                                                                (TRUE != FALSE)
#define Csm_HasJobInfo()                                                                            (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfo()                                                                   (TRUE != FALSE)
#define Csm_HasJobState()                                                                           (TRUE != FALSE)
#define Csm_HasJobTable()                                                                           (TRUE != FALSE)
#define Csm_HasAsynchronousOfJobTable()                                                             (TRUE != FALSE)
#define Csm_HasBswCallbacksIdxOfJobTable()
#define Csm_HasBswCallbacksUsedOfJobTable()
#define Csm_HasCalloutInfoIdxOfJobTable()
#define Csm_HasCalloutInfoUsedOfJobTable()
#define Csm_HasCsmKeyIdIdxOfJobTable()                                                              (TRUE != FALSE)
#define Csm_HasInOutRedirectionMapIdxOfJobTable()
#define Csm_HasInOutRedirectionMapUsedOfJobTable()
#define Csm_HasJobIdxOfJobTable()
#define Csm_HasJobInfoIdxOfJobTable()                                                               (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfoIdxOfJobTable()                                                      (TRUE != FALSE)
#define Csm_HasJobUsedOfJobTable()
#define Csm_HasMaskedBitsOfJobTable()                                                               (TRUE != FALSE)
#define Csm_HasPrimitiveCallbackUpdateNotificationOfJobTable()                                      (TRUE != FALSE)
#define Csm_HasPriorityOfJobTable()                                                                 (TRUE != FALSE)
#define Csm_HasQueueRefIdxOfJobTable()                                                              (TRUE != FALSE)
#define Csm_HasRteCallbackIdxOfJobTable()
#define Csm_HasRteCallbackUsedOfJobTable()
#define Csm_HasJobToObjMap()                                                                        (TRUE != FALSE)
#define Csm_HasKey()                                                                                (TRUE != FALSE)
#define Csm_HasCryIfKeyIdOfKey()                                                                    (TRUE != FALSE)
#define Csm_HasMainFunctionPeriodOfGeneral()                                                        (TRUE != FALSE)
#define Csm_HasPrimitiveInfo()                                                                      (TRUE != FALSE)
#define Csm_HasQueue()                                                                              (TRUE != FALSE)
#define Csm_HasQueueInfo()                                                                          (TRUE != FALSE)
#define Csm_HasChannelIdOfQueueInfo()                                                               (TRUE != FALSE)
#define Csm_HasJobObjSynchronousIdxOfQueueInfo()                                                    (TRUE != FALSE)
#define Csm_HasJobObjSynchronousUsedOfQueueInfo()                                                   (TRUE != FALSE)
#define Csm_HasJobPoolEndIdxOfQueueInfo()                                                           (TRUE != FALSE)
#define Csm_HasJobPoolStartIdxOfQueueInfo()                                                         (TRUE != FALSE)
#define Csm_HasJobPoolUsedOfQueueInfo()                                                             (TRUE != FALSE)
#define Csm_HasJobSharingOfQueueInfo()                                                              (TRUE != FALSE)
#define Csm_HasMaskedBitsOfQueueInfo()                                                              (TRUE != FALSE)
#define Csm_HasQueueEndIdxOfQueueInfo()                                                             (TRUE != FALSE)
#define Csm_HasQueueStartIdxOfQueueInfo()                                                           (TRUE != FALSE)
#define Csm_HasTriggerAsynchJobsInCallbackOfQueueInfo()
#define Csm_HasQueueState()                                                                         (TRUE != FALSE)
#define Csm_HasLockOfQueueState()                                                                   (TRUE != FALSE)
#define Csm_HasQueueIdxOfQueueState()                                                               (TRUE != FALSE)
#define Csm_HasRetriggeringOfQueueState()
#define Csm_HasRteCallback()
#define Csm_HasRteCallbackOccurred()
#define Csm_HasRteResult()
#define Csm_HasSizeOfJob()                                                                          (TRUE != FALSE)
#define Csm_HasSizeOfJobInfo()                                                                      (TRUE != FALSE)
#define Csm_HasSizeOfJobPrimitiveInfo()                                                             (TRUE != FALSE)
#define Csm_HasSizeOfJobState()                                                                     (TRUE != FALSE)
#define Csm_HasSizeOfJobTable()                                                                     (TRUE != FALSE)
#define Csm_HasSizeOfJobToObjMap()                                                                  (TRUE != FALSE)
#define Csm_HasSizeOfKey()                                                                          (TRUE != FALSE)
#define Csm_HasSizeOfPrimitiveInfo()                                                                (TRUE != FALSE)
#define Csm_HasSizeOfQueue()                                                                        (TRUE != FALSE)
#define Csm_HasSizeOfQueueInfo()                                                                    (TRUE != FALSE)
#define Csm_HasSizeOfQueueState()                                                                   (TRUE != FALSE)
#define Csm_HasSymKeyMaxLengthOfGeneral()                                                           (TRUE != FALSE)
#define Csm_HasUseDeprecatedOfGeneral()                                                             (TRUE != FALSE)
#define Csm_HasVersionInfoApiOfGeneral()                                                            (TRUE != FALSE)
#define Csm_HasPCConfig()                                                                           (TRUE != FALSE)
#define Csm_HasAsymPrivateKeyMaxLengthOfGeneralOfPCConfig()                                         (TRUE != FALSE)
#define Csm_HasAsymPublicKeyMaxLengthOfGeneralOfPCConfig()                                          (TRUE != FALSE)
#define Csm_HasCallbackStartNotificationOfGeneralOfPCConfig()                                       (TRUE != FALSE)
#define Csm_HasCancelationDuringProcessingOfGeneralOfPCConfig()                                     (TRUE != FALSE)
#define Csm_HasExpectedCompatibilityVersionOfPCConfig()
#define Csm_HasFinalMagicNumberOfPCConfig()
#define Csm_HasGeneratorCompatibilityVersionOfPCConfig()
#define Csm_HasInitDataHashCodeOfPCConfig()
#define Csm_HasJobInfoOfPCConfig()                                                                  (TRUE != FALSE)
#define Csm_HasJobOfPCConfig()                                                                      (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfoOfPCConfig()                                                         (TRUE != FALSE)
#define Csm_HasJobStateOfPCConfig()                                                                 (TRUE != FALSE)
#define Csm_HasJobTableOfPCConfig()                                                                 (TRUE != FALSE)
#define Csm_HasJobToObjMapOfPCConfig()                                                              (TRUE != FALSE)
#define Csm_HasKeyOfPCConfig()                                                                      (TRUE != FALSE)
#define Csm_HasMainFunctionPeriodOfGeneralOfPCConfig()                                              (TRUE != FALSE)
#define Csm_HasPrimitiveInfoOfPCConfig()                                                            (TRUE != FALSE)
#define Csm_HasQueueInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Csm_HasQueueOfPCConfig()                                                                    (TRUE != FALSE)
#define Csm_HasQueueStateOfPCConfig()                                                               (TRUE != FALSE)
#define Csm_HasSizeOfJobInfoOfPCConfig()                                                            (TRUE != FALSE)
#define Csm_HasSizeOfJobOfPCConfig()                                                                (TRUE != FALSE)
#define Csm_HasSizeOfJobPrimitiveInfoOfPCConfig()                                                   (TRUE != FALSE)
#define Csm_HasSizeOfJobStateOfPCConfig()                                                           (TRUE != FALSE)
#define Csm_HasSizeOfJobTableOfPCConfig()                                                           (TRUE != FALSE)
#define Csm_HasSizeOfJobToObjMapOfPCConfig()                                                        (TRUE != FALSE)
#define Csm_HasSizeOfKeyOfPCConfig()                                                                (TRUE != FALSE)
#define Csm_HasSizeOfPrimitiveInfoOfPCConfig()                                                      (TRUE != FALSE)
#define Csm_HasSizeOfQueueInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Csm_HasSizeOfQueueOfPCConfig()                                                              (TRUE != FALSE)
#define Csm_HasSizeOfQueueStateOfPCConfig()                                                         (TRUE != FALSE)
#define Csm_HasSymKeyMaxLengthOfGeneralOfPCConfig()                                                 (TRUE != FALSE)
#define Csm_HasUseDeprecatedOfGeneralOfPCConfig()                                                   (TRUE != FALSE)
#define Csm_HasVersionInfoApiOfGeneralOfPCConfig()                                                  (TRUE != FALSE)

#define Csm_IncCalloutStateOfCalloutState(Index)
#define Csm_IncInOutRedirection(Index)
#define Csm_IncJob(Index)                                                                           Csm_GetJob(Index)++
#define Csm_IncJobState(Index)                                                                      Csm_GetJobState(Index)++
#define Csm_IncQueue(Index)                                                                         Csm_GetQueue(Index)++
#define Csm_IncLockOfQueueState(Index)                                                              Csm_GetLockOfQueueState(Index)++
#define Csm_IncQueueIdxOfQueueState(Index)                                                          Csm_GetQueueIdxOfQueueState(Index)++
#define Csm_IncRetriggeringOfQueueState(Index)
#define Csm_IncRteResult(Index)

#define Csm_DecCalloutStateOfCalloutState(Index)
#define Csm_DecInOutRedirection(Index)
#define Csm_DecJob(Index)                                                                           Csm_GetJob(Index)--
#define Csm_DecJobState(Index)                                                                      Csm_GetJobState(Index)--
#define Csm_DecQueue(Index)                                                                         Csm_GetQueue(Index)--
#define Csm_DecLockOfQueueState(Index)                                                              Csm_GetLockOfQueueState(Index)--
#define Csm_DecQueueIdxOfQueueState(Index)                                                          Csm_GetQueueIdxOfQueueState(Index)--
#define Csm_DecRetriggeringOfQueueState(Index)
#define Csm_DecRteResult(Index)

#define Csm_AddCalloutStateOfCalloutState(Index, Value)
#define Csm_AddInOutRedirection(Index, Value)
#define Csm_AddJob(Index, Value)                                                                    Csm_SetJob(Index, (Csm_GetJob(Index) + Value))
#define Csm_AddJobState(Index, Value)                                                               Csm_SetJobState(Index, (Csm_GetJobState(Index) + Value))
#define Csm_AddQueue(Index, Value)                                                                  Csm_SetQueue(Index, (Csm_GetQueue(Index) + Value))
#define Csm_AddLockOfQueueState(Index, Value)                                                       Csm_SetLockOfQueueState(Index, (Csm_GetLockOfQueueState(Index) + Value))
#define Csm_AddQueueIdxOfQueueState(Index, Value)                                                   Csm_SetQueueIdxOfQueueState(Index, (Csm_GetQueueIdxOfQueueState(Index) + Value))
#define Csm_AddRetriggeringOfQueueState(Index, Value)
#define Csm_AddRteResult(Index, Value)

#define Csm_SubCalloutStateOfCalloutState(Index, Value)
#define Csm_SubInOutRedirection(Index, Value)
#define Csm_SubJob(Index, Value)                                                                    Csm_SetJob(Index, (Csm_GetJob(Index) - Value))
#define Csm_SubJobState(Index, Value)                                                               Csm_SetJobState(Index, (Csm_GetJobState(Index) - Value))
#define Csm_SubQueue(Index, Value)                                                                  Csm_SetQueue(Index, (Csm_GetQueue(Index) - Value))
#define Csm_SubLockOfQueueState(Index, Value)                                                       Csm_SetLockOfQueueState(Index, (Csm_GetLockOfQueueState(Index) - Value))
#define Csm_SubQueueIdxOfQueueState(Index, Value)                                                   Csm_SetQueueIdxOfQueueState(Index, (Csm_GetQueueIdxOfQueueState(Index) - Value))
#define Csm_SubRetriggeringOfQueueState(Index, Value)
#define Csm_SubRteResult(Index, Value)

#define Csm_GetLTConfigIdxOfPBConfig()
#define Csm_GetPCConfigIdxOfPBConfig()

#define Csm_HasPBConfig()
#define Csm_HasLTConfigIdxOfPBConfig()
#define Csm_HasPCConfigIdxOfPBConfig()

typedef P2VAR(Crypto_JobType, AUTOMATIC, CSM_VAR_NOINIT) Csm_QueueElementType;
typedef uint8 Csm_JobCalloutStateType;
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc43Type)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Std_ReturnType result);
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc44Type)(const uint32 jobID, Csm_ResultType result);
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc45Type)(P2CONST(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Crypto_ResultType result);
typedef P2FUNC (Std_ReturnType, CSM_CODE, Csm_PreJobCalloutFunc)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state);
typedef P2FUNC (Std_ReturnType, CSM_CODE, Csm_PostJobCalloutFunc)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state, P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue);

typedef uint8_least Csm_JobIterType;

typedef uint8_least Csm_JobInfoIterType;

typedef uint8_least Csm_JobPrimitiveInfoIterType;

typedef uint8_least Csm_JobTableIterType;

typedef uint8_least Csm_KeyIterType;

typedef uint8_least Csm_PrimitiveInfoIterType;

typedef uint8_least Csm_QueueIterType;

typedef uint8_least Csm_QueueInfoIterType;

typedef Csm_JobTableIterType Csm_JobStateIterType;

typedef Csm_JobTableIterType Csm_JobToObjMapIterType;

typedef Csm_QueueInfoIterType Csm_QueueStateIterType;

typedef uint8 Csm_AsymPrivateKeyMaxLengthOfGeneralType;

typedef uint16 Csm_AsymPublicKeyMaxLengthOfGeneralType;

typedef boolean Csm_CallbackStartNotificationOfGeneralType;

typedef boolean Csm_CancelationDuringProcessingOfGeneralType;

typedef uint8 Csm_JobStateType;

typedef boolean Csm_AsynchronousOfJobTableType;

typedef uint8 Csm_CsmKeyIdIdxOfJobTableType;

typedef uint8 Csm_JobInfoIdxOfJobTableType;

typedef uint8 Csm_JobPrimitiveInfoIdxOfJobTableType;

typedef uint8 Csm_MaskedBitsOfJobTableType;

typedef boolean Csm_PrimitiveCallbackUpdateNotificationOfJobTableType;

typedef uint8 Csm_PriorityOfJobTableType;

typedef uint8 Csm_QueueRefIdxOfJobTableType;

typedef uint32 Csm_CryIfKeyIdOfKeyType;

typedef uint8 Csm_MainFunctionPeriodOfGeneralType;

typedef uint32 Csm_ChannelIdOfQueueInfoType;

typedef uint8 Csm_JobObjSynchronousIdxOfQueueInfoType;

typedef boolean Csm_JobObjSynchronousUsedOfQueueInfoType;

typedef uint8 Csm_JobPoolEndIdxOfQueueInfoType;

typedef uint8 Csm_JobPoolStartIdxOfQueueInfoType;

typedef boolean Csm_JobPoolUsedOfQueueInfoType;

typedef boolean Csm_JobSharingOfQueueInfoType;

typedef uint8 Csm_MaskedBitsOfQueueInfoType;

typedef uint8 Csm_QueueEndIdxOfQueueInfoType;

typedef uint8 Csm_QueueStartIdxOfQueueInfoType;

typedef uint16 Csm_LockOfQueueStateType;

typedef uint8 Csm_QueueIdxOfQueueStateType;

typedef uint8 Csm_SizeOfJobType;

typedef uint8 Csm_SizeOfJobInfoType;

typedef uint8 Csm_SizeOfJobPrimitiveInfoType;

typedef uint8 Csm_SizeOfJobStateType;

typedef uint8 Csm_SizeOfJobTableType;

typedef uint8 Csm_SizeOfJobToObjMapType;

typedef uint8 Csm_SizeOfKeyType;

typedef uint8 Csm_SizeOfPrimitiveInfoType;

typedef uint8 Csm_SizeOfQueueType;

typedef uint8 Csm_SizeOfQueueInfoType;

typedef uint8 Csm_SizeOfQueueStateType;

typedef uint8 Csm_SymKeyMaxLengthOfGeneralType;

typedef boolean Csm_UseDeprecatedOfGeneralType;

typedef boolean Csm_VersionInfoApiOfGeneralType;

typedef struct sCsm_JobTableType{
  Csm_CsmKeyIdIdxOfJobTableType CsmKeyIdIdxOfJobTable;
  Csm_PriorityOfJobTableType PriorityOfJobTable;
  Csm_QueueRefIdxOfJobTableType QueueRefIdxOfJobTable;
}Csm_JobTableType;

typedef struct sCsm_KeyType{
  Csm_CryIfKeyIdOfKeyType CryIfKeyIdOfKey;
}Csm_KeyType;

typedef struct sCsm_QueueInfoType{
  Csm_ChannelIdOfQueueInfoType ChannelIdOfQueueInfo;
  Csm_JobPoolStartIdxOfQueueInfoType JobPoolStartIdxOfQueueInfo;
  Csm_MaskedBitsOfQueueInfoType MaskedBitsOfQueueInfo;
  Csm_QueueEndIdxOfQueueInfoType QueueEndIdxOfQueueInfo;
}Csm_QueueInfoType;

typedef struct sCsm_QueueStateType{
  Csm_LockOfQueueStateType LockOfQueueState;
  Csm_QueueIdxOfQueueStateType QueueIdxOfQueueState;
}Csm_QueueStateType;

typedef struct Csm_QueueStructSTag{
  Csm_QueueElementType CsmQueue_Standard;
  Csm_QueueElementType CsmQueue_Aes;
}Csm_QueueStructSType;

typedef union Csm_QueueUTag{
  Csm_QueueElementType raw[2];
  Csm_QueueStructSType str;
}Csm_QueueUType;

typedef P2VAR(Crypto_JobType, TYPEDEF, CSM_VAR_NOINIT) Csm_JobPtrType;

typedef P2CONST(Crypto_JobInfoType, TYPEDEF, CSM_CONST) Csm_JobInfoPtrType;

typedef P2CONST(Crypto_JobPrimitiveInfoType, TYPEDEF, CSM_CONST) Csm_JobPrimitiveInfoPtrType;

typedef P2VAR(Csm_JobStateType, TYPEDEF, CSM_VAR_NOINIT) Csm_JobStatePtrType;

typedef P2CONST(Csm_JobTableType, TYPEDEF, CSM_CONST) Csm_JobTablePtrType;

typedef P2VAR(Csm_SizeOfJobType, TYPEDEF, CSM_VAR_NOINIT) Csm_JobToObjMapPtrType;

typedef P2CONST(Csm_KeyType, TYPEDEF, CSM_CONST) Csm_KeyPtrType;

typedef P2CONST(Crypto_PrimitiveInfoType, TYPEDEF, CSM_CONST) Csm_PrimitiveInfoPtrType;

typedef P2VAR(Csm_QueueElementType, TYPEDEF, CSM_VAR_NOINIT) Csm_QueuePtrType;

typedef P2CONST(Csm_QueueInfoType, TYPEDEF, CSM_CONST) Csm_QueueInfoPtrType;

typedef P2VAR(Csm_QueueStateType, TYPEDEF, CSM_VAR_NOINIT) Csm_QueueStatePtrType;

typedef struct sCsm_PCConfigType{
  uint8 Csm_PCConfigNeverUsed;
}Csm_PCConfigType;

typedef Csm_PCConfigType Csm_ConfigType;

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo[5];
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[5];
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[5];
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Csm_KeyType, CSM_CONST) Csm_Key[7];
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[5];
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[2];
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

extern VAR(Crypto_JobType, CSM_VAR_NOINIT) Csm_Job[2];
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_VAR_NOINIT_8BIT

#include "MemMap.hpp"

extern VAR(Csm_JobStateType, CSM_VAR_NOINIT) Csm_JobState[5];
#define CSM_STOP_SEC_VAR_NOINIT_8BIT

#include "MemMap.hpp"

#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

extern VAR(Csm_SizeOfJobType, CSM_VAR_NOINIT) Csm_JobToObjMap[5];
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

extern VAR(Csm_QueueUType, CSM_VAR_NOINIT) Csm_Queue;
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

extern VAR(Csm_QueueStateType, CSM_VAR_NOINIT) Csm_QueueState[2];
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#endif

