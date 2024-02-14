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
    const real_T runtimedata_x[4], const real_T runtimedata_OutputMin[40],
    const real_T runtimedata_OutputMax[40], real_T runtimedata_Parameters_f1,
    real_T runtimedata_Parameters_f2, const real_T z[51],
    emxArray_real_T *varargout_1, real_T varargout_2[40],
    emxArray_real_T *varargout_3, real_T varargout_4[2040])
{
  __m128d r;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emxArray_int8_T *Je;
  emxArray_int8_T *r1;
  emxArray_real_T *Jc;
  emxArray_real_T *b_Jx;
  emxArray_real_T *b_c;
  emxArray_real_T *c;
  emxArray_real_T *c_y;
  emxArray_real_T *r2;
  emxArray_real_T *varargin_1;
  emxArray_real_T *varargin_2;
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
  real_T b_val[8];
  real_T f[4];
  real_T xa[4];
  real_T xk[4];
  real_T xk1[4];
  real_T b_uk_tmp;
  real_T c_uk_tmp;
  real_T d;
  real_T du;
  real_T dx;
  real_T e;
  real_T ua_idx_0;
  real_T ua_idx_1;
  real_T *Jc_data;
  real_T *b_c_data;
  real_T *c_data;
  real_T *varargin_1_data;
  int32_T U_tmp;
  int32_T b_i;
  int32_T b_icf_tmp;
  int32_T i;
  int32_T icf_tmp;
  int32_T j;
  int32_T uk_tmp;
  char_T TRANSA1;
  char_T TRANSB1;
  int8_T b_Je[80];
  int8_T ic[4];
  int8_T i1;
  int8_T i2;
  int8_T input_sizes_idx_0;
  int8_T input_sizes_idx_1;
  int8_T *Je_data;
  int8_T *r6;
  boolean_T bv[40];
  boolean_T x[4];
  boolean_T b_y;
  boolean_T exitg1;
  boolean_T guard1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  memset(&X[0], 0, 44U * sizeof(real_T));
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (i = 0; i < 20; i++) {
    d = 0.0;
    for (icf_tmp = 0; icf_tmp < 10; icf_tmp++) {
      d += (real_T)iv[i + 20 * icf_tmp] * z[icf_tmp + 40];
    }
    a[i] = d;
  }
  for (i = 0; i < 2; i++) {
    for (icf_tmp = 0; icf_tmp < 10; icf_tmp++) {
      Umv[icf_tmp + 11 * i] = a[i + (icf_tmp << 1)];
    }
  }
  e = z[50];
  memcpy(&b_z[0], &z[0], 40U * sizeof(real_T));
  for (i = 0; i < 4; i++) {
    for (icf_tmp = 0; icf_tmp < 10; icf_tmp++) {
      X[(icf_tmp + 11 * i) + 1] = b_z[i + (icf_tmp << 2)];
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
  for (b_i = 0; b_i < 10; b_i++) {
    __m128d r3;
    __m128d r4;
    __m128d r5;
    real_T uk[2];
    uk_tmp = b_i << 1;
    b_uk_tmp = Umv[uk_tmp];
    c_uk_tmp = Umv[uk_tmp + 1];
    uk[1] = c_uk_tmp;
    U_tmp = b_i << 2;
    vehicleDynamics_Simple(&b_X[U_tmp], &Umv[uk_tmp], runtimedata_Parameters_f1,
                           runtimedata_Parameters_f2, xk1);
    d = b_X[U_tmp];
    xk[0] = d;
    xa[0] = muDoubleScalarAbs(d);
    d = b_X[U_tmp + 1];
    xk[1] = d;
    xa[1] = muDoubleScalarAbs(d);
    d = b_X[U_tmp + 2];
    xk[2] = d;
    xa[2] = muDoubleScalarAbs(d);
    d = b_X[U_tmp + 3];
    xk[3] = d;
    xa[3] = muDoubleScalarAbs(d);
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
      vehicleDynamics_Simple(xk, &Umv[uk_tmp], runtimedata_Parameters_f1,
                             runtimedata_Parameters_f2, f);
      xk[j] -= dx;
      r3 = _mm_loadu_pd(&f[0]);
      r4 = _mm_loadu_pd(&xk1[0]);
      i = j << 2;
      r5 = _mm_set1_pd(dx);
      _mm_storeu_pd(&val[i], _mm_div_pd(_mm_sub_pd(r3, r4), r5));
      r3 = _mm_loadu_pd(&f[2]);
      r4 = _mm_loadu_pd(&xk1[2]);
      _mm_storeu_pd(&val[i + 2], _mm_div_pd(_mm_sub_pd(r3, r4), r5));
    }
    ua_idx_0 = muDoubleScalarAbs(b_uk_tmp);
    ua_idx_1 = muDoubleScalarAbs(c_uk_tmp);
    if (ua_idx_0 < 1.0) {
      ua_idx_0 = 1.0;
    }
    if (ua_idx_1 < 1.0) {
      ua_idx_1 = 1.0;
    }
    du = 1.0E-6 * ua_idx_0;
    uk[0] = b_uk_tmp + du;
    vehicleDynamics_Simple(xk, uk, runtimedata_Parameters_f1,
                           runtimedata_Parameters_f2, f);
    uk[0] -= du;
    r3 = _mm_loadu_pd(&f[0]);
    r4 = _mm_loadu_pd(&xk1[0]);
    r5 = _mm_set1_pd(du);
    _mm_storeu_pd(&b_val[0], _mm_div_pd(_mm_sub_pd(r3, r4), r5));
    r3 = _mm_loadu_pd(&f[2]);
    r4 = _mm_loadu_pd(&xk1[2]);
    _mm_storeu_pd(&b_val[2], _mm_div_pd(_mm_sub_pd(r3, r4), r5));
    du = 1.0E-6 * ua_idx_1;
    uk[1] = c_uk_tmp + du;
    vehicleDynamics_Simple(xk, uk, runtimedata_Parameters_f1,
                           runtimedata_Parameters_f2, f);
    r3 = _mm_loadu_pd(&f[0]);
    r4 = _mm_loadu_pd(&xk1[0]);
    r5 = _mm_set1_pd(du);
    _mm_storeu_pd(&b_val[4], _mm_div_pd(_mm_sub_pd(r3, r4), r5));
    r3 = _mm_loadu_pd(&f[2]);
    r4 = _mm_loadu_pd(&xk1[2]);
    _mm_storeu_pd(&b_val[6], _mm_div_pd(_mm_sub_pd(r3, r4), r5));
    U_tmp = (b_i + 1) << 2;
    input_sizes_idx_0 = ic[0];
    varargout_2[ic[0] - 1] = b_X[U_tmp] - xk1[0];
    Jx[(ic[0] + 160 * b_i) - 1] = 1.0;
    input_sizes_idx_1 = ic[1];
    varargout_2[ic[1] - 1] = b_X[U_tmp + 1] - xk1[1];
    Jx[(ic[1] + 160 * b_i) + 39] = 1.0;
    i1 = ic[2];
    varargout_2[ic[2] - 1] = b_X[U_tmp + 2] - xk1[2];
    Jx[(ic[2] + 160 * b_i) + 79] = 1.0;
    i2 = ic[3];
    varargout_2[ic[3] - 1] = b_X[U_tmp + 3] - xk1[3];
    Jx[(ic[3] + 160 * b_i) + 119] = 1.0;
    if (b_i + 1 > 1) {
      for (i = 0; i <= 14; i += 2) {
        r3 = _mm_loadu_pd(&val[i]);
        _mm_storeu_pd(&val[i], _mm_mul_pd(r3, _mm_set1_pd(-1.0)));
      }
      uk_tmp = 160 * (b_i - 1);
      for (j = 0; j < 4; j++) {
        U_tmp = j << 2;
        Jx[((input_sizes_idx_0 + 40 * j) + uk_tmp) - 1] = val[U_tmp];
        Jx[((input_sizes_idx_1 + 40 * j) + uk_tmp) - 1] = val[U_tmp + 1];
        Jx[((i1 + 40 * j) + uk_tmp) - 1] = val[U_tmp + 2];
        Jx[((i2 + 40 * j) + uk_tmp) - 1] = val[U_tmp + 3];
      }
    }
    r3 = _mm_loadu_pd(&b_val[0]);
    _mm_storeu_pd(&b_val[0], _mm_mul_pd(r3, r));
    r3 = _mm_loadu_pd(&b_val[2]);
    _mm_storeu_pd(&b_val[2], _mm_mul_pd(r3, r));
    r3 = _mm_loadu_pd(&b_val[4]);
    _mm_storeu_pd(&b_val[4], _mm_mul_pd(r3, r));
    r3 = _mm_loadu_pd(&b_val[6]);
    _mm_storeu_pd(&b_val[6], _mm_mul_pd(r3, r));
    for (j = 0; j < 2; j++) {
      U_tmp = j << 2;
      Jmv[((input_sizes_idx_0 + 40 * j) + 80 * b_i) - 1] = b_val[U_tmp];
      Jmv[((input_sizes_idx_1 + 40 * j) + 80 * b_i) - 1] = b_val[U_tmp + 1];
      Jmv[((i1 + 40 * j) + 80 * b_i) - 1] = b_val[U_tmp + 2];
      Jmv[((i2 + 40 * j) + 80 * b_i) - 1] = b_val[U_tmp + 3];
    }
    ic[0] = (int8_T)(ic[0] + 4);
    ic[1] = (int8_T)(ic[1] + 4);
    ic[2] = (int8_T)(ic[2] + 4);
    ic[3] = (int8_T)(ic[3] + 4);
  }
  TRANSB1 = 'N';
  TRANSA1 = 'N';
  ua_idx_0 = 1.0;
  du = 0.0;
  m_t = (ptrdiff_t)40;
  n_t = (ptrdiff_t)10;
  k_t = (ptrdiff_t)20;
  lda_t = (ptrdiff_t)40;
  ldb_t = (ptrdiff_t)20;
  ldc_t = (ptrdiff_t)40;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &ua_idx_0, &Jmv[0], &lda_t,
        (real_T *)&dv[0], &ldb_t, &du, &y[0], &ldc_t);
  for (i = 0; i < 40; i++) {
    bv[i] = muDoubleScalarIsInf(runtimedata_OutputMin[i]);
  }
  all(bv, x);
  b_y = true;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j <= 3)) {
    if (!x[j]) {
      b_y = false;
      exitg1 = true;
    } else {
      j++;
    }
  }
  emxInit_real_T(&c, 2);
  c_data = c->data;
  emxInit_real_T(&Jc, 2);
  Jc_data = Jc->data;
  emxInit_int8_T(&r1, 1);
  emxInit_real_T(&c_y, 2);
  emxInit_real_T(&varargin_1, 2);
  emxInit_real_T(&varargin_2, 2);
  emxInit_real_T(&b_c, 1);
  emxInit_real_T(&r2, 2);
  emxInit_real_T(&b_Jx, 3);
  emxInit_int8_T(&Je, 2);
  guard1 = false;
  if (b_y) {
    for (i = 0; i < 40; i++) {
      bv[i] = muDoubleScalarIsInf(runtimedata_OutputMax[i]);
    }
    all(bv, x);
    b_y = true;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j <= 3)) {
      if (!x[j]) {
        b_y = false;
        exitg1 = true;
      } else {
        j++;
      }
    }
    if (b_y) {
      c->size[0] = 0;
      c->size[1] = 0;
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
    memset(&b_Je[0], 0, 80U * sizeof(int8_T));
    ic[0] = 1;
    ic[1] = 2;
    ic[2] = 3;
    ic[3] = 4;
    for (b_i = 0; b_i < 10; b_i++) {
      int32_T c_icf_tmp;
      int32_T d_icf_tmp;
      d = runtimedata_OutputMin[b_i];
      input_sizes_idx_0 = ic[0];
      icf[ic[0] - 1] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      xk1[0] = (real_T)ic[0] + 4.0;
      d = runtimedata_OutputMin[b_i + 10];
      input_sizes_idx_1 = ic[1];
      icf[ic[1] - 1] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      xk1[1] = (real_T)ic[1] + 4.0;
      d = runtimedata_OutputMin[b_i + 20];
      i1 = ic[2];
      icf[ic[2] - 1] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      xk1[2] = (real_T)ic[2] + 4.0;
      d = runtimedata_OutputMin[b_i + 30];
      i2 = ic[3];
      icf[ic[3] - 1] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      xk1[3] = (real_T)ic[3] + 4.0;
      d = runtimedata_OutputMax[b_i];
      b_icf_tmp = (int32_T)xk1[0] - 1;
      icf[b_icf_tmp] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      d = runtimedata_OutputMax[b_i + 10];
      icf_tmp = (int32_T)xk1[1] - 1;
      icf[icf_tmp] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      ua_idx_0 = runtimedata_OutputMax[b_i + 20];
      c_icf_tmp = (int32_T)xk1[2] - 1;
      icf[c_icf_tmp] = ((!muDoubleScalarIsInf(ua_idx_0)) &&
                        (!muDoubleScalarIsNaN(ua_idx_0)));
      du = runtimedata_OutputMax[b_i + 30];
      d_icf_tmp = (int32_T)xk1[3] - 1;
      icf[d_icf_tmp] =
          ((!muDoubleScalarIsInf(du)) && (!muDoubleScalarIsNaN(du)));
      b_y = false;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j <= 7)) {
        int16_T b_ic[8];
        b_ic[0] = (int16_T)(input_sizes_idx_0 - 1);
        b_ic[4] = (int16_T)(ic[0] + 3);
        b_ic[1] = (int16_T)(input_sizes_idx_1 - 1);
        b_ic[5] = (int16_T)(ic[1] + 3);
        b_ic[2] = (int16_T)(i1 - 1);
        b_ic[6] = (int16_T)(ic[2] + 3);
        b_ic[3] = (int16_T)(i2 - 1);
        b_ic[7] = (int16_T)(ic[3] + 3);
        if (icf[b_ic[j]]) {
          b_y = true;
          exitg1 = true;
        } else {
          j++;
        }
      }
      if (b_y) {
        real_T d1;
        ua_idx_1 = X[b_i + 1];
        xk[0] = ua_idx_1;
        xa[0] = muDoubleScalarAbs(ua_idx_1);
        b_uk_tmp = X[b_i + 12];
        xk[1] = b_uk_tmp;
        xa[1] = muDoubleScalarAbs(b_uk_tmp);
        c_uk_tmp = X[b_i + 23];
        xk[2] = c_uk_tmp;
        xa[2] = muDoubleScalarAbs(c_uk_tmp);
        d1 = X[b_i + 34];
        xk[3] = d1;
        xa[3] = muDoubleScalarAbs(d1);
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
          U_tmp = j << 2;
          Ck[U_tmp] = (xk[0] - ua_idx_1) / dx;
          Ck[U_tmp + 1] = (xk[1] - b_uk_tmp) / dx;
          Ck[U_tmp + 2] = (xk[2] - c_uk_tmp) / dx;
          Ck[U_tmp + 3] = (xk[3] - d1) / dx;
          xk[j] -= dx;
          c_c[ic[j] - 1] =
              (runtimedata_OutputMin[b_i + 10 * j] - e) - X[(b_i + 11 * j) + 1];
        }
        input_sizes_idx_0 = ic[0];
        c_c[ic[0] + 3] = (ua_idx_1 - runtimedata_OutputMax[b_i]) - e;
        input_sizes_idx_1 = ic[1];
        c_c[ic[1] + 3] = (b_uk_tmp - d) - e;
        i1 = ic[2];
        c_c[ic[2] + 3] = (c_uk_tmp - ua_idx_0) - e;
        i2 = ic[3];
        c_c[ic[3] + 3] = (d1 - du) - e;
        for (i = 0; i <= 14; i += 2) {
          r = _mm_loadu_pd(&Ck[i]);
          _mm_storeu_pd(&val[i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
        }
        for (j = 0; j < 4; j++) {
          uk_tmp = j << 2;
          c_Jx[((input_sizes_idx_0 + 80 * j) + 320 * b_i) - 1] = val[uk_tmp];
          c_Jx[((input_sizes_idx_1 + 80 * j) + 320 * b_i) - 1] =
              val[uk_tmp + 1];
          c_Jx[((i1 + 80 * j) + 320 * b_i) - 1] = val[uk_tmp + 2];
          c_Jx[((i2 + 80 * j) + 320 * b_i) - 1] = val[uk_tmp + 3];
        }
        for (j = 0; j < 4; j++) {
          uk_tmp = j << 2;
          c_Jx[((ic[0] + 80 * j) + 320 * b_i) + 3] = Ck[uk_tmp];
          c_Jx[((ic[1] + 80 * j) + 320 * b_i) + 3] = Ck[uk_tmp + 1];
          c_Jx[((ic[2] + 80 * j) + 320 * b_i) + 3] = Ck[uk_tmp + 2];
          c_Jx[((ic[3] + 80 * j) + 320 * b_i) + 3] = Ck[uk_tmp + 3];
          b_Je[ic[j] - 1] = -1;
        }
        b_Je[b_icf_tmp] = -1;
        b_Je[icf_tmp] = -1;
        b_Je[c_icf_tmp] = -1;
        b_Je[d_icf_tmp] = -1;
      }
      ic[0] = (int8_T)(ic[0] + 8);
      ic[1] = (int8_T)(ic[1] + 8);
      ic[2] = (int8_T)(ic[2] + 8);
      ic[3] = (int8_T)(ic[3] + 8);
    }
    U_tmp = 0;
    for (b_i = 0; b_i < 80; b_i++) {
      if (icf[b_i]) {
        U_tmp++;
      }
    }
    i = r1->size[0];
    r1->size[0] = U_tmp;
    emxEnsureCapacity_int8_T(r1, i);
    r6 = r1->data;
    U_tmp = 0;
    for (b_i = 0; b_i < 80; b_i++) {
      if (icf[b_i]) {
        r6[U_tmp] = (int8_T)b_i;
        U_tmp++;
      }
    }
    i = b_c->size[0];
    b_c->size[0] = r1->size[0];
    emxEnsureCapacity_real_T(b_c, i);
    b_c_data = b_c->data;
    b_icf_tmp = r1->size[0];
    for (i = 0; i < b_icf_tmp; i++) {
      b_c_data[i] = c_c[r6[i]];
    }
    i = c->size[0] * c->size[1];
    c->size[0] = r1->size[0];
    c->size[1] = 1;
    emxEnsureCapacity_real_T(c, i);
    c_data = c->data;
    b_icf_tmp = r1->size[0];
    for (i = 0; i < b_icf_tmp; i++) {
      c_data[i] = b_c_data[i];
    }
    if (r1->size[0] == 0) {
      Jc->size[0] = 0;
      Jc->size[1] = 0;
    } else {
      i = r2->size[0] * r2->size[1];
      r2->size[0] = r1->size[0];
      r2->size[1] = 20;
      emxEnsureCapacity_real_T(r2, i);
      b_c_data = r2->data;
      b_icf_tmp = r1->size[0] * 20;
      for (i = 0; i < b_icf_tmp; i++) {
        b_c_data[i] = 0.0;
      }
      mtimes(r2, c_y);
      Jc_data = c_y->data;
      i = b_Jx->size[0] * b_Jx->size[1] * b_Jx->size[2];
      b_Jx->size[0] = r1->size[0];
      b_Jx->size[1] = 4;
      b_Jx->size[2] = 10;
      emxEnsureCapacity_real_T(b_Jx, i);
      b_c_data = b_Jx->data;
      b_icf_tmp = r1->size[0];
      for (i = 0; i < 10; i++) {
        for (icf_tmp = 0; icf_tmp < 4; icf_tmp++) {
          for (U_tmp = 0; U_tmp < b_icf_tmp; U_tmp++) {
            b_c_data[(U_tmp + b_Jx->size[0] * icf_tmp) +
                     b_Jx->size[0] * 4 * i] =
                c_Jx[(r6[U_tmp] + 80 * icf_tmp) + 320 * i];
          }
        }
      }
      U_tmp = r1->size[0];
      i = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = 40;
      varargin_1->size[1] = r1->size[0];
      emxEnsureCapacity_real_T(varargin_1, i);
      varargin_1_data = varargin_1->data;
      b_icf_tmp = r1->size[0];
      for (i = 0; i < b_icf_tmp; i++) {
        for (icf_tmp = 0; icf_tmp < 40; icf_tmp++) {
          varargin_1_data[icf_tmp + 40 * i] = b_c_data[i + U_tmp * icf_tmp];
        }
      }
      i = varargin_2->size[0] * varargin_2->size[1];
      varargin_2->size[0] = 10;
      varargin_2->size[1] = c_y->size[0];
      emxEnsureCapacity_real_T(varargin_2, i);
      b_c_data = varargin_2->data;
      b_icf_tmp = c_y->size[0];
      for (i = 0; i < b_icf_tmp; i++) {
        for (icf_tmp = 0; icf_tmp < 10; icf_tmp++) {
          b_c_data[icf_tmp + 10 * i] = Jc_data[i + c_y->size[0] * icf_tmp];
        }
      }
      U_tmp = varargin_1->size[1];
      if ((varargin_1->size[1] == 0) || (varargin_2->size[1] != 0)) {
        input_sizes_idx_0 = 10;
      } else {
        input_sizes_idx_0 = 0;
      }
      uk_tmp = input_sizes_idx_0;
      i = Je->size[0] * Je->size[1];
      Je->size[0] = 1;
      Je->size[1] = r1->size[0];
      emxEnsureCapacity_int8_T(Je, i);
      Je_data = Je->data;
      b_icf_tmp = r1->size[0];
      for (i = 0; i < b_icf_tmp; i++) {
        Je_data[i] = b_Je[r6[i]];
      }
      i = Jc->size[0] * Jc->size[1];
      Jc->size[0] = input_sizes_idx_0 + 41;
      Jc->size[1] = varargin_1->size[1];
      emxEnsureCapacity_real_T(Jc, i);
      Jc_data = Jc->data;
      for (i = 0; i < U_tmp; i++) {
        for (icf_tmp = 0; icf_tmp < 40; icf_tmp++) {
          Jc_data[icf_tmp + Jc->size[0] * i] =
              varargin_1_data[icf_tmp + 40 * i];
        }
        for (icf_tmp = 0; icf_tmp < uk_tmp; icf_tmp++) {
          Jc_data[(icf_tmp + Jc->size[0] * i) + 40] =
              b_c_data[icf_tmp + input_sizes_idx_0 * i];
        }
        Jc_data[(input_sizes_idx_0 + Jc->size[0] * i) + 40] = Je_data[i];
      }
    }
  }
  emxFree_int8_T(&Je);
  emxFree_real_T(&b_Jx);
  emxFree_real_T(&r2);
  emxFree_real_T(&b_c);
  emxFree_real_T(&varargin_2);
  emxFree_real_T(&varargin_1);
  emxFree_real_T(&c_y);
  emxFree_int8_T(&r1);
  b_y = ((c->size[0] != 0) && (c->size[1] != 0));
  input_sizes_idx_0 = (int8_T)c->size[0];
  i = varargout_1->size[0] * varargout_1->size[1];
  varargout_1->size[0] = input_sizes_idx_0;
  U_tmp = b_y;
  varargout_1->size[1] = b_y;
  emxEnsureCapacity_real_T(varargout_1, i);
  b_c_data = varargout_1->data;
  for (i = 0; i < U_tmp; i++) {
    b_icf_tmp = input_sizes_idx_0;
    for (icf_tmp = 0; icf_tmp < b_icf_tmp; icf_tmp++) {
      b_c_data[icf_tmp] = c_data[icf_tmp];
    }
  }
  emxFree_real_T(&c);
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
  b_icf_tmp = input_sizes_idx_1;
  for (i = 0; i < b_icf_tmp; i++) {
    U_tmp = input_sizes_idx_0;
    for (icf_tmp = 0; icf_tmp < U_tmp; icf_tmp++) {
      b_c_data[icf_tmp + varargout_3->size[0] * i] =
          Jc_data[icf_tmp + input_sizes_idx_0 * i];
    }
  }
  emxFree_real_T(&Jc);
  for (i = 0; i < 40; i++) {
    for (icf_tmp = 0; icf_tmp < 40; icf_tmp++) {
      varargout_4[icf_tmp + 51 * i] = Jx[i + 40 * icf_tmp];
    }
    for (icf_tmp = 0; icf_tmp < 10; icf_tmp++) {
      varargout_4[(icf_tmp + 51 * i) + 40] = y[i + 40 * icf_tmp];
    }
    varargout_4[51 * i + 50] = 0.0;
  }
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
  real_T dv1[51];
  real_T z[51];
  real_T b_x[40];
  real_T Umv[22];
  real_T b_lastMV[20];
  real_T a[10];
  real_T ic[2];
  real_T ExitFlag;
  real_T Out_constrviolation;
  real_T Out_iterations;
  real_T c_expl_temp;
  real_T g_expl_temp;
  real_T h_expl_temp;
  real_T i_expl_temp;
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
  ic[0] = 1.0;
  ic[1] = 2.0;
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 10; expl_temp_idx_0++) {
    __m128d r;
    r = _mm_loadu_pd(&ic[0]);
    _mm_storeu_pd(&ic[0], _mm_add_pd(r, _mm_set1_pd(8.0)));
  }
  emxInit_real_T(&B, 1);
  B->size[0] = 0;
  ref->size[0] = 0;
  ref->size[1] = 61;
  emxInit_real_T(&b_initX, 2);
  i = b_initX->size[0] * b_initX->size[1];
  b_initX->size[0] = initX->size[1];
  b_initX->size[1] = initX->size[0];
  emxEnsureCapacity_real_T(b_initX, i);
  ref_data = b_initX->data;
  loop_ub = initX->size[0];
  for (i = 0; i < loop_ub; i++) {
    expl_temp_idx_0 = initX->size[1];
    for (i1 = 0; i1 < expl_temp_idx_0; i1++) {
      ref_data[i1 + b_initX->size[0] * i] = initX_data[i + initX->size[0] * i1];
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
    c_expl_temp = 0.0;
    for (i1 = 0; i1 < 20; i1++) {
      c_expl_temp += (real_T)b_a[i + 10 * i1] * initX_data[i1];
    }
    a[i] = c_expl_temp;
  }
  emxFree_real_T(&initX);
  for (i = 0; i < 40; i++) {
    z[i] = ref_data[i];
  }
  emxFree_real_T(&b_initX);
  memcpy(&z[40], &a[0], 10U * sizeof(real_T));
  z[50] = onlinedata->Slack0;
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
  b_dv[50] = 0.0;
  for (i = 0; i < 40; i++) {
    dv1[i] = rtInf;
  }
  for (i = 0; i < 10; i++) {
    dv1[i + 40] = rtInf;
  }
  char_T f_expl_temp[3];
  dv1[50] = rtInf;
  info->Cost = fmincon(&b_expl_temp, &expl_temp, z, ref, B, b_dv, dv1,
                       &d_expl_temp, &e_expl_temp, &ExitFlag, &Out_iterations,
                       &c_expl_temp, f_expl_temp, &Out_constrviolation,
                       &g_expl_temp, &h_expl_temp, &i_expl_temp);
  emxFreeStruct_struct_T1(&e_expl_temp);
  emxFreeStruct_struct_T(&d_expl_temp);
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
  for (i = 0; i < 20; i++) {
    c_expl_temp = 0.0;
    for (i1 = 0; i1 < 10; i1++) {
      c_expl_temp += (real_T)iv[i + 20 * i1] * z[i1 + 40];
    }
    b_lastMV[i] = c_expl_temp;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 10; i1++) {
      Umv[i1 + 11 * i] = b_lastMV[i + (i1 << 1)];
    }
  }
  memcpy(&b_x[0], &z[0], 40U * sizeof(real_T));
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
    info->Yopt[expl_temp_idx_0] = info->Xopt[expl_temp_idx_0];
    info->Yopt[expl_temp_idx_0 + 11] = info->Xopt[expl_temp_idx_0 + 11];
    info->Yopt[expl_temp_idx_0 + 22] = info->Xopt[expl_temp_idx_0 + 22];
    info->Yopt[expl_temp_idx_0 + 33] = info->Xopt[expl_temp_idx_0 + 33];
    info->Topt[expl_temp_idx_0] = 0.1 * (real_T)expl_temp_idx_0;
  }
  info->Slack = z[50];
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
