

#ifndef ACTHASHMACWRAPPERS_INT_H
# define ACTHASHMACWRAPPERS_INT_H

# include "CfgSwcServiceSecPrim.hpp"
# include "actPlatformTypes.hpp"
# include "actITypes.hpp"

# include "actIHashMAC.hpp"
# include "actIHashMACSHA256.hpp"

# ifndef VSECPRIM_WRAPPER_HMAC_SHA1

#  define actHashMACInitWrapper                                       actHashMACInitNoneWrapper
#  define actHashMACUpdateWrapper                                     actHashMACUpdateNoneWrapper
#  define actHashMACFinalizeWrapper                                   actHashMACFinalizeNoneWrapper
# endif

# ifndef VSECPRIM_WRAPPER_HMAC_SHA256

#  define actHashMACSHA256InitWrapper                                 actHashMACInitNoneWrapper
#  define actHashMACSHA256UpdateWrapper                               actHashMACUpdateNoneWrapper
#  define actHashMACSHA256FinalizeWrapper                             actHashMACFinalizeNoneWrapper
# endif

typedef P2FUNC(actRETURNCODE, VSECPRIM_CODE, actHashMACType_Init)(VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

typedef P2FUNC(actRETURNCODE, VSECPRIM_CODE, actHashMACType_Update)(VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

typedef P2FUNC(actRETURNCODE, VSECPRIM_CODE, actHashMACType_Finalize)(VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACInitNoneWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACUpdateNoneWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACFinalizeNoneWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef VSECPRIM_WRAPPER_HMAC_SHA1

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACInitWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACUpdateWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACFinalizeWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# endif

# ifdef VSECPRIM_WRAPPER_HMAC_SHA256

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256InitWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256UpdateWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256FinalizeWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, actHashMACType_Init) actHashMACInitTable[2] = {
  actHashMACInitWrapper, actHashMACSHA256InitWrapper
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actHashMACType_Update) actHashMACUpdateTable[2] = {
  actHashMACUpdateWrapper, actHashMACSHA256UpdateWrapper
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actHashMACType_Finalize) actHashMACFinalizeTable[2] = {
  actHashMACFinalizeWrapper, actHashMACSHA256FinalizeWrapper
};

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACInitNoneWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_DUMMY_STATEMENT(info);
  VSECPRIM_DUMMY_STATEMENT(key);
  VSECPRIM_DUMMY_STATEMENT(key_length);
  VSECPRIM_DUMMY_STATEMENT(watchdog);
  return actEXCEPTION_UNKNOWN;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACUpdateNoneWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_DUMMY_STATEMENT(info);
  VSECPRIM_DUMMY_STATEMENT(dataIN);
  VSECPRIM_DUMMY_STATEMENT(length);
  VSECPRIM_DUMMY_STATEMENT(watchdog);
  return actEXCEPTION_UNKNOWN;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACFinalizeNoneWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_DUMMY_STATEMENT(info);
  VSECPRIM_DUMMY_STATEMENT(hash);
  VSECPRIM_DUMMY_STATEMENT(watchdog);
  return actEXCEPTION_UNKNOWN;
}

# ifdef VSECPRIM_WRAPPER_HMAC_SHA1

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACInitWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actHashMACInit(&(info->hmac_sha1), key, key_length, watchdog);
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACUpdateWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actHashMACUpdate(&(info->hmac_sha1), dataIN, length, watchdog);
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACFinalizeWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actHashMACFinalize(&(info->hmac_sha1), hash, watchdog);
}

# endif

# ifdef VSECPRIM_WRAPPER_HMAC_SHA256

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256InitWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actHashMACSHA256Init(&(info->hmac_sha256), key, key_length, watchdog);
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256UpdateWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actHashMACSHA256Update(&(info->hmac_sha256), dataIN, length, watchdog);
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256FinalizeWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actHashMACSHA256Finalize(&(info->hmac_sha256), hash, watchdog);
}

# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

