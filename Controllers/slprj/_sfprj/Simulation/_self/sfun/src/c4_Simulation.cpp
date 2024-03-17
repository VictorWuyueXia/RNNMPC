/* Include files */

#include "Simulation_sfun.h"
#include "c4_Simulation.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
const int32_T CALL_EVENT{ -1 };

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtBCInfo c4_emlrtBCI{ 0,     /* iFirst */
  11,                                  /* iLast */
  2,                                   /* lineNo */
  7,                                   /* colNo */
  "x",                                 /* aName */
  "MPC/Lane Vectorize/NaN to 0",       /* fName */
  "#Simulation:1176",                  /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c4_emlrtDCI{ 2,     /* lineNo */
  7,                                   /* colNo */
  "MPC/Lane Vectorize/NaN to 0",       /* fName */
  "#Simulation:1176",                  /* pName */
  1                                    /* checkKind */
};

/* Function Declarations */
static void initialize_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance);
static void initialize_params_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance);
static void mdl_start_c4_Simulation(SFc4_SimulationInstanceStruct *chartInstance);
static void mdl_terminate_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c4_Simulation
  (SFc4_SimulationInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c4_Simulation
  (SFc4_SimulationInstanceStruct *chartInstance);
static void enable_c4_Simulation(SFc4_SimulationInstanceStruct *chartInstance);
static void disable_c4_Simulation(SFc4_SimulationInstanceStruct *chartInstance);
static void sf_gateway_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance);
static void ext_mode_exec_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance);
static void c4_update_jit_animation_c4_Simulation(SFc4_SimulationInstanceStruct *
  chartInstance);
static void c4_do_animation_call_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_Simulation(SFc4_SimulationInstanceStruct *
  chartInstance);
static void set_sim_state_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void initSimStructsc4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance);
static void initSubchartIOPointersc4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance);
static void c4_emlrt_marshallIn(SFc4_SimulationInstanceStruct *chartInstance,
  const mxArray *c4_nullptr, const char_T *c4_identifier, real_T c4_y[12]);
static void c4_b_emlrt_marshallIn(SFc4_SimulationInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[12]);
static uint8_T c4_c_emlrt_marshallIn(SFc4_SimulationInstanceStruct
  *chartInstance, const mxArray *c4_nullptr, const char_T *c4_identifier);
static uint8_T c4_d_emlrt_marshallIn(SFc4_SimulationInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_slStringInitializeDynamicBuffers(SFc4_SimulationInstanceStruct
  *chartInstance);
static void c4_chart_data_browse_helper(SFc4_SimulationInstanceStruct
  *chartInstance, int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T
  *c4_isValueTooBig);
static void init_dsm_address_info(SFc4_SimulationInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_SimulationInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance)
{
  sf_is_first_init_cond(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_doneDoubleBufferReInit = false;
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance)
{
}

static void mdl_start_c4_Simulation(SFc4_SimulationInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance)
{
}

static void mdl_setup_runtime_resources_c4_Simulation
  (SFc4_SimulationInstanceStruct *chartInstance)
{
  static const uint32_T c4_decisionTxtEndIdx{ 0U };

  static const uint32_T c4_decisionTxtStartIdx{ 0U };

  sfSetAnimationVectors(chartInstance->S, chartInstance->c4_JITStateAnimation,
                        chartInstance->c4_JITTransitionAnimation);
  setDataBrowseFcn(chartInstance->S, (void *)&c4_chart_data_browse_helper);
  chartInstance->c4_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c4_RuntimeVar,
    &chartInstance->c4_IsDebuggerActive,
    &chartInstance->c4_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c4_mlFcnLineNumber, &chartInstance->c4_IsHeatMapPresent, 0);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    18U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 42);
}

