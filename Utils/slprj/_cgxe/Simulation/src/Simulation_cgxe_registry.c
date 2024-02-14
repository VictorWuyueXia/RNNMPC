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
  checksumData[0] = 196577005;
  checksumData[1] = 2015493399;
  checksumData[2] = 935721284;
  checksumData[3] = 2726891565;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 436919724;
  checksumData[1] = 1785888773;
  checksumData[2] = 1506053526;
  checksumData[3] = 1159152402;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 979849666;
  checksumData[1] = 2926213305;
  checksumData[2] = 327434230;
  checksumData[3] = 3151806556;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2033019415;
  checksumData[1] = 306828270;
  checksumData[2] = 2237024133;
  checksumData[3] = 4118633253;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2632041385;
  checksumData[1] = 1820346401;
  checksumData[2] = 3582283875;
  checksumData[3] = 1146030813;
  mxSetCell(mxModules, 4, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3216773775;
  checksumData[1] = 1886668734;
  checksumData[2] = 2910500283;
  checksumData[3] = 635975606;
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
    checksumData[0] = 2735042816;
    checksumData[1] = 1823426486;
    checksumData[2] = 116236990;
    checksumData[3] = 2839938385;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 3902352346;
    checksumData[1] = 1466471745;
    checksumData[2] = 3506349523;
    checksumData[3] = 2918608140;
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
    checksumData[0] = 2478072452;
    checksumData[1] = 1406309965;
    checksumData[2] = 632446080;
    checksumData[3] = 2114857374;
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
  if (strcmp(tpChksum, "7FHURCaqdj8HBx85ZVuatH") == 0) {
    extern mxArray *cgxe_7FHURCaqdj8HBx85ZVuatH_BuildInfoUpdate(void);
    plhs[0] = cgxe_7FHURCaqdj8HBx85ZVuatH_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "Ubuc0hQMhWDyT4IHVUnH3F") == 0) {
    extern mxArray *cgxe_Ubuc0hQMhWDyT4IHVUnH3F_BuildInfoUpdate(void);
    plhs[0] = cgxe_Ubuc0hQMhWDyT4IHVUnH3F_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "dnzcGMWurWPtQDFTDYOwHC") == 0) {
    extern mxArray *cgxe_dnzcGMWurWPtQDFTDYOwHC_BuildInfoUpdate(void);
    plhs[0] = cgxe_dnzcGMWurWPtQDFTDYOwHC_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "CbZldr20LixTpws6qXiNyC") == 0) {
    extern mxArray *cgxe_CbZldr20LixTpws6qXiNyC_BuildInfoUpdate(void);
    plhs[0] = cgxe_CbZldr20LixTpws6qXiNyC_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "tSgvweChskFYUuuPTg6HwH") == 0) {
    extern mxArray *cgxe_tSgvweChskFYUuuPTg6HwH_BuildInfoUpdate(void);
    plhs[0] = cgxe_tSgvweChskFYUuuPTg6HwH_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "klQ7XEZS1zy3wE2vktBM0F") == 0) {
    extern mxArray *cgxe_klQ7XEZS1zy3wE2vktBM0F_BuildInfoUpdate(void);
    plhs[0] = cgxe_klQ7XEZS1zy3wE2vktBM0F_BuildInfoUpdate();
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
  if (strcmp(tpChksum, "7FHURCaqdj8HBx85ZVuatH") == 0) {
    extern mxArray *cgxe_7FHURCaqdj8HBx85ZVuatH_fallback_info(void);
    plhs[0] = cgxe_7FHURCaqdj8HBx85ZVuatH_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "Ubuc0hQMhWDyT4IHVUnH3F") == 0) {
    extern mxArray *cgxe_Ubuc0hQMhWDyT4IHVUnH3F_fallback_info(void);
    plhs[0] = cgxe_Ubuc0hQMhWDyT4IHVUnH3F_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "dnzcGMWurWPtQDFTDYOwHC") == 0) {
    extern mxArray *cgxe_dnzcGMWurWPtQDFTDYOwHC_fallback_info(void);
    plhs[0] = cgxe_dnzcGMWurWPtQDFTDYOwHC_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "CbZldr20LixTpws6qXiNyC") == 0) {
    extern mxArray *cgxe_CbZldr20LixTpws6qXiNyC_fallback_info(void);
    plhs[0] = cgxe_CbZldr20LixTpws6qXiNyC_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "tSgvweChskFYUuuPTg6HwH") == 0) {
    extern mxArray *cgxe_tSgvweChskFYUuuPTg6HwH_fallback_info(void);
    plhs[0] = cgxe_tSgvweChskFYUuuPTg6HwH_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "klQ7XEZS1zy3wE2vktBM0F") == 0) {
    extern mxArray *cgxe_klQ7XEZS1zy3wE2vktBM0F_fallback_info(void);
    plhs[0] = cgxe_klQ7XEZS1zy3wE2vktBM0F_fallback_info();
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
