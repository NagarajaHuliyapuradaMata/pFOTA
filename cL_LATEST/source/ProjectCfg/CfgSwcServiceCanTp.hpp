

#if !defined(CANTP_CFG_H)
#define CANTP_CFG_H

#include "Types_SwcServiceCom.hpp"

#ifndef CANTP_USE_DUMMY_STATEMENT
#define CANTP_USE_DUMMY_STATEMENT STD_ON
#endif
#ifndef CANTP_DUMMY_STATEMENT
#define CANTP_DUMMY_STATEMENT(v) (v)=(v)
#endif
#ifndef CANTP_DUMMY_STATEMENT_CONST
#define CANTP_DUMMY_STATEMENT_CONST(v) (void)(v)
#endif
#ifndef CANTP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANTP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF
#endif
#ifndef CANTP_ATOMIC_VARIABLE_ACCESS
#define CANTP_ATOMIC_VARIABLE_ACCESS 32u
#endif
#ifndef CANTP_PROCESSOR_RH850_1013
#define CANTP_PROCESSOR_RH850_1013
#endif
#ifndef CANTP_COMP_GREENHILLS
#define CANTP_COMP_GREENHILLS
#endif
#ifndef CANTP_GEN_GENERATOR_MSR
#define CANTP_GEN_GENERATOR_MSR
#endif
#ifndef CANTP_CPUTYPE_BITORDER_LSB2MSB
#define CANTP_CPUTYPE_BITORDER_LSB2MSB
#endif
#ifndef CANTP_CONFIGURATION_VARIANT_PRECOMPILE
#define CANTP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANTP_CONFIGURATION_VARIANT_LINKTIME
#define CANTP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANTP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANTP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANTP_CONFIGURATION_VARIANT
#define CANTP_CONFIGURATION_VARIANT CANTP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANTP_POSTBUILD_VARIANT_SUPPORT
#define CANTP_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#define CANTP_CFG_GEN_MAJOR_VERSION                                            4u
#define CANTP_CFG_GEN_MINOR_VERSION                                            4u
#define CANTP_CFG_GEN_PATCH_VERSION                                            0u

#define CANTP_VERSION_INFO_API                                                 STD_OFF
#define CANTP_DEV_ERROR_DETECT                                                 STD_ON
#define CANTP_DEV_ERROR_REPORT                                                 STD_ON
#define CANTP_TC                                                               STD_OFF
#define CANTP_RC                                                               STD_OFF
#define CANTP_INVALID_HDL                                                      ((PduIdType) 255u)
#define CANTP_TASK_CYCLE                                                       5u

#define CANTP_MAX_FRAME_LENGTH                                                 8u
#define CANTP_MAX_PAYLOAD_LENGTH                                               7u
#define CANTP_MAX_PDU_METADATA_LENGTH                                          0u
#define CANTP_MAX_SDU_METADATA_LENGTH                                          0u
#define CANTP_NUM_RX_CHANNELS                                                  CanTp_GetSizeOfRxState()
#define CANTP_NUM_RX_SDUS                                                      2
#define CANTP_NUM_TX_CHANNELS                                                  CanTp_GetSizeOfTxState()
#define CANTP_NUM_TX_SDUS                                                      1
#define CANTP_SIZEOF_PDULENGTHTYPE                                             2

#define CANTP_MODE_FULL_DUPLEX                                                 1u
#define CANTP_MODE_HALF_DUPLEX                                                 0u
#define CANTP_TATYPE_FUNCTIONAL                                                1u
#define CANTP_TATYPE_PHYSICAL                                                  0u

#define CANTP_ADDRESS_FORMAT_EXTENDED                                          1u
#define CANTP_ADDRESS_FORMAT_MIXED11                                           2u
#define CANTP_ADDRESS_FORMAT_MIXED29                                           4u
#define CANTP_ADDRESS_FORMAT_NORMALFIXED                                       3u
#define CANTP_ADDRESS_FORMAT_STANDARD                                          0u

#define CANTP_CANTYPE_CAN20                                                    0u
#define CANTP_CANTYPE_CANFD                                                    1u

#define CANTP_GENERATOR_COMPATIBILITY_VERSION                                  0x0005D047uL
#define CANTP_CAN20_PADDING_ACTIVE                                             STD_ON
#define CANTP_HAVE_PADDING_BYTE                                                STD_OFF
#define CANTP_PADDING_PATTERN                                                  0xCCu
#define CANTP_DYN_CHANNEL_ASSIGNMENT                                           STD_OFF
#define CANTP_STANDARD_ADDRESSING                                              STD_ON
#define CANTP_EXTENDED_ADDRESSING                                              STD_OFF
#define CANTP_MIXED11_ADDRESSING                                               STD_OFF
#define CANTP_MIXED29_ADDRESSING                                               STD_ON
#define CANTP_NORMALFIXED_ADDRESSING                                           STD_ON
#define CANTP_SINGLE_RX_BUFFER_OPTIMIZED                                       STD_OFF
#define CANTP_RXTX_MAINFUNCTION_API                                            STD_OFF
#define CANTP_CONSTANT_BS                                                      STD_ON
#define CANTP_REJECT_FC_WITH_RES_STMIN                                         STD_OFF
#define CANTP_USE_ONLY_FIRST_FC                                                STD_OFF
#define CANTP_ENABLE_CHANGE_PARAM                                              STD_OFF
#define CANTP_ENABLE_READ_PARAM                                                STD_OFF
#define CANTP_ONLY_NOTIFY_INFORMED_APPL                                        STD_ON
#define CANTP_TRANSMIT_QUEUE                                                   STD_OFF
#define CANTP_SUPPORT_LONG_FF                                                  STD_OFF
#define CANTP_PDUR_API_AR_VERSION                                              0x412
#define CANTP_SYNC_TRANSMIT                                                    STD_ON
#define CANTP_SUPPORT_CANFD                                                    STD_OFF
#define CANTP_STMIN_BY_APPL                                                    STD_OFF
#define CANTP_DCM_REQUEST_DETECT                                               STD_OFF
#define CANTP_GENERIC_CONNECTIONS                                              STD_OFF
#define CanTp_ApplStartSeparationTime

#define CANTP_LOLAYER_CANIF                                                    STD_ON
#define CANTP_LOLAYER_TC                                                       STD_OFF
#define CanTp_CanIfCancelTransmit(Dir, SduId, PduId)
#define CanTp_CanIfTransmit(Dir, SduId, PduId, Data)                           (EcuabCanIf_Transmit((PduId),(Data)))

#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_4c7635fa 0u
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_eb0c53ed 1u

#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_eb0c53ed 0u

#define CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_1287d665 0u
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_307d0297     0u
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_062d19b1     1u

#define CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_307d0297 0u
#define CanTpConf_CanTpTxNPdu_CanTpTxNPdu_1287d665     0u

