/* Include files */

#include "Simulation_sfun.h"
#include "c2_Simulation.h"
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
static emlrtRTEInfo c2_emlrtRTEI{ 128, /* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2023b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

/* Function Declarations */
static void initialize_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance);
static void initialize_params_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance);
static void mdl_start_c2_Simulation(SFc2_SimulationInstanceStruct *chartInstance);
static void mdl_terminate_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c2_Simulation
  (SFc2_SimulationInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c2_Simulation
  (SFc2_SimulationInstanceStruct *chartInstance);
static void enable_c2_Simulation(SFc2_SimulationInstanceStruct *chartInstance);
static void disable_c2_Simulation(SFc2_SimulationInstanceStruct *chartInstance);
static void sf_gateway_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance);
static void ext_mode_exec_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance);
static void c2_update_jit_animation_c2_Simulation(SFc2_SimulationInstanceStruct *
  chartInstance);
static void c2_do_animation_call_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_Simulation(SFc2_SimulationInstanceStruct *
  chartInstance);
static void set_sim_state_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void initSimStructsc2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance);
static void initSubchartIOPointersc2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance);
static void c2_emlrt_marshallIn(SFc2_SimulationInstanceStruct *chartInstance,
  const mxArray *c2_nullptr, const char_T *c2_identifier, real_T c2_y[12]);
static void c2_b_emlrt_marshallIn(SFc2_SimulationInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[12]);
static uint8_T c2_c_emlrt_marshallIn(SFc2_SimulationInstanceStruct
  *chartInstance, const mxArray *c2_nullptr, const char_T *c2_identifier);
static uint8_T c2_d_emlrt_marshallIn(SFc2_SimulationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_slStringInitializeDynamicBuffers(SFc2_SimulationInstanceStruct
  *chartInstance);
static void c2_chart_data_browse_helper(SFc2_SimulationInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig);
static void init_dsm_address_info(SFc2_SimulationInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_SimulationInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance)
{
  sf_is_first_init_cond(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c2_doneDoubleBufferReInit = false;
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance)
{
}

static void mdl_start_c2_Simulation(SFc2_SimulationInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance)
{
}

static void mdl_setup_runtime_resources_c2_Simulation
  (SFc2_SimulationInstanceStruct *chartInstance)
{
  static const uint32_T c2_decisionTxtEndIdx{ 0U };

  static const uint32_T c2_decisionTxtStartIdx{ 0U };

  sfSetAnimationVectors(chartInstance->S, chartInstance->c2_JITStateAnimation,
                        chartInstance->c2_JITTransitionAnimation);
  setDataBrowseFcn(chartInstance->S, (void *)&c2_chart_data_browse_helper);
  chartInstance->c2_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c2_RuntimeVar,
    &chartInstance->c2_IsDebuggerActive,
    &chartInstance->c2_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c2_mlFcnLineNumber, &chartInstance->c2_IsHeatMapPresent, 0);
  covrtCreateStateflowInstanceData(chartInstance->c2_covrtInstance, 1U, 0U, 1U,
    16U);
  covrtChartInitFcn(chartInstance->c2_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c2_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c2_decisionTxtStartIdx, &c2_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c2_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance, "", 4U, 0U, 1U, 0U, 2U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 630);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 465, 476, -1,
                    626, false);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 1U, 527, 550, -1,
                    618, false);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 530,
    550, -1, 2U);
}

static void mdl_cleanup_runtime_resources_c2_Simulation
  (SFc2_SimulationInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c2_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c2_covrtInstance);
}

