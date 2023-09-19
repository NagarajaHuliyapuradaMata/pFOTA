

#ifndef ACTECDSA_H
#define ACTECDSA_H

#include "actIECDSA.hpp"
#include "actECPoint.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C" {
#endif

VSECPRIM_FUNC(actRETURNCODE) actECDSAvp(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) e
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) s
   ,  VSECPRIM_P2CONST_PARA(actECPOINT) Q
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp_ptr
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actECDSAsp(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) e
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) d
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) r
   ,  VSECPRIM_P2VAR_PARA(actBNDIGIT) s
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

