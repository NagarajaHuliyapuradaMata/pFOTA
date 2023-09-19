

#define ESLIB_RSA_V15_EM_SOURCE

#include "ESLib.hpp"
#include "ESLib_ASN_1.hpp"

#if(VSECPRIM_RSA_ENABLED == STD_ON)

#define ASN1_PADDING_BLOCK_TYPE_INVALID                              (0xFFu)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyPaddingRSAEM_V15(VSECPRIM_P2CONST_PARA(eslt_Byte) message, VSECPRIM_P2VAR_PARA(eslt_Length) paddingLength, eslt_Byte blockType){
  eslt_ErrorCode returnValue;
  eslt_Length length;
  eslt_Length index;
  eslt_Length offset;
  eslt_Length newOffset;
  eslt_Length oldOffset;
  eslt_Byte allowedMask;
  eslt_Byte allowedValue;
  eslt_Byte allowedResult;
  eslt_Byte deniedMask;
  eslt_Byte deniedValue;
  eslt_Byte deniedResult;
  eslt_Byte localBlockType;

  returnValue = ESL_ERC_NO_ERROR;

  if((message == NULL_PTR) || (paddingLength == NULL_PTR)){
    returnValue = ESL_ERC_PARAMETER_INVALID;
  }

  if(returnValue == ESL_ERC_NO_ERROR){
    length = *paddingLength;
    localBlockType = blockType;

    if(length < ASN1_SIZEOF_MINIMAL_PADDING){
      returnValue = ESL_ERC_PARAMETER_INVALID;
    }
    else{
      if((0x00u != message[0]) || (blockType != message[1]))
      {
        localBlockType = ASN1_PADDING_BLOCK_TYPE_INVALID;
      }

      switch(localBlockType)
      {
      case ASN1_PADDING_BLOCK_TYPE_PRIVATE_ZERO:
      {
        allowedMask = 0xFFu;
        allowedValue = 0x00u;
        deniedMask = 0x00u;
        deniedValue = 0xFFu;

        break;
      }
      case ASN1_PADDING_BLOCK_TYPE_PRIVATE:
      {
        allowedMask = 0xFFu;
        allowedValue = 0xFFu;
        deniedMask = 0x00u;
        deniedValue = 0xFFu;

        break;
      }
      case ASN1_PADDING_BLOCK_TYPE_PUBLIC:
      {
        allowedMask = 0x00u;
        allowedValue = 0x00u;
        deniedMask = 0xFFu;
        deniedValue = 0x00u;

        break;
      }
      case ASN1_PADDING_BLOCK_TYPE_INVALID:
      default:
      {
        allowedMask = 0x00u;
        allowedValue = 0xFFu;
        deniedMask = 0x00u;
        deniedValue = 0x00u;

        returnValue = ESL_ERC_RSA_ENCODING_INVALID;

        break;
      }
      }

      offset = 1u;

      for(index = 2u; index < length; index++)
      {
        newOffset = offset + 1u;
        oldOffset = offset;

        if((message[index] & allowedMask) == allowedValue)
        {
          allowedResult = 0x00u;
        }
        else
        {
          allowedResult = 0x01u;
        }

        if((message[index] & deniedMask) != deniedValue)
        {
          deniedResult = 0x00u;
        }
        else
        {
          deniedResult = 0x01u;
        }

        if(0x00u == (allowedResult | deniedResult))
        {
          if(newOffset == index)
          {
            offset = newOffset;
          }
          else
          {
            offset = oldOffset;
          }
        }
      }

      if((ASN1_PADDING_BLOCK_TYPE_PRIVATE_ZERO != localBlockType) && (offset < (length - 1u)))
      {
        offset++;
      }

      if(((ASN1_SIZEOF_MINIMAL_PADDING - 1u) > offset) || (0x00u != message[offset]))
      {
        returnValue = ESL_ERC_RSA_ENCODING_INVALID;
      }

      if(ESL_ERC_NO_ERROR == returnValue)
      {
        *paddingLength = offset + 1u;
      }
    }
  }

  return returnValue;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