static void enable_c2_Simulation(SFc2_SimulationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_Simulation(SFc2_SimulationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance)
{
  real_T c2_b_newWaypoints[12];
  real_T c2_b_waypoints[12];
  real_T c2_b_pos[2];
  real_T c2_b_vel[2];
  real_T c2_wp1[2];
  real_T c2_x_data[2];
  real_T c2_absxk;
  real_T c2_b;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_d_k;
  real_T c2_d_y;
  real_T c2_distance;
  real_T c2_e_y;
  real_T c2_perimeter;
  real_T c2_scale;
  real_T c2_t;
  real_T c2_varargin_2;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_k;
  boolean_T c2_exitg1;
  boolean_T c2_f_y;
  for (c2_i = 0; c2_i < 12; c2_i++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 2U,
                      (*chartInstance->c2_waypoints)[c2_i]);
  }

  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 1U,
                      (*chartInstance->c2_vel)[c2_i1]);
  }

  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U,
                      (*chartInstance->c2_pos)[c2_i2]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_JITTransitionAnimation[0] = 0U;
  chartInstance->c2_sfEvent = CALL_EVENT;
  for (c2_i3 = 0; c2_i3 < 12; c2_i3++) {
    c2_b_waypoints[c2_i3] = (*chartInstance->c2_waypoints)[c2_i3];
  }

  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
    c2_b_pos[c2_i4] = (*chartInstance->c2_pos)[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
    c2_b_vel[c2_i5] = (*chartInstance->c2_vel)[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 12; c2_i6++) {
    c2_b_newWaypoints[c2_i6] = 0.0;
  }

  c2_i7 = 0;
  for (c2_i8 = 0; c2_i8 < 2; c2_i8++) {
    c2_wp1[c2_i8] = c2_b_waypoints[c2_i7];
    c2_i7 += 6;
  }

  for (c2_i9 = 0; c2_i9 < 2; c2_i9++) {
    c2_b_pos[c2_i9] = c2_wp1[c2_i9] - c2_b_pos[c2_i9];
  }

  c2_distance = 0.0;
  c2_scale = 3.3121686421112381E-170;
  for (c2_k = 0; c2_k < 2; c2_k++) {
    c2_b_k = c2_k;
    c2_x = c2_b_pos[c2_b_k];
    c2_b_x = c2_x;
    c2_c_x = c2_b_x;
    c2_absxk = muDoubleScalarAbs(c2_c_x);
    if (c2_absxk > c2_scale) {
      c2_t = c2_scale / c2_absxk;
      c2_distance = 1.0 + c2_distance * c2_t * c2_t;
      c2_scale = c2_absxk;
    } else {
      c2_t = c2_absxk / c2_scale;
      c2_distance += c2_t * c2_t;
    }
  }

  c2_distance = c2_scale * muDoubleScalarSqrt(c2_distance);
  c2_varargin_2 = c2_b_vel[0];
  c2_y = c2_varargin_2;
  c2_b_y = c2_y;
  c2_c_y = c2_b_y;
  c2_b = c2_c_y;
  c2_d_y = c2_b;
  c2_e_y = c2_d_y;
  c2_perimeter = muDoubleScalarMax(3.0, c2_e_y);
  for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
    c2_x_data[c2_i10] = c2_wp1[c2_i10];
  }

  c2_f_y = true;
  c2_c_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_c_k < 2)) {
    c2_d_k = static_cast<real_T>(c2_c_k) + 1.0;
    if (c2_x_data[static_cast<int32_T>(c2_d_k) - 1] == 0.0) {
      c2_f_y = false;
      c2_exitg1 = true;
    } else {
      c2_c_k++;
    }
  }

  if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 0, c2_f_y) &&
      covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 1,
                     covrtRelationalopUpdateFcn(chartInstance->c2_covrtInstance,
        4U, 0U, 0U, c2_distance, c2_perimeter, -1, 2U, static_cast<int32_T>
        (c2_distance < c2_perimeter)))) {
    c2_i11 = 0;
    for (c2_i13 = 0; c2_i13 < 2; c2_i13++) {
      for (c2_i14 = 0; c2_i14 < 5; c2_i14++) {
        c2_b_newWaypoints[c2_i14 + c2_i11] = c2_b_waypoints[(c2_i14 + c2_i11) +
          1];
      }

      c2_i11 += 6;
    }
  }

  for (c2_i12 = 0; c2_i12 < 12; c2_i12++) {
    (*chartInstance->c2_newWaypoints)[c2_i12] = c2_b_newWaypoints[c2_i12];
  }

  c2_do_animation_call_c2_Simulation(chartInstance);
  for (c2_i15 = 0; c2_i15 < 12; c2_i15++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 3U,
                      (*chartInstance->c2_newWaypoints)[c2_i15]);
  }
}

