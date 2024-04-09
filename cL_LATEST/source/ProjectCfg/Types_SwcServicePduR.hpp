#if !defined (PDUR_TYPES_H)
#define PDUR_TYPES_H

#define PDUR_MAX_NUMBER_OF_CORES   1

#include "Types_SwcServiceCom.hpp"

typedef P2VAR(PduInfoType, TYPEDEF, PDUR_APPL_DATA) PduInfoTypeApplPtr;
typedef       uint16                                PduR_RoutingPathGroupIdType;
typedef       uint8                                 PduR_Lock_SpinLockCounterArrayType[PDUR_MAX_NUMBER_OF_CORES];

#endif

