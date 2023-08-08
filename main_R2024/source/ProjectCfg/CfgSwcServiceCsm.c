

#define CSM_CFG_SOURCE

#include "CfgSwcServiceCsm.hpp"
#include "EcuabCryIf.hpp"

#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CSM_LOCAL)
# define CSM_LOCAL static
#endif

#if !defined (CSM_LOCAL_INLINE)
# define CSM_LOCAL_INLINE LOCAL_INLINE
#endif

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo[5] = {
   {0u, 0u} ,
   {1u, 0u} ,
   {2u, 0u} ,
   {3u, 0u} ,
   {4u, 0u}
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[5] = {
   {0u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Decrypt_Aes128, CRYPTO_PROCESSING_SYNC, FALSE}    ,
   {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_HashDummy, CRYPTO_PROCESSING_SYNC, FALSE}         ,
   {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Rsa3072, CRYPTO_PROCESSING_SYNC, FALSE} ,
   {0u, &Csm_PrimitiveInfo[3], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Rsa2048, CRYPTO_PROCESSING_SYNC, FALSE} ,
   {0u, &Csm_PrimitiveInfo[1], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_ClassC, CRYPTO_PROCESSING_SYNC, FALSE}
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[5] = {
  {           0u,       0u,          0u },
  {           1u,       0u,          1u },
  {           6u,       0u,          1u },
  {           5u,       0u,          1u },
  {           2u,       0u,          1u }
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Csm_KeyType, CSM_CONST) Csm_Key[7] = {
  {  CryIfConf_CryIfKey_CryIfKey_Fbl_Decrypt_Aes128    },
  {  CryIfConf_CryIfKey_CryIfKey_Fbl_HashDummy         },
  {  CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_ClassC  },
  {  CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Ed25519 },
  {  CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Rsa1024 },
  {  CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Rsa2048 },
  {  CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Rsa3072 }
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[5] = {
   {0u, CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CBC, CRYPTO_ALGOFAM_CUSTOM_PADDING_PKCS7}}       ,
   {0u, CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_SHA1, 16u, CRYPTO_ALGOMODE_HMAC, CRYPTO_ALGOFAM_NOT_SET}}                ,
   {0u, CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_RSA, 32u, CRYPTO_ALGOMODE_RSASSA_PSS, CRYPTO_ALGOFAM_SHA2_256}}    ,
   {0u, CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_RSA, 32u, CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5, CRYPTO_ALGOFAM_SHA1}} ,
   {64u, CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA2_512, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[2] = {
  {  CryIfConf_CryIfChannel_CryIfChannel_CryptoCv_Fbl_Aes      ,              1u,      0x07u,          2u },
  {  CryIfConf_CryIfChannel_CryIfChannel_CryptoCv_Fbl_Signature,              0u,      0x07u,          1u }
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(Crypto_JobType, CSM_VAR_NOINIT) Csm_Job[2];

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_VAR_NOINIT_8BIT

#include "MemMap.hpp"

VAR(Csm_JobStateType, CSM_VAR_NOINIT) Csm_JobState[5];

#define CSM_STOP_SEC_VAR_NOINIT_8BIT

#include "MemMap.hpp"

#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(Csm_SizeOfJobType, CSM_VAR_NOINIT) Csm_JobToObjMap[5];

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(Csm_QueueUType, CSM_VAR_NOINIT) Csm_Queue;

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

VAR(Csm_QueueStateType, CSM_VAR_NOINIT) Csm_QueueState[2];

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.hpp"

