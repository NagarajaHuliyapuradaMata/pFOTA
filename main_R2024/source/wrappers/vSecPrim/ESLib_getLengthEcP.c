

#define ESLIB_GETLENGTHECP_SOURCE

#include "ESLib.hpp"

#include "actIECKey.hpp"

#if(VSECPRIM_ESLGETLENGTHECP_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_Length) esl_getLengthOfEcPprivateKey(VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain){
  eslt_Length result;
  if(domain == NULL_PTR){
    result = 0u;
  }
  else{
    result = (eslt_Length)(actECGetPrivateKeyLength(domain));
  }
  return result;
}

VSECPRIM_FUNC(eslt_Length) esl_getLengthOfEcPpublicKey_comp(VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain){
  eslt_Length result;
  if(domain == NULL_PTR){
    result = 0u;
  }
  else{
    result = (eslt_Length)(actECGetPublicKeyCompLength(domain));
  }
  return result;
}

VSECPRIM_FUNC(eslt_Length) esl_getMaxLengthOfEcPmessage(VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain){
  eslt_Length result;
  if(domain == NULL_PTR){
    result = 0u;
  }
  else{
    result = esl_getLengthOfEcPprivateKey(domain);
  }
  return result;
}

VSECPRIM_FUNC(eslt_Length) esl_getLengthOfEcPsignature_comp(VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain){
  eslt_Length result;
  if(domain == NULL_PTR){
    result = 0u;
  }
  else{
    result = esl_getLengthOfEcPprivateKey(domain);
  }
  return result;
}

VSECPRIM_FUNC(eslt_Length) esl_getLengthOfEcPsecret_comp(VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain){
  eslt_Length result;
  if(domain == NULL_PTR){
    result = 0u;
  }
  else{
    result = esl_getLengthOfEcPpublicKey_comp(domain);
  }
  return result;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

