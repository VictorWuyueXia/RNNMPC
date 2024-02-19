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
                        const k_struct_T *e_obj_next_next_next_next_next_,
                        const real_T x[51], emxArray_real_T *Cineq_workspace,
                        int32_T ineq0, real_T Ceq_workspace[40], int32_T eq0,
                        int32_T *status)
{
  emxArray_int32_T *ineqRange;
  emxArray_int8_T *r1;
  emxArray_real_T *b_c;
  emxArray_real_T *c;
  emxArray_real_T *d_c;
  real_T X[44];
  real_T b_x[40];
  real_T U[22];
  real_T Umv[22];
  real_T a[20];
  real_T target_relative[2];
  real_T R_tmp;
  real_T cost_inputs;
  real_T cost_progress;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T f_obj_next_next_next_next_next_;
  real_T fval;
  real_T g_obj_next_next_next_next_next_;
  real_T *Cineq_workspace_data;
  real_T *b_c_data;
  real_T *c_data;
  int32_T i;
  int32_T icf_tmp;
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
  for (icf_tmp = 0; icf_tmp < 20; icf_tmp++) {
    d = 0.0;
    for (n = 0; n < 10; n++) {
      d += (real_T)iv[icf_tmp + 20 * n] * x[n + 40];
    }
    a[icf_tmp] = d;
  }
  for (icf_tmp = 0; icf_tmp < 2; icf_tmp++) {
    for (n = 0; n < 10; n++) {
      Umv[n + 11 * icf_tmp] = a[icf_tmp + (n << 1)];
    }
  }
  memcpy(&b_x[0], &x[0], 40U * sizeof(real_T));
  for (icf_tmp = 0; icf_tmp < 4; icf_tmp++) {
    for (n = 0; n < 10; n++) {
      X[(n + 11 * icf_tmp) + 1] = b_x[icf_tmp + (n << 2)];
    }
    X[11 * icf_tmp] = e_obj_next_next_next_next_next_->runtimedata.x[icf_tmp];
  }
  for (i = 0; i < 2; i++) {
    Umv[11 * i + 10] = Umv[11 * i + 9];
    memcpy(&U[i * 11], &Umv[i * 11], 11U * sizeof(real_T));
  }
  /*  weights is fed in as an array of  */
  /*  [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL
   * sofConstraints] */
  cost_progress = 0.0;
  for (i = 0; i < 11; i++) {
    /*  Rotation matrix for transforming to the vehicle's local frame */
    cost_inputs = -X[i + 22];
    R_tmp = cost_inputs;
    b_sind(&R_tmp);
    b_cosd(&cost_inputs);
    g_obj_next_next_next_next_next_ =
        e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[0] - X[i];
    f_obj_next_next_next_next_next_ =
        e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[3] -
        X[i + 11];
    target_relative[0] = cost_inputs * g_obj_next_next_next_next_next_ +
                         -R_tmp * f_obj_next_next_next_next_next_;
    target_relative[1] = R_tmp * g_obj_next_next_next_next_next_ +
                         cost_inputs * f_obj_next_next_next_next_next_;
    d = target_relative[0] *
        e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[4];
    d += target_relative[1] *
         e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[5];
    cost_inputs = d * target_relative[0];
    d = target_relative[0] *
        e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[6];
    d += target_relative[1] *
         e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[7];
    cost_inputs += d * target_relative[1];
    cost_progress += cost_inputs;
  }
  /*  quadratic cost for inputs */
  cost_inputs = 0.0;
  d = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[0];
  d1 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[1];
  f_obj_next_next_next_next_next_ =
      e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[2];
  d2 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[3];
  for (i = 0; i < 11; i++) {
    d3 = U[i + 11];
    R_tmp = U[i];
    cost_inputs += (R_tmp * d + d3 * d1) * R_tmp +
                   (R_tmp * f_obj_next_next_next_next_next_ + d3 * d2) * d3;
  }
  fval = cost_progress + cost_inputs;
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
    int32_T loop_ub;
    int32_T yk;
    int8_T ic_idx_0;
    int8_T ic_idx_1;
    int8_T ic_idx_2;
    int8_T ic_idx_3;
    boolean_T bv[20];
    boolean_T c_x[2];
    boolean_T exitg1;
    boolean_T guard1;
    if (c_obj_next_next_next_next_next_ - 1 < 0) {
      n = 0;
    } else {
      n = c_obj_next_next_next_next_next_;
    }
    icf_tmp = ineqRange->size[0] * ineqRange->size[1];
    ineqRange->size[0] = 1;
    ineqRange->size[1] = n;
    emxEnsureCapacity_int32_T(ineqRange, icf_tmp);
    ineqRange_data = ineqRange->data;
    if (n > 0) {
      ineqRange_data[0] = 0;
      yk = 0;
      for (k = 2; k <= n; k++) {
        yk++;
        ineqRange_data[k - 1] = yk;
      }
    }
    icf_tmp = ineqRange->size[1];
    n = ineqRange->size[0] * ineqRange->size[1];
    ineqRange->size[0] = 1;
    emxEnsureCapacity_int32_T(ineqRange, n);
    ineqRange_data = ineqRange->data;
    loop_ub = icf_tmp - 1;
    yk = (icf_tmp / 4) << 2;
    n = yk - 4;
    for (icf_tmp = 0; icf_tmp <= n; icf_tmp += 4) {
      __m128i r;
      r = _mm_loadu_si128((const __m128i *)&ineqRange_data[icf_tmp]);
      _mm_storeu_si128((__m128i *)&ineqRange_data[icf_tmp],
                       _mm_add_epi32(r, _mm_set1_epi32(ineq0)));
    }
    for (icf_tmp = yk; icf_tmp <= loop_ub; icf_tmp++) {
      ineqRange_data[icf_tmp] += ineq0;
    }
    memset(&X[0], 0, 44U * sizeof(real_T));
    memset(&Umv[0], 0, 22U * sizeof(real_T));
    for (icf_tmp = 0; icf_tmp < 20; icf_tmp++) {
      d = 0.0;
      for (n = 0; n < 10; n++) {
        d += (real_T)iv[icf_tmp + 20 * n] * x[n + 40];
      }
      a[icf_tmp] = d;
    }
    for (icf_tmp = 0; icf_tmp < 2; icf_tmp++) {
      for (n = 0; n < 10; n++) {
        Umv[n + 11 * icf_tmp] = a[icf_tmp + (n << 1)];
      }
    }
    g_obj_next_next_next_next_next_ = x[50];
    memcpy(&b_x[0], &x[0], 40U * sizeof(real_T));
    for (icf_tmp = 0; icf_tmp < 4; icf_tmp++) {
      for (n = 0; n < 10; n++) {
        X[(n + 11 * icf_tmp) + 1] = b_x[icf_tmp + (n << 2)];
      }
      X[11 * icf_tmp] = d_obj_next_next_next_next_next_->x[icf_tmp];
    }
    for (i = 0; i < 2; i++) {
      Umv[11 * i + 10] = Umv[11 * i + 9];
      memcpy(&U[i * 11], &Umv[i * 11], 11U * sizeof(real_T));
    }
    memset(&b_x[0], 0, 40U * sizeof(real_T));
    ic_idx_0 = 1;
    ic_idx_1 = 2;
    ic_idx_2 = 3;
    ic_idx_3 = 4;
    for (icf_tmp = 0; icf_tmp < 11; icf_tmp++) {
      yk = icf_tmp << 1;
      Umv[yk] = U[icf_tmp];
      Umv[yk + 1] = U[icf_tmp + 11];
    }
    for (icf_tmp = 0; icf_tmp < 11; icf_tmp++) {
      yk = icf_tmp << 2;
      b_X[yk] = X[icf_tmp];
      b_X[yk + 1] = X[icf_tmp + 11];
      b_X[yk + 2] = X[icf_tmp + 22];
      b_X[yk + 3] = X[icf_tmp + 33];
    }
    for (i = 0; i < 10; i++) {
      /*  Unpack the state and input */
      /*  [x_pos, y_pos, yaw_direction, speed] */
      /*  Vehicle dynamics equations - continuous */
      /*  Euler's method */
      /*  Return the next state */
      icf_tmp = i << 2;
      d = b_X[icf_tmp + 2];
      d1 = d;
      b_cosd(&d1);
      f_obj_next_next_next_next_next_ = d;
      b_sind(&f_obj_next_next_next_next_next_);
      n = i << 1;
      d2 = Umv[n + 1];
      b_tand(&d2);
      d3 = b_X[icf_tmp + 3];
      yk = (i + 1) << 2;
      b_x[ic_idx_0 - 1] =
          b_X[yk] - (b_X[icf_tmp] +
                     d3 * d1 * d_obj_next_next_next_next_next_->Parameters.f1);
      ic_idx_0 = (int8_T)(ic_idx_0 + 4);
      b_x[ic_idx_1 - 1] =
          b_X[yk + 1] - (b_X[icf_tmp + 1] +
                         d3 * f_obj_next_next_next_next_next_ *
                             d_obj_next_next_next_next_next_->Parameters.f1);
      ic_idx_1 = (int8_T)(ic_idx_1 + 4);
      b_x[ic_idx_2 - 1] =
          b_X[yk + 2] -
          (d + d3 * d2 / d_obj_next_next_next_next_next_->Parameters.f2 *
                   d_obj_next_next_next_next_next_->Parameters.f1);
      ic_idx_2 = (int8_T)(ic_idx_2 + 4);
      b_x[ic_idx_3 - 1] =
          b_X[yk + 3] -
          (d3 + Umv[n] * d_obj_next_next_next_next_next_->Parameters.f1);
      ic_idx_3 = (int8_T)(ic_idx_3 + 4);
    }
    for (icf_tmp = 0; icf_tmp < 20; icf_tmp++) {
      bv[icf_tmp] = muDoubleScalarIsInf(
          d_obj_next_next_next_next_next_->OutputMin[icf_tmp]);
    }
    all(bv, c_x);
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 1)) {
      if (!c_x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    emxInit_real_T(&c, 2);
    c_data = c->data;
    emxInit_int8_T(&r1, 1);
    emxInit_real_T(&b_c, 1);
    guard1 = false;
    if (y) {
      for (icf_tmp = 0; icf_tmp < 20; icf_tmp++) {
        bv[icf_tmp] = muDoubleScalarIsInf(
            d_obj_next_next_next_next_next_->OutputMax[icf_tmp]);
      }
      all(bv, c_x);
      y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= 1)) {
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
      real_T c_c[40];
      boolean_T icf[40];
      for (i = 0; i < 40; i++) {
        c_c[i] = 0.0;
        icf[i] = true;
      }
      target_relative[0] = 1.0;
      target_relative[1] = 2.0;
      for (i = 0; i < 10; i++) {
        __m128d r3;
        d = d_obj_next_next_next_next_next_->OutputMin[i];
        yk = (int32_T)target_relative[0] - 1;
        icf[yk] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
        d = d_obj_next_next_next_next_next_->OutputMin[i + 10];
        n = (int32_T)target_relative[1] - 1;
        icf[n] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
        d1 = d_obj_next_next_next_next_next_->OutputMax[i];
        loop_ub = (int32_T)(target_relative[0] + 2.0) - 1;
        icf[loop_ub] =
            ((!muDoubleScalarIsInf(d1)) && (!muDoubleScalarIsNaN(d1)));
        d1 = d_obj_next_next_next_next_next_->OutputMax[i + 10];
        icf_tmp = (int32_T)(target_relative[1] + 2.0) - 1;
        icf[icf_tmp] =
            ((!muDoubleScalarIsInf(d1)) && (!muDoubleScalarIsNaN(d1)));
        y = false;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= 3)) {
          int32_T b_target_relative[4];
          b_target_relative[0] = yk;
          b_target_relative[2] = loop_ub;
          b_target_relative[1] = n;
          b_target_relative[3] = icf_tmp;
          if (icf[b_target_relative[k]]) {
            y = true;
            exitg1 = true;
          } else {
            k++;
          }
        }
        if (y) {
          cost_inputs = X[i + 1];
          c_c[yk] = (d_obj_next_next_next_next_next_->OutputMin[i] -
                     g_obj_next_next_next_next_next_) -
                    cost_inputs;
          R_tmp = X[i + 12];
          c_c[n] = (d - g_obj_next_next_next_next_next_) - R_tmp;
          c_c[loop_ub] =
              (cost_inputs - d_obj_next_next_next_next_next_->OutputMax[i]) -
              g_obj_next_next_next_next_next_;
          c_c[icf_tmp] = (R_tmp - d1) - g_obj_next_next_next_next_next_;
        }
        r3 = _mm_loadu_pd(&target_relative[0]);
        _mm_storeu_pd(&target_relative[0], _mm_add_pd(r3, _mm_set1_pd(4.0)));
      }
      yk = 0;
      for (i = 0; i < 40; i++) {
        if (icf[i]) {
          yk++;
        }
      }
      icf_tmp = r1->size[0];
      r1->size[0] = yk;
      emxEnsureCapacity_int8_T(r1, icf_tmp);
      r2 = r1->data;
      yk = 0;
      for (i = 0; i < 40; i++) {
        if (icf[i]) {
          r2[yk] = (int8_T)i;
          yk++;
        }
      }
      icf_tmp = b_c->size[0];
      b_c->size[0] = r1->size[0];
      emxEnsureCapacity_real_T(b_c, icf_tmp);
      b_c_data = b_c->data;
      loop_ub = r1->size[0];
      for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
        b_c_data[icf_tmp] = c_c[r2[icf_tmp]];
      }
      icf_tmp = c->size[0] * c->size[1];
      c->size[0] = r1->size[0];
      c->size[1] = 1;
      emxEnsureCapacity_real_T(c, icf_tmp);
      c_data = c->data;
      loop_ub = r1->size[0];
      for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
        c_data[icf_tmp] = b_c_data[icf_tmp];
      }
    }
    emxFree_real_T(&b_c);
    emxFree_int8_T(&r1);
    y = ((c->size[0] != 0) && (c->size[1] != 0));
    ic_idx_0 = (int8_T)c->size[0];
    emxInit_real_T(&d_c, 2);
    icf_tmp = d_c->size[0] * d_c->size[1];
    d_c->size[0] = ic_idx_0;
    yk = y;
    d_c->size[1] = y;
    emxEnsureCapacity_real_T(d_c, icf_tmp);
    b_c_data = d_c->data;
    for (icf_tmp = 0; icf_tmp < yk; icf_tmp++) {
      loop_ub = ic_idx_0;
      for (n = 0; n < loop_ub; n++) {
        b_c_data[n] = c_data[n];
      }
    }
    emxFree_real_T(&c);
    loop_ub = ineqRange->size[1];
    for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
      Cineq_workspace_data[ineqRange_data[icf_tmp] - 1] = b_c_data[icf_tmp];
    }
    emxFree_real_T(&d_c);
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
