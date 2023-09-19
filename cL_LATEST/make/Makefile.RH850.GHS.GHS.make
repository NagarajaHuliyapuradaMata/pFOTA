include Makefile.derivative.memorymap

##########################################################################################################
# MULTI CONNECT SCRIPT GENERATION
##########################################################################################################
ifeq ($(DEBUGGER),MINICUBE)
  REMOTE_ESERV = 850eserv2 -fastflashload -rh850 -minicube -df=$(DEVICE_FILE_FOLDER)\$(DEVICE_FILE_NAME)".dvf" -id ffffffffffffffffffffffff -noiop
endif

ifeq ($(DEBUGGER),E1)
  ifeq ($(DERIVATIVE_GROUP_$(DERIVATIVE)),$(filter $(DERIVATIVE_GROUP_$(DERIVATIVE)),P1H P1L_C))
    REMOTE_ESERV = 850eserv2 -fastflashload -rh850 -e1lpd4=16500 -df=$(DEVICE_FILE_FOLDER)\$(DEVICE_FILE_NAME).dvf -cfapw ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff -dfapw ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff -id ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff -dclock=$(MAIN_OSC_CLK)000,0,swoff -no_trace -noiop
  else
    REMOTE_ESERV = 850eserv2 -fastflashload -rh850 -e1lpd4=11000 -dclock=$(MAIN_OSC_CLK)000,0,swoff -df=$(DEVICE_FILE_FOLDER)\$(DEVICE_FILE_NAME).dvf -id ffffffffffffffffffffffffffffffff -noiop
  endif
endif

# Definition of additional commands for each platform, will be added at the end of the *.rc file
# Should be independent from used debugger
# DCLOCK [main_clock sub_clock (swon|swoff)]
# main_clock  specifies main clock per kHz
# sub_clock   specifies sub clock per kHz
# swon        switches to main clock automatically from sub clock at the time of a break
# swoff       impossible automatic change on main clock
# for details see docu of ESERV
define ESERV2_DEFAULT_COMMAND
  $(ECHO) "                                         "  >> $@; \
  $(ECHO) "/* Set target clock */                   "  >> $@; \
  $(ECHO) "target dclock $(MAIN_OSC_CLK)000 0 swoff "  >> $@; \
  $(ECHO) "                                         "  >> $@; \
  $(ECHO) "/* Disable interrupts */                 "  >> $@; \
  $(ECHO) "target reg psw=0x0020                    "  >> $@; \
  $(ECHO) "                                         "  >> $@; \
  $(ECHO) "/* Unmask reset sources */               "  >> $@; \
  $(ECHO) "target pinmask k                         "  >> $@; \
  $(ECHO) "                                         "  >> $@; \
  $(ECHO) "/* load program and go to main */        "  >> $@; \
  $(ECHO) "load $(PROJECT_NAME).$(BINARY_SUFFIX)    "  >> $@; \
  $(ECHO) "                                         "  >> $@; \
  $(ECHO) "/* Set breakpoint to main */             "  >> $@; \
  $(ECHO) "b main                                   "  >> $@; \
  $(ECHO) "                                         "  >> $@; \
  $(ECHO) "/* Reset target */                       "  >> $@; \
  $(ECHO) "target rst                               "  >> $@; \
  $(ECHO) "                                         "  >> $@; \
  $(ECHO) "/* Run application*/                     "  >> $@; \
  $(ECHO) "c                                        "  >> $@
endef

##########################################################################################################
# LINKER FILE GENERATION
##########################################################################################################

#Linker script generation moved to external file
ifeq ($(OS_USECASE),BRS)
  ADDITIONAL_LINKER_SCRIPT_DEPENDENCY = Makefile.RH850.GHS.GHS.LinkerScriptDefault
endif

ifeq ($(OS_USECASE),OSGEN7)
  ADDITIONAL_LINKER_SCRIPT_DEPENDENCY = Makefile.RH850.GHS.GHS.LinkerScriptOsGen7
endif

ifneq ($(ADDITIONAL_LINKER_SCRIPT_DEPENDENCY),)
  include $(ADDITIONAL_LINKER_SCRIPT_DEPENDENCY)
endif

##########################################################################################################
# RULE TO DELETE PYTHON SCRIPT - Tested with Cubesuite Version 3.00.00 and higher
##########################################################################################################
RM_$(PROJECT_NAME):
	@$(RM) $(PROJECT_NAME).py; \
   $(ECHO) "Deleted $(PROJECT_NAME).py";

