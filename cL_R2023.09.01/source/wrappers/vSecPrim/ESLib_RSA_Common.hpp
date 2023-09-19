

#ifndef ESLIB_RSA_PSS_COMMON_H
#define ESLIB_RSA_PSS_COMMON_H

#include "ESLib.hpp"
#include "actUtilities.hpp"

#if((VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON))

#define VSECPRIM_START_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM_EXTERN(eslt_Byte) esl_RSAPSSEncodingMask[8];

#define VSECPRIM_STOP_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

#endif

#if((VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON))

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSaltedHashRSA_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceUnionHashFunctions_RSA) wsuHash
   ,  eslt_Length saltSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length hashDigestSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) saltedHash
   ,  eslt_HashAlgorithm hashID);

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

#if((VSECPRIM_RSA_OAEP_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_ENABLED == STD_ON))

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateMaskMGF1(
  eslt_HashAlgorithm hashAlgorithm
   ,  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceUnionHashFunctions_RSA) wsHash
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tempHash
   ,  eslt_Length hashDigestSize
   ,  eslt_Length seedLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) seed
   ,  eslt_Length maskLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) mask);

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif
#endif
