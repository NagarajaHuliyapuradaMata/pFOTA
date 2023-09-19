

#ifndef ACTIECDSA_H
#define ACTIECDSA_H

#include "actITypes.hpp"

#define actSIGNATURE_INVALID                                         (0x80u)

#define actSIGNATURE_OUT_OF_RANGE                                    (0x81u)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

VSECPRIM_FUNC(actLengthType) actECDSAGetSignatureCompLength(VSECPRIM_P2ROMCONST_PARA(actU8) domain);

VSECPRIM_FUNC(actRETURNCODE) actECDSAInitVerify(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp
   ,  actLengthType wksp_len);

VSECPRIM_FUNC(actRETURNCODE) actECDSAVerify(
  VSECPRIM_P2CONST_PARA(actU8) message
   ,  actLengthType message_len
   ,  VSECPRIM_P2CONST_PARA(actU8) signature_r
   ,  actLengthType signature_r_len
   ,  VSECPRIM_P2CONST_PARA(actU8) signature_s
   ,  actLengthType signature_s_len
   ,  VSECPRIM_P2CONST_PARA(actU8) publickey_x
   ,  VSECPRIM_P2CONST_PARA(actU8) publickey_y
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actECDSAInitSign(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) speedup_ext
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp
   ,  actLengthType wksp_len);

VSECPRIM_FUNC(actRETURNCODE) actECDSASign(
  VSECPRIM_P2CONST_PARA(actU8) message
   ,  actLengthType message_len
   ,  VSECPRIM_P2CONST_PARA(actU8) privatekey
   ,  VSECPRIM_P2VAR_PARA(actU8) signature_r
   ,  VSECPRIM_P2VAR_PARA(actLengthType) signature_r_len
   ,  VSECPRIM_P2VAR_PARA(actU8) signature_s
   ,  VSECPRIM_P2VAR_PARA(actLengthType) signature_s_len
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

