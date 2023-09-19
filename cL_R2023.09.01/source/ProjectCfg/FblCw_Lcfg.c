

#define FBLCW_LCFG_SOURCE

#include "fbl_inc.hpp"
#include "FblCw_Lcfg.hpp"
#include "infSwcServicePduRSwcServiceDcm.hpp"

#include "McalCan.hpp"
#include "EcuabCanIf.hpp"
#include "SwcServiceCanTp.hpp"
#include "SwcServiceDet.hpp"
#include "SwcServicePduR.hpp"

#define FBLCW_START_SEC_CONST_8BIT

#include "MemMap.hpp"

CONST(FblCw_CanIfCtrlInfoType, FBLCW_CONST) FblCw_CanIfCtrlInfo[1] = {
    CanIfConf_CanIfCtrlCfg_CT_P1951001_0_003_01_24_Rivian_A1_V_b79a45a3
};
#define FBLCW_STOP_SEC_CONST_8BIT

#include "MemMap.hpp"

#define FBLCW_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(FblCw_DcmDslConnectionInfoType, FBLCW_CONST) FblCw_DcmDslConnectionInfo[1] = {
  {  0x00000FFFuL, FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO, CanIfConf_CanIfCtrlCfg_CT_P1951001_0_003_01_24_Rivian_A1_V_b79a45a3,                    0u, PduRConf_PduRSrcPdu_PduRSrcPdu_83bcc558 }
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define FBLCW_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(FblCw_DcmDslProtocolRxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolRxInfo[2] = {
  {  FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      0u }
   ,  {    FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      0u }
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define FBLCW_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(FblCw_DcmDslProtocolTxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolTxInfo[1] = {
  {                       0u }
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define FBLCW_START_SEC_VAR_ZERO_INIT_8BIT

#include "MemMap.hpp"

VAR(FblCw_InitializedType, FBLCW_VAR_ZERO_INIT) FblCw_Initialized = FALSE;
#define FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT

#include "MemMap.hpp"

#define FBLCW_START_SEC_CODE
#include "MemMap.hpp"

FUNC(void, FBLCW_CODE) FblCw_EcuMInit(void){
  infEcuabCanIfSwcApplEcuM_InitFunctionMemory();
  SwcServiceCanTp_InitFunctionMemory();
  Can_InitMemory();
  Det_InitMemory();
  PduR_InitMemory();

#if(FBLCW_USE_INIT_POINTER == STD_ON)
  if(FblCw_ConfigDataPtr == FblCw_Config_Ptr)
#endif
  {
    Det_Init(Det_Config_Ptr);

    PduR_Init(PduR_Config_Ptr);

    Can_Init(Can_Config_Ptr);

    infEcuabCanIfSwcApplEcuM_InitFunction(CanIf_Config_Ptr);

    SwcServiceCanTp_InitFunction(CanTp_Config_Ptr);

  }
}

#define FBLCW_STOP_SEC_CODE
#include "MemMap.hpp"

