

#ifndef SEC_H
#define SEC_H

# define SYSSERVICE_SECMODHIS_VERSION              0x0312u
# define SYSSERVICE_SECMODHIS_RELEASE_VERSION      0x02u

#define SECM_HIS_SECURITY_MODULE_VERSION           0x010100uL

#include "Sec_Inc.hpp"

#include "Sec_Job.hpp"
#include "Sec_Crc.hpp"
#include "Sec_Decryption.hpp"
#include "Sec_SeedKey.hpp"
#include "Sec_Verification.hpp"

#if defined( SEC_KEY_TIMEOUT ) && ( SEC_KEY_TIMEOUT != 0x00u )

# define  SecM_StartKeyTimer()   (secTimer = (SEC_KEY_TIMEOUT / SEC_CALL_CYCLE))

# define  SecM_StopKeyTimer()    (secTimer = 0u)

# define  SecM_GetKeyTimer()     (secTimer)

# define  SecM_DecrKeyTimer() \
   if(secTimer > 0u)         \
   {                          \
      secTimer--;             \
   }
#else

# define  SecM_StartKeyTimer()
# define  SecM_StopKeyTimer()
# define  SecM_GetKeyTimer()     (1u)
# define  SecM_DecrKeyTimer()
#endif

typedef SecM_ConstVoidPtrType   SecM_InitType;

typedef void SEC_CALL_TYPE (* pSecTaskFct)( void );

#define SECM_START_SEC_VAR
#include "MemMap.hpp"

#if defined( SEC_KEY_TIMEOUT ) && ( SEC_KEY_TIMEOUT != 0x00u )
V_MEMRAM0 extern V_MEMRAM1 SecM_ShortType V_MEMRAM2 secTimer;
#endif

#define SECM_STOP_SEC_VAR
#include "MemMap.hpp"

#if defined( __cplusplus )
extern "C" {
#endif

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

SecM_StatusType SecM_InitPowerOn( SecM_InitType initParam );
void SecM_Task( void );
SecM_WordType SecM_GetInteger( SecM_ByteFastType count, SecM_ConstRamDataType buffer );
void SecM_SetInteger( SecM_ByteFastType count, SecM_WordType input, SecM_RamDataType buffer );
void SecM_CopyBuffer( SecM_ConstRamDataType input, SecM_RamDataType output, SecM_ShortType count );
void SecM_InitBuffer( SecM_RamBufferProcessingPtrType buff, SecM_ShortType size );
SecM_BufferRetType SecM_AccumulateBufferStore( SecM_RamBufferProcessingPtrType buff, SecM_ConstRamDataType src,
   SecM_RamShortType size );
SecM_BufferRetType SecM_FifoBufferStore( SecM_RamBufferProcessingPtrType buff, SecM_ConstRamDataType src,
   SecM_RamShortType srcSize, SecM_RamDataType flushBuff, SecM_RamShortType flushSize );

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#if defined( __cplusplus )
}
#endif

#endif

