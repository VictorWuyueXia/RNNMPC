/* Include files */

#include "autolibshared_sfun.h"
#include "c3_autolibshared.h"
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
const real_T c3_const_trackMode = 1.0;
const real_T c3_const_inputMode = 2.0;
const int32_T CALL_EVENT = -1;
const real_T c3_b_trackMode = 1.0;
const real_T c3_b_inputMode = 2.0;

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c3_emlrtMCI = { 82, /* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtMCInfo c3_b_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtRSInfo c3_emlrtRSI = { 71, /* lineNo */
  "power",                             /* fcnName */
  "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo c3_b_emlrtRSI = { 1,/* lineNo */
  "automlvehdynbicycle",               /* fcnName */
  "/Applications/MATLAB_R2023b.app/toolbox/autoblks/autoblksshared/automlvehdynbicycle.p"/* pathName */
};

static emlrtRSInfo c3_c_emlrtRSI = { 1,/* lineNo */
  "automldiv0protect",                 /* fcnName */
  "/Applications/MATLAB_R2023b.app/toolbox/autoblks/autoblksshared/automldiv0protect.p"/* pathName */
};

static emlrtRSInfo c3_d_emlrtRSI = { 1,/* lineNo */
  "automlvehdynftiresat",              /* fcnName */
  "/Applications/MATLAB_R2023b.app/toolbox/autoblks/autoblksshared/automlvehdynftiresat.p"/* pathName */
};

static emlrtRSInfo c3_e_emlrtRSI = { 5,/* lineNo */
  "Vehicle Body 3DOF Single Track/vehicle model",/* fcnName */
  "#autolibshared:1021:643"            /* pathName */
};

static emlrtRTEInfo c3_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "automldiv0protect",                 /* fName */
  "/Applications/MATLAB_R2023b.app/toolbox/autoblks/autoblksshared/automldiv0protect.p"/* pName */
};

static emlrtRTEInfo c3_b_emlrtRTEI = { 71,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo c3_c_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "automlvehdynftiresat",              /* fName */
  "/Applications/MATLAB_R2023b.app/toolbox/autoblks/autoblksshared/automlvehdynftiresat.p"/* pName */
};

static emlrtRTEInfo c3_d_emlrtRTEI = { 364,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_e_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c3_f_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "automlsatfunc",                     /* fName */
  "/Applications/MATLAB_R2023b.app/toolbox/autoblks/autoblksshared/automlsatfunc.p"/* pName */
};

static emlrtECInfo c3_emlrtECI = { -1, /* nDims */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "automldiv0protect",                 /* fName */
  "/Applications/MATLAB_R2023b.app/toolbox/autoblks/autoblksshared/automldiv0protect.p"/* pName */
};

static emlrtECInfo c3_b_emlrtECI = { -1,/* nDims */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "automlvehdynftiresat",              /* fName */
  "/Applications/MATLAB_R2023b.app/toolbox/autoblks/autoblksshared/automlvehdynftiresat.p"/* pName */
};

static char_T c3_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n', 'E',
  'r', 'r', 'o', 'r' };

/* Function Declarations */
static void initialize_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance);
static void initialize_params_c3_autolibshared(SFc3_autolibsharedInstanceStruct *
  chartInstance);
static void mdl_start_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance);
static void mdl_terminate_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance);
static void enable_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance);
static void disable_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance);
static void sf_gateway_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance);
static void ext_mode_exec_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance);
static void c3_update_jit_animation_c3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance);
static void c3_do_animation_call_c3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance);
static void set_sim_state_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void initSimStructsc3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance);
static void initSubchartIOPointersc3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance);
static real_T c3_function_handle_parenReference(SFc3_autolibsharedInstanceStruct
  *chartInstance, real_T c3_varargin_1);
static void c3_automlsatfunc(SFc3_autolibsharedInstanceStruct *chartInstance,
  real_T c3_u[2], real_T c3_y_sat[2]);
static void c3_automlvehdynftiresat(SFc3_autolibsharedInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_Ftire_x, real_T c3_Ftire_y,
  real_T c3_b_Fxtire_sat, real_T c3_b_Fytire_sat, real_T *c3_Ftire_xs, real_T
  *c3_Ftire_ys);
static void c3_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct *chartInstance,
  const mxArray *c3_nullptr, const char_T *c3_identifier, real_T c3_y[3]);
static void c3_b_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3]);
static void c3_c_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_nullptr, const char_T *c3_identifier, real_T
  c3_y[6]);
static void c3_d_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[6]);
static void c3_e_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_nullptr, const char_T *c3_identifier, real_T
  c3_y[4]);
static void c3_f_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4]);
static real_T c3_g_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_nullptr, const char_T *c3_identifier);
static real_T c3_h_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint8_T c3_i_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_nullptr, const char_T *c3_identifier);
static uint8_T c3_j_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_slStringInitializeDynamicBuffers(SFc3_autolibsharedInstanceStruct
  *chartInstance);
static void c3_chart_data_browse_helper(SFc3_autolibsharedInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig);
static void c3_b_automlsatfunc(SFc3_autolibsharedInstanceStruct *chartInstance,
  real_T c3_u[2]);
