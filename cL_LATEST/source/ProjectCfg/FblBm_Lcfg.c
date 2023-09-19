#define FBLBM_CFG_SOURCE

#include "FblBm_Cfg.hpp"

#define FBLBM_START_SEC_CONST
#include "MemMap.hpp"
V_MEMROM0 V_MEMROM1 tFblBmHdrTargetListEntry V_MEMROM2 FblBm_BootTargetList[FBLBM_BOOTTARGETLIST_SIZE] = {
      {
            FBLBMHDR_TARGET_FBL
         ,  V_NULL
         ,  0u
      }
   ,  {
            FBLBMHDR_TARGET_APPL
         ,  V_NULL
         ,  0u
      }
};
#define FBLBM_STOP_SEC_CONST
#include "MemMap.hpp"
