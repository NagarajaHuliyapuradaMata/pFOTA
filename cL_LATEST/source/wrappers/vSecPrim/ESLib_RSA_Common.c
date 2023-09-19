

#define ESLIB_RSA_PSS_COMMON_SOURCE

#include "ESLib.hpp"
#include "ESLib_RSA_Common.hpp"

#if((VSECPRIM_RSA_OAEP_ENABLED == STD_ON) || (VSECPRIM_RSA_PSS_ENABLED == STD_ON))

#if((VSECPRIM_RSA_PSS_SHA1_ENABLED == STD_ON) || (VSECPRIM_RSA_OAEP_SHA1_ENABLED == STD_ON))
#define VSECPRIM_WRAPPER_SHA1
#endif
#if((VSECPRIM_RSA_PSS_SHA2_256_ENABLED == STD_ON) || (VSECPRIM_RSA_OAEP_SHA2_256_ENABLED == STD_ON))
#define VSECPRIM_WRAPPER_SHA256
#endif
#if(VSECPRIM_RSA_PSS_RIPEMD160_ENABLED == STD_ON)
#define VSECPRIM_WRAPPER_RIPEMD160
#endif

typedef eslt_WorkSpaceUnionHashFunctions_RSA eslt_WorkSpaceUnionHashFunctions;
#include "actHashFctWrappers_Implementation.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSaltedHashRSA_PSS(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceUnionHashFunctions_RSA) wsuHash
   ,  eslt_Length saltSize
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) salt
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) messageDigest
   ,  eslt_Length hashDigestSize
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) saltedHash
   ,  eslt_HashAlgorithm hashID){
  eslt_ErrorCode returnValue = ESL_ERC_NO_ERROR;
  actRETURNCODE actReturnValue;
  eslt_Byte padding[ESL_SIZEOF_RSA_PSS_PADDING1];

  actReturnValue = actHashInit(wsuHash, hashID);

  if(actReturnValue == actOK){
    actMemClear(padding, sizeof(padding));
    actReturnValue = actHashUpdate(wsuHash, padding, sizeof(padding), hashID);

    if(actReturnValue == actOK){
      actReturnValue = actHashUpdate(wsuHash, messageDigest, hashDigestSize, hashID);
    }

    if(actReturnValue == actOK){
      if(saltSize > 0u)
      {
        actReturnValue = actHashUpdate(wsuHash, salt, saltSize, hashID);
      }
    }

    if(actReturnValue == actOK){
      (void)actHashFinalize(wsuHash, saltedHash, hashID);
    }
    else{
      returnValue = ESL_ERC_TOTAL_LENGTH_OVERFLOW;
    }
  }
  else{
    returnValue = ESL_ERC_INPUT_INVALID;
  }

  return returnValue;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateMaskMGF1(
  eslt_HashAlgorithm hashAlgorithm
   ,  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceUnionHashFunctions_RSA) wsHash
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) tempHash
   ,  eslt_Length hashDigestSize
   ,  eslt_Length seedLength
   ,  VSECPRIM_P2CONST_PARA(eslt_Byte) seed
   ,  eslt_Length maskLength
   ,  VSECPRIM_P2VAR_PARA(eslt_Byte) mask){
  eslt_ErrorCode returnValue;
  actRETURNCODE actReturnValue = actEXCEPTION_UNKNOWN;
  eslt_Size32 counter;
  eslt_Byte octetCounter[4u];
  eslt_Length digestNumber;
  eslt_Length remainingLength;
  eslt_Length offset;
  eslt_Length passLength;
  eslt_Length i;

  if(hashDigestSize == 0u){
    returnValue = ESL_ERC_ERROR;
  }
  else{
    counter = 0u;
    offset = 0u;
    digestNumber = (maskLength + hashDigestSize - 1u) / hashDigestSize;
    remainingLength = maskLength;

    returnValue = ESL_ERC_NO_ERROR;

    for(i = 0; i < digestNumber; i++){
      actReturnValue = actHashInit(wsHash, hashAlgorithm);

      if(actReturnValue == actOK)
      {
        actReturnValue = actHashUpdate(wsHash, seed, seedLength, hashAlgorithm);
      }

      if(actReturnValue == actOK)
      {
        actU32toBE(octetCounter, counter);

        actReturnValue = actHashUpdate(wsHash, octetCounter, sizeof(octetCounter), hashAlgorithm);
      }

      if(actReturnValue == actOK)
      {
        actReturnValue = actHashFinalize(wsHash, tempHash, hashAlgorithm);
      }

      if(actReturnValue == actOK)
      {
        passLength = hashDigestSize;
        if(passLength > remainingLength)
        {
          passLength = remainingLength;
        }

        actMemCpyByteArray(&mask[offset], tempHash, passLength);

        counter++;
        offset += passLength;
        remainingLength -= passLength;
      }

      if(actReturnValue != actOK)
      {
        returnValue = ESL_ERC_ERROR;
        break;
      }
    }
  }

  return returnValue;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