static void init_dsm_address_info(SFc3_autolibsharedInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_autolibsharedInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance)
{
  sf_is_first_init_cond(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c3_doneDoubleBufferReInit = false;
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c3_autolibshared(SFc3_autolibsharedInstanceStruct *
  chartInstance)
{
  real_T c3_dv[2];
  real_T c3_b_d;
  real_T c3_d1;
  real_T c3_d10;
  real_T c3_d11;
  real_T c3_d12;
  real_T c3_d13;
  real_T c3_d14;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  real_T c3_d7;
  real_T c3_d8;
  real_T c3_d9;
  int32_T c3_i;
  sf_mex_import_named("a", sf_mex_get_sfun_param(chartInstance->S, 6U, 0U),
                      &c3_b_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_a = c3_b_d;
  sf_mex_import_named("b", sf_mex_get_sfun_param(chartInstance->S, 7U, 0U),
                      &c3_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_b = c3_d1;
  sf_mex_import_named("h", sf_mex_get_sfun_param(chartInstance->S, 10U, 0U),
                      &c3_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_h = c3_d2;
  sf_mex_import_named("d", sf_mex_get_sfun_param(chartInstance->S, 8U, 0U),
                      &c3_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_d = c3_d3;
  sf_mex_import_named("w", sf_mex_get_sfun_param(chartInstance->S, 14U, 0U),
                      c3_dv, 0, 0, 0U, 1, 0U, 2, 1, 2);
  for (c3_i = 0; c3_i < 2; c3_i++) {
    chartInstance->c3_w[c3_i] = c3_dv[c3_i];
  }

  sf_mex_import_named("m", sf_mex_get_sfun_param(chartInstance->S, 12U, 0U),
                      &c3_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_m = c3_d4;
  sf_mex_import_named("NF", sf_mex_get_sfun_param(chartInstance->S, 4U, 0U),
                      &c3_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_NF = c3_d5;
  sf_mex_import_named("NR", sf_mex_get_sfun_param(chartInstance->S, 5U, 0U),
                      &c3_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_NR = c3_d6;
  sf_mex_import_named("Izz", sf_mex_get_sfun_param(chartInstance->S, 3U, 0U),
                      &c3_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Izz = c3_d7;
  sf_mex_import_named("g", sf_mex_get_sfun_param(chartInstance->S, 9U, 0U),
                      &c3_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_g = c3_d8;
  sf_mex_import_named("Fxtire_sat", sf_mex_get_sfun_param(chartInstance->S, 0U,
    0U), &c3_d9, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Fxtire_sat = c3_d9;
  sf_mex_import_named("Fytire_sat", sf_mex_get_sfun_param(chartInstance->S, 1U,
    0U), &c3_d10, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Fytire_sat = c3_d10;
  sf_mex_import_named("trackMode", sf_mex_get_sfun_param(chartInstance->S, 13U,
    0U), &c3_d11, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_trackMode = c3_d11;
  sf_mex_import_named("inputMode", sf_mex_get_sfun_param(chartInstance->S, 11U,
    0U), &c3_d12, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_inputMode = c3_d12;
  sf_mex_import_named("xdot_tol", sf_mex_get_sfun_param(chartInstance->S, 15U,
    0U), &c3_d13, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_xdot_tol = c3_d13;
  sf_mex_import_named("Fznom", sf_mex_get_sfun_param(chartInstance->S, 2U, 0U),
                      &c3_d14, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Fznom = c3_d14;
}

static void mdl_start_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance)
{
}

static void mdl_setup_runtime_resources_c3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance)
{
  static const int32_T c3_condTxtEndIdx[3] = { 8, 291, 529 };

  static const int32_T c3_condTxtStartIdx[3] = { -1, 285, 523 };

  static const uint32_T c3_decisionTxtEndIdx = 0U;
  static const uint32_T c3_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, chartInstance->c3_JITStateAnimation,
                        chartInstance->c3_JITTransitionAnimation);
  setDataBrowseFcn(chartInstance->S, (void *)&c3_chart_data_browse_helper);
  chartInstance->c3_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c3_RuntimeVar,
    &chartInstance->c3_IsDebuggerActive,
    &chartInstance->c3_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c3_mlFcnLineNumber, &chartInstance->c3_IsHeatMapPresent, 0);
  covrtCreateStateflowInstanceData(chartInstance->c3_covrtInstance, 1U, 0U, 1U,
    536U);
  covrtChartInitFcn(chartInstance->c3_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c3_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c3_decisionTxtStartIdx, &c3_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c3_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c3_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 1U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 773);
  covrtEmlSwitchInitFcn(chartInstance->c3_covrtInstance, 4U, 0U, 0U, 264, 280,
                        769, 3U, c3_condTxtStartIdx, c3_condTxtEndIdx);
}

static void mdl_cleanup_runtime_resources_c3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c3_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c3_covrtInstance);
}

static void enable_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance)
{
  static char_T c3_cv2[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  static char_T c3_b_cv[4] = { 's', 'q', 'r', 't' };

  static char_T c3_cv1[4] = { 's', 'q', 'r', 't' };

  emlrtStack c3_b_st;
  emlrtStack c3_c_st;
  emlrtStack c3_d_st;
  emlrtStack c3_e_st;
  emlrtStack c3_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_i_y = NULL;
  const mxArray *c3_j_y = NULL;
  const mxArray *c3_k_y = NULL;
  const mxArray *c3_m_y = NULL;
  real_T c3_Fz[2];
  real_T c3_FzCalc[2];
  real_T c3_Fzinit[2];
  real_T c3_varargin_1[2];
  real_T c3_dv[1];
  real_T c3_y_data[1];
  real_T c3_B2;
  real_T c3_Fx_f;
  real_T c3_Fx_ft;
  real_T c3_Fx_r;
  real_T c3_Fx_rt;
  real_T c3_Fy_f;
  real_T c3_Fy_ft;
  real_T c3_Fy_r;
  real_T c3_Fy_rt;
  real_T c3_Fz_f;
  real_T c3_Fz_r;
  real_T c3_Vwheel_f;
  real_T c3_Vwheel_r;
  real_T c3_ab_x;
  real_T c3_alfa_f;
  real_T c3_alfa_r;
  real_T c3_b_B1;
  real_T c3_b_B2;
  real_T c3_b_Cy_f;
  real_T c3_b_Cy_r;
  real_T c3_b_Fx_ft;
  real_T c3_b_Fx_rt;
  real_T c3_b_Fxtire_sat;
  real_T c3_b_Fy_ft;
  real_T c3_b_Fy_rt;
  real_T c3_b_Fytire_sat;
  real_T c3_b_Fznom;
  real_T c3_b_Izz;
  real_T c3_b_NF;
  real_T c3_b_NR;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_b_d;
  real_T c3_b_delta_f;
  real_T c3_b_delta_r;
  real_T c3_b_dh;
  real_T c3_b_g;
  real_T c3_b_h;
  real_T c3_b_hh;
  real_T c3_b_iterCnt;
  real_T c3_b_m;
  real_T c3_b_r;
  real_T c3_b_status;
  real_T c3_b_x;
  real_T c3_b_xddot;
  real_T c3_b_xdot_tol;
  real_T c3_b_y;
  real_T c3_b_ydot;
  real_T c3_bb_x;
  real_T c3_c_B1;
  real_T c3_c_Cy_f;
  real_T c3_c_Cy_r;
  real_T c3_c_Fxtire_sat;
  real_T c3_c_Fytire_sat;
  real_T c3_c_Fznom;
  real_T c3_c_Izz;
  real_T c3_c_Nf;
  real_T c3_c_Nr;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_c_delta_f;
  real_T c3_c_delta_r;
  real_T c3_c_dh;
  real_T c3_c_g;
  real_T c3_c_h;
  real_T c3_c_hh;
  real_T c3_c_m;
  real_T c3_c_r;
  real_T c3_c_x;
  real_T c3_c_xdot_tol;
  real_T c3_cb_x;
  real_T c3_d_a;
  real_T c3_d_dh;
  real_T c3_d_g;
  real_T c3_d_hh;
  real_T c3_d_m;
  real_T c3_d_r;
  real_T c3_d_x;
  real_T c3_db_x;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_e_dh;
  real_T c3_e_g;
  real_T c3_e_h;
  real_T c3_e_hh;
  real_T c3_e_m;
  real_T c3_e_r;
  real_T c3_e_x;
  real_T c3_eb_x;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_f_x;
  real_T c3_f_y;
  real_T c3_fb_x;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_g_h;
  real_T c3_g_x;
  real_T c3_g_y;
  real_T c3_gb_x;
  real_T c3_h_a;
  real_T c3_h_b;
  real_T c3_h_x;
  real_T c3_hb_x;
  real_T c3_i_a;
  real_T c3_i_x;
  real_T c3_ib_x;
  real_T c3_j_a;
  real_T c3_j_x;
  real_T c3_jb_x;
  real_T c3_k_a;
  real_T c3_k_x;
  real_T c3_kb_x;
  real_T c3_m_a;
  real_T c3_m_x;
  real_T c3_maxFerr;
  real_T c3_mb_x;
  real_T c3_o_a;
  real_T c3_o_x;
  real_T c3_o_y;
  real_T c3_ob_x;
  real_T c3_p_a;
  real_T c3_p_x;
  real_T c3_p_y;
  real_T c3_q_a;
  real_T c3_q_x;
  real_T c3_q_y;
  real_T c3_r;
  real_T c3_r_a;
  real_T c3_r_x;
  real_T c3_r_y;
  real_T c3_rdot;
  real_T c3_s_a;
  real_T c3_s_x;
  real_T c3_s_y;
  real_T c3_t_a;
  real_T c3_t_x;
  real_T c3_tol;
  real_T c3_u;
  real_T c3_u_a;
  real_T c3_u_x;
  real_T c3_v_a;
  real_T c3_v_x;
  real_T c3_w_a;
  real_T c3_w_x;
  real_T c3_x;
  real_T c3_x_a;
  real_T c3_x_x;
  real_T c3_xddot;
  real_T c3_xdot;
  real_T c3_xdot_pabs;
  real_T c3_y;
  real_T c3_y_a;
  real_T c3_y_x;
  real_T c3_yddot;
  real_T c3_ydot;
  int32_T c3_iv[2];
  int32_T c3_iv1[2];
  int32_T c3_iv2[2];
  int32_T c3_iv3[2];
  int32_T c3_iv4[2];
  int32_T c3_tmp_size[2];
  int32_T c3_y_size[2];
  int32_T c3_tmp_data[1];
  int32_T c3_b_end;
  int32_T c3_b_i;
  int32_T c3_b_k;
  int32_T c3_b_loop_ub;
  int32_T c3_b_trueCount;
  int32_T c3_c_end;
  int32_T c3_c_i;
  int32_T c3_c_loop_ub;
  int32_T c3_c_trueCount;
  int32_T c3_d_end;
  int32_T c3_d_i22;
  int32_T c3_d_loop_ub;
  int32_T c3_d_trueCount;
  int32_T c3_e_end;
  int32_T c3_e_i;
  int32_T c3_e_loop_ub;
  int32_T c3_e_trueCount;
  int32_T c3_end;
  int32_T c3_f_i;
  int32_T c3_g_i;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i2;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i3;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_iterCnt;
  int32_T c3_j_i;
  int32_T c3_k;
  int32_T c3_loop_ub;
  int32_T c3_trueCount;
  boolean_T c3_b_p;
  boolean_T c3_c_p;
  boolean_T c3_d_p;
  boolean_T c3_e_p;
  boolean_T c3_j_b;
  boolean_T c3_k_b;
  boolean_T c3_p;
  c3_st.tls = chartInstance->c3_fEmlrtCtx;
  c3_b_st.prev = &c3_st;
  c3_b_st.tls = c3_st.tls;
  c3_c_st.prev = &c3_b_st;
  c3_c_st.tls = c3_b_st.tls;
  c3_d_st.prev = &c3_c_st;
  c3_d_st.tls = c3_c_st.tls;
  c3_e_st.prev = &c3_d_st;
  c3_e_st.tls = c3_d_st.tls;
  for (c3_i = 0; c3_i < 4; c3_i++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 14U,
                      (*chartInstance->c3_stateVec)[c3_i]);
  }

  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 13U, *chartInstance->c3_hh);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 12U, *chartInstance->c3_hl);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 11U, *chartInstance->c3_dh);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 10U,
                    *chartInstance->c3_Cy_r);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 9U, *chartInstance->c3_Cy_f);
  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 8U,
                      (*chartInstance->c3_Mh)[c3_i1]);
  }

  for (c3_i2 = 0; c3_i2 < 3; c3_i2++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 7U,
                      (*chartInstance->c3_Fh)[c3_i2]);
  }

  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 6U,
                      (*chartInstance->c3_M_ext)[c3_i3]);
  }

  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 5U,
                      (*chartInstance->c3_F_ext)[c3_i4]);
  }

  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 4U,
                      (*chartInstance->c3_F_r)[c3_i5]);
  }

  for (c3_i6 = 0; c3_i6 < 2; c3_i6++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 3U,
                      (*chartInstance->c3_F_f)[c3_i6]);
  }

  for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 2U,
                      (*chartInstance->c3_mu)[c3_i7]);
  }

  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 1U,
                    *chartInstance->c3_delta_r);
  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 0U,
                    *chartInstance->c3_delta_f);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_JITTransitionAnimation[0] = 0U;
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_b_delta_f = *chartInstance->c3_delta_f;
  c3_b_delta_r = *chartInstance->c3_delta_r;
  c3_b_a = chartInstance->c3_a;
  c3_b_b = chartInstance->c3_b;
  c3_b_h = chartInstance->c3_h;
  c3_b_m = chartInstance->c3_m;
  c3_b_NF = chartInstance->c3_NF;
  c3_b_NR = chartInstance->c3_NR;
  c3_b_Izz = chartInstance->c3_Izz;
  c3_b_g = chartInstance->c3_g;
  c3_b_Fxtire_sat = chartInstance->c3_Fxtire_sat;
  c3_b_Fytire_sat = chartInstance->c3_Fytire_sat;
  c3_b_xdot_tol = chartInstance->c3_xdot_tol;
  c3_b_Fznom = chartInstance->c3_Fznom;
  c3_b_Cy_f = *chartInstance->c3_Cy_f;
  c3_b_Cy_r = *chartInstance->c3_Cy_r;
  c3_b_dh = *chartInstance->c3_dh;
  c3_b_hh = *chartInstance->c3_hh;
  covrtEmlFcnEval(chartInstance->c3_covrtInstance, 4U, 0, 0);
  covrtEmlSwitchEval(chartInstance->c3_covrtInstance, 4U, 0, 0, 1);
  c3_b_st.site = &c3_e_emlrtRSI;
  c3_c_delta_f = c3_b_delta_f;
  c3_c_delta_r = c3_b_delta_r;
  c3_c_a = c3_b_a;
  c3_c_b = c3_b_b;
  c3_c_h = c3_b_h;
  c3_c_m = c3_b_m;
  c3_c_Nf = c3_b_NF;
  c3_c_Nr = c3_b_NR;
  c3_c_Izz = c3_b_Izz;
  c3_c_g = c3_b_g;
  c3_c_Fxtire_sat = c3_b_Fxtire_sat;
  c3_c_Fytire_sat = c3_b_Fytire_sat;
  c3_c_xdot_tol = c3_b_xdot_tol;
  c3_c_Fznom = c3_b_Fznom;
  c3_c_Cy_f = c3_b_Cy_f;
  c3_c_Cy_r = c3_b_Cy_r;
  c3_c_dh = c3_b_dh;
  c3_c_hh = c3_b_hh;
  c3_xdot = (*chartInstance->c3_stateVec)[0];
  c3_ydot = (*chartInstance->c3_stateVec)[1];
  c3_r = (*chartInstance->c3_stateVec)[3];
  c3_c_st.site = &c3_b_emlrtRSI;
  c3_d_a = c3_ydot + c3_c_a * c3_r;
  c3_d_st.site = &c3_emlrtRSI;
  c3_e_a = c3_d_a;
  c3_f_a = c3_e_a;
  c3_g_a = c3_f_a;
  c3_y = c3_g_a * c3_g_a;
  c3_c_st.site = &c3_b_emlrtRSI;
  c3_h_a = c3_xdot;
  c3_d_st.site = &c3_emlrtRSI;
  c3_i_a = c3_h_a;
  c3_j_a = c3_i_a;
  c3_k_a = c3_j_a;
  c3_b_y = c3_k_a * c3_k_a;
  c3_c_st.site = &c3_b_emlrtRSI;
  c3_x = c3_y + c3_b_y;
  c3_Vwheel_f = c3_x;
  c3_b_x = c3_Vwheel_f;
  if (c3_b_x < 0.0) {
    c3_p = true;
  } else {
    c3_p = false;
  }

  c3_b_p = c3_p;
  if (c3_b_p) {
    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_d_y = NULL;
    sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_e_y = NULL;
    sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c3_c_st, &c3_b_emlrtMCI, "error", 0U, 2U, 14, c3_c_y, 14,
                sf_mex_call(&c3_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_c_st, NULL, "message", 1U, 2U, 14, c3_d_y, 14, c3_e_y)));
  }

  c3_Vwheel_f = muDoubleScalarSqrt(c3_Vwheel_f);
  c3_c_st.site = &c3_b_emlrtRSI;
  c3_m_a = c3_ydot - c3_c_b * c3_r;
  c3_d_st.site = &c3_emlrtRSI;
  c3_o_a = c3_m_a;
  c3_p_a = c3_o_a;
  c3_q_a = c3_p_a;
  c3_f_y = c3_q_a * c3_q_a;
  c3_c_st.site = &c3_b_emlrtRSI;
  c3_r_a = c3_xdot;
  c3_d_st.site = &c3_emlrtRSI;
  c3_s_a = c3_r_a;
  c3_t_a = c3_s_a;
  c3_u_a = c3_t_a;
  c3_g_y = c3_u_a * c3_u_a;
  c3_c_st.site = &c3_b_emlrtRSI;
  c3_c_x = c3_f_y + c3_g_y;
  c3_Vwheel_r = c3_c_x;
  c3_d_x = c3_Vwheel_r;
  if (c3_d_x < 0.0) {
    c3_c_p = true;
  } else {
    c3_c_p = false;
  }

  c3_d_p = c3_c_p;
  if (c3_d_p) {
    c3_h_y = NULL;
    sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_i_y = NULL;
    sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_j_y = NULL;
    sf_mex_assign(&c3_j_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c3_c_st, &c3_b_emlrtMCI, "error", 0U, 2U, 14, c3_h_y, 14,
                sf_mex_call(&c3_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_c_st, NULL, "message", 1U, 2U, 14, c3_i_y, 14, c3_j_y)));
  }

  c3_Vwheel_r = muDoubleScalarSqrt(c3_Vwheel_r);
  c3_c_st.site = &c3_b_emlrtRSI;
  c3_u = c3_xdot;
  c3_tol = c3_c_xdot_tol;
  c3_e_x = c3_u;
  c3_f_x = c3_e_x;
  c3_g_x = c3_f_x;
  c3_xdot_pabs = muDoubleScalarAbs(c3_g_x);
  c3_end = 1;
  c3_trueCount = 0;
  for (c3_b_i = 0; c3_b_i < c3_end; c3_b_i++) {
    if (c3_xdot_pabs < c3_tol) {
      c3_trueCount++;
    }
  }

  c3_tmp_size[1] = c3_trueCount;
  for (c3_c_i = 0; c3_c_i < c3_end; c3_c_i++) {
    if (c3_xdot_pabs < c3_tol) {
      c3_tmp_data[0] = c3_c_i;
    }
  }

  c3_h_x = 2.0 * c3_tol;
  c3_d_st.site = &c3_c_emlrtRSI;
  c3_b_end = 1;
  c3_b_trueCount = 0;
  for (c3_e_i = 0; c3_e_i < c3_b_end; c3_e_i++) {
    if (c3_xdot_pabs < c3_tol) {
      c3_b_trueCount++;
    }
  }

  c3_iv[1] = c3_b_trueCount;
  c3_y_size[1] = c3_iv[1];
  c3_c_end = 1;
  c3_c_trueCount = 0;
  for (c3_f_i = 0; c3_f_i < c3_c_end; c3_f_i++) {
    if (c3_xdot_pabs < c3_tol) {
      c3_c_trueCount++;
    }
  }

  c3_iv1[0] = 1;
  c3_iv2[1] = c3_c_trueCount;
  c3_loop_ub = c3_iv1[0] * c3_iv2[1] - 1;
  for (c3_i8 = 0; c3_i8 <= c3_loop_ub; c3_i8++) {
    c3_y_data[0] = c3_xdot_pabs / c3_tol;
  }

  c3_e_st.site = &c3_emlrtRSI;
  c3_e_p = false;
  if (c3_e_p) {
    c3_k_y = NULL;
    sf_mex_assign(&c3_k_y, sf_mex_create("y", c3_cv2, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c3_m_y = NULL;
    sf_mex_assign(&c3_m_y, sf_mex_create("y", c3_cv2, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c3_e_st, &c3_emlrtMCI, "error", 0U, 2U, 14, c3_k_y, 14,
                sf_mex_call(&c3_e_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_e_st, NULL, "message", 1U, 1U, 14, c3_m_y)));
  }

  c3_i9 = c3_y_size[1];
  c3_i10 = c3_i9;
  c3_b_loop_ub = c3_i10 - 1;
  for (c3_i11 = 0; c3_i11 <= c3_b_loop_ub; c3_i11++) {
    c3_y_data[0] = c3_function_handle_parenReference(chartInstance, c3_y_data[0]);
  }

  c3_i12 = c3_y_size[1];
  c3_i13 = c3_i12;
  c3_c_loop_ub = c3_i13 - 1;
  for (c3_i14 = 0; c3_i14 <= c3_c_loop_ub; c3_i14++) {
    c3_y_data[0] = 3.0 - c3_y_data[0];
  }

  c3_i_x = c3_h_x;
  c3_i15 = c3_y_size[1];
  c3_i16 = c3_i15;
  c3_d_loop_ub = c3_i16 - 1;
  for (c3_i17 = 0; c3_i17 <= c3_d_loop_ub; c3_i17++) {
    c3_y_data[0] = c3_i_x / c3_y_data[0];
  }

  if (c3_tmp_size[1] != c3_y_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_tmp_size[1], c3_y_size[1], &c3_emlrtECI,
      &c3_c_st);
  }

  c3_dv[0] = c3_xdot_pabs;
  c3_e_loop_ub = c3_y_size[1] - 1;
  for (c3_i18 = 0; c3_i18 <= c3_e_loop_ub; c3_i18++) {
    c3_dv[c3_tmp_data[0]] = c3_y_data[0];
  }

  c3_xdot_pabs = c3_dv[0];
  c3_d_end = 1;
  c3_d_trueCount = 0;
  for (c3_g_i = 0; c3_g_i < c3_d_end; c3_g_i++) {
    if (c3_u < 0.0) {
      c3_d_trueCount++;
    }
  }

  c3_iv3[1] = c3_d_trueCount;
  c3_y_size[1] = c3_iv3[1];
  c3_e_end = 1;
  c3_e_trueCount = 0;
  for (c3_j_i = 0; c3_j_i < c3_e_end; c3_j_i++) {
    if (c3_u < 0.0) {
      c3_e_trueCount++;
    }
  }

  c3_iv4[1] = c3_e_trueCount;
  if (c3_iv4[1] != c3_y_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_iv4[1], c3_y_size[1], &c3_emlrtECI,
      &c3_c_st);
  }

  c3_o_y = c3_ydot + c3_c_a * c3_r;
  c3_j_x = c3_xdot_pabs;
  c3_v_a = c3_o_y;
  c3_e_b = c3_j_x;
  c3_p_y = c3_v_a;
  c3_k_x = c3_e_b;
  c3_b_r = muDoubleScalarAtan2(c3_p_y, c3_k_x);
  c3_m_x = 4.0 * c3_xdot;
  c3_o_x = c3_m_x;
  c3_o_x = muDoubleScalarTanh(c3_o_x);
  c3_alfa_f = c3_b_r - c3_c_delta_f * c3_o_x;
  c3_q_y = c3_ydot - c3_c_b * c3_r;
  c3_p_x = c3_xdot_pabs;
  c3_w_a = c3_q_y;
  c3_f_b = c3_p_x;
  c3_r_y = c3_w_a;
  c3_q_x = c3_f_b;
  c3_c_r = muDoubleScalarAtan2(c3_r_y, c3_q_x);
  c3_r_x = 4.0 * c3_xdot;
  c3_s_x = c3_r_x;
  c3_s_x = muDoubleScalarTanh(c3_s_x);
  c3_alfa_r = c3_c_r - c3_c_delta_r * c3_s_x;
  for (c3_i19 = 0; c3_i19 < 2; c3_i19++) {
    c3_Fz[c3_i19] = 0.0;
  }

  for (c3_iterCnt = 0; c3_iterCnt < 6; c3_iterCnt++) {
    c3_b_iterCnt = static_cast<real_T>(c3_iterCnt);
    if (c3_b_iterCnt == 0.0) {
      c3_d_r = c3_r;
      c3_d_m = c3_c_m;
      c3_d_g = c3_c_g;
      c3_e_h = c3_c_h;
      c3_d_hh = c3_c_hh;
      c3_x_a = c3_c_a;
      c3_g_b = c3_c_b;
      c3_d_dh = c3_c_dh;
      c3_b_B1 = (((c3_e_h * ((((*chartInstance->c3_F_ext)[0] +
        (*chartInstance->c3_Fh)[0]) - c3_d_m * (0.0 - c3_d_r * 0.0)) - c3_d_m *
        c3_d_g * 0.0) - (*chartInstance->c3_Mh)[1]) - (*chartInstance->c3_Fh)[2]
                  * c3_d_dh) - (*chartInstance->c3_Fh)[0] * (c3_e_h - c3_d_hh))
        - (*chartInstance->c3_M_ext)[1];
      c3_B2 = (-(*chartInstance->c3_F_ext)[2] - (*chartInstance->c3_Fh)[2]) -
        c3_d_m * c3_d_g;
      c3_FzCalc[0] = -(c3_b_B1 - c3_B2 * c3_g_b) / (c3_x_a + c3_g_b);
      c3_FzCalc[1] = (c3_b_B1 + c3_B2 * c3_x_a) / (c3_x_a + c3_g_b);
      for (c3_i21 = 0; c3_i21 < 2; c3_i21++) {
        c3_FzCalc[c3_i21] = -c3_FzCalc[c3_i21];
      }

      for (c3_d_i22 = 0; c3_d_i22 < 2; c3_d_i22++) {
        c3_Fzinit[c3_d_i22] = c3_FzCalc[c3_d_i22];
      }

      c3_b_automlsatfunc(chartInstance, c3_Fzinit);
    } else {
      for (c3_i20 = 0; c3_i20 < 2; c3_i20++) {
        c3_Fzinit[c3_i20] = c3_Fz[c3_i20];
      }
    }

    c3_Fx_f = (*chartInstance->c3_F_f)[0];
    c3_Fy_f = -c3_c_Cy_f * c3_alfa_f * (*chartInstance->c3_mu)[0] * c3_Fzinit[0]
      / c3_c_Fznom;
    c3_Fx_r = (*chartInstance->c3_F_r)[0];
    c3_Fy_r = -c3_c_Cy_r * c3_alfa_r * (*chartInstance->c3_mu)[1] * c3_Fzinit[1]
      / c3_c_Fznom;
    c3_c_st.site = &c3_b_emlrtRSI;
    c3_automlvehdynftiresat(chartInstance, &c3_c_st, c3_Fx_f, c3_Fy_f,
      c3_c_Fxtire_sat * c3_Fzinit[0] / c3_c_Fznom, c3_c_Fytire_sat * c3_Fzinit[0]
      / c3_c_Fznom, &c3_Fx_ft, &c3_Fy_ft);
    c3_b_Fx_ft = c3_Fx_ft;
    c3_b_Fy_ft = c3_Fy_ft;
    c3_c_st.site = &c3_b_emlrtRSI;
    c3_automlvehdynftiresat(chartInstance, &c3_c_st, c3_Fx_r, c3_Fy_r,
      c3_c_Fxtire_sat * c3_Fzinit[1] / c3_c_Fznom, c3_c_Fytire_sat * c3_Fzinit[1]
      / c3_c_Fznom, &c3_Fx_rt, &c3_Fy_rt);
    c3_b_Fx_rt = c3_Fx_rt;
    c3_b_Fy_rt = c3_Fy_rt;
    c3_t_x = c3_c_delta_f;
    c3_u_x = c3_t_x;
    c3_u_x = muDoubleScalarCos(c3_u_x);
    c3_v_x = c3_c_delta_f;
    c3_w_x = c3_v_x;
    c3_w_x = muDoubleScalarSin(c3_w_x);
    c3_Fx_f = c3_Fx_ft * c3_u_x - c3_Fy_ft * c3_w_x;
    c3_x_x = c3_c_delta_f;
    c3_y_x = c3_x_x;
    c3_y_x = muDoubleScalarSin(c3_y_x);
    c3_ab_x = c3_c_delta_f;
    c3_bb_x = c3_ab_x;
    c3_bb_x = muDoubleScalarCos(c3_bb_x);
    c3_Fy_f = -c3_Fx_f * c3_y_x + c3_Fy_f * c3_bb_x;
    c3_cb_x = c3_c_delta_r;
    c3_db_x = c3_cb_x;
    c3_db_x = muDoubleScalarCos(c3_db_x);
    c3_eb_x = c3_c_delta_r;
    c3_fb_x = c3_eb_x;
    c3_fb_x = muDoubleScalarSin(c3_fb_x);
    c3_Fx_r = c3_Fx_rt * c3_db_x - c3_Fy_rt * c3_fb_x;
    c3_gb_x = c3_c_delta_r;
    c3_hb_x = c3_gb_x;
    c3_hb_x = muDoubleScalarSin(c3_hb_x);
    c3_ib_x = c3_c_delta_r;
    c3_jb_x = c3_ib_x;
    c3_jb_x = muDoubleScalarCos(c3_jb_x);
    c3_Fy_r = -c3_Fx_r * c3_hb_x + c3_Fy_r * c3_jb_x;
    c3_xddot = c3_ydot * c3_r + ((((c3_Fx_f + c3_Fx_r) - c3_c_m * c3_c_g * 0.0)
      + (*chartInstance->c3_F_ext)[0]) + (*chartInstance->c3_Fh)[0]) / c3_c_m;
    c3_yddot = -c3_xdot * c3_r + (((c3_Fy_f + c3_Fy_r) +
      (*chartInstance->c3_F_ext)[1]) + (*chartInstance->c3_Fh)[1]) / c3_c_m;
    c3_rdot = ((((c3_c_a * c3_Fy_f - c3_c_b * c3_Fy_r) +
                 (*chartInstance->c3_M_ext)[2]) + (*chartInstance->c3_Mh)[2]) -
               (*chartInstance->c3_Fh)[1] * c3_c_dh) / c3_c_Izz;
    c3_b_xddot = c3_xddot;
    c3_b_ydot = c3_ydot;
    c3_e_r = c3_r;
    c3_e_m = c3_c_m;
    c3_e_g = c3_c_g;
    c3_g_h = c3_c_h;
    c3_e_hh = c3_c_hh;
    c3_y_a = c3_c_a;
    c3_h_b = c3_c_b;
    c3_e_dh = c3_c_dh;
    c3_c_B1 = (((c3_g_h * ((((*chartInstance->c3_F_ext)[0] +
      (*chartInstance->c3_Fh)[0]) - c3_e_m * (c3_b_xddot - c3_e_r * c3_b_ydot))
      - c3_e_m * c3_e_g * 0.0) - (*chartInstance->c3_Mh)[1]) -
                (*chartInstance->c3_Fh)[2] * c3_e_dh) - (*chartInstance->c3_Fh)
               [0] * (c3_g_h - c3_e_hh)) - (*chartInstance->c3_M_ext)[1];
    c3_b_B2 = (-(*chartInstance->c3_F_ext)[2] - (*chartInstance->c3_Fh)[2]) -
      c3_e_m * c3_e_g;
    c3_FzCalc[0] = -(c3_c_B1 - c3_b_B2 * c3_h_b) / (c3_y_a + c3_h_b);
    c3_FzCalc[1] = (c3_c_B1 + c3_b_B2 * c3_y_a) / (c3_y_a + c3_h_b);
    for (c3_i31 = 0; c3_i31 < 2; c3_i31++) {
      c3_FzCalc[c3_i31] = -c3_FzCalc[c3_i31];
    }

    for (c3_i32 = 0; c3_i32 < 2; c3_i32++) {
      c3_Fz[c3_i32] = c3_FzCalc[c3_i32];
    }

    c3_b_automlsatfunc(chartInstance, c3_Fz);
    c3_Fz_f = c3_Fz[0];
    c3_Fz_r = c3_Fz[1];
    for (c3_i33 = 0; c3_i33 < 2; c3_i33++) {
      c3_Fzinit[c3_i33] = c3_Fz[c3_i33] - c3_Fzinit[c3_i33];
    }

    for (c3_k = 0; c3_k < 2; c3_k++) {
      c3_b_k = c3_k;
      c3_mb_x = c3_Fzinit[c3_b_k];
      c3_s_y = muDoubleScalarAbs(c3_mb_x);
      c3_varargin_1[c3_b_k] = c3_s_y;
    }

    if (c3_varargin_1[0] < c3_varargin_1[1]) {
      c3_maxFerr = c3_varargin_1[1];
    } else {
      c3_kb_x = c3_varargin_1[0];
      c3_j_b = muDoubleScalarIsNaN(c3_kb_x);
      if (c3_j_b) {
        c3_ob_x = c3_varargin_1[1];
        c3_k_b = muDoubleScalarIsNaN(c3_ob_x);
        if (!c3_k_b) {
          c3_maxFerr = c3_varargin_1[1];
        } else {
          c3_maxFerr = c3_varargin_1[0];
        }
      } else {
        c3_maxFerr = c3_varargin_1[0];
      }
    }
  }

  (*chartInstance->c3_stateDer)[0] = c3_xddot;
  (*chartInstance->c3_stateDer)[1] = c3_yddot;
  (*chartInstance->c3_stateDer)[2] = c3_r;
  (*chartInstance->c3_stateDer)[3] = c3_rdot;
  (*chartInstance->c3_wheelInfo)[0] = c3_alfa_f;
  (*chartInstance->c3_wheelInfo)[1] = c3_Vwheel_f;
  (*chartInstance->c3_wheelInfo)[2] = c3_alfa_r;
  (*chartInstance->c3_wheelInfo)[3] = c3_Vwheel_r;
  (*chartInstance->c3_yOut)[0] = c3_xddot;
  (*chartInstance->c3_yOut)[1] = c3_yddot;
  (*chartInstance->c3_yOut)[2] = c3_rdot;
  (*chartInstance->c3_FBody)[0] = (c3_xddot - c3_ydot * c3_r) * c3_c_m;
  (*chartInstance->c3_FBody)[1] = (c3_yddot + c3_xdot * c3_r) * c3_c_m;
  (*chartInstance->c3_FBody)[2] = 0.0;
  (*chartInstance->c3_MBody)[0] = 0.0;
  (*chartInstance->c3_MBody)[1] = c3_rdot * c3_c_Izz;
  (*chartInstance->c3_MBody)[2] = 0.0;
  (*chartInstance->c3_FTire)[0] = c3_b_Fx_ft / c3_c_Nf;
  (*chartInstance->c3_FTire)[1] = c3_b_Fy_ft / c3_c_Nf;
  (*chartInstance->c3_FTire)[2] = c3_Fz_f / c3_c_Nf;
  (*chartInstance->c3_FTire)[3] = c3_b_Fx_rt / c3_c_Nr;
  (*chartInstance->c3_FTire)[4] = c3_b_Fy_rt / c3_c_Nr;
  (*chartInstance->c3_FTire)[5] = c3_Fz_r / c3_c_Nr;
  (*chartInstance->c3_FOut)[0] = c3_Fx_f;
  (*chartInstance->c3_FOut)[1] = c3_Fy_f;
  (*chartInstance->c3_FOut)[2] = c3_Fz_f;
  (*chartInstance->c3_FOut)[3] = c3_Fx_r;
  (*chartInstance->c3_FOut)[4] = c3_Fy_r;
  (*chartInstance->c3_FOut)[5] = c3_Fz_r;
  (*chartInstance->c3_Fg)[0] = 0.0;
  (*chartInstance->c3_Fg)[1] = 0.0;
  (*chartInstance->c3_Fg)[2] = c3_c_m * c3_c_g;
  c3_b_status = c3_maxFerr;
  c3_b_d = c3_b_status;
  *chartInstance->c3_status = c3_b_d;
  c3_do_animation_call_c3_autolibshared(chartInstance);
  for (c3_i23 = 0; c3_i23 < 3; c3_i23++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 15U,
                      (*chartInstance->c3_yOut)[c3_i23]);
  }

  for (c3_i24 = 0; c3_i24 < 3; c3_i24++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 16U,
                      (*chartInstance->c3_FBody)[c3_i24]);
  }

  for (c3_i25 = 0; c3_i25 < 3; c3_i25++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 17U,
                      (*chartInstance->c3_MBody)[c3_i25]);
  }

  for (c3_i26 = 0; c3_i26 < 6; c3_i26++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 18U,
                      (*chartInstance->c3_FOut)[c3_i26]);
  }

  for (c3_i27 = 0; c3_i27 < 6; c3_i27++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 19U,
                      (*chartInstance->c3_FTire)[c3_i27]);
  }

  for (c3_i28 = 0; c3_i28 < 3; c3_i28++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 20U,
                      (*chartInstance->c3_Fg)[c3_i28]);
  }

  for (c3_i29 = 0; c3_i29 < 4; c3_i29++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 21U,
                      (*chartInstance->c3_wheelInfo)[c3_i29]);
  }

  for (c3_i30 = 0; c3_i30 < 4; c3_i30++) {
    covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 22U,
                      (*chartInstance->c3_stateDer)[c3_i30]);
  }

  covrtSigUpdateFcn(chartInstance->c3_covrtInstance, 23U,
                    *chartInstance->c3_status);
}

