

#define ACTIRSAEXP_SOURCE

#include "actIRSA.hpp"
#include "actIRSAExp.hpp"
#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTIRSAEXP_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actRSAInitExpCheckInputParameters(
  actLengthType modulus_len
   ,  actLengthType exponent_len
   ,  actLengthType n_length
   ,  actU16 key_flag);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actRSAInitExpCheckExponent(
  actU16 key_flag
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) e
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) modulus
   ,  actLengthType n_length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actRSAExpInputCheck(
  VSECPRIM_P2CONST_PARA(actU8) message
   ,  VSECPRIM_P2CONST_PARA(actLengthType) message_len
   ,  actLengthType cipher_len
   ,  actLengthType modulusLengthBytes);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actRSAInitExpCheckInputParameters(
  actLengthType modulus_len
   ,  actLengthType exponent_len
   ,  actLengthType n_length
   ,  actU16 key_flag){
  actRETURNCODE returnValue = actOK;
  actU32 key_out_of_range = ((key_flag == actRSA_PUBLIC_KEY_OPERATION) ? actEXCEPTION_PUBKEY : actEXCEPTION_PRIVKEY);

  if(exponent_len > modulus_len){
    returnValue = key_out_of_range;
  }

  if(returnValue == actOK){
    if(n_length > actRSA_MAX_KEY_SIZE_IN_DIGIT){
      returnValue = actEXCEPTION_MEMORY;
    }
  }

  return returnValue;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actRSAInitExpCheckExponent(
  actU16 key_flag
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) e
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) modulus
   ,  actLengthType n_length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE returnValue = actOK;
  actU32 key_out_of_range = ((key_flag == actRSA_PUBLIC_KEY_OPERATION) ? actEXCEPTION_PUBKEY : actEXCEPTION_PRIVKEY);

  if(key_flag != actRSA_PRIVATE_KEY_OPERATION_CRT){
    if(key_flag == actRSA_PRIVATE_KEY_OPERATION){
      if(actBNIsZero(e, n_length) == TRUE)
      {
        returnValue = key_out_of_range;
      }
    }
    else{
      if(e[0] <= 1u)
      {
        if(actBNIsZero(&e[1], n_length - 1u) == TRUE)
        {
          returnValue = key_out_of_range;
        }
      }
      else if((actBNIsEven(e)))
      {
        returnValue = key_out_of_range;
      }
      else
      {
      }
    }

    actL2trigger(watchdog);

    if(returnValue == actOK){
      if(actBNCompare(e, modulus, n_length) >= actCOMPARE_EQUAL)
      {
        returnValue = key_out_of_range;
      }
    }
  }

  return returnValue;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actRSAExpInputCheck(
  VSECPRIM_P2CONST_PARA(actU8) message
   ,  VSECPRIM_P2CONST_PARA(actLengthType) message_len
   ,  actLengthType cipher_len
   ,  actLengthType modulusLengthBytes){
  actRETURNCODE returnValue = actOK;

  if((message != NULL_PTR) && (*message_len < modulusLengthBytes)){
    returnValue = actEXCEPTION_MEMORY;
  }

  if(cipher_len > modulusLengthBytes){
    returnValue = actRSA_PARAM_OUT_OF_RANGE;
  }

  return returnValue;
}

VSECPRIM_FUNC(actRETURNCODE) actRSAInitExponentiation(
  VSECPRIM_P2CONST_PARA(actU8) modulus
   ,  actLengthType modulus_len
   ,  VSECPRIM_P2CONST_PARA(actU8) exponent
   ,  actLengthType exponent_len
   ,  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wksp
   ,  actU16 key_flag
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE returnValue = actOK;

  VSECPRIM_P2VAR_PARA(actBNRING) n_ring = &(wksp->wsRSARing);
  actLengthType n_bytes = modulus_len;
  actLengthType n_length = actBNGetDigitLength(n_bytes);
  actLengthType tmp_len;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) tmp;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) e;

  returnValue = actRSAInitExpCheckInputParameters(modulus_len, exponent_len, n_length, key_flag);

  if(returnValue == actOK){
    actL1trigger(watchdog);

    n_ring->m = wksp->modulusBuffer;
    n_ring->RR = wksp->RRBuffer;
    n_ring->m_length = n_length;
    n_ring->m_byte_length = n_bytes;
    actBNSetOctetStringROM(n_ring->m, n_length, modulus, n_bytes);

#if(actBN_MONT_MUL_VERSION == 1)
    n_ring->prime_structure = 0u;
#endif
#if(actBN_MOD_EXP_WINDOW_SIZE == 0)

    n_ring->window_size = actRSA_MOD_EXP_WINDOW_SIZE;
#endif

    actL1trigger(watchdog);

    tmp = wksp->tmp.tmpInit;

    tmp_len = (2u * n_length) + 1u;
    actBNSetZero(tmp, tmp_len);
    tmp[tmp_len - 1u] = 1u;

    actL2trigger(watchdog);

    returnValue = actBNReduce(tmp, tmp_len, n_ring->m, n_length, wksp->RRBuffer, watchdog);

    if( returnValue != actOK){
      returnValue = actRSA_PARAM_OUT_OF_RANGE;
    }
    else{
      actL2trigger(watchdog);

      actBNOddInvModBase(&(n_ring->m_bar), &((n_ring->m)[0]));

      e = wksp->exponent;
      actL1trigger(watchdog);

      actBNSetOctetStringROM(e, n_length, exponent, exponent_len);
      actL1trigger(watchdog);

      returnValue = actRSAInitExpCheckExponent(key_flag, e, wksp->modulusBuffer, n_length, watchdog);
      actL1trigger(watchdog);
    }
  }
  return returnValue;
}

VSECPRIM_FUNC(actRETURNCODE) actRSAExponentiation(
  VSECPRIM_P2CONST_PARA(actU8) cipher
   ,  actLengthType cipher_len
   ,  VSECPRIM_P2VAR_PARA(actU8) message
   ,  VSECPRIM_P2VAR_PARA(actLengthType) message_len
   ,  VSECPRIM_P2VAR_PARA(actRSAPRIMSTRUCT) wksp
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE returnValue = actOK;
  VSECPRIM_P2CONST_PARA(actBNRING) n_ring = &(wksp->wsRSARing);
  actLengthType n_length = n_ring->m_length;
  actLengthType n_bytes = n_ring->m_byte_length;

  VSECPRIM_P2VAR_PARA(actBNDIGIT) e;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) c;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) m;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) t[actRSA_MOD_EXP_TMP];
  actU8 i;

  actL1trigger(watchdog);

  returnValue = actRSAExpInputCheck(message, message_len, cipher_len, n_bytes);

  if(returnValue == actOK){
    e = wksp->exponent;
    c = wksp->tmp.cipherAndMsg.cipher;
    m = wksp->tmp.cipherAndMsg.message;

    for(i = 0; i < actRSA_MOD_EXP_TMP; ++i){
      t[i] = wksp->tmpExp;
    }

    actL3trigger(watchdog);

    actBNSetOctetString(c, n_length, cipher, cipher_len);
    actL3trigger(watchdog);

    if(actBNCompare(c, n_ring->m, n_length) >= actCOMPARE_EQUAL){
      returnValue = actRSA_PARAM_OUT_OF_RANGE;
    }

    if(returnValue == actOK){
      actL3trigger(watchdog);

      actBNMontMulCopy(c, n_ring->RR, t[0], n_ring, watchdog);
      actL3trigger(watchdog);

      actBNModExp(c, e, m, n_ring, t, watchdog);
      actL3trigger(watchdog);

      {
        VSECPRIM_P2VAR_PARA(actBNDIGIT) one = e;
        actBNSetZero(one, n_length);
        one[0] = (actBNDIGIT)1;
        actBNMontMulCopy(m, one, t[0], n_ring, watchdog);
      }
      actL3trigger(watchdog);

      if(message != NULL_PTR)
      {
        actBNOctetString(message, n_bytes, m, n_length);
        *message_len = n_bytes;
      }
      actL1trigger(watchdog);
    }

  }
  return returnValue;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

