

#if !defined (FBLCW_LCFG_H)
# define FBLCW_LCFG_H

# include "Types_SwcServiceCom.hpp"

#define FBLCW_CANIFCTRLINFO                                           STD_ON
#define FBLCW_COMMETHCHANNELINFO                                      STD_OFF
#define FBLCW_COMMFRCHANNELINFO                                       STD_OFF
#define FBLCW_COMMFRNMCHANNELINFO                                     STD_OFF
#define FBLCW_DCMDSLBROADCASTGROUPINFO                                STD_OFF
#define FBLCW_SNVOFDCMDSLBROADCASTGROUPINFO                           STD_OFF
#define FBLCW_DCMDSLBROADCASTGROUPINFOIND                             STD_OFF
#define FBLCW_DCMDSLCONNECTIONGROUPINFO                               STD_OFF
#define FBLCW_SNVOFDCMDSLCONNECTIONGROUPINFO                          STD_OFF
#define FBLCW_DCMDSLCONNECTIONGROUPINFOIND                            STD_OFF
#define FBLCW_DCMDSLCONNECTIONINFO                                    STD_ON
#define FBLCW_BUSTYPEOFDCMDSLCONNECTIONINFO                           STD_ON
#define FBLCW_CONTROLLEROFDCMDSLCONNECTIONINFO                        STD_ON
#define FBLCW_DCMDSLBROADCASTGROUPINFOIDXOFDCMDSLCONNECTIONINFO       STD_OFF
#define FBLCW_DCMDSLBROADCASTGROUPINFOINDENDIDXOFDCMDSLCONNECTIONINFO STD_OFF
#define FBLCW_DCMDSLBROADCASTGROUPINFOINDSTARTIDXOFDCMDSLCONNECTIONINFO STD_OFF
#define FBLCW_DCMDSLBROADCASTGROUPINFOINDUSEDOFDCMDSLCONNECTIONINFO   STD_OFF
#define FBLCW_DCMDSLBROADCASTGROUPINFOUSEDOFDCMDSLCONNECTIONINFO      STD_OFF
#define FBLCW_DCMDSLCONNECTIONGROUPINFOINDENDIDXOFDCMDSLCONNECTIONINFO STD_OFF
#define FBLCW_DCMDSLCONNECTIONGROUPINFOINDSTARTIDXOFDCMDSLCONNECTIONINFO STD_OFF
#define FBLCW_DCMDSLCONNECTIONGROUPINFOINDUSEDOFDCMDSLCONNECTIONINFO  STD_OFF
#define FBLCW_PARAMETERINFOIDXOFDCMDSLCONNECTIONINFO                  STD_OFF
#define FBLCW_PARAMETERINFOUSEDOFDCMDSLCONNECTIONINFO                 STD_OFF
#define FBLCW_PAYLOADLIMITOFDCMDSLCONNECTIONINFO                      STD_ON
#define FBLCW_RXTESTERSOURCEADDRESSOFDCMDSLCONNECTIONINFO             STD_ON
#define FBLCW_TXREMOTEPDUIDOFDCMDSLCONNECTIONINFO                     STD_ON
#define FBLCW_DCMDSLPROTOCOLRXINFO                                    STD_ON
#define FBLCW_ADDRTYPEOFDCMDSLPROTOCOLRXINFO                          STD_ON
#define FBLCW_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLRXINFO           STD_ON
#define FBLCW_INVALIDHNDOFDCMDSLPROTOCOLRXINFO                        STD_OFF
#define FBLCW_DCMDSLPROTOCOLTXINFO                                    STD_ON
#define FBLCW_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLTXINFO           STD_ON
#define FBLCW_INVALIDHNDOFDCMDSLPROTOCOLTXINFO                        STD_OFF
#define FBLCW_FINALMAGICNUMBER                                        STD_OFF
#define FBLCW_INITDATAHASHCODE                                        STD_OFF
#define FBLCW_INITIALBS                                               STD_OFF
#define FBLCW_INITIALSTMIN                                            STD_OFF
#define FBLCW_INITIALIZED                                             STD_ON
#define FBLCW_PARAMETERINFO                                           STD_OFF
#define FBLCW_CANTPIDOFPARAMETERINFO                                  STD_OFF
#define FBLCW_PDURIDOFPARAMETERINFO                                   STD_OFF
#define FBLCW_SIZEOFCANIFCTRLINFO                                     STD_ON
#define FBLCW_SIZEOFDCMDSLCONNECTIONINFO                              STD_ON
#define FBLCW_SIZEOFDCMDSLPROTOCOLRXINFO                              STD_ON
#define FBLCW_SIZEOFDCMDSLPROTOCOLTXINFO                              STD_ON
#define FBLCW_VARIANTIDX                                              STD_ON
#define FBLCW_PCCONFIG                                                STD_ON
#define FBLCW_CANIFCTRLINFOOFPCCONFIG                                 STD_ON
#define FBLCW_DCMDSLCONNECTIONINFOOFPCCONFIG                          STD_ON
#define FBLCW_DCMDSLPROTOCOLRXINFOOFPCCONFIG                          STD_ON
#define FBLCW_DCMDSLPROTOCOLTXINFOOFPCCONFIG                          STD_ON
#define FBLCW_FINALMAGICNUMBEROFPCCONFIG                              STD_OFF
#define FBLCW_INITDATAHASHCODEOFPCCONFIG                              STD_OFF
#define FBLCW_INITIALIZEDOFPCCONFIG                                   STD_ON
#define FBLCW_SIZEOFCANIFCTRLINFOOFPCCONFIG                           STD_ON
#define FBLCW_SIZEOFDCMDSLCONNECTIONINFOOFPCCONFIG                    STD_ON
#define FBLCW_SIZEOFDCMDSLPROTOCOLRXINFOOFPCCONFIG                    STD_ON
#define FBLCW_SIZEOFDCMDSLPROTOCOLTXINFOOFPCCONFIG                    STD_ON
#define FBLCW_VARIANTIDXOFPCCONFIG                                    STD_ON

