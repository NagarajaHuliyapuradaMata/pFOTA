#ifndef MICROSAR_DISABLE_MEMMAP

#define MEMMAP_ERROR

#if defined MCALCRY_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define MCALCRY_CODE_OPEN

# pragma ghs section text = ".MSR_CODE"

# undef MCALCRY_START_SEC_CODE
# undef MEMMAP_ERROR

#elif defined MCALCRY_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN
# ifndef MCALCRY_CODE_OPEN
#  error Using MCALCRY_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef MCALCRY_CODE_OPEN

# pragma ghs section text = default

# undef MCALCRY_STOP_SEC_CODE
# undef MEMMAP_ERROR

#elif defined MCALCRY_START_SEC_CONST_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_START_SEC_CONST_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define MCALCRY_CONST_8BIT_OPEN

# pragma ghs section rodata = ".MSR_CONST"

# undef MCALCRY_START_SEC_CONST_8BIT
# undef MEMMAP_ERROR

#elif defined MCALCRY_STOP_SEC_CONST_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_STOP_SEC_CONST_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN
# ifndef MCALCRY_CONST_8BIT_OPEN
#  error Using MCALCRY_STOP_SEC_CONST_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef MCALCRY_CONST_8BIT_OPEN

# pragma ghs section rodata = default

# undef MCALCRY_STOP_SEC_CONST_8BIT
# undef MEMMAP_ERROR

#elif defined MCALCRY_START_SEC_CONST_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_START_SEC_CONST_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define MCALCRY_CONST_32BIT_OPEN

# pragma ghs section rodata = ".MSR_CONST"

# undef MCALCRY_START_SEC_CONST_32BIT
# undef MEMMAP_ERROR

#elif defined MCALCRY_STOP_SEC_CONST_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_STOP_SEC_CONST_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN
# ifndef MCALCRY_CONST_32BIT_OPEN
#  error Using MCALCRY_STOP_SEC_CONST_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef MCALCRY_CONST_32BIT_OPEN

# pragma ghs section rodata = default

# undef MCALCRY_STOP_SEC_CONST_32BIT
# undef MEMMAP_ERROR

#elif defined MCALCRY_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define MCALCRY_CONST_UNSPECIFIED_OPEN

# pragma ghs section rodata = ".MSR_CONST"

# undef MCALCRY_START_SEC_CONST_UNSPECIFIED
# undef MEMMAP_ERROR

#elif defined MCALCRY_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN
# ifndef MCALCRY_CONST_UNSPECIFIED_OPEN
#  error Using MCALCRY_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef MCALCRY_CONST_UNSPECIFIED_OPEN

# pragma ghs section rodata = default

# undef MCALCRY_STOP_SEC_CONST_UNSPECIFIED
# undef MEMMAP_ERROR

#elif defined MCALCRY_START_SEC_VAR_NOINIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_START_SEC_VAR_NOINIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define MCALCRY_VAR_NOINIT_8BIT_OPEN

# pragma ghs section bss = ".MSR_VAR_NO_INIT"
# pragma ghs section data = ".MSR_VAR_INIT"

# undef MCALCRY_START_SEC_VAR_NOINIT_8BIT
# undef MEMMAP_ERROR

#elif defined MCALCRY_STOP_SEC_VAR_NOINIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_STOP_SEC_VAR_NOINIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN
# ifndef MCALCRY_VAR_NOINIT_8BIT_OPEN
#  error Using MCALCRY_STOP_SEC_VAR_NOINIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef MCALCRY_VAR_NOINIT_8BIT_OPEN

# pragma ghs section bss = default
# pragma ghs section data = default

# undef MCALCRY_STOP_SEC_VAR_NOINIT_8BIT
# undef MEMMAP_ERROR

#elif defined MCALCRY_START_SEC_VAR_NOINIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_START_SEC_VAR_NOINIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define MCALCRY_VAR_NOINIT_16BIT_OPEN

# pragma ghs section bss = ".MSR_VAR_NO_INIT"
# pragma ghs section data = ".MSR_VAR_INIT"

# undef MCALCRY_START_SEC_VAR_NOINIT_16BIT
# undef MEMMAP_ERROR

#elif defined MCALCRY_STOP_SEC_VAR_NOINIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_STOP_SEC_VAR_NOINIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN
# ifndef MCALCRY_VAR_NOINIT_16BIT_OPEN
#  error Using MCALCRY_STOP_SEC_VAR_NOINIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef MCALCRY_VAR_NOINIT_16BIT_OPEN

