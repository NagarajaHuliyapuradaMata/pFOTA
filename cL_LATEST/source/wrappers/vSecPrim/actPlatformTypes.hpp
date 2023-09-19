

#ifndef ACTPLATFORMTYPES_H
#define ACTPLATFORMTYPES_H

#include "CfgSwcServiceSecPrim.hpp"

#ifndef VSECPRIM_LOCAL
#define VSECPRIM_LOCAL                                              static
#endif

#ifndef VSECPRIM_INLINE
#define VSECPRIM_INLINE
#endif

#ifndef VSECPRIM_LOCAL_INLINE
#define VSECPRIM_LOCAL_INLINE                                       VSECPRIM_LOCAL
#endif

#if(CPU_TYPE == CPU_TYPE_8)
#define ACT_PLATFORM_CPUTYPE_8BIT

# elif(CPU_TYPE == CPU_TYPE_16)
#define ACT_PLATFORM_CPUTYPE_16BIT

# elif(CPU_TYPE == CPU_TYPE_32)
#define ACT_PLATFORM_CPUTYPE_32BIT
# elif defined CPU_TYPE_64
#if(CPU_TYPE == CPU_TYPE_64)
#define ACT_PLATFORM_CPUTYPE_64BIT
#else
#   error "No valid CPU_TYPE from Platform_Types.h was found!"
#endif
#else
#error "No valid CPU_TYPE from Platform_Types.h was found!"
#endif

typedef uint8     actPlatformUint8;
typedef uint16    actPlatformUint16;
typedef uint32    actPlatformUint32;

#if defined( ACT_PLATFORM_CPUTYPE_64BIT )
#define ACT_PLATFORM_BITS_PER_DIGIT                                 (32u)
#define ACT_PLATFORM_UINT64_AVAILABLE
#define ACT_PLATFORM_ALIGNMENT                                      (8u)
typedef unsigned long long actPlatformUint64;
# elif defined(ACT_PLATFORM_CPUTYPE_32BIT)
#if(VSECPRIM_SUPPORT_UINT64 == STD_ON)
#define ACT_PLATFORM_BITS_PER_DIGIT                                (32u)
#define ACT_PLATFORM_UINT64_AVAILABLE
typedef unsigned long long actPlatformUint64;
#else
#define ACT_PLATFORM_BITS_PER_DIGIT                                (16u)
#endif
#define ACT_PLATFORM_ALIGNMENT                                      (4u)
# elif defined(ACT_PLATFORM_CPUTYPE_16BIT)
#define ACT_PLATFORM_BITS_PER_DIGIT                                 (16u)
#define ACT_PLATFORM_ALIGNMENT                                      (4u)
# elif defined(ACT_PLATFORM_CPUTYPE_8BIT)
#define ACT_PLATFORM_BITS_PER_DIGIT                                 (8u)
#define ACT_PLATFORM_ALIGNMENT                                      (1u)
#else
#error "actPlatformTypes.h: Current CPU type is not supported!"
#endif

#define ACT_ROM_POST

#define ACT_ROM_STR(x)                                               (x)

#define ACT_ROM_BYT(x)                                               (*(x))
#define ACT_ROM_WRD(x)                                               (*(x))
#define ACT_ROM_PTR(x)                                               ((VSECPRIM_P2ROMCONST_PARA(actU8))(*(x)))
#define ACT_ROM_DWD(x)                                               (*(x))

#define ACT_ROM_R_BYT(x)                                             (x)
#define ACT_ROM_R_WRD(x)                                             (x)
#define ACT_ROM_R_PTR(x)                                             ((VSECPRIM_P2ROMCONST_PARA(actU8))(x))
#define ACT_ROM_R_DWD(x)                                             (x)

#if !defined(VSECPRIM_FUNC_NULL_PTR)
#define VSECPRIM_FUNC_NULL_PTR                                      ((void (*)(void))0)
#endif

