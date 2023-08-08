

#ifndef ACTECLENGTHINFO_H
# define ACTECLENGTHINFO_H

# include "actITypes.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
extern "C"
{
# endif

VSECPRIM_FUNC(actLengthType ) actECBasicWksp(
  actLengthType p_length,
  actLengthType n_length);

VSECPRIM_FUNC(actLengthType ) actECKgWksp(actLengthType p_length, actLengthType n_length);

VSECPRIM_FUNC(actLengthType ) actECDHpWksp(actLengthType p_length, actLengthType n_length);

VSECPRIM_FUNC(actLengthType ) actECDHWksp(actLengthType p_length, actLengthType n_length);

VSECPRIM_FUNC(actLengthType ) actECDSASpWksp(actLengthType p_length, actLengthType n_length);

VSECPRIM_FUNC( actLengthType ) actECDSAVpWksp( actLengthType p_length, actLengthType n_length );

VSECPRIM_FUNC( actLengthType ) actECBDWksp( actLengthType p_length, actLengthType n_length );

VSECPRIM_FUNC(actRETURNCODE) actECGetPrimeAndOrderBytes(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actLengthType ) p_bytes,
  VSECPRIM_P2VAR_PARA(actLengthType ) n_bytes);

# ifdef __cplusplus
}
# endif
# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

