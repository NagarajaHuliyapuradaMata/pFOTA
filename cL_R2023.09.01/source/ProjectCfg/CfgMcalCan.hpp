#if !defined(CAN_CFG_H)
#define CAN_CFG_H

#include "Types_SwcServiceCom.hpp"
#include "Types_McalCan.hpp"

#if defined (CAN_LCFG_SOURCE) || defined (C_DRV_INTERNAL)
#include "SwcServiceOs.hpp"
#endif

#ifndef CAN_USE_DUMMY_STATEMENT
#define CAN_USE_DUMMY_STATEMENT STD_ON
#endif
#ifndef CAN_DUMMY_STATEMENT
#define CAN_DUMMY_STATEMENT(v) (v)=(v)
#endif
#ifndef CAN_DUMMY_STATEMENT_CONST
#define CAN_DUMMY_STATEMENT_CONST(v) (void)(v)
#endif
#ifndef CAN_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CAN_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF
#endif
#ifndef CAN_ATOMIC_VARIABLE_ACCESS
#define CAN_ATOMIC_VARIABLE_ACCESS 32u
#endif
#ifndef CAN_CPU_F1L
#define CAN_CPU_F1L
#endif
#ifndef CAN_PROCESSOR_RH850_1013
#define CAN_PROCESSOR_RH850_1013
#endif
#ifndef CAN_COMP_GREENHILLS
#define CAN_COMP_GREENHILLS
#endif
#ifndef CAN_GEN_GENERATOR_MSR
#define CAN_GEN_GENERATOR_MSR
#endif
#ifndef CAN_CPUTYPE_BITORDER_LSB2MSB
#define CAN_CPUTYPE_BITORDER_LSB2MSB
#endif
#ifndef CAN_CONFIGURATION_VARIANT_PRECOMPILE
#define CAN_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CAN_CONFIGURATION_VARIANT_LINKTIME
#define CAN_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CAN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CAN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CAN_CONFIGURATION_VARIANT
#define CAN_CONFIGURATION_VARIANT CAN_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CAN_POSTBUILD_VARIANT_SUPPORT
#define CAN_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#if !defined(V_GEN_GENERATOR5)
#define V_GEN_GENERATOR5
#endif
#if !defined(V_ENABLE_CAN_ASR_ABSTRACTION)
#define V_ENABLE_CAN_ASR_ABSTRACTION
#endif
#define CAN_GEN_COM_STACK_LIB

#if !defined( V_OSTYPE_AUTOSAR )
#define V_OSTYPE_AUTOSAR
#endif

#if(CPU_TYPE == CPU_TYPE_32)
#if !defined( C_CPUTYPE_32BIT )
#define C_CPUTYPE_32BIT
#endif
#endif
#if(CPU_TYPE == CPU_TYPE_16)
#if !defined( C_CPUTYPE_16BIT )
#define C_CPUTYPE_16BIT
#endif
#endif
#if(CPU_TYPE == CPU_TYPE_8)
#if !defined( C_CPUTYPE_8BIT )
#define C_CPUTYPE_8BIT
#endif
#endif
#if(CPU_BIT_ORDER == LSB_FIRST)
#if !defined( C_CPUTYPE_BITORDER_LSB2MSB )
#define C_CPUTYPE_BITORDER_LSB2MSB
#endif
#endif
#if(CPU_BIT_ORDER == MSB_FIRST)
#if !defined( C_CPUTYPE_BITORDER_MSB2LSB )
#define C_CPUTYPE_BITORDER_MSB2LSB
#endif
#endif
#if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
#if !defined( C_CPUTYPE_LITTLEENDIAN )
#define C_CPUTYPE_LITTLEENDIAN
#endif
#endif
#if(CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
#if !defined( C_CPUTYPE_BIGENDIAN )
#define C_CPUTYPE_BIGENDIAN
#endif
#endif

#if !defined( V_DISABLE_USE_DUMMY_FUNCTIONS )
#define V_DISABLE_USE_DUMMY_FUNCTIONS
#endif
#if !defined( V_ENABLE_USE_DUMMY_STATEMENT )
#define V_ENABLE_USE_DUMMY_STATEMENT
#endif

#if !defined( V_CPU_RH850 )
#define V_CPU_RH850
#endif

#if !defined( C_PROCESSOR_F1L )
#define C_PROCESSOR_F1L
#endif
#if !defined( V_PROCESSOR_F1L )
#define V_PROCESSOR_F1L
#endif

#if !defined( C_COMP_GHS_RH850_RSCAN )
#define C_COMP_GHS_RH850_RSCAN
#endif
#if !defined( V_COMP_GHS )
#define V_COMP_GHS
#endif
#if !defined( V_COMP_GHS_RH850 )
#define V_COMP_GHS_RH850
#endif

#if !defined( V_SUPPRESS_EXTENDED_VERSION_CHECK )
#define V_SUPPRESS_EXTENDED_VERSION_CHECK
#endif

#define CAN_ASR_VERSION              0x0400u
#define CAN_GEN_BASE_CFG5_VERSION    0x0103u
#define CAN_GEN_BASESASR_VERSION     0x0407u
#define CAN_GEN_SH2RSCANASR_VERSION              0x0302u
#define CAN_MICROSAR_VERSION         CAN_MSR403

#define CAN_INSTANCE_ID           0

#define CAN_RX_BASICCAN_TYPE                 0u
#define CAN_RX_FULLCAN_TYPE                  1u
#define CAN_TX_BASICCAN_TYPE                 2u
#define CAN_TX_FULLCAN_TYPE                  3u
#define CAN_UNUSED_CAN_TYPE                  4u
#define CAN_TX_BASICCAN_MUX_TYPE             5u
#define CAN_TX_BASICCAN_FIFO_TYPE            6u

#define CAN_INTERRUPT                        0u
#define CAN_POLLING                          1u

#define kCanChannelNotUsed                     CAN_NO_CANIFCHANNELID

#define CAN_NONE                             0u

#define CAN_NOTIFY_ISSUE                     1u
#define CAN_NOTIFY_MAILBOX                   2u
#define CAN_EXTENDED                         3u

#define CAN_DRIVER                           1u
#define CAN_APPL                             2u
#define CAN_BOTH                             3u

#define CAN_DET                              1u

#define CAN_BRS                              1u
#define CAN_FULL                             2u

#define CAN_FD_RXONLY                        2u
#define CAN_FD_RXTX                          1u

#define CAN_API1                             1u
#define CAN_API2                             2u

#define CAN_OS_TICK2MS(tick)     OS_TICKS2MS_OsCounter((tick))
#define CAN_OS_COUNTER_ID        OsCounter

#define CAN_VERSION_INFO_API                 STD_OFF
#define CAN_DEV_ERROR_DETECT                 STD_ON
#define CAN_DEV_ERROR_REPORT                 STD_ON
#define CAN_SAFE_BSW                         STD_OFF

#define CAN_TX_PROCESSING                    CAN_POLLING
#define CAN_RX_PROCESSING                    CAN_POLLING
#define CAN_BUSOFF_PROCESSING                CAN_POLLING
#define CAN_WAKEUP_PROCESSING                CAN_POLLING
#define CAN_INDIVIDUAL_PROCESSING            STD_OFF
#define CAN_INTERRUPT_USED                   STD_OFF
#define CAN_NESTED_INTERRUPTS                STD_OFF
#define C_DISABLE_OSEK_OS_INTCAT2
#define C_ENABLE_ISRVOID
#define CAN_INTLOCK                          CAN_DRIVER

#define CAN_MULTIPLEXED_TX_MAX               1u
#define CAN_CANCEL_SUPPORT_API               STD_OFF
#define CAN_TRANSMIT_BUFFER                  STD_ON
#define CAN_MULTIPLEXED_TRANSMISSION         STD_OFF
#define CAN_TX_HW_FIFO                       STD_OFF
#define CAN_HW_TRANSMIT_CANCELLATION         STD_OFF
#define CAN_IDENTICAL_ID_CANCELLATION        STD_OFF
#define CAN_MULTIPLE_BASICCAN_TX             STD_OFF

#define CAN_MULTIPLE_BASICCAN                STD_OFF
#define CAN_RX_QUEUE                         STD_OFF
#define CAN_OVERRUN_NOTIFICATION             CAN_NONE

#define CAN_SLEEP_SUPPORT                    STD_ON
#define CAN_WAKEUP_SUPPORT                   STD_OFF

#define CAN_HARDWARE_CANCELLATION            STD_ON
#define CAN_TIMEOUT_DURATION                 10uL
#define CAN_LOOP_MAX                         4u

#define CAN_HW_LOOP_SUPPORT_API              STD_ON
#define CAN_GENERIC_PRECOPY                  STD_OFF
#define CAN_GENERIC_CONFIRMATION             STD_OFF
#define CAN_GENERIC_PRETRANSMIT              STD_OFF
#define CAN_USE_OS_INTERRUPT_CONTROL         STD_OFF

#define CAN_RX_FULLCAN_OBJECTS               STD_OFF
#define CAN_TX_FULLCAN_OBJECTS               STD_OFF
#define CAN_RX_BASICCAN_OBJECTS              STD_ON
#define CAN_EXTENDED_ID                      STD_OFF
#define CAN_MIXED_ID                         STD_OFF
#define CAN_ONE_CONTROLLER_OPTIMIZATION      STD_ON
#define CAN_CHANGE_BAUDRATE_API              STD_OFF
#define CAN_FD_HW_BUFFER_OPTIMIZATION        STD_ON

#define CAN_SET_BAUDRATE_API                 STD_OFF
#define CAN_FD_SUPPORT                       CAN_NONE

#define CAN_COMMON_CAN                       STD_OFF
#define CAN_RAM_CHECK                        CAN_NONE
#define CAN_REINIT_START                     STD_OFF
#define CAN_GET_STATUS                       STD_ON
#define CAN_RUNTIME_MEASUREMENT_SUPPORT      STD_OFF
#define CAN_PROTECTED_MODE                   STD_OFF
#define CAN_MIRROR_MODE                      STD_OFF
#define CAN_SILENT_MODE                      STD_OFF
#define CAN_CHECK_WAKEUP_CAN_RET_TYPE        STD_OFF

#ifndef C_DRV_INTERNAL
#ifndef kCanNumberOfChannels
#define kCanNumberOfChannels               1u
#endif
#ifndef kCanNumberOfHwChannels
#define kCanNumberOfHwChannels             1u
#endif
#endif
#ifndef kCanNumberOfUsedChannels
#define kCanNumberOfUsedChannels            1u
#endif

#define kCanPhysToLogChannelIndex_0

#define kCanNumberOfPhysChannels             1u

#define CanConf_CanController_CT_P1951001_0_003_01_24_RAJA_A1_V_b79a45a3 0u

