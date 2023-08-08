#define VSTDLIB_SOURCE

#include "vstdlib.hpp"

#if(VSTDLIB_DEV_ERROR_REPORT == STD_ON)
# include "SwcServiceDet.hpp"
#endif

#if(  (VSTDLIB_SW_MAJOR_VERSION != (3u)) \
    || (VSTDLIB_SW_MINOR_VERSION != (0u)) \
    || (VSTDLIB_SW_PATCH_VERSION != (0u)) )
# error "Version numbers of vstdlib.c and vstdlib.h are inconsistent!"
#endif

#if(  (VSTDLIB_CFG_MAJOR_VERSION != (2u)) \
    || (VSTDLIB_CFG_MINOR_VERSION != (0u)) )
# error "Version numbers of vstdlib.c and VStdLib_Cfg.h are inconsistent!"
#endif

# if !defined (VSTDLIB_USE_LIBRARY_FUNCTIONS)
#  error "VSTDLIB_USE_LIBRARY_FUNCTIONS has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_RUNTIME_OPTIMIZATION)
#  error "VSTDLIB_RUNTIME_OPTIMIZATION has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_USE_JUMPTABLES)
#  error "VSTDLIB_USE_JUMPTABLES has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_DEV_ERROR_DETECT)
#  error "VSTDLIB_DEV_ERROR_DETECT has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_DEV_ERROR_REPORT)
#  error "VSTDLIB_DEV_ERROR_REPORT has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_VERSION_INFO_API)
#  error "VSTDLIB_VERSION_INFO_API has to be defined.. check VStdLib_Cfg.h!"
# endif

# if !defined (VSTDLIB_DUMMY_STATEMENT)
#  error "VSTDLIB_DUMMY_STATEMENT has to be defined.. check VStdLib_Cfg.h!"
# endif

# if((VSTDLIB_DEV_ERROR_REPORT == STD_ON) && (VSTDLIB_DEV_ERROR_DETECT != STD_ON))
#  error "VSTDLIB_DEV_ERROR_REPORT defined to STD_ON requires VSTDLIB_DEV_ERROR_DETECT also to be defined to STD_ON!"
# endif

# if(VSTDLIB_USE_LIBRARY_FUNCTIONS == STD_ON)
#  if(!defined (VStdLib_MemClr) || !defined (VStdLib_MemSet) || !defined (VStdLib_MemCpy) || \
       !defined (VStdLib_MemCpy16) || !defined (VStdLib_MemCpy32))
#   error "VStdLib_MemClr, VStdLib_MemSet, VStdLib_MemCpy, VStdLib_MemCpy16 and VStdLib_MemCpy32 have to be defined!"
#  endif
# else
#  if((VSTDLIB_SUPPORT_LARGE_DATA != STD_ON) && (VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON))
#   error "VSTDLIB_RUNTIME_OPTIMIZATION must not be enabled if large data support is not given!"
#  endif
# endif

#define VSTDLIB_MASK_3                       (0x03u)
#define VSTDLIB_MASK_31                      (0x1Fu)

#define VSTDLIB_ALIGN_OFFSET(ptr)   \
  (uint8_least)((4u - (uint32_least)(ptr)) & VSTDLIB_MASK_3)

#if !defined (VSTDLIB_LOCAL_INLINE)
# define VSTDLIB_LOCAL_INLINE                LOCAL_INLINE
#endif

#define VSTDLIB_START_SEC_CODE
#include "MemMap.hpp"