static void ext_mode_exec_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance)
{
}

static void c2_update_jit_animation_c2_Simulation(SFc2_SimulationInstanceStruct *
  chartInstance)
{
}

static void c2_do_animation_call_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c2_Simulation(SFc2_SimulationInstanceStruct *
  chartInstance)
{
  const mxArray *c2_b_y{ nullptr };

  const mxArray *c2_c_y{ nullptr };

  const mxArray *c2_st;
  const mxArray *c2_y{ nullptr };

  c2_st = nullptr;
  c2_st = nullptr;
  c2_y = nullptr;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(2, 1), false);
  c2_b_y = nullptr;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", *chartInstance->c2_newWaypoints, 0,
    0U, 1U, 0U, 2, 6, 2), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_c_y = nullptr;
  sf_mex_assign(&c2_c_y, sf_mex_create("y",
    &chartInstance->c2_is_active_c2_Simulation, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv[12];
  int32_T c2_i;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "newWaypoints", c2_dv);
  for (c2_i = 0; c2_i < 12; c2_i++) {
    (*chartInstance->c2_newWaypoints)[c2_i] = c2_dv[c2_i];
  }

  chartInstance->c2_is_active_c2_Simulation = c2_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_Simulation");
  sf_mex_destroy(&c2_u);
  sf_mex_destroy(&c2_st);
}

static void initSimStructsc2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance)
{
}

static void initSubchartIOPointersc2_Simulation(SFc2_SimulationInstanceStruct
  *chartInstance)
{
}

const mxArray *sf_c2_Simulation_get_eml_resolved_functions_info()
{
  const mxArray *c2_nameCaptureInfo{ nullptr };

  c2_nameCaptureInfo = nullptr;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", nullptr, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_emlrt_marshallIn(SFc2_SimulationInstanceStruct *chartInstance,
  const mxArray *c2_nullptr, const char_T *c2_identifier, real_T c2_y[12])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = const_cast<const char_T *>(c2_identifier);
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_nullptr);
}

static void c2_b_emlrt_marshallIn(SFc2_SimulationInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[12])
{
  real_T c2_dv[12];
  int32_T c2_i;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv, 1, 0, 0U, 1, 0U, 2, 6, 2);
  for (c2_i = 0; c2_i < 12; c2_i++) {
    c2_y[c2_i] = c2_dv[c2_i];
  }

  sf_mex_destroy(&c2_u);
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_SimulationInstanceStruct
  *chartInstance, const mxArray *c2_nullptr, const char_T *c2_identifier)
{
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  c2_thisId.fIdentifier = const_cast<const char_T *>(c2_identifier);
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr), &c2_thisId);
  sf_mex_destroy(&c2_nullptr);
  return c2_y;
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_SimulationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_b_u;
  uint8_T c2_y;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b_u, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_b_u;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_slStringInitializeDynamicBuffers(SFc2_SimulationInstanceStruct
  *chartInstance)
{
}

static void c2_chart_data_browse_helper(SFc2_SimulationInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig)
{
  *c2_mxData = nullptr;
  *c2_mxData = nullptr;
  *c2_isValueTooBig = 0U;
  switch (c2_ssIdNumber) {
   case 4U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_pos, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 5U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData",
      *chartInstance->c2_newWaypoints, 0, 0U, 1U, 0U, 2, 6, 2), false);
    break;

   case 6U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", *chartInstance->c2_vel, 0,
      0U, 1U, 0U, 2, 1, 3), false);
    break;

   case 7U:
    sf_mex_assign(c2_mxData, sf_mex_create("mxData",
      *chartInstance->c2_waypoints, 0, 0U, 1U, 0U, 2, 6, 2), false);
    break;
  }
}

