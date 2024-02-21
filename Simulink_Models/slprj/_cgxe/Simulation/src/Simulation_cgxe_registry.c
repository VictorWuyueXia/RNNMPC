#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                Simulation_cgxe
#include "simstruc.h"
#include "Simulation_cgxe.h"
#define MDL_START

static void mdlStart(SimStruct* S)
{
  unsigned int success;
  success = cgxe_Simulation_method_dispatcher(S, SS_CALL_MDL_START, NULL);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }
}

#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlInitializeConditions method directly.\n");
}

#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlUpdate method directly.\n");
}

static void mdlOutputs(SimStruct* S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlOutputs method directly.\n");
}

static void mdlTerminate(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlTerminate method directly.\n");
}

static void mdlInitializeSizes(SimStruct *S)
{
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
}

static mxArray* cgxe_get_supported_modules(void)
{
  mxArray* mxModules = mxCreateCellMatrix(6, 1);
  mxArray* mxChksum = NULL;
  uint32_T* checksumData = NULL;
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 104879594;
  checksumData[1] = 3833300259;
  checksumData[2] = 4229585988;
  checksumData[3] = 1211985281;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 427064520;
  checksumData[1] = 303696802;
  checksumData[2] = 3178787481;
  checksumData[3] = 2624036092;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1261712584;
  checksumData[1] = 605983007;
  checksumData[2] = 520643782;
  checksumData[3] = 758256508;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2337988574;
  checksumData[1] = 1462109421;
  checksumData[2] = 2341626354;
  checksumData[3] = 1946879561;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2721415071;
  checksumData[1] = 3258777778;
  checksumData[2] = 3392792636;
  checksumData[3] = 3068205031;
  mxSetCell(mxModules, 4, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2867611393;
  checksumData[1] = 2692440233;
  checksumData[2] = 3079015999;
  checksumData[3] = 3288895526;
  mxSetCell(mxModules, 5, mxChksum);
  return mxModules;
}

static int cgxe_process_get_checksums(int nlhs, mxArray* plhs[], int nrhs, const
  mxArray* prhs[])
{
  const char* checksumFields[] = { "modules", "model", "makefile", "target",
    "overall" };

  mxArray* mxChecksum = mxCreateStructMatrix(1, 1, 5, checksumFields);
  mxSetField(mxChecksum, 0, "modules", cgxe_get_supported_modules());

  {
    mxArray* mxModelChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxModelChksum);
    checksumData[0] = 1881842578;
    checksumData[1] = 4185565304;
    checksumData[2] = 1897962338;
    checksumData[3] = 693144865;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 811512488;
    checksumData[1] = 3695208091;
    checksumData[2] = 3974489156;
    checksumData[3] = 120904266;
    mxSetField(mxChecksum, 0, "makefile", mxMakefileChksum);
  }

  {
    mxArray* mxTargetChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxTargetChksum);
    checksumData[0] = 2911221907;
    checksumData[1] = 2308967934;
    checksumData[2] = 2419390157;
    checksumData[3] = 1906300239;
    mxSetField(mxChecksum, 0, "target", mxTargetChksum);
  }

  {
    mxArray* mxOverallChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxOverallChksum);
    checksumData[0] = 1269491564;
    checksumData[1] = 2548117028;
    checksumData[2] = 1573699137;
    checksumData[3] = 978803412;
    mxSetField(mxChecksum, 0, "overall", mxOverallChksum);
  }

  plhs[0] = mxChecksum;
  return 1;
}

static int cgxe_mex_unlock_call(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  while (mexIsLocked()) {
    mexUnlock();
  }

  return 1;
}

static SimStruct* cgxe_unpack_simstruct(const mxArray *mxS)
{
  uint32_T *uintPtr = (uint32_T*)malloc(sizeof(SimStruct*));
  int nEl = sizeof(SimStruct*)/sizeof(uint32_T);
  uint32_T *uintDataPtr = (uint32_T *)mxGetData(mxS);
  int el;
  SimStruct *S;
  for (el=0; el < nEl; el++) {
    uintPtr[el] = uintDataPtr[el];
  }

  memcpy(&S,uintPtr,sizeof(SimStruct*));
  free(uintPtr);
  return S;
}

