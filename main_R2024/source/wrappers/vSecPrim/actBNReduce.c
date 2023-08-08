

#define ACTBNREDUCE_SOURCE

#include "actBigNum.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTBNREDUCE_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(actBNDIGIT) actBNMulDigit(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  const actLengthType a_length,
  const actBNDIGIT b,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) c);

VSECPRIM_LOCAL_FUNC(void) actBNNormalize(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a,
  VSECPRIM_P2VAR_PARA(actLengthType) a_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) b,
  actLengthType b_length,
  actLengthType shift);

VSECPRIM_LOCAL_FUNC(void) actBNReNormalize(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) b,
  actLengthType b_length,
  actLengthType shift);

VSECPRIM_FUNC(actRETURNCODE) actBNReduceLengthCheck(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2VAR_PARA(actLengthType) a_length,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  VSECPRIM_P2VAR_PARA(actLengthType) b_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r);

VSECPRIM_FUNC(void) actBNReduceInitialize(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a,
  VSECPRIM_P2VAR_PARA(actLengthType) a_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) b,
  VSECPRIM_P2CONST_PARA(actLengthType) b_length,
  VSECPRIM_P2VAR_PARA(actLengthType) shift);

VSECPRIM_FUNC(void) actBNReduceComputeQuotientEstimate(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  actLengthType idx,
  actLengthType b_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) qDig);

VSECPRIM_FUNC(void) actBNReduceRefineQuotientEstimate(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  actLengthType idx,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  actLengthType b_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) qDig,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actBNReduceUpdateCurrentProduct(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  actLengthType idx,
  actLengthType b_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) qDig,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

  VSECPRIM_LOCAL_FUNC(actBNDIGIT) actBNMulDigit(
    VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
    const actLengthType a_length,
    const actBNDIGIT b,
    VSECPRIM_P2VAR_PARA(actBNDIGIT) c){
  actLengthType i;
  actBNDDIGIT tmp = 0;

  for (i = 0u; i < a_length; ++i){
    tmp = ((actBNDDIGIT) a[i] * b) + actBNHiWord(tmp);
    c[i] = actBNLoWord(tmp);
  }
  return actBNHiWord(tmp);
}

VSECPRIM_LOCAL_FUNC(void) actBNNormalize(
   VSECPRIM_P2VAR_PARA(actBNDIGIT) a,
  VSECPRIM_P2VAR_PARA(actLengthType) a_length,
   VSECPRIM_P2VAR_PARA(actBNDIGIT) b,
  actLengthType b_length,
  actLengthType shift){
  actBNDIGIT tmp = (actBNDIGIT) (((actBNDIGIT) 1u) << shift);

  actBNDIGIT carry = actBNMulDigit(a, *a_length, tmp, a);
  if(carry != 0u){
    a[*a_length] = carry;
    ++(*a_length);
  }

  (void)actBNMulDigit(b, b_length, tmp, b);
}

VSECPRIM_LOCAL_FUNC(void) actBNReNormalize(
   VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
   VSECPRIM_P2VAR_PARA(actBNDIGIT) b,
  actLengthType b_length,
  actLengthType shift){
  actBNDIGIT tmp = (actBNDIGIT)(((actBNDIGIT)1u) << (actBN_BITS_PER_DIGIT - shift));

  r[b_length] = actBNMulDigit(r, b_length, tmp, r);

  actBNCopy(r, &r[1u], b_length);

  tmp = actBNMulDigit(b, b_length, tmp, b);

  actBNCopy(b, &b[1], b_length - 1u);

  b[b_length - 1u] = tmp;
}

VSECPRIM_FUNC(actRETURNCODE) actBNReduceLengthCheck(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2VAR_PARA(actLengthType) a_length,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  VSECPRIM_P2VAR_PARA(actLengthType) b_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r){
  actRETURNCODE retVal = actOK;

  while ((*a_length > 1u) && (a[*a_length - 1u] == 0u)){
    --(*a_length);
  }

  while ((*b_length > 1u) && (b[*b_length - 1u] == 0u)){
    --(*b_length);
  }

  if(*b_length <= 1u){
    retVal = actEXCEPTION_LENGTH;
  }

  else{
    if(*a_length == *b_length){
      if(actBNCompare(a, b, *a_length) == actCOMPARE_SMALLER)
      {
        actBNCopy(r, a, *a_length);
        retVal = actDONE;
      }
    }
    if(*a_length < *b_length){
      actBNCopy(r, a, *a_length);
      retVal = actDONE;
    }
  }

  return retVal;

}

