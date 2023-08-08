

#ifndef ACTIRSA_H
# define ACTIRSA_H

# include "actITypes.hpp"

# define actRSA_PARAM_OUT_OF_RANGE                                    (0x90u)

# ifdef __cplusplus
extern "C" {
# endif

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actRSAInitPublicKeyOperation(
  VSECPRIM_P2CONST_PARA(actU8) modulus,
  actLengthType modulus_len,
  VSECPRIM_P2CONST_PARA(actU8) public_exponent,
  actLengthType public_exponent_len,
  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wkspBuf,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actRSAPublicKeyOperation(
  VSECPRIM_P2CONST_PARA(actU8) message,
  actLengthType message_len,
  VSECPRIM_P2VAR_PARA(actU8) cipher,
  VSECPRIM_P2VAR_PARA(actLengthType) cipher_len,
  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wkspBuf,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actLengthType) actRSAPublicKeyGetBitLength(
  VSECPRIM_P2CONST_PARA(actBNRING) n_ring);

VSECPRIM_FUNC(actRETURNCODE) actRSAInitPrivateKeyOperation(
  VSECPRIM_P2CONST_PARA(actU8) modulus,
  actLengthType modulus_len,
  VSECPRIM_P2CONST_PARA(actU8) private_exponent,
  actLengthType private_exponent_len,
  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wkspBuf,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actRSAPrivateKeyOperation(
  VSECPRIM_P2CONST_PARA(actU8) cipher,
  actLengthType cipher_len,
  VSECPRIM_P2VAR_PARA(actU8) message,
  VSECPRIM_P2VAR_PARA(actLengthType) message_len,
  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wkspBuf,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actLengthType) actRSAPrivateKeyGetBitLength(
  VSECPRIM_P2CONST_PARA(actBNRING) n_ring);

# if(VSECPRIM_ACTIRSAPRIVATECRT_ENABLED == STD_ON)

VSECPRIM_FUNC(actRETURNCODE) actRSAInitPrivateKeyOperationCRT(
  VSECPRIM_P2CONST_PARA(actU8) prime_p,
  actLengthType prime_p_len,
  VSECPRIM_P2CONST_PARA(actU8) prime_q,
  actLengthType prime_q_len,
  VSECPRIM_P2CONST_PARA(actU8) private_exponent_dp,
  actLengthType private_exponent_dp_len,
  VSECPRIM_P2CONST_PARA(actU8) private_exponent_dq,
  actLengthType private_exponent_dq_len,
  VSECPRIM_P2CONST_PARA(actU8) q_inverse_mod_p,
  actLengthType q_inverse_mod_p_len,
  VSECPRIM_P2VAR_PARA(actRSACRTSTRUCT) wsCRT,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actRSAPrivateKeyOperationCRT(
  VSECPRIM_P2CONST_PARA(actU8) cipher,
  actLengthType cipher_len,
  VSECPRIM_P2VAR_PARA(actU8) message,
  VSECPRIM_P2VAR_PARA(actLengthType) message_len,
  VSECPRIM_P2VAR_PARA(actRSACRTSTRUCT) wsCRT,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
}
# endif

#endif

