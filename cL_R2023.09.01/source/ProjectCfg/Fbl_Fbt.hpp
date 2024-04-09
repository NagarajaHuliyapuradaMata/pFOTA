

#if !defined(__FBL_APFB_H__)
#define __FBL_APFB_H__

#define FLASH_BLOCK_ENTRIES              kNrOfFlashBlock

#define kMioDeviceFlash                  0u
#define FBL_DISABLE_FUNC_VERIFYSYNC
#define FBL_DISABLE_MULTIPLE_MEM_DEVICES

typedef struct tFlashBlockTag {
  tFblAddress begin;
  tFblAddress end;
}tFlashBlock;

V_MEMROM0 extern  V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfFlashBlock;
V_MEMROM0 extern  V_MEMROM1_FAR tFlashBlock V_MEMROM2_FAR FlashBlock[];

#endif

