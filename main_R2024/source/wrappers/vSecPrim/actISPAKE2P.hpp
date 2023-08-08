

#ifndef ACTISPAKE2P_H
# define ACTISPAKE2P_H

# include "actITypes.hpp"

# define VSECPRIM_START_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

# ifdef __cplusplus
extern "C"
{
# endif

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PPreambleInit(
  VSECPRIM_P2VAR_PARA(actSPAKE2PPreambleStruct) wksp,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext,
  actLengthType wksp_len);

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PPreambleCalc(
  VSECPRIM_P2VAR_PARA(actSPAKE2PPreambleStruct) wksp,
  VSECPRIM_P2CONST_PARA(actU8) pbkdfOutput,
  const actLengthType pbkdfOutputLength,
  VSECPRIM_P2VAR_PARA(actU8) w0OutputBuffer,
  VSECPRIM_P2VAR_PARA(actLengthType) w0BufferLength,
  VSECPRIM_P2VAR_PARA(actU8) w1OutputBuffer,
  VSECPRIM_P2VAR_PARA(actLengthType) w1BufferLength,
  VSECPRIM_P2VAR_PARA(actU8) pointL,
  VSECPRIM_P2VAR_PARA(actLengthType) pointLBufferLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PInit(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wksp,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain,
  VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext,
  VSECPRIM_P2CONST_PARA(actU8) pointM,
  const actLengthType mlength,
  VSECPRIM_P2CONST_PARA(actU8) pointN,
  const actLengthType nlength,
  actLengthType wksp_len);

 VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PSetPreambleData(
   VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake,
   VSECPRIM_P2CONST_PARA(actU8) w0,
   const actLengthType w0length,
   VSECPRIM_P2CONST_PARA(actU8) w1,
   const actLengthType w1length,
   VSECPRIM_P2CONST_PARA(actU8) pointL,
   const actLengthType pointLLength);

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PCalcPubVal(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake,
  VSECPRIM_P2VAR_PARA(actU8) pubValXCoordinate,
  VSECPRIM_P2VAR_PARA(actU8) pubValYCoordinate,
  VSECPRIM_P2VAR_PARA(actLengthType) pubValCoordinateLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PSetAdditionalInformation(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake,
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) wsHash,
  VSECPRIM_P2CONST_PARA(actU8) infoA,
  const actLengthType infoALength,
  VSECPRIM_P2CONST_PARA(actU8) infoB,
  const actLengthType infoBLength,
  VSECPRIM_P2CONST_PARA(actU8) aad,
  const actLengthType aadLength,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PCalcSharedSecret(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake,
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) wsHash,
  VSECPRIM_P2VAR_PARA(actHKDFSTRUCT) wsHKDF,
  VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) wsCMAC,
  VSECPRIM_P2CONST_PARA(actU8) pubValXCoordinate,
  VSECPRIM_P2CONST_PARA(actU8) pubValYCoordinate,
  const actLengthType pubValCoordinateLength,
  VSECPRIM_P2VAR_PARA(actU8) sharedSecret,
  VSECPRIM_P2VAR_PARA(actU8) confirmationMAC,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

VSECPRIM_FUNC(actRETURNCODE) actSPAKE2PConfirmKey(
  VSECPRIM_P2VAR_PARA(actSPAKE2PSTRUCT) wsSpake,
  VSECPRIM_P2VAR_PARA(actCMACAESSTRUCT) wsCMAC,
  VSECPRIM_P2CONST_PARA(actU8) mac,
  VSECPRIM_P2VAR_PARA(actU8) recomputedMAC,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus
}
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "CompilerCfg_vSecPrim.hpp"

#endif

