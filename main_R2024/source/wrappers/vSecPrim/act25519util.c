

#define ACT25519UTIL_SOURCE

#include "act25519util.hpp"
#include "actWatchdog.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACT25519UTIL_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) curvePrime[BNDIGITS_256] =
{
  DIGITs(0xFFFFFFEDuL), DIGITs(0xFFFFFFFFuL), DIGITs(0xFFFFFFFFuL), DIGITs(0xFFFFFFFFuL),
  DIGITs(0xFFFFFFFFuL), DIGITs(0xFFFFFFFFuL), DIGITs(0xFFFFFFFFuL), DIGITs(0x7FFFFFFFuL)
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) curveConst[BNDIGITS_256] =
{
  DIGITs(0x135978A3uL), DIGITs(0x75EB4DCAuL), DIGITs(0x4141D8ABuL), DIGITs(0x00700A4DuL),
  DIGITs(0x7779E898uL), DIGITs(0x8CC74079uL), DIGITs(0x2B6FFE73uL), DIGITs(0x52036CEEuL)
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) groupOrder[BNDIGITS_256] =
{
  DIGITs(0x5CF5D3EDuL), DIGITs(0x5812631AuL), DIGITs(0xA2F79CD6uL), DIGITs(0x14DEF9DEuL),
  DIGITs(0x00000000uL), DIGITs(0x00000000uL), DIGITs(0x00000000uL), DIGITs(0x10000000uL)
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actPoint) basePoint =
{
  {DIGITs(0x8F25D51AuL), DIGITs(0xC9562D60uL), DIGITs(0x9525A7B2uL), DIGITs(0x692CC760uL),
    DIGITs(0xFDD6DC5CuL), DIGITs(0xC0A4E231uL), DIGITs(0xCD6E53FEuL), DIGITs(0x216936D3uL)},
  {DIGITs(0x66666658uL), DIGITs(0x66666666uL), DIGITs(0x66666666uL), DIGITs(0x66666666uL),
    DIGITs(0x66666666uL), DIGITs(0x66666666uL), DIGITs(0x66666666uL), DIGITs(0x66666666uL)},
  {DIGITs(0x00000001uL), DIGITs(0x00000000uL), DIGITs(0x00000000uL), DIGITs(0x00000000uL),
    DIGITs(0x00000000uL), DIGITs(0x00000000uL), DIGITs(0x00000000uL), DIGITs(0x00000000uL)},
  {DIGITs(0xA5B7DDA3uL), DIGITs(0x6DDE8AB3uL), DIGITs(0x775152F5uL), DIGITs(0x20F09F80uL),
    DIGITs(0x64ABE37DuL), DIGITs(0x66EA4E8EuL), DIGITs(0xD78B7665uL), DIGITs(0x67875F0FuL)}
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) gOBarrett[BNDIGITS_256 + 1u] =
{
  DIGITs(0x0A2C131BuL), DIGITs(0xED9CE5A3uL), DIGITs(0x086329A7uL), DIGITs(0x2106215DuL),
  DIGITs(0xFFFFFFEBuL), DIGITs(0xFFFFFFFFuL), DIGITs(0xFFFFFFFFuL), DIGITs(0xFFFFFFFFuL),
  0x0Fu
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) cCtimes2[BNDIGITS_256] =
{
  DIGITs(0x26B2F159uL), DIGITs(0xEBD69B94uL), DIGITs(0x8283B156uL), DIGITs(0x00E0149AuL),
  DIGITs(0xEEF3D130uL), DIGITs(0x198E80F2uL), DIGITs(0x56DFFCE7uL), DIGITs(0x2406D9DCuL)
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) prime38[BNDIGITS_256] =
{
  DIGITs(0xFFFFFFFEuL), DIGITs(0xFFFFFFFFuL), DIGITs(0xFFFFFFFFuL), DIGITs(0xFFFFFFFFuL),
  DIGITs(0xFFFFFFFFuL), DIGITs(0xFFFFFFFFuL), DIGITs(0xFFFFFFFFuL), DIGITs(0x0FFFFFFFuL)
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) sqrtM1[BNDIGITS_256] =
{
  DIGITs(0x4A0EA0B0uL), DIGITs(0xC4EE1B27uL), DIGITs(0xAD2FE478uL), DIGITs(0x2F431806uL),
  DIGITs(0x3DFBD7A7uL), DIGITs(0x2B4D0099uL), DIGITs(0x4FC1DF0BuL), DIGITs(0x2B832480uL)
};

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) act25519_reduce(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) q,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) n);

