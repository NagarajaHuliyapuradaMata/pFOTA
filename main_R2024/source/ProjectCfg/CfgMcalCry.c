

#define MCALCRY_CFG_SOURCE

#include "CfgMcalCry.hpp"
#include "McalCry.hpp"
#include "McalCry_Services.hpp"

#include "McalCry_Decrypt.hpp"
#include "McalCry_Hash.hpp"
#include "McalCry_MacVerify.hpp"
#include "McalCry_SignatureVerify.hpp"

#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (MCALCRY_LOCAL)
# define MCALCRY_LOCAL static
#endif

#if !defined (MCALCRY_LOCAL_INLINE)
# define MCALCRY_LOCAL_INLINE LOCAL_INLINE
#endif

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_AesDecryptType, MCALCRY_CONST) McalCry_AesDecrypt[1] = {
  {  &McalCry_UnionWS_McalCry_Aes.primWS.AesDecrypt }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_HmacSha1VerifyType, MCALCRY_CONST) McalCry_HmacSha1Verify[1] = {
  {  &McalCry_UnionWS_McalCry.primWS.HmacSha1Verify }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_KeyType, MCALCRY_CONST) McalCry_Key[7] = {
  {                 2u,                  0u },
  {                 3u,                  2u },
  {                 4u,                  3u },
  {                 6u,                  4u },
  {                 8u,                  6u },
  {                10u,                  8u },
  {                11u,                 10u }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_KeyElementInfoType, MCALCRY_CONST) McalCry_KeyElementInfo[11] = {
  {     16u,   1u,      0x00u, MCALCRY_RA_ALLOWED, MCALCRY_WA_ALLOWED },
  {     16u,   5u,      0x00u, MCALCRY_RA_ALLOWED, MCALCRY_WA_ALLOWED },
  {     16u,   1u,      0x00u, MCALCRY_RA_ALLOWED, MCALCRY_WA_ALLOWED },
  {     32u,   1u,      0x00u, MCALCRY_RA_ALLOWED, MCALCRY_WA_ALLOWED },
  {    128u, 160u,      0x00u, MCALCRY_RA_ALLOWED, MCALCRY_WA_ALLOWED },
  {      4u, 161u,      0x00u, MCALCRY_RA_ALLOWED, MCALCRY_WA_ALLOWED },
  {    256u, 160u,      0x00u, MCALCRY_RA_ALLOWED, MCALCRY_WA_ALLOWED },
  {      4u, 161u,      0x00u, MCALCRY_RA_ALLOWED, MCALCRY_WA_ALLOWED },
  {    384u, 160u,      0x00u, MCALCRY_RA_ALLOWED, MCALCRY_WA_ALLOWED },
  {      4u, 161u,      0x00u, MCALCRY_RA_ALLOWED, MCALCRY_WA_ALLOWED },
  {     20u,   1u,      0x00u, MCALCRY_RA_ALLOWED, MCALCRY_WA_ALLOWED }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_KeyElementsType, MCALCRY_CONST) McalCry_KeyElements[11] = {
  {               20u,                 4u,   1u },
  {               40u,                24u,   5u },
  {               60u,                44u,   1u },
  {               96u,                64u,   1u },
  {              228u,               100u, 160u },
  {              236u,               232u, 161u },
  {              496u,               240u, 160u },
  {              504u,               500u, 161u },
  {              892u,               508u, 160u },
  {              900u,               896u, 161u },
  {              924u,               904u,   1u }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_ObjectInfoType, MCALCRY_CONST) McalCry_ObjectInfo[2] = {
  {  sizeof(McalCry_WS_McalCry_Aes_Type),                                           0u, MCALCRY_NO_HMACSHA1VERIFYIDXOFOBJECTINFO,       0u, MCALCRY_NO_RSAPKCS1VERIFYIDXOFOBJECTINFO, MCALCRY_NO_RSAPSSVERIFYIDXOFOBJECTINFO, MCALCRY_NO_SHA512IDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, MCALCRY_VAR_NOINIT))&McalCry_UnionWS_McalCry_Aes },
  {  sizeof(McalCry_WS_McalCry_Type)    , MCALCRY_NO_AESDECRYPTIDXOFOBJECTINFO,                                               0u,       1u,                                               0u,                                             0u,                                       0u, (P2VAR(uint8, AUTOMATIC, MCALCRY_VAR_NOINIT))&McalCry_UnionWS_McalCry     }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_8BIT

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_ObjectInfoIndType, MCALCRY_CONST) McalCry_ObjectInfoInd[5] = {
               0u,
               1u,
               1u,
               1u,
               1u
};
#define MCALCRY_STOP_SEC_CONST_8BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_PrimitiveFctType, MCALCRY_CONST) McalCry_PrimitiveFct[5] = {
  {                   1u,                    0u, McalCry_Dispatch_AesDecrypt     },
  {                   2u,                    1u, McalCry_Dispatch_SHA512         },
  {                   3u,                    2u, McalCry_Dispatch_HmacSha1Verify },
  {                   4u,                    3u, McalCry_Dispatch_RsaPkcs1Verify },
  {                   5u,                    4u, McalCry_Dispatch_RsaPssVerify   }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_PrimitiveInfoType, MCALCRY_CONST) McalCry_PrimitiveInfo[14] = {
  {  ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                             ,      0x00u,              0u },
  {  ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_MCALCRY_PADDING_PKCS7)),      0x00u,              0u },
  {  ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                ,      0x00u,              0u },
  {  ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                             ,      0x00u,              0u },
  {  ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_MCALCRY_PADDING_PKCS7)),      0x00u,              0u },
  {  ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                ,      0x00u,              0u },
  {  ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                             ,      0x00u,              0u },
  {  ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_MCALCRY_PADDING_PKCS7)),      0x00u,              0u },
  {  ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                ,      0x00u,              0u },
  {  ((((uint32)CRYPTO_HASH) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_512) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                       ,      0x00u,              1u },
  {  ((((uint32)CRYPTO_MACVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA1) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                         ,      0x00u,              2u },
  {  ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_RSA) << 16) | (((uint32)CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA1))          ,      0x00u,              3u },
  {  ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_RSA) << 16) | (((uint32)CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256))      ,      0x00u,              3u },
  {  ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_RSA) << 16) | (((uint32)CRYPTO_ALGOMODE_RSASSA_PSS) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256))             ,      0x00u,              4u }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_PrimitiveServiceInfoType, MCALCRY_CONST) McalCry_PrimitiveServiceInfo[20] = {
  {                                                           10u,                                                             9u },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {                                                           11u,                                                            10u },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {                                                            9u,                                                             0u },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {                                                           14u,                                                            11u },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },
  {  MCALCRY_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, MCALCRY_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_RsaPkcs1VerifyType, MCALCRY_CONST) McalCry_RsaPkcs1Verify[1] = {
  {  &McalCry_UnionWS_McalCry.primWS.RsaPkcs1Verify }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_RsaPssVerifyType, MCALCRY_CONST) McalCry_RsaPssVerify[1] = {
  {  &McalCry_UnionWS_McalCry.primWS.RsaPssVerify }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

CONST(McalCry_SHA512Type, MCALCRY_CONST) McalCry_SHA512[1] = {
  {  &McalCry_UnionWS_McalCry.primWS.SHA512 }
};
#define MCALCRY_STOP_SEC_CONST_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

VAR(McalCry_BufferLengthType, MCALCRY_VAR_NOINIT) McalCry_BufferLength[2];

#define MCALCRY_STOP_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

VAR(McalCry_DriverObjectStateType, MCALCRY_VAR_NOINIT) McalCry_DriverObjectState[2];

#define MCALCRY_STOP_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

VAR(McalCry_KeyLockUType, MCALCRY_VAR_NOINIT) McalCry_KeyLock;

#define MCALCRY_STOP_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

VAR(McalCry_KeyStorageType, MCALCRY_VAR_NOINIT) McalCry_KeyStorage[924];

#define MCALCRY_STOP_SEC_VAR_NOINIT_8BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

VAR(McalCry_LockType, MCALCRY_VAR_NOINIT) McalCry_Lock[2];

#define MCALCRY_STOP_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

VAR(McalCry_QueueUType, MCALCRY_VAR_NOINIT) McalCry_Queue;

#define MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

VAR(McalCry_WS_McalCry_Type, MCALCRY_VAR_NOINIT) McalCry_UnionWS_McalCry;
#define MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

VAR(McalCry_WS_McalCry_Aes_Type, MCALCRY_VAR_NOINIT) McalCry_UnionWS_McalCry_Aes;
#define MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "CompilerCfg_McalCry.hpp"

#define MCALCRY_START_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

VAR(McalCry_WrittenLengthType, MCALCRY_VAR_NOINIT) McalCry_WrittenLength[2];

#define MCALCRY_STOP_SEC_VAR_NOINIT_32BIT

#include "CompilerCfg_McalCry.hpp"

