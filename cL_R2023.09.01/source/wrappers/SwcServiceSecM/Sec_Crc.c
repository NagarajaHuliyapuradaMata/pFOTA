

#define SEC_CRC_SOURCE

#include "Sec_Inc.hpp"

#include "Sec_Types.hpp"

#include "Sec.hpp"

#define CRC_SPEED_OPT_INDEX_BITS    8u

#define CRC_SPEED_OPT_INDEX_MASK    0xFFu

#define CRC_SPEED_OPT_TABLE_SIZE    256u

#define CRC_SIZE_OPT_INDEX_BITS    4u

#define CRC_SIZE_OPT_INDEX_MASK    0x0Fu

#define CRC_SIZE_OPT_TABLE_SIZE    16u

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
#if( SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED )
#define SEC_CRC_16_INDEX_BITS     CRC_SPEED_OPT_INDEX_BITS
#define SEC_CRC_16_INDEX_MASK     CRC_SPEED_OPT_INDEX_MASK
#define SEC_CRC_16_TABLE_SIZE     CRC_SPEED_OPT_TABLE_SIZE
#else
#define SEC_CRC_16_INDEX_BITS     CRC_SIZE_OPT_INDEX_BITS
#define SEC_CRC_16_INDEX_MASK     CRC_SIZE_OPT_INDEX_MASK
#define SEC_CRC_16_TABLE_SIZE     CRC_SIZE_OPT_TABLE_SIZE
#endif

#define SEC_CRC_16_UNINIT_PATTERN  0xA5A5u

#define SEC_CRC_16_INIT_PATTERN    0xC2C7u
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
#if( SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED )
#define SEC_CRC_32_INDEX_BITS     CRC_SPEED_OPT_INDEX_BITS
#define SEC_CRC_32_INDEX_MASK     CRC_SPEED_OPT_INDEX_MASK
#define SEC_CRC_32_TABLE_SIZE     CRC_SPEED_OPT_TABLE_SIZE
#else
#define SEC_CRC_32_INDEX_BITS     CRC_SIZE_OPT_INDEX_BITS
#define SEC_CRC_32_INDEX_MASK     CRC_SIZE_OPT_INDEX_MASK
#define SEC_CRC_32_TABLE_SIZE     CRC_SIZE_OPT_TABLE_SIZE
#endif

#define SEC_CRC_32_UNINIT_PATTERN  0xA5A5A5A5uL

#define SEC_CRC_32_INIT_PATTERN    0xC2C3274BuL
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
#if( SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED )
#define SEC_CRC_64_INDEX_BITS     CRC_SPEED_OPT_INDEX_BITS
#define SEC_CRC_64_INDEX_MASK     CRC_SPEED_OPT_INDEX_MASK
#define SEC_CRC_64_TABLE_SIZE     CRC_SPEED_OPT_TABLE_SIZE
#else
#define SEC_CRC_64_INDEX_BITS     CRC_SIZE_OPT_INDEX_BITS
#define SEC_CRC_64_INDEX_MASK     CRC_SIZE_OPT_INDEX_MASK
#define SEC_CRC_64_TABLE_SIZE     CRC_SIZE_OPT_TABLE_SIZE
#endif

#define SEC_CRC_64_UNINIT_PATTERN  { 0xA5A5A5A5uL, 0xA5A5A5A5uL }

#define SEC_CRC_64_INIT_PATTERN    { 0xC2C6474BuL, 0xC2C6474BuL }
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
#if( SEC_CRC_16_OPT == SEC_CRC_SIZE_OPTIMIZED )

#if( SEC_CRC_16_MODE == SEC_CRC_MODE_NON_REFLECTED )

#define CRC_16_BIT(in)        (((((in) & 0x7FFFu) << 1u) ^ ((((in) >> 15u) & 0x01u) * SEC_CRC_16_POLYNOMIAL)) & 0xFFFFu)

#define CRC_16_CALC(in)       CRC_16_NIBBLE(((in) & 0x0Fu) << 12u)
#else

#define CRC_16_BIT(in)        ((((in) >> 1u) ^ (((in) & 0x01u) * SEC_CRC_16_POLYNOMIAL)) & 0xFFFFu)

#define CRC_16_CALC(in)       CRC_16_NIBBLE((in))
#endif

#define CRC_16_NIBBLE(in)      (CRC_16_BIT(CRC_16_BIT(CRC_16_BIT(CRC_16_BIT(in)))))

#define CRC_16_ENTRIES_4(i)    \
   CRC_16_CALC((i)),             \
   CRC_16_CALC((i) + 1u),        \
   CRC_16_CALC((i) + 2u),        \
   CRC_16_CALC((i) + 3u)

