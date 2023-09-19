#if !defined(SECMPAR_H)
#define SECMPAR_H

#include "Sec_Inc.hpp"

#define SECM_START_SEC_CODE
#include "MemMap.hpp"
SecM_StatusType DecryptAes128(
      const V_MEMRAM1 SecM_DecInputParamType  V_MEMRAM2 V_MEMRAM3 * pInBlock
   ,        V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock
   ,  const V_MEMRAM1 SecM_DecParamType       V_MEMRAM2 V_MEMRAM3 * pDecParam
);
SecM_StatusType SecM_VerifyClass_DDD       (V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
SecM_StatusType SecM_Verify_ClassC         (V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
SecM_StatusType SecM_VerifyClass_CCC       (V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
SecM_StatusType SecM_VerificationClassDDD  (V_MEMRAM1 SecM_VerifyParamType    V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
SecM_StatusType SecM_Verification_ClassC   (V_MEMRAM1 SecM_VerifyParamType    V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
SecM_StatusType SecM_Verification_ClassCCC (V_MEMRAM1 SecM_VerifyParamType    V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
#define SECM_STOP_SEC_CODE
#include "MemMap.hpp"

#define SECM_START_SEC_CONST
#include "MemMap.hpp"
V_MEMROM0 extern V_MEMROM1 vuint8                    V_MEMROM2 AesKeyKey[16];
V_MEMROM0 extern V_MEMROM1 vuint8                    V_MEMROM2 AesKeyIV[16];
V_MEMROM0 extern V_MEMROM1 vuint8                    V_MEMROM2 ClassCCC_Ed25519Key[32];
V_MEMROM0 extern V_MEMROM1 vuint8                    V_MEMROM2 ClassC_Key[16];
V_MEMROM0 extern V_MEMROM1 vuint8                    V_MEMROM2 ClassCCC_Rsa1024KeyExp[4];
V_MEMROM0 extern V_MEMROM1 vuint8                    V_MEMROM2 ClassCCC_Rsa1024KeyMod[128];
V_MEMROM0 extern V_MEMROM1 vuint8                    V_MEMROM2 ClassCCC_Rsa2048KeyExp[4];
V_MEMROM0 extern V_MEMROM1 vuint8                    V_MEMROM2 ClassCCC_Rsa2048KeyMod[256];
V_MEMROM0 extern V_MEMROM1 vuint8                    V_MEMROM2 ClassCCC_Rsa3072KeyExp[4];
V_MEMROM0 extern V_MEMROM1 vuint8                    V_MEMROM2 ClassCCC_Rsa3072KeyMod[384];
V_MEMROM0 extern V_MEMROM1 SecM_CryptographicKeyType V_MEMROM2 SecM_CryptographicKeys[6];
V_MEMROM0 extern V_MEMROM1 SecM_DecPrimitiveType     V_MEMROM2 SecM_DecryptionPrimitives[1];
V_MEMROM0 extern V_MEMROM1 SecM_CrcPrimitiveType     V_MEMROM2 SecM_CrcPrimitives[1];
V_MEMROM0 extern V_MEMROM1 SecM_RamDataType          V_MEMROM2 SecM_MacPrimitivesContextBuffs[1];
V_MEMROM0 extern V_MEMROM1 SecM_MacPrimitiveType     V_MEMROM2 SecM_MacPrimitives[1];
V_MEMROM0 extern V_MEMROM1 SecM_RamDataType          V_MEMROM2 SecM_SignaturePrimitivesContextBuffs[1];
V_MEMROM0 extern V_MEMROM1 SecM_SigPrimitiveType     V_MEMROM2 SecM_SignaturePrimitives[1];
V_MEMROM0 extern V_MEMROM1 SecM_JobInfoType          V_MEMROM2 SecM_JobInfo[4];
#define SECM_STOP_SEC_CONST
#include "MemMap.hpp"

#endif