#define CanConf_CN_P1951001_0_003_01_24_RAJA_A1_V_244b719d_Tx 0u
#define CanConf_CN_P1951001_0_003_01_24_RAJA_A1_V_79155c6f_Rx 1u

#define CanConf_ControllerBaudrateConfig_CT_P1951001_0_003_01_24_RAJA_A1_V_b79a45a3_CanControllerBaudrateConfig 0u

#define CanConf_MemorySection_RxBuffer 2u
#define CanConf_MemorySection_RxFifo 1u
#define CanConf_MemorySection_TxBuffer_CT_P1951001_0_003_01_24_RAJA_A1_V_b79a45a3 0u

#define kCanBaseAdr                          0xFFD00000uL
#define kCanIntcRxFifoBaseAdr                0xFFFF901EuL
#define kCanIntcGErrorBaseAdr                0xFFFF901CuL
#define kCanIntcChTxBaseAdr                  0xFFFF9024uL
#define kCanIntcChErrorBaseAdr               0xFFFF9020uL

#define kCanMaxPhysChannels                  3u
#define kCanMaxRxFifos                       8u
#define kCanMaxTxFifos                       3u
#define kCanMaxTxBuf                         16u
#define kCanMaxRxBuf                         48u
#define kCanMaxPoolBuf                       192u
#define kCanMaxRules                         192u
#define kCanNumberOfSharedReg16              1u
#define kCanLogToPhys                        0u

#define C_ENABLE_IF_RSCAN
#define C_ENABLE_INT_LAYOUT_TWOGLOBAL_THREELOCAL
#define C_ENABLE_BUSWAKEUP_SUPPORT
#define C_ENABLE_SINGLE_PHYS_CHANNEL_OPTIMIZATION
#define C_ENABLE_ALTERNATIVE_CLOCK_SOURCE

typedef struct tCanLLCanIntOldTag{
  uint8 Err;
  uint8 Tx;
  uint8 Wup;
}tCanLLCanIntOld;

typedef struct tCanTmpMsgObjTag{
  uint32 Id;
  uint32 Dlc;
  union
  {
    uint8     bData[8];
    uint16    wData[4];
    uint32    iData[2];
  } u;
}tCanTmpMsgObj;

#if(defined(CAN_LCFG_SOURCE) || defined(C_DRV_INTERNAL)) && (CAN_USE_OS_INTERRUPT_CONTROL == STD_ON)
typedef ISRType Can_ExternalISRType;
#else
typedef uint32 Can_ExternalISRType;
#endif

typedef VAR(uint8, TYPEDEF) CanChannelHandle;

#if defined (CAN_LCFG_SOURCE) || defined (C_DRV_INTERNAL)
typedef TickType Can_ExternalTickType;
#else
typedef uint32 Can_ExternalTickType;
#endif

typedef VAR(Can_ExternalTickType, TYPEDEF) Can_LoopTimeout_dim_type[CAN_LOOP_MAX+1u];

#define CAN_ACTIVESENDOBJECT                                          STD_ON
#define CAN_PDUOFACTIVESENDOBJECT                                     STD_ON
#define CAN_STATEOFACTIVESENDOBJECT                                   STD_ON
#define CAN_BASEDLL_GENERATORVERSION                                  STD_ON
#define CAN_CANIFCHANNELID                                            STD_ON
#define CAN_CHANNELDATA                                               STD_ON
#define CAN_FIFOPROCCOUNTOFCHANNELDATA                                STD_ON
#define CAN_FRSTARTINDEXOFCHANNELDATA                                 STD_ON
#define CAN_FRTOTALCOUNTOFCHANNELDATA                                 STD_ON
#define CAN_RXBCMASKOFCHANNELDATA                                     STD_ON
#define CAN_RXBCSTARTINDEXOFCHANNELDATA                               STD_ON
#define CAN_RXBCSTOPINDEXOFCHANNELDATA                                STD_ON
#define CAN_TXINTMASKOFCHANNELDATA                                    STD_ON
#define CAN_CONTROLLERCONFIG                                          STD_ON
#define CAN_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG         STD_ON
#define CAN_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG            STD_ON
#define CAN_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG                    STD_ON
#define CAN_MAILBOXRXBASICLENGTHOFCONTROLLERCONFIG                    STD_ON
#define CAN_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG                  STD_ON
#define CAN_MAILBOXRXBASICUSEDOFCONTROLLERCONFIG                      STD_ON
#define CAN_MAILBOXRXFULLENDIDXOFCONTROLLERCONFIG                     STD_OFF
#define CAN_MAILBOXRXFULLLENGTHOFCONTROLLERCONFIG                     STD_OFF
#define CAN_MAILBOXRXFULLSTARTIDXOFCONTROLLERCONFIG                   STD_OFF
#define CAN_MAILBOXRXFULLUSEDOFCONTROLLERCONFIG                       STD_OFF
#define CAN_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG                    STD_ON
#define CAN_MAILBOXTXBASICLENGTHOFCONTROLLERCONFIG                    STD_ON
#define CAN_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG                  STD_ON
#define CAN_MAILBOXTXBASICUSEDOFCONTROLLERCONFIG                      STD_ON
#define CAN_MAILBOXTXFULLENDIDXOFCONTROLLERCONFIG                     STD_OFF
#define CAN_MAILBOXTXFULLLENGTHOFCONTROLLERCONFIG                     STD_OFF
#define CAN_MAILBOXTXFULLSTARTIDXOFCONTROLLERCONFIG                   STD_OFF
#define CAN_MAILBOXTXFULLUSEDOFCONTROLLERCONFIG                       STD_OFF
#define CAN_MAILBOXUNUSEDENDIDXOFCONTROLLERCONFIG                     STD_OFF
#define CAN_MAILBOXUNUSEDLENGTHOFCONTROLLERCONFIG                     STD_OFF
#define CAN_MAILBOXUNUSEDSTARTIDXOFCONTROLLERCONFIG                   STD_OFF
#define CAN_MAILBOXUNUSEDUSEDOFCONTROLLERCONFIG                       STD_OFF
#define CAN_RXBASICHWSTARTOFCONTROLLERCONFIG                          STD_ON
#define CAN_RXBASICHWSTOPOFCONTROLLERCONFIG                           STD_ON
#define CAN_RXFULLHWSTARTOFCONTROLLERCONFIG                           STD_ON
#define CAN_RXFULLHWSTOPOFCONTROLLERCONFIG                            STD_ON
#define CAN_TXBASICHWSTARTOFCONTROLLERCONFIG                          STD_ON
#define CAN_TXBASICHWSTOPOFCONTROLLERCONFIG                           STD_ON
#define CAN_TXFULLHWSTARTOFCONTROLLERCONFIG                           STD_ON
#define CAN_TXFULLHWSTOPOFCONTROLLERCONFIG                            STD_ON
#define CAN_UNUSEDHWSTARTOFCONTROLLERCONFIG                           STD_ON
#define CAN_UNUSEDHWSTOPOFCONTROLLERCONFIG                            STD_ON
#define CAN_CONTROLLERDATA                                            STD_ON
#define CAN_BUSOFFCOUNTEROFCONTROLLERDATA                             STD_ON
#define CAN_BUSOFFTRANSITIONREQUESTOFCONTROLLERDATA                   STD_ON
#define CAN_CANINTERRUPTCOUNTEROFCONTROLLERDATA                       STD_ON
#define CAN_CANINTERRUPTOLDSTATUSOFCONTROLLERDATA                     STD_ON
#define CAN_ISBUSOFFOFCONTROLLERDATA                                  STD_ON
#define CAN_LASTINITOBJECTOFCONTROLLERDATA                            STD_ON
#define CAN_LOGSTATUSOFCONTROLLERDATA                                 STD_ON
#define CAN_LOOPTIMEOUTOFCONTROLLERDATA                               STD_ON
#define CAN_MODETRANSITIONREQUESTOFCONTROLLERDATA                     STD_ON
#define CAN_RAMCHECKTRANSITIONREQUESTOFCONTROLLERDATA                 STD_ON
#define CAN_RXTMPBUFOFCONTROLLERDATA                                  STD_ON
#define CAN_FINALMAGICNUMBER                                          STD_OFF
#define CAN_INITDATAHASHCODE                                          STD_OFF
#define CAN_INITFILTERRULES                                           STD_ON
#define CAN_CODEOFINITFILTERRULES                                     STD_ON
#define CAN_MASKOFINITFILTERRULES                                     STD_ON
#define CAN_INITOBJECTBAUDRATE                                        STD_ON
#define CAN_INITOBJECTBITTIMING                                       STD_ON
#define CAN_INITOBJECTSTARTINDEX                                      STD_ON
#define CAN_MAILBOX                                                   STD_ON
#define CAN_ACTIVESENDOBJECTOFMAILBOX                                 STD_ON
#define CAN_CONTROLLERCONFIGIDXOFMAILBOX                              STD_ON
#define CAN_HWHANDLEOFMAILBOX                                         STD_ON
#define CAN_IDVALUEOFMAILBOX                                          STD_ON
#define CAN_MAILBOXSIZEOFMAILBOX                                      STD_ON
#define CAN_MAILBOXTYPEOFMAILBOX                                      STD_ON
#define CAN_MAXDATALENOFMAILBOX                                       STD_ON
#define CAN_MEMORYSECTIONSINDEXOFMAILBOX                              STD_ON
#define CAN_MEMORYSECTIONINFO                                         STD_ON
#define CAN_MEMORYSECTIONSTARTOFMEMORYSECTIONINFO                     STD_ON
#define CAN_MEMORYSECTIONOBJECTS                                      STD_ON
#define CAN_HWHANDLEOFMEMORYSECTIONOBJECTS                            STD_ON
#define CAN_MAILBOXELEMENTOFMEMORYSECTIONOBJECTS                      STD_ON
#define CAN_MAILBOXHANDLEOFMEMORYSECTIONOBJECTS                       STD_ON
#define CAN_PLATFORMDLL_GENERATORVERSION                              STD_ON
#define CAN_RXFIFODATA                                                STD_ON
#define CAN_CONTROLLEROFRXFIFODATA                                    STD_ON
#define CAN_FIFODEPTHOFRXFIFODATA                                     STD_ON
#define CAN_FILTERSTARTINDEXOFRXFIFODATA                              STD_ON
#define CAN_FILTERSTOPINDEXOFRXFIFODATA                               STD_ON
#define CAN_SIZEOFACTIVESENDOBJECT                                    STD_ON
#define CAN_SIZEOFCANIFCHANNELID                                      STD_ON
#define CAN_SIZEOFCHANNELDATA                                         STD_ON
#define CAN_SIZEOFCONTROLLERCONFIG                                    STD_ON
#define CAN_SIZEOFCONTROLLERDATA                                      STD_ON
#define CAN_SIZEOFINITFILTERRULES                                     STD_ON
#define CAN_SIZEOFINITOBJECTBAUDRATE                                  STD_ON
#define CAN_SIZEOFINITOBJECTBITTIMING                                 STD_ON
#define CAN_SIZEOFINITOBJECTSTARTINDEX                                STD_ON
#define CAN_SIZEOFMAILBOX                                             STD_ON
#define CAN_SIZEOFMEMORYSECTIONINFO                                   STD_ON
#define CAN_SIZEOFMEMORYSECTIONOBJECTS                                STD_ON
#define CAN_SIZEOFRXFIFODATA                                          STD_ON
#define CAN_PCCONFIG                                                  STD_ON
#define CAN_ACTIVESENDOBJECTOFPCCONFIG                                STD_ON
#define CAN_BASEDLL_GENERATORVERSIONOFPCCONFIG                        STD_ON
#define CAN_CANIFCHANNELIDOFPCCONFIG                                  STD_ON
#define CAN_CHANNELDATAOFPCCONFIG                                     STD_ON
#define CAN_CONTROLLERCONFIGOFPCCONFIG                                STD_ON
#define CAN_CONTROLLERDATAOFPCCONFIG                                  STD_ON
#define CAN_FINALMAGICNUMBEROFPCCONFIG                                STD_OFF
#define CAN_INITDATAHASHCODEOFPCCONFIG                                STD_OFF
#define CAN_INITFILTERRULESOFPCCONFIG                                 STD_ON
#define CAN_INITOBJECTBAUDRATEOFPCCONFIG                              STD_ON
#define CAN_INITOBJECTBITTIMINGOFPCCONFIG                             STD_ON
#define CAN_INITOBJECTSTARTINDEXOFPCCONFIG                            STD_ON
#define CAN_MAILBOXOFPCCONFIG                                         STD_ON
#define CAN_MEMORYSECTIONINFOOFPCCONFIG                               STD_ON
#define CAN_MEMORYSECTIONOBJECTSOFPCCONFIG                            STD_ON
#define CAN_PLATFORMDLL_GENERATORVERSIONOFPCCONFIG                    STD_ON
#define CAN_RXFIFODATAOFPCCONFIG                                      STD_ON
#define CAN_SIZEOFACTIVESENDOBJECTOFPCCONFIG                          STD_ON
#define CAN_SIZEOFCANIFCHANNELIDOFPCCONFIG                            STD_ON
#define CAN_SIZEOFCHANNELDATAOFPCCONFIG                               STD_ON
#define CAN_SIZEOFCONTROLLERCONFIGOFPCCONFIG                          STD_ON
#define CAN_SIZEOFCONTROLLERDATAOFPCCONFIG                            STD_ON
#define CAN_SIZEOFINITFILTERRULESOFPCCONFIG                           STD_ON
#define CAN_SIZEOFINITOBJECTBAUDRATEOFPCCONFIG                        STD_ON
#define CAN_SIZEOFINITOBJECTBITTIMINGOFPCCONFIG                       STD_ON
#define CAN_SIZEOFINITOBJECTSTARTINDEXOFPCCONFIG                      STD_ON
#define CAN_SIZEOFMAILBOXOFPCCONFIG                                   STD_ON
#define CAN_SIZEOFMEMORYSECTIONINFOOFPCCONFIG                         STD_ON
#define CAN_SIZEOFMEMORYSECTIONOBJECTSOFPCCONFIG                      STD_ON
#define CAN_SIZEOFRXFIFODATAOFPCCONFIG                                STD_ON

