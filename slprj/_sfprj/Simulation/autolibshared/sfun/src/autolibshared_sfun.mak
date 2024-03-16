# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64

MODEL     = autolibshared
TARGET      = sfun
MODULE_SRCS   = c3_autolibshared.cpp half_type.cpp
MODEL_SRC  = autolibshared_sfun.cpp
MODEL_REG = 
MAKEFILE    = autolibshared_sfun.mak
MATLAB_ROOT  = C:\Program Files\MATLAB\R2023b
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   =  /I "C:\Users\administrator\documents\RNNMPC\slprj\_sfprj\simulation\autolibshared\sfun\src" /I "C:\Users\administrator\documents\RNNMPC" /I "C:\Users\administrator\documents\RNNMPC\simulink_models"
AUX_INCLUDES   = 
MLSLSF_INCLUDES = \
    /I "C:\Program Files\MATLAB\R2023b\extern\include" \
    /I "C:\Program Files\MATLAB\R2023b\simulink\include" \
    /I "C:\Program Files\MATLAB\R2023b\simulink\include\sf_runtime" \
    /I "C:\Program Files\MATLAB\R2023b\stateflow\c\mex\include" \
    /I "C:\Program Files\MATLAB\R2023b\rtw\c\src" \
    /I "C:\Users\Administrator\Documents\RNNMPC\slprj\_sfprj\Simulation\autolibshared\sfun\src" 

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   = 
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(MLSLSF_INCLUDES)\
 $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMX_COMPAT_64 /DMATLAB_MEXCMD_RELEASE=R2018a /DMATLAB_MEX_FILE /nologo /MD  
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction /export:mexfilerequiredapiversion  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MODEL_SRC) $(MODEL_REG) $(MODULE_SRCS)

USER_OBJS =

AUX_ABS_OBJS =

THIRD_PARTY_OBJS     = \
     "c_mexapi_version.obj" \

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_OBJS) $(AUX_ABS_OBJS) $(THIRD_PARTY_OBJS)
OBJLIST_FILE = autolibshared_sfun.mol
SFCLIB = 
AUX_LNK_OBJS =     
USER_LIBS = 
#--------------------------------- Rules --------------------------------------

$(MODEL)_$(TARGET).lib : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
	@echo ### Linking ...
	$(LD) -lib /OUT:$(MODEL)_$(TARGET).lib @$(OBJLIST_FILE) $(USER_LIBS) $(THIRD_PARTY_LIBS)
	@echo ### Created Stateflow library $@
.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


c_mexapi_version.obj :  "C:\Program Files\MATLAB\R2023b\extern\version\c_mexapi_version.c"
	@echo ### Compiling "C:\Program Files\MATLAB\R2023b\extern\version\c_mexapi_version.c"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2023b\extern\version\c_mexapi_version.c"
