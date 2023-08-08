

#define ESLIB_SPAKE2P_SOURCE

#include "ESLib.hpp"
#include "ESLib_Helper.hpp"
#include "ESLib_SPAKE2PConstants.hpp"

#include "actISPAKE2P.hpp"

#if(VSECPRIM_SPAKE2_P_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CONST_8BIT
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_NONE, eslt_Byte) esl_SPAKE2P_pointM_P256[65] =
{
  0x04,
  0x88U, 0x6eU, 0x2fU, 0x97U, 0xacU, 0xe4U, 0x6eU, 0x55U, 0xbaU, 0x9dU, 0xd7U, 0x24U, 0x25U, 0x79U, 0xf2U, 0x99U,
  0x3bU, 0x64U, 0xe1U, 0x6eU, 0xf3U, 0xdcU, 0xabU, 0x95U, 0xafU, 0xd4U, 0x97U, 0x33U, 0x3dU, 0x8fU, 0xa1U, 0x2fU,
  0x5fU, 0xf3U, 0x55U, 0x16U, 0x3eU, 0x43U, 0xceU, 0x22U, 0x4eU, 0x0bU, 0x0eU, 0x65U, 0xffU, 0x02U, 0xacU, 0x8eU,
  0x5cU, 0x7bU, 0xe0U, 0x94U, 0x19U, 0xc7U, 0x85U, 0xe0U, 0xcaU, 0x54U, 0x7dU, 0x55U, 0xa1U, 0x2eU, 0x2dU, 0x20U
};

VSECPRIM_ROM(VSECPRIM_NONE, eslt_Byte) esl_SPAKE2P_pointN_P256[65] =
{
  0x04,
  0xd8U, 0xbbU, 0xd6U, 0xc6U, 0x39U, 0xc6U, 0x29U, 0x37U, 0xb0U, 0x4dU, 0x99U, 0x7fU, 0x38U, 0xc3U, 0x77U, 0x07U,
  0x19U, 0xc6U, 0x29U, 0xd7U, 0x01U, 0x4dU, 0x49U, 0xa2U, 0x4bU, 0x4fU, 0x98U, 0xbaU, 0xa1U, 0x29U, 0x2bU, 0x49U,
  0x07U, 0xd6U, 0x0aU, 0xa6U, 0xbfU, 0xadU, 0xe4U, 0x50U, 0x08U, 0xa6U, 0x36U, 0x33U, 0x7fU, 0x51U, 0x68U, 0xc6U,
  0x4dU, 0x9bU, 0xd3U, 0x60U, 0x34U, 0x80U, 0x8cU, 0xd5U, 0x64U, 0x49U, 0x0bU, 0x1eU, 0x65U, 0x6eU, 0xdbU, 0xe7U
};

