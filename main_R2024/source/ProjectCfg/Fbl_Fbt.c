

#include "fbl_inc.hpp"

V_MEMROM0 V_MEMROM1_FAR tFlashBlock V_MEMROM2_FAR FlashBlock[] =
{
  {
    0x00000000uL  ,
    0x00001FFFuL
  },
  {
    0x00002000uL  ,
    0x00003FFFuL
  },
  {
    0x00004000uL  ,
    0x00005FFFuL
  },
  {
    0x00006000uL  ,
    0x00007FFFuL
  },
  {
    0x00008000uL  ,
    0x00009FFFuL
  },
  {
    0x0000A000uL  ,
    0x0000BFFFuL
  },
  {
    0x0000C000uL  ,
    0x0000DFFFuL
  },
  {
    0x0000E000uL  ,
    0x0000FFFFuL
  },
  {
    0x00010000uL  ,
    0x00017FFFuL
  },
  {
    0x00018000uL  ,
    0x0001FFFFuL
  },
  {
    0x00020000uL  ,
    0x00027FFFuL
  },
  {
    0x00028000uL  ,
    0x0002FFFFuL
  },
  {
    0x00030000uL  ,
    0x00037FFFuL
  },
  {
    0x00038000uL  ,
    0x0003FFFFuL
  },
  {
    0x00040000uL  ,
    0x00047FFFuL
  },
  {
    0x00048000uL  ,
    0x0004FFFFuL
  },
  {
    0x00050000uL  ,
    0x0005FFFFuL
  },
  {
    0x00060000uL  ,
    0x0006FFFFuL
  },
  {
    0x00070000uL  ,
    0x00077FFFuL
  },
  {
    0x00078000uL  ,
    0x0007EFFFuL
  },
  {
    0x0007F000uL  ,
    0x0007FFFFuL
  },
  {
    0x00080000uL  ,
    0x0008FFFFuL
  },
  {
    0x00090000uL  ,
    0x0009FFFFuL
  },
  {
    0x000C0000uL  ,
    0x000CFFFFuL
  },
  {
    0x000D0000uL  ,
    0x000DFFFFuL
  },
  {
    0x000E0000uL  ,
    0x000EFFFFuL
  },
  {
    0x000F0000uL  ,
    0x000FFFFFuL
  },
  {
    0x01000000uL  ,
    0x01007FFFuL
  }
};
V_MEMROM0 V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfFlashBlock = sizeof(FlashBlock) / sizeof(FlashBlock[0]);

#if defined( FLASH_SEGMENT_SIZE )
# if( FLASH_SEGMENT_SIZE != 256uL )
#  error "Consistency check failed! Adjust Cfg5 configuration!"
# endif
#endif

#if defined( FBL_FLASH_DELETED )
# if( FBL_FLASH_DELETED != 0xFFu )
#  error "Consistency check failed! Adjust Cfg5 configuration!"
# endif
#endif