#define CANTP_CALCBS                                                                                STD_ON
#define CANTP_COMPATIBILITYVERSION                                                                  STD_ON
#define CANTP_DYNFCPARAMETERS                                                                       STD_OFF
#define CANTP_FINALMAGICNUMBER                                                                      STD_OFF
#define CANTP_INITDATAHASHCODE                                                                      STD_OFF
#define CANTP_LOLAYERFCTS                                                                           STD_OFF
#define CANTP_CANCELTRANSMITFCTOFLOLAYERFCTS                                                        STD_OFF
#define CANTP_TRANSMITFCTOFLOLAYERFCTS                                                              STD_OFF
#define CANTP_RXCHANNELMAP                                                                          STD_OFF
#define CANTP_RXPDUMAP                                                                              STD_ON
#define CANTP_ADDRESSINGFORMATOFRXPDUMAP                                                            STD_ON
#define CANTP_GENERICCONNECTIONOFRXPDUMAP                                                           STD_ON
#define CANTP_PDUMETADATALENGTHOFRXPDUMAP                                                           STD_ON
#define CANTP_RXSDUCFGINDENDIDXOFRXPDUMAP                                                           STD_ON
#define CANTP_RXSDUCFGINDSTARTIDXOFRXPDUMAP                                                         STD_ON
#define CANTP_RXSDUCFGINDUSEDOFRXPDUMAP                                                             STD_ON
#define CANTP_TXSDUCFGINDENDIDXOFRXPDUMAP                                                           STD_ON
#define CANTP_TXSDUCFGINDSTARTIDXOFRXPDUMAP                                                         STD_ON
#define CANTP_TXSDUCFGINDUSEDOFRXPDUMAP                                                             STD_ON
#define CANTP_RXSDUCFG                                                                              STD_ON
#define CANTP_BLOCKSIZEOFRXSDUCFG                                                                   STD_ON
#define CANTP_CANTYPEOFRXSDUCFG                                                                     STD_ON
#define CANTP_CHANNELMODEOFRXSDUCFG                                                                 STD_ON
#define CANTP_GENERICCONNECTIONOFRXSDUCFG                                                           STD_ON
#define CANTP_LOLAYERFCTSIDXOFRXSDUCFG                                                              STD_OFF
#define CANTP_LOLAYERTXFCPDUIDOFRXSDUCFG                                                            STD_ON
#define CANTP_NAROFRXSDUCFG                                                                         STD_ON
#define CANTP_NBROFRXSDUCFG                                                                         STD_ON
#define CANTP_NCROFRXSDUCFG                                                                         STD_ON
#define CANTP_PASSSDUMETADATAOFRXSDUCFG                                                             STD_ON
#define CANTP_PDURRXSDUIDOFRXSDUCFG                                                                 STD_ON
#define CANTP_RXADDRESSOFRXSDUCFG                                                                   STD_ON
#define CANTP_RXADDRESSINGFORMATOFRXSDUCFG                                                          STD_ON
#define CANTP_RXMAXPAYLOADLENGTHOFRXSDUCFG                                                          STD_ON
#define CANTP_RXPADDINGACTIVATIONOFRXSDUCFG                                                         STD_ON
#define CANTP_RXPDUIDOFRXSDUCFG                                                                     STD_ON
#define CANTP_RXTATYPEOFRXSDUCFG                                                                    STD_ON
#define CANTP_RXWFTMAXOFRXSDUCFG                                                                    STD_ON
#define CANTP_STMINOFRXSDUCFG                                                                       STD_ON
#define CANTP_TXFCADDRESSOFRXSDUCFG                                                                 STD_ON
#define CANTP_TXFCPDUCONFIRMATIONPDUIDOFRXSDUCFG                                                    STD_ON
#define CANTP_TXSDUCFGIDXOFRXSDUCFG                                                                 STD_ON
#define CANTP_TXSDUCFGUSEDOFRXSDUCFG                                                                STD_ON
#define CANTP_RXSDUCFGIND                                                                           STD_ON
#define CANTP_RXSDUSNV2HDL                                                                          STD_ON
#define CANTP_RXSDUCFGIDXOFRXSDUSNV2HDL                                                             STD_ON
#define CANTP_RXSDUCFGUSEDOFRXSDUSNV2HDL                                                            STD_ON
#define CANTP_RXSTATE                                                                               STD_ON
#define CANTP_SIZEOFCALCBS                                                                          STD_ON
#define CANTP_SIZEOFRXPDUMAP                                                                        STD_ON
#define CANTP_SIZEOFRXSDUCFG                                                                        STD_ON
#define CANTP_SIZEOFRXSDUCFGIND                                                                     STD_ON
#define CANTP_SIZEOFRXSDUSNV2HDL                                                                    STD_ON
#define CANTP_SIZEOFRXSTATE                                                                         STD_ON
#define CANTP_SIZEOFTXSDUCFG                                                                        STD_ON
#define CANTP_SIZEOFTXSDUCFGIND                                                                     STD_ON
#define CANTP_SIZEOFTXSDUSNV2HDL                                                                    STD_ON
#define CANTP_SIZEOFTXSEMAPHORES                                                                    STD_ON
#define CANTP_SIZEOFTXSTATE                                                                         STD_ON
#define CANTP_TXCHANNELMAP                                                                          STD_OFF
#define CANTP_TXQUEUE                                                                               STD_OFF
#define CANTP_TXSDUCFG                                                                              STD_ON
#define CANTP_CANTYPEOFTXSDUCFG                                                                     STD_ON
#define CANTP_CHANNELMODEOFTXSDUCFG                                                                 STD_ON
#define CANTP_LOLAYERFCTSIDXOFTXSDUCFG                                                              STD_OFF
#define CANTP_LOLAYERTXPDUIDOFTXSDUCFG                                                              STD_ON
#define CANTP_NASOFTXSDUCFG                                                                         STD_ON
#define CANTP_NBSOFTXSDUCFG                                                                         STD_ON
#define CANTP_NCSOFTXSDUCFG                                                                         STD_ON
#define CANTP_PDURTXSDUIDOFTXSDUCFG                                                                 STD_ON
#define CANTP_RXFCADDRESSOFTXSDUCFG                                                                 STD_ON
#define CANTP_RXFCPDUIDOFTXSDUCFG                                                                   STD_ON
#define CANTP_RXSDUCFGIDXOFTXSDUCFG                                                                 STD_ON
#define CANTP_RXSDUCFGUSEDOFTXSDUCFG                                                                STD_ON
#define CANTP_SDUMETADATALENGTHOFTXSDUCFG                                                           STD_ON
#define CANTP_TRANSMITCANCELLATIONOFTXSDUCFG                                                        STD_ON
#define CANTP_TXADDRESSOFTXSDUCFG                                                                   STD_ON
#define CANTP_TXADDRESSINGFORMATOFTXSDUCFG                                                          STD_ON
#define CANTP_TXMAXPAYLOADLENGTHOFTXSDUCFG                                                          STD_ON
#define CANTP_TXPADDINGACTIVATIONOFTXSDUCFG                                                         STD_ON
#define CANTP_TXPDUCONFIRMATIONPDUIDOFTXSDUCFG                                                      STD_ON
#define CANTP_TXTATYPEOFTXSDUCFG                                                                    STD_ON
#define CANTP_TXSDUCFGIND                                                                           STD_ON
#define CANTP_TXSDUSNV2HDL                                                                          STD_ON
#define CANTP_TXSDUCFGIDXOFTXSDUSNV2HDL                                                             STD_ON
#define CANTP_TXSDUCFGUSEDOFTXSDUSNV2HDL                                                            STD_ON
#define CANTP_TXSEMAPHORES                                                                          STD_ON
#define CANTP_TXSTATE                                                                               STD_ON
#define CANTP_PCCONFIG                                                                              STD_ON
#define CANTP_CALCBSOFPCCONFIG                                                                      STD_ON
#define CANTP_COMPATIBILITYVERSIONOFPCCONFIG                                                        STD_ON
#define CANTP_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF
#define CANTP_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF
#define CANTP_RXPDUMAPOFPCCONFIG                                                                    STD_ON
#define CANTP_RXSDUCFGINDOFPCCONFIG                                                                 STD_ON
#define CANTP_RXSDUCFGOFPCCONFIG                                                                    STD_ON
#define CANTP_RXSDUSNV2HDLOFPCCONFIG                                                                STD_ON
#define CANTP_RXSTATEOFPCCONFIG                                                                     STD_ON
#define CANTP_SIZEOFCALCBSOFPCCONFIG                                                                STD_ON
#define CANTP_SIZEOFRXPDUMAPOFPCCONFIG                                                              STD_ON
#define CANTP_SIZEOFRXSDUCFGINDOFPCCONFIG                                                           STD_ON
#define CANTP_SIZEOFRXSDUCFGOFPCCONFIG                                                              STD_ON
#define CANTP_SIZEOFRXSDUSNV2HDLOFPCCONFIG                                                          STD_ON
#define CANTP_SIZEOFRXSTATEOFPCCONFIG                                                               STD_ON
#define CANTP_SIZEOFTXSDUCFGINDOFPCCONFIG                                                           STD_ON
#define CANTP_SIZEOFTXSDUCFGOFPCCONFIG                                                              STD_ON
#define CANTP_SIZEOFTXSDUSNV2HDLOFPCCONFIG                                                          STD_ON
#define CANTP_SIZEOFTXSEMAPHORESOFPCCONFIG                                                          STD_ON
#define CANTP_SIZEOFTXSTATEOFPCCONFIG                                                               STD_ON
#define CANTP_TXSDUCFGINDOFPCCONFIG                                                                 STD_ON
#define CANTP_TXSDUCFGOFPCCONFIG                                                                    STD_ON
#define CANTP_TXSDUSNV2HDLOFPCCONFIG                                                                STD_ON
#define CANTP_TXSEMAPHORESOFPCCONFIG                                                                STD_ON
#define CANTP_TXSTATEOFPCCONFIG                                                                     STD_ON

