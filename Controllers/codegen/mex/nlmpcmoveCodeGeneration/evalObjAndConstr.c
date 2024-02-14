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
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "vehicleDynamics_Simple.h"
#include "znlmpc_objfun.h"
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
  __m128d r;
  __m128d r1;
  emxArray_int32_T *ineqRange;
  emxArray_int8_T *r3;
  emxArray_real_T *c;
  emxArray_real_T *c_c;
  emxArray_real_T *urk;
  real_T X[44];
  real_T b_X[44];
  real_T b_x[40];
  real_T U[22];
  real_T Umv[22];
  real_T b_U[22];
  real_T a[20];
  real_T wtYerr[4];
  real_T duk[2];
  real_T umvk[2];
  real_T b_duk;
  real_T b_wtYerr;
  real_T d;
  real_T fs;
  real_T fval;
  real_T *Cineq_workspace_data;
  real_T *c_data;
  real_T *urk_data;
  int32_T i;
  int32_T icf_tmp;
  int32_T k;
  int32_T loop_ub;
  int32_T n;
  int32_T yk;
  int32_T *ineqRange_data;
  int8_T *r4;
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
    d = Umv[11 * i + 9];
    Umv[11 * i + 10] = d;
    memcpy(&U[i * 11], &Umv[i * 11], 11U * sizeof(real_T));
  }
  fs = 0.0;
  for (icf_tmp = 0; icf_tmp < 11; icf_tmp++) {
    yk = icf_tmp << 2;
    b_X[yk] = X[icf_tmp];
    b_X[yk + 1] = X[icf_tmp + 11];
    b_X[yk + 2] = X[icf_tmp + 22];
    b_X[yk + 3] = X[icf_tmp + 33];
    yk = icf_tmp << 1;
    b_U[yk] = U[icf_tmp];
    b_U[yk + 1] = U[icf_tmp + 11];
  }
  memcpy(&Umv[0], &b_U[0], 22U * sizeof(real_T));
  emxInit_real_T(&urk, 1);
  for (i = 0; i < 10; i++) {
    if (e_obj_next_next_next_next_next_->runtimedata.ref->size[1] == 4) {
      yk = (i + 1) << 2;
      wtYerr[0] =
          e_obj_next_next_next_next_next_->runtimedata.OutputWeights[i] *
          (b_X[yk] - e_obj_next_next_next_next_next_->runtimedata.ref->data[i]);
      wtYerr[1] =
          e_obj_next_next_next_next_next_->runtimedata.OutputWeights[i + 10] *
          (b_X[yk + 1] - e_obj_next_next_next_next_next_->runtimedata.ref
                             ->data[i + e_obj_next_next_next_next_next_
                                            ->runtimedata.ref->size[0]]);
      wtYerr[2] =
          e_obj_next_next_next_next_next_->runtimedata.OutputWeights[i + 20] *
          (b_X[yk + 2] - e_obj_next_next_next_next_next_->runtimedata.ref
                             ->data[i + e_obj_next_next_next_next_next_
                                                ->runtimedata.ref->size[0] *
                                            2]);
      wtYerr[3] =
          e_obj_next_next_next_next_next_->runtimedata.OutputWeights[i + 30] *
          (b_X[yk + 3] - e_obj_next_next_next_next_next_->runtimedata.ref
                             ->data[i + e_obj_next_next_next_next_next_
                                                ->runtimedata.ref->size[0] *
                                            3]);
    } else {
      binary_expand_op_1(wtYerr, e_obj_next_next_next_next_next_, i, b_X);
    }
    d = wtYerr[0];
    b_wtYerr = d * d;
    d = wtYerr[1];
    b_wtYerr += d * d;
    d = wtYerr[2];
    b_wtYerr += d * d;
    d = wtYerr[3];
    b_wtYerr += d * d;
    fs += b_wtYerr;
    yk = i << 1;
    umvk[0] = Umv[yk];
    umvk[1] = Umv[yk + 1];
    if (i + 1 == 1) {
      r = _mm_loadu_pd(&umvk[0]);
      r1 =
          _mm_loadu_pd(&e_obj_next_next_next_next_next_->runtimedata.lastMV[0]);
      _mm_storeu_pd(&duk[0], _mm_sub_pd(r, r1));
    } else {
      r = _mm_loadu_pd(&umvk[0]);
      r1 = _mm_loadu_pd(&Umv[(i - 1) << 1]);
      _mm_storeu_pd(&duk[0], _mm_sub_pd(r, r1));
    }
    loop_ub =
        e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget->size[1];
    if ((e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget->size[0] ==
         0) ||
        (loop_ub == 0)) {
      icf_tmp = urk->size[0];
      urk->size[0] = 2;
      emxEnsureCapacity_real_T(urk, icf_tmp);
      urk_data = urk->data;
      urk_data[0] = 0.0;
      urk_data[1] = 0.0;
    } else {
      icf_tmp = urk->size[0];
      urk->size[0] = loop_ub;
      emxEnsureCapacity_real_T(urk, icf_tmp);
      urk_data = urk->data;
      for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
        urk_data[icf_tmp] =
            e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget
                ->data[i + e_obj_next_next_next_next_next_->runtimedata
                                   .MVScaledTarget->size[0] *
                               icf_tmp];
      }
    }
    if (urk->size[0] == 2) {
      umvk[0] = e_obj_next_next_next_next_next_->runtimedata.MVWeights[i] *
                (umvk[0] - urk_data[0]);
      umvk[1] = e_obj_next_next_next_next_next_->runtimedata.MVWeights[i + 10] *
                (umvk[1] - urk_data[1]);
    } else {
      binary_expand_op(umvk, e_obj_next_next_next_next_next_, i, urk);
    }
    d = umvk[0];
    b_wtYerr = d * d;
    d = duk[0];
    d *= e_obj_next_next_next_next_next_->runtimedata.MVRateWeights[i];
    duk[0] = d;
    b_duk = d * d;
    d = umvk[1];
    b_wtYerr += d * d;
    d = duk[1];
    d *= e_obj_next_next_next_next_next_->runtimedata.MVRateWeights[i + 10];
    duk[1] = d;
    b_duk += d * d;
    fs += b_wtYerr;
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
    int8_T input_sizes_idx_0;
    boolean_T bv[40];
    boolean_T c_x[4];
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
      __m128i r2;
      r2 = _mm_loadu_si128((const __m128i *)&ineqRange_data[icf_tmp]);
      _mm_storeu_si128((__m128i *)&ineqRange_data[icf_tmp],
                       _mm_add_epi32(r2, _mm_set1_epi32(ineq0)));
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
    fs = x[50];
    memcpy(&b_x[0], &x[0], 40U * sizeof(real_T));
    for (icf_tmp = 0; icf_tmp < 4; icf_tmp++) {
      for (n = 0; n < 10; n++) {
        X[(n + 11 * icf_tmp) + 1] = b_x[icf_tmp + (n << 2)];
      }
      X[11 * icf_tmp] = d_obj_next_next_next_next_next_->x[icf_tmp];
    }
    for (i = 0; i < 2; i++) {
      d = Umv[11 * i + 9];
      Umv[11 * i + 10] = d;
      memcpy(&U[i * 11], &Umv[i * 11], 11U * sizeof(real_T));
    }
    memset(&b_x[0], 0, 40U * sizeof(real_T));
    wtYerr[0] = 1.0;
    wtYerr[1] = 2.0;
    wtYerr[2] = 3.0;
    wtYerr[3] = 4.0;
    for (icf_tmp = 0; icf_tmp < 11; icf_tmp++) {
      yk = icf_tmp << 1;
      b_U[yk] = U[icf_tmp];
      b_U[yk + 1] = U[icf_tmp + 11];
    }
    memcpy(&Umv[0], &b_U[0], 22U * sizeof(real_T));
    for (icf_tmp = 0; icf_tmp < 11; icf_tmp++) {
      yk = icf_tmp << 2;
      b_X[yk] = X[icf_tmp];
      b_X[yk + 1] = X[icf_tmp + 11];
      b_X[yk + 2] = X[icf_tmp + 22];
      b_X[yk + 3] = X[icf_tmp + 33];
    }
    for (i = 0; i < 10; i++) {
      real_T b_dv[4];
      vehicleDynamics_Simple(&b_X[i << 2], &Umv[i << 1],
                             d_obj_next_next_next_next_next_->Parameters.f1,
                             d_obj_next_next_next_next_next_->Parameters.f2,
                             b_dv);
      d = wtYerr[0];
      yk = (i + 1) << 2;
      b_x[(int32_T)d - 1] = b_X[yk] - b_dv[0];
      d += 4.0;
      wtYerr[0] = d;
      d = wtYerr[1];
      b_x[(int32_T)d - 1] = b_X[yk + 1] - b_dv[1];
      d += 4.0;
      wtYerr[1] = d;
      d = wtYerr[2];
      b_x[(int32_T)d - 1] = b_X[yk + 2] - b_dv[2];
      d += 4.0;
      wtYerr[2] = d;
      d = wtYerr[3];
      b_x[(int32_T)d - 1] = b_X[yk + 3] - b_dv[3];
      d += 4.0;
      wtYerr[3] = d;
    }
    for (icf_tmp = 0; icf_tmp < 40; icf_tmp++) {
      bv[icf_tmp] = muDoubleScalarIsInf(
          d_obj_next_next_next_next_next_->OutputMin[icf_tmp]);
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
    emxInit_real_T(&c, 2);
    c_data = c->data;
    emxInit_int8_T(&r3, 1);
    guard1 = false;
    if (y) {
      for (icf_tmp = 0; icf_tmp < 40; icf_tmp++) {
        bv[icf_tmp] = muDoubleScalarIsInf(
            d_obj_next_next_next_next_next_->OutputMax[icf_tmp]);
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
      for (i = 0; i < 80; i++) {
        b_c[i] = 0.0;
        icf[i] = true;
      }
      wtYerr[0] = 1.0;
      wtYerr[1] = 2.0;
      wtYerr[2] = 3.0;
      wtYerr[3] = 4.0;
      r = _mm_set1_pd(8.0);
      for (i = 0; i < 10; i++) {
        real_T d1;
        real_T d2;
        real_T d3;
        real_T d4;
        int32_T b_icf_tmp;
        int32_T c_icf_tmp;
        int32_T d_icf_tmp;
        int32_T e_icf_tmp;
        d = d_obj_next_next_next_next_next_->OutputMin[i];
        yk = (int32_T)wtYerr[0] - 1;
        icf[yk] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
        d = d_obj_next_next_next_next_next_->OutputMin[i + 10];
        n = (int32_T)wtYerr[1] - 1;
        icf[n] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
        b_wtYerr = d_obj_next_next_next_next_next_->OutputMin[i + 20];
        loop_ub = (int32_T)wtYerr[2] - 1;
        icf[loop_ub] = ((!muDoubleScalarIsInf(b_wtYerr)) &&
                        (!muDoubleScalarIsNaN(b_wtYerr)));
        d1 = d_obj_next_next_next_next_next_->OutputMin[i + 30];
        icf_tmp = (int32_T)wtYerr[3] - 1;
        icf[icf_tmp] =
            ((!muDoubleScalarIsInf(d1)) && (!muDoubleScalarIsNaN(d1)));
        d2 = d_obj_next_next_next_next_next_->OutputMax[i];
        b_icf_tmp = (int32_T)(wtYerr[0] + 4.0) - 1;
        icf[b_icf_tmp] =
            ((!muDoubleScalarIsInf(d2)) && (!muDoubleScalarIsNaN(d2)));
        d2 = d_obj_next_next_next_next_next_->OutputMax[i + 10];
        c_icf_tmp = (int32_T)(wtYerr[1] + 4.0) - 1;
        icf[c_icf_tmp] =
            ((!muDoubleScalarIsInf(d2)) && (!muDoubleScalarIsNaN(d2)));
        d3 = d_obj_next_next_next_next_next_->OutputMax[i + 20];
        d_icf_tmp = (int32_T)(wtYerr[2] + 4.0) - 1;
        icf[d_icf_tmp] =
            ((!muDoubleScalarIsInf(d3)) && (!muDoubleScalarIsNaN(d3)));
        d4 = d_obj_next_next_next_next_next_->OutputMax[i + 30];
        e_icf_tmp = (int32_T)(wtYerr[3] + 4.0) - 1;
        icf[e_icf_tmp] =
            ((!muDoubleScalarIsInf(d4)) && (!muDoubleScalarIsNaN(d4)));
        y = false;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= 7)) {
          int32_T c_wtYerr[8];
          c_wtYerr[0] = yk;
          c_wtYerr[4] = b_icf_tmp;
          c_wtYerr[1] = n;
          c_wtYerr[5] = c_icf_tmp;
          c_wtYerr[2] = loop_ub;
          c_wtYerr[6] = d_icf_tmp;
          c_wtYerr[3] = icf_tmp;
          c_wtYerr[7] = e_icf_tmp;
          if (icf[c_wtYerr[k]]) {
            y = true;
            exitg1 = true;
          } else {
            k++;
          }
        }
        if (y) {
          real_T b_c_tmp;
          real_T c_tmp;
          c_tmp = X[i + 1];
          b_c[yk] =
              (d_obj_next_next_next_next_next_->OutputMin[i] - fs) - c_tmp;
          b_c_tmp = X[i + 12];
          b_c[n] = (d - fs) - b_c_tmp;
          b_duk = X[i + 23];
          b_c[loop_ub] = (b_wtYerr - fs) - b_duk;
          b_wtYerr = X[i + 34];
          b_c[icf_tmp] = (d1 - fs) - b_wtYerr;
          b_c[b_icf_tmp] =
              (c_tmp - d_obj_next_next_next_next_next_->OutputMax[i]) - fs;
          b_c[c_icf_tmp] = (b_c_tmp - d2) - fs;
          b_c[d_icf_tmp] = (b_duk - d3) - fs;
          b_c[e_icf_tmp] = (b_wtYerr - d4) - fs;
        }
        r1 = _mm_loadu_pd(&wtYerr[0]);
        _mm_storeu_pd(&wtYerr[0], _mm_add_pd(r1, r));
        r1 = _mm_loadu_pd(&wtYerr[2]);
        _mm_storeu_pd(&wtYerr[2], _mm_add_pd(r1, r));
      }
      yk = 0;
      for (i = 0; i < 80; i++) {
        if (icf[i]) {
          yk++;
        }
      }
      icf_tmp = r3->size[0];
      r3->size[0] = yk;
      emxEnsureCapacity_int8_T(r3, icf_tmp);
      r4 = r3->data;
      yk = 0;
      for (i = 0; i < 80; i++) {
        if (icf[i]) {
          r4[yk] = (int8_T)i;
          yk++;
        }
      }
      icf_tmp = urk->size[0];
      urk->size[0] = r3->size[0];
      emxEnsureCapacity_real_T(urk, icf_tmp);
      urk_data = urk->data;
      loop_ub = r3->size[0];
      for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
        urk_data[icf_tmp] = b_c[r4[icf_tmp]];
      }
      icf_tmp = c->size[0] * c->size[1];
      c->size[0] = r3->size[0];
      c->size[1] = 1;
      emxEnsureCapacity_real_T(c, icf_tmp);
      c_data = c->data;
      loop_ub = r3->size[0];
      for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
        c_data[icf_tmp] = urk_data[icf_tmp];
      }
    }
    emxFree_int8_T(&r3);
    y = ((c->size[0] != 0) && (c->size[1] != 0));
    input_sizes_idx_0 = (int8_T)c->size[0];
    emxInit_real_T(&c_c, 2);
    icf_tmp = c_c->size[0] * c_c->size[1];
    c_c->size[0] = input_sizes_idx_0;
    yk = y;
    c_c->size[1] = y;
    emxEnsureCapacity_real_T(c_c, icf_tmp);
    urk_data = c_c->data;
    for (icf_tmp = 0; icf_tmp < yk; icf_tmp++) {
      loop_ub = input_sizes_idx_0;
      for (n = 0; n < loop_ub; n++) {
        urk_data[n] = c_data[n];
      }
    }
    emxFree_real_T(&c);
    loop_ub = ineqRange->size[1];
    for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
      Cineq_workspace_data[ineqRange_data[icf_tmp] - 1] = urk_data[icf_tmp];
    }
    emxFree_real_T(&c_c);
    memcpy(&Ceq_workspace[eq0 + -1], &b_x[0], 40U * sizeof(real_T));
    *status = checkVectorNonFinite(c_obj_next_next_next_next_next_,
                                   Cineq_workspace, ineq0);
    if (*status == 1) {
      *status = b_checkVectorNonFinite(Ceq_workspace, eq0);
    }
  }
  emxFree_real_T(&urk);
  emxFree_int32_T(&ineqRange);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

/* End of code generation (evalObjAndConstr.c) */
