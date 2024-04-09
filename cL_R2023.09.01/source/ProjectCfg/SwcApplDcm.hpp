#if !defined (DCM_CBK_H)
#define DCM_CBK_H

#include "Platform_Types.hpp"
#include "Types_SwcServiceCom.hpp"

#define DcmConf_DcmDslProtocolRx_UDS_Rx_Functional_oP1951001_0_003_01_24_RAJA_A1_V_e1de61a7_Rx_00673789 0
#define DcmConf_DcmDslProtocolRx_UDS_Rx_Physical_oP1951001_0_003_01_24_RAJA_A1_V_3425a492_Rx_6829a205   1
#define DcmConf_DcmDslProtocolTx_UDS_Tx_Physical_oP1951001_0_003_01_24_RAJA_A1_V_4bb359b8_Tx_0ffb8362   0

#define FBLCW_START_SEC_CODE
#include "MemMap.hpp"
FUNC(BufReq_ReturnType, FBLCW_CODE) Dcm_StartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, FBLCW_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, FBLCW_APPL_DATA) bufferSizePtr);
FUNC(BufReq_ReturnType, FBLCW_CODE) Dcm_CopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, FBLCW_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, FBLCW_APPL_DATA) bufferSizePtr);
FUNC(void, FBLCW_CODE) Dcm_TpRxIndication(PduIdType id, Std_ReturnType result);
FUNC(BufReq_ReturnType, FBLCW_CODE) Dcm_CopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, FBLCW_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, FBLCW_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, FBLCW_APPL_DATA) availableDataPtr);
FUNC(void, FBLCW_CODE) Dcm_TpTxConfirmation(PduIdType id, Std_ReturnType result);
#define FBLCW_STOP_SEC_CODE
#include "MemMap.hpp"

#endif

