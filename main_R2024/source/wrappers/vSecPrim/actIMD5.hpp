

#ifndef ACTIMD5_H
# define ACTIMD5_H

# include "actITypes.hpp"

# define actHASH_SIZE_MD5                                             (16u)
# define actHASH_BLOCK_SIZE_MD5                                       (64u)

typedef struct{
   actU32 digest [4];
   actU32 count  [2];
   actLengthType buffer_used;
   actU8  buffer [actHASH_BLOCK_SIZE_MD5];
}actMD5STRUCT;

# ifdef __cplusplus
extern "C" {
# endif

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actMD5Init (VSECPRIM_P2VAR_PARA(actMD5STRUCT) info);

VSECPRIM_FUNC(actRETURNCODE) actMD5Update(
   VSECPRIM_P2VAR_PARA(actMD5STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actMD5Finalize (
   VSECPRIM_P2VAR_PARA(actMD5STRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
}
# endif

#endif

