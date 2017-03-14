###########################################################################
## Makefile generated for Simulink model 'shell_elec_electric_vehicle'. 
## 
## Makefile     : shell_elec_electric_vehicle.mk
## Generated on : Mon Mar 13 20:26:07 2017
## MATLAB Coder version: 3.2 (R2016b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/shell_elec_electric_vehicle.exe
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.
# MODELREF_LINK_RSPFILE   Include paths for the model reference build
# PERL                    PERL Tool
# GEN_LNK_SCRIPT          Perl script to generate the command file
# CMD_FILE                Command file

PRODUCT_NAME              = shell_elec_electric_vehicle
MAKEFILE                  = shell_elec_electric_vehicle.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2016b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2016b/bin
MATLAB_ARCH_BIN           = C:/PROGRA~1/MATLAB/R2016b/bin/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Senior_Design/MATLAB_Enviornment/Simulation_Files
ARCH                      = win64
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODELREF_LINK_RSPFILE_NAME = shell_elec_electric_vehicle_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ..
MODELREF_LINK_RSPFILE     = shell_elec_electric_vehicle_ref.rsp
PERL                      = $(MATLAB_ROOT)/sys/perl/win32/bin/perl.exe
GEN_LNK_SCRIPT            = $(MATLAB_ROOT)/rtw/c/tools/mkvc_lnk.pl
CMD_FILE                  = $(PRODUCT_NAME).lnk
LIBSSC_SLI_LCC_OBJS       = 
LIBSSC_CORE_LCC_OBJS      = 
LIBNE_LCC_OBJS            = 
LIBMC_LCC_OBJS            = 
LIBEX_LCC_OBJS            = 
LIBPM_LCC_OBJS            = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          LCC-win64 v2.4.1 | gmake (64-bit Windows)
# Supported Version(s):    2.4.1
# ToolchainInfo Version:   R2016b
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

SHELL              = cmd
LCC_ROOT           = $(MATLAB_ROOT)/sys/lcc64/lcc64
LCC_BUILDLIB       = $(LCC_ROOT)/bin/buildlib
LCC_LIB            = $(LCC_ROOT)/lib64
MW_EXTERNLIB_DIR   = $(MATLAB_ROOT)/extern/lib/win64/microsoft
MW_LIB_DIR         = $(MATLAB_ROOT)/lib/win64
TOOLCHAIN_INCLUDES = -I$(LCC_ROOT)/include64
MEX_OPTS_FILE      = $(MATLAB_ROOT/rtw/c/tools/lcc-win64.xml

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Lcc-win64 C Compiler
CC_PATH = $(LCC_ROOT)/bin
CC = $(CC_PATH)/lcc64

# Linker: Lcc-win64 Linker
LD_PATH = $(LCC_ROOT)/bin
LD = $(LD_PATH)/lcclnk64

# Archiver: Lcc-win64 Archiver
AR_PATH = $(LCC_ROOT)/bin
AR = $(AR_PATH)/lcclib64

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -Fo
LDDEBUG             =
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = /out:
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              =
CFLAGS               = -c -w -noregistrylookup -nodeclspec -I$(LCC_ROOT)/include64
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL)
MEX_CFLAGS           = -win64 $(MEX_SRC) $(MEX_OPT_FILE)$(INCLUDES) -outdir $(RELATIVE_PATH_TO_ANCHOR)
MEX_LDFLAGS          = LINKFLAGS="$$LINKFLAGS $(LDFLAGS_ADDITIONAL)"
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dll -entry LibMain -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL) $(DEF_FILE)

#--------------------
# File extensions
#--------------------

H_EXT               = .h
OBJ_EXT             = .obj
C_EXT               = .c
EXE_EXT             = .exe
SHAREDLIB_EXT       = .dll
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/shell_elec_electric_vehicle.exe
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/shell_elec_electric_vehicle_grt_rtw -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/toolbox/physmod/simscape/engine/sli/c -I$(MATLAB_ROOT)/toolbox/physmod/simscape/engine/core/c -I$(MATLAB_ROOT)/toolbox/physmod/simscape/compiler/core/c -I$(MATLAB_ROOT)/toolbox/physmod/network_engine/c -I$(MATLAB_ROOT)/toolbox/physmod/common/math/core/c -I$(MATLAB_ROOT)/toolbox/physmod/common/lang/core/c -I$(MATLAB_ROOT)/toolbox/physmod/common/external/library/c -I$(MATLAB_ROOT)/toolbox/physmod/common/foundation/core/c

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DMAT_FILE=1 -DINTEGER_CODE=0 -DMT=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0
DEFINES_IMPLIED = -DTID01EQ=0
DEFINES_STANDARD = -DMODEL=shell_elec_electric_vehicle -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_eq_tol.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_vmf.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_dxicr_p.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_assert.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_dxdelt_p.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_dxf.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_f.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_dxf_p.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_a_p.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_a.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_tdxf_p.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_slf.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_dxm.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_ic.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_log.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_m.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_m_p.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_dxm_p.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_mode.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_obs_exp.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_tdxy_p.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_obs_act.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_obs_all.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_qx.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_qx_p.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_var_tol.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_dxy_p.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_mdxy_p.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_ds_zc.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_442b803b_1_gateway.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/pm_printf.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/rt_backsubrr_dbl.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/rt_forwardsubrr_dbl.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/rt_lu_real.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/rt_matrixlib_dbl.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/rtGetInf.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/rtGetNaN.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/rt_nonfinite.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/rt_zcfcn.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle.c $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/shell_elec_electric_vehicle_data.c $(MATLAB_ROOT)/rtw/c/src/rt_logging.c

