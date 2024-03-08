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
  checksumData[0] = 1065006368;
  checksumData[1] = 1217208527;
  checksumData[2] = 1096120938;
  checksumData[3] = 811435461;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2738713870;
  checksumData[1] = 1342834526;
  checksumData[2] = 1730324275;
  checksumData[3] = 3910327326;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2887874293;
  checksumData[1] = 3458408461;
  checksumData[2] = 4269444112;
  checksumData[3] = 1373635269;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3175323601;
  checksumData[1] = 749882744;
  checksumData[2] = 645409672;
  checksumData[3] = 850471966;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3632150448;
  checksumData[1] = 933365598;
  checksumData[2] = 578439164;
  checksumData[3] = 1077159606;
  mxSetCell(mxModules, 4, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3894687809;
  checksumData[1] = 429432161;
  checksumData[2] = 675749810;
  checksumData[3] = 2571590031;
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
    checksumData[0] = 470819333;
    checksumData[1] = 2939662850;
    checksumData[2] = 3399541659;
    checksumData[3] = 239944847;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 3516500921;
    checksumData[1] = 670541225;
    checksumData[2] = 1846904084;
    checksumData[3] = 2863524970;
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
    checksumData[0] = 3535084922;
    checksumData[1] = 2338023182;
    checksumData[2] = 1690491358;
    checksumData[3] = 3274889427;
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
  if (strcmp(tpChksum, "SB9zHJYh0KMHD57S1kbsM") == 0) {
    extern mxArray *cgxe_SB9zHJYh0KMHD57S1kbsM_BuildInfoUpdate(void);
    plhs[0] = cgxe_SB9zHJYh0KMHD57S1kbsM_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "Tuycm3s88pcXArSxTYlM2C") == 0) {
    extern mxArray *cgxe_Tuycm3s88pcXArSxTYlM2C_BuildInfoUpdate(void);
    plhs[0] = cgxe_Tuycm3s88pcXArSxTYlM2C_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "GQSILvSPCTzISyZ7NYwLIF") == 0) {
    extern mxArray *cgxe_GQSILvSPCTzISyZ7NYwLIF_BuildInfoUpdate(void);
    plhs[0] = cgxe_GQSILvSPCTzISyZ7NYwLIF_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "KqMOmJaMosVk1PSEjFkU4E") == 0) {
    extern mxArray *cgxe_KqMOmJaMosVk1PSEjFkU4E_BuildInfoUpdate(void);
    plhs[0] = cgxe_KqMOmJaMosVk1PSEjFkU4E_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "pwNSslKdKNeB60Ahlj0yKH") == 0) {
    extern mxArray *cgxe_pwNSslKdKNeB60Ahlj0yKH_BuildInfoUpdate(void);
    plhs[0] = cgxe_pwNSslKdKNeB60Ahlj0yKH_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "F0jeqmD47IABR1DbZqFEwB") == 0) {
    extern mxArray *cgxe_F0jeqmD47IABR1DbZqFEwB_BuildInfoUpdate(void);
    plhs[0] = cgxe_F0jeqmD47IABR1DbZqFEwB_BuildInfoUpdate();
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
  if (strcmp(tpChksum, "SB9zHJYh0KMHD57S1kbsM") == 0) {
    extern mxArray *cgxe_SB9zHJYh0KMHD57S1kbsM_fallback_info(void);
    plhs[0] = cgxe_SB9zHJYh0KMHD57S1kbsM_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "Tuycm3s88pcXArSxTYlM2C") == 0) {
    extern mxArray *cgxe_Tuycm3s88pcXArSxTYlM2C_fallback_info(void);
    plhs[0] = cgxe_Tuycm3s88pcXArSxTYlM2C_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "GQSILvSPCTzISyZ7NYwLIF") == 0) {
    extern mxArray *cgxe_GQSILvSPCTzISyZ7NYwLIF_fallback_info(void);
    plhs[0] = cgxe_GQSILvSPCTzISyZ7NYwLIF_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "KqMOmJaMosVk1PSEjFkU4E") == 0) {
    extern mxArray *cgxe_KqMOmJaMosVk1PSEjFkU4E_fallback_info(void);
    plhs[0] = cgxe_KqMOmJaMosVk1PSEjFkU4E_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "pwNSslKdKNeB60Ahlj0yKH") == 0) {
    extern mxArray *cgxe_pwNSslKdKNeB60Ahlj0yKH_fallback_info(void);
    plhs[0] = cgxe_pwNSslKdKNeB60Ahlj0yKH_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "F0jeqmD47IABR1DbZqFEwB") == 0) {
    extern mxArray *cgxe_F0jeqmD47IABR1DbZqFEwB_fallback_info(void);
    plhs[0] = cgxe_F0jeqmD47IABR1DbZqFEwB_fallback_info();
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
