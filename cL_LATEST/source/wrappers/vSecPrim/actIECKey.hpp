

#ifndef ACTIECKEY_H
#define ACTIECKEY_H

#include "actITypes.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C" {
#endif

VSECPRIM_FUNC(actLengthType) actECGetPrivateKeyLength(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain);

VSECPRIM_FUNC(actLengthType) actECGetPublicKeyCompLength(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain);

VSECPRIM_FUNC(actRETURNCODE) actECInitGenerateKeyPair(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) speedup_ext
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp
   ,  actLengthType wksp_len);

VSECPRIM_FUNC(actRETURNCODE) actECGenerateKeyPair(
  boolean generate_privatekey
   ,  VSECPRIM_P2VAR_PARA(actU8) privatekey
   ,  VSECPRIM_P2VAR_PARA(actU8) publickey_x
   ,  VSECPRIM_P2VAR_PARA(actU8) publickey_y
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif
#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

