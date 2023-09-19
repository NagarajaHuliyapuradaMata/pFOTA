

#ifndef ACTECTOOLS_H
#define ACTECTOOLS_H

#include "actITypes.hpp"

#define actEC_ALGO_FLAG_KG                                           (1u)
#define actEC_ALGO_FLAG_SP                                           (2u)
#define actEC_ALGO_FLAG_VP                                           (3u)
#define actEC_ALGO_FLAG_DH_PRIM                                      (4u)
#define actEC_ALGO_FLAG_DH                                           (5u)
#define actEC_ALGO_FLAG_BDKA                                         (6u)
#define actEC_ALGO_FLAG_SPAKE2P                                      (7u)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C" {
#endif

VSECPRIM_FUNC( actRETURNCODE ) actECParseDomain(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain
   ,  VSECPRIM_P2VAR_PARA( actLengthType ) p_bytes
   ,  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) p_addr
   ,  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) a_addr
   ,  VSECPRIM_P2VAR_PARA( actLengthType ) n_bytes
   ,  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) n_addr
);

VSECPRIM_FUNC(actRETURNCODE) actECInit(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) speedup_ext
   ,  actU16 algo_flag
   ,  VSECPRIM_P2VAR_PARA(actECPBasicStruct) wksp
   ,  actLengthType wksp_len);

#ifdef __cplusplus
}
#endif
#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

