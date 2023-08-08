

#define ACTBIGNUMGCD_SOURCE

#include "actBigNum.hpp"
#include "actBigNumGCD.hpp"

#if(VSECPRIM_ACTBNEUCLID_ENABLED == STD_ON)

typedef struct{
   int sign;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) value;
}actBIGINT;

# define actBIIsEven(x)                                               (actBNIsEven((x).value))

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actBIDiv2(VSECPRIM_P2VAR_PARA(actBIGINT) a, actLengthType length);

VSECPRIM_LOCAL_FUNC(void) actBIAdd(
   VSECPRIM_P2VAR_PARA(actBIGINT) a, VSECPRIM_P2VAR_PARA(actBIGINT) b,
   VSECPRIM_P2VAR_PARA(actBIGINT) c, actLengthType length);

VSECPRIM_LOCAL_FUNC(void) actBISub(
   VSECPRIM_P2VAR_PARA(actBIGINT) a, VSECPRIM_P2VAR_PARA(actBIGINT) b,
   VSECPRIM_P2VAR_PARA(actBIGINT) c, actLengthType length);

VSECPRIM_LOCAL_FUNC(void) actBIDiv2(VSECPRIM_P2VAR_PARA(actBIGINT) a, actLengthType length){
  actBNDiv2(a->value, 0, length);
  if(actBNIsZero(a->value, length) == TRUE){
    a->sign = 0;
  }
}

VSECPRIM_LOCAL_FUNC(void) actBIAdd(
   VSECPRIM_P2VAR_PARA(actBIGINT) a, VSECPRIM_P2VAR_PARA(actBIGINT) b,
   VSECPRIM_P2VAR_PARA(actBIGINT) c, actLengthType length){
  if(a->sign == b->sign){
    (void)actBNAdd(a->value, b->value, c->value, length);
    c->sign = a->sign;
  }
  else{
    if(actBNCompare(a->value, b->value, length) >= actCOMPARE_EQUAL){
      actBNSub(a->value, b->value, c->value, length);
      if(actBNIsZero(c->value, length) == TRUE)
      {
        c->sign = 0;
      }
      else
      {
        c->sign = a->sign;
      }
    }
    else{
      actBNSub(b->value, a->value, c->value, length);
      c->sign = b->sign;
    }
  }
}

VSECPRIM_LOCAL_FUNC(void) actBISub(
   VSECPRIM_P2VAR_PARA(actBIGINT) a, VSECPRIM_P2VAR_PARA(actBIGINT) b,
   VSECPRIM_P2VAR_PARA(actBIGINT) c, actLengthType length){
  b->sign = -(b->sign);
  actBIAdd(a, b, c, length);
  b->sign = -(b->sign);
}

VSECPRIM_FUNC(void) actBNGCDix(
   VSECPRIM_P2CONST_PARA(actBNDIGIT) a, VSECPRIM_P2VAR_PARA(actBNDIGIT) a_inv,
   VSECPRIM_P2CONST_PARA(actBNRING) Field, VSECPRIM_P2VAR_PARA(actBNDIGIT) t[]){
  actBIGINT x, B, D;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) u;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) v;
  actLengthType length = Field->m_length;
  actLengthType save_length = length + 1;
  int i;

  actBNSetZero(a_inv, save_length);
  for (i = 0; i < 4; ++i){
    actBNSetZero(t[i], save_length);
  }

  x.value = t[0];
  B.value = t[1];
  D.value = a_inv;
  u = t[2];
  v = t[3];

  actBNCopy(x.value, Field->m, length);
  x.sign = 1;

  B.sign = 0;

  D.value[0] = 1;
  D.sign = 1;

  actBNCopy(u, x.value, length);

  actBNCopy(v, a, length);

  while(actBNIsZero(u, length) == FALSE){
    while(actBNIsEven(u)){
      actBNDiv2(u, 0, length);

      if(actBIIsEven(B))
      {
        actBIDiv2(&B, save_length);
      }
      else
      {
        actBISub(&B, &x, &B, save_length);
        actBIDiv2(&B, save_length);
      }
    }

    while(actBNIsEven(v)){
      actBNDiv2(v, 0, length);

      if(actBIIsEven(D))
      {
        actBIDiv2(&D, save_length);
      }
      else
      {
        actBISub(&D, &x, &D, save_length);
        actBIDiv2(&D, save_length);
      }
    }

    if(actBNCompare(u, v, length) >= actCOMPARE_EQUAL){
      actBNSub(u, v, u, length);
      actBISub(&B, &D, &B, save_length);
    }
    else{
      actBNSub(v, u, v, length);
      actBISub(&D, &B, &D, save_length);
    }
  }

  while(D.sign < 0){
    actBIAdd(&D, &x, &D, save_length);
  }

  while(actBNCompare(D.value, x.value, save_length) >= actCOMPARE_EQUAL){
    actBNSub(D.value, x.value, D.value, save_length);
  }
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

