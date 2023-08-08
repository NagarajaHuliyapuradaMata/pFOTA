

#ifndef ACTIECDH_H
# define ACTIECDH_H

# include "actITypes.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
extern "C"
{
# endif

  VSECPRIM_FUNC(actLengthType) actECDSAGetSecretCompLength(VSECPRIM_P2ROMCONST_PARA(actU8) domain);

VSECPRIM_FUNC(actRETURNCODE) actECDHInitGetSecret(VSECPRIM_P2ROMCONST_PARA(actU8) domain, VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp, actLengthType wksp_len);

VSECPRIM_FUNC(actRETURNCODE) actECDHGetSecret(VSECPRIM_P2CONST_PARA(actU8) privatekey,
                                              VSECPRIM_P2CONST_PARA(actU8) publickey_x, VSECPRIM_P2CONST_PARA(actU8) publickey_y,
                                              VSECPRIM_P2VAR_PARA(actU8) secret_x, VSECPRIM_P2VAR_PARA(actU8) secret_y, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
                                              VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

    VSECPRIM_FUNC(actRETURNCODE) actECDHInitKeyDerive(VSECPRIM_P2ROMCONST_PARA(actU8) domain, VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp, actLengthType wksp_len);

VSECPRIM_FUNC(actRETURNCODE) actECDHKeyDerive(VSECPRIM_P2CONST_PARA(actU8) privatekey, VSECPRIM_P2CONST_PARA(actU8) publickey_x,
                                              VSECPRIM_P2CONST_PARA(actU8) publickey_y, actLengthType iteration_count,
                                              VSECPRIM_P2CONST_PARA(actU8) salt, actLengthType salt_length, VSECPRIM_P2VAR_PARA(actU8) key, actLengthType key_length, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
                                              VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus
}
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

