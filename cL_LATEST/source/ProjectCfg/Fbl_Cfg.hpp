#if !defined(__FBL_CFG_H__)
#define __FBL_CFG_H__

#ifndef FBL_USE_DUMMY_STATEMENT
#define FBL_USE_DUMMY_STATEMENT STD_ON
#endif
#ifndef FBL_DUMMY_STATEMENT
#define FBL_DUMMY_STATEMENT(v) (v)=(v)
#endif
#ifndef FBL_DUMMY_STATEMENT_CONST
#define FBL_DUMMY_STATEMENT_CONST(v) (void)(v)
#endif
#ifndef FBL_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FBL_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF
#endif
#ifndef FBL_ATOMIC_VARIABLE_ACCESS
#define FBL_ATOMIC_VARIABLE_ACCESS 32u
#endif
#ifndef FBL_PROCESSOR_RH850_1013
#define FBL_PROCESSOR_RH850_1013
#endif
#ifndef FBL_COMP_GREENHILLS
#define FBL_COMP_GREENHILLS
#endif
#ifndef FBL_GEN_GENERATOR_MSR
#define FBL_GEN_GENERATOR_MSR
#endif
#ifndef FBL_CPUTYPE_BITORDER_LSB2MSB
#define FBL_CPUTYPE_BITORDER_LSB2MSB
#endif
#ifndef FBL_CONFIGURATION_VARIANT_PRECOMPILE
#define FBL_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FBL_CONFIGURATION_VARIANT_LINKTIME
#define FBL_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FBL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FBL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FBL_CONFIGURATION_VARIANT
#define FBL_CONFIGURATION_VARIANT FBL_CONFIGURATION_VARIANT_LINKTIME
#endif
#ifndef FBL_POSTBUILD_VARIANT_SUPPORT
#define FBL_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#define FBL_ENABLE_STAY_IN_BOOT
#define FBL_USE_OWN_MEMCPY
#define FBL_WATCHDOG_ON
#define FBL_WATCHDOG_TIME                        (1u / FBL_REPEAT_CALL_CYCLE)
#define FBL_HEADER_ADDRESS                       0x00000360uL
#define FBL_ENABLE_APPL_TIMER_TASK
#define FBL_ENABLE_APPL_TASK
#define FBL_ENABLE_APPL_STATE_TASK
#define SWM_DATA_MAX_NOAR                        8u
#define FBL_DIAG_BUFFER_LENGTH                   4095uL
#define FBL_DIAG_TIME_P2MAX                      (10uL / FBL_REPEAT_CALL_CYCLE)
#define FBL_DIAG_TIME_P3MAX                      (5000uL / FBL_REPEAT_CALL_CYCLE)
#define FBL_DISABLE_SLEEPMODE
#define FBL_SLEEP_TIME                           300000uL
#define FBL_ENABLE_GAP_FILL
#define kFillChar                                0xFFu
#define FBL_DISABLE_GATEWAY_SUPPORT
#define FBL_DISABLE_PRESENCE_PATTERN
#define FBL_DISABLE_FBL_START
#define FBL_DISABLE_COMMON_DATA
#define FBL_ENABLE_RESPONSE_AFTER_RESET
#define FBL_ENABLE_USERSUBFUNCTION
#define FBL_ENABLE_USERSERVICE
#define FBL_DISABLE_USERROUTINE
#define FBL_DIAG_TIME_S3EXT                      (0uL / FBL_REPEAT_CALL_CYCLE)
#define FBL_DIAG_TIME_S3PRG                      (0uL / FBL_REPEAT_CALL_CYCLE)
#define FBL_DIAG_DISABLE_FLASHDRV_DOWNLOAD
#define FBL_DIAG_ENABLE_FLASHDRV_ROM
#define FBL_DISABLE_DATA_PROCESSING
#define FBL_DISABLE_ENCRYPTION_MODE
#define FBL_DISABLE_COMPRESSION_MODE
#define FBL_INTEGRATION                          2uL
#define FBL_PRODUCTION                           1uL
#define FBL_PROJECT_STATE                        FBL_INTEGRATION
#define FBL_ENABLE_SYSTEM_CHECK
#define FBL_ENABLE_DEBUG_STATUS
#define FBL_ENABLE_ASSERTION
#define FBL_MEM_PROC_BUFFER_SIZE                 256uL
#define FBL_MEM_DISABLE_VERIFY_INPUT
#define FBL_MEM_DISABLE_VERIFY_PROCESSED
#define FBL_MEM_DISABLE_VERIFY_PIPELINED
#define FBL_MEM_ENABLE_VERIFY_OUTPUT
#define FBL_MEM_VERIFY_SEGMENTATION              256uL
#define FBL_DISABLE_ADAPTIVE_DATA_TRANSFER_RCRRP
#define FBL_DISABLE_PIPELINED_PROGRAMMING
#define FBL_DISABLE_SUSPEND_PROGRAMMING
#define FBL_MEM_WRITE_SEGMENTATION               256uL
#define FBL_ENABLE_UNALIGNED_DATA_TRANSFER
#define FBL_BLOCK_START_ADDRESS                  0x00000000uL
#define FBL_BLOCK_LENGTH                         131072uL

#include "FblHal_Cfg.hpp"

#define FBL_ENABLE_SEC_ACCESS_DELAY
#define FBL_SEC_ACCESS_DELAY_TIME                        0uL
#define FBL_DIAG_COMMUNICATION_CONTROL_TYPE              kDiagSubEnableRxAndDisableTx
#define FBL_DIAG_DISABLE_CONTROLDTC_OPTIONRECORD
#define FBL_DIAG_DISABLE_CHECK_PROGRAMMING_PRECONDITIONS
#define FBL_APPL_DISABLE_STARTUP_DEPENDENCY_CHECK
#define FBL_DIAG_ENABLE_PROCESS_DATA_STORAGE

#define FBL_ENABLE_VECTOR_HW

#define V_ENABLE_USE_DUMMY_STATEMENT

#define kFblDiagSubRequestSeed   0x01
#define kFblDiagSubSendKey      0x02

#define kDiagRqlWriteDataByIdentifierFingerPrintParameter  23

#define kFblMainStartMessageDelay   50u

#endif

