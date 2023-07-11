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

#include "SwcServiceStartUp.h" //TBD: Move to Det
#include "LibAutosar.h"

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
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallFailsafeUpdater_Entry             (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallSwcServiceStartUp_Entry           (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallSwcServiceStartUpInitCmac_Entry   (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallSwcServiceStartUpInitKey_Entry    (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallSwcServiceStartUpStayInBoot_Entry (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallTarget_Entry                      (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckApplStartFlag                    (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckKeyAvailability                  (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckReprogFlag                       (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckReprogLbt                        (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpLbt             (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpMacErased       (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpValidity        (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpVerification    (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventDefault                               (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventFail_Entry                            (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventFailsafeUpdaterCheck                  (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventFailsafeUpdaterSearchInit             (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventFailsafeUpdaterSearchNext             (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventInit_Entry                            (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventPowerOn_Entry                         (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventTargetCheck                           (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventTargetListInit                        (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventTargetListNext                        (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent);

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCallFailsafeUpdater[CfgSwcServiceStartUp_dNumEventsMachineStateCallFailsafeUpdater] = {
      {SwcServiceStartUp_eHandlerEventCallFailsafeUpdater_Entry,             LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUp[CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUp] = {
      {SwcServiceStartUp_eHandlerEventCallSwcServiceStartUp_Entry,           LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUpInitCmac[CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpInitCmac] = {
      {SwcServiceStartUp_eHandlerEventCallSwcServiceStartUpInitCmac_Entry,   LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUpInitKey[CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpInitKey] = {
      {SwcServiceStartUp_eHandlerEventCallSwcServiceStartUpInitKey_Entry,    LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCallSwcServiceStartUpStayInBoot[CfgSwcServiceStartUp_dNumEventsMachineStateCallSwcServiceStartUpStayInBoot] = {
      {SwcServiceStartUp_eHandlerEventCallSwcServiceStartUpStayInBoot_Entry, LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCallTarget[CfgSwcServiceStartUp_dNumEventsMachineStateCallTarget] = {
      {SwcServiceStartUp_eHandlerEventCallTarget_Entry,                      LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCheckApplStartFlag[CfgSwcServiceStartUp_dNumEventsMachineStateCheckApplStartFlag] = {
      {SwcServiceStartUp_eHandlerEventCheckApplStartFlag,                    LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpLbt}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpVerificationStayInBoot}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCheckKeyAvailability[CfgSwcServiceStartUp_dNumEventsMachineStateCheckKeyAvailability] = {
      {SwcServiceStartUp_eHandlerEventCheckKeyAvailability,                  LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateInitSwcServiceStartUpMacEnabled}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallSwcServiceStartUpInitKey}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCheckReprogFlag[CfgSwcServiceStartUp_dNumEventsMachineStateCheckReprogFlag] = {
      {SwcServiceStartUp_eHandlerEventCheckReprogFlag,                       LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpVerification}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateStayInBootEnabled}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCheckReprogLbt[CfgSwcServiceStartUp_dNumEventsMachineStateCheckReprogLbt] = {
      {SwcServiceStartUp_eHandlerEventCheckReprogLbt,                        LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateTargetListInit}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpVerification}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpLbt[CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpLbt] = {
      {SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpLbt,             LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateReprogLbtEnabled}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpMacErased[CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpMacErased] = {
      {SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpMacErased,       LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallSwcServiceStartUpInitCmac}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckReprogFlag}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpValidity[CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpValidity] = {
      {SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpValidity,        LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateSecureBootEnabled}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFailsafeUpdaterEnabled}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpVerification[CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpVerification] = {
      {SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpVerification,    LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallSwcServiceStartUp}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateCheckSwcServiceStartUpVerificationStayInBoot[CfgSwcServiceStartUp_dNumEventsMachineStateCheckSwcServiceStartUpVerificationStayInBoot] = {
      {SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpVerification,    LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallSwcServiceStartUpStayInBoot}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateFail[CfgSwcServiceStartUp_dNumEventsMachineStateFail] = {
      {SwcServiceStartUp_eHandlerEventFail_Entry,                            LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterCheck[CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterCheck] = {
      {SwcServiceStartUp_eHandlerEventFailsafeUpdaterCheck,                  LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallFailsafeUpdater}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFailsafeUpdaterSearchNext},
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterEnabled[CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterEnabled] = {
      {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_eStateFailsafeUpdaterSearchInit}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterSearchInit[CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterSearchInit] = {
      {SwcServiceStartUp_eHandlerEventFailsafeUpdaterSearchInit,             LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFailsafeUpdaterCheck}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateFailsafeUpdaterSearchNext[CfgSwcServiceStartUp_dNumEventsMachineStateFailsafeUpdaterSearchNext] = {
      {SwcServiceStartUp_eHandlerEventFailsafeUpdaterSearchNext,             LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFailsafeUpdaterCheck}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateInit[CfgSwcServiceStartUp_dNumEventsMachineStateInit] = {
      {SwcServiceStartUp_eHandlerEventInit_Entry,                            LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpValidity}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateInitSwcServiceStartUpMacEnabled[CfgSwcServiceStartUp_dNumEventsMachineStateInitSwcServiceStartUpMacEnabled] = {
      {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_eStateCheckSwcServiceStartUpMacErased}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStatePowerOn[CfgSwcServiceStartUp_dNumEventsMachineStatePowerOn] = {
      {SwcServiceStartUp_eHandlerEventPowerOn_Entry,                         LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_dStateDefault}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateInit}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateReprogLbtEnabled[CfgSwcServiceStartUp_dNumEventsMachineStateReprogLbtEnabled] = {
      {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_eStateCheckReprogLbt}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateSecureBootEnabled[CfgSwcServiceStartUp_dNumEventsMachineStateSecureBootEnabled] = {
      {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_eStateCheckKeyAvailability}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateStayInBootEnabled[CfgSwcServiceStartUp_dNumEventsMachineStateStayInBootEnabled] = {
      {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventEntry,    LibAutosarStateMachine_eStateCheckApplStartFlag}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateTargetCheck[CfgSwcServiceStartUp_dNumEventsMachineStateTargetCheck] = {
      {SwcServiceStartUp_eHandlerEventTargetCheck,                           LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCallTarget}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateTargetListNext}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateTargetListInit[CfgSwcServiceStartUp_dNumEventsMachineStateTargetListInit] = {
      {SwcServiceStartUp_eHandlerEventTargetListInit,                        LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateTargetCheck}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateFail}
};

static const Type_LibAutosarStateMachine_stInfoEvent SwcServiceStartUp_astTableInfoEventMachineStateTargetListNext[CfgSwcServiceStartUp_dNumEventsMachineStateTargetListNext] = {
      {SwcServiceStartUp_eHandlerEventTargetListNext,                        LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateTargetCheck}
   ,  {SwcServiceStartUp_eHandlerEventDefault,                               LibAutosarStateMachine_eEventContinue, LibAutosarStateMachine_eStateCheckSwcServiceStartUpVerification}
};

const Type_LibAutosarStateMachine_stInfoState CfgSwcServiceStartUp_castTableMachineStates[CfgSwcServiceStartUp_dNumMachineStates] = {
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
Type_SwcServiceStartUp_eError SwcServiceStartUp_eError; //TBD: Move to Det

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallFailsafeUpdater_Entry             (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallSwcServiceStartUp_Entry           (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallSwcServiceStartUpInitCmac_Entry   (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallSwcServiceStartUpInitKey_Entry    (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallSwcServiceStartUpStayInBoot_Entry (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCallTarget_Entry                      (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckApplStartFlag                    (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckKeyAvailability                  (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckReprogFlag                       (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckReprogLbt                        (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpLbt             (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpMacErased       (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpValidity        (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventCheckSwcServiceStartUpVerification    (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventDefault                               (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventFail_Entry                            (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventFailsafeUpdaterCheck                  (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventFailsafeUpdaterSearchInit             (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventFailsafeUpdaterSearchNext             (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventInit_Entry                            (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}

static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventPowerOn_Entry(
      Type_LibAutosarStateMachine_tptrContext const ctptrContext
   ,  Type_LibAutosarStateMachine_eEvent            leEvent
){
   UNUSED(ctptrContext);
   UNUSED(leEvent);

   SwcServiceStartUp_eError = SwcServiceStartUp_eError_None;

   return LibAutosarStateMachine_eGaurdTrue;
}

static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventTargetCheck                           (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventTargetListInit                        (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}
static Type_LibAutosarStateMachine_eGaurd SwcServiceStartUp_eHandlerEventTargetListNext                        (Type_LibAutosarStateMachine_tptrContext const ctptrContext, Type_LibAutosarStateMachine_eEvent leEvent){UNUSED(ctptrContext); UNUSED(leEvent); return LibAutosarStateMachine_eGaurdTrue;}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