static void ext_mode_exec_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance)
{
}

static void c3_update_jit_animation_c3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance)
{
}

static void c3_do_animation_call_c3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance)
{
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_i_y = NULL;
  const mxArray *c3_j_y = NULL;
  const mxArray *c3_k_y = NULL;
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(10, 1), false);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", *chartInstance->c3_FBody, 0, 0U, 1U,
    0U, 1, 3), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", *chartInstance->c3_FOut, 0, 0U, 1U,
    0U, 1, 6), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", *chartInstance->c3_FTire, 0, 0U, 1U,
    0U, 1, 6), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", *chartInstance->c3_Fg, 0, 0U, 1U, 0U,
    1, 3), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", *chartInstance->c3_MBody, 0, 0U, 1U,
    0U, 1, 3), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", *chartInstance->c3_stateDer, 0, 0U,
    1U, 0U, 1, 4), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", chartInstance->c3_status, 0, 0U, 0U,
    0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", *chartInstance->c3_wheelInfo, 0, 0U,
    1U, 0U, 1, 4), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", *chartInstance->c3_yOut, 0, 0U, 1U,
    0U, 1, 3), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y",
    &chartInstance->c3_is_active_c3_autolibshared, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv1[6];
  real_T c3_dv2[6];
  real_T c3_dv5[4];
  real_T c3_dv6[4];
  real_T c3_dv[3];
  real_T c3_dv3[3];
  real_T c3_dv4[3];
  real_T c3_dv7[3];
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                      "FBody", c3_dv);
  for (c3_i = 0; c3_i < 3; c3_i++) {
    (*chartInstance->c3_FBody)[c3_i] = c3_dv[c3_i];
  }

  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
                        "FOut", c3_dv1);
  for (c3_i1 = 0; c3_i1 < 6; c3_i1++) {
    (*chartInstance->c3_FOut)[c3_i1] = c3_dv1[c3_i1];
  }

  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
                        "FTire", c3_dv2);
  for (c3_i2 = 0; c3_i2 < 6; c3_i2++) {
    (*chartInstance->c3_FTire)[c3_i2] = c3_dv2[c3_i2];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)), "Fg",
                      c3_dv3);
  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    (*chartInstance->c3_Fg)[c3_i3] = c3_dv3[c3_i3];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
                      "MBody", c3_dv4);
  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    (*chartInstance->c3_MBody)[c3_i4] = c3_dv4[c3_i4];
  }

  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)),
                        "stateDer", c3_dv5);
  for (c3_i5 = 0; c3_i5 < 4; c3_i5++) {
    (*chartInstance->c3_stateDer)[c3_i5] = c3_dv5[c3_i5];
  }

  *chartInstance->c3_status = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 6)), "status");
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 7)),
                        "wheelInfo", c3_dv6);
  for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
    (*chartInstance->c3_wheelInfo)[c3_i6] = c3_dv6[c3_i6];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 8)), "yOut",
                      c3_dv7);
  for (c3_i7 = 0; c3_i7 < 3; c3_i7++) {
    (*chartInstance->c3_yOut)[c3_i7] = c3_dv7[c3_i7];
  }

  chartInstance->c3_is_active_c3_autolibshared = c3_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 9)),
     "is_active_c3_autolibshared");
  sf_mex_destroy(&c3_u);
  sf_mex_destroy(&c3_st);
}

