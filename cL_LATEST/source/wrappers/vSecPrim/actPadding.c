

#define ACTPADDING_SOURCE

#include "actPadding.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTPADDING_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actPaddingInit(actU8 mode){
  actRETURNCODE result;

  switch(mode){
    case actPADDING_PM_OFF:
    case actPADDING_PM_ONEWITHZEROES:
    case actPADDING_PM_PKCS7:
    {
      result = actOK;

      break;
    }
    default:
    {
      result = actEXCEPTION_ALGOID;

      break;
    }
  }

  return result;
}

VSECPRIM_FUNC(actRETURNCODE) actPaddingPad(
   actU8 mode, actLengthType buffer_size, VSECPRIM_P2VAR_PARA(actLengthType) buffer_used
   ,  VSECPRIM_P2VAR_PARA(actU8) buffer){
  actRETURNCODE result;
  actLengthType pad;
  actLengthType used;

  used = *buffer_used;

  if(buffer_size <= used){
    result = actEXCEPTION_LENGTH;
  }
  else{
    result = actOK;
    pad = buffer_size - used;

    switch(mode){
      case actPADDING_PM_OFF:
      {
        if(used != 0u)
        {
          result = actEXCEPTION_LENGTH;
        }

        pad = 0u;

        break;
      }
      case actPADDING_PM_ONEWITHZEROES:
      {
        actMemset(&buffer[used], 0x00u, pad);
        buffer[used] = 0x80u;

        break;
      }
      case actPADDING_PM_PKCS7:
      {
        actMemset(&buffer[used], (actU8) (pad & 0xFFu), pad);

        break;
      }
      default:
      {
        result = actEXCEPTION_PADDING;

        break;
      }
    }

    *buffer_used = used + pad;
  }

  return result;
}

VSECPRIM_FUNC(actRETURNCODE) actPaddingUnpad(
   actU8 mode, actLengthType buffer_size, VSECPRIM_P2VAR_PARA(actLengthType) buffer_used
   ,  VSECPRIM_P2CONST_PARA(actU8) buffer){
  actRETURNCODE result;
  actU8 pad;
  actLengthType unpad;
  actLengthType index;

  result = actOK;
  unpad = 0u;

  switch(mode){
    case actPADDING_PM_OFF:
    {
      unpad = buffer_size;

      break;
    }
    case actPADDING_PM_ONEWITHZEROES:
    {
      for(index = (buffer_size - 1u); index > 0u; index--)
      {
        if(buffer[index] != 0x00u)
        {
          break;
        }
      }

      if(buffer[index] != 0x80u)
      {
        result = actEXCEPTION_PADDING;
      }
      else
      {
        unpad = index;
      }

      break;
    }
    case actPADDING_PM_PKCS7:
    {
      pad = buffer[buffer_size - 1u];

      if(pad > buffer_size)
      {
        result = actEXCEPTION_PADDING;
      }
      else
      {
        unpad = buffer_size - pad;

        for(index = unpad; index < buffer_size; index++)
        {
          if(buffer[index] != pad)
          {
            result = actEXCEPTION_PADDING;
          }
        }
      }

      break;
    }
    default:
    {
      result = actEXCEPTION_PADDING;

      break;
    }
  }

  if(result == actOK){
    *buffer_used = unpad;
  }

  return result;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