#define CAN_MIN_PDUOFACTIVESENDOBJECT                                 0u
#define CAN_MIN_STATEOFACTIVESENDOBJECT                               0u
#define CAN_MIN_BUSOFFCOUNTEROFCONTROLLERDATA                         0u
#define CAN_MIN_BUSOFFTRANSITIONREQUESTOFCONTROLLERDATA               0u
#define CAN_MIN_CANINTERRUPTCOUNTEROFCONTROLLERDATA                   0u
#define CAN_MIN_LASTINITOBJECTOFCONTROLLERDATA                        0u
#define CAN_MIN_LOGSTATUSOFCONTROLLERDATA                             0u
#define CAN_MIN_MODETRANSITIONREQUESTOFCONTROLLERDATA                 0u
#define CAN_MIN_RAMCHECKTRANSITIONREQUESTOFCONTROLLERDATA             0u

#define CAN_MAX_PDUOFACTIVESENDOBJECT                                 255u
#define CAN_MAX_STATEOFACTIVESENDOBJECT                               65535u
#define CAN_MAX_BUSOFFCOUNTEROFCONTROLLERDATA                         255u
#define CAN_MAX_BUSOFFTRANSITIONREQUESTOFCONTROLLERDATA               255u
#define CAN_MAX_CANINTERRUPTCOUNTEROFCONTROLLERDATA                   255u
#define CAN_MAX_LASTINITOBJECTOFCONTROLLERDATA                        255u
#define CAN_MAX_LOGSTATUSOFCONTROLLERDATA                             255u
#define CAN_MAX_MODETRANSITIONREQUESTOFCONTROLLERDATA                 255u
#define CAN_MAX_RAMCHECKTRANSITIONREQUESTOFCONTROLLERDATA             255u

#define CAN_NO_CANIFCHANNELID                                         255u
#define CAN_NO_FIFOPROCCOUNTOFCHANNELDATA                             255u
#define CAN_NO_FRSTARTINDEXOFCHANNELDATA                              255u
#define CAN_NO_FRTOTALCOUNTOFCHANNELDATA                              255u
#define CAN_NO_RXBCMASKOFCHANNELDATA                                  255u
#define CAN_NO_RXBCSTARTINDEXOFCHANNELDATA                            255u
#define CAN_NO_RXBCSTOPINDEXOFCHANNELDATA                             255u
#define CAN_NO_TXINTMASKOFCHANNELDATA                                 255u
#define CAN_NO_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG      255u
#define CAN_NO_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG         65535u
#define CAN_NO_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG                 255u
#define CAN_NO_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG               255u
#define CAN_NO_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG                 255u
#define CAN_NO_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG               255u
#define CAN_NO_RXBASICHWSTARTOFCONTROLLERCONFIG                       255u
#define CAN_NO_RXBASICHWSTOPOFCONTROLLERCONFIG                        255u
#define CAN_NO_RXFULLHWSTARTOFCONTROLLERCONFIG                        255u
#define CAN_NO_RXFULLHWSTOPOFCONTROLLERCONFIG                         255u
#define CAN_NO_TXBASICHWSTARTOFCONTROLLERCONFIG                       255u
#define CAN_NO_TXBASICHWSTOPOFCONTROLLERCONFIG                        255u
#define CAN_NO_TXFULLHWSTARTOFCONTROLLERCONFIG                        255u
#define CAN_NO_TXFULLHWSTOPOFCONTROLLERCONFIG                         255u
#define CAN_NO_UNUSEDHWSTARTOFCONTROLLERCONFIG                        255u
#define CAN_NO_UNUSEDHWSTOPOFCONTROLLERCONFIG                         255u

#define CAN_EXISTS_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX              STD_ON
#define CAN_EXISTS_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX               STD_OFF
#define CAN_EXISTS_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX              STD_ON
#define CAN_EXISTS_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX               STD_OFF
#define CAN_EXISTS_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX               STD_OFF
#define CAN_EXISTS_TX_BASICCAN_MUX_TYPE_MAILBOXTYPEOFMAILBOX          STD_OFF
#define CAN_EXISTS_TX_BASICCAN_FIFO_TYPE_MAILBOXTYPEOFMAILBOX         STD_OFF

#define CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX                     0x00u
#define CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX                     0x02u

#define CAN_ISDEF_CANIFCHANNELID                                      STD_OFF
#define CAN_ISDEF_FIFOPROCCOUNTOFCHANNELDATA                          STD_OFF
#define CAN_ISDEF_FRSTARTINDEXOFCHANNELDATA                           STD_OFF
#define CAN_ISDEF_FRTOTALCOUNTOFCHANNELDATA                           STD_OFF
#define CAN_ISDEF_RXBCMASKOFCHANNELDATA                               STD_OFF
#define CAN_ISDEF_RXBCSTARTINDEXOFCHANNELDATA                         STD_OFF
#define CAN_ISDEF_RXBCSTOPINDEXOFCHANNELDATA                          STD_OFF
#define CAN_ISDEF_TXINTMASKOFCHANNELDATA                              STD_OFF
#define CAN_ISDEF_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG   STD_OFF
#define CAN_ISDEF_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG      STD_OFF
#define CAN_ISDEF_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG              STD_OFF
#define CAN_ISDEF_MAILBOXRXBASICLENGTHOFCONTROLLERCONFIG              STD_OFF
#define CAN_ISDEF_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG            STD_OFF
#define CAN_ISDEF_MAILBOXRXBASICUSEDOFCONTROLLERCONFIG                STD_OFF
#define CAN_ISDEF_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG              STD_OFF
#define CAN_ISDEF_MAILBOXTXBASICLENGTHOFCONTROLLERCONFIG              STD_OFF
#define CAN_ISDEF_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG            STD_OFF
#define CAN_ISDEF_MAILBOXTXBASICUSEDOFCONTROLLERCONFIG                STD_OFF
#define CAN_ISDEF_RXBASICHWSTARTOFCONTROLLERCONFIG                    STD_OFF
#define CAN_ISDEF_RXBASICHWSTOPOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_RXFULLHWSTARTOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_RXFULLHWSTOPOFCONTROLLERCONFIG                      STD_OFF
#define CAN_ISDEF_TXBASICHWSTARTOFCONTROLLERCONFIG                    STD_OFF
#define CAN_ISDEF_TXBASICHWSTOPOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_TXFULLHWSTARTOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_TXFULLHWSTOPOFCONTROLLERCONFIG                      STD_OFF
#define CAN_ISDEF_UNUSEDHWSTARTOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_UNUSEDHWSTOPOFCONTROLLERCONFIG                      STD_OFF
#define CAN_ISDEF_CODEOFINITFILTERRULES                               STD_OFF
#define CAN_ISDEF_MASKOFINITFILTERRULES                               STD_OFF
#define CAN_ISDEF_INITOBJECTBAUDRATE                                  STD_OFF
#define CAN_ISDEF_INITOBJECTBITTIMING                                 STD_OFF
#define CAN_ISDEF_INITOBJECTSTARTINDEX                                STD_OFF
#define CAN_ISDEF_ACTIVESENDOBJECTOFMAILBOX                           STD_OFF
#define CAN_ISDEF_CONTROLLERCONFIGIDXOFMAILBOX                        STD_OFF
#define CAN_ISDEF_HWHANDLEOFMAILBOX                                   STD_OFF
#define CAN_ISDEF_IDVALUEOFMAILBOX                                    STD_OFF
#define CAN_ISDEF_MAILBOXSIZEOFMAILBOX                                STD_OFF
#define CAN_ISDEF_MAILBOXTYPEOFMAILBOX                                STD_OFF
#define CAN_ISDEF_MAXDATALENOFMAILBOX                                 STD_OFF
#define CAN_ISDEF_MEMORYSECTIONSINDEXOFMAILBOX                        STD_OFF
#define CAN_ISDEF_MEMORYSECTIONSTARTOFMEMORYSECTIONINFO               STD_OFF
#define CAN_ISDEF_HWHANDLEOFMEMORYSECTIONOBJECTS                      STD_OFF
#define CAN_ISDEF_MAILBOXELEMENTOFMEMORYSECTIONOBJECTS                STD_OFF
#define CAN_ISDEF_MAILBOXHANDLEOFMEMORYSECTIONOBJECTS                 STD_OFF
#define CAN_ISDEF_CONTROLLEROFRXFIFODATA                              STD_OFF
#define CAN_ISDEF_FIFODEPTHOFRXFIFODATA                               STD_OFF
#define CAN_ISDEF_FILTERSTARTINDEXOFRXFIFODATA                        STD_OFF
#define CAN_ISDEF_FILTERSTOPINDEXOFRXFIFODATA                         STD_OFF
#define CAN_ISDEF_ACTIVESENDOBJECTOFPCCONFIG                          STD_ON
#define CAN_ISDEF_CANIFCHANNELIDOFPCCONFIG                            STD_ON
#define CAN_ISDEF_CHANNELDATAOFPCCONFIG                               STD_ON
#define CAN_ISDEF_CONTROLLERCONFIGOFPCCONFIG                          STD_ON
#define CAN_ISDEF_CONTROLLERDATAOFPCCONFIG                            STD_ON
#define CAN_ISDEF_INITFILTERRULESOFPCCONFIG                           STD_ON
#define CAN_ISDEF_INITOBJECTBAUDRATEOFPCCONFIG                        STD_ON
#define CAN_ISDEF_INITOBJECTBITTIMINGOFPCCONFIG                       STD_ON
#define CAN_ISDEF_INITOBJECTSTARTINDEXOFPCCONFIG                      STD_ON
#define CAN_ISDEF_MAILBOXOFPCCONFIG                                   STD_ON
#define CAN_ISDEF_MEMORYSECTIONINFOOFPCCONFIG                         STD_ON
#define CAN_ISDEF_MEMORYSECTIONOBJECTSOFPCCONFIG                      STD_ON
#define CAN_ISDEF_RXFIFODATAOFPCCONFIG                                STD_ON

