

#if !defined (PDUR_DCM_H)
#define PDUR_DCM_H

#include "CfgSwcServicePduR.hpp"

#define PDUR_START_SEC_CODE
#include "MemMap.hpp"

FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);

#define PDUR_STOP_SEC_CODE
#include "MemMap.hpp"

#endif

