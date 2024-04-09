#if !defined(CANIF_CFG_H)
#define CANIF_CFG_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "McalCan.hpp"

#define CANIF_CFG5_VERSION                                 0x0411u
#define CANIF_CFG5_RELEASE_VERSION                         0x01u
#define IF_ASRIFCAN_GENTOOL_CFG5_MAJOR_VERSION             0x04u
#define IF_ASRIFCAN_GENTOOL_CFG5_MINOR_VERSION             0x11u
#define IF_ASRIFCAN_GENTOOL_CFG5_PATCH_VERSION             0x01u

#define CANIF_CFG5_GENERATOR_COMPATIBILITY_VERSION         0x0212u

#define EcuabCanIf_Transmit_BUFFER                              STD_ON
#define EcuabCanIf_Transmit_BUFFER_PRIO_BY_CANID                STD_ON
#define EcuabCanIf_Transmit_BUFFER_FIFO                         STD_OFF
#define CANIF_BITQUEUE                                     STD_OFF
#define CANIF_STATIC_FD_TXQUEUE                            STD_OFF
#define CANIF_WAKEUP_SUPPORT                               STD_OFF
#define CANIF_WAKEUP_VALIDATION                            STD_OFF
#define CANIF_WAKEUP_VALID_ALL_RX_MSGS                     STD_OFF
#define CANIF_WAKEUP_VALID_ONLY_NM_RX_MSGS                 STD_OFF
#define CANIF_DEV_ERROR_DETECT                             STD_ON
#define CANIF_DEV_ERROR_REPORT                             STD_ON
#define EcuabCanIf_Transmit_CANCELLATION                        STD_OFF
#define CANIF_CANCEL_SUPPORT_API                           STD_OFF
#define CANIF_VERSION_INFO_API                             STD_OFF
#define CANIF_DLC_CHECK                                    STD_OFF
#define CANIF_SUPPORT_NMOSEK_INDICATION                    STD_OFF
#define CANIF_TRCV_HANDLING                                STD_OFF
#define CANIF_TRCV_MAPPING                                 STD_OFF
#define CANIF_PN_TRCV_HANDLING                             STD_OFF
#define CANIF_EXTENDEDID_SUPPORT                           STD_OFF
#define CANIF_ONE_CONTROLLER_OPTIMIZATION                  STD_ON
#define CANIF_SETDYNAMICTXID_API                           STD_OFF
#define CANIF_PN_WU_TX_PDU_FILTER                          STD_OFF
#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT            STD_OFF
#define CANIF_RX_INDICATION_TYPE_I_IS_USED                 STD_OFF
#define CANIF_RX_INDICATION_TYPE_IV_IS_USED                STD_OFF
#define CANIF_CHANGE_BAUDRATE_SUPPORT                      STD_OFF
#define CANIF_SET_BAUDRATE_API                             STD_OFF
#define CANIF_META_DATA_RX_SUPPORT                         STD_OFF
#define CANIF_META_DATA_TX_SUPPORT                         STD_OFF
#define CANIF_J1939_DYN_ADDR_SUPPORT                       CANIF_J1939_DYN_ADDR_DISABLED
#define CANIF_MULTIPLE_CANDRV_SUPPORT                      STD_OFF
#define CANIF_RX_SEARCH_CONSIDER_MSG_TYPE                  STD_OFF
#define CANIF_ECUC_SAFE_BSW_CHECKS                         STD_OFF
#define CANIF_EXTENDED_RAM_CHECK_SUPPORT                   STD_OFF
#define CANIF_DATA_CHECKSUM_RX_SUPPORT                     STD_OFF
#define CANIF_DATA_CHECKSUM_TX_SUPPORT                     STD_OFF
#define CANIF_SET_PDU_RECEPTION_MODE_SUPPORT               STD_OFF
#define CANIF_BUS_MIRRORING_SUPPORT                        STD_OFF
#define CANIF_SUPPRESS_EXTENDED_VERSION_CHECK

#ifndef CANIF_USE_DUMMY_STATEMENT
#define CANIF_USE_DUMMY_STATEMENT STD_ON
#endif
#ifndef CANIF_DUMMY_STATEMENT
#define CANIF_DUMMY_STATEMENT(v) (v)=(v)
#endif
#ifndef CANIF_DUMMY_STATEMENT_CONST
#define CANIF_DUMMY_STATEMENT_CONST(v) (void)(v)
#endif
#ifndef CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF
#endif
#ifndef CANIF_ATOMIC_VARIABLE_ACCESS
#define CANIF_ATOMIC_VARIABLE_ACCESS 32u
#endif
#ifndef CANIF_PROCESSOR_RH850_1013
#define CANIF_PROCESSOR_RH850_1013
#endif
#ifndef CANIF_COMP_GREENHILLS
#define CANIF_COMP_GREENHILLS
#endif
#ifndef CANIF_GEN_GENERATOR_MSR
#define CANIF_GEN_GENERATOR_MSR
#endif
#ifndef CANIF_CPUTYPE_BITORDER_LSB2MSB
#define CANIF_CPUTYPE_BITORDER_LSB2MSB
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#define CANIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_LINKTIME
#define CANIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANIF_CONFIGURATION_VARIANT
#define CANIF_CONFIGURATION_VARIANT CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANIF_POSTBUILD_VARIANT_SUPPORT
#define CANIF_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#define CANIF_CPU_TYPE_SET_IN_ECUC_MODULE                  CPU_TYPE_32
#define CANIF_SEARCH_ALGORITHM                             CANIF_LINEAR
#define CANIF_CONFIG_VARIANT                               CANIF_CFGVAR_PRECOMPILETIME

typedef uint8 CanIf_TxBufferSizeType;

#include "Types_EcuabCanIf.hpp"

