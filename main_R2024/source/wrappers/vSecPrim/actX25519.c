

#define ACTX25519_SOURCE

#include "actUtilities.hpp"
#include "actExternRandom.hpp"
#include "actConfig.hpp"
#include "actWatchdog.hpp"
#include "actX25519core.hpp"

#if(VSECPRIM_ACTX25519_ENABLED == STD_ON)

# define x25519_initCore(ws)                                          actX25519_initCore (ws)
# define x25519_exchangeKeys(ws, wd)                                  actX25519_eval ((ws), (wd))

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actX25519Init(VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws){
  x25519_initCore(ws);

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actX25519GenKeyPair(
  VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws,
  VSECPRIM_P2VAR_PARA(actU8) publicKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actGetExternRandom(ws->privateKey, actX25519_KEY_SIZE);

  if(retVal != actOK){
    actMemset(ws->privateKey, 0u, actX25519_KEY_SIZE);
    retVal = actEXCEPTION_PRIVKEY;
  }
  else{
    ws->privateKey[0] &= 0xF8u;
    ws->privateKey[31] &= 0x7Fu;
    ws->privateKey[31] |= 0x40u;

    actMemset(ws->basePointBuf.uCoord, 0, actX25519_KEY_SIZE);
    ws->basePointBuf.uCoord[0] = 9u;
    (void)x25519_exchangeKeys(ws, watchdog);

    actMemCpyByteArray(publicKey, ws->basePointBuf.uCoord, actX25519_KEY_SIZE);
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actX25519ImportPrivateKey(
  VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) privateKey,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actMemCpyByteArray(ws->privateKey, privateKey, actX25519_KEY_SIZE);
  ws->privateKey[0] &= 0xF8u;
  ws->privateKey[31] &= 0x7Fu;
  ws->privateKey[31] |= 0x40u;
  actL1trigger(watchdog);
  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actX25519GenSecret(
  VSECPRIM_P2VAR_PARA(actX25519STRUCT) ws,
  VSECPRIM_P2CONST_PARA(actU8) publicKey,
  VSECPRIM_P2VAR_PARA(actU8) sharedSecret,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actMemCpyByteArray(ws->basePointBuf.uCoord, publicKey, actX25519_KEY_SIZE);
  (void)x25519_exchangeKeys(ws, watchdog);

  actMemCpyByteArray(sharedSecret, ws->basePointBuf.uCoord, actX25519_KEY_SIZE);
  return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

