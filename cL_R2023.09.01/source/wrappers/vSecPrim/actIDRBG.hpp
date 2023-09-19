

#ifndef ACTIDRBG_H
#define ACTIDRBG_H

#include "actITypes.hpp"

#define actHASHDRBG_SEEDING_PREFIX1                                  (0x00u)
#define actHASHDRBG_SEEDING_PREFIX2                                  (0x01u)
#define actHASHDRBG_GENERATE_PREFIX1                                 (0x02u)
#define actHASHDRBG_GENERATE_PREFIX2                                 (0x03u)

#define actDRBGSEED_INPUT_PARAM1                                     (0u)
#define actDRBGSEED_INPUT_PARAM2                                     (1u)
#define actDRBGSEED_INPUT_PARAM3                                     (2u)
#define actDRBGSEED_INPUT_PARAM4                                     (3u)

#define actDRBG_SIZEOF_SEEDINPUT                                     (4u)

typedef struct{
  VSECPRIM_P2CONST_PARA(actU8) dataPtr;
  actLengthType length;
}actAesCtrDrbgSeedInputElementType;

typedef struct{
  actU8 elements;
  actAesCtrDrbgSeedInputElementType input[actDRBG_SIZEOF_SEEDINPUT];
}actDrbgSeedInputType;

#if(VSECPRIM_ACTCTRDRBG_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actAesCtrDrbgInstantiation(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) dataInput
   ,  boolean reseedFlag
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actAesCtrDrbgGenerate(
  VSECPRIM_P2VAR_PARA(actCTRDRBGSTRUCT) workSpace
   ,  actLengthType requestedLength
   ,  VSECPRIM_P2VAR_PARA(actU8) outputBuffer
   ,  VSECPRIM_P2CONST_PARA(actU8) additionalInputPtr
   ,  actLengthType additionalInputLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

#if(VSECPRIM_ACTHASHDRBG_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actHashDrbgInstantiation(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace
   ,  VSECPRIM_P2CONST_PARA(actDrbgSeedInputType) seedMaterial
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actHashDrbgGenerate(
  VSECPRIM_P2VAR_PARA(actHASHDRBGSTRUCT) workSpace
   ,  actLengthType requestedLength
   ,  VSECPRIM_P2VAR_PARA(actU8) outputBuffer
   ,  VSECPRIM_P2CONST_PARA(actU8) additionalInputPtr
   ,  actLengthType additionalInputLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

#endif