#define CAN_EQ2_CANIFCHANNELID
#define CAN_EQ2_FIFOPROCCOUNTOFCHANNELDATA
#define CAN_EQ2_FRSTARTINDEXOFCHANNELDATA
#define CAN_EQ2_FRTOTALCOUNTOFCHANNELDATA
#define CAN_EQ2_RXBCMASKOFCHANNELDATA
#define CAN_EQ2_RXBCSTARTINDEXOFCHANNELDATA
#define CAN_EQ2_RXBCSTOPINDEXOFCHANNELDATA
#define CAN_EQ2_TXINTMASKOFCHANNELDATA
#define CAN_EQ2_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG
#define CAN_EQ2_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG
#define CAN_EQ2_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG
#define CAN_EQ2_MAILBOXRXBASICLENGTHOFCONTROLLERCONFIG
#define CAN_EQ2_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG
#define CAN_EQ2_MAILBOXRXBASICUSEDOFCONTROLLERCONFIG
#define CAN_EQ2_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG
#define CAN_EQ2_MAILBOXTXBASICLENGTHOFCONTROLLERCONFIG
#define CAN_EQ2_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG
#define CAN_EQ2_MAILBOXTXBASICUSEDOFCONTROLLERCONFIG
#define CAN_EQ2_RXBASICHWSTARTOFCONTROLLERCONFIG
#define CAN_EQ2_RXBASICHWSTOPOFCONTROLLERCONFIG
#define CAN_EQ2_RXFULLHWSTARTOFCONTROLLERCONFIG
#define CAN_EQ2_RXFULLHWSTOPOFCONTROLLERCONFIG
#define CAN_EQ2_TXBASICHWSTARTOFCONTROLLERCONFIG
#define CAN_EQ2_TXBASICHWSTOPOFCONTROLLERCONFIG
#define CAN_EQ2_TXFULLHWSTARTOFCONTROLLERCONFIG
#define CAN_EQ2_TXFULLHWSTOPOFCONTROLLERCONFIG
#define CAN_EQ2_UNUSEDHWSTARTOFCONTROLLERCONFIG
#define CAN_EQ2_UNUSEDHWSTOPOFCONTROLLERCONFIG
#define CAN_EQ2_CODEOFINITFILTERRULES
#define CAN_EQ2_MASKOFINITFILTERRULES
#define CAN_EQ2_INITOBJECTBAUDRATE
#define CAN_EQ2_INITOBJECTBITTIMING
#define CAN_EQ2_INITOBJECTSTARTINDEX
#define CAN_EQ2_ACTIVESENDOBJECTOFMAILBOX
#define CAN_EQ2_CONTROLLERCONFIGIDXOFMAILBOX
#define CAN_EQ2_HWHANDLEOFMAILBOX
#define CAN_EQ2_IDVALUEOFMAILBOX
#define CAN_EQ2_MAILBOXSIZEOFMAILBOX
#define CAN_EQ2_MAILBOXTYPEOFMAILBOX
#define CAN_EQ2_MAXDATALENOFMAILBOX
#define CAN_EQ2_MEMORYSECTIONSINDEXOFMAILBOX
#define CAN_EQ2_MEMORYSECTIONSTARTOFMEMORYSECTIONINFO
#define CAN_EQ2_HWHANDLEOFMEMORYSECTIONOBJECTS
#define CAN_EQ2_MAILBOXELEMENTOFMEMORYSECTIONOBJECTS
#define CAN_EQ2_MAILBOXHANDLEOFMEMORYSECTIONOBJECTS
#define CAN_EQ2_CONTROLLEROFRXFIFODATA
#define CAN_EQ2_FIFODEPTHOFRXFIFODATA
#define CAN_EQ2_FILTERSTARTINDEXOFRXFIFODATA
#define CAN_EQ2_FILTERSTOPINDEXOFRXFIFODATA
#define CAN_EQ2_ACTIVESENDOBJECTOFPCCONFIG                            Can_ActiveSendObject
#define CAN_EQ2_CANIFCHANNELIDOFPCCONFIG                              Can_CanIfChannelId
#define CAN_EQ2_CHANNELDATAOFPCCONFIG                                 Can_ChannelData
#define CAN_EQ2_CONTROLLERCONFIGOFPCCONFIG                            Can_ControllerConfig
#define CAN_EQ2_CONTROLLERDATAOFPCCONFIG                              Can_ControllerData
#define CAN_EQ2_INITFILTERRULESOFPCCONFIG                             Can_InitFilterRules
#define CAN_EQ2_INITOBJECTBAUDRATEOFPCCONFIG                          Can_InitObjectBaudrate
#define CAN_EQ2_INITOBJECTBITTIMINGOFPCCONFIG                         Can_InitObjectBitTiming
#define CAN_EQ2_INITOBJECTSTARTINDEXOFPCCONFIG                        Can_InitObjectStartIndex
#define CAN_EQ2_MAILBOXOFPCCONFIG                                     Can_Mailbox
#define CAN_EQ2_MEMORYSECTIONINFOOFPCCONFIG                           Can_MemorySectionInfo
#define CAN_EQ2_MEMORYSECTIONOBJECTSOFPCCONFIG                        Can_MemorySectionObjects
#define CAN_EQ2_RXFIFODATAOFPCCONFIG                                  Can_RxFifoData

#define Can_Config_Ptr                                                NULL_PTR

#define Can_Config                                                    NULL_PTR

#define CAN_CHECK_INIT_POINTER                                        STD_OFF
#define CAN_FINAL_MAGIC_NUMBER                                        0x501Eu
#define CAN_INDIVIDUAL_POSTBUILD                                      STD_OFF
#define CAN_INIT_DATA                                                 CAN_CONST
#define CAN_INIT_DATA_HASH_CODE                                       -1893185136
#define CAN_USE_ECUM_BSW_ERROR_HOOK                                   STD_OFF
#define CAN_USE_INIT_POINTER                                          STD_OFF

#define CAN_LTCONFIG                                                  STD_OFF

#define CAN_PBCONFIG                                                  STD_OFF
#define CAN_LTCONFIGIDXOFPBCONFIG                                     STD_OFF
#define CAN_PCCONFIGIDXOFPBCONFIG                                     STD_OFF

#define Can_GetActiveSendObjectOfPCConfig()                           Can_ActiveSendObject
#define Can_GetBaseDll_GeneratorVersionOfPCConfig()                   0x0103u
#define Can_GetCanIfChannelIdOfPCConfig()                             Can_CanIfChannelId
#define Can_GetChannelDataOfPCConfig()                                Can_ChannelData
#define Can_GetControllerConfigOfPCConfig()                           Can_ControllerConfig
#define Can_GetControllerDataOfPCConfig()                             Can_ControllerData
#define Can_GetInitFilterRulesOfPCConfig()                            Can_InitFilterRules
#define Can_GetInitObjectBaudrateOfPCConfig()                         Can_InitObjectBaudrate
#define Can_GetInitObjectBitTimingOfPCConfig()                        Can_InitObjectBitTiming
#define Can_GetInitObjectStartIndexOfPCConfig()                       Can_InitObjectStartIndex
#define Can_GetMailboxOfPCConfig()                                    Can_Mailbox
#define Can_GetMemorySectionInfoOfPCConfig()                          Can_MemorySectionInfo
#define Can_GetMemorySectionObjectsOfPCConfig()                       Can_MemorySectionObjects
#define Can_GetPlatformDll_GeneratorVersionOfPCConfig()               0x0302u
#define Can_GetRxFifoDataOfPCConfig()                                 Can_RxFifoData
#define Can_GetSizeOfActiveSendObjectOfPCConfig()                     1u
#define Can_GetSizeOfCanIfChannelIdOfPCConfig()                       1u
#define Can_GetSizeOfChannelDataOfPCConfig()                          1u
#define Can_GetSizeOfControllerConfigOfPCConfig()                     1u
#define Can_GetSizeOfInitFilterRulesOfPCConfig()                      1u
#define Can_GetSizeOfInitObjectBaudrateOfPCConfig()                   1u
#define Can_GetSizeOfInitObjectBitTimingOfPCConfig()                  1u
#define Can_GetSizeOfInitObjectStartIndexOfPCConfig()                 2u
#define Can_GetSizeOfMailboxOfPCConfig()                              2u
#define Can_GetSizeOfMemorySectionInfoOfPCConfig()                    1u
#define Can_GetSizeOfMemorySectionObjectsOfPCConfig()                 16u
#define Can_GetSizeOfRxFifoDataOfPCConfig()                           1u

