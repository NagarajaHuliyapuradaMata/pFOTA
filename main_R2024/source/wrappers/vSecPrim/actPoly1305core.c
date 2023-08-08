

#define ACTPOLY1305CORE_SOURCE

#include "actIPoly1305.hpp"
#include "actPoly1305core.hpp"
#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"

#if(VSECPRIM_ACTPOLY1305_ENABLED == STD_ON)

# if(8 == actBN_BITS_PER_DIGIT)
#  define DIGITs(value)                                               ((actBNDIGIT) ((value) >>  0)), \
                                                                      ((actBNDIGIT) ((value) >>  8)), \
                                                                      ((actBNDIGIT) ((value) >> 16)), \
                                                                      ((actBNDIGIT) ((value) >> 24))
#  define actLEtoBigNum                                               actMemCpyByteArray
#  define actBigNumtoLE                                               actMemCpyByteArray
# elif(16 == actBN_BITS_PER_DIGIT)
#  define DIGITs(value)                                               ((actBNDIGIT) ((value) >>  0)), \
                                                                      ((actBNDIGIT) ((value) >> 16))
#  define actLEtoBigNum                                               actCpyLEtoU16
#  define actBigNumtoLE                                               actCpyU16toLE
# elif(32 == actBN_BITS_PER_DIGIT)
#  define DIGITs(value)                                               (value)
#  define actLEtoBigNum                                               actCpyLEtoU32
#  define actBigNumtoLE                                               actCpyU32toLE
# endif

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM( VSECPRIM_LOCAL, actBNDIGIT ) clamp [BNDIGITS_128] = {
  DIGITs (0x0FFFFFFFUL), DIGITs (0x0FFFFFFCUL), DIGITs (0x0FFFFFFCUL), DIGITs (0x0FFFFFFCUL)
};

VSECPRIM_ROM( VSECPRIM_LOCAL, actBNDIGIT ) p [BNDIGITS_130] = {
  DIGITs (0xFFFFFFFBUL), DIGITs (0xFFFFFFFFUL), DIGITs (0xFFFFFFFFUL), DIGITs (0xFFFFFFFFUL), 0x03
};

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actPoly1305_init(VSECPRIM_P2VAR_PARA(actPoly1305Context) context, VSECPRIM_P2CONST_PARA(actU8) key){
  VSECPRIM_P2VAR_PARA(poly1305context) ctx = (poly1305context *)context->opaque;

  actLengthType i;

  actLEtoBigNum(ctx->r, &(key[0]), BNBYTES_128);
  actLEtoBigNum(ctx->s, &(key[BNBYTES_128]), BNBYTES_128);

  for (i = 0; i < BNDIGITS_128; i++){
    ctx->r[i] &= clamp[i];
  }

  for (i = 0; i < BNDIGITS_130; i++){
    ctx->p[i] = p[i];
  }

  actMemset((actU8 *)ctx->a, 0, sizeof(ctx->a));
}

VSECPRIM_FUNC(void) actPoly1305_block(VSECPRIM_P2VAR_PARA(actPoly1305Context) context, VSECPRIM_P2CONST_PARA(actU8) data, const actU8 pad, VSECPRIM_P2FUNC( VSECPRIM_NONE, void, watchdog)(void)) {
  VSECPRIM_P2VAR_PARA(poly1305context) ctx = (poly1305context *)context->opaque;

  actLEtoBigNum(ctx->d, data, BNBYTES_128);
  ctx->d[BNDIGITS_128] = pad;

  (void)actBNAdd(ctx->a, ctx->d, ctx->a, BNDIGITS_130);

  actBNMult(ctx->a, BNDIGITS_130, ctx->r, BNDIGITS_128, ctx->tmp, watchdog);

  (void)actBNReduce(ctx->tmp, BNDIGITS_130 + BNDIGITS_128, ctx->p, BNDIGITS_130, ctx->a, watchdog);
}

VSECPRIM_FUNC(void) actPoly1305_finish(VSECPRIM_P2VAR_PARA(actPoly1305Context) context, VSECPRIM_P2VAR_PARA(actU8) tag) {
  VSECPRIM_P2VAR_PARA(poly1305context) ctx = (poly1305context *)context->opaque;

  (void)actBNAdd(ctx->a, ctx->s, ctx->a, BNDIGITS_128);

  actBigNumtoLE(tag, ctx->a, BNDIGITS_128);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

