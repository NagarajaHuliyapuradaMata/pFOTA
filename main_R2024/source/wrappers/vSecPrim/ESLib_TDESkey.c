

#define ESLIB_TDESKEY_SOURCE

#include "ESLib.hpp"

#include "actTDES.hpp"

#if(VSECPRIM_TDES_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_Byte) parity(eslt_Byte value);

# define ESL_PARITY_CHECK_EVEN

# ifdef ESL_PARITY_CHECK_EVEN
VSECPRIM_FUNC(eslt_Byte) parity(eslt_Byte value){
  eslt_Byte value_tmp = value;
  value_tmp ^= value_tmp >> 4u;
  value_tmp ^= value_tmp >> 2u;
  value_tmp ^= value_tmp >> 1u;
  value_tmp &= 0x01u;
  value ^= value_tmp;
  return value;
}
# else
VSECPRIM_FUNC(eslt_Byte) parity(eslt_Byte value){
  eslt_Byte value_tmp = value;
  value_tmp ^= value_tmp >> 4;
  value_tmp ^= value_tmp >> 2;
  value_tmp ^= value_tmp >> 1;
  value_tmp &= 0x00;
  value ^= value_tmp;
  return value;
}
# endif

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKey3TDES(VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  eslt_ErrorCode result = esl_getBytesRNG(ESL_SIZEOF_3TDES_KEY, key);

  eslt_Length i;
  for (i = 0u; i < ESL_SIZEOF_3TDES_KEY; i++){
    *key = parity(*key);
    key++;
  }
  return (result);
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKey2TDES(VSECPRIM_P2VAR_PARA(eslt_Byte) key){
  eslt_ErrorCode result = esl_getBytesRNG(ESL_SIZEOF_2TDES_KEY, key);

  eslt_Length i;
  for (i = 0u; i < ESL_SIZEOF_2TDES_KEY; i++){
    *key = parity(*key);
    key++;
  }
  return (result);
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