#define CANTP_MIN_CALCBS                                                                            0u

#define CANTP_MAX_CALCBS                                                                            255u

#define CANTP_NO_RXSDUCFGINDENDIDXOFRXPDUMAP                                                        255u
#define CANTP_NO_RXSDUCFGINDSTARTIDXOFRXPDUMAP                                                      255u
#define CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP                                                        255u
#define CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP                                                      255u
#define CANTP_NO_TXSDUCFGIDXOFRXSDUCFG                                                              255u
#define CANTP_NO_RXSDUCFGIDXOFRXSDUSNV2HDL                                                          255u
#define CANTP_NO_RXSDUCFGIDXOFTXSDUCFG                                                              255u
#define CANTP_NO_TXSDUCFGIDXOFTXSDUSNV2HDL                                                          255u

#define CANTP_EXISTS_NORMAL_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                                   STD_ON
#define CANTP_EXISTS_EXTENDED_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                                 STD_OFF
#define CANTP_EXISTS_MIXED11_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                                  STD_OFF
#define CANTP_EXISTS_NORMALFIXED_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                              STD_OFF
#define CANTP_EXISTS_MIXED29_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                                  STD_OFF
#define CANTP_EXISTS_CAN20_CANTYPEOFRXSDUCFG                                                        STD_ON
#define CANTP_EXISTS_CANFD_CANTYPEOFRXSDUCFG                                                        STD_OFF
#define CANTP_EXISTS_HALF_DUPLEX_CHANNELMODEOFRXSDUCFG                                              STD_OFF
#define CANTP_EXISTS_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG                                              STD_ON
#define CANTP_EXISTS_NORMAL_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                                 STD_ON
#define CANTP_EXISTS_EXTENDED_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                               STD_OFF
#define CANTP_EXISTS_MIXED11_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                                STD_OFF
#define CANTP_EXISTS_NORMALFIXED_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                            STD_OFF
#define CANTP_EXISTS_MIXED29_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                                STD_OFF
#define CANTP_EXISTS_PHYSICAL_RXTATYPEOFRXSDUCFG                                                    STD_ON
#define CANTP_EXISTS_FUNCTIONAL_RXTATYPEOFRXSDUCFG                                                  STD_ON
#define CANTP_EXISTS_CANFD_PHYSICAL_RXTATYPEOFRXSDUCFG                                              STD_ON
#define CANTP_EXISTS_CANFD_FUNCTIONAL_RXTATYPEOFRXSDUCFG                                            STD_ON
#define CANTP_EXISTS_CAN20_CANTYPEOFTXSDUCFG                                                        STD_ON
#define CANTP_EXISTS_CANFD_CANTYPEOFTXSDUCFG                                                        STD_OFF
#define CANTP_EXISTS_HALF_DUPLEX_CHANNELMODEOFTXSDUCFG                                              STD_OFF
#define CANTP_EXISTS_FULL_DUPLEX_CHANNELMODEOFTXSDUCFG                                              STD_ON
#define CANTP_EXISTS_NORMAL_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                                 STD_ON
#define CANTP_EXISTS_EXTENDED_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                               STD_OFF
#define CANTP_EXISTS_MIXED11_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                                STD_OFF
#define CANTP_EXISTS_NORMALFIXED_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                            STD_OFF
#define CANTP_EXISTS_MIXED29_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                                STD_OFF
#define CANTP_EXISTS_PHYSICAL_TXTATYPEOFTXSDUCFG                                                    STD_ON
#define CANTP_EXISTS_FUNCTIONAL_TXTATYPEOFTXSDUCFG                                                  STD_OFF
#define CANTP_EXISTS_CANFD_PHYSICAL_TXTATYPEOFTXSDUCFG                                              STD_ON
#define CANTP_EXISTS_CANFD_FUNCTIONAL_TXTATYPEOFTXSDUCFG                                            STD_OFF

#define CANTP_NORMAL_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                                          0x00u
#define CANTP_CAN20_CANTYPEOFRXSDUCFG                                                               0x00u
#define CANTP_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG                                                     0x01u
#define CANTP_NORMAL_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                                        0x00u
#define CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG                                                           0x00u
#define CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG                                                         0x01u
#define CANTP_CANFD_PHYSICAL_RXTATYPEOFRXSDUCFG                                                     0x00u
#define CANTP_CANFD_FUNCTIONAL_RXTATYPEOFRXSDUCFG                                                   0x01u
#define CANTP_CAN20_CANTYPEOFTXSDUCFG                                                               0x00u
#define CANTP_FULL_DUPLEX_CHANNELMODEOFTXSDUCFG                                                     0x01u
#define CANTP_NORMAL_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                                        0x00u
#define CANTP_PHYSICAL_TXTATYPEOFTXSDUCFG                                                           0x00u
#define CANTP_CANFD_PHYSICAL_TXTATYPEOFTXSDUCFG                                                     0x00u