#define CANIF_XCFG                                         CANIF_CONST
#define CANIF_VAR_XCFG_NOINIT                              CANIF_VAR_NOINIT
#define CanIf_TxPduHnd_INVALID                             0xFFu
#define CanIf_RxPduHnd_INVALID                             0xFFu
#define CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID                                                             1u
#define CANIF_TXBUFFER_HANDLINGTYPE_FIFO                                                                    2u
#define CANIF_TXBUFFER_HANDLINGTYPE_NONE                                                                    3u
#define CanIfConf_CanIfCtrlCfg_CT_P1951001_0_003_01_24_RAJA_A1_V_b79a45a3                         0u
#define CanIfTxPduHnd_UDS_Tx_Physical_Tp_oP1951001_0_003_01_24_RAJA_A1_V_bbbad787_Tx              0u
#define CanIfTxPduHnd_BootId_oP1951001_0_003_01_24_RAJA_A1_V_4c4265eb_Tx                          1u
#define CanIfRxPduHnd_UDS_Rx_Functional_Tp_oP1951001_0_003_01_24_RAJA_A1_V_6536114b_Rx            0u
#define CanIfRxPduHnd_UDS_Rx_Physical_Tp_oP1951001_0_003_01_24_RAJA_A1_V_8c6ce0f5_Rx              1u
#define CanIfConf_CanIfTxPduCfg_UDS_Tx_Physical_Tp_oP1951001_0_003_01_24_RAJA_A1_V_bbbad787_Tx    0u
#define CanIfConf_CanIfTxPduCfg_BootId_oP1951001_0_003_01_24_RAJA_A1_V_4c4265eb_Tx                1u
#define CanIfConf_CanIfRxPduCfg_UDS_Rx_Functional_Tp_oP1951001_0_003_01_24_RAJA_A1_V_6536114b_Rx  0u
#define CanIfConf_CanIfRxPduCfg_UDS_Rx_Physical_Tp_oP1951001_0_003_01_24_RAJA_A1_V_8c6ce0f5_Rx    1u
#define CanIfTxBufferType                    BYTE_QUEUE
#define  EcuabCanIf_RxIndication(Hrh, CanId, CanDlc, CanSduPtr) EcuabCanIf_RxIndicationAsr403((Hrh), (CanId), (CanDlc), (CanSduPtr))
#define CANIF_CFG_MAXRXDLC_PLUS_MAXMETADATA     0u
#define CANIF_BUSOFFNOTIFICATIONFCTPTR                                STD_ON
#define CANIF_CANCHANNELIDUPTOLOWMAP                                  STD_OFF
#define CANIF_CANDRVFCTTBLIDXOFCANCHANNELIDUPTOLOWMAP                 STD_OFF
#define CANIF_CANDRVFCTTBLUSEDOFCANCHANNELIDUPTOLOWMAP                STD_OFF
#define CANIF_CHANNELINDEXOFCANCHANNELIDUPTOLOWMAP                    STD_OFF
#define CANIF_CANDRVFCTTBL                                            STD_OFF
#define CANIF_CANCELTXFCTOFCANDRVFCTTBL                               STD_OFF
#define CANIF_CHANGEBAUDRATEFCTOFCANDRVFCTTBL                         STD_OFF
#define CANIF_CHECKBAUDRATEFCTOFCANDRVFCTTBL                          STD_OFF
#define CANIF_CHECKWAKEUPFCTOFCANDRVFCTTBL                            STD_OFF
#define CANIF_GETCONTROLLERERRORSTATEFCTOFCANDRVFCTTBL                STD_OFF
#define CANIF_GETCONTROLLERRXERRORCOUNTEROFCANDRVFCTTBL               STD_OFF
#define CANIF_GETCONTROLLERTXERRORCOUNTEROFCANDRVFCTTBL               STD_OFF
#define CANIF_RAMCHECKENABLECONTROLLERFCTOFCANDRVFCTTBL               STD_OFF
#define CANIF_RAMCHECKENABLEMAILBOXFCTOFCANDRVFCTTBL                  STD_OFF
#define CANIF_RAMCHECKEXECUTEFCTOFCANDRVFCTTBL                        STD_OFF
#define CANIF_SETBAUDRATEFCTOFCANDRVFCTTBL                            STD_OFF
#define CANIF_SETCONTROLLERMODEFCTOFCANDRVFCTTBL                      STD_OFF
#define CANIF_WRITEFCTOFCANDRVFCTTBL                                  STD_OFF
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIG                       STD_ON
#define CANIF_INVALIDHNDOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG           STD_OFF
#define CANIF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_ON
#define CANIF_CANTRCVFCTTBL                                           STD_OFF
#define CANIF_CHECKWAKEFLAGFCTOFCANTRCVFCTTBL                         STD_OFF
#define CANIF_CHECKWAKEUPFCTOFCANTRCVFCTTBL                           STD_OFF
#define CANIF_CLEARTRCVWUFFLAGFCTOFCANTRCVFCTTBL                      STD_OFF
#define CANIF_GETBUSWUREASONFCTOFCANTRCVFCTTBL                        STD_OFF
#define CANIF_GETOPMODEFCTOFCANTRCVFCTTBL                             STD_OFF
#define CANIF_SETOPMODEFCTOFCANTRCVFCTTBL                             STD_OFF
#define CANIF_SETWAKEUPMODEFCTOFCANTRCVFCTTBL                         STD_OFF
#define CANIF_CTRLCONFIG                                              STD_OFF
#define CANIF_FEATUREPNWUTXPDUFILTERENABLEDOFCTRLCONFIG               STD_OFF
#define CANIF_J1939DYNADDROFFSETOFCTRLCONFIG                          STD_OFF
#define CANIF_J1939DYNADDRSUPPORTOFCTRLCONFIG                         STD_OFF
#define CANIF_RXDHRANDOMNUMBER1OFCTRLCONFIG                           STD_OFF
#define CANIF_RXDHRANDOMNUMBER2OFCTRLCONFIG                           STD_OFF
#define CANIF_CTRLMODEINDICATIONFCTPTR                                STD_ON
#define CANIF_CTRLSTATES                                              STD_ON
#define CANIF_CTRLMODEOFCTRLSTATES                                    STD_ON
#define CANIF_PDUMODEOFCTRLSTATES                                     STD_ON
#define CANIF_FINALMAGICNUMBER                                        STD_OFF
#define CANIF_GENERATORCOMPATIBILITYVERSION                           STD_ON
#define CANIF_GENERATORVERSION                                        STD_ON
#define CANIF_HXHOFFSET                                               STD_OFF
#define infEcuabCanIfSwcApplEcuM_InitFunctionDATAHASHCODE                                        STD_OFF
#define CANIF_MAILBOXCONFIG                                           STD_ON
#define CANIF_CTRLSTATESIDXOFMAILBOXCONFIG                            STD_ON
#define CANIF_MAILBOXTYPEOFMAILBOXCONFIG                              STD_ON
#define CANIF_PDUIDFIRSTOFMAILBOXCONFIG                               STD_ON
#define CANIF_PDUIDLASTOFMAILBOXCONFIG                                STD_ON
#define CANIF_TXBUFFERCFGIDXOFMAILBOXCONFIG                           STD_ON
#define CANIF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                          STD_ON
#define CANIF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                     STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIG                                   STD_ON
#define CANIF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                 STD_ON
#define CANIF_MAXVALIDRXDLC                                           STD_ON
#define CANIF_PDURXMODE                                               STD_OFF
#define CANIF_RXDHADJUST                                              STD_OFF
#define EcuabCanIf_RxIndicationFCTLIST                                     STD_ON
#define EcuabCanIf_RxIndicationFCTOFRXINDICATIONFCTLIST                    STD_ON
#define EcuabCanIf_RxIndicationLAYOUTOFRXINDICATIONFCTLIST                 STD_ON
#define CANIF_RXPDUCONFIG                                             STD_ON
#define CANIF_CANIFRXPDUIDOFRXPDUCONFIG                               STD_OFF
#define CANIF_DLCOFRXPDUCONFIG                                        STD_ON
#define CANIF_ISDATACHECKSUMRXPDUOFRXPDUCONFIG                        STD_OFF
#define CANIF_MSGTYPEOFRXPDUCONFIG                                    STD_OFF
#define EcuabCanIf_RxIndicationFCTLISTIDXOFRXPDUCONFIG                     STD_ON
#define CANIF_RXMETADATALENGTHOFRXPDUCONFIG                           STD_OFF
#define CANIF_RXPDUCANIDOFRXPDUCONFIG                                 STD_ON
#define CANIF_RXPDUMASKOFRXPDUCONFIG                                  STD_ON
#define CANIF_UPPERPDUIDOFRXPDUCONFIG                                 STD_ON
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                 STD_ON
#define CANIF_SIZEOFCTRLSTATES                                        STD_ON
#define CANIF_SIZEOFMAILBOXCONFIG                                     STD_ON
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIG                             STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLIST                               STD_ON
#define CANIF_SIZEOFRXPDUCONFIG                                       STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASE                           STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS          STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLIST                             STD_ON
#define CANIF_SIZEOFTXPDUCONFIG                                       STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEX                                   STD_ON
#define CANIF_SIZEOFTXQUEUE                                           STD_ON
#define CANIF_TRANSCEIVERUPTOLOWMAP                                   STD_OFF
#define CANIF_CANTRCVFCTTBLIDXOFTRANSCEIVERUPTOLOWMAP                 STD_OFF
#define CANIF_CHANNELINDEXOFTRANSCEIVERUPTOLOWMAP                     STD_OFF
#define CANIF_TRANSCEIVERUPTOUPPERMAP                                 STD_OFF
#define CANIF_TRCVTOCTRLMAP                                           STD_OFF
#define CANIF_TXBUFFERFIFOCONFIG                                      STD_OFF
#define CANIF_SIZEOFONEPAYLOADELOFTXBUFFERFIFOCONFIG                  STD_OFF
#define CANIF_TXBUFFERPRIOBYCANIDBASE                                 STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBITQUEUECONFIG                       STD_OFF
#define CANIF_BITPOS2TXPDUIDOFFSETOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG STD_OFF
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                      STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS                STD_ON
#define CANIF_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS STD_ON
#define EcuabCanIf_TxConfirmationFCTLIST                                   STD_ON
#define CANIF_TXPDUCONFIG                                             STD_ON
#define CANIF_CANIDOFTXPDUCONFIG                                      STD_ON
#define CANIF_CANIDTXMASKOFTXPDUCONFIG                                STD_OFF
#define CANIF_CTRLSTATESIDXOFTXPDUCONFIG                              STD_ON
#define CANIF_DLCOFTXPDUCONFIG                                        STD_ON
#define CANIF_ISDATACHECKSUMTXPDUOFTXPDUCONFIG                        STD_OFF
#define CANIF_MAILBOXCONFIGIDXOFTXPDUCONFIG                           STD_ON
#define EcuabCanIf_TxConfirmationFCTLISTIDXOFTXPDUCONFIG                   STD_ON
#define CANIF_TXMETADATALENGTHOFTXPDUCONFIG                           STD_OFF
#define CANIF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                          STD_ON
#define CANIF_TXPDUQUEUEINDEX                                         STD_ON
#define CANIF_TXQUEUEIDXOFTXPDUQUEUEINDEX                             STD_ON
#define CANIF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                            STD_ON
#define CANIF_TXPDUSTATIC2DYNAMICINDIRECTION                          STD_OFF
#define CANIF_TXQUEUE                                                 STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOP                              STD_OFF
#define CANIF_ULRXPDUID2INTERNALRXPDUID                               STD_OFF
#define CANIF_RXPDUCONFIGIDXOFULRXPDUID2INTERNALRXPDUID               STD_OFF
#define CANIF_RXPDUCONFIGUSEDOFULRXPDUID2INTERNALRXPDUID              STD_OFF
#define CANIF_ULTXPDUID2INTERNALTXPDUID                               STD_OFF
#define CANIF_WAKEUPCONFIG                                            STD_OFF
#define CANIF_CONTROLLEROFWAKEUPCONFIG                                STD_OFF
#define CANIF_WAKEUPSOURCEOFWAKEUPCONFIG                              STD_OFF
#define CANIF_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                       STD_OFF
#define CANIF_WAKEUPTARGETMODULEOFWAKEUPCONFIG                        STD_OFF
#define CANIF_PCCONFIG                                                STD_ON
#define CANIF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                      STD_ON
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG             STD_ON
#define CANIF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                      STD_ON
#define CANIF_CTRLSTATESOFPCCONFIG                                    STD_ON
#define CANIF_FINALMAGICNUMBEROFPCCONFIG                              STD_OFF
#define CANIF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                 STD_ON
#define CANIF_GENERATORVERSIONOFPCCONFIG                              STD_ON
#define infEcuabCanIfSwcApplEcuM_InitFunctionDATAHASHCODEOFPCCONFIG                              STD_OFF
#define CANIF_MAILBOXCONFIGOFPCCONFIG                                 STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                         STD_ON
#define CANIF_MAXVALIDRXDLCOFPCCONFIG                                 STD_ON
#define EcuabCanIf_RxIndicationFCTLISTOFPCCONFIG                           STD_ON
#define CANIF_RXPDUCONFIGOFPCCONFIG                                   STD_ON
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG       STD_ON
#define CANIF_SIZEOFCTRLSTATESOFPCCONFIG                              STD_ON
#define CANIF_SIZEOFMAILBOXCONFIGOFPCCONFIG                           STD_ON
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIGOFPCCONFIG                   STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLISTOFPCCONFIG                     STD_ON
#define CANIF_SIZEOFRXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASEOFPCCONFIG                 STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG      STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLISTOFPCCONFIG                   STD_ON
#define CANIF_SIZEOFTXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEXOFPCCONFIG                         STD_ON
#define CANIF_SIZEOFTXQUEUEOFPCCONFIG                                 STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                       STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG            STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG      STD_ON
#define EcuabCanIf_TxConfirmationFCTLISTOFPCCONFIG                         STD_ON
#define CANIF_TXPDUCONFIGOFPCCONFIG                                   STD_ON
#define CANIF_TXPDUQUEUEINDEXOFPCCONFIG                               STD_ON
#define CANIF_TXQUEUEOFPCCONFIG                                       STD_ON
#define CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG                        255u
#define CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX                          255u
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_OFF
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFMAILBOXCONFIG                      STD_OFF
#define CANIF_ISDEF_MAILBOXTYPEOFMAILBOXCONFIG                        STD_OFF
#define CANIF_ISDEF_PDUIDFIRSTOFMAILBOXCONFIG                         STD_OFF
#define CANIF_ISDEF_PDUIDLASTOFMAILBOXCONFIG                          STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGIDXOFMAILBOXCONFIG                     STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                    STD_OFF
#define CANIF_ISDEF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG               STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG           STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTOFRXINDICATIONFCTLIST              STD_OFF
#define CANIF_ISDEF_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST           STD_OFF
#define CANIF_ISDEF_DLCOFRXPDUCONFIG                                  STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG               STD_OFF
#define CANIF_ISDEF_RXPDUCANIDOFRXPDUCONFIG                           STD_OFF
#define CANIF_ISDEF_RXPDUMASKOFRXPDUCONFIG                            STD_OFF
#define CANIF_ISDEF_UPPERPDUIDOFRXPDUCONFIG                           STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLIST                             STD_OFF
#define CANIF_ISDEF_CANIDOFTXPDUCONFIG                                STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFTXPDUCONFIG                        STD_OFF
#define CANIF_ISDEF_DLCOFTXPDUCONFIG                                  STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFTXPDUCONFIG                     STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG             STD_OFF
#define CANIF_ISDEF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                    STD_OFF
#define CANIF_ISDEF_TXQUEUEIDXOFTXPDUQUEUEINDEX                       STD_OFF
#define CANIF_ISDEF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                      STD_OFF
#define CANIF_ISDEF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                STD_ON
#define CANIF_ISDEF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG       STD_ON
#define CANIF_ISDEF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                STD_ON
#define CANIF_ISDEF_CTRLSTATESOFPCCONFIG                              STD_ON
#define CANIF_ISDEF_MAILBOXCONFIGOFPCCONFIG                           STD_ON
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                   STD_ON
#define CANIF_ISDEF_RXINDICATIONFCTLISTOFPCCONFIG                     STD_ON
#define CANIF_ISDEF_RXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                 STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG      STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG STD_ON
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTOFPCCONFIG                   STD_ON
#define CANIF_ISDEF_TXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_ISDEF_TXPDUQUEUEINDEXOFPCCONFIG                         STD_ON
#define CANIF_ISDEF_TXQUEUEOFPCCONFIG                                 STD_ON
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG
#define CANIF_EQ2_CTRLSTATESIDXOFMAILBOXCONFIG
#define CANIF_EQ2_MAILBOXTYPEOFMAILBOXCONFIG
#define CANIF_EQ2_PDUIDFIRSTOFMAILBOXCONFIG
#define CANIF_EQ2_PDUIDLASTOFMAILBOXCONFIG
#define CANIF_EQ2_TXBUFFERCFGIDXOFMAILBOXCONFIG
#define CANIF_EQ2_TXBUFFERCFGUSEDOFMAILBOXCONFIG
#define CANIF_EQ2_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG
#define CANIF_EQ2_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG
#define CANIF_EQ2_RXINDICATIONFCTOFRXINDICATIONFCTLIST
#define CANIF_EQ2_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST
#define CANIF_EQ2_DLCOFRXPDUCONFIG
#define CANIF_EQ2_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG
#define CANIF_EQ2_RXPDUCANIDOFRXPDUCONFIG
#define CANIF_EQ2_RXPDUMASKOFRXPDUCONFIG
#define CANIF_EQ2_UPPERPDUIDOFRXPDUCONFIG
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG
#define CANIF_EQ2_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS
#define CANIF_EQ2_TXCONFIRMATIONFCTLIST
#define CANIF_EQ2_CANIDOFTXPDUCONFIG
#define CANIF_EQ2_CTRLSTATESIDXOFTXPDUCONFIG
#define CANIF_EQ2_DLCOFTXPDUCONFIG
#define CANIF_EQ2_MAILBOXCONFIGIDXOFTXPDUCONFIG
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG
#define CANIF_EQ2_UPPERLAYERTXPDUIDOFTXPDUCONFIG
#define CANIF_EQ2_TXQUEUEIDXOFTXPDUQUEUEINDEX
#define CANIF_EQ2_TXQUEUEUSEDOFTXPDUQUEUEINDEX
#define CANIF_EQ2_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                  CfgEcuabCanIf_fptrNotificationBusOff
#define CANIF_EQ2_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG         CfgEcuabCanIf_IdCtrl2MappedBuffersTx
#define CANIF_EQ2_CTRLMODEINDICATIONFCTPTROFPCCONFIG                  CanIf_CtrlModeIndicationFctPtr
#define CANIF_EQ2_CTRLSTATESOFPCCONFIG                                EcuabCanIf_StatesCtrl.raw
#define CANIF_EQ2_MAILBOXCONFIGOFPCCONFIG                             CfgEcuabCanIf_MailBox
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                     CfgEcuabCanIf_BuffersTxMapped
#define CANIF_EQ2_RXINDICATIONFCTLISTOFPCCONFIG                       CfgEcuabCanIf_ListFctIndicationRx
#define CANIF_EQ2_RXPDUCONFIGOFPCCONFIG                               CfgEcuabCanIf_PduRx
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                   EcuabCanIf_BufferTxPrioByIdCanBase.raw
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG        CfgEcuabCanIf_QueueBufferTxPrioByIdCan
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG  CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCan
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTOFPCCONFIG                     EcuabCanIf_ListFctConfirmationTx
#define CANIF_EQ2_TXPDUCONFIGOFPCCONFIG                               EcuabCanIf_PduTx
#define CANIF_EQ2_TXPDUQUEUEINDEXOFPCCONFIG                           EcuabCanIf_IndexQueuePduTx
#define CANIF_EQ2_TXQUEUEOFPCCONFIG                                   EcuabCanIf_QueueTx.raw
#define CanIf_Config_Ptr                                              NULL_PTR
#define CanIf_Config                                                  NULL_PTR
#define CANIF_CHECK_INIT_POINTER                                      STD_OFF
#define CANIF_FINAL_MAGIC_NUMBER                                      0x3C1Eu
#define CANIF_INDIVIDUAL_POSTBUILD                                    STD_OFF
#define infEcuabCanIfSwcApplEcuM_InitFunction_DATA                                               CANIF_CONST
#define infEcuabCanIfSwcApplEcuM_InitFunction_DATA_HASH_CODE                                     -713533440
#define CANIF_USE_ECUM_BSW_ERROR_HOOK                                 STD_OFF
#define CANIF_USE_INIT_POINTER                                        STD_OFF
#define CANIF_LTCONFIG                                                STD_OFF
#define CANIF_PBCONFIG                                                STD_OFF
#define CANIF_LTCONFIGIDXOFPBCONFIG                                   STD_OFF
#define CANIF_PCCONFIGIDXOFPBCONFIG                                   STD_OFF
#define CanIf_GetBusOffNotificationFctPtrOfPCConfig()                 CfgEcuabCanIf_fptrNotificationBusOff
#define CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()        CfgEcuabCanIf_IdCtrl2MappedBuffersTx
#define CanIf_GetCtrlModeIndicationFctPtrOfPCConfig()                 CanIf_CtrlModeIndicationFctPtr
#define CanIf_GetCtrlStatesOfPCConfig()                               EcuabCanIf_StatesCtrl.raw
#define CanIf_GetGeneratorCompatibilityVersionOfPCConfig()            0x0212u
#define CanIf_GetGeneratorVersionOfPCConfig()                         0x00041101u
#define CanIf_GetMailBoxConfigOfPCConfig()                            CfgEcuabCanIf_MailBox
#define CanIf_GetMappedTxBuffersConfigOfPCConfig()                    CfgEcuabCanIf_BuffersTxMapped
#define CanIf_GetMaxValidRxDlcOfPCConfig()                            8u
#define CanIf_GetRxIndicationFctListOfPCConfig()                      CfgEcuabCanIf_ListFctIndicationRx
#define CanIf_GetRxPduConfigOfPCConfig()                              CfgEcuabCanIf_PduRx
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()  1u
#define CanIf_GetSizeOfCtrlStatesOfPCConfig()                         1u
#define CanIf_GetSizeOfMailBoxConfigOfPCConfig()                      2u
#define CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()              1u
#define CanIf_GetSizeOfRxIndicationFctListOfPCConfig()                2u
#define CanIf_GetSizeOfRxPduConfigOfPCConfig()                        2u
#define CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()            1u
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig() 1u
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() 2u
#define CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()              3u
#define CanIf_GetSizeOfTxPduConfigOfPCConfig()                        2u
#define CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()                    2u
#define CanIf_GetSizeOfTxQueueOfPCConfig()                            2u
#define CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()                  EcuabCanIf_BufferTxPrioByIdCanBase.raw
#define CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()       CfgEcuabCanIf_QueueBufferTxPrioByIdCan
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCan
#define CanIf_GetTxConfirmationFctListOfPCConfig()                    EcuabCanIf_ListFctConfirmationTx
#define CanIf_GetTxPduConfigOfPCConfig()                              EcuabCanIf_PduTx
#define CanIf_GetTxPduQueueIndexOfPCConfig()                          EcuabCanIf_IndexQueuePduTx
#define CanIf_GetTxQueueOfPCConfig()                                  EcuabCanIf_QueueTx.raw
#define CanIf_GetBusOffNotificationFctPtr()                           (CanIf_GetBusOffNotificationFctPtrOfPCConfig())
#define CanIf_GetMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index) (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index) (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetCtrlModeIndicationFctPtr()                           (CanIf_GetCtrlModeIndicationFctPtrOfPCConfig())
#define CanIf_GetCtrlModeOfCtrlStates(Index)                          (CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates)
#define CanIf_GetPduModeOfCtrlStates(Index)                           (CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates)
#define CanIf_GetCtrlStatesIdxOfMailBoxConfig(Index)                  (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].CtrlStatesIdxOfMailBoxConfig)
#define CanIf_GetMailBoxTypeOfMailBoxConfig(Index)                    (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].MailBoxTypeOfMailBoxConfig)
#define CanIf_GetPduIdFirstOfMailBoxConfig(Index)                     (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdFirstOfMailBoxConfig)
#define CanIf_GetPduIdLastOfMailBoxConfig(Index)                      (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdLastOfMailBoxConfig)
#define CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index)                 (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferCfgIdxOfMailBoxConfig)
#define CanIf_GetTxBufferHandlingTypeOfMailBoxConfig(Index)           (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferHandlingTypeOfMailBoxConfig)
#define CanIf_GetMailBoxConfigIdxOfMappedTxBuffersConfig(Index)       (CanIf_GetMappedTxBuffersConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfMappedTxBuffersConfig)
#define CanIf_GetRxIndicationFctOfRxIndicationFctList(Index)          (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationFctOfRxIndicationFctList)
#define CanIf_GetRxIndicationLayoutOfRxIndicationFctList(Index)       (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationLayoutOfRxIndicationFctList)
#define CanIf_GetDlcOfRxPduConfig(Index)                              (CanIf_GetRxPduConfigOfPCConfig()[(Index)].DlcOfRxPduConfig)
#define CanIf_GetRxIndicationFctListIdxOfRxPduConfig(Index)           (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxIndicationFctListIdxOfRxPduConfig)
#define CanIf_GetRxPduCanIdOfRxPduConfig(Index)                       (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduCanIdOfRxPduConfig)
#define CanIf_GetRxPduMaskOfRxPduConfig(Index)                        (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduMaskOfRxPduConfig)
#define CanIf_GetUpperPduIdOfRxPduConfig(Index)                       (CanIf_GetRxPduConfigOfPCConfig()[(Index)].UpperPduIdOfRxPduConfig)
#define CanIf_GetTxBufferPrioByCanIdBase(Index)                       (CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)])
#define CanIf_GetTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()[(Index)].TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus)
#define CanIf_GetTxConfirmationFctList(Index)                         (CanIf_GetTxConfirmationFctListOfPCConfig()[(Index)])
#define CanIf_GetCanIdOfTxPduConfig(Index)                            (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CanIdOfTxPduConfig)
#define CanIf_GetCtrlStatesIdxOfTxPduConfig(Index)                    (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CtrlStatesIdxOfTxPduConfig)
#define CanIf_GetDlcOfTxPduConfig(Index)                              (CanIf_GetTxPduConfigOfPCConfig()[(Index)].DlcOfTxPduConfig)
#define CanIf_GetMailBoxConfigIdxOfTxPduConfig(Index)                 (CanIf_GetTxPduConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfTxPduConfig)
#define CanIf_GetTxConfirmationFctListIdxOfTxPduConfig(Index)         (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxConfirmationFctListIdxOfTxPduConfig)
#define CanIf_GetUpperLayerTxPduIdOfTxPduConfig(Index)                (CanIf_GetTxPduConfigOfPCConfig()[(Index)].UpperLayerTxPduIdOfTxPduConfig)
#define CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index)                   (CanIf_GetTxPduQueueIndexOfPCConfig()[(Index)].TxQueueIdxOfTxPduQueueIndex)
#define CanIf_GetTxQueue(Index)                                       (CanIf_GetTxQueueOfPCConfig()[(Index)])
#define CanIf_GetGeneratorCompatibilityVersion()                      CanIf_GetGeneratorCompatibilityVersionOfPCConfig()
#define CanIf_GetGeneratorVersion()                                   CanIf_GetGeneratorVersionOfPCConfig()
#define CanIf_IsTxBufferCfgUsedOfMailBoxConfig(Index)                 (((boolean)(CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index) != CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG)) != FALSE)
#define CanIf_GetMaxValidRxDlc()                                      CanIf_GetMaxValidRxDlcOfPCConfig()
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfig()            CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfCtrlStates()                                   CanIf_GetSizeOfCtrlStatesOfPCConfig()
#define CanIf_GetSizeOfMailBoxConfig()                                CanIf_GetSizeOfMailBoxConfigOfPCConfig()
#define CanIf_GetSizeOfMappedTxBuffersConfig()                        CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfRxIndicationFctList()                          CanIf_GetSizeOfRxIndicationFctListOfPCConfig()
#define CanIf_GetSizeOfRxPduConfig()                                  CanIf_GetSizeOfRxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdBase()                      CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfig()           CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus()     CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()
#define CanIf_GetSizeOfTxConfirmationFctList()                        CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()
#define CanIf_GetSizeOfTxPduConfig()                                  CanIf_GetSizeOfTxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTxPduQueueIndex()                              CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()
#define CanIf_GetSizeOfTxQueue()                                      CanIf_GetSizeOfTxQueueOfPCConfig()
#define CanIf_IsTxQueueUsedOfTxPduQueueIndex(Index)                   (((boolean)(CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index) != CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX)) != FALSE)
#define CanIf_SetCtrlModeOfCtrlStates(Index, Value)                   CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates = (Value)
#define CanIf_SetPduModeOfCtrlStates(Index, Value)                    CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates = (Value)
#define CanIf_SetTxBufferPrioByCanIdBase(Index, Value)                CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxQueue(Index, Value)                                CanIf_GetTxQueueOfPCConfig()[(Index)] = (Value)
#define CanIf_HasBusOffNotificationFctPtr()                           (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfig()                  (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig() (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig() (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtr()                           (TRUE != FALSE)
#define CanIf_HasCtrlStates()                                         (TRUE != FALSE)
#define CanIf_HasCtrlModeOfCtrlStates()                               (TRUE != FALSE)
#define CanIf_HasPduModeOfCtrlStates()                                (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersion()                      (TRUE != FALSE)
#define CanIf_HasGeneratorVersion()                                   (TRUE != FALSE)
#define CanIf_HasMailBoxConfig()                                      (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfMailBoxConfig()                       (TRUE != FALSE)
#define CanIf_HasMailBoxTypeOfMailBoxConfig()                         (TRUE != FALSE)
#define CanIf_HasPduIdFirstOfMailBoxConfig()                          (TRUE != FALSE)
#define CanIf_HasPduIdLastOfMailBoxConfig()                           (TRUE != FALSE)
#define CanIf_HasTxBufferCfgIdxOfMailBoxConfig()                      (TRUE != FALSE)
#define CanIf_HasTxBufferCfgUsedOfMailBoxConfig()                     (TRUE != FALSE)
#define CanIf_HasTxBufferHandlingTypeOfMailBoxConfig()                (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfig()                              (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfMappedTxBuffersConfig()            (TRUE != FALSE)
#define CanIf_HasMaxValidRxDlc()                                      (TRUE != FALSE)
#define CanIf_HasRxIndicationFctList()                                (TRUE != FALSE)
#define CanIf_HasRxIndicationFctOfRxIndicationFctList()               (TRUE != FALSE)
#define CanIf_HasRxIndicationLayoutOfRxIndicationFctList()            (TRUE != FALSE)
#define CanIf_HasRxPduConfig()                                        (TRUE != FALSE)
#define CanIf_HasDlcOfRxPduConfig()                                   (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListIdxOfRxPduConfig()                (TRUE != FALSE)
#define CanIf_HasRxPduCanIdOfRxPduConfig()                            (TRUE != FALSE)
#define CanIf_HasRxPduMaskOfRxPduConfig()                             (TRUE != FALSE)
#define CanIf_HasUpperPduIdOfRxPduConfig()                            (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfig()            (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStates()                                   (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfig()                                (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctList()                          (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfig()                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBase()                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueConfig()           (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus()     (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctList()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfig()                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndex()                              (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueue()                                      (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBase()                            (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueConfig()                 (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdus()           (TRUE != FALSE)
#define CanIf_HasTxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus() (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctList()                              (TRUE != FALSE)
#define CanIf_HasTxPduConfig()                                        (TRUE != FALSE)
#define CanIf_HasCanIdOfTxPduConfig()                                 (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfTxPduConfig()                         (TRUE != FALSE)
#define CanIf_HasDlcOfTxPduConfig()                                   (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfTxPduConfig()                      (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListIdxOfTxPduConfig()              (TRUE != FALSE)
#define CanIf_HasUpperLayerTxPduIdOfTxPduConfig()                     (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndex()                                    (TRUE != FALSE)
#define CanIf_HasTxQueueIdxOfTxPduQueueIndex()                        (TRUE != FALSE)
#define CanIf_HasTxQueueUsedOfTxPduQueueIndex()                       (TRUE != FALSE)
#define CanIf_HasTxQueue()                                            (TRUE != FALSE)
#define CanIf_HasPCConfig()                                           (TRUE != FALSE)
#define CanIf_HasBusOffNotificationFctPtrOfPCConfig()                 (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()        (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtrOfPCConfig()                 (TRUE != FALSE)
#define CanIf_HasCtrlStatesOfPCConfig()                               (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersionOfPCConfig()            (TRUE != FALSE)
#define CanIf_HasGeneratorVersionOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasMailBoxConfigOfPCConfig()                            (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigOfPCConfig()                    (TRUE != FALSE)
#define CanIf_HasMaxValidRxDlcOfPCConfig()                            (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListOfPCConfig()                      (TRUE != FALSE)
#define CanIf_HasRxPduConfigOfPCConfig()                              (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()  (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStatesOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfigOfPCConfig()                      (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfigOfPCConfig()              (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctListOfPCConfig()                (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfigOfPCConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBaseOfPCConfig()            (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig() (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctListOfPCConfig()              (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfigOfPCConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndexOfPCConfig()                    (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueOfPCConfig()                            (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseOfPCConfig()                  (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueConfigOfPCConfig()       (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListOfPCConfig()                    (TRUE != FALSE)
#define CanIf_HasTxPduConfigOfPCConfig()                              (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndexOfPCConfig()                          (TRUE != FALSE)
#define CanIf_HasTxQueueOfPCConfig()                                  (TRUE != FALSE)
#define CanIf_IncCtrlModeOfCtrlStates(Index)                          CanIf_GetCtrlModeOfCtrlStates(Index)++
#define CanIf_IncPduModeOfCtrlStates(Index)                           CanIf_GetPduModeOfCtrlStates(Index)++
#define CanIf_IncTxBufferPrioByCanIdBase(Index)                       CanIf_GetTxBufferPrioByCanIdBase(Index)++
#define CanIf_IncTxQueue(Index)                                       CanIf_GetTxQueue(Index)++
#define CanIf_DecCtrlModeOfCtrlStates(Index)                          CanIf_GetCtrlModeOfCtrlStates(Index)--
#define CanIf_DecPduModeOfCtrlStates(Index)                           CanIf_GetPduModeOfCtrlStates(Index)--
#define CanIf_DecTxBufferPrioByCanIdBase(Index)                       CanIf_GetTxBufferPrioByCanIdBase(Index)--
#define CanIf_DecTxQueue(Index)                                       CanIf_GetTxQueue(Index)--

