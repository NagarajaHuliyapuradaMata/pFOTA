

#define ACTECTOOLS_SOURCE

#include "actITypes.hpp"
#include "actECTools.hpp"
#include "actUtilities.hpp"
#include "actBigNum.hpp"
#include "actECPoint.hpp"
#include "actECLengthInfo.hpp"

#if(VSECPRIM_ACTECTOOLS_ENABLED == STD_ON)

# define actTAG_SEQUENCE                                              (0x30u)
# define actTAG_INTEGER                                               (0x02u)
# define actTAG_OCTETSTRING                                           (0x04u)

# define actASN1_MIN_VERSION_LEN                                      (0x03u)
# define actASN1_MIN_SEQ_LEN                                          (0x02u)

# define actBASEPOINTENCODING_COMPRESSED_POSITIVE                     (0x02u)
# define actBASEPOINTENCODING_COMPRESSED_NEGATIVE                     (0x03u)
# define actBASEPOINTENCODING_UNCOMPRESSED                            (0x04u)
# define actBASEPOINTENCODING_UNCOMPRESSED_LEADING06                  (0x06u)
# define actBASEPOINTENCODING_UNCOMPRESSED_LEADING07                  (0x07u)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_LOCAL_FUNC(actLengthType) actParseTL(
  VSECPRIM_P2ROMCONST_PARA(actU8) input,
  VSECPRIM_P2VAR_PARA(actLengthType) value_length);

VSECPRIM_LOCAL_FUNC(actLengthType) actParseTLVElement(
  VSECPRIM_P2ROMCONST_PARA(actU8) input,
  actLengthType element_length,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) addr);

VSECPRIM_LOCAL_FUNC(actLengthType) actParseTLVFieldPrime(
  VSECPRIM_P2ROMCONST_PARA(actU8) input,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) addr,
  VSECPRIM_P2VAR_PARA(actLengthType) length);

VSECPRIM_LOCAL_FUNC(actLengthType) actParseTLVPoint(
  VSECPRIM_P2ROMCONST_PARA(actU8) input,
  actLengthType x_y_length,
  VSECPRIM_P2VAR_PARA(actLengthType) tag);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParsePoint(
  VSECPRIM_P2ROMCONST_PARA(actU8) input,
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
  actLengthType pointNumber,
  actLengthType p_bytes,
  actLengthType lengthOfASN1Struct,
  VSECPRIM_P2VAR_PARA(actLengthType) currentIndex);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actECCheckWorkSpaceSize(
  actU16 algo_flag,
  actLengthType p_length,
  actLengthType n_length,
  actLengthType wksp_len);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseSkipSequenceTag(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actLengthType) tagLength,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexData,
  actRETURNCODE retValInErrorCase);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseFieldConstants(
  VSECPRIM_P2CONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actBNRING) field,
  actLengthType dataLengthRR,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexNextDataEntry);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseCurveCoefficient(
  VSECPRIM_P2CONST_PARA(actU8) domain,
  actLengthType dataLength,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) dataAddr,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexNextDataEntry,
  boolean retValDomainExtension);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseCurveParameters(
  VSECPRIM_P2CONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
  actLengthType dataLength,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) addressA,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) addressB,
  boolean retValDomainExtension,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexNextDataEntry);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseSkipUntilFieldPrime(
  VSECPRIM_P2CONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actLengthType) lengthOfASN1Struct,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexData);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseFieldPrime(
  VSECPRIM_P2CONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actLengthType) primeByteLength,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) primeStartAddr,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexNextDataEntry);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseDomainExtension(
  VSECPRIM_P2ROMCONST_PARA(actU8) domainExtension,
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
  actLengthType p_bytes,
  actLengthType n_bytes);

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseSpeedUpExtension(
  VSECPRIM_P2ROMCONST_PARA(actU8) speedupExtension,
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
  actLengthType p_bytes);