#define CANTP_ISDEF_ADDRESSINGFORMATOFRXPDUMAP                                                      STD_ON
#define CANTP_ISDEF_GENERICCONNECTIONOFRXPDUMAP                                                     STD_ON
#define CANTP_ISDEF_PDUMETADATALENGTHOFRXPDUMAP                                                     STD_ON
#define CANTP_ISDEF_RXSDUCFGINDENDIDXOFRXPDUMAP                                                     STD_OFF
#define CANTP_ISDEF_RXSDUCFGINDSTARTIDXOFRXPDUMAP                                                   STD_OFF
#define CANTP_ISDEF_RXSDUCFGINDUSEDOFRXPDUMAP                                                       STD_ON
#define CANTP_ISDEF_TXSDUCFGINDENDIDXOFRXPDUMAP                                                     STD_OFF
#define CANTP_ISDEF_TXSDUCFGINDSTARTIDXOFRXPDUMAP                                                   STD_OFF
#define CANTP_ISDEF_TXSDUCFGINDUSEDOFRXPDUMAP                                                       STD_OFF
#define CANTP_ISDEF_BLOCKSIZEOFRXSDUCFG                                                             STD_OFF
#define CANTP_ISDEF_CANTYPEOFRXSDUCFG                                                               STD_ON
#define CANTP_ISDEF_CHANNELMODEOFRXSDUCFG                                                           STD_ON
#define CANTP_ISDEF_GENERICCONNECTIONOFRXSDUCFG                                                     STD_ON
#define CANTP_ISDEF_LOLAYERTXFCPDUIDOFRXSDUCFG                                                      STD_OFF
#define CANTP_ISDEF_NAROFRXSDUCFG                                                                   STD_OFF
#define CANTP_ISDEF_NBROFRXSDUCFG                                                                   STD_ON
#define CANTP_ISDEF_NCROFRXSDUCFG                                                                   STD_OFF
#define CANTP_ISDEF_PASSSDUMETADATAOFRXSDUCFG                                                       STD_ON
#define CANTP_ISDEF_PDURRXSDUIDOFRXSDUCFG                                                           STD_OFF
#define CANTP_ISDEF_RXADDRESSOFRXSDUCFG                                                             STD_ON
#define CANTP_ISDEF_RXADDRESSINGFORMATOFRXSDUCFG                                                    STD_ON
#define CANTP_ISDEF_RXMAXPAYLOADLENGTHOFRXSDUCFG                                                    STD_ON
#define CANTP_ISDEF_RXPADDINGACTIVATIONOFRXSDUCFG                                                   STD_ON
#define CANTP_ISDEF_RXPDUIDOFRXSDUCFG                                                               STD_OFF
#define CANTP_ISDEF_RXTATYPEOFRXSDUCFG                                                              STD_OFF
#define CANTP_ISDEF_RXWFTMAXOFRXSDUCFG                                                              STD_ON
#define CANTP_ISDEF_STMINOFRXSDUCFG                                                                 STD_ON
#define CANTP_ISDEF_TXFCADDRESSOFRXSDUCFG                                                           STD_ON
#define CANTP_ISDEF_TXFCPDUCONFIRMATIONPDUIDOFRXSDUCFG                                              STD_OFF
#define CANTP_ISDEF_TXSDUCFGIDXOFRXSDUCFG                                                           STD_OFF
#define CANTP_ISDEF_TXSDUCFGUSEDOFRXSDUCFG                                                          STD_OFF
#define CANTP_ISDEF_RXSDUCFGIND                                                                     STD_OFF
#define CANTP_ISDEF_RXSDUCFGIDXOFRXSDUSNV2HDL                                                       STD_OFF
#define CANTP_ISDEF_RXSDUCFGUSEDOFRXSDUSNV2HDL                                                      STD_ON
#define CANTP_ISDEF_CANTYPEOFTXSDUCFG                                                               STD_ON
#define CANTP_ISDEF_CHANNELMODEOFTXSDUCFG                                                           STD_ON
#define CANTP_ISDEF_LOLAYERTXPDUIDOFTXSDUCFG                                                        STD_ON
#define CANTP_ISDEF_NASOFTXSDUCFG                                                                   STD_ON
#define CANTP_ISDEF_NBSOFTXSDUCFG                                                                   STD_ON
#define CANTP_ISDEF_NCSOFTXSDUCFG                                                                   STD_ON
#define CANTP_ISDEF_PDURTXSDUIDOFTXSDUCFG                                                           STD_ON
#define CANTP_ISDEF_RXFCADDRESSOFTXSDUCFG                                                           STD_ON
#define CANTP_ISDEF_RXFCPDUIDOFTXSDUCFG                                                             STD_ON
#define CANTP_ISDEF_RXSDUCFGIDXOFTXSDUCFG                                                           STD_ON
#define CANTP_ISDEF_RXSDUCFGUSEDOFTXSDUCFG                                                          STD_ON
#define CANTP_ISDEF_SDUMETADATALENGTHOFTXSDUCFG                                                     STD_ON
#define CANTP_ISDEF_TRANSMITCANCELLATIONOFTXSDUCFG                                                  STD_ON
#define CANTP_ISDEF_TXADDRESSOFTXSDUCFG                                                             STD_ON
#define CANTP_ISDEF_TXADDRESSINGFORMATOFTXSDUCFG                                                    STD_ON
#define CANTP_ISDEF_TXMAXPAYLOADLENGTHOFTXSDUCFG                                                    STD_ON
#define CANTP_ISDEF_TXPADDINGACTIVATIONOFTXSDUCFG                                                   STD_ON
#define CANTP_ISDEF_TXPDUCONFIRMATIONPDUIDOFTXSDUCFG                                                STD_ON
#define CANTP_ISDEF_TXTATYPEOFTXSDUCFG                                                              STD_ON
#define CANTP_ISDEF_TXSDUCFGIND                                                                     STD_ON
#define CANTP_ISDEF_TXSDUCFGIDXOFTXSDUSNV2HDL                                                       STD_ON
#define CANTP_ISDEF_TXSDUCFGUSEDOFTXSDUSNV2HDL                                                      STD_ON
#define CANTP_ISDEF_CALCBSOFPCCONFIG                                                                STD_ON
#define CANTP_ISDEF_RXPDUMAPOFPCCONFIG                                                              STD_ON
#define CANTP_ISDEF_RXSDUCFGINDOFPCCONFIG                                                           STD_ON
#define CANTP_ISDEF_RXSDUCFGOFPCCONFIG                                                              STD_ON
#define CANTP_ISDEF_RXSDUSNV2HDLOFPCCONFIG                                                          STD_ON
#define CANTP_ISDEF_RXSTATEOFPCCONFIG                                                               STD_ON
#define CANTP_ISDEF_TXSDUCFGINDOFPCCONFIG                                                           STD_ON
#define CANTP_ISDEF_TXSDUCFGOFPCCONFIG                                                              STD_ON
#define CANTP_ISDEF_TXSDUSNV2HDLOFPCCONFIG                                                          STD_ON
#define CANTP_ISDEF_TXSEMAPHORESOFPCCONFIG                                                          STD_ON
#define CANTP_ISDEF_TXSTATEOFPCCONFIG                                                               STD_ON