static void init_dsm_address_info(SFc2_SimulationInstanceStruct *chartInstance)
{
}

static void init_simulink_io_address(SFc2_SimulationInstanceStruct
  *chartInstance)
{
  chartInstance->c2_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_pos = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_newWaypoints = (real_T (*)[12])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_vel = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_waypoints = (real_T (*)[12])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c2_Simulation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(74983613U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2328720456U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2813647174U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2767153276U);
}

mxArray *sf_c2_Simulation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_Simulation_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_vars");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("x");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_Simulation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_Simulation(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPhDBxMDABqQ4IEwwYIXyGaFijHBxFri4AhCXVBakgsSLi5I9U4B0XmIumJ9YWuG"
    "Zl5YPNt+CAWE+GxbzGZHM54SKQ8AHe8r0iziA9Dsg6WfBop8HSb8AlJ+XWh6eWFmQn5lXUgwPJy"
    "hNvnsUHCjTD7Hfg4B/xNH8A+JnFscnJpdklqXGJxvFB2fmluYklmTm58H9BQCuaxyr"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Simulation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "s2pkFr2AADZonuySiHiY1ME";
}

static void sf_opaque_initialize_c2_Simulation(void *chartInstanceVar)
{
  initialize_params_c2_Simulation((SFc2_SimulationInstanceStruct*)
    chartInstanceVar);
  initialize_c2_Simulation((SFc2_SimulationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_Simulation(void *chartInstanceVar)
{
  enable_c2_Simulation((SFc2_SimulationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_Simulation(void *chartInstanceVar)
{
  disable_c2_Simulation((SFc2_SimulationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_Simulation(void *chartInstanceVar)
{
  sf_gateway_c2_Simulation((SFc2_SimulationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_Simulation(SimStruct* S)
{
  return get_sim_state_c2_Simulation((SFc2_SimulationInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_Simulation(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c2_Simulation((SFc2_SimulationInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c2_Simulation(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_SimulationInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Simulation_optimization_info();
    }

    mdl_cleanup_runtime_resources_c2_Simulation((SFc2_SimulationInstanceStruct*)
      chartInstanceVar);
    ((SFc2_SimulationInstanceStruct*) chartInstanceVar)->
      ~SFc2_SimulationInstanceStruct();
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c2_Simulation(void *chartInstanceVar)
{
  mdl_start_c2_Simulation((SFc2_SimulationInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc2_SimulationInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c2_Simulation(void *chartInstanceVar)
{
  mdl_terminate_c2_Simulation((SFc2_SimulationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Simulation(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Simulation((SFc2_SimulationInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc2_Simulation((SFc2_SimulationInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c2_Simulation_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWE+P20QUn6TLiqLtqgekcqjUPXJBaoMqcUCwaf60kTbsCiet6GU1a7/Eo4xn3PmTbLiAhPg",
    "4SBw48BE48AH4GByRuPDGcdLUGzYep4i2lryzY/s3773fvH8TUuv1CV6HeN//iJB9HN/Hu04W13",
    "v5vLZ2L57vkc/z+W8fEBLKCMYgAjsasUvidwmbnFFFE038L0ET+Bq05NYwKXpiJMtjmRiBAhHiA",
    "qlUxkuuZonlTEy6VoROsn4WszAOYml59AgXpNGp4PN/k5tac4YS20xBaLoAkYmVtOO4y+n4ehaU",
    "mbViCCfaJt5caTCBTZ2pum+5YSmHziWEPaENRRb0FnsDQw20zKUfyc5eHSzRMkk5o6I81zHVAaT",
    "oHQaGaYR/T61B9krKRXkXTFAjFaO8k/BWTFVZ7BlHPfvo1tybZ5OYNlzY8ZiJsWNX2QQE2o9+Uo",
    "KrUUtOQdExnAo/uaGzrnOZbfDKL0tiDUvgKVXNEP1AQ+QXg+jAOqC4tTDAZbywIOgFh54eKDbFP",
    "fLNGz0XSpXyhk0WnqQrYTO5nSnuqq4otxuKFuVc+2EHMj2BKfBMfpsaWgG7kO8B1ppFA4ne4SLX",
    "M/qtYC8s5NiWFBEr75XTAiorEl9hwi8BZ4kLA4iQ5pXqq4W2xZHVRiYtDP32yUlJeVexPWFAjWg",
    "IpfO1okwDKpz5lafciGkXSIhGlkxmZekVFjFYCUr0yIr2TKoJcuxbGF5y5SLBDw3RGNpgIEtyHf",
    "Tup5TbkjonGrOyc4+hxizrJxexLn4qgUMaxhC5Gsg49DHP4gJlt1i78tlEa6fMzNugQ8XSspFkM",
    "aFj8XMsDeYpDMVEyJnoKpkEeRdzjV8BYNagSmApe4SlVM27qHw5rRW8GGTZ3bdhcDxTw+mF843H",
    "ILAaOltd9aYhRlVHYLuJCu2CDdi32I4IzbTBFnDeyWIgyvrgY/KyD97b0AffWuuDb+fzsHGekbk",
    "s8lk/vbbOQYl+mpTAkSs4ssItx4/X8LUNcsnaWJR3s/7q9zcK8ur4pFarXeHpVkHOXgG3n3N19H",
    "BIvvtp+PfjH389+f2H73/ZJr92RX4t+9/hfq77nVcO8/ndZa+0yszTK8nLfftkix/cKfiBm+tGO",
    "umqRrPZfi6FnQfsCfvmQb+z2J8t+tYL+i6fH7n+DAM3ywMq7EX5ucfNqV304279z9b03d/Cx801",
    "fyLkzy93w394XCZuDgp8HWS94+wZnaeS5Z3Uuh9X1+foeDd89f1n+py6LA3nr2aEw5Lxdp2/++L",
    "eFnnvup6v074ydeRGRVztP6xbrxO3q32+9fFt//7+NXmMFL6//QbbURyr9klvml1/EL8+5l4+/2",
    "J1Nm/FjEcbTgf5a2zgR5veviP+/Zcnf8u63XH85T+IPv+0KSif43FgcdzKH58p91vc6pUCqjefu",
    "f6PerIcq/RdMyYiOdOfPGg8bOxSn/4B8vQIYA==",
    ""
  };

  static char newstr [1465] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c2_Simulation(SimStruct *S)
{
  const char* newstr = sf_c2_Simulation_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(5584160U));
  ssSetChecksum1(S,(4216696191U));
  ssSetChecksum2(S,(1287161159U));
  ssSetChecksum3(S,(3028321228U));
}

static void mdlRTW_c2_Simulation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c2_Simulation(SimStruct *S)
{
  SFc2_SimulationInstanceStruct *chartInstance;
  chartInstance = (SFc2_SimulationInstanceStruct *)utMalloc(sizeof
    (SFc2_SimulationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_SimulationInstanceStruct));
  chartInstance = new (chartInstance) SFc2_SimulationInstanceStruct;
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_Simulation;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_Simulation;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c2_Simulation;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c2_Simulation;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c2_Simulation;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_Simulation;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_Simulation;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_Simulation;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_Simulation;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_Simulation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Simulation;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_Simulation;
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

  mdl_setup_runtime_resources_c2_Simulation(chartInstance);
}

void c2_Simulation_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c2_Simulation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Simulation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Simulation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Simulation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