typedef uint8_least Type_CfgEcuabCanIf_IdCtrl2MappedBuffersTxIter;
typedef uint8_least Type_CfgEcuabCanIf_StatesCtrlIter;
typedef uint8_least Type_CfgEcuabCanIf_MailBoxIter;
typedef uint8_least Type_CfgEcuabCanIf_BuffersTxMappedIter;
typedef uint8_least Type_CfgEcuabCanIf_ListFctIndicationRxIter;
typedef uint8_least Type_CfgEcuabCanIf_PduRxIter;
typedef uint8_least Type_CfgEcuabCanIf_BufferTxPrioByIdCanBaseIter;
typedef uint8_least Type_CfgEcuabCanIf_QueueBufferTxPrioByIdCanIter;
typedef uint8_least Type_CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCanIter;
typedef uint8_least Type_CfgEcuabCanIf_ListFctConfirmationTxIter;
typedef uint8_least Type_CfgEcuabCanIf_PduTxIter;
typedef uint8_least Type_CfgEcuabCanIf_IndexQueuePduTxIter;
typedef uint8_least Type_CfgEcuabCanIf_QueueTxIter;
typedef uint8       Type_CfgEcuabCanIf_BuffersTxMappedEndIdxOfCanIfCtrlId2MappedTxBuffers;
typedef uint8       Type_CfgEcuabCanIf_BuffersTxMappedStartIdxOfCanIfCtrlId2MappedTxBuffers;
typedef uint16      Type_CfgEcuabCanIf_GeneratorCompatibilityVersion;
typedef uint32      Type_CfgEcuabCanIf_GeneratorVersion;
typedef uint8       Type_CfgEcuabCanIf_StatesCtrlIdxOfMailBox;
typedef uint8       Type_CfgEcuabCanIf_PduIdFirstOfMailBox;
typedef uint8       Type_CfgEcuabCanIf_PduIdLastOfMailBox;
typedef uint8       Type_EcuabCanIf_TxBufferCfgIdxOfMailBox;
typedef boolean     Type_EcuabCanIf_TxBufferCfgUsedOfMailBox;
typedef uint8       Type_EcuabCanIf_TxBufferHandlingTypeOfMailBox;
typedef uint8       Type_CfgEcuabCanIf_MailBoxIdxOfMappedTxBuffers;
typedef uint8       Type_CfgEcuabCanIf_MaxValidRxDlc;
typedef uint8       CanIf_DlcOfRxPduConfigType;
typedef uint8       CfgEcuabCanIf_ListFctIndicationRxIdxOfRxPduConfigType;
typedef uint16      CanIf_RxPduCanIdOfRxPduConfigType;
typedef uint16      CanIf_RxPduMaskOfRxPduConfigType;
typedef PduIdType   CanIf_UpperPduIdOfRxPduConfigType;
typedef uint8       CanIf_SizeOfCanIfCtrlId2MappedTxBuffersConfigType;
typedef uint8       CanIf_SizeOfCtrlStatesType;
typedef uint8       CanIf_SizeOfMailBoxConfigType;
typedef uint8       CanIf_SizeOfMappedTxBuffersConfigType;
typedef uint8       CanIf_SizeOfRxIndicationFctListType;
typedef uint8       CanIf_SizeOfRxPduConfigType;
typedef uint8       CanIf_SizeOfTxBufferPrioByCanIdBaseType;
typedef uint8       CanIf_SizeOfTxBufferPrioByCanIdByteQueueConfigType;
typedef uint8       CanIf_SizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusType;
typedef uint8       CanIf_SizeOfTxConfirmationFctListType;
typedef uint8       CanIf_SizeOfTxPduConfigType;
typedef uint8       CanIf_SizeOfTxPduQueueIndexType;
typedef uint8       CanIf_SizeOfTxQueueType;
typedef uint8       EcuabCanIf_BufferTxPrioByIdCanBaseIdxOfTxBufferPrioByCanIdByteQueueConfigType;
typedef uint8       CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCanEndIdxOfTxBufferPrioByCanIdByteQueueConfigType;
typedef uint8       CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCanLengthOfTxBufferPrioByCanIdByteQueueConfigType;
typedef uint8       CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCanStartIdxOfTxBufferPrioByCanIdByteQueueConfigType;
typedef uint8       EcuabCanIf_PduTxIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdusType;
typedef uint16      CanIf_CanIdOfTxPduConfigType;
typedef uint8       EcuabCanIf_StatesCtrlIdxOfTxPduConfigType;
typedef uint8       CanIf_DlcOfTxPduConfigType;
typedef uint8       CfgEcuabCanIf_MailBoxIdxOfTxPduConfigType;
typedef uint8       EcuabCanIf_ListFctConfirmationTxIdxOfTxPduConfigType;
typedef PduIdType   CanIf_UpperLayerTxPduIdOfTxPduConfigType;
typedef uint8       EcuabCanIf_QueueTxIdxOfTxPduQueueIndexType;
typedef boolean     EcuabCanIf_QueueTxUsedOfTxPduQueueIndexType;

