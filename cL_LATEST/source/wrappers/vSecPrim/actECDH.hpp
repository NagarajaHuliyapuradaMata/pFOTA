

#ifndef ACTECDH_H
#define ACTECDH_H

#include "actIECDH.hpp"
#include "actECPoint.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C" {
#endif

VSECPRIM_FUNC(actRETURNCODE) actECDHp(VSECPRIM_P2CONST_PARA(actBNDIGIT) d, VSECPRIM_P2CONST_PARA(actECPOINT) Q
   ,  VSECPRIM_P2VAR_PARA(actECPOINT) point, VSECPRIM_P2VAR_PARA(actECCURVE) Curve
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

