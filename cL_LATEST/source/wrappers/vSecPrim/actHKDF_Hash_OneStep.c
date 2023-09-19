

#define ACTHKDF_HASH_ONESTEP_SOURCE

#include "actIHKDF_Hash_OneStep.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTHKDFHASHONESTEP_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actHKDF_Hash_OneStepDerive(
  VSECPRIM_P2VAR_PARA(actHKDFHASHSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) secret
   ,  actLengthType secretLength
   ,  VSECPRIM_P2CONST_PARA(actU8) addInput
   ,  actLengthType addInputLength
   ,  VSECPRIM_P2VAR_PARA(actU8) derivedKey
   ,  const actLengthType derivedKeyLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;
  actLengthType numberOfBlocks, remainingBytes, currentBlock;
  actU8 counterBuffer[4];
  actU32 counter = 1u;

  actU32toBE(counterBuffer, counter);

  if((derivedKeyLength + actHASH_SIZE_SHA256 - 1u) < derivedKeyLength){
    retVal = actEXCEPTION_LENGTH;
  }
  else{
    numberOfBlocks = (derivedKeyLength + actHASH_SIZE_SHA256 - 1u) / actHASH_SIZE_SHA256;
    remainingBytes = derivedKeyLength % actHASH_SIZE_SHA256;

    for(currentBlock = 1u; currentBlock <= numberOfBlocks; currentBlock++){
      (void)actSHA256Init(&info->actwsSha);

      (void)actSHA256Update(&info->actwsSha, counterBuffer, 4u, watchdog);
      (void)actSHA256Update(&info->actwsSha, secret, secretLength, watchdog);

      if(addInputLength > 0u)
      {
        (void)actSHA256Update(&info->actwsSha, addInput, addInputLength, watchdog);
      }

      if((currentBlock != numberOfBlocks) || (0u == remainingBytes))
      {
        (void)actSHA256Finalize(&info->actwsSha, &derivedKey[actHASH_SIZE_SHA256 * (currentBlock - 1u)], watchdog);
      }
      else
      {
        (void)actSHA256Finalize(&info->actwsSha, info->blockT, watchdog);
        actMemCpyByteArray(&derivedKey[actHASH_SIZE_SHA256 * (currentBlock - 1u)], info->blockT, remainingBytes);
      }

      counter++;
      actU32toBE(counterBuffer, counter);
    }

    retVal = actOK;
  }

  return retVal;

}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif
