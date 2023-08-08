

#define VSECPRIM_SOURCE
#include "vSecPrim.hpp"
#include "CfgSwcServiceSecPrim.hpp"
#include "actConfig.hpp"
#include "actPlatformTypes.hpp"

#if((VSECPRIM_SW_MAJOR_VERSION != (6u)) \
    || (VSECPRIM_SW_MINOR_VERSION != (1u)) \
    || (VSECPRIM_SW_PATCH_VERSION != (0u)))
# error "Vendor specific version numbers of vSecPrim.c and vSecPrim.h are inconsistent"
#endif