#define Can_GetSizeOfControllerDataOfPCConfig()                       Can_GetSizeOfControllerConfigOfPCConfig()

#define Can_GetPduOfActiveSendObject(Index)                           (Can_GetActiveSendObjectOfPCConfig()[(Index)].PduOfActiveSendObject)
#define Can_GetStateOfActiveSendObject(Index)                         (Can_GetActiveSendObjectOfPCConfig()[(Index)].StateOfActiveSendObject)
#define Can_GetCanIfChannelId(Index)                                  (Can_GetCanIfChannelIdOfPCConfig()[(Index)])
#define Can_GetFifoProcCountOfChannelData(Index)                      (Can_GetChannelDataOfPCConfig()[(Index)].FifoProcCountOfChannelData)
#define Can_GetFrStartIndexOfChannelData(Index)                       (Can_GetChannelDataOfPCConfig()[(Index)].FrStartIndexOfChannelData)
#define Can_GetFrTotalCountOfChannelData(Index)                       (Can_GetChannelDataOfPCConfig()[(Index)].FrTotalCountOfChannelData)
#define Can_GetRxBcMaskOfChannelData(Index)                           (Can_GetChannelDataOfPCConfig()[(Index)].RxBcMaskOfChannelData)
#define Can_GetRxBcStartIndexOfChannelData(Index)                     (Can_GetChannelDataOfPCConfig()[(Index)].RxBcStartIndexOfChannelData)
#define Can_GetRxBcStopIndexOfChannelData(Index)                      (Can_GetChannelDataOfPCConfig()[(Index)].RxBcStopIndexOfChannelData)
#define Can_GetTxIntMaskOfChannelData(Index)                          (Can_GetChannelDataOfPCConfig()[(Index)].TxIntMaskOfChannelData)
#define Can_GetCanControllerDefaultBaudrateIdxOfControllerConfig(Index) (Can_GetControllerConfigOfPCConfig()[(Index)].CanControllerDefaultBaudrateIdxOfControllerConfig)
#define Can_GetCanControllerDefaultBaudrateOfControllerConfig(Index)  (Can_GetControllerConfigOfPCConfig()[(Index)].CanControllerDefaultBaudrateOfControllerConfig)
#define Can_GetMailboxRxBasicEndIdxOfControllerConfig(Index)          (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxRxBasicEndIdxOfControllerConfig)
#define Can_GetMailboxRxBasicLengthOfControllerConfig(Index)          (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxRxBasicLengthOfControllerConfig)
#define Can_GetMailboxRxBasicStartIdxOfControllerConfig(Index)        (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxRxBasicStartIdxOfControllerConfig)
#define Can_GetMailboxTxBasicEndIdxOfControllerConfig(Index)          (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxTxBasicEndIdxOfControllerConfig)
#define Can_GetMailboxTxBasicLengthOfControllerConfig(Index)          (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxTxBasicLengthOfControllerConfig)
#define Can_GetMailboxTxBasicStartIdxOfControllerConfig(Index)        (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxTxBasicStartIdxOfControllerConfig)
#define Can_GetRxBasicHwStartOfControllerConfig(Index)                (Can_GetControllerConfigOfPCConfig()[(Index)].RxBasicHwStartOfControllerConfig)
#define Can_GetRxBasicHwStopOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].RxBasicHwStopOfControllerConfig)
#define Can_GetRxFullHwStartOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].RxFullHwStartOfControllerConfig)
#define Can_GetRxFullHwStopOfControllerConfig(Index)                  (Can_GetControllerConfigOfPCConfig()[(Index)].RxFullHwStopOfControllerConfig)
#define Can_GetTxBasicHwStartOfControllerConfig(Index)                (Can_GetControllerConfigOfPCConfig()[(Index)].TxBasicHwStartOfControllerConfig)
#define Can_GetTxBasicHwStopOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].TxBasicHwStopOfControllerConfig)
#define Can_GetTxFullHwStartOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].TxFullHwStartOfControllerConfig)
#define Can_GetTxFullHwStopOfControllerConfig(Index)                  (Can_GetControllerConfigOfPCConfig()[(Index)].TxFullHwStopOfControllerConfig)
#define Can_GetUnusedHwStartOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].UnusedHwStartOfControllerConfig)
#define Can_GetUnusedHwStopOfControllerConfig(Index)                  (Can_GetControllerConfigOfPCConfig()[(Index)].UnusedHwStopOfControllerConfig)
#define Can_GetBusOffCounterOfControllerData(Index)                   (Can_GetControllerDataOfPCConfig()[(Index)].BusOffCounterOfControllerData)
#define Can_GetBusOffTransitionRequestOfControllerData(Index)         (Can_GetControllerDataOfPCConfig()[(Index)].BusOffTransitionRequestOfControllerData)
#define Can_GetCanInterruptCounterOfControllerData(Index)             (Can_GetControllerDataOfPCConfig()[(Index)].CanInterruptCounterOfControllerData)
#define Can_GetCanInterruptOldStatusOfControllerData(Index)           (Can_GetControllerDataOfPCConfig()[(Index)].CanInterruptOldStatusOfControllerData)
#define Can_IsIsBusOffOfControllerData(Index)                         ((Can_GetControllerDataOfPCConfig()[(Index)].IsBusOffOfControllerData) != FALSE)
#define Can_GetLastInitObjectOfControllerData(Index)                  (Can_GetControllerDataOfPCConfig()[(Index)].LastInitObjectOfControllerData)
#define Can_GetLogStatusOfControllerData(Index)                       (Can_GetControllerDataOfPCConfig()[(Index)].LogStatusOfControllerData)
#define Can_GetLoopTimeoutOfControllerData(Index)                     (Can_GetControllerDataOfPCConfig()[(Index)].LoopTimeoutOfControllerData)
#define Can_GetModeTransitionRequestOfControllerData(Index)           (Can_GetControllerDataOfPCConfig()[(Index)].ModeTransitionRequestOfControllerData)
#define Can_GetRamCheckTransitionRequestOfControllerData(Index)       (Can_GetControllerDataOfPCConfig()[(Index)].RamCheckTransitionRequestOfControllerData)
#define Can_GetRxTmpBufOfControllerData(Index)                        (Can_GetControllerDataOfPCConfig()[(Index)].RxTmpBufOfControllerData)
#define Can_GetCodeOfInitFilterRules(Index)                           (Can_GetInitFilterRulesOfPCConfig()[(Index)].CodeOfInitFilterRules)
#define Can_GetMaskOfInitFilterRules(Index)                           (Can_GetInitFilterRulesOfPCConfig()[(Index)].MaskOfInitFilterRules)
#define Can_GetInitObjectBaudrate(Index)                              (Can_GetInitObjectBaudrateOfPCConfig()[(Index)])
#define Can_GetInitObjectBitTiming(Index)                             (Can_GetInitObjectBitTimingOfPCConfig()[(Index)])
#define Can_GetInitObjectStartIndex(Index)                            (Can_GetInitObjectStartIndexOfPCConfig()[(Index)])
#define Can_GetActiveSendObjectOfMailbox(Index)                       (Can_GetMailboxOfPCConfig()[(Index)].ActiveSendObjectOfMailbox)
#define Can_GetControllerConfigIdxOfMailbox(Index)                    (Can_GetMailboxOfPCConfig()[(Index)].ControllerConfigIdxOfMailbox)
#define Can_GetHwHandleOfMailbox(Index)                               (Can_GetMailboxOfPCConfig()[(Index)].HwHandleOfMailbox)
#define Can_GetIDValueOfMailbox(Index)                                (Can_GetMailboxOfPCConfig()[(Index)].IDValueOfMailbox)
#define Can_GetMailboxSizeOfMailbox(Index)                            (Can_GetMailboxOfPCConfig()[(Index)].MailboxSizeOfMailbox)
#define Can_GetMailboxTypeOfMailbox(Index)                            (Can_GetMailboxOfPCConfig()[(Index)].MailboxTypeOfMailbox)
#define Can_GetMaxDataLenOfMailbox(Index)                             (Can_GetMailboxOfPCConfig()[(Index)].MaxDataLenOfMailbox)
#define Can_GetMemorySectionsIndexOfMailbox(Index)                    (Can_GetMailboxOfPCConfig()[(Index)].MemorySectionsIndexOfMailbox)
#define Can_GetMemorySectionStartOfMemorySectionInfo(Index)           (Can_GetMemorySectionInfoOfPCConfig()[(Index)].MemorySectionStartOfMemorySectionInfo)
#define Can_GetHwHandleOfMemorySectionObjects(Index)                  (Can_GetMemorySectionObjectsOfPCConfig()[(Index)].HwHandleOfMemorySectionObjects)
#define Can_GetMailboxElementOfMemorySectionObjects(Index)            (Can_GetMemorySectionObjectsOfPCConfig()[(Index)].MailboxElementOfMemorySectionObjects)
#define Can_GetMailboxHandleOfMemorySectionObjects(Index)             (Can_GetMemorySectionObjectsOfPCConfig()[(Index)].MailboxHandleOfMemorySectionObjects)
#define Can_GetControllerOfRxFifoData(Index)                          (Can_GetRxFifoDataOfPCConfig()[(Index)].ControllerOfRxFifoData)
#define Can_GetFifoDepthOfRxFifoData(Index)                           (Can_GetRxFifoDataOfPCConfig()[(Index)].FifoDepthOfRxFifoData)
#define Can_GetFilterStartIndexOfRxFifoData(Index)                    (Can_GetRxFifoDataOfPCConfig()[(Index)].FilterStartIndexOfRxFifoData)
#define Can_GetFilterStopIndexOfRxFifoData(Index)                     (Can_GetRxFifoDataOfPCConfig()[(Index)].FilterStopIndexOfRxFifoData)

