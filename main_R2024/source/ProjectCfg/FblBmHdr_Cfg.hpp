

#if !defined (FBLBMHDR_CFG_H)
# define FBLBMHDR_CFG_H

# include "Std_Types.hpp"
# include "fbl_def.hpp"

# define FBLBMHDR_CFG_MAJOR_VERSION 1u

# define FBLBMHDR_CFG_MINOR_VERSION 2u

# define FBLBMHDR_MAGIC_FLAG 0xB14E9B4AuL

# define FBLBMHDR_NUM_OF_VERIFICATION_ENTRIES 1uL

# define FBLBMHDR_NUM_OF_TARGETS 3uL

# define FBLBMHDR_ENTRY_ADDRESS_INVALID 0xFFFFFFFFuL

# ifndef FBLBMHDR_USE_DUMMY_STATEMENT
#  define FBLBMHDR_USE_DUMMY_STATEMENT STD_ON
# endif
# ifndef FBLBMHDR_DUMMY_STATEMENT
#  define FBLBMHDR_DUMMY_STATEMENT(v) (v)=(v)
# endif
# ifndef FBLBMHDR_DUMMY_STATEMENT_CONST
#  define FBLBMHDR_DUMMY_STATEMENT_CONST(v) (void)(v)
# endif
# ifndef FBLBMHDR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#  define FBLBMHDR_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF
# endif
# ifndef FBLBMHDR_ATOMIC_VARIABLE_ACCESS
#  define FBLBMHDR_ATOMIC_VARIABLE_ACCESS 32u
# endif
# ifndef FBLBMHDR_PROCESSOR_RH850_1013
#  define FBLBMHDR_PROCESSOR_RH850_1013
# endif
# ifndef FBLBMHDR_COMP_GREENHILLS
#  define FBLBMHDR_COMP_GREENHILLS
# endif
# ifndef FBLBMHDR_GEN_GENERATOR_MSR
#  define FBLBMHDR_GEN_GENERATOR_MSR
# endif
# ifndef FBLBMHDR_CPUTYPE_BITORDER_LSB2MSB
#  define FBLBMHDR_CPUTYPE_BITORDER_LSB2MSB
# endif
# ifndef FBLBMHDR_CONFIGURATION_VARIANT_PRECOMPILE
#  define FBLBMHDR_CONFIGURATION_VARIANT_PRECOMPILE 1
# endif
# ifndef FBLBMHDR_CONFIGURATION_VARIANT_LINKTIME
#  define FBLBMHDR_CONFIGURATION_VARIANT_LINKTIME 2
# endif
# ifndef FBLBMHDR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#  define FBLBMHDR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
# endif
# ifndef FBLBMHDR_CONFIGURATION_VARIANT
#  define FBLBMHDR_CONFIGURATION_VARIANT FBLBMHDR_CONFIGURATION_VARIANT_PRECOMPILE
# endif
# ifndef FBLBMHDR_POSTBUILD_VARIANT_SUPPORT
#  define FBLBMHDR_POSTBUILD_VARIANT_SUPPORT STD_OFF
# endif

# define FblBmHdr_GetFblSbMacId(targetId)        FblBmHdrTargets[targetId]

typedef enum{
  FBLBMHDR_TARGET_FBL = 0,
  FBLBMHDR_TARGET_FBLUPDATER = 1,
  FBLBMHDR_TARGET_APPL = 2
}tFblBmHdrTargetHandle;

typedef struct{
   vuint32 address;
   vuint32 length;
}tFblBmHdrVerificationList;

typedef struct{
   vuint32                    bmMagicFlag;
   tFblAddress                bmEntryAddress;
   tFblBmHdrTargetHandle      bmTargetHandle;
   tFblAddress                bmBlockStartAddress;
   tFblLength                 bmBlockLength;
   vuint8                     bmVerificationListEntries;
   tFblBmHdrVerificationList  bmVerificationList[FBLBMHDR_NUM_OF_VERIFICATION_ENTRIES];
}tFblBmHdrHeader;

#define FBLBMHDR_BMHEADER_START_SEC_CONST
#include "MemMap.hpp"

extern CONST(tFblBmHdrHeader, FBLBMHDR_CONST) FblBmHdrHeader;

#define FBLBMHDR_BMHEADER_STOP_SEC_CONST
#include "MemMap.hpp"

# define FBLBMHDR_START_SEC_CONST
# include "MemMap.hpp"

extern CONST(uint32, FBLBMHDR_CONST) FblBmHdrTargets[FBLBMHDR_NUM_OF_TARGETS];

# define FBLBMHDR_STOP_SEC_CONST
# include "MemMap.hpp"

# define FBLBMHDR_START_SEC_CODE
# include "MemMap.hpp"

# define FBLBMHDR_STOP_SEC_CODE
# include "MemMap.hpp"

#endif

