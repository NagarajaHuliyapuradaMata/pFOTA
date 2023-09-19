#if !defined(CANTP_LCFG_H)
#define CANTP_LCFG_H

#include "CfgSwcServiceCanTp.hpp"
#include "Types_SwcServiceCanTp.hpp"

typedef uint8_least CanTp_CalcBSIterType;
typedef uint8_least CanTp_RxPduMapIterType;
typedef uint8_least CanTp_RxSduCfgIterType;
typedef uint8_least CanTp_RxSduCfgIndIterType;
typedef uint8_least CanTp_RxSduSnv2HdlIterType;
typedef uint8_least CanTp_RxStateIterType;
typedef uint8_least CanTp_TxSduCfgIterType;
typedef uint8_least CanTp_TxSduCfgIndIterType;
typedef uint8_least CanTp_TxSduSnv2HdlIterType;
typedef uint8_least CanTp_TxSemaphoresIterType;
typedef uint8_least CanTp_TxStateIterType;
typedef uint8 CanTp_CalcBSType;
typedef uint32 CanTp_CompatibilityVersionType;
typedef uint8 CanTp_AddressingFormatOfRxPduMapType;
typedef boolean CanTp_GenericConnectionOfRxPduMapType;
typedef uint8 CanTp_PduMetadataLengthOfRxPduMapType;
typedef uint8 CanTp_RxSduCfgIndEndIdxOfRxPduMapType;
typedef uint8 CanTp_RxSduCfgIndStartIdxOfRxPduMapType;
typedef boolean CanTp_RxSduCfgIndUsedOfRxPduMapType;
typedef uint8 CanTp_TxSduCfgIndEndIdxOfRxPduMapType;
typedef uint8 CanTp_TxSduCfgIndStartIdxOfRxPduMapType;
typedef boolean CanTp_TxSduCfgIndUsedOfRxPduMapType;
typedef uint8 CanTp_BlockSizeOfRxSduCfgType;
typedef uint8 CanTp_CanTypeOfRxSduCfgType;
typedef uint8 CanTp_ChannelModeOfRxSduCfgType;
typedef boolean CanTp_GenericConnectionOfRxSduCfgType;
typedef PduIdType CanTp_LoLayerTxFcPduIdOfRxSduCfgType;
typedef uint8 CanTp_NArOfRxSduCfgType;
typedef uint8 CanTp_NBrOfRxSduCfgType;
typedef uint8 CanTp_NCrOfRxSduCfgType;
typedef boolean CanTp_PassSduMetadataOfRxSduCfgType;
typedef PduIdType CanTp_PduRRxSduIdOfRxSduCfgType;
typedef uint8 CanTp_RxAddressOfRxSduCfgType;
typedef uint8 CanTp_RxAddressingFormatOfRxSduCfgType;
typedef uint8 CanTp_RxMaxPayloadLengthOfRxSduCfgType;
typedef boolean CanTp_RxPaddingActivationOfRxSduCfgType;
typedef PduIdType CanTp_RxPduIdOfRxSduCfgType;
typedef uint8 CanTp_RxTaTypeOfRxSduCfgType;
typedef uint8 CanTp_RxWftMaxOfRxSduCfgType;
typedef uint8 CanTp_STminOfRxSduCfgType;
typedef uint8 CanTp_TxFcAddressOfRxSduCfgType;
typedef PduIdType CanTp_TxFcPduConfirmationPduIdOfRxSduCfgType;
typedef uint8 CanTp_TxSduCfgIdxOfRxSduCfgType;
typedef boolean CanTp_TxSduCfgUsedOfRxSduCfgType;
typedef uint8 CanTp_RxSduCfgIndType;
typedef uint8 CanTp_RxSduCfgIdxOfRxSduSnv2HdlType;
typedef boolean CanTp_RxSduCfgUsedOfRxSduSnv2HdlType;
typedef uint8 CanTp_SizeOfCalcBSType;
typedef uint8 CanTp_SizeOfRxPduMapType;
typedef uint8 CanTp_SizeOfRxSduCfgType;
typedef uint8 CanTp_SizeOfRxSduCfgIndType;
typedef uint8 CanTp_SizeOfRxSduSnv2HdlType;
typedef uint8 CanTp_SizeOfRxStateType;
typedef uint8 CanTp_SizeOfTxSduCfgType;
typedef uint8 CanTp_SizeOfTxSduCfgIndType;
typedef uint8 CanTp_SizeOfTxSduSnv2HdlType;
typedef uint8 CanTp_SizeOfTxSemaphoresType;
typedef uint8 CanTp_SizeOfTxStateType;
typedef uint8 CanTp_CanTypeOfTxSduCfgType;
typedef uint8 CanTp_ChannelModeOfTxSduCfgType;
typedef PduIdType CanTp_LoLayerTxPduIdOfTxSduCfgType;
typedef uint8 CanTp_NAsOfTxSduCfgType;
typedef uint8 CanTp_NBsOfTxSduCfgType;
typedef uint8 CanTp_NCsOfTxSduCfgType;
typedef PduIdType CanTp_PduRTxSduIdOfTxSduCfgType;
typedef uint8 CanTp_RxFcAddressOfTxSduCfgType;
typedef PduIdType CanTp_RxFcPduIdOfTxSduCfgType;
typedef uint8 CanTp_RxSduCfgIdxOfTxSduCfgType;
typedef boolean CanTp_RxSduCfgUsedOfTxSduCfgType;
typedef uint8 CanTp_SduMetadataLengthOfTxSduCfgType;
typedef boolean SwcServiceCanTp_TransmitCancellationOfTxSduCfgType;
typedef uint8 CanTp_TxAddressOfTxSduCfgType;
typedef uint8 CanTp_TxAddressingFormatOfTxSduCfgType;
typedef uint8 CanTp_TxMaxPayloadLengthOfTxSduCfgType;
typedef boolean CanTp_TxPaddingActivationOfTxSduCfgType;
typedef PduIdType CanTp_TxPduConfirmationPduIdOfTxSduCfgType;
typedef uint8 CanTp_TxTaTypeOfTxSduCfgType;
typedef uint8 CanTp_TxSduCfgIndType;
typedef uint8 CanTp_TxSduCfgIdxOfTxSduSnv2HdlType;
typedef boolean CanTp_TxSduCfgUsedOfTxSduSnv2HdlType;

