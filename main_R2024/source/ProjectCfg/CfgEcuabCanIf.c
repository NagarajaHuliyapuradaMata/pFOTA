

#define CANIF_LCFG_SOURCE

#include "CfgEcuabCanIf.hpp"

#include "CfgSwcServiceCanTp.hpp"
#include "CanTp_Cbk.hpp"

#include "CfgSwcServicePduR.hpp"
#include "infSwcServicePduREcuabCanIf.hpp"

#include "CanIf_Cdd.hpp"

#define CANIF_START_SEC_APPL_CODE

#include "MemMap.hpp"

#define CANIF_STOP_SEC_APPL_CODE

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = FblCw_ControllerBusOff;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[1] = {
  {                           1u  ,                            0u   }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = FblCw_ControllerModeIndication;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[2] = {
  {             0u  ,         0u  ,        0u  ,                                     0u  , CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox },
  {             0u  ,         0u            ,        1u           , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG                                  , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1] = {
  {                0u   }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(EcuabCanIf_RxIndicationFctListType, CANIF_CONST) EcuabCanIf_RxIndicationFctList[2] = {
  {   { (CanIf_SimpleRxIndicationFctType)NULL_PTR }          , CanIf_SimpleRxIndicationLayout      },
  {   { (CanIf_SimpleRxIndicationFctType)CanTp_RxIndication }, CanIf_AdvancedRxIndicationLayout    }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[2] = {
  {     0x07DFu  ,   0x47FFu  , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_062d19b1,  0u,                     1u   },
  {     0x073Au    ,   0x07FFu    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_307d0297,  0u,                     1u   }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1] = {
  {                          0u  ,                                             2u  ,                                             2u  ,                                               0u   }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[2] = {
  {              0u   },
  {              1u               }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(EcuabCanIf_TxConfirmationFctType, CANIF_CONST) EcuabCanIf_TxConfirmationFctList[3] = {
   (EcuabCanIf_TxConfirmationFctType)NULL_PTR ,
   CanTp_TxConfirmation                  ,
   PduR_CanIfTxConfirmation
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[2] = {
  {  0x077Au, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_307d0297                           ,            0u  ,  8u,               0u  ,                       1u       },
  {  0x057Au, PduRConf_PduRDestPdu_BootId_oP1951001_0_003_01_24_Rivian_A1_V_3098033a_Tx,            0u  ,  8u,               0u  ,                       2u   }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[2] = {
  {          0u   },
  {          1u               }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