typedef struct sType_CfgEcuabCanIf_IdCtrl2MappedBuffersTx{
  Type_CfgEcuabCanIf_BuffersTxMappedEndIdxOfCanIfCtrlId2MappedTxBuffers MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig;
  Type_CfgEcuabCanIf_BuffersTxMappedStartIdxOfCanIfCtrlId2MappedTxBuffers MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig;
}Type_CfgEcuabCanIf_IdCtrl2MappedBuffersTx;

typedef struct sEcuabCanIf_StatesCtrlType{
  CanIf_ControllerModeType CtrlModeOfCtrlStates;
  CanIf_PduGetModeType PduModeOfCtrlStates;
}EcuabCanIf_StatesCtrlType;

typedef struct sType_CfgEcuabCanIf_MailBox{
  Type_CfgEcuabCanIf_StatesCtrlIdxOfMailBox CtrlStatesIdxOfMailBoxConfig;
  Type_CfgEcuabCanIf_PduIdFirstOfMailBox PduIdFirstOfMailBoxConfig;
  Type_CfgEcuabCanIf_PduIdLastOfMailBox PduIdLastOfMailBoxConfig;
  Type_EcuabCanIf_TxBufferCfgIdxOfMailBox TxBufferCfgIdxOfMailBoxConfig;
  Type_EcuabCanIf_TxBufferHandlingTypeOfMailBox TxBufferHandlingTypeOfMailBoxConfig;
  CanIf_MailBoxTypeType MailBoxTypeOfMailBoxConfig;
}Type_CfgEcuabCanIf_MailBox;