#define CANTP_EQ2_ADDRESSINGFORMATOFRXPDUMAP                                                        CANTP_NORMAL_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP
#define CANTP_EQ2_GENERICCONNECTIONOFRXPDUMAP                                                       FALSE
#define CANTP_EQ2_PDUMETADATALENGTHOFRXPDUMAP                                                       0u
#define CANTP_EQ2_RXSDUCFGINDENDIDXOFRXPDUMAP
#define CANTP_EQ2_RXSDUCFGINDSTARTIDXOFRXPDUMAP
#define CANTP_EQ2_RXSDUCFGINDUSEDOFRXPDUMAP                                                         TRUE
#define CANTP_EQ2_TXSDUCFGINDENDIDXOFRXPDUMAP
#define CANTP_EQ2_TXSDUCFGINDSTARTIDXOFRXPDUMAP
#define CANTP_EQ2_TXSDUCFGINDUSEDOFRXPDUMAP
#define CANTP_EQ2_BLOCKSIZEOFRXSDUCFG
#define CANTP_EQ2_CANTYPEOFRXSDUCFG                                                                 CANTP_CAN20_CANTYPEOFRXSDUCFG
#define CANTP_EQ2_CHANNELMODEOFRXSDUCFG                                                             CANTP_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG
#define CANTP_EQ2_GENERICCONNECTIONOFRXSDUCFG                                                       FALSE
#define CANTP_EQ2_LOLAYERTXFCPDUIDOFRXSDUCFG
#define CANTP_EQ2_NAROFRXSDUCFG
#define CANTP_EQ2_NBROFRXSDUCFG                                                                     21u
#define CANTP_EQ2_NCROFRXSDUCFG
#define CANTP_EQ2_PASSSDUMETADATAOFRXSDUCFG                                                         FALSE
#define CANTP_EQ2_PDURRXSDUIDOFRXSDUCFG
#define CANTP_EQ2_RXADDRESSOFRXSDUCFG                                                               255u
#define CANTP_EQ2_RXADDRESSINGFORMATOFRXSDUCFG                                                      CANTP_NORMAL_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG
#define CANTP_EQ2_RXMAXPAYLOADLENGTHOFRXSDUCFG                                                      7u
#define CANTP_EQ2_RXPADDINGACTIVATIONOFRXSDUCFG                                                     TRUE
#define CANTP_EQ2_RXPDUIDOFRXSDUCFG
#define CANTP_EQ2_RXTATYPEOFRXSDUCFG
#define CANTP_EQ2_RXWFTMAXOFRXSDUCFG                                                                15u
#define CANTP_EQ2_STMINOFRXSDUCFG                                                                   0u
#define CANTP_EQ2_TXFCADDRESSOFRXSDUCFG                                                             255u
#define CANTP_EQ2_TXFCPDUCONFIRMATIONPDUIDOFRXSDUCFG
#define CANTP_EQ2_TXSDUCFGIDXOFRXSDUCFG
#define CANTP_EQ2_TXSDUCFGUSEDOFRXSDUCFG
#define CANTP_EQ2_RXSDUCFGIND
#define CANTP_EQ2_RXSDUCFGIDXOFRXSDUSNV2HDL
#define CANTP_EQ2_RXSDUCFGUSEDOFRXSDUSNV2HDL                                                        TRUE
#define CANTP_EQ2_CANTYPEOFTXSDUCFG                                                                 CANTP_CAN20_CANTYPEOFTXSDUCFG
#define CANTP_EQ2_CHANNELMODEOFTXSDUCFG                                                             CANTP_FULL_DUPLEX_CHANNELMODEOFTXSDUCFG
#define CANTP_EQ2_LOLAYERTXPDUIDOFTXSDUCFG                                                          CanIfConf_CanIfTxPduCfg_UDS_Tx_Physical_Tp_oP1951001_0_003_01_24_RAJA_A1_V_bbbad787_Tx
#define CANTP_EQ2_NASOFTXSDUCFG                                                                     21u
#define CANTP_EQ2_NBSOFTXSDUCFG                                                                     101u
#define CANTP_EQ2_NCSOFTXSDUCFG                                                                     41u
#define CANTP_EQ2_PDURTXSDUIDOFTXSDUCFG                                                             PduRConf_PduRDestPdu_UDS_Tx_Physical_oP1951001_0_003_01_24_RAJA_A1_V_abd46ddc_Tx
#define CANTP_EQ2_RXFCADDRESSOFTXSDUCFG                                                             255u
#define CANTP_EQ2_RXFCPDUIDOFTXSDUCFG                                                               CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_1287d665
#define CANTP_EQ2_RXSDUCFGIDXOFTXSDUCFG                                                             1u
#define CANTP_EQ2_RXSDUCFGUSEDOFTXSDUCFG                                                            TRUE
#define CANTP_EQ2_SDUMETADATALENGTHOFTXSDUCFG                                                       0u
#define CANTP_EQ2_TRANSMITCANCELLATIONOFTXSDUCFG                                                    FALSE
#define CANTP_EQ2_TXADDRESSOFTXSDUCFG                                                               255u
#define CANTP_EQ2_TXADDRESSINGFORMATOFTXSDUCFG                                                      CANTP_NORMAL_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG
#define CANTP_EQ2_TXMAXPAYLOADLENGTHOFTXSDUCFG                                                      7u
#define CANTP_EQ2_TXPADDINGACTIVATIONOFTXSDUCFG                                                     TRUE
#define CANTP_EQ2_TXPDUCONFIRMATIONPDUIDOFTXSDUCFG                                                  CanTpConf_CanTpTxNPdu_CanTpTxNPdu_1287d665
#define CANTP_EQ2_TXTATYPEOFTXSDUCFG                                                                CANTP_PHYSICAL_TXTATYPEOFTXSDUCFG
#define CANTP_EQ2_TXSDUCFGIND                                                                       0u
#define CANTP_EQ2_TXSDUCFGIDXOFTXSDUSNV2HDL                                                         0u
#define CANTP_EQ2_TXSDUCFGUSEDOFTXSDUSNV2HDL                                                        TRUE
#define CANTP_EQ2_CALCBSOFPCCONFIG                                                                  CanTp_CalcBS
#define CANTP_EQ2_RXPDUMAPOFPCCONFIG                                                                CanTp_RxPduMap
#define CANTP_EQ2_RXSDUCFGINDOFPCCONFIG                                                             CanTp_RxSduCfgInd
#define CANTP_EQ2_RXSDUCFGOFPCCONFIG                                                                CanTp_RxSduCfg
#define CANTP_EQ2_RXSDUSNV2HDLOFPCCONFIG                                                            CanTp_RxSduSnv2Hdl
#define CANTP_EQ2_RXSTATEOFPCCONFIG                                                                 CanTp_RxState
#define CANTP_EQ2_TXSDUCFGINDOFPCCONFIG                                                             CanTp_TxSduCfgInd
#define CANTP_EQ2_TXSDUCFGOFPCCONFIG                                                                CanTp_TxSduCfg
#define CANTP_EQ2_TXSDUSNV2HDLOFPCCONFIG                                                            CanTp_TxSduSnv2Hdl
#define CANTP_EQ2_TXSEMAPHORESOFPCCONFIG                                                            CanTp_TxSemaphores
#define CANTP_EQ2_TXSTATEOFPCCONFIG                                                                 CanTp_TxState

#define CanTp_Config_Ptr                                                                            NULL_PTR

#define CanTp_Config                                                                                NULL_PTR

#define CANTP_CHECK_INIT_POINTER                                                                    STD_OFF
#define CANTP_FINAL_MAGIC_NUMBER                                                                    0x231Eu
#define CANTP_INDIVIDUAL_POSTBUILD                                                                  STD_OFF
#define CANTP_INIT_DATA                                                                             CANTP_CONST
#define CANTP_INIT_DATA_HASH_CODE                                                                   835452236
#define CANTP_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF
#define CANTP_USE_INIT_POINTER                                                                      STD_OFF

