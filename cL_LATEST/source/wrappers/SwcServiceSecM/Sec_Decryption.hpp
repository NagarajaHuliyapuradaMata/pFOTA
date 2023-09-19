

#ifndef SEC_DECRYPTION_H
#define SEC_DECRYPTION_H

#include "Sec_Inc.hpp"

#define SEC_DECRYPTION_MODE_DEFAULT                0x00u

#define SEC_DECRYPTION_MODE_IV                     0x01u

#define SEC_DECRYPTION_MODE_INIT                   0x10u

#define SEC_DECRYPTION_MODE_FINALIZE               0x20u

#define SEC_DECRYPTION_MODE_AES_128_PKCS_CBC      SEC_DECRYPTION_MODE_DEFAULT

#define SEC_DECRYPTION_MODE_AES_128_PKCS_CBC_IV   (SEC_DECRYPTION_MODE_DEFAULT | SEC_DECRYPTION_MODE_IV)

#define SEC_DECRYPTION_MODE_AES_192_PKCS_CBC      SEC_DECRYPTION_MODE_DEFAULT

#define SEC_DECRYPTION_MODE_AES_192_PKCS_CBC_IV   (SEC_DECRYPTION_MODE_DEFAULT | SEC_DECRYPTION_MODE_IV)

#define SEC_DECRYPTION_MODE_AES_256_PKCS_CBC      SEC_DECRYPTION_MODE_DEFAULT

#define SEC_DECRYPTION_MODE_AES_256_PKCS_CBC_IV   (SEC_DECRYPTION_MODE_DEFAULT | SEC_DECRYPTION_MODE_IV)

#define SEC_DECRYPTION_BLOCK_SIZE_AES             0x10u

#define SEC_DECRYPTION_BLOCK_SIZE_AES_PKCS_CBC    SEC_DECRYPTION_BLOCK_SIZE_AES

#if defined( SEC_ENABLE_DECRYPTION ) || defined( SEC_ENABLE_ENCRYPTION )
#define SEC_ENABLE_SECURITY_CLASS_AAA
#endif

#if defined( SEC_ENABLE_DECRYPTION ) || defined( SEC_ENABLE_ENCRYPTION )

typedef SecM_ConstVoidPtrType   SecM_DecInitType;

typedef SecM_ConstVoidPtrType   SecM_DecDeinitType;

typedef SecM_StatusType SEC_CALL_TYPE (* pSecInitDecryptionFct)( SecM_DecInitType init );
typedef SecM_StatusType SEC_CALL_TYPE (* pSecDeinitDecryptionFct)( SecM_DecDeinitType deinit );
typedef SecM_StatusType SEC_CALL_TYPE (* pSecDecryptionFct)( V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * inBlock
   ,  V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * outBlock
   ,  const V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * decParam );
#endif

#if defined( __cplusplus )
extern "C" {
#endif

#define SECM_START_SEC_CODE
#include "MemMap.hpp"

#if defined( SEC_ENABLE_DECRYPTION ) || defined( SEC_ENABLE_ENCRYPTION )

SecM_StatusType SecM_InitDecryption( SecM_DecInitType init );
SecM_StatusType SecM_DeinitDecryption( SecM_DecDeinitType deinit );
SecM_StatusType SecM_Decryption( const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock
   ,  V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock
   ,  V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pDecParam );
SecM_StatusType SecM_InitEncryption( SecM_DecInitType init );
SecM_StatusType SecM_DeinitEncryption( SecM_DecDeinitType deinit );
SecM_StatusType SecM_Encryption( const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock
   ,  V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock
   ,  V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pEncParam );

SecM_StatusType SecM_DecryptionUpdate(const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock
   ,  V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock
   ,  const V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pDecParam
   ,  SecM_WordType smhId);
#endif

#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#if defined( __cplusplus )
}
#endif

#endif

