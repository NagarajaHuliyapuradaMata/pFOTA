

#define ACTIRSAPUBLIC_SOURCE

#include "actIRSA.hpp"
#include "actIRSAExp.hpp"
#include "actBigNum.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTIRSAPUBLIC_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actRSAInitPublicKeyOperation(
  VSECPRIM_P2CONST_PARA(actU8) modulus
   ,  actLengthType modulus_len
   ,  VSECPRIM_P2CONST_PARA(actU8) public_exponent
   ,  actLengthType public_exponent_len
   ,  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wkspBuf
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actRSAInitExponentiation(modulus, modulus_len, public_exponent, public_exponent_len
   ,                                  wkspBuf, actRSA_PUBLIC_KEY_OPERATION, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actRSAPublicKeyOperation(
  VSECPRIM_P2CONST_PARA(actU8) message
   ,  actLengthType message_len
   ,  VSECPRIM_P2VAR_PARA(actU8) cipher
   ,  VSECPRIM_P2VAR_PARA(actLengthType) cipher_len
   ,  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wkspBuf
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actRSAExponentiation(message, message_len, cipher, cipher_len, wkspBuf, watchdog);
}

VSECPRIM_FUNC(actLengthType) actRSAPublicKeyGetBitLength(VSECPRIM_P2CONST_PARA(actBNRING) n_ring){
   return actBNGetBitLength(n_ring->m, n_ring->m_length);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

