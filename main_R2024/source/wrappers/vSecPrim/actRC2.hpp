

#ifndef ACTRC2_H
# define ACTRC2_H

# include "actITypes.hpp"

# define RC2_MAX_KEY_LENGTH                                           128u
# define actRC2_MIN_KEY_SIZE                                          5u
# define RC2_MASK                                                     0xffu
# define MAX_ROUNDS                                                   16u
# define actRC2_BLOCK_SIZE                                            8u

typedef struct{
   actU16 e_key[RC2_MAX_KEY_LENGTH/2u];
   actLengthType key_word_len;
   actLengthType eff_key_word_len;
   actLengthType max_key_len;
   actU8 mode;
   actU8 prev_block[actRC2_BLOCK_SIZE];
   actLengthType buffer_used;
   actU8 buffer[actRC2_BLOCK_SIZE];
   actU8 copyInputData[actRC2_BLOCK_SIZE];
}actRC2STRUCT;

typedef VSECPRIM_P2FUNC(VSECPRIM_NONE, void, actRC2TransformFctType)(
   VSECPRIM_P2VAR_PARA(actRC2STRUCT) info, VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
   actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define actRC2_ECB                                                   (0x20u)

# define actRC2_CBC                                                   (0x21u)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actRC2KeySetup(
  VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actRC2Init(
  VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len, actLengthType eff_key_len,
  VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actRC2Encrypt(
  VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length,
  VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length,
  boolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actRC2Decrypt(
  VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length,
  VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length,
  boolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actRC2InitCryptBlock(
  VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len, actLengthType eff_key_len,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void)  actRC2EncryptBlock(
   VSECPRIM_P2CONST_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actRC2DecryptBlock(
   VSECPRIM_P2CONST_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actRC2EncryptMultipleBlocks(
  VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
  actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actRC2DecryptMultipleBlocks(
  VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
  actLengthType blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actRC2Transform(
   VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, actRC2TransformFctType transform,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif
