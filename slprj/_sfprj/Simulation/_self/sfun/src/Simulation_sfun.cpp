/* Include files */

#include "Simulation_sfun.h"
#include "c2_Simulation.h"
#include "c4_Simulation.h"

/* Forward Declarations */
/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void Simulation_initializer()
{
}

void Simulation_terminator()
{
}

/* SFunction Glue Code */
unsigned int sf_Simulation_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_Simulation_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Simulation_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Simulation_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1955063120U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1515445175U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3469511506U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1110089764U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_Simulation_get_check_sum(mxArray *plhs[]);
          sf_c2_Simulation_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Simulation_get_check_sum(mxArray *plhs[]);
          sf_c4_Simulation_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2775583819U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(82856142U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(949263188U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2220222672U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(107971009U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3727560096U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(574850568U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2892329061U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Simulation_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  char instanceChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    mxGetString(prhs[2], instanceChksum,sizeof(instanceChksum)/sizeof(char));
    instanceChksum[(sizeof(instanceChksum)/sizeof(char)-1)] = '\0';
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(instanceChksum, "s2pkFr2AADZonuySiHiY1ME") == 0) {
          extern const mxArray *sf_c2_Simulation_get_eml_resolved_functions_info
            (void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c2_Simulation_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 4:
      {
        if (strcmp(instanceChksum, "siAFjvTkQ8mpDMAAbKudVC") == 0) {
          extern const mxArray *sf_c4_Simulation_get_eml_resolved_functions_info
            (void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c4_Simulation_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Simulation_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "s2pkFr2AADZonuySiHiY1ME") == 0) {
          extern mxArray *sf_c2_Simulation_third_party_uses_info(void);
          plhs[0] = sf_c2_Simulation_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "siAFjvTkQ8mpDMAAbKudVC") == 0) {
          extern mxArray *sf_c4_Simulation_third_party_uses_info(void);
          plhs[0] = sf_c4_Simulation_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Simulation_jit_fallback_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "s2pkFr2AADZonuySiHiY1ME") == 0) {
          extern mxArray *sf_c2_Simulation_jit_fallback_info(void);
          plhs[0] = sf_c2_Simulation_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "siAFjvTkQ8mpDMAAbKudVC") == 0) {
          extern mxArray *sf_c4_Simulation_jit_fallback_info(void);
          plhs[0] = sf_c4_Simulation_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Simulation_get_post_codegen_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get_post_codegen_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_post_codegen_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "s2pkFr2AADZonuySiHiY1ME") == 0) {
          const char *sf_c2_Simulation_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c2_Simulation_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "siAFjvTkQ8mpDMAAbKudVC") == 0) {
          const char *sf_c4_Simulation_get_post_codegen_info(void);
          const char* encoded_post_codegen_info =
            sf_c4_Simulation_get_post_codegen_info();
          plhs[0] = sf_mex_decode(encoded_post_codegen_info);
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Simulation_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "s2pkFr2AADZonuySiHiY1ME") == 0) {
          extern mxArray *sf_c2_Simulation_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_Simulation_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "siAFjvTkQ8mpDMAAbKudVC") == 0) {
          extern mxArray *sf_c4_Simulation_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_Simulation_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Simulation_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_Simulation_optimization_info(void);
mxArray* load_Simulation_optimization_info(boolean_T isRtwGen, boolean_T
  isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_Simulation_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Simulation",
      "Simulation");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Simulation_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