#define CRC_16_ENTRIES_16(i)   \
   CRC_16_ENTRIES_4((i)),        \
   CRC_16_ENTRIES_4((i) + 4u),   \
   CRC_16_ENTRIES_4((i) + 8u),   \
   CRC_16_ENTRIES_4((i) + 12u)
#endif
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
#if( SEC_CRC_32_OPT == SEC_CRC_SIZE_OPTIMIZED )

#if( SEC_CRC_32_MODE == SEC_CRC_MODE_NON_REFLECTED )

#define CRC_32_BIT(in)        ((((in) & 0x7FFFFFFFuL) << 1u) ^ ((((in) >> 31u) & 0x01u) * SEC_CRC_32_POLYNOMIAL))

#define CRC_32_CALC(in)       CRC_32_NIBBLE(((in) & 0x0Fu) << 28u)
#else

#define CRC_32_BIT(in)        (((in) >> 1u) ^ (((in) & 0x01u) * SEC_CRC_32_POLYNOMIAL))

#define CRC_32_CALC(in)       CRC_32_NIBBLE((in))
#endif

#define CRC_32_NIBBLE(in)      (CRC_32_BIT(CRC_32_BIT(CRC_32_BIT(CRC_32_BIT(in)))))

#define CRC_32_ENTRIES_4(i)    \
   CRC_32_CALC((i)),             \
   CRC_32_CALC((i) + 1u),        \
   CRC_32_CALC((i) + 2u),        \
   CRC_32_CALC((i) + 3u)

#define CRC_32_ENTRIES_16(i)   \
   CRC_32_ENTRIES_4((i)),        \
   CRC_32_ENTRIES_4((i) + 4u),   \
   CRC_32_ENTRIES_4((i) + 8u),   \
   CRC_32_ENTRIES_4((i) + 12u)
#endif
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
#if( SEC_CRC_64_OPT == SEC_CRC_SIZE_OPTIMIZED )

#if( SEC_CRC_64_MODE == SEC_CRC_MODE_NON_REFLECTED )

#define CRC_64_BIT__(h, l)    (((((h) & 0x7FFFFFFFuL) << 1u) | (((l) >> 31u) & 0x01u)) ^ ((((h) >> 31u) & 0x01u) * SEC_CRC_64_POLYNOMIAL_HIGH)), \
                                 ((((l) & 0x7FFFFFFFuL) << 1u) ^ ((((h) >> 31u) & 0x01u) * SEC_CRC_64_POLYNOMIAL_LOW))

#define CRC_64_CALC(in)       { CRC_64_NIBBLE((in) << 28u, 0x00u) }
#else

#define CRC_64_BIT__(h, l)    (((SecM_Crc64BaseType)(h) >> 1u) ^ (((SecM_Crc64BaseType)(l) & 0x01u) * SEC_CRC_64_POLYNOMIAL_HIGH)), \
                                 ((((SecM_Crc64BaseType)(l) >> 1u) | ((((SecM_Crc64BaseType)h) & 0x01u) << 31u)) ^ (((SecM_Crc64BaseType)(l) & 0x01u) * SEC_CRC_64_POLYNOMIAL_LOW))

#define CRC_64_CALC(in)       { CRC_64_NIBBLE(0x00u, (in)) }
#endif

#define CRC_64_BIT_(p)         CRC_64_BIT__ p

#define CRC_64_BIT(p)          CRC_64_BIT_((p))

#define CRC_64_NIBBLE(h, l)    CRC_64_BIT(CRC_64_BIT(CRC_64_BIT(CRC_64_BIT__((h), (l)))))

#define CRC_64_ENTRIES_4(i)    \
   CRC_64_CALC((i)),             \
   CRC_64_CALC((i) + 1u),        \
   CRC_64_CALC((i) + 2u),        \
   CRC_64_CALC((i) + 3u)

#define CRC_64_ENTRIES_16(i)   \
   CRC_64_ENTRIES_4((i)),        \
   CRC_64_ENTRIES_4((i) + 4u),   \
   CRC_64_ENTRIES_4((i) + 8u),   \
   CRC_64_ENTRIES_4((i) + 12u)
#endif
#endif

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
#if( SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED )
static void SecM_GenerateLookupCrc16(FL_WDTriggerFctType pWatchdog);
#endif
#endif
#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
#if( SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED )
static void SecM_GenerateLookupCrc32(FL_WDTriggerFctType pWatchdog);
#endif
#endif
#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
#if( SEC_CRC_64_OPT == SEC_CRC_SIZE_OPTIMIZED )
static void SecM_GenerateLookupCrc64(FL_WDTriggerFctType pWatchdog);
#endif
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
static void SecM_UpdateCrc16(V_MEMRAM1 SecM_CRC16ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam);
#endif
#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
static void SecM_UpdateCrc32(V_MEMRAM1 SecM_CRC32ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam);
#endif
#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
static void SecM_UpdateCrc64(V_MEMRAM1 SecM_CRC64ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam);
#endif

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
#if( SEC_CRC_16_OPT == SEC_CRC_SIZE_OPTIMIZED )
#define SECM_START_SEC_CONST
#include "MemMap.hpp"

