

#ifndef ACTED25519CORE_H
# define ACTED25519CORE_H

# include "actITypes.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
extern "C"
{
# endif

extern VSECPRIM_FUNC(void) actEd25519_initCore(VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws);

extern VSECPRIM_FUNC(void) actEd25519_sign(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws,
  VSECPRIM_P2VAR_PARA(actU8) signature,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(actRETURNCODE) actEd25519_verify(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) signature,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

extern VSECPRIM_FUNC(void) actEd25519_importKeyPair(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) secretKey,
  VSECPRIM_P2CONST_PARA(actU8) publicKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus
}
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

