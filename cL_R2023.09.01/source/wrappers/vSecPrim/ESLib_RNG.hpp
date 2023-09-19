

#ifndef ESLIB_RNG_H
#define ESLIB_RNG_H

#include "ESLib_t.hpp"
#include "ESLib_ERC.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

#define ESL_MAXSIZEOF_WS_RNG                                         ESL_MAXSIZEOF_WS_FIPS186

  typedef struct
  {
    eslt_WorkSpaceHeader header;
    eslt_Byte wsRNG[ESL_MAXSIZEOF_WS_RNG];
  } eslt_WorkSpaceRNG;

#define ESL_SIZEOF_RNG_STATE                                         ESL_SIZEOF_RNGFIPS186_STATE

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initRNG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRNG) workSpace
   ,  const eslt_Length entropyLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) entropy
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) savedState);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_getBytesRNG(
  const eslt_Length targetLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) target);

extern VSECPRIM_FUNC(eslt_ErrorCode) esl_stirRNG(
  const eslt_Length inputLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) input);

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
}
#endif

#endif

