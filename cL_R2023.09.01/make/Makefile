PROJECT_NAME = Bootloader

include Makefile.static

COMPILER_BASE = c:\GHS\comp_201517
COMPILER_BIN  = $(COMPILER_BASE)
COMPILER_INC  = $(COMPILER_BASE)\ansi $(COMPILER_BASE)\include\v800
COMPILER_LIB  = $(COMPILER_BASE)\lib\rh850

ELFCONVERTER_BIN = $(ROOT)\Misc\OsElfConverter\ElfConverter.exe
DEVICE_FILE_FOLDER = $(COMPILER_BASE)\rh850
MULTI_BASE = $(COMPILER_BASE)\multi_616
ASFLAGS_SELECTOR = VECTOR
CFLAGS_SELECTOR  = CUSTOMER
LDFLAGS_SELECTOR = VECTOR
LICENSE_SERVER = bredtoff0003.ad.huf
LICENSE_SERVER_PORT = 2009

ifeq ($(EMU_PATH),)
EMU_PATH = $(COMPILER_BASE)
endif

ifeq ($(DERIVATIVE_GROUP_$(DERIVATIVE)),$(filter $(DERIVATIVE_GROUP_$(DERIVATIVE)),F1H C1H C1M_AZ P1H F1KH))
  BRS_STARTUP_RAM_DEFINES_DEP =  BRS_CPU_LOCAL_RAM_SIZE_CORE0=$(LOCAL_RAM_SIZE_CORE0_$(DERIVATIVE)) \
                                 BRS_CPU_LOCAL_RAM_SIZE_CORE1=$(LOCAL_RAM_SIZE_CORE1_$(DERIVATIVE)) \
                                 BRS_CPU_RAM_START_CORE0=$($(DERIVATIVE_GROUP_$(DERIVATIVE))_LOCAL_RAM_START_ADDRESS_CORE0_$(LOCAL_RAM_SIZE_CORE0_$(DERIVATIVE))) \
                                 BRS_CPU_RAM_START_CORE1=$($(DERIVATIVE_GROUP_$(DERIVATIVE))_LOCAL_RAM_START_ADDRESS_CORE1_$(LOCAL_RAM_SIZE_CORE1_$(DERIVATIVE)))

else
  ifeq ($(DERIVATIVE_GROUP_$(DERIVATIVE)),$(filter $(DERIVATIVE_GROUP_$(DERIVATIVE)),F1KM_S4))
    BRS_STARTUP_RAM_DEFINES_DEP =  BRS_CPU_LOCAL_RAM_SIZE_CORE0=$(LOCAL_RAM_SIZE_CORE0_$(DERIVATIVE)) \
                                   BRS_CPU_RAM_START_CORE0=$($(DERIVATIVE_GROUP_$(DERIVATIVE))_LOCAL_RAM_START_ADDRESS_CORE0_$(LOCAL_RAM_SIZE_CORE0_$(DERIVATIVE)))

  else
    BRS_STARTUP_RAM_DEFINES_DEP =  BRS_CPU_LOCAL_RAM_SIZE_CORE0=$(GLOBAL_RAM_SIZE_$(DERIVATIVE)) \
                                   BRS_CPU_RAM_START_CORE0=$($(DERIVATIVE_GROUP_$(DERIVATIVE))_RAM_START_ADDRESS_$(GLOBAL_RAM_SIZE_$(DERIVATIVE)))
  endif
endif

DEP_DEFINES = BRS_DERIVATIVE_$(DERIVATIVE)                           \
              BRS_OSC_CLK=$(MAIN_OSC_CLK)                            \
              BRS_TIMEBASE_CLOCK=$(TIMEBASE_CLOCK)                   \
              BRS_OS_USECASE_$(OS_USECASE)                           \
              BRS_EVA_BOARD_$(EVA_BOARD)                             \
              BRS_DERIVATIVE_GROUP_$(DERIVATIVE_GROUP_$(DERIVATIVE)) \
              BRS_PLATFORM_$(PLATFORM)                               \
              BRS_COMP_$(COMPILER_MANUFACTURER)                      \
              $(BRS_STARTUP_RAM_DEFINES_DEP)

AS_ENV  = $(CC_ENV)
AS      = $(CC)
ASFLAGS_VECTOR_MAKESUPPORT =

ASFLAGS_VECTOR_OPTIONS = -c -preprocess_assembly_files \
                         -cpu=$(GHS_CPU_SWITCH_$(DERIVATIVE_GROUP_$(DERIVATIVE)))

ASFLAGS_CUSTOMER_OPTIONS =
ASVERSION = test.asm -V
AS_LC = 5
CC_ENV = export GHS_LMHOST=@$(LICENSE_SERVER);\
         export GHS_LMPORT=$(LICENSE_SERVER_PORT);
CC     = $(COMPILER_BIN)\ccrh850.exe

ifeq ($(DERIVATIVE_GROUP_$(DERIVATIVE)),$(filter $(DERIVATIVE_GROUP_$(DERIVATIVE)),F1H C1H C1M_AZ P1H F1KH))
  BRS_STARTUP_RAM_DEFINES = -DBRS_CPU_LOCAL_RAM_SIZE_CORE0=$(LOCAL_RAM_SIZE_CORE0_$(DERIVATIVE)) \
                            -DBRS_CPU_LOCAL_RAM_SIZE_CORE1=$(LOCAL_RAM_SIZE_CORE1_$(DERIVATIVE)) \
                            -DBRS_CPU_RAM_START_CORE0=$($(DERIVATIVE_GROUP_$(DERIVATIVE))_LOCAL_RAM_START_ADDRESS_CORE0_$(LOCAL_RAM_SIZE_CORE0_$(DERIVATIVE))) \
                            -DBRS_CPU_RAM_START_CORE1=$($(DERIVATIVE_GROUP_$(DERIVATIVE))_LOCAL_RAM_START_ADDRESS_CORE1_$(LOCAL_RAM_SIZE_CORE1_$(DERIVATIVE))) 