VSECPRIM_LOCAL_FUNC(void) act25519_reduce(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) q,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) n){
  actU32 d;
  actBNDDIGIT tempBuffer;

  actMemset(r, 0u, BNBYTES_256);
  for (d = 0u; d < BNDIGITS_256; d++){
    actU32 j;
    actBNDDIGIT digit;

    digit = n[d];
    tempBuffer = 0u;
    for (j = 0u; j < ((actU32)BNDIGITS_256 - d); j++){
      tempBuffer += ((actBNDDIGIT) q[j]) * digit;
      tempBuffer += r[d + j];
      r[d + j] = actBNLoWord(tempBuffer);
      tempBuffer = actBNHiWord(tempBuffer);
    }
  }

  actBNSub(a, r, r, BNDIGITS_256);

  while (actCOMPARE_LARGER == actBNCompare(r, n, BNDIGITS_256)){
    actBNSub(r, n, r, BNDIGITS_256);
  }
}

VSECPRIM_FUNC(void) act25519_initCore(VSECPRIM_P2VAR_PARA(actCurve25519ws) ws){
  VSECPRIM_P2VAR_PARA(actBNRING) ring;

  actMemCpyWordArray(ws->prime, curvePrime, BNDIGITS_256);
  actMemCpyWordArray(ws->order, groupOrder, BNDIGITS_256);
  actMemCpyWordArray(ws->orderB, gOBarrett, BNDIGITS_256 + 1u);

  ring = &(ws->pRing);
  ring->m = ws->prime;
  ring->m_length = BNDIGITS_256;

  ring = &(ws->qRing);
  ring->m = ws->order;
  ring->m_length = BNDIGITS_256;
}

VSECPRIM_FUNC(void) act25519_reduceP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a){
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a76 = a;
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a2 = a;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) q = ws->auxVar.tempQ;
  actBNDDIGIT tempBuffer = 0u;
  actU8 d;
  actU8 offsetA2 = 0u;
  actU8 offsetQ = 0u;

  for (d = 0u; d < BNDIGITS_256; d++){
    tempBuffer += ((actBNDDIGIT)a76[d]) * 76u;
    tempBuffer = actBNHiWord(tempBuffer);
  }

  for (; d < (2u * (BNDIGITS_256)); d++){
    tempBuffer += ((actBNDDIGIT)a76[d]) * 76u;
    tempBuffer += ((actBNDDIGIT)a2[offsetA2]) * 2u;
    tempBuffer = actBNHiWord(tempBuffer);
    offsetA2++;
  }

  for (; d < (3u * (BNDIGITS_256)); d++){
    tempBuffer += ((actBNDDIGIT)a2[offsetA2]) * 2u;
    q[offsetQ] = actBNLoWord(tempBuffer);
    tempBuffer = actBNHiWord(tempBuffer);
    offsetA2++;
    offsetQ++;
  }

  act25519_reduce(r, a, ws->auxVar.tempQ, ws->prime);
}

VSECPRIM_FUNC(void) act25519_reduceQ(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a){
  actBNDIGIT q[BNDIGITS_512 * 2u];

  actBNMult(a, BNDIGITS_512, ws->orderB, BNDIGITS_256 + 1u, q, NULL_PTR);

  act25519_reduce(r, a, &q[BNDIGITS_512], ws->order);
}

VSECPRIM_FUNC(void) act25519_addModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b){
  actBNModAdd(a, b, r, &(ws->pRing), NULL_PTR);
}

VSECPRIM_FUNC(void) act25519_subModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b){
  actBNModSub(a, b, r, &(ws->pRing), NULL_PTR);
}

VSECPRIM_FUNC(void) act25519_mulModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b){
  actBNMult(a, BNDIGITS_256, b, BNDIGITS_256, ws->auxVar.temp1, NULL_PTR);

  act25519_reduceP(ws, r, ws->auxVar.temp1);
}

VSECPRIM_FUNC(void) act25519_powModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 dig;

  actMemset(r, 0u, BNBYTES_256);
  r[0] = 1u;

  for (dig = 0u; dig < BNDIGITS_256; dig++){
    actBNDIGIT digit = b[dig];
    actU8 bit;

    for (bit = 0u; bit < actBN_BITS_PER_DIGIT; bit++){
      if((digit & 0x1u) == TRUE)
      {
        act25519_mulModP(ws, r, a, r);
      }
      act25519_mulModP(ws, a, a, a);
      digit >>= 1u;

      ifWDisL2(0u == (bit % 2u), watchdog);
    }
  }
}

VSECPRIM_FUNC(void) act25519_invModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actMemCpyWordArray(ws->auxVar.tempE, a, BNDIGITS_256);
  actMemCpyWordArray(ws->auxVar.tempF, ws->prime, BNDIGITS_256);

  ws->auxVar.tempF[0] -= 2u;

  act25519_powModP(ws, r, ws->auxVar.tempE, ws->auxVar.tempF, watchdog);
}

