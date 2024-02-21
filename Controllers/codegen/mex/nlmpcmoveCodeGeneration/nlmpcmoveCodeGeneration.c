/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nlmpcmoveCodeGeneration.c
 *
 * Code generation for function 'nlmpcmoveCodeGeneration'
 *
 */

/* Include files */
#include "nlmpcmoveCodeGeneration.h"
#include "all.h"
#include "cosd.h"
#include "fmincon.h"
#include "inequalityConstraints.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include "tand.h"
#include "znlmpc_computeJacobianIneq.h"
#include "znlmpc_reformJacobian.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void c_nlmpcmoveCodeGeneration_anonF(
    const real_T runtimedata_x[4], const real_T runtimedata_OutputMin[40],
    const real_T runtimedata_OutputMax[40], real_T runtimedata_Parameters_f1,
    real_T runtimedata_Parameters_f2, const real_T runtimedata_Parameters_f5[6],
    real_T userdata_PredictionHorizon, const real_T z[51],
    emxArray_real_T *varargout_1, real_T varargout_2[40],
    emxArray_real_T *varargout_3, real_T varargout_4[2040])
{
  static const int8_T b_iv[4] = {0, 0, 0, 1};
  __m128d r2;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emxArray_int8_T *r;
  emxArray_real_T *Jc;
  emxArray_real_T *Jcu;
  emxArray_real_T *Ju;
  emxArray_real_T *b_Jx;
  emxArray_real_T *b_c;
  emxArray_real_T *c;
  emxArray_real_T *cu;
  emxArray_real_T *d_Jx;
  emxArray_real_T *f;
  emxArray_real_T *f2;
  real_T c_Jx[3200];
  real_T Jx[1600];
  real_T Jmv[800];
  real_T y[400];
  real_T X[44];
  real_T b_X[44];
  real_T b_z[40];
  real_T U[22];
  real_T Umv[22];
  real_T a[20];
  real_T Ck[16];
  real_T val[16];
  real_T alpha1;
  real_T beta1;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T dx;
  real_T e;
  real_T *Jc_data;
  real_T *Jcu_data;
  real_T *b_c_data;
  real_T *c_data;
  real_T *cu_data;
  real_T *f2_data;
  real_T *f_data;
  int32_T b_i;
  int32_T b_input_sizes_idx_1;
  int32_T i;
  int32_T input_sizes_idx_0;
  int32_T input_sizes_idx_1;
  int32_T j;
  int32_T nf;
  char_T TRANSA1;
  char_T TRANSB1;
  int8_T Je[80];
  int8_T ic[4];
  int8_T i1;
  int8_T i2;
  int8_T i3;
  int8_T i4;
  int8_T *r1;
  boolean_T bv[40];
  boolean_T x[4];
  boolean_T b_y;
  boolean_T empty_non_axis_sizes;
  boolean_T exitg1;
  boolean_T guard1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&cu, 1);
  emxInit_real_T(&f, 1);
  emxInit_real_T(&f2, 1);
  emxInit_real_T(&c, 1);
  memset(&X[0], 0, 44U * sizeof(real_T));
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (i = 0; i < 20; i++) {
    d = 0.0;
    for (nf = 0; nf < 10; nf++) {
      d += (real_T)iv[i + 20 * nf] * z[nf + 40];
    }
    a[i] = d;
  }
  for (i = 0; i < 2; i++) {
    for (nf = 0; nf < 10; nf++) {
      Umv[nf + 11 * i] = a[i + (nf << 1)];
    }
  }
  e = z[50];
  memcpy(&b_z[0], &z[0], 40U * sizeof(real_T));
  for (i = 0; i < 4; i++) {
    for (nf = 0; nf < 10; nf++) {
      X[(nf + 11 * i) + 1] = b_z[i + (nf << 2)];
    }
    X[11 * i] = runtimedata_x[i];
  }
  for (b_i = 0; b_i < 2; b_i++) {
    Umv[11 * b_i + 10] = Umv[11 * b_i + 9];
    memcpy(&U[b_i * 11], &Umv[b_i * 11], 11U * sizeof(real_T));
  }
  memset(&Jx[0], 0, 1600U * sizeof(real_T));
  memset(&Jmv[0], 0, 800U * sizeof(real_T));
  memset(&varargout_2[0], 0, 40U * sizeof(real_T));
  ic[0] = 1;
  ic[1] = 2;
  ic[2] = 3;
  ic[3] = 4;
  for (i = 0; i < 11; i++) {
    input_sizes_idx_1 = i << 1;
    Umv[input_sizes_idx_1] = U[i];
    Umv[input_sizes_idx_1 + 1] = U[i + 11];
  }
  for (i = 0; i < 11; i++) {
    input_sizes_idx_0 = i << 2;
    b_X[input_sizes_idx_0] = X[i];
    b_X[input_sizes_idx_0 + 1] = X[i + 11];
    b_X[input_sizes_idx_0 + 2] = X[i + 22];
    b_X[input_sizes_idx_0 + 3] = X[i + 33];
  }
  for (b_i = 0; b_i < 10; b_i++) {
    real_T b_val[8];
    /*  Unpack */
    /*  [x_pos, y_pos, yaw_direction, speed] */
    /*  Pre-computed J_state expression */
    i = b_i << 2;
    d = b_X[i + 2];
    alpha1 = d;
    b_cosd(&alpha1);
    beta1 = d;
    b_sind(&beta1);
    nf = b_i << 1;
    d1 = Umv[nf + 1];
    dx = d1;
    b_tand(&dx);
    /*  Pre-computed J_input expression */
    /*  Unpack */
    /*  [x_pos, y_pos, yaw_direction, speed] */
    /*  Vehicle dynamics equations - continuous */
    /*  Euler's method */
    /*  Return the next state */
    d2 = d;
    b_cosd(&d2);
    d3 = d;
    b_sind(&d3);
    b_tand(&d1);
    d4 = b_X[i + 3];
    input_sizes_idx_0 = (b_i + 1) << 2;
    i1 = ic[0];
    varargout_2[ic[0] - 1] =
        b_X[input_sizes_idx_0] - (b_X[i] + d4 * d2 * runtimedata_Parameters_f1);
    Jx[(ic[0] + 160 * b_i) - 1] = 1.0;
    i2 = ic[1];
    varargout_2[ic[1] - 1] = b_X[input_sizes_idx_0 + 1] -
                             (b_X[i + 1] + d4 * d3 * runtimedata_Parameters_f1);
    Jx[(ic[1] + 160 * b_i) + 39] = 1.0;
    i3 = ic[2];
    varargout_2[ic[2] - 1] =
        b_X[input_sizes_idx_0 + 2] -
        (d + d4 * d1 / runtimedata_Parameters_f2 * runtimedata_Parameters_f1);
    Jx[(ic[2] + 160 * b_i) + 79] = 1.0;
    i4 = ic[3];
    varargout_2[ic[3] - 1] =
        b_X[input_sizes_idx_0 + 3] - (d4 + Umv[nf] * runtimedata_Parameters_f1);
    Jx[(ic[3] + 160 * b_i) + 119] = 1.0;
    if (b_i + 1 > 1) {
      val[0] = -1.0;
      val[4] = -0.0;
      val[8] = -(-runtimedata_Parameters_f1 * d4 * beta1);
      val[12] = -(runtimedata_Parameters_f1 * alpha1);
      val[1] = -0.0;
      val[5] = -1.0;
      val[9] = -(runtimedata_Parameters_f1 * d4 * alpha1);
      val[13] = -(runtimedata_Parameters_f1 * beta1);
      val[2] = -0.0;
      val[6] = -0.0;
      val[10] = -1.0;
      val[14] = -(runtimedata_Parameters_f1 * dx / runtimedata_Parameters_f2);
      input_sizes_idx_0 = 160 * (b_i - 1);
      for (b_input_sizes_idx_1 = 0; b_input_sizes_idx_1 < 4;
           b_input_sizes_idx_1++) {
        input_sizes_idx_1 = b_input_sizes_idx_1 << 2;
        val[input_sizes_idx_1 + 3] = -(real_T)b_iv[b_input_sizes_idx_1];
        Jx[((i1 + 40 * b_input_sizes_idx_1) + input_sizes_idx_0) - 1] =
            val[input_sizes_idx_1];
        Jx[((i2 + 40 * b_input_sizes_idx_1) + input_sizes_idx_0) - 1] =
            val[input_sizes_idx_1 + 1];
        Jx[((i3 + 40 * b_input_sizes_idx_1) + input_sizes_idx_0) - 1] =
            val[input_sizes_idx_1 + 2];
        Jx[((i4 + 40 * b_input_sizes_idx_1) + input_sizes_idx_0) - 1] =
            val[input_sizes_idx_1 + 3];
      }
    }
    b_val[2] = -(runtimedata_Parameters_f1 * d4 * (dx * dx + 1.0) /
                 runtimedata_Parameters_f2);
    b_val[6] = -0.0;
    b_val[3] = -0.0;
    b_val[7] = -runtimedata_Parameters_f1;
    for (b_input_sizes_idx_1 = 0; b_input_sizes_idx_1 < 2;
         b_input_sizes_idx_1++) {
      input_sizes_idx_1 = b_input_sizes_idx_1 << 2;
      b_val[input_sizes_idx_1] = -0.0;
      b_val[input_sizes_idx_1 + 1] = -0.0;
      Jmv[((i1 + 40 * b_input_sizes_idx_1) + 80 * b_i) - 1] = -0.0;
      Jmv[((i2 + 40 * b_input_sizes_idx_1) + 80 * b_i) - 1] = -0.0;
      Jmv[((i3 + 40 * b_input_sizes_idx_1) + 80 * b_i) - 1] =
          b_val[input_sizes_idx_1 + 2];
      Jmv[((i4 + 40 * b_input_sizes_idx_1) + 80 * b_i) - 1] =
          b_val[input_sizes_idx_1 + 3];
    }
    ic[0] = (int8_T)(ic[0] + 4);
    ic[1] = (int8_T)(ic[1] + 4);
    ic[2] = (int8_T)(ic[2] + 4);
    ic[3] = (int8_T)(ic[3] + 4);
  }
  TRANSB1 = 'N';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)40;
  n_t = (ptrdiff_t)10;
  k_t = (ptrdiff_t)20;
  lda_t = (ptrdiff_t)40;
  ldb_t = (ptrdiff_t)20;
  ldc_t = (ptrdiff_t)40;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &Jmv[0], &lda_t,
        (real_T *)&dv[0], &ldb_t, &beta1, &y[0], &ldc_t);
  for (i = 0; i < 40; i++) {
    bv[i] = muDoubleScalarIsInf(runtimedata_OutputMin[i]);
  }
  all(bv, x);
  b_y = true;
  b_input_sizes_idx_1 = 0;
  exitg1 = false;
  while ((!exitg1) && (b_input_sizes_idx_1 <= 3)) {
    if (!x[b_input_sizes_idx_1]) {
      b_y = false;
      exitg1 = true;
    } else {
      b_input_sizes_idx_1++;
    }
  }
  emxInit_real_T(&b_c, 2);
  c_data = b_c->data;
  emxInit_real_T(&Jc, 2);
  Jc_data = Jc->data;
  emxInit_real_T(&Ju, 3);
  emxInit_int8_T(&r);
  emxInit_real_T(&b_Jx, 3);
  guard1 = false;
  if (b_y) {
    for (i = 0; i < 40; i++) {
      bv[i] = muDoubleScalarIsInf(runtimedata_OutputMax[i]);
    }
    all(bv, x);
    b_y = true;
    b_input_sizes_idx_1 = 0;
    exitg1 = false;
    while ((!exitg1) && (b_input_sizes_idx_1 <= 3)) {
      if (!x[b_input_sizes_idx_1]) {
        b_y = false;
        exitg1 = true;
      } else {
        b_input_sizes_idx_1++;
      }
    }
    if (b_y) {
      b_c->size[0] = 0;
      b_c->size[1] = 0;
      Jc->size[0] = 0;
      Jc->size[1] = 0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1) {
    real_T c_c[80];
    boolean_T icf[80];
    for (b_i = 0; b_i < 80; b_i++) {
      c_c[b_i] = 0.0;
      icf[b_i] = true;
    }
    memset(&c_Jx[0], 0, 3200U * sizeof(real_T));
    memset(&Je[0], 0, 80U * sizeof(int8_T));
    ic[0] = 1;
    ic[1] = 2;
    ic[2] = 3;
    ic[3] = 4;
    for (b_i = 0; b_i < 10; b_i++) {
      d = runtimedata_OutputMin[b_i];
      i1 = ic[0];
      icf[ic[0] - 1] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      d = runtimedata_OutputMin[b_i + 10];
      i2 = ic[1];
      icf[ic[1] - 1] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      d = runtimedata_OutputMin[b_i + 20];
      i3 = ic[2];
      icf[ic[2] - 1] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      d = runtimedata_OutputMin[b_i + 30];
      i4 = ic[3];
      icf[ic[3] - 1] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      d = runtimedata_OutputMax[b_i];
      icf[(int8_T)(ic[0] + 4) - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      d = runtimedata_OutputMax[b_i + 10];
      icf[(int8_T)(ic[1] + 4) - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      d1 = runtimedata_OutputMax[b_i + 20];
      icf[(int8_T)(ic[2] + 4) - 1] =
          ((!muDoubleScalarIsInf(d1)) && (!muDoubleScalarIsNaN(d1)));
      d2 = runtimedata_OutputMax[b_i + 30];
      icf[(int8_T)(ic[3] + 4) - 1] =
          ((!muDoubleScalarIsInf(d2)) && (!muDoubleScalarIsNaN(d2)));
      b_y = false;
      b_input_sizes_idx_1 = 0;
      exitg1 = false;
      while ((!exitg1) && (b_input_sizes_idx_1 <= 7)) {
        int16_T b_ic[8];
        b_ic[0] = (int16_T)(i1 - 1);
        b_ic[4] = (int16_T)(ic[0] + 3);
        b_ic[1] = (int16_T)(i2 - 1);
        b_ic[5] = (int16_T)(ic[1] + 3);
        b_ic[2] = (int16_T)(i3 - 1);
        b_ic[6] = (int16_T)(ic[2] + 3);
        b_ic[3] = (int16_T)(i4 - 1);
        b_ic[7] = (int16_T)(ic[3] + 3);
        if (icf[b_ic[b_input_sizes_idx_1]]) {
          b_y = true;
          exitg1 = true;
        } else {
          b_input_sizes_idx_1++;
        }
      }
      if (b_y) {
        real_T xa[4];
        real_T xk[4];
        d3 = X[b_i + 1];
        xk[0] = d3;
        xa[0] = muDoubleScalarAbs(d3);
        d4 = X[b_i + 12];
        xk[1] = d4;
        xa[1] = muDoubleScalarAbs(d4);
        alpha1 = X[b_i + 23];
        xk[2] = alpha1;
        xa[2] = muDoubleScalarAbs(alpha1);
        beta1 = X[b_i + 34];
        xk[3] = beta1;
        xa[3] = muDoubleScalarAbs(beta1);
        if (xa[0] < 1.0) {
          xa[0] = 1.0;
        }
        if (xa[1] < 1.0) {
          xa[1] = 1.0;
        }
        if (xa[2] < 1.0) {
          xa[2] = 1.0;
        }
        if (xa[3] < 1.0) {
          xa[3] = 1.0;
        }
        for (j = 0; j < 4; j++) {
          dx = 1.0E-6 * xa[j];
          xk[j] += dx;
          input_sizes_idx_0 = j << 2;
          Ck[input_sizes_idx_0] = (xk[0] - d3) / dx;
          Ck[input_sizes_idx_0 + 1] = (xk[1] - d4) / dx;
          Ck[input_sizes_idx_0 + 2] = (xk[2] - alpha1) / dx;
          Ck[input_sizes_idx_0 + 3] = (xk[3] - beta1) / dx;
          xk[j] -= dx;
          c_c[ic[j] - 1] =
              (runtimedata_OutputMin[b_i + 10 * j] - e) - X[(b_i + 11 * j) + 1];
        }
        i1 = ic[0];
        c_c[ic[0] + 3] = (d3 - runtimedata_OutputMax[b_i]) - e;
        i2 = ic[1];
        c_c[ic[1] + 3] = (d4 - d) - e;
        i3 = ic[2];
        c_c[ic[2] + 3] = (alpha1 - d1) - e;
        i4 = ic[3];
        c_c[ic[3] + 3] = (beta1 - d2) - e;
        for (i = 0; i <= 14; i += 2) {
          r2 = _mm_loadu_pd(&Ck[i]);
          _mm_storeu_pd(&val[i], _mm_mul_pd(r2, _mm_set1_pd(-1.0)));
        }
        for (b_input_sizes_idx_1 = 0; b_input_sizes_idx_1 < 4;
             b_input_sizes_idx_1++) {
          input_sizes_idx_0 = b_input_sizes_idx_1 << 2;
          c_Jx[((i1 + 80 * b_input_sizes_idx_1) + 320 * b_i) - 1] =
              val[input_sizes_idx_0];
          c_Jx[((i2 + 80 * b_input_sizes_idx_1) + 320 * b_i) - 1] =
              val[input_sizes_idx_0 + 1];
          c_Jx[((i3 + 80 * b_input_sizes_idx_1) + 320 * b_i) - 1] =
              val[input_sizes_idx_0 + 2];
          c_Jx[((i4 + 80 * b_input_sizes_idx_1) + 320 * b_i) - 1] =
              val[input_sizes_idx_0 + 3];
        }
        for (b_input_sizes_idx_1 = 0; b_input_sizes_idx_1 < 4;
             b_input_sizes_idx_1++) {
          input_sizes_idx_0 = b_input_sizes_idx_1 << 2;
          c_Jx[((ic[0] + 80 * b_input_sizes_idx_1) + 320 * b_i) + 3] =
              Ck[input_sizes_idx_0];
          c_Jx[((ic[1] + 80 * b_input_sizes_idx_1) + 320 * b_i) + 3] =
              Ck[input_sizes_idx_0 + 1];
          c_Jx[((ic[2] + 80 * b_input_sizes_idx_1) + 320 * b_i) + 3] =
              Ck[input_sizes_idx_0 + 2];
          c_Jx[((ic[3] + 80 * b_input_sizes_idx_1) + 320 * b_i) + 3] =
              Ck[input_sizes_idx_0 + 3];
          Je[ic[b_input_sizes_idx_1] - 1] = -1;
        }
        Je[(int8_T)(ic[0] + 4) - 1] = -1;
        Je[(int8_T)(ic[1] + 4) - 1] = -1;
        Je[(int8_T)(ic[2] + 4) - 1] = -1;
        Je[(int8_T)(ic[3] + 4) - 1] = -1;
      }
      ic[0] = (int8_T)(ic[0] + 8);
      ic[1] = (int8_T)(ic[1] + 8);
      ic[2] = (int8_T)(ic[2] + 8);
      ic[3] = (int8_T)(ic[3] + 8);
    }
    input_sizes_idx_0 = 0;
    for (b_i = 0; b_i < 80; b_i++) {
      if (icf[b_i]) {
        input_sizes_idx_0++;
      }
    }
    i = r->size[0];
    r->size[0] = input_sizes_idx_0;
    emxEnsureCapacity_int8_T(r, i);
    r1 = r->data;
    input_sizes_idx_0 = 0;
    for (b_i = 0; b_i < 80; b_i++) {
      if (icf[b_i]) {
        r1[input_sizes_idx_0] = (int8_T)b_i;
        input_sizes_idx_0++;
      }
    }
    i = c->size[0];
    c->size[0] = r->size[0];
    emxEnsureCapacity_real_T(c, i);
    b_c_data = c->data;
    input_sizes_idx_0 = r->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      b_c_data[i] = c_c[r1[i]];
    }
    i = b_c->size[0] * b_c->size[1];
    b_c->size[0] = r->size[0];
    b_c->size[1] = 1;
    emxEnsureCapacity_real_T(b_c, i);
    c_data = b_c->data;
    input_sizes_idx_0 = r->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      c_data[i] = b_c_data[i];
    }
    i = b_Jx->size[0] * b_Jx->size[1] * b_Jx->size[2];
    b_Jx->size[0] = r->size[0];
    b_Jx->size[1] = 4;
    b_Jx->size[2] = 10;
    emxEnsureCapacity_real_T(b_Jx, i);
    Jcu_data = b_Jx->data;
    input_sizes_idx_0 = r->size[0];
    for (i = 0; i < 10; i++) {
      for (nf = 0; nf < 4; nf++) {
        for (input_sizes_idx_1 = 0; input_sizes_idx_1 < input_sizes_idx_0;
             input_sizes_idx_1++) {
          Jcu_data[(input_sizes_idx_1 + b_Jx->size[0] * nf) +
                   b_Jx->size[0] * 4 * i] =
              c_Jx[(r1[input_sizes_idx_1] + 80 * nf) + 320 * i];
        }
      }
    }
    i = Ju->size[0] * Ju->size[1] * Ju->size[2];
    Ju->size[0] = r->size[0];
    Ju->size[1] = 2;
    Ju->size[2] = 10;
    emxEnsureCapacity_real_T(Ju, i);
    f2_data = Ju->data;
    input_sizes_idx_0 = (r->size[0] << 1) * 10;
    for (i = 0; i < input_sizes_idx_0; i++) {
      f2_data[i] = 0.0;
    }
    i = c->size[0];
    c->size[0] = r->size[0];
    emxEnsureCapacity_real_T(c, i);
    b_c_data = c->data;
    input_sizes_idx_0 = r->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      b_c_data[i] = Je[r1[i]];
    }
    znlmpc_reformJacobian(b_Jx, Ju, c, Jc);
    Jc_data = Jc->data;
  }
  emxFree_real_T(&b_Jx);
  emxFree_int8_T(&r);
  inequalityConstraints(X, U, z[50], userdata_PredictionHorizon,
                        runtimedata_Parameters_f1, runtimedata_Parameters_f5,
                        cu);
  cu_data = cu->data;
  emxInit_real_T(&Jcu, 2);
  Jcu_data = Jcu->data;
  if (cu->size[0] == 0) {
    Jcu->size[0] = 0;
    Jcu->size[1] = 0;
  } else {
    __m128d r3;
    nf = cu->size[0] - 1;
    emxInit_real_T(&d_Jx, 3);
    i = d_Jx->size[0] * d_Jx->size[1] * d_Jx->size[2];
    d_Jx->size[0] = cu->size[0];
    d_Jx->size[1] = 4;
    d_Jx->size[2] = 10;
    emxEnsureCapacity_real_T(d_Jx, i);
    Jcu_data = d_Jx->data;
    i = Ju->size[0] * Ju->size[1] * Ju->size[2];
    Ju->size[0] = cu->size[0];
    Ju->size[1] = 2;
    Ju->size[2] = 10;
    emxEnsureCapacity_real_T(Ju, i);
    f2_data = Ju->data;
    input_sizes_idx_0 = (cu->size[0] << 1) * 10;
    for (i = 0; i < input_sizes_idx_0; i++) {
      f2_data[i] = 0.0;
    }
    i = c->size[0];
    c->size[0] = cu->size[0];
    emxEnsureCapacity_real_T(c, i);
    b_c_data = c->data;
    input_sizes_idx_0 = cu->size[0];
    for (i = 0; i < input_sizes_idx_0; i++) {
      b_c_data[i] = 0.0;
    }
    for (b_input_sizes_idx_1 = 0; b_input_sizes_idx_1 < 44;
         b_input_sizes_idx_1++) {
      d = muDoubleScalarAbs(X[b_input_sizes_idx_1]);
      b_X[b_input_sizes_idx_1] = d;
      if (d < 1.0) {
        b_X[b_input_sizes_idx_1] = 1.0;
      }
    }
    for (b_i = 0; b_i < 10; b_i++) {
      for (j = 0; j < 4; j++) {
        dx = 1.0E-6 * b_X[j];
        input_sizes_idx_0 = (b_i + 11 * j) + 1;
        X[input_sizes_idx_0] += dx;
        inequalityConstraints(X, U, e, userdata_PredictionHorizon,
                              runtimedata_Parameters_f1,
                              runtimedata_Parameters_f5, f);
        f_data = f->data;
        X[input_sizes_idx_0] -= dx;
        if (f->size[0] == cu->size[0]) {
          input_sizes_idx_0 = f->size[0];
          input_sizes_idx_1 = (input_sizes_idx_0 / 2) << 1;
          b_input_sizes_idx_1 = input_sizes_idx_1 - 2;
          for (i = 0; i <= b_input_sizes_idx_1; i += 2) {
            r2 = _mm_loadu_pd(&f_data[i]);
            r3 = _mm_loadu_pd(&cu_data[i]);
            _mm_storeu_pd(&f_data[i],
                          _mm_div_pd(_mm_sub_pd(r2, r3), _mm_set1_pd(dx)));
          }
          for (i = input_sizes_idx_1; i < input_sizes_idx_0; i++) {
            f_data[i] = (f_data[i] - cu_data[i]) / dx;
          }
        } else {
          binary_expand_op(f, cu, dx);
          f_data = f->data;
        }
        for (input_sizes_idx_0 = 0; input_sizes_idx_0 <= nf;
             input_sizes_idx_0++) {
          Jcu_data[(input_sizes_idx_0 + d_Jx->size[0] * j) +
                   d_Jx->size[0] * 4 * b_i] = f_data[input_sizes_idx_0];
        }
      }
    }
    for (b_input_sizes_idx_1 = 0; b_input_sizes_idx_1 < 22;
         b_input_sizes_idx_1++) {
      d = muDoubleScalarAbs(U[b_input_sizes_idx_1]);
      Umv[b_input_sizes_idx_1] = d;
      if (d < 1.0) {
        Umv[b_input_sizes_idx_1] = 1.0;
      }
    }
    for (b_i = 0; b_i < 9; b_i++) {
      for (j = 0; j < 2; j++) {
        alpha1 = 1.0E-6 * Umv[j];
        input_sizes_idx_1 = b_i + 11 * j;
        U[input_sizes_idx_1] += alpha1;
        inequalityConstraints(X, U, e, userdata_PredictionHorizon,
                              runtimedata_Parameters_f1,
                              runtimedata_Parameters_f5, f);
        f_data = f->data;
        U[input_sizes_idx_1] -= alpha1;
        if (f->size[0] == cu->size[0]) {
          input_sizes_idx_0 = f->size[0];
          input_sizes_idx_1 = (input_sizes_idx_0 / 2) << 1;
          b_input_sizes_idx_1 = input_sizes_idx_1 - 2;
          for (i = 0; i <= b_input_sizes_idx_1; i += 2) {
            r2 = _mm_loadu_pd(&f_data[i]);
            r3 = _mm_loadu_pd(&cu_data[i]);
            _mm_storeu_pd(&f_data[i],
                          _mm_div_pd(_mm_sub_pd(r2, r3), _mm_set1_pd(alpha1)));
          }
          for (i = input_sizes_idx_1; i < input_sizes_idx_0; i++) {
            f_data[i] = (f_data[i] - cu_data[i]) / alpha1;
          }
        } else {
          binary_expand_op(f, cu, alpha1);
          f_data = f->data;
        }
        for (input_sizes_idx_0 = 0; input_sizes_idx_0 <= nf;
             input_sizes_idx_0++) {
          f2_data[(input_sizes_idx_0 + Ju->size[0] * j) +
                  Ju->size[0] * 2 * b_i] = f_data[input_sizes_idx_0];
        }
      }
    }
    for (j = 0; j < 2; j++) {
      alpha1 = 1.0E-6 * Umv[j];
      input_sizes_idx_1 = 11 * j + 9;
      U[input_sizes_idx_1] += alpha1;
      input_sizes_idx_0 = 11 * j + 10;
      U[input_sizes_idx_0] += alpha1;
      inequalityConstraints(X, U, e, userdata_PredictionHorizon,
                            runtimedata_Parameters_f1,
                            runtimedata_Parameters_f5, f);
      f_data = f->data;
      U[input_sizes_idx_1] -= alpha1;
      U[input_sizes_idx_0] -= alpha1;
      if (f->size[0] == cu->size[0]) {
        input_sizes_idx_0 = f->size[0];
        input_sizes_idx_1 = (input_sizes_idx_0 / 2) << 1;
        b_input_sizes_idx_1 = input_sizes_idx_1 - 2;
        for (i = 0; i <= b_input_sizes_idx_1; i += 2) {
          r2 = _mm_loadu_pd(&f_data[i]);
          r3 = _mm_loadu_pd(&cu_data[i]);
          _mm_storeu_pd(&f_data[i],
                        _mm_div_pd(_mm_sub_pd(r2, r3), _mm_set1_pd(alpha1)));
        }
        for (i = input_sizes_idx_1; i < input_sizes_idx_0; i++) {
          f_data[i] = (f_data[i] - cu_data[i]) / alpha1;
        }
      } else {
        binary_expand_op(f, cu, alpha1);
        f_data = f->data;
      }
      for (input_sizes_idx_0 = 0; input_sizes_idx_0 <= nf;
           input_sizes_idx_0++) {
        f2_data[(input_sizes_idx_0 + Ju->size[0] * j) + Ju->size[0] * 2 * 9] =
            f_data[input_sizes_idx_0];
      }
    }
    alpha1 = muDoubleScalarMax(1.0E-6, muDoubleScalarAbs(z[50])) * 1.0E-6;
    inequalityConstraints(X, U, z[50] + alpha1, userdata_PredictionHorizon,
                          runtimedata_Parameters_f1, runtimedata_Parameters_f5,
                          f);
    f_data = f->data;
    inequalityConstraints(X, U, z[50] - alpha1, userdata_PredictionHorizon,
                          runtimedata_Parameters_f1, runtimedata_Parameters_f5,
                          f2);
    f2_data = f2->data;
    if (f->size[0] == f2->size[0]) {
      d = 2.0 * alpha1;
      input_sizes_idx_0 = cu->size[0];
      input_sizes_idx_1 = (input_sizes_idx_0 / 2) << 1;
      b_input_sizes_idx_1 = input_sizes_idx_1 - 2;
      for (i = 0; i <= b_input_sizes_idx_1; i += 2) {
        r2 = _mm_loadu_pd(&f_data[i]);
        r3 = _mm_loadu_pd(&f2_data[i]);
        _mm_storeu_pd(&b_c_data[i],
                      _mm_div_pd(_mm_sub_pd(r2, r3), _mm_set1_pd(d)));
      }
      for (i = input_sizes_idx_1; i < input_sizes_idx_0; i++) {
        b_c_data[i] = (f_data[i] - f2_data[i]) / d;
      }
    } else {
      binary_expand_op_3(c, cu, f, f2, alpha1);
    }
    znlmpc_reformJacobian(d_Jx, Ju, c, Jcu);
    Jcu_data = Jcu->data;
    emxFree_real_T(&d_Jx);
  }
  emxFree_real_T(&Ju);
  if (cu->size[0] != 0) {
    input_sizes_idx_0 = cu->size[0];
  } else {
    input_sizes_idx_0 = 0;
  }
  if ((b_c->size[0] != 0) && (b_c->size[1] != 0)) {
    input_sizes_idx_1 = (int8_T)b_c->size[0];
  } else {
    input_sizes_idx_1 = 0;
  }
  i = varargout_1->size[0] * varargout_1->size[1];
  varargout_1->size[0] = input_sizes_idx_1 + input_sizes_idx_0;
  varargout_1->size[1] = 1;
  emxEnsureCapacity_real_T(varargout_1, i);
  f2_data = varargout_1->data;
  for (i = 0; i < input_sizes_idx_1; i++) {
    f2_data[i] = c_data[i];
  }
  emxFree_real_T(&b_c);
  for (i = 0; i < input_sizes_idx_0; i++) {
    f2_data[i + input_sizes_idx_1] = cu_data[i];
  }
  b_y = ((Jc->size[0] != 0) && (Jc->size[1] != 0));
  if (b_y) {
    input_sizes_idx_0 = Jc->size[0];
  } else if ((Jcu->size[0] != 0) && (Jcu->size[1] != 0)) {
    input_sizes_idx_0 = Jcu->size[0];
  } else {
    input_sizes_idx_0 = 0;
  }
  empty_non_axis_sizes = (input_sizes_idx_0 == 0);
  if (empty_non_axis_sizes || b_y) {
    input_sizes_idx_1 = Jc->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || ((Jcu->size[0] != 0) && (Jcu->size[1] != 0))) {
    b_input_sizes_idx_1 = Jcu->size[1];
  } else {
    b_input_sizes_idx_1 = 0;
  }
  i = varargout_3->size[0] * varargout_3->size[1];
  varargout_3->size[0] = input_sizes_idx_0;
  varargout_3->size[1] = input_sizes_idx_1 + b_input_sizes_idx_1;
  emxEnsureCapacity_real_T(varargout_3, i);
  f2_data = varargout_3->data;
  for (i = 0; i < input_sizes_idx_1; i++) {
    for (nf = 0; nf < input_sizes_idx_0; nf++) {
      f2_data[nf + varargout_3->size[0] * i] =
          Jc_data[nf + input_sizes_idx_0 * i];
    }
  }
  emxFree_real_T(&Jc);
  for (i = 0; i < b_input_sizes_idx_1; i++) {
    for (nf = 0; nf < input_sizes_idx_0; nf++) {
      f2_data[nf + varargout_3->size[0] * (i + input_sizes_idx_1)] =
          Jcu_data[nf + input_sizes_idx_0 * i];
    }
  }
  emxFree_real_T(&Jcu);
  for (i = 0; i < 40; i++) {
    for (nf = 0; nf < 40; nf++) {
      varargout_4[nf + 51 * i] = Jx[i + 40 * nf];
    }
    for (nf = 0; nf < 10; nf++) {
      varargout_4[(nf + 51 * i) + 40] = y[i + 40 * nf];
    }
    varargout_4[51 * i + 50] = 0.0;
  }
  emxFree_real_T(&c);
  emxFree_real_T(&f2);
  emxFree_real_T(&f);
  emxFree_real_T(&cu);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void nlmpcmoveCodeGeneration(const real_T x[4], const real_T lastMV[2],
                             struct1_T *onlinedata, real_T mv[2],
                             struct2_T *info)
{
  static const int8_T b_a[200] = {
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  static const int8_T varargin_10[40] = {
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  static const int8_T b_iv[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10};
  emxArray_real_T *B;
  emxArray_real_T *b_initX;
  emxArray_real_T *initMV;
  emxArray_real_T *initX;
  emxArray_real_T *ref;
  i_struct_T b_expl_temp;
  i_struct_T d_expl_temp;
  j_struct_T e_expl_temp;
  j_struct_T expl_temp;
  real_T b_dv[51];
  real_T z0[51];
  real_T zUB[51];
  real_T b_x[40];
  real_T Umv[22];
  real_T b_lastMV[20];
  real_T a[10];
  real_T target_relative[2];
  real_T R_tmp;
  real_T R_tmp_tmp;
  real_T b_cost_inputs;
  real_T b_cost_progress;
  real_T c_expl_temp;
  real_T cost_inputs;
  real_T cost_progress;
  real_T d;
  real_T e0;
  real_T onlinedata_idx_0;
  real_T onlinedata_idx_1;
  real_T *b_initX_data;
  real_T *initMV_data;
  real_T *initX_data;
  real_T *ref_data;
  int32_T expl_temp_idx_0;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&ref, 2);
  ref_data = ref->data;
  if (onlinedata->ref->size[0] == 0) {
    i = ref->size[0] * ref->size[1];
    ref->size[0] = 10;
    ref->size[1] = 4;
    emxEnsureCapacity_real_T(ref, i);
    ref_data = ref->data;
    for (i = 0; i < 40; i++) {
      ref_data[i] = 0.0;
    }
  } else if (onlinedata->ref->size[0] == 0) {
    ref->size[0] = 0;
    ref->size[1] = 0;
  } else if (onlinedata->ref->size[0] < 10) {
    expl_temp_idx_0 = 10 - onlinedata->ref->size[0];
    i = ref->size[0] * ref->size[1];
    ref->size[0] = onlinedata->ref->size[0] + expl_temp_idx_0;
    ref->size[1] = 4;
    emxEnsureCapacity_real_T(ref, i);
    ref_data = ref->data;
    loop_ub = onlinedata->ref->size[0];
    for (i = 0; i < 4; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        ref_data[i1 + ref->size[0] * i] =
            onlinedata->ref->data[i1 + onlinedata->ref->size[0] * i];
      }
    }
    for (i = 0; i < 4; i++) {
      for (i1 = 0; i1 < expl_temp_idx_0; i1++) {
        ref_data[(i1 + onlinedata->ref->size[0]) + ref->size[0] * i] =
            onlinedata->ref->data[(onlinedata->ref->size[0] +
                                   onlinedata->ref->size[0] * i) -
                                  1];
      }
    }
  } else {
    i = ref->size[0] * ref->size[1];
    ref->size[0] = onlinedata->ref->size[0];
    ref->size[1] = 4;
    emxEnsureCapacity_real_T(ref, i);
    ref_data = ref->data;
    loop_ub = onlinedata->ref->size[0] << 2;
    for (i = 0; i < loop_ub; i++) {
      ref_data[i] = onlinedata->ref->data[i];
    }
  }
  emxInitStruct_struct_T1(&expl_temp);
  if (onlinedata->MVTarget->size[0] == 0) {
    i = expl_temp.MVTarget->size[0] * expl_temp.MVTarget->size[1];
    expl_temp.MVTarget->size[0] = 10;
    expl_temp.MVTarget->size[1] = 2;
    emxEnsureCapacity_real_T(expl_temp.MVTarget, i);
    for (i = 0; i < 20; i++) {
      expl_temp.MVTarget->data[i] = 0.0;
    }
  } else if (onlinedata->MVTarget->size[0] == 0) {
    expl_temp.MVTarget->size[0] = 0;
    expl_temp.MVTarget->size[1] = 0;
  } else if (onlinedata->MVTarget->size[0] < 10) {
    expl_temp_idx_0 = 10 - onlinedata->MVTarget->size[0];
    i = expl_temp.MVTarget->size[0] * expl_temp.MVTarget->size[1];
    expl_temp.MVTarget->size[0] =
        onlinedata->MVTarget->size[0] + expl_temp_idx_0;
    expl_temp.MVTarget->size[1] = 2;
    emxEnsureCapacity_real_T(expl_temp.MVTarget, i);
    loop_ub = onlinedata->MVTarget->size[0];
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        expl_temp.MVTarget->data[i1 + expl_temp.MVTarget->size[0] * i] =
            onlinedata->MVTarget->data[i1 + onlinedata->MVTarget->size[0] * i];
      }
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < expl_temp_idx_0; i1++) {
        expl_temp.MVTarget->data[(i1 + onlinedata->MVTarget->size[0]) +
                                 expl_temp.MVTarget->size[0] * i] =
            onlinedata->MVTarget->data[(onlinedata->MVTarget->size[0] +
                                        onlinedata->MVTarget->size[0] * i) -
                                       1];
      }
    }
  } else {
    i = expl_temp.MVTarget->size[0] * expl_temp.MVTarget->size[1];
    expl_temp.MVTarget->size[0] = onlinedata->MVTarget->size[0];
    expl_temp.MVTarget->size[1] = 2;
    emxEnsureCapacity_real_T(expl_temp.MVTarget, i);
    loop_ub = onlinedata->MVTarget->size[0] << 1;
    for (i = 0; i < loop_ub; i++) {
      expl_temp.MVTarget->data[i] = onlinedata->MVTarget->data[i];
    }
  }
  emxInitStruct_struct_T(&b_expl_temp);
  i = b_expl_temp.MVScaledTarget->size[0] * b_expl_temp.MVScaledTarget->size[1];
  b_expl_temp.MVScaledTarget->size[0] = expl_temp.MVTarget->size[0];
  b_expl_temp.MVScaledTarget->size[1] = expl_temp.MVTarget->size[1];
  emxEnsureCapacity_real_T(b_expl_temp.MVScaledTarget, i);
  loop_ub = expl_temp.MVTarget->size[0] * expl_temp.MVTarget->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.MVScaledTarget->data[i] = expl_temp.MVTarget->data[i];
  }
  emxInit_real_T(&initX, 2);
  initX_data = initX->data;
  if (onlinedata->X0->size[0] != 0) {
    if (onlinedata->X0->size[0] == 0) {
      initX->size[0] = 0;
      initX->size[1] = 0;
    } else if (onlinedata->X0->size[0] < 10) {
      expl_temp_idx_0 = 10 - onlinedata->X0->size[0];
      i = initX->size[0] * initX->size[1];
      initX->size[0] = onlinedata->X0->size[0] + expl_temp_idx_0;
      initX->size[1] = 4;
      emxEnsureCapacity_real_T(initX, i);
      initX_data = initX->data;
      loop_ub = onlinedata->X0->size[0];
      for (i = 0; i < 4; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          initX_data[i1 + initX->size[0] * i] =
              onlinedata->X0->data[i1 + onlinedata->X0->size[0] * i];
        }
      }
      for (i = 0; i < 4; i++) {
        for (i1 = 0; i1 < expl_temp_idx_0; i1++) {
          initX_data[(i1 + onlinedata->X0->size[0]) + initX->size[0] * i] =
              onlinedata->X0->data[(onlinedata->X0->size[0] +
                                    onlinedata->X0->size[0] * i) -
                                   1];
        }
      }
    } else {
      i = initX->size[0] * initX->size[1];
      initX->size[0] = onlinedata->X0->size[0];
      initX->size[1] = 4;
      emxEnsureCapacity_real_T(initX, i);
      initX_data = initX->data;
      loop_ub = onlinedata->X0->size[0] << 2;
      for (i = 0; i < loop_ub; i++) {
        initX_data[i] = onlinedata->X0->data[i];
      }
    }
  } else {
    for (i = 0; i < 4; i++) {
      b_x[10 * i] = x[i];
      for (i1 = 0; i1 < 9; i1++) {
        b_x[(i1 + 10 * i) + 1] = x[i];
      }
    }
    i = initX->size[0] * initX->size[1];
    initX->size[0] = 10;
    initX->size[1] = 4;
    emxEnsureCapacity_real_T(initX, i);
    initX_data = initX->data;
    for (i = 0; i < 40; i++) {
      initX_data[i] = b_x[i];
    }
  }
  emxInit_real_T(&initMV, 2);
  initMV_data = initMV->data;
  if (onlinedata->MV0->size[0] != 0) {
    if (onlinedata->MV0->size[0] == 0) {
      initMV->size[0] = 0;
      initMV->size[1] = 0;
    } else if (onlinedata->MV0->size[0] < 10) {
      expl_temp_idx_0 = 10 - onlinedata->MV0->size[0];
      i = initMV->size[0] * initMV->size[1];
      initMV->size[0] = onlinedata->MV0->size[0] + expl_temp_idx_0;
      initMV->size[1] = 2;
      emxEnsureCapacity_real_T(initMV, i);
      initMV_data = initMV->data;
      loop_ub = onlinedata->MV0->size[0];
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          initMV_data[i1 + initMV->size[0] * i] =
              onlinedata->MV0->data[i1 + onlinedata->MV0->size[0] * i];
        }
      }
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < expl_temp_idx_0; i1++) {
          initMV_data[(i1 + onlinedata->MV0->size[0]) + initMV->size[0] * i] =
              onlinedata->MV0->data[(onlinedata->MV0->size[0] +
                                     onlinedata->MV0->size[0] * i) -
                                    1];
        }
      }
    } else {
      i = initMV->size[0] * initMV->size[1];
      initMV->size[0] = onlinedata->MV0->size[0];
      initMV->size[1] = 2;
      emxEnsureCapacity_real_T(initMV, i);
      initMV_data = initMV->data;
      loop_ub = onlinedata->MV0->size[0] << 1;
      for (i = 0; i < loop_ub; i++) {
        initMV_data[i] = onlinedata->MV0->data[i];
      }
    }
  } else {
    for (i = 0; i < 2; i++) {
      b_lastMV[10 * i] = lastMV[i];
      for (i1 = 0; i1 < 9; i1++) {
        b_lastMV[(i1 + 10 * i) + 1] = lastMV[i];
      }
    }
    i = initMV->size[0] * initMV->size[1];
    initMV->size[0] = 10;
    initMV->size[1] = 2;
    emxEnsureCapacity_real_T(initMV, i);
    initMV_data = initMV->data;
    for (i = 0; i < 20; i++) {
      initMV_data[i] = b_lastMV[i];
    }
  }
  emxInit_real_T(&b_initX, 2);
  i = b_initX->size[0] * b_initX->size[1];
  b_initX->size[0] = initX->size[1];
  b_initX->size[1] = initX->size[0];
  emxEnsureCapacity_real_T(b_initX, i);
  b_initX_data = b_initX->data;
  loop_ub = initX->size[0];
  for (i = 0; i < loop_ub; i++) {
    expl_temp_idx_0 = initX->size[1];
    for (i1 = 0; i1 < expl_temp_idx_0; i1++) {
      b_initX_data[i1 + b_initX->size[0] * i] =
          initX_data[i + initX->size[0] * i1];
    }
  }
  i = initX->size[0] * initX->size[1];
  initX->size[0] = initMV->size[1];
  initX->size[1] = initMV->size[0];
  emxEnsureCapacity_real_T(initX, i);
  initX_data = initX->data;
  loop_ub = initMV->size[0];
  for (i = 0; i < loop_ub; i++) {
    expl_temp_idx_0 = initMV->size[1];
    for (i1 = 0; i1 < expl_temp_idx_0; i1++) {
      initX_data[i1 + initX->size[0] * i] =
          initMV_data[i + initMV->size[0] * i1];
    }
  }
  emxFree_real_T(&initMV);
  for (i = 0; i < 10; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 20; i1++) {
      d += (real_T)b_a[i + 10 * i1] * initX_data[i1];
    }
    a[i] = d;
  }
  emxFree_real_T(&initX);
  for (i = 0; i < 40; i++) {
    z0[i] = b_initX_data[i];
  }
  emxFree_real_T(&b_initX);
  memcpy(&z0[40], &a[0], 10U * sizeof(real_T));
  z0[50] = onlinedata->Slack0;
  i = expl_temp.References->size[0] * expl_temp.References->size[1];
  expl_temp.References->size[0] = ref->size[0];
  expl_temp.References->size[1] = ref->size[1];
  emxEnsureCapacity_real_T(expl_temp.References, i);
  expl_temp_idx_0 = ref->size[0] * ref->size[1];
  for (i = 0; i < expl_temp_idx_0; i++) {
    expl_temp.References->data[i] = ref_data[i];
  }
  i = b_expl_temp.ref->size[0] * b_expl_temp.ref->size[1];
  b_expl_temp.ref->size[0] = ref->size[0];
  b_expl_temp.ref->size[1] = ref->size[1];
  emxEnsureCapacity_real_T(b_expl_temp.ref, i);
  for (i = 0; i < expl_temp_idx_0; i++) {
    b_expl_temp.ref->data[i] = ref_data[i];
  }
  for (i = 0; i < 20; i++) {
    b_expl_temp.MVRateWeights[i] = 0.1;
  }
  for (i = 0; i < 40; i++) {
    b_expl_temp.OutputMin[i] = rtMinusInf;
    b_expl_temp.OutputMax[i] = rtInf;
    b_expl_temp.StateMin[i] = rtMinusInf;
    b_expl_temp.StateMax[i] = rtInf;
  }
  for (i = 0; i < 20; i++) {
    b_expl_temp.MVMin[i] = rtMinusInf;
    b_expl_temp.MVMax[i] = rtInf;
    b_expl_temp.MVRateMin[i] = rtMinusInf;
    b_expl_temp.MVRateMax[i] = rtInf;
  }
  for (i = 0; i < 40; i++) {
    zUB[i] = rtInf;
  }
  for (i = 0; i < 10; i++) {
    zUB[i + 40] = rtInf;
  }
  zUB[50] = rtInf;
  memset(&info->Xopt[0], 0, 44U * sizeof(real_T));
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (i = 0; i < 20; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 10; i1++) {
      d += (real_T)iv[i + 20 * i1] * z0[i1 + 40];
    }
    b_lastMV[i] = d;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 10; i1++) {
      Umv[i1 + 11 * i] = b_lastMV[i + (i1 << 1)];
    }
  }
  memcpy(&b_x[0], &z0[0], 40U * sizeof(real_T));
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < 10; i1++) {
      info->Xopt[(i1 + 11 * i) + 1] = b_x[i + (i1 << 2)];
    }
    info->Xopt[11 * i] = x[i];
  }
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 2; expl_temp_idx_0++) {
    Umv[11 * expl_temp_idx_0 + 10] = Umv[11 * expl_temp_idx_0 + 9];
    memcpy(&info->MVopt[expl_temp_idx_0 * 11], &Umv[expl_temp_idx_0 * 11],
           11U * sizeof(real_T));
  }
  e0 = z0[50];
  if (z0[50] <= 0.0) {
    e0 = 1.0E-5;
  }
  /*  Unpack */
  /*  weights is fed in as an array of  */
  /*  [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL
   * sofConstraints] */
  cost_progress = 0.0;
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 11; expl_temp_idx_0++) {
    /*  Rotation matrix for transforming to the vehicle's local frame */
    R_tmp_tmp = -info->Xopt[expl_temp_idx_0 + 22];
    R_tmp = R_tmp_tmp;
    b_sind(&R_tmp);
    b_cosd(&R_tmp_tmp);
    onlinedata_idx_0 =
        onlinedata->Parameters.f3[0] - info->Xopt[expl_temp_idx_0];
    onlinedata_idx_1 =
        onlinedata->Parameters.f3[3] - info->Xopt[expl_temp_idx_0 + 11];
    target_relative[0] =
        R_tmp_tmp * onlinedata_idx_0 + -R_tmp * onlinedata_idx_1;
    target_relative[1] =
        R_tmp * onlinedata_idx_0 + R_tmp_tmp * onlinedata_idx_1;
    d = target_relative[0] * onlinedata->Parameters.f4[4];
    d += target_relative[1] * onlinedata->Parameters.f4[5];
    R_tmp_tmp = d * target_relative[0];
    d = target_relative[0] * onlinedata->Parameters.f4[6];
    d += target_relative[1] * onlinedata->Parameters.f4[7];
    R_tmp_tmp += d * target_relative[1];
    cost_progress += R_tmp_tmp;
  }
  /*  quadratic cost for inputs */
  cost_inputs = 0.0;
  d = onlinedata->Parameters.f4[0];
  c_expl_temp = onlinedata->Parameters.f4[1];
  R_tmp_tmp = onlinedata->Parameters.f4[2];
  R_tmp = onlinedata->Parameters.f4[3];
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 11; expl_temp_idx_0++) {
    onlinedata_idx_0 = info->MVopt[expl_temp_idx_0 + 11];
    onlinedata_idx_1 = info->MVopt[expl_temp_idx_0];
    cost_inputs += (onlinedata_idx_1 * d + onlinedata_idx_0 * c_expl_temp) *
                       onlinedata_idx_1 +
                   (onlinedata_idx_1 * R_tmp_tmp + onlinedata_idx_0 * R_tmp) *
                       onlinedata_idx_0;
  }
  /*  Unpack */
  /*  weights is fed in as an array of  */
  /*  [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL
   * sofConstraints] */
  b_cost_progress = 0.0;
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 11; expl_temp_idx_0++) {
    /*  Rotation matrix for transforming to the vehicle's local frame */
    R_tmp_tmp = -info->Xopt[expl_temp_idx_0 + 22];
    R_tmp = R_tmp_tmp;
    b_sind(&R_tmp);
    b_cosd(&R_tmp_tmp);
    onlinedata_idx_0 =
        onlinedata->Parameters.f3[0] - info->Xopt[expl_temp_idx_0];
    onlinedata_idx_1 =
        onlinedata->Parameters.f3[3] - info->Xopt[expl_temp_idx_0 + 11];
    target_relative[0] =
        R_tmp_tmp * onlinedata_idx_0 + -R_tmp * onlinedata_idx_1;
    target_relative[1] =
        R_tmp * onlinedata_idx_0 + R_tmp_tmp * onlinedata_idx_1;
    d = target_relative[0] * onlinedata->Parameters.f4[4];
    d += target_relative[1] * onlinedata->Parameters.f4[5];
    R_tmp_tmp = d * target_relative[0];
    d = target_relative[0] * onlinedata->Parameters.f4[6];
    d += target_relative[1] * onlinedata->Parameters.f4[7];
    R_tmp_tmp += d * target_relative[1];
    b_cost_progress += R_tmp_tmp;
  }
  /*  quadratic cost for inputs */
  b_cost_inputs = 0.0;
  d = onlinedata->Parameters.f4[0];
  c_expl_temp = onlinedata->Parameters.f4[1];
  R_tmp_tmp = onlinedata->Parameters.f4[2];
  R_tmp = onlinedata->Parameters.f4[3];
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 11; expl_temp_idx_0++) {
    onlinedata_idx_0 = info->MVopt[expl_temp_idx_0 + 11];
    onlinedata_idx_1 = info->MVopt[expl_temp_idx_0];
    b_cost_inputs += (onlinedata_idx_1 * d + onlinedata_idx_0 * c_expl_temp) *
                         onlinedata_idx_1 +
                     (onlinedata_idx_1 * R_tmp_tmp + onlinedata_idx_0 * R_tmp) *
                         onlinedata_idx_0;
  }
  if ((cost_progress + cost_inputs) +
          (e0 + 0.1) * onlinedata->Parameters.f4[1] <=
      (b_cost_progress + b_cost_inputs) + e0 * onlinedata->Parameters.f4[1]) {
    zUB[50] = 0.0;
  }
  target_relative[0] = 1.0;
  target_relative[1] = 2.0;
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 10; expl_temp_idx_0++) {
    __m128d r;
    r = _mm_loadu_pd(&target_relative[0]);
    _mm_storeu_pd(&target_relative[0], _mm_add_pd(r, _mm_set1_pd(8.0)));
  }
  emxInit_real_T(&B, 1);
  B->size[0] = 0;
  ref->size[0] = 0;
  ref->size[1] = 61;
  b_expl_temp.Parameters = onlinedata->Parameters;
  b_expl_temp.ECRWeight = 100000.0;
  memset(&b_expl_temp.MVWeights[0], 0, 20U * sizeof(real_T));
  for (i = 0; i < 40; i++) {
    b_expl_temp.OutputWeights[i] = varargin_10[i];
  }
  b_expl_temp.lastMV[0] = lastMV[0];
  b_expl_temp.lastMV[1] = lastMV[1];
  b_expl_temp.x[0] = x[0];
  b_expl_temp.x[1] = x[1];
  b_expl_temp.x[2] = x[2];
  b_expl_temp.x[3] = x[3];
  expl_temp.PassivityUsePredictedX = true;
  expl_temp.OutputPassivityIndex = 0.1;
  expl_temp.InputPassivityIndex = 0.0;
  expl_temp.NumOfInputs = 2.0;
  expl_temp.NumOfOutputs = 4.0;
  expl_temp.NumOfStates = 4.0;
  expl_temp.PredictionHorizon = 10.0;
  expl_temp.MVIndex[0] = 1.0;
  expl_temp.LastMV[0] = lastMV[0];
  expl_temp.MVIndex[1] = 2.0;
  expl_temp.LastMV[1] = lastMV[1];
  expl_temp.CurrentStates[0] = x[0];
  expl_temp.CurrentStates[1] = x[1];
  expl_temp.CurrentStates[2] = x[2];
  expl_temp.CurrentStates[3] = x[3];
  expl_temp.Ts = 0.1;
  emxInitStruct_struct_T(&d_expl_temp);
  d_expl_temp.Parameters = onlinedata->Parameters;
  i = d_expl_temp.MVScaledTarget->size[0] * d_expl_temp.MVScaledTarget->size[1];
  d_expl_temp.MVScaledTarget->size[0] = b_expl_temp.MVScaledTarget->size[0];
  d_expl_temp.MVScaledTarget->size[1] = b_expl_temp.MVScaledTarget->size[1];
  emxEnsureCapacity_real_T(d_expl_temp.MVScaledTarget, i);
  loop_ub =
      b_expl_temp.MVScaledTarget->size[0] * b_expl_temp.MVScaledTarget->size[1];
  for (i = 0; i < loop_ub; i++) {
    d_expl_temp.MVScaledTarget->data[i] = b_expl_temp.MVScaledTarget->data[i];
  }
  for (i = 0; i < 20; i++) {
    d_expl_temp.MVRateMax[i] = rtInf;
    d_expl_temp.MVRateMin[i] = rtMinusInf;
    d_expl_temp.MVMax[i] = rtInf;
    d_expl_temp.MVMin[i] = rtMinusInf;
  }
  for (i = 0; i < 40; i++) {
    d_expl_temp.StateMax[i] = rtInf;
    d_expl_temp.StateMin[i] = rtMinusInf;
    d_expl_temp.OutputMax[i] = rtInf;
    d_expl_temp.OutputMin[i] = rtMinusInf;
  }
  d_expl_temp.ECRWeight = 100000.0;
  for (i = 0; i < 20; i++) {
    d_expl_temp.MVRateWeights[i] = 0.1;
    d_expl_temp.MVWeights[i] = 0.0;
  }
  for (i = 0; i < 40; i++) {
    d_expl_temp.OutputWeights[i] = varargin_10[i];
  }
  i = d_expl_temp.ref->size[0] * d_expl_temp.ref->size[1];
  d_expl_temp.ref->size[0] = b_expl_temp.ref->size[0];
  d_expl_temp.ref->size[1] = b_expl_temp.ref->size[1];
  emxEnsureCapacity_real_T(d_expl_temp.ref, i);
  loop_ub = b_expl_temp.ref->size[0] * b_expl_temp.ref->size[1];
  for (i = 0; i < loop_ub; i++) {
    d_expl_temp.ref->data[i] = b_expl_temp.ref->data[i];
  }
  d_expl_temp.lastMV[0] = lastMV[0];
  d_expl_temp.lastMV[1] = lastMV[1];
  d_expl_temp.x[0] = x[0];
  d_expl_temp.x[1] = x[1];
  d_expl_temp.x[2] = x[2];
  d_expl_temp.x[3] = x[3];
  emxInitStruct_struct_T1(&e_expl_temp);
  e_expl_temp.PassivityUsePredictedX = true;
  e_expl_temp.OutputPassivityIndex = 0.1;
  e_expl_temp.InputPassivityIndex = 0.0;
  e_expl_temp.MVIndex[0] = 1.0;
  e_expl_temp.MVIndex[1] = 2.0;
  e_expl_temp.NumOfInputs = 2.0;
  e_expl_temp.NumOfOutputs = 4.0;
  e_expl_temp.NumOfStates = 4.0;
  e_expl_temp.PredictionHorizon = 10.0;
  i = e_expl_temp.MVTarget->size[0] * e_expl_temp.MVTarget->size[1];
  e_expl_temp.MVTarget->size[0] = expl_temp.MVTarget->size[0];
  e_expl_temp.MVTarget->size[1] = expl_temp.MVTarget->size[1];
  emxEnsureCapacity_real_T(e_expl_temp.MVTarget, i);
  loop_ub = expl_temp.MVTarget->size[0] * expl_temp.MVTarget->size[1];
  for (i = 0; i < loop_ub; i++) {
    e_expl_temp.MVTarget->data[i] = expl_temp.MVTarget->data[i];
  }
  i = e_expl_temp.References->size[0] * e_expl_temp.References->size[1];
  e_expl_temp.References->size[0] = expl_temp.References->size[0];
  e_expl_temp.References->size[1] = expl_temp.References->size[1];
  emxEnsureCapacity_real_T(e_expl_temp.References, i);
  loop_ub = expl_temp.References->size[0] * expl_temp.References->size[1];
  for (i = 0; i < loop_ub; i++) {
    e_expl_temp.References->data[i] = expl_temp.References->data[i];
  }
  e_expl_temp.LastMV[0] = lastMV[0];
  e_expl_temp.LastMV[1] = lastMV[1];
  e_expl_temp.CurrentStates[0] = x[0];
  e_expl_temp.CurrentStates[1] = x[1];
  e_expl_temp.CurrentStates[2] = x[2];
  e_expl_temp.CurrentStates[3] = x[3];
  e_expl_temp.Ts = 0.1;
  for (i = 0; i < 40; i++) {
    b_dv[i] = rtMinusInf;
  }
  for (i = 0; i < 10; i++) {
    b_dv[i + 40] = rtMinusInf;
  }
  char_T f_expl_temp[3];
  b_dv[50] = 0.0;
  info->Cost =
      fmincon(&b_expl_temp, &expl_temp, z0, ref, B, b_dv, zUB, &d_expl_temp,
              &e_expl_temp, &e0, &b_cost_inputs, &R_tmp_tmp, f_expl_temp,
              &R_tmp, &onlinedata_idx_0, &onlinedata_idx_1, &c_expl_temp);
  emxFreeStruct_struct_T1(&e_expl_temp);
  emxFreeStruct_struct_T(&d_expl_temp);
  emxFreeStruct_struct_T1(&expl_temp);
  emxFreeStruct_struct_T(&b_expl_temp);
  emxFree_real_T(&ref);
  emxFree_real_T(&B);
  if (((int32_T)muDoubleScalarRound(e0) == 0) && (R_tmp > 1.0E-6)) {
    e0 = -2.0;
  }
  memset(&info->Xopt[0], 0, 44U * sizeof(real_T));
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (i = 0; i < 20; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 10; i1++) {
      d += (real_T)iv[i + 20 * i1] * z0[i1 + 40];
    }
    b_lastMV[i] = d;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 10; i1++) {
      Umv[i1 + 11 * i] = b_lastMV[i + (i1 << 1)];
    }
  }
  memcpy(&b_x[0], &z0[0], 40U * sizeof(real_T));
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < 10; i1++) {
      info->Xopt[(i1 + 11 * i) + 1] = b_x[i + (i1 << 2)];
    }
    info->Xopt[11 * i] = x[i];
  }
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 2; expl_temp_idx_0++) {
    Umv[11 * expl_temp_idx_0 + 10] = Umv[11 * expl_temp_idx_0 + 9];
    memcpy(&info->MVopt[expl_temp_idx_0 * 11], &Umv[expl_temp_idx_0 * 11],
           11U * sizeof(real_T));
  }
  if (e0 > 0.0) {
    mv[0] = info->MVopt[0];
    mv[1] = info->MVopt[11];
  } else {
    mv[0] = lastMV[0];
    mv[1] = lastMV[1];
  }
  info->ExitFlag = e0;
  info->Iterations = b_cost_inputs;
  onlinedata->Slack0 = muDoubleScalarMax(0.0, z0[50]);
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 11; expl_temp_idx_0++) {
    info->Yopt[expl_temp_idx_0] = info->Xopt[expl_temp_idx_0];
    info->Yopt[expl_temp_idx_0 + 11] = info->Xopt[expl_temp_idx_0 + 11];
    info->Yopt[expl_temp_idx_0 + 22] = info->Xopt[expl_temp_idx_0 + 22];
    info->Yopt[expl_temp_idx_0 + 33] = info->Xopt[expl_temp_idx_0 + 33];
    info->Topt[expl_temp_idx_0] = 0.1 * (real_T)expl_temp_idx_0;
  }
  info->Slack = z0[50];
  i = onlinedata->X0->size[0] * onlinedata->X0->size[1];
  onlinedata->X0->size[0] = 10;
  onlinedata->X0->size[1] = 4;
  emxEnsureCapacity_real_T(onlinedata->X0, i);
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < 10; i1++) {
      onlinedata->X0->data[i1 + onlinedata->X0->size[0] * i] =
          info->Xopt[b_iv[i1] + 11 * i];
    }
  }
  i = onlinedata->MV0->size[0] * onlinedata->MV0->size[1];
  onlinedata->MV0->size[0] = 10;
  onlinedata->MV0->size[1] = 2;
  emxEnsureCapacity_real_T(onlinedata->MV0, i);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 10; i1++) {
      onlinedata->MV0->data[i1 + onlinedata->MV0->size[0] * i] =
          info->MVopt[(i1 + 11 * i) + 1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (nlmpcmoveCodeGeneration.c) */
