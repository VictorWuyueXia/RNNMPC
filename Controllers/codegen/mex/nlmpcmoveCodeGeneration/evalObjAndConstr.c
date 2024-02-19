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
#include "checkVectorNonFinite.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "vehicleDynamics_Simple.h"
#include "znlmpc_objfun.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T evalObjAndConstr(int32_T c_obj_next_next_next_next_next_,
                        const i_struct_T *d_obj_next_next_next_next_next_,
                        const k_struct_T *e_obj_next_next_next_next_next_,
                        const real_T x[51], emxArray_real_T *Cineq_workspace,
                        int32_T ineq0, real_T Ceq_workspace[40], int32_T eq0,
                        int32_T *status)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emxArray_int32_T *ineqRange;
  emxArray_int8_T *r3;
  emxArray_real_T *b_c;
  emxArray_real_T *c_c;
  emxArray_real_T *wtYerr;
  real_T X[44];
  real_T b_x[40];
  real_T U[22];
  real_T Umv[22];
  real_T b_U[22];
  real_T c[20];
  real_T duk[2];
  real_T umvk[2];
  real_T d;
  real_T f_obj_next_next_next_next_next_;
  real_T fs;
  real_T fval;
  real_T *Cineq_workspace_data;
  real_T *c_data;
  real_T *wtYerr_data;
  int32_T i;
  int32_T loop_ub;
  int32_T n;
  int32_T yk;
  int32_T *ineqRange_data;
  int8_T *r4;
  boolean_T y;
  Cineq_workspace_data = Cineq_workspace->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_int32_T(&ineqRange, 2);
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (i = 0; i < 20; i++) {
    d = 0.0;
    for (n = 0; n < 10; n++) {
      d += (real_T)iv[i + 20 * n] * x[n + 40];
    }
    c[i] = d;
  }
  for (n = 0; n < 2; n++) {
    for (i = 0; i < 10; i++) {
      Umv[i + 11 * n] = c[n + (i << 1)];
    }
    d = Umv[11 * n + 9];
    Umv[11 * n + 10] = d;
    memcpy(&U[n * 11], &Umv[n * 11], 11U * sizeof(real_T));
  }
  fs = 0.0;
  for (i = 0; i < 11; i++) {
    yk = i << 1;
    b_U[yk] = U[i];
    b_U[yk + 1] = U[i + 11];
  }
  memcpy(&Umv[0], &b_U[0], 22U * sizeof(real_T));
  loop_ub = e_obj_next_next_next_next_next_->runtimedata.ref->size[1];
  emxInit_real_T(&wtYerr, 1);
  for (n = 0; n < 10; n++) {
    real_T b_duk;
    f_obj_next_next_next_next_next_ =
        e_obj_next_next_next_next_next_->runtimedata.OutputWeights[n];
    i = wtYerr->size[0];
    wtYerr->size[0] = e_obj_next_next_next_next_next_->runtimedata.ref->size[1];
    emxEnsureCapacity_real_T(wtYerr, i);
    wtYerr_data = wtYerr->data;
    for (i = 0; i < loop_ub; i++) {
      wtYerr_data[i] =
          f_obj_next_next_next_next_next_ *
          (0.0 - e_obj_next_next_next_next_next_->runtimedata.ref
                     ->data[n + e_obj_next_next_next_next_next_->runtimedata
                                        .ref->size[0] *
                                    i]);
    }
    if (wtYerr->size[0] < 1) {
      f_obj_next_next_next_next_next_ = 0.0;
    } else {
      n_t = (ptrdiff_t)wtYerr->size[0];
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      f_obj_next_next_next_next_next_ =
          ddot(&n_t, &wtYerr_data[0], &incx_t, &wtYerr_data[0], &incy_t);
    }
    fs += f_obj_next_next_next_next_next_;
    yk = n << 1;
    umvk[0] = Umv[yk];
    umvk[1] = Umv[yk + 1];
    if (n + 1 == 1) {
      __m128d r;
      __m128d r1;
      r = _mm_loadu_pd(&umvk[0]);
      r1 =
          _mm_loadu_pd(&e_obj_next_next_next_next_next_->runtimedata.lastMV[0]);
      _mm_storeu_pd(&duk[0], _mm_sub_pd(r, r1));
    } else {
      __m128d r;
      __m128d r1;
      r = _mm_loadu_pd(&umvk[0]);
      r1 = _mm_loadu_pd(&Umv[(n - 1) << 1]);
      _mm_storeu_pd(&duk[0], _mm_sub_pd(r, r1));
    }
    if ((e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget->size[0] ==
         0) ||
        (e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget->size[1] ==
         0)) {
      i = wtYerr->size[0];
      wtYerr->size[0] = 2;
      emxEnsureCapacity_real_T(wtYerr, i);
      wtYerr_data = wtYerr->data;
      wtYerr_data[0] = 0.0;
      wtYerr_data[1] = 0.0;
    } else {
      i = wtYerr->size[0];
      wtYerr->size[0] =
          e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget->size[1];
      emxEnsureCapacity_real_T(wtYerr, i);
      wtYerr_data = wtYerr->data;
      yk = e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget->size[1];
      for (i = 0; i < yk; i++) {
        wtYerr_data[i] =
            e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget
                ->data[n + e_obj_next_next_next_next_next_->runtimedata
                                   .MVScaledTarget->size[0] *
                               i];
      }
    }
    if (wtYerr->size[0] == 2) {
      umvk[0] = e_obj_next_next_next_next_next_->runtimedata.MVWeights[n] *
                (umvk[0] - wtYerr_data[0]);
      umvk[1] = e_obj_next_next_next_next_next_->runtimedata.MVWeights[n + 10] *
                (umvk[1] - wtYerr_data[1]);
    } else {
      binary_expand_op(umvk, e_obj_next_next_next_next_next_, n, wtYerr);
    }
    d = umvk[0];
    f_obj_next_next_next_next_next_ = d * d;
    d = duk[0];
    d *= e_obj_next_next_next_next_next_->runtimedata.MVRateWeights[n];
    duk[0] = d;
    b_duk = d * d;
    d = umvk[1];
    f_obj_next_next_next_next_next_ += d * d;
    d = duk[1];
    d *= e_obj_next_next_next_next_next_->runtimedata.MVRateWeights[n + 10];
    duk[1] = d;
    b_duk += d * d;
    fs += f_obj_next_next_next_next_next_;
    fs += b_duk;
  }
  fval = fs +
         e_obj_next_next_next_next_next_->runtimedata.ECRWeight * x[50] * x[50];
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
    int8_T ic_idx_0;
    int8_T ic_idx_1;
    int8_T ic_idx_2;
    int8_T ic_idx_3;
    boolean_T b[10];
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
      for (loop_ub = 2; loop_ub <= n; loop_ub++) {
        yk++;
        ineqRange_data[loop_ub - 1] = yk;
      }
    }
    i = ineqRange->size[1];
    n = ineqRange->size[0] * ineqRange->size[1];
    ineqRange->size[0] = 1;
    emxEnsureCapacity_int32_T(ineqRange, n);
    ineqRange_data = ineqRange->data;
    loop_ub = i - 1;
    yk = (i / 4) << 2;
    n = yk - 4;
    for (i = 0; i <= n; i += 4) {
      __m128i r2;
      r2 = _mm_loadu_si128((const __m128i *)&ineqRange_data[i]);
      _mm_storeu_si128((__m128i *)&ineqRange_data[i],
                       _mm_add_epi32(r2, _mm_set1_epi32(ineq0)));
    }
    for (i = yk; i <= loop_ub; i++) {
      ineqRange_data[i] += ineq0;
    }
    memset(&X[0], 0, 44U * sizeof(real_T));
    memset(&Umv[0], 0, 22U * sizeof(real_T));
    for (i = 0; i < 20; i++) {
      d = 0.0;
      for (n = 0; n < 10; n++) {
        d += (real_T)iv[i + 20 * n] * x[n + 40];
      }
      c[i] = d;
    }
    for (i = 0; i < 2; i++) {
      for (n = 0; n < 10; n++) {
        Umv[n + 11 * i] = c[i + (n << 1)];
      }
    }
    f_obj_next_next_next_next_next_ = x[50];
    memcpy(&b_x[0], &x[0], 40U * sizeof(real_T));
    for (i = 0; i < 4; i++) {
      for (n = 0; n < 10; n++) {
        X[(n + 11 * i) + 1] = b_x[i + (n << 2)];
      }
      X[11 * i] = d_obj_next_next_next_next_next_->x[i];
    }
    for (n = 0; n < 2; n++) {
      d = Umv[11 * n + 9];
      Umv[11 * n + 10] = d;
      memcpy(&U[n * 11], &Umv[n * 11], 11U * sizeof(real_T));
    }
    memset(&b_x[0], 0, 40U * sizeof(real_T));
    ic_idx_0 = 1;
    ic_idx_1 = 2;
    ic_idx_2 = 3;
    ic_idx_3 = 4;
    for (i = 0; i < 11; i++) {
      yk = i << 1;
      b_U[yk] = U[i];
      b_U[yk + 1] = U[i + 11];
    }
    memcpy(&Umv[0], &b_U[0], 22U * sizeof(real_T));
    for (i = 0; i < 11; i++) {
      yk = i << 2;
      b_X[yk] = X[i];
      b_X[yk + 1] = X[i + 11];
      b_X[yk + 2] = X[i + 22];
      b_X[yk + 3] = X[i + 33];
    }
    for (n = 0; n < 10; n++) {
      real_T b_dv[4];
      vehicleDynamics_Simple(&b_X[n << 2], &Umv[n << 1],
                             d_obj_next_next_next_next_next_->Parameters.f1,
                             d_obj_next_next_next_next_next_->Parameters.f2,
                             b_dv);
      yk = (n + 1) << 2;
      b_x[ic_idx_0 - 1] = b_X[yk] - b_dv[0];
      ic_idx_0 = (int8_T)(ic_idx_0 + 4);
      b_x[ic_idx_1 - 1] = b_X[yk + 1] - b_dv[1];
      ic_idx_1 = (int8_T)(ic_idx_1 + 4);
      b_x[ic_idx_2 - 1] = b_X[yk + 2] - b_dv[2];
      ic_idx_2 = (int8_T)(ic_idx_2 + 4);
      b_x[ic_idx_3 - 1] = b_X[yk + 3] - b_dv[3];
      ic_idx_3 = (int8_T)(ic_idx_3 + 4);
      b[n] = muDoubleScalarIsInf(d_obj_next_next_next_next_next_->OutputMin[n]);
    }
    y = true;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= 9)) {
      if (!b[loop_ub]) {
        y = false;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
    emxInit_real_T(&b_c, 2);
    c_data = b_c->data;
    emxInit_int8_T(&r3, 1);
    guard1 = false;
    if (y) {
      for (n = 0; n < 10; n++) {
        b[n] =
            muDoubleScalarIsInf(d_obj_next_next_next_next_next_->OutputMax[n]);
      }
      y = true;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= 9)) {
        if (!b[loop_ub]) {
          y = false;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
      if (y) {
        b_c->size[0] = 0;
        b_c->size[1] = 0;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      boolean_T icf[20];
      for (n = 0; n < 20; n++) {
        c[n] = 0.0;
        icf[n] = true;
      }
      for (n = 0; n < 10; n++) {
        yk = n << 1;
        d = d_obj_next_next_next_next_next_->OutputMin[n];
        icf[yk] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
        d = d_obj_next_next_next_next_next_->OutputMax[n];
        icf[yk + 1] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
        y = false;
        loop_ub = 0;
        exitg1 = false;
        while ((!exitg1) && (loop_ub <= 1)) {
          int8_T ic[2];
          ic[0] = (int8_T)yk;
          ic[1] = (int8_T)(yk + 1);
          if (icf[ic[loop_ub]]) {
            y = true;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
        if (y) {
          c[yk] = d_obj_next_next_next_next_next_->OutputMin[n] -
                  f_obj_next_next_next_next_next_;
          c[yk + 1] = (0.0 - d_obj_next_next_next_next_next_->OutputMax[n]) -
                      f_obj_next_next_next_next_next_;
        }
      }
      yk = 0;
      for (n = 0; n < 20; n++) {
        if (icf[n]) {
          yk++;
        }
      }
      i = r3->size[0];
      r3->size[0] = yk;
      emxEnsureCapacity_int8_T(r3, i);
      r4 = r3->data;
      yk = 0;
      for (n = 0; n < 20; n++) {
        if (icf[n]) {
          r4[yk] = (int8_T)n;
          yk++;
        }
      }
      i = wtYerr->size[0];
      wtYerr->size[0] = r3->size[0];
      emxEnsureCapacity_real_T(wtYerr, i);
      wtYerr_data = wtYerr->data;
      loop_ub = r3->size[0];
      for (i = 0; i < loop_ub; i++) {
        wtYerr_data[i] = c[r4[i]];
      }
      i = b_c->size[0] * b_c->size[1];
      b_c->size[0] = r3->size[0];
      b_c->size[1] = 1;
      emxEnsureCapacity_real_T(b_c, i);
      c_data = b_c->data;
      loop_ub = r3->size[0];
      for (i = 0; i < loop_ub; i++) {
        c_data[i] = wtYerr_data[i];
      }
    }
    emxFree_int8_T(&r3);
    y = ((b_c->size[0] != 0) && (b_c->size[1] != 0));
    ic_idx_0 = (int8_T)b_c->size[0];
    emxInit_real_T(&c_c, 2);
    i = c_c->size[0] * c_c->size[1];
    c_c->size[0] = ic_idx_0;
    yk = y;
    c_c->size[1] = y;
    emxEnsureCapacity_real_T(c_c, i);
    wtYerr_data = c_c->data;
    for (i = 0; i < yk; i++) {
      loop_ub = ic_idx_0;
      for (n = 0; n < loop_ub; n++) {
        wtYerr_data[n] = c_data[n];
      }
    }
    emxFree_real_T(&b_c);
    loop_ub = ineqRange->size[1];
    for (i = 0; i < loop_ub; i++) {
      Cineq_workspace_data[ineqRange_data[i] - 1] = wtYerr_data[i];
    }
    emxFree_real_T(&c_c);
    memcpy(&Ceq_workspace[eq0 + -1], &b_x[0], 40U * sizeof(real_T));
    *status = checkVectorNonFinite(c_obj_next_next_next_next_next_,
                                   Cineq_workspace, ineq0);
    if (*status == 1) {
      *status = b_checkVectorNonFinite(Ceq_workspace, eq0);
    }
  }
  emxFree_real_T(&wtYerr);
  emxFree_int32_T(&ineqRange);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

/* End of code generation (evalObjAndConstr.c) */
