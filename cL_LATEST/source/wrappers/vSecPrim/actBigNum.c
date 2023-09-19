

#define ACTBIGNUM_SOURCE

#include "actBigNum.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTBIGNUM_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(void) actBNLoadLE(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) bigNum
   ,  VSECPRIM_P2CONST_PARA(actU8) bytes
   ,  const actU32 byteLength){
  actLengthType b;
  actLengthType offset = 0u;

  for(b = (byteLength / actBN_BYTES_PER_DIGIT); b > 0u; b--){
    actBNDIGIT tmp;

#if(4 == actBN_BYTES_PER_DIGIT)
    tmp = ((actBNDIGIT)(bytes[offset]));
    tmp += ((actBNDIGIT)(bytes[offset + 1u])) << 8;
    tmp += ((actBNDIGIT)(bytes[offset + 2u])) << 16;
    tmp += ((actBNDIGIT)(bytes[offset + 3u])) << 24;
    offset += 4u;
# elif(2 == actBN_BYTES_PER_DIGIT)
    tmp = ((actBNDIGIT)(bytes[offset]));
    offset++;
    tmp += ((actBNDIGIT)(bytes[offset])) << 8;
    offset++;
# elif(1 == actBN_BYTES_PER_DIGIT)
    tmp = ((actBNDIGIT)(bytes[offset]));
    offset++;
#else
#error actBN_BYTES_PER_DIGIT value not supported
#endif

    bigNum[(byteLength / actBN_BYTES_PER_DIGIT) - b] = tmp;
  }
}

VSECPRIM_FUNC(void) actBNStoreLE(
  VSECPRIM_P2VAR_PARA(actU8) bytes
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) bigNum
   ,  const actLengthType bnLength){
  VSECPRIM_REGISTER actU32 b;
  VSECPRIM_P2VAR_PARA(actU8) bytesPtr = bytes;

  for(b = bnLength; b > 0u; b--){
    VSECPRIM_REGISTER actBNDIGIT tmp = *(&bigNum[(bnLength - b)]);

#if(actBN_BYTES_PER_DIGIT == 4)
    bytesPtr[0] = (actU8) (tmp);
    bytesPtr[1] = (actU8) (tmp >> 8);
    bytesPtr[2] = (actU8) (tmp >> 16);
    bytesPtr[3] = (actU8) (tmp >> 24);
    bytesPtr = &bytesPtr[4];
# elif(actBN_BYTES_PER_DIGIT == 2)
    bytesPtr[0] = (actU8) (tmp);
    bytesPtr[1] = (actU8) (tmp >> 8);
    bytesPtr = &bytesPtr[2];
# elif(actBN_BYTES_PER_DIGIT == 1)
    bytesPtr[(bnLength - b)] = (actU8) (tmp);
#else
#error actBN_BYTES_PER_DIGIT value not supported
#endif
  }
}

VSECPRIM_FUNC(void) actBNCopy(VSECPRIM_P2VAR_PARA(actBNDIGIT) a, VSECPRIM_P2CONST_PARA(actBNDIGIT) b, const actLengthType length){
  actLengthType i;

  for(i = 0u; i < length; ++i){
    a[i] = b[i];
  }
}

VSECPRIM_FUNC(actLengthType) actBNGetBitLength(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  const actLengthType length){
  actLengthType bits = 0u;

  if(length > 0u){
    actBNDIGIT high_digit;
    actLengthType i = length - 1u;
    while((a[i] == 0u) && (i > 0u)){
      --i;
    }
    high_digit = a[i];
    bits = i * actBN_BITS_PER_DIGIT;
    while(high_digit > 0u){
      ++bits;
      high_digit >>= 1u;
    }
  }

  return bits;
}

VSECPRIM_FUNC(actRETURNCODE) actBNSetBit(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a
   ,  const actLengthType length
   ,  const actLengthType bit_pos){
  actRETURNCODE retVal = actEXCEPTION_UNKNOWN;
  if(bit_pos >= (actLengthType)(length * actBN_BITS_PER_DIGIT)){
  }
  else{
    a[bit_pos / actBN_BITS_PER_DIGIT] |= (((actBNDIGIT) 1) << (bit_pos % actBN_BITS_PER_DIGIT));
    retVal = actOK;
  }

  return retVal;
}

VSECPRIM_FUNC(void) actBNSet(
  VSECPRIM_P2VAR_PARA( actBNDIGIT ) a
   ,  const actLengthType length
   ,  const actBNDIGIT  value){
   actLengthType i;

   a[0] = value;
   for(i = 1u; i<length; ++i){
      a[i] = 0u;
   }
}

VSECPRIM_FUNC(actU8) actBNIsZero(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  const actLengthType length){
  actU8 retVal = TRUE;
  actLengthType i;

  for(i = 0u; i < length; ++i){
    if(a[i] != 0u){
      retVal = FALSE;
      break;
    }
  }
  return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actBNCompare(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) a
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) b
   ,  const actLengthType length){
  actRETURNCODE retVal = actCOMPARE_EQUAL;
  actLengthType i;

  for(i = 0u; i < length; i++){
    if(a[((length - 1u) - i)] < b[((length - 1u) - i)]){
      retVal = actCOMPARE_SMALLER;
      break;
    }
    else if(a[((length - 1u) - i)] > b[((length - 1u) - i)]){
      retVal = actCOMPARE_LARGER;
      break;
    }
    else{
    }
  }

  return retVal;
}

