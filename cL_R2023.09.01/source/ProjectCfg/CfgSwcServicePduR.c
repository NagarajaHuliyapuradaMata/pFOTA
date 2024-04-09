#define PDUR_LCFG_SOURCE

#include "SwcServicePduR.hpp"
#include "PduR_Fm.hpp"
#include "PduR_IFQ.hpp"
#include "PduR_Sm.hpp"
#include "PduR_RmIf.hpp"
#include "PduR_RmTp.hpp"
#include "PduR_RmTp_TxInst.hpp"
#include "SchM_PduR.hpp"
#if(PDUR_DEV_ERROR_REPORT == STD_ON)
#include "SwcServiceDet.hpp"
#endif

#include "infSwcServicePduRSwcServiceCanTp.hpp"
#include "infSwcServicePduRSwcServiceDcm.hpp"
#include "infSwcServicePduREcuabCanIf.hpp"
#include "infSwcServicePduRCddCom.hpp"

static FUNC(void, PDUR_CODE) PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0(void);
static FUNC(void, PDUR_CODE) PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0(void);

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(PduR_ExclusiveAreaRomType, PDUR_CONST) PduR_ExclusiveAreaRom[1] = {
  {  PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0, PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0 }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[4] = {
  {                 0u,      0x14u,                              1u,                                0u, NULL_PTR            , NULL_PTR            , NULL_PTR                        , NULL_PTR                          , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , EcuabCanIf_Transmit    , NULL_PTR           }
   ,  {                 0u,      0x0Cu,                              2u,                                1u, NULL_PTR            , NULL_PTR            , NULL_PTR                        , NULL_PTR                          , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , NULL_PTR          , SwcServiceCanTp_Transmit     }
   ,  {                 0u,      0x05u,                              4u,                                2u, Dcm_CopyRxData      , Dcm_CopyTxData      , NULL_PTR                        , NULL_PTR                          , Dcm_StartOfReception      , Dcm_TpRxIndication      , Dcm_TpTxConfirmation      , NULL_PTR          , NULL_PTR           }
   ,  {                 0u,      0x02u, PDUR_NO_RMGDESTROMENDIDXOFMMROM, PDUR_NO_RMGDESTROMSTARTIDXOFMMROM, NULL_PTR            , NULL_PTR            , MyCom_Bl_Status_Msg_RxIndication, MyCom_Bl_Status_Msg_TxConfirmation, NULL_PTR                  , NULL_PTR                , NULL_PTR                  , NULL_PTR          , NULL_PTR           }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRom[4] = {
  {             3u,          1u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM }
   ,  {             0u,          2u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM }
   ,  {             1u,          3u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM }
   ,  {             2u,          0u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRom[4] = {
  {                       CanIfConf_CanIfTxPduCfg_BootId_oP1951001_0_003_01_24_RAJA_A1_V_4c4265eb_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           1u }
   ,  {                                                         CanTpConf_CanTpTxNSdu_CanTpTxNSdu_eb0c53ed, PDUR_TX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           2u }
   ,  {  DcmConf_DcmDslProtocolRx_UDS_Rx_Functional_oP1951001_0_003_01_24_RAJA_A1_V_e1de61a7_Rx_00673789, PDUR_RX_DIRECTIONOFRMGDESTROM,       2u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           3u }
   ,  {    DcmConf_DcmDslProtocolRx_UDS_Rx_Physical_oP1951001_0_003_01_24_RAJA_A1_V_3425a492_Rx_6829a205, PDUR_RX_DIRECTIONOFRMGDESTROM,       2u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           0u }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRom[4] = {
  {        1u,              1u,                3u,                                                                            PDUR_NO_SRCHNDOFRMSRCROM }
   ,  {        1u,              1u,                0u,                                                                            PDUR_NO_SRCHNDOFRMSRCROM }
   ,  {        3u,              1u,                1u, MyCom_Bl_Status_MsgConf_CddPduRUpperLayerTxPdu_BootId_oP1951001_0_003_01_24_RAJA_A1_V_f6c6c016_Tx }
   ,  {        2u,              1u,                2u,     DcmConf_DcmDslProtocolTx_UDS_Tx_Physical_oP1951001_0_003_01_24_RAJA_A1_V_4bb359b8_Tx_0ffb8362 }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[2] = {
   PduR_RmIf_RoutePdu           
   ,  PduR_RmTp_Transmit_MultiDest
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2Up[1] = {
  {                TRUE }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define PDUR_START_SEC_VAR_ZERO_INIT_8BIT

#include "MemMap.hpp"

VAR(PduR_InitializedType, PDUR_VAR_ZERO_INIT) PduR_Initialized = FALSE;
#define PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT

#include "MemMap.hpp"

#define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.hpp"

#if(PDUR_USE_INIT_POINTER == STD_ON)
P2CONST(PduR_PBConfigType, PDUR_VAR_ZERO_INIT, PDUR_PBCFG) PduR_ConfigDataPtr = (const PduR_PBConfigType *) NULL_PTR;
#endif

#define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.hpp"

#define PDUR_START_SEC_CODE

#include "MemMap.hpp"

static FUNC(void, PDUR_CODE) PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0(void){
  SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
}

static FUNC(void, PDUR_CODE) PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0(void){
  SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
}

FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info){
  Std_ReturnType retVal = E_NOT_OK;

#if(PDUR_TX2LO == STD_ON)
  retVal = PduR_UpTransmit(id, info);
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);
  PDUR_DUMMY_STATEMENT(info);

  return retVal;
}

FUNC(Std_ReturnType, PDUR_CODE) PduR_MyCom_Bl_Status_MsgTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info){
  Std_ReturnType retVal = E_NOT_OK;

#if(PDUR_TX2LO == STD_ON)
  retVal = PduR_UpTransmit(id, info);
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);
  PDUR_DUMMY_STATEMENT(info);

  return retVal;
}

FUNC(void, PDUR_CODE) PduR_CanIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info){
#if(PDUR_RXIF2DEST == STD_ON)
  PduR_LoIfRxIndication(RxPduId, info);
#else
  PduR_Det_ReportError(PDUR_FCT_IFRXIND, PDUR_E_PDU_ID_INVALID);
#endif
  PDUR_DUMMY_STATEMENT(RxPduId);
  PDUR_DUMMY_STATEMENT(info);   		
}

FUNC(void, PDUR_CODE) PduR_CanIfTxConfirmation(PduIdType TxPduId){
#if(PDUR_TXCONFIRMATIONUSEDOFTXIF2UP == STD_ON)
  PduR_LoIfTxConfirmation(TxPduId);
#endif
  PDUR_DUMMY_STATEMENT(TxPduId);
}

FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr){
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

#if(PDUR_RXTP2DEST == STD_ON)
  retVal = PduR_LoTpStartOfReception(id, info, TpSduLength, bufferSizePtr);
#else
  PduR_Det_ReportError(PDUR_FCT_SOR, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     		
  PDUR_DUMMY_STATEMENT(info);   		
  PDUR_DUMMY_STATEMENT(TpSduLength);
  PDUR_DUMMY_STATEMENT(bufferSizePtr);

  return retVal;
}

FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr){
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

#if(PDUR_RXTP2DEST == STD_ON)
  retVal = PduR_LoTpCopyRxData(id, info, bufferSizePtr);
#else
  PduR_Det_ReportError(PDUR_FCT_CPYRX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     		
  PDUR_DUMMY_STATEMENT(info);  			
  PDUR_DUMMY_STATEMENT(bufferSizePtr);

  return retVal;
}

FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr){
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

#if(PDUR_TXTP2SRC == STD_ON)
  retVal = PduR_LoTpCopyTxData(id, info, retry, availableDataPtr);
#else
  PduR_Det_ReportError(PDUR_FCT_CPYTX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     				
  PDUR_DUMMY_STATEMENT(info);  					
  PDUR_DUMMY_STATEMENT(retry);  				
  PDUR_DUMMY_STATEMENT(availableDataPtr);

  return retVal;
}

FUNC(void, PDUR_CODE) PduR_CanTpRxIndication(PduIdType id, Std_ReturnType result){
#if(PDUR_RXTP2DEST == STD_ON)
  PduR_LoTpRxIndication(id, result);
#else
  PduR_Det_ReportError(PDUR_FCT_TPRXIND, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);
  PDUR_DUMMY_STATEMENT(result);
}

FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation(PduIdType id, Std_ReturnType result){
#if(PDUR_TXTP2SRC == STD_ON)
  PduR_LoTpTxConfirmation(id, result);
#else
  PduR_Det_ReportError(PDUR_FCT_TPTXCFM, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);
  PDUR_DUMMY_STATEMENT(result);
}

#define PDUR_STOP_SEC_CODE

#include "MemMap.hpp"