typedef struct sType_CfgEcuabCanIf_BuffersTxMapped{
  Type_CfgEcuabCanIf_MailBoxIdxOfMappedTxBuffers MailBoxConfigIdxOfMappedTxBuffersConfig;
}Type_CfgEcuabCanIf_BuffersTxMapped;

typedef struct sType_CfgEcuabCanIf_ListFctIndicationRx{
  EcuabCanIf_RxIndicationFctType RxIndicationFctOfRxIndicationFctList;
  EcuabCanIf_RxIndicationLayoutType RxIndicationLayoutOfRxIndicationFctList;
}Type_CfgEcuabCanIf_ListFctIndicationRx;

typedef struct sType_CfgEcuabCanIf_PduRx{
  CanIf_RxPduCanIdOfRxPduConfigType RxPduCanIdOfRxPduConfig;
  CanIf_RxPduMaskOfRxPduConfigType RxPduMaskOfRxPduConfig;
  CanIf_UpperPduIdOfRxPduConfigType UpperPduIdOfRxPduConfig;
  CanIf_DlcOfRxPduConfigType DlcOfRxPduConfig;
  CfgEcuabCanIf_ListFctIndicationRxIdxOfRxPduConfigType RxIndicationFctListIdxOfRxPduConfig;
}Type_CfgEcuabCanIf_PduRx;

