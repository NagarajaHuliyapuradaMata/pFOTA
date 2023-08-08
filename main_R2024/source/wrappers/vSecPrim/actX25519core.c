

#define ACTX25519CORE_SOURCE

#include "actX25519core.hpp"
#include "actWatchdog.hpp"
#include "actUtilities.hpp"
#include "actBigNum.hpp"

#if(VSECPRIM_ACTX25519CORE_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, actBNDIGIT) a24[BNDIGITS_256] =
{
  DIGITs(0x0001DB41uL), DIGITs(0x00000000uL), DIGITs(0x00000000uL), DIGITs(0x00000000uL),
  DIGITs(0x00000000uL), DIGITs(0x00000000uL), DIGITs(0x00000000uL), DIGITs(0x00000000uL)
};

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actX25519_cswap(actU32 swap, VSECPRIM_P2VAR_PARA(actBNDIGIT) a, VSECPRIM_P2VAR_PARA(actBNDIGIT) b);

VSECPRIM_LOCAL_FUNC(void) actX25519_cswap(actU32 swap, VSECPRIM_P2VAR_PARA(actBNDIGIT) a, VSECPRIM_P2VAR_PARA(actBNDIGIT) b){
  actBNDIGIT mask = (actBNDIGIT)(0u - swap);
  actBNDIGIT digit;
  actU8 d;

  for (d = 0; d < BNDIGITS_256; d++){
    digit = mask & (a[d] ^ b[d]);
    a[d] ^= digit;
    b[d] ^= digit;
  }
}

VSECPRIM_FUNC(void) actX25519_initCore(VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws){
  act25519_initCore((VSECPRIM_P2VAR_PARA(actCurve25519ws)) &ws->coreWS);
}

VSECPRIM_FUNC(actRETURNCODE) actX25519_eval(
  VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actCurve25519ws) coreWSptr = (VSECPRIM_P2VAR_PARA(actCurve25519ws)) &ws->coreWS;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) x_1 = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) ws->basePointBuf.bnDigit_x_1);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) x_2 = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempA);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) z_2 = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempB);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) x_3 = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempC);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) z_3 = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempD);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) A   = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempE);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) B   = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempF);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) C   = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempG);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) D   = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) coreWSptr->auxVar.tempH);
  VSECPRIM_P2VAR_PARA(actBNDIGIT) AA = A;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) BB = B;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) CB = C;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) DA = D;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) E = x_3;

  actU32 k_t;
  actU32 swap;
  actU8 i;

  actBNLoadLE(x_1, ws->basePointBuf.uCoord, BNBYTES_256);
  x_1[BNDIGITS_256 - 1u] &= (actBNDIGIT)MASK_MSBit;
  actMemset(x_2, 0u, BNBYTES_256);
  *x_2 = 1;
  actMemset(z_2, 0u, BNBYTES_256);
  actMemCpyWordArray(x_3, x_1, BNDIGITS_256);
  actMemCpyWordArray(z_3, x_2, BNDIGITS_256);

  swap = 0u;
  for (i = 255u; i > 0u; i--){
    k_t = ((actU32)ws->privateKey[(i - 1u) / 8u] >> ((i - 1u) & 0x07u)) & 0x01u;

    swap ^= k_t;
    actX25519_cswap(swap, x_2, x_3);
    actX25519_cswap(swap, z_2, z_3);
    swap = k_t;

    act25519_addModP(coreWSptr, A, x_2, z_2);
    act25519_subModP(coreWSptr, B, x_2, z_2);
    act25519_addModP(coreWSptr, C, x_3, z_3);
    act25519_subModP(coreWSptr, D, x_3, z_3);
    act25519_mulModP(coreWSptr, DA, D, A);
    act25519_mulModP(coreWSptr, CB, C, B);
    act25519_mulModP(coreWSptr, BB, B, B);
    act25519_mulModP(coreWSptr, AA, A, A);
    act25519_subModP(coreWSptr, E, AA, BB);

    act25519_mulModP(coreWSptr, x_2, AA, BB);

    actL2trigger(watchdog);

    actMemCpyWordArray(BB, a24, BNDIGITS_256);
    act25519_mulModP(coreWSptr, z_2, BB, E);
    act25519_addModP(coreWSptr, z_2, AA, z_2);
    act25519_mulModP(coreWSptr, z_2, E, z_2);

    act25519_addModP(coreWSptr, x_3, DA, CB);
    act25519_mulModP(coreWSptr, x_3, x_3, x_3);

    act25519_subModP(coreWSptr, z_3, DA, CB);
    act25519_mulModP(coreWSptr, z_3, z_3, z_3);
    act25519_mulModP(coreWSptr, z_3, z_3, x_1);

    actL2trigger(watchdog);
  }

  actX25519_cswap(swap, x_2, x_3);
  actX25519_cswap(swap, z_2, z_3);

  act25519_invModP(coreWSptr, z_3, z_2, watchdog);
  act25519_mulModP(coreWSptr, x_2, x_2, z_3);
  actBNStoreLE(ws->basePointBuf.uCoord, x_2, BNDIGITS_256);

  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempA, 0u, sizeof(coreWSptr->auxVar.tempA));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempB, 0u, sizeof(coreWSptr->auxVar.tempB));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempC, 0u, sizeof(coreWSptr->auxVar.tempC));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempD, 0u, sizeof(coreWSptr->auxVar.tempD));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempE, 0u, sizeof(coreWSptr->auxVar.tempE));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempF, 0u, sizeof(coreWSptr->auxVar.tempF));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempG, 0u, sizeof(coreWSptr->auxVar.tempG));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempH, 0u, sizeof(coreWSptr->auxVar.tempH));

  return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

