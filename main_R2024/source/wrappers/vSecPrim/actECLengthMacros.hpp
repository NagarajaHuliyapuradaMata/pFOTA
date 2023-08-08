

#ifndef ACTECLENGTHMACROS_H
# define ACTECLENGTHMACROS_H

# include "actITypes.hpp"
# include "actECPoint.hpp"

# ifdef __cplusplus
extern "C"
{
# endif

# define actEC_DOMAIN_WKSP(p_length, n_length)                        ((2u* (p_length)) + (2u* (n_length)))

# define actEC_TMP_WKSP(p_length, n_length)                           (actEC_BIGNUM_TMP * (actMax ((n_length), (p_length)) +1u))

# define actEC_POINT_WKSP(p_length)                                   (3u* (p_length))

# define actEC_POINT_AFFINE_WKSP(p_length)                            (2u* (p_length))

# define actEC_BASIC_WKSP(p_length, n_length)                         (actEC_DOMAIN_WKSP ((p_length), (n_length)) + actEC_TMP_WKSP ((p_length), (n_length)))

# define actEC_KG_WKSP(p_length, n_length)                            (actEC_BASIC_WKSP ((p_length), (n_length)) + (n_length) + actEC_POINT_WKSP (p_length) + actEC_POINT_AFFINE_WKSP (p_length))

# define actEC_DHp_WKSP(p_length, n_length)                           (actEC_BASIC_WKSP ((p_length), (n_length)) + (n_length) + actEC_POINT_AFFINE_WKSP (p_length) + actEC_POINT_WKSP (p_length))

# define actEC_DH_WKSP(p_length, n_length)                            (actEC_DHp_WKSP((p_length), (n_length)) + (p_length))

# define actEC_DSASp_WKSP(p_length, n_length)                         (actEC_BASIC_WKSP ((p_length), (n_length)) + (4u*(n_length)) + (n_length) + actEC_POINT_WKSP (p_length) + actEC_POINT_AFFINE_WKSP (p_length))

# define actEC_DSAVp_WKSP(p_length, n_length)                         (actEC_BASIC_WKSP ((p_length), (n_length)) + (3u*(n_length)) + actEC_POINT_AFFINE_WKSP (p_length) + (2u*((n_length) +1u)) + actEC_POINT_AFFINE_WKSP (p_length) +  (2u*actEC_POINT_WKSP (p_length)))

# define actEC_BDKA_WKSP(p_length, n_length)                          (actEC_BASIC_WKSP ((p_length), (n_length)) + (n_length) + actEC_POINT_WKSP (p_length) +  actEC_POINT_WKSP (p_length) +  actEC_POINT_WKSP (p_length))

# ifdef __cplusplus
}
# endif

#endif