V_MEMROM0 static V_MEMROM1 SecM_Crc16Type V_MEMROM2 lookupCrc16[SEC_CRC_16_TABLE_SIZE] =
{
   CRC_16_ENTRIES_16(0x00u)
};
#define SECM_STOP_SEC_CONST
#include "MemMap.hpp"
#else
#define SECM_START_SEC_VAR
#include "MemMap.hpp"

V_MEMRAM0 static V_MEMRAM1 SecM_Crc16Type V_MEMRAM2 lookupCrc16[SEC_CRC_16_TABLE_SIZE + 1u];
#define SECM_STOP_SEC_VAR
#include "MemMap.hpp"
#endif
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
#if( SEC_CRC_32_OPT == SEC_CRC_SIZE_OPTIMIZED )

#define SECM_START_SEC_CONST
#include "MemMap.hpp"
V_MEMROM0 static V_MEMROM1 SecM_Crc32Type V_MEMROM2 lookupCrc32[SEC_CRC_32_TABLE_SIZE] =
{
   CRC_32_ENTRIES_16(0x00u)
};
#define SECM_STOP_SEC_CONST
#include "MemMap.hpp"
#else

#define SECM_START_SEC_VAR
#include "MemMap.hpp"
V_MEMRAM0 static V_MEMRAM1 SecM_Crc32Type V_MEMRAM2 lookupCrc32[SEC_CRC_32_TABLE_SIZE + 1u];
#define SECM_STOP_SEC_VAR
#include "MemMap.hpp"
#endif
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
#if( SEC_CRC_64_OPT == SEC_CRC_SIZE_OPTIMIZED )

#define SECM_START_SEC_CONST
#include "MemMap.hpp"
V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 lookupCrc64[SEC_CRC_64_TABLE_SIZE] =
{
   CRC_64_ENTRIES_16(0x00u)
};
#define SECM_STOP_SEC_CONST
#include "MemMap.hpp"
#else

#define SECM_START_SEC_VAR
#include "MemMap.hpp"
V_MEMRAM0 static V_MEMRAM1 SecM_Crc64Type V_MEMRAM2 lookupCrc64[SEC_CRC_64_TABLE_SIZE + 1u];
#define SECM_STOP_SEC_VAR
#include "MemMap.hpp"

#define SECM_START_SEC_CONST
#include "MemMap.hpp"
V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 polynomialCrc64 = SEC_CRC_64_POLYNOMIAL;

V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 uninitPatternCrc64 = SEC_CRC_64_UNINIT_PATTERN;

V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 initPatternCrc64 = SEC_CRC_64_INIT_PATTERN;
#define SECM_STOP_SEC_CONST
#include "MemMap.hpp"
#endif
#endif

#define SECM_START_SEC_CONST
#include "MemMap.hpp"
#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )

V_MEMROM0 static V_MEMROM1 SecM_Crc16Type V_MEMROM2 initialValueCrc16 = SEC_CRC_16_INITIAL;

V_MEMROM0 static V_MEMROM1 SecM_Crc16Type V_MEMROM2 finalValueCrc16 = SEC_CRC_16_FINAL;
#endif
#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )

V_MEMROM0 static V_MEMROM1 SecM_Crc32Type V_MEMROM2 initialValueCrc32 = SEC_CRC_32_INITIAL;

V_MEMROM0 static V_MEMROM1 SecM_Crc32Type V_MEMROM2 finalValueCrc32 = SEC_CRC_32_FINAL;
#endif
#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )

V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 initialValueCrc64 = SEC_CRC_64_INITIAL;

V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 finalValueCrc64 = SEC_CRC_64_FINAL;
#endif
#define SECM_STOP_SEC_CONST
#include "MemMap.hpp"

#define SECM_START_SEC_VAR
#include "MemMap.hpp"
#if defined( SEC_ENABLE_SAVE_RESTORE_CRC )
V_MEMRAM0 V_MEMRAM1 SecM_CrcWorkspaceInfoType V_MEMRAM2 SecM_CrcWorkspaceInfo[SEC_CRC_WORKSPACE_SIZE];
#endif

#define SECM_STOP_SEC_VAR
#include "MemMap.hpp"

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
#if( SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED )

