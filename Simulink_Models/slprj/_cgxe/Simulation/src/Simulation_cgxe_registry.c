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
  checksumData[0] = 157878504;
  checksumData[1] = 4001787657;
  checksumData[2] = 3213701742;
  checksumData[3] = 1561583486;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 576054828;
  checksumData[1] = 384235410;
  checksumData[2] = 64355062;
  checksumData[3] = 3798346424;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2199502089;
  checksumData[1] = 1048284618;
  checksumData[2] = 198960934;
  checksumData[3] = 1141218566;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3115673736;
  checksumData[1] = 1974039894;
  checksumData[2] = 4280443194;
  checksumData[3] = 1854590770;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3312732043;
  checksumData[1] = 11562350;
  checksumData[2] = 2761741414;
  checksumData[3] = 2336657024;
  mxSetCell(mxModules, 4, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3554441861;
  checksumData[1] = 15995505;
  checksumData[2] = 527288328;
  checksumData[3] = 869250312;
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
    checksumData[0] = 3556843876;
    checksumData[1] = 348208933;
    checksumData[2] = 3747972320;
    checksumData[3] = 3751754803;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 2714832522;
    checksumData[1] = 3642960743;
    checksumData[2] = 1683111881;
    checksumData[3] = 2656063012;
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
    checksumData[0] = 668448459;
    checksumData[1] = 1198472045;
    checksumData[2] = 1488224048;
    checksumData[3] = 3682276124;
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
  if (strcmp(tpChksum, "EEtzHiXfiRvve9WcRzUZ0G") == 0) {
    extern mxArray *cgxe_EEtzHiXfiRvve9WcRzUZ0G_BuildInfoUpdate(void);
    plhs[0] = cgxe_EEtzHiXfiRvve9WcRzUZ0G_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "Gy3UxPXLizbP5xlK4utmDC") == 0) {
    extern mxArray *cgxe_Gy3UxPXLizbP5xlK4utmDC_BuildInfoUpdate(void);
    plhs[0] = cgxe_Gy3UxPXLizbP5xlK4utmDC_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "zcZA3UboXwgydm2Nw2xQGD") == 0) {
    extern mxArray *cgxe_zcZA3UboXwgydm2Nw2xQGD_BuildInfoUpdate(void);
    plhs[0] = cgxe_zcZA3UboXwgydm2Nw2xQGD_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "A3OEzCGKN1ZkDLb8v5muLB") == 0) {
    extern mxArray *cgxe_A3OEzCGKN1ZkDLb8v5muLB_BuildInfoUpdate(void);
    plhs[0] = cgxe_A3OEzCGKN1ZkDLb8v5muLB_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "NvR95jDAEIBMkarGcQ1raB") == 0) {
    extern mxArray *cgxe_NvR95jDAEIBMkarGcQ1raB_BuildInfoUpdate(void);
    plhs[0] = cgxe_NvR95jDAEIBMkarGcQ1raB_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "UsfOBx8CwYjG2xn1VVBw3G") == 0) {
    extern mxArray *cgxe_UsfOBx8CwYjG2xn1VVBw3G_BuildInfoUpdate(void);
    plhs[0] = cgxe_UsfOBx8CwYjG2xn1VVBw3G_BuildInfoUpdate();
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
  if (strcmp(tpChksum, "EEtzHiXfiRvve9WcRzUZ0G") == 0) {
    extern mxArray *cgxe_EEtzHiXfiRvve9WcRzUZ0G_fallback_info(void);
    plhs[0] = cgxe_EEtzHiXfiRvve9WcRzUZ0G_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "Gy3UxPXLizbP5xlK4utmDC") == 0) {
    extern mxArray *cgxe_Gy3UxPXLizbP5xlK4utmDC_fallback_info(void);
    plhs[0] = cgxe_Gy3UxPXLizbP5xlK4utmDC_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "zcZA3UboXwgydm2Nw2xQGD") == 0) {
    extern mxArray *cgxe_zcZA3UboXwgydm2Nw2xQGD_fallback_info(void);
    plhs[0] = cgxe_zcZA3UboXwgydm2Nw2xQGD_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "A3OEzCGKN1ZkDLb8v5muLB") == 0) {
    extern mxArray *cgxe_A3OEzCGKN1ZkDLb8v5muLB_fallback_info(void);
    plhs[0] = cgxe_A3OEzCGKN1ZkDLb8v5muLB_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "NvR95jDAEIBMkarGcQ1raB") == 0) {
    extern mxArray *cgxe_NvR95jDAEIBMkarGcQ1raB_fallback_info(void);
    plhs[0] = cgxe_NvR95jDAEIBMkarGcQ1raB_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "UsfOBx8CwYjG2xn1VVBw3G") == 0) {
    extern mxArray *cgxe_UsfOBx8CwYjG2xn1VVBw3G_fallback_info(void);
    plhs[0] = cgxe_UsfOBx8CwYjG2xn1VVBw3G_fallback_info();
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