MAIN_SRC = $(MATLAB_ROOT)/rtw/c/src/common/rt_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = shell_elec_electric_vehicle_442b803b_1_ds.obj shell_elec_electric_vehicle_442b803b_1_ds_eq_tol.obj shell_elec_electric_vehicle_442b803b_1_ds_vmf.obj shell_elec_electric_vehicle_442b803b_1_ds_dxicr_p.obj shell_elec_electric_vehicle_442b803b_1_ds_assert.obj shell_elec_electric_vehicle_442b803b_1_ds_dxdelt_p.obj shell_elec_electric_vehicle_442b803b_1_ds_dxf.obj shell_elec_electric_vehicle_442b803b_1_ds_f.obj shell_elec_electric_vehicle_442b803b_1_ds_dxf_p.obj shell_elec_electric_vehicle_442b803b_1_ds_a_p.obj shell_elec_electric_vehicle_442b803b_1_ds_a.obj shell_elec_electric_vehicle_442b803b_1_ds_tdxf_p.obj shell_elec_electric_vehicle_442b803b_1_ds_slf.obj shell_elec_electric_vehicle_442b803b_1_ds_dxm.obj shell_elec_electric_vehicle_442b803b_1_ds_ic.obj shell_elec_electric_vehicle_442b803b_1_ds_log.obj shell_elec_electric_vehicle_442b803b_1_ds_m.obj shell_elec_electric_vehicle_442b803b_1_ds_m_p.obj shell_elec_electric_vehicle_442b803b_1_ds_dxm_p.obj shell_elec_electric_vehicle_442b803b_1_ds_mode.obj shell_elec_electric_vehicle_442b803b_1_ds_obs_exp.obj shell_elec_electric_vehicle_442b803b_1_ds_tdxy_p.obj shell_elec_electric_vehicle_442b803b_1_ds_obs_act.obj shell_elec_electric_vehicle_442b803b_1_ds_obs_all.obj shell_elec_electric_vehicle_442b803b_1_ds_qx.obj shell_elec_electric_vehicle_442b803b_1_ds_qx_p.obj shell_elec_electric_vehicle_442b803b_1_ds_var_tol.obj shell_elec_electric_vehicle_442b803b_1_ds_dxy_p.obj shell_elec_electric_vehicle_442b803b_1_ds_mdxy_p.obj shell_elec_electric_vehicle_442b803b_1_ds_zc.obj shell_elec_electric_vehicle_442b803b_1.obj shell_elec_electric_vehicle_442b803b_1_gateway.obj pm_printf.obj rt_backsubrr_dbl.obj rt_forwardsubrr_dbl.obj rt_lu_real.obj rt_matrixlib_dbl.obj rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj rt_zcfcn.obj shell_elec_electric_vehicle.obj shell_elec_electric_vehicle_data.obj rt_logging.obj

MAIN_OBJ = rt_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/simscape/engine/sli/lib/win64/SS6C37~1.LIB C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/simscape/engine/core/lib/win64/SSB942~1.LIB C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/NETWOR~1/lib/win64/ne_lcc.lib C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/common/math/core/lib/win64/mc_lcc.lib C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/common/external/library/lib/win64/ex_lcc.lib C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/common/FOUNDA~1/core/lib/win64/pm_lcc.lib

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : build


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(subst /,\,$(OBJS))
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(subst /,\,$(subst /,\,$(MAIN_OBJ))) $(subst /,\,$(subst /,\,$(LIBS))) $(subst /,\,$(subst /,\,$(SYSTEM_LIBS))) $(subst /,\,$(subst /,\,$(TOOLCHAIN_LIBS)))
	@echo "### Created: $(PRODUCT)"
	$(RM) $(CMD_FILE)


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/shell_elec_electric_vehicle_grt_rtw/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/simscape/engine/sli/c/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/simscape/engine/core/c/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/simscape/compiler/core/c/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/network_engine/c/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/common/math/core/c/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/common/lang/core/c/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/common/external/library/c/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/common/foundation/core/c/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : ../%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_main.obj : $(MATLAB_ROOT)/rtw/c/src/common/rt_main.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


#------------------------
# BUILDABLE LIBRARIES
#------------------------

C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/simscape/engine/sli/lib/win64/ssc_sli_lcc.lib : $(LIBSSC_SLI_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBSSC_SLI_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/simscape/engine/core/lib/win64/ssc_core_lcc.lib : $(LIBSSC_CORE_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBSSC_CORE_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/NETWOR~1/lib/win64/ne_lcc.lib : $(LIBNE_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBNE_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/common/math/core/lib/win64/mc_lcc.lib : $(LIBMC_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBMC_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/common/external/library/lib/win64/ex_lcc.lib : $(LIBEX_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBEX_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2016b/toolbox/physmod/common/FOUNDA~1/core/lib/win64/pm_lcc.lib : $(LIBPM_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBPM_LCC_OBJS)


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


