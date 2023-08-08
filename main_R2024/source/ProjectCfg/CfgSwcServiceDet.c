

#define DET_CFG_SOURCE

#include "SwcServiceDet.hpp"

#define DET_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Det_CalloutTableType, DET_CONST) Det_ErrorHookTable[1] = {
   ApplFbl_DetEntryHandler
};
#define DET_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define DET_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Det_CalloutTableType, DET_CONST) Det_RuntimeErrorCalloutTable[1] = {
   ApplFbl_DetEntryHandler
};
#define DET_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define DET_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Det_CalloutTableType, DET_CONST) Det_TransientFaultCalloutTable[1] = {
   ApplFbl_DetEntryHandler
};
#define DET_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

