

#define ACTSHA2_64_SOURCE

#include "actISHA2_64.hpp"
#include "actUtilities.hpp"
#include "actWatchdog.hpp"
#include "actConfig.hpp"

#if(VSECPRIM_ACTSHA2_64_ENABLED == STD_ON)

# define actSHA512_WORD_SIZE                                          (8u)

# if defined(ACT_PLATFORM_UINT64_AVAILABLE)
#  define S0(x)                                                       (actRotr64(x, 28u)^actRotr64(x, 34u)^actRotr64(x, 39u))
#  define S1(x)                                                       (actRotr64(x, 14u)^actRotr64(x, 18u)^actRotr64(x, 41u))
#  define s0(x)                                                       (actRotr64(x, 1u)^actRotr64(x, 8u)^((x)>>7u))
#  define s1(x)                                                       (actRotr64(x, 19u)^actRotr64(x, 61u)^((x)>>6u))

#  define blk0(i)                                                     (W[(i)])
#  define blk2(i)                                                     (W[(i)&15u]+=s1(W[((i)-2u)&15u])+W[((i)-7u)&15u]+s0(W[((i)-15u)&15u]))

#  define Ch(x, y, z)                                                 ((z)^((x)&((y)^(z))))
#  define Maj(x, y, z)                                                (((x)&(y))|((z)&((x)|(y))))

#  define a(i)                                                        (T[(0u-(i)) & 7u])
#  define b(i)                                                        (T[(1u-(i)) & 7u])
#  define c(i)                                                        (T[(2u-(i)) & 7u])
#  define d(i)                                                        (T[(3u-(i)) & 7u])
#  define e(i)                                                        (T[(4u-(i)) & 7u])
#  define f(i)                                                        (T[(5u-(i)) & 7u])
#  define g(i)                                                        (T[(6u-(i)) & 7u])
#  define h(i)                                                        (T[(7u-(i)) & 7u])

#  define Ra(i, j)                                                    if(j > 0u) {blk2(i);} \
                                                                      (h(i) += S1(e(i)) + Ch(e(i), f(i), g(i)) + ((actU64)(actSHA2_64_K[(i) + (j)]) + ((j > 0u) ? W[(i)&15u] : blk0(i))))
#  define Ra0(i, j)                                                   (h(i) += S1(e(i)) + Ch(e(i), f(i), g(i)) + ((actU64)(actSHA2_64_K[(i) + (j)]) +  blk0(i)))
#  define Ra2(i, j)                                                   blk2(i); \
                                                                      (h(i) += S1(e(i)) + Ch(e(i), f(i), g(i)) + ((actU64)(actSHA2_64_K[(i) + (j)]) +  W[(i)&15u]))
#  define Rb(i)                                                       (d(i) += h(i))
#  define Rc(i)                                                       (h(i) += S0(a(i)) + Maj(a(i), b(i), c(i)))
# else
#  define clr_64(tgt)                                                 do { \
                                                                      (tgt)[0] =       \
                                                                      (tgt)[1] = 0;     \
                                                                      } while (0)

#  define cpy_64(tgt, src)                                            do { \
                                                                      (tgt)[0] = (src)[0];   \
                                                                      (tgt)[1] = (src)[1];   \
                                                                      } while (0)

#  define add_64(sum, add)                                            do { \
                                                                      if(((sum)[1] + (add)[1]) < (sum)[1]) \
                                                                       \
                                                                      (sum)[0]++;       \
                                                                      (sum)[1] += (add)[1];   \
                                                                      (sum)[0] += (add)[0];   \
                                                                      } while (0)

#  define xor_64(tgt, val)                                            do { \
                                                                      (tgt)[0] ^= (val)[0];   \
                                                                      (tgt)[1] ^= (val)[1];   \
                                                                      } while (0)

#  define shR_64(tgt, x, n)                                           do { \
                                                                      (tgt)[0] =  ((x)[0] >> (n)); \
                                                                      (tgt)[1] = (((x)[1] >> (n)) | ((x)[0] << (32 - (n)))); \
                                                                      } while (0)

#  define shL_64(tgt, x, n)                                           do { \
                                                                      (tgt)[0] = (((x)[0] << (n)) | ((x)[1] >> (32 - (n)))); \
                                                                      (tgt)[1] =  ((x)[1] << (n)); \
                                                                      } while (0)

#  define rotR_64(tgt, x, n)                                          do { \
                                                                      (tgt)[0] = (((x)[0] >> (n)) | ((x)[1] << (32 - (n)))); \
                                                                      (tgt)[1] = (((x)[1] >> (n)) | ((x)[0] << (32 - (n)))); \
                                                                      } while (0)

