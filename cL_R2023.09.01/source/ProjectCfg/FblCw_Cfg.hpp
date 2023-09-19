

#if !defined (FBLCW_CFG_H)
#define FBLCW_CFG_H

#include "Types_SwcServiceCom.hpp"

#ifndef DCM_USE_DUMMY_STATEMENT
#define DCM_USE_DUMMY_STATEMENT STD_ON
#endif
#ifndef DCM_DUMMY_STATEMENT
#define DCM_DUMMY_STATEMENT(v) (v)=(v)
#endif
#ifndef DCM_DUMMY_STATEMENT_CONST
#define DCM_DUMMY_STATEMENT_CONST(v) (void)(v)
#endif
#ifndef DCM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define DCM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF
#endif
#ifndef DCM_ATOMIC_VARIABLE_ACCESS
#define DCM_ATOMIC_VARIABLE_ACCESS 32u
#endif
#ifndef DCM_PROCESSOR_RH850_1013
#define DCM_PROCESSOR_RH850_1013
#endif
#ifndef DCM_COMP_GREENHILLS
#define DCM_COMP_GREENHILLS
#endif
#ifndef DCM_GEN_GENERATOR_MSR
#define DCM_GEN_GENERATOR_MSR
#endif
#ifndef DCM_CPUTYPE_BITORDER_LSB2MSB
#define DCM_CPUTYPE_BITORDER_LSB2MSB
#endif
#ifndef DCM_CONFIGURATION_VARIANT_PRECOMPILE
#define DCM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef DCM_CONFIGURATION_VARIANT_LINKTIME
#define DCM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef DCM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define DCM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef DCM_CONFIGURATION_VARIANT
#define DCM_CONFIGURATION_VARIANT DCM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef DCM_POSTBUILD_VARIANT_SUPPORT
#define DCM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#define FBLCW_DUMMY_STATEMENT(v)         DCM_DUMMY_STATEMENT(v)
#define FBLCW_DEV_ERROR_DETECT           STD_ON
#define FBLCW_DEV_ERROR_REPORT           STD_ON

#define FBLCW_MODULE_NM                  STD_OFF
#define FBLCW_MODULE_CANNM               STD_OFF
#define FBLCW_MODULE_FRNM                STD_OFF

#define FBLCW_MODULE_XCP                 STD_OFF
#define FBLCW_MODULE_CANXCP              STD_OFF
#define FBLCW_MODULE_TCPIPXCP            STD_OFF

#define FBLCW_MODULE_COMM                STD_OFF
#define FBLCW_MODULE_CANSM               STD_OFF
#define FBLCW_MODULE_FRSM                STD_OFF
#define FBLCW_MODULE_ETHSM               STD_OFF

#define FBLCW_MODULE_ETHSWT              STD_OFF
#define FBLCW_MODULE_ETHTRCV             STD_OFF

#define FBLCW_MODULE_DOIP                STD_OFF
#define FBLCW_MODULE_SOAD                STD_OFF
#define FBLCW_MODULE_TCPIP               STD_OFF

#define FBLCW_QUEUED_REQUEST             STD_OFF
#define FBLCW_KEY_SLOT_MODE              STD_OFF
#define FBLCW_BAUDRATE_SWITCH            STD_OFF
#define FBLCW_NW_STATUS_RX_BUFFER_SIZE   0uL
#define FBLCW_TASK_CYCLE                 5u
#define FBLCW_CAN_HARDWARE_LOOP_TIMEOUT  100u
#define FBLCW_DECLINED_REQUESTS          STD_OFF
#define kFblCwMaxNumDeclinedRequests     3u

#if(FBLCW_MODULE_ETHSWT == STD_ON)
#define FBLCW_ETHSWT_MAINFUNCTION()      _MainFunction()
#endif
#if(FBLCW_MODULE_ETHTRCV == STD_ON)
#define FBLCW_ETHTRCV_MAINFUNCTION()     _MainFunction()
#endif

#define FBLCW_CANDRV_HEADER_NAME          "McalCan.hpp"
#define FBLCW_CANSCHM_HEADER_NAME         "SchM_Can.hpp"
#define FBLCW_CAN_MAINFUNCTION_READ       Can_MainFunction_Read
#define FBLCW_CAN_MAINFUNCTION_WRITE      Can_MainFunction_Write
#define FBLCW_CAN_MAINFUNCTION_BUSOFF     Can_MainFunction_BusOff
#define FBLCW_CAN_MAINFUNCTION_MODE       Can_MainFunction_Mode
#define FBLCW_APPLCANTIMERSTART           ApplCanTimerStart
#define FBLCW_APPLCANTIMERLOOP            ApplCanTimerLoop
#define FBLCW_APPLCANTIMEREND             ApplCanTimerEnd
#define FBLCW_CAN_CHANNEL_CANTYPE_FIRST   CAN_CHANNEL_CANTYPE_FIRST
#define FBLCW_TX_PROCESSING               CAN_TX_PROCESSING
#define FBLCW_RX_PROCESSING               CAN_RX_PROCESSING
#define FBLCW_BUSOFF_PROCESSING           CAN_BUSOFF_PROCESSING
#define FBLCW_POLLING                     CAN_POLLING

#define FBLCW_CHANGE_PARAMETER            STD_OFF

#define FBLCW_NW_STATUS_PDU           (FrIfConf_FrIfLPdu_LPdu_FrTrKeySlot1Frame_S_1_B_0_R_1_ChA_IN)

#endif