static void mdl_cleanup_runtime_resources_c4_Simulation
  (SFc4_SimulationInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c4_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void enable_c4_Simulation(SFc4_SimulationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_Simulation(SFc4_SimulationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance)
{
  emlrtStack c4_st{ NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c4_d;
  int32_T c4_b_i;
  int32_T c4_end;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  for (c4_i = 0; c4_i < 12; c4_i++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 0U, (*chartInstance->c4_x)
                      [c4_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  chartInstance->c4_sfEvent = CALL_EVENT;
  for (c4_i1 = 0; c4_i1 < 12; c4_i1++) {
    (*chartInstance->c4_b_x)[c4_i1] = (*chartInstance->c4_x)[c4_i1];
  }

  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  c4_end = 12;
  for (c4_b_i = 0; c4_b_i < c4_end; c4_b_i++) {
    if (muDoubleScalarIsNaN((*chartInstance->c4_b_x)[c4_b_i])) {
      c4_d = static_cast<real_T>(c4_b_i);
      if (c4_d != static_cast<real_T>(static_cast<int32_T>(muDoubleScalarFloor
            (c4_d)))) {
        emlrtIntegerCheckR2012b(c4_d, &c4_emlrtDCI, &c4_st);
      }

      c4_i3 = static_cast<int32_T>(muDoubleScalarFloor(c4_d));
      if ((c4_i3 < 0) || (c4_i3 > 11)) {
        emlrtDynamicBoundsCheckR2012b(c4_i3, 0, 11, &c4_emlrtBCI, &c4_st);
      }

      (*chartInstance->c4_b_x)[c4_i3] = 0.0;
    }
  }

  c4_do_animation_call_c4_Simulation(chartInstance);
  for (c4_i2 = 0; c4_i2 < 12; c4_i2++) {
    covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U,
                      (*chartInstance->c4_b_x)[c4_i2]);
  }
}

static void ext_mode_exec_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance)
{
}

static void c4_update_jit_animation_c4_Simulation(SFc4_SimulationInstanceStruct *
  chartInstance)
{
}

static void c4_do_animation_call_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c4_Simulation(SFc4_SimulationInstanceStruct *
  chartInstance)
{
  const mxArray *c4_b_y{ nullptr };

  const mxArray *c4_c_y{ nullptr };

  const mxArray *c4_st;
  const mxArray *c4_y{ nullptr };

  c4_st = nullptr;
  c4_st = nullptr;
  c4_y = nullptr;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  c4_b_y = nullptr;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", *chartInstance->c4_b_x, 0, 0U, 1U,
    0U, 2, 6, 2), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = nullptr;
  sf_mex_assign(&c4_c_y, sf_mex_create("y",
    &chartInstance->c4_is_active_c4_Simulation, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv[12];
  int32_T c4_i;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "x",
                      c4_dv);
  for (c4_i = 0; c4_i < 12; c4_i++) {
    (*chartInstance->c4_b_x)[c4_i] = c4_dv[c4_i];
  }

  chartInstance->c4_is_active_c4_Simulation = c4_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_Simulation");
  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void initSimStructsc4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance)
{
}

static void initSubchartIOPointersc4_Simulation(SFc4_SimulationInstanceStruct
  *chartInstance)
{
}

const mxArray *sf_c4_Simulation_get_eml_resolved_functions_info()
{
  const mxArray *c4_nameCaptureInfo{ nullptr };

  c4_nameCaptureInfo = nullptr;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", nullptr, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static void c4_emlrt_marshallIn(SFc4_SimulationInstanceStruct *chartInstance,
  const mxArray *c4_nullptr, const char_T *c4_identifier, real_T c4_y[12])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = const_cast<const char_T *>(c4_identifier);
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nullptr), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_nullptr);
}

static void c4_b_emlrt_marshallIn(SFc4_SimulationInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[12])
{
  real_T c4_dv[12];
  int32_T c4_i;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv, 1, 0, 0U, 1, 0U, 2, 6, 2);
  for (c4_i = 0; c4_i < 12; c4_i++) {
    c4_y[c4_i] = c4_dv[c4_i];
  }

  sf_mex_destroy(&c4_u);
}

