

#define ACTBNMODEXP_SOURCE

#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTBNMODEXP_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actBNModExp(
   VSECPRIM_P2CONST_PARA(actBNDIGIT) gR, VSECPRIM_P2CONST_PARA(actBNDIGIT) e,
   VSECPRIM_P2VAR_PARA(actBNDIGIT) AR, VSECPRIM_P2CONST_PARA(actBNRING) Ring,
   VSECPRIM_P2VAR_PARA(actBNDIGIT) t[], VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
# if(actBN_MOD_EXP_WINDOW_SIZE==1)

  actLengthType m_length = Ring->m_length;
  actLengthType i = actBNGetBitLength(Ring->m, Ring->m_length) - 1u;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) tmp = t[0];

  actL1trigger(watchdog);

  while(actBNGetBit(e, i) == FALSE){
    if((i & 0x07u) == 0x00u){
      actL3trigger(watchdog);
    }
    --i;
  }

  actL1trigger(watchdog);

  actBNCopy(AR, gR, m_length);

  actL1trigger(watchdog);

  for (; i > 0u; i--){
    actL3trigger(watchdog);

    actBNMontMul(AR, AR, tmp, Ring, watchdog);

    actL3trigger(watchdog);

    if(actBNGetBit(e, (i - 1u)) == TRUE){
      actL3trigger(watchdog);

      actBNMontMul(tmp, gR, AR, Ring, watchdog);
    }
    else{
      actL3trigger(watchdog);

      actBNCopy(AR, tmp, m_length);
    }
  }

# elif(actBN_MOD_EXP_WINDOW_SIZE == 2)

  actLengthType i = actBNGetBitLength(Ring->m, Ring->m_length) - 1;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) tmp = t[0];
  actU8 e1_bit, e2_bit;

  actL1trigger(watchdog);

  while(actBNGetBit(e, i) == 0){
    if((i & 0x07) == 0x00){
      actL3trigger(watchdog);
    }
    --i;
  }

  actL1trigger(watchdog);

  if(i & 1u){
    actBNSetZero(AR, Ring->m_length);
    AR[0] = (actBNDIGIT) 1;

    actL3trigger(watchdog);

    actBNMontMulCopy(AR, Ring->RR, tmp, Ring, watchdog);
  }
  else{
    actBNCopy(AR, gR, Ring->m_length);
    --i;
  }

  actBNMontMul(gR, gR, tmp, Ring, watchdog);

  actL1trigger(watchdog);

  actBNMontMul(gR, tmp, t[1], Ring, watchdog);

  while(i >= 0){
    e1_bit = (actU8) actBNGetBit(e, i);
    --i;
    e2_bit = (actU8) actBNGetBit(e, i);
    --i;

    actL3trigger(watchdog);

    actBNMontMul(AR, AR, tmp, Ring, watchdog);

    actL3trigger(watchdog);

    if(e1_bit){
      if(e2_bit)
      {
        actBNMontMul(tmp, tmp, AR, Ring, watchdog);

        actL3trigger(watchdog);

        actBNMontMulCopy(AR, t[1], tmp, Ring, watchdog);
      }
      else
      {
        actBNMontMul(tmp, gR, AR, Ring, watchdog);

        actL3trigger(watchdog);

        actBNMontMulCopy(AR, AR, tmp, Ring, watchdog);
      }
    }
    else{
      actBNMontMul(tmp, tmp, AR, Ring, watchdog);

      actL3trigger(watchdog);

      if(e2_bit)
      {
        actBNMontMulCopy(AR, gR, tmp, Ring, watchdog);
      }
    }
  }

