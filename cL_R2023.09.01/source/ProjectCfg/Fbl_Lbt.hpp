

#if !defined(__FBL_LBT_H__)
#define __FBL_LBT_H__

#include "Platform_Types.hpp"

#define FBL_LBT_DISABLE_REPROGRAMMABLE_LBT
#define FBL_LBT_ENABLE_MANDATORY_TYPE
#define FBL_LBT_ENABLE_BM_HEADER_ADDRESS
#define FBL_LBT_ENABLE_MAX_PROG_ATTEMPTS
#define FBL_LBT_ENABLE_VERIFY_INPUT
#define FBL_LBT_ENABLE_VERIFY_PROCESSED
#define FBL_LBT_ENABLE_VERIFY_PIPELINED
#define FBL_LBT_ENABLE_VERIFY_OUTPUT
#define FBL_LBT_RAJAAPPL_BLOCK_NUMBER    0u
#define FBL_LBT_BLOCK_COUNT                1u
#define kNrOfValidationBytes               1u
#define FBL_LBT_MAGIC_FLAG                 0xA407191EuL

#define IsLogicalBlockTableValid()        (FblLogicalBlockTable.magicFlag == FBL_LBT_MAGIC_FLAG)

#define FBL_MTAB_RAJAAPPL_BLOCK_NUMBER FBL_LBT_RAJAAPPL_BLOCK_NUMBER
#define FBL_MTAB_NO_OF_BLOCKS            FBL_LBT_BLOCK_COUNT
#define FBL_MTAB_MAGIC_FLAG              FBL_LBT_MAGIC_FLAG

typedef vuint8 tFblLbtBlockNr;
typedef boolean tFblLbtMandatoryType;
typedef vuint16 tFblLbtMaxProgAttempts;
typedef vuint32 tFblLbtMagicFlag;
typedef vuint8 tFblLbtAssignFlags;
typedef vuint8 tFblLbtBlockCount;

typedef struct tBlockDescriptorTag {
  tFblLbtBlockNr blockNr;
  tFblLbtMandatoryType mandatoryType;
  tFblAddress blockStartAddress;
  tFblLength blockLength;
  tFblAddress bmHeaderAddress;
  tFblLbtMaxProgAttempts maxProgAttempts;
  tExportFct verifyInput;
  tExportFct verifyProcessed;
  tExportFct verifyPipelined;
  tExportFct verifyOutput;
}tBlockDescriptor;

typedef struct tLogicalBlockTableTag {
  tFblLbtMagicFlag magicFlag;
  tFblLbtAssignFlags assignFlags[kNrOfValidationBytes];
  tFblLbtBlockCount noOfBlocks;
  tBlockDescriptor logicalBlock[FBL_LBT_BLOCK_COUNT];
}tLogicalBlockTable;

V_MEMROM0 extern V_MEMROM1 tLogicalBlockTable V_MEMROM2 FblLogicalBlockTable;

#endif
