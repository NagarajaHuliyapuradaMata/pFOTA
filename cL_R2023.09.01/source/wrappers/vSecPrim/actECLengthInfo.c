

#define ACTECLENGTHINFO_SOURCE

#include "actECLengthInfo.hpp"
#include "actITypes.hpp"
#include "actUtilities.hpp"
#include "actBigNum.hpp"
#include "actECPoint.hpp"
#include "actECTools.hpp"
#include "actECLengthMacros.hpp"

#if(VSECPRIM_ACTECLENGTHINFO_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actLengthType) actECBasicWksp(
  actLengthType p_length
   ,  actLengthType n_length){
   return ( actEC_BASIC_WKSP(p_length, n_length) );
}

VSECPRIM_FUNC(actLengthType) actECKgWksp(
  actLengthType p_length
   ,  actLengthType n_length){
   return ( actEC_KG_WKSP(p_length, n_length) );
}

VSECPRIM_FUNC(actLengthType) actECDHpWksp(
  actLengthType p_length
   ,  actLengthType n_length){
   return ( actEC_DHp_WKSP(p_length, n_length) );
}

VSECPRIM_FUNC(actLengthType) actECDHWksp(
  actLengthType p_length
   ,  actLengthType n_length){
   return ( actEC_DH_WKSP(p_length, n_length) );
}

VSECPRIM_FUNC(actLengthType) actECDSASpWksp(
  actLengthType p_length
   ,  actLengthType n_length){
   return ( actEC_DSASp_WKSP(p_length, n_length) );
}

VSECPRIM_FUNC( actLengthType ) actECDSAVpWksp(
  actLengthType p_length
   ,  actLengthType n_length ){
   return ( actEC_DSAVp_WKSP(p_length, n_length) );
}

VSECPRIM_FUNC( actLengthType ) actECBDWksp(
  actLengthType p_length
   ,  actLengthType n_length ){
   return ( actEC_BDKA_WKSP(p_length, n_length) );
}

VSECPRIM_FUNC(actRETURNCODE) actECGetPrimeAndOrderBytes(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain
   ,  VSECPRIM_P2VAR_PARA(actLengthType) p_bytes
   ,  VSECPRIM_P2VAR_PARA(actLengthType) n_bytes){
   return actECParseDomain(domain
   ,                           p_bytes
   ,                           (VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)))NULL_PTR
   ,                           (VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)))NULL_PTR
   ,                           n_bytes
   ,                           (VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)))NULL_PTR);
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