#define FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO                STD_ON
#define FBLCW_EXISTS_FR_BUSTYPEOFDCMDSLCONNECTIONINFO                 STD_OFF
#define FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO                STD_OFF
#define FBLCW_EXISTS_CDD_BUSTYPEOFDCMDSLCONNECTIONINFO                STD_OFF
#define FBLCW_EXISTS_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO        STD_ON
#define FBLCW_EXISTS_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO          STD_ON

#define FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO                       0x00u
#define FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO               0x00u
#define FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO                 0x01u

#define FBLCW_ISDEF_CANIFCTRLINFO                                     STD_OFF
#define FBLCW_ISDEF_BUSTYPEOFDCMDSLCONNECTIONINFO                     STD_OFF
#define FBLCW_ISDEF_CONTROLLEROFDCMDSLCONNECTIONINFO                  STD_OFF
#define FBLCW_ISDEF_PAYLOADLIMITOFDCMDSLCONNECTIONINFO                STD_OFF
#define FBLCW_ISDEF_RXTESTERSOURCEADDRESSOFDCMDSLCONNECTIONINFO       STD_OFF
#define FBLCW_ISDEF_TXREMOTEPDUIDOFDCMDSLCONNECTIONINFO               STD_OFF
#define FBLCW_ISDEF_ADDRTYPEOFDCMDSLPROTOCOLRXINFO                    STD_OFF
#define FBLCW_ISDEF_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLRXINFO     STD_OFF
#define FBLCW_ISDEF_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLTXINFO     STD_OFF
#define FBLCW_ISDEF_CANIFCTRLINFOOFPCCONFIG                           STD_ON
#define FBLCW_ISDEF_DCMDSLCONNECTIONINFOOFPCCONFIG                    STD_ON
#define FBLCW_ISDEF_DCMDSLPROTOCOLRXINFOOFPCCONFIG                    STD_ON
#define FBLCW_ISDEF_DCMDSLPROTOCOLTXINFOOFPCCONFIG                    STD_ON
#define FBLCW_ISDEF_INITIALIZEDOFPCCONFIG                             STD_ON

