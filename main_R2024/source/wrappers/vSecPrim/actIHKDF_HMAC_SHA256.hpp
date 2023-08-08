

#ifndef ACTIHKDFHMACSHA256_H
# define ACTIHKDFHMACSHA256_H

# include "actITypes.hpp"
# include "actIHashMACSHA256.hpp"

# ifdef __cplusplus
extern "C" {
# endif

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actHKDF_HMAC_SHA256_Extract(
  VSECPRIM_P2VAR_PARA(actHKDFSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) secret,
  actLengthType secretLength,
  VSECPRIM_P2CONST_PARA(actU8) salt,
  actLengthType saltLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actHKDF_HMAC_SHA256_Expand(
  VSECPRIM_P2VAR_PARA(actHKDFSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) addInput,
  actLengthType addInputLength,
  VSECPRIM_P2VAR_PARA(actU8) derivedKey,
  const actLengthType derivedKeyLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actHKDF_HMAC_SHA256_OneStepDerive(
  VSECPRIM_P2VAR_PARA(actHKDFSTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) secret,
  actLengthType secretLength,
  VSECPRIM_P2CONST_PARA(actU8) salt,
  actLengthType saltLength,
  VSECPRIM_P2CONST_PARA(actU8) addInput,
  actLengthType addInputLength,
  VSECPRIM_P2VAR_PARA(actU8) derivedKey,
  const actLengthType derivedKeyLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
}
# endif

#endif