# elif(actBN_MOD_EXP_WINDOW_SIZE == 3)

  actLengthType i = actBNGetBitLength(Ring->m, Ring->m_length) - 1;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) tmp = t[0];
  actU8 e1_bit, e2_bit, e3_bit;

  actL1trigger(watchdog);

  while(actBNGetBit(e, i) == 0){
    if((i & 0x07) == 0x00){
      actL3trigger(watchdog);
    }
    --i;
  }

  actL1trigger(watchdog);

  actBNSetZero(AR, Ring->m_length);
  AR[0] = (actBNDIGIT) 1;

  actL1trigger(watchdog);

  actBNMontMulCopy(AR, Ring->RR, tmp, Ring, watchdog);

  actBNMontMul(gR, gR, tmp, Ring, watchdog);

  actL1trigger(watchdog);

  actBNMontMul(gR, tmp, t[1], Ring, watchdog);

  actL1trigger(watchdog);

  actBNMontMul(t[1], tmp, t[2], Ring, watchdog);

  actL1trigger(watchdog);

  actBNMontMul(t[2], tmp, t[3], Ring, watchdog);

  while(i >= 2){
    actL3trigger(watchdog);

    e1_bit = (actU8) actBNGetBit(e, i);
    --i;
    e2_bit = (actU8) actBNGetBit(e, i);
    --i;
    e3_bit = (actU8) actBNGetBit(e, i);
    --i;

    actL3trigger(watchdog);

    actBNMontMul(AR, AR, tmp, Ring, watchdog);

    actL3trigger(watchdog);

    if(e1_bit){
      if(e2_bit)
      {
        actBNMontMul(tmp, tmp, AR, Ring, watchdog);

        actL3trigger(watchdog);

        if(e3_bit)
        {
          actBNMontMul(AR, AR, tmp, Ring, watchdog);

          actL3trigger(watchdog);

          actBNMontMul(tmp, t[3], AR, Ring, watchdog);
        }
        else
        {
          actBNMontMul(AR, t[1], tmp, Ring, watchdog);

          actL3trigger(watchdog);

          actBNMontMul(tmp, tmp, AR, Ring, watchdog);
        }
      }
      else
      {
        if(e3_bit)
        {
          actBNMontMul(tmp, tmp, AR, Ring, watchdog);

          actL3trigger(watchdog);

          actBNMontMul(AR, AR, tmp, Ring, watchdog);

          actL3trigger(watchdog);

          actBNMontMul(tmp, t[2], AR, Ring, watchdog);
        }
        else
        {
          actBNMontMul(tmp, gR, AR, Ring, watchdog);

          actL3trigger(watchdog);

          actBNMontMul(AR, AR, tmp, Ring, watchdog);

          actL3trigger(watchdog);

          actBNMontMul(tmp, tmp, AR, Ring, watchdog);
        }
      }
    }
    else{
      actL3trigger(watchdog);

      actBNMontMul(tmp, tmp, AR, Ring, watchdog);

      actL3trigger(watchdog);

      if(e3_bit)
      {
        actBNMontMul(AR, AR, tmp, Ring, watchdog);

        actL3trigger(watchdog);

        if(e2_bit)
        {
          actBNMontMul(tmp, t[1], AR, Ring, watchdog);
        }
        else
        {
          actBNMontMul(tmp, gR, AR, Ring, watchdog);
        }
      }
      else
      {
        if(e2_bit)
        {
          actBNMontMul(AR, gR, tmp, Ring, watchdog);

          actL3trigger(watchdog);

          actBNMontMul(tmp, tmp, AR, Ring, watchdog);
        }
        else
        {
          actBNMontMulCopy(AR, AR, tmp, Ring, watchdog);
        }
      }
    }
  }

  for (; i > 0; --i){
    actL3trigger(watchdog);

    actBNMontMulCopy(AR, AR, tmp, Ring, watchdog);

    actL3trigger(watchdog);

    if(actBNGetBit(e, i-1) == 1){
      actBNMontMulCopy(AR, gR, tmp, Ring, watchdog);
    }
  }

# else

  actLengthType i = actBNGetBitLength(Ring->m, Ring->m_length) - 1;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) tmp = t[0];
  actLengthType j, l, index, len;
  actLengthType k = Ring->window_size - 1;
  actLengthType num_of_tmps = 1 << k;

  actL1trigger(watchdog);

  while(actBNGetBit(e, i) == 0){
    --i;
  }

  actL3trigger(watchdog);

  actBNSetZero(AR, Ring->m_length);
  AR[0] = (actBNDIGIT) 1;
  actBNMontMulCopy(AR, Ring->RR, tmp, Ring, watchdog);

  actL3trigger(watchdog);

  actBNMontMul(gR, gR, tmp, Ring, watchdog);

  actBNMontMul(gR, tmp, t[1], Ring, watchdog);

  actL3trigger(watchdog);

  for (j = 2; j < num_of_tmps; ++j){
    actBNMontMul(t[j - 1], tmp, t[j], Ring, watchdog);
  }

  t[0] = (VSECPRIM_P2VAR_PARA(actBNDIGIT)) gR;

  while(i >= 0){
    actL3trigger(watchdog);

    if(actBNGetBit(e, i) == 0){
      actBNMontMulCopy(AR, AR, tmp, Ring, watchdog);
      --i;
    }
    else{
      l = i - k;
      l = actMax(l, 0);
      while(actBNGetBit(e, l) == 0)
      {
        ++l;
      }
      len = i - l;

      actL3trigger(watchdog);

      for (j = 0; j <= len; j++)
      {
        actBNMontMulCopy(AR, AR, tmp, Ring, watchdog);
      }

      actL3trigger(watchdog);

      index = 1u << len;
      for (j = l + 1; j < i; j++)
      {
        if(actBNGetBit(e, j) == 1)
        {
          index += (1u << (j - l));
        }
      }

      actL3trigger(watchdog);

      actBNMontMulCopy(AR, t[index >> 1], tmp, Ring, watchdog);

      i = l - 1;
    }
  }

  t[0] = tmp;

# endif

  actL1trigger(watchdog);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

