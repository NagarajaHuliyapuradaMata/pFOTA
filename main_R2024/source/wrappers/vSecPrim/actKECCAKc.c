

#define ACTKECCAKC_SOURCE

#include "actKECCAKc.hpp"
#include "actITypes.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTKECCAK_ENABLED == STD_ON)

# ifdef ACT_PLATFORM_UINT64_AVAILABLE
#  include "actKECCAKf-64.hpp"
# else
#  include "actKECCAKf-32.hpp"
# endif

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actKECCAKcInit(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  const actU32 strength,
  const actU8  pad1){
  actRETURNCODE retVal;

  if(((2u * strength) % actHASH_SHA3_LANE) == 0u){
    info->strength = strength;
    info->rate     = (actHASH_SHA3_WIDTH - (2u * strength)) /actHASH_SHA3_LANE;
    info->pad1     = pad1;

    info->phase   &= ~KECCAKc_PHASE;

    info->phase   |=  KECCAKc_PHASE_INITIAL;
    info->rUsed    = 0u;
    info->dUsed    = 0u;
    actMemClear(info->state, actBitsToBytes(actHASH_SHA3_WIDTH));
    actMemClear(info->data, actBitsToBytes(actHASH_SHA3_LANE));

    retVal = actOK;
  }
  else{
    retVal = actEXCEPTION_LENGTH;
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actKECCAKcAbsorb(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) data,
  const actLengthType dataLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;
  actLengthType len;
  actLengthType n;

  if((info->phase & KECCAKc_PHASE) != KECCAKc_PHASE_SQUEEZE){
    len = dataLength;
    while (len > 0u){
      if(info->dUsed != 0u)
      {
        n = actMin ((actHASH_SHA3_LANE /8u) - info->dUsed, len);
        actMemCpyByteArray (&(info->data [info->dUsed]), &data[dataLength - len], n);
        info->dUsed += n;
        len         -= n;

        if(info->dUsed >= (actHASH_SHA3_LANE /8u))
        {
          actKECCAKcAbsorbData(info, info->data);
          info->rUsed++;
          info->dUsed = 0u;
        }
      }
      else if(len >= (actHASH_SHA3_LANE /8u))
      {
        actKECCAKcAbsorbData(info, &data[dataLength - len]);
        info->rUsed++;
        len  -= (actHASH_SHA3_LANE /8u);
      }
      else
      {
        actMemCpyByteArray (info->data, &data[dataLength - len], len);
        info->dUsed = len;
        len        -= len;
      }

      if(info->rUsed >= info->rate)
      {
        KECCAKf (info, watchdog);
        info->rUsed = 0u;
      }
    }

    info->phase &= ~KECCAKc_PHASE;
    info->phase |=  KECCAKc_PHASE_ABSORB;

    retVal = actOK;
  }
  else{
    retVal = actEXCEPTION_MODE;
  }

  actL1trigger (watchdog);
  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actKECCAKcSqueeze(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) digest,
  const actLengthType digestSize,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;
  actLengthType size, n;

  if((digestSize % 8u) == 0u){
    if((info->phase & KECCAKc_PHASE) == KECCAKc_PHASE_ABSORB){
      actMemClear(&(info->data[info->dUsed]), ((actHASH_SHA3_LANE / 8u) - info->dUsed));
      info->data[info->dUsed] ^= info->pad1;
      actKECCAKcAbsorbData(info, info->data);

      actMemClear(info->data, actBitsToBytes(actHASH_SHA3_LANE));

      info->data[actBitsToBytes(actHASH_SHA3_LANE) - 1u] = actHASH_SHA3_PAD_2;
      info->rUsed = info->rate - 1u;
      actKECCAKcAbsorbData(info, info->data);

      KECCAKf (info, watchdog);

      info->phase &= ~KECCAKc_PHASE;

      info->phase |=  KECCAKc_PHASE_SQUEEZE;
      info->rUsed = 0u;
      info->dUsed = 0u;
    }

    size = (digestSize / 8u);
    while (size > 0u){
      if(info->rUsed >= info->rate)
      {
        KECCAKf (info, watchdog);
        info->rUsed = 0u;
      }

      if(info->dUsed != 0u)
      {
        n = actMin ((actHASH_SHA3_LANE /8u) - info->dUsed, size);
        actMemCpyByteArray (&digest[(digestSize/8u) - size], &(info->data [info->dUsed]), n);
        info->dUsed += n;
        info->dUsed %= 8u;
        size        -= n;
      }
      else if(size >= (actHASH_SHA3_LANE /8u))
      {
        actKECCAKcSqueezeData(info, &digest[(digestSize / 8u) - size]);
        info->rUsed++;
        size   -= (actHASH_SHA3_LANE/8u);
      }
      else
      {
        actKECCAKcSqueezeData(info, info->data);
        info->rUsed++;

        actMemCpyByteArray  (&digest[(digestSize / 8u) - size], info->data, size);
        info->dUsed = size;
        size       -= size;
      }
    }

    retVal = actOK;
  }
  else{
    retVal = actEXCEPTION_LENGTH;
  }

  actL1trigger (watchdog);
  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actKECCAKcZEROPadToRate(
  VSECPRIM_P2VAR_PARA(actKECCAKcSTRUCT) info,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
    if(info->dUsed != 0u){
      actMemClear(&(info->data[info->dUsed]), ((actHASH_SHA3_LANE / 8u) - info->dUsed));
      actKECCAKcAbsorbData(info, info->data);

      info->rUsed++;
    }

    if(info->rUsed != 0u){
      KECCAKf (info, watchdog);
      info->rUsed = 0;
      info->dUsed = 0;
    }

    actL1trigger (watchdog);
    return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

