

#ifndef ACTPOLY1305CORE_H
#define ACTPOLY1305CORE_H

#include "actIPoly1305.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

#define BNBYTES_128                                                  ((128u + (8u -1u)) /8u)
#define BNBYTES_129                                                  ((129u + (8u -1u)) /8u)
#define BNBYTES_130                                                  ((130u + (8u -1u)) /8u)
#define BNDIGITS_128                                                 ((BNBYTES_128 + (actBN_BYTES_PER_DIGIT -1u)) /actBN_BYTES_PER_DIGIT)
#define BNDIGITS_129                                                 ((BNBYTES_129 + (actBN_BYTES_PER_DIGIT -1u)) /actBN_BYTES_PER_DIGIT)
#define BNDIGITS_130                                                 ((BNBYTES_130 + (actBN_BYTES_PER_DIGIT -1u)) /actBN_BYTES_PER_DIGIT)

typedef struct{
  actBNDIGIT r[BNDIGITS_128];
  actBNDIGIT s[BNDIGITS_128];

  actBNDIGIT a[BNDIGITS_130 + 1u];
  actBNDIGIT p[BNDIGITS_130];
  actBNDIGIT d[BNDIGITS_129];
  actBNDIGIT tmp[BNDIGITS_130 +
    BNDIGITS_128 + 1u];
}poly1305context;

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actPoly1305_init(VSECPRIM_P2VAR_PARA(actPoly1305Context) context, VSECPRIM_P2CONST_PARA(actU8) key);

VSECPRIM_FUNC(void) actPoly1305_block(VSECPRIM_P2VAR_PARA(actPoly1305Context) context, VSECPRIM_P2CONST_PARA(actU8) data, const actU8 pad, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(void) actPoly1305_finish(VSECPRIM_P2VAR_PARA( actPoly1305Context ) context, VSECPRIM_P2VAR_PARA( actU8 ) tag);

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#ifdef __cplusplus
}
#endif

#endif