typedef struct sCanTp_RxPduMapType{
   CanTp_RxSduCfgIndEndIdxOfRxPduMapType RxSduCfgIndEndIdxOfRxPduMap;
   CanTp_RxSduCfgIndStartIdxOfRxPduMapType RxSduCfgIndStartIdxOfRxPduMap;
   CanTp_TxSduCfgIndEndIdxOfRxPduMapType TxSduCfgIndEndIdxOfRxPduMap;
   CanTp_TxSduCfgIndStartIdxOfRxPduMapType TxSduCfgIndStartIdxOfRxPduMap;
}CanTp_RxPduMapType;

typedef struct sCanTp_RxSduCfgType{
   CanTp_LoLayerTxFcPduIdOfRxSduCfgType LoLayerTxFcPduIdOfRxSduCfg;
   CanTp_PduRRxSduIdOfRxSduCfgType PduRRxSduIdOfRxSduCfg;
   CanTp_RxPduIdOfRxSduCfgType RxPduIdOfRxSduCfg;
   CanTp_TxFcPduConfirmationPduIdOfRxSduCfgType TxFcPduConfirmationPduIdOfRxSduCfg;
   CanTp_BlockSizeOfRxSduCfgType BlockSizeOfRxSduCfg;
   CanTp_NArOfRxSduCfgType NArOfRxSduCfg;
   CanTp_NCrOfRxSduCfgType NCrOfRxSduCfg;
   CanTp_RxTaTypeOfRxSduCfgType RxTaTypeOfRxSduCfg;
   CanTp_TxSduCfgIdxOfRxSduCfgType TxSduCfgIdxOfRxSduCfg;
}CanTp_RxSduCfgType;

