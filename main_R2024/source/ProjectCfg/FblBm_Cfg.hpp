

#if !defined (FBLBM_CFG_H)
# define FBLBM_CFG_H

# include "fbl_def.hpp"
# include "bm_hdr_types.hpp"
# include "bm_ap_cfg.hpp"

# define FBLBM_CFG_MAJOR_VERSION 1u

# define FBLBM_CFG_MINOR_VERSION 2u

# define FBLBM_DISABLE_UPDATER_FAILSAFE

# define FBLBM_DISABLE_SECBOOT_FBL_INIT_KEY

# define FBLBM_DISABLE_SECBOOT_FBL_INIT_MAC

# define FBLBM_DISABLE_SECURE_BOOT

# define FBLBM_DISABLE_STANDALONE_MODE

# define FBLBM_HEADER_ADDRESS 0x00000300uL

# define FBLBM_BOOTTARGETLIST_SIZE 2u

# ifndef FBLBM_USE_DUMMY_STATEMENT
#  define FBLBM_USE_DUMMY_STATEMENT STD_ON
# endif
# ifndef FBLBM_DUMMY_STATEMENT
#  define FBLBM_DUMMY_STATEMENT(v) (v)=(v)
# endif
# ifndef FBLBM_DUMMY_STATEMENT_CONST
#  define FBLBM_DUMMY_STATEMENT_CONST(v) (void)(v)
# endif
# ifndef FBLBM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#  define FBLBM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF
# endif
# ifndef FBLBM_ATOMIC_VARIABLE_ACCESS
#  define FBLBM_ATOMIC_VARIABLE_ACCESS 32u
# endif
# ifndef FBLBM_PROCESSOR_RH850_1013
#  define FBLBM_PROCESSOR_RH850_1013
# endif
# ifndef FBLBM_COMP_GREENHILLS
#  define FBLBM_COMP_GREENHILLS
# endif
# ifndef FBLBM_GEN_GENERATOR_MSR
#  define FBLBM_GEN_GENERATOR_MSR
# endif
# ifndef FBLBM_CPUTYPE_BITORDER_LSB2MSB
#  define FBLBM_CPUTYPE_BITORDER_LSB2MSB
# endif
# ifndef FBLBM_CONFIGURATION_VARIANT_PRECOMPILE
#  define FBLBM_CONFIGURATION_VARIANT_PRECOMPILE 1
# endif
# ifndef FBLBM_CONFIGURATION_VARIANT_LINKTIME
#  define FBLBM_CONFIGURATION_VARIANT_LINKTIME 2
# endif
# ifndef FBLBM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#  define FBLBM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
# endif
# ifndef FBLBM_CONFIGURATION_VARIANT
#  define FBLBM_CONFIGURATION_VARIANT FBLBM_CONFIGURATION_VARIANT_PRECOMPILE
# endif
# ifndef FBLBM_POSTBUILD_VARIANT_SUPPORT
#  define FBLBM_POSTBUILD_VARIANT_SUPPORT STD_OFF
# endif

typedef enum{
   FBLBM_TARGET_TYPE_MANDATORY = 0u,
   FBLBM_TARGET_TYPE_OPTIONAL
}tFblBmTargetType;

typedef struct{
   tFblBmHdrTargetHandle target;
   tFblBmTargetType      type;
}tFblBmHdrTargetDependency;

typedef struct{
   tFblBmHdrTargetHandle       target;
   V_MEMROM1 tFblBmHdrTargetDependency V_MEMROM2 V_MEMROM3 * dependencies;
   vuintx                      dependenciesSize;
}tFblBmHdrTargetListEntry;

#define FBLBM_START_SEC_CONST
#include "MemMap.hpp"

V_MEMROM0 extern V_MEMROM1 tFblBmHdrTargetListEntry V_MEMROM2 FblBm_BootTargetList[FBLBM_BOOTTARGETLIST_SIZE];

#define FBLBM_STOP_SEC_CONST
#include "MemMap.hpp"

#endif

