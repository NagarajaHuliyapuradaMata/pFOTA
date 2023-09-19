

#ifndef MICROSAR_DISABLE_MEMMAP

#define MEMMAP_ERROR

#if defined VSECPRIM_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
#error Using VSECPRIM_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
#endif
#define MEMMAP_SECTION_OPEN
#define VSECPRIM_CODE_OPEN

# pragma ghs section text = ".MSR_CODE"

# undef VSECPRIM_START_SEC_CODE
# undef MEMMAP_ERROR

#elif defined VSECPRIM_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
#error Using VSECPRIM_STOP_SEC_CODE is not possible as no memory section has been opened.
#endif
# undef MEMMAP_SECTION_OPEN
#ifndef VSECPRIM_CODE_OPEN
#error Using VSECPRIM_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
#endif
# undef VSECPRIM_CODE_OPEN

# pragma ghs section text = default

# undef VSECPRIM_STOP_SEC_CODE
# undef MEMMAP_ERROR

#elif defined VSECPRIM_START_SEC_CONST_8BIT
#ifdef MEMMAP_SECTION_OPEN
#error Using VSECPRIM_START_SEC_CONST_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
#endif
#define MEMMAP_SECTION_OPEN
#define VSECPRIM_CONST_8BIT_OPEN

# pragma ghs section rodata = ".MSR_CONST"

# undef VSECPRIM_START_SEC_CONST_8BIT
# undef MEMMAP_ERROR

#elif defined VSECPRIM_STOP_SEC_CONST_8BIT
#ifndef MEMMAP_SECTION_OPEN
#error Using VSECPRIM_STOP_SEC_CONST_8BIT is not possible as no memory section has been opened.
#endif
# undef MEMMAP_SECTION_OPEN
#ifndef VSECPRIM_CONST_8BIT_OPEN
#error Using VSECPRIM_STOP_SEC_CONST_8BIT is not possible as the corresponding memory section has not been opened.
#endif
# undef VSECPRIM_CONST_8BIT_OPEN

# pragma ghs section rodata = default

# undef VSECPRIM_STOP_SEC_CONST_8BIT
# undef MEMMAP_ERROR

#elif defined VSECPRIM_START_SEC_CONST_32BIT
#ifdef MEMMAP_SECTION_OPEN
#error Using VSECPRIM_START_SEC_CONST_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
#endif
#define MEMMAP_SECTION_OPEN
#define VSECPRIM_CONST_32BIT_OPEN

# pragma ghs section rodata = ".MSR_CONST"

# undef VSECPRIM_START_SEC_CONST_32BIT
# undef MEMMAP_ERROR

#elif defined VSECPRIM_STOP_SEC_CONST_32BIT
#ifndef MEMMAP_SECTION_OPEN
#error Using VSECPRIM_STOP_SEC_CONST_32BIT is not possible as no memory section has been opened.
#endif
# undef MEMMAP_SECTION_OPEN
#ifndef VSECPRIM_CONST_32BIT_OPEN
#error Using VSECPRIM_STOP_SEC_CONST_32BIT is not possible as the corresponding memory section has not been opened.
#endif
# undef VSECPRIM_CONST_32BIT_OPEN

# pragma ghs section rodata = default

# undef VSECPRIM_STOP_SEC_CONST_32BIT
# undef MEMMAP_ERROR

#elif defined VSECPRIM_START_SEC_CONST_64BIT
#ifdef MEMMAP_SECTION_OPEN
#error Using VSECPRIM_START_SEC_CONST_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
#endif
#define MEMMAP_SECTION_OPEN
#define VSECPRIM_CONST_64BIT_OPEN

# pragma ghs section rodata = ".MSR_CONST"

# undef VSECPRIM_START_SEC_CONST_64BIT
# undef MEMMAP_ERROR

#elif defined VSECPRIM_STOP_SEC_CONST_64BIT
#ifndef MEMMAP_SECTION_OPEN
#error Using VSECPRIM_STOP_SEC_CONST_64BIT is not possible as no memory section has been opened.
#endif
# undef MEMMAP_SECTION_OPEN
#ifndef VSECPRIM_CONST_64BIT_OPEN
#error Using VSECPRIM_STOP_SEC_CONST_64BIT is not possible as the corresponding memory section has not been opened.
#endif
# undef VSECPRIM_CONST_64BIT_OPEN

# pragma ghs section rodata = default

# undef VSECPRIM_STOP_SEC_CONST_64BIT
# undef MEMMAP_ERROR

#elif defined VSECPRIM_START_SEC_CONST_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
#error Using VSECPRIM_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
#endif
#define MEMMAP_SECTION_OPEN
#define VSECPRIM_CONST_UNSPECIFIED_OPEN

# pragma ghs section rodata = ".MSR_CONST"

# undef VSECPRIM_START_SEC_CONST_UNSPECIFIED
# undef MEMMAP_ERROR

#elif defined VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error Using VSECPRIM_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
#endif
# undef MEMMAP_SECTION_OPEN
#ifndef VSECPRIM_CONST_UNSPECIFIED_OPEN
#error Using VSECPRIM_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
#endif
# undef VSECPRIM_CONST_UNSPECIFIED_OPEN

# pragma ghs section rodata = default

# undef VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# undef MEMMAP_ERROR
#endif

#ifdef VSECPRIM_START_SEC_CODE
# error Using VSECPRIM_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_STOP_SEC_CODE
# error Using VSECPRIM_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_START_SEC_CONST_8BIT
# error Using VSECPRIM_START_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_STOP_SEC_CONST_8BIT
# error Using VSECPRIM_STOP_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_START_SEC_CONST_32BIT
# error Using VSECPRIM_START_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_STOP_SEC_CONST_32BIT
# error Using VSECPRIM_STOP_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_START_SEC_CONST_64BIT
# error Using VSECPRIM_START_SEC_CONST_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_STOP_SEC_CONST_64BIT
# error Using VSECPRIM_STOP_SEC_CONST_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_START_SEC_CONST_UNSPECIFIED
# error Using VSECPRIM_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# error Using VSECPRIM_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#ifdef MEMMAP_ERROR
# error No MemMap section found in vSecPrim_MemMap.h. Check your section define for validity.
#endif

#endif

