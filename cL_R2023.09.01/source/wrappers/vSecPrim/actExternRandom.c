

#define ACTEXTERNRANDOM_SOURCE

#include "actConfig.hpp"
#include "actExternRandom.hpp"
#include "ESLib_ERC.hpp"
#include "ESLib_RNG.hpp"

#if(VSECPRIM_ACTEXTERNRANDOM_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actGetExternRandom(VSECPRIM_P2VAR_PARA(actU8) output, actLengthType length){
  actU8 retVal = actEXCEPTION_UNKNOWN;

  if(esl_getBytesRNG(((actU16)length), output) == ESL_ERC_NO_ERROR){
    retVal = actOK;
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

