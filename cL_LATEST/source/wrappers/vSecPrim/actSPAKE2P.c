

#define ACTISPAKE2P_SOURCE

#include "actISPAKE2P.hpp"
#include "actECTools.hpp"
#include "actECPoint.hpp"
#include "actECLengthInfo.hpp"
#include "actISHA2_32.hpp"
#include "actIHKDF_HMAC_SHA256.hpp"
#include "actICMACAES.hpp"
#include "actUtilities.hpp"
#include "actConfig.hpp"

#if(VSECPRIM_ACTSPAKE2P_ENABLED == STD_ON)

#define actSPAKE2P_CURVEP256_P_BYTE_LENGTH                           (32u)
#define actSPAKE2P_32BIT_BYTE_LENGTH                                 (4u)

#define actSSPAKE2PEncodedPointLength(fieldPrimeLength)              ((2u*fieldPrimeLength) + 1u)

#define VSECPRIM_START_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_ROM(VSECPRIM_LOCAL, actU8) confirmationKeyString[16] = {
  0x43, 0x6f, 0x6e, 0x66, 0x69, 0x72, 0x6d, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x4b, 0x65, 0x79, 0x73
};

#define VSECPRIM_STOP_SEC_CONST_8BIT
#include "CompilerCfg_vSecPrim.hpp"

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSPAKE2PCalcCommonValues(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actSPAKE2PHashPoint(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) wsHash
   ,  VSECPRIM_P2CONST_PARA(actECPprojectivePointBuffer) point
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actSPAKE2PHashTT(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) wsHash
   ,  VSECPRIM_P2VAR_PARA(actU8) hashTT
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(void) actSPAKE2PCalcCmac(
  VSECPRIM_P2CONST_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2CONST_PARA(actU8) macKey
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) pointXCoord
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) pointYCoord
   ,  VSECPRIM_P2VAR_PARA(actU8) pointBuffer
   ,  VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) wsCMAC
   ,  VSECPRIM_P2VAR_PARA(actU8) mac
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actSPAKE2PCalcCommonValues(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;
  actECPOINT publicValueOtherParty, curvePoint, result, Z, V, L;
  actLengthType p_length = wsSpake->baseData.Curve.p_field.m_length;

  publicValueOtherParty.x = wsSpake->tmpVariables.tmp2.xcoord;
  publicValueOtherParty.y = wsSpake->tmpVariables.tmp2.ycoord;
  publicValueOtherParty.z = wsSpake->tmpVariables.tmp2.zcoord;
  publicValueOtherParty.is_affine = FALSE;
  publicValueOtherParty.is_infinity = FALSE;

  Z.x = wsSpake->Z.xcoord;
  Z.y = wsSpake->Z.ycoord;
  Z.z = wsSpake->Z.zcoord;
  Z.is_affine = FALSE;
  Z.is_infinity = FALSE;

  V.x = wsSpake->V.xcoord;
  V.y = wsSpake->V.ycoord;
  V.z = wsSpake->V.zcoord;
  V.is_affine = FALSE;
  V.is_infinity = FALSE;

  L.x = wsSpake->L.xcoord;
  L.y = wsSpake->L.ycoord;
  L.is_affine = TRUE;
  L.is_infinity = FALSE;

  result.x = wsSpake->tmp1.xcoord;
  result.y = wsSpake->tmp1.ycoord;
  result.z = wsSpake->tmp1.zcoord;
  result.is_affine = FALSE;
  result.is_infinity = FALSE;

  if(wsSpake->isPartyA == TRUE){
    actBNCopy(publicValueOtherParty.x, wsSpake->pB.xcoord, p_length);
    actBNCopy(publicValueOtherParty.y, wsSpake->pB.ycoord, p_length);
    actBNSetOne(publicValueOtherParty.z, p_length);

    curvePoint.x = wsSpake->N.xcoord;
    curvePoint.y = wsSpake->N.ycoord;
    curvePoint.is_affine = TRUE;
    curvePoint.is_infinity = FALSE;

    actECPToMont(&publicValueOtherParty, &(wsSpake->baseData.Curve), watchdog);
    actECPToMont(&curvePoint, &(wsSpake->baseData.Curve), watchdog);

    actECPMult(&curvePoint, wsSpake->w0, &result, &(wsSpake->baseData.Curve), watchdog);
    actECPSub(&publicValueOtherParty, &result, &(wsSpake->baseData.Curve), watchdog);
    actECPMult(&publicValueOtherParty, wsSpake->randomNumber, &Z, &(wsSpake->baseData.Curve), watchdog);

    retVal = actECPToAffineFromMont(&Z, &(wsSpake->baseData.Curve), FALSE, watchdog);

    if(retVal == actOK){
      actECPMult(&publicValueOtherParty, wsSpake->w1, &V, &(wsSpake->baseData.Curve), watchdog);
      retVal = actECPToAffineFromMont(&V, &(wsSpake->baseData.Curve), FALSE, watchdog);
    }
  }
  else{
    actBNCopy(publicValueOtherParty.x, wsSpake->pA.xcoord, p_length);
    actBNCopy(publicValueOtherParty.y, wsSpake->pA.ycoord, p_length);
    actBNSetOne(publicValueOtherParty.z, p_length);

    curvePoint.x = wsSpake->M.xcoord;
    curvePoint.y = wsSpake->M.ycoord;
    curvePoint.is_affine = TRUE;
    curvePoint.is_infinity = FALSE;

    actECPToMont(&publicValueOtherParty, &(wsSpake->baseData.Curve), watchdog);
    actECPToMont(&curvePoint, &(wsSpake->baseData.Curve), watchdog);

    actECPMult(&curvePoint, wsSpake->w0, &result, &(wsSpake->baseData.Curve), watchdog);
    actECPSub(&publicValueOtherParty, &result, &(wsSpake->baseData.Curve), watchdog);
    actECPMult(&publicValueOtherParty, wsSpake->randomNumber, &Z, &(wsSpake->baseData.Curve), watchdog);

    retVal = actECPToAffineFromMont(&Z, &(wsSpake->baseData.Curve), FALSE, watchdog);

    if(retVal == actOK){
      actECPToMont(&L, &(wsSpake->baseData.Curve), watchdog);
      actECPMult(&L, wsSpake->randomNumber, &V, &(wsSpake->baseData.Curve), watchdog);
      retVal = actECPToAffineFromMont(&V, &(wsSpake->baseData.Curve), FALSE, watchdog);
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(void) actSPAKE2PHashPoint(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) wsHash
   ,  VSECPRIM_P2CONST_PARA(actECPprojectivePointBuffer) point
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 lengthBuffer[4];
  actU8 allZeroBuffer[4];
  actU8 encodingByte = 0x04u;

  actLengthType p_length = wsSpake->baseData.Curve.p_field.m_length;
  actLengthType p_bytes = wsSpake->baseData.Curve.p_field.m_byte_length;

  actU8 * tmpBuffer = wsSpake->pointToByteString;

  actMemClear(allZeroBuffer, 4);

  actU32toLE(lengthBuffer, ((2u * p_bytes) + 1u));
  (void)actSHA256Update(wsHash, lengthBuffer, 4, watchdog);
  (void)actSHA256Update(wsHash, allZeroBuffer, 4, watchdog);

  (void)actSHA256Update(wsHash, &encodingByte, 1, watchdog);

  actBNOctetString(tmpBuffer, p_bytes, point->xcoord, p_length);
  (void)actSHA256Update(wsHash, tmpBuffer, p_bytes, watchdog);

  actBNOctetString(tmpBuffer, p_bytes, point->ycoord, p_length);
  (void)actSHA256Update(wsHash, tmpBuffer, p_bytes, watchdog);
}

VSECPRIM_LOCAL_FUNC(void) actSPAKE2PHashTT(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) wsHash
   ,  VSECPRIM_P2VAR_PARA(actU8) hashTT
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 lengthBuffer[actSPAKE2P_32BIT_BYTE_LENGTH];
  actU8 allZeroBuffer[actSPAKE2P_32BIT_BYTE_LENGTH];

  actLengthType n_length = wsSpake->baseData.Curve.n_field.m_length;
  actLengthType n_bytes = wsSpake->baseData.Curve.n_field.m_byte_length;

  actMemClear(allZeroBuffer, actSPAKE2P_32BIT_BYTE_LENGTH);

  if(wsSpake->setAdditionalInformationWasCalled == FALSE){
    (void)actSHA256Init(wsHash);
  }

  actSPAKE2PHashPoint(wsSpake, wsHash, &wsSpake->pA, watchdog);
  actSPAKE2PHashPoint(wsSpake, wsHash, &wsSpake->pB, watchdog);
  actSPAKE2PHashPoint(wsSpake, wsHash, &wsSpake->Z, watchdog);
  actSPAKE2PHashPoint(wsSpake, wsHash, &wsSpake->V, watchdog);

  actU32toLE(lengthBuffer, n_bytes);
  (void)actSHA256Update(wsHash, lengthBuffer, actSPAKE2P_32BIT_BYTE_LENGTH, watchdog);
  (void)actSHA256Update(wsHash, allZeroBuffer, actSPAKE2P_32BIT_BYTE_LENGTH, watchdog);

  actBNOctetString(wsSpake->pointToByteString, n_bytes, wsSpake->w0, n_length);
  (void)actSHA256Update(wsHash, wsSpake->pointToByteString, n_bytes, watchdog);

  (void)actSHA256Finalize(wsHash, hashTT, watchdog);
}

VSECPRIM_LOCAL_FUNC(void) actSPAKE2PCalcCmac(
  VSECPRIM_P2CONST_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2CONST_PARA(actU8) macKey
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) pointXCoord
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) pointYCoord
   ,  VSECPRIM_P2VAR_PARA(actU8) pointBuffer
   ,  VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) wsCMAC
   ,  VSECPRIM_P2VAR_PARA(actU8) mac
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actU8 encodingByte = 0x04u;
  actLengthType p_length = wsSpake->baseData.Curve.p_field.m_length;
  actLengthType p_bytes = wsSpake->baseData.Curve.p_field.m_byte_length;

  (void)actCMACAESInit(wsCMAC, macKey, actAES128_KEY_SIZE, watchdog);

  (void)actCMACAESUpdate(wsCMAC, &encodingByte, 1u, watchdog);

  actBNOctetString(pointBuffer, p_bytes, pointXCoord, p_length);
  (void)actCMACAESUpdate(wsCMAC, pointBuffer, p_bytes, watchdog);

  actBNOctetString(pointBuffer, p_bytes, pointYCoord, p_length);
  (void)actCMACAESUpdate(wsCMAC, pointBuffer, p_bytes, watchdog);

  (void)actCMACAESFinalize(wsCMAC, mac, watchdog);
}

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PPreambleInit(
  VSECPRIM_P2VAR_PARA(actSPAKE2PPreambleStruct) wksp
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) domain
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext
   ,  actLengthType wksp_len){
  actRETURNCODE retVal;
  actLengthType p_byte_length;

  retVal = actECInit(domain, domain_ext, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR
   ,                    actEC_ALGO_FLAG_SPAKE2P, &(wksp->baseData), wksp_len);

  if(retVal == actOK){
    p_byte_length = wksp->baseData.Curve.p_field.m_byte_length;
    if(p_byte_length != actSPAKE2P_CURVEP256_P_BYTE_LENGTH){
      retVal = actEXCEPTION_LENGTH;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PPreambleCalc(
  VSECPRIM_P2VAR_PARA(actSPAKE2PPreambleStruct) wksp
   ,  VSECPRIM_P2CONST_PARA(actU8) pbkdfOutput
   ,  const actLengthType pbkdfOutputLength
   ,  VSECPRIM_P2VAR_PARA(actU8) w0OutputBuffer
   ,  VSECPRIM_P2VAR_PARA(actLengthType) w0BufferLength
   ,  VSECPRIM_P2VAR_PARA(actU8) w1OutputBuffer
   ,  VSECPRIM_P2VAR_PARA(actLengthType) w1BufferLength
   ,  VSECPRIM_P2VAR_PARA(actU8) pointL
   ,  VSECPRIM_P2VAR_PARA(actLengthType) pointLBufferLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;
  actLengthType wDigitLength;

  actLengthType p_ByteLength = wksp->baseData.Curve.p_field.m_byte_length;
  actLengthType p_DigitLength = wksp->baseData.Curve.p_field.m_length;
  actLengthType n_ByteLength = wksp->baseData.Curve.n_field.m_byte_length;
  actLengthType n_DigitLength = wksp->baseData.Curve.n_field.m_length;

  actECPOINT P, L;

  if((pbkdfOutputLength == 0u) || (pbkdfOutputLength > actSPAKE2P_PREAMBLE_OKM_LENGTH)){
    retVal = actEXCEPTION_INPUT_LENGTH;
  }
  else if((*w0BufferLength < n_ByteLength) ||
           (*w1BufferLength < n_ByteLength) ||
           (*pointLBufferLength < actSSPAKE2PEncodedPointLength(p_ByteLength))){
    retVal = actEXCEPTION_MEMORY;
  }
  else{
    wDigitLength = ((pbkdfOutputLength / 2u) + actBN_BYTES_PER_DIGIT - 1u) / actBN_BYTES_PER_DIGIT;

    actBNSetOctetString(wksp->digitsW0, wDigitLength, pbkdfOutput, (pbkdfOutputLength / 2u));
    actBNSetOctetString(wksp->digitsW1, wDigitLength, &pbkdfOutput[(pbkdfOutputLength / 2u)], (pbkdfOutputLength / 2u));

    retVal = actBNReduce(wksp->digitsW0, wDigitLength, wksp->baseData.n_field_modulus
   ,                        n_DigitLength, wksp->result, watchdog);

    if(retVal == actOK){
      actBNOctetString(w0OutputBuffer, n_ByteLength, wksp->result, n_DigitLength);
      *w0BufferLength = n_ByteLength;

      retVal = actBNReduce(wksp->digitsW1, wDigitLength, wksp->baseData.n_field_modulus
   ,                          n_DigitLength, wksp->result, watchdog);

      if(retVal == actOK)
      {
        actBNOctetString(w1OutputBuffer, n_ByteLength, wksp->result, n_DigitLength);
        *w1BufferLength = n_ByteLength;
      }

    }
  }

  if(retVal == actOK){
    P.x = wksp->basePoint.xcoord;
    P.y = wksp->basePoint.ycoord;

    actBNSetOctetStringROM(P.x, p_DigitLength, wksp->baseData.Curve.G_R, p_ByteLength);
    actBNSetOctetStringROM(P.y, p_DigitLength, &(wksp->baseData.Curve.G_R[p_ByteLength]), p_ByteLength);

    P.is_affine = TRUE;
    P.is_infinity = FALSE;

    L.x = wksp->L.xcoord;
    L.y = wksp->L.ycoord;
    L.z = wksp->L.zcoord;
    L.is_affine = FALSE;
    L.is_infinity = FALSE;

    actECPMult(&P, wksp->result, &L, &wksp->baseData.Curve, watchdog);
    retVal = actECPToAffineFromMont(&L, &wksp->baseData.Curve, FALSE, watchdog);

    if(retVal == actOK){
      pointL[0] = 0x04u;
      actBNOctetString(&pointL[1], p_ByteLength, L.x, p_DigitLength);
      actBNOctetString(&pointL[p_ByteLength + 1u], p_ByteLength, L.y, p_DigitLength);
      *pointLBufferLength = actSSPAKE2PEncodedPointLength(p_ByteLength);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PInit(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wksp
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) domain
   ,  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext
   ,  VSECPRIM_P2CONST_PARA(actU8) pointM
   ,  const actLengthType mlength
   ,  VSECPRIM_P2CONST_PARA(actU8) pointN
   ,  const actLengthType nlength
   ,  actLengthType wksp_len){
  actRETURNCODE retVal;
  actLengthType p_bytes;

  retVal = actECInit(domain, domain_ext, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR
   ,                    actEC_ALGO_FLAG_SPAKE2P, &(wksp->baseData), wksp_len);

  if(retVal == actOK){
    p_bytes = wksp->baseData.Curve.p_field.m_byte_length;

    if(p_bytes != actSPAKE2P_CURVEP256_P_BYTE_LENGTH){
      retVal = actEXCEPTION_LENGTH;
    }

    else if((mlength != actSSPAKE2PEncodedPointLength(p_bytes)) ||
             (nlength != actSSPAKE2PEncodedPointLength(p_bytes))){
      retVal = actEXCEPTION_INPUT_LENGTH;
    }
    else{
      actBNSetOctetString(wksp->M.xcoord, actBNGetDigitLengthFromBit(actBytesToBits(p_bytes))
   ,                         &pointM[1], p_bytes);
      actBNSetOctetString(wksp->M.ycoord, actBNGetDigitLengthFromBit(actBytesToBits(p_bytes))
   ,                         &pointM[p_bytes + 1u], p_bytes);
      actBNSetOne(wksp->M.zcoord, actBNGetDigitLengthFromBit(actBytesToBits(p_bytes)));

      actBNSetOctetString(wksp->N.xcoord, actBNGetDigitLengthFromBit(actBytesToBits(p_bytes))
   ,                         &pointN[1], p_bytes);
      actBNSetOctetString(wksp->N.ycoord, actBNGetDigitLengthFromBit(actBytesToBits(p_bytes))
   ,                         &pointN[p_bytes + 1u], p_bytes);
      actBNSetOne(wksp->N.zcoord, actBNGetDigitLengthFromBit(actBytesToBits(p_bytes)));
    }
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PSetPreambleData(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2CONST_PARA(actU8) w0
   ,  const actLengthType w0length
   ,  VSECPRIM_P2CONST_PARA(actU8) w1
   ,  const actLengthType w1length
   ,  VSECPRIM_P2CONST_PARA(actU8) pointL
   ,  const actLengthType pointLLength){
  actRETURNCODE retVal = actOK;
  actLengthType p_length, p_bytes, n_bytes;

  actECPOINT P, L;

  n_bytes = wsSpake->baseData.Curve.n_field.m_byte_length;

  p_length = wsSpake->baseData.Curve.p_field.m_length;
  p_bytes = wsSpake->baseData.Curve.p_field.m_byte_length;

  if(w0length != n_bytes){
    retVal = actEXCEPTION_INPUT_LENGTH;
  }
  else{
    actBNSetOctetString(wsSpake->w0, actBNGetDigitLengthFromBit(actBytesToBits(w0length)), w0, w0length);

    P.x = wsSpake->basePoint.xcoord;
    P.y = wsSpake->basePoint.ycoord;

    actBNSetOctetStringROM(P.x, p_length, wsSpake->baseData.Curve.G_R, p_bytes);
    actBNSetOctetStringROM(P.y, p_length, &(wsSpake->baseData.Curve.G_R[p_bytes]), p_bytes);

    if(w1 != NULL_PTR){
      if(w1length != n_bytes)
      {
        retVal = actEXCEPTION_INPUT_LENGTH;
      }
      else
      {
        wsSpake->isPartyA = TRUE;
        actBNSetOctetString(wsSpake->w1, actBNGetDigitLengthFromBit(actBytesToBits(w1length)), w1, w1length);
      }
    }
    else if(pointL != NULL_PTR){
      if(pointLLength != actSSPAKE2PEncodedPointLength(p_bytes))
      {
        retVal = actEXCEPTION_INPUT_LENGTH;
      }
      else
      {
        wsSpake->isPartyA = FALSE;

        L.x = wsSpake->L.xcoord;
        L.y = wsSpake->L.ycoord;

        actBNSetOctetString(L.x, actBNGetDigitLengthFromBit(actBytesToBits(p_bytes))
   ,                           &pointL[1], p_bytes);
        actBNSetOctetString(L.y, actBNGetDigitLengthFromBit(actBytesToBits(p_bytes))
   ,                           &pointL[p_bytes + 1u], p_bytes);
      }
    }
    else{
      retVal = actEXCEPTION_NULL;
    }
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PCalcPubVal(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2VAR_PARA(actU8) pubValXCoordinate
   ,  VSECPRIM_P2VAR_PARA(actU8) pubValYCoordinate
   ,  VSECPRIM_P2VAR_PARA(actLengthType) pubValCoordinateLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;
  actECCURVE * Curve = &(wsSpake->baseData.Curve);

  actECPOINT P, curvePoint, pubVal, multBasePoint;

  actLengthType p_length = wsSpake->baseData.Curve.p_field.m_length;
  actLengthType p_bytes = wsSpake->baseData.Curve.p_field.m_byte_length;

  if(*pubValCoordinateLength < p_bytes){
    retVal = actEXCEPTION_OUTPUT_BUFFER;
  }
  else{
    P.x = wsSpake->basePoint.xcoord;
    P.y = wsSpake->basePoint.ycoord;
    P.is_affine = TRUE;
    P.is_infinity = FALSE;

    multBasePoint.x = wsSpake->kG.xcoord;
    multBasePoint.y = wsSpake->kG.ycoord;
    multBasePoint.z = wsSpake->kG.zcoord;
    multBasePoint.is_affine = FALSE;
    multBasePoint.is_infinity = FALSE;

    retVal = actBNModRandomize(wsSpake->randomNumber, &(Curve->n_field), Curve->t, watchdog);

    if(retVal == actOK){
      if(wsSpake->isPartyA == TRUE)
      {
        pubVal.x = &(wsSpake->pA.xcoord[0]);
        pubVal.y = &(wsSpake->pA.ycoord[0]);
        pubVal.z = &(wsSpake->pA.zcoord[0]);

        curvePoint.x = &(wsSpake->M.xcoord[0]);
        curvePoint.y = &(wsSpake->M.ycoord[0]);
      }
      else
      {
        pubVal.x = &(wsSpake->pB.xcoord[0]);
        pubVal.y = &(wsSpake->pB.ycoord[0]);
        pubVal.z = &(wsSpake->pB.zcoord[0]);

        curvePoint.x = &(wsSpake->N.xcoord[0]);
        curvePoint.y = &(wsSpake->N.ycoord[0]);
      }

      pubVal.is_affine = FALSE;
      pubVal.is_infinity = FALSE;

      curvePoint.is_affine = TRUE;
      curvePoint.is_infinity = FALSE;

      actECPToMont(&curvePoint, Curve, watchdog);

      actECPMult(&P, wsSpake->randomNumber, &multBasePoint, Curve, watchdog);

      actECPMult(&curvePoint, wsSpake->w0, &pubVal, Curve, watchdog);

      actECPAdd(&pubVal, &multBasePoint, Curve, watchdog);
      retVal = actECPToAffineFromMont(&pubVal, Curve, FALSE, watchdog);

      if(retVal == actOK)
      {
        actBNOctetString(pubValXCoordinate, p_bytes, pubVal.x, p_length);
        actBNOctetString(pubValYCoordinate, p_bytes, pubVal.y, p_length);
        *pubValCoordinateLength = p_bytes;
      }
    }
  }

  wsSpake->setAdditionalInformationWasCalled = FALSE;
  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PSetAdditionalInformation(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) wsHash
   ,  VSECPRIM_P2CONST_PARA(actU8) infoA
   ,  const actLengthType infoALength
   ,  VSECPRIM_P2CONST_PARA(actU8) infoB
   ,  const actLengthType infoBLength
   ,  VSECPRIM_P2CONST_PARA(actU8) aad
   ,  const actLengthType aadLength
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal = actOK;
  actU8 lengthBuffer[4];
  actU8 allZeros[4];

  actMemClear(allZeros, 4);
  (void)actSHA256Init(wsHash);

  if((infoA != NULL_PTR) && (infoALength > 0u)){
    actU32toLE(lengthBuffer, infoALength);
    (void)actSHA256Update(wsHash, lengthBuffer, 4, watchdog);
    (void)actSHA256Update(wsHash, allZeros, 4, watchdog);

    (void)actSHA256Update(wsHash, infoA, infoALength, watchdog);
  }

  if((infoB != NULL_PTR) && (infoBLength > 0u)){
    actU32toLE(lengthBuffer, infoBLength);
    (void)actSHA256Update(wsHash, lengthBuffer, 4, watchdog);
    (void)actSHA256Update(wsHash, allZeros, 4, watchdog);

    (void)actSHA256Update(wsHash, infoB, infoBLength, watchdog);
  }

  if(aadLength > actSPAKE2P_MAX_AAD_SIZE){
    wsSpake->aadLength = 0u;
    retVal = actEXCEPTION_INPUT_LENGTH;
  }
  else{
    actMemCpyByteArray(wsSpake->addInHKDF, confirmationKeyString, 16);

    if((aad != NULL_PTR) && (aadLength > 0u)){
      actMemCpyByteArray(&(wsSpake->addInHKDF[16]), aad, aadLength);
      wsSpake->aadLength = aadLength;
    }
    else{
      wsSpake->aadLength = 0u;
    }
  }

  wsSpake->setAdditionalInformationWasCalled = TRUE;
  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PCalcSharedSecret(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) wsHash
   ,  VSECPRIM_P2VAR_PARA(actHKDFSTRUCT) wsHKDF
   ,  VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) wsCMAC
   ,  VSECPRIM_P2CONST_PARA(actU8) pubValXCoordinate
   ,  VSECPRIM_P2CONST_PARA(actU8) pubValYCoordinate
   ,  const actLengthType pubValCoordinateLength
   ,  VSECPRIM_P2VAR_PARA(actU8) sharedSecret
   ,  VSECPRIM_P2VAR_PARA(actU8) confirmationMAC
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;
  actU8 * hashTT = wsSpake->tmpVariables.hashTT;
  actLengthType p_length = wsSpake->baseData.Curve.p_field.m_length;
  actLengthType p_bytes = wsSpake->baseData.Curve.p_field.m_byte_length;

  if(pubValCoordinateLength != p_bytes){
    retVal = actEXCEPTION_INPUT_LENGTH;
  }
  else{
    if(wsSpake->isPartyA == TRUE){
      actBNSetOctetString(wsSpake->pB.xcoord, p_length, pubValXCoordinate, p_bytes);
      actBNSetOctetString(wsSpake->pB.ycoord, p_length, pubValYCoordinate, p_bytes);
    }
    else{
      actBNSetOctetString(wsSpake->pA.xcoord, p_length, pubValXCoordinate, p_bytes);
      actBNSetOctetString(wsSpake->pA.ycoord, p_length, pubValYCoordinate, p_bytes);
    }

    retVal = actSPAKE2PCalcCommonValues(wsSpake, watchdog);

    if(retVal == actOK){
      actSPAKE2PHashTT(wsSpake, wsHash, hashTT, watchdog);

      actMemCpyByteArray(sharedSecret, &hashTT[actHASH_SIZE_SHA256 / 2u], actHASH_SIZE_SHA256 / 2u);

      if(wsSpake->setAdditionalInformationWasCalled == FALSE)
      {
        actMemCpyByteArray(wsSpake->addInHKDF, confirmationKeyString, 16);
        wsSpake->aadLength = 0u;
      }

      actHKDF_HMAC_SHA256_Extract(wsHKDF, hashTT, actHASH_SIZE_SHA256 / 2u, NULL_PTR, 0u, watchdog);

      (void)actHKDF_HMAC_SHA256_Expand(wsHKDF, wsSpake->addInHKDF, (16u + wsSpake->aadLength)
   ,                                      wsSpake->macKeys, 2u * actAES128_KEY_SIZE, watchdog);

      if(wsSpake->isPartyA == TRUE)
      {
        if((wsSpake->ciphersuite & actSPAKE2P_VERSION_MASK) == actSPAKE2P_VERSION_KEY_A_FIRST)
        {
          actSPAKE2PCalcCmac(wsSpake, wsSpake->macKeys, wsSpake->pB.xcoord, wsSpake->pB.ycoord
   ,                            wsSpake->pointToByteString, wsCMAC, confirmationMAC, watchdog);
        }
        else
        {
          actSPAKE2PCalcCmac(wsSpake, &wsSpake->macKeys[actAES128_KEY_SIZE], wsSpake->pB.xcoord, wsSpake->pB.ycoord
   ,                            wsSpake->pointToByteString, wsCMAC, confirmationMAC, watchdog);
        }
      }
      else
      {
        if((wsSpake->ciphersuite & actSPAKE2P_VERSION_MASK) == actSPAKE2P_VERSION_KEY_A_FIRST)
        {
          actSPAKE2PCalcCmac(wsSpake, &wsSpake->macKeys[actAES128_KEY_SIZE], wsSpake->pA.xcoord, wsSpake->pA.ycoord
   ,                            wsSpake->pointToByteString, wsCMAC, confirmationMAC, watchdog);
        }
        else
        {
          actSPAKE2PCalcCmac(wsSpake, wsSpake->macKeys, wsSpake->pA.xcoord, wsSpake->pA.ycoord
   ,                            wsSpake->pointToByteString, wsCMAC, confirmationMAC, watchdog);
        }
      }

    }
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PConfirmKey(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake
   ,  VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) wsCMAC
   ,  VSECPRIM_P2CONST_PARA(actU8) mac
   ,  VSECPRIM_P2VAR_PARA(actU8) recomputedMAC
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actRETURNCODE retVal;

  if(wsSpake->isPartyA == TRUE){
    if((wsSpake->ciphersuite & actSPAKE2P_VERSION_MASK) == actSPAKE2P_VERSION_KEY_A_FIRST){
      actSPAKE2PCalcCmac(wsSpake, &wsSpake->macKeys[actAES128_KEY_SIZE], wsSpake->pA.xcoord, wsSpake->pA.ycoord
   ,                         wsSpake->pointToByteString, wsCMAC, recomputedMAC, watchdog);
    }
    else{
      actSPAKE2PCalcCmac(wsSpake, wsSpake->macKeys, wsSpake->pA.xcoord, wsSpake->pA.ycoord
   ,                         wsSpake->pointToByteString, wsCMAC, recomputedMAC, watchdog);
    }
  }
  else{
    if((wsSpake->ciphersuite & actSPAKE2P_VERSION_MASK) == actSPAKE2P_VERSION_KEY_A_FIRST){
      actSPAKE2PCalcCmac(wsSpake, wsSpake->macKeys, wsSpake->pB.xcoord, wsSpake->pB.ycoord
   ,                         wsSpake->pointToByteString, wsCMAC, recomputedMAC, watchdog);
    }
    else{
      actSPAKE2PCalcCmac(wsSpake, &wsSpake->macKeys[actAES128_KEY_SIZE], wsSpake->pB.xcoord, wsSpake->pB.ycoord
   ,                         wsSpake->pointToByteString, wsCMAC, recomputedMAC, watchdog);
    }
  }

  if(actMemcmp(recomputedMAC, mac, actAES_BLOCK_SIZE) != TRUE){
    retVal = actVERIFICATION_FAILED;
  }
  else{
    retVal = actOK;
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

