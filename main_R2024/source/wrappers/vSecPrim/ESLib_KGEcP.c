

#define ESLIB_KGECP_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"

#include "actIECKey.hpp"

#if(VSECPRIM_ECCENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_initGenerateKeyEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccSpeedUpExt) speedUpExt){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (domain == NULL_PTR) || (domainExt == NULL_PTR) || (speedUpExt == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_ECP)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actECInitGenerateKeyPair(domain, domainExt, speedUpExt, &workSpace->wsEcP, workSpace->header.size);

    if(actRetVal != actOK){
      if(actRetVal == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_WS_TOO_SMALL;
      }
      else if(actRetVal == actEXCEPTION_DOMAIN)
      {
        retVal = ESL_ERC_ECC_DOMAIN_INVALID;
      }
      else if(actRetVal == actEXCEPTION_DOMAIN_EXT)
      {
        retVal = ESL_ERC_ECC_DOMAINEXT_INVALID;
      }
      else
      {
        retVal = ESL_ERC_ECC_SPEEDUPEXT_INVALID;
      }
    }
    else{
      retVal = ESL_ERC_NO_ERROR;

      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_ECP);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyEcP_prim(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceEcP) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Byte) privateKey,
  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey_x,
  VSECPRIM_P2VAR_PARA(eslt_Byte) publicKey_y){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (privateKey == NULL_PTR) || (publicKey_x == NULL_PTR) || (publicKey_y == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_ECP, ESL_WST_ALGO_ECP)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actECGenerateKeyPair(TRUE, privateKey, publicKey_x, publicKey_y, &workSpace->wsEcP, workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_UNKNOWN){
      retVal = ESL_ERC_ECC_INTERNAL_ERROR;
    }
    else if(actRetVal == actEXCEPTION_PRIVKEY){
      retVal = ESL_ERC_ECC_PRIVKEY_INVALID;
    }
    else{
      retVal = ESL_ERC_NO_ERROR;
    }
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

