

#ifndef ACTTDES_H
#define ACTTDES_H

#include "actDES.hpp"
#include "actITypes.hpp"
#include "actConfig.hpp"

typedef struct{
   actDESSTRUCT k1;
   actDESSTRUCT k2;
   actDESSTRUCT k3;
   VSECPRIM_P2CONST_PARA(actU8) k1_ptr;
   VSECPRIM_P2CONST_PARA(actU8) k2_ptr;
   VSECPRIM_P2CONST_PARA(actU8) k3_ptr;
   actU8 mode;
   actU8 prev_block[actDES_BLOCK_SIZE];
   actLengthType buffer_used;
   actU8 buffer[actDES_BLOCK_SIZE];
}actTDESSTRUCT;

typedef VSECPRIM_P2FUNC(VSECPRIM_NONE, void, actTDESTransformFctType)(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer
   ,  actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actTDESInit(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len
   ,  actU8 crypt_mode, VSECPRIM_P2CONST_PARA(actU8) iv
   ,  actU8 block_mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actTDESKeySetup(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len
   ,  actU8 crypt_mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actTDESInitEncrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actU8  key_len
   ,  VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actTDESEncrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length
   ,  VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length
   ,  boolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actTDESInitDecrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len
   ,  VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actTDESDecrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length
   ,  VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length
   ,  boolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actTDESInitEncryptBlock(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actTDESInitDecryptBlock(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key, actU8  key_len
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actTDESCryptBlock (
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actTDESEncryptMultipleBlocks(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer
   ,  actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actTDESDecryptMultipleBlocks(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer
   ,  actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actTDESTransform(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length
   ,  VSECPRIM_P2VAR_PARA(actU8) out_buffer, actTDESTransformFctType transform
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

