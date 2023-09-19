#define CRYIF_CFG_SOURCE

#include "CfgEcuabCryIf.hpp"
#include "EcuabCryIf.hpp"
#include "McalCry.hpp"

#if !defined (STATIC)
#define STATIC static
#endif

#if !defined (CRYIF_LOCAL)
#define CRYIF_LOCAL static
#endif

#if !defined (CRYIF_LOCAL_INLINE)
#define CRYIF_LOCAL_INLINE LOCAL_INLINE
#endif

#define CRYIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CryIf_ChannelType, CRYIF_CONST) CryIf_Channel[2] = {
  {  CryptoConf_CryptoDriverObject_McalCry_Aes,                 0u, 0u }
   ,  {  CryptoConf_CryptoDriverObject_McalCry    ,                 0u, 1u }
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CRYIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CryIf_CryptoFunctionsType, CRYIF_CONST) CryIf_CryptoFunctions[1] = {
  {                           TRUE, McalCry_CancelJob, McalCry_CertificateParse, McalCry_CertificateVerify, McalCry_KeyCopy, McalCry_KeyDerive, McalCry_KeyElementCopy, McalCry_KeyElementCopyPartial, McalCry_KeyElementGet, McalCry_KeyElementIdsGet, McalCry_KeyElementSet, McalCry_KeyExchangeCalcPubVal, McalCry_KeyExchangeCalcSecret, McalCry_KeyGenerate, McalCry_KeyValidSet, McalCry_ProcessJob, McalCry_RandomSeed }
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CRYIF_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(CryIf_KeyType, CRYIF_CONST) CryIf_Key[7] = {
  {  CryptoConf_CryptoKey_CryptoKey_Fbl_Decrypt_Aes128   ,                 0u }
   ,  {  CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Class_C,                 0u }
   ,  {  CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Ed25519,                 0u }
   ,  {  CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Rsa1024,                 0u }
   ,  {  CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Rsa2048,                 0u }
   ,  {  CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Rsa3072,                 0u }
   ,  {  CryptoConf_CryptoKey_CryptoKey_Fbl_HashDummy        ,                 0u }
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

