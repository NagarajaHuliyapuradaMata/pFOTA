

#define ACTED25519_SOURCE

#include "actUtilities.hpp"
#include "actExternRandom.hpp"
#include "actConfig.hpp"
#include "actWatchdog.hpp"
#include "actEd25519core.hpp"
#include "actEd25519.hpp"

#if(VSECPRIM_ACTED25519_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CONST_UNSPECIFIED
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, actU8) dom2[] = { "SigEd25519 no Ed25519 collisions" };
VSECPRIM_ROM(VSECPRIM_LOCAL, actU8) dom2len = 32u;

#define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
#include "CompilerCfg_vSecPrim.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) act25519_dom2(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actEd25519ImportMessage(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) message
   ,  const actLengthType msgLen
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) act25519_dom2(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  if(ws->instance != actEd25519pure){
    VSECPRIM_P2VAR_PARA(actSHA512STRUCT) sha512WsPtr = &(ws->shaWs.sha512);
    actU8 ph_len[2] = {0u, 0u};

    if(actEd25519ph == ws->instance){
      ph_len[0] = 1u;
    }

    if(ws->context != NULL_PTR){
      ph_len[1] = (actU8)(ws->ctxLen & 0xFFu);
    }

    (void)actSHA512Update(sha512WsPtr, dom2, dom2len, watchdog);
    (void)actSHA512Update(sha512WsPtr, ph_len, 2, watchdog);

    if((ws->context != NULL_PTR) && (ws->ctxLen != 0u)){
      (void)actSHA512Update(sha512WsPtr, ws->context, ws->ctxLen, watchdog);
    }
  }
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actEd25519ImportMessage(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) message
   ,  const actLengthType msgLen
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;

  if(actEd25519ph == ws->instance){
    if(actOK != (actSHA512Update(&(ws->shaWs.sha512), message, msgLen, watchdog))){
      retVal = actEXCEPTION_UNKNOWN;
    }
    else{
      if(actOK != (actSHA512Finalize(&(ws->shaWs.sha512), ws->hashBuf.hashValue, watchdog)))
      {
        retVal = actEXCEPTION_UNKNOWN;
      }
      else
      {
        ws->message = ws->hashBuf.hashValue;
        ws->msgLen = actHASH_SIZE_SHA512;
      }
    }
  }
  else{
    ws->message = message;
    ws->msgLen = msgLen;
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) act25519_hashPM(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) sha512WsPtr = &(ws->shaWs.sha512);

  (void)actSHA512Init(sha512WsPtr);

  act25519_dom2(ws, watchdog);

  (void)actSHA512Update(sha512WsPtr, &ws->privateKey[32], 32, watchdog);
  (void)actSHA512Update(sha512WsPtr, ws->message, ws->msgLen, watchdog);
  (void)actSHA512Finalize(sha512WsPtr, hash, watchdog);

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) act25519_hashRAM(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) R
   ,  VSECPRIM_P2VAR_PARA(actU8) hash
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) sha512WsPtr = &(ws->shaWs.sha512);

  (void)actSHA512Init(sha512WsPtr);
  act25519_dom2(ws, watchdog);

  (void)actSHA512Update(sha512WsPtr, R, 32, watchdog);
  (void)actSHA512Update(sha512WsPtr, ws->pubKeyBuf.publicKey, 32, watchdog);
  (void)actSHA512Update(sha512WsPtr, ws->message, ws->msgLen, watchdog);
  (void)actSHA512Finalize(sha512WsPtr, hash, watchdog);

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actEd25519Init(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  const actU8 instance
   ,  VSECPRIM_P2CONST_PARA(actU8) context
   ,  const actLengthType ctxLen){
  ws->instance = instance;

  if(actEd25519ph == instance){
    (void)actSHA512Init(&(ws->shaWs.sha512));
  }

  actEd25519_initCore(ws);
  ws->context = context;
  ws->ctxLen = ctxLen;

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actEd25519Update(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) message
   ,  const actLengthType msgLen
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actEXCEPTION_ALGOID;

  if(actEd25519ph != ws->instance){
  }
  else{
    retVal = actSHA512Update(&(ws->shaWs.sha512), message, msgLen, watchdog);
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actEd25519Sign(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) message
   ,  const actLengthType msgLen
   ,  VSECPRIM_P2CONST_PARA(actU8) secretKey
   ,  VSECPRIM_P2CONST_PARA(actU8) publicKey
   ,  VSECPRIM_P2VAR_PARA(actU8) signature
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actEd25519ImportMessage(ws, message, msgLen, watchdog);

  if(retVal == actOK){
    actEd25519_importKeyPair(ws, secretKey, publicKey, watchdog);

    actEd25519_sign(ws, signature, watchdog);

    actMemset(ws->privateKey, 0u, sizeof(ws->privateKey));
    actMemset(ws->pubKeyBuf.publicKey, 0u, sizeof(ws->pubKeyBuf.publicKey));

    actL1trigger(watchdog);
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actEd25519Verify(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2CONST_PARA(actU8) message
   ,  const actLengthType msgLen
   ,  VSECPRIM_P2CONST_PARA(actU8) publicKey
   ,  VSECPRIM_P2CONST_PARA(actU8) signature
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actEd25519ImportMessage(ws, message, msgLen, watchdog);

  if(retVal == actOK){
    actEd25519_importKeyPair(ws, NULL_PTR, publicKey, watchdog);

    retVal = actEd25519_verify(ws, signature, watchdog);

    actMemset(ws->pubKeyBuf.publicKey, 0u, sizeof(ws->pubKeyBuf.publicKey));

    actL1trigger(watchdog);
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actEd25519GenKeyPair(
  VSECPRIM_P2VAR_PARA(actEd25519STRUCT) ws
   ,  VSECPRIM_P2VAR_PARA(actU8) secretKey
   ,  VSECPRIM_P2VAR_PARA(actU8) publicKey
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actGetExternRandom(secretKey, actEd25519_KEY_SIZE);

  if(retVal != actOK){
    actMemset(secretKey, 0u, actEd25519_KEY_SIZE);
    retVal = actEXCEPTION_PRIVKEY;
  }
  else{
    actEd25519_importKeyPair(ws, secretKey, NULL_PTR, watchdog);

    actMemCpyByteArray(publicKey, ws->pubKeyBuf.publicKey, actEd25519_KEY_SIZE);

    actMemset(ws->privateKey, 0u, sizeof(ws->privateKey));
    actMemset(ws->pubKeyBuf.publicKey, 0u, sizeof(ws->pubKeyBuf.publicKey));

    actL1trigger(watchdog);
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

