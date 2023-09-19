

#ifndef ESLIB_ERC_H
#define ESLIB_ERC_H

#include "ESLib_t.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

#define ESL_ERT_RETURNCODE                                           0x0000u
#define ESL_ERT_WARNING                                              0x1000u
#define ESL_ERT_ERROR                                                0x2000u

#define ESL_ERT_WS_ERROR                                             ESL_ERT_ERROR+0x0100u

#define ESL_ERC_NO_ERROR                                             (ESL_ERT_RETURNCODE)

#define ESL_ERC_WARNING                                              (ESL_ERT_WARNING)

#define ESL_ERC_ERROR                                                (ESL_ERT_ERROR)

#define ESL_ERC_WS_STATE_INVALID                                     (ESL_ERT_ERROR + 0x0001u)

#define ESL_ERC_WS_TOO_SMALL                                         (ESL_ERT_ERROR + 0x0002u)

#define ESL_ERC_PARAMETER_INVALID                                    (ESL_ERT_ERROR + 0x0003u)

#define ESL_ERC_MODE_INVALID                                         (ESL_ERT_ERROR + 0x0004u)

#define ESL_ERC_MODE_INCOMPATIBLE                                    (ESL_ERT_ERROR + 0x0005u)

#define ESL_ERC_MEMORY_CONFLICT                                      (ESL_ERT_ERROR + 0x0006u)

#define ESL_ERC_OUTPUT_SIZE_TOO_SHORT                                (ESL_ERT_ERROR + 0x0007u)
#define ESL_ERC_BUFFER_TOO_SMALL                                     (ESL_ERT_ERROR + 0x0007u)

#define ESL_ERC_INPUT_INVALID                                        (ESL_ERT_ERROR + 0x0008u)

#define ESL_ERC_RNG_INIT_FAILED                                      (ESL_ERT_ERROR + 0x0009u)

#define ESL_ERC_RNG_ENTROPY_TOO_SMALL                                (ESL_ERT_ERROR + 0x000Au)

#define ESL_ERC_RNG_BAD_INTERNAL_STATE                               (ESL_ERT_ERROR + 0x000Bu)

#define ESL_ERC_AES_PADDING_INVALID                                  (ESL_ERT_ERROR + 0x000Cu)

#define ESL_ERC_SHA1_TOTAL_LENGTH_OVERFLOW                           (ESL_ERT_ERROR + 0x000Du)

#define ESL_ERC_HMAC_KEY_LENGTH_OUT_OF_RANGE                         (ESL_ERT_ERROR + 0x000Eu)

#define ESL_ERC_HMAC_INCORRECT_MAC                                   (ESL_ERT_ERROR + 0x000Fu)
#define ESL_ERC_INCORRECT_MAC                                        ESL_ERC_HMAC_INCORRECT_MAC

#define ESL_ERC_KDF_ITERATION_COUNT_OUT_OF_RANGE                     (ESL_ERT_ERROR + 0x0010u)

#define ESL_ERC_ECC_DOMAIN_INVALID                                   (ESL_ERT_ERROR + 0x0011u)

#define ESL_ERC_ECC_PUBKEY_INVALID                                   (ESL_ERT_ERROR + 0x0012u)

#define ESL_ERC_ECC_MESSAGE_TOO_LONG                                 (ESL_ERT_ERROR + 0x0013u)

#define ESL_ERC_ECC_PRIVKEY_INVALID                                  (ESL_ERT_ERROR + 0x0014u)

#define ESL_ERC_ECC_DOMAINEXT_INVALID                                (ESL_ERT_ERROR + 0x0015u)

#define ESL_ERC_ECC_SPEEDUPEXT_INVALID                               (ESL_ERT_ERROR + 0x0016u)

#define ESL_ERC_ECC_INTERNAL_ERROR                                   (ESL_ERT_ERROR + 0x0017u)

#define ESL_ERC_ECC_SIGNATURE_INVALID                                (ESL_ERT_ERROR + 0x0018u)

#define ESL_ERC_RSA_MODULE_OUT_OF_RANGE                              (ESL_ERT_ERROR + 0x0019u)

