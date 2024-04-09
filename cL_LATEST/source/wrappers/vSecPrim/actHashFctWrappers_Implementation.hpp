

#ifndef ACTHASHFCTWRAPPERS_INT_H
#define ACTHASHFCTWRAPPERS_INT_H

#ifdef VSECPRIM_WRAPPER_SHA1
#include "actISHA.hpp"
#endif
#if(defined(VSECPRIM_WRAPPER_SHA256) || defined(VSECPRIM_WRAPPER_SHA224))
#include "actISHA2_32.hpp"
#endif
#if(defined(VSECPRIM_WRAPPER_SHA384) || defined(VSECPRIM_WRAPPER_SHA512) || defined(VSECPRIM_WRAPPER_SHA512_224) || defined(VSECPRIM_WRAPPER_SHA512_256))
#include "actISHA2_64.hpp"
#endif
#ifdef VSECPRIM_WRAPPER_RIPEMD160
#include "actIRMD160.hpp"
#endif

#define ACT_GET_SHA1STRUCT(hashWSU)                                  (&(hashWSU->SHA1ws.wsSHA1))
#define ACT_GET_SHA224STRUCT(hashWSU)                                (&(hashWSU->SHA224ws.wsSHA224))
#define ACT_GET_SHA256STRUCT(hashWSU)                                (&(hashWSU->SHA256ws.wsSHA256))
#define ACT_GET_SHA384STRUCT(hashWSU)                                (&(hashWSU->SHA384ws.wsSHA384))
#define ACT_GET_SHA512STRUCT(hashWSU)                                (&(hashWSU->SHA512ws.wsSHA512))
#define ACT_GET_SHA512_224STRUCT(hashWSU)                            (&(hashWSU->SHA512_224ws.wsSHA512_224))
#define ACT_GET_SHA512_256STRUCT(hashWSU)                            (&(hashWSU->SHA512_256ws.wsSHA512_256))
#define ACT_GET_RMD160STRUCT(hashWSU)                                (&(hashWSU->RIPEMD160ws.wsRIPEMD160))

#define ACT_GET_WATCHDOG(hashWSU, hashWorkSpace)                     (hashWSU->hashWorkSpace.header.watchdog)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

static VSECPRIM_FUNC(actRETURNCODE) actHashInit(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceUnionHashFunctions) hashWSU
   ,  eslt_HashAlgorithm hashID);

static VSECPRIM_FUNC(actRETURNCODE) actHashUpdate(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceUnionHashFunctions) hashWSU,
VSECPRIM_P2CONST_PARA(actU8) dataIN,
actLengthType length,
eslt_HashAlgorithm hashID);

static VSECPRIM_FUNC(actRETURNCODE) actHashFinalize(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceUnionHashFunctions) hashWSU,
VSECPRIM_P2VAR_PARA(actU8) hash,
eslt_HashAlgorithm hashID);

static VSECPRIM_FUNC(actRETURNCODE) actHashInit(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceUnionHashFunctions) hashWSU,
eslt_HashAlgorithm hashID){
  actRETURNCODE returnValue;
  switch(hashID){
#ifdef VSECPRIM_WRAPPER_SHA1
    case ESL_HA_SHA1:
      returnValue = actSHAInit(ACT_GET_SHA1STRUCT(hashWSU));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA224
    case ESL_HA_SHA2_224:
      returnValue = actSHA224Init(ACT_GET_SHA224STRUCT(hashWSU));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA256
    case ESL_HA_SHA2_256:
      returnValue = actSHA256Init(ACT_GET_SHA256STRUCT(hashWSU));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA384
    case ESL_HA_SHA2_384:
      returnValue = actSHA384Init(ACT_GET_SHA384STRUCT(hashWSU));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA512
    case ESL_HA_SHA2_512:
      returnValue = actSHA512Init(ACT_GET_SHA512STRUCT(hashWSU));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA512_224
    case ESL_HA_SHA2_512_224:
      returnValue = actSHA512_224Init(ACT_GET_SHA512_224STRUCT(hashWSU));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA512_256
    case ESL_HA_SHA2_512_256:
      returnValue = actSHA512_256Init(ACT_GET_SHA512_256STRUCT(hashWSU));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_RIPEMD160
    case ESL_HA_RMD160:
      returnValue = actRMD160Init(ACT_GET_RMD160STRUCT(hashWSU));
      break;
#endif
    default:
      returnValue = actEXCEPTION_ALGOID;
      break;
  }
  return returnValue;
}

