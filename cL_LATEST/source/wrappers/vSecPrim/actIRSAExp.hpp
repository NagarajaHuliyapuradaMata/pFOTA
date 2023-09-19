

#ifndef ACTIRSAEXP_H
#define ACTIRSAEXP_H

#include "actITypes.hpp"

#define actRSA_PRIVATE_KEY_OPERATION                                 (0u)
#define actRSA_PRIVATE_KEY_OPERATION_CRT                             (1u)
#define actRSA_PUBLIC_KEY_OPERATION                                  (2u)

#ifdef __cplusplus
extern "C" {
#endif

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

extern VSECPRIM_FUNC(actRETURNCODE) actRSAInitExponentiation(
  VSECPRIM_P2CONST_PARA(actU8) modulus
   ,  actLengthType modulus_len
   ,  VSECPRIM_P2CONST_PARA(actU8) exponent
   ,  actLengthType exponent_len
   ,  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wksp
   ,  actU16 key_flag
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actRETURNCODE) actRSAExponentiation(
  VSECPRIM_P2CONST_PARA(actU8) cipher
   ,  actLengthType cipher_len
   ,  VSECPRIM_P2VAR_PARA(actU8) message
   ,  VSECPRIM_P2VAR_PARA(actLengthType) message_len
   ,  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wksp
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
}
#endif

#endif

