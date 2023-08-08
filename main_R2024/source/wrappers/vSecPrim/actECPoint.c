

#define ACTECPOINT_SOURCE

#include "actECPoint.hpp"

#if(VSECPRIM_ACTECPOINT_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actECPCopy(
  VSECPRIM_P2VAR_PARA(actECPOINT) Q1,
  VSECPRIM_P2CONST_PARA(actECPOINT) Q2,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actECPCopy(
  VSECPRIM_P2VAR_PARA(actECPOINT) Q1,
  VSECPRIM_P2CONST_PARA(actECPOINT) Q2,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType p_length = Curve->p_field.m_length;

  actBNCopy(Q1->x, Q2->x, p_length);
  actBNCopy(Q1->y, Q2->y, p_length);
  if((Q2->is_affine) == TRUE){
    actBNSetOne(Q1->z, p_length);

    actBNMontMulCopy(Q1->z, Curve->p_field.RR, Curve->t[0], &Curve->p_field, watchdog);
  }
  else{
    actBNCopy(Q1->z, Q2->z, p_length);
  }
  Q1->is_infinity = Q2->is_infinity;
}

VSECPRIM_FUNC( void ) actECPAssign(
  VSECPRIM_P2VAR_PARA( actECPOINT ) Q1,
  VSECPRIM_P2CONST_PARA( actECPOINT ) Q2,
  VSECPRIM_P2CONST_PARA( actECCURVE ) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2CONST_PARA(actBNRING) p = &Curve->p_field;

    Q1->is_affine   = FALSE;
    Q1->is_infinity = Q2->is_infinity;

    actBNCopy (Q1->x, Q2->x, p->m_length);
    actBNCopy (Q1->y, Q2->y, p->m_length);

   if( (Q2->is_affine) == TRUE ){
      actBNSetOne       (Q1->z, p->m_length);

      actBNMontMulCopy  (Q1->z, p->RR, Curve->t[0], p, watchdog);
   }
   else{
     actBNCopy( Q1->z, Q2->z, p->m_length);
   }
}

VSECPRIM_FUNC(void) actECPToMont(
  VSECPRIM_P2CONST_PARA(actECPOINT) Q,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   VSECPRIM_P2CONST_PARA(actBNRING)  p_field  = &Curve->p_field;
   VSECPRIM_P2CONST_PARA(actBNDIGIT) RR       = p_field->RR;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) tmp      = Curve->t[0];

   actBNMontMulCopy(Q->x, RR, tmp, p_field, watchdog);

   actBNMontMulCopy(Q->y, RR, tmp, p_field, watchdog);

   if((Q->is_affine) == FALSE){
     actBNMontMulCopy(Q->z, RR, tmp, p_field, watchdog);
   }
}