static void initSimStructsc3_autolibshared(SFc3_autolibsharedInstanceStruct
  *chartInstance)
{
}

static void initSubchartIOPointersc3_autolibshared
  (SFc3_autolibsharedInstanceStruct *chartInstance)
{
}

static real_T c3_function_handle_parenReference(SFc3_autolibsharedInstanceStruct
  *chartInstance, real_T c3_varargin_1)
{
  real_T c3_b_a;
  real_T c3_x;
  c3_x = c3_varargin_1;
  c3_b_a = c3_x;
  return c3_b_a * c3_b_a;
}

static void c3_automlsatfunc(SFc3_autolibsharedInstanceStruct *chartInstance,
  real_T c3_u[2], real_T c3_y_sat[2])
{
  int32_T c3_i;
  for (c3_i = 0; c3_i < 2; c3_i++) {
    c3_y_sat[c3_i] = c3_u[c3_i];
  }

  c3_b_automlsatfunc(chartInstance, c3_y_sat);
}

static void c3_automlvehdynftiresat(SFc3_autolibsharedInstanceStruct
  *chartInstance, const emlrtStack *c3_sp, real_T c3_Ftire_x, real_T c3_Ftire_y,
  real_T c3_b_Fxtire_sat, real_T c3_b_Fytire_sat, real_T *c3_Ftire_xs, real_T
  *c3_Ftire_ys)
{
  static char_T c3_b_cv[4] = { 's', 'q', 'r', 't' };

  emlrtStack c3_st;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  real_T c3_b_tmp_data[1];
  real_T c3_dv[1];
  real_T c3_dv1[1];
  real_T c3_Ftire_mag;
  real_T c3_Ftire_x_max;
  real_T c3_Ftire_y_max;
  real_T c3_ab_x;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_bb_x;
  real_T c3_c_a;
  real_T c3_c_x;
  real_T c3_c_y;
  real_T c3_d_a;
  real_T c3_d_x;
  real_T c3_d_y;
  real_T c3_e_a;
  real_T c3_e_x;
  real_T c3_f_a;
  real_T c3_f_x;
  real_T c3_g_a;
  real_T c3_g_x;
  real_T c3_h_a;
  real_T c3_h_x;
  real_T c3_h_y;
  real_T c3_i_a;
  real_T c3_i_x;
  real_T c3_i_y;
  real_T c3_j_a;
  real_T c3_j_x;
  real_T c3_j_y;
  real_T c3_k_x;
  real_T c3_k_y;
  real_T c3_m_x;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_theta_Ftire;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_w_x;
  real_T c3_x;
  real_T c3_x_x;
  real_T c3_y;
  real_T c3_y_x;
  int32_T c3_b_tmp_size[2];
  int32_T c3_c_tmp_size[2];
  int32_T c3_iv[2];
  int32_T c3_iv1[2];
  int32_T c3_iv2[2];
  int32_T c3_iv3[2];
  int32_T c3_iv4[2];
  int32_T c3_iv5[2];
  int32_T c3_tmp_size[2];
  int32_T c3_c_tmp_data[1];
  int32_T c3_tmp_data[1];
  int32_T c3_b_end;
  int32_T c3_b_i;
  int32_T c3_b_loop_ub;
  int32_T c3_b_trueCount;
  int32_T c3_c_end;
  int32_T c3_c_i;
  int32_T c3_c_loop_ub;
  int32_T c3_c_trueCount;
  int32_T c3_d_end;
  int32_T c3_d_loop_ub;
  int32_T c3_d_trueCount;
  int32_T c3_e_end;
  int32_T c3_e_i;
  int32_T c3_e_trueCount;
  int32_T c3_end;
  int32_T c3_f_end;
  int32_T c3_f_i;
  int32_T c3_f_trueCount;
  int32_T c3_g_i;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_j_i;
  int32_T c3_k_i;
  int32_T c3_loop_ub;
  int32_T c3_m_i;
  int32_T c3_trueCount;
  boolean_T c3_b_p;
  boolean_T c3_p;
  c3_st.prev = c3_sp;
  c3_st.tls = c3_sp->tls;
  c3_y = c3_Ftire_x;
  c3_x = c3_Ftire_y;
  c3_b_a = c3_y;
  c3_b_b = c3_x;
  c3_b_y = c3_b_a;
  c3_b_x = c3_b_b;
  c3_theta_Ftire = muDoubleScalarAtan2(c3_b_y, c3_b_x);
  c3_st.site = &c3_d_emlrtRSI;
  c3_c_x = c3_theta_Ftire;
  c3_d_x = c3_c_x;
  c3_d_x = muDoubleScalarCos(c3_d_x);
  c3_c_a = c3_b_Fxtire_sat * c3_d_x;
  c3_d_a = c3_c_a;
  c3_e_a = c3_d_a;
  c3_f_a = c3_e_a;
  c3_c_y = c3_f_a * c3_f_a;
  c3_st.site = &c3_d_emlrtRSI;
  c3_e_x = c3_theta_Ftire;
  c3_f_x = c3_e_x;
  c3_f_x = muDoubleScalarSin(c3_f_x);
  c3_g_a = c3_b_Fytire_sat * c3_f_x;
  c3_h_a = c3_g_a;
  c3_i_a = c3_h_a;
  c3_j_a = c3_i_a;
  c3_d_y = c3_j_a * c3_j_a;
  c3_st.site = &c3_d_emlrtRSI;
  c3_g_x = c3_c_y + c3_d_y;
  c3_h_x = c3_g_x;
  c3_i_x = c3_h_x;
  if (c3_i_x < 0.0) {
    c3_p = true;
  } else {
    c3_p = false;
  }

  c3_b_p = c3_p;
  if (c3_b_p) {
    c3_e_y = NULL;
    sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_f_y = NULL;
    sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c3_g_y = NULL;
    sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_b_cv, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c3_st, &c3_b_emlrtMCI, "error", 0U, 2U, 14, c3_e_y, 14,
                sf_mex_call(&c3_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c3_st, NULL, "message", 1U, 2U, 14, c3_f_y, 14, c3_g_y)));
  }

  c3_h_x = muDoubleScalarSqrt(c3_h_x);
  c3_Ftire_mag = c3_b_Fxtire_sat * c3_b_Fytire_sat / c3_h_x;
  c3_j_x = c3_theta_Ftire;
  c3_k_x = c3_j_x;
  c3_k_x = muDoubleScalarSin(c3_k_x);
  c3_Ftire_x_max = c3_Ftire_mag * c3_k_x;
  c3_m_x = c3_theta_Ftire;
  c3_o_x = c3_m_x;
  c3_o_x = muDoubleScalarCos(c3_o_x);
  c3_Ftire_y_max = c3_Ftire_mag * c3_o_x;
  c3_p_x = c3_Ftire_x;
  c3_q_x = c3_p_x;
  c3_r_x = c3_q_x;
  c3_h_y = muDoubleScalarAbs(c3_r_x);
  c3_s_x = c3_Ftire_x_max;
  c3_t_x = c3_s_x;
  c3_u_x = c3_t_x;
  c3_i_y = muDoubleScalarAbs(c3_u_x);
  c3_end = 1;
  c3_trueCount = 0;
  for (c3_i = 0; c3_i < c3_end; c3_i++) {
    if (c3_h_y > c3_i_y) {
      c3_trueCount++;
    }
  }

  c3_tmp_size[1] = c3_trueCount;
  for (c3_b_i = 0; c3_b_i < c3_end; c3_b_i++) {
    if (c3_h_y > c3_i_y) {
      c3_tmp_data[0] = c3_b_i;
    }
  }

  c3_b_end = 1;
  c3_b_trueCount = 0;
  for (c3_c_i = 0; c3_c_i < c3_b_end; c3_c_i++) {
    if (c3_h_y > c3_i_y) {
      c3_b_trueCount++;
    }
  }

  c3_iv[1] = c3_b_trueCount;
  c3_b_tmp_size[1] = c3_iv[1];
  c3_c_end = 1;
  c3_c_trueCount = 0;
  for (c3_e_i = 0; c3_e_i < c3_c_end; c3_e_i++) {
    if (c3_h_y > c3_i_y) {
      c3_c_trueCount++;
    }
  }

  c3_iv1[0] = 1;
  c3_iv2[1] = c3_c_trueCount;
  c3_loop_ub = c3_iv1[0] * c3_iv2[1] - 1;
  for (c3_f_i = 0; c3_f_i <= c3_loop_ub; c3_f_i++) {
    c3_b_tmp_data[0] = c3_Ftire_x_max;
  }

  if (c3_tmp_size[1] != c3_b_tmp_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_tmp_size[1], c3_b_tmp_size[1],
      &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
  }

  c3_dv[0] = c3_Ftire_x;
  c3_b_loop_ub = c3_b_tmp_size[1] - 1;
  for (c3_i1 = 0; c3_i1 <= c3_b_loop_ub; c3_i1++) {
    c3_dv[c3_tmp_data[0]] = c3_b_tmp_data[0];
  }

  *c3_Ftire_xs = c3_dv[0];
  c3_v_x = c3_Ftire_y;
  c3_w_x = c3_v_x;
  c3_x_x = c3_w_x;
  c3_j_y = muDoubleScalarAbs(c3_x_x);
  c3_y_x = c3_Ftire_y_max;
  c3_ab_x = c3_y_x;
  c3_bb_x = c3_ab_x;
  c3_k_y = muDoubleScalarAbs(c3_bb_x);
  c3_d_end = 1;
  c3_d_trueCount = 0;
  for (c3_g_i = 0; c3_g_i < c3_d_end; c3_g_i++) {
    if (c3_j_y > c3_k_y) {
      c3_d_trueCount++;
    }
  }

  c3_c_tmp_size[1] = c3_d_trueCount;
  for (c3_j_i = 0; c3_j_i < c3_d_end; c3_j_i++) {
    if (c3_j_y > c3_k_y) {
      c3_c_tmp_data[0] = c3_j_i;
    }
  }

  c3_e_end = 1;
  c3_e_trueCount = 0;
  for (c3_k_i = 0; c3_k_i < c3_e_end; c3_k_i++) {
    if (c3_j_y > c3_k_y) {
      c3_e_trueCount++;
    }
  }

  c3_iv3[1] = c3_e_trueCount;
  c3_b_tmp_size[1] = c3_iv3[1];
  c3_f_end = 1;
  c3_f_trueCount = 0;
  for (c3_m_i = 0; c3_m_i < c3_f_end; c3_m_i++) {
    if (c3_j_y > c3_k_y) {
      c3_f_trueCount++;
    }
  }

  c3_iv4[0] = 1;
  c3_iv5[1] = c3_f_trueCount;
  c3_c_loop_ub = c3_iv4[0] * c3_iv5[1] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_c_loop_ub; c3_i2++) {
    c3_b_tmp_data[0] = c3_Ftire_y_max;
  }

  if (c3_c_tmp_size[1] != c3_b_tmp_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(c3_c_tmp_size[1], c3_b_tmp_size[1],
      &c3_b_emlrtECI, (emlrtConstCTX)c3_sp);
  }

  c3_dv1[0] = c3_Ftire_y;
  c3_d_loop_ub = c3_b_tmp_size[1] - 1;
  for (c3_i3 = 0; c3_i3 <= c3_d_loop_ub; c3_i3++) {
    c3_dv1[c3_c_tmp_data[0]] = c3_b_tmp_data[0];
  }

  *c3_Ftire_ys = c3_dv1[0];
}

