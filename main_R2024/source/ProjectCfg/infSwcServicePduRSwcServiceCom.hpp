#if !defined (PDUR_COM_H)
# define PDUR_COM_H

#include "CfgSwcServicePduR.hpp"

#define PDUR_START_SEC_CODE
# include "MemMap.hpp"
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#define PDUR_STOP_SEC_CODE
# include "MemMap.hpp"

#endif

