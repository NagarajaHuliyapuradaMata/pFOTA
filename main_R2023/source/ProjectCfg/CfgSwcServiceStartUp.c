/******************************************************************************/
/* File   : CfgSwcServiceStartUp.c                                            */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"

#include "CfgSwcServiceStartUp.h"

#include "infSwcApplStartUpCfgSwcServiceStartUp.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CfgSwcServiceStartUp_dNumEventsMachineStateCallFailsafeUpdater                          2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUp                        2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpInitCmac                2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpInitKey                 2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpStayInBoot              2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCallTarget                                   2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCheckApplStartFlag                           2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCheckKeyAvailability                         2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCheckReprogFlag                              2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCheckReprogLbt                               2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpLbt                    2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpMacErased              2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpValidity               2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpVerification           2
#define CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpVerificationStayInBoot 2
#define CfgSwcServiceStartUp_dNumEventsMachineStateFail                                         1
#define CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterCheck                         2
#define CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterEnabled                       1
#define CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterSearchInit                    2
#define CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterSearchNext                    2
#define CfgSwcServiceStartUp_dNumEventsMachineStateInit                                         2
#define CfgSwcServiceStartUp_dNumEventsMachineStateInitSwcServiceStartUpMacEnabled              1
#define CfgSwcServiceStartUp_dNumEventsMachineStatePowerOn                                      2
#define CfgSwcServiceStartUp_dNumEventsMachineStateReprogLbtEnabled                             1
#define CfgSwcServiceStartUp_dNumEventsMachineStateSecureBootEnabled                            1
#define CfgSwcServiceStartUp_dNumEventsMachineStateStayInBootEnabled                            1
#define CfgSwcServiceStartUp_dNumEventsMachineStateTargetCheck                                  2
#define CfgSwcServiceStartUp_dNumEventsMachineStateTargetListInit                               2
#define CfgSwcServiceStartUp_dNumEventsMachineStateTargetListNext                               2

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCallFailsafeUpdater[CfgSwcServiceStartUp_dNumEventsMachineStateCallFailsafeUpdater] = {
      {SwcApplStartUp_eHandlerEventCallFailsafeUpdater_Entry,             LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUp[CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUp] = {
      {SwcApplStartUp_eHandlerEventCallSwcServiceStartUp_Entry,           LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUpInitCmac[CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpInitCmac] = {
      {SwcApplStartUp_eHandlerEventCallSwcServiceStartUpInitCmac_Entry,   LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUpInitKey[CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpInitKey] = {
      {SwcApplStartUp_eHandlerEventCallSwcServiceStartUpInitKey_Entry,    LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUpStayInBoot[CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpStayInBoot] = {
      {SwcApplStartUp_eHandlerEventCallSwcServiceStartUpStayInBoot_Entry, LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCallTarget[CfgSwcServiceStartUp_dNumEventsMachineStateCallTarget] = {
      {SwcApplStartUp_eHandlerEventCallTarget_Entry,                      LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCheckApplStartFlag[CfgSwcServiceStartUp_dNumEventsMachineStateCheckApplStartFlag] = {
      {SwcApplStartUp_eHandlerEventCheckApplStartFlag,                    LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpLbt}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpVerificationStayInBoot}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCheckKeyAvailability[CfgSwcServiceStartUp_dNumEventsMachineStateCheckKeyAvailability] = {
      {SwcApplStartUp_eHandlerEventCheckKeyAvailability,                  LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateInitSwcServiceStartUpMacEnabled}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallSwcServiceStartUpInitKey}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCheckReprogFlag[CfgSwcServiceStartUp_dNumEventsMachineStateCheckReprogFlag] = {
      {SwcApplStartUp_eHandlerEventCheckReprogFlag,                       LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpVerification}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateStayInBootEnabled}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCheckReprogLbt[CfgSwcServiceStartUp_dNumEventsMachineStateCheckReprogLbt] = {
      {SwcApplStartUp_eHandlerEventCheckReprogLbt,                        LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateTargetListInit}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpVerification}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpLbt[CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpLbt] = {
      {SwcApplStartUp_eHandlerEventCheckSwcServiceStartUpLbt,             LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateReprogLbtEnabled}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpMacErased[CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpMacErased] = {
      {SwcApplStartUp_eHandlerEventCheckSwcServiceStartUpMacErased,       LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallSwcServiceStartUpInitCmac}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckReprogFlag}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpValidity[CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpValidity] = {
      {SwcApplStartUp_eHandlerEventCheckSwcServiceStartUpValidity,        LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateSecureBootEnabled}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFailsafeUpdaterEnabled}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpVerification[CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpVerification] = {
      {SwcApplStartUp_eHandlerEventCheckSwcServiceStartUpVerification,    LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallSwcServiceStartUp}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpVerificationStayInBoot[CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpVerificationStayInBoot] = {
      {SwcApplStartUp_eHandlerEventCheckSwcServiceStartUpVerification,    LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallSwcServiceStartUpStayInBoot}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateFail[CfgSwcServiceStartUp_dNumEventsMachineStateFail] = {
      {SwcApplStartUp_eHandlerEventFail_Entry,                            LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterCheck[CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterCheck] = {
      {SwcApplStartUp_eHandlerEventFailsafeUpdaterCheck,                  LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallFailsafeUpdater}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFailsafeUpdaterSearchNext},
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterEnabled[CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterEnabled] = {
      {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_eStateFailsafeUpdaterSearchInit}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterSearchInit[CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterSearchInit] = {
      {SwcApplStartUp_eHandlerEventFailsafeUpdaterSearchInit,             LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFailsafeUpdaterCheck}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterSearchNext[CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterSearchNext] = {
      {SwcApplStartUp_eHandlerEventFailsafeUpdaterSearchNext,             LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFailsafeUpdaterCheck}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateInit[CfgSwcServiceStartUp_dNumEventsMachineStateInit] = {
      {SwcApplStartUp_eHandlerEventInit_Entry,                            LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpValidity}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateInitSwcServiceStartUpMacEnabled[CfgSwcServiceStartUp_dNumEventsMachineStateInitSwcServiceStartUpMacEnabled] = {
      {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_eStateCheckSwcServiceStartUpMacErased}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStatePowerOn[CfgSwcServiceStartUp_dNumEventsMachineStatePowerOn] = {
      {SwcApplStartUp_eHandlerEventPowerOn_Entry,                         LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateInit}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateReprogLbtEnabled[CfgSwcServiceStartUp_dNumEventsMachineStateReprogLbtEnabled] = {
      {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_eStateCheckReprogLbt}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateSecureBootEnabled[CfgSwcServiceStartUp_dNumEventsMachineStateSecureBootEnabled] = {
      {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_eStateCheckKeyAvailability}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateStayInBootEnabled[CfgSwcServiceStartUp_dNumEventsMachineStateStayInBootEnabled] = {
      {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_eStateCheckApplStartFlag}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateTargetCheck[CfgSwcServiceStartUp_dNumEventsMachineStateTargetCheck] = {
      {SwcApplStartUp_eHandlerEventTargetCheck,                           LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallTarget}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateTargetListNext}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateTargetListInit[CfgSwcServiceStartUp_dNumEventsMachineStateTargetListInit] = {
      {SwcApplStartUp_eHandlerEventTargetListInit,                        LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateTargetCheck}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static CONST(Type_LibAutosarStateMachine_stInfoEvent, SWCSERVICESTARTUP_CONFIG_DATA) SwcServiceStartUp_astTableInfoEventMachineStateTargetListNext[CfgSwcServiceStartUp_dNumEventsMachineStateTargetListNext] = {
      {SwcApplStartUp_eHandlerEventTargetListNext,                        LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateTargetCheck}
   ,  {SwcApplStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpVerification}
};

CONST(Type_LibAutosarStateMachine_stInfoState, SWCSERVICESTARTUP_CONFIG_DATA) CfgSwcServiceStartUp_castTableMachineStates[CfgSwcServiceStartUp_dNumMachineStates] = {
      {CfgSwcServiceStartUp_dNumEventsMachineStateCallFailsafeUpdater,                          SwcServiceStartUp_astTableInfoEventMachineStateCallFailsafeUpdater,                          LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUp,                        SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUp,                        LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpInitCmac,                SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUpInitCmac,                LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpInitKey,                 SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUpInitKey,                 LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpStayInBoot,              SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUpStayInBoot,              LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCallTarget,                                   SwcServiceStartUp_astTableInfoEventMachineStateCallTarget,                                   LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCheckApplStartFlag,                           SwcServiceStartUp_astTableInfoEventMachineStateCheckApplStartFlag,                           LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCheckKeyAvailability,                         SwcServiceStartUp_astTableInfoEventMachineStateCheckKeyAvailability,                         LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCheckReprogFlag,                              SwcServiceStartUp_astTableInfoEventMachineStateCheckReprogFlag,                              LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCheckReprogLbt,                               SwcServiceStartUp_astTableInfoEventMachineStateCheckReprogLbt,                               LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpLbt,                    SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpLbt,                    LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpMacErased,              SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpMacErased,              LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpValidity,               SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpValidity,               LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpVerification,           SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpVerification,           LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpVerificationStayInBoot, SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpVerificationStayInBoot, LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateFail,                                         SwcServiceStartUp_astTableInfoEventMachineStateFail,                                         LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterCheck,                         SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterCheck,                         LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterEnabled,                       SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterEnabled,                       LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterSearchInit,                    SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterSearchInit,                    LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterSearchNext,                    SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterSearchNext,                    LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateInit,                                         SwcServiceStartUp_astTableInfoEventMachineStateInit,                                         LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateInitSwcServiceStartUpMacEnabled,              SwcServiceStartUp_astTableInfoEventMachineStateInitSwcServiceStartUpMacEnabled,              LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStatePowerOn,                                      SwcServiceStartUp_astTableInfoEventMachineStatePowerOn,                                      LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateReprogLbtEnabled,                             SwcServiceStartUp_astTableInfoEventMachineStateReprogLbtEnabled,                             LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateSecureBootEnabled,                            SwcServiceStartUp_astTableInfoEventMachineStateSecureBootEnabled,                            LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateStayInBootEnabled,                            SwcServiceStartUp_astTableInfoEventMachineStateStayInBootEnabled,                            LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateTargetCheck,                                  SwcServiceStartUp_astTableInfoEventMachineStateTargetCheck,                                  LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateTargetListInit,                               SwcServiceStartUp_astTableInfoEventMachineStateTargetListInit,                               LibAutosarStateMachine_dStateDefault}
   ,  {CfgSwcServiceStartUp_dNumEventsMachineStateTargetListNext,                               SwcServiceStartUp_astTableInfoEventMachineStateTargetListNext,                               LibAutosarStateMachine_dStateDefault}
};

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