#define Can_GetBaseDll_GeneratorVersion()                             Can_GetBaseDll_GeneratorVersionOfPCConfig()
#define Can_IsMailboxRxBasicUsedOfControllerConfig(Index)             (((boolean)(Can_GetMailboxRxBasicLengthOfControllerConfig(Index) != 0u)) != FALSE)
#define Can_IsMailboxTxBasicUsedOfControllerConfig(Index)             (((boolean)(Can_GetMailboxTxBasicLengthOfControllerConfig(Index) != 0u)) != FALSE)
#define Can_GetPlatformDll_GeneratorVersion()                         Can_GetPlatformDll_GeneratorVersionOfPCConfig()
#define Can_GetSizeOfActiveSendObject()                               Can_GetSizeOfActiveSendObjectOfPCConfig()
#define Can_GetSizeOfCanIfChannelId()                                 Can_GetSizeOfCanIfChannelIdOfPCConfig()
#define Can_GetSizeOfChannelData()                                    Can_GetSizeOfChannelDataOfPCConfig()
#define Can_GetSizeOfControllerConfig()                               Can_GetSizeOfControllerConfigOfPCConfig()
#define Can_GetSizeOfControllerData()                                 Can_GetSizeOfControllerDataOfPCConfig()
#define Can_GetSizeOfInitFilterRules()                                Can_GetSizeOfInitFilterRulesOfPCConfig()
#define Can_GetSizeOfInitObjectBaudrate()                             Can_GetSizeOfInitObjectBaudrateOfPCConfig()
#define Can_GetSizeOfInitObjectBitTiming()                            Can_GetSizeOfInitObjectBitTimingOfPCConfig()
#define Can_GetSizeOfInitObjectStartIndex()                           Can_GetSizeOfInitObjectStartIndexOfPCConfig()
#define Can_GetSizeOfMailbox()                                        Can_GetSizeOfMailboxOfPCConfig()
#define Can_GetSizeOfMemorySectionInfo()                              Can_GetSizeOfMemorySectionInfoOfPCConfig()
#define Can_GetSizeOfMemorySectionObjects()                           Can_GetSizeOfMemorySectionObjectsOfPCConfig()
#define Can_GetSizeOfRxFifoData()                                     Can_GetSizeOfRxFifoDataOfPCConfig()

#define Can_SetPduOfActiveSendObject(Index, Value)                    Can_GetActiveSendObjectOfPCConfig()[(Index)].PduOfActiveSendObject = (Value)
#define Can_SetStateOfActiveSendObject(Index, Value)                  Can_GetActiveSendObjectOfPCConfig()[(Index)].StateOfActiveSendObject = (Value)
#define Can_SetBusOffCounterOfControllerData(Index, Value)            Can_GetControllerDataOfPCConfig()[(Index)].BusOffCounterOfControllerData = (Value)
#define Can_SetBusOffTransitionRequestOfControllerData(Index, Value)  Can_GetControllerDataOfPCConfig()[(Index)].BusOffTransitionRequestOfControllerData = (Value)
#define Can_SetCanInterruptCounterOfControllerData(Index, Value)      Can_GetControllerDataOfPCConfig()[(Index)].CanInterruptCounterOfControllerData = (Value)
#define Can_SetCanInterruptOldStatusOfControllerData(Index, Value)    Can_GetControllerDataOfPCConfig()[(Index)].CanInterruptOldStatusOfControllerData = (Value)
#define Can_SetIsBusOffOfControllerData(Index, Value)                 Can_GetControllerDataOfPCConfig()[(Index)].IsBusOffOfControllerData = (Value)
#define Can_SetLastInitObjectOfControllerData(Index, Value)           Can_GetControllerDataOfPCConfig()[(Index)].LastInitObjectOfControllerData = (Value)
#define Can_SetLogStatusOfControllerData(Index, Value)                Can_GetControllerDataOfPCConfig()[(Index)].LogStatusOfControllerData = (Value)
#define Can_SetLoopTimeoutOfControllerData(Index, Value)              Can_GetControllerDataOfPCConfig()[(Index)].LoopTimeoutOfControllerData = (Value)
#define Can_SetModeTransitionRequestOfControllerData(Index, Value)    Can_GetControllerDataOfPCConfig()[(Index)].ModeTransitionRequestOfControllerData = (Value)
#define Can_SetRamCheckTransitionRequestOfControllerData(Index, Value) Can_GetControllerDataOfPCConfig()[(Index)].RamCheckTransitionRequestOfControllerData = (Value)
#define Can_SetRxTmpBufOfControllerData(Index, Value)                 Can_GetControllerDataOfPCConfig()[(Index)].RxTmpBufOfControllerData = (Value)

#define Can_HasActiveSendObject()                                     (TRUE != FALSE)
#define Can_HasPduOfActiveSendObject()                                (TRUE != FALSE)
#define Can_HasStateOfActiveSendObject()                              (TRUE != FALSE)
#define Can_HasBaseDll_GeneratorVersion()                             (TRUE != FALSE)
#define Can_HasCanIfChannelId()                                       (TRUE != FALSE)
#define Can_HasChannelData()                                          (TRUE != FALSE)
#define Can_HasFifoProcCountOfChannelData()                           (TRUE != FALSE)
#define Can_HasFrStartIndexOfChannelData()                            (TRUE != FALSE)
#define Can_HasFrTotalCountOfChannelData()                            (TRUE != FALSE)
#define Can_HasRxBcMaskOfChannelData()                                (TRUE != FALSE)
#define Can_HasRxBcStartIndexOfChannelData()                          (TRUE != FALSE)
#define Can_HasRxBcStopIndexOfChannelData()                           (TRUE != FALSE)
#define Can_HasTxIntMaskOfChannelData()                               (TRUE != FALSE)
#define Can_HasControllerConfig()                                     (TRUE != FALSE)
#define Can_HasCanControllerDefaultBaudrateIdxOfControllerConfig()    (TRUE != FALSE)
#define Can_HasCanControllerDefaultBaudrateOfControllerConfig()       (TRUE != FALSE)
#define Can_HasMailboxRxBasicEndIdxOfControllerConfig()               (TRUE != FALSE)
#define Can_HasMailboxRxBasicLengthOfControllerConfig()               (TRUE != FALSE)
#define Can_HasMailboxRxBasicStartIdxOfControllerConfig()             (TRUE != FALSE)
#define Can_HasMailboxRxBasicUsedOfControllerConfig()                 (TRUE != FALSE)
#define Can_HasMailboxTxBasicEndIdxOfControllerConfig()               (TRUE != FALSE)
#define Can_HasMailboxTxBasicLengthOfControllerConfig()               (TRUE != FALSE)
#define Can_HasMailboxTxBasicStartIdxOfControllerConfig()             (TRUE != FALSE)
#define Can_HasMailboxTxBasicUsedOfControllerConfig()                 (TRUE != FALSE)
#define Can_HasRxBasicHwStartOfControllerConfig()                     (TRUE != FALSE)
#define Can_HasRxBasicHwStopOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasRxFullHwStartOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasRxFullHwStopOfControllerConfig()                       (TRUE != FALSE)
#define Can_HasTxBasicHwStartOfControllerConfig()                     (TRUE != FALSE)
#define Can_HasTxBasicHwStopOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasTxFullHwStartOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasTxFullHwStopOfControllerConfig()                       (TRUE != FALSE)
#define Can_HasUnusedHwStartOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasUnusedHwStopOfControllerConfig()                       (TRUE != FALSE)
#define Can_HasControllerData()                                       (TRUE != FALSE)
#define Can_HasBusOffCounterOfControllerData()                        (TRUE != FALSE)
#define Can_HasBusOffTransitionRequestOfControllerData()              (TRUE != FALSE)
#define Can_HasCanInterruptCounterOfControllerData()                  (TRUE != FALSE)
#define Can_HasCanInterruptOldStatusOfControllerData()                (TRUE != FALSE)
#define Can_HasIsBusOffOfControllerData()                             (TRUE != FALSE)
#define Can_HasLastInitObjectOfControllerData()                       (TRUE != FALSE)
#define Can_HasLogStatusOfControllerData()                            (TRUE != FALSE)
#define Can_HasLoopTimeoutOfControllerData()                          (TRUE != FALSE)
#define Can_HasModeTransitionRequestOfControllerData()                (TRUE != FALSE)
#define Can_HasRamCheckTransitionRequestOfControllerData()            (TRUE != FALSE)
#define Can_HasRxTmpBufOfControllerData()                             (TRUE != FALSE)
#define Can_HasInitFilterRules()                                      (TRUE != FALSE)
#define Can_HasCodeOfInitFilterRules()                                (TRUE != FALSE)
#define Can_HasMaskOfInitFilterRules()                                (TRUE != FALSE)
#define Can_HasInitObjectBaudrate()                                   (TRUE != FALSE)
#define Can_HasInitObjectBitTiming()                                  (TRUE != FALSE)
#define Can_HasInitObjectStartIndex()                                 (TRUE != FALSE)
#define Can_HasMailbox()                                              (TRUE != FALSE)
#define Can_HasActiveSendObjectOfMailbox()                            (TRUE != FALSE)
#define Can_HasControllerConfigIdxOfMailbox()                         (TRUE != FALSE)
#define Can_HasHwHandleOfMailbox()                                    (TRUE != FALSE)
#define Can_HasIDValueOfMailbox()                                     (TRUE != FALSE)
#define Can_HasMailboxSizeOfMailbox()                                 (TRUE != FALSE)
#define Can_HasMailboxTypeOfMailbox()                                 (TRUE != FALSE)
#define Can_HasMaxDataLenOfMailbox()                                  (TRUE != FALSE)
#define Can_HasMemorySectionsIndexOfMailbox()                         (TRUE != FALSE)
#define Can_HasMemorySectionInfo()                                    (TRUE != FALSE)
#define Can_HasMemorySectionStartOfMemorySectionInfo()                (TRUE != FALSE)
#define Can_HasMemorySectionObjects()                                 (TRUE != FALSE)
#define Can_HasHwHandleOfMemorySectionObjects()                       (TRUE != FALSE)
#define Can_HasMailboxElementOfMemorySectionObjects()                 (TRUE != FALSE)
#define Can_HasMailboxHandleOfMemorySectionObjects()                  (TRUE != FALSE)
#define Can_HasPlatformDll_GeneratorVersion()                         (TRUE != FALSE)
#define Can_HasRxFifoData()                                           (TRUE != FALSE)
#define Can_HasControllerOfRxFifoData()                               (TRUE != FALSE)
#define Can_HasFifoDepthOfRxFifoData()                                (TRUE != FALSE)
#define Can_HasFilterStartIndexOfRxFifoData()                         (TRUE != FALSE)
#define Can_HasFilterStopIndexOfRxFifoData()                          (TRUE != FALSE)
#define Can_HasSizeOfActiveSendObject()                               (TRUE != FALSE)
#define Can_HasSizeOfCanIfChannelId()                                 (TRUE != FALSE)
#define Can_HasSizeOfChannelData()                                    (TRUE != FALSE)
#define Can_HasSizeOfControllerConfig()                               (TRUE != FALSE)
#define Can_HasSizeOfControllerData()                                 (TRUE != FALSE)
#define Can_HasSizeOfInitFilterRules()                                (TRUE != FALSE)
#define Can_HasSizeOfInitObjectBaudrate()                             (TRUE != FALSE)
#define Can_HasSizeOfInitObjectBitTiming()                            (TRUE != FALSE)
#define Can_HasSizeOfInitObjectStartIndex()                           (TRUE != FALSE)
#define Can_HasSizeOfMailbox()                                        (TRUE != FALSE)
#define Can_HasSizeOfMemorySectionInfo()                              (TRUE != FALSE)
#define Can_HasSizeOfMemorySectionObjects()                           (TRUE != FALSE)
#define Can_HasSizeOfRxFifoData()                                     (TRUE != FALSE)
#define Can_HasPCConfig()                                             (TRUE != FALSE)
#define Can_HasActiveSendObjectOfPCConfig()                           (TRUE != FALSE)
#define Can_HasBaseDll_GeneratorVersionOfPCConfig()                   (TRUE != FALSE)
#define Can_HasCanIfChannelIdOfPCConfig()                             (TRUE != FALSE)
#define Can_HasChannelDataOfPCConfig()                                (TRUE != FALSE)
#define Can_HasControllerConfigOfPCConfig()                           (TRUE != FALSE)
#define Can_HasControllerDataOfPCConfig()                             (TRUE != FALSE)
#define Can_HasInitFilterRulesOfPCConfig()                            (TRUE != FALSE)
#define Can_HasInitObjectBaudrateOfPCConfig()                         (TRUE != FALSE)
#define Can_HasInitObjectBitTimingOfPCConfig()                        (TRUE != FALSE)
#define Can_HasInitObjectStartIndexOfPCConfig()                       (TRUE != FALSE)
#define Can_HasMailboxOfPCConfig()                                    (TRUE != FALSE)
#define Can_HasMemorySectionInfoOfPCConfig()                          (TRUE != FALSE)
#define Can_HasMemorySectionObjectsOfPCConfig()                       (TRUE != FALSE)
#define Can_HasPlatformDll_GeneratorVersionOfPCConfig()               (TRUE != FALSE)
#define Can_HasRxFifoDataOfPCConfig()                                 (TRUE != FALSE)
#define Can_HasSizeOfActiveSendObjectOfPCConfig()                     (TRUE != FALSE)
#define Can_HasSizeOfCanIfChannelIdOfPCConfig()                       (TRUE != FALSE)
#define Can_HasSizeOfChannelDataOfPCConfig()                          (TRUE != FALSE)
#define Can_HasSizeOfControllerConfigOfPCConfig()                     (TRUE != FALSE)
#define Can_HasSizeOfControllerDataOfPCConfig()                       (TRUE != FALSE)
#define Can_HasSizeOfInitFilterRulesOfPCConfig()                      (TRUE != FALSE)
#define Can_HasSizeOfInitObjectBaudrateOfPCConfig()                   (TRUE != FALSE)
#define Can_HasSizeOfInitObjectBitTimingOfPCConfig()                  (TRUE != FALSE)
#define Can_HasSizeOfInitObjectStartIndexOfPCConfig()                 (TRUE != FALSE)
#define Can_HasSizeOfMailboxOfPCConfig()                              (TRUE != FALSE)
#define Can_HasSizeOfMemorySectionInfoOfPCConfig()                    (TRUE != FALSE)
#define Can_HasSizeOfMemorySectionObjectsOfPCConfig()                 (TRUE != FALSE)
#define Can_HasSizeOfRxFifoDataOfPCConfig()                           (TRUE != FALSE)

