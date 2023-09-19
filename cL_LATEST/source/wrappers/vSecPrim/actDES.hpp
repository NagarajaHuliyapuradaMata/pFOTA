

#ifndef ACTDES_H
#define ACTDES_H

#include "actITypes.hpp"

#define actDES_BLOCK_SIZE                                            (8u)
#define EN0                                                          (0u)
#define DE1                                                          (1u)

typedef struct{
   actU32 n_keys[32];
   actU8 mode;
   actU8 prev_block[actDES_BLOCK_SIZE];
   actLengthType buffer_used;
   actU8 buffer[actDES_BLOCK_SIZE];
}actDESSTRUCT;

typedef VSECPRIM_P2FUNC(VSECPRIM_NONE, void, actDESTransformFctType)(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) in
   ,  VSECPRIM_P2VAR_PARA(actU8) out_buffer, actLengthType blocks
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define actDES_ECB                                                   (0x20u)

#define actDES_CBC                                                   (0x21u)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actDESInit(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key
   ,  actU8 crypt_mode, VSECPRIM_P2CONST_PARA(actU8) iv, actU8 block_mode
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actDESKeySetup(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key
   ,  actU8 crypt_mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actDESInitEncrypt(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key
   ,  VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actDESEncrypt(
  VSECPRIM_P2VAR_PARA(actDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length
   ,  VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length
   ,  boolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actDESInitDecrypt(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key
   ,  VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actDESDecrypt(
  VSECPRIM_P2VAR_PARA(actDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length
   ,  VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length
   ,  boolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actDESInitEncryptBlock(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actDESInitDecryptBlock(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actDESCryptBlock(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actDESEncryptMultipleBlocks(
  VSECPRIM_P2VAR_PARA(actDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer
   ,  actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actDESDecryptMultipleBlocks(
  VSECPRIM_P2VAR_PARA(actDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer
   ,  actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actDESTransform(
  VSECPRIM_P2VAR_PARA(actDESSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length
   ,  VSECPRIM_P2VAR_PARA(actU8) out_buffer, actDESTransformFctType transform
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

