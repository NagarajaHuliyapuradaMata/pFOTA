

#define ACTISHA3_SOURCE

#include "actISHA3.hpp"
#include "actITypes.hpp"
#include "actKECCAKc.hpp"

#if(VSECPRIM_ACTSHA3_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actSHA3Init(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  const actU32 strength){
    return actKECCAKcInit (info, strength, actHASH_SHA3_PAD_1_SHA3);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA3Update(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) data,
  const actLengthType dataLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
    return actKECCAKcAbsorb (info, data, dataLength, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA3Finalize(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) digest,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
    return actKECCAKcSqueeze (info, digest, info->strength, watchdog);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

