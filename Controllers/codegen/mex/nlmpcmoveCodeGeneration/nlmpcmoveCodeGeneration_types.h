/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nlmpcmoveCodeGeneration_types.h
 *
 * Code generation for function 'nlmpcmoveCodeGeneration'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include <stddef.h>

/* Type Definitions */
#ifndef typedef_cell_0
#define typedef_cell_0
typedef struct {
  real_T f1;
  real_T f2;
  real_T f3[6];
  real_T f4[16];
  real_T f5[6];
} cell_0;
#endif /* typedef_cell_0 */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  real_T MVopt[22];
  real_T Xopt[44];
  real_T Yopt[44];
  real_T Topt[11];
  real_T Slack;
  real_T ExitFlag;
  real_T Iterations;
  real_T Cost;
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T
struct emxArray_int8_T {
  int8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int8_T */
#ifndef typedef_emxArray_int8_T
#define typedef_emxArray_int8_T
typedef struct emxArray_int8_T emxArray_int8_T;
#endif /* typedef_emxArray_int8_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#ifndef typedef_c_struct_T
#define typedef_c_struct_T
typedef struct {
  int32_T nVarMax;
  int32_T mNonlinIneq;
  int32_T mNonlinEq;
  int32_T mIneq;
  int32_T mEq;
  int32_T iNonIneq0;
  int32_T iNonEq0;
  real_T sqpFval;
  real_T sqpFval_old;
  real_T xstarsqp[51];
  real_T xstarsqp_old[51];
  emxArray_real_T *cIneq;
  emxArray_real_T *cIneq_old;
  real_T cEq[40];
  real_T cEq_old[40];
  emxArray_real_T *grad;
  emxArray_real_T *grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  emxArray_real_T *lambdasqp;
  emxArray_real_T *lambdaStopTest;
  emxArray_real_T *lambdaStopTestPrev;
  real_T steplength;
  emxArray_real_T *delta_x;
  emxArray_real_T *socDirection;
  emxArray_int32_T *workingset_old;
  emxArray_real_T *JacCineqTrans_old;
  emxArray_real_T *JacCeqTrans_old;
  emxArray_real_T *gradLag;
  emxArray_real_T *delta_gradLag;
  emxArray_real_T *xstar;
  real_T fstar;
  real_T firstorderopt;
  emxArray_real_T *lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  emxArray_real_T *searchDir;
} c_struct_T;
#endif /* typedef_c_struct_T */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

#ifndef typedef_d_struct_T
#define typedef_d_struct_T
typedef struct {
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  emxArray_real_T *Aineq;
  emxArray_real_T *bineq;
  emxArray_real_T *Aeq;
  real_T beq[40];
  emxArray_real_T *lb;
  emxArray_real_T *ub;
  emxArray_int32_T *indexLB;
  emxArray_int32_T *indexUB;
  emxArray_int32_T *indexFixed;
  int32_T mEqRemoved;
  int32_T indexEqRemoved[40];
  emxArray_real_T *ATwset;
  emxArray_real_T *bwset;
  int32_T nActiveConstr;
  emxArray_real_T *maxConstrWorkspace;
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  emxArray_boolean_T *isActiveConstr;
  emxArray_int32_T *Wid;
  emxArray_int32_T *Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
} d_struct_T;
#endif /* typedef_d_struct_T */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  emxArray_real_T *ref;
  emxArray_real_T *MVTarget;
  cell_0 Parameters;
  emxArray_real_T *X0;
  emxArray_real_T *MV0;
  real_T Slack0;
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_e_struct_T
#define typedef_e_struct_T
typedef struct {
  int32_T ldq;
  emxArray_real_T *QR;
  emxArray_real_T *Q;
  emxArray_int32_T *jpvt;
  int32_T mrows;
  int32_T ncols;
  emxArray_real_T *tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
} e_struct_T;
#endif /* typedef_e_struct_T */

#ifndef typedef_f_struct_T
#define typedef_f_struct_T
typedef struct {
  emxArray_real_T *FMat;
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_;
  real_T workspace2_;
} f_struct_T;
#endif /* typedef_f_struct_T */

#ifndef typedef_g_struct_T
#define typedef_g_struct_T
typedef struct {
  emxArray_real_T *grad;
  emxArray_real_T *Hx;
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
} g_struct_T;
#endif /* typedef_g_struct_T */

#ifndef typedef_h_struct_T
#define typedef_h_struct_T
typedef struct {
  emxArray_real_T *workspace_double;
  emxArray_int32_T *workspace_int;
  emxArray_int32_T *workspace_sort;
} h_struct_T;
#endif /* typedef_h_struct_T */

#ifndef struct_emxArray_ptrdiff_t
#define struct_emxArray_ptrdiff_t
struct emxArray_ptrdiff_t {
  ptrdiff_t *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_ptrdiff_t */
#ifndef typedef_emxArray_ptrdiff_t
#define typedef_emxArray_ptrdiff_t
typedef struct emxArray_ptrdiff_t emxArray_ptrdiff_t;
#endif /* typedef_emxArray_ptrdiff_t */

#ifndef typedef_i_struct_T
#define typedef_i_struct_T
typedef struct {
  real_T x[4];
  real_T lastMV[2];
  emxArray_real_T *ref;
  real_T OutputWeights[40];
  real_T MVWeights[20];
  real_T MVRateWeights[20];
  real_T ECRWeight;
  real_T OutputMin[40];
  real_T OutputMax[40];
  real_T StateMin[40];
  real_T StateMax[40];
  real_T MVMin[20];
  real_T MVMax[20];
  real_T MVRateMin[20];
  real_T MVRateMax[20];
  emxArray_real_T *MVScaledTarget;
  cell_0 Parameters;
} i_struct_T;
#endif /* typedef_i_struct_T */

#ifndef typedef_j_struct_T
#define typedef_j_struct_T
typedef struct {
  real_T Ts;
  real_T CurrentStates[4];
  real_T LastMV[2];
  emxArray_real_T *References;
  emxArray_real_T *MVTarget;
  real_T PredictionHorizon;
  real_T NumOfStates;
  real_T NumOfOutputs;
  real_T NumOfInputs;
  real_T MVIndex[2];
  real_T InputPassivityIndex;
  real_T OutputPassivityIndex;
  boolean_T PassivityUsePredictedX;
} j_struct_T;
#endif /* typedef_j_struct_T */

#ifndef typedef_k_struct_T
#define typedef_k_struct_T
typedef struct {
  i_struct_T runtimedata;
  j_struct_T userdata;
} k_struct_T;
#endif /* typedef_k_struct_T */

#ifndef typedef_anonymous_function
#define typedef_anonymous_function
typedef struct {
  k_struct_T workspace;
} anonymous_function;
#endif /* typedef_anonymous_function */

#ifndef typedef_coder_internal_stickyStruct
#define typedef_coder_internal_stickyStruct
typedef struct {
  anonymous_function value;
} coder_internal_stickyStruct;
#endif /* typedef_coder_internal_stickyStruct */

#ifndef typedef_b_coder_internal_stickyStruct
#define typedef_b_coder_internal_stickyStruct
typedef struct {
  anonymous_function value;
  coder_internal_stickyStruct next;
} b_coder_internal_stickyStruct;
#endif /* typedef_b_coder_internal_stickyStruct */

#ifndef typedef_c_coder_internal_stickyStruct
#define typedef_c_coder_internal_stickyStruct
typedef struct {
  b_coder_internal_stickyStruct next;
} c_coder_internal_stickyStruct;
#endif /* typedef_c_coder_internal_stickyStruct */

#ifndef typedef_d_coder_internal_stickyStruct
#define typedef_d_coder_internal_stickyStruct
typedef struct {
  int32_T value;
  c_coder_internal_stickyStruct next;
} d_coder_internal_stickyStruct;
#endif /* typedef_d_coder_internal_stickyStruct */

#ifndef typedef_e_coder_internal_stickyStruct
#define typedef_e_coder_internal_stickyStruct
typedef struct {
  d_coder_internal_stickyStruct next;
} e_coder_internal_stickyStruct;
#endif /* typedef_e_coder_internal_stickyStruct */

#ifndef typedef_f_coder_internal_stickyStruct
#define typedef_f_coder_internal_stickyStruct
typedef struct {
  e_coder_internal_stickyStruct next;
} f_coder_internal_stickyStruct;
#endif /* typedef_f_coder_internal_stickyStruct */

#ifndef typedef_g_coder_internal_stickyStruct
#define typedef_g_coder_internal_stickyStruct
typedef struct {
  f_coder_internal_stickyStruct next;
} g_coder_internal_stickyStruct;
#endif /* typedef_g_coder_internal_stickyStruct */

#ifndef typedef_h_coder_internal_stickyStruct
#define typedef_h_coder_internal_stickyStruct
typedef struct {
  g_coder_internal_stickyStruct next;
} h_coder_internal_stickyStruct;
#endif /* typedef_h_coder_internal_stickyStruct */

#ifndef typedef_i_coder_internal_stickyStruct
#define typedef_i_coder_internal_stickyStruct
typedef struct {
  h_coder_internal_stickyStruct next;
} i_coder_internal_stickyStruct;
#endif /* typedef_i_coder_internal_stickyStruct */

#ifndef typedef_l_struct_T
#define typedef_l_struct_T
typedef struct {
  anonymous_function objfun;
  anonymous_function nonlin;
  emxArray_real_T *cIneq_1;
  emxArray_real_T *cIneq_2;
  int32_T numEvals;
  boolean_T hasLB[51];
  boolean_T hasUB[51];
} l_struct_T;
#endif /* typedef_l_struct_T */

/* End of code generation (nlmpcmoveCodeGeneration_types.h) */