static uint8_T c4_c_emlrt_marshallIn(SFc4_SimulationInstanceStruct
  *chartInstance, const mxArray *c4_nullptr, const char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  c4_thisId.fIdentifier = const_cast<const char_T *>(c4_identifier);
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nullptr), &c4_thisId);
  sf_mex_destroy(&c4_nullptr);
  return c4_y;
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_SimulationInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_b_u;
  uint8_T c4_y;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b_u, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_b_u;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_slStringInitializeDynamicBuffers(SFc4_SimulationInstanceStruct
  *chartInstance)
{
}

static void c4_chart_data_browse_helper(SFc4_SimulationInstanceStruct
  *chartInstance, int32_T c4_ssIdNumber, const mxArray **c4_mxData, uint8_T
  *c4_isValueTooBig)
{
  *c4_mxData = nullptr;
  *c4_mxData = nullptr;
  *c4_isValueTooBig = 0U;
  switch (c4_ssIdNumber) {
   case 4U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", *chartInstance->c4_b_x, 0,
      0U, 1U, 0U, 2, 6, 2), false);
    break;

   case 5U:
    sf_mex_assign(c4_mxData, sf_mex_create("mxData", *chartInstance->c4_b_x, 0,
      0U, 1U, 0U, 2, 6, 2), false);
    break;
  }
}

static void init_dsm_address_info(SFc4_SimulationInstanceStruct *chartInstance)
{
}

static void init_simulink_io_address(SFc4_SimulationInstanceStruct
  *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_x = (real_T (*)[12])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_b_x = (real_T (*)[12])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_Simulation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3898346802U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3144069466U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(390652823U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2061216810U);
}

mxArray *sf_c4_Simulation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_Simulation_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_vars");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_Simulation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_Simulation(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wMjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI6BcAsiqg4QILH/LtV3CgTD/Efg"
    "8C7hdHcT+En1kcn5hcklmWGp9sEh+cmVuak1iSmZ8H9xcAWMAY1g=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Simulation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sv1XYvRnUbaktwvuxbspKCH";
}