static VSECPRIM_FUNC(actRETURNCODE) actHashUpdate(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceUnionHashFunctions) hashWSU,
VSECPRIM_P2CONST_PARA(actU8) dataIN,
actLengthType length,
eslt_HashAlgorithm hashID){
  actRETURNCODE returnValue;
  switch(hashID){
#ifdef VSECPRIM_WRAPPER_SHA1
    case ESL_HA_SHA1:
      returnValue = actSHAUpdate(ACT_GET_SHA1STRUCT(hashWSU), dataIN, length, ACT_GET_WATCHDOG(hashWSU, SHA1ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA224
    case ESL_HA_SHA2_224:
      returnValue = actSHA224Update(ACT_GET_SHA224STRUCT(hashWSU), dataIN, length, ACT_GET_WATCHDOG(hashWSU, SHA224ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA256
    case ESL_HA_SHA2_256:
      returnValue = actSHA256Update(ACT_GET_SHA256STRUCT(hashWSU), dataIN, length, ACT_GET_WATCHDOG(hashWSU, SHA256ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA384
    case ESL_HA_SHA2_384:
      returnValue = actSHA384Update(ACT_GET_SHA384STRUCT(hashWSU), dataIN, length, ACT_GET_WATCHDOG(hashWSU, SHA384ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA512
    case ESL_HA_SHA2_512:
      returnValue = actSHA512Update(ACT_GET_SHA512STRUCT(hashWSU), dataIN, length, ACT_GET_WATCHDOG(hashWSU, SHA512ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA512_224
    case ESL_HA_SHA2_512_224:
      returnValue = actSHA512_224Update(ACT_GET_SHA512_224STRUCT(hashWSU), dataIN, length, ACT_GET_WATCHDOG(hashWSU, SHA512_224ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA512_256
    case ESL_HA_SHA2_512_256:
      returnValue = actSHA512_256Update(ACT_GET_SHA512_256STRUCT(hashWSU), dataIN, length, ACT_GET_WATCHDOG(hashWSU, SHA512_256ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_RIPEMD160
    case ESL_HA_RMD160:
      returnValue = actRMD160Update(ACT_GET_RMD160STRUCT(hashWSU), dataIN, length, ACT_GET_WATCHDOG(hashWSU, RIPEMD160ws));
      break;
#endif
    default:
      returnValue = actEXCEPTION_ALGOID;
      break;
  }
  return returnValue;
}

static VSECPRIM_FUNC(actRETURNCODE) actHashFinalize(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceUnionHashFunctions) hashWSU,
VSECPRIM_P2VAR_PARA(actU8) hash,
eslt_HashAlgorithm hashID){
  actRETURNCODE returnValue;
  switch(hashID){
#ifdef VSECPRIM_WRAPPER_SHA1
  case ESL_HA_SHA1:
      returnValue = actSHAFinalize(ACT_GET_SHA1STRUCT(hashWSU), hash, ACT_GET_WATCHDOG(hashWSU, SHA1ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA224
    case ESL_HA_SHA2_224:
      returnValue = actSHA224Finalize(ACT_GET_SHA224STRUCT(hashWSU), hash, ACT_GET_WATCHDOG(hashWSU, SHA224ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA256
    case ESL_HA_SHA2_256:
      returnValue = actSHA256Finalize(ACT_GET_SHA256STRUCT(hashWSU), hash, ACT_GET_WATCHDOG(hashWSU, SHA256ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA384
    case ESL_HA_SHA2_384:
      returnValue = actSHA384Finalize(ACT_GET_SHA384STRUCT(hashWSU), hash, ACT_GET_WATCHDOG(hashWSU, SHA384ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA512
    case ESL_HA_SHA2_512:
      returnValue = actSHA512Finalize(ACT_GET_SHA512STRUCT(hashWSU), hash, ACT_GET_WATCHDOG(hashWSU, SHA512ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA512_224
    case ESL_HA_SHA2_512_224:
      returnValue = actSHA512_224Finalize(ACT_GET_SHA512_224STRUCT(hashWSU), hash, ACT_GET_WATCHDOG(hashWSU, SHA512_224ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_SHA512_256
    case ESL_HA_SHA2_512_256:
      returnValue = actSHA512_256Finalize(ACT_GET_SHA512_256STRUCT(hashWSU), hash, ACT_GET_WATCHDOG(hashWSU, SHA512_256ws));
      break;
#endif
#ifdef VSECPRIM_WRAPPER_RIPEMD160
    case ESL_HA_RMD160:
      returnValue = actRMD160Finalize(ACT_GET_RMD160STRUCT(hashWSU), hash, ACT_GET_WATCHDOG(hashWSU, RIPEMD160ws));
      break;
#endif
    default:
      returnValue = actEXCEPTION_ALGOID;
      break;
  }
  return returnValue;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

