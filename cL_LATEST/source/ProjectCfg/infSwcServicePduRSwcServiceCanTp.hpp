#if !defined (PDUR_CANTP_H)
#define PDUR_CANTP_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "CfgSwcServicePduR.hpp"

#define PDUR_START_SEC_CODE
#include "MemMap.hpp"
FUNC(void, PDUR_CODE) PduR_CanTpRxIndication(PduIdType id, Std_ReturnType result);
FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation(PduIdType id, Std_ReturnType result);
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);
#define PDUR_STOP_SEC_CODE
#include "MemMap.hpp"

#ifdef __cplusplus
}
#endif
#endif