static void sf_opaque_initialize_c4_Simulation(void *chartInstanceVar)
{
  initialize_params_c4_Simulation((SFc4_SimulationInstanceStruct*)
    chartInstanceVar);
  initialize_c4_Simulation((SFc4_SimulationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_Simulation(void *chartInstanceVar)
{
  enable_c4_Simulation((SFc4_SimulationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_Simulation(void *chartInstanceVar)
{
  disable_c4_Simulation((SFc4_SimulationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_Simulation(void *chartInstanceVar)
{
  sf_gateway_c4_Simulation((SFc4_SimulationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_Simulation(SimStruct* S)
{
  return get_sim_state_c4_Simulation((SFc4_SimulationInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_Simulation(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c4_Simulation((SFc4_SimulationInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c4_Simulation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_SimulationInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Simulation_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_Simulation((SFc4_SimulationInstanceStruct*)
      chartInstanceVar);
    ((SFc4_SimulationInstanceStruct*) chartInstanceVar)->
      ~SFc4_SimulationInstanceStruct();
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_Simulation(void *chartInstanceVar)
{
  mdl_start_c4_Simulation((SFc4_SimulationInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc4_SimulationInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c4_Simulation(void *chartInstanceVar)
{
  mdl_terminate_c4_Simulation((SFc4_SimulationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Simulation(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_Simulation((SFc4_SimulationInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc4_Simulation((SFc4_SimulationInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_Simulation_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWE+P20QUn0TLilbtag9IcEBijxyKRAtIHKDs1k7aiF121WQLVCqrif0SjzIeu/PHSThVvfX",
    "Ad+DEJ+DGF+Aj8Ak4c+TIG8dJgzckHqcqbS05ztj+zXvvN+/fmDQ6JwSPPTwP3iNkF69v49kks+",
    "OtYtxYOmf3d8gXxfj3q4QESQhDEF0zGLAJcTuEic+opLEi7oegMdwHlXCjWSI6YpBUxzIxAAkiw",
    "AnSRGonuYrFhjMxahsRWMnq24gFUTdKDA/v4IQ0PBV8+l9yU6PPUKLPJAS6DRDqSCZmGLU5Ha5n",
    "QeqxF0EwUiZ25kqB7prUmqpODNcs5dCaQNARSlNkQW2wt6upBk9P3Ei29qruHJ3EKWdUVOc6oqo",
    "LKXqHhvM0xN9To5G9inJRXp8JqhPJKG/F3IuorIo946jnCbo1d+ZZx9qHvhkOmRhadqWJQaD96C",
    "cVuBp4SQaSDuFUuMkNrHWtSb7AC7+siNUshgdUHgXoBwpCtxhEB1ZdiksLPZzGCQuC9jl0VE+yD",
    "NfINW90bCjVyhsmnnmSqoXN5bYyXFVVU247EB7lXLlhe0l6DBnwXL5PNa2Bncl3ACvFwl6C3mEj",
    "1zH6jWCPDRRYLxEhq+6VWQmVF4lvMOFXgLPYhgGESPNC9cVEm+LIKJ3EHoa+f3xcUd5lbEdokAM",
    "aQOV8LSlTgArnfuUoN2TKBhKikSWdW1l5hlkM1oISNTDCHydyhBy7FobnXNlIcENDOAQfNORJro",
    "Xe/YByU1HnWGFWtu5xrjDLuslFrI2fWuCABhGEtgYyDieYZ3GCqkusbPk8Qmszpqc+qECytGokG",
    "UzoWPwsS71pCudiJJKxaMsk7hZdzBq/AsCsQaXAUnYHS6mctlH5alpLeNzLs7trw2B5pprTvvWN",
    "uyCwGlpbbfWmAUZVS2C7iQptg+2yH7EdEYopjS3gtJXHQJj3wYfkeR+8s6IPvr7UB+8X4+DTi5z",
    "MeZG383y8NM+1Cv00qYAjl3BkgZtfP1zCN1bIJUvXsrwrzfV6NvFfo8At83S9JGenhNstuHry6w",
    "/+M//LX54+evjbT3/eeLSN/J+bbvuVvWL8/rxXWmTm7FLysu/e2+AH75b8wI5VdvO777P74rxPR",
    "3qcmUlfpV979/L5/mqs17dZ0nd+/8D2Zxi4eR6QQScs9j12TM2sH7fzf76k7+4GPq4s+RNq9tV2",
    "+HcOy+u4swG/j/8mJb+tL//gcDt8/fVm6oLarAwX/84Aey8gvlxxr4u8N13PF2lflbrxsnHkJeO",
    "2tc+1Hr7u76/Lw6T0/v4rbEf5WrcvetXs+oO49S0fFOPbi724FzEertgNFI+xYR+sevqG+Pffjv",
    "zN63bL8ld8AH34yZGgfIrt/2x7Vdw+k/bb2+KRBKpW77H+j3pCVvTdq/qUa6X4tuMxE2EyVh/dv",
    "PXZrW3q0z8L+AVv",
    ""
  };

  static char newstr [1441] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_Simulation(SimStruct *S)
{
  const char* newstr = sf_c4_Simulation_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1147057280U));
  ssSetChecksum1(S,(2789033097U));
  ssSetChecksum2(S,(3143261570U));
  ssSetChecksum3(S,(1563223693U));
}

static void mdlRTW_c4_Simulation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_Simulation(SimStruct *S)
{
  SFc4_SimulationInstanceStruct *chartInstance;
  chartInstance = (SFc4_SimulationInstanceStruct *)utMalloc(sizeof
    (SFc4_SimulationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_SimulationInstanceStruct));
  chartInstance = new (chartInstance) SFc4_SimulationInstanceStruct;
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_Simulation;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_Simulation;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_Simulation;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c4_Simulation;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_Simulation;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_Simulation;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_Simulation;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_Simulation;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_Simulation;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_Simulation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Simulation;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_Simulation;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c4_Simulation(chartInstance);
}

void c4_Simulation_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_Simulation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Simulation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Simulation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Simulation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
