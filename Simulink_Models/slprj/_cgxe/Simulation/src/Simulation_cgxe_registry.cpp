#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                Simulation_cgxe
#include "simstruc.h"
#include "Simulation_cgxe.hpp"
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
  checksumData[0] = 1121014787;
  checksumData[1] = 1391846244;
  checksumData[2] = 820181253;
  checksumData[3] = 3455596994;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2209566692;
  checksumData[1] = 875839503;
  checksumData[2] = 1047498558;
  checksumData[3] = 1771902077;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2766517331;
  checksumData[1] = 3970157338;
  checksumData[2] = 1077290368;
  checksumData[3] = 1336294495;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3090108058;
  checksumData[1] = 3172431932;
  checksumData[2] = 2406867171;
  checksumData[3] = 51515358;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3955171895;
  checksumData[1] = 661154611;
  checksumData[2] = 140638312;
  checksumData[3] = 414028511;
  mxSetCell(mxModules, 4, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3976561189;
  checksumData[1] = 3017949172;
  checksumData[2] = 1188770181;
  checksumData[3] = 1582093972;
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
    checksumData[0] = 3230105264;
    checksumData[1] = 723997052;
    checksumData[2] = 1916306164;
    checksumData[3] = 3194113094;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 3564887269;
    checksumData[1] = 2264869073;
    checksumData[2] = 2610247317;
    checksumData[3] = 4111944923;
    mxSetField(mxChecksum, 0, "makefile", mxMakefileChksum);
  }

  {
    mxArray* mxTargetChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxTargetChksum);
    checksumData[0] = 138454357;
    checksumData[1] = 2309299117;
    checksumData[2] = 638394794;
    checksumData[3] = 1105183017;
    mxSetField(mxChecksum, 0, "target", mxTargetChksum);
  }

  {
    mxArray* mxOverallChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxOverallChksum);
    checksumData[0] = 245880362;
    checksumData[1] = 4085688385;
    checksumData[2] = 1413062491;
    checksumData[3] = 3144617887;
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
  if (strcmp(tpChksum, "ZRrpjjOELWkOuMsKQEyWoF") == 0) {
    extern mxArray *cgxe_ZRrpjjOELWkOuMsKQEyWoF_BuildInfoUpdate(void);
    plhs[0] = cgxe_ZRrpjjOELWkOuMsKQEyWoF_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "mZFHXjKJf39PvHko4ZIKxC") == 0) {
    extern mxArray *cgxe_mZFHXjKJf39PvHko4ZIKxC_BuildInfoUpdate(void);
    plhs[0] = cgxe_mZFHXjKJf39PvHko4ZIKxC_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "56gefFAY8sWtm2RGYfNlU") == 0) {
    extern mxArray *cgxe_56gefFAY8sWtm2RGYfNlU_BuildInfoUpdate(void);
    plhs[0] = cgxe_56gefFAY8sWtm2RGYfNlU_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "WFiyNWZ93pktdiGZeY69YB") == 0) {
    extern mxArray *cgxe_WFiyNWZ93pktdiGZeY69YB_BuildInfoUpdate(void);
    plhs[0] = cgxe_WFiyNWZ93pktdiGZeY69YB_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "pjFZoYX16idRmw1zvTmDE") == 0) {
    extern mxArray *cgxe_pjFZoYX16idRmw1zvTmDE_BuildInfoUpdate(void);
    plhs[0] = cgxe_pjFZoYX16idRmw1zvTmDE_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "RoES6REdnpdpdiUOCbCqeE") == 0) {
    extern mxArray *cgxe_RoES6REdnpdpdiUOCbCqeE_BuildInfoUpdate(void);
    plhs[0] = cgxe_RoES6REdnpdpdiUOCbCqeE_BuildInfoUpdate();
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
  if (strcmp(tpChksum, "ZRrpjjOELWkOuMsKQEyWoF") == 0) {
    extern mxArray *cgxe_ZRrpjjOELWkOuMsKQEyWoF_fallback_info(void);
    plhs[0] = cgxe_ZRrpjjOELWkOuMsKQEyWoF_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "mZFHXjKJf39PvHko4ZIKxC") == 0) {
    extern mxArray *cgxe_mZFHXjKJf39PvHko4ZIKxC_fallback_info(void);
    plhs[0] = cgxe_mZFHXjKJf39PvHko4ZIKxC_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "56gefFAY8sWtm2RGYfNlU") == 0) {
    extern mxArray *cgxe_56gefFAY8sWtm2RGYfNlU_fallback_info(void);
    plhs[0] = cgxe_56gefFAY8sWtm2RGYfNlU_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "WFiyNWZ93pktdiGZeY69YB") == 0) {
    extern mxArray *cgxe_WFiyNWZ93pktdiGZeY69YB_fallback_info(void);
    plhs[0] = cgxe_WFiyNWZ93pktdiGZeY69YB_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "pjFZoYX16idRmw1zvTmDE") == 0) {
    extern mxArray *cgxe_pjFZoYX16idRmw1zvTmDE_fallback_info(void);
    plhs[0] = cgxe_pjFZoYX16idRmw1zvTmDE_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "RoES6REdnpdpdiUOCbCqeE") == 0) {
    extern mxArray *cgxe_RoES6REdnpdpdiUOCbCqeE_fallback_info(void);
    plhs[0] = cgxe_RoES6REdnpdpdiUOCbCqeE_fallback_info();
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
