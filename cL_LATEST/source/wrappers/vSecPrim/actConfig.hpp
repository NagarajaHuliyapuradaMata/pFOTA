

#ifndef ACTCONFIG_H
#define ACTCONFIG_H

#include "CfgSwcServiceSecPrim.hpp"

#ifndef actBN_MONT_MUL_VERSION_ONE

#define actBN_MONT_MUL_VERSION                                      0
#else

#define actBN_MONT_MUL_VERSION                                      1
#endif

#define actBN_MOD_EXP_WINDOW_SIZE                                    1u

#if((actBN_MOD_EXP_WINDOW_SIZE)==0u)
#define actEC_MOD_EXP_WINDOW_SIZE                                   (3u)
#define actRSA_MOD_EXP_WINDOW_SIZE                                  (3u)
#else
#define actEC_MOD_EXP_WINDOW_SIZE                                   (actBN_MOD_EXP_WINDOW_SIZE)
#define actRSA_MOD_EXP_WINDOW_SIZE                                  (actBN_MOD_EXP_WINDOW_SIZE)
#endif
#define actEC_MOD_EXP_TMP                                            (1u << ((actEC_MOD_EXP_WINDOW_SIZE)-1u))
#define actRSA_MOD_EXP_TMP                                           (1u << ((actRSA_MOD_EXP_WINDOW_SIZE)-1u))

#define actSHA_SPEED_UP                                              (vSecPrim_GetSha1SpeedUpOfOptimization())

#define actRMD160_SPEED_UP                                           1

#define actSHA256_SPEED_UP                                           (vSecPrim_GetSha256SpeedUpOfOptimization())

#define actSHA512_SPEED_UP                                           (vSecPrim_GetSha512SpeedUpOfOptimization())

#define actMD5_SPEED_UP                                              1

#define actAES_SPEED_UP                                              (vSecPrim_GetAesSpeedUpOfOptimization())

#define actGHASH_SPEED_UP                                            1

#define actChaCha20_SPEED_UP                                         (vSecPrim_GetChaCha20SpeedUpOfOptimization())

#define actWD_LEVEL                                                  (vSecPrim_GetWatchdogLevelOfGeneral())

#define VSECPRIM_ACTBNEUCLID_ENABLED                                 STD_OFF

#if(vSecPrim_GetCTRDRBGAES128SecurityStrengthOfGeneral() == VSECPRIM_SECURITY_STRENGTH_128)
#define actAES128CTRDRBG_SECURITY_STRENGTH                          (128u)
#else
#define actAES128CTRDRBG_SECURITY_STRENGTH                          (112u)
#endif

#define actAES256CTRDRBG_SECURITY_STRENGTH                           (256u)

#define actHASHDRBG_SECURITY_STRENGTH                                (256u)

#endif

