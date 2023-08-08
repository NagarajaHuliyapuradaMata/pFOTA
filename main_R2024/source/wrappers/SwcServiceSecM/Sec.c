

#define SEC_SOURCE

#include "Sec_Inc.hpp"

#include "Sec_Types.hpp"

#include "Sec.hpp"

#if( SYSSERVICE_SECMODHIS_VERSION != 0x0312u ) || \
    ( SYSSERVICE_SECMODHIS_RELEASE_VERSION != 0x02u )
# error "Error in SecM.c: Source and header file are inconsistent!"
#endif

#define SECM_START_SEC_VAR
#include "MemMap.hpp"

#if defined( SEC_KEY_TIMEOUT ) && ( SEC_KEY_TIMEOUT != 0x00u )

V_MEMRAM0 V_MEMRAM1 SecM_ShortType V_MEMRAM2 secTimer;
#endif

#define SECM_STOP_SEC_VAR
#include "MemMap.hpp"

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

static void SecM_TimerTask( void );

static void SecM_TimerTask( void ){
   SecM_DecrKeyTimer();
}

SecM_StatusType SecM_InitPowerOn( SecM_InitType initParam ){
   SecM_StatusType result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )

   (void)initParam;
#endif

   result = SECM_OK;

   SecM_InitPowerOnCRC();
   SecM_InitPowerOnVerification();

   return result;
}

void SecM_Task( void ){
   SecM_TimerTask();
}

SecM_WordType SecM_GetInteger( SecM_ByteFastType count, SecM_ConstRamDataType buffer ){
   SecM_WordType output;
   SecM_ByteFastType index;

   output = 0u;
   index = 0u;

   while (index < count){
      output <<= 8u;

      output |= (SecM_WordType)buffer[index];

      index++;
   }

   return output;
}

void SecM_SetInteger( SecM_ByteFastType count, SecM_WordType input, SecM_RamDataType buffer ){
   SecM_ByteFastType index;
   SecM_WordType localInput;

   index = count;
   localInput = input;
   while (index > 0u){
      index--;

      buffer[index] = (SecM_ByteType)(localInput & 0xFFu);

      localInput >>= 8u;
   }
}

void SecM_CopyBuffer( SecM_ConstRamDataType input, SecM_RamDataType output, SecM_ShortType count ){
   SecM_ShortType index;

   for (index = 0u; index < count; index++){
      output[index] = input[index];
   }
}

void SecM_InitBuffer(SecM_RamBufferProcessingPtrType buff, SecM_ShortType size){
   buff->pos = 0u;
   buff->size = size;
}

SecM_BufferRetType SecM_AccumulateBufferStore(SecM_RamBufferProcessingPtrType buff, SecM_ConstRamDataType src,
   SecM_RamShortType size){
   SecM_BufferRetType result = SEC_BUFF_OK;

   if(buff->size == buff->pos){
      result = SEC_BUFF_FULL;
      *size = 0u;
   }
   else if(*size > (buff->size - buff->pos)){
      *size = (buff->size - buff->pos);
      SecM_CopyBuffer(src, &buff->buffer[buff->pos], *size);
      buff->pos += *size;
      result = SEC_BUFF_FULL;
   }
   else{
      if(*size == (buff->size - buff->pos))
      {
         result = SEC_BUFF_FULL;
      }
      SecM_CopyBuffer(src, &buff->buffer[buff->pos], *size);
      buff->pos += *size;
   }

   return result;
}

SecM_BufferRetType SecM_FifoBufferStore(SecM_RamBufferProcessingPtrType buff, SecM_ConstRamDataType src,
   SecM_RamShortType srcSize, SecM_RamDataType flushBuff, SecM_RamShortType flushSize){
   SecM_BufferRetType result = SEC_BUFF_OK;

   if((buff->size - buff->pos) >= *srcSize){
      SecM_CopyBuffer(src, &buff->buffer[buff->pos], *srcSize);
      buff->pos += *srcSize;
      *flushSize = 0u;
   }
   else{
      SecM_ShortType localTransferSize;
      SecM_ShortType srcIdx;

      localTransferSize = (*srcSize < buff->size) ? *srcSize : buff->size;
      srcIdx = (*srcSize <= buff->size) ? 0u : (*srcSize - buff->size);

      if(localTransferSize < buff->size)
      {
         SecM_CopyBuffer(buff->buffer, flushBuff, (localTransferSize - (buff->size - buff->pos)));
         *flushSize = (localTransferSize - (buff->size - buff->pos));
         SecM_CopyBuffer(&buff->buffer[(localTransferSize - (buff->size - buff->pos))], buff->buffer, (buff->size - (localTransferSize - (buff->size - buff->pos))));
         buff->pos -= (localTransferSize - (buff->size - buff->pos));
      }
      else
      {
         SecM_CopyBuffer(buff->buffer, flushBuff, buff->size);
         *flushSize = buff->pos;
         buff->pos = 0u;
      }

      SecM_CopyBuffer(&src[srcIdx], &buff->buffer[buff->pos], localTransferSize);
      buff->pos += localTransferSize;
      *srcSize = localTransferSize;
   }

   return result;
}

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