VSECPRIM_FUNC(actU8) act25519_sqrtModP(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 retVal = FALSE;
  actMemCpyWordArray(ws->auxVar.tempG, a, BNDIGITS_256);
  actMemCpyWordArray(ws->auxVar.tempH, prime38, BNDIGITS_256);

  act25519_powModP(ws, ws->auxVar.tempE, ws->auxVar.tempG, ws->auxVar.tempH, watchdog);

  act25519_mulModP(ws, ws->auxVar.tempF, ws->auxVar.tempE, ws->auxVar.tempE);
  if(TRUE == actMemcmp(ws->auxVar.tempF, a, BNBYTES_256)){
    actMemCpyWordArray(r, ws->auxVar.tempE, BNDIGITS_256);

    actL2trigger(watchdog);
    retVal = TRUE;
  }

  if(retVal == FALSE){
    actMemCpyWordArray(ws->auxVar.tempH, sqrtM1, BNDIGITS_256);
    act25519_mulModP(ws, ws->auxVar.tempE, ws->auxVar.tempE, ws->auxVar.tempH);

    act25519_mulModP(ws, ws->auxVar.tempF, ws->auxVar.tempE, ws->auxVar.tempE);
    if(TRUE == actMemcmp(ws->auxVar.tempF, a, BNBYTES_256)){
      actMemCpyWordArray(r, ws->auxVar.tempE, BNDIGITS_256);

      actL2trigger(watchdog);
      retVal = TRUE;
    }
  }

  actL2trigger(watchdog);
  return retVal;
}

VSECPRIM_FUNC(void) act25519_addModQ(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b){
  actBNModAdd(a, b, r, &(ws->qRing), NULL_PTR);
}

VSECPRIM_FUNC(void) act25519_mulModQ(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actBNDIGIT) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) b){
  actBNMult(a, BNDIGITS_256, b, BNDIGITS_256, ws->auxVar.temp1, NULL_PTR);

  act25519_reduceQ(ws, r, ws->auxVar.temp1);
}

VSECPRIM_FUNC(void) act25519_encodePoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actU8) buffer,
  VSECPRIM_P2CONST_PARA(actPoint) point,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actMemCpyWordArray(ws->auxVar.tempA, point->z, BNDIGITS_256);

  act25519_invModP(ws, ws->auxVar.tempA, point->z, watchdog);
  act25519_mulModP(ws, ws->auxVar.tempB, point->x, ws->auxVar.tempA);
  act25519_mulModP(ws, ws->auxVar.tempC, point->y, ws->auxVar.tempA);

  ws->auxVar.tempC[BNDIGITS_256 - 1u] |= ws->auxVar.tempB[0] << (actBN_BITS_PER_DIGIT - 1u);

  actBNStoreLE(buffer, ws->auxVar.tempC, BNDIGITS_256);

  actL2trigger(watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) act25519_decodePoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actPoint) point,
  VSECPRIM_P2CONST_PARA(actU8) buffer,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 x_0;
  actU8 d;
  actBNDIGIT xNOTzero = 0u;
  actRETURNCODE retVal = actOK;

  actBNLoadLE(point->y, buffer, BNBYTES_256);

  x_0 = (actU8)((point->y[BNDIGITS_256 - 1u] >> (actBN_BITS_PER_DIGIT - 1u)) & 0xFFu);

  point->y[BNDIGITS_256 - 1u] &= (actBNDIGIT)MASK_MSBit;

  actMemset(point->z, 0u, sizeof(point->z));
  point->z[0] = 1u;

  act25519_mulModP(ws, ws->auxVar.tempD, point->y, point->y);
  act25519_subModP(ws, ws->auxVar.tempA, ws->auxVar.tempD, point->z);
  actMemCpyWordArray(ws->auxVar.tempC, curveConst, BNDIGITS_256);
  act25519_mulModP(ws, ws->auxVar.tempB, ws->auxVar.tempD, ws->auxVar.tempC);
  act25519_addModP(ws, ws->auxVar.tempB, ws->auxVar.tempB, point->z);
  actL2trigger(watchdog);

  act25519_invModP(ws, ws->auxVar.tempC, ws->auxVar.tempB, watchdog);
  act25519_mulModP(ws, ws->auxVar.tempD, ws->auxVar.tempA, ws->auxVar.tempC);
  if(FALSE == act25519_sqrtModP(ws, point->x, ws->auxVar.tempD, watchdog)){
    retVal = actEXCEPTION_UNKNOWN;
  }
  else{
    for (d = 0u; d < BNDIGITS_256; ++d){
      xNOTzero |= point->x[d];
    }

    if((xNOTzero == 0x0u) && (x_0 == 0x1u)){
      retVal = actEXCEPTION_UNKNOWN;
    }
    else{
      if(x_0 != (point->x[0] & 1u))
      {
        actMemset(ws->auxVar.tempB, 0u, BNBYTES_256);
        act25519_subModP(ws, point->x, ws->auxVar.tempB, point->x);
      }

      act25519_mulModP(ws, point->t, point->x, point->y);
    }
  }

  actL2trigger(watchdog);
  return retVal;
}