else
  ifeq ($(DERIVATIVE_GROUP_$(DERIVATIVE)),$(filter $(DERIVATIVE_GROUP_$(DERIVATIVE)),F1KM_S4))
    BRS_STARTUP_RAM_DEFINES =  -DBRS_CPU_LOCAL_RAM_SIZE_CORE0=$(LOCAL_RAM_SIZE_CORE0_$(DERIVATIVE)) \
                               -DBRS_CPU_RAM_START_CORE0=$($(DERIVATIVE_GROUP_$(DERIVATIVE))_LOCAL_RAM_START_ADDRESS_CORE0_$(LOCAL_RAM_SIZE_CORE0_$(DERIVATIVE)))

  else
    BRS_STARTUP_RAM_DEFINES = -DBRS_CPU_LOCAL_RAM_SIZE_CORE0=$(GLOBAL_RAM_SIZE_$(DERIVATIVE)) \
                              -DBRS_CPU_RAM_START_CORE0=$($(DERIVATIVE_GROUP_$(DERIVATIVE))_RAM_START_ADDRESS_$(GLOBAL_RAM_SIZE_$(DERIVATIVE)))
  endif
endif

CFLAGS_VECTOR_MAKESUPPORT = -DBRS_DERIVATIVE_$(DERIVATIVE)         \
                            -DBRS_OSC_CLK=$(MAIN_OSC_CLK)          \
                            -DBRS_TIMEBASE_CLOCK=$(TIMEBASE_CLOCK) \
                            -DBRS_EVA_BOARD_$(EVA_BOARD)           \
                            -DBRS_DERIVATIVE_GROUP_$(DERIVATIVE_GROUP_$(DERIVATIVE)) \
                            -DBRS_OS_USECASE_$(OS_USECASE)         \
                            -DBRS_PLATFORM_$(PLATFORM)             \
                            -DBRS_COMP_$(COMPILER_MANUFACTURER)    \
                            $(BRS_STARTUP_RAM_DEFINES)             \
                            -list=$(LST_PATH)/$*.lst               \
                            -object_dir=$(OBJ_PATH)                \
                            -stderr=$(ERR_PATH)\$*.$(ERR_SUFFIX)   \
                            -c

REGISTERMODE = 32

CFLAGS_VECTOR_OPTIONS = -cpu=$(GHS_CPU_SWITCH_$(DERIVATIVE_GROUP_$(DERIVATIVE))) \
                        -needprototype     \
                        -Wundef            \
                        --no_commons       \
                        -G                 \
                        -dual_debug        \
                        -noobj             \
                        -pragma_asm_inline \
                        -inline_prologue   \
                        --long_long        \
                        -fsoft             \
                        -sda=all           \
                        -large_sda         \
                        -Ogeneral          \
                        -registermode=$(REGISTERMODE)

CFLAGS_CUSTOMER_OPTIONS =-cpu=rh850                \
                         -sda=all                  \
                         -large_sda                \
                         -prepare_dispose          \
                         -pragma_asm_inline        \
                         -no_callt                 \
                         -inline_prologue          \
                         -notda                    \
                         -reserve_r2               \
                         -fsoft                    \
                         --unknown_pragma_warnings \
                         -list                     \
                         -g                        \
                         -Ogeneral                 \
                         -shortenum                \
                         -registermode=$(REGISTERMODE)

CVERSION = -V dummy.c

CC_LC = 5

CINC = -I

LD_ENV  = $(CC_ENV)
LD      = $(CC)

LDFLAGS_VECTOR_MAKESUPPORT = -o $*.$(BINARY_SUFFIX)        \
                             -map=$*.map                   \
                             -cpu=$(GHS_CPU_SWITCH_$(DERIVATIVE_GROUP_$(DERIVATIVE))) \
                             --preprocess_linker_directive_full \
                             -e __usr_init

ifeq ($(USER_LINKER_COMMAND_FILE),)
LDFLAGS_VECTOR_MAKESUPPORT += $(PROJECT_NAME).$(LNK_SUFFIX)
else
LDFLAGS_VECTOR_MAKESUPPORT += $(USER_LINKER_COMMAND_FILE)
endif

LDFLAGS_VECTOR_OPTIONS = -Manx       \
                         -G          \
                         -dual_debug \
                         -sda=all    \
                         -large_sda  \
                         -Ogeneral

LDFLAGS_CUSTOMER_OPTIONS =

LDVERSION = $(CVERSION)

LD_LC = $(CC_LC)

HEX_ENV    = $(CC_ENV)
HEX        = $(COMPILER_BIN)\gsrec.exe

HEXFLAGS = -nos5 -skip .tdata $(PROJECT_NAME).$(BINARY_SUFFIX)  -o 

LB_ENV  = $(LD_ENV)
LB      = $(LD)

LBFLAGS = :archiver.args=-c \
          -archive          \
          -o $@

LBVERSION = $(LDVERSION)

LB_LC = $(LD_LC)

ADDITIONAL_INCLUDES +=

ADDITIONAL_OBJECTS +=

ASM_SOURCES +=

APP_SOURCE_LST +=

hex: $(PROJECT_NAME).$(BINARY_SUFFIX)
	$(subst \,/,$(HEX) $(HEXFLAGS) $(PROJECT_NAME).hex)

include Makefile.$(PLATFORM).$(COMPILER_MANUFACTURER).$(EMULATOR).make

include $(MAKESUPPORT_DIR)\Global.Makefile.target.make.$(VERSION)
