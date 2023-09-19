

#define ESLIB_ECBD_SOURCE
#include "ESLib_Helper.hpp"

#include "actIECBD.hpp"

#if(VSECPRIM_ECBD_GENERIC_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC( eslt_ErrorCode ) esl_validateWS(VSECPRIM_P2CONST_PARA( eslt_WorkSpaceECBD ) workSpace);

VSECPRIM_LOCAL_FUNC( eslt_ErrorCode ) get_ESL_ERC_from_actEXCEPTION (actRETURNCODE rc);

VSECPRIM_FUNC( eslt_ErrorCode ) esl_initECBD (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceECBD ) workSpace
   ,                                             const eslt_Size32                nDevices
   ,                                             const eslt_Size32                deviceID
   ,                                             VSECPRIM_P2CONST_PARA( eslt_EccDomain ) domain
   ,                                             VSECPRIM_P2CONST_PARA( eslt_EccDomainExt ) domainExt
   ,                                             VSECPRIM_P2CONST_PARA( eslt_EccSpeedUpExt ) speedUpExt){
    actRETURNCODE    rc;
    VSECPRIM_P2VAR_PARA( actECBDstruct ) ws;

    if(NULL == workSpace){
      return ESL_ERC_PARAMETER_INVALID;
    }
    if(ESL_MAXSIZEOF_WS_ECBD > workSpace->header.size){
      return ESL_ERC_WS_TOO_SMALL;
    }
    ws = &workSpace->wsECBD;

    if((NULL == domain)
      || (NULL == domainExt)
      || (NULL == speedUpExt)){
      return ESL_ERC_PARAMETER_INVALID;
    }

    if((deviceID <= 0u)
      || (deviceID > nDevices)
      || (3u > nDevices)){
      return ESL_ERC_INPUT_INVALID;
    }

    rc = actECBDinit(ws, ESL_MAXSIZEOF_WS_ECBD, nDevices, deviceID, domain, domainExt, speedUpExt);
    if(rc != actOK){
      return get_ESL_ERC_from_actEXCEPTION(rc);
    }

    workSpace->header.status = (ESL_WST_ALGO_ECBD_KA | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);

    return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC( eslt_ErrorCode ) esl_generateEphemeralKeyPairECBD (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceECBD ) workSpace
   ,                                                                 VSECPRIM_P2VAR_PARA( eslt_Byte ) privateKey
   ,                                                                 VSECPRIM_P2VAR_PARA( eslt_Byte ) publicKey_x
   ,                                                                 VSECPRIM_P2VAR_PARA( eslt_Byte ) publicKey_y){
    eslt_ErrorCode  ec;
    actRETURNCODE   rc;
    VSECPRIM_P2VAR_PARA( actECBDstruct ) ws;

    ec = esl_validateWS(workSpace);
    if(ec != ESL_ERC_NO_ERROR){
      return ec;
    }
    ws = &workSpace->wsECBD;

    if((NULL == publicKey_x)
      || (NULL == publicKey_y)){
      return ESL_ERC_PARAMETER_INVALID;
    }

    rc = actECBDgenKeyPair(ws, privateKey, publicKey_x, publicKey_y, workSpace->header.watchdog);
    if(rc != actOK){
      return get_ESL_ERC_from_actEXCEPTION(rc);
    }

    return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC( eslt_ErrorCode ) esl_calculateIntermediateECBD (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceECBD ) workSpace
   ,                                                              VSECPRIM_P2CONST_PARA( eslt_Byte ) pubKeyLeft_x
   ,                                                              VSECPRIM_P2CONST_PARA( eslt_Byte ) pubKeyLeft_y
   ,                                                              VSECPRIM_P2CONST_PARA( eslt_Byte ) pubKeyRight_x
   ,                                                              VSECPRIM_P2CONST_PARA( eslt_Byte ) pubKeyRight_y
   ,                                                              VSECPRIM_P2VAR_PARA( eslt_Byte ) intermediate_x
   ,                                                              VSECPRIM_P2VAR_PARA( eslt_Byte ) intermediate_y) {
    eslt_ErrorCode  ec;
    actRETURNCODE   rc;
    VSECPRIM_P2VAR_PARA( actECBDstruct ) ws;

    ec = esl_validateWS(workSpace);
    if(ec != ESL_ERC_NO_ERROR){
      return ec;
    }
    ws = &workSpace->wsECBD;

    if((NULL == pubKeyLeft_x)
      || (NULL == pubKeyLeft_y)
      || (NULL == pubKeyRight_x)
      || (NULL == pubKeyRight_y)
      || (NULL == intermediate_x)
      || (NULL == intermediate_y)){
      return ESL_ERC_PARAMETER_INVALID;
    }

    rc = actECBDcalcXi(ws, pubKeyLeft_x, pubKeyLeft_y, pubKeyRight_x, pubKeyRight_y, intermediate_x, intermediate_y, workSpace->header.watchdog);
    if(rc != actOK){
      return get_ESL_ERC_from_actEXCEPTION(rc);
    }

    return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC( eslt_ErrorCode ) esl_initSharedSecretECBD (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceECBD ) workSpace) {
    eslt_ErrorCode  ec;
    actRETURNCODE   rc;
    VSECPRIM_P2VAR_PARA( actECBDstruct ) ws;

    ec = esl_validateWS(workSpace);
    if(ec != ESL_ERC_NO_ERROR){
      return ec;
    }
    ws = &workSpace->wsECBD;

    rc = actECBDinitK(ws, workSpace->header.watchdog);
    if(rc != actOK){
      return get_ESL_ERC_from_actEXCEPTION(rc);
    }

    return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC( eslt_ErrorCode ) esl_updateSharedSecretECBD (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceECBD ) workSpace
   ,                                                           const eslt_Size32          deviceID
   ,                                                           VSECPRIM_P2CONST_PARA( eslt_Byte ) intermediate_x
   ,                                                           VSECPRIM_P2CONST_PARA( eslt_Byte ) intermediate_y){
    eslt_ErrorCode  ec;
    actRETURNCODE   rc;
    VSECPRIM_P2VAR_PARA( actECBDstruct ) ws;

    ec = esl_validateWS(workSpace);
    if(ec != ESL_ERC_NO_ERROR){
      return ec;
    }
    ws = &workSpace->wsECBD;

    if((NULL == intermediate_x)
      || (NULL == intermediate_y)){
      return ESL_ERC_PARAMETER_INVALID;
    }

    if((deviceID <= 0u)
      || (deviceID > ws->bd.nECUs)){
      return ESL_ERC_INPUT_INVALID;
    }

    rc = actECBDupdateK(ws, deviceID, intermediate_x, intermediate_y, workSpace->header.watchdog);
    if(rc != actOK){
      return get_ESL_ERC_from_actEXCEPTION(rc);
    }

    return ESL_ERC_NO_ERROR;
}

