

#define ACTIECKEY_SOURCE

#include "actIECKey.hpp"
#include "actECTools.hpp"
#include "actECKey.hpp"
#include "actECPoint.hpp"
#include "actECLengthInfo.hpp"
#include "actBigNum.hpp"
#include "actUtilities.hpp"
#include "actConfig.hpp"

#if(VSECPRIM_ACTIECKEY_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actLengthType) actECGetPrivateKeyLength(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain){
   actLengthType p_bytes, n_bytes;
   actRETURNCODE returncode = actECGetPrimeAndOrderBytes(domain, &p_bytes, &n_bytes);
   return (returncode != actOK) ? 0u : n_bytes;
}

VSECPRIM_FUNC(actLengthType) actECGetPublicKeyCompLength(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain){
   actLengthType p_bytes, n_bytes;
   actRETURNCODE returncode = actECGetPrimeAndOrderBytes(domain, &p_bytes, &n_bytes);
   return (returncode != actOK) ? 0u : p_bytes;
}

VSECPRIM_FUNC(actRETURNCODE) actECInitGenerateKeyPair(
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext,
  VSECPRIM_P2ROMCONST_PARA(actU8) speedup_ext,
  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
  actLengthType wksp_len){
   return actECInit(domain, domain_ext, speedup_ext, actEC_ALGO_FLAG_KG, &(wksp->baseData), wksp_len);
}

VSECPRIM_FUNC(actRETURNCODE) actECGenerateKeyPair(
  boolean generate_privatekey,
  VSECPRIM_P2VAR_PARA(actU8) privatekey,
  VSECPRIM_P2VAR_PARA(actU8) publickey_x,
  VSECPRIM_P2VAR_PARA(actU8) publickey_y,
  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   actRETURNCODE returncode = actOK;
   actRETURNCODE rng_callback_error;

   VSECPRIM_P2VAR_PARA(actECCURVE) Curve = &(wksp->baseData.Curve);
   actLengthType p_length = Curve->p_field.m_length;
   actLengthType p_bytes = Curve->p_field.m_byte_length;
   actLengthType n_length = Curve->n_field.m_length;
   actLengthType n_bytes = Curve->n_field.m_byte_length;
   actECPOINT Q;
   VSECPRIM_P2VAR_PARA(actBNDIGIT) d;

   d   = wksp->dataPair.privKeys.privKey;
   Q.x = wksp->multG.kG.xcoord;
   Q.y = wksp->multG.kG.ycoord;
   Q.z = wksp->multG.kG.zcoord;

   if(generate_privatekey == TRUE){
      rng_callback_error = actBNModRandomize(d, &(Curve->n_field), Curve->t, watchdog);
      if(rng_callback_error != actOK)
      {
        returncode = rng_callback_error;
      }
      else
      {
        actBNOctetString(privatekey, n_bytes, d, n_length);
      }
   }
   else{
      actBNSetOctetString(d, n_length, privatekey, n_bytes);

      if(actBNIsZero(d, n_length) == TRUE)
      {
         returncode = actEXCEPTION_PRIVKEY;
      }
      if(actBNCompare(d, Curve->n_field.m, n_length) >= actCOMPARE_EQUAL)
      {
         returncode = actEXCEPTION_PRIVKEY;
      }
   }

   if(returncode == actOK){
     returncode = actECkgp(d, &Q, wksp, watchdog);

     if(returncode == actOK)
     {
       actBNOctetString(publickey_x, p_bytes, Q.x, p_length);
       actBNOctetString(publickey_y, p_bytes, Q.y, p_length);
     }

     actBNSetZero(d, n_length);
   }

   return returncode;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