typedef struct sType_CfgEcuabCanIf_QueueBufferTxPrioByIdCan{
  EcuabCanIf_BufferTxPrioByIdCanBaseIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig;
  CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCanEndIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig;
  CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCanLengthOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig;
  CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCanStartIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig;
}Type_CfgEcuabCanIf_QueueBufferTxPrioByIdCan;

typedef struct sType_CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCan{
  EcuabCanIf_PduTxIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdusType TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus;
}Type_CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCan;

typedef struct sType_EcuabCanIf_PduTx{
  CanIf_CanIdOfTxPduConfigType CanIdOfTxPduConfig;
  CanIf_UpperLayerTxPduIdOfTxPduConfigType UpperLayerTxPduIdOfTxPduConfig;
  EcuabCanIf_StatesCtrlIdxOfTxPduConfigType CtrlStatesIdxOfTxPduConfig;
  CanIf_DlcOfTxPduConfigType DlcOfTxPduConfig;
  CfgEcuabCanIf_MailBoxIdxOfTxPduConfigType MailBoxConfigIdxOfTxPduConfig;
  EcuabCanIf_ListFctConfirmationTxIdxOfTxPduConfigType TxConfirmationFctListIdxOfTxPduConfig;
}Type_EcuabCanIf_PduTx;