static void SecM_GenerateLookupCrc16( FL_WDTriggerFctType pWatchdog ){
   SecM_ShortFastType   tableIndex;
   SecM_ByteFastType    bitIndex;
   SecM_Crc16Type       crc;

   for(tableIndex = 0u; tableIndex < SEC_CRC_16_TABLE_SIZE; tableIndex++){
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, tableIndex);

#if( SEC_CRC_16_MODE == SEC_CRC_MODE_NON_REFLECTED )

      crc = (SecM_Crc16Type)(tableIndex << (16u - SEC_CRC_16_INDEX_BITS));
#else

      crc = tableIndex;
#endif

      for(bitIndex = 0u; bitIndex < SEC_CRC_16_INDEX_BITS; bitIndex++)
      {
#if( SEC_CRC_16_MODE == SEC_CRC_MODE_NON_REFLECTED )

         if((crc & ((SecM_Crc16Type)0x01u << 15u)) != 0x00u)
         {
            crc <<= 1u;
            crc ^= SEC_CRC_16_POLYNOMIAL;
         }
         else
         {
            crc <<= 1u;
         }
#else

         if((crc & 0x01u) != 0x00u)
         {
            crc >>= 1u;
            crc ^= SEC_CRC_16_POLYNOMIAL;
         }
         else
         {
            crc >>= 1u;
         }
#endif
      }

      lookupCrc16[tableIndex] = crc;
   }

   lookupCrc16[SEC_CRC_16_TABLE_SIZE] = SEC_CRC_16_INIT_PATTERN;
}
#endif
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
#if( SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED )

static void SecM_GenerateLookupCrc32( FL_WDTriggerFctType pWatchdog ){
   SecM_ShortFastType   tableIndex;
   SecM_ByteFastType    bitIndex;
   SecM_Crc32Type       crc;

   for(tableIndex = 0u; tableIndex < SEC_CRC_32_TABLE_SIZE; tableIndex++){
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, tableIndex);

#if( SEC_CRC_32_MODE == SEC_CRC_MODE_NON_REFLECTED )

      crc = (SecM_Crc32Type)tableIndex << (32u - SEC_CRC_32_INDEX_BITS);
#else

      crc = tableIndex;
#endif

      for(bitIndex = 0u; bitIndex < SEC_CRC_32_INDEX_BITS; bitIndex++)
      {
#if( SEC_CRC_32_MODE == SEC_CRC_MODE_NON_REFLECTED )

         if((crc & ((SecM_Crc32Type)0x01u << 31u)) != 0x00u)
         {
            crc <<= 1u;
            crc ^= SEC_CRC_32_POLYNOMIAL;
         }
         else
         {
            crc <<= 1u;
         }
#else

         if((crc & 0x01u) != 0x00u)
         {
            crc >>= 1u;
            crc ^= SEC_CRC_32_POLYNOMIAL;
         }
         else
         {
            crc >>= 1u;
         }
#endif
      }

      lookupCrc32[tableIndex] = crc;
   }

   lookupCrc32[SEC_CRC_32_TABLE_SIZE] = SEC_CRC_32_INIT_PATTERN;
}
#endif
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
#if( SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED )

static void SecM_GenerateLookupCrc64( FL_WDTriggerFctType pWatchdog ){
   SecM_ShortFastType   tableIndex;
   SecM_ByteFastType    bitIndex;
   SecM_Crc64Type       crc;

   for(tableIndex = 0u; tableIndex < SEC_CRC_64_TABLE_SIZE; tableIndex++){
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, tableIndex);

#if( SEC_CRC_64_MODE == SEC_CRC_MODE_NON_REFLECTED )

      crc.highWord = tableIndex << (32u - SEC_CRC_64_INDEX_BITS);
      crc.lowWord  = 0u;
#else

      crc.highWord = 0u;
      crc.lowWord  = tableIndex;
#endif

      for(bitIndex = 0u; bitIndex < SEC_CRC_64_INDEX_BITS; bitIndex++)
      {
#if( SEC_CRC_64_MODE == SEC_CRC_MODE_NON_REFLECTED )

         if((crc.highWord & (0x01u << 31u)) != 0x00u)
         {
            crc.highWord <<= 1u;

            crc.highWord |= (crc.lowWord >> 31u) & 0x01u;
            crc.highWord ^= polynomialCrc64.highWord;

            crc.lowWord <<= 1u;
            crc.lowWord ^= polynomialCrc64.lowWord;
         }
         else
         {
            crc.highWord <<= 1u;

            crc.highWord |= (crc.lowWord >> 31u) & 0x01u;

            crc.lowWord <<= 1u;
         }
#else

         if((crc.lowWord & 0x01u) != 0x00u)
         {
            crc.lowWord >>= 1u;

            crc.lowWord |= (crc.highWord & 0x01u);
            crc.lowWord ^= polynomialCrc64.lowWord;

            crc.highWord >>= 1u;
            crc.highWord ^= polynomialCrc64.highWord;
         }
         else
         {
            crc.lowWord  >>= 1u;

            crc.lowWord |= (crc.highWord & 0x01u);

            crc.highWord >>= 1u;
         }
#endif
      }

      lookupCrc64[tableIndex] = crc;
   }

   lookupCrc64[SEC_CRC_64_TABLE_SIZE] = initPatternCrc64;
}
#endif
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )

static void SecM_UpdateCrc16(V_MEMRAM1 SecM_CRC16ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam){
   SecM_ShortFastType      tableIndex;
   SecM_LengthFastType     sourceIndex;
   SecM_LengthFastType     byteCount;
   SecM_Crc16Type          tmpCrc;
   SecM_ByteType           currentData;
   FL_WDTriggerFctType     pWatchdog;

   tmpCrc      = (SecM_Crc16Type)pCrcParam->currentCRC;
   byteCount   = pCrcParam->crcByteCount;
   pWatchdog   = pCrcParam->wdTriggerFct;

   for(sourceIndex = 0u; sourceIndex < byteCount; sourceIndex++){
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, sourceIndex);

      currentData = pCrcParam->crcSourceBuffer[sourceIndex];

#if( SEC_CRC_16_MODE == SEC_CRC_MODE_NON_REFLECTED )
#if(SEC_CRC_16_OPT == SEC_CRC_SIZE_OPTIMIZED)

      tableIndex = (SecM_ShortFastType)((((SecM_Crc16Type)currentData >> (8u - SEC_CRC_16_INDEX_BITS)) ^ (tmpCrc >> (16u - SEC_CRC_16_INDEX_BITS))) & SEC_CRC_16_INDEX_MASK);
      tmpCrc = (SecM_Crc16Type)((tmpCrc << SEC_CRC_16_INDEX_BITS) ^ lookupCrc16[tableIndex]);
#endif

      tableIndex = (SecM_ShortFastType)(((SecM_Crc16Type)currentData ^ (tmpCrc >> (SecM_Crc16Type)(16u - SEC_CRC_16_INDEX_BITS))) & SEC_CRC_16_INDEX_MASK);
      tmpCrc = (SecM_Crc16Type)((tmpCrc << SEC_CRC_16_INDEX_BITS) ^ lookupCrc16[tableIndex]);
#else

      tableIndex = (SecM_ShortFastType)(((SecM_Crc16Type)currentData ^ tmpCrc) & SEC_CRC_16_INDEX_MASK);
      tmpCrc = (SecM_Crc16Type)((tmpCrc >> SEC_CRC_16_INDEX_BITS) ^ lookupCrc16[tableIndex]);

#if( SEC_CRC_16_OPT == SEC_CRC_SIZE_OPTIMIZED )

      tableIndex = (SecM_ShortFastType)((((SecM_Crc16Type)currentData >> (8u - SEC_CRC_16_INDEX_BITS)) ^ tmpCrc) & SEC_CRC_16_INDEX_MASK);
      tmpCrc = (SecM_Crc16Type)((tmpCrc >> SEC_CRC_16_INDEX_BITS) ^ lookupCrc16[tableIndex]);
#endif
#endif
   }

   pCrcParam->currentCRC = tmpCrc;
}
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )

static void SecM_UpdateCrc32( V_MEMRAM1 SecM_CRC32ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam ){
   SecM_ShortFastType      tableIndex;
   SecM_LengthFastType     sourceIndex;
   SecM_LengthFastType     byteCount;
   SecM_Crc32Type          tmpCrc;
   SecM_ByteType           currentData;
   FL_WDTriggerFctType     pWatchdog;

   tmpCrc      = (SecM_Crc32Type)pCrcParam->currentCRC;
   byteCount   = pCrcParam->crcByteCount;
   pWatchdog   = pCrcParam->wdTriggerFct;

   for(sourceIndex = 0u; sourceIndex < byteCount; sourceIndex++){
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, sourceIndex);

      currentData = pCrcParam->crcSourceBuffer[sourceIndex];

#if( SEC_CRC_32_MODE == SEC_CRC_MODE_NON_REFLECTED )
#if(SEC_CRC_32_OPT == SEC_CRC_SIZE_OPTIMIZED)

      tableIndex  = (SecM_ShortFastType)((((SecM_Crc32Type)currentData >> (8u - SEC_CRC_32_INDEX_BITS)) ^ (tmpCrc >> (32u - SEC_CRC_32_INDEX_BITS))) & SEC_CRC_32_INDEX_MASK);
      tmpCrc      = (SecM_Crc32Type)((tmpCrc << SEC_CRC_32_INDEX_BITS) ^ lookupCrc32[tableIndex]);
#endif

      tableIndex  = (SecM_ShortFastType)(((SecM_Crc32Type)currentData ^ (tmpCrc >> (32u - SEC_CRC_32_INDEX_BITS))) & SEC_CRC_32_INDEX_MASK);
      tmpCrc      = (SecM_Crc32Type)((tmpCrc << SEC_CRC_32_INDEX_BITS) ^ lookupCrc32[tableIndex]);
#else

      tableIndex  = (SecM_ShortFastType)(((SecM_Crc32Type)currentData ^ tmpCrc) & SEC_CRC_32_INDEX_MASK);
      tmpCrc      = (SecM_Crc32Type)((tmpCrc >> SEC_CRC_32_INDEX_BITS) ^ lookupCrc32[tableIndex]);
#if( SEC_CRC_32_OPT == SEC_CRC_SIZE_OPTIMIZED )

      tableIndex  = (SecM_ShortFastType)((((SecM_Crc32Type)currentData >> (8u - SEC_CRC_32_INDEX_BITS)) ^ tmpCrc) & SEC_CRC_32_INDEX_MASK);
      tmpCrc      = (SecM_Crc32Type)((tmpCrc >> SEC_CRC_32_INDEX_BITS) ^ lookupCrc32[tableIndex]);
#endif
#endif
   }

   pCrcParam->currentCRC = tmpCrc;
}
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )

static void SecM_UpdateCrc64(V_MEMRAM1 SecM_CRC64ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam){
   SecM_ShortFastType      tableIndex;
   SecM_LengthFastType     sourceIndex;
   SecM_LengthFastType     byteCount;
   SecM_Crc64Type          tmpCrc;
   SecM_ByteType           currentData;
   FL_WDTriggerFctType     pWatchdog;

   tmpCrc      = pCrcParam->currentCRC;
   byteCount   = pCrcParam->crcByteCount;
   pWatchdog   = pCrcParam->wdTriggerFct;

   for(sourceIndex = 0u; sourceIndex < byteCount; sourceIndex++){
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, sourceIndex);

      currentData = pCrcParam->crcSourceBuffer[sourceIndex];

#if( SEC_CRC_64_MODE == SEC_CRC_MODE_NON_REFLECTED )

#if( SEC_CRC_64_OPT == SEC_CRC_SIZE_OPTIMIZED )

      tableIndex = (SecM_ShortFastType)((((SecM_Crc64BaseType)currentData >> (8u - SEC_CRC_64_INDEX_BITS)) ^ (tmpCrc.highWord >> (32u - SEC_CRC_64_INDEX_BITS))) & SEC_CRC_64_INDEX_MASK);
      tmpCrc.highWord = (SecM_Crc64BaseType)(((tmpCrc.highWord << SEC_CRC_64_INDEX_BITS) | (tmpCrc.lowWord >> (32u - SEC_CRC_64_INDEX_BITS))) ^ lookupCrc64[tableIndex].highWord);
      tmpCrc.lowWord = (SecM_Crc64BaseType)((tmpCrc.lowWord << SEC_CRC_64_INDEX_BITS) ^ lookupCrc64[tableIndex].lowWord);
#endif

      tableIndex = (SecM_ShortFastType)(((SecM_Crc64BaseType)currentData ^ (tmpCrc.highWord >> (32u - SEC_CRC_64_INDEX_BITS))) & SEC_CRC_64_INDEX_MASK);
      tmpCrc.highWord = (SecM_Crc64BaseType)((((tmpCrc.highWord) << SEC_CRC_64_INDEX_BITS) | (tmpCrc.lowWord >> (32u - SEC_CRC_64_INDEX_BITS))) ^ lookupCrc64[tableIndex].highWord);
      tmpCrc.lowWord = (SecM_Crc64BaseType)(((tmpCrc.lowWord) << SEC_CRC_64_INDEX_BITS) ^ lookupCrc64[tableIndex].lowWord);
#else

      tableIndex = (SecM_ShortFastType)(((SecM_Crc64BaseType)currentData ^ tmpCrc.lowWord) & SEC_CRC_64_INDEX_MASK);

      tmpCrc.lowWord = (SecM_Crc64BaseType)((((tmpCrc.highWord << (32u - SEC_CRC_64_INDEX_BITS))) | (tmpCrc.lowWord >> SEC_CRC_64_INDEX_BITS)) ^ lookupCrc64[tableIndex].lowWord);
      tmpCrc.highWord = (SecM_Crc64BaseType)((tmpCrc.highWord >> SEC_CRC_64_INDEX_BITS) ^ lookupCrc64[tableIndex].highWord);

#if( SEC_CRC_64_OPT == SEC_CRC_SIZE_OPTIMIZED )

      tableIndex = (SecM_ShortFastType)((((SecM_Crc64BaseType)currentData >> (8u - SEC_CRC_64_INDEX_BITS)) ^ tmpCrc.lowWord) & SEC_CRC_64_INDEX_MASK);
      tmpCrc.lowWord = (SecM_Crc64BaseType)((((tmpCrc.highWord << (32u - SEC_CRC_64_INDEX_BITS))) | (tmpCrc.lowWord >> SEC_CRC_64_INDEX_BITS)) ^ lookupCrc64[tableIndex].lowWord);
      tmpCrc.highWord = (SecM_Crc64BaseType)((tmpCrc.highWord >> SEC_CRC_64_INDEX_BITS) ^ lookupCrc64[tableIndex].highWord);
#endif
#endif
   }

   pCrcParam->currentCRC = tmpCrc;
}
#endif