typedef struct sCanTp_RxSduSnv2HdlType{
   CanTp_RxSduCfgIdxOfRxSduSnv2HdlType RxSduCfgIdxOfRxSduSnv2Hdl;
}CanTp_RxSduSnv2HdlType;

typedef struct sCanTp_TxSduCfgType{
   uint8 CanTp_TxSduCfgNeverUsed;
}CanTp_TxSduCfgType;

typedef struct sCanTp_TxSduSnv2HdlType{
   uint8 CanTp_TxSduSnv2HdlNeverUsed;
}CanTp_TxSduSnv2HdlType;

typedef P2VAR(CanTp_CalcBSType, TYPEDEF, CANTP_VAR_NOINIT) CanTp_CalcBSPtrType;
typedef P2CONST(CanTp_RxPduMapType, TYPEDEF, CANTP_CONST) CanTp_RxPduMapPtrType;
typedef P2CONST(CanTp_RxSduCfgType, TYPEDEF, CANTP_CONST) CanTp_RxSduCfgPtrType;
typedef P2CONST(CanTp_RxSduCfgIndType, TYPEDEF, CANTP_CONST) CanTp_RxSduCfgIndPtrType;
typedef P2CONST(CanTp_RxSduSnv2HdlType, TYPEDEF, CANTP_CONST) CanTp_RxSduSnv2HdlPtrType;
typedef P2VAR(CanTp_RxStateType, TYPEDEF, CANTP_VAR_NOINIT) CanTp_RxStatePtrType;
typedef P2CONST(CanTp_TxSduCfgType, TYPEDEF, CANTP_CONST) CanTp_TxSduCfgPtrType;
typedef P2CONST(CanTp_TxSduCfgIndType, TYPEDEF, CANTP_CONST) CanTp_TxSduCfgIndPtrType;
typedef P2CONST(CanTp_TxSduSnv2HdlType, TYPEDEF, CANTP_CONST) CanTp_TxSduSnv2HdlPtrType;
typedef P2VAR(CanTp_TxSemaphoreType, TYPEDEF, CANTP_VAR_NOINIT) CanTp_TxSemaphoresPtrType;
typedef P2VAR(CanTp_TxStateType, TYPEDEF, CANTP_VAR_NOINIT) CanTp_TxStatePtrType;

typedef struct sCanTp_PCConfigType{
   uint8 CanTp_PCConfigNeverUsed;
}CanTp_PCConfigType;

typedef CanTp_PCConfigType CanTp_ConfigType;

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
extern CONST(CanTp_RxPduMapType,     CANTP_CONST) CanTp_RxPduMap[2];
extern CONST(CanTp_RxSduCfgType,     CANTP_CONST) CanTp_RxSduCfg[2];
extern CONST(CanTp_RxSduSnv2HdlType, CANTP_CONST) CanTp_RxSduSnv2Hdl[2];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"


#define CANTP_START_SEC_CONST_8BIT
#include "MemMap.hpp"
extern CONST(CanTp_RxSduCfgIndType, CANTP_CONST) CanTp_RxSduCfgInd[2];
#define CANTP_STOP_SEC_CONST_8BIT
#include "MemMap.hpp"


#define CANTP_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.hpp"
extern VAR(CanTp_CalcBSType, CANTP_VAR_NOINIT) CanTp_CalcBS[2];
#define CANTP_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.hpp"

#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"
extern VAR(CanTp_RxStateType,     CANTP_VAR_NOINIT) CanTp_RxState[2];
extern VAR(CanTp_TxSemaphoreType, CANTP_VAR_NOINIT) CanTp_TxSemaphores[1];
extern VAR(CanTp_TxStateType,     CANTP_VAR_NOINIT) CanTp_TxState[1];
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"

#endif
