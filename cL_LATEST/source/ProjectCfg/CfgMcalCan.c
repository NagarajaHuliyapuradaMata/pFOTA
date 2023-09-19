

#define CAN_LCFG_SOURCE

#include "CfgMcalCan.hpp"

#define CAN_START_SEC_CONST_8BIT

#include "MemMap.hpp"

CONST(Can_CanIfChannelIdType, CAN_CONST) Can_CanIfChannelId[1] = {
                0u
};
#define CAN_STOP_SEC_CONST_8BIT

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Can_ChannelDataType, CAN_CONST) Can_ChannelData[1] = {
  {           255u,           0u,           1u,    0x01u,             0u,            1u,     0x00u }
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Can_ControllerConfigType, CAN_CONST) Can_ControllerConfig[1] = {
  {                          500u,                              0u,                   2u  ,                   1u  ,                     1u  ,                   1u  ,                   1u  ,                     0u  ,             0u,            1u,            1u,           1u,             0u,            1u,            1u,           1u,            0u,           0u }
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Can_InitFilterRulesType, CAN_CONST) Can_InitFilterRules[1] = {
  {  0x00u, 0x00u }
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_16BIT

#include "MemMap.hpp"

CONST(Can_InitObjectBaudrateType, CAN_CONST) Can_InitObjectBaudrate[1] = {
                  500u
};
#define CAN_STOP_SEC_CONST_16BIT

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_32BIT

#include "MemMap.hpp"

CONST(Can_InitObjectBitTimingType, CAN_CONST) Can_InitObjectBitTiming[1] = {
            0x023A0001u
};
#define CAN_STOP_SEC_CONST_32BIT

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_8BIT

#include "MemMap.hpp"

CONST(Can_InitObjectStartIndexType, CAN_CONST) Can_InitObjectStartIndex[2] = {
                      0u
   ,                     1u
};
#define CAN_STOP_SEC_CONST_8BIT

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Can_MailboxType, CAN_CONST) Can_Mailbox[2] = {
  {                0u,                  0u  ,       0u,   0x00u,          1u, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                  0u }
   ,  {                0u,                  0u  ,       0u,   0x00u,          4u, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                 16u }
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Can_MemorySectionInfoType, CAN_CONST) Can_MemorySectionInfo[1] = {
  {                  0u }
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Can_MemorySectionObjectsType, CAN_CONST) Can_MemorySectionObjects[16] = {
  {        0u,             0u,            0u }
   ,  {        1u,             0u,            0u }
   ,  {        2u,             0u,            0u }
   ,  {        3u,             0u,            0u }
   ,  {        4u,             0u,            0u }
   ,  {        5u,             0u,            0u }
   ,  {        6u,             0u,            0u }
   ,  {        7u,             0u,            0u }
   ,  {        8u,             0u,            0u }
   ,  {        9u,             0u,            0u }
   ,  {       10u,             0u,            0u }
   ,  {       11u,             0u,            0u }
   ,  {       12u,             0u,            0u }
   ,  {       13u,             0u,            0u }
   ,  {       14u,             0u,            0u }
   ,  {       15u,             0u,            0u }
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Can_RxFifoDataType, CAN_CONST) Can_RxFifoData[1] = {
  {          0u,     0x01u,               0u,              1u }
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(Can_ActiveSendObjectType, CAN_VAR_NOINIT) Can_ActiveSendObject[1];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(Can_ControllerDataType, CAN_VAR_NOINIT) Can_ControllerData[1];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