void SecM_InitPowerOnCRC(void){
#if defined( SEC_ENABLE_SAVE_RESTORE_CRC)
   SecM_ByteFastType i;

   for(i = 0u; i < SEC_CRC_WORKSPACE_SIZE; i++){
      SecM_CrcWorkspaceInfo[i].state = CRC_WORKSPACE_UNDEF;
   }
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
#if( SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED )

   lookupCrc16[SEC_CRC_16_TABLE_SIZE] = SEC_CRC_16_UNINIT_PATTERN;
#endif
#endif
#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
#if( SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED )
   lookupCrc32[SEC_CRC_32_TABLE_SIZE] = SEC_CRC_32_UNINIT_PATTERN;
#endif
#endif
#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
#if( SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED )
   lookupCrc64[SEC_CRC_64_TABLE_SIZE] = uninitPatternCrc64;
#endif
#endif
}

#if defined( SEC_ENABLE_CRC )

SecM_StatusType SecM_ComputeCRC( V_MEMRAM1 SecM_CRCParamType V_MEMRAM2 V_MEMRAM2 * crcParam ){
#if( SEC_CRC_TYPE == SEC_CRC16 )
   return SecM_ComputeCrc16(crcParam);
# elif( SEC_CRC_TYPE == SEC_CRC32 )
   return SecM_ComputeCrc32(crcParam);
# elif( SEC_CRC_TYPE == SEC_CRC64 )
   return SecM_ComputeCrc64(crcParam);
#else
   return SECM_NOT_OK;
#endif
}
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )

SecM_StatusType SecM_ComputeCrc16(V_MEMRAM1 SecM_CRC16ParamType V_MEMRAM2 V_MEMRAM3 * crcParam){
   SecM_StatusType result;
   SecM_Crc16Type  crcTransferred;

   result = SECM_NOT_OK;

   switch(crcParam->crcState){
      case SEC_CRC_INIT:
      {
#if( SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED )

         if(SEC_CRC_16_INIT_PATTERN != lookupCrc16[SEC_CRC_16_TABLE_SIZE])
         {
            SecM_GenerateLookupCrc16(crcParam->wdTriggerFct);
         }
#endif

         crcParam->currentCRC = initialValueCrc16;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_COMPUTE:
      {
         SecM_UpdateCrc16(crcParam);

         result = SECM_OK;

         break;
      }
      case SEC_CRC_FINALIZE:
      {
         crcParam->currentCRC ^= finalValueCrc16;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_VERIFY:
      {
         if(crcParam->crcByteCount == SEC_SIZE_CHECKSUM_CRC_16)
         {
            crcTransferred = (SecM_Crc16Type)SecM_GetInteger(SEC_SIZE_CHECKSUM_CRC_16, crcParam->crcSourceBuffer);

            if(crcTransferred == crcParam->currentCRC)
            {
               result = SECM_VER_OK;
            }
            else
            {
               result = SECM_VER_CRC;
            }
         }

         break;
      }
      case SEC_CRC_GET:
      {
         if(crcParam->crcByteCount >= SEC_SIZE_CHECKSUM_CRC_16)
         {
            SecM_SetInteger(SEC_SIZE_CHECKSUM_CRC_16, crcParam->currentCRC, crcParam->crcOutputBuffer);

            crcParam->crcByteCount = SEC_SIZE_CHECKSUM_CRC_16;

            result = SECM_OK;
         }

         break;
      }
      default:
      {
         break;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )

SecM_StatusType SecM_ComputeCrc32( V_MEMRAM1 SecM_CRC32ParamType V_MEMRAM2 V_MEMRAM3 * crcParam ){
   SecM_StatusType result;
   SecM_Crc32Type  crcTransferred;

   result = SECM_NOT_OK;

   switch(crcParam->crcState){
      case SEC_CRC_INIT:
      {
#if( SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED )

         if(SEC_CRC_32_INIT_PATTERN != lookupCrc32[SEC_CRC_32_TABLE_SIZE])
         {
            SecM_GenerateLookupCrc32(crcParam->wdTriggerFct);
         }
#endif

         crcParam->currentCRC = initialValueCrc32;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_COMPUTE:
      {
         SecM_UpdateCrc32(crcParam);

         result = SECM_OK;

         break;
      }
      case SEC_CRC_FINALIZE:
      {
         crcParam->currentCRC ^= finalValueCrc32;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_VERIFY:
      {
         if(crcParam->crcByteCount == SEC_SIZE_CHECKSUM_CRC_32)
         {
            crcTransferred = (SecM_Crc32Type)SecM_GetInteger(SEC_SIZE_CHECKSUM_CRC_32, crcParam->crcSourceBuffer);

            if(crcTransferred == crcParam->currentCRC)
            {
               result = SECM_VER_OK;
            }
            else
            {
               result = SECM_VER_CRC;
            }
         }

         break;
      }
      case SEC_CRC_GET:
      {
         if(crcParam->crcByteCount >= SEC_SIZE_CHECKSUM_CRC_32)
         {
            SecM_SetInteger(SEC_SIZE_CHECKSUM_CRC_32, crcParam->currentCRC, crcParam->crcOutputBuffer);

            crcParam->crcByteCount = SEC_SIZE_CHECKSUM_CRC_32;

            result = SECM_OK;
         }

         break;
      }
      default:
      {
         break;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )

SecM_StatusType SecM_ComputeCrc64(V_MEMRAM1 SecM_CRC64ParamType V_MEMRAM2 V_MEMRAM3 * crcParam){
   SecM_StatusType result;
   SecM_Crc64Type  crcTransferred;

   result = SECM_NOT_OK;

   switch(crcParam->crcState){
      case SEC_CRC_INIT:
      {
#if( SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED )

         if((initPatternCrc64.highWord != lookupCrc64[SEC_CRC_64_TABLE_SIZE].highWord)
            || (initPatternCrc64.lowWord != lookupCrc64[SEC_CRC_64_TABLE_SIZE].lowWord))
         {
            SecM_GenerateLookupCrc64(crcParam->wdTriggerFct);
         }
#endif

         crcParam->currentCRC = initialValueCrc64;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_COMPUTE:
      {
         SecM_UpdateCrc64(crcParam);

         result = SECM_OK;

         break;
      }
      case SEC_CRC_FINALIZE:
      {
         crcParam->currentCRC.highWord ^= finalValueCrc64.highWord;
         crcParam->currentCRC.lowWord  ^= finalValueCrc64.lowWord;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_VERIFY:
      {
         if(crcParam->crcByteCount == SEC_SIZE_CHECKSUM_CRC_64)
         {
            crcTransferred.highWord = (SecM_Crc64BaseType)SecM_GetInteger(SEC_SIZE_CHECKSUM_CRC_32, crcParam->crcSourceBuffer);
            crcTransferred.lowWord  = (SecM_Crc64BaseType)SecM_GetInteger(SEC_SIZE_CHECKSUM_CRC_32, &crcParam->crcSourceBuffer[SEC_SIZE_CHECKSUM_CRC_32]);

            if( (crcTransferred.highWord == crcParam->currentCRC.highWord)
              || (crcTransferred.lowWord == crcParam->currentCRC.lowWord) )
            {
               result = SECM_VER_OK;
            }
            else
            {
               result = SECM_VER_CRC;
            }
         }

         break;
      }
      case SEC_CRC_GET:
      {
         if(crcParam->crcByteCount >= SEC_SIZE_CHECKSUM_CRC_64)
         {
            SecM_SetInteger(SEC_SIZE_CHECKSUM_CRC_32, crcParam->currentCRC.highWord, crcParam->crcOutputBuffer);
            SecM_SetInteger(SEC_SIZE_CHECKSUM_CRC_32, crcParam->currentCRC.lowWord, &crcParam->crcOutputBuffer[SEC_SIZE_CHECKSUM_CRC_32]);

            crcParam->crcByteCount = SEC_SIZE_CHECKSUM_CRC_64;

            result = SECM_OK;
         }

         break;
      }
      default:
      {
         break;
      }
   }

   return result;
}
#endif

#if defined( SEC_ENABLE_SAVE_RESTORE_CRC )

SecM_StatusType SecM_SaveContextCrc(SecM_WordType workspaceIdx, SecM_RamDataType contextBuffer, SecM_RamWordType contextBufferLengthPtr){
   SecM_StatusType result = SECM_NOT_OK;
   if(workspaceIdx < SEC_CRC_WORKSPACE_SIZE){
      SecM_CrcWorkspaceInfoType const * localWorkspace = &SecM_CrcWorkspaceInfo[workspaceIdx];
      if(localWorkspace->state == CRC_WORKSPACE_INIT)
      {
         if(*contextBufferLengthPtr >= localWorkspace->workspaceLength)
         {
            SecM_CopyBuffer((SecM_ConstRamDataType)localWorkspace->workspacePtr, contextBuffer, (SecM_ShortType)localWorkspace->workspaceLength);
            *contextBufferLengthPtr = localWorkspace->workspaceLength;
            result = SECM_OK;
         }
      }
   }

   return result;
}
#endif

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

