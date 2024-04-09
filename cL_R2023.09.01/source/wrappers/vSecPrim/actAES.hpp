

#ifndef ACTAES_H
#define ACTAES_H

#include "actIAES.hpp"

typedef VSECPRIM_P2FUNC(VSECPRIM_NONE, void, actAESTransformFctType) (
  VSECPRIM_P2VAR_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in
   ,  VSECPRIM_P2VAR_PARA(actU8) out_buffer
   ,  actLengthType blocks
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

extern VSECPRIM_FUNC(void) actAESEncryptionRound(
  VSECPRIM_P2VAR_PARA(actU32) bo, VSECPRIM_P2CONST_PARA(actU32) bi, VSECPRIM_P2CONST_PARA(actU32) k);

extern VSECPRIM_FUNC(void) actAESDecryptionRound(
  VSECPRIM_P2VAR_PARA(actU32) bo, VSECPRIM_P2CONST_PARA(actU32) bi, VSECPRIM_P2CONST_PARA(actU32) k);

extern VSECPRIM_FUNC(void) actAESEncryptionFinalRound(
  VSECPRIM_P2VAR_PARA(actU32) bo, VSECPRIM_P2CONST_PARA(actU32) bi, VSECPRIM_P2CONST_PARA(actU32) k);

extern VSECPRIM_FUNC(void) actAESDecryptionFinalRound(
  VSECPRIM_P2VAR_PARA(actU32) bo, VSECPRIM_P2CONST_PARA(actU32) bi, VSECPRIM_P2CONST_PARA(actU32) k);

extern VSECPRIM_FUNC(actRETURNCODE) actAESKeySetup(
  VSECPRIM_P2VAR_PARA(actAESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) actAESMakeDecryptionKey(VSECPRIM_P2VAR_PARA(actAESSTRUCT) info);

extern VSECPRIM_FUNC(actRETURNCODE) actAESInit(
  VSECPRIM_P2VAR_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len, VSECPRIM_P2CONST_PARA(actU8) iv
   ,  actU8 mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) actAESEncryptMultipleBlocks(
  VSECPRIM_P2VAR_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer
   ,  actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) actAESDecryptMultipleBlocks(
  VSECPRIM_P2VAR_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer
   ,  actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) actAESTransform(
  VSECPRIM_P2VAR_PARA(actAESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length
   ,  VSECPRIM_P2VAR_PARA(actU8) out_buffer, actAESTransformFctType transform
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