const mxArray *sf_c3_autolibshared_get_eml_resolved_functions_info()
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct *chartInstance,
  const mxArray *c3_nullptr, const char_T *c3_identifier, real_T c3_y[3])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = const_cast<const char_T *>(c3_identifier);
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nullptr), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_nullptr);
}

static void c3_b_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3])
{
  real_T c3_dv[3];
  int32_T c3_i;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i = 0; c3_i < 3; c3_i++) {
    c3_y[c3_i] = c3_dv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_nullptr, const char_T *c3_identifier, real_T
  c3_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = const_cast<const char_T *>(c3_identifier);
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nullptr), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_nullptr);
}

static void c3_d_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[6])
{
  real_T c3_dv[6];
  int32_T c3_i;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv, 1, 0, 0U, 1, 0U, 1, 6);
  for (c3_i = 0; c3_i < 6; c3_i++) {
    c3_y[c3_i] = c3_dv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_nullptr, const char_T *c3_identifier, real_T
  c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = const_cast<const char_T *>(c3_identifier);
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nullptr), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_nullptr);
}

static void c3_f_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4])
{
  real_T c3_dv[4];
  int32_T c3_i;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv, 1, 0, 0U, 1, 0U, 1, 4);
  for (c3_i = 0; c3_i < 4; c3_i++) {
    c3_y[c3_i] = c3_dv[c3_i];
  }

  sf_mex_destroy(&c3_u);
}