##########################################################################################################
# RULE TO GENERATE PYTHON SCRIPT - Tested with Cubesuite Version 3.00.00 and higher
##########################################################################################################
$(PROJECT_NAME).py:
	@$(ECHO) "Generated $(PROJECT_NAME).py"; \
    $(ECHO) "project.Create('$(subst \,/,$(CURDIR))/Debug/$(PROJECT_NAME)/$(PROJECT_NAME).mtpj', MicomType.RH850, '$(DEVICE_FILE_NAME)', ProjectKind.DebugOnly) "  > $@; \
    $(ECHO) "project.Open(r'$(subst \,/,$(CURDIR))/Debug/$(PROJECT_NAME)/$(PROJECT_NAME).mtpj') "                                                                 >> $@; \
    $(ECHO) "project.File.Add('$(subst \,/,$(CURDIR))/$(PROJECT_NAME).$(BINARY_SUFFIX)', 'Download files') "                                                      >> $@; \
    $(ECHO) "debugger.Disconnect() "                                                                                                                              >> $@; \
    $(ECHO) "debugger.DebugTool.Change(DebugTool.E1Lpd) "                                                                                                         >> $@; \
    $(ECHO) "Generated $(PROJECT_NAME).mtpj"; 

##########################################################################################################
# MAKE TARGETS
##########################################################################################################

$(PROJECT_NAME).$(LNK_SUFFIX): Makefile \
                               Makefile.Project.Part.Defines \
                               Makefile.$(PLATFORM).$(COMPILER_MANUFACTURER).$(EMULATOR).make \
                               Makefile.config \
                               $(ADDITIONAL_LINKER_SCRIPT_DEPENDENCY) \
                               $(PROJECT_NAME).rc \
                               $(PROJECT_NAME).$(BINARY_SUFFIX).bld
	@$(ECHO) "Creating $@"; \
$(LD_FILE)

$(PROJECT_NAME).rc:  Makefile \
                     Makefile.Project.Part.Defines \
                     Makefile.$(PLATFORM).$(COMPILER_MANUFACTURER).$(EMULATOR).make \
                     Makefile.config
	@$(ECHO) "Creating $@";                    \
   $(ECHO) "/* ICE setup */ "          > $@; \
   $(ECHO) "connect $(REMOTE_ESERV) " >> $@; \
   $(ESERV2_DEFAULT_COMMAND)

$(PROJECT_NAME).$(BINARY_SUFFIX).bld: Makefile \
                     Makefile.Project.Part.Defines \
                     Makefile.$(PLATFORM).$(COMPILER_MANUFACTURER).$(EMULATOR).make \
                     Makefile.config
	@$(ECHO) "Creating $@";                           \
   $(ECHO) "#!build                        "  > $@; \
   $(ECHO) "default:                       " >> $@; \
   $(ECHO) "        program                " >> $@; \
   $(ECHO) "        :compilation=assembly  " >> $@; \
   for dir in $(subst \,\\,$(SUBDIRS)); do          \
       $(ECHO) "        :sourcedirs=$$dir  " >> $@; \
   done;                                            \
   $(ECHO) "$(PROJECT_NAME).$(LNK_SUFFIX)  " >> $@; \
   $(ECHO) "        linker_file            " >> $@; \
   $(ECHO) "$(PROJECT_NAME).rc             " >> $@; \
   $(ECHO) "        custom                 " >> $@;

multi: $(PROJECT_NAME).rc
	@export DEVICE_FILE="$(DEVICE_FILE_NAME).dvf"; \
   export GHS_LMHOST=@$(LICENSE_SERVER); \
   export GHS_LMPORT=$(LICENSE_SERVER_PORT); \
   $(ECHO) "DF = $(DEVICE_FILE_NAME).dvf"; \
   $(ECHO) "$(COMPILER_BASE)" > "$(MULTI_BASE)\.redirect_tools"; \
   $(ECHO) "File '$(MULTI_BASE)\.redirect_tools' updated with compiler path '$(COMPILER_BASE)'"; \
   $(subst \,/,$(MULTI_BASE)\multi.exe $(PROJECT_NAME).$(BINARY_SUFFIX) -rc $(PROJECT_NAME).rc) &

$(OBJ_PATH)/%.$(ASM_SUFFIX):
	$(MAKEDEPEND) $< $@

##########################################################################################################
# Automatic connect script for Renesas Debug Environment CubeSuite+
# Tested with Cubesuite Version 3.00.00 and higher
##########################################################################################################
cs: RM_$(PROJECT_NAME) \
    $(PROJECT_NAME).py
	@$(ECHO) "DF = $(DEVICE_FILE_NAME).dvf"; \
   $(ECHO) "$(COMPILER_BASE)" > "$(EMU_PATH)\.redirect_tools"; \
   $(ECHO) "File '$(EMU_PATH)\.redirect_tools' updated with compiler path '$(COMPILER_BASE)'"; \
   $(subst \,/,$(EMU_PATH)\CubeSuiteW+.exe /lpall /noproj /ps $(PROJECT_NAME).py) &

# end of Makefile.RH850.GHS.GHS.make
