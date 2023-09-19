#define CANIF_LCFG_SOURCE

#include "CfgEcuabCanIf.hpp"
#include "CfgSwcServiceCanTp.hpp"
#include "CanTp_Cbk.hpp"
#include "CfgSwcServicePduR.hpp"
#include "infSwcServicePduREcuabCanIf.hpp"
#include "CanIf_Cdd.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
CONST(Type_CfgEcuabCanIf_FctNotificationBusOff,  CANIF_CONST) CfgEcuabCanIf_fptrNotificationBusOff = FblCw_ControllerBusOff;
CONST(Type_CfgEcuabCanIf_IdCtrl2MappedBuffersTx, CANIF_CONST) CfgEcuabCanIf_IdCtrl2MappedBuffersTx[1] = {{1u, 0u}};
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = FblCw_ControllerModeIndication;

CONST(Type_CfgEcuabCanIf_MailBox, CANIF_CONST) CfgEcuabCanIf_MailBox[2] = {
      {0u, 0u, 0u, 0u,                                     CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox}
   ,  {0u, 0u, 1u, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG, CANIF_TXBUFFER_HANDLINGTYPE_NONE,        CANIF_RxBasicCANMailbox}
};

CONST(Type_CfgEcuabCanIf_BuffersTxMapped, CANIF_CONST) CfgEcuabCanIf_BuffersTxMapped[1] = {{0u}};

CONST(Type_CfgEcuabCanIf_ListFctIndicationRx, CANIF_CONST) CfgEcuabCanIf_ListFctIndicationRx[2] = {
      {{(CanIf_SimpleRxIndicationFctType)NULL_PTR},           CanIf_SimpleRxIndicationLayout}
   ,  {{(CanIf_SimpleRxIndicationFctType)CanTp_RxIndication}, CanIf_AdvancedRxIndicationLayout}
};

CONST(Type_CfgEcuabCanIf_PduRx, CANIF_CONST) CfgEcuabCanIf_PduRx[2] = {
      {0x07DFu, 0x47FFu, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_062d19b1, 0u, 1u}
   ,  {0x073Au, 0x07FFu, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_307d0297, 0u, 1u}
};

CONST(Type_CfgEcuabCanIf_QueueBufferTxPrioByIdCan, CANIF_CONST) CfgEcuabCanIf_QueueBufferTxPrioByIdCan[1] = {{0u, 2u, 2u, 0u}};

CONST(Type_CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCan, CANIF_CONST) CfgEcuabCanIf_QueueBufferPdusMappedTxPrioByIdCan[2] = {
      {0u}
   ,  {1u}
};

CONST(Type_EcuabCanIf_FctConfirmationTx, CANIF_CONST) EcuabCanIf_ListFctConfirmationTx[3] = {
      (Type_EcuabCanIf_FctConfirmationTx)NULL_PTR
   ,  CanTp_TxConfirmation
   ,  PduR_CanIfTxConfirmation
};

CONST(Type_EcuabCanIf_PduTx, CANIF_CONST) EcuabCanIf_PduTx[2] = {
      {0x077Au, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_307d0297                           , 0u, 8u, 0u, 1u}
   ,  {0x057Au, PduRConf_PduRDestPdu_BootId_oP1951001_0_003_01_24_Rivian_A1_V_3098033a_Tx, 0u, 8u, 0u, 2u}
};

CONST(Type_EcuabCanIf_IndexQueuePduTx, CANIF_CONST) EcuabCanIf_IndexQueuePduTx[2] = {
      {0u}
   ,  {1u}
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"
VAR(Type_EcuabCanIf_StatesCtrl,              CANIF_VAR_NOINIT) EcuabCanIf_StatesCtrl;
VAR(Type_EcuabCanIf_BufferTxPrioByIdCanBase, CANIF_VAR_NOINIT) EcuabCanIf_BufferTxPrioByIdCanBase;
VAR(Type_EcuabCanIf_QueueTx,                 CANIF_VAR_NOINIT) EcuabCanIf_QueueTx;
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"