static real_T c3_g_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_nullptr, const char_T *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  c3_thisId.fIdentifier = const_cast<const char_T *>(c3_identifier);
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nullptr), &c3_thisId);
  sf_mex_destroy(&c3_nullptr);
  return c3_y;
}

static real_T c3_h_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_b_d;
  real_T c3_y;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b_d, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_b_d;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint8_T c3_i_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_nullptr, const char_T *c3_identifier)
{
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  c3_thisId.fIdentifier = const_cast<const char_T *>(c3_identifier);
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nullptr), &c3_thisId);
  sf_mex_destroy(&c3_nullptr);
  return c3_y;
}

static uint8_T c3_j_emlrt_marshallIn(SFc3_autolibsharedInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_u;
  uint8_T c3_y;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b_u, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_b_u;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_slStringInitializeDynamicBuffers(SFc3_autolibsharedInstanceStruct
  *chartInstance)
{
}

static void c3_chart_data_browse_helper(SFc3_autolibsharedInstanceStruct
  *chartInstance, int32_T c3_ssIdNumber, const mxArray **c3_mxData, uint8_T
  *c3_isValueTooBig)
{
  real_T c3_b_d;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  real_T c3_d7;
  *c3_mxData = NULL;
  *c3_mxData = NULL;
  *c3_isValueTooBig = 0U;
  switch (c3_ssIdNumber) {
   case 7U:
    c3_b_d = *chartInstance->c3_delta_f;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_b_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 10U:
    c3_d1 = *chartInstance->c3_delta_r;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 26U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_mu, 0,
      0U, 1U, 0U, 1, 2), false);
    break;

   case 11U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_a, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 12U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_b, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 15U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_h, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 49U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_d, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 35U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", chartInstance->c3_w, 0, 0U,
      1U, 0U, 2, 1, 2), false);
    break;

   case 13U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_m, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 37U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_NF, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 38U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_NR, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 14U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Izz, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 16U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_g, 0, 0U,
      0U, 0U, 0), false);
    break;

   case 25U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_Fxtire_sat, 0, 0U, 0U, 0U, 0), false);
    break;

   case 28U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_Fytire_sat, 0, 0U, 0U, 0U, 0), false);
    break;

   case 34U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_trackMode, 0, 0U, 0U, 0U, 0), false);
    break;

   case 27U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      &chartInstance->c3_inputMode, 0, 0U, 0U, 0U, 0), false);
    break;

   case 29U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_xdot_tol,
      0, 0U, 0U, 0U, 0), false);
    break;

   case 42U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &chartInstance->c3_Fznom, 0,
      0U, 0U, 0U, 0), false);
    break;

   case 19U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_F_f, 0,
      0U, 1U, 0U, 1, 2), false);
    break;

   case 20U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_F_r, 0,
      0U, 1U, 0U, 1, 2), false);
    break;

   case 32U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_F_ext, 0,
      0U, 1U, 0U, 1, 3), false);
    break;

   case 33U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_M_ext, 0,
      0U, 1U, 0U, 1, 3), false);
    break;

   case 53U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Fh, 0,
      0U, 1U, 0U, 1, 3), false);
    break;

   case 54U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Mh, 0,
      0U, 1U, 0U, 1, 3), false);
    break;

   case 21U:
    c3_d2 = *chartInstance->c3_Cy_f;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d2, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 22U:
    c3_d3 = *chartInstance->c3_Cy_r;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d3, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 50U:
    c3_d4 = *chartInstance->c3_dh;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d4, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 51U:
    c3_d5 = *chartInstance->c3_hl;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d5, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 52U:
    c3_d6 = *chartInstance->c3_hh;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d6, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 5U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_yOut, 0,
      0U, 1U, 0U, 1, 3), false);
    break;

   case 47U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_FBody, 0,
      0U, 1U, 0U, 1, 3), false);
    break;

   case 48U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_MBody, 0,
      0U, 1U, 0U, 1, 3), false);
    break;

   case 36U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_FOut, 0,
      0U, 1U, 0U, 1, 6), false);
    break;

   case 43U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_FTire, 0,
      0U, 1U, 0U, 1, 6), false);
    break;

   case 44U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_Fg, 0,
      0U, 1U, 0U, 1, 3), false);
    break;

   case 41U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData",
      *chartInstance->c3_wheelInfo, 0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 17U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_stateDer,
      0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 18U:
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", *chartInstance->c3_stateVec,
      0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 39U:
    c3_d7 = *chartInstance->c3_status;
    sf_mex_assign(c3_mxData, sf_mex_create("mxData", &c3_d7, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }
}