typedef struct sType_EcuabCanIf_IndexQueuePduTx{
  EcuabCanIf_QueueTxIdxOfTxPduQueueIndexType TxQueueIdxOfTxPduQueueIndex;
}Type_EcuabCanIf_IndexQueuePduTx;

typedef struct EcuabCanIf_StatesCtrlStructSTag{
  EcuabCanIf_StatesCtrlType CT_P1951001_0_003_01_24_RAJA_A1_V_b79a45a3;
}EcuabCanIf_StatesCtrlStructSType;

typedef struct EcuabCanIf_BufferTxPrioByIdCanBaseStructSTag{
  EcuabCanIf_BufferTxPrioByIdCanBaseType CHNL_86b53749;
}EcuabCanIf_BufferTxPrioByIdCanBaseStructSType;

typedef struct EcuabCanIf_QueueTxStructSTag{
  CanIf_TxPrioByCanIdByteQueueType UDS_Tx_Physical_Tp_oP1951001_0_003_01_24_RAJA_A1_V_bbbad787_Tx;
  CanIf_TxPrioByCanIdByteQueueType BootId_oP1951001_0_003_01_24_RAJA_A1_V_4c4265eb_Tx;
}EcuabCanIf_QueueTxStructSType;

typedef union EcuabCanIf_StatesCtrlUTag{
  EcuabCanIf_StatesCtrlType raw[1];
  EcuabCanIf_StatesCtrlStructSType str;
}Type_EcuabCanIf_StatesCtrl;

