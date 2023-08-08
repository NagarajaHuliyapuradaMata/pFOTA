

#define ACTIRSAPRIVATE_SOURCE

#include "actIRSA.hpp"
#include "actIRSAExp.hpp"
#include "actBigNum.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTIRSAPRIVATE_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actRSAInitPrivateKeyOperation(
  VSECPRIM_P2CONST_PARA(actU8) modulus,
  actLengthType modulus_len,
  VSECPRIM_P2CONST_PARA(actU8) private_exponent,
  actLengthType private_exponent_len,
  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wkspBuf,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actRSAInitExponentiation(modulus, modulus_len, private_exponent, private_exponent_len,
                                   wkspBuf, actRSA_PRIVATE_KEY_OPERATION, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE)  actRSAPrivateKeyOperation(
  VSECPRIM_P2CONST_PARA(actU8) cipher,
  actLengthType cipher_len,
  VSECPRIM_P2VAR_PARA(actU8) message,
  VSECPRIM_P2VAR_PARA(actLengthType) message_len,
  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wkspBuf,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   return actRSAExponentiation(cipher, cipher_len, message, message_len, wkspBuf, watchdog);
}

VSECPRIM_FUNC(actLengthType) actRSAPrivateKeyGetBitLength(VSECPRIM_P2CONST_PARA(actBNRING) n_ring){
   return actBNGetBitLength(n_ring->m, n_ring->m_length);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

