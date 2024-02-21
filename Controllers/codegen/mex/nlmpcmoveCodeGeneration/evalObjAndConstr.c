/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * evalObjAndConstr.c
 *
 * Code generation for function 'evalObjAndConstr'
 *
 */

/* Include files */
#include "evalObjAndConstr.h"
#include "all.h"
#include "checkVectorNonFinite.h"
#include "cosd.h"
#include "inequalityConstraints.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include "tand.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
real_T evalObjAndConstr(int32_T c_obj_next_next_next_next_next_,
                        const i_struct_T *d_obj_next_next_next_next_next_,
                        const j_struct_T *e_obj_next_next_next_next_next_,
                        const k_struct_T *f_obj_next_next_next_next_next_,
                        const real_T x[51], emxArray_real_T *Cineq_workspace,
                        int32_T ineq0, real_T Ceq_workspace[40], int32_T eq0,
                        int32_T *status)
{
  emxArray_int32_T *ineqRange;
  emxArray_int8_T *r1;
  emxArray_real_T *c;
  emxArray_real_T *c_c;
  emxArray_real_T *cu;
  real_T X[44];
  real_T b_x[40];
  real_T U[22];
  real_T Umv[22];
  real_T a[20];
  real_T R_tmp;
  real_T cost_inputs;
  real_T cost_progress;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T fval;
  real_T g_obj_next_next_next_next_next_;
  real_T h_obj_next_next_next_next_next_;
  real_T target_relative_idx_0;
  real_T *Cineq_workspace_data;
  real_T *b_c_data;
  real_T *c_data;
  real_T *cu_data;
  int32_T b_i;
  int32_T i;
  int32_T k;
  int32_T n;
  int32_T *ineqRange_data;
  int8_T *r2;
  boolean_T y;
  Cineq_workspace_data = Cineq_workspace->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_int32_T(&ineqRange, 2);
  memset(&X[0], 0, 44U * sizeof(real_T));
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (i = 0; i < 20; i++) {
    R_tmp = 0.0;
    for (n = 0; n < 10; n++) {
      R_tmp += (real_T)iv[i + 20 * n] * x[n + 40];
    }
    a[i] = R_tmp;
  }
  for (i = 0; i < 2; i++) {
    for (n = 0; n < 10; n++) {
      Umv[n + 11 * i] = a[i + (n << 1)];
    }
  }
  memcpy(&b_x[0], &x[0], 40U * sizeof(real_T));
  for (i = 0; i < 4; i++) {
    for (n = 0; n < 10; n++) {
      X[(n + 11 * i) + 1] = b_x[i + (n << 2)];
    }
    X[11 * i] = f_obj_next_next_next_next_next_->runtimedata.x[i];
  }
  for (b_i = 0; b_i < 2; b_i++) {
    Umv[11 * b_i + 10] = Umv[11 * b_i + 9];
    memcpy(&U[b_i * 11], &Umv[b_i * 11], 11U * sizeof(real_T));
  }
  /*  Unpack */
  /*  weights is fed in as an array of  */
  /*  [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL
   * sofConstraints] */
  cost_progress = 0.0;
  for (b_i = 0; b_i < 11; b_i++) {
    /*  Rotation matrix for transforming to the vehicle's local frame */
    cost_inputs = -X[b_i + 22];
    R_tmp = cost_inputs;
    b_sind(&R_tmp);
    b_cosd(&cost_inputs);
    g_obj_next_next_next_next_next_ =
        f_obj_next_next_next_next_next_->runtimedata.Parameters.f3[0] - X[b_i];
    h_obj_next_next_next_next_next_ =
        f_obj_next_next_next_next_next_->runtimedata.Parameters.f3[3] -
        X[b_i + 11];
    target_relative_idx_0 = cost_inputs * g_obj_next_next_next_next_next_ +
                            -R_tmp * h_obj_next_next_next_next_next_;
    R_tmp = R_tmp * g_obj_next_next_next_next_next_ +
            cost_inputs * h_obj_next_next_next_next_next_;
    cost_progress +=
        (target_relative_idx_0 *
             f_obj_next_next_next_next_next_->runtimedata.Parameters.f4[4] +
         R_tmp *
             f_obj_next_next_next_next_next_->runtimedata.Parameters.f4[5]) *
            target_relative_idx_0 +
        (target_relative_idx_0 *
             f_obj_next_next_next_next_next_->runtimedata.Parameters.f4[6] +
         R_tmp *
             f_obj_next_next_next_next_next_->runtimedata.Parameters.f4[7]) *
            R_tmp;
  }
  /*  quadratic cost for inputs */
  cost_inputs = 0.0;
  R_tmp = f_obj_next_next_next_next_next_->runtimedata.Parameters.f4[0];
  d = f_obj_next_next_next_next_next_->runtimedata.Parameters.f4[1];
  d1 = f_obj_next_next_next_next_next_->runtimedata.Parameters.f4[2];
  d2 = f_obj_next_next_next_next_next_->runtimedata.Parameters.f4[3];
  for (b_i = 0; b_i < 11; b_i++) {
    d3 = U[b_i + 11];
    d4 = U[b_i];
    cost_inputs += (d4 * R_tmp + d3 * d) * d4 + (d4 * d1 + d3 * d2) * d3;
  }
  fval = (cost_progress + cost_inputs) +
         f_obj_next_next_next_next_next_->runtimedata.Parameters.f4[1] * x[50];
  *status = 1;
  y = muDoubleScalarIsNaN(fval);
  if (muDoubleScalarIsInf(fval) || y) {
    if (y) {
      *status = -3;
    } else if (fval < 0.0) {
      *status = -1;
    } else {
      *status = -2;
    }
  }
  if (*status == 1) {
    real_T b_X[44];
    int32_T yk;
    int8_T ic_idx_0;
    int8_T ic_idx_1;
    int8_T ic_idx_2;
    int8_T ic_idx_3;
    boolean_T bv[40];
    boolean_T c_x[4];
    boolean_T exitg1;
    boolean_T guard1;
    if (c_obj_next_next_next_next_next_ - 1 < 0) {
      n = 0;
    } else {
      n = c_obj_next_next_next_next_next_;
    }
    i = ineqRange->size[0] * ineqRange->size[1];
    ineqRange->size[0] = 1;
    ineqRange->size[1] = n;
    emxEnsureCapacity_int32_T(ineqRange, i);
    ineqRange_data = ineqRange->data;
    if (n > 0) {
      ineqRange_data[0] = 0;
      yk = 0;
      for (k = 2; k <= n; k++) {
        yk++;
        ineqRange_data[k - 1] = yk;
      }
    }
    i = ineqRange->size[1];
    n = ineqRange->size[0] * ineqRange->size[1];
    ineqRange->size[0] = 1;
    emxEnsureCapacity_int32_T(ineqRange, n);
    ineqRange_data = ineqRange->data;
    yk = i - 1;
    n = (i / 4) << 2;
    k = n - 4;
    for (i = 0; i <= k; i += 4) {
      __m128i r;
      r = _mm_loadu_si128((const __m128i *)&ineqRange_data[i]);
      _mm_storeu_si128((__m128i *)&ineqRange_data[i],
                       _mm_add_epi32(r, _mm_set1_epi32(ineq0)));
    }
    for (i = n; i <= yk; i++) {
      ineqRange_data[i] += ineq0;
    }
    memset(&X[0], 0, 44U * sizeof(real_T));
    memset(&Umv[0], 0, 22U * sizeof(real_T));
    for (i = 0; i < 20; i++) {
      R_tmp = 0.0;
      for (n = 0; n < 10; n++) {
        R_tmp += (real_T)iv[i + 20 * n] * x[n + 40];
      }
      a[i] = R_tmp;
    }
    for (i = 0; i < 2; i++) {
      for (n = 0; n < 10; n++) {
        Umv[n + 11 * i] = a[i + (n << 1)];
      }
    }
    h_obj_next_next_next_next_next_ = x[50];
    memcpy(&b_x[0], &x[0], 40U * sizeof(real_T));
    for (i = 0; i < 4; i++) {
      for (n = 0; n < 10; n++) {
        X[(n + 11 * i) + 1] = b_x[i + (n << 2)];
      }
      X[11 * i] = d_obj_next_next_next_next_next_->x[i];
    }
    for (b_i = 0; b_i < 2; b_i++) {
      Umv[11 * b_i + 10] = Umv[11 * b_i + 9];
      memcpy(&U[b_i * 11], &Umv[b_i * 11], 11U * sizeof(real_T));
    }
    memset(&b_x[0], 0, 40U * sizeof(real_T));
    ic_idx_0 = 1;
    ic_idx_1 = 2;
    ic_idx_2 = 3;
    ic_idx_3 = 4;
    for (i = 0; i < 11; i++) {
      yk = i << 1;
      Umv[yk] = U[i];
      Umv[yk + 1] = U[i + 11];
    }
    for (i = 0; i < 11; i++) {
      yk = i << 2;
      b_X[yk] = X[i];
      b_X[yk + 1] = X[i + 11];
      b_X[yk + 2] = X[i + 22];
      b_X[yk + 3] = X[i + 33];
    }
    for (b_i = 0; b_i < 10; b_i++) {
      /*  Unpack */
      /*  [x_pos, y_pos, yaw_direction, speed] */
      /*  Vehicle dynamics equations - continuous */
      /*  Euler's method */
      /*  Return the next state */
      i = b_i << 2;
      R_tmp = b_X[i + 2];
      d = R_tmp;
      b_cosd(&d);
      d1 = R_tmp;
      b_sind(&d1);
      n = b_i << 1;
      d2 = Umv[n + 1];
      b_tand(&d2);
      d3 = b_X[i + 3];
      yk = (b_i + 1) << 2;
      b_x[ic_idx_0 - 1] =
          b_X[yk] -
          (b_X[i] + d3 * d * d_obj_next_next_next_next_next_->Parameters.f1);
      ic_idx_0 = (int8_T)(ic_idx_0 + 4);
      b_x[ic_idx_1 - 1] =
          b_X[yk + 1] -
          (b_X[i + 1] +
           d3 * d1 * d_obj_next_next_next_next_next_->Parameters.f1);
      ic_idx_1 = (int8_T)(ic_idx_1 + 4);
      b_x[ic_idx_2 - 1] =
          b_X[yk + 2] -
          (R_tmp + d3 * d2 / d_obj_next_next_next_next_next_->Parameters.f2 *
                       d_obj_next_next_next_next_next_->Parameters.f1);
      ic_idx_2 = (int8_T)(ic_idx_2 + 4);
      b_x[ic_idx_3 - 1] =
          b_X[yk + 3] -
          (d3 + Umv[n] * d_obj_next_next_next_next_next_->Parameters.f1);
      ic_idx_3 = (int8_T)(ic_idx_3 + 4);
    }
    for (i = 0; i < 40; i++) {
      bv[i] =
          muDoubleScalarIsInf(d_obj_next_next_next_next_next_->OutputMin[i]);
    }
    all(bv, c_x);
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 3)) {
      if (!c_x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    emxInit_real_T(&cu, 1);
    emxInit_real_T(&c, 2);
    c_data = c->data;
    emxInit_int8_T(&r1);
    guard1 = false;
    if (y) {
      for (i = 0; i < 40; i++) {
        bv[i] =
            muDoubleScalarIsInf(d_obj_next_next_next_next_next_->OutputMax[i]);
      }
      all(bv, c_x);
      y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= 3)) {
        if (!c_x[k]) {
          y = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (y) {
        c->size[0] = 0;
        c->size[1] = 0;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      real_T b_c[80];
      boolean_T icf[80];
      for (b_i = 0; b_i < 80; b_i++) {
        b_c[b_i] = 0.0;
        icf[b_i] = true;
      }
      ic_idx_0 = 1;
      ic_idx_1 = 2;
      ic_idx_2 = 3;
      ic_idx_3 = 4;
      for (b_i = 0; b_i < 10; b_i++) {
        R_tmp = d_obj_next_next_next_next_next_->OutputMin[b_i];
        icf[ic_idx_0 - 1] =
            ((!muDoubleScalarIsInf(R_tmp)) && (!muDoubleScalarIsNaN(R_tmp)));
        R_tmp = d_obj_next_next_next_next_next_->OutputMin[b_i + 10];
        icf[ic_idx_1 - 1] =
            ((!muDoubleScalarIsInf(R_tmp)) && (!muDoubleScalarIsNaN(R_tmp)));
        d = d_obj_next_next_next_next_next_->OutputMin[b_i + 20];
        icf[ic_idx_2 - 1] =
            ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
        d1 = d_obj_next_next_next_next_next_->OutputMin[b_i + 30];
        icf[ic_idx_3 - 1] =
            ((!muDoubleScalarIsInf(d1)) && (!muDoubleScalarIsNaN(d1)));
        d2 = d_obj_next_next_next_next_next_->OutputMax[b_i];
        icf[ic_idx_0 + 3] =
            ((!muDoubleScalarIsInf(d2)) && (!muDoubleScalarIsNaN(d2)));
        d2 = d_obj_next_next_next_next_next_->OutputMax[b_i + 10];
        icf[ic_idx_1 + 3] =
            ((!muDoubleScalarIsInf(d2)) && (!muDoubleScalarIsNaN(d2)));
        d3 = d_obj_next_next_next_next_next_->OutputMax[b_i + 20];
        icf[ic_idx_2 + 3] =
            ((!muDoubleScalarIsInf(d3)) && (!muDoubleScalarIsNaN(d3)));
        d4 = d_obj_next_next_next_next_next_->OutputMax[b_i + 30];
        icf[ic_idx_3 + 3] =
            ((!muDoubleScalarIsInf(d4)) && (!muDoubleScalarIsNaN(d4)));
        y = false;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= 7)) {
          int16_T ic[8];
          ic[0] = (int16_T)(ic_idx_0 - 1);
          ic[4] = (int16_T)(ic_idx_0 + 3);
          ic[1] = (int16_T)(ic_idx_1 - 1);
          ic[5] = (int16_T)(ic_idx_1 + 3);
          ic[2] = (int16_T)(ic_idx_2 - 1);
          ic[6] = (int16_T)(ic_idx_2 + 3);
          ic[3] = (int16_T)(ic_idx_3 - 1);
          ic[7] = (int16_T)(ic_idx_3 + 3);
          if (icf[ic[k]]) {
            y = true;
            exitg1 = true;
          } else {
            k++;
          }
        }
        if (y) {
          target_relative_idx_0 = X[b_i + 1];
          b_c[ic_idx_0 - 1] = (d_obj_next_next_next_next_next_->OutputMin[b_i] -
                               h_obj_next_next_next_next_next_) -
                              target_relative_idx_0;
          cost_inputs = X[b_i + 12];
          b_c[ic_idx_1 - 1] =
              (R_tmp - h_obj_next_next_next_next_next_) - cost_inputs;
          g_obj_next_next_next_next_next_ = X[b_i + 23];
          b_c[ic_idx_2 - 1] = (d - h_obj_next_next_next_next_next_) -
                              g_obj_next_next_next_next_next_;
          R_tmp = X[b_i + 34];
          b_c[ic_idx_3 - 1] = (d1 - h_obj_next_next_next_next_next_) - R_tmp;
          b_c[ic_idx_0 + 3] =
              (target_relative_idx_0 -
               d_obj_next_next_next_next_next_->OutputMax[b_i]) -
              h_obj_next_next_next_next_next_;
          b_c[ic_idx_1 + 3] =
              (cost_inputs - d2) - h_obj_next_next_next_next_next_;
          b_c[ic_idx_2 + 3] = (g_obj_next_next_next_next_next_ - d3) -
                              h_obj_next_next_next_next_next_;
          b_c[ic_idx_3 + 3] = (R_tmp - d4) - h_obj_next_next_next_next_next_;
        }
        ic_idx_0 = (int8_T)(ic_idx_0 + 8);
        ic_idx_1 = (int8_T)(ic_idx_1 + 8);
        ic_idx_2 = (int8_T)(ic_idx_2 + 8);
        ic_idx_3 = (int8_T)(ic_idx_3 + 8);
      }
      yk = 0;
      for (b_i = 0; b_i < 80; b_i++) {
        if (icf[b_i]) {
          yk++;
        }
      }
      i = r1->size[0];
      r1->size[0] = yk;
      emxEnsureCapacity_int8_T(r1, i);
      r2 = r1->data;
      yk = 0;
      for (b_i = 0; b_i < 80; b_i++) {
        if (icf[b_i]) {
          r2[yk] = (int8_T)b_i;
          yk++;
        }
      }
      i = cu->size[0];
      cu->size[0] = r1->size[0];
      emxEnsureCapacity_real_T(cu, i);
      cu_data = cu->data;
      yk = r1->size[0];
      for (i = 0; i < yk; i++) {
        cu_data[i] = b_c[r2[i]];
      }
      i = c->size[0] * c->size[1];
      c->size[0] = r1->size[0];
      c->size[1] = 1;
      emxEnsureCapacity_real_T(c, i);
      c_data = c->data;
      yk = r1->size[0];
      for (i = 0; i < yk; i++) {
        c_data[i] = cu_data[i];
      }
    }
    emxFree_int8_T(&r1);
    inequalityConstraints(X, U, x[50],
                          e_obj_next_next_next_next_next_->PredictionHorizon,
                          d_obj_next_next_next_next_next_->Parameters.f1,
                          d_obj_next_next_next_next_next_->Parameters.f5, cu);
    cu_data = cu->data;
    if ((c->size[0] != 0) && (c->size[1] != 0)) {
      yk = (int8_T)c->size[0];
    } else {
      yk = 0;
    }
    if (cu->size[0] != 0) {
      n = cu->size[0];
    } else {
      n = 0;
    }
    emxInit_real_T(&c_c, 2);
    i = c_c->size[0] * c_c->size[1];
    c_c->size[0] = yk + n;
    c_c->size[1] = 1;
    emxEnsureCapacity_real_T(c_c, i);
    b_c_data = c_c->data;
    for (i = 0; i < yk; i++) {
      b_c_data[i] = c_data[i];
    }
    emxFree_real_T(&c);
    for (i = 0; i < n; i++) {
      b_c_data[i + yk] = cu_data[i];
    }
    emxFree_real_T(&cu);
    yk = ineqRange->size[1];
    for (i = 0; i < yk; i++) {
      Cineq_workspace_data[ineqRange_data[i] - 1] = b_c_data[i];
    }
    emxFree_real_T(&c_c);
    memcpy(&Ceq_workspace[eq0 + -1], &b_x[0], 40U * sizeof(real_T));
    *status = checkVectorNonFinite(c_obj_next_next_next_next_next_,
                                   Cineq_workspace, ineq0);
    if (*status == 1) {
      *status = b_checkVectorNonFinite(Ceq_workspace, eq0);
    }
  }
  emxFree_int32_T(&ineqRange);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

/* End of code generation (evalObjAndConstr.c) */