#ifndef VSECPRIM_REGISTER
#define VSECPRIM_REGISTER                                           register
#endif

#ifndef VSECPRIM_NONE
#define VSECPRIM_NONE
#endif

#define VSECPRIM_P2VAR(storage, ptrtype)                             storage P2VAR(ptrtype, AUTOMATIC, VSECPRIM_APPL_VAR)
#define VSECPRIM_P2VAR_TYPE(storage, ptrtype)                        typedef storage P2VAR(ptrtype, TYPEDEF, VSECPRIM_APPL_VAR)
#define VSECPRIM_P2VAR_PARA(ptrtype)                                 P2VAR(ptrtype, AUTOMATIC, VSECPRIM_APPL_VAR)

#define VSECPRIM_CONSTP2VAR(storage, ptrtype)                        storage CONSTP2VAR(ptrtype, AUTOMATIC, VSECPRIM_APPL_VAR)
#define VSECPRIM_ROM(storage, type)                                  storage CONST(type, VSECPRIM_APPL_CONST)
#define VSECPRIM_CONST_TYPE(storage, type)                           typedef storage CONST(type, TYPEDEF)

#define VSECPRIM_ROM_EXTERN(type)                                    extern VSECPRIM_ROM(VSECPRIM_NONE, type)

#define VSECPRIM_P2CONST(storage, ptrtype)                           storage P2CONST(ptrtype, AUTOMATIC, VSECPRIM_APPL_DATA)
#define VSECPRIM_P2CONST_TYPE(storage, ptrtype)                      typedef storage P2CONST(ptrtype, TYPEDEF, VSECPRIM_APPL_DATA)
#define VSECPRIM_P2CONST_PARA(ptrtype)                               P2CONST(ptrtype, AUTOMATIC, VSECPRIM_APPL_DATA)

#define VSECPRIM_P2ROMCONST(storage, ptrtype)                        storage P2CONST(ptrtype, AUTOMATIC, VSECPRIM_APPL_CONST)
#define VSECPRIM_P2ROMCONST_TYPE(storage, ptrtype)                   typedef storage P2CONST(ptrtype, TYPEDEF, VSECPRIM_APPL_CONST)
#define VSECPRIM_P2ROMCONST_PARA(ptrtype)                            P2CONST(ptrtype, AUTOMATIC, VSECPRIM_APPL_CONST)

#define VSECPRIM_CONSTP2CONST(storage, ptrtype)                      storage CONSTP2CONST(ptrtype, AUTOMATIC, VSECPRIM_APPL_DATA)
#define VSECPRIM_CONSTP2ROMCONST(storage, ptrtype)                   storage CONSTP2CONST(ptrtype, AUTOMATIC, VSECPRIM_APPL_CONST)
#define VSECPRIM_CONSTP2CONST_TYPE(storage, ptrtype)                 typedef storage CONSTP2CONST(ptrtype, TYPEDEF, VSECPRIM_APPL_DATA)
#define VSECPRIM_CONSTP2ROMCONST_TYPE(storage, ptrtype)              typedef storage CONSTP2CONST(ptrtype, TYPEDEF, VSECPRIM_APPL_CONST)
#define VSECPRIM_FUNC(rettype)                                       FUNC(rettype, VSECPRIM_CODE)
#define VSECPRIM_LOCAL_FUNC(rettype)                                 VSECPRIM_LOCAL VSECPRIM_FUNC(rettype)
#define VSECPRIM_LOCAL_INLINE_FUNC(rettype)                          VSECPRIM_LOCAL_INLINE VSECPRIM_FUNC(rettype)
#define VSECPRIM_INLINE_FUNC(rettype)                                VSECPRIM_INLINE VSECPRIM_FUNC(rettype)
#define VSECPRIM_P2FUNC(storage, rettype, fctname)                   storage P2FUNC(rettype, AUTOMATIC, fctname)

#endif

