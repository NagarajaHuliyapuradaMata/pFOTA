#define ECUABFEE_IMPLEMENTATION_SOURCE

#include "Std_Types.hpp"
#include "EcuabFee.hpp"

#if(   (ECUABFEE_CFG_MAJOR_VERSION != (2u)) \
     || (ECUABFEE_CFG_MINOR_VERSION != (0u)))
# error "Version numbers of EcuabFee_Cfg.c and EcuabFee_Cfg.h are inconsistent!"
#endif

#define ECUABFEE_START_SEC_CONST_8BIT
#include "MemMap.hpp"

CONST(uint8, ECUABFEE_PRIVATE_CONST) EcuabFee_DatasetSelectionBits = (1U);

#define ECUABFEE_STOP_SEC_CONST_8BIT
#include "MemMap.hpp"

#define ECUABFEE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

CONST(EcuabFee_PartitionConfigType, ECUABFEE_PRIVATE_CONST) EcuabFee_PartitionConfigList[ECUABFEE_NUMBER_OF_PARTITIONS] =
{
    {
      0x00000800UL
   ,     0x0040U
   ,     0x0008U
   ,     0x0008U
   ,     0x0000U
   ,     &EcuabFee_FlsApi0
   ,     0xFFU
   ,     TRUE
   ,   {
        0x0004U
    }
  }
   ,   {
      0x00000C00UL
   ,     0x0040U
   ,     0x0008U
   ,     0x0008U
   ,     0x0000U
   ,     &EcuabFee_FlsApi0
   ,     0xFFU
   ,     TRUE
   ,   {
        0x0002U
    }
  }
};

CONST(EcuabFee_BlockConfigType, ECUABFEE_PRIVATE_CONST) EcuabFee_BlockConfigList[ECUABFEE_NUMBER_OF_BLOCKS] =
{
  {
      0x00000000UL
   ,     0x0004U
   ,     0x01U
   ,     0x02U
   ,     FALSE
   ,     FALSE
  }
   ,  {
      0x00000000UL
   ,     0x0082U
   ,     0x01U
   ,     0x01U
   ,     FALSE
   ,     FALSE
  }
};

CONST(EcuabFee_FlsApiType, ECUABFEE_PRIVATE_CONST) EcuabFee_FlsApi0 = {
   Fls_Read
   ,  Fls_Write
   ,  Fls_Compare
   ,  Fls_Erase
   ,  Fls_BlankCheck
   ,  Fls_GetStatus
   ,  Fls_GetJobResult
};

CONST(EcuabFee_CbkJobEndNotificationType, ECUABFEE_PRIVATE_CONST) EcuabFee_CbkJobEndNotification =
    NULL_PTR;
CONST(EcuabFee_CbkJobErrorNotificationType, ECUABFEE_PRIVATE_CONST) EcuabFee_CbkJobErrorNotification =
    NULL_PTR;

#define ECUABFEE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"	

