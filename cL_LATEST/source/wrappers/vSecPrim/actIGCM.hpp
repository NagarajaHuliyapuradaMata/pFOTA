

#ifndef ACTIGCM_H
#define ACTIGCM_H

#include "actITypes.hpp"
#include "actIAES.hpp"
#include "actIGHash.hpp"

#define STATE_AAD                                                    0u
#define STATE_CIPHERTEXT                                             1u

#define MODE_ENC                                                     0u
#define MODE_DEC                                                     1u

#define AAD_HI                                                       0
#define AAD_LO                                                       1
#define Data_HI                                                      2
#define Data_LO                                                      3

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

VSECPRIM_FUNC(actRETURNCODE) actGCMInit (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key
   ,  actLengthType key_len
   ,  VSECPRIM_P2CONST_PARA(actU8) IV
   ,  actLengthType IV_len
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actGCMTransform (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) input
   ,  const actLengthType in_len
   ,  VSECPRIM_P2VAR_PARA(actU8) output
   ,  VSECPRIM_P2VAR_PARA(actLengthType) bytes_out
   ,  const uint8 encORdec
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actGCMEncryptUpdate (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) X
   ,  const actLengthType X_len
   ,  VSECPRIM_P2VAR_PARA(actU8) output
   ,  VSECPRIM_P2VAR_PARA(actLengthType) bytes_out
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actGCMDecryptUpdate (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) X
   ,  const actLengthType X_len
   ,  VSECPRIM_P2VAR_PARA(actU8) output
   ,  VSECPRIM_P2VAR_PARA(actLengthType) bytes_out
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actGCMTriggerState (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actGMACFinalize (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) tag
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actGCMEncryptFinalize (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) output
   ,  VSECPRIM_P2VAR_PARA(actLengthType) bytes_out
   ,  VSECPRIM_P2VAR_PARA(actU8) tag
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actGCMDecryptFinalize (
   VSECPRIM_P2VAR_PARA(actGCMSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU8) output
   ,  VSECPRIM_P2VAR_PARA(actLengthType) bytes_out
   ,  VSECPRIM_P2VAR_PARA(actU8) tag
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#ifdef __cplusplus
}
#endif

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif
