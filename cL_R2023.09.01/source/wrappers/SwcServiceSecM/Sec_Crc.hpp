

#ifndef SEC_CRC_H
#define SEC_CRC_H

#include "Sec_Inc.hpp"

#if defined ( SEC_ENABLE_CRC )

#define kCRCInit                       0x01u

#define kCRCCompute                    0x02u

#define kCRCFinalize                   0x03u

#define SEC_CRC_NONE                   0x00u
#define SEC_CRC_INIT                   kCRCInit
#define SEC_CRC_COMPUTE                kCRCCompute
#define SEC_CRC_FINALIZE               kCRCFinalize
#define SEC_CRC_VERIFY                 0x04u
#define SEC_CRC_GET                    0x05u

#define SEC_SIZE_CHECKSUM_CRC_16       2u

#define SEC_SIZE_CHECKSUM_CRC_32       4u

#define SEC_SIZE_CHECKSUM_CRC_64       8u

#define SEC_INITIAL_VAL_CRC16(val) (val)
#define SEC_INITIAL_VAL_CRC32(val) (val)
#define SEC_INITIAL_VAL_CRC64(high, low) { (high), (low) }

#if(SEC_CRC_TYPE == SEC_CRC16 )
#define SEC_ZERO_VALUE       SEC_INITIAL_VAL_CRC16(0x00u)
# elif( SEC_CRC_TYPE == SEC_CRC32 )
#define SEC_ZERO_VALUE       SEC_INITIAL_VAL_CRC32(0x00u)
# elif( SEC_CRC_TYPE == SEC_CRC64 )
#define SEC_ZERO_VALUE       SEC_INITIAL_VAL_CRC64(0x00u, 0x00u)
#endif

typedef struct{
   SecM_Crc16Type          currentCRC;
   SecM_ByteType           crcState;
   SecM_ConstRamDataType   crcSourceBuffer;
   SecM_RamDataType        crcOutputBuffer;
   SecM_LengthType         crcByteCount;
   FL_WDTriggerFctType     wdTriggerFct;
}SecM_CRC16ParamType;
typedef struct{
   SecM_Crc32Type          currentCRC;
   SecM_ByteType           crcState;
   SecM_ConstRamDataType   crcSourceBuffer;
   SecM_RamDataType        crcOutputBuffer;
   SecM_LengthType         crcByteCount;
   FL_WDTriggerFctType     wdTriggerFct;
}SecM_CRC32ParamType;
typedef struct{
   SecM_Crc64Type          currentCRC;
   SecM_ByteType           crcState;
   SecM_ConstRamDataType   crcSourceBuffer;
   SecM_RamDataType        crcOutputBuffer;
   SecM_LengthType         crcByteCount;
   FL_WDTriggerFctType     wdTriggerFct;
}SecM_CRC64ParamType;

#if(SEC_CRC_TYPE == SEC_CRC16 )
typedef SecM_CRC16ParamType   SecM_CRCParamType;
# elif( SEC_CRC_TYPE == SEC_CRC32 )
typedef SecM_CRC32ParamType   SecM_CRCParamType;
# elif( SEC_CRC_TYPE == SEC_CRC64 )
typedef SecM_CRC64ParamType   SecM_CRCParamType;
#endif

typedef SecM_StatusType SEC_CALL_TYPE (* pSecComputeCRCFct)( V_MEMRAM1 SecM_CRCParamType V_MEMRAM2 V_MEMRAM3 * crcParam );
#endif

#define SECM_START_SEC_VAR
#include "MemMap.hpp"

#if defined( SEC_ENABLE_SAVE_RESTORE_CRC)
V_MEMRAM0 extern V_MEMRAM1 SecM_CrcWorkspaceInfoType V_MEMRAM2 SecM_CrcWorkspaceInfo[SEC_CRC_WORKSPACE_SIZE];
#endif

#define SECM_STOP_SEC_VAR
#include "MemMap.hpp"

#if defined( __cplusplus )
extern "C" {
#endif

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

void SecM_InitPowerOnCRC(void);
#if defined( SEC_ENABLE_CRC )
SecM_StatusType SecM_ComputeCRC( V_MEMRAM1 SecM_CRCParamType V_MEMRAM2 V_MEMRAM3 * crcParam );
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
SecM_StatusType SecM_ComputeCrc16(V_MEMRAM1 SecM_CRC16ParamType V_MEMRAM2 V_MEMRAM3 * crcParam);
#endif
#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
SecM_StatusType SecM_ComputeCrc32(V_MEMRAM1 SecM_CRC32ParamType V_MEMRAM2 V_MEMRAM3 * crcParam);
#endif
#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
SecM_StatusType SecM_ComputeCrc64(V_MEMRAM1 SecM_CRC64ParamType V_MEMRAM2 V_MEMRAM3 * crcParam);
#endif

#if defined( SEC_ENABLE_SAVE_RESTORE_CRC )
SecM_StatusType SecM_SaveContextCrc(SecM_WordType workspaceIdx, SecM_RamDataType contextBuffer, SecM_RamWordType contextBufferLengthPtr);
#endif

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#if defined( __cplusplus )
}
#endif

#endif