VSECPRIM_FUNC(actRETURNCODE) actECPToAffineFromMont(
  VSECPRIM_P2VAR_PARA(actECPOINT) Q,
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
  boolean transformToAffineOnly,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;

  VSECPRIM_P2CONST_PARA(actBNRING) p_field  = &Curve->p_field;
  actLengthType p_length = p_field->m_length;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) t0    = Curve->t[0];
  VSECPRIM_P2VAR_PARA(actBNDIGIT) t1    = Curve->t[1];
  VSECPRIM_P2VAR_PARA(actBNDIGIT) Z_inv = Curve->t[actEC_BIGNUM_TMP - 1u];

  if((actBNIsZero(Q->z, p_length) == TRUE) || ((Q->is_infinity) == TRUE)){
    retVal = actEXCEPTION_POINT;
  }

  if(retVal == actOK){
    actBNFieldInversion(Q->z, Z_inv, p_field, Curve->t, watchdog);

    actBNMontMul(Z_inv, Z_inv, t0, p_field, watchdog);

    actBNMontMulCopy(Q->x, t0, t1, p_field, watchdog);

    actBNMontMul(Z_inv, t0, t1, p_field, watchdog);

    actBNMontMulCopy(Q->y, t1, t0, p_field, watchdog);

    if(transformToAffineOnly == FALSE){
      if(actECPointIsOnCurve(Q, Curve, watchdog) != actOK)
      {
        retVal = actEXCEPTION_POINT;
      }
      else
      {
        actBNSetOne(t1, p_length);
        actBNMontMulCopy(Q->x, t1, t0, p_field, watchdog);
        actBNMontMulCopy(Q->y, t1, t0, p_field, watchdog);
      }
    }
    else{
      Q->is_affine = TRUE;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actECPointIsOnCurve(
   VSECPRIM_P2CONST_PARA(actECPOINT) Q,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   actRETURNCODE retVal = actOK;

   if((Q->is_infinity) == TRUE){
      retVal = actEXCEPTION_POINT;
   }
   else{
      VSECPRIM_P2CONST_PARA(actBNRING) p_field = &Curve->p_field;
      actLengthType p_length = p_field->m_length;
      actLengthType p_bytes  = p_field->m_byte_length;
      VSECPRIM_P2VAR_PARA(actBNDIGIT) a_R    = Curve->t[0];
      VSECPRIM_P2VAR_PARA(actBNDIGIT) b_R    = Curve->t[1];
      VSECPRIM_P2VAR_PARA(actBNDIGIT) tmp1   = Curve->t[2];
      VSECPRIM_P2VAR_PARA(actBNDIGIT) tmp2   = Curve->t[3];

      actBNSetOctetStringROM(a_R, p_length, Curve->a_R, p_bytes);

      actBNSetOctetStringROM(b_R, p_length, Curve->b_R, p_bytes);

      actBNMontMul(Q->x, Q->x, tmp1, p_field, watchdog);

      actBNModAdd(tmp1, a_R, tmp1, p_field, watchdog);

      actBNMontMul(tmp1, Q->x, tmp2, p_field, watchdog);

      actBNModAdd(tmp2, b_R, tmp1, p_field, watchdog);

      actBNMontMul(Q->y, Q->y, tmp2, p_field, watchdog);

      if(actBNCompare(tmp1, tmp2, p_length) != actCOMPARE_EQUAL)
      {
         retVal = actEXCEPTION_POINT;
      }
   }

   return retVal;
}

VSECPRIM_FUNC(void) actECPDouble(
  VSECPRIM_P2VAR_PARA(actECPOINT) Q,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   VSECPRIM_P2CONST_PARA(actBNRING)  p_field = &Curve->p_field;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) result  = Curve->t[0];
   actLengthType p_length = p_field->m_length;

   VSECPRIM_P2VAR_PARA(actBNDIGIT) t1 = Q->x;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) t2 = Q->y;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) t3 = Q->z;

   if((Q->is_infinity) == TRUE){
   }
   else if(actBNIsZero(t2, p_length) == TRUE){
      Q->is_infinity = TRUE;
   }
   else{
      VSECPRIM_P2VAR_PARA(actBNDIGIT) t4 = Curve->t[1];
      VSECPRIM_P2VAR_PARA(actBNDIGIT) t5 = Curve->t[2];

      if((Curve->a_equals_p_minus_3) == TRUE)
      {
         actBNMontMul(t3, t3, t4, p_field, watchdog);

         actBNModSub(t1, t4, t5, p_field, watchdog);

         actBNModAdd(t1, t4, t4, p_field, watchdog);

         actBNMontMul(t4, t5, result, p_field, watchdog);

         actBNModAdd(result, result, t4, p_field, watchdog);

         actBNModAdd(t4, result, t4, p_field, watchdog);
      }
      else
      {
         actBNSetOctetStringROM(t4, p_length, Curve->a_R, Curve->p_field.m_byte_length);
         if(actBNIsZero(t4, p_length) == FALSE)
         {
            actBNMontMul(t3, t3, t5, p_field, watchdog);

            actBNMontMul(t5, t5, result, p_field, watchdog);

            actBNMontMul(result, t4, t5, p_field, watchdog);
         }
         else
         {
            actBNSetZero(t5, p_length);
         }

         actBNMontMul(t1, t1, result, p_field, watchdog);

         actBNModAdd(result, result, t4, p_field, watchdog);

         actBNModAdd(t4, result, t4, p_field, watchdog);

         actBNModAdd(t4, t5, t4, p_field, watchdog);
      }

      actBNMontMul(t2, t3, result, p_field, watchdog);

      actBNModAdd(result, result, t3, p_field, watchdog);

      actBNMontMulCopy(t2, t2, result, p_field, watchdog);

      actBNMontMul(t1, t2, t5, p_field, watchdog);

      actBNModAdd(t5, t5, t5, p_field, watchdog);

      actBNModAdd(t5, t5, t5, p_field, watchdog);

      actBNMontMul(t4, t4, result, p_field, watchdog);

      actBNModSub(result, t5, t1, p_field, watchdog);

      actBNModSub(t1, t5, t1, p_field, watchdog);

      actBNMontMul(t2, t2, result, p_field, watchdog);

      actBNModAdd(result, result, t2, p_field, watchdog);

      actBNModAdd(t2, t2, t2, p_field, watchdog);
      actBNModAdd(t2, t2, t2, p_field, watchdog);

      actBNModSub(t5, t1, t5, p_field, watchdog);

      actBNMontMul(t5, t4, result, p_field, watchdog);

      actBNModSub(result, t2, t2, p_field, watchdog);
   }
}