VSECPRIM_FUNC( eslt_ErrorCode ) esl_retrieveSharedSecretECBD (VSECPRIM_P2VAR_PARA( eslt_WorkSpaceECBD ) workSpace
   ,                                                             VSECPRIM_P2VAR_PARA( eslt_Byte ) sharedSecret_x
   ,                                                             VSECPRIM_P2VAR_PARA( eslt_Byte ) sharedSecret_y){
    eslt_ErrorCode  ec;
    actRETURNCODE   rc;
    VSECPRIM_P2VAR_PARA( actECBDstruct ) ws;

    ec = esl_validateWS(workSpace);
    if(ec != ESL_ERC_NO_ERROR){
      return ec;
    }
    ws = &workSpace->wsECBD;

    if(NULL == sharedSecret_x)

    {
      return ESL_ERC_PARAMETER_INVALID;
    }

    rc = actECBDretrieveK(ws, sharedSecret_x, sharedSecret_y, workSpace->header.watchdog);
    if(rc != actOK){
      return get_ESL_ERC_from_actEXCEPTION(rc);
    }

    return ESL_ERC_NO_ERROR;
}

VSECPRIM_LOCAL_FUNC( eslt_ErrorCode ) esl_validateWS (VSECPRIM_P2CONST_PARA( eslt_WorkSpaceECBD ) workSpace){
  if(NULL == workSpace){
    return ESL_ERC_PARAMETER_INVALID;
  }

    if((ESL_WST_ALGO_ECBD_KA != (workSpace->header.status & ESL_WST_M_ALGO))
    ||  (ESL_WST_M_RUNNING    != (workSpace->header.status & ESL_WST_M_RUNNING))){
        return ESL_ERC_WS_STATE_INVALID;
    }

    if(ESL_MAXSIZEOF_WS_ECBD > workSpace->header.size){
        return ESL_ERC_WS_TOO_SMALL;
    }

    return ESL_ERC_NO_ERROR;
}

VSECPRIM_LOCAL_FUNC( eslt_ErrorCode ) get_ESL_ERC_from_actEXCEPTION (actRETURNCODE rc){
  eslt_ErrorCode retVal;

    switch(rc){
    case actEXCEPTION_UNKNOWN:
      retVal = ESL_ERC_ECC_INTERNAL_ERROR;
      break;
    case actEXCEPTION_NULL:
      retVal = ESL_ERC_PARAMETER_INVALID;
      break;
    case actEXCEPTION_MEMORY:
      retVal = ESL_ERC_WS_TOO_SMALL;
      break;
    case actEXCEPTION_DOMAIN:
      retVal = ESL_ERC_ECC_DOMAIN_INVALID;
      break;
    case actEXCEPTION_DOMAIN_EXT:
      retVal = ESL_ERC_ECC_DOMAINEXT_INVALID;
      break;
    case actEXCEPTION_SPEEDUP_EXT:
      retVal = ESL_ERC_ECC_SPEEDUPEXT_INVALID;
      break;
    case actEXCEPTION_POINT:
      retVal = ESL_ERC_ECC_INTERNAL_ERROR;
      break;
    case actEXCEPTION_RANDOM:
      retVal = ESL_ERC_RNG_FAILED;
      break;
    default:
      retVal = ESL_ERC_ERROR;
      break;
    }

    return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

