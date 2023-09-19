

#ifndef ACTIECBD_H
#define ACTIECBD_H

#include "actITypes.hpp"
#include "actECPoint.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

extern VSECPRIM_FUNC( actRETURNCODE ) actECBDinit(VSECPRIM_P2VAR_PARA( actECBDstruct ) ws
   ,                           const actLengthType  wsSize
   ,                           const actU32            nECUs
   ,                           const actU32            ecuID
   ,                           VSECPRIM_P2ROMCONST_PARA(actU8) domain
   ,                           VSECPRIM_P2ROMCONST_PARA(actU8) domainExt
   ,                           VSECPRIM_P2ROMCONST_PARA(actU8) speedupExt);

extern VSECPRIM_FUNC( actRETURNCODE ) actECBDgenKeyPair (VSECPRIM_P2VAR_PARA( actECBDstruct )ws
   ,                                       VSECPRIM_P2VAR_PARA( actU8 ) privKey
   ,                                       VSECPRIM_P2VAR_PARA( actU8 ) pubKey_x
   ,                                       VSECPRIM_P2VAR_PARA( actU8 ) pubKey_y
   ,                                       VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC( actRETURNCODE ) actECBDcalcXi (VSECPRIM_P2VAR_PARA( actECBDstruct ) ws
   ,                                   VSECPRIM_P2CONST_PARA( actU8 ) ZiLeft_x
   ,                                   VSECPRIM_P2CONST_PARA( actU8 ) ZiLeft_y
   ,                                   VSECPRIM_P2CONST_PARA( actU8 ) ZiRight_x
   ,                                   VSECPRIM_P2CONST_PARA( actU8 ) ZiRight_y
   ,                                   VSECPRIM_P2VAR_PARA( actU8 ) Xi_x
   ,                                   VSECPRIM_P2VAR_PARA( actU8 ) Xi_y
   ,                                   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC( actRETURNCODE ) actECBDinitK (VSECPRIM_P2VAR_PARA( actECBDstruct ) ws
   ,                                                   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC( actRETURNCODE ) actECBDupdateK (VSECPRIM_P2VAR_PARA( actECBDstruct ) ws
   ,                                                     const actU32          ecuID
   ,                                                     VSECPRIM_P2CONST_PARA( actU8 ) Xi_x
   ,                                                     VSECPRIM_P2CONST_PARA( actU8 ) Xi_y
   ,                                                     VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actRETURNCODE) actECBDretrieveK(VSECPRIM_P2VAR_PARA(actECBDstruct) ws
   ,  VSECPRIM_P2VAR_PARA(actU8) K_x
   ,  VSECPRIM_P2VAR_PARA(actU8) K_y
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