VSECPRIM_FUNC(void) actBNReduceInitialize(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a,
  VSECPRIM_P2VAR_PARA(actLengthType) a_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) b,
  VSECPRIM_P2CONST_PARA(actLengthType) b_length,
  VSECPRIM_P2VAR_PARA(actLengthType) shift){
  actBNDIGIT tmp = b[*b_length - 1u];
  while (tmp < actBN_MAX_BIT){
    tmp <<= 1;
    *shift = *shift + 1u;
  }

  if(*shift > 0u){
    actBNNormalize(a, a_length, b, *b_length, *shift);
  }

  if(actBNCompare(&a[*a_length - *b_length], b, *b_length) >= actCOMPARE_EQUAL){
    actBNSub(&a[*a_length - *b_length], b, &a[*a_length - *b_length], *b_length);
  }
}

VSECPRIM_FUNC(void) actBNReduceComputeQuotientEstimate(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  actLengthType idx,
  actLengthType b_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) qDig){
  actBNDDIGIT tmp;

  if(a[idx] == b[b_length - 1u]){
    qDig[0] = 0;
  }
  else{
    tmp = ((((actBNDDIGIT)a[idx]) << actBN_BITS_PER_DIGIT) + a[idx - 1u]) / b[b_length - 1u];

    qDig[0] = (actBNDIGIT)(((actBNDIGIT)tmp) + 1u);
  }
}

VSECPRIM_FUNC(void) actBNReduceRefineQuotientEstimate(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  actLengthType idx,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  actLengthType b_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) qDig,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actBNDDIGIT tmp;
  actBNDIGIT digits[3];

  do
  {
    --(*qDig);
    tmp = ((actBNDDIGIT)(*qDig)) * b[b_length - 2u];
    digits[0] = actBNLoWord(tmp);
    tmp = (((actBNDDIGIT)(*qDig)) * b[b_length - 1u]) + actBNHiWord(tmp);
    digits[1] = actBNLoWord(tmp);
    digits[2] = actBNHiWord(tmp);

    actL3trigger(watchdog);
  } while (actBNCompare(&a[idx - 2u], digits, 3) == actCOMPARE_SMALLER);
}

VSECPRIM_FUNC(void) actBNReduceUpdateCurrentProduct(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  actLengthType idx, actLengthType b_length,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) qDig,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  r[b_length] = actBNMulDigit(b, b_length, *qDig, r);
  actL3trigger(watchdog);

  if(actBNCompare(&a[idx - b_length], r, b_length + 1u) == actCOMPARE_SMALLER){
    --(*qDig);
    r[b_length] = actBNMulDigit(b, b_length, *qDig, r);
  }
  actL3trigger(watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actBNReduce(
   VSECPRIM_P2VAR_PARA(actBNDIGIT) a,
  actLengthType a_length,
   VSECPRIM_P2VAR_PARA(actBNDIGIT) b,
  actLengthType b_length,
   VSECPRIM_P2VAR_PARA(actBNDIGIT) r, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actEXCEPTION_UNKNOWN;
  actLengthType a_len = a_length;
  actLengthType b_len = b_length;

  actL1trigger(watchdog);

  actBNSetZero(r, b_len);
  retVal = actBNReduceLengthCheck(a, &a_len, b, &b_len, r);

  if(retVal == actOK){
    actLengthType i, n, t, shift;

    actBNDIGIT qDig;

    shift = 0;

    actBNReduceInitialize(a, &a_len, b, &b_len, &shift);

    n = a_len - 1u;
    t = b_len - 1u;

    for (i = n; i > t; --i){
      actL2trigger(watchdog);

      actBNReduceComputeQuotientEstimate(a, b, i, b_len, &qDig);
      actBNReduceRefineQuotientEstimate(a, i, b, b_len, &qDig, watchdog);
      actBNReduceUpdateCurrentProduct(a, b, i, b_len, &qDig, r, watchdog);
      actBNSub(&a[i - t - 1u], r, &a[i - t - 1u], b_len + 1u);
    }

    actL3trigger(watchdog);

    actBNCopy(r, a, b_len);

    actL3trigger(watchdog);

    if(shift > 0u){
      actBNReNormalize(r, b, b_len, shift);
    }
  }

  actL1trigger(watchdog);

  if(retVal == actDONE){
    retVal = actOK;
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

