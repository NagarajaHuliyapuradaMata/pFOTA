

#if !defined (PDUR_MYCOM_BL_STATUS_MSG_H)
#define PDUR_MYCOM_BL_STATUS_MSG_H

#include "CfgSwcServicePduR.hpp"

#define PDUR_START_SEC_CODE
#include "MemMap.hpp"

FUNC(Std_ReturnType, PDUR_CODE) PduR_MyCom_Bl_Status_MsgTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);

#define PDUR_STOP_SEC_CODE
#include "MemMap.hpp"

#endif