static void c3_b_automlsatfunc(SFc3_autolibsharedInstanceStruct *chartInstance,
  real_T c3_u[2])
{
  real_T c3_tempInds_data[2];
  int32_T c3_ii_data[2];
  int32_T c3_ii_size[2];
  int32_T c3_tempInds_size[2];
  int32_T c3_b_ii;
  int32_T c3_b_loop_ub;
  int32_T c3_c_ii;
  int32_T c3_c_loop_ub;
  int32_T c3_i;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_idx;
  int32_T c3_loop_ub;
  boolean_T c3_x[2];
  boolean_T c3_b_b;
  boolean_T c3_exitg1;
  for (c3_i = 0; c3_i < 2; c3_i++) {
    c3_x[c3_i] = (c3_u[c3_i] < 0.0);
  }

  c3_idx = 0;
  c3_b_ii = 1;
  c3_exitg1 = false;
  while ((!c3_exitg1) && (c3_b_ii - 1 < 2)) {
    c3_c_ii = c3_b_ii;
    if (c3_x[c3_c_ii - 1]) {
      c3_idx++;
      c3_ii_data[c3_idx - 1] = c3_c_ii;
      if (c3_idx >= 2) {
        c3_exitg1 = true;
      } else {
        c3_b_ii++;
      }
    } else {
      c3_b_ii++;
    }
  }

  c3_b_b = (c3_idx < 1);
  if (c3_b_b) {
    c3_i1 = 0;
  } else {
    c3_i1 = c3_idx;
  }

  c3_ii_size[1] = c3_i1;
  c3_tempInds_size[1] = c3_ii_size[1];
  c3_loop_ub = c3_ii_size[1] - 1;
  for (c3_i2 = 0; c3_i2 <= c3_loop_ub; c3_i2++) {
    c3_tempInds_data[c3_i2] = static_cast<real_T>(c3_ii_data[c3_i2]);
  }

  c3_ii_size[1] = c3_tempInds_size[1];
  c3_b_loop_ub = c3_tempInds_size[1] - 1;
  for (c3_i3 = 0; c3_i3 <= c3_b_loop_ub; c3_i3++) {
    c3_ii_data[c3_i3] = static_cast<int32_T>(c3_tempInds_data[c3_i3]);
  }

  c3_c_loop_ub = c3_ii_size[1] - 1;
  for (c3_i4 = 0; c3_i4 <= c3_c_loop_ub; c3_i4++) {
    c3_u[c3_ii_data[c3_i4] - 1] = 0.0;
  }
}