#define ESL_ERC_RSA_CODE_OUT_OF_RANGE                                (ESL_ERT_ERROR + 0x001Au)

#define ESL_ERC_RSA_MESSAGE_OUT_OF_RANGE                             (ESL_ERT_ERROR + 0x001Bu)

#define ESL_ERC_RSA_SIGNATURE_OUT_OF_RANGE                           (ESL_ERT_ERROR + 0x001Cu)

#define ESL_ERC_RSA_SIGNATURE_INVALID                                (ESL_ERT_ERROR + 0x001Du)

#define ESL_ERC_RSA_ENCODING_INVALID                                 (ESL_ERT_ERROR + 0x001Eu)

#define ESL_ERC_RSA_PUBKEY_INVALID                                   (ESL_ERT_ERROR + 0x001Fu)

#define ESL_ERC_RSA_PRIVKEY_INVALID                                  (ESL_ERT_ERROR + 0x0020u)

#define ESL_ERC_TOTAL_LENGTH_OVERFLOW                                (ESL_ERT_ERROR + 0x002Cu)

#define ESL_ERC_SHA256_TOTAL_LENGTH_OVERFLOW                         (ESL_ERC_TOTAL_LENGTH_OVERFLOW)

#define ESL_ERC_SHA384_TOTAL_LENGTH_OVERFLOW                         (ESL_ERC_TOTAL_LENGTH_OVERFLOW)

#define ESL_ERC_RIPEMD160_TOTAL_LENGTH_OVERFLOW                      (ESL_ERC_TOTAL_LENGTH_OVERFLOW)

#define ESL_ERC_DES_PADDING_INVALID                                  (ESL_ERT_ERROR + 0x0025u)

#define ESL_ERC_TDES_KEY_LENGTH_INVALID                              (ESL_ERT_ERROR + 0x0026u)

#define ESL_ERC_GCM_INVALID_KEY_LENGTH                               (ESL_ERT_ERROR + 0x0027u)
#define ESL_ERC_CCM_INVALID_KEY_LENGTH                               (define ESL_ERC_GCM_INVALID_KEY_LENGTH)

#define ESL_ERC_GCM_TOTAL_LENGTH_OVERFLOW                            (ESL_ERT_ERROR + 0x0028u)
#define ESL_ERC_CCM_TOTAL_LENGTH_OVERFLOW                            (ESL_ERC_GCM_TOTAL_LENGTH_OVERFLOW)

#define ESL_ERC_GCM_TAG_VERIFICATION_FAILED                          (ESL_ERT_ERROR + 0x0029u)

#define ESL_ERC_GCM_STATE_INVALID                                    (ESL_ERT_ERROR + 0x002Au)

#define ESL_ERC_STATE_INVALID                                        (ESL_ERC_GCM_STATE_INVALID)

#define ESL_ERC_INVALID_IV_LENGTH                                    (ESL_ERT_ERROR + 0x002Bu)

#define ESL_ERC_CURVE_NOT_SUPPORTED                                  (ESL_ERT_ERROR + 0x002Du)

#define ESL_ERC_SIGNATURE_INVALID                                    (ESL_ERT_ERROR + 0x002Eu)

#define ESL_ERC_RNG_FAILED                                           (ESL_ERT_ERROR + 0x002Fu)

#define ESL_ERC_INSTANCE_NOT_SUPPORTED                               (ESL_ERT_ERROR + 0x0030u)

#define ESL_ERC_ENTROPY_EXHAUSTION                                   (ESL_ERT_ERROR + 0x0031u)

#define ESL_ERC_INVALID_LENGTH                                       (ESL_ERT_ERROR + 0x0032u)

#define ESL_ERC_REQUESTED_LENGTH_INVALID                             (ESL_ERT_ERROR + 0x0033u)

#define ESL_ERC_INCORRECT_TAG                                        ESL_ERC_INCORRECT_MAC

#define ESL_ERC_UNRECOVERABLE_ERROR                                  (ESL_ERT_ERROR + 0x0800u)

#define ESL_ERC_16BITS                                               (0x7FFFu)

typedef actU16 eslt_ErrorCode;

#ifdef __cplusplus
}
#endif

#endif

