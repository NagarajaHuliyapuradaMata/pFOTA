

#ifndef ACTIAEADAES128CCM_H
#define ACTIAEADAES128CCM_H

#include "actITypes.hpp"
#include "actIAES.hpp"

#define actAESCCM_UPDATE_NOT_CALLED                                  (0x00u)
#define actAESCCM_UPDATE_CALLED                                      (0x01u)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

VSECPRIM_FUNC(void) actAESCCMInit(
 VSECPRIM_P2VAR_PARA(actAESCCMSTRUCT) info,
 VSECPRIM_P2CONST_PARA(actU8) key,
 const actLengthType keyLength,
 VSECPRIM_P2CONST_PARA(actU8) nonce,
 const actLengthType nonceLength,
 const actLengthType aadLength,
 const actLengthType msgLength,
 const actU8 authenticationFieldSize,
 const actU8 lengthFieldSize,
 VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actAESCCMUpdateEncrypt(
 VSECPRIM_P2VAR_PARA(actAESCCMSTRUCT) info,
 VSECPRIM_P2CONST_PARA(actU8) aad,
 const actLengthType aadLength,
 VSECPRIM_P2CONST_PARA(actU8) msg,
 const actLengthType msgLength,
 VSECPRIM_P2VAR_PARA(actU8) out,
 VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

 VSECPRIM_FUNC(actRETURNCODE) actAESCCMUpdateDecrypt(
  VSECPRIM_P2VAR_PARA(actAESCCMSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) aad
   ,  const actLengthType aadLength
   ,  VSECPRIM_P2CONST_PARA(actU8) msg
   ,  const actLengthType msgLength
   ,  VSECPRIM_P2VAR_PARA(actU8) out
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actAESCCMFinalizeEncrypt(
  VSECPRIM_P2VAR_PARA(actAESCCMSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) out
   ,  VSECPRIM_P2VAR_PARA(actU8) tag
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actAESCCMFinalizeDecrypt(
  VSECPRIM_P2VAR_PARA(actAESCCMSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) out
   ,  VSECPRIM_P2VAR_PARA(actU8) tag
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