#define CanTp_GetCalcBSOfPCConfig()                                                                 CanTp_CalcBS
#define CanTp_GetCompatibilityVersionOfPCConfig()                                                   380999u
#define CanTp_GetRxPduMapOfPCConfig()                                                               CanTp_RxPduMap
#define CanTp_GetRxSduCfgIndOfPCConfig()                                                            CanTp_RxSduCfgInd
#define CanTp_GetRxSduCfgOfPCConfig()                                                               CanTp_RxSduCfg
#define CanTp_GetRxSduSnv2HdlOfPCConfig()                                                           CanTp_RxSduSnv2Hdl
#define CanTp_GetRxStateOfPCConfig()                                                                CanTp_RxState
#define CanTp_GetSizeOfCalcBSOfPCConfig()                                                           2u
#define CanTp_GetSizeOfRxPduMapOfPCConfig()                                                         2u
#define CanTp_GetSizeOfRxSduCfgIndOfPCConfig()                                                      2u
#define CanTp_GetSizeOfRxSduCfgOfPCConfig()                                                         2u
#define CanTp_GetSizeOfRxSduSnv2HdlOfPCConfig()                                                     2u
#define CanTp_GetSizeOfRxStateOfPCConfig()                                                          2u
#define CanTp_GetSizeOfTxSduCfgIndOfPCConfig()                                                      1u
#define CanTp_GetSizeOfTxSduCfgOfPCConfig()                                                         1u
#define CanTp_GetSizeOfTxSduSnv2HdlOfPCConfig()                                                     1u
#define CanTp_GetSizeOfTxSemaphoresOfPCConfig()                                                     1u
#define CanTp_GetSizeOfTxStateOfPCConfig()                                                          1u
#define CanTp_GetTxSduCfgIndOfPCConfig()                                                            CanTp_TxSduCfgInd
#define CanTp_GetTxSduCfgOfPCConfig()                                                               CanTp_TxSduCfg
#define CanTp_GetTxSduSnv2HdlOfPCConfig()                                                           CanTp_TxSduSnv2Hdl
#define CanTp_GetTxSemaphoresOfPCConfig()                                                           CanTp_TxSemaphores
#define CanTp_GetTxStateOfPCConfig()                                                                CanTp_TxState

#define CanTp_GetCalcBS(Index)                                                                      (CanTp_GetCalcBSOfPCConfig()[(Index)])
#define CanTp_GetRxSduCfgIndEndIdxOfRxPduMap(Index)                                                 (CanTp_GetRxPduMapOfPCConfig()[(Index)].RxSduCfgIndEndIdxOfRxPduMap)
#define CanTp_GetRxSduCfgIndStartIdxOfRxPduMap(Index)                                               (CanTp_GetRxPduMapOfPCConfig()[(Index)].RxSduCfgIndStartIdxOfRxPduMap)
#define CanTp_GetTxSduCfgIndEndIdxOfRxPduMap(Index)                                                 (CanTp_GetRxPduMapOfPCConfig()[(Index)].TxSduCfgIndEndIdxOfRxPduMap)
#define CanTp_GetTxSduCfgIndStartIdxOfRxPduMap(Index)                                               (CanTp_GetRxPduMapOfPCConfig()[(Index)].TxSduCfgIndStartIdxOfRxPduMap)
#define CanTp_GetBlockSizeOfRxSduCfg(Index)                                                         (CanTp_GetRxSduCfgOfPCConfig()[(Index)].BlockSizeOfRxSduCfg)
#define CanTp_GetLoLayerTxFcPduIdOfRxSduCfg(Index)                                                  (CanTp_GetRxSduCfgOfPCConfig()[(Index)].LoLayerTxFcPduIdOfRxSduCfg)
#define CanTp_GetNArOfRxSduCfg(Index)                                                               (CanTp_GetRxSduCfgOfPCConfig()[(Index)].NArOfRxSduCfg)
#define CanTp_GetNCrOfRxSduCfg(Index)                                                               (CanTp_GetRxSduCfgOfPCConfig()[(Index)].NCrOfRxSduCfg)
#define CanTp_GetPduRRxSduIdOfRxSduCfg(Index)                                                       (CanTp_GetRxSduCfgOfPCConfig()[(Index)].PduRRxSduIdOfRxSduCfg)
#define CanTp_GetRxPduIdOfRxSduCfg(Index)                                                           (CanTp_GetRxSduCfgOfPCConfig()[(Index)].RxPduIdOfRxSduCfg)
#define CanTp_GetRxTaTypeOfRxSduCfg(Index)                                                          (CanTp_GetRxSduCfgOfPCConfig()[(Index)].RxTaTypeOfRxSduCfg)
#define CanTp_GetTxFcPduConfirmationPduIdOfRxSduCfg(Index)                                          (CanTp_GetRxSduCfgOfPCConfig()[(Index)].TxFcPduConfirmationPduIdOfRxSduCfg)
#define CanTp_GetTxSduCfgIdxOfRxSduCfg(Index)                                                       (CanTp_GetRxSduCfgOfPCConfig()[(Index)].TxSduCfgIdxOfRxSduCfg)
#define CanTp_GetRxSduCfgInd(Index)                                                                 (CanTp_GetRxSduCfgIndOfPCConfig()[(Index)])
#define CanTp_GetRxSduCfgIdxOfRxSduSnv2Hdl(Index)                                                   (CanTp_GetRxSduSnv2HdlOfPCConfig()[(Index)].RxSduCfgIdxOfRxSduSnv2Hdl)
#define CanTp_GetRxState(Index)                                                                     (CanTp_GetRxStateOfPCConfig()[(Index)])
#define CanTp_GetTxSemaphores(Index)                                                                (CanTp_GetTxSemaphoresOfPCConfig()[(Index)])
#define CanTp_GetTxState(Index)                                                                     (CanTp_GetTxStateOfPCConfig()[(Index)])

