#if !defined(DET_CFG_H)
#define DET_CFG_H

#define DET_GENERATOR_CFG5
#define DET_AUTOSARVERSION                       4U
#define DET_ENABLED                              STD_ON
#define DET_VERSION_INFO_API                     STD_OFF
#define DET_DEBUG_ENABLED                        STD_OFF
#define DET_DLTFILTERSIZE                        0u
#define DET_GLOBALFILTERSIZE                     0u
#define DET_BREAKFILTERSIZE                      0u
#define DET_LOGBUFFERSIZE                        0u
#define DET_FORWARD_TO_DLT                       STD_OFF
#define DET_REPORT_ERROR_RECURSIONLIMIT          0u
#define DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT   0u
#define DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT 0u
#define DET_ERRORHOOKTABLE                                            STD_ON
#define DET_FINALMAGICNUMBER                                          STD_OFF
#define DET_INITDATAHASHCODE                                          STD_OFF
#define DET_RUNTIMEERRORCALLOUTTABLE                                  STD_ON
#define DET_SIZEOFERRORHOOKTABLE                                      STD_ON
#define DET_SIZEOFRUNTIMEERRORCALLOUTTABLE                            STD_ON
#define DET_SIZEOFTRANSIENTFAULTCALLOUTTABLE                          STD_ON
#define DET_TRANSIENTFAULTCALLOUTTABLE                                STD_ON
#define DET_PCCONFIG                                                  STD_ON
#define DET_ERRORHOOKTABLEOFPCCONFIG                                  STD_ON
#define DET_FINALMAGICNUMBEROFPCCONFIG                                STD_OFF
#define DET_INITDATAHASHCODEOFPCCONFIG                                STD_OFF
#define DET_RUNTIMEERRORCALLOUTTABLEOFPCCONFIG                        STD_ON
#define DET_SIZEOFERRORHOOKTABLEOFPCCONFIG                            STD_ON
#define DET_SIZEOFRUNTIMEERRORCALLOUTTABLEOFPCCONFIG                  STD_ON
#define DET_SIZEOFTRANSIENTFAULTCALLOUTTABLEOFPCCONFIG                STD_ON
#define DET_TRANSIENTFAULTCALLOUTTABLEOFPCCONFIG                      STD_ON
#define DET_ISDEF_ERRORHOOKTABLE                                      STD_OFF
#define DET_ISDEF_RUNTIMEERRORCALLOUTTABLE                            STD_OFF
#define DET_ISDEF_TRANSIENTFAULTCALLOUTTABLE                          STD_OFF
#define DET_ISDEF_ERRORHOOKTABLEOFPCCONFIG                            STD_ON
#define DET_ISDEF_RUNTIMEERRORCALLOUTTABLEOFPCCONFIG                  STD_ON
#define DET_ISDEF_TRANSIENTFAULTCALLOUTTABLEOFPCCONFIG                STD_ON
#define DET_EQ2_ERRORHOOKTABLE
#define DET_EQ2_RUNTIMEERRORCALLOUTTABLE
#define DET_EQ2_TRANSIENTFAULTCALLOUTTABLE
#define DET_EQ2_ERRORHOOKTABLEOFPCCONFIG                              Det_ErrorHookTable
#define DET_EQ2_RUNTIMEERRORCALLOUTTABLEOFPCCONFIG                    Det_RuntimeErrorCalloutTable
#define DET_EQ2_TRANSIENTFAULTCALLOUTTABLEOFPCCONFIG                  Det_TransientFaultCalloutTable
#define Det_Config_Ptr                                                NULL_PTR
#define Det_Config                                                    NULL_PTR
#define DET_CHECK_INIT_POINTER                                        STD_OFF
#define DET_FINAL_MAGIC_NUMBER                                        0x0F1Eu
#define DET_INDIVIDUAL_POSTBUILD                                      STD_OFF
#define DET_INIT_DATA                                                 DET_CONST
#define DET_INIT_DATA_HASH_CODE                                       1840703899
#define DET_USE_ECUM_BSW_ERROR_HOOK                                   STD_OFF
#define DET_USE_INIT_POINTER                                          STD_OFF