#if(VSTDLIB_USE_LIBRARY_FUNCTIONS != STD_ON)
# if(VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON)

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_8_3(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8 nPattern,
  uint8_least nCnt);

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_8_31(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8 nPattern,
  uint8_least nCnt);

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_32_Aligned(
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst32,
  uint8 nPattern,
  uint32_least nCnt);

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_3(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc8,
  uint8_least nCnt);

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_31(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc8,
  uint8_least nCnt);

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_32_Aligned(
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst32,
  P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc32,
  uint32_least nCnt);

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_PartialWord(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8_least nCnt,
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pPrev,
  P2VAR(uint32_least, AUTOMATIC, VSTDLIB_VAR_FAR) pDPos);

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_32_Unaligned(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc32,
  uint32_least nCnt,
  uint8_least nDstOffset);

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_8_3(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8 nPattern,
  uint8_least nCnt){
#  if(VSTDLIB_USE_JUMPTABLES == STD_ON)

  switch(nCnt){
    case 3:
      pDst8[2] = nPattern;

    case 2:
      pDst8[1] = nPattern;

    case 1:
      pDst8[0] = nPattern;

    default:

      break;
  }

#  else

  uint8_least idx;

  for (idx = 0u; idx < nCnt; idx++){
    pDst8[idx] = nPattern;
  }

#  endif
}

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_8_31(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8 nPattern,
  uint8_least nCnt){
#  if(VSTDLIB_USE_JUMPTABLES == STD_ON)

  switch(nCnt){
    case 31:
      pDst8[30] = nPattern;

    case 30:
      pDst8[29] = nPattern;

    case 29:
      pDst8[28] = nPattern;

    case 28:
      pDst8[27] = nPattern;

    case 27:
      pDst8[26] = nPattern;

    case 26:
      pDst8[25] = nPattern;

    case 25:
      pDst8[24] = nPattern;

    case 24:
      pDst8[23] = nPattern;

    case 23:
      pDst8[22] = nPattern;

    case 22:
      pDst8[21] = nPattern;

    case 21:
      pDst8[20] = nPattern;

    case 20:
      pDst8[19] = nPattern;

    case 19:
      pDst8[18] = nPattern;

    case 18:
      pDst8[17] = nPattern;

    case 17:
      pDst8[16] = nPattern;

    case 16:
      pDst8[15] = nPattern;

    case 15:
      pDst8[14] = nPattern;

    case 14:
      pDst8[13] = nPattern;

    case 13:
      pDst8[12] = nPattern;

    case 12:
      pDst8[11] = nPattern;

    case 11:
      pDst8[10] = nPattern;

    case 10:
      pDst8[9] = nPattern;

    case 9:
      pDst8[8] = nPattern;

    case 8:
      pDst8[7] = nPattern;

    case 7:
      pDst8[6] = nPattern;

    case 6:
      pDst8[5] = nPattern;

    case 5:
      pDst8[4] = nPattern;

    case 4:
      pDst8[3] = nPattern;

    case 3:
      pDst8[2] = nPattern;

    case 2:
      pDst8[1] = nPattern;

    case 1:
      pDst8[0] = nPattern;

    default:

      break;
  }

#  else

  uint8_least idx;

  for (idx = 0u; idx < nCnt; idx++){
    pDst8[idx] = nPattern;
  }

#  endif
}

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemSet_32_Aligned(
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst32,
  uint8 nPattern,
  uint32_least nCnt){
  uint32_least dPos = 0u;
  uint32_least remaining;
  uint32 nPattern32 =
    (uint32)(((uint32)nPattern << 24u) | ((uint32)nPattern << 16u) | ((uint32)nPattern << 8u) | nPattern);

  for (remaining = nCnt; remaining >= 16u; remaining -= 16u){
    pDst32[dPos]      = nPattern32;
    pDst32[dPos + 1u] = nPattern32;
    pDst32[dPos + 2u] = nPattern32;
    pDst32[dPos + 3u] = nPattern32;
    dPos += 4u;
  }

#  if(VSTDLIB_USE_JUMPTABLES == STD_ON)

  switch(remaining){
    case 15:
    case 14:
    case 13:
    case 12:
      pDst32[dPos] = nPattern32;
      dPos++;

    case 11:
    case 10:
    case 9:
    case 8:
      pDst32[dPos] = nPattern32;
      dPos++;

    case 7:
    case 6:
    case 5:
    case 4:
      pDst32[dPos] = nPattern32;
      dPos++;

    case 3:
    case 2:
    case 1:
      VStdLib_Loc_MemSet_8_3(
        (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pDst32[dPos],
        nPattern,
        (uint8_least) (remaining & VSTDLIB_MASK_3));

    default:

      break;
  }

#  else

  VStdLib_Loc_MemSet_8_31(
    (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pDst32[dPos],
    nPattern,
    (uint8_least) remaining);

#  endif
}

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_3(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc8,
  uint8_least nCnt){
#  if(VSTDLIB_USE_JUMPTABLES == STD_ON)

  switch(nCnt){
    case 3:
      pDst8[2] = pSrc8[2];

    case 2:
      pDst8[1] = pSrc8[1];

    case 1:
      pDst8[0] = pSrc8[0];

    default:

      break;
  }

#  else

  uint8_least idx;

  for (idx = 0u; idx < nCnt; idx++){
    pDst8[idx] = pSrc8[idx];
  }

#  endif
}

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_31(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc8,
  uint8_least nCnt){
#  if(VSTDLIB_USE_JUMPTABLES == STD_ON)

  switch(nCnt){
    case 31:
      pDst8[30] = pSrc8[30];

    case 30:
      pDst8[29] = pSrc8[29];

    case 29:
      pDst8[28] = pSrc8[28];

    case 28:
      pDst8[27] = pSrc8[27];

    case 27:
      pDst8[26] = pSrc8[26];

    case 26:
      pDst8[25] = pSrc8[25];

    case 25:
      pDst8[24] = pSrc8[24];

    case 24:
      pDst8[23] = pSrc8[23];

    case 23:
      pDst8[22] = pSrc8[22];

    case 22:
      pDst8[21] = pSrc8[21];

    case 21:
      pDst8[20] = pSrc8[20];

    case 20:
      pDst8[19] = pSrc8[19];

    case 19:
      pDst8[18] = pSrc8[18];

    case 18:
      pDst8[17] = pSrc8[17];

    case 17:
      pDst8[16] = pSrc8[16];

    case 16:
      pDst8[15] = pSrc8[15];

    case 15:
      pDst8[14] = pSrc8[14];

    case 14:
      pDst8[13] = pSrc8[13];

    case 13:
      pDst8[12] = pSrc8[12];

    case 12:
      pDst8[11] = pSrc8[11];

    case 11:
      pDst8[10] = pSrc8[10];

    case 10:
      pDst8[9] = pSrc8[9];

    case 9:
      pDst8[8] = pSrc8[8];

    case 8:
      pDst8[7] = pSrc8[7];

    case 7:
      pDst8[6] = pSrc8[6];

    case 6:
      pDst8[5] = pSrc8[5];

    case 5:
      pDst8[4] = pSrc8[4];

    case 4:
      pDst8[3] = pSrc8[3];

    case 3:
      pDst8[2] = pSrc8[2];

    case 2:
      pDst8[1] = pSrc8[1];

    case 1:
      pDst8[0] = pSrc8[0];

    default:

      break;
  }

#  else

  uint8_least idx;

  for (idx = 0u; idx < nCnt; idx++){
    pDst8[idx] = pSrc8[idx];
  }

#  endif
}

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_32_Aligned(
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst32,
  P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc32,
  uint32_least nCnt){
  uint32_least dPos = 0u;
  uint32_least remaining;
  uint32 x0, x1, x2, x3;

  for (remaining = nCnt; remaining >= 16u; remaining -= 16u){
    x0 = pSrc32[dPos];
    x1 = pSrc32[dPos + 1u];
    x2 = pSrc32[dPos + 2u];
    x3 = pSrc32[dPos + 3u];
    pDst32[dPos]      = x0;
    pDst32[dPos + 1u] = x1;
    pDst32[dPos + 2u] = x2;
    pDst32[dPos + 3u] = x3;
    dPos += 4u;
  }

#  if(VSTDLIB_USE_JUMPTABLES == STD_ON)

  switch(remaining){
    case 15:
    case 14:
    case 13:
    case 12:
      pDst32[dPos] = pSrc32[dPos];
      dPos++;

    case 11:
    case 10:
    case 9:
    case 8:
      pDst32[dPos] = pSrc32[dPos];
      dPos++;

    case 7:
    case 6:
    case 5:
    case 4:
      pDst32[dPos] = pSrc32[dPos];
      dPos++;

    case 3:
    case 2:
    case 1:
      VStdLib_Loc_MemCpy_8_3(
        (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pDst32[dPos],
        (P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pSrc32[dPos],
        (uint8_least) (remaining & VSTDLIB_MASK_3));

    default:

      break;
  }

#  else

  VStdLib_Loc_MemCpy_8_31(
    (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pDst32[dPos],
    (P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pSrc32[dPos],
    (uint8_least) remaining);

#  endif
}

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_8_PartialWord(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  uint8_least nCnt,
  P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pPrev,
  P2VAR(uint32_least, AUTOMATIC, VSTDLIB_VAR_FAR) pDPos){
#  if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
#   if(VSTDLIB_USE_JUMPTABLES == STD_ON)

  switch(nCnt){
    case 3:
      pDst8[*pDPos] = (uint8) *pPrev;
      (*pDPos)++;
      (*pPrev) >>= 8u;

    case 2:
      pDst8[*pDPos] = (uint8) *pPrev;
      (*pDPos)++;
      (*pPrev) >>= 8u;

    default:
      pDst8[*pDPos] = (uint8) *pPrev;
      (*pDPos)++;
      (*pPrev) >>= 8u;
      break;
  }

#   else

  uint8_least idx;

  for (idx = 0u; idx < nCnt; idx++){
    pDst8[*pDPos] = (uint8) (uint8) *pPrev;
    (*pDPos)++;
    (*pPrev) >>= 8u;
  }

#   endif
#  else
#   if(VSTDLIB_USE_JUMPTABLES == STD_ON)

  switch(nCnt){
    case 3:
      pDst8[*pDPos] = (uint8) ((*pPrev) >> 24u);
      (*pDPos)++;
      (*pPrev) <<= 8u;

    case 2:
      pDst8[*pDPos] = (uint8) ((*pPrev) >> 24u);
      (*pDPos)++;
      (*pPrev) <<= 8u;

    default:
      pDst8[*pDPos] = (uint8) ((*pPrev) >> 24u);
      (*pDPos)++;
      (*pPrev) <<= 8u;
      break;
  }

#   else

  uint8_least idx;

  for (idx = 0u; idx < nCnt; idx++){
    pDst8[*pDPos] = (uint8) ((*pPrev) >> 24u);
    (*pDPos)++;
    (*pPrev) <<= 8u;
  }

#   endif
#  endif
}

VSTDLIB_LOCAL_INLINE FUNC(void, VSTDLIB_CODE) VStdLib_Loc_MemCpy_32_Unaligned(
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8,
  P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc32,
  uint32_least nCnt,
  uint8_least nDstOffset){
  uint32_least dPos = 0u;
  uint32_least sPos = 0u;
  uint32_least remaining = nCnt;

  if(remaining >= 32u){
    P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst32;
    uint32 prev;

    prev = pSrc32[sPos];
    remaining -= 4u;
    VStdLib_Loc_MemCpy_8_PartialWord(
      pDst8,
      nDstOffset,
      &prev,
      &dPos);

    pDst32 = (P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR)) &pDst8[dPos];
    dPos = 0u;
    sPos++;

    if(nDstOffset == 3u){
      for (; remaining >= 16u; remaining -= 16u)
      {
        uint32 x0, x1, x2, x3, x4;
        x1 = pSrc32[sPos];
        x2 = pSrc32[sPos + 1u];
        x3 = pSrc32[sPos + 2u];
        x4 = pSrc32[sPos + 3u];
#  if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        x0 = prev | (x1 << 8u);
        x1 = (x1 >> 24u) | (x2 << 8u);
        x2 = (x2 >> 24u) | (x3 << 8u);
        x3 = (x3 >> 24u) | (x4 << 8u);
        prev = x4 >> 24u;
#  else
        x0 = prev | (x1 >> 8u);
        x1 = (x1 << 24u) | (x2 >> 8u);
        x2 = (x2 << 24u) | (x3 >> 8u);
        x3 = (x3 << 24u) | (x4 >> 8u);
        prev = x4 << 24;
#  endif
        pDst32[dPos]      = x0;
        pDst32[dPos + 1u] = x1;
        pDst32[dPos + 2u] = x2;
        pDst32[dPos + 3u] = x3;
        dPos += 4u;
        sPos += 4u;
      }
    }
    else if(nDstOffset == 2u){
      for (; remaining >= 16u; remaining -= 16u)
      {
        uint32 x0, x1, x2, x3, x4;
        x1 = pSrc32[sPos];
        x2 = pSrc32[sPos + 1u];
        x3 = pSrc32[sPos + 2u];
        x4 = pSrc32[sPos + 3u];
#  if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        x0 = prev | (x1 << 16u);
        x1 = (x1 >> 16u) | (x2 << 16u);
        x2 = (x2 >> 16u) | (x3 << 16u);
        x3 = (x3 >> 16u) | (x4 << 16u);
        prev = x4 >> 16u;
#  else
        x0 = prev | (x1 >> 16);
        x1 = (x1 << 16u) | (x2 >> 16u);
        x2 = (x2 << 16u) | (x3 >> 16u);
        x3 = (x3 << 16u) | (x4 >> 16u);
        prev = x4 << 16;
#  endif
        pDst32[dPos]      = x0;
        pDst32[dPos + 1u] = x1;
        pDst32[dPos + 2u] = x2;
        pDst32[dPos + 3u] = x3;
        dPos += 4u;
        sPos += 4u;
      }

    }
    else{
      for (; remaining >= 16u; remaining -= 16u)
      {
        uint32 x0, x1, x2, x3, x4;
        x1 = pSrc32[sPos];
        x2 = pSrc32[sPos + 1u];
        x3 = pSrc32[sPos + 2u];
        x4 = pSrc32[sPos + 3u];
#  if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        x0 = prev | (x1 << 24u);
        x1 = (x1 >> 8u) | (x2 << 24u);
        x2 = (x2 >> 8u) | (x3 << 24u);
        x3 = (x3 >> 8u) | (x4 << 24u);
        prev = x4 >> 8u;
#  else
        x0 = prev | (x1 >> 24u);
        x1 = (x1 << 8u) | (x2 >> 24u);
        x2 = (x2 << 8u) | (x3 >> 24u);
        x3 = (x3 << 8u) | (x4 >> 24u);
        prev = x4 << 8u;
#  endif
        pDst32[dPos]      = x0;
        pDst32[dPos + 1u] = x1;
        pDst32[dPos + 2u] = x2;
        pDst32[dPos + 3u] = x3;
        dPos += 4u;
        sPos += 4u;
      }
    }

    {
      uint8_least prevShift = (nDstOffset << 3u) & VSTDLIB_MASK_31;
      uint8_least xShift = 32u - prevShift;

      for (; remaining >= 4u; remaining -= 4u)
      {
        uint32 x0, x1;
        x1 = pSrc32[sPos];
#  if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        x0 = prev | (x1 << xShift);
        prev = x1 >> prevShift;
#  else
        x0 = prev | (x1 >> xShift);
        prev = x1 << prevShift;
#  endif
        pDst32[dPos] = x0;
        dPos++;
        sPos++;
      }
    }

    pDst8 = (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pDst32[dPos];
    dPos = 0u;
    VStdLib_Loc_MemCpy_8_PartialWord(
      pDst8,
      (4u - nDstOffset),
      &prev,
      &dPos);
  }

  VStdLib_Loc_MemCpy_8_31(
    &pDst8[dPos],
    (P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) &pSrc32[sPos],
    (uint8_least) remaining);
}

# endif

FUNC(void, VSTDLIB_CODE) VStdLib_MemSet(P2VAR(void, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                        uint8 nPattern,
                                        VStdLib_CntType nCnt){
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8 = \
    (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst;
  uint8 errorId = VSTDLIB_E_NO_ERROR;

# if(VSTDLIB_DEV_ERROR_DETECT == STD_ON)

  if(pDst == NULL_PTR){
    errorId = VSTDLIB_E_PARAM_POINTER;
  }
  else
# endif
  {
# if(VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON)

    if(nCnt < 32u){
      VStdLib_Loc_MemSet_8_31(
        pDst8,
        nPattern,
        (uint8_least) nCnt);
    }

    else{
      uint8_least nDstOffset = VSTDLIB_ALIGN_OFFSET(pDst8);

      if(nDstOffset != 0u)
      {
        VStdLib_Loc_MemSet_8_3(
          pDst8,
          nPattern,
          nDstOffset);

        pDst8 = &pDst8[nDstOffset];
        nCnt -= nDstOffset;
      }

      VStdLib_Loc_MemSet_32_Aligned(
        (P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst8,
        nPattern,
        nCnt);
    }

# else

    VStdLib_CntType idx;

    for (idx = 0u; idx < nCnt; idx++){
      pDst8[idx] = nPattern;
    }

# endif
  }

# if(VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if(errorId != VSTDLIB_E_NO_ERROR){
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_MEM_SET, errorId);
  }
# else
  VSTDLIB_DUMMY_STATEMENT(errorId);
# endif
}

FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy(P2VAR(void, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                        P2CONST(void, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                        VStdLib_CntType nCnt){
  P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pDst8 = \
    (P2VAR(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst;
  P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc8 = \
    (P2CONST(uint8, AUTOMATIC, VSTDLIB_VAR_FAR)) pSrc;
  uint8 errorId = VSTDLIB_E_NO_ERROR;

# if(VSTDLIB_DEV_ERROR_DETECT == STD_ON)

  if((pDst == NULL_PTR) || (pSrc == NULL_PTR)){
    errorId = VSTDLIB_E_PARAM_POINTER;
  }
  else
# endif
  {
# if(VSTDLIB_RUNTIME_OPTIMIZATION == STD_ON)

    if(nCnt < 32u){
      VStdLib_Loc_MemCpy_8_31(
        pDst8,
        pSrc8,
        (uint8_least) nCnt);
    }

    else{
      uint8_least nSrcOffset = VSTDLIB_ALIGN_OFFSET(pSrc8);
      uint8_least nDstOffset;

      if(nSrcOffset != 0u)
      {
        VStdLib_Loc_MemCpy_8_3(
          pDst8,
          pSrc8,
          nSrcOffset);

        pSrc8 = &pSrc8[nSrcOffset];
        pDst8 = &pDst8[nSrcOffset];
        nCnt -= nSrcOffset;
      }

      nDstOffset = VSTDLIB_ALIGN_OFFSET(pDst8);

      if(nDstOffset == 0u)
      {
        VStdLib_Loc_MemCpy_32_Aligned(
          (P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR)) pDst8,
          (P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR)) pSrc8,
          nCnt);
      }

      else
      {
        VStdLib_Loc_MemCpy_32_Unaligned(
          pDst8,
          (P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR)) pSrc8,
          nCnt,
          nDstOffset);
      }
    }

# else

    VStdLib_CntType idx;

    for (idx = 0u; idx < nCnt; idx++){
      pDst8[idx] = pSrc8[idx];
    }

# endif
  }

# if(VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if(errorId != VSTDLIB_E_NO_ERROR){
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_MEM_COPY, errorId);
  }
# else
  VSTDLIB_DUMMY_STATEMENT(errorId);
# endif
}

FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy16(P2VAR(uint16, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                          P2CONST(uint16, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                          VStdLib_CntType nCnt){
  VStdLib_CntType idx;
  uint8 errorId = VSTDLIB_E_NO_ERROR;

# if(VSTDLIB_DEV_ERROR_DETECT == STD_ON)

  if((pDst == NULL_PTR) || (pSrc == NULL_PTR)){
    errorId = VSTDLIB_E_PARAM_POINTER;
  }
  else
# endif
  {
    for (idx = 0u; idx < nCnt; idx++){
      pDst[idx] = pSrc[idx];
    }
  }

# if(VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if(errorId != VSTDLIB_E_NO_ERROR){
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_MEM_COPY_16, errorId);
  }
# else
  VSTDLIB_DUMMY_STATEMENT(errorId);
# endif
}

FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy32(P2VAR(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                          P2CONST(uint32, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                          VStdLib_CntType nCnt){
  VStdLib_CntType idx;
  uint8 errorId = VSTDLIB_E_NO_ERROR;

# if(VSTDLIB_DEV_ERROR_DETECT == STD_ON)

  if((pDst == NULL_PTR) || (pSrc == NULL_PTR)){
    errorId = VSTDLIB_E_PARAM_POINTER;
  }
  else
# endif
  {
    for (idx = 0u; idx < nCnt; idx++){
      pDst[idx] = pSrc[idx];
    }
  }

# if(VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if(errorId != VSTDLIB_E_NO_ERROR){
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_MEM_COPY_32, errorId);
  }
# else
  VSTDLIB_DUMMY_STATEMENT(errorId);
# endif
}

#endif

FUNC(void, VSTDLIB_CODE) VStdLib_MemCpy_s(P2VAR(void, AUTOMATIC, VSTDLIB_VAR_FAR) pDst,
                                          VStdLib_CntType nDstSize,
                                          P2CONST(void, AUTOMATIC, VSTDLIB_VAR_FAR) pSrc,
                                          VStdLib_CntType nCnt){
  uint8 errorId = VSTDLIB_E_NO_ERROR;

  if(nCnt > nDstSize){
    errorId = VSTDLIB_E_PARAM_SIZE;
  }
  else{
    VStdLib_MemCpy(pDst, pSrc, nCnt);
  }

#if(VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if(errorId != VSTDLIB_E_NO_ERROR){
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_MEM_COPY_S, errorId);
  }
#else
  VSTDLIB_DUMMY_STATEMENT(errorId);
#endif
}

#if(VSTDLIB_VERSION_INFO_API == STD_ON)

FUNC(void, VSTDLIB_CODE) VStdLib_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VSTDLIB_APPL_VAR) versioninfo){
  uint8 errorId = VSTDLIB_E_NO_ERROR;

# if(VSTDLIB_DEV_ERROR_DETECT == STD_ON)

  if(versioninfo == NULL_PTR){
    errorId = VSTDLIB_E_PARAM_POINTER;
  }
  else
# endif
  {
    versioninfo->vendorID = VSTDLIB_VENDOR_ID;
    versioninfo->moduleID = VSTDLIB_MODULE_ID;
    versioninfo->sw_major_version = VSTDLIB_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = VSTDLIB_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = VSTDLIB_SW_PATCH_VERSION;
  }

# if(VSTDLIB_DEV_ERROR_REPORT == STD_ON)
  if(errorId != VSTDLIB_E_NO_ERROR){
    (void) Det_ReportError(VSTDLIB_MODULE_ID, VSTDLIB_INSTANCE_ID_DET, VSTDLIB_SID_GET_VERSION_INFO, errorId);
  }
# else
  VSTDLIB_DUMMY_STATEMENT(errorId);
# endif
}

#endif

#define VSTDLIB_STOP_SEC_CODE
#include "MemMap.hpp"