#define CanTp_GetCompatibilityVersion()                                                             CanTp_GetCompatibilityVersionOfPCConfig()
#define CanTp_GetAddressingFormatOfRxPduMap(Index)                                                  CANTP_NORMAL_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP
#define CanTp_IsGenericConnectionOfRxPduMap(Index)                                                  (((FALSE)) != FALSE)
#define CanTp_GetPduMetadataLengthOfRxPduMap(Index)                                                 0u
#define CanTp_IsRxSduCfgIndUsedOfRxPduMap(Index)                                                    (((TRUE)) != FALSE)
#define CanTp_IsTxSduCfgIndUsedOfRxPduMap(Index)                                                    (((boolean)(CanTp_GetTxSduCfgIndStartIdxOfRxPduMap(Index) != CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP)) != FALSE)
#define CanTp_GetCanTypeOfRxSduCfg(Index)                                                           CANTP_CAN20_CANTYPEOFRXSDUCFG
#define CanTp_GetChannelModeOfRxSduCfg(Index)                                                       CANTP_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG
#define CanTp_IsGenericConnectionOfRxSduCfg(Index)                                                  (((FALSE)) != FALSE)
#define CanTp_GetNBrOfRxSduCfg(Index)                                                               21u
#define CanTp_IsPassSduMetadataOfRxSduCfg(Index)                                                    (((FALSE)) != FALSE)
#define CanTp_GetRxAddressOfRxSduCfg(Index)                                                         255u
#define CanTp_GetRxAddressingFormatOfRxSduCfg(Index)                                                CANTP_NORMAL_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG
#define CanTp_GetRxMaxPayloadLengthOfRxSduCfg(Index)                                                7u
#define CanTp_IsRxPaddingActivationOfRxSduCfg(Index)                                                (((TRUE)) != FALSE)
#define CanTp_GetRxWftMaxOfRxSduCfg(Index)                                                          15u
#define CanTp_GetSTminOfRxSduCfg(Index)                                                             0u
#define CanTp_GetTxFcAddressOfRxSduCfg(Index)                                                       255u
#define CanTp_IsTxSduCfgUsedOfRxSduCfg(Index)                                                       (((boolean)(CanTp_GetTxSduCfgIdxOfRxSduCfg(Index) != CANTP_NO_TXSDUCFGIDXOFRXSDUCFG)) != FALSE)
#define CanTp_IsRxSduCfgUsedOfRxSduSnv2Hdl(Index)                                                   (((TRUE)) != FALSE)
#define CanTp_GetSizeOfCalcBS()                                                                     CanTp_GetSizeOfCalcBSOfPCConfig()
#define CanTp_GetSizeOfRxPduMap()                                                                   CanTp_GetSizeOfRxPduMapOfPCConfig()
#define CanTp_GetSizeOfRxSduCfg()                                                                   CanTp_GetSizeOfRxSduCfgOfPCConfig()
#define CanTp_GetSizeOfRxSduCfgInd()                                                                CanTp_GetSizeOfRxSduCfgIndOfPCConfig()
#define CanTp_GetSizeOfRxSduSnv2Hdl()                                                               CanTp_GetSizeOfRxSduSnv2HdlOfPCConfig()
#define CanTp_GetSizeOfRxState()                                                                    CanTp_GetSizeOfRxStateOfPCConfig()
#define CanTp_GetSizeOfTxSduCfg()                                                                   CanTp_GetSizeOfTxSduCfgOfPCConfig()
#define CanTp_GetSizeOfTxSduCfgInd()                                                                CanTp_GetSizeOfTxSduCfgIndOfPCConfig()
#define CanTp_GetSizeOfTxSduSnv2Hdl()                                                               CanTp_GetSizeOfTxSduSnv2HdlOfPCConfig()
#define CanTp_GetSizeOfTxSemaphores()                                                               CanTp_GetSizeOfTxSemaphoresOfPCConfig()
#define CanTp_GetSizeOfTxState()                                                                    CanTp_GetSizeOfTxStateOfPCConfig()
#define CanTp_GetCanTypeOfTxSduCfg(Index)                                                           CANTP_CAN20_CANTYPEOFTXSDUCFG
#define CanTp_GetChannelModeOfTxSduCfg(Index)                                                       CANTP_FULL_DUPLEX_CHANNELMODEOFTXSDUCFG
#define CanTp_GetLoLayerTxPduIdOfTxSduCfg(Index)                                                    CanIfConf_CanIfTxPduCfg_UDS_Tx_Physical_Tp_oP1951001_0_003_01_24_RAJA_A1_V_bbbad787_Tx
#define CanTp_GetNAsOfTxSduCfg(Index)                                                               21u
#define CanTp_GetNBsOfTxSduCfg(Index)                                                               101u
#define CanTp_GetNCsOfTxSduCfg(Index)                                                               41u
#define CanTp_GetPduRTxSduIdOfTxSduCfg(Index)                                                       PduRConf_PduRDestPdu_UDS_Tx_Physical_oP1951001_0_003_01_24_RAJA_A1_V_abd46ddc_Tx
#define CanTp_GetRxFcAddressOfTxSduCfg(Index)                                                       255u
#define CanTp_GetRxFcPduIdOfTxSduCfg(Index)                                                         CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_1287d665
#define CanTp_GetRxSduCfgIdxOfTxSduCfg(Index)                                                       1u
#define CanTp_IsRxSduCfgUsedOfTxSduCfg(Index)                                                       (((TRUE)) != FALSE)
#define CanTp_GetSduMetadataLengthOfTxSduCfg(Index)                                                 0u
#define CanTp_IsTransmitCancellationOfTxSduCfg(Index)                                               (((FALSE)) != FALSE)
#define CanTp_GetTxAddressOfTxSduCfg(Index)                                                         255u
#define CanTp_GetTxAddressingFormatOfTxSduCfg(Index)                                                CANTP_NORMAL_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG
#define CanTp_GetTxMaxPayloadLengthOfTxSduCfg(Index)                                                7u
#define CanTp_IsTxPaddingActivationOfTxSduCfg(Index)                                                (((TRUE)) != FALSE)
#define CanTp_GetTxPduConfirmationPduIdOfTxSduCfg(Index)                                            CanTpConf_CanTpTxNPdu_CanTpTxNPdu_1287d665
#define CanTp_GetTxTaTypeOfTxSduCfg(Index)                                                          CANTP_PHYSICAL_TXTATYPEOFTXSDUCFG
#define CanTp_GetTxSduCfgInd(Index)                                                                 0u
#define CanTp_GetTxSduCfgIdxOfTxSduSnv2Hdl(Index)                                                   0u
#define CanTp_IsTxSduCfgUsedOfTxSduSnv2Hdl(Index)                                                   (((TRUE)) != FALSE)

#define CanTp_SetCalcBS(Index, Value)                                                               CanTp_GetCalcBSOfPCConfig()[(Index)] = (Value)
#define CanTp_SetRxState(Index, Value)                                                              CanTp_GetRxStateOfPCConfig()[(Index)] = (Value)
#define CanTp_SetTxSemaphores(Index, Value)                                                         CanTp_GetTxSemaphoresOfPCConfig()[(Index)] = (Value)
#define CanTp_SetTxState(Index, Value)                                                              CanTp_GetTxStateOfPCConfig()[(Index)] = (Value)