static void init_dsm_address_info(SFc3_autolibsharedInstanceStruct
  *chartInstance)
{
}

static void init_simulink_io_address(SFc3_autolibsharedInstanceStruct
  *chartInstance)
{
  chartInstance->c3_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_delta_f = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_delta_r = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_mu = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_F_f = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_F_r = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_F_ext = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_M_ext = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_Fh = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_Mh = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c3_Cy_f = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c3_Cy_r = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c3_dh = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    11);
  chartInstance->c3_hl = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    12);
  chartInstance->c3_hh = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    13);
  chartInstance->c3_yOut = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_FBody = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_MBody = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_FOut = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_FTire = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_Fg = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_wheelInfo = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_stateDer = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c3_stateVec = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c3_status = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c3_autolibshared_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1338716371U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3157887622U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2108316693U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2050724987U);
}

mxArray *sf_c3_autolibshared_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_autolibshared_jit_fallback_info(void)
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

mxArray *sf_c3_autolibshared_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_autolibshared(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiA24GBgYAPSQIqBiQECWKF8RiDmgtIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3uK9De4O6DrZ8GinxVJvwCU7+aUn1IJDR9YOA2YPx"
    "icwP4wIOAPFhR/sDC4+ZeWDAr3N7iSHw8hmUWpgyYe3IiKByYUfzAxuKUPFvd7kB0PvoMqPxgS5"
    "Q8ONH+A+MUliSWpLqlFgyNfOBPlDzY0f7BB/VFaPEjio8EF7A8HAv7gRPMHiF+ekZqaA64pEP4Y"
    "+PQlQlZ5W0m18lbBgTL9EPsDCLhfCi0+QPzM4vjE5JLMstT4ZOP4xNKS/JzMpOKMxKLUFNT4AQB"
    "O9Uec"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_autolibshared_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "shrjSmGUDCIVgYzTF0dJoME";
}

static void sf_opaque_initialize_c3_autolibshared(void *chartInstanceVar)
{
  initialize_params_c3_autolibshared((SFc3_autolibsharedInstanceStruct*)
    chartInstanceVar);
  initialize_c3_autolibshared((SFc3_autolibsharedInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_autolibshared(void *chartInstanceVar)
{
  enable_c3_autolibshared((SFc3_autolibsharedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_autolibshared(void *chartInstanceVar)
{
  disable_c3_autolibshared((SFc3_autolibsharedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_autolibshared(void *chartInstanceVar)
{
  sf_gateway_c3_autolibshared((SFc3_autolibsharedInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_autolibshared(SimStruct* S)
{
  return get_sim_state_c3_autolibshared((SFc3_autolibsharedInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_autolibshared(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c3_autolibshared((SFc3_autolibsharedInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c3_autolibshared(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_autolibsharedInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_autolibshared_optimization_info();
    }

    mdl_cleanup_runtime_resources_c3_autolibshared
      ((SFc3_autolibsharedInstanceStruct*) chartInstanceVar);
    ((SFc3_autolibsharedInstanceStruct*) chartInstanceVar)->
      ~SFc3_autolibsharedInstanceStruct();
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c3_autolibshared(void *chartInstanceVar)
{
  mdl_start_c3_autolibshared((SFc3_autolibsharedInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc3_autolibsharedInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c3_autolibshared(void *chartInstanceVar)
{
  mdl_terminate_c3_autolibshared((SFc3_autolibsharedInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_autolibshared(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_autolibshared((SFc3_autolibsharedInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc3_autolibshared((SFc3_autolibsharedInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c3_autolibshared_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [23] = {
    "eNrdWU9vG0UUn0RpSCpIc0BCqlDJrVyQCr30gMCJvZsaxSTCThBcosnus3fI7Kw7f5y46iEfgSt",
    "fgs/AkY/ADbhy4siRN+u166xNPLOpqNuVNpvZ3d+893v/5s2arDRbBI8tPJMHhKzjdQPPVTI67h",
    "TjlalzdH+NfF6Mf71LSJTF0APRNt0uuyR+hzDpEZU0VcT/EDSFb0Bl3GiWiaboZu5YJrogQUQ4Q",
    "T+T2kuuYqnhTJyHRkRWsvo2YVHSTjLD4z2ckMaHgg//S27f6COU2GASIh0CxDqRmeklIae9m60g",
    "9UU9gehcmdTbVgp02/QtVdUyXLM+h+ASoqZQmqIV1AK+bU011PWln5EtX9Ueo7O0zxkV7rZOqGp",
    "DH6NDw3E/xr+HRqP1HOWivDMmqM4kozxIeT2h0hV7xFHPFoY197azTnUDzkyvx0TPWleaFATyxz",
    "hxsFW3ng1A0h4cCj+5kWUXXOYOnsSlI1azFE6o3I0wDhTEfjmIAazaFF0LHZzGCwuCnnFoqo5kA",
    "/SRb91o2lSqVDdMOookVQmbyw0G6FVVUW4YiTrlXPlhO1n/AAbAc/kNqmkF7Ei+B1gpFncyjA6b",
    "uZ7ZbwR7ZqDA1jMRM/eoHJRQ+SLxNRZ8BzhLbRpAjGaeqD6ZaFEeGaWztI6p3zg4cJQ3i20KDbJ",
    "LI3Cu15IyBahwHleecmOmbCIhGq2kc5bOM4xysBKUqK4RjYtMnqONfReGl7aymeCHhrgHDdCQF7",
    "kAo/uEcuOoc6qwKtvwOFZYZf3kItbmTyVwRKMEYrsGMg4trLM4gauLlV0+d5HtgOlhA1QkWd81k",
    "wwWdFz8rJU6wz4ci3ORXYhQZmm76GJuiCsArBpUClzK9nAplcMQlXfTWsKzTl7dfRsGa2eqOT2z",
    "sbEPAldDy9Wu3jTCrAoEtpuo0G2wbfYc2xGhmNLYAg6DPAfivA+ukZd98NqcPnh7qg/eLs7o8Sk",
    "1OuPsTKEkiO08j6bmedehn94u+vCbcGQGNzq2pq4fT+FX5sglU9cy383V6+/fK8lbHd+7fszM81",
    "5J7lppnvXCbu88/PmvnYenf34W/PSC//7Lj2X+ZX1WZvRZyf+3uD82/PYvW8X4w3HvNKnUg5liZ",
    "t99uiAuPijFhR2rRP7QTvePG/XmSe+7553wUfxV1gpGfl6g792SvuP7O7Zfw0TO64KMmnGxD7Jj",
    "akb9uZ3/yZS+6wvssTkVX4T8/eWt8Ff7tTJ+nr3ulOxlx+FeFg9L8fzaeJC9Wjke5/FYu8ZjjYS",
    "4QiyF/ldBdT90cG+6NH4Infyweo3HKgl7y6L/08p+aC1VPnzqxGOjxGNj3L80QC5HXtSdeKyXeK",
    "wXPIxaEn9cNWou/cpmiYcdXyQA0y33csTX+5Xq7fCV1dud2u3wI/lHC/S/X/LH/fy7zym13T2cl",
    "jvJWf9U7Y98cW+KvLddz1fJz2Ufcq8ibrMijvzPuNvy891fvenv31SPSen97SXmcVMd9dlnLxuv",
    "34jfvvejYvzF5NtuPWE8nvN1qXh8ALQ77+lbEt//eNpvvM8PrP2KH9S+f7wrKB8qNvo0Nr59JO1",
    "vOZNHEqia/83udawn8/ol133JcSf85Mkt1qV/AQXsMr8=",
    ""
  };

  static char newstr [1621] = "";
  newstr[0] = '\0';
  for (i = 0; i < 23; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c3_autolibshared(SimStruct *S)
{
  const char* newstr = sf_c3_autolibshared_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(3937281799U));
  ssSetChecksum1(S,(3781109536U));
  ssSetChecksum2(S,(2090419506U));
  ssSetChecksum3(S,(2428559212U));
}

static void mdlRTW_c3_autolibshared(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c3_autolibshared(SimStruct *S)
{
  SFc3_autolibsharedInstanceStruct *chartInstance;
  chartInstance = (SFc3_autolibsharedInstanceStruct *)utMalloc(sizeof
    (SFc3_autolibsharedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_autolibsharedInstanceStruct));
  chartInstance = new (chartInstance) SFc3_autolibsharedInstanceStruct;
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_autolibshared;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_autolibshared;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c3_autolibshared;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c3_autolibshared;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c3_autolibshared;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_autolibshared;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_autolibshared;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_autolibshared;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_autolibshared;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_autolibshared;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_autolibshared;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_autolibshared;
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

  mdl_setup_runtime_resources_c3_autolibshared(chartInstance);
}

void c3_autolibshared_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c3_autolibshared(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_autolibshared(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_autolibshared(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_autolibshared_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
