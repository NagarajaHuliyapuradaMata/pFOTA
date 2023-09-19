

#define ACTED25519CORE_SOURCE

#include "actEd25519core.hpp"
#include "actWatchdog.hpp"
#include "actUtilities.hpp"
#include "actISHA2_64.hpp"
#include "actEd25519.hpp"
#include "act25519util.hpp"

#if(VSECPRIM_ACTED25519CORE_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actEd25519_initCore(VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws){
  act25519_initCore((VSECPRIM_P2VAR_PARA(actCurve25519ws))&ws->coreWS);
}

VSECPRIM_FUNC(void) actEd25519_sign(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2VAR_PARA(actU8) signature
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actCurve25519ws) coreWSptr = (VSECPRIM_P2VAR_PARA(actCurve25519ws)) &ws->coreWS;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) (coreWSptr->auxVar.tempA));
  VSECPRIM_P2VAR_PARA(actBNDIGIT) k = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) (coreWSptr->auxVar.tempB));
  VSECPRIM_P2VAR_PARA(actBNDIGIT) s = ((VSECPRIM_P2VAR_PARA(actBNDIGIT)) (coreWSptr->auxVar.tempC));
  VSECPRIM_P2VAR_PARA(actPoint) rB = ((VSECPRIM_P2VAR_PARA(actPoint))&(ws->shaWs.point_rB));
  VSECPRIM_P2VAR_PARA(actU8) hash = ((VSECPRIM_P2VAR_PARA(actU8))(coreWSptr->auxVar.tempA));

  actBNDIGIT r[BNDIGITS_256];

  (void)act25519_hashPM(ws, hash, watchdog);
  actBNLoadLE(coreWSptr->auxVar.temp1, hash, actHASH_SIZE_SHA512);
  act25519_reduceQ(coreWSptr, r, coreWSptr->auxVar.temp1);

  act25519_mulBasePoint(coreWSptr, rB, r, watchdog);
  act25519_encodePoint(coreWSptr, signature, rB, watchdog);

  (void)act25519_hashRAM(ws, signature, ws->hashBuf.hashValue, watchdog);

  actBNLoadLE(coreWSptr->auxVar.temp1, ws->hashBuf.hashValue, actHASH_SIZE_SHA512);
  act25519_reduceQ(coreWSptr, k, coreWSptr->auxVar.temp1);

  actBNLoadLE(a, ws->privateKey, 32u);
  act25519_mulModQ(coreWSptr, s, k, a);
  act25519_addModQ(coreWSptr, s, r, s);

  actBNStoreLE(&signature[32], s, BNDIGITS_256);

  actL2trigger(watchdog);

  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempA, 0u, sizeof(coreWSptr->auxVar.tempA));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempB, 0u, sizeof(coreWSptr->auxVar.tempB));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempC, 0u, sizeof(coreWSptr->auxVar.tempC));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.temp1, 0u, sizeof(coreWSptr->auxVar.temp1));
}

VSECPRIM_FUNC(actRETURNCODE) actEd25519_verify(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) signature
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actCurve25519ws) coreWSptr = (VSECPRIM_P2VAR_PARA(actCurve25519ws)) &ws->coreWS;

  VSECPRIM_P2VAR_PARA(actPoint) A = ((VSECPRIM_P2VAR_PARA(actPoint))&(ws->shaWs.point_A));
  VSECPRIM_P2VAR_PARA(actPoint) sB = ((VSECPRIM_P2VAR_PARA(actPoint))&(ws->shaWs.point_sB));
  VSECPRIM_P2VAR_PARA(actBNDIGIT) s = ((VSECPRIM_P2VAR_PARA(actBNDIGIT))&(ws->hashBuf.bnDigit_s));
  VSECPRIM_P2VAR_PARA(actBNDIGIT) k = ((VSECPRIM_P2VAR_PARA(actBNDIGIT))&(ws->hashBuf.bnDigit_k));
  actPoint R;
  actRETURNCODE result = actVERIFICATION_FAILED;

  (void)act25519_hashRAM(ws, signature, ws->hashBuf.hashValue, watchdog);

  if(actOK == act25519_decodePoint(coreWSptr, A, ws->pubKeyBuf.publicKey, watchdog)){
    if(actOK == act25519_decodePoint(coreWSptr, &R, signature, watchdog)){
      actBNLoadLE(coreWSptr->auxVar.temp1, ws->hashBuf.hashValue, actHASH_SIZE_SHA512);
      act25519_reduceQ(coreWSptr, k, coreWSptr->auxVar.temp1);
      act25519_mulAddPoint(coreWSptr, &R, A, k, watchdog);

      actBNLoadLE(s, &signature[32], 32);
      act25519_mulBasePoint(coreWSptr, sB, s, watchdog);

      if(act25519_comparePoints(coreWSptr, sB, &R, watchdog) == actOK)
      {
        result = actOK;
      }
      else
      {
        result = actVERIFICATION_FAILED;
      }
    }
  }

  actL3trigger(watchdog);
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempA, 0u, sizeof(coreWSptr->auxVar.tempA));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempB, 0u, sizeof(coreWSptr->auxVar.tempB));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempC, 0u, sizeof(coreWSptr->auxVar.tempC));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempD, 0u, sizeof(coreWSptr->auxVar.tempD));
  actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.temp1, 0u, sizeof(coreWSptr->auxVar.temp1));

  return result;
}

VSECPRIM_FUNC(void)actEd25519_importKeyPair(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) secretKey
   ,  VSECPRIM_P2CONST_PARA(actU8) publicKey
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  if(NULL_PTR != secretKey){
    (void)actSHA512Init(&(ws->shaWs.sha512));
    (void)actSHA512Update(&(ws->shaWs.sha512), secretKey, actEd25519_KEY_SIZE, watchdog);
    (void)actSHA512Finalize(&(ws->shaWs.sha512), ws->privateKey, watchdog);

    ws->privateKey[0] &= 0xF8u;
    ws->privateKey[31] &= 0x7Fu;
    ws->privateKey[31] |= 0x40u;
  }

  if(NULL_PTR != publicKey){
    actMemCpyByteArray(ws->pubKeyBuf.publicKey, publicKey, actEd25519_KEY_SIZE);
  }
  else{
    VSECPRIM_P2VAR_PARA(actCurve25519ws) coreWSptr = (VSECPRIM_P2VAR_PARA(actCurve25519ws)) &ws->coreWS;
    VSECPRIM_P2VAR_PARA(actPoint) A = ((VSECPRIM_P2VAR_PARA(actPoint))&(ws->shaWs.point_A));
    VSECPRIM_P2VAR_PARA(actBNDIGIT) a = ((VSECPRIM_P2VAR_PARA(actBNDIGIT))&(ws->pubKeyBuf.bnDigit_a));

    actBNLoadLE(a, ws->privateKey, actEd25519_KEY_SIZE);
    act25519_mulBasePoint(coreWSptr, A, a, watchdog);
    act25519_encodePoint(coreWSptr, ws->pubKeyBuf.publicKey, A, watchdog);

    actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempA, 0u, sizeof(coreWSptr->auxVar.tempA));
    actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempB, 0u, sizeof(coreWSptr->auxVar.tempB));
    actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempC, 0u, sizeof(coreWSptr->auxVar.tempC));
    actMemset((VSECPRIM_P2VAR_PARA(actU8))coreWSptr->auxVar.tempD, 0u, sizeof(coreWSptr->auxVar.tempD));
  }
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