#  define rotL_64(tgt, x, n)                                          do { \
                                                                      (tgt)[0] = (((x)[0] << (n)) | ((x)[1] >> (32 - (n)))); \
                                                                      (tgt)[1] = (((x)[1] << (n)) | ((x)[0] >> (32 - (n)))); \
                                                                      } while (0)

#  define xor_rotR(tgt, x, n)                                         do { \
                                                                      (tgt)[0] ^= (((x)[0] >> (n)) | ((x)[1] << (32 - (n)))); \
                                                                      (tgt)[1] ^= (((x)[1] >> (n)) | ((x)[0] << (32 - (n)))); \
                                                                      } while (0)

#  define xor_rotL(tgt, x, n)                                         do { \
                                                                      (tgt)[0] ^= (((x)[0] << (n)) | ((x)[1] >> (32 - (n)))); \
                                                                      (tgt)[1] ^= (((x)[1] << (n)) | ((x)[0] >> (32 - (n)))); \
                                                                      } while (0)

#  define add_Ch(tgt, x, y, z)                                        do { \
                                                                      actU32 tmp [2];         \
                                                                      tmp[0] = ((z)[0] ^ ((x)[0] & ((y)[0] ^ (z)[0]))); \
                                                                      tmp[1] = ((z)[1] ^ ((x)[1] & ((y)[1] ^ (z)[1]))); \
                                                                      add_64 ((tgt), tmp);     \
                                                                      } while (0)

#  define add_Maj(tgt, x, y, z)                                       do { \
                                                                      actU32 tmp [2];         \
                                                                      tmp[0] = (((x)[0] & (y)[0]) | ((z)[0] & ((x)[0] | (y)[0]))); \
                                                                      tmp[1] = (((x)[1] & (y)[1]) | ((z)[1] & ((x)[1] | (y)[1]))); \
                                                                      add_64 ((tgt), tmp);     \
                                                                      } while (0)

#  define add_S0(tgt, x)                                              do { \
                                                                      actU32 tmp [2];       \
                                                                      rotR_64  (tmp, (x), 28); \
                                                                      xor_rotL (tmp, (x), 30);  \
                                                                      xor_rotL (tmp, (x), 25);  \
                                                                      add_64   ((tgt), tmp);   \
                                                                      } while (0)

#  define add_S1(tgt, x)                                              do { \
                                                                      actU32 tmp [2];       \
                                                                      rotR_64  (tmp, (x), 14); \
                                                                      xor_rotR (tmp, (x), 18); \
                                                                      xor_rotL (tmp, (x), 23);  \
                                                                      add_64   ((tgt), tmp);   \
                                                                      } while (0)

#  define add_s0(tgt, x)                                              do { \
                                                                      actU32 tmp [2];       \
                                                                      shR_64   (tmp, (x),  7); \
                                                                      xor_rotR (tmp, (x),  1); \
                                                                      xor_rotR (tmp, (x),  8); \
                                                                      add_64   ((tgt), tmp);   \
                                                                      } while (0)

#  define add_s1(tgt, x)                                              do { \
                                                                      actU32 tmp [2];       \
                                                                      shR_64   (tmp, (x),  6); \
                                                                      xor_rotR (tmp, (x), 19); \
                                                                      xor_rotL (tmp, (x),  3);  \
                                                                      add_64   ((tgt), tmp);   \
                                                                      } while (0)
# endif

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

