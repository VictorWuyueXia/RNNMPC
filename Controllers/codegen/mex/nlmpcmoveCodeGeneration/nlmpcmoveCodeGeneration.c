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
#include "fmincon.h"
#include "mtimes.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "vehicleDynamics_Simple.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void c_nlmpcmoveCodeGeneration_anonF(
    const real_T runtimedata_x[4], const real_T runtimedata_OutputMin[10],
    const real_T runtimedata_OutputMax[10], real_T runtimedata_Parameters_f1,
    real_T runtimedata_Parameters_f2, const real_T z[51],
    emxArray_real_T *varargout_1, real_T varargout_2[40],
    emxArray_real_T *varargout_3, real_T varargout_4[2040])
{
  __m128d r;
  __m128d r1;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emxArray_int8_T *Je;
  emxArray_int8_T *r2;
  emxArray_real_T *Jc;
  emxArray_real_T *b_Jmv;
  emxArray_real_T *b_c;
  emxArray_real_T *c_c;
  emxArray_real_T *c_y;
  emxArray_real_T *r3;
  emxArray_real_T *varargin_1;
  emxArray_real_T *varargin_2;
  real_T Jx[1600];
  real_T Jmv[800];
  real_T y[400];
  real_T X[44];
  real_T b_X[44];
  real_T b_z[40];
  real_T U[22];
  real_T Umv[22];
  real_T c[20];
  real_T val[16];
  real_T b_val[8];
  real_T f[4];
  real_T ic[4];
  real_T xa[4];
  real_T xk1[4];
  real_T dx;
  real_T e;
  real_T ua_idx_0;
  real_T *Jc_data;
  real_T *b_c_data;
  real_T *c_data;
  real_T *varargin_1_data;
  int32_T U_tmp;
  int32_T b_i;
  int32_T i;
  int32_T k;
  int32_T uk_tmp;
  char_T TRANSA1;
  char_T TRANSB1;
  int8_T input_sizes_idx_0;
  int8_T input_sizes_idx_1;
  int8_T *Je_data;
  int8_T *r7;
  boolean_T b[10];
  boolean_T b_y;
  boolean_T exitg1;
  boolean_T guard1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  memset(&X[0], 0, 44U * sizeof(real_T));
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (i = 0; i < 20; i++) {
    dx = 0.0;
    for (k = 0; k < 10; k++) {
      dx += (real_T)iv[i + 20 * k] * z[k + 40];
    }
    c[i] = dx;
  }
  for (i = 0; i < 2; i++) {
    for (k = 0; k < 10; k++) {
      Umv[k + 11 * i] = c[i + (k << 1)];
    }
  }
  e = z[50];
  memcpy(&b_z[0], &z[0], 40U * sizeof(real_T));
  for (i = 0; i < 4; i++) {
    for (k = 0; k < 10; k++) {
      X[(k + 11 * i) + 1] = b_z[i + (k << 2)];
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
  ic[0] = 1.0;
  ic[1] = 2.0;
  ic[2] = 3.0;
  ic[3] = 4.0;
  for (i = 0; i < 11; i++) {
    U_tmp = i << 1;
    Umv[U_tmp] = U[i];
    Umv[U_tmp + 1] = U[i + 11];
  }
  for (i = 0; i < 11; i++) {
    U_tmp = i << 2;
    b_X[U_tmp] = X[i];
    b_X[U_tmp + 1] = X[i + 11];
    b_X[U_tmp + 2] = X[i + 22];
    b_X[U_tmp + 3] = X[i + 33];
  }
  r = _mm_set1_pd(-1.0);
  r1 = _mm_set1_pd(4.0);
  for (b_i = 0; b_i < 10; b_i++) {
    __m128d r4;
    __m128d r5;
    __m128d r6;
    real_T xk[4];
    real_T uk[2];
    real_T b_uk_tmp;
    real_T c_uk_tmp;
    real_T ua_idx_1;
    uk_tmp = b_i << 1;
    b_uk_tmp = Umv[uk_tmp];
    c_uk_tmp = Umv[uk_tmp + 1];
    uk[1] = c_uk_tmp;
    U_tmp = b_i << 2;
    vehicleDynamics_Simple(&b_X[U_tmp], &Umv[uk_tmp], runtimedata_Parameters_f1,
                           runtimedata_Parameters_f2, xk1);
    dx = b_X[U_tmp];
    xk[0] = dx;
    xa[0] = muDoubleScalarAbs(dx);
    dx = b_X[U_tmp + 1];
    xk[1] = dx;
    xa[1] = muDoubleScalarAbs(dx);
    dx = b_X[U_tmp + 2];
    xk[2] = dx;
    xa[2] = muDoubleScalarAbs(dx);
    dx = b_X[U_tmp + 3];
    xk[3] = dx;
    xa[3] = muDoubleScalarAbs(dx);
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
    for (U_tmp = 0; U_tmp < 4; U_tmp++) {
      dx = 1.0E-6 * xa[U_tmp];
      xk[U_tmp] += dx;
      vehicleDynamics_Simple(xk, &Umv[uk_tmp], runtimedata_Parameters_f1,
                             runtimedata_Parameters_f2, f);
      xk[U_tmp] -= dx;
      r4 = _mm_loadu_pd(&f[0]);
      r5 = _mm_loadu_pd(&xk1[0]);
      i = U_tmp << 2;
      r6 = _mm_set1_pd(dx);
      _mm_storeu_pd(&val[i], _mm_div_pd(_mm_sub_pd(r4, r5), r6));
      r4 = _mm_loadu_pd(&f[2]);
      r5 = _mm_loadu_pd(&xk1[2]);
      _mm_storeu_pd(&val[i + 2], _mm_div_pd(_mm_sub_pd(r4, r5), r6));
    }
    ua_idx_0 = muDoubleScalarAbs(b_uk_tmp);
    ua_idx_1 = muDoubleScalarAbs(c_uk_tmp);
    if (ua_idx_0 < 1.0) {
      ua_idx_0 = 1.0;
    }
    if (ua_idx_1 < 1.0) {
      ua_idx_1 = 1.0;
    }
    dx = 1.0E-6 * ua_idx_0;
    uk[0] = b_uk_tmp + dx;
    vehicleDynamics_Simple(xk, uk, runtimedata_Parameters_f1,
                           runtimedata_Parameters_f2, f);
    uk[0] -= dx;
    r4 = _mm_loadu_pd(&f[0]);
    r5 = _mm_loadu_pd(&xk1[0]);
    r6 = _mm_set1_pd(dx);
    _mm_storeu_pd(&b_val[0], _mm_div_pd(_mm_sub_pd(r4, r5), r6));
    r4 = _mm_loadu_pd(&f[2]);
    r5 = _mm_loadu_pd(&xk1[2]);
    _mm_storeu_pd(&b_val[2], _mm_div_pd(_mm_sub_pd(r4, r5), r6));
    dx = 1.0E-6 * ua_idx_1;
    uk[1] = c_uk_tmp + dx;
    vehicleDynamics_Simple(xk, uk, runtimedata_Parameters_f1,
                           runtimedata_Parameters_f2, f);
    r4 = _mm_loadu_pd(&f[0]);
    r5 = _mm_loadu_pd(&xk1[0]);
    r6 = _mm_set1_pd(dx);
    _mm_storeu_pd(&b_val[4], _mm_div_pd(_mm_sub_pd(r4, r5), r6));
    r4 = _mm_loadu_pd(&f[2]);
    r5 = _mm_loadu_pd(&xk1[2]);
    _mm_storeu_pd(&b_val[6], _mm_div_pd(_mm_sub_pd(r4, r5), r6));
    dx = ic[0];
    U_tmp = (b_i + 1) << 2;
    varargout_2[(int32_T)dx - 1] = b_X[U_tmp] - xk1[0];
    Jx[((int8_T)dx + 160 * b_i) - 1] = 1.0;
    dx = ic[1];
    varargout_2[(int32_T)dx - 1] = b_X[U_tmp + 1] - xk1[1];
    Jx[((int8_T)dx + 160 * b_i) + 39] = 1.0;
    dx = ic[2];
    varargout_2[(int32_T)dx - 1] = b_X[U_tmp + 2] - xk1[2];
    Jx[((int8_T)dx + 160 * b_i) + 79] = 1.0;
    dx = ic[3];
    varargout_2[(int32_T)dx - 1] = b_X[U_tmp + 3] - xk1[3];
    Jx[((int8_T)dx + 160 * b_i) + 119] = 1.0;
    if (b_i + 1 > 1) {
      for (i = 0; i <= 14; i += 2) {
        r4 = _mm_loadu_pd(&val[i]);
        _mm_storeu_pd(&val[i], _mm_mul_pd(r4, _mm_set1_pd(-1.0)));
      }
      U_tmp = 160 * (b_i - 1);
      for (k = 0; k < 4; k++) {
        uk_tmp = k << 2;
        Jx[(((int32_T)ic[0] + 40 * k) + U_tmp) - 1] = val[uk_tmp];
        Jx[(((int32_T)ic[1] + 40 * k) + U_tmp) - 1] = val[uk_tmp + 1];
        Jx[(((int32_T)ic[2] + 40 * k) + U_tmp) - 1] = val[uk_tmp + 2];
        Jx[(((int32_T)ic[3] + 40 * k) + U_tmp) - 1] = val[uk_tmp + 3];
      }
    }
    r4 = _mm_loadu_pd(&b_val[0]);
    _mm_storeu_pd(&b_val[0], _mm_mul_pd(r4, r));
    r4 = _mm_loadu_pd(&b_val[2]);
    _mm_storeu_pd(&b_val[2], _mm_mul_pd(r4, r));
    r4 = _mm_loadu_pd(&b_val[4]);
    _mm_storeu_pd(&b_val[4], _mm_mul_pd(r4, r));
    r4 = _mm_loadu_pd(&b_val[6]);
    _mm_storeu_pd(&b_val[6], _mm_mul_pd(r4, r));
    for (k = 0; k < 2; k++) {
      U_tmp = k << 2;
      Jmv[(((int32_T)ic[0] + 40 * k) + 80 * b_i) - 1] = b_val[U_tmp];
      Jmv[(((int32_T)ic[1] + 40 * k) + 80 * b_i) - 1] = b_val[U_tmp + 1];
      Jmv[(((int32_T)ic[2] + 40 * k) + 80 * b_i) - 1] = b_val[U_tmp + 2];
      Jmv[(((int32_T)ic[3] + 40 * k) + 80 * b_i) - 1] = b_val[U_tmp + 3];
    }
    r4 = _mm_loadu_pd(&ic[0]);
    _mm_storeu_pd(&ic[0], _mm_add_pd(r4, r1));
    r4 = _mm_loadu_pd(&ic[2]);
    _mm_storeu_pd(&ic[2], _mm_add_pd(r4, r1));
  }
  TRANSB1 = 'N';
  TRANSA1 = 'N';
  dx = 1.0;
  ua_idx_0 = 0.0;
  m_t = (ptrdiff_t)40;
  n_t = (ptrdiff_t)10;
  k_t = (ptrdiff_t)20;
  lda_t = (ptrdiff_t)40;
  ldb_t = (ptrdiff_t)20;
  ldc_t = (ptrdiff_t)40;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &dx, &Jmv[0], &lda_t,
        (real_T *)&dv[0], &ldb_t, &ua_idx_0, &y[0], &ldc_t);
  for (b_i = 0; b_i < 10; b_i++) {
    b[b_i] = muDoubleScalarIsInf(runtimedata_OutputMin[b_i]);
  }
  b_y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 9)) {
    if (!b[k]) {
      b_y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  emxInit_real_T(&b_c, 2);
  c_data = b_c->data;
  emxInit_real_T(&Jc, 2);
  Jc_data = Jc->data;
  emxInit_int8_T(&r2, 1);
  emxInit_real_T(&c_y, 2);
  emxInit_real_T(&varargin_1, 2);
  emxInit_real_T(&varargin_2, 2);
  emxInit_real_T(&c_c, 1);
  emxInit_real_T(&r3, 2);
  emxInit_real_T(&b_Jmv, 3);
  emxInit_int8_T(&Je, 2);
  guard1 = false;
  if (b_y) {
    for (b_i = 0; b_i < 10; b_i++) {
      b[b_i] = muDoubleScalarIsInf(runtimedata_OutputMax[b_i]);
    }
    b_y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 9)) {
      if (!b[k]) {
        b_y = false;
        exitg1 = true;
      } else {
        k++;
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
    int32_T b_ic[2];
    int8_T b_Je[20];
    boolean_T icf[20];
    for (b_i = 0; b_i < 20; b_i++) {
      c[b_i] = 0.0;
      icf[b_i] = true;
    }
    memset(&Jmv[0], 0, 800U * sizeof(real_T));
    for (b_i = 0; b_i < 20; b_i++) {
      b_Je[b_i] = 0;
    }
    for (b_i = 0; b_i < 10; b_i++) {
      uk_tmp = b_i << 1;
      dx = runtimedata_OutputMin[b_i];
      icf[uk_tmp] = ((!muDoubleScalarIsInf(dx)) && (!muDoubleScalarIsNaN(dx)));
      dx = runtimedata_OutputMax[b_i];
      icf[uk_tmp + 1] =
          ((!muDoubleScalarIsInf(dx)) && (!muDoubleScalarIsNaN(dx)));
      b_y = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= 1)) {
        b_ic[0] = uk_tmp;
        b_ic[1] = uk_tmp + 1;
        if (icf[b_ic[k]]) {
          b_y = true;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (b_y) {
        xa[0] = muDoubleScalarAbs(X[b_i + 1]);
        xa[1] = muDoubleScalarAbs(X[b_i + 12]);
        xa[2] = muDoubleScalarAbs(X[b_i + 23]);
        xa[3] = muDoubleScalarAbs(X[b_i + 34]);
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
        c[uk_tmp] = runtimedata_OutputMin[b_i] - e;
        c[uk_tmp + 1] = (0.0 - runtimedata_OutputMax[b_i]) - e;
        dx = 0.0 / (1.0E-6 * xa[0]);
        U_tmp = uk_tmp + 80 * b_i;
        Jmv[U_tmp] = -dx;
        Jmv[U_tmp + 1] = dx;
        dx = 0.0 / (1.0E-6 * xa[1]);
        Jmv[U_tmp + 20] = -dx;
        Jmv[U_tmp + 21] = dx;
        dx = 0.0 / (1.0E-6 * xa[2]);
        Jmv[U_tmp + 40] = -dx;
        Jmv[U_tmp + 41] = dx;
        dx = 0.0 / (1.0E-6 * xa[3]);
        Jmv[U_tmp + 60] = -dx;
        Jmv[U_tmp + 61] = dx;
        b_Je[uk_tmp] = -1;
        b_Je[uk_tmp + 1] = -1;
      }
    }
    U_tmp = 0;
    for (b_i = 0; b_i < 20; b_i++) {
      if (icf[b_i]) {
        U_tmp++;
      }
    }
    i = r2->size[0];
    r2->size[0] = U_tmp;
    emxEnsureCapacity_int8_T(r2, i);
    r7 = r2->data;
    U_tmp = 0;
    for (b_i = 0; b_i < 20; b_i++) {
      if (icf[b_i]) {
        r7[U_tmp] = (int8_T)b_i;
        U_tmp++;
      }
    }
    i = c_c->size[0];
    c_c->size[0] = r2->size[0];
    emxEnsureCapacity_real_T(c_c, i);
    b_c_data = c_c->data;
    uk_tmp = r2->size[0];
    for (i = 0; i < uk_tmp; i++) {
      b_c_data[i] = c[r7[i]];
    }
    i = b_c->size[0] * b_c->size[1];
    b_c->size[0] = r2->size[0];
    b_c->size[1] = 1;
    emxEnsureCapacity_real_T(b_c, i);
    c_data = b_c->data;
    uk_tmp = r2->size[0];
    for (i = 0; i < uk_tmp; i++) {
      c_data[i] = b_c_data[i];
    }
    if (r2->size[0] == 0) {
      Jc->size[0] = 0;
      Jc->size[1] = 0;
    } else {
      i = r3->size[0] * r3->size[1];
      r3->size[0] = r2->size[0];
      r3->size[1] = 20;
      emxEnsureCapacity_real_T(r3, i);
      b_c_data = r3->data;
      uk_tmp = r2->size[0] * 20;
      for (i = 0; i < uk_tmp; i++) {
        b_c_data[i] = 0.0;
      }
      mtimes(r3, c_y);
      Jc_data = c_y->data;
      i = b_Jmv->size[0] * b_Jmv->size[1] * b_Jmv->size[2];
      b_Jmv->size[0] = r2->size[0];
      b_Jmv->size[1] = 4;
      b_Jmv->size[2] = 10;
      emxEnsureCapacity_real_T(b_Jmv, i);
      b_c_data = b_Jmv->data;
      uk_tmp = r2->size[0];
      for (i = 0; i < 10; i++) {
        for (k = 0; k < 4; k++) {
          for (U_tmp = 0; U_tmp < uk_tmp; U_tmp++) {
            b_c_data[(U_tmp + b_Jmv->size[0] * k) + b_Jmv->size[0] * 4 * i] =
                Jmv[(r7[U_tmp] + 20 * k) + 80 * i];
          }
        }
      }
      b_ic[0] = r2->size[0];
      i = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = 40;
      varargin_1->size[1] = r2->size[0];
      emxEnsureCapacity_real_T(varargin_1, i);
      varargin_1_data = varargin_1->data;
      uk_tmp = r2->size[0];
      for (i = 0; i < uk_tmp; i++) {
        for (k = 0; k < 40; k++) {
          varargin_1_data[k + 40 * i] = b_c_data[i + b_ic[0] * k];
        }
      }
      i = varargin_2->size[0] * varargin_2->size[1];
      varargin_2->size[0] = 10;
      varargin_2->size[1] = c_y->size[0];
      emxEnsureCapacity_real_T(varargin_2, i);
      b_c_data = varargin_2->data;
      uk_tmp = c_y->size[0];
      for (i = 0; i < uk_tmp; i++) {
        for (k = 0; k < 10; k++) {
          b_c_data[k + 10 * i] = Jc_data[i + c_y->size[0] * k];
        }
      }
      if (varargin_2->size[1] != 0) {
        U_tmp = 10;
      } else {
        U_tmp = 0;
      }
      i = Je->size[0] * Je->size[1];
      Je->size[0] = 1;
      Je->size[1] = r2->size[0];
      emxEnsureCapacity_int8_T(Je, i);
      Je_data = Je->data;
      uk_tmp = r2->size[0];
      i = Jc->size[0] * Jc->size[1];
      Jc->size[0] = U_tmp + 41;
      Jc->size[1] = varargin_1->size[1];
      emxEnsureCapacity_real_T(Jc, i);
      Jc_data = Jc->data;
      for (i = 0; i < uk_tmp; i++) {
        Je_data[i] = b_Je[r7[i]];
        for (k = 0; k < 40; k++) {
          Jc_data[k + Jc->size[0] * i] = varargin_1_data[k + 40 * i];
        }
        for (k = 0; k < U_tmp; k++) {
          Jc_data[(k + Jc->size[0] * i) + 40] = b_c_data[k + U_tmp * i];
        }
      }
      uk_tmp = varargin_1->size[1];
      for (i = 0; i < uk_tmp; i++) {
        Jc_data[(U_tmp + Jc->size[0] * i) + 40] = Je_data[i];
      }
    }
  }
  emxFree_int8_T(&Je);
  emxFree_real_T(&b_Jmv);
  emxFree_real_T(&r3);
  emxFree_real_T(&c_c);
  emxFree_real_T(&varargin_2);
  emxFree_real_T(&varargin_1);
  emxFree_real_T(&c_y);
  emxFree_int8_T(&r2);
  b_y = ((b_c->size[0] != 0) && (b_c->size[1] != 0));
  input_sizes_idx_0 = (int8_T)b_c->size[0];
  i = varargout_1->size[0] * varargout_1->size[1];
  varargout_1->size[0] = input_sizes_idx_0;
  U_tmp = b_y;
  varargout_1->size[1] = b_y;
  emxEnsureCapacity_real_T(varargout_1, i);
  b_c_data = varargout_1->data;
  for (i = 0; i < U_tmp; i++) {
    uk_tmp = input_sizes_idx_0;
    for (k = 0; k < uk_tmp; k++) {
      b_c_data[k] = c_data[k];
    }
  }
  emxFree_real_T(&b_c);
  b_y = ((Jc->size[0] != 0) && (Jc->size[1] != 0));
  if (b_y) {
    input_sizes_idx_0 = (int8_T)Jc->size[0];
  } else {
    input_sizes_idx_0 = 0;
  }
  if ((input_sizes_idx_0 == 0) || b_y) {
    input_sizes_idx_1 = (int8_T)Jc->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }
  i = varargout_3->size[0] * varargout_3->size[1];
  varargout_3->size[0] = input_sizes_idx_0;
  varargout_3->size[1] = input_sizes_idx_1;
  emxEnsureCapacity_real_T(varargout_3, i);
  b_c_data = varargout_3->data;
  uk_tmp = input_sizes_idx_1;
  for (i = 0; i < uk_tmp; i++) {
    U_tmp = input_sizes_idx_0;
    for (k = 0; k < U_tmp; k++) {
      b_c_data[k + varargout_3->size[0] * i] =
          Jc_data[k + input_sizes_idx_0 * i];
    }
  }
  emxFree_real_T(&Jc);
  for (i = 0; i < 40; i++) {
    for (k = 0; k < 40; k++) {
      varargout_4[k + 51 * i] = Jx[i + 40 * k];
    }
    for (k = 0; k < 10; k++) {
      varargout_4[(k + 51 * i) + 40] = y[i + 40 * k];
    }
    varargout_4[51 * i + 50] = 0.0;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void nlmpcmoveCodeGeneration(const real_T x[4], const real_T lastMV[2],
                             struct1_T *onlinedata, real_T mv[2],
                             struct2_T *info)
{
  static real_T c_CostFcn_workspace_runtimedata[40] = {
      0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,
      0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,
      0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,
      30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0};
  static real_T d_CostFcn_workspace_runtimedata[40] = {
      0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,
      0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,
      0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,   0.0,
      -30.0, -30.0, -30.0, -30.0, -30.0, -30.0, -30.0, -30.0, -30.0, -30.0};
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
  static const int8_T t2_f1[20] = {-15, -15, -15, -15, -15, -15, -15,
                                   -15, -15, -15, -30, -30, -30, -30,
                                   -30, -30, -30, -30, -30, -30};
  static const int8_T t4_f1[20] = {-8,  -8,  -8,  -8,  -8,  -8,  -8,
                                   -8,  -8,  -8,  -30, -30, -30, -30,
                                   -30, -30, -30, -30, -30, -30};
  static const int8_T t5_f1[20] = {8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
                                   30, 30, 30, 30, 30, 30, 30, 30, 30, 30};
  static const int8_T b_iv[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10};
  emxArray_int8_T *ii;
  emxArray_real_T b_Auf;
  emxArray_real_T *Auf;
  emxArray_real_T *B;
  emxArray_real_T *b_initX;
  emxArray_real_T *icf;
  emxArray_real_T *initMV;
  emxArray_real_T *initX;
  emxArray_real_T *ref;
  emxArray_real_T *y;
  i_struct_T b_expl_temp;
  i_struct_T c_expl_temp;
  j_struct_T d_expl_temp;
  j_struct_T expl_temp;
  real_T Au[1600];
  real_T Bu[80];
  real_T f_CostFcn_workspace_runtimedata[51];
  real_T g_CostFcn_workspace_runtimedata[51];
  real_T z[51];
  real_T b_x[40];
  real_T e_CostFcn_workspace_runtimedata[40];
  real_T Umv[22];
  real_T b_lastMV[20];
  real_T a[10];
  real_T ic[2];
  real_T Bu_idx_1;
  real_T ExitFlag;
  real_T Out_constrviolation;
  real_T Out_iterations;
  real_T f_expl_temp;
  real_T g_expl_temp;
  real_T h_expl_temp;
  real_T *Auf_data;
  real_T *icf_data;
  real_T *initMV_data;
  real_T *initX_data;
  real_T *ref_data;
  int32_T c_icf[2];
  int32_T b_icf_tmp;
  int32_T c_icf_tmp;
  int32_T expl_temp_idx_0;
  int32_T i;
  int32_T icf_tmp;
  int32_T idx;
  int32_T loop_ub;
  int8_T input_sizes_idx_1_tmp;
  int8_T *ii_data;
  boolean_T b_icf[80];
  boolean_T exitg1;
  c_CostFcn_workspace_runtimedata[0U] = rtInf;
  c_CostFcn_workspace_runtimedata[1U] = rtInf;
  c_CostFcn_workspace_runtimedata[2U] = rtInf;
  c_CostFcn_workspace_runtimedata[3U] = rtInf;
  c_CostFcn_workspace_runtimedata[4U] = rtInf;
  c_CostFcn_workspace_runtimedata[5U] = rtInf;
  c_CostFcn_workspace_runtimedata[6U] = rtInf;
  c_CostFcn_workspace_runtimedata[7U] = rtInf;
  c_CostFcn_workspace_runtimedata[8U] = rtInf;
  c_CostFcn_workspace_runtimedata[9U] = rtInf;
  c_CostFcn_workspace_runtimedata[10U] = rtInf;
  c_CostFcn_workspace_runtimedata[11U] = rtInf;
  c_CostFcn_workspace_runtimedata[12U] = rtInf;
  c_CostFcn_workspace_runtimedata[13U] = rtInf;
  c_CostFcn_workspace_runtimedata[14U] = rtInf;
  c_CostFcn_workspace_runtimedata[15U] = rtInf;
  c_CostFcn_workspace_runtimedata[16U] = rtInf;
  c_CostFcn_workspace_runtimedata[17U] = rtInf;
  c_CostFcn_workspace_runtimedata[18U] = rtInf;
  c_CostFcn_workspace_runtimedata[19U] = rtInf;
  c_CostFcn_workspace_runtimedata[20U] = rtInf;
  c_CostFcn_workspace_runtimedata[21U] = rtInf;
  c_CostFcn_workspace_runtimedata[22U] = rtInf;
  c_CostFcn_workspace_runtimedata[23U] = rtInf;
  c_CostFcn_workspace_runtimedata[24U] = rtInf;
  c_CostFcn_workspace_runtimedata[25U] = rtInf;
  c_CostFcn_workspace_runtimedata[26U] = rtInf;
  c_CostFcn_workspace_runtimedata[27U] = rtInf;
  c_CostFcn_workspace_runtimedata[28U] = rtInf;
  c_CostFcn_workspace_runtimedata[29U] = rtInf;
  d_CostFcn_workspace_runtimedata[0U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[1U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[2U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[3U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[4U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[5U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[6U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[7U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[8U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[9U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[10U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[11U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[12U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[13U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[14U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[15U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[16U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[17U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[18U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[19U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[20U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[21U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[22U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[23U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[24U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[25U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[26U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[27U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[28U] = rtMinusInf;
  d_CostFcn_workspace_runtimedata[29U] = rtMinusInf;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&ref, 2);
  emxInit_real_T(&icf, 1);
  if (onlinedata->ref->size[0] == 0) {
    icf_tmp = ref->size[0] * ref->size[1];
    ref->size[0] = 10;
    ref->size[1] = 1;
    emxEnsureCapacity_real_T(ref, icf_tmp);
    ref_data = ref->data;
    for (icf_tmp = 0; icf_tmp < 10; icf_tmp++) {
      ref_data[icf_tmp] = 0.0;
    }
  } else if (onlinedata->ref->size[0] < 10) {
    icf_tmp = icf->size[0];
    icf->size[0] = 10;
    emxEnsureCapacity_real_T(icf, icf_tmp);
    icf_data = icf->data;
    loop_ub = onlinedata->ref->size[0];
    for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
      icf_data[icf_tmp] = onlinedata->ref->data[icf_tmp];
    }
    loop_ub = -onlinedata->ref->size[0];
    for (icf_tmp = 0; icf_tmp <= loop_ub + 9; icf_tmp++) {
      icf_data[icf_tmp + onlinedata->ref->size[0]] =
          onlinedata->ref->data[onlinedata->ref->size[0] - 1];
    }
    icf_tmp = ref->size[0] * ref->size[1];
    ref->size[0] = 10;
    ref->size[1] = 1;
    emxEnsureCapacity_real_T(ref, icf_tmp);
    ref_data = ref->data;
    for (icf_tmp = 0; icf_tmp < 10; icf_tmp++) {
      ref_data[icf_tmp] = icf_data[icf_tmp];
    }
  } else {
    icf_tmp = ref->size[0] * ref->size[1];
    ref->size[0] = onlinedata->ref->size[0];
    ref->size[1] = 1;
    emxEnsureCapacity_real_T(ref, icf_tmp);
    ref_data = ref->data;
    loop_ub = onlinedata->ref->size[0];
    for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
      ref_data[icf_tmp] = onlinedata->ref->data[icf_tmp];
    }
  }
  emxInitStruct_struct_T1(&expl_temp);
  if (onlinedata->MVTarget->size[0] == 0) {
    icf_tmp = expl_temp.MVTarget->size[0] * expl_temp.MVTarget->size[1];
    expl_temp.MVTarget->size[0] = 10;
    expl_temp.MVTarget->size[1] = 2;
    emxEnsureCapacity_real_T(expl_temp.MVTarget, icf_tmp);
    for (icf_tmp = 0; icf_tmp < 20; icf_tmp++) {
      expl_temp.MVTarget->data[icf_tmp] = 0.0;
    }
  } else if (onlinedata->MVTarget->size[0] == 0) {
    expl_temp.MVTarget->size[0] = 0;
    expl_temp.MVTarget->size[1] = 0;
  } else if (onlinedata->MVTarget->size[0] < 10) {
    expl_temp_idx_0 = 10 - onlinedata->MVTarget->size[0];
    icf_tmp = expl_temp.MVTarget->size[0] * expl_temp.MVTarget->size[1];
    expl_temp.MVTarget->size[0] =
        onlinedata->MVTarget->size[0] + expl_temp_idx_0;
    expl_temp.MVTarget->size[1] = 2;
    emxEnsureCapacity_real_T(expl_temp.MVTarget, icf_tmp);
    loop_ub = onlinedata->MVTarget->size[0];
    for (icf_tmp = 0; icf_tmp < 2; icf_tmp++) {
      for (b_icf_tmp = 0; b_icf_tmp < loop_ub; b_icf_tmp++) {
        expl_temp.MVTarget
            ->data[b_icf_tmp + expl_temp.MVTarget->size[0] * icf_tmp] =
            onlinedata->MVTarget
                ->data[b_icf_tmp + onlinedata->MVTarget->size[0] * icf_tmp];
      }
    }
    for (icf_tmp = 0; icf_tmp < 2; icf_tmp++) {
      for (b_icf_tmp = 0; b_icf_tmp < expl_temp_idx_0; b_icf_tmp++) {
        expl_temp.MVTarget->data[(b_icf_tmp + onlinedata->MVTarget->size[0]) +
                                 expl_temp.MVTarget->size[0] * icf_tmp] =
            onlinedata->MVTarget
                ->data[(onlinedata->MVTarget->size[0] +
                        onlinedata->MVTarget->size[0] * icf_tmp) -
                       1];
      }
    }
  } else {
    icf_tmp = expl_temp.MVTarget->size[0] * expl_temp.MVTarget->size[1];
    expl_temp.MVTarget->size[0] = onlinedata->MVTarget->size[0];
    expl_temp.MVTarget->size[1] = 2;
    emxEnsureCapacity_real_T(expl_temp.MVTarget, icf_tmp);
    loop_ub = onlinedata->MVTarget->size[0] << 1;
    for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
      expl_temp.MVTarget->data[icf_tmp] = onlinedata->MVTarget->data[icf_tmp];
    }
  }
  emxInitStruct_struct_T(&b_expl_temp);
  icf_tmp =
      b_expl_temp.MVScaledTarget->size[0] * b_expl_temp.MVScaledTarget->size[1];
  b_expl_temp.MVScaledTarget->size[0] = expl_temp.MVTarget->size[0];
  b_expl_temp.MVScaledTarget->size[1] = expl_temp.MVTarget->size[1];
  emxEnsureCapacity_real_T(b_expl_temp.MVScaledTarget, icf_tmp);
  loop_ub = expl_temp.MVTarget->size[0] * expl_temp.MVTarget->size[1];
  for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
    b_expl_temp.MVScaledTarget->data[icf_tmp] =
        expl_temp.MVTarget->data[icf_tmp];
  }
  emxInit_real_T(&initX, 2);
  initX_data = initX->data;
  if (onlinedata->X0->size[0] != 0) {
    if (onlinedata->X0->size[0] == 0) {
      initX->size[0] = 0;
      initX->size[1] = 0;
    } else if (onlinedata->X0->size[0] < 10) {
      expl_temp_idx_0 = 10 - onlinedata->X0->size[0];
      icf_tmp = initX->size[0] * initX->size[1];
      initX->size[0] = onlinedata->X0->size[0] + expl_temp_idx_0;
      initX->size[1] = 4;
      emxEnsureCapacity_real_T(initX, icf_tmp);
      initX_data = initX->data;
      loop_ub = onlinedata->X0->size[0];
      for (icf_tmp = 0; icf_tmp < 4; icf_tmp++) {
        for (b_icf_tmp = 0; b_icf_tmp < loop_ub; b_icf_tmp++) {
          initX_data[b_icf_tmp + initX->size[0] * icf_tmp] =
              onlinedata->X0
                  ->data[b_icf_tmp + onlinedata->X0->size[0] * icf_tmp];
        }
      }
      for (icf_tmp = 0; icf_tmp < 4; icf_tmp++) {
        for (b_icf_tmp = 0; b_icf_tmp < expl_temp_idx_0; b_icf_tmp++) {
          initX_data[(b_icf_tmp + onlinedata->X0->size[0]) +
                     initX->size[0] * icf_tmp] =
              onlinedata->X0->data[(onlinedata->X0->size[0] +
                                    onlinedata->X0->size[0] * icf_tmp) -
                                   1];
        }
      }
    } else {
      icf_tmp = initX->size[0] * initX->size[1];
      initX->size[0] = onlinedata->X0->size[0];
      initX->size[1] = 4;
      emxEnsureCapacity_real_T(initX, icf_tmp);
      initX_data = initX->data;
      loop_ub = onlinedata->X0->size[0] << 2;
      for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
        initX_data[icf_tmp] = onlinedata->X0->data[icf_tmp];
      }
    }
  } else {
    for (icf_tmp = 0; icf_tmp < 4; icf_tmp++) {
      b_x[10 * icf_tmp] = x[icf_tmp];
      for (b_icf_tmp = 0; b_icf_tmp < 9; b_icf_tmp++) {
        b_x[(b_icf_tmp + 10 * icf_tmp) + 1] = x[icf_tmp];
      }
    }
    icf_tmp = initX->size[0] * initX->size[1];
    initX->size[0] = 10;
    initX->size[1] = 4;
    emxEnsureCapacity_real_T(initX, icf_tmp);
    initX_data = initX->data;
    for (icf_tmp = 0; icf_tmp < 40; icf_tmp++) {
      initX_data[icf_tmp] = b_x[icf_tmp];
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
      icf_tmp = initMV->size[0] * initMV->size[1];
      initMV->size[0] = onlinedata->MV0->size[0] + expl_temp_idx_0;
      initMV->size[1] = 2;
      emxEnsureCapacity_real_T(initMV, icf_tmp);
      initMV_data = initMV->data;
      loop_ub = onlinedata->MV0->size[0];
      for (icf_tmp = 0; icf_tmp < 2; icf_tmp++) {
        for (b_icf_tmp = 0; b_icf_tmp < loop_ub; b_icf_tmp++) {
          initMV_data[b_icf_tmp + initMV->size[0] * icf_tmp] =
              onlinedata->MV0
                  ->data[b_icf_tmp + onlinedata->MV0->size[0] * icf_tmp];
        }
      }
      for (icf_tmp = 0; icf_tmp < 2; icf_tmp++) {
        for (b_icf_tmp = 0; b_icf_tmp < expl_temp_idx_0; b_icf_tmp++) {
          initMV_data[(b_icf_tmp + onlinedata->MV0->size[0]) +
                      initMV->size[0] * icf_tmp] =
              onlinedata->MV0->data[(onlinedata->MV0->size[0] +
                                     onlinedata->MV0->size[0] * icf_tmp) -
                                    1];
        }
      }
    } else {
      icf_tmp = initMV->size[0] * initMV->size[1];
      initMV->size[0] = onlinedata->MV0->size[0];
      initMV->size[1] = 2;
      emxEnsureCapacity_real_T(initMV, icf_tmp);
      initMV_data = initMV->data;
      loop_ub = onlinedata->MV0->size[0] << 1;
      for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
        initMV_data[icf_tmp] = onlinedata->MV0->data[icf_tmp];
      }
    }
  } else {
    for (icf_tmp = 0; icf_tmp < 2; icf_tmp++) {
      b_lastMV[10 * icf_tmp] = lastMV[icf_tmp];
      for (b_icf_tmp = 0; b_icf_tmp < 9; b_icf_tmp++) {
        b_lastMV[(b_icf_tmp + 10 * icf_tmp) + 1] = lastMV[icf_tmp];
      }
    }
    icf_tmp = initMV->size[0] * initMV->size[1];
    initMV->size[0] = 10;
    initMV->size[1] = 2;
    emxEnsureCapacity_real_T(initMV, icf_tmp);
    initMV_data = initMV->data;
    for (icf_tmp = 0; icf_tmp < 20; icf_tmp++) {
      initMV_data[icf_tmp] = b_lastMV[icf_tmp];
    }
  }
  icf_tmp = expl_temp.References->size[0] * expl_temp.References->size[1];
  expl_temp.References->size[0] = ref->size[0];
  expl_temp.References->size[1] = 1;
  emxEnsureCapacity_real_T(expl_temp.References, icf_tmp);
  loop_ub = ref->size[0];
  for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
    expl_temp.References->data[icf_tmp] = ref_data[icf_tmp];
  }
  icf_tmp = b_expl_temp.ref->size[0] * b_expl_temp.ref->size[1];
  b_expl_temp.ref->size[0] = ref->size[0];
  b_expl_temp.ref->size[1] = 1;
  emxEnsureCapacity_real_T(b_expl_temp.ref, icf_tmp);
  loop_ub = ref->size[0];
  for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
    b_expl_temp.ref->data[icf_tmp] = ref_data[icf_tmp];
  }
  for (icf_tmp = 0; icf_tmp < 20; icf_tmp++) {
    b_expl_temp.MVRateWeights[icf_tmp] = 0.1;
  }
  for (i = 0; i < 10; i++) {
    b_expl_temp.OutputMin[i] = rtMinusInf;
    b_expl_temp.OutputMax[i] = rtInf;
  }
  memset(&Au[0], 0, 1600U * sizeof(real_T));
  memset(&Bu[0], 0, 80U * sizeof(real_T));
  memset(&b_icf[0], 0, 80U * sizeof(boolean_T));
  ic[0] = 1.0;
  ic[1] = 2.0;
  for (i = 0; i < 10; i++) {
    __m128d r;
    int32_T Au_tmp;
    int32_T b_Au_tmp;
    int32_T d_icf_tmp;
    int32_T e_icf_tmp;
    int32_T f_icf_tmp;
    c_icf_tmp = (int32_T)ic[0] - 1;
    b_icf[c_icf_tmp] = true;
    expl_temp_idx_0 = (int32_T)ic[1] - 1;
    b_icf[expl_temp_idx_0] = true;
    loop_ub = (int32_T)(ic[0] + 2.0) - 1;
    b_icf[loop_ub] = true;
    input_sizes_idx_1_tmp = t5_f1[i + 10];
    b_icf_tmp = (int32_T)(ic[1] + 2.0) - 1;
    b_icf[b_icf_tmp] = true;
    icf_tmp = (int32_T)(ic[0] + 4.0) - 1;
    b_icf[icf_tmp] = true;
    d_icf_tmp = (int32_T)(ic[1] + 4.0) - 1;
    b_icf[d_icf_tmp] = true;
    e_icf_tmp = (int32_T)(ic[0] + 6.0) - 1;
    b_icf[e_icf_tmp] = true;
    Au_tmp = (int32_T)ic[0] + 160 * i;
    Au[Au_tmp - 1] = -1.0;
    b_Au_tmp = (int32_T)ic[1] + 160 * i;
    Au[b_Au_tmp - 1] = -0.0;
    f_icf_tmp = (int32_T)(ic[1] + 6.0) - 1;
    b_icf[f_icf_tmp] = true;
    Au[Au_tmp + 79] = -0.0;
    Au[b_Au_tmp + 79] = -1.0;
    Au_tmp = (int32_T)(ic[0] + 2.0) + 160 * i;
    Au[Au_tmp - 1] = 1.0;
    b_Au_tmp = (int32_T)(ic[1] + 2.0) + 160 * i;
    Au[b_Au_tmp - 1] = 0.0;
    Au[Au_tmp + 79] = 0.0;
    Au[b_Au_tmp + 79] = 1.0;
    Au_tmp = (int32_T)(ic[0] + 4.0) + 160 * i;
    Au[Au_tmp - 1] = -1.0;
    b_Au_tmp = (int32_T)(ic[1] + 4.0) + 160 * i;
    Au[b_Au_tmp - 1] = -0.0;
    Au[Au_tmp + 79] = -0.0;
    Au[b_Au_tmp + 79] = -1.0;
    Au_tmp = (int32_T)(ic[0] + 6.0) + 160 * i;
    Au[Au_tmp - 1] = 1.0;
    b_Au_tmp = (int32_T)(ic[1] + 6.0) + 160 * i;
    Au[b_Au_tmp - 1] = 0.0;
    Au[Au_tmp + 79] = 0.0;
    Au[b_Au_tmp + 79] = 1.0;
    Bu[c_icf_tmp] = -(real_T)t4_f1[i];
    Bu[expl_temp_idx_0] = -(real_T)t4_f1[i + 10];
    idx = t5_f1[i];
    Bu[loop_ub] = idx;
    Bu[b_icf_tmp] = input_sizes_idx_1_tmp;
    Bu[icf_tmp] = -(real_T)t2_f1[i];
    Bu[d_icf_tmp] = -(real_T)t2_f1[i + 10];
    Bu[e_icf_tmp] = idx;
    Bu[f_icf_tmp] = input_sizes_idx_1_tmp;
    if (i + 1 == 1) {
      Bu_idx_1 = Bu[expl_temp_idx_0] - lastMV[1];
      Bu[c_icf_tmp] -= lastMV[0];
      Bu[expl_temp_idx_0] = Bu_idx_1;
      Bu_idx_1 = Bu[b_icf_tmp] + lastMV[1];
      Bu[loop_ub] += lastMV[0];
      Bu[b_icf_tmp] = Bu_idx_1;
    } else {
      Au_tmp = 160 * (i - 1);
      b_Au_tmp = (int32_T)ic[0] + Au_tmp;
      Au[b_Au_tmp - 1] = 1.0;
      idx = (int32_T)ic[1] + Au_tmp;
      Au[idx - 1] = 0.0;
      Au[b_Au_tmp + 79] = 0.0;
      Au[idx + 79] = 1.0;
      b_Au_tmp = (int32_T)(ic[0] + 2.0) + Au_tmp;
      Au[b_Au_tmp - 1] = -1.0;
      Au_tmp += (int32_T)(ic[1] + 2.0);
      Au[Au_tmp - 1] = -0.0;
      Au[b_Au_tmp + 79] = -0.0;
      Au[Au_tmp + 79] = -1.0;
    }
    r = _mm_loadu_pd(&ic[0]);
    _mm_storeu_pd(&ic[0], _mm_add_pd(r, _mm_set1_pd(8.0)));
  }
  idx = 0;
  emxInit_int8_T(&ii, 1);
  icf_tmp = ii->size[0];
  ii->size[0] = 80;
  emxEnsureCapacity_int8_T(ii, icf_tmp);
  ii_data = ii->data;
  expl_temp_idx_0 = 0;
  exitg1 = false;
  while ((!exitg1) && (expl_temp_idx_0 < 80)) {
    if (b_icf[expl_temp_idx_0]) {
      idx++;
      ii_data[idx - 1] = (int8_T)(expl_temp_idx_0 + 1);
      if (idx >= 80) {
        exitg1 = true;
      } else {
        expl_temp_idx_0++;
      }
    } else {
      expl_temp_idx_0++;
    }
  }
  icf_tmp = ii->size[0];
  if (idx < 1) {
    ii->size[0] = 0;
  } else {
    ii->size[0] = idx;
  }
  emxEnsureCapacity_int8_T(ii, icf_tmp);
  ii_data = ii->data;
  icf_tmp = icf->size[0];
  icf->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(icf, icf_tmp);
  icf_data = icf->data;
  loop_ub = ii->size[0];
  for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
    icf_data[icf_tmp] = ii_data[icf_tmp];
  }
  emxFree_int8_T(&ii);
  emxInit_real_T(&B, 1);
  if (icf->size[0] > 0) {
    icf_tmp = B->size[0];
    B->size[0] = icf->size[0];
    emxEnsureCapacity_real_T(B, icf_tmp);
    Auf_data = B->data;
    loop_ub = icf->size[0];
    for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
      Auf_data[icf_tmp] = Bu[(int32_T)icf_data[icf_tmp] - 1];
    }
    emxInit_real_T(&Auf, 3);
    icf_tmp = Auf->size[0] * Auf->size[1] * Auf->size[2];
    Auf->size[0] = icf->size[0];
    Auf->size[1] = 2;
    Auf->size[2] = 10;
    emxEnsureCapacity_real_T(Auf, icf_tmp);
    Auf_data = Auf->data;
    icf_tmp = icf->size[0];
    for (idx = 0; idx < 2; idx++) {
      for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 10; expl_temp_idx_0++) {
        for (i = 0; i < icf_tmp; i++) {
          Auf_data[(i + Auf->size[0] * idx) +
                   Auf->size[0] * 2 * expl_temp_idx_0] =
              Au[(((int32_T)icf_data[i] + 80 * idx) + 160 * expl_temp_idx_0) -
                 1];
        }
      }
    }
    idx = icf->size[0];
    b_Auf = *Auf;
    c_icf[0] = idx;
    c_icf[1] = 20;
    b_Auf.size = &c_icf[0];
    b_Auf.numDimensions = 2;
    emxInit_real_T(&y, 2);
    mtimes(&b_Auf, y);
    Auf_data = y->data;
    emxFree_real_T(&Auf);
    if (y->size[0] != 0) {
      input_sizes_idx_1_tmp = 10;
    } else {
      input_sizes_idx_1_tmp = 0;
    }
    idx = icf->size[0];
    c_icf_tmp = input_sizes_idx_1_tmp;
    expl_temp_idx_0 = icf->size[0];
    icf_tmp = ref->size[0] * ref->size[1];
    ref->size[0] = icf->size[0];
    ref->size[1] = input_sizes_idx_1_tmp + 41;
    emxEnsureCapacity_real_T(ref, icf_tmp);
    ref_data = ref->data;
    for (icf_tmp = 0; icf_tmp < 40; icf_tmp++) {
      loop_ub = icf->size[0];
      for (b_icf_tmp = 0; b_icf_tmp < loop_ub; b_icf_tmp++) {
        ref_data[b_icf_tmp + ref->size[0] * icf_tmp] = 0.0;
      }
    }
    for (icf_tmp = 0; icf_tmp < c_icf_tmp; icf_tmp++) {
      for (b_icf_tmp = 0; b_icf_tmp < idx; b_icf_tmp++) {
        ref_data[b_icf_tmp + ref->size[0] * (icf_tmp + 40)] =
            Auf_data[b_icf_tmp + idx * icf_tmp];
      }
    }
    emxFree_real_T(&y);
    for (icf_tmp = 0; icf_tmp < expl_temp_idx_0; icf_tmp++) {
      ref_data[icf_tmp + ref->size[0] * (input_sizes_idx_1_tmp + 40)] = 0.0;
    }
  } else {
    B->size[0] = 0;
    ref->size[0] = 0;
    ref->size[1] = 61;
  }
  emxFree_real_T(&icf);
  emxInit_real_T(&b_initX, 2);
  icf_tmp = b_initX->size[0] * b_initX->size[1];
  b_initX->size[0] = initX->size[1];
  b_initX->size[1] = initX->size[0];
  emxEnsureCapacity_real_T(b_initX, icf_tmp);
  Auf_data = b_initX->data;
  loop_ub = initX->size[0];
  for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
    idx = initX->size[1];
    for (b_icf_tmp = 0; b_icf_tmp < idx; b_icf_tmp++) {
      Auf_data[b_icf_tmp + b_initX->size[0] * icf_tmp] =
          initX_data[icf_tmp + initX->size[0] * b_icf_tmp];
    }
  }
  icf_tmp = initX->size[0] * initX->size[1];
  initX->size[0] = initMV->size[1];
  initX->size[1] = initMV->size[0];
  emxEnsureCapacity_real_T(initX, icf_tmp);
  initX_data = initX->data;
  loop_ub = initMV->size[0];
  for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
    idx = initMV->size[1];
    for (b_icf_tmp = 0; b_icf_tmp < idx; b_icf_tmp++) {
      initX_data[b_icf_tmp + initX->size[0] * icf_tmp] =
          initMV_data[icf_tmp + initMV->size[0] * b_icf_tmp];
    }
  }
  emxFree_real_T(&initMV);
  for (icf_tmp = 0; icf_tmp < 10; icf_tmp++) {
    Bu_idx_1 = 0.0;
    for (b_icf_tmp = 0; b_icf_tmp < 20; b_icf_tmp++) {
      Bu_idx_1 += (real_T)b_a[icf_tmp + 10 * b_icf_tmp] * initX_data[b_icf_tmp];
    }
    a[icf_tmp] = Bu_idx_1;
  }
  emxFree_real_T(&initX);
  for (icf_tmp = 0; icf_tmp < 40; icf_tmp++) {
    z[icf_tmp] = Auf_data[icf_tmp];
  }
  emxFree_real_T(&b_initX);
  memcpy(&z[40], &a[0], 10U * sizeof(real_T));
  z[50] = onlinedata->Slack0;
  b_expl_temp.Parameters = onlinedata->Parameters;
  for (icf_tmp = 0; icf_tmp < 20; icf_tmp++) {
    b_icf_tmp = t5_f1[icf_tmp];
    b_expl_temp.MVRateMax[icf_tmp] = b_icf_tmp;
    b_expl_temp.MVRateMin[icf_tmp] = t4_f1[icf_tmp];
    b_expl_temp.MVMax[icf_tmp] = b_icf_tmp;
    b_expl_temp.MVMin[icf_tmp] = t2_f1[icf_tmp];
  }
  memcpy(&b_expl_temp.StateMax[0], &c_CostFcn_workspace_runtimedata[0],
         40U * sizeof(real_T));
  memcpy(&b_expl_temp.StateMin[0], &d_CostFcn_workspace_runtimedata[0],
         40U * sizeof(real_T));
  b_expl_temp.ECRWeight = 100000.0;
  memset(&b_expl_temp.MVWeights[0], 0, 20U * sizeof(real_T));
  for (i = 0; i < 10; i++) {
    b_expl_temp.OutputWeights[i] = 1.0;
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
  expl_temp.NumOfOutputs = 1.0;
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
  emxInitStruct_struct_T(&c_expl_temp);
  c_expl_temp.Parameters = onlinedata->Parameters;
  icf_tmp =
      c_expl_temp.MVScaledTarget->size[0] * c_expl_temp.MVScaledTarget->size[1];
  c_expl_temp.MVScaledTarget->size[0] = b_expl_temp.MVScaledTarget->size[0];
  c_expl_temp.MVScaledTarget->size[1] = b_expl_temp.MVScaledTarget->size[1];
  emxEnsureCapacity_real_T(c_expl_temp.MVScaledTarget, icf_tmp);
  loop_ub =
      b_expl_temp.MVScaledTarget->size[0] * b_expl_temp.MVScaledTarget->size[1];
  for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
    c_expl_temp.MVScaledTarget->data[icf_tmp] =
        b_expl_temp.MVScaledTarget->data[icf_tmp];
  }
  for (icf_tmp = 0; icf_tmp < 20; icf_tmp++) {
    b_icf_tmp = t5_f1[icf_tmp];
    c_expl_temp.MVRateMax[icf_tmp] = b_icf_tmp;
    c_expl_temp.MVRateMin[icf_tmp] = t4_f1[icf_tmp];
    c_expl_temp.MVMax[icf_tmp] = b_icf_tmp;
    c_expl_temp.MVMin[icf_tmp] = t2_f1[icf_tmp];
  }
  memcpy(&c_expl_temp.StateMax[0], &c_CostFcn_workspace_runtimedata[0],
         40U * sizeof(real_T));
  memcpy(&c_expl_temp.StateMin[0], &d_CostFcn_workspace_runtimedata[0],
         40U * sizeof(real_T));
  for (i = 0; i < 10; i++) {
    c_expl_temp.OutputMax[i] = rtInf;
    c_expl_temp.OutputMin[i] = rtMinusInf;
  }
  c_expl_temp.ECRWeight = 100000.0;
  for (icf_tmp = 0; icf_tmp < 20; icf_tmp++) {
    c_expl_temp.MVRateWeights[icf_tmp] = 0.1;
    c_expl_temp.MVWeights[icf_tmp] = 0.0;
  }
  for (i = 0; i < 10; i++) {
    c_expl_temp.OutputWeights[i] = 1.0;
  }
  icf_tmp = c_expl_temp.ref->size[0] * c_expl_temp.ref->size[1];
  c_expl_temp.ref->size[0] = b_expl_temp.ref->size[0];
  c_expl_temp.ref->size[1] = 1;
  emxEnsureCapacity_real_T(c_expl_temp.ref, icf_tmp);
  loop_ub = b_expl_temp.ref->size[0];
  for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
    c_expl_temp.ref->data[icf_tmp] = b_expl_temp.ref->data[icf_tmp];
  }
  c_expl_temp.lastMV[0] = lastMV[0];
  c_expl_temp.lastMV[1] = lastMV[1];
  c_expl_temp.x[0] = x[0];
  c_expl_temp.x[1] = x[1];
  c_expl_temp.x[2] = x[2];
  c_expl_temp.x[3] = x[3];
  emxInitStruct_struct_T1(&d_expl_temp);
  d_expl_temp.PassivityUsePredictedX = true;
  d_expl_temp.OutputPassivityIndex = 0.1;
  d_expl_temp.InputPassivityIndex = 0.0;
  d_expl_temp.MVIndex[0] = 1.0;
  d_expl_temp.MVIndex[1] = 2.0;
  d_expl_temp.NumOfInputs = 2.0;
  d_expl_temp.NumOfOutputs = 1.0;
  d_expl_temp.NumOfStates = 4.0;
  d_expl_temp.PredictionHorizon = 10.0;
  icf_tmp = d_expl_temp.MVTarget->size[0] * d_expl_temp.MVTarget->size[1];
  d_expl_temp.MVTarget->size[0] = expl_temp.MVTarget->size[0];
  d_expl_temp.MVTarget->size[1] = expl_temp.MVTarget->size[1];
  emxEnsureCapacity_real_T(d_expl_temp.MVTarget, icf_tmp);
  loop_ub = expl_temp.MVTarget->size[0] * expl_temp.MVTarget->size[1];
  for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
    d_expl_temp.MVTarget->data[icf_tmp] = expl_temp.MVTarget->data[icf_tmp];
  }
  icf_tmp = d_expl_temp.References->size[0] * d_expl_temp.References->size[1];
  d_expl_temp.References->size[0] = expl_temp.References->size[0];
  d_expl_temp.References->size[1] = 1;
  emxEnsureCapacity_real_T(d_expl_temp.References, icf_tmp);
  loop_ub = expl_temp.References->size[0];
  for (icf_tmp = 0; icf_tmp < loop_ub; icf_tmp++) {
    d_expl_temp.References->data[icf_tmp] = expl_temp.References->data[icf_tmp];
  }
  d_expl_temp.LastMV[0] = lastMV[0];
  d_expl_temp.LastMV[1] = lastMV[1];
  d_expl_temp.CurrentStates[0] = x[0];
  d_expl_temp.CurrentStates[1] = x[1];
  d_expl_temp.CurrentStates[2] = x[2];
  d_expl_temp.CurrentStates[3] = x[3];
  d_expl_temp.Ts = 0.1;
  for (icf_tmp = 0; icf_tmp < 10; icf_tmp++) {
    expl_temp_idx_0 = icf_tmp << 2;
    b_x[expl_temp_idx_0] = d_CostFcn_workspace_runtimedata[icf_tmp];
    e_CostFcn_workspace_runtimedata[expl_temp_idx_0] =
        c_CostFcn_workspace_runtimedata[icf_tmp];
    b_x[expl_temp_idx_0 + 1] = d_CostFcn_workspace_runtimedata[icf_tmp + 10];
    e_CostFcn_workspace_runtimedata[expl_temp_idx_0 + 1] =
        c_CostFcn_workspace_runtimedata[icf_tmp + 10];
    b_x[expl_temp_idx_0 + 2] = d_CostFcn_workspace_runtimedata[icf_tmp + 20];
    e_CostFcn_workspace_runtimedata[expl_temp_idx_0 + 2] =
        c_CostFcn_workspace_runtimedata[icf_tmp + 20];
    b_x[expl_temp_idx_0 + 3] = d_CostFcn_workspace_runtimedata[icf_tmp + 30];
    e_CostFcn_workspace_runtimedata[expl_temp_idx_0 + 3] =
        c_CostFcn_workspace_runtimedata[icf_tmp + 30];
  }
  memcpy(&f_CostFcn_workspace_runtimedata[0], &b_x[0], 40U * sizeof(real_T));
  for (icf_tmp = 0; icf_tmp < 10; icf_tmp++) {
    f_CostFcn_workspace_runtimedata[icf_tmp + 40] = rtMinusInf;
  }
  f_CostFcn_workspace_runtimedata[50] = 0.0;
  memcpy(&g_CostFcn_workspace_runtimedata[0],
         &e_CostFcn_workspace_runtimedata[0], 40U * sizeof(real_T));
  for (icf_tmp = 0; icf_tmp < 10; icf_tmp++) {
    g_CostFcn_workspace_runtimedata[icf_tmp + 40] = rtInf;
  }
  char_T e_expl_temp[3];
  g_CostFcn_workspace_runtimedata[50] = rtInf;
  info->Cost = fmincon(
      &b_expl_temp, &expl_temp, z, ref, B, f_CostFcn_workspace_runtimedata,
      g_CostFcn_workspace_runtimedata, &c_expl_temp, &d_expl_temp, &ExitFlag,
      &Out_iterations, &Bu_idx_1, e_expl_temp, &Out_constrviolation,
      &f_expl_temp, &g_expl_temp, &h_expl_temp);
  emxFreeStruct_struct_T1(&d_expl_temp);
  emxFreeStruct_struct_T(&c_expl_temp);
  emxFreeStruct_struct_T1(&expl_temp);
  emxFreeStruct_struct_T(&b_expl_temp);
  emxFree_real_T(&ref);
  emxFree_real_T(&B);
  if (((int32_T)muDoubleScalarRound(ExitFlag) == 0) &&
      (Out_constrviolation > 1.0E-6)) {
    ExitFlag = -2.0;
  }
  memset(&info->Xopt[0], 0, 44U * sizeof(real_T));
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (icf_tmp = 0; icf_tmp < 20; icf_tmp++) {
    Bu_idx_1 = 0.0;
    for (b_icf_tmp = 0; b_icf_tmp < 10; b_icf_tmp++) {
      Bu_idx_1 += (real_T)iv[icf_tmp + 20 * b_icf_tmp] * z[b_icf_tmp + 40];
    }
    b_lastMV[icf_tmp] = Bu_idx_1;
  }
  for (icf_tmp = 0; icf_tmp < 2; icf_tmp++) {
    for (b_icf_tmp = 0; b_icf_tmp < 10; b_icf_tmp++) {
      Umv[b_icf_tmp + 11 * icf_tmp] = b_lastMV[icf_tmp + (b_icf_tmp << 1)];
    }
  }
  memcpy(&b_x[0], &z[0], 40U * sizeof(real_T));
  for (icf_tmp = 0; icf_tmp < 4; icf_tmp++) {
    for (b_icf_tmp = 0; b_icf_tmp < 10; b_icf_tmp++) {
      info->Xopt[(b_icf_tmp + 11 * icf_tmp) + 1] =
          b_x[icf_tmp + (b_icf_tmp << 2)];
    }
    info->Xopt[11 * icf_tmp] = x[icf_tmp];
  }
  for (i = 0; i < 2; i++) {
    Umv[11 * i + 10] = Umv[11 * i + 9];
    memcpy(&info->MVopt[i * 11], &Umv[i * 11], 11U * sizeof(real_T));
  }
  if (ExitFlag > 0.0) {
    mv[0] = info->MVopt[0];
    mv[1] = info->MVopt[11];
  } else {
    mv[0] = lastMV[0];
    mv[1] = lastMV[1];
  }
  info->ExitFlag = ExitFlag;
  info->Iterations = Out_iterations;
  onlinedata->Slack0 = muDoubleScalarMax(0.0, z[50]);
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 11; expl_temp_idx_0++) {
    info->Yopt[expl_temp_idx_0] = 0.0;
    info->Topt[expl_temp_idx_0] = 0.1 * (real_T)expl_temp_idx_0;
  }
  info->Slack = z[50];
  icf_tmp = onlinedata->X0->size[0] * onlinedata->X0->size[1];
  onlinedata->X0->size[0] = 10;
  onlinedata->X0->size[1] = 4;
  emxEnsureCapacity_real_T(onlinedata->X0, icf_tmp);
  for (icf_tmp = 0; icf_tmp < 4; icf_tmp++) {
    for (b_icf_tmp = 0; b_icf_tmp < 10; b_icf_tmp++) {
      onlinedata->X0->data[b_icf_tmp + onlinedata->X0->size[0] * icf_tmp] =
          info->Xopt[b_iv[b_icf_tmp] + 11 * icf_tmp];
    }
  }
  icf_tmp = onlinedata->MV0->size[0] * onlinedata->MV0->size[1];
  onlinedata->MV0->size[0] = 10;
  onlinedata->MV0->size[1] = 2;
  emxEnsureCapacity_real_T(onlinedata->MV0, icf_tmp);
  for (icf_tmp = 0; icf_tmp < 2; icf_tmp++) {
    for (b_icf_tmp = 0; b_icf_tmp < 10; b_icf_tmp++) {
      onlinedata->MV0->data[b_icf_tmp + onlinedata->MV0->size[0] * icf_tmp] =
          info->MVopt[(b_icf_tmp + 11 * icf_tmp) + 1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (nlmpcmoveCodeGeneration.c) */
