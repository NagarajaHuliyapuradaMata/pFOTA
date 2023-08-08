

#ifndef VSECPRIM_H
# define VSECPRIM_H

# include "vSecPrim_types.hpp"
# include "ESLib.hpp"

# define VSECPRIM_SW_MAJOR_VERSION                                    (6u)
# define VSECPRIM_SW_MINOR_VERSION                                    (1u)
# define VSECPRIM_SW_PATCH_VERSION                                    (0u)

# if(VSECPRIM_HASH_ENABLED == STD_ON)

extern VSECPRIM_FUNC(eslt_ErrorCode) vSecPrim_initHash(
VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace,
vSecPrimType_HashAlgorithm hashID,
vSecPrimType_OutputBufferFlag outputLengthFlag);

extern VSECPRIM_FUNC(eslt_ErrorCode) vSecPrim_updateHash(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace,
  const eslt_Length inputLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input);

extern VSECPRIM_FUNC(eslt_ErrorCode) vSecPrim_finalizeHash(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

extern VSECPRIM_FUNC(eslt_ErrorCode) vSecPrim_digestHash(
  VSECPRIM_P2VAR_PARA(vSecPrimType_WorkSpaceHash) workSpace,
  const eslt_Length inputLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) input,
  VSECPRIM_P2VAR_PARA(eslt_Length) messageDigestLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) messageDigest);

# endif

#endif

