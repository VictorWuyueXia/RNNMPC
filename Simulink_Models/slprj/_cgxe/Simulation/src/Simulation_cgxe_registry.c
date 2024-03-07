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
  checksumData[0] = 153446712;
  checksumData[1] = 3579856289;
  checksumData[2] = 3336506709;
  checksumData[3] = 3489570508;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 444235368;
  checksumData[1] = 2292809002;
  checksumData[2] = 3522993967;
  checksumData[3] = 2240094667;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1166200749;
  checksumData[1] = 2489865969;
  checksumData[2] = 161800365;
  checksumData[3] = 3682709053;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1564209120;
  checksumData[1] = 1995302686;
  checksumData[2] = 3931225181;
  checksumData[3] = 4275661259;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1585062389;
  checksumData[1] = 1070096283;
  checksumData[2] = 2478312728;
  checksumData[3] = 2363510964;
  mxSetCell(mxModules, 4, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2802779187;
  checksumData[1] = 33447400;
  checksumData[2] = 2331305112;
  checksumData[3] = 1912541166;
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
    checksumData[0] = 3266729155;
    checksumData[1] = 1811913610;
    checksumData[2] = 3504502332;
    checksumData[3] = 839824566;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 3358614544;
    checksumData[1] = 127693073;
    checksumData[2] = 2878341565;
    checksumData[3] = 2731863747;
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
    checksumData[0] = 1779657463;
    checksumData[1] = 3901272433;
    checksumData[2] = 3540903982;
    checksumData[3] = 1424941108;
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
  if (strcmp(tpChksum, "i6JIq3KucPRF5QrGOFwzjB") == 0) {
    extern mxArray *cgxe_i6JIq3KucPRF5QrGOFwzjB_BuildInfoUpdate(void);
    plhs[0] = cgxe_i6JIq3KucPRF5QrGOFwzjB_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "JocDF8MFckqn84Vxx8ZZiG") == 0) {
    extern mxArray *cgxe_JocDF8MFckqn84Vxx8ZZiG_BuildInfoUpdate(void);
    plhs[0] = cgxe_JocDF8MFckqn84Vxx8ZZiG_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "SZ5YeaR6Ox52FcXntkQ9jD") == 0) {
    extern mxArray *cgxe_SZ5YeaR6Ox52FcXntkQ9jD_BuildInfoUpdate(void);
    plhs[0] = cgxe_SZ5YeaR6Ox52FcXntkQ9jD_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "lngpTpB04y9Plw6SQnFI6B") == 0) {
    extern mxArray *cgxe_lngpTpB04y9Plw6SQnFI6B_BuildInfoUpdate(void);
    plhs[0] = cgxe_lngpTpB04y9Plw6SQnFI6B_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "gMjjfv0nELkY1xQ5qDwKMC") == 0) {
    extern mxArray *cgxe_gMjjfv0nELkY1xQ5qDwKMC_BuildInfoUpdate(void);
    plhs[0] = cgxe_gMjjfv0nELkY1xQ5qDwKMC_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "9drqcfEqOaEijwL939rhKE") == 0) {
    extern mxArray *cgxe_9drqcfEqOaEijwL939rhKE_BuildInfoUpdate(void);
    plhs[0] = cgxe_9drqcfEqOaEijwL939rhKE_BuildInfoUpdate();
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
  if (strcmp(tpChksum, "i6JIq3KucPRF5QrGOFwzjB") == 0) {
    extern mxArray *cgxe_i6JIq3KucPRF5QrGOFwzjB_fallback_info(void);
    plhs[0] = cgxe_i6JIq3KucPRF5QrGOFwzjB_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "JocDF8MFckqn84Vxx8ZZiG") == 0) {
    extern mxArray *cgxe_JocDF8MFckqn84Vxx8ZZiG_fallback_info(void);
    plhs[0] = cgxe_JocDF8MFckqn84Vxx8ZZiG_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "SZ5YeaR6Ox52FcXntkQ9jD") == 0) {
    extern mxArray *cgxe_SZ5YeaR6Ox52FcXntkQ9jD_fallback_info(void);
    plhs[0] = cgxe_SZ5YeaR6Ox52FcXntkQ9jD_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "lngpTpB04y9Plw6SQnFI6B") == 0) {
    extern mxArray *cgxe_lngpTpB04y9Plw6SQnFI6B_fallback_info(void);
    plhs[0] = cgxe_lngpTpB04y9Plw6SQnFI6B_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "gMjjfv0nELkY1xQ5qDwKMC") == 0) {
    extern mxArray *cgxe_gMjjfv0nELkY1xQ5qDwKMC_fallback_info(void);
    plhs[0] = cgxe_gMjjfv0nELkY1xQ5qDwKMC_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "9drqcfEqOaEijwL939rhKE") == 0) {
    extern mxArray *cgxe_9drqcfEqOaEijwL939rhKE_fallback_info(void);
    plhs[0] = cgxe_9drqcfEqOaEijwL939rhKE_fallback_info();
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