VSECPRIM_FUNC(void) actECPAdd(
  VSECPRIM_P2VAR_PARA(actECPOINT) Q1,
  VSECPRIM_P2CONST_PARA(actECPOINT) Q2,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   VSECPRIM_P2CONST_PARA(actBNRING)  p_field = &Curve->p_field;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) result  = Curve->t[0];
   actLengthType p_length = p_field->m_length;

   VSECPRIM_P2VAR_PARA(actBNDIGIT) t1 = Q1->x;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) t2 = Q1->y;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) t3 = Q1->z;

   if((Q2->is_infinity) == TRUE){
   }
   else if((Q1->is_infinity) == TRUE){
      actECPCopy(Q1, Q2, Curve, watchdog);
   }
   else{
      VSECPRIM_P2VAR_PARA(actBNDIGIT) t4 = Curve->t[1];
      VSECPRIM_P2VAR_PARA(actBNDIGIT) t5 = Curve->t[2];
      VSECPRIM_P2VAR_PARA(actBNDIGIT) t7 = Curve->t[3];

      VSECPRIM_P2CONST_PARA(actBNDIGIT) t6 = Curve->t[3];

      actBNCopy(t4, Q2->x, p_length);
      actBNCopy(t5, Q2->y, p_length);

      if((Q2->is_affine) == FALSE)
      {
         t6 = Q2->z;

         actBNMontMul(t6, t6, t7, p_field, watchdog);

         actBNMontMulCopy(t1, t7, result, p_field, watchdog);

         actBNMontMul(t7, t6, result, p_field, watchdog);

         actBNMontMulCopy(t2, result, t7, p_field, watchdog);
      }

      actBNMontMul(t3, t3, t7, p_field, watchdog);

      actBNMontMul(t4, t7, result, p_field, watchdog);

      actBNModSub(t1, result, t4, p_field, watchdog);

      actBNMontMulCopy(t7, t3, result, p_field, watchdog);

      actBNMontMul(t5, t7, result, p_field, watchdog);

      actBNModSub(t2, result, t5, p_field, watchdog);

      if(actBNIsZero(t4, p_length) == TRUE)
      {
         if(actBNIsZero(t5, p_length) == TRUE)
         {
            actECPCopy(Q1, Q2, Curve, watchdog);
            actECPDouble(Q1, Curve, watchdog);
         }
         else
         {
            Q1->is_infinity = TRUE;
         }
      }
      else
      {
         actBNModAdd(t1, t1, t1, p_field, watchdog);

         actBNModSub(t1, t4, t1, p_field, watchdog);

         actBNModAdd(t2, t2, t2, p_field, watchdog);

         actBNModSub(t2, t5, t2, p_field, watchdog);

         if((Q2->is_affine) == FALSE)
         {
            actBNMontMulCopy(t3, t6, result, p_field, watchdog);
         }

         actBNMontMulCopy(t3, t4, result, p_field, watchdog);

         actBNMontMul(t4, t4, t7, p_field, watchdog);

         actBNMontMulCopy(t4, t7, result, p_field, watchdog);

         actBNMontMulCopy(t7, t1, result, p_field, watchdog);

         actBNMontMul(t5, t5, result, p_field, watchdog);

         actBNModSub(result, t7, t1, p_field, watchdog);

         actBNModSub(t7, t1, t7, p_field, watchdog);
         actBNModSub(t7, t1, t7, p_field, watchdog);

         actBNMontMulCopy(t5, t7, result, p_field, watchdog);

         actBNMontMul(t4, t2, result, p_field, watchdog);

         actBNModSub(t5, result, t2, p_field, watchdog);

         actBNModDiv2(t2, p_field, watchdog);
      }
   }
}

VSECPRIM_FUNC (void) actECPSub (
  VSECPRIM_P2VAR_PARA( actECPOINT ) Q1,
  VSECPRIM_P2CONST_PARA( actECPOINT ) Q2,
  VSECPRIM_P2CONST_PARA( actECCURVE ) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
    VSECPRIM_P2CONST_PARA (actBNRING) p = &Curve->p_field;

    actBNModSub (p->m, Q2->y, Q2->y, p,     watchdog);
    actECPAdd   (Q1, Q2, Curve, watchdog);

    actBNModSub (p->m, Q2->y, Q2->y, p, watchdog);
}

VSECPRIM_FUNC(void) actECPMult(
  VSECPRIM_P2CONST_PARA(actECPOINT) Q,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) k,
  VSECPRIM_P2VAR_PARA(actECPOINT) R,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   actLengthType i = actBNGetBitLength(Curve->n_field.m, Curve->n_field.m_length);

   R->is_affine   = FALSE;
   R->is_infinity = TRUE;

   for (; i > 0u; --i){
      actECPDouble(R, Curve, watchdog);

      if(actBNGetBit(k, i - 1u))
      {
         actECPAdd(R, Q, Curve, watchdog);
      }
   }
}

