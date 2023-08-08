

#ifndef ACTPADDING_H
# define ACTPADDING_H

# include "actITypes.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actPaddingInit(actU8 mode);

VSECPRIM_FUNC(actRETURNCODE) actPaddingPad(actU8 mode, actLengthType buffer_size, VSECPRIM_P2VAR_PARA(actLengthType) buffer_used, VSECPRIM_P2VAR_PARA(actU8) buffer);

VSECPRIM_FUNC(actRETURNCODE) actPaddingUnpad(actU8 mode, actLengthType buffer_size, VSECPRIM_P2VAR_PARA(actLengthType) buffer_used, VSECPRIM_P2CONST_PARA(actU8) buffer);

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

