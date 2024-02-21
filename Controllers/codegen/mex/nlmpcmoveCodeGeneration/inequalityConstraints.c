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
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
void inequalityConstraints(const real_T X[44], const real_T U[22], real_T e,
                           real_T data_PredictionHorizon, real_T Ts,
                           const real_T limits[6], emxArray_real_T *constraints)
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  __m128d r3;
  real_T linearAcc[10];
  real_T linearJerk[10];
  real_T steerRate[10];
  real_T turnRadius[10];
  real_T b_y1[9];
  real_T b_work;
  real_T tmp2;
  real_T work;
  real_T *constraints_data;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T m;
  int32_T scalarLB_tmp;
  int32_T vectorUB_tmp;
  /*     %% Make inequality constraints */
  /*  [ieqCon1 */
  /*   ieqCon2-e] <=0 */
  /*  Unpack */
  /*  [speedMAX accMAX jerkMAX brakeMAX turnAngleMAX turnAngleRateMAX] */
  /*  Xs are PredictionHorizon rows and 4 columns */
  /*  The first row is the current X, which cannot be changed */
  /*  Inputs are PredictionHorizon rows and 2 columns */
  /*  The last row is duplicated for the final step */
  /*  [X{speed} XRate{G-force, G-force jerk} input inpuRate ... */
  /*  LaneKeeping obsAvoid}] */
  /*     %% X  */
  /*  [x y yaw speed(v)] */
  if (data_PredictionHorizon + 1.0 < 2.0) {
    i = 0;
    i1 = 0;
    i2 = 0;
    i3 = 0;
    i4 = 0;
    i5 = 0;
  } else {
    i = 1;
    i1 = (int32_T)(data_PredictionHorizon + 1.0);
    i2 = 1;
    i3 = (int32_T)(data_PredictionHorizon + 1.0);
    i4 = 1;
    i5 = (int32_T)(data_PredictionHorizon + 1.0);
  }
  /*  speed */
  /*     %% XRate */
  work = X[22];
  for (m = 0; m < 10; m++) {
    tmp2 = work;
    work = X[m + 23];
    turnRadius[m] = work - tmp2;
  }
  if (i5 - i4 == 10) {
    for (i5 = 0; i5 <= 8; i5 += 2) {
      r = _mm_loadu_pd(&turnRadius[i5]);
      r1 = _mm_loadu_pd(&X[(i4 + i5) + 33]);
      _mm_storeu_pd(
          &turnRadius[i5],
          _mm_div_pd(
              r1, _mm_div_pd(_mm_mul_pd(_mm_set1_pd(0.017453292519943295), r),
                             _mm_set1_pd(Ts))));
    }
  } else {
    binary_expand_op_4(turnRadius, X, i4, i5 - 1, Ts);
  }
  /*  r=v/omega */
  /*  in case yawRate==0 */
  work = X[33];
  for (m = 0; m < 10; m++) {
    if (muDoubleScalarIsNaN(turnRadius[m])) {
      turnRadius[m] = 1000.0;
    }
    tmp2 = work;
    work = X[m + 34];
    linearAcc[m] = work - tmp2;
  }
  for (i4 = 0; i4 <= 8; i4 += 2) {
    r = _mm_loadu_pd(&linearAcc[i4]);
    r1 = _mm_loadu_pd(&turnRadius[i4]);
    _mm_storeu_pd(&turnRadius[i4],
                  _mm_div_pd(_mm_mul_pd(r, _mm_set1_pd(2.0)), r1));
  }
  /*  a=v^2/ */
  /*  totalAcc=(centriAcc.^2 + linearAcc.^2).*0.5; % a=sqrt(al^2+ar^2) */
  work = turnRadius[0];
  for (m = 0; m < 9; m++) {
    tmp2 = work;
    work = turnRadius[m + 1];
    b_y1[m] = work - tmp2;
  }
  /*  G-force */
  /*  G-force jerk */
  /*     %% Input  */
  /*  [acc steer(deg)] */
  /*  linear acc */
  /*  steer */
  /*     %% InputRate */
  work = U[0];
  b_work = U[11];
  for (m = 0; m < 10; m++) {
    tmp2 = work;
    work = U[m + 1];
    linearJerk[m] = work - tmp2;
    tmp2 = b_work;
    b_work = U[m + 12];
    steerRate[m] = b_work - tmp2;
  }
  /*  linear jerk */
  /*  steer rate */
  /*     %% */
  work = limits[0];
  tmp2 = -limits[0];
  m = i1 - i;
  i4 = (m + i3) - i2;
  i5 = constraints->size[0];
  constraints->size[0] = i4 + 122;
  emxEnsureCapacity_real_T(constraints, i5);
  constraints_data = constraints->data;
  scalarLB_tmp = (m / 2) << 1;
  vectorUB_tmp = scalarLB_tmp - 2;
  for (i5 = 0; i5 <= vectorUB_tmp; i5 += 2) {
    r = _mm_loadu_pd(&X[(i + i5) + 33]);
    _mm_storeu_pd(&constraints_data[i5],
                  _mm_sub_pd(_mm_sub_pd(r, _mm_set1_pd(work)), _mm_set1_pd(e)));
  }
  for (i5 = scalarLB_tmp; i5 < m; i5++) {
    constraints_data[i5] = (X[(i + i5) + 33] - work) - e;
  }
  for (i5 = 0; i5 <= vectorUB_tmp; i5 += 2) {
    r = _mm_loadu_pd(&X[(i2 + i5) + 33]);
    _mm_storeu_pd(&constraints_data[(i5 + i1) - i],
                  _mm_sub_pd(_mm_sub_pd(_mm_set1_pd(tmp2), r), _mm_set1_pd(e)));
  }
  for (i5 = scalarLB_tmp; i5 < m; i5++) {
    constraints_data[(i5 + i1) - i] = (tmp2 - X[(i2 + i5) + 33]) - e;
  }
  work = limits[1];
  r = _mm_set1_pd(e);
  for (i5 = 0; i5 <= 8; i5 += 2) {
    r1 = _mm_loadu_pd(&turnRadius[i5]);
    _mm_storeu_pd(&constraints_data[(((i5 + i1) - i) + i3) - i2],
                  _mm_sub_pd(_mm_sub_pd(r1, _mm_set1_pd(work)), r));
    _mm_storeu_pd(&constraints_data[(((i5 + m) + i3) - i2) + 10],
                  _mm_sub_pd(_mm_sub_pd(_mm_set1_pd(-work), r1), r));
  }
  r = _mm_loadu_pd(&b_y1[0]);
  r1 = _mm_set1_pd(e);
  r2 = _mm_set1_pd(limits[2]);
  _mm_storeu_pd(&constraints_data[i4 + 20], _mm_sub_pd(_mm_sub_pd(r, r2), r1));
  r3 = _mm_set1_pd(-limits[2]);
  _mm_storeu_pd(&constraints_data[i4 + 29], _mm_sub_pd(_mm_sub_pd(r3, r), r1));
  r = _mm_loadu_pd(&b_y1[2]);
  _mm_storeu_pd(&constraints_data[i4 + 22], _mm_sub_pd(_mm_sub_pd(r, r2), r1));
  _mm_storeu_pd(&constraints_data[i4 + 31], _mm_sub_pd(_mm_sub_pd(r3, r), r1));
  r = _mm_loadu_pd(&b_y1[4]);
  _mm_storeu_pd(&constraints_data[i4 + 24], _mm_sub_pd(_mm_sub_pd(r, r2), r1));
  _mm_storeu_pd(&constraints_data[i4 + 33], _mm_sub_pd(_mm_sub_pd(r3, r), r1));
  r = _mm_loadu_pd(&b_y1[6]);
  _mm_storeu_pd(&constraints_data[i4 + 26], _mm_sub_pd(_mm_sub_pd(r, r2), r1));
  _mm_storeu_pd(&constraints_data[i4 + 35], _mm_sub_pd(_mm_sub_pd(r3, r), r1));
  work = b_y1[8];
  constraints_data[i4 + 28] = (work - limits[2]) - e;
  constraints_data[i4 + 37] = (-limits[2] - work) - e;
  work = limits[1];
  tmp2 = limits[3];
  for (i = 0; i <= 8; i += 2) {
    r = _mm_loadu_pd(&linearAcc[i]);
    i1 = ((i + m) + i3) - i2;
    _mm_storeu_pd(&constraints_data[i1 + 38], _mm_sub_pd(r, _mm_set1_pd(work)));
    _mm_storeu_pd(&constraints_data[i1 + 48],
                  _mm_sub_pd(_mm_set1_pd(-tmp2), r));
  }
  work = limits[4];
  for (i = 0; i <= 8; i += 2) {
    r = _mm_loadu_pd(&U[i + 11]);
    i1 = ((i + m) + i3) - i2;
    _mm_storeu_pd(&constraints_data[i1 + 58], _mm_sub_pd(r, _mm_set1_pd(work)));
    _mm_storeu_pd(&constraints_data[i1 + 69],
                  _mm_sub_pd(_mm_set1_pd(-work), r));
  }
  work = U[21];
  constraints_data[i4 + 68] = work - limits[4];
  constraints_data[i4 + 79] = -limits[4] - work;
  work = limits[5];
  for (i = 0; i <= 8; i += 2) {
    r = _mm_loadu_pd(&linearJerk[i]);
    i1 = ((i + m) + i3) - i2;
    _mm_storeu_pd(&constraints_data[i1 + 80],
                  _mm_sub_pd(_mm_sub_pd(r, r2), r1));
    _mm_storeu_pd(&constraints_data[i1 + 90],
                  _mm_sub_pd(_mm_sub_pd(r3, r), r1));
    r = _mm_loadu_pd(&steerRate[i]);
    _mm_storeu_pd(&constraints_data[i1 + 100],
                  _mm_sub_pd(_mm_sub_pd(r, _mm_set1_pd(work)), r1));
    _mm_storeu_pd(&constraints_data[i1 + 110],
                  _mm_sub_pd(_mm_sub_pd(_mm_set1_pd(-work), r), r1));
  }
  constraints_data[i4 + 120] = -1.0;
  constraints_data[i4 + 121] = -1.0;
}

/* End of code generation (inequalityConstraints.c) */
