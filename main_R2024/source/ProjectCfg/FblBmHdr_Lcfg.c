

#define FBLBMHDR_LCFG_SOURCE

#include "Std_Types.hpp"
#include "FblBmHdr_Cfg.hpp"

extern uint8 _FBLENTRY[];

#define FBLBMHDR_BMHEADER_START_SEC_CONST
#include "MemMap.hpp"

CONST(tFblBmHdrHeader, FBLBMHDR_CONST) FblBmHdrHeader =
{
  FBLBMHDR_MAGIC_FLAG,
  (tFblAddress) &_FBLENTRY,
  FBLBMHDR_TARGET_FBL,
  0x00000000uL,
  0x00020000uL,
  1u,
  {
    {
      0x00000000uL,
      0x00020000uL
    }
  }
};

#define FBLBMHDR_BMHEADER_STOP_SEC_CONST
#include "MemMap.hpp"

#define FBLBMHDR_START_SEC_CONST
#include "MemMap.hpp"

CONST(uint32, FBLBMHDR_CONST) FblBmHdrTargets[FBLBMHDR_NUM_OF_TARGETS] =
{
  255uL  ,
  255uL  ,
  255uL
};

#define FBLBMHDR_STOP_SEC_CONST
#include "MemMap.hpp"

#define FBLBMHDR_START_SEC_CODE
#include "MemMap.hpp"

#define FBLBMHDR_STOP_SEC_CODE
#include "MemMap.hpp"