#define FBLCW_EQ2_CANIFCTRLINFO
#define FBLCW_EQ2_BUSTYPEOFDCMDSLCONNECTIONINFO
#define FBLCW_EQ2_CONTROLLEROFDCMDSLCONNECTIONINFO
#define FBLCW_EQ2_PAYLOADLIMITOFDCMDSLCONNECTIONINFO
#define FBLCW_EQ2_RXTESTERSOURCEADDRESSOFDCMDSLCONNECTIONINFO
#define FBLCW_EQ2_TXREMOTEPDUIDOFDCMDSLCONNECTIONINFO
#define FBLCW_EQ2_ADDRTYPEOFDCMDSLPROTOCOLRXINFO
#define FBLCW_EQ2_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLRXINFO
#define FBLCW_EQ2_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLTXINFO
#define FBLCW_EQ2_CANIFCTRLINFOOFPCCONFIG                             FblCw_CanIfCtrlInfo
#define FBLCW_EQ2_DCMDSLCONNECTIONINFOOFPCCONFIG                      FblCw_DcmDslConnectionInfo
#define FBLCW_EQ2_DCMDSLPROTOCOLRXINFOOFPCCONFIG                      FblCw_DcmDslProtocolRxInfo
#define FBLCW_EQ2_DCMDSLPROTOCOLTXINFOOFPCCONFIG                      FblCw_DcmDslProtocolTxInfo
#define FBLCW_EQ2_INITIALIZEDOFPCCONFIG                               FblCw_Initialized

#define FblCw_Config_Ptr                                              NULL_PTR

#define FblCw_Config                                                  NULL_PTR

#define FBLCW_CHECK_INIT_POINTER                                      STD_OFF
#define FBLCW_FINAL_MAGIC_NUMBER                                      0xFF1Eu
#define FBLCW_INDIVIDUAL_POSTBUILD                                    STD_OFF
#define FBLCW_INIT_DATA                                               FBLCW_CONST
#define FBLCW_INIT_DATA_HASH_CODE                                     -299722517L
#define FBLCW_USE_ECUM_BSW_ERROR_HOOK                                 STD_OFF
#define FBLCW_USE_INIT_POINTER                                        STD_OFF

#define FBLCW_LTCONFIG                                                STD_OFF

#define FblCw_GetCanIfCtrlInfoOfPCConfig()                            FblCw_CanIfCtrlInfo
#define FblCw_GetDcmDslConnectionInfoOfPCConfig()                     FblCw_DcmDslConnectionInfo
#define FblCw_GetDcmDslProtocolRxInfoOfPCConfig()                     FblCw_DcmDslProtocolRxInfo
#define FblCw_GetDcmDslProtocolTxInfoOfPCConfig()                     FblCw_DcmDslProtocolTxInfo
#define FblCw_GetInitializedOfPCConfig()                              FblCw_Initialized
#define FblCw_GetSizeOfCanIfCtrlInfoOfPCConfig()                      1u
#define FblCw_GetSizeOfDcmDslConnectionInfoOfPCConfig()               1u
#define FblCw_GetSizeOfDcmDslProtocolRxInfoOfPCConfig()               2u
#define FblCw_GetSizeOfDcmDslProtocolTxInfoOfPCConfig()               1u
#define FblCw_GetVariantIdxOfPCConfig()                               0u

#define FblCw_GetCanIfCtrlInfo(Index)                                 (FblCw_GetCanIfCtrlInfoOfPCConfig()[(Index)])
#define FblCw_GetBusTypeOfDcmDslConnectionInfo(Index)                 (FblCw_GetDcmDslConnectionInfoOfPCConfig()[(Index)].BusTypeOfDcmDslConnectionInfo)
#define FblCw_GetControllerOfDcmDslConnectionInfo(Index)              (FblCw_GetDcmDslConnectionInfoOfPCConfig()[(Index)].ControllerOfDcmDslConnectionInfo)
#define FblCw_GetPayloadLimitOfDcmDslConnectionInfo(Index)            (FblCw_GetDcmDslConnectionInfoOfPCConfig()[(Index)].PayloadLimitOfDcmDslConnectionInfo)
#define FblCw_GetRxTesterSourceAddressOfDcmDslConnectionInfo(Index)   (FblCw_GetDcmDslConnectionInfoOfPCConfig()[(Index)].RxTesterSourceAddressOfDcmDslConnectionInfo)
#define FblCw_GetTxRemotePduIdOfDcmDslConnectionInfo(Index)           (FblCw_GetDcmDslConnectionInfoOfPCConfig()[(Index)].TxRemotePduIdOfDcmDslConnectionInfo)
#define FblCw_GetAddrTypeOfDcmDslProtocolRxInfo(Index)                (FblCw_GetDcmDslProtocolRxInfoOfPCConfig()[(Index)].AddrTypeOfDcmDslProtocolRxInfo)
#define FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo(Index) (FblCw_GetDcmDslProtocolRxInfoOfPCConfig()[(Index)].DcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo)
#define FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolTxInfo(Index) (FblCw_GetDcmDslProtocolTxInfoOfPCConfig()[(Index)].DcmDslConnectionInfoIdxOfDcmDslProtocolTxInfo)
#define FblCw_IsInitialized()                                         ((FblCw_GetInitializedOfPCConfig()) != FALSE)