typedef union EcuabCanIf_BufferTxPrioByIdCanBaseUTag{
  EcuabCanIf_BufferTxPrioByIdCanBaseType raw[1];
  EcuabCanIf_BufferTxPrioByIdCanBaseStructSType str;
}Type_EcuabCanIf_BufferTxPrioByIdCanBase;

typedef union EcuabCanIf_QueueTxUTag{
  CanIf_TxPrioByCanIdByteQueueType raw[2];
  EcuabCanIf_QueueTxStructSType str;
}Type_EcuabCanIf_QueueTx;

typedef P2CONST(Type_CfgEcuabCanIf_IdCtrl2MappedBuffersTx, TYPEDEF, CANIF_CONST) CfgEcuabCanIf_IdCtrl2MappedBuffersTxPtrType;
typedef P2VAR(EcuabCanIf_StatesCtrlType, TYPEDEF, CANIF_VAR_NOINIT) EcuabCanIf_StatesCtrlPtrType;
typedef P2CONST(Type_CfgEcuabCanIf_MailBox, TYPEDEF, CANIF_CONST) CfgEcuabCanIf_MailBoxPtrType;
typedef P2CONST(Type_CfgEcuabCanIf_BuffersTxMapped, TYPEDEF, CANIF_CONST) CfgEcuabCanIf_BuffersTxMappedPtrType;
typedef P2CONST(Type_CfgEcuabCanIf_ListFctIndicationRx, TYPEDEF, CANIF_CONST) CfgEcuabCanIf_ListFctIndicationRxPtrType;
typedef P2CONST(Type_CfgEcuabCanIf_PduRx, TYPEDEF, CANIF_CONST) CfgEcuabCanIf_PduRxPtrType;
typedef P2VAR(EcuabCanIf_BufferTxPrioByIdCanBaseType, TYPEDEF, CANIF_VAR_NOINIT) EcuabCanIf_BufferTxPrioByIdCanBasePtrType;
typedef P2CONST(Type_CfgEcuabCanIf_QueueBufferTxPrioByIdCan, TYPEDEF, CANIF_CONST) CfgEcuabCanIf_QueueBufferTxPrioByIdCanPtrType;
typedef P2CONST(Type_CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCan, TYPEDEF, CANIF_CONST) CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCanPtrType;
typedef P2CONST(Type_EcuabCanIf_FctConfirmationTx, TYPEDEF, CANIF_CONST) EcuabCanIf_ListFctConfirmationTxPtrType;
typedef P2CONST(Type_EcuabCanIf_PduTx, TYPEDEF, CANIF_CONST) EcuabCanIf_PduTxPtrType;
typedef P2CONST(Type_EcuabCanIf_IndexQueuePduTx, TYPEDEF, CANIF_CONST) EcuabCanIf_IndexQueuePduTxPtrType;
typedef P2VAR(CanIf_TxPrioByCanIdByteQueueType, TYPEDEF, CANIF_VAR_NOINIT) EcuabCanIf_QueueTxPtrType;

typedef struct sCanIf_PCConfigType{
  uint8 CanIf_PCConfigNeverUsed;
}CanIf_PCConfigType;

typedef CanIf_PCConfigType CanIf_ConfigType;

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Type_CfgEcuabCanIf_FctNotificationBusOff, CANIF_CONST) CfgEcuabCanIf_fptrNotificationBusOff;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Type_CfgEcuabCanIf_IdCtrl2MappedBuffersTx, CANIF_CONST) CfgEcuabCanIf_IdCtrl2MappedBuffersTx[1];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Type_CfgEcuabCanIf_MailBox, CANIF_CONST) CfgEcuabCanIf_MailBox[2];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Type_CfgEcuabCanIf_BuffersTxMapped, CANIF_CONST) CfgEcuabCanIf_BuffersTxMapped[1];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Type_CfgEcuabCanIf_ListFctIndicationRx, CANIF_CONST) CfgEcuabCanIf_ListFctIndicationRx[2];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Type_CfgEcuabCanIf_PduRx, CANIF_CONST) CfgEcuabCanIf_PduRx[2];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Type_CfgEcuabCanIf_QueueBufferTxPrioByIdCan, CANIF_CONST) CfgEcuabCanIf_QueueBufferTxPrioByIdCan[1];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Type_CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCan, CANIF_CONST) CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCan[2];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Type_EcuabCanIf_FctConfirmationTx, CANIF_CONST) EcuabCanIf_ListFctConfirmationTx[3];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Type_EcuabCanIf_PduTx, CANIF_CONST) EcuabCanIf_PduTx[2];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Type_EcuabCanIf_IndexQueuePduTx, CANIF_CONST) EcuabCanIf_IndexQueuePduTx[2];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"
extern VAR(Type_EcuabCanIf_StatesCtrl, CANIF_VAR_NOINIT) EcuabCanIf_StatesCtrl;
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"
extern VAR(Type_EcuabCanIf_BufferTxPrioByIdCanBase, CANIF_VAR_NOINIT) EcuabCanIf_BufferTxPrioByIdCanBase;
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"
extern VAR(Type_EcuabCanIf_QueueTx, CANIF_VAR_NOINIT) EcuabCanIf_QueueTx;
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"

#ifdef __cplusplus
}
#endif
#endif

