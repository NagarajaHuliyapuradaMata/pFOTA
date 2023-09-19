

#define ACTECKEY_SOURCE

#include "actECKey.hpp"
#include "actECLengthInfo.hpp"

#if(VSECPRIM_ACTECKEY_ENABLED == STD_ON)

#define VSECPRIM_START_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

VSECPRIM_FUNC(actRETURNCODE) actECkgp(
  VSECPRIM_P2CONST_PARA(actBNDIGIT) d
   ,  VSECPRIM_P2VAR_PARA(actECPOINT) Q
   ,  VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp_ptr
   ,  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void)){
  actECPOINT Prec;
  actRETURNCODE retVal = actOK;

  Prec.x = wksp_ptr->curvePoint.precomputedPoint.xcoord;
  Prec.y = wksp_ptr->curvePoint.precomputedPoint.ycoord;

  actECPMultG(d, &Prec, Q, &wksp_ptr->baseData.Curve, watchdog);

  if(actECPToAffineFromMont(Q, &wksp_ptr->baseData.Curve, FALSE, watchdog) != actOK){
    retVal = actEXCEPTION_UNKNOWN;
  }

  return retVal;
}

#define VSECPRIM_STOP_SEC_CODE
#include "CompilerCfg_vSecPrim.hpp"

#endif