VSECPRIM_FUNC( void ) actECPMultShort (
  VSECPRIM_P2CONST_PARA( actECPOINT ) Q,
  const actU32      k,
  VSECPRIM_P2VAR_PARA( actECPOINT ) R,
  VSECPRIM_P2CONST_PARA( actECCURVE ) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   actU32   mask = 0x80000000UL;

   R->is_affine   = FALSE;
   R->is_infinity = TRUE;

   while (mask != 0u){
      actECPDouble (R, Curve, watchdog);

      if((mask & k) != 0u)
      {
         actECPAdd (R, Q, Curve, watchdog);
      }

      mask >>= 1u;
   }
}

VSECPRIM_FUNC(void) actECPMultG(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) k,
  VSECPRIM_P2VAR_PARA(actECPOINT) Prec,
  VSECPRIM_P2VAR_PARA(actECPOINT) R,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   VSECPRIM_P2CONST_PARA(actBNRING) p_field = &Curve->p_field;
   actLengthType p_length = p_field->m_length;
   actLengthType p_bytes = p_field->m_byte_length;
   actLengthType n_bits = actBNGetBitLength(Curve->n_field.m, Curve->n_field.m_length);
   actLengthType prec_offset = (p_bytes >= 64u) ? 4u : 3u;
   actLengthType prec_length = prec_offset + (2u * p_bytes);
   actLengthType i, j, group_bits, index, bit_pos;
   VSECPRIM_P2ROMCONST_PARA(actU8) prec_ptr;
   VSECPRIM_P2ROMCONST_PARA(actU8) correctionPoint_ptr;

   for (i = n_bits; (i % Curve->groups) != 0u; ++i) {}
   group_bits = i / Curve->groups;

   R->is_affine   = FALSE;
   R->is_infinity = TRUE;

   Prec->is_affine   = TRUE;
   Prec->is_infinity = FALSE;

   for (i = group_bits; i > 0u; --i){
      actECPDouble(R, Curve, watchdog);

      index = 0u;
      for (j = Curve->groups; j > 0u; --j)
      {
         bit_pos = ((j - 1u) * group_bits) + (i - 1u);
         if(bit_pos < n_bits)
         {
            index += ((actLengthType)(actBNGetBit(k, bit_pos)) << (j - 1u));
         }
      }

      if(index == 0u)
      {
         prec_ptr = Curve->G_R;
      }
      else
      {
        prec_ptr = &(Curve->prec_first[((index - 1u) * prec_length) + prec_offset]);
      }

      actBNSetOctetStringROM(Prec->x, p_length, prec_ptr, p_bytes);
      actBNSetOctetStringROM(Prec->y, p_length, &prec_ptr[p_bytes], p_bytes);

      actECPAdd(R, Prec, Curve, watchdog);
   }

   correctionPoint_ptr = &(Curve->prec_first[(((((actLengthType)1u) << Curve->groups) - 1u) * prec_length) + prec_offset]);
   actBNSetOctetStringROM(Prec->x, p_length, correctionPoint_ptr, p_bytes);
   actBNSetOctetStringROM(Prec->y, p_length, &correctionPoint_ptr[p_bytes], p_bytes);

   actECPAdd(R, Prec, Curve, watchdog);
}

VSECPRIM_FUNC(void) actECPSimMult(
  VSECPRIM_P2CONST_PARA(actECPOINT) Q1,
  VSECPRIM_P2CONST_PARA(actECPOINT) Q2,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) k1,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) k2,
  VSECPRIM_P2VAR_PARA(actECPOINT) Q12,
  VSECPRIM_P2VAR_PARA(actECPOINT) R,
  VSECPRIM_P2CONST_PARA(actECCURVE) Curve,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   actLengthType i = actBNGetBitLength(Curve->n_field.m, Curve->n_field.m_length);
   actLengthType tmpI;
   actU8 k1_bit, k2_bit;

   R->is_affine   = FALSE;
   R->is_infinity = TRUE;

   Q12->is_affine = FALSE;
   actECPCopy(Q12, Q1, Curve, watchdog);
   actECPAdd(Q12, Q2, Curve, watchdog);

# if(VSECPRIM_ACTBNEUCLID_ENABLED == STD_ON)
   actECPToAffineFromMont(Q12, Curve, TRUE);
# endif

   for (; i > 0u; --i){
      tmpI = i - 1u;

      actECPDouble(R, Curve, watchdog);

      k1_bit = (actU8)actBNGetBit(k1, tmpI);
      k2_bit = (actU8)actBNGetBit(k2, tmpI);
      if(k1_bit != 0u)
      {
         if(k2_bit != 0u)
         {
            actECPAdd(R, Q12, Curve, watchdog);
         }
         else
         {
            actECPAdd(R, Q1, Curve, watchdog);
         }
      }
      else
      {
         if(k2_bit != 0u)
         {
            actECPAdd(R, Q2, Curve, watchdog);
         }
      }
   }
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