#define CanTp_HasCalcBS()                                                                           (TRUE != FALSE)
#define CanTp_HasCompatibilityVersion()                                                             (TRUE != FALSE)
#define CanTp_HasRxPduMap()                                                                         (TRUE != FALSE)
#define CanTp_HasAddressingFormatOfRxPduMap()                                                       (TRUE != FALSE)
#define CanTp_HasGenericConnectionOfRxPduMap()                                                      (TRUE != FALSE)
#define CanTp_HasPduMetadataLengthOfRxPduMap()                                                      (TRUE != FALSE)
#define CanTp_HasRxSduCfgIndEndIdxOfRxPduMap()                                                      (TRUE != FALSE)
#define CanTp_HasRxSduCfgIndStartIdxOfRxPduMap()                                                    (TRUE != FALSE)
#define CanTp_HasRxSduCfgIndUsedOfRxPduMap()                                                        (TRUE != FALSE)
#define CanTp_HasTxSduCfgIndEndIdxOfRxPduMap()                                                      (TRUE != FALSE)
#define CanTp_HasTxSduCfgIndStartIdxOfRxPduMap()                                                    (TRUE != FALSE)
#define CanTp_HasTxSduCfgIndUsedOfRxPduMap()                                                        (TRUE != FALSE)
#define CanTp_HasRxSduCfg()                                                                         (TRUE != FALSE)
#define CanTp_HasBlockSizeOfRxSduCfg()                                                              (TRUE != FALSE)
#define CanTp_HasCanTypeOfRxSduCfg()                                                                (TRUE != FALSE)
#define CanTp_HasChannelModeOfRxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasGenericConnectionOfRxSduCfg()                                                      (TRUE != FALSE)
#define CanTp_HasLoLayerTxFcPduIdOfRxSduCfg()                                                       (TRUE != FALSE)
#define CanTp_HasNArOfRxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasNBrOfRxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasNCrOfRxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasPassSduMetadataOfRxSduCfg()                                                        (TRUE != FALSE)
#define CanTp_HasPduRRxSduIdOfRxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasRxAddressOfRxSduCfg()                                                              (TRUE != FALSE)
#define CanTp_HasRxAddressingFormatOfRxSduCfg()                                                     (TRUE != FALSE)
#define CanTp_HasRxMaxPayloadLengthOfRxSduCfg()                                                     (TRUE != FALSE)
#define CanTp_HasRxPaddingActivationOfRxSduCfg()                                                    (TRUE != FALSE)
#define CanTp_HasRxPduIdOfRxSduCfg()                                                                (TRUE != FALSE)
#define CanTp_HasRxTaTypeOfRxSduCfg()                                                               (TRUE != FALSE)
#define CanTp_HasRxWftMaxOfRxSduCfg()                                                               (TRUE != FALSE)
#define CanTp_HasSTminOfRxSduCfg()                                                                  (TRUE != FALSE)
#define CanTp_HasTxFcAddressOfRxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasTxFcPduConfirmationPduIdOfRxSduCfg()                                               (TRUE != FALSE)
#define CanTp_HasTxSduCfgIdxOfRxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasTxSduCfgUsedOfRxSduCfg()                                                           (TRUE != FALSE)
#define CanTp_HasRxSduCfgInd()                                                                      (TRUE != FALSE)
#define CanTp_HasRxSduSnv2Hdl()                                                                     (TRUE != FALSE)
#define CanTp_HasRxSduCfgIdxOfRxSduSnv2Hdl()                                                        (TRUE != FALSE)
#define CanTp_HasRxSduCfgUsedOfRxSduSnv2Hdl()                                                       (TRUE != FALSE)
#define CanTp_HasRxState()                                                                          (TRUE != FALSE)
#define CanTp_HasSizeOfCalcBS()                                                                     (TRUE != FALSE)
#define CanTp_HasSizeOfRxPduMap()                                                                   (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduCfg()                                                                   (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduCfgInd()                                                                (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduSnv2Hdl()                                                               (TRUE != FALSE)
#define CanTp_HasSizeOfRxState()                                                                    (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduCfg()                                                                   (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduCfgInd()                                                                (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduSnv2Hdl()                                                               (TRUE != FALSE)
#define CanTp_HasSizeOfTxSemaphores()                                                               (TRUE != FALSE)
#define CanTp_HasSizeOfTxState()                                                                    (TRUE != FALSE)
#define CanTp_HasTxSduCfg()                                                                         (TRUE != FALSE)
#define CanTp_HasCanTypeOfTxSduCfg()                                                                (TRUE != FALSE)
#define CanTp_HasChannelModeOfTxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasLoLayerTxPduIdOfTxSduCfg()                                                         (TRUE != FALSE)
#define CanTp_HasNAsOfTxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasNBsOfTxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasNCsOfTxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasPduRTxSduIdOfTxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasRxFcAddressOfTxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasRxFcPduIdOfTxSduCfg()                                                              (TRUE != FALSE)
#define CanTp_HasRxSduCfgIdxOfTxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasRxSduCfgUsedOfTxSduCfg()                                                           (TRUE != FALSE)
#define CanTp_HasSduMetadataLengthOfTxSduCfg()                                                      (TRUE != FALSE)
#define CanTp_HasTransmitCancellationOfTxSduCfg()                                                   (TRUE != FALSE)
#define CanTp_HasTxAddressOfTxSduCfg()                                                              (TRUE != FALSE)
#define CanTp_HasTxAddressingFormatOfTxSduCfg()                                                     (TRUE != FALSE)
#define CanTp_HasTxMaxPayloadLengthOfTxSduCfg()                                                     (TRUE != FALSE)
#define CanTp_HasTxPaddingActivationOfTxSduCfg()                                                    (TRUE != FALSE)
#define CanTp_HasTxPduConfirmationPduIdOfTxSduCfg()                                                 (TRUE != FALSE)
#define CanTp_HasTxTaTypeOfTxSduCfg()                                                               (TRUE != FALSE)
#define CanTp_HasTxSduCfgInd()                                                                      (TRUE != FALSE)
#define CanTp_HasTxSduSnv2Hdl()                                                                     (TRUE != FALSE)
#define CanTp_HasTxSduCfgIdxOfTxSduSnv2Hdl()                                                        (TRUE != FALSE)
#define CanTp_HasTxSduCfgUsedOfTxSduSnv2Hdl()                                                       (TRUE != FALSE)
#define CanTp_HasTxSemaphores()                                                                     (TRUE != FALSE)
#define CanTp_HasTxState()                                                                          (TRUE != FALSE)
#define CanTp_HasPCConfig()                                                                         (TRUE != FALSE)
#define CanTp_HasCalcBSOfPCConfig()                                                                 (TRUE != FALSE)
#define CanTp_HasCompatibilityVersionOfPCConfig()                                                   (TRUE != FALSE)
#define CanTp_HasRxPduMapOfPCConfig()                                                               (TRUE != FALSE)
#define CanTp_HasRxSduCfgIndOfPCConfig()                                                            (TRUE != FALSE)
#define CanTp_HasRxSduCfgOfPCConfig()                                                               (TRUE != FALSE)
#define CanTp_HasRxSduSnv2HdlOfPCConfig()                                                           (TRUE != FALSE)
#define CanTp_HasRxStateOfPCConfig()                                                                (TRUE != FALSE)
#define CanTp_HasSizeOfCalcBSOfPCConfig()                                                           (TRUE != FALSE)
#define CanTp_HasSizeOfRxPduMapOfPCConfig()                                                         (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduCfgIndOfPCConfig()                                                      (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduCfgOfPCConfig()                                                         (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduSnv2HdlOfPCConfig()                                                     (TRUE != FALSE)
#define CanTp_HasSizeOfRxStateOfPCConfig()                                                          (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduCfgIndOfPCConfig()                                                      (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduCfgOfPCConfig()                                                         (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduSnv2HdlOfPCConfig()                                                     (TRUE != FALSE)
#define CanTp_HasSizeOfTxSemaphoresOfPCConfig()                                                     (TRUE != FALSE)
#define CanTp_HasSizeOfTxStateOfPCConfig()                                                          (TRUE != FALSE)
#define CanTp_HasTxSduCfgIndOfPCConfig()                                                            (TRUE != FALSE)
#define CanTp_HasTxSduCfgOfPCConfig()                                                               (TRUE != FALSE)
#define CanTp_HasTxSduSnv2HdlOfPCConfig()                                                           (TRUE != FALSE)
#define CanTp_HasTxSemaphoresOfPCConfig()                                                           (TRUE != FALSE)
#define CanTp_HasTxStateOfPCConfig()                                                                (TRUE != FALSE)

#define CanTp_IncCalcBS(Index)                                                                      CanTp_GetCalcBS(Index)++
#define CanTp_IncRxState(Index)                                                                     CanTp_GetRxState(Index)++
#define CanTp_IncTxSemaphores(Index)                                                                CanTp_GetTxSemaphores(Index)++
#define CanTp_IncTxState(Index)                                                                     CanTp_GetTxState(Index)++

#define CanTp_DecCalcBS(Index)                                                                      CanTp_GetCalcBS(Index)--
#define CanTp_DecRxState(Index)                                                                     CanTp_GetRxState(Index)--
#define CanTp_DecTxSemaphores(Index)                                                                CanTp_GetTxSemaphores(Index)--
#define CanTp_DecTxState(Index)                                                                     CanTp_GetTxState(Index)--

#define CANTP_LTCONFIG                                                                              STD_OFF

#define CANTP_PBCONFIG                                                                              STD_OFF
#define CANTP_LTCONFIGIDXOFPBCONFIG                                                                 STD_OFF
#define CANTP_PCCONFIGIDXOFPBCONFIG                                                                 STD_OFF

#endif
