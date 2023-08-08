

#define CANTP_LCFG_SOURCE

#include "SwcServiceCanTp_Lcfg.hpp"
#if(CANTP_LOLAYER_CANIF == STD_ON)
# include "EcuabCanIf.hpp"
#endif
#include "infSwcServicePduRSwcServiceCanTp.hpp"

#define CANTP_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanTp_RxPduMapType, CANTP_CONST) CanTp_RxPduMap[2] = {
  {                 1u,                  0u,                                   1u,                                     0u },
  {                 2u,                  1u, CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP, CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANTP_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfg[2] = {
  {  CANTP_INVALID_HDL                                                                       , PduRConf_PduRSrcPdu_PduRSrcPdu_985a394f, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_062d19b1, CANTP_INVALID_HDL                             ,        8u, 11u,  11u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },
  {  CanIfConf_CanIfTxPduCfg_UDS_Tx_Physical_Tp_oP1951001_0_003_01_24_Rivian_A1_V_bbbad787_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_096fbb61, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_307d0297, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_307d0297,        0u, 21u, 101u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,                             0u }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANTP_START_SEC_CONST_8BIT

#include "MemMap.hpp"

CONST(CanTp_RxSduCfgIndType, CANTP_CONST) CanTp_RxSduCfgInd[2] = {
             1u,
             0u
};
#define CANTP_STOP_SEC_CONST_8BIT

#include "MemMap.hpp"

#define CANTP_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CanTp_RxSduSnv2HdlType, CANTP_CONST) CanTp_RxSduSnv2Hdl[2] = {
  {           0u },
  {           1u }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CANTP_START_SEC_VAR_NOINIT_8BIT

#include "MemMap.hpp"

VAR(CanTp_CalcBSType, CANTP_VAR_NOINIT) CanTp_CalcBS[2];
#define CANTP_STOP_SEC_VAR_NOINIT_8BIT

#include "MemMap.hpp"

#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(CanTp_RxStateType, CANTP_VAR_NOINIT) CanTp_RxState[2];
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(CanTp_TxSemaphoreType, CANTP_VAR_NOINIT) CanTp_TxSemaphores[1];
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(CanTp_TxStateType, CANTP_VAR_NOINIT) CanTp_TxState[1];
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