#ifndef DET_USE_DUMMY_STATEMENT
#define DET_USE_DUMMY_STATEMENT STD_ON
#endif
#ifndef DET_DUMMY_STATEMENT
#define DET_DUMMY_STATEMENT(v) (v)=(v)
#endif
#ifndef DET_DUMMY_STATEMENT_CONST
#define DET_DUMMY_STATEMENT_CONST(v) (void)(v)
#endif
#ifndef DET_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define DET_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF
#endif
#ifndef DET_ATOMIC_VARIABLE_ACCESS
#define DET_ATOMIC_VARIABLE_ACCESS 32u
#endif
#ifndef DET_PROCESSOR_RH850_1013
#define DET_PROCESSOR_RH850_1013
#endif
#ifndef DET_COMP_GREENHILLS
#define DET_COMP_GREENHILLS
#endif
#ifndef DET_GEN_GENERATOR_MSR
#define DET_GEN_GENERATOR_MSR
#endif
#ifndef DET_CPUTYPE_BITORDER_LSB2MSB
#define DET_CPUTYPE_BITORDER_LSB2MSB
#endif
#ifndef DET_CONFIGURATION_VARIANT_PRECOMPILE
#define DET_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef DET_CONFIGURATION_VARIANT_LINKTIME
#define DET_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef DET_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define DET_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef DET_CONFIGURATION_VARIANT
#define DET_CONFIGURATION_VARIANT DET_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef DET_POSTBUILD_VARIANT_SUPPORT
#define DET_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#define DET_RUNTIME_ERROR_CALLOUT_ENABLED        DET_RUNTIMEERRORCALLOUTTABLE
#define DET_TRANSIENT_FAULT_CALLOUT_ENABLED      DET_TRANSIENTFAULTCALLOUTTABLE
#define DET_ERROR_HOOK_ENABLED                   DET_ERRORHOOKTABLE
#define Det_GetErrorHookTableOfPCConfig()                             Det_ErrorHookTable
#define Det_GetRuntimeErrorCalloutTableOfPCConfig()                   Det_RuntimeErrorCalloutTable
#define Det_GetSizeOfErrorHookTableOfPCConfig()                       1u
#define Det_GetSizeOfRuntimeErrorCalloutTableOfPCConfig()             1u
#define Det_GetSizeOfTransientFaultCalloutTableOfPCConfig()           1u
#define Det_GetTransientFaultCalloutTableOfPCConfig()                 Det_TransientFaultCalloutTable
#define Det_GetErrorHookTable(Index)                                  (Det_GetErrorHookTableOfPCConfig()[(Index)])
#define Det_GetRuntimeErrorCalloutTable(Index)                        (Det_GetRuntimeErrorCalloutTableOfPCConfig()[(Index)])
#define Det_GetTransientFaultCalloutTable(Index)                      (Det_GetTransientFaultCalloutTableOfPCConfig()[(Index)])
#define Det_GetSizeOfErrorHookTable()                                 Det_GetSizeOfErrorHookTableOfPCConfig()
#define Det_GetSizeOfRuntimeErrorCalloutTable()                       Det_GetSizeOfRuntimeErrorCalloutTableOfPCConfig()
#define Det_GetSizeOfTransientFaultCalloutTable()                     Det_GetSizeOfTransientFaultCalloutTableOfPCConfig()
#define Det_HasErrorHookTable()                                       (TRUE != FALSE)
#define Det_HasRuntimeErrorCalloutTable()                             (TRUE != FALSE)
#define Det_HasSizeOfErrorHookTable()                                 (TRUE != FALSE)
#define Det_HasSizeOfRuntimeErrorCalloutTable()                       (TRUE != FALSE)
#define Det_HasSizeOfTransientFaultCalloutTable()                     (TRUE != FALSE)
#define Det_HasTransientFaultCalloutTable()                           (TRUE != FALSE)
#define Det_HasPCConfig()                                             (TRUE != FALSE)
#define Det_HasErrorHookTableOfPCConfig()                             (TRUE != FALSE)
#define Det_HasRuntimeErrorCalloutTableOfPCConfig()                   (TRUE != FALSE)
#define Det_HasSizeOfErrorHookTableOfPCConfig()                       (TRUE != FALSE)
#define Det_HasSizeOfRuntimeErrorCalloutTableOfPCConfig()             (TRUE != FALSE)
#define Det_HasSizeOfTransientFaultCalloutTableOfPCConfig()           (TRUE != FALSE)
#define Det_HasTransientFaultCalloutTableOfPCConfig()                 (TRUE != FALSE)

typedef P2FUNC(Std_ReturnType, DET_CODE, Det_CalloutTableType)(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
typedef uint8_least Det_ErrorHookTableIterType;
typedef uint8_least Det_RuntimeErrorCalloutTableIterType;
typedef uint8_least Det_TransientFaultCalloutTableIterType;
typedef uint8 Det_SizeOfErrorHookTableType;
typedef uint8 Det_SizeOfRuntimeErrorCalloutTableType;
typedef uint8 Det_SizeOfTransientFaultCalloutTableType;
typedef P2CONST(Det_CalloutTableType, TYPEDEF, DET_CONST) Det_ErrorHookTablePtrType;
typedef P2CONST(Det_CalloutTableType, TYPEDEF, DET_CONST) Det_RuntimeErrorCalloutTablePtrType;
typedef P2CONST(Det_CalloutTableType, TYPEDEF, DET_CONST) Det_TransientFaultCalloutTablePtrType;

typedef struct sDet_PCConfigType{
  uint8 Det_PCConfigNeverUsed;
}Det_PCConfigType;

typedef Det_PCConfigType Det_ConfigType;

#define DET_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(Det_CalloutTableType, DET_CONST) Det_ErrorHookTable[1];
extern CONST(Det_CalloutTableType, DET_CONST) Det_RuntimeErrorCalloutTable[1];
extern CONST(Det_CalloutTableType, DET_CONST) Det_TransientFaultCalloutTable[1];
#define DET_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define DET_START_SEC_CODE
#include "MemMap.hpp"
FUNC(Std_ReturnType, DET_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
#define DET_STOP_SEC_CODE
#include "MemMap.hpp"

#endif