VSECPRIM_LOCAL_FUNC(actLengthType) actParseTL(
  VSECPRIM_P2ROMCONST_PARA(actU8) input,
  VSECPRIM_P2VAR_PARA(actLengthType) value_length){
  actLengthType returnLength;

  if(ACT_ROM_R_BYT(input[1]) < 0x80u){
    if(value_length != NULL_PTR){
      *value_length = ACT_ROM_R_BYT(input[1]);
    }
    returnLength = 2u;
  }
  else if(ACT_ROM_R_BYT(input[1]) == 0x81u){
    if(value_length != NULL_PTR){
      *value_length = ACT_ROM_R_BYT(input[2]);
    }
    returnLength = 3u;
  }
  else if(ACT_ROM_R_BYT(input[1]) == 0x82u){
    if(value_length != NULL_PTR){
      *value_length = ((actLengthType)ACT_ROM_R_BYT(input[2]) << 8u) | ACT_ROM_R_BYT(input[3]);
    }
    returnLength = 4u;
  }
  else{
    returnLength = 0u;
  }

  return returnLength;
}

VSECPRIM_LOCAL_FUNC(actLengthType) actParseTLVElement(
  VSECPRIM_P2ROMCONST_PARA(actU8) input,
  actLengthType element_length,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) addr){
  actLengthType parsedElementLength, returnLength;
  actLengthType startIndexElement = actParseTL(input, &parsedElementLength);

  if((startIndexElement == 0u) || (parsedElementLength > element_length)){
    returnLength = 0u;
  }
  else{
    if(addr != NULL_PTR){
      *addr = &input[startIndexElement];
    }
    returnLength = startIndexElement + element_length;
  }

  return returnLength;
}

VSECPRIM_LOCAL_FUNC(actLengthType) actParseTLVFieldPrime(
  VSECPRIM_P2ROMCONST_PARA(actU8) input,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) addr,
  VSECPRIM_P2VAR_PARA(actLengthType) length){
  actLengthType startIndexNextElement;
  actLengthType startIndexPrime = actParseTL(input, length);

  if(startIndexPrime == 0u){
    startIndexNextElement = 0u;
  }
  else{
    while (ACT_ROM_R_BYT(input[startIndexPrime]) == 0u){
      ++startIndexPrime;
      *length = *length - 1u;
    }

    if(addr != NULL_PTR){
      *addr = &input[startIndexPrime];
    }

    startIndexNextElement = startIndexPrime + (*length);
  }

  return startIndexNextElement;
}

