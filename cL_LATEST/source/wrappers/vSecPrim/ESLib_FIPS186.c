

#define ESLIB_FIPS186_SOURCE

#include "ESLib.hpp"
#include "ESLib_RNG.hpp"
#include "ESLib_Helper.hpp"

#include "actFIPS186.hpp"
#include "actISHA.hpp"

#if(VSECPRIM_FIPS186_ENABLED == STD_ON)

#define ESL_FIPS_INIT_HASH_FCT(workspace)                            actSHAInit(&((workspace)->wsFIPS186buffer.sha1))

#define ESL_FIPS_UPDATE_HASH_FCT(workspace, inputSize, input)        actSHAUpdate(&((workspace)->wsFIPS186buffer.sha1), (VSECPRIM_P2CONST_PARA(actU8))(input), (actLengthType)(inputSize), (workspace)->header.watchdog)

#define ESL_FIPS_FINALIZE_HASH_FCT(workspace, messageDigest)         actSHAFinalize(&((workspace)->wsFIPS186buffer.sha1), (VSECPRIM_P2VAR_PARA(actU8))(messageDigest), (workspace)->header.watchdog)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initFIPS186(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceFIPS186) workSpace
   ,                                             const eslt_Length entropyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) entropy, VSECPRIM_P2VAR_PARA(eslt_Byte) savedState){
  eslt_ErrorCode retVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_FIPS186)) != ESL_ERC_NO_ERROR){
  }
  else if(entropy == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if(entropyLength < ESL_SIZEOF_RNGFIPS186_STATE){
    retVal = ESL_ERC_RNG_ENTROPY_TOO_SMALL;
  }
  else{
    (void)(ESL_FIPS_INIT_HASH_FCT(workSpace));

    if(ESL_FIPS_UPDATE_HASH_FCT(workSpace, entropyLength, entropy) != actOK){
      retVal = ESL_ERC_SHA1_TOTAL_LENGTH_OVERFLOW;
    }

    if((retVal == ESL_ERC_NO_ERROR) && (savedState != NULL_PTR)){
      if(ESL_FIPS_UPDATE_HASH_FCT(workSpace, ESL_SIZEOF_RNGFIPS186_STATE, savedState) != actOK)
      {
        retVal = ESL_ERC_SHA1_TOTAL_LENGTH_OVERFLOW;
      }
    }

    if(retVal == ESL_ERC_NO_ERROR){
      eslt_Byte seed[ESL_SIZEOF_RNGFIPS186_STATE];
      actMemClear(seed, ESL_SIZEOF_RNGFIPS186_STATE);

      (void)ESL_FIPS_FINALIZE_HASH_FCT(workSpace, seed);

      actInitializeFIPS186(&workSpace->wsFIPS186buffer, seed);

      if(savedState != NULL_PTR)
      {
        actGetFIPS186(&workSpace->wsFIPS186buffer, savedState, ESL_SIZEOF_RNGFIPS186_STATE, workSpace->header.watchdog);
      }

      workSpace->wsFIPS186 = (VSECPRIM_P2VAR_PARA(eslt_Byte))&(workSpace->wsFIPS186buffer);

      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_FIPS186);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_getBytesFIPS186(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceFIPS186) workSpace, const eslt_Length targetLength, VSECPRIM_P2VAR_PARA(eslt_Byte) target){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (target == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_FIPS186, ESL_WST_ALGO_FIPS186)) != ESL_ERC_NO_ERROR){
  }
  else{
    actGetFIPS186(&workSpace->wsFIPS186buffer, target, (actLengthType)targetLength, workSpace->header.watchdog);
  }
  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_stirFIPS186(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceFIPS186) workSpace, const eslt_Length inputLength, VSECPRIM_P2VAR_PARA(eslt_Byte) input){
  eslt_ErrorCode retVal;
  if((workSpace == NULL_PTR) || (input == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_FIPS186, ESL_WST_ALGO_FIPS186)) != ESL_ERC_NO_ERROR){
  }
  else{
    eslt_Byte savedState[ESL_SIZEOF_RNGFIPS186_STATE];
    VSECPRIM_P2CONST_PARA(actU8) origState;
    actLengthType i;
    origState = (workSpace->wsFIPS186buffer.X_KEY);

    for(i = 0; i < actFIPS186_BASE_LENGTH; ++i){
      savedState[i] = origState[i];
    }
    retVal = esl_initFIPS186(workSpace, inputLength, input, savedState);
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