#define FblCw_GetSizeOfCanIfCtrlInfo()                                FblCw_GetSizeOfCanIfCtrlInfoOfPCConfig()
#define FblCw_GetSizeOfDcmDslConnectionInfo()                         FblCw_GetSizeOfDcmDslConnectionInfoOfPCConfig()
#define FblCw_GetSizeOfDcmDslProtocolRxInfo()                         FblCw_GetSizeOfDcmDslProtocolRxInfoOfPCConfig()
#define FblCw_GetSizeOfDcmDslProtocolTxInfo()                         FblCw_GetSizeOfDcmDslProtocolTxInfoOfPCConfig()
#define FblCw_GetVariantIdx()                                         FblCw_GetVariantIdxOfPCConfig()

#define FblCw_SetInitialized(Value)                                   FblCw_GetInitializedOfPCConfig() = (Value)

#define FblCw_HasCanIfCtrlInfo()                                      (TRUE != FALSE)
#define FblCw_HasDcmDslConnectionInfo()                               (TRUE != FALSE)
#define FblCw_HasBusTypeOfDcmDslConnectionInfo()                      (TRUE != FALSE)
#define FblCw_HasControllerOfDcmDslConnectionInfo()                   (TRUE != FALSE)
#define FblCw_HasPayloadLimitOfDcmDslConnectionInfo()                 (TRUE != FALSE)
#define FblCw_HasRxTesterSourceAddressOfDcmDslConnectionInfo()        (TRUE != FALSE)
#define FblCw_HasTxRemotePduIdOfDcmDslConnectionInfo()                (TRUE != FALSE)
#define FblCw_HasDcmDslProtocolRxInfo()                               (TRUE != FALSE)
#define FblCw_HasAddrTypeOfDcmDslProtocolRxInfo()                     (TRUE != FALSE)
#define FblCw_HasDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo()      (TRUE != FALSE)
#define FblCw_HasDcmDslProtocolTxInfo()                               (TRUE != FALSE)
#define FblCw_HasDcmDslConnectionInfoIdxOfDcmDslProtocolTxInfo()      (TRUE != FALSE)
#define FblCw_HasInitialized()                                        (TRUE != FALSE)
#define FblCw_HasSizeOfCanIfCtrlInfo()                                (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslConnectionInfo()                         (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslProtocolRxInfo()                         (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslProtocolTxInfo()                         (TRUE != FALSE)
#define FblCw_HasVariantIdx()                                         (TRUE != FALSE)
#define FblCw_HasPCConfig()                                           (TRUE != FALSE)
#define FblCw_HasCanIfCtrlInfoOfPCConfig()                            (TRUE != FALSE)
#define FblCw_HasDcmDslConnectionInfoOfPCConfig()                     (TRUE != FALSE)
#define FblCw_HasDcmDslProtocolRxInfoOfPCConfig()                     (TRUE != FALSE)
#define FblCw_HasDcmDslProtocolTxInfoOfPCConfig()                     (TRUE != FALSE)
#define FblCw_HasInitializedOfPCConfig()                              (TRUE != FALSE)
#define FblCw_HasSizeOfCanIfCtrlInfoOfPCConfig()                      (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslConnectionInfoOfPCConfig()               (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslProtocolRxInfoOfPCConfig()               (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslProtocolTxInfoOfPCConfig()               (TRUE != FALSE)
#define FblCw_HasVariantIdxOfPCConfig()                               (TRUE != FALSE)

typedef uint8_least FblCw_CanIfCtrlInfoIterType;

typedef uint8_least FblCw_DcmDslConnectionInfoIterType;