#define Can_IncPduOfActiveSendObject(Index)                           Can_GetPduOfActiveSendObject(Index)++
#define Can_IncStateOfActiveSendObject(Index)                         Can_GetStateOfActiveSendObject(Index)++
#define Can_IncBusOffCounterOfControllerData(Index)                   Can_GetBusOffCounterOfControllerData(Index)++
#define Can_IncBusOffTransitionRequestOfControllerData(Index)         Can_GetBusOffTransitionRequestOfControllerData(Index)++
#define Can_IncCanInterruptCounterOfControllerData(Index)             Can_GetCanInterruptCounterOfControllerData(Index)++
#define Can_IncCanInterruptOldStatusOfControllerData(Index)           Can_GetCanInterruptOldStatusOfControllerData(Index)++
#define Can_IncLastInitObjectOfControllerData(Index)                  Can_GetLastInitObjectOfControllerData(Index)++
#define Can_IncLogStatusOfControllerData(Index)                       Can_GetLogStatusOfControllerData(Index)++
#define Can_IncLoopTimeoutOfControllerData(Index)                     Can_GetLoopTimeoutOfControllerData(Index)++
#define Can_IncModeTransitionRequestOfControllerData(Index)           Can_GetModeTransitionRequestOfControllerData(Index)++
#define Can_IncRamCheckTransitionRequestOfControllerData(Index)       Can_GetRamCheckTransitionRequestOfControllerData(Index)++
#define Can_IncRxTmpBufOfControllerData(Index)                        Can_GetRxTmpBufOfControllerData(Index)++

#define Can_DecPduOfActiveSendObject(Index)                           Can_GetPduOfActiveSendObject(Index)--
#define Can_DecStateOfActiveSendObject(Index)                         Can_GetStateOfActiveSendObject(Index)--
#define Can_DecBusOffCounterOfControllerData(Index)                   Can_GetBusOffCounterOfControllerData(Index)--
#define Can_DecBusOffTransitionRequestOfControllerData(Index)         Can_GetBusOffTransitionRequestOfControllerData(Index)--
#define Can_DecCanInterruptCounterOfControllerData(Index)             Can_GetCanInterruptCounterOfControllerData(Index)--
#define Can_DecCanInterruptOldStatusOfControllerData(Index)           Can_GetCanInterruptOldStatusOfControllerData(Index)--
#define Can_DecLastInitObjectOfControllerData(Index)                  Can_GetLastInitObjectOfControllerData(Index)--
#define Can_DecLogStatusOfControllerData(Index)                       Can_GetLogStatusOfControllerData(Index)--
#define Can_DecLoopTimeoutOfControllerData(Index)                     Can_GetLoopTimeoutOfControllerData(Index)--
#define Can_DecModeTransitionRequestOfControllerData(Index)           Can_GetModeTransitionRequestOfControllerData(Index)--
#define Can_DecRamCheckTransitionRequestOfControllerData(Index)       Can_GetRamCheckTransitionRequestOfControllerData(Index)--
#define Can_DecRxTmpBufOfControllerData(Index)                        Can_GetRxTmpBufOfControllerData(Index)--

typedef uint8_least Can_ActiveSendObjectIterType;

typedef uint8_least Can_CanIfChannelIdIterType;

typedef uint8_least Can_ChannelDataIterType;

typedef uint8_least Can_ControllerConfigIterType;

typedef uint8_least Can_InitFilterRulesIterType;

typedef uint8_least Can_InitObjectBaudrateIterType;

typedef uint8_least Can_InitObjectBitTimingIterType;

typedef uint8_least Can_InitObjectStartIndexIterType;

typedef uint8_least Can_MailboxIterType;

typedef uint8_least Can_MemorySectionInfoIterType;

typedef uint8_least Can_MemorySectionObjectsIterType;

typedef uint8_least Can_RxFifoDataIterType;

typedef Can_ControllerConfigIterType Can_ControllerDataIterType;

typedef PduIdType Can_PduOfActiveSendObjectType;

typedef uint16 Can_StateOfActiveSendObjectType;

typedef uint16 Can_BaseDll_GeneratorVersionType;

typedef uint8 Can_CanIfChannelIdType;

typedef uint8 Can_FifoProcCountOfChannelDataType;

typedef uint8 Can_FrStartIndexOfChannelDataType;

typedef uint8 Can_FrTotalCountOfChannelDataType;

typedef uint8 Can_RxBcMaskOfChannelDataType;

typedef uint8 Can_RxBcStartIndexOfChannelDataType;

typedef uint8 Can_RxBcStopIndexOfChannelDataType;

typedef uint8 Can_TxIntMaskOfChannelDataType;

typedef uint8 Can_CanControllerDefaultBaudrateIdxOfControllerConfigType;

typedef uint16 Can_CanControllerDefaultBaudrateOfControllerConfigType;

typedef uint8 Can_MailboxRxBasicEndIdxOfControllerConfigType;

typedef uint8 Can_MailboxRxBasicLengthOfControllerConfigType;

typedef uint8 Can_MailboxRxBasicStartIdxOfControllerConfigType;

typedef boolean Can_MailboxRxBasicUsedOfControllerConfigType;

typedef uint8 Can_MailboxTxBasicEndIdxOfControllerConfigType;

typedef uint8 Can_MailboxTxBasicLengthOfControllerConfigType;

typedef uint8 Can_MailboxTxBasicStartIdxOfControllerConfigType;

typedef boolean Can_MailboxTxBasicUsedOfControllerConfigType;

typedef uint8 Can_RxBasicHwStartOfControllerConfigType;

typedef uint8 Can_RxBasicHwStopOfControllerConfigType;

typedef uint8 Can_RxFullHwStartOfControllerConfigType;

typedef uint8 Can_RxFullHwStopOfControllerConfigType;

typedef uint8 Can_TxBasicHwStartOfControllerConfigType;

typedef uint8 Can_TxBasicHwStopOfControllerConfigType;

typedef uint8 Can_TxFullHwStartOfControllerConfigType;

typedef uint8 Can_TxFullHwStopOfControllerConfigType;

typedef uint8 Can_UnusedHwStartOfControllerConfigType;

typedef uint8 Can_UnusedHwStopOfControllerConfigType;

typedef uint8 Can_BusOffCounterOfControllerDataType;

typedef uint8 Can_BusOffTransitionRequestOfControllerDataType;

typedef uint8 Can_CanInterruptCounterOfControllerDataType;

typedef boolean Can_IsBusOffOfControllerDataType;

typedef uint8 Can_LastInitObjectOfControllerDataType;

typedef uint8 Can_LogStatusOfControllerDataType;

typedef uint8 Can_ModeTransitionRequestOfControllerDataType;

typedef uint8 Can_RamCheckTransitionRequestOfControllerDataType;

typedef uint8 Can_CodeOfInitFilterRulesType;

typedef uint8 Can_MaskOfInitFilterRulesType;

typedef uint16 Can_InitObjectBaudrateType;

typedef uint32 Can_InitObjectBitTimingType;

typedef uint8 Can_InitObjectStartIndexType;

typedef uint8 Can_ActiveSendObjectOfMailboxType;

typedef uint8 Can_ControllerConfigIdxOfMailboxType;

typedef uint8 Can_HwHandleOfMailboxType;

typedef uint8 Can_IDValueOfMailboxType;

typedef uint8 Can_MailboxSizeOfMailboxType;

typedef uint8 Can_MailboxTypeOfMailboxType;

typedef uint8 Can_MaxDataLenOfMailboxType;

typedef uint8 Can_MemorySectionsIndexOfMailboxType;

typedef uint8 Can_MemorySectionStartOfMemorySectionInfoType;

typedef uint8 Can_HwHandleOfMemorySectionObjectsType;

typedef uint8 Can_MailboxElementOfMemorySectionObjectsType;

typedef uint8 Can_MailboxHandleOfMemorySectionObjectsType;

typedef uint16 Can_PlatformDll_GeneratorVersionType;