VSECPRIM_FUNC(void) actBNSetOctetString(
  VSECPRIM_P2VAR_PARA(actBNDIGIT) a
   ,  actLengthType length
   ,  VSECPRIM_P2CONST_PARA(actU8) in
   ,  const actLengthType in_len){
  actLengthType i, digits = in_len / actBN_BYTES_PER_DIGIT;
  actLengthType offset = in_len - 1u;

  actBNSetZero(a, length);
  digits = actMin((actLengthType)length, digits);

  for(i = 0u; i < digits; ++i){
#if(actBN_BYTES_PER_DIGIT == 1)
    a[i] = (actBNDIGIT)in[offset - i];
# elif(actBN_BYTES_PER_DIGIT == 2)
    a[i] = (actBNDIGIT)(((actBNDIGIT)(in[offset - 1u]) << 8) | ((actBNDIGIT)(in[offset])));
    offset -= 2u;
# elif(actBN_BYTES_PER_DIGIT == 4)
    a[i] = (actBNDIGIT)(((((actBNDIGIT)(in[offset - 3u]) << 24) | ((actBNDIGIT)(in[offset - 2u]) << 16)) | ((actBNDIGIT)(in[offset - 1u]) << 8)) | ((actBNDIGIT)(in[offset])));
    offset -= 4u;
#else
#error actBN_BYTES_PER_DIGIT value not supported
#endif
  }

#if(actBN_BYTES_PER_DIGIT != 1)
  if(in_len <= ((actLengthType)length * actBN_BYTES_PER_DIGIT)){
    for(i = in_len % actBN_BYTES_PER_DIGIT; i > 0u; --i){
      a[digits] <<= 8;
      a[digits] |= in[((offset - i) + 1u)];
    }
  }
#endif
}

VSECPRIM_FUNC(void) actBNSetOctetStringROM(
   VSECPRIM_P2VAR_PARA(actBNDIGIT) a, actLengthType length
   ,  VSECPRIM_P2CONST_PARA(actU8) in, const actLengthType in_len){
  actLengthType i, digits = in_len / actBN_BYTES_PER_DIGIT;
  actLengthType offset = in_len - 1u;

  actBNSetZero(a, length);
  digits = actMin((actLengthType)length, digits);

  for(i = 0; i < digits; i++){
#if(actBN_BYTES_PER_DIGIT == 1)
    a[i] = (actBNDIGIT)ACT_ROM_BYT(&in[offset - i]);
# elif(actBN_BYTES_PER_DIGIT == 2)
    a[i] = (actBNDIGIT)(((actBNDIGIT)ACT_ROM_BYT(&in[offset - 1u]) << 8) | (actBNDIGIT)(ACT_ROM_BYT(&in[offset])));
    offset -= 2u;
# elif(actBN_BYTES_PER_DIGIT == 4)
    a[i] = (actBNDIGIT)(((((actBNDIGIT)ACT_ROM_BYT(&in[offset - 3u]) << 24) | ((actBNDIGIT)ACT_ROM_BYT(&in[offset - 2u]) << 16)) | ((actBNDIGIT)ACT_ROM_BYT(&in[offset - 1u]) << 8)) | ((actBNDIGIT)ACT_ROM_BYT(&in[offset])));
    offset -= 4u;
#else
#error actBN_BYTES_PER_DIGIT value not supported
#endif
  }

#if(actBN_BYTES_PER_DIGIT != 1)
  if(in_len <= (actLengthType)(length * actBN_BYTES_PER_DIGIT)){
    for(i = in_len % actBN_BYTES_PER_DIGIT; i > 0u; --i){
      a[digits] <<= 8;
      a[digits] |= ACT_ROM_BYT(&in[((offset - i) + 1u)]);
    }
  }
#endif
}

VSECPRIM_FUNC(void) actBNOctetString(
   VSECPRIM_P2VAR_PARA(actU8) out, actLengthType out_len
   ,  VSECPRIM_P2CONST_PARA(actBNDIGIT) a, const actLengthType length){
  actLengthType i, digits = out_len / actBN_BYTES_PER_DIGIT;
#if(actBN_BYTES_PER_DIGIT != 1)
  actBNDIGIT tmp;
#endif
  actLengthType offset = out_len;

  actMemset(out, 0u, out_len);
  digits = actMin((actLengthType)length, digits);

  for(i = 0; i < digits; ++i){
#if(actBN_BYTES_PER_DIGIT == 1)
    offset--;
    out[offset] = a[i];
# elif(actBN_BYTES_PER_DIGIT == 2)
    tmp = a[i];
    offset--;
    out[offset] = ((actU8) tmp);
    tmp >>= 8;
    offset--;
    out[offset] = ((actU8) tmp);
# elif(actBN_BYTES_PER_DIGIT == 4)
    tmp = a[i];
    offset--;
    out[offset] = ((actU8) tmp);
    tmp >>= 8;
    offset--;
    out[offset] = ((actU8) tmp);
    tmp >>= 8;
    offset--;
    out[offset] = ((actU8) tmp);
    tmp >>= 8;
    offset--;
    out[offset] = ((actU8) tmp);
#else
#error actBN_BYTES_PER_DIGIT value not supported
#endif
  }

#if(actBN_BYTES_PER_DIGIT != 1)
  if(out_len <= (actLengthType)(length * actBN_BYTES_PER_DIGIT)){
    if((out_len % actBN_BYTES_PER_DIGIT) > 0u){
      tmp = a[i];

      for(i = out_len % actBN_BYTES_PER_DIGIT; i > 0u; --i)
      {
        offset--;
        out[offset] = ((actU8) tmp);
        tmp >>= 8;
      }
    }
  }
#endif
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

