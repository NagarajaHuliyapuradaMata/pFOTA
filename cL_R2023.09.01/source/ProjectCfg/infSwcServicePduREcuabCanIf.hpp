#if !defined (PDUR_CANIF_H)
#define PDUR_CANIF_H

#include "CfgSwcServicePduR.hpp"

#define PDUR_START_SEC_CODE
#include "MemMap.hpp"
FUNC(void, PDUR_CODE) PduR_CanIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
FUNC(void, PDUR_CODE) PduR_CanIfTxConfirmation(PduIdType TxPduId);
#define PDUR_STOP_SEC_CODE
#include "MemMap.hpp"

#endif

