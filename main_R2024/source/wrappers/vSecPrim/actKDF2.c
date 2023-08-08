

#define ACTKDF2_SOURCE

#include "actIKDF2.hpp"
#include "actUtilities.hpp"

#if(VSECPRIM_ACTKDF2_ENABLED == STD_ON)

# if(VSECPRIM_ACTKDF2HMACSHA256_ENABLED == STD_ON)
#  define VSECPRIM_WRAPPER_HMAC_SHA256
# endif

# if(VSECPRIM_ACTKDF2HMACSHA1_ENABLED == STD_ON)
#  define VSECPRIM_WRAPPER_HMAC_SHA1
# endif

typedef actHASHMACUNION_KDF2 actHASHMACUNION;
# include "actHashMACWrappers_int.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actKDF2Init(
   VSECPRIM_P2VAR_PARA(actKDF2STRUCT) info, actLengthType iteration_count){
    actRETURNCODE retVal;

   if(iteration_count <= 0u){
      retVal = actEXCEPTION_LENGTH;
   }
   else{
     info->iteration_count = iteration_count;
     retVal = actOK;
   }
   return retVal;
}

VSECPRIM_FUNC(actRETURNCODE) actKDF2Derive(
   VSECPRIM_P2VAR_PARA(actKDF2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) passwd, actLengthType passwd_length,
   VSECPRIM_P2CONST_PARA(actU8) salt, actLengthType salt_length,
   VSECPRIM_P2VAR_PARA(actU8) key, actLengthType key_length,
   actU8 hashMACidx,
   actLengthType sizeSHA){
    actRETURNCODE retVal = actOK;

   VSECPRIM_P2VAR_PARA(actHASHMACUNION_KDF2) hmac = &info->hmac;
   VSECPRIM_P2VAR_PARA(actU8) U_buf = info->U_buf;
   VSECPRIM_P2VAR_PARA(actU8) F_buf = info->F_buf;
   actU8 INT[4];

   actU32 c, l, r;

   if(key_length >= (0xFFFFFFFFuL - sizeSHA)){
     retVal = actEXCEPTION_INPUT_LENGTH;
   }
   else{
     actU32 i, j;

     c = info->iteration_count;
     l = (key_length + sizeSHA - 1u) / sizeSHA;
     r = key_length - ((l - 1u) * sizeSHA);

     for (i = 1u; i <= l; ++i)
     {
       actMemset(F_buf, 0, sizeSHA);

       actU32toBE(INT, (actU32)i);

       (void)(*actHashMACInitTable[hashMACidx])(hmac, passwd, passwd_length, VSECPRIM_FUNC_NULL_PTR);

       if(salt != NULL_PTR)
       {
         (void)(*actHashMACUpdateTable[hashMACidx])(hmac, salt, salt_length, VSECPRIM_FUNC_NULL_PTR);
       }
       (void)(*actHashMACUpdateTable[hashMACidx])(hmac, INT, sizeof(INT), VSECPRIM_FUNC_NULL_PTR);
       (void)(*actHashMACFinalizeTable[hashMACidx])(hmac, U_buf, VSECPRIM_FUNC_NULL_PTR);

       for (j = 2u; j <= c; ++j)
       {
         actXOR(F_buf, U_buf, sizeSHA);

         (void)(*actHashMACInitTable[hashMACidx])(hmac, passwd, passwd_length, VSECPRIM_FUNC_NULL_PTR);
         (void)(*actHashMACUpdateTable[hashMACidx])(hmac, U_buf, sizeSHA, VSECPRIM_FUNC_NULL_PTR);
         (void)(*actHashMACFinalizeTable[hashMACidx])(hmac, U_buf, VSECPRIM_FUNC_NULL_PTR);
       }

       actXOR(F_buf, U_buf, sizeSHA);

       if(i != l)
       {
         actMemCpyByteArray(&(key[(i - 1u)*sizeSHA]), F_buf, sizeSHA);
       }
       else
       {
         actMemCpyByteArray(&(key[(i - 1u)*sizeSHA]), F_buf, r);
       }
     }
   }

   return retVal;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif
