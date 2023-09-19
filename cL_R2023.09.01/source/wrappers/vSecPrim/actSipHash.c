

#define ACTSIPHASH_SOURCE

#include "actISipHash.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTSIPHASH_ENABLED == STD_ON)

#ifndef ACT_PLATFORM_UINT64_AVAILABLE
#error SipHahs is only running on platforms supporting uint64. Make sure platforms supports it or disable SipHash
#endif

#define SIP_HASH_CONST_1                                             (0x736f6d6570736575uLL)
#define SIP_HASH_CONST_2                                             (0x646f72616e646f6duLL)
#define SIP_HASH_CONST_3                                             (0x6c7967656e657261uLL)
#define SIP_HASH_CONST_4                                             (0x7465646279746573uLL)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(void) actSipHashBlockUpdate(
  VSECPRIM_P2VAR_PARA(actSipHashSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actU8 rounds);

VSECPRIM_LOCAL_FUNC(void) actSipHashRound(
  VSECPRIM_P2VAR_PARA(actU64) pv0
   ,  VSECPRIM_P2VAR_PARA(actU64) pv1
   ,  VSECPRIM_P2VAR_PARA(actU64) pv2
   ,  VSECPRIM_P2VAR_PARA(actU64) pv3
   ,  actU8 rounds);

VSECPRIM_LOCAL_FUNC(void) actSipHashBlockUpdate(
  VSECPRIM_P2VAR_PARA(actSipHashSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN
   ,  actU8 rounds){
  actU64 m;

  m = actU8toU64(dataIN);
  info->v3 ^= m;

  actSipHashRound(&info->v0, &info->v1, &info->v2, &info->v3, rounds);

  info->v0 ^= m;
}

VSECPRIM_LOCAL_FUNC(void) actSipHashRound(
  VSECPRIM_P2VAR_PARA(actU64) pv0
   ,  VSECPRIM_P2VAR_PARA(actU64) pv1
   ,  VSECPRIM_P2VAR_PARA(actU64) pv2
   ,  VSECPRIM_P2VAR_PARA(actU64) pv3
   ,  actU8 rounds){
  actU8 i;

  for(i = 0; i < rounds; i++){
    *pv0 += *pv1;
    *pv1 = actRotl64(*pv1, 13);
    *pv1 ^= *pv0;
    *pv0 = actRotl64(*pv0, 32);
    *pv2 += *pv3;
    *pv3 = actRotl64(*pv3, 16);
    *pv3 ^= *pv2;
    *pv0 += *pv3;
    *pv3 = actRotl64(*pv3, 21);
    *pv3 ^= *pv0;
    *pv2 += *pv1;
    *pv1 = actRotl64(*pv1, 17);
    *pv1 ^= *pv2;
    *pv2 = actRotl64(*pv2, 32);
  }
}

VSECPRIM_FUNC(actRETURNCODE) actSipHashInit(
  VSECPRIM_P2VAR_PARA(actSipHashSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) key
   ,  actLengthType key_length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog) (void)){
  actRETURNCODE result;
  actU64 k[2];

  if(key == NULL_PTR){
    result = actEXCEPTION_NULL;
  }
  else if(key_length != 16u){
    result = actEXCEPTION_LENGTH;
  }
  else{
    k[0] = actU8toU64(key);
    k[1] = actU8toU64(&key[8]);

    actL2trigger(watchdog);

    info->v0 = SIP_HASH_CONST_1 ^ k[0];
    info->v1 = SIP_HASH_CONST_2 ^ k[1];
    info->v2 = SIP_HASH_CONST_3 ^ k[0];
    info->v3 = SIP_HASH_CONST_4 ^ k[1];

    actMemset(info->buffer, 0u, actSIPHASH_BLOCK_SIZE);
    info->buffer_used = 0u;
    info->length = 0u;

    result = actOK;
  }
  return result;
}

VSECPRIM_FUNC(actRETURNCODE) actSipHashUpdate(
  VSECPRIM_P2VAR_PARA(actSipHashSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE result = actEXCEPTION_UNKNOWN;
  actLengthType diff = 0u;
  actLengthType lastBlockEnd;
  actLengthType bcount;

  if(dataIN == NULL_PTR){
    result = actEXCEPTION_NULL;
  }
  else{
    info->length = info->length + (length % 256u);

    if(info->buffer_used > 0u){
      diff = actMin((actLengthType)length, (actLengthType)actSIPHASH_BLOCK_SIZE - info->buffer_used);

      actMemCpyByteArray((VSECPRIM_P2VAR_PARA(void))&info->buffer[info->buffer_used], (VSECPRIM_P2CONST_PARA(void)) dataIN, diff);
      info->buffer_used += (actU8) diff;

      if(info->buffer_used < actSIPHASH_BLOCK_SIZE)
      {
        result = actOK;
      }
      else
      {
        actSipHashBlockUpdate(info, info->buffer, ACT_SIPHASH_CROUNDS);
        actL2trigger(watchdog);
        info->buffer_used = 0u;
      }
    }

    if(result != actOK){
      lastBlockEnd = (actLengthType)((length - diff) / actSIPHASH_BLOCK_SIZE);
      lastBlockEnd = (actSIPHASH_BLOCK_SIZE * lastBlockEnd) + diff;

      for(bcount = diff; bcount < lastBlockEnd; bcount += actSIPHASH_BLOCK_SIZE)
      {
        actL1trigger(watchdog);
        actSipHashBlockUpdate(info, &dataIN[bcount], ACT_SIPHASH_CROUNDS);
      }

      info->buffer_used = (actU8)(length - lastBlockEnd);
      actMemCpyByteArray((VSECPRIM_P2VAR_PARA(void)) info->buffer, (VSECPRIM_P2CONST_PARA(void)) &dataIN[lastBlockEnd], info->buffer_used);
      result = actOK;
    }
  }
  return result;
}

VSECPRIM_FUNC(actRETURNCODE) actSipHashFinalize(
  VSECPRIM_P2VAR_PARA(actSipHashSTRUCT) info
   ,  VSECPRIM_P2VAR_PARA(actU64) mac
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 i;

  for(i = info->buffer_used; i < actSIPHASH_BLOCK_SIZE; i++){
    info->buffer[i] = 0u;
  }

  info->buffer[actSIPHASH_BLOCK_SIZE - 1u] = (actU8)info->length;

  actSipHashBlockUpdate(info, info->buffer, ACT_SIPHASH_CROUNDS);
  info->buffer_used = 0u;
  actL2trigger(watchdog);

  info->v2 ^= 0xFFuLL;

  actSipHashRound(&info->v0, &info->v1, &info->v2, &info->v3, ACT_SIPHASH_DROUNDS);
  actL1trigger(watchdog);

  *mac = info->v0 ^ info->v1 ^ info->v2 ^ info->v3;

  return actOK;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