typedef uint8 Can_ControllerOfRxFifoDataType;

typedef uint8 Can_FifoDepthOfRxFifoDataType;

typedef uint8 Can_FilterStartIndexOfRxFifoDataType;

typedef uint8 Can_FilterStopIndexOfRxFifoDataType;

typedef uint8 Can_SizeOfActiveSendObjectType;

typedef uint8 Can_SizeOfCanIfChannelIdType;

typedef uint8 Can_SizeOfChannelDataType;

typedef uint8 Can_SizeOfControllerConfigType;

typedef uint8 Can_SizeOfControllerDataType;

typedef uint8 Can_SizeOfInitFilterRulesType;

typedef uint8 Can_SizeOfInitObjectBaudrateType;

typedef uint8 Can_SizeOfInitObjectBitTimingType;

typedef uint8 Can_SizeOfInitObjectStartIndexType;

typedef uint8 Can_SizeOfMailboxType;

typedef uint8 Can_SizeOfMemorySectionInfoType;

typedef uint8 Can_SizeOfMemorySectionObjectsType;

typedef uint8 Can_SizeOfRxFifoDataType;

typedef struct sCan_ActiveSendObjectType{
  Can_StateOfActiveSendObjectType StateOfActiveSendObject;
  Can_PduOfActiveSendObjectType PduOfActiveSendObject;
}Can_ActiveSendObjectType;

typedef struct sCan_ChannelDataType{
  Can_FifoProcCountOfChannelDataType FifoProcCountOfChannelData;
  Can_FrStartIndexOfChannelDataType FrStartIndexOfChannelData;
  Can_FrTotalCountOfChannelDataType FrTotalCountOfChannelData;
  Can_RxBcMaskOfChannelDataType RxBcMaskOfChannelData;
  Can_RxBcStartIndexOfChannelDataType RxBcStartIndexOfChannelData;
  Can_RxBcStopIndexOfChannelDataType RxBcStopIndexOfChannelData;
  Can_TxIntMaskOfChannelDataType TxIntMaskOfChannelData;
}Can_ChannelDataType;

typedef struct sCan_ControllerConfigType{
  Can_CanControllerDefaultBaudrateOfControllerConfigType CanControllerDefaultBaudrateOfControllerConfig;
  Can_CanControllerDefaultBaudrateIdxOfControllerConfigType CanControllerDefaultBaudrateIdxOfControllerConfig;
  Can_MailboxRxBasicEndIdxOfControllerConfigType MailboxRxBasicEndIdxOfControllerConfig;
  Can_MailboxRxBasicLengthOfControllerConfigType MailboxRxBasicLengthOfControllerConfig;
  Can_MailboxRxBasicStartIdxOfControllerConfigType MailboxRxBasicStartIdxOfControllerConfig;
  Can_MailboxTxBasicEndIdxOfControllerConfigType MailboxTxBasicEndIdxOfControllerConfig;
  Can_MailboxTxBasicLengthOfControllerConfigType MailboxTxBasicLengthOfControllerConfig;
  Can_MailboxTxBasicStartIdxOfControllerConfigType MailboxTxBasicStartIdxOfControllerConfig;
  Can_RxBasicHwStartOfControllerConfigType RxBasicHwStartOfControllerConfig;
  Can_RxBasicHwStopOfControllerConfigType RxBasicHwStopOfControllerConfig;
  Can_RxFullHwStartOfControllerConfigType RxFullHwStartOfControllerConfig;
  Can_RxFullHwStopOfControllerConfigType RxFullHwStopOfControllerConfig;
  Can_TxBasicHwStartOfControllerConfigType TxBasicHwStartOfControllerConfig;
  Can_TxBasicHwStopOfControllerConfigType TxBasicHwStopOfControllerConfig;
  Can_TxFullHwStartOfControllerConfigType TxFullHwStartOfControllerConfig;
  Can_TxFullHwStopOfControllerConfigType TxFullHwStopOfControllerConfig;
  Can_UnusedHwStartOfControllerConfigType UnusedHwStartOfControllerConfig;
  Can_UnusedHwStopOfControllerConfigType UnusedHwStopOfControllerConfig;
}Can_ControllerConfigType;

typedef struct sCan_ControllerDataType{
  Can_BusOffCounterOfControllerDataType BusOffCounterOfControllerData;
  Can_BusOffTransitionRequestOfControllerDataType BusOffTransitionRequestOfControllerData;
  Can_CanInterruptCounterOfControllerDataType CanInterruptCounterOfControllerData;
  Can_IsBusOffOfControllerDataType IsBusOffOfControllerData;
  Can_LastInitObjectOfControllerDataType LastInitObjectOfControllerData;
  Can_LogStatusOfControllerDataType LogStatusOfControllerData;
  Can_ModeTransitionRequestOfControllerDataType ModeTransitionRequestOfControllerData;
  Can_RamCheckTransitionRequestOfControllerDataType RamCheckTransitionRequestOfControllerData;
  tCanLLCanIntOld CanInterruptOldStatusOfControllerData;
  Can_LoopTimeout_dim_type LoopTimeoutOfControllerData;
  tCanTmpMsgObj RxTmpBufOfControllerData;
}Can_ControllerDataType;

typedef struct sCan_InitFilterRulesType{
  Can_CodeOfInitFilterRulesType CodeOfInitFilterRules;
  Can_MaskOfInitFilterRulesType MaskOfInitFilterRules;
}Can_InitFilterRulesType;

typedef struct sCan_MailboxType{
  Can_ActiveSendObjectOfMailboxType ActiveSendObjectOfMailbox;
  Can_ControllerConfigIdxOfMailboxType ControllerConfigIdxOfMailbox;
  Can_HwHandleOfMailboxType HwHandleOfMailbox;
  Can_IDValueOfMailboxType IDValueOfMailbox;
  Can_MailboxSizeOfMailboxType MailboxSizeOfMailbox;
  Can_MailboxTypeOfMailboxType MailboxTypeOfMailbox;
  Can_MaxDataLenOfMailboxType MaxDataLenOfMailbox;
  Can_MemorySectionsIndexOfMailboxType MemorySectionsIndexOfMailbox;
}Can_MailboxType;

typedef struct sCan_MemorySectionInfoType{
  Can_MemorySectionStartOfMemorySectionInfoType MemorySectionStartOfMemorySectionInfo;
}Can_MemorySectionInfoType;

typedef struct sCan_MemorySectionObjectsType{
  Can_HwHandleOfMemorySectionObjectsType HwHandleOfMemorySectionObjects;
  Can_MailboxElementOfMemorySectionObjectsType MailboxElementOfMemorySectionObjects;
  Can_MailboxHandleOfMemorySectionObjectsType MailboxHandleOfMemorySectionObjects;
}Can_MemorySectionObjectsType;

typedef struct sCan_RxFifoDataType{
  Can_ControllerOfRxFifoDataType ControllerOfRxFifoData;
  Can_FifoDepthOfRxFifoDataType FifoDepthOfRxFifoData;
  Can_FilterStartIndexOfRxFifoDataType FilterStartIndexOfRxFifoData;
  Can_FilterStopIndexOfRxFifoDataType FilterStopIndexOfRxFifoData;
}Can_RxFifoDataType;

typedef P2VAR(Can_ActiveSendObjectType, TYPEDEF, CAN_VAR_NOINIT) Can_ActiveSendObjectPtrType;

typedef P2CONST(Can_CanIfChannelIdType, TYPEDEF, CAN_CONST) Can_CanIfChannelIdPtrType;

typedef P2CONST(Can_ChannelDataType, TYPEDEF, CAN_CONST) Can_ChannelDataPtrType;

typedef P2CONST(Can_ControllerConfigType, TYPEDEF, CAN_CONST) Can_ControllerConfigPtrType;

typedef P2VAR(Can_ControllerDataType, TYPEDEF, CAN_VAR_NOINIT) Can_ControllerDataPtrType;

typedef P2CONST(Can_InitFilterRulesType, TYPEDEF, CAN_CONST) Can_InitFilterRulesPtrType;

typedef P2CONST(Can_InitObjectBaudrateType, TYPEDEF, CAN_CONST) Can_InitObjectBaudratePtrType;

typedef P2CONST(Can_InitObjectBitTimingType, TYPEDEF, CAN_CONST) Can_InitObjectBitTimingPtrType;

typedef P2CONST(Can_InitObjectStartIndexType, TYPEDEF, CAN_CONST) Can_InitObjectStartIndexPtrType;

typedef P2CONST(Can_MailboxType, TYPEDEF, CAN_CONST) Can_MailboxPtrType;

typedef P2CONST(Can_MemorySectionInfoType, TYPEDEF, CAN_CONST) Can_MemorySectionInfoPtrType;

typedef P2CONST(Can_MemorySectionObjectsType, TYPEDEF, CAN_CONST) Can_MemorySectionObjectsPtrType;

typedef P2CONST(Can_RxFifoDataType, TYPEDEF, CAN_CONST) Can_RxFifoDataPtrType;

typedef struct sCan_PCConfigType{
  uint8 Can_PCConfigNeverUsed;
}Can_PCConfigType;

typedef Can_PCConfigType Can_ConfigType;

#define CAN_START_SEC_CONST_8BIT

#include "MemMap.hpp"

extern CONST(Can_CanIfChannelIdType, CAN_CONST) Can_CanIfChannelId[1];
#define CAN_STOP_SEC_CONST_8BIT

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Can_ChannelDataType, CAN_CONST) Can_ChannelData[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Can_ControllerConfigType, CAN_CONST) Can_ControllerConfig[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Can_InitFilterRulesType, CAN_CONST) Can_InitFilterRules[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_16BIT

#include "MemMap.hpp"

extern CONST(Can_InitObjectBaudrateType, CAN_CONST) Can_InitObjectBaudrate[1];
#define CAN_STOP_SEC_CONST_16BIT

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_32BIT

#include "MemMap.hpp"

extern CONST(Can_InitObjectBitTimingType, CAN_CONST) Can_InitObjectBitTiming[1];
#define CAN_STOP_SEC_CONST_32BIT

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_8BIT

#include "MemMap.hpp"

extern CONST(Can_InitObjectStartIndexType, CAN_CONST) Can_InitObjectStartIndex[2];
#define CAN_STOP_SEC_CONST_8BIT

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Can_MailboxType, CAN_CONST) Can_Mailbox[2];
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Can_MemorySectionInfoType, CAN_CONST) Can_MemorySectionInfo[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Can_MemorySectionObjectsType, CAN_CONST) Can_MemorySectionObjects[16];
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(Can_RxFifoDataType, CAN_CONST) Can_RxFifoData[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

extern VAR(Can_ActiveSendObjectType, CAN_VAR_NOINIT) Can_ActiveSendObject[1];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

extern VAR(Can_ControllerDataType, CAN_VAR_NOINIT) Can_ControllerData[1];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#endif

