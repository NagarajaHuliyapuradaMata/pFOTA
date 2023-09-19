###############################################################################
# File Name  : WrapNv_rules.mak
# Description: Rules makefile
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2021 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# REVISION HISTORY
#------------------------------------------------------------------------------
# Version   Date        Author  Description
#------------------------------------------------------------------------------
# 1.00.00   2021-05-26  vistbe  Initial version
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += SecMod$(BSW_SRC_DIR)\Sec.c
CC_FILES_TO_BUILD       += SecMod$(BSW_SRC_DIR)\Sec_Crc.c
CC_FILES_TO_BUILD       += SecMod$(BSW_SRC_DIR)\Sec_Decryption.c
CC_FILES_TO_BUILD       += SecMod$(BSW_SRC_DIR)\Sec_Job.c
CC_FILES_TO_BUILD       += SecMod$(BSW_SRC_DIR)\Sec_SeedKey.c
CC_FILES_TO_BUILD       += SecMod$(BSW_SRC_DIR)\Sec_Verification.c

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\SecMPar.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\..\Source\SecM_Callout_Stubs.c

# Library Settings
LIBRARIES_TO_BUILD      += SecMod
SecMod_FILES            += SecMod$(BSW_SRC_DIR)\Sec.c SecMod$(BSW_SRC_DIR)\Sec_Crc.c SecMod$(BSW_SRC_DIR)\Sec_Decryption.c SecMod$(BSW_SRC_DIR)\Sec_Job.c SecMod$(BSW_SRC_DIR)\Sec_SeedKey.c SecMod$(BSW_SRC_DIR)\Sec_Verification.c