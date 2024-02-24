/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * inequalityConstraints.c
 *
 * Code generation for function 'inequalityConstraints'
 *
 */

/* Include files */
#include "inequalityConstraints.h"
#include "div.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
void inequalityConstraints(const real_T X[44], const real_T U[22], real_T e,
                           real_T data_PredictionHorizon, real_T Ts,
                           const real_T limits[7], emxArray_real_T *constraints)
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  emxArray_real_T *y;
  real_T b_y[10];
  real_T d_y[10];
  real_T turnRadius[10];
  real_T b_y1[9];
  real_T c_y[9];
  real_T b_work;
  real_T tmp2;
  real_T work;
  real_T *constraints_data;
  real_T *y_data;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T loop_ub;
  int32_T m;
  int32_T vectorUB;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&y, 1);
  /*     %% Make inequality constraints */
  /*  [ieqCon1 */
  /*   ieqCon2-e] <=0 */
  /*  Unpack */
  /*  lastMV=data.LastMV; */
  /*  [speedMAX accMAX jerkMAX brakeMAX turnAngleMAX turnAngleRateMAX] */
  /*  Xs are PredictionHorizon rows and 4 columns */
  /*  The first row is the current X, which cannot be changed */
  /*  Inputs are PredictionHorizon rows and 2 columns */
  /*  The last row is duplicated for the final step */
  /*  [X{speed} XRate{G-force, G-force jerk} input inpuRate ... */
  /*  LaneKeeping obsAvoid}] */
  /*     %% State  */
  /*  [x y yaw speed(v)] */
  if (data_PredictionHorizon + 1.0 < 2.0) {
    i = -43;
    i1 = -1;
    i2 = 0;
    i3 = -1;
    i4 = 0;
    i5 = 0;
  } else {
    i = -42;
    i1 = (int32_T)(data_PredictionHorizon + 1.0) - 1;
    i2 = 1;
    i3 = (int32_T)(data_PredictionHorizon + 1.0) - 1;
    i4 = 1;
    i5 = (int32_T)(data_PredictionHorizon + 1.0);
  }
  /*  speed */
  /*     %% StateRate */
  work = X[22];
  for (m = 0; m < 10; m++) {
    tmp2 = work;
    work = X[m + 23];
    b_y[m] = work - tmp2;
  }
  if (i5 - i4 == 10) {
    for (i5 = 0; i5 <= 8; i5 += 2) {
      r = _mm_loadu_pd(&b_y[i5]);
      r1 = _mm_loadu_pd(&X[(i4 + i5) + 33]);
      _mm_storeu_pd(
          &b_y[i5],
          _mm_div_pd(
              r1, _mm_div_pd(_mm_mul_pd(_mm_set1_pd(0.017453292519943295), r),
                             _mm_set1_pd(Ts))));
    }
  } else {
    binary_expand_op_5(b_y, X, i4, i5 - 1, Ts);
  }
  /*  r=v/omega */
  for (m = 0; m < 10; m++) {
    turnRadius[m] = muDoubleScalarAbs(b_y[m]);
    if (muDoubleScalarIsNaN(turnRadius[m])) {
      turnRadius[m] = 1000.0;
    }
  }
  /*  in case yawRate==0 */
  if (data_PredictionHorizon + 1.0 < 2.0) {
    i4 = 0;
    i5 = 0;
  } else {
    i4 = 1;
    i5 = (int32_T)(data_PredictionHorizon + 1.0);
  }
  if (i5 - i4 == 10) {
    for (i5 = 0; i5 <= 8; i5 += 2) {
      r = _mm_loadu_pd(&X[(i4 + i5) + 33]);
      r1 = _mm_loadu_pd(&turnRadius[i5]);
      _mm_storeu_pd(&turnRadius[i5],
                    _mm_div_pd(_mm_mul_pd(r, _mm_set1_pd(2.0)), r1));
    }
  } else {
    binary_expand_op_4(turnRadius, X, i4, i5 - 1);
  }
  /*  a=v^2/r */
  for (m = 0; m < 10; m++) {
    if (muDoubleScalarIsNaN(turnRadius[m])) {
      turnRadius[m] = 0.0;
    }
  }
  /*  in case turnRadius==0 */
  /*  totalAcc=(centriAcc.^2 + linearAcc.^2).*0.5; % a=sqrt(al^2+ar^2) */
  work = turnRadius[0];
  for (m = 0; m < 9; m++) {
    tmp2 = work;
    work = turnRadius[m + 1];
    b_y1[m] = work - tmp2;
  }
  for (m = 0; m < 10; m++) {
    b_y[m] = muDoubleScalarAbs(turnRadius[m]);
  }
  for (m = 0; m < 9; m++) {
    c_y[m] = muDoubleScalarAbs(b_y1[m]);
  }
  /*  G-force */
  /*  G-force jerk */
  /*     %% Input  */
  /*  [acc steer(deg)] */
  if (data_PredictionHorizon < 1.0) {
    i4 = 0;
  } else {
    i4 = (int32_T)data_PredictionHorizon;
  }
  i5 = y->size[0];
  y->size[0] = i4;
  emxEnsureCapacity_real_T(y, i5);
  y_data = y->data;
  for (m = 0; m < i4; m++) {
    y_data[m] = muDoubleScalarAbs(U[m + 11]);
  }
  /*  linear acc */
  /*  steer */
  /*     %% InputRate */
  work = U[0];
  b_work = U[11];
  for (m = 0; m < 10; m++) {
    tmp2 = work;
    work = U[m + 1];
    turnRadius[m] = work - tmp2;
    tmp2 = b_work;
    b_work = U[m + 12];
    d_y[m] = muDoubleScalarAbs(turnRadius[m]);
    turnRadius[m] = muDoubleScalarAbs(b_work - tmp2);
  }
  /*  linear jerk */
  /*  steer rate */
  /*     %% */
  work = limits[0];
  tmp2 = limits[1];
  b_work = limits[5];
  loop_ub = i1 - i;
  i4 = loop_ub + i3;
  i5 = i4 - i2;
  i6 = i5 + y->size[0];
  i7 = constraints->size[0];
  constraints->size[0] = i6 + 22;
  emxEnsureCapacity_real_T(constraints, i7);
  constraints_data = constraints->data;
  m = ((loop_ub - 42) / 2) << 1;
  vectorUB = m - 2;
  for (i7 = 0; i7 <= vectorUB; i7 += 2) {
    r = _mm_loadu_pd(&X[(i + i7) + 76]);
    _mm_storeu_pd(&constraints_data[i7],
                  _mm_sub_pd(_mm_sub_pd(r, _mm_set1_pd(work)), _mm_set1_pd(e)));
  }
  for (i7 = m; i7 <= loop_ub - 43; i7++) {
    constraints_data[i7] = (X[(i + i7) + 76] - work) - e;
  }
  b_loop_ub = i3 - i2;
  m = ((b_loop_ub + 1) / 2) << 1;
  vectorUB = m - 2;
  for (i7 = 0; i7 <= vectorUB; i7 += 2) {
    r = _mm_loadu_pd(&X[(i2 + i7) + 33]);
    _mm_storeu_pd(&constraints_data[((i7 + i1) - i) - 42],
                  _mm_add_pd(_mm_sub_pd(_mm_mul_pd(r, _mm_set1_pd(-1.0)),
                                        _mm_set1_pd(tmp2)),
                             _mm_set1_pd(e)));
  }
  for (i7 = m; i7 <= b_loop_ub; i7++) {
    constraints_data[((i7 + i1) - i) - 42] = (-X[(i2 + i7) + 33] - tmp2) + e;
  }
  for (i7 = 0; i7 <= 8; i7 += 2) {
    r = _mm_loadu_pd(&b_y[i7]);
    _mm_storeu_pd(
        &constraints_data[(((i7 + loop_ub) + i3) - i2) - 41],
        _mm_sub_pd(_mm_sub_pd(r, _mm_set1_pd(limits[2])), _mm_set1_pd(e)));
  }
  r = _mm_loadu_pd(&c_y[0]);
  r1 = _mm_set1_pd(limits[3]);
  r2 = _mm_set1_pd(e);
  _mm_storeu_pd(&constraints_data[i5 - 31], _mm_sub_pd(_mm_sub_pd(r, r1), r2));
  r = _mm_loadu_pd(&c_y[2]);
  _mm_storeu_pd(&constraints_data[i5 - 29], _mm_sub_pd(_mm_sub_pd(r, r1), r2));
  r = _mm_loadu_pd(&c_y[4]);
  _mm_storeu_pd(&constraints_data[i5 - 27], _mm_sub_pd(_mm_sub_pd(r, r1), r2));
  r = _mm_loadu_pd(&c_y[6]);
  _mm_storeu_pd(&constraints_data[i5 - 25], _mm_sub_pd(_mm_sub_pd(r, r1), r2));
  constraints_data[i5 - 23] = (c_y[8] - limits[3]) - e;
  work = limits[2];
  tmp2 = limits[4];
  for (i7 = 0; i7 <= 8; i7 += 2) {
    r = _mm_loadu_pd(&U[i7]);
    m = ((i7 + loop_ub) + i3) - i2;
    _mm_storeu_pd(&constraints_data[m - 22], _mm_sub_pd(r, _mm_set1_pd(work)));
    _mm_storeu_pd(&constraints_data[m - 11], _mm_sub_pd(_mm_set1_pd(-tmp2), r));
  }
  work = U[10];
  constraints_data[i5 - 12] = work - limits[2];
  constraints_data[i5 - 1] = -limits[4] - work;
  b_loop_ub = y->size[0];
  m = (b_loop_ub / 2) << 1;
  vectorUB = m - 2;
  for (i5 = 0; i5 <= vectorUB; i5 += 2) {
    r = _mm_loadu_pd(&y_data[i5]);
    _mm_storeu_pd(&constraints_data[(((i5 + i1) - i) + i3) - i2],
                  _mm_sub_pd(r, _mm_set1_pd(b_work)));
  }
  for (i5 = m; i5 < b_loop_ub; i5++) {
    constraints_data[(((i5 + i1) - i) + i3) - i2] = y_data[i5] - b_work;
  }
  for (i = 0; i <= 8; i += 2) {
    r = _mm_loadu_pd(&d_y[i]);
    _mm_storeu_pd(&constraints_data[(((i + loop_ub) + i3) - i2) + y->size[0]],
                  _mm_sub_pd(_mm_sub_pd(r, r1), r2));
    r = _mm_loadu_pd(&turnRadius[i]);
    _mm_storeu_pd(&constraints_data[(((i + i4) - i2) + y->size[0]) + 10],
                  _mm_sub_pd(_mm_sub_pd(r, _mm_set1_pd(limits[6])), r2));
  }
  constraints_data[i6 + 20] = -1.0;
  constraints_data[i6 + 21] = -1.0;
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (inequalityConstraints.c) */