# pragma ghs section bss = default
# pragma ghs section data = default

# undef MCALCRY_STOP_SEC_VAR_NOINIT_16BIT
# undef MEMMAP_ERROR

#elif defined MCALCRY_START_SEC_VAR_NOINIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_START_SEC_VAR_NOINIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define MCALCRY_VAR_NOINIT_32BIT_OPEN

# pragma ghs section bss = ".MSR_VAR_NO_INIT"
# pragma ghs section data = ".MSR_VAR_INIT"

# undef MCALCRY_START_SEC_VAR_NOINIT_32BIT
# undef MEMMAP_ERROR

#elif defined MCALCRY_STOP_SEC_VAR_NOINIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_STOP_SEC_VAR_NOINIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN
# ifndef MCALCRY_VAR_NOINIT_32BIT_OPEN
#  error Using MCALCRY_STOP_SEC_VAR_NOINIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef MCALCRY_VAR_NOINIT_32BIT_OPEN

# pragma ghs section bss = default
# pragma ghs section data = default

# undef MCALCRY_STOP_SEC_VAR_NOINIT_32BIT
# undef MEMMAP_ERROR

#elif defined MCALCRY_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define MCALCRY_VAR_NOINIT_UNSPECIFIED_OPEN

# pragma ghs section bss = ".MSR_VAR_NO_INIT"
# pragma ghs section data = ".MSR_VAR_INIT"

# undef MCALCRY_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef MEMMAP_ERROR

#elif defined MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN
# ifndef MCALCRY_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef MCALCRY_VAR_NOINIT_UNSPECIFIED_OPEN

# pragma ghs section bss = default
# pragma ghs section data = default

# undef MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef MEMMAP_ERROR

#elif defined MCALCRY_START_SEC_VAR_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_START_SEC_VAR_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define MCALCRY_VAR_ZERO_INIT_8BIT_OPEN

# pragma ghs section bss = ".MSR_VAR_CLEARED"
# pragma ghs section data = ".MSR_VAR_INIT"

# undef MCALCRY_START_SEC_VAR_ZERO_INIT_8BIT
# undef MEMMAP_ERROR

#elif defined MCALCRY_STOP_SEC_VAR_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using MCALCRY_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN
# ifndef MCALCRY_VAR_ZERO_INIT_8BIT_OPEN
#  error Using MCALCRY_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef MCALCRY_VAR_ZERO_INIT_8BIT_OPEN

# pragma ghs section bss = default
# pragma ghs section data = default

# undef MCALCRY_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef MEMMAP_ERROR
#endif

#ifdef MCALCRY_START_SEC_CODE
# error Using MCALCRY_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_STOP_SEC_CODE
# error Using MCALCRY_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_START_SEC_CONST_8BIT
# error Using MCALCRY_START_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_STOP_SEC_CONST_8BIT
# error Using MCALCRY_STOP_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_START_SEC_CONST_32BIT
# error Using MCALCRY_START_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_STOP_SEC_CONST_32BIT
# error Using MCALCRY_STOP_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_START_SEC_CONST_UNSPECIFIED
# error Using MCALCRY_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_STOP_SEC_CONST_UNSPECIFIED
# error Using MCALCRY_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_START_SEC_VAR_NOINIT_8BIT
# error Using MCALCRY_START_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_STOP_SEC_VAR_NOINIT_8BIT
# error Using MCALCRY_STOP_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_START_SEC_VAR_NOINIT_16BIT
# error Using MCALCRY_START_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_STOP_SEC_VAR_NOINIT_16BIT
# error Using MCALCRY_STOP_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_START_SEC_VAR_NOINIT_32BIT
# error Using MCALCRY_START_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_STOP_SEC_VAR_NOINIT_32BIT
# error Using MCALCRY_STOP_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using MCALCRY_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using MCALCRY_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_START_SEC_VAR_ZERO_INIT_8BIT
# error Using MCALCRY_START_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef MCALCRY_STOP_SEC_VAR_ZERO_INIT_8BIT
# error Using MCALCRY_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#ifdef MEMMAP_ERROR
# error No MemMap section found in McalCry_MemMap.h. Check your section define for validity.
#endif

#endif