VSECPRIM_LOCAL_FUNC(actLengthType) actParseTLVPoint(
  VSECPRIM_P2ROMCONST_PARA(actU8) input,
  actLengthType x_y_length,
  VSECPRIM_P2VAR_PARA(actLengthType) tag){
  actLengthType indexTag, pointLength;
  actLengthType startIndexNextDataEntry;
  indexTag = actParseTL(input, &pointLength);

  if((indexTag == 0u) || (pointLength > ((2u*x_y_length) + 1u))){
    startIndexNextDataEntry = 0u;
  }
  else{
    if(tag != NULL_PTR){
      *tag = ACT_ROM_R_BYT(input[indexTag]);
    }

    switch(ACT_ROM_R_BYT(input[indexTag])){
    case actBASEPOINTENCODING_COMPRESSED_POSITIVE:
    case actBASEPOINTENCODING_COMPRESSED_NEGATIVE:
      {
        startIndexNextDataEntry = indexTag + x_y_length + 1u;
        break;
      }

    case actBASEPOINTENCODING_UNCOMPRESSED:
    case actBASEPOINTENCODING_UNCOMPRESSED_LEADING06:
    case actBASEPOINTENCODING_UNCOMPRESSED_LEADING07:
      {
        startIndexNextDataEntry = indexTag + ((2u * x_y_length) + 1u);
        break;
      }
    default:
      {
        startIndexNextDataEntry = 0u;
        break;
      }
    }
  }
  return startIndexNextDataEntry;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParsePoint(
  VSECPRIM_P2ROMCONST_PARA(actU8) input,
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
  actLengthType pointNumber,
  actLengthType p_bytes,
  actLengthType lengthOfASN1Struct,
  VSECPRIM_P2VAR_PARA(actLengthType) currentIndex){
  actRETURNCODE retVal;
  actLengthType pointUncompressedTag, startIndexNextPoint;

  if(ACT_ROM_BYT(input) != actTAG_OCTETSTRING){
    retVal = actEXCEPTION_SPEEDUP_EXT;
  }
  else{
    startIndexNextPoint = actParseTLVPoint(input, p_bytes, &pointUncompressedTag);
    if((startIndexNextPoint == 0u) || (pointUncompressedTag < actBASEPOINTENCODING_UNCOMPRESSED) ||
        ((*currentIndex + startIndexNextPoint) > lengthOfASN1Struct)){
      retVal = actEXCEPTION_SPEEDUP_EXT;
    }
    else{
      if(pointNumber == 0u)
      {
        Curve->prec_first = input;
      }

      *currentIndex += startIndexNextPoint;
      retVal = actOK;
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actECCheckWorkSpaceSize(
  actU16 algo_flag,
  actLengthType p_length,
  actLengthType n_length,
  actLengthType wksp_len){
  actRETURNCODE result = actOK;
  actLengthType max_length = 0u;

  if((algo_flag != 0u) && (algo_flag < actEC_ALGO_FLAG_BDKA)){
    max_length = sizeof(actECPSTRUCT);
  }
  else if(algo_flag == actEC_ALGO_FLAG_BDKA){
    max_length = (actECBDWksp(p_length, n_length) * actBN_BYTES_PER_DIGIT) + sizeof(actECCURVE);
  }
  else if(algo_flag == actEC_ALGO_FLAG_SPAKE2P){
    max_length = sizeof(actSPAKE2PPreambleStruct);
  }
  else{
    result = actEXCEPTION_ALGOID;
  }

  if(result == actOK){
    if(wksp_len < max_length){
      result = actEXCEPTION_MEMORY;
    }
  }

  return result;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseSkipSequenceTag(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actLengthType) tagLength,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexData,
  actRETURNCODE retValInErrorCase){
  actRETURNCODE retVal = actOK;

  if(ACT_ROM_BYT(domain) != actTAG_SEQUENCE){
    retVal = retValInErrorCase;
  }
  else{
    *startIndexData = actParseTL(domain, tagLength);
    if(*startIndexData == 0u){
      retVal = retValInErrorCase;
    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseFieldConstants(
  VSECPRIM_P2CONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actBNRING) field,
  actLengthType dataLengthRR,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexNextDataEntry){
  actRETURNCODE retVal;
  actLengthType currentIndex, startIndexNextDataEntryLocal = 0u;
  actLengthType digitLengthRR = actBNGetDigitLength(dataLengthRR);

  retVal = actOK;

  if(ACT_ROM_BYT(domain) != actTAG_OCTETSTRING){
    retVal = actEXCEPTION_DOMAIN_EXT;
  }
  else{
    startIndexNextDataEntryLocal = actParseTLVElement(domain, dataLengthRR, (VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)))NULL_PTR);

    if(startIndexNextDataEntryLocal == 0u){
      retVal = actEXCEPTION_DOMAIN_EXT;
    }
  }

  if(retVal == actOK){
    currentIndex = startIndexNextDataEntryLocal;

    actBNSetOctetStringROM(field->RR, digitLengthRR, &domain[currentIndex - dataLengthRR], dataLengthRR);

    if(ACT_ROM_BYT(&domain[currentIndex]) != actTAG_OCTETSTRING){
      retVal = actEXCEPTION_DOMAIN_EXT;
    }
    else{
      startIndexNextDataEntryLocal = actParseTLVElement(&domain[currentIndex], actBN_BYTES_PER_DIGIT, (VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)))NULL_PTR);

      if(startIndexNextDataEntryLocal == 0u)
      {
        retVal = actEXCEPTION_DOMAIN_EXT;
      }
      else
      {
        currentIndex += startIndexNextDataEntryLocal;
        actBNSetOctetStringROM(&(field->m_bar), 1, &domain[currentIndex - actBN_BYTES_PER_DIGIT], actBN_BYTES_PER_DIGIT);
        *startIndexNextDataEntry = currentIndex;
      }
    }
  }
  return retVal;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseCurveCoefficient(
  VSECPRIM_P2CONST_PARA(actU8) domain,
  actLengthType dataLength,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) dataAddr,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexNextDataEntry,
  boolean retValDomainExtension){
  actRETURNCODE retVal;
  actRETURNCODE retValError;

  retVal = actOK;
  retValError = ((retValDomainExtension == TRUE) ? actEXCEPTION_DOMAIN_EXT : actEXCEPTION_DOMAIN);

  if(ACT_ROM_BYT(domain) != actTAG_OCTETSTRING){
    retVal = retValError;
  }
  else{
    *startIndexNextDataEntry = actParseTLVElement(domain, dataLength, dataAddr);

    if(*startIndexNextDataEntry == 0u){
      retVal = retValError;
    }
  }
  return retVal;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseCurveParameters(
  VSECPRIM_P2CONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
  actLengthType dataLength,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) addressA,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) addressB,
  boolean retValDomainExtension,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexNextDataEntry){
  actRETURNCODE retVal;
  actRETURNCODE retValError;

  actLengthType startIndexNextDataEntryLocal, tag, currentIndex = 0u;

  retValError = ((retValDomainExtension == TRUE) ? actEXCEPTION_DOMAIN_EXT : actEXCEPTION_DOMAIN);

  retVal = actParseCurveCoefficient(domain, dataLength, addressA, &startIndexNextDataEntryLocal, retValDomainExtension);

  if(retVal == actOK){
    currentIndex = startIndexNextDataEntryLocal;
    retVal = actParseCurveCoefficient(&domain[currentIndex], dataLength, addressB, &startIndexNextDataEntryLocal, retValDomainExtension);
  }
  else{
    retVal = retValError;
  }

  if(retVal == actOK){
    currentIndex += startIndexNextDataEntryLocal;

    if(ACT_ROM_BYT(&domain[currentIndex]) != actTAG_OCTETSTRING){
      retVal = retValError;
    }
    else{
      startIndexNextDataEntryLocal = actParseTLVPoint(&domain[currentIndex], dataLength, &tag);

      if((startIndexNextDataEntryLocal == 0u) || (tag < 0x04u))
      {
        retVal = retValError;
      }
      else
      {
        currentIndex += startIndexNextDataEntryLocal;
        *startIndexNextDataEntry = currentIndex;

        if(Curve != NULL_PTR)
        {
          Curve->G_R = &domain[currentIndex - (2u * dataLength)];
        }
      }

    }
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseSkipUntilFieldPrime(
 VSECPRIM_P2CONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actLengthType) lengthOfASN1Struct,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexData){
  actRETURNCODE retVal;
  actLengthType startIndexDataLocal, currentIndex, tagLengthLocal;
  const actU8 PRIME_OID_TLV[] = { 0x06u, 0x07u, 0x2au, 0x86u, 0x48u, 0xceu, 0x3du, 0x01u, 0x01u };

  startIndexDataLocal = 0u;
  currentIndex = 0u;

  retVal = actParseSkipSequenceTag(domain, lengthOfASN1Struct, &startIndexDataLocal, actEXCEPTION_DOMAIN);

  *lengthOfASN1Struct += startIndexDataLocal;

  if(*lengthOfASN1Struct < (startIndexDataLocal + actASN1_MIN_VERSION_LEN + actASN1_MIN_SEQ_LEN + sizeof(PRIME_OID_TLV))){
    retVal = actEXCEPTION_DOMAIN;
  }

  if(retVal == actOK){
    currentIndex = startIndexDataLocal;

    if((ACT_ROM_BYT(&domain[currentIndex]) != actTAG_INTEGER) ||
        (ACT_ROM_BYT(&domain[currentIndex + 1u]) != 0x01u) ||
        (ACT_ROM_BYT(&domain[currentIndex + 2u]) != 0x01u)){
      retVal = actEXCEPTION_DOMAIN;
    }
    else{
      currentIndex += 3u;
      retVal = actParseSkipSequenceTag(&domain[currentIndex], &tagLengthLocal, &startIndexDataLocal, actEXCEPTION_DOMAIN);

    }
  }

  if(retVal == actOK){
    currentIndex += startIndexDataLocal;

    if(actMemcmp_ROM(&domain[currentIndex], PRIME_OID_TLV, sizeof(PRIME_OID_TLV)) == FALSE){
      retVal = actEXCEPTION_DOMAIN;
    }
    else{
      currentIndex += sizeof(PRIME_OID_TLV);
      *startIndexData = currentIndex;
    }
  }
  return retVal;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseFieldPrime(
  VSECPRIM_P2CONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actLengthType) primeByteLength,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) primeStartAddr,
  VSECPRIM_P2VAR_PARA(actLengthType) startIndexNextDataEntry){
  actLengthType tagLength;
  actRETURNCODE retVal = actOK;

  if(ACT_ROM_BYT(domain) != actTAG_INTEGER){
    retVal = actEXCEPTION_DOMAIN;
  }
  else{
    if(startIndexNextDataEntry != NULL_PTR){
      *startIndexNextDataEntry = actParseTLVFieldPrime(domain, primeStartAddr, primeByteLength);
      if(*startIndexNextDataEntry == 0u)
      {
        retVal = actEXCEPTION_DOMAIN;
      }
    }
    else{
      tagLength = actParseTLVFieldPrime(domain, primeStartAddr, primeByteLength);
      if(tagLength == 0u)
      {
        retVal = actEXCEPTION_DOMAIN;
      }
    }
  }
  return retVal;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseDomainExtension(
  VSECPRIM_P2ROMCONST_PARA(actU8) domainExtension,
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
  actLengthType p_bytes,
  actLengthType n_bytes){
  actRETURNCODE retVal;
  actLengthType startIndexData, lengthOfANS1Struct, startIndexNextDataEntry, currentIndex;

  VSECPRIM_P2VAR_PARA(actBNRING) p_field = &(Curve->p_field);
  VSECPRIM_P2VAR_PARA(actBNRING) n_field = &(Curve->n_field);

  startIndexData = 0u;
  lengthOfANS1Struct = 0u;
  startIndexNextDataEntry = 0u;
  currentIndex = 0u;

  retVal = actParseSkipSequenceTag(domainExtension, &lengthOfANS1Struct, &startIndexData, actEXCEPTION_DOMAIN_EXT);

  lengthOfANS1Struct += startIndexData;

  if(retVal == actOK){
    currentIndex = startIndexData;
    retVal = actParseSkipSequenceTag(&domainExtension[currentIndex], (VSECPRIM_P2VAR_PARA(actLengthType))NULL_PTR, &startIndexData, actEXCEPTION_DOMAIN_EXT);
  }

  if((retVal == actOK) && ((currentIndex + startIndexData) < lengthOfANS1Struct)){
    currentIndex += startIndexData;
    retVal = actParseFieldConstants(&domainExtension[currentIndex], p_field, p_bytes, &startIndexNextDataEntry);
  }
  else{
    retVal = actEXCEPTION_DOMAIN_EXT;
  }

  if((retVal == actOK) && ((currentIndex + startIndexNextDataEntry) < lengthOfANS1Struct)){
    currentIndex += startIndexNextDataEntry;

    retVal = actParseSkipSequenceTag(&domainExtension[currentIndex], (VSECPRIM_P2VAR_PARA(actLengthType))NULL_PTR, &startIndexData, actEXCEPTION_DOMAIN_EXT);
  }
  else{
    retVal = actEXCEPTION_DOMAIN_EXT;
  }

  if((retVal == actOK) && ((currentIndex + startIndexData) < lengthOfANS1Struct)){
    currentIndex += startIndexData;
    retVal = actParseCurveParameters(&domainExtension[currentIndex], Curve, p_bytes,
                                     &Curve->a_R, &Curve->b_R, TRUE, &startIndexNextDataEntry);
  }
  else{
    retVal = actEXCEPTION_DOMAIN_EXT;
  }

  if((retVal == actOK) && ((currentIndex + startIndexNextDataEntry) < lengthOfANS1Struct)){
    currentIndex += startIndexNextDataEntry;

    retVal = actParseSkipSequenceTag(&domainExtension[currentIndex], (VSECPRIM_P2VAR_PARA(actLengthType))NULL_PTR, &startIndexData, actEXCEPTION_DOMAIN_EXT);
  }
  else{
    retVal = actEXCEPTION_DOMAIN_EXT;
  }

  if((retVal == actOK) && ((currentIndex + startIndexData) < lengthOfANS1Struct)){
    currentIndex += startIndexData;
    retVal = actParseFieldConstants(&domainExtension[currentIndex], n_field, n_bytes, &startIndexNextDataEntry);
  }
  else{
    retVal = actEXCEPTION_DOMAIN_EXT;
  }

  return retVal;
}

VSECPRIM_LOCAL_FUNC(actRETURNCODE) actParseSpeedUpExtension(
  VSECPRIM_P2ROMCONST_PARA(actU8) speedupExtension,
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
  actLengthType p_bytes){
  actRETURNCODE retVal;
  actLengthType i, startIndexData, startIndexNextDataEntry, currentIndex, lengthOfANS1Struct;
  actU32 num_of_points;

  startIndexData = 0u;
  currentIndex = 0u;
  lengthOfANS1Struct = 0u;

  retVal = actParseSkipSequenceTag(speedupExtension, &lengthOfANS1Struct, &startIndexData, actEXCEPTION_SPEEDUP_EXT);

  lengthOfANS1Struct += startIndexData;

  if(retVal == actOK){
    currentIndex = startIndexData;
    if(ACT_ROM_BYT(&speedupExtension[currentIndex]) != actTAG_OCTETSTRING){
      retVal = actEXCEPTION_SPEEDUP_EXT;
    }
    else{
      startIndexNextDataEntry = actParseTLVElement(&speedupExtension[currentIndex], 1,
                                                   (VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)))NULL_PTR);

      if((startIndexNextDataEntry == 0u) || ((currentIndex + startIndexNextDataEntry) > lengthOfANS1Struct))
      {
        retVal = actEXCEPTION_SPEEDUP_EXT;
      }
      else
      {
        currentIndex += startIndexNextDataEntry;
        Curve->groups = ACT_ROM_BYT(&speedupExtension[currentIndex - 1u]);
      }
    }
  }

  if(retVal == actOK){
    if(Curve->groups < 2u){
      retVal = actEXCEPTION_SPEEDUP_EXT;
    }
    else{
      retVal = actParseSkipSequenceTag(&speedupExtension[currentIndex], (VSECPRIM_P2VAR_PARA(actLengthType))NULL_PTR,
                                       &startIndexData, actEXCEPTION_SPEEDUP_EXT);
      if((currentIndex + startIndexData) > lengthOfANS1Struct)
      {
        retVal = actEXCEPTION_SPEEDUP_EXT;
      }
      else
      {
        currentIndex += startIndexData;
      }
    }
  }

  num_of_points = (actLengthType)(1UL << Curve->groups);
  for (i = 0u; i < num_of_points; ++i){
    if(retVal == actOK){
      retVal = actParsePoint(&speedupExtension[currentIndex], Curve, i, p_bytes,
                             lengthOfANS1Struct, &currentIndex);
    }
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actECParseDomain(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2VAR_PARA(actLengthType) p_bytes,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) p_addr,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) a_addr,
  VSECPRIM_P2VAR_PARA(actLengthType) n_bytes,
  VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)) n_addr){
  actRETURNCODE retVal;
  actLengthType startIndexData = 0u;
  actLengthType startIndexNextDataEntry = 0u;
  actLengthType currentIndex = 0u;
  actLengthType localTagLength = 0u;
  actLengthType lengthOfASN1Struct = 0u;

  *p_bytes = 0u;
  *n_bytes = 0u;

  retVal = actParseSkipUntilFieldPrime(domain, &lengthOfASN1Struct, &startIndexData);

  if((retVal == actOK)){
    currentIndex = startIndexData;
    retVal = actParseFieldPrime(&domain[currentIndex], p_bytes, p_addr, &startIndexNextDataEntry);

    if(*p_bytes > actECC_MAX_BYTE_LEN){
      retVal = actEXCEPTION_DOMAIN;
    }
  }

  if((retVal == actOK) && ((currentIndex + startIndexNextDataEntry) < lengthOfASN1Struct)){
    currentIndex += startIndexNextDataEntry;
    retVal = actParseSkipSequenceTag(&domain[currentIndex], &localTagLength, &startIndexData, actEXCEPTION_DOMAIN);
  }
  else{
    retVal = actEXCEPTION_DOMAIN;
  }

  if((retVal == actOK) && ((currentIndex + localTagLength) < lengthOfASN1Struct)){
    currentIndex += startIndexData;
    retVal = actParseCurveParameters(&domain[currentIndex], (VSECPRIM_P2VAR_PARA(actECCURVE))NULL_PTR, *p_bytes,
                                     a_addr, (VSECPRIM_P2VAR_PARA(VSECPRIM_P2CONST_PARA(actU8)))NULL_PTR, FALSE, &startIndexNextDataEntry);
  }
  else{
    retVal = actEXCEPTION_DOMAIN;
  }

  if((retVal == actOK) && ((currentIndex + startIndexNextDataEntry) < lengthOfASN1Struct)){
    currentIndex += startIndexNextDataEntry;
    retVal = actParseFieldPrime(&domain[currentIndex], n_bytes, n_addr, (VSECPRIM_P2VAR_PARA(actLengthType))NULL_PTR);

    if(*n_bytes > actECC_MAX_BYTE_LEN){
      retVal = actEXCEPTION_DOMAIN;
    }
  }
  else{
    retVal = actEXCEPTION_DOMAIN;
  }

  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actECInit(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext,
  VSECPRIM_P2ROMCONST_PARA(actU8) speedup_ext,
  actU16 algo_flag,
  VSECPRIM_P2VAR_PARA(actECPBasicStruct) wksp,
  actLengthType wksp_len){
  actRETURNCODE result;
  VSECPRIM_P2CONST_PARA(actU8) p_addr;
  VSECPRIM_P2CONST_PARA(actU8) a_addr;
  VSECPRIM_P2CONST_PARA(actU8) n_addr;
  actLengthType p_bytes, n_bytes, p_length, n_length;

  VSECPRIM_P2VAR_PARA(actBNDIGIT) p_minus_3;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a;

  VSECPRIM_P2VAR_PARA(actECCURVE) Curve = &(wksp->Curve);
  VSECPRIM_P2VAR_PARA(actBNRING) p_field = &Curve->p_field;
  VSECPRIM_P2VAR_PARA(actBNRING) n_field = &Curve->n_field;

  result = actECParseDomain(domain, &p_bytes, &p_addr, &a_addr, &n_bytes, &n_addr);

  if(result == actOK){
    p_length = actBNGetDigitLength(p_bytes);
    n_length = actBNGetDigitLength(n_bytes);

    result = actECCheckWorkSpaceSize(algo_flag, p_length, n_length, wksp_len);

    if(result == actOK){
      p_field->m = wksp->p_field_modulus;
      p_field->RR = wksp->p_field_RR;
      n_field->m = wksp->n_field_modulus;
      n_field->RR = wksp->n_field_RR;

      Curve->t[0] = wksp->Curve_tmp0;
      Curve->t[1] = wksp->Curve_tmp1;
      Curve->t[2] = wksp->Curve_tmp2;
      Curve->t[3] = wksp->Curve_tmp3;

      p_field->m_length = p_length;
      p_field->m_byte_length = p_bytes;
      n_field->m_length = n_length;
      n_field->m_byte_length = n_bytes;

      actBNSetOctetStringROM(p_field->m, p_length, p_addr, p_bytes);

      p_minus_3 = Curve->t[0];
      a = Curve->t[1];

      actBNSetOctetStringROM(a, p_length, a_addr, p_bytes);
      actBNSetZero(p_minus_3, p_length);
      p_minus_3[0] = 3;
      actBNSub(p_field->m, p_minus_3, p_minus_3, p_length);
      if(actBNCompare(a, p_minus_3, p_length) == actCOMPARE_EQUAL)
      {
        Curve->a_equals_p_minus_3 = TRUE;
      }
      else
      {
        Curve->a_equals_p_minus_3 = FALSE;
      }

      actBNSetOctetStringROM(n_field->m, n_length, n_addr, n_bytes);

      result = actParseDomainExtension(domain_ext, Curve, p_bytes, n_bytes);
    }

    if((result == actOK) && (speedup_ext != NULL_PTR)){
        result = actParseSpeedUpExtension(speedup_ext, Curve, p_bytes);
    }
  }

# if(actBN_MONT_MUL_VERSION==1)

    p_field->prime_structure = 0u;
    n_field->prime_structure = 0u;
# endif

# if(actBN_MOD_EXP_WINDOW_SIZE==0)
    p_field->window_size = actEC_MOD_EXP_WINDOW_SIZE;
    n_field->window_size = actEC_MOD_EXP_WINDOW_SIZE;
# endif

  return result;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

