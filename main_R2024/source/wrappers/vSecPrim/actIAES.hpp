

#ifndef ACTIAES_H
# define ACTIAES_H

# include "actITypes.hpp"
# include "actPadding.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
extern "C"
{
# endif

VSECPRIM_FUNC(actRETURNCODE) actAESInitEncrypt(
  VSECPRIM_P2VAR_PARA(actAESSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len, VSECPRIM_P2CONST_PARA(actU8) iv,
  actU8 mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actAESEncrypt(
   VSECPRIM_P2VAR_PARA(actAESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length,
   actBoolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actAESInitDecrypt(
   VSECPRIM_P2VAR_PARA(actAESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len, VSECPRIM_P2CONST_PARA(actU8) iv,
   actU8 mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actAESDecrypt(
   VSECPRIM_P2VAR_PARA(actAESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, actLengthType in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(actLengthType) out_length,
   actBoolean final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actAESInitEncryptBlock(
   VSECPRIM_P2VAR_PARA(actAESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actAESEncryptBlock(
   VSECPRIM_P2CONST_PARA(actAESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actAESInitDecryptBlock(
   VSECPRIM_P2VAR_PARA(actAESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actAESDecryptBlock(
   VSECPRIM_P2CONST_PARA(actAESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus
}
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