static int cgxe_get_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_Simulation_method_dispatcher(S, SS_CALL_MDL_GET_SIM_STATE,
    (void *) (plhs));
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_set_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_Simulation_method_dispatcher(S, SS_CALL_MDL_SET_SIM_STATE,
    (void *) prhs[2]);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_get_BuildInfoUpdate(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "MZ052aXbO4TZnBM2ZpV4mC") == 0) {
    extern mxArray *cgxe_MZ052aXbO4TZnBM2ZpV4mC_BuildInfoUpdate(void);
    plhs[0] = cgxe_MZ052aXbO4TZnBM2ZpV4mC_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "W2hcibOvtpwvw1S3wCpu6C") == 0) {
    extern mxArray *cgxe_W2hcibOvtpwvw1S3wCpu6C_BuildInfoUpdate(void);
    plhs[0] = cgxe_W2hcibOvtpwvw1S3wCpu6C_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "pUpcZnZhk1ZuuS3YohifKG") == 0) {
    extern mxArray *cgxe_pUpcZnZhk1ZuuS3YohifKG_BuildInfoUpdate(void);
    plhs[0] = cgxe_pUpcZnZhk1ZuuS3YohifKG_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "xGMPP5dg6NcOAWHcDYFG3E") == 0) {
    extern mxArray *cgxe_xGMPP5dg6NcOAWHcDYFG3E_BuildInfoUpdate(void);
    plhs[0] = cgxe_xGMPP5dg6NcOAWHcDYFG3E_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "JfY3qUib7paXLgdilcvOr") == 0) {
    extern mxArray *cgxe_JfY3qUib7paXLgdilcvOr_BuildInfoUpdate(void);
    plhs[0] = cgxe_JfY3qUib7paXLgdilcvOr_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "SvSMygm8xP7OgFQXmKzyxF") == 0) {
    extern mxArray *cgxe_SvSMygm8xP7OgFQXmKzyxF_BuildInfoUpdate(void);
    plhs[0] = cgxe_SvSMygm8xP7OgFQXmKzyxF_BuildInfoUpdate();
    return 1;
  }

  return 0;
}

static int cgxe_get_fallback_info(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "MZ052aXbO4TZnBM2ZpV4mC") == 0) {
    extern mxArray *cgxe_MZ052aXbO4TZnBM2ZpV4mC_fallback_info(void);
    plhs[0] = cgxe_MZ052aXbO4TZnBM2ZpV4mC_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "W2hcibOvtpwvw1S3wCpu6C") == 0) {
    extern mxArray *cgxe_W2hcibOvtpwvw1S3wCpu6C_fallback_info(void);
    plhs[0] = cgxe_W2hcibOvtpwvw1S3wCpu6C_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "pUpcZnZhk1ZuuS3YohifKG") == 0) {
    extern mxArray *cgxe_pUpcZnZhk1ZuuS3YohifKG_fallback_info(void);
    plhs[0] = cgxe_pUpcZnZhk1ZuuS3YohifKG_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "xGMPP5dg6NcOAWHcDYFG3E") == 0) {
    extern mxArray *cgxe_xGMPP5dg6NcOAWHcDYFG3E_fallback_info(void);
    plhs[0] = cgxe_xGMPP5dg6NcOAWHcDYFG3E_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "JfY3qUib7paXLgdilcvOr") == 0) {
    extern mxArray *cgxe_JfY3qUib7paXLgdilcvOr_fallback_info(void);
    plhs[0] = cgxe_JfY3qUib7paXLgdilcvOr_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "SvSMygm8xP7OgFQXmKzyxF") == 0) {
    extern mxArray *cgxe_SvSMygm8xP7OgFQXmKzyxF_fallback_info(void);
    plhs[0] = cgxe_SvSMygm8xP7OgFQXmKzyxF_fallback_info();
    return 1;
  }

  return 0;
}

#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

static int ProcessMexSfunctionCmdLineCall(int nlhs, mxArray* plhs[], int nrhs,
  const mxArray* prhs[])
{
  char commandName[64];
  if (nrhs < 1 || !mxIsChar(prhs[0]))
    return 0;
  mxGetString(prhs[0], commandName, sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName, "get_checksums") == 0) {
    return cgxe_process_get_checksums(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "mex_unlock") == 0) {
    return cgxe_mex_unlock_call(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_sim_state") == 0) {
    return cgxe_get_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "set_sim_state") == 0) {
    return cgxe_set_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_BuildInfoUpdate") == 0) {
    return cgxe_get_BuildInfoUpdate(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_fallback_info") == 0) {
    return cgxe_get_fallback_info(nlhs, plhs, nrhs, prhs);
  }

  return 0;
}

#include "simulink.c"