typedef uint8_least FblCw_DcmDslProtocolRxInfoIterType;

typedef uint8_least FblCw_DcmDslProtocolTxInfoIterType;

typedef uint8 FblCw_CanIfCtrlInfoType;

typedef uint8 FblCw_BusTypeOfDcmDslConnectionInfoType;

typedef uint8 FblCw_ControllerOfDcmDslConnectionInfoType;

typedef uint16 FblCw_PayloadLimitOfDcmDslConnectionInfoType;

typedef uint8 FblCw_RxTesterSourceAddressOfDcmDslConnectionInfoType;

typedef uint8 FblCw_TxRemotePduIdOfDcmDslConnectionInfoType;

typedef uint8 FblCw_AddrTypeOfDcmDslProtocolRxInfoType;

typedef uint8 FblCw_DcmDslConnectionInfoIdxOfDcmDslProtocolRxInfoType;

typedef uint8 FblCw_DcmDslConnectionInfoIdxOfDcmDslProtocolTxInfoType;

typedef boolean FblCw_InitializedType;

typedef uint8 FblCw_SizeOfCanIfCtrlInfoType;

typedef uint8 FblCw_SizeOfDcmDslConnectionInfoType;

typedef uint8 FblCw_SizeOfDcmDslProtocolRxInfoType;

typedef uint8 FblCw_SizeOfDcmDslProtocolTxInfoType;

typedef uint8 FblCw_VariantIdxType;

typedef struct sFblCw_DcmDslConnectionInfoType{
  FblCw_PayloadLimitOfDcmDslConnectionInfoType PayloadLimitOfDcmDslConnectionInfo;
  FblCw_BusTypeOfDcmDslConnectionInfoType BusTypeOfDcmDslConnectionInfo;
  FblCw_ControllerOfDcmDslConnectionInfoType ControllerOfDcmDslConnectionInfo;
  FblCw_RxTesterSourceAddressOfDcmDslConnectionInfoType RxTesterSourceAddressOfDcmDslConnectionInfo;
  FblCw_TxRemotePduIdOfDcmDslConnectionInfoType TxRemotePduIdOfDcmDslConnectionInfo;
}FblCw_DcmDslConnectionInfoType;

typedef struct sFblCw_DcmDslProtocolRxInfoType{
  FblCw_AddrTypeOfDcmDslProtocolRxInfoType AddrTypeOfDcmDslProtocolRxInfo;
  FblCw_DcmDslConnectionInfoIdxOfDcmDslProtocolRxInfoType DcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo;
}FblCw_DcmDslProtocolRxInfoType;

typedef struct sFblCw_DcmDslProtocolTxInfoType{
  FblCw_DcmDslConnectionInfoIdxOfDcmDslProtocolTxInfoType DcmDslConnectionInfoIdxOfDcmDslProtocolTxInfo;
}FblCw_DcmDslProtocolTxInfoType;

typedef struct sFblCw_PCConfigType{
  uint8 FblCw_PCConfigNeverUsed;
}FblCw_PCConfigType;

typedef FblCw_PCConfigType FblCw_ConfigType;

#define FBLCW_START_SEC_CONST_8BIT

#include "MemMap.hpp"

extern CONST(FblCw_CanIfCtrlInfoType, FBLCW_CONST) FblCw_CanIfCtrlInfo[1];
#define FBLCW_STOP_SEC_CONST_8BIT

#include "MemMap.hpp"

#define FBLCW_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(FblCw_DcmDslConnectionInfoType, FBLCW_CONST) FblCw_DcmDslConnectionInfo[1];
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define FBLCW_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(FblCw_DcmDslProtocolRxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolRxInfo[2];
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define FBLCW_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

extern CONST(FblCw_DcmDslProtocolTxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolTxInfo[1];
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define FBLCW_START_SEC_VAR_ZERO_INIT_8BIT

#include "MemMap.hpp"

extern VAR(FblCw_InitializedType, FBLCW_VAR_ZERO_INIT) FblCw_Initialized;
#define FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT

#include "MemMap.hpp"

#define FBLCW_START_SEC_CODE
#include "MemMap.hpp"

FUNC(void, FBLCW_CODE) FblCw_EcuMInit(void);

#define FBLCW_STOP_SEC_CODE
#include "MemMap.hpp"

#endif