# if defined(ACT_PLATFORM_UINT64_AVAILABLE)
VSECPRIM_ROM(VSECPRIM_LOCAL, actU64) actSHA2_64_K[80] =
{
    0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL, 0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL,
    0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL, 0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL,
    0xd807aa98a3030242ULL, 0x12835b0145706fbeULL, 0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
    0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL, 0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
    0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL, 0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
    0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL, 0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
    0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL, 0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL,
    0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL, 0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
    0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL, 0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
    0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL, 0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
    0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL, 0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL,
    0xd192e819d6ef5218ULL, 0xd69906245565a910ULL, 0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
    0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL, 0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL,
    0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL, 0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
    0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL, 0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
    0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL, 0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
    0xca273eceea26619cULL, 0xd186b8c721c0c207ULL, 0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL,
    0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL, 0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
    0x28db77f523047d84ULL, 0x32caab7b40c72493ULL, 0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL,
    0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL, 0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL
};
# else
VSECPRIM_ROM(VSECPRIM_LOCAL, actU32) actSHA2_64_K[160] =
{
    0x428a2f98UL, 0xd728ae22UL, 0x71374491UL, 0x23ef65cdUL, 0xb5c0fbcfUL, 0xec4d3b2fUL, 0xe9b5dba5UL, 0x8189dbbcUL,
    0x3956c25bUL, 0xf348b538UL, 0x59f111f1UL, 0xb605d019UL, 0x923f82a4UL, 0xaf194f9bUL, 0xab1c5ed5UL, 0xda6d8118UL,
    0xd807aa98UL, 0xa3030242UL, 0x12835b01UL, 0x45706fbeUL, 0x243185beUL, 0x4ee4b28cUL, 0x550c7dc3UL, 0xd5ffb4e2UL,
    0x72be5d74UL, 0xf27b896fUL, 0x80deb1feUL, 0x3b1696b1UL, 0x9bdc06a7UL, 0x25c71235UL, 0xc19bf174UL, 0xcf692694UL,
    0xe49b69c1UL, 0x9ef14ad2UL, 0xefbe4786UL, 0x384f25e3UL, 0x0fc19dc6UL, 0x8b8cd5b5UL, 0x240ca1ccUL, 0x77ac9c65UL,
    0x2de92c6fUL, 0x592b0275UL, 0x4a7484aaUL, 0x6ea6e483UL, 0x5cb0a9dcUL, 0xbd41fbd4UL, 0x76f988daUL, 0x831153b5UL,
    0x983e5152UL, 0xee66dfabUL, 0xa831c66dUL, 0x2db43210UL, 0xb00327c8UL, 0x98fb213fUL, 0xbf597fc7UL, 0xbeef0ee4UL,
    0xc6e00bf3UL, 0x3da88fc2UL, 0xd5a79147UL, 0x930aa725UL, 0x06ca6351UL, 0xe003826fUL, 0x14292967UL, 0x0a0e6e70UL,
    0x27b70a85UL, 0x46d22ffcUL, 0x2e1b2138UL, 0x5c26c926UL, 0x4d2c6dfcUL, 0x5ac42aedUL, 0x53380d13UL, 0x9d95b3dfUL,
    0x650a7354UL, 0x8baf63deUL, 0x766a0abbUL, 0x3c77b2a8UL, 0x81c2c92eUL, 0x47edaee6UL, 0x92722c85UL, 0x1482353bUL,
    0xa2bfe8a1UL, 0x4cf10364UL, 0xa81a664bUL, 0xbc423001UL, 0xc24b8b70UL, 0xd0f89791UL, 0xc76c51a3UL, 0x0654be30UL,
    0xd192e819UL, 0xd6ef5218UL, 0xd6990624UL, 0x5565a910UL, 0xf40e3585UL, 0x5771202aUL, 0x106aa070UL, 0x32bbd1b8UL,
    0x19a4c116UL, 0xb8d2d0c8UL, 0x1e376c08UL, 0x5141ab53UL, 0x2748774cUL, 0xdf8eeb99UL, 0x34b0bcb5UL, 0xe19b48a8UL,
    0x391c0cb3UL, 0xc5c95a63UL, 0x4ed8aa4aUL, 0xe3418acbUL, 0x5b9cca4fUL, 0x7763e373UL, 0x682e6ff3UL, 0xd6b2b8a3UL,
    0x748f82eeUL, 0x5defb2fcUL, 0x78a5636fUL, 0x43172f60UL, 0x84c87814UL, 0xa1f0ab72UL, 0x8cc70208UL, 0x1a6439ecUL,
    0x90befffaUL, 0x23631e28UL, 0xa4506cebUL, 0xde82bde9UL, 0xbef9a3f7UL, 0xb2c67915UL, 0xc67178f2UL, 0xe372532bUL,
    0xca273eceUL, 0xea26619cUL, 0xd186b8c7UL, 0x21c0c207UL, 0xeada7dd6UL, 0xcde0eb1eUL, 0xf57d4f7fUL, 0xee6ed178UL,
    0x06f067aaUL, 0x72176fbaUL, 0x0a637dc5UL, 0xa2c898a6UL, 0x113f9804UL, 0xbef90daeUL, 0x1b710b35UL, 0x131c471bUL,
    0x28db77f5UL, 0x23047d84UL, 0x32caab7bUL, 0x40c72493UL, 0x3c9ebe0aUL, 0x15c9bebcUL, 0x431d67c4UL, 0x9c100d4cUL,
    0x4cc5d4beUL, 0xcb3e42b6UL, 0x597f299cUL, 0xfc657e2aUL, 0x5fcb6fabUL, 0x3ad6faecUL, 0x6c44198cUL, 0x4a475817UL
};
# endif

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "CompilerCfg_vSecPrim.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"
# ifndef ACT_PLATFORM_UINT64_AVAILABLE

