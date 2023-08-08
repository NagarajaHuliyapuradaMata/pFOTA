

#include "fbl_inc.hpp"

V_MEMROM0 V_MEMROM1 tLogicalBlockTable V_MEMROM2 FblLogicalBlockTable =
{
  FBL_LBT_MAGIC_FLAG,
  {
    0x01u
  }  ,
  1u,
  {
    {
      0u,
      TRUE  ,
      0x00020000uL  ,
      0x00058000uL  ,
      0x00020000uL  ,
      0x0000u  ,
      (tExportFct)SecM_VerifySignature  ,
      (tExportFct)SecM_VerifySignature  ,
      (tExportFct)SecM_VerifySignature  ,
      (tExportFct)SecM_Verification
    }
  }
};