# define VSECPRIM_STOP_SEC_CONST_8BIT
# include "CompilerCfg_vSecPrim.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_calcSPAKE2PPreamble_inputCheck(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceSPAKE2PPreamble) wsSpakePre,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pbkdfOutput,
  const eslt_Length pbkdfOutputLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) w0,
  VSECPRIM_P2CONST_PARA(eslt_Length) w0Length,
  VSECPRIM_P2CONST_PARA(eslt_Byte) w1,
  VSECPRIM_P2CONST_PARA(eslt_Length) w1Length,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointL,
  VSECPRIM_P2CONST_PARA(eslt_Length) pointLLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initSPAKE2P_inputCheck(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointM,
  const eslt_Length mlength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointN,
  const eslt_Length nlength,
  eslt_SPAKE2PMode ciphersuite);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initSPAKE2P_pointCheck(
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointM,
  const eslt_Length mlength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointN,
  const eslt_Length nlength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_setPreambleDataPartyBSPAKE2P_inputCheck(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) w0,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointL,
  const eslt_Length pointLLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_calcSharedSecretSPAKE2P_inputCheck(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pubVal_x,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pubVal_y,
  VSECPRIM_P2CONST_PARA(eslt_Byte) sharedSecret,
  VSECPRIM_P2CONST_PARA(eslt_Length) sharedSecretLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) confirmationMAC,
  VSECPRIM_P2CONST_PARA(eslt_Length) confirmationMACLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_confirmKeySPAKE2P_inputCheck(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) mac,
  const eslt_Length macLength);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_SPAKE2P_get_ERC_from_actEXCEPTION(
  actRETURNCODE actRetVal);

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_calcSPAKE2PPreamble_inputCheck(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceSPAKE2PPreamble) wsSpakePre,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pbkdfOutput,
  const eslt_Length pbkdfOutputLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) w0,
  VSECPRIM_P2CONST_PARA(eslt_Length) w0Length,
  VSECPRIM_P2CONST_PARA(eslt_Byte) w1,
  VSECPRIM_P2CONST_PARA(eslt_Length) w1Length,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointL,
  VSECPRIM_P2CONST_PARA(eslt_Length) pointLLength){
  eslt_ErrorCode retVal;

  if((wsSpakePre == NULL_PTR) || (pbkdfOutput == NULL_PTR) ||
      (w0 == NULL_PTR) || (w0Length == NULL_PTR) ||
      (w1 == NULL_PTR) || (w1Length == NULL_PTR) ||
      (pointL == NULL_PTR) || (pointLLength == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&wsSpakePre->header, ESL_SIZEOF_WS_SPAKE2PPRE, ESL_WST_ALGO_SPAKE2P_PREAMBLE)) != ESL_ERC_NO_ERROR){
  }
  else if(Esl_ValueIsOdd(pbkdfOutputLength) == TRUE){
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  else{
    retVal = ESL_ERC_NO_ERROR;
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initSPAKE2P_inputCheck(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointM,
  const eslt_Length mlength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointN,
  const eslt_Length nlength,
  eslt_SPAKE2PMode ciphersuite){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (domain == NULL_PTR) || (domainExt == NULL_PTR) ||
      (pointM == NULL_PTR) || (pointN == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_SIZEOF_WS_SPAKE2P)) != ESL_ERC_NO_ERROR){
  }
  else if((ciphersuite != ESL_SPAKE2P_MODE_CIPHERSUITE_8_1) && (ciphersuite != ESL_SPAKE2P_MODE_CIPHERSUITE_8_2)){
    retVal = ESL_ERC_MODE_INVALID;
  }
  else if((retVal = esl_initSPAKE2P_pointCheck(pointM, mlength, pointN, nlength)) != ESL_ERC_NO_ERROR){
  }
  else{
    retVal = ESL_ERC_NO_ERROR;
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_initSPAKE2P_pointCheck(
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointM,
  const eslt_Length mlength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointN,
  const eslt_Length nlength){
  eslt_ErrorCode retVal;

  if((mlength == 0u) || (nlength == 0u)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((Esl_ValueIsEven(mlength) == TRUE) || (Esl_ValueIsEven(nlength) == TRUE)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((pointM[0] != ESL_UNCOMPRESSED_POINT_ENCODING_BYTE) || (pointN[0] != ESL_UNCOMPRESSED_POINT_ENCODING_BYTE)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else{
    retVal = ESL_ERC_NO_ERROR;
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_setPreambleDataPartyBSPAKE2P_inputCheck(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) w0,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointL,
  const eslt_Length pointLLength){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (w0 == NULL_PTR) || (pointL == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((pointL[0] != ESL_UNCOMPRESSED_POINT_ENCODING_BYTE) || (Esl_ValueIsEven(pointLLength) == TRUE)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SPAKE2P, ESL_WST_ALGO_SPAKE2P)) != ESL_ERC_NO_ERROR){
  }
  else if(workSpace->workSpaceSpake.algoState != ESL_SPAKE2P_PREAMBLE_DATA_NOT_SET){
    retVal = ESL_ERC_STATE_INVALID;
  }
  else{
    retVal = ESL_ERC_NO_ERROR;
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_calcSharedSecretSPAKE2P_inputCheck(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pubVal_x,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pubVal_y,
  VSECPRIM_P2CONST_PARA(eslt_Byte) sharedSecret,
  VSECPRIM_P2CONST_PARA(eslt_Length) sharedSecretLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) confirmationMAC,
  VSECPRIM_P2CONST_PARA(eslt_Length) confirmationMACLength){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (pubVal_x == NULL_PTR) || (pubVal_y == NULL_PTR) ||
    (sharedSecret == NULL_PTR) || (sharedSecretLength == NULL_PTR) ||
    (confirmationMAC == NULL_PTR) || (confirmationMACLength == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SPAKE2P, ESL_WST_ALGO_SPAKE2P)) != ESL_ERC_NO_ERROR){
  }
  else if(workSpace->workSpaceSpake.algoState != ESL_SPAKE2P_PUBLIC_VALUE_CALCULATED){
    retVal = ESL_ERC_STATE_INVALID;
  }
  else if((*sharedSecretLength < (ESL_SIZEOF_SHA256_DIGEST / 2u)) || (*confirmationMACLength < ESL_SIZEOF_AES128_BLOCK)){
    retVal = ESL_ERC_BUFFER_TOO_SMALL;
  }
  else{
    retVal = ESL_ERC_NO_ERROR;
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_confirmKeySPAKE2P_inputCheck(
  VSECPRIM_P2CONST_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) mac,
  const eslt_Length macLength){
  eslt_ErrorCode retVal;

  if((workSpace == NULL_PTR) || (mac == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SPAKE2P, ESL_WST_ALGO_SPAKE2P)) != ESL_ERC_NO_ERROR){
  }
  else if(workSpace->workSpaceSpake.algoState != ESL_SPAKE2P_SHARED_SECRET_CALCULATED){
    retVal = ESL_ERC_STATE_INVALID;
  }
  else if(macLength != ESL_SIZEOF_AES128_BLOCK){
    retVal = ESL_ERC_INVALID_LENGTH;
  }
  else{
    retVal = ESL_ERC_NO_ERROR;
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(eslt_ErrorCode) esl_SPAKE2P_get_ERC_from_actEXCEPTION(
  actRETURNCODE actRetVal){
  eslt_ErrorCode retVal;

  switch(actRetVal){
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

  case actEXCEPTION_LENGTH:
    retVal = ESL_ERC_CURVE_NOT_SUPPORTED;
    break;

  case actEXCEPTION_INPUT_LENGTH:
    retVal = ESL_ERC_PARAMETER_INVALID;
    break;

  case actEXCEPTION_POINT:
    retVal = ESL_ERC_ECC_INTERNAL_ERROR;
    break;

  case actEXCEPTION_OUTPUT_BUFFER:
    retVal = ESL_ERC_BUFFER_TOO_SMALL;
    break;

  default:
    retVal = ESL_ERC_ERROR;
    break;
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSPAKE2PPreamble(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2PPreamble) wsSpakePre,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((wsSpakePre == NULL_PTR) || (domain == NULL_PTR) || (domainExt == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeader(&wsSpakePre->header, ESL_SIZEOF_WS_SPAKE2PPRE)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actSPAKE2PPreambleInit(&wsSpakePre->wsSPAKEPreamble, domain, domainExt, ESL_SIZEOF_WS_SPAKE2PPRE);

    if(actRetVal != actOK){
      retVal = esl_SPAKE2P_get_ERC_from_actEXCEPTION(actRetVal);
    }
    else{
      esl_SetWorkspaceStatus(&wsSpakePre->header, ESL_WST_ALGO_SPAKE2P_PREAMBLE);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSPAKE2PPreamble(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2PPreamble) wsSpakePre,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pbkdfOutput,
  const eslt_Length pbkdfOutputLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) w0,
  VSECPRIM_P2VAR_PARA(eslt_Length) w0Length,
  VSECPRIM_P2VAR_PARA(eslt_Byte) w1,
  VSECPRIM_P2VAR_PARA(eslt_Length) w1Length,
  VSECPRIM_P2VAR_PARA(eslt_Byte) pointL,
  VSECPRIM_P2VAR_PARA(eslt_Length) pointLLength){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  actLengthType w0_length, w1_length, pointL_length;

  if((retVal = esl_calcSPAKE2PPreamble_inputCheck(wsSpakePre, pbkdfOutput, pbkdfOutputLength, w0, w0Length, w1, w1Length, pointL, pointLLength)) != ESL_ERC_NO_ERROR){
  }
  else{
    w0_length = (actLengthType)(*w0Length);
    w1_length = (actLengthType)(*w1Length);
    pointL_length = (actLengthType)(*pointLLength);

    actRetVal = actSPAKE2PPreambleCalc(&wsSpakePre->wsSPAKEPreamble, pbkdfOutput, (actLengthType)pbkdfOutputLength, w0, &w0_length, w1, &w1_length, pointL, &pointL_length, wsSpakePre->header.watchdog);

    if(actRetVal != actOK){
      if(actRetVal == actEXCEPTION_MEMORY)
      {
        retVal = ESL_ERC_BUFFER_TOO_SMALL;
      }
      else if(actRetVal == actEXCEPTION_INPUT_LENGTH)
      {
        retVal = ESL_ERC_INVALID_LENGTH;
      }
      else
      {
        retVal = ESL_ERC_ERROR;
      }

      *w0Length = 0u;
      *w1Length = 0u;
      *pointLLength = 0u;
    }
    else{
      *w0Length = (eslt_Length)(w0_length);
      *w1Length = (eslt_Length)(w1_length);
      *pointLLength = (eslt_Length)(pointL_length);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_initSPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomain) domain,
  VSECPRIM_P2ROMCONST_PARA(eslt_EccDomainExt) domainExt,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointM,
  const eslt_Length mlength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointN,
  const eslt_Length nlength,
  eslt_SPAKE2PMode ciphersuite){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((retVal = esl_initSPAKE2P_inputCheck(workSpace, domain, domainExt, pointM, mlength, pointN, nlength, ciphersuite)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actSPAKE2PInit(&workSpace->workSpaceSpake, domain, domainExt,
      pointM, mlength, pointN, nlength, ESL_SIZEOF_WS_SPAKE2P);

    if(actRetVal != actOK){
      retVal = esl_SPAKE2P_get_ERC_from_actEXCEPTION(actRetVal);
    }
    else{
      retVal = ESL_ERC_NO_ERROR;

      workSpace->workSpaceSpake.ciphersuite = ciphersuite;
      workSpace->workSpaceSpake.algoState = ESL_SPAKE2P_PREAMBLE_DATA_NOT_SET;
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_SPAKE2P);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_setPreambleDataPartyASPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) w0,
  const eslt_Length w0length,
  VSECPRIM_P2CONST_PARA(eslt_Byte) w1,
  const eslt_Length w1length){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((workSpace == NULL_PTR) || (w0 == NULL_PTR) || (w1 == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SPAKE2P, ESL_WST_ALGO_SPAKE2P)) != ESL_ERC_NO_ERROR){
  }
  else if(workSpace->workSpaceSpake.algoState != ESL_SPAKE2P_PREAMBLE_DATA_NOT_SET){
    retVal = ESL_ERC_STATE_INVALID;
  }
  else{
    actRetVal = actSPAKE2PSetPreambleData(&workSpace->workSpaceSpake, w0, w0length, w1, w1length, NULL_PTR, 0);

    if(actRetVal != actOK){
      retVal = ESL_ERC_PARAMETER_INVALID;
    }
    else{
      workSpace->workSpaceSpake.algoState = ESL_SPAKE2P_PREAMBLE_DATA_SET;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_setPreambleDataPartyBSPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) w0,
  const eslt_Length w0length,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pointL,
  const eslt_Length pointLLength){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((retVal = esl_setPreambleDataPartyBSPAKE2P_inputCheck(workSpace, w0, pointL, pointLLength)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actSPAKE2PSetPreambleData(&workSpace->workSpaceSpake, w0, w0length, NULL_PTR, 0, pointL, pointLLength);

    if(actRetVal != actOK){
      retVal = ESL_ERC_PARAMETER_INVALID;
    }
    else{
      workSpace->workSpaceSpake.algoState = ESL_SPAKE2P_PREAMBLE_DATA_SET;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_calcPubValSPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2VAR_PARA(eslt_Byte) pubVal_x,
  VSECPRIM_P2VAR_PARA(eslt_Byte) pubVal_y,
  VSECPRIM_P2VAR_PARA(eslt_Length) pubValLength){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  actLengthType pubVal_length;

  if((workSpace == NULL_PTR) || (pubVal_x == NULL_PTR) || (pubVal_y == NULL_PTR) || (pubValLength == NULL_PTR)){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SPAKE2P, ESL_WST_ALGO_SPAKE2P)) != ESL_ERC_NO_ERROR){
  }
  else if(workSpace->workSpaceSpake.algoState != ESL_SPAKE2P_PREAMBLE_DATA_SET){
    retVal = ESL_ERC_STATE_INVALID;
  }
  else{
    pubVal_length = (actLengthType)(*pubValLength);
    actRetVal = actSPAKE2PCalcPubVal(&(workSpace->workSpaceSpake), pubVal_x, pubVal_y, &pubVal_length, workSpace->header.watchdog);

    if(actRetVal != actOK){
      retVal = esl_SPAKE2P_get_ERC_from_actEXCEPTION(actRetVal);
    }
    else{
      workSpace->workSpaceSpake.algoState = ESL_SPAKE2P_PUBLIC_VALUE_CALCULATED;
      *pubValLength = (eslt_Length)pubVal_length;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_setAdditionalInformationSPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) infoA,
  const eslt_Length infoALength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) infoB,
  const eslt_Length infoBLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) aad,
  const eslt_Length aadLength){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if(workSpace == NULL_PTR){
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_SIZEOF_WS_SPAKE2P, ESL_WST_ALGO_SPAKE2P)) != ESL_ERC_NO_ERROR){
  }
  else if(workSpace->workSpaceSpake.algoState >= ESL_SPAKE2P_SHARED_SECRET_CALCULATED){
    retVal = ESL_ERC_STATE_INVALID;
  }
  else{
    actRetVal = actSPAKE2PSetAdditionalInformation(&workSpace->workSpaceSpake, &workSpace->workSpaceSHA, infoA, infoALength, infoB, infoBLength, aad, aadLength, workSpace->header.watchdog);

    if(actRetVal == actEXCEPTION_INPUT_LENGTH){
      retVal = ESL_ERC_INVALID_LENGTH;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_calcSharedSecretSPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pubVal_x,
  VSECPRIM_P2CONST_PARA(eslt_Byte) pubVal_y,
  const eslt_Length pubValLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) sharedSecret,
  VSECPRIM_P2VAR_PARA(eslt_Length) sharedSecretLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) confirmationMAC,
  VSECPRIM_P2VAR_PARA(eslt_Length) confirmationMACLength){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;

  if((retVal = esl_calcSharedSecretSPAKE2P_inputCheck(workSpace, pubVal_x, pubVal_y, sharedSecret, sharedSecretLength, confirmationMAC, confirmationMACLength)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actSPAKE2PCalcSharedSecret(&(workSpace->workSpaceSpake), &(workSpace->workSpaceSHA),
                                           &(workSpace->workSpaceHKDF), &(workSpace->workSpaceCMAC),
                                           pubVal_x, pubVal_y, pubValLength,
                                           sharedSecret, confirmationMAC, workSpace->header.watchdog);

    if(actRetVal != actOK){
      retVal = esl_SPAKE2P_get_ERC_from_actEXCEPTION(actRetVal);

      *sharedSecretLength = 0u;
      *confirmationMACLength = 0u;
    }
    else{
      *sharedSecretLength = ESL_SIZEOF_SHA256_DIGEST / 2u;
      *confirmationMACLength = ESL_SIZEOF_AES128_BLOCK;
      workSpace->workSpaceSpake.algoState = ESL_SPAKE2P_SHARED_SECRET_CALCULATED;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(eslt_ErrorCode) esl_confirmKeySPAKE2P(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceSPAKE2P) workSpace,
  VSECPRIM_P2CONST_PARA(eslt_Byte) mac,
  const eslt_Length macLength){
  eslt_ErrorCode retVal;
  actRETURNCODE actRetVal;
  eslt_Byte confirmationMac[actAES_BLOCK_SIZE];

  if((retVal = esl_confirmKeySPAKE2P_inputCheck(workSpace, mac, macLength)) != ESL_ERC_NO_ERROR){
  }
  else{
    actRetVal = actSPAKE2PConfirmKey(&workSpace->workSpaceSpake, &workSpace->workSpaceCMAC, mac, confirmationMac, workSpace->header.watchdog);

    if(actRetVal != actOK){
      retVal = ESL_ERC_INCORRECT_MAC;
    }

    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->workSpaceSpake);
  }

  return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

