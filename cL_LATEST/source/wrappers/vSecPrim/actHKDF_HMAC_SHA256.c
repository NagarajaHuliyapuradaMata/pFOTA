

#define ACTHKDF_HMAC_SHA256_SOURCE

#include "actIHKDF_HMAC_SHA256.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTHKDFHMACSHA256_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actHKDF_HMAC_SHA256_Extract(
  VSECPRIM_P2VAR_PARA(actHKDFSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) secret
   ,  actLengthType secretLength
   ,  VSECPRIM_P2CONST_PARA(actU8) salt
   ,  actLengthType saltLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  if((salt == NULL_PTR) || (saltLength == 0u)){
    actMemClear(info->tmpBlock.tmpKey, actHASH_SIZE_SHA256);

    (void)actHashMACSHA256Init(&info->actwsHmac, info->tmpBlock.tmpKey, actHASH_SIZE_SHA256, watchdog);
  }
  else{
    (void)actHashMACSHA256Init(&info->actwsHmac, salt, saltLength, watchdog);
  }

  (void)actHashMACSHA256Update(&info->actwsHmac, secret, secretLength, watchdog);

  (void)actHashMACSHA256Finalize(&info->actwsHmac, info->keyDerivationKey, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actHKDF_HMAC_SHA256_Expand(
  VSECPRIM_P2VAR_PARA(actHKDFSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) addInput
   ,  actLengthType addInputLength
   ,  VSECPRIM_P2VAR_PARA(actU8) derivedKey
   ,  const actLengthType derivedKeyLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;
  actLengthType numberOfBlocks, remainingBytes, currentBlock, blockSize;
  actU8 counter = 1u;

  if(derivedKeyLength > (255u * actHASH_SIZE_SHA256)){
    retVal = actEXCEPTION_LENGTH;
  }
  else{
    numberOfBlocks = (derivedKeyLength + actHASH_SIZE_SHA256 - 1u) / actHASH_SIZE_SHA256;
    remainingBytes = derivedKeyLength % actHASH_SIZE_SHA256;

    actMemClear(info->tmpBlock.blockT, actHASH_SIZE_SHA256);
    blockSize = 0u;

    for(currentBlock = 1u; currentBlock <= numberOfBlocks; currentBlock++){
      (void)actHashMACSHA256Init(&info->actwsHmac, info->keyDerivationKey, actHASH_SIZE_SHA256, watchdog);

      (void)actHashMACSHA256Update(&info->actwsHmac, info->tmpBlock.blockT, blockSize, watchdog);

      if(addInputLength > 0u)
      {
        (void)actHashMACSHA256Update(&info->actwsHmac, addInput, addInputLength, watchdog);
      }

      (void)actHashMACSHA256Update(&info->actwsHmac, &counter, 1u, watchdog);

      if((currentBlock != numberOfBlocks) || (0u == remainingBytes))
      {
        (void)actHashMACSHA256Finalize(&info->actwsHmac, info->tmpBlock.blockT, watchdog);
        actMemCpyByteArray(&derivedKey[actHASH_SIZE_SHA256 * (currentBlock - 1u)], info->tmpBlock.blockT, actHASH_SIZE_SHA256);
      }
      else
      {
        (void)actHashMACSHA256Finalize(&info->actwsHmac, info->tmpBlock.blockT, watchdog);
        actMemCpyByteArray(&derivedKey[actHASH_SIZE_SHA256 * (currentBlock - 1u)], info->tmpBlock.blockT, remainingBytes);
      }

      blockSize = actHASH_SIZE_SHA256;
      counter++;
    }
  }

  return retVal;

}

VSECPRIM_FUNC(actRETURNCODE) actHKDF_HMAC_SHA256_OneStepDerive(
  VSECPRIM_P2VAR_PARA(actHKDFSTRUCT) info
   ,  VSECPRIM_P2CONST_PARA(actU8) secret
   ,  actLengthType secretLength
   ,  VSECPRIM_P2CONST_PARA(actU8) salt
   ,  actLengthType saltLength
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
      if((salt == NULL_PTR) || (saltLength == 0u))
      {
        actMemClear(info->tmpBlock.tmpKey, actHASH_SIZE_SHA256);

        (void)actHashMACSHA256Init(&info->actwsHmac, info->tmpBlock.tmpKey, actHASH_SIZE_SHA256, watchdog);
      }
      else
      {
        (void)actHashMACSHA256Init(&info->actwsHmac, salt, saltLength, watchdog);
      }

      (void)actHashMACSHA256Update(&info->actwsHmac, counterBuffer, 4u, watchdog);
      (void)actHashMACSHA256Update(&info->actwsHmac, secret, secretLength, watchdog);
      (void)actHashMACSHA256Update(&info->actwsHmac, addInput, addInputLength, watchdog);

      if((currentBlock != numberOfBlocks) || (0u == remainingBytes))
      {
        (void)actHashMACSHA256Finalize(&info->actwsHmac, &derivedKey[actHASH_SIZE_SHA256 * (currentBlock - 1u)], watchdog);
      }
      else
      {
        (void)actHashMACSHA256Finalize(&info->actwsHmac, info->tmpBlock.blockT, watchdog);
        actMemCpyByteArray(&derivedKey[actHASH_SIZE_SHA256 * (currentBlock - 1u)], info->tmpBlock.blockT, remainingBytes);
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
