#pragma once
/******************************************************************************/
/* File   : CfgSwcServiceStartUp.h                                            */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_SwcServiceStartUp.h"
#include "Types_SwcServiceStartUp.h"

#include "LibAutosar_StateMachine.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CfgSwcServiceStartUp_dNumMachineStates                                29
#define CfgSwcServiceStartUp_dAddressHeader                         0x00000300uL

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
extern CONST(Type_LibAutosarStateMachine_stInfoState, SWCSERVICESTARTUP_CONFIG_DATA) CfgSwcServiceStartUp_castTableMachineStates[CfgSwcServiceStartUp_dNumMachineStates];
extern CONST(Type_SwcServiceStartUp_stHeader,         SWCSERVICESTARTUP_CONFIG_DATA) CfgSwcServiceStartUp_cstHeader;

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