VSECPRIM_FUNC(void) act25519_addPoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actPoint) r,
  VSECPRIM_P2CONST_PARA(actPoint) p,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actMemCpyWordArray(ws->auxVar.tempD, cCtimes2, BNDIGITS_256);

  act25519_subModP(ws, ws->auxVar.tempA, r->y, r->x);
  act25519_subModP(ws, ws->auxVar.tempC, p->y, p->x);
  act25519_mulModP(ws, ws->auxVar.tempA, ws->auxVar.tempA, ws->auxVar.tempC);

  act25519_addModP(ws, ws->auxVar.tempB, r->y, r->x);
  act25519_addModP(ws, ws->auxVar.tempC, p->y, p->x);
  act25519_mulModP(ws, ws->auxVar.tempB, ws->auxVar.tempB, ws->auxVar.tempC);

  act25519_mulModP(ws, ws->auxVar.tempC, r->t, ws->auxVar.tempD);
  act25519_mulModP(ws, ws->auxVar.tempC, ws->auxVar.tempC, p->t);

  act25519_mulModP(ws, ws->auxVar.tempD, r->z, p->z);
  act25519_addModP(ws, ws->auxVar.tempD, ws->auxVar.tempD, ws->auxVar.tempD);

  actL2trigger(watchdog);

  act25519_subModP(ws, r->t, ws->auxVar.tempB, ws->auxVar.tempA);

  act25519_subModP(ws, r->z, ws->auxVar.tempD, ws->auxVar.tempC);

  act25519_addModP(ws, ws->auxVar.tempD, ws->auxVar.tempD, ws->auxVar.tempC);

  act25519_addModP(ws, ws->auxVar.tempB, ws->auxVar.tempB, ws->auxVar.tempA);

  act25519_mulModP(ws, r->x, r->t, r->z);

  act25519_mulModP(ws, r->y, ws->auxVar.tempD, ws->auxVar.tempB);

  act25519_mulModP(ws, r->z, r->z, ws->auxVar.tempD);

  act25519_mulModP(ws, r->t, r->t, ws->auxVar.tempB);

  actL2trigger(watchdog);
}

VSECPRIM_FUNC(void) act25519_mulPoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actPoint) r,
  VSECPRIM_P2VAR_PARA(actPoint) p,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) s,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actMemset(r, 0u, sizeof(actPoint));
  r->y[0] = 1u;
  r->z[0] = 1u;

  act25519_mulAddPoint(ws, r, p, s, watchdog);
}

VSECPRIM_FUNC(void) act25519_mulAddPoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actPoint) r,
  VSECPRIM_P2VAR_PARA(actPoint) p,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) s,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 dig;

  for (dig = 0u; dig < BNDIGITS_256; dig++){
    actU8 bit;
    actBNDIGIT digit = s[dig];

    for (bit = 0; bit < actBN_BITS_PER_DIGIT; bit++){
      if((digit & 0x1u) == TRUE)
      {
        act25519_addPoint(ws, r, p, watchdog);
      }
      act25519_addPoint(ws, p, p, watchdog);
      digit >>= 1;
    }
  }
}

VSECPRIM_FUNC(void) act25519_mulBasePoint(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2VAR_PARA(actPoint) r,
  VSECPRIM_P2CONST_PARA(actBNDIGIT) s,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actPoint p;

  actMemCpyByteArray(&p, &basePoint, sizeof(basePoint));
  act25519_mulPoint(ws, r, &p, s, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) act25519_comparePoints(
  VSECPRIM_P2VAR_PARA(actCurve25519ws) ws,
  VSECPRIM_P2CONST_PARA(actPoint) p,
  VSECPRIM_P2CONST_PARA(actPoint) q,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE result = actEXCEPTION_UNKNOWN;

  act25519_mulModP(ws, ws->auxVar.tempA, p->x, q->z);
  act25519_mulModP(ws, ws->auxVar.tempB, q->x, p->z);

  if(TRUE == actMemcmp(ws->auxVar.tempA, ws->auxVar.tempB, BNBYTES_256)){
    act25519_mulModP(ws, ws->auxVar.tempA, p->y, q->z);
    act25519_mulModP(ws, ws->auxVar.tempB, q->y, p->z);

    if(TRUE == actMemcmp(ws->auxVar.tempA, ws->auxVar.tempB, BNBYTES_256)){
      result = actOK;
    }
  }

  actL2trigger(watchdog);
  return result;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