VSECPRIM_LOCAL_FUNC(void) actSHA2_64_sha512Round(
  VSECPRIM_P2CONST_PARA(actU32) a,
  VSECPRIM_P2CONST_PARA(actU32) b,
  VSECPRIM_P2CONST_PARA(actU32) c,
  VSECPRIM_P2VAR_PARA(actU32) d,
  VSECPRIM_P2CONST_PARA(actU32) e,
  VSECPRIM_P2CONST_PARA(actU32) f,
  VSECPRIM_P2CONST_PARA(actU32) g,
  VSECPRIM_P2VAR_PARA(actU32) h,
  actU8 t,
  VSECPRIM_P2VAR_PARA(actU32) W);
# endif

# if defined(ACT_PLATFORM_UINT64_AVAILABLE)
VSECPRIM_LOCAL_FUNC(void) actSHA2_64_Transform(
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU64) H,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));
# else
VSECPRIM_LOCAL_FUNC(void) actSHA2_64_Transform (
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU32) H,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));
# endif

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_64_Update(
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_64_Finalize(
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifndef ACT_PLATFORM_UINT64_AVAILABLE

VSECPRIM_LOCAL_FUNC(void) actSHA2_64_sha512Round (
  VSECPRIM_P2CONST_PARA(actU32) a,
  VSECPRIM_P2CONST_PARA(actU32) b,
  VSECPRIM_P2CONST_PARA(actU32) c,
  VSECPRIM_P2VAR_PARA(actU32) d,
  VSECPRIM_P2CONST_PARA(actU32) e,
  VSECPRIM_P2CONST_PARA(actU32) f,
  VSECPRIM_P2CONST_PARA(actU32) g,
  VSECPRIM_P2VAR_PARA(actU32) h,
  actU8 t,
  VSECPRIM_P2VAR_PARA(actU32) W){
  if(t >= 16u){
    actU32 *w = &(W [(t *2u) & 0x1Eu]);

    add_s1 (w, &(W [((t - 2u) * 2u) &0x1Eu]));
    add_64 (w, &(W [((t - 7u) * 2u) &0x1Eu]));
    add_s0 (w, &(W [((t - 15u) * 2u) &0x1Eu]));
  }

  add_S1  (h, e);
  add_Ch  (h, e, f, g);
  add_64  (h, &(actSHA2_64_K [(t * 2u)]));
  add_64  (h, &(W [(t * 2u) & 0x1Eu]));

  add_64  (d, h);

  add_S0  (h, a);
  add_Maj (h, a, b, c);
}
# endif

# ifdef ACT_PLATFORM_UINT64_AVAILABLE
VSECPRIM_LOCAL_FUNC(void) actSHA2_64_Transform(
  VSECPRIM_P2CONST_PARA(actU8) in,
  VSECPRIM_P2VAR_PARA(actU64) H,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU64 W[16];
  actU64 T[8];
  actU8 i, j;

  for (i = 0u; i < 8u; ++i){
    T[i] = H[i];
  }

  actL3trigger(watchdog);

  actCpyBEtoU64(W, in, actHASH_BLOCK_SIZE_SHA512);

  actL2trigger(watchdog);

  for (j = 0u; j < 80u; j += 16u){
#  if(actSHA512_SPEED_UP > 0)

    if(j == 0u) {
      Ra0(0u, j); Rb(0u); Rc(0u); Ra0(1u, j); Rb(1u); Rc(1u);
      Ra0(2u, j); Rb(2u); Rc(2u); Ra0(3u, j); Rb(3u); Rc(3u);
      Ra0(4u, j); Rb(4u); Rc(4u); Ra0(5u, j); Rb(5u); Rc(5u);
      Ra0(6u, j); Rb(6u); Rc(6u); Ra0(7u, j); Rb(7u); Rc(7u);
      Ra0(8u, j); Rb(8u); Rc(8u); Ra0(9u, j); Rb(9u); Rc(9u);
      Ra0(10u, j); Rb(10u); Rc(10u); Ra0(11u, j); Rb(11u); Rc(11u);
      Ra0(12u, j); Rb(12u); Rc(12u); Ra0(13u, j); Rb(13u); Rc(13u);
      Ra0(14u, j); Rb(14u); Rc(14u); Ra0(15u, j); Rb(15u); Rc(15u);
      actL3trigger(watchdog);
    }
    else{
      Ra2(0u, j); Rb(0u); Rc(0u); Ra2(1u, j); Rb(1u); Rc(1u);
      Ra2(2u, j); Rb(2u); Rc(2u); Ra2(3u, j); Rb(3u); Rc(3u);
      Ra2(4u, j); Rb(4u); Rc(4u); Ra2(5u, j); Rb(5u); Rc(5u);
      Ra2(6u, j); Rb(6u); Rc(6u); Ra2(7u, j); Rb(7u); Rc(7u);
      Ra2(8u, j); Rb(8u); Rc(8u); Ra2(9u, j); Rb(9u); Rc(9u);
      Ra2(10u, j); Rb(10u); Rc(10u); Ra2(11u, j); Rb(11u); Rc(11u);
      Ra2(12u, j); Rb(12u); Rc(12u); Ra2(13u, j); Rb(13u); Rc(13u);
      Ra2(14u, j); Rb(14u); Rc(14u); Ra2(15u, j); Rb(15u); Rc(15u);
      actL3trigger(watchdog);
    }
#  else
    if(j == 0u) {
      for (i = 0u; i < 16u; ++i)
      {
        Ra0(i, j);
        Rb(i);
        Rc(i);
        actL3trigger(watchdog);
      }
    }
    else{
      for (i = 0u; i < 16u; ++i)
      {
        Ra2(i, j);
        Rb(i);
        Rc(i);
        actL3trigger(watchdog);
      }
    }
#  endif
    actL2trigger(watchdog);
  }

  actL1trigger(watchdog);

  for (i = 0u; i < 8u; ++i){
    H[i] += T[i];
  }
}
# else
VSECPRIM_LOCAL_FUNC(void) actSHA2_64_Transform (
   VSECPRIM_P2CONST_PARA(actU8) in,
   VSECPRIM_P2VAR_PARA(actU32) H,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU32 W [32];
  actU32 T [16];
  actU8 t, i;

  for (i = 0u; i < 16u; ++i) {
    T [i] = H [i];
  }

  actL3trigger(watchdog);

  actCpyBEtoU32 (W, in, actHASH_BLOCK_SIZE_SHA512);

  actL2trigger(watchdog);

  for (t = 0u; t < 80u; t += 8u) {
#  if(actSHA512_SPEED_UP > 0)

    actSHA2_64_sha512Round(&T[ 0], &T[ 2], &T[ 4], &T[ 6], &T[ 8], &T[10], &T[12], &T[14], t + 0u, W);
    actSHA2_64_sha512Round(&T[14], &T[ 0], &T[ 2], &T[ 4], &T[ 6], &T[ 8], &T[10], &T[12], t + 1u, W);
    actSHA2_64_sha512Round(&T[12], &T[14], &T[ 0], &T[ 2], &T[ 4], &T[ 6], &T[ 8], &T[10], t + 2u, W);
    actSHA2_64_sha512Round(&T[10], &T[12], &T[14], &T[ 0], &T[ 2], &T[ 4], &T[ 6], &T[ 8], t + 3u, W);
    actSHA2_64_sha512Round(&T[ 8], &T[10], &T[12], &T[14], &T[ 0], &T[ 2], &T[ 4], &T[ 6], t + 4u, W);
    actSHA2_64_sha512Round(&T[ 6], &T[ 8], &T[10], &T[12], &T[14], &T[ 0], &T[ 2], &T[ 4], t + 5u, W);
    actSHA2_64_sha512Round(&T[ 4], &T[ 6], &T[ 8], &T[10], &T[12], &T[14], &T[ 0], &T[ 2], t + 6u, W);
    actSHA2_64_sha512Round(&T[ 2], &T[ 4], &T[ 6], &T[ 8], &T[10], &T[12], &T[14], &T[ 0], t + 7u, W);
    actL3trigger(watchdog);
#  else
    for (i = 0u; i < 8u; ++i){
      actU32 tmp [2];

      actSHA2_64_sha512Round(&T[ 0], &T[ 2], &T[ 4], &T[ 6], &T[ 8], &T[10], &T[12], &T[14], t + i, W);

      cpy_64 (tmp, &T[14]);
      cpy_64 (&T[14], &T[12]);
      cpy_64 (&T[12], &T[10]);
      cpy_64 (&T[10], &T[ 8]);
      cpy_64 (&T[ 8], &T[ 6]);
      cpy_64 (&T[ 6], &T[ 4]);
      cpy_64 (&T[ 4], &T[ 2]);
      cpy_64 (&T[ 2], &T[ 0]);
      cpy_64 (&T[ 0],  tmp);
      actL3trigger(watchdog);
    }
#  endif
  actL2trigger(watchdog);
  }

  actL1trigger(watchdog);

  for (i = 0u; i <= (16u - 2u); i += 2u) {
    add_64 (&H [i], &T [i]);
  }
}
# endif

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_64_Update(
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
# if defined(ACT_PLATFORM_UINT64_AVAILABLE)
   VSECPRIM_P2VAR_PARA(actU64) Hptr = info->H;
# else
   VSECPRIM_P2VAR_PARA(actU32) Hptr = info->H;
# endif
  VSECPRIM_P2VAR_PARA(actU8) bufferPtr = info->buffer;
  actRETURNCODE retVal = actOK;
  actLengthType diff = 0u;
  actLengthType blocks;
  actLengthType bcount;

  actL1trigger(watchdog);

# if defined(ACT_PLATFORM_UINT64_AVAILABLE)
  if((info->count_L + (actU64) length) < info->count_L){
    info->count_H++;
    if((info->count_H) == ((actU64)1u << 61)){
      retVal = actEXCEPTION_LENGTH;
    }
  }
  info->count_L += (actU64)length;
# else
  if((info->count_L + (actU32)length) < info->count_L){
    ++info->count_2;
    if(info->count_2 == 0u){
      ++info->count_3;
      if(info->count_3 == 0u)
      {
        ++info->count_H;
        if((info->count_H) == ((actU32) 1u << 29))
        {
          retVal = actEXCEPTION_LENGTH;
        }
      }
    }
  }
  info->count_L += (actU32)length;
# endif
  if(retVal == actOK){
    actU8 finished = FALSE;

    if(info->buffer_used > 0u){
      diff = (actLengthType)actMin(length, (actHASH_BLOCK_SIZE_SHA512 - info->buffer_used));
      actMemCpyByteArray(&bufferPtr[info->buffer_used], dataIN, diff);
      info->buffer_used += (actU16)(diff & 0xFFu);
      if(info->buffer_used < actHASH_BLOCK_SIZE_SHA512)
      {
        finished = TRUE;
      }
      else
      {
        actSHA2_64_Transform(bufferPtr, Hptr, watchdog);
      }
    }

    if(finished == FALSE){
      blocks = (actLengthType)((length - diff) / actHASH_BLOCK_SIZE_SHA512);

      for (bcount = diff; bcount < (diff + (blocks*actHASH_BLOCK_SIZE_SHA512)); bcount += actHASH_BLOCK_SIZE_SHA512)
      {
        actSHA2_64_Transform(&dataIN[bcount], Hptr, watchdog);
      }

      diff += (actHASH_BLOCK_SIZE_SHA512 * blocks);
      info->buffer_used = (actLengthType)(length - diff);
      actMemCpyByteArray(bufferPtr, &dataIN[diff], info->buffer_used);

      actL1trigger(watchdog);
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSHA2_64_Finalize(
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actLengthType len = (actLengthType)(info->count_L & 0x7Fu);
  const actLengthType pad_len = (actLengthType)(actHASH_BLOCK_SIZE_SHA512 - (2u * actSHA512_WORD_SIZE));
  VSECPRIM_P2VAR_PARA(actU8) tempBuffer = (VSECPRIM_P2VAR_PARA(actU8))info->buffer;
# ifdef ACT_PLATFORM_UINT64_AVAILABLE
  actU64 count_Lptr = info->count_L << 3;
  actU64 count_Hptr = (info->count_H << 3) | (info->count_L >> 61);
  VSECPRIM_P2VAR_PARA(actU64) digest = info->H;
# else
  actU32 count[4];
  VSECPRIM_P2VAR_PARA(actU32) digest = info->H;
  count[3] = info->count_L << 3;
  count[2] = ((info->count_2 << 3) | (info->count_L >> 29));
  count[1] = ((info->count_3 << 3) | (info->count_2 >> 29));
  count[0] = ((info->count_H << 3) | (info->count_3 >> 29));
# endif

  actL1trigger(watchdog);

  tempBuffer[len] = 0x80u;
  len = len + 1u;

  actMemset(&tempBuffer[len], 0u, (actLengthType)(actHASH_BLOCK_SIZE_SHA512 - len));
  if(len > pad_len){
    actSHA2_64_Transform((VSECPRIM_P2CONST_PARA(actU8))tempBuffer, digest, watchdog);
    actMemset(tempBuffer, 0u, (actLengthType)pad_len);
  }

# ifdef ACT_PLATFORM_UINT64_AVAILABLE
  actU64toBE(&tempBuffer[pad_len], count_Hptr);
  actU64toBE(&tempBuffer[pad_len + actSHA512_WORD_SIZE], count_Lptr);
# else
  actU32toBE(&tempBuffer[112], count[0]);
  actU32toBE(&tempBuffer[116], count[1]);
  actU32toBE(&tempBuffer[120], count[2]);
  actU32toBE(&tempBuffer[124], count[3]);
# endif

  actSHA2_64_Transform((VSECPRIM_P2CONST_PARA(actU8))tempBuffer, digest, watchdog);

# ifdef ACT_PLATFORM_UINT64_AVAILABLE
  actCpyU64toBE((VSECPRIM_P2VAR_PARA(actU8))digest, digest, actHASH_SIZE_SHA512 /actSHA512_WORD_SIZE);
# else
  actCpyU32toBE((VSECPRIM_P2VAR_PARA(actU8))digest, digest, 16u);
# endif

  actMemCpyByteArray(hash, (VSECPRIM_P2CONST_PARA(actU8))(&digest[0]), info->result_length);

  actMemset((VSECPRIM_P2VAR_PARA(actU8))&info->buffer[0], 0u, actHASH_BLOCK_SIZE_SHA512);

  actL1trigger(watchdog);

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actSHA512_224Init(VSECPRIM_P2VAR_PARA(actSHA512_224STRUCT) info){
# if defined (ACT_PLATFORM_UINT64_AVAILABLE)
  info->H[0] = 0x8C3D37C819544DA2ULL;
  info->H[1] = 0x73E1996689DCD4D6ULL;
  info->H[2] = 0x1DFAB7AE32FF9C82ULL;
  info->H[3] = 0x679DD514582F9FCFULL;
  info->H[4] = 0x0F6D2B697BD44DA8ULL;
  info->H[5] = 0x77E36F7304C48942ULL;
  info->H[6] = 0x3F9D85A86A1D36C8ULL;
  info->H[7] = 0x1112E6AD91D692A1ULL;
# else
  info->H[0] = 0x8C3D37C8UL;
  info->H[1] = 0x19544DA2UL;
  info->H[2] = 0x73E19966UL;
  info->H[3] = 0x89DCD4D6UL;
  info->H[4] = 0x1DFAB7AEUL;
  info->H[5] = 0x32FF9C82UL;
  info->H[6] = 0x679DD514UL;
  info->H[7] = 0x582F9FCFUL;
  info->H[8] = 0x0F6D2B69UL;
  info->H[9] = 0x7BD44DA8UL;
  info->H[10] = 0x77E36F73UL;
  info->H[11] = 0x04C48942UL;
  info->H[12] = 0x3F9D85A8UL;
  info->H[13] = 0x6A1D36C8UL;
  info->H[14] = 0x1112E6ADUL;
  info->H[15] = 0x91D692A1UL;
# endif

  info->count_L = 0u;
# ifndef ACT_PLATFORM_UINT64_AVAILABLE
  info->count_2 = 0u;
  info->count_3 = 0u;
# endif
  info->count_H = 0u;
  info->buffer_used = 0u;
  info->result_length = actHASH_SIZE_SHA512_224;

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actSHA512_224Update(
  VSECPRIM_P2VAR_PARA(actSHA512_224STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog) (void)){
  return actSHA2_64_Update((VSECPRIM_P2VAR_PARA(actSHA512STRUCT)) info, dataIN, length, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA512_224Finalize(
  VSECPRIM_P2VAR_PARA(actSHA512_224STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHA2_64_Finalize((VSECPRIM_P2VAR_PARA(actSHA512STRUCT)) info, hash, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA512_256Init(VSECPRIM_P2VAR_PARA(actSHA512_256STRUCT) info){
# if defined (ACT_PLATFORM_UINT64_AVAILABLE)
  info->H[0] = 0x22312194FC2BF72CULL;
  info->H[1] = 0x9F555FA3C84C64C2ULL;
  info->H[2] = 0x2393B86B6F53B151ULL;
  info->H[3] = 0x963877195940EABDULL;
  info->H[4] = 0x96283EE2A88EFFE3ULL;
  info->H[5] = 0xBE5E1E2553863992ULL;
  info->H[6] = 0x2B0199FC2C85B8AAULL;
  info->H[7] = 0x0EB72DDC81C52CA2ULL;
# else
  info->H[0] = 0x22312194UL;
  info->H[1] = 0xFC2BF72CUL;
  info->H[2] = 0x9F555FA3UL;
  info->H[3] = 0xC84C64C2UL;
  info->H[4] = 0x2393B86BUL;
  info->H[5] = 0x6F53B151UL;
  info->H[6] = 0x96387719UL;
  info->H[7] = 0x5940EABDUL;
  info->H[8] = 0x96283EE2UL;
  info->H[9] = 0xA88EFFE3UL;
  info->H[10] = 0xBE5E1E25UL;
  info->H[11] = 0x53863992UL;
  info->H[12] = 0x2B0199FCUL;
  info->H[13] = 0x2C85B8AAUL;
  info->H[14] = 0x0EB72DDCUL;
  info->H[15] = 0x81C52CA2UL;
# endif

  info->count_L = 0u;
# ifndef ACT_PLATFORM_UINT64_AVAILABLE
  info->count_2 = 0u;
  info->count_3 = 0u;
# endif
  info->count_H = 0u;
  info->buffer_used = 0u;
  info->result_length = actHASH_SIZE_SHA512_256;

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actSHA512_256Update(
  VSECPRIM_P2VAR_PARA(actSHA512_256STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHA2_64_Update((VSECPRIM_P2VAR_PARA(actSHA512STRUCT)) info, dataIN, length, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA512_256Finalize(
  VSECPRIM_P2VAR_PARA(actSHA512_256STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHA2_64_Finalize((VSECPRIM_P2VAR_PARA(actSHA512STRUCT)) info, hash, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA384Init(VSECPRIM_P2VAR_PARA(actSHA384STRUCT) info){
# if defined (ACT_PLATFORM_UINT64_AVAILABLE)
  info->H[0] = 0xcbbb9d5dc1059ed8ULL;
  info->H[1] = 0x629a292a367cd507ULL;
  info->H[2] = 0x9159015a3070dd17ULL;
  info->H[3] = 0x152fecd8f70e5939ULL;
  info->H[4] = 0x67332667ffc00b31ULL;
  info->H[5] = 0x8eb44a8768581511ULL;
  info->H[6] = 0xdb0c2e0d64f98fa7ULL;
  info->H[7] = 0x47b5481dbefa4fa4ULL;
# else
  info->H[0] = 0xcbbb9d5dUL;
  info->H[1] = 0xc1059ed8UL;
  info->H[2] = 0x629a292aUL;
  info->H[3] = 0x367cd507UL;
  info->H[4] = 0x9159015aUL;
  info->H[5] = 0x3070dd17UL;
  info->H[6] = 0x152fecd8UL;
  info->H[7] = 0xf70e5939UL;
  info->H[8] = 0x67332667UL;
  info->H[9] = 0xffc00b31UL;
  info->H[10] = 0x8eb44a87UL;
  info->H[11] = 0x68581511UL;
  info->H[12] = 0xdb0c2e0dUL;
  info->H[13] = 0x64f98fa7UL;
  info->H[14] = 0x47b5481dUL;
  info->H[15] = 0xbefa4fa4UL;
# endif

  info->count_L = 0u;
# ifndef ACT_PLATFORM_UINT64_AVAILABLE
  info->count_2 = 0u;
  info->count_3 = 0u;
# endif
  info->count_H = 0u;
  info->buffer_used = 0u;
  info->result_length = actHASH_SIZE_SHA384;

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actSHA384Update(
  VSECPRIM_P2VAR_PARA(actSHA384STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHA2_64_Update((VSECPRIM_P2VAR_PARA(actSHA512STRUCT)) info, dataIN, length, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA384Finalize(
  VSECPRIM_P2VAR_PARA(actSHA384STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHA2_64_Finalize((VSECPRIM_P2VAR_PARA(actSHA512STRUCT)) info, hash, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA512Init(VSECPRIM_P2VAR_PARA(actSHA512STRUCT) info){
# if defined (ACT_PLATFORM_UINT64_AVAILABLE)
  info->H[0] = 0x6a09e667f3bcc908ULL;
  info->H[1] = 0xbb67ae8584caa73bULL;
  info->H[2] = 0x3c6ef372fe94f82bULL;
  info->H[3] = 0xa54ff53a5f1d36f1ULL;
  info->H[4] = 0x510e527fade682d1ULL;
  info->H[5] = 0x9b05688c2b3e6c1fULL;
  info->H[6] = 0x1f83d9abfb41bd6bULL;
  info->H[7] = 0x5be0cd19137e2179ULL;
# else
  info->H[0] = 0x6a09e667UL;
  info->H[1] = 0xf3bcc908UL;
  info->H[2] = 0xbb67ae85UL;
  info->H[3] = 0x84caa73bUL;
  info->H[4] = 0x3c6ef372UL;
  info->H[5] = 0xfe94f82bUL;
  info->H[6] = 0xa54ff53aUL;
  info->H[7] = 0x5f1d36f1UL;
  info->H[8] = 0x510e527fUL;
  info->H[9] = 0xade682d1UL;
  info->H[10] = 0x9b05688cUL;
  info->H[11] = 0x2b3e6c1fUL;
  info->H[12] = 0x1f83d9abUL;
  info->H[13] = 0xfb41bd6bUL;
  info->H[14] = 0x5be0cd19UL;
  info->H[15] = 0x137e2179UL;
# endif

  info->count_L       = 0u;
# ifndef ACT_PLATFORM_UINT64_AVAILABLE
  info->count_2       = 0u;
  info->count_3       = 0u;
# endif
  info->count_H       = 0u;
  info->buffer_used   = 0u;
  info->result_length = actHASH_SIZE_SHA512;

  return actOK;
}

VSECPRIM_FUNC(actRETURNCODE) actSHA512Update(
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHA2_64_Update((VSECPRIM_P2VAR_PARA(actSHA512STRUCT)) info, dataIN, length, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSHA512Finalize(
  VSECPRIM_P2VAR_PARA(actSHA512STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  return actSHA2_64_Finalize((VSECPRIM_P2VAR_PARA(actSHA512STRUCT)) info, hash, watchdog);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

