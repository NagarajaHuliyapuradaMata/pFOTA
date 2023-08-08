

#define ACTECDH_SOURCE

#include "actECDH.hpp"
#include "actECLengthInfo.hpp"

#if(VSECPRIM_ACTECDH_ENABLED == STD_ON)

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actECDHp(
   VSECPRIM_P2CONST_PARA(actBNDIGIT) d, VSECPRIM_P2CONST_PARA(actECPOINT) Q,
   VSECPRIM_P2VAR_PARA(actECPOINT) point, VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
   actECPToMont(Q, Curve, watchdog);

   if(actECPointIsOnCurve(Q, Curve, watchdog) != actOK){
      return actEXCEPTION_PUBKEY;
   }

   actECPMult(Q, d, point, Curve, watchdog);

   if(actECPToAffineFromMont(point, Curve, 0, watchdog) != actOK) { return actEXCEPTION_UNKNOWN; }

   return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

