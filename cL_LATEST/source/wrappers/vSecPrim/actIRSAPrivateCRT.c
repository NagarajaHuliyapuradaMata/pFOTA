

#define ACTIRSAPRIVATECRT_SOURCE

#include "actIRSA.hpp"
#include "actIRSAExp.hpp"
#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTIRSAPRIVATECRT_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actRSAInitPrivateKeyOperationCRT(
  VSECPRIM_P2CONST_PARA(actU8) prime_p
   ,  actLengthType prime_p_len
   ,  VSECPRIM_P2CONST_PARA(actU8) prime_q
   ,  actLengthType prime_q_len
   ,  VSECPRIM_P2CONST_PARA(actU8) private_exponent_dp
   ,  actLengthType private_exponent_dp_len
   ,  VSECPRIM_P2CONST_PARA(actU8) private_exponent_dq
   ,  actLengthType private_exponent_dq_len
   ,  VSECPRIM_P2CONST_PARA(actU8) q_inverse_mod_p
   ,  actLengthType q_inverse_mod_p_len
   ,  VSECPRIM_P2VAR_PARA(actRSACRTSTRUCT) wsCRT
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;
  actLengthType p_length = actBNGetDigitLength(prime_p_len);
  actLengthType q_length = actBNGetDigitLength(prime_q_len);

  VSECPRIM_P2VAR_PARA(actBNDIGIT) p = wsCRT->wsUnion1.wsCRTInit.primeP;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) q = wsCRT->wsUnion1.wsCRTInit.primeQ;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) dp = wsCRT->wsUnion1.wsCRTInit.primeDP;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) dq = wsCRT->wsUnion1.wsCRTInit.primeDQ;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) qInv = wsCRT->wsUnion1.wsCRTInit.qInv;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) one = wsCRT->wsUnion1.wsCRTInit.one;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) t6 = wsCRT->keySizeBuffer.fullModulus;

  actL1trigger(watchdog);

  if((private_exponent_dp_len > prime_p_len) || (private_exponent_dq_len > prime_q_len) || (q_inverse_mod_p_len > prime_p_len)){
    retVal = actEXCEPTION_PRIVKEY;
  }

  else if((p_length > actRSA_CRT_PRIME_SIZE) || (q_length > actRSA_CRT_PRIME_SIZE) || ((p_length + q_length) > actRSA_CRT_PRIMEPAIR_SIZE)){
    retVal = actEXCEPTION_MEMORY;
  }
  else{
    actBNSetOctetStringROM(p, p_length, prime_p, prime_p_len);
    actBNSetOctetStringROM(q, q_length, prime_q, prime_q_len);
    actBNSetOctetStringROM(dp, p_length, private_exponent_dp, private_exponent_dp_len);
    actBNSetOctetStringROM(dq, q_length, private_exponent_dq, private_exponent_dq_len);
    actBNSetOctetStringROM(qInv, p_length, q_inverse_mod_p, q_inverse_mod_p_len);

    actL1trigger(watchdog);

    actBNMult(p, p_length, q, q_length, t6, VSECPRIM_FUNC_NULL_PTR);

    wsCRT->n_bytes = (actBNGetBitLength(t6, p_length + q_length) + 7u) / 8u;

    if(actBNIsZero(qInv, p_length) == TRUE){
      retVal = actEXCEPTION_PRIVKEY;
    }
    else if(actBNCompare(qInv, p, p_length) >= actCOMPARE_EQUAL){
      retVal = actEXCEPTION_PRIVKEY;
    }
    else{
      actBNSetZero(one, actMax(p_length, q_length));
      one[0] = (actBNDIGIT)1;

      actBNSub(p, one, p, p_length);
      actBNSub(q, one, q, q_length);

      if(actBNIsZero(dp, p_length) == TRUE)
      {
        retVal = actEXCEPTION_PRIVKEY;
      }
      else if(actBNCompare(dp, p, p_length) >= actCOMPARE_EQUAL)
      {
        retVal = actEXCEPTION_PRIVKEY;
      }
      else if(actBNIsZero(dq, q_length) == TRUE)
      {
        retVal = actEXCEPTION_PRIVKEY;
      }
      else if(actBNCompare(dq, q, q_length) >= actCOMPARE_EQUAL)
      {
        retVal = actEXCEPTION_PRIVKEY;
      }
      else
      {
        wsCRT->p = prime_p;
        wsCRT->p_bytes = prime_p_len;
        wsCRT->q = prime_q;
        wsCRT->q_bytes = prime_q_len;
        wsCRT->dp = private_exponent_dp;
        wsCRT->dp_bytes = private_exponent_dp_len;
        wsCRT->dq = private_exponent_dq;
        wsCRT->dq_bytes = private_exponent_dq_len;
        wsCRT->q_inv = q_inverse_mod_p;
        wsCRT->q_inv_bytes = q_inverse_mod_p_len;

        retVal = actOK;
      }
    }
  }

  actL1trigger(watchdog);
  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actRSAPrivateKeyOperationCRT(
  VSECPRIM_P2CONST_PARA(actU8) cipher
   ,  actLengthType cipher_len
   ,  VSECPRIM_P2VAR_PARA(actU8) message
   ,  VSECPRIM_P2VAR_PARA(actLengthType) message_len
   ,  VSECPRIM_P2VAR_PARA(actRSACRTSTRUCT) wsCRT
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE rc;
  VSECPRIM_P2VAR_PARA(actBNRING) ring;

  VSECPRIM_P2VAR_PARA(actBNDIGIT) m1;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) m2;

  VSECPRIM_P2CONST_PARA(actBNDIGIT) fullModulus;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) origCipherBeforeReduction;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) reducedCipherInDigits;
  VSECPRIM_P2VAR_PARA(actU8) reducedCipherInBytes;

  VSECPRIM_P2VAR_PARA(actBNDIGIT) m2Copy;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) m2ModP;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) m1m2;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) qInv;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) qInvM1M2R;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) qInvM1M2;

  VSECPRIM_P2VAR_PARA(actBNDIGIT) primeQ;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) qInvM1M2q;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) m2Padded;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) msg;

  actLengthType p_bytes = wsCRT->p_bytes;
  actLengthType q_bytes = wsCRT->q_bytes;
  actLengthType n_bytes = wsCRT->n_bytes;

  actLengthType p_length = actBNGetDigitLength(p_bytes);
  actLengthType q_length = actBNGetDigitLength(q_bytes);
  actLengthType n_length = actBNGetDigitLength(n_bytes);

  actL1trigger(watchdog);

  if(cipher_len > n_bytes){
    return actRSA_PARAM_OUT_OF_RANGE;
  }

  if(*message_len < n_bytes){
    return actEXCEPTION_MEMORY;
  }

  fullModulus = wsCRT->keySizeBuffer.fullModulus;
  origCipherBeforeReduction = wsCRT->wsUnion2.wsCRTCipherOperations.origCipherBeforeReduction;
  reducedCipherInBytes = wsCRT->wsUnion2.wsCRTCipherOperations.reducedCipherInBytes;
  reducedCipherInDigits = wsCRT->wsUnion2.wsCRTCipherOperations.reducedCipherInDigits;

  actBNSetOctetString(origCipherBeforeReduction, n_length, cipher, cipher_len);

  if(actBNIsZero(origCipherBeforeReduction, n_length) == TRUE){
    return actRSA_PARAM_OUT_OF_RANGE;
  }

  if(actBNCompare(origCipherBeforeReduction, fullModulus, n_length) >= actCOMPARE_EQUAL){
    return actRSA_PARAM_OUT_OF_RANGE;
  }

  m1 = wsCRT->keySizeBuffer.messages.m1;
  m2 = wsCRT->keySizeBuffer.messages.m2;

  ring = &(wsCRT->wsUnion1.wsRSAPrim.wsRSARing);

  rc = actRSAInitExponentiation(wsCRT->q, q_bytes, wsCRT->dq, wsCRT->dq_bytes, &(wsCRT->wsUnion1.wsRSAPrim)
   ,   actRSA_PRIVATE_KEY_OPERATION_CRT, watchdog);
  if(rc != actOK){
    return rc;
  }

  (void)actBNReduce(origCipherBeforeReduction, n_length, ring->m, q_length, reducedCipherInDigits, watchdog);

  actBNOctetString(reducedCipherInBytes, q_bytes, reducedCipherInDigits, q_length);

  (void)actRSAExponentiation(reducedCipherInBytes, q_bytes, (VSECPRIM_P2VAR_PARA(actU8)) 0
   ,   (VSECPRIM_P2VAR_PARA(actLengthType)) 0, &(wsCRT->wsUnion1.wsRSAPrim), watchdog);

  actBNCopy(m2, wsCRT->wsUnion1.wsRSAPrim.tmp.cipherAndMsg.message, q_length);

  rc = actRSAInitExponentiation(wsCRT->p, p_bytes, wsCRT->dp, wsCRT->dp_bytes, &(wsCRT->wsUnion1.wsRSAPrim)
   ,   actRSA_PRIVATE_KEY_OPERATION_CRT, watchdog);
  if(rc != actOK){
    return rc;
  }

  actBNSetOctetString(origCipherBeforeReduction, n_length, cipher, cipher_len);

  (void)actBNReduce(origCipherBeforeReduction, n_length, ring->m, p_length, reducedCipherInDigits, watchdog);

  actBNOctetString(reducedCipherInBytes, p_bytes, reducedCipherInDigits, p_length);

  (void)actRSAExponentiation(reducedCipherInBytes, p_bytes, (VSECPRIM_P2VAR_PARA(actU8)) 0
   ,   (VSECPRIM_P2VAR_PARA(actLengthType)) 0, &(wsCRT->wsUnion1.wsRSAPrim), watchdog);

  actBNCopy(m1, wsCRT->wsUnion1.wsRSAPrim.tmp.cipherAndMsg.message, p_length);

  actL1trigger(watchdog);

  m2Copy = wsCRT->wsUnion2.wsCRTStep3.m2Copy;
  m2ModP = wsCRT->wsUnion2.wsCRTStep3.m2ModP;
  m1m2 = wsCRT->wsUnion2.wsCRTStep3.m1m2;
  qInv = wsCRT->wsUnion2.wsCRTStep3.qInv;
  qInvM1M2R = wsCRT->wsUnion2.wsCRTStep3.qInvM1M2R;
  qInvM1M2 = wsCRT->wsUnion2.wsCRTStep3.qInvM1M2;

  actBNCopy(m2Copy, m2, q_length);

  (void)actBNReduce(m2, q_length, ring->m, p_length, m2ModP, watchdog);

  actBNModSub(m1, m2ModP, m1m2, ring, watchdog);

  actBNSetOctetStringROM(qInv, p_length, wsCRT->q_inv, wsCRT->q_inv_bytes);

  actBNMontMul(m1m2, qInv, qInvM1M2R, ring, watchdog);

  actBNMontMul(qInvM1M2R, ring->RR, qInvM1M2, ring, watchdog);

  m2Padded = wsCRT->wsUnion1.wsCRTSTEP4.m2Padded;
  primeQ = wsCRT->wsUnion1.wsCRTSTEP4.primeQ;
  qInvM1M2q = wsCRT->wsUnion1.wsCRTSTEP4.qInvM1M2q;
  msg = wsCRT->wsUnion1.wsCRTSTEP4.msg;

  actBNSetOctetStringROM(primeQ, q_length, wsCRT->q, wsCRT->q_bytes);

  actBNMult(primeQ, q_length, qInvM1M2, p_length, qInvM1M2q, watchdog);

  actBNCopy(m2Padded, m2Copy, q_length);
  actBNSetZero(&m2Padded[q_length], n_length - q_length);

  (void)actBNAdd(qInvM1M2q, m2Padded, msg, n_length);

  actBNOctetString(message, n_bytes, msg, n_length);
  *message_len = n_bytes;

  actL1trigger(watchdog);

  return actOK;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif
