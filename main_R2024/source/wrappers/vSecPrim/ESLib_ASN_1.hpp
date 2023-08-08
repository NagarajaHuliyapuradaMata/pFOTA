

#ifndef ESLIB_ASN_1_H
# define ESLIB_ASN_1_H

# define OID_ansi_x9_62                                               1*40+2,        \
                                                                      0x86, 0x48,    \
                                                                      0xce, 0x3d
# define LengthOfOID_ansi_x9_62                                       0x05

# define OID_ansi_x9_62_fieldType_prime                               OID_ansi_x9_62, 0x01,  0x01
# define LengthOfOID_ansi_x9_62_fieldType_prime                       (2+LengthOfOID_ansi_x9_62)

# define OID_ansi_x9_62_fieldType_char2                               OID_ansi_x9_62, 0x01,  0x02
# define LengthOfOID_ansi_x9_62_fieldType_char2                       (2+LengthOfOID_ansi_x9_62)

# define OID_ansi_x9_62_fieldType_char2gn                             OID_ansi_x9_62_fieldType_char2, 0x01
# define LengthOfOID_ansi_x9_62_fieldType_char2gn                     (1+LengthOfOID_ansi_x9_62_fieldType_char2)

# define OID_ansi_x9_62_fieldType_char2tp                             OID_ansi_x9_62_fieldType_char2, 0x02
# define LengthOfOID_ansi_x9_62_fieldType_char2tp                     (1+LengthOfOID_ansi_x9_62_fieldType_char2)

# define OID_ansi_x9_62_fieldType_char2pp                             OID_ansi_x9_62_fieldType_char2, 0x03
# define LengthOfOID_ansi_x9_62_fieldType_char2pp                     (1+LengthOfOID_ansi_x9_62_fieldType_char2)

# define asn1Tag_INTEGER                                              2

# define asn1Tag_OBJECT_IDENTIFIER                                    6

# define asn1Tag_OCTET_STRING                                         4

# define asn1Tag_BIT_STRING                                           3

# define asn1Tag_COMPOUND                                             0x20

# define asn1Tag_SEQUENCE                                             (0x10 | asn1Tag_COMPOUND)

# define ASN1_PADDING_BLOCK_TYPE_PRIVATE_ZERO                         0x00u

# define ASN1_PADDING_BLOCK_TYPE_PRIVATE                              0x01u

# define ASN1_PADDING_BLOCK_TYPE_PUBLIC                               0x02u

# define ASN1_MINIMAL_PADDING_LENGTH                                  8u

# define ASN1_SIZEOF_MINIMAL_PADDING                                  (3u + ASN1_MINIMAL_PADDING_LENGTH)

# define ASN1_SIZEOF_PARAMETERS_WITH_FIXED_LENGTH                     (20u + 3u + 15u)
# define ASN1_SIZEOF_SHA256_PARAMETERS_WITH_FIXED_LENGTH              (32u + 3u + 19u)

# define ASN1_MINIMAL_SIGVER_KEY_LENGTH                               (ASN1_SIZEOF_PARAMETERS_WITH_FIXED_LENGTH + ASN1_MINIMAL_PADDING_LENGTH)
# define ASN1_MINIMAL_SIGVER_KEY_LENGTH_SHA256                        (ASN1_SIZEOF_SHA256_PARAMETERS_WITH_FIXED_LENGTH + ASN1_MINIMAL_PADDING_LENGTH)

# define ASN1_DIGESTINFO_SHA1                                         {0x30u, 0x21u, 0x30u, 0x09u, 0x06u, 0x05u, 0x2bu, 0x0eu, 0x03u, 0x02u, 0x1au, 0x05u, 0x00u, 0x04u, 0x14u}
# define ASN1_DIGESTINFO_SHA256                                       {0x30u, 0x31u, 0x30u, 0x0du, 0x06u, 0x09u, 0x60u, 0x86u, 0x48u, 0x01u, 0x65u, 0x03u, 0x04u, 0x02u, 0x01u, 0x05u, 0x00u, 0x04u, 0x20u}
# define ASN1_DIGESTINFO_RIPEMD160                                    {0x30u, 0x21u, 0x30u, 0x09u, 0x06u, 0x05u, 0x2bu, 0x24u, 0x03u, 0x02u, 0x01u, 0x05u, 0x00u, 0x04u, 0x14u}

#endif

