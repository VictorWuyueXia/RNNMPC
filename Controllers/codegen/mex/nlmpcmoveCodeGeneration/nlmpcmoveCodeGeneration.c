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
#include "mtimes.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include "tand.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void c_nlmpcmoveCodeGeneration_anonF(
    const real_T runtimedata_x[4], const real_T runtimedata_OutputMin[20],
    const real_T runtimedata_OutputMax[20], real_T runtimedata_Parameters_f1,
    real_T runtimedata_Parameters_f2, const real_T z[51],
    emxArray_real_T *varargout_1, real_T varargout_2[40],
    emxArray_real_T *varargout_3, real_T varargout_4[2040])
{
  static const int8_T b_iv[4] = {0, 0, 0, 1};
  __m128d r;
  __m128d r3;
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
  emxArray_real_T *c_c;
  emxArray_real_T *c_y;
  emxArray_real_T *r2;
  emxArray_real_T *varargin_1;
  emxArray_real_T *varargin_2;
  real_T Jx[1600];
  real_T c_Jx[1600];
  real_T Jmv[800];
  real_T y[400];
  real_T X[44];
  real_T b_X[44];
  real_T c[40];
  real_T U[22];
  real_T Umv[22];
  real_T a[20];
  real_T Ck[8];
  real_T b_val[8];
  real_T ic[4];
  real_T Ak_tmp;
  real_T alpha1;
  real_T beta1;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T e;
  real_T *Jc_data;
  real_T *b_c_data;
  real_T *c_data;
  real_T *varargin_1_data;
  int32_T U_tmp;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T val_tmp;
  char_T TRANSA1;
  char_T TRANSB1;
  int8_T ic_idx_0;
  int8_T ic_idx_1;
  int8_T *Je_data;
  int8_T *r4;
  boolean_T bv[20];
  boolean_T x[2];
  boolean_T b_y;
  boolean_T exitg1;
  boolean_T guard1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  memset(&X[0], 0, 44U * sizeof(real_T));
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (i = 0; i < 20; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 10; i1++) {
      d += (real_T)iv[i + 20 * i1] * z[i1 + 40];
    }
    a[i] = d;
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 10; i1++) {
      Umv[i1 + 11 * i] = a[i + (i1 << 1)];
    }
  }
  e = z[50];
  memcpy(&c[0], &z[0], 40U * sizeof(real_T));
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < 10; i1++) {
      X[(i1 + 11 * i) + 1] = c[i + (i1 << 2)];
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
  r = _mm_set1_pd(4.0);
  for (b_i = 0; b_i < 10; b_i++) {
    real_T d5;
    /*  Unpack the state and input */
    /*  [x_pos, y_pos, yaw_direction, speed] */
    /*  Pre-computed J_state expression */
    i = b_i << 2;
    d = b_X[i + 2];
    alpha1 = d;
    b_cosd(&alpha1);
    beta1 = d;
    b_sind(&beta1);
    i1 = b_i << 1;
    d1 = Umv[i1 + 1];
    Ak_tmp = d1;
    b_tand(&Ak_tmp);
    /*  Pre-computed J_input expression */
    /*  Unpack the state and input */
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
    d5 = ic[0];
    U_tmp = (b_i + 1) << 2;
    varargout_2[(int32_T)d5 - 1] =
        b_X[U_tmp] - (b_X[i] + d4 * d2 * runtimedata_Parameters_f1);
    Jx[((int8_T)d5 + 160 * b_i) - 1] = 1.0;
    d5 = ic[1];
    varargout_2[(int32_T)d5 - 1] =
        b_X[U_tmp + 1] - (b_X[i + 1] + d4 * d3 * runtimedata_Parameters_f1);
    Jx[((int8_T)d5 + 160 * b_i) + 39] = 1.0;
    d5 = ic[2];
    varargout_2[(int32_T)d5 - 1] =
        b_X[U_tmp + 2] -
        (d + d4 * d1 / runtimedata_Parameters_f2 * runtimedata_Parameters_f1);
    Jx[((int8_T)d5 + 160 * b_i) + 79] = 1.0;
    d5 = ic[3];
    varargout_2[(int32_T)d5 - 1] =
        b_X[U_tmp + 3] - (d4 + Umv[i1] * runtimedata_Parameters_f1);
    Jx[((int8_T)d5 + 160 * b_i) + 119] = 1.0;
    if (b_i + 1 > 1) {
      real_T val[16];
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
      val[14] =
          -(runtimedata_Parameters_f1 * Ak_tmp / runtimedata_Parameters_f2);
      U_tmp = 160 * (b_i - 1);
      for (k = 0; k < 4; k++) {
        val_tmp = k << 2;
        i = -b_iv[k];
        val[val_tmp + 3] = i;
        Jx[(((int32_T)ic[0] + 40 * k) + U_tmp) - 1] = val[val_tmp];
        Jx[(((int32_T)ic[1] + 40 * k) + U_tmp) - 1] = val[val_tmp + 1];
        Jx[(((int32_T)ic[2] + 40 * k) + U_tmp) - 1] = val[val_tmp + 2];
        Jx[(((int32_T)ic[3] + 40 * k) + U_tmp) - 1] = i;
      }
    }
    b_val[2] = -(runtimedata_Parameters_f1 * d4 * (Ak_tmp * Ak_tmp + 1.0) /
                 runtimedata_Parameters_f2);
    b_val[6] = -0.0;
    b_val[3] = -0.0;
    b_val[7] = -runtimedata_Parameters_f1;
    for (k = 0; k < 2; k++) {
      val_tmp = k << 2;
      b_val[val_tmp] = -0.0;
      b_val[val_tmp + 1] = -0.0;
      Jmv[(((int32_T)ic[0] + 40 * k) + 80 * b_i) - 1] = b_val[val_tmp];
      Jmv[(((int32_T)ic[1] + 40 * k) + 80 * b_i) - 1] = b_val[val_tmp + 1];
      Jmv[(((int32_T)ic[2] + 40 * k) + 80 * b_i) - 1] = b_val[val_tmp + 2];
      Jmv[(((int32_T)ic[3] + 40 * k) + 80 * b_i) - 1] = b_val[val_tmp + 3];
    }
    r3 = _mm_loadu_pd(&ic[0]);
    _mm_storeu_pd(&ic[0], _mm_add_pd(r3, r));
    r3 = _mm_loadu_pd(&ic[2]);
    _mm_storeu_pd(&ic[2], _mm_add_pd(r3, r));
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
  for (i = 0; i < 20; i++) {
    bv[i] = muDoubleScalarIsInf(runtimedata_OutputMin[i]);
  }
  all(bv, x);
  b_y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 1)) {
    if (!x[k]) {
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
  emxInit_int8_T(&r1, 1);
  emxInit_real_T(&c_y, 2);
  emxInit_real_T(&varargin_1, 2);
  emxInit_real_T(&varargin_2, 2);
  emxInit_real_T(&c_c, 1);
  emxInit_real_T(&r2, 2);
  emxInit_real_T(&b_Jx, 3);
  emxInit_int8_T(&Je, 2);
  guard1 = false;
  if (b_y) {
    for (i = 0; i < 20; i++) {
      bv[i] = muDoubleScalarIsInf(runtimedata_OutputMax[i]);
    }
    all(bv, x);
    b_y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 1)) {
      if (!x[k]) {
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
    int8_T b_Je[40];
    boolean_T icf[40];
    for (b_i = 0; b_i < 40; b_i++) {
      c[b_i] = 0.0;
      icf[b_i] = true;
    }
    memset(&c_Jx[0], 0, 1600U * sizeof(real_T));
    for (b_i = 0; b_i < 40; b_i++) {
      b_Je[b_i] = 0;
    }
    ic_idx_0 = 1;
    ic_idx_1 = 2;
    for (b_i = 0; b_i < 10; b_i++) {
      d = runtimedata_OutputMin[b_i];
      icf[ic_idx_0 - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      d = runtimedata_OutputMin[b_i + 10];
      icf[ic_idx_1 - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      d1 = runtimedata_OutputMax[b_i];
      icf[(int8_T)(ic_idx_0 + 2) - 1] =
          ((!muDoubleScalarIsInf(d1)) && (!muDoubleScalarIsNaN(d1)));
      d1 = runtimedata_OutputMax[b_i + 10];
      icf[(int8_T)(ic_idx_1 + 2) - 1] =
          ((!muDoubleScalarIsInf(d1)) && (!muDoubleScalarIsNaN(d1)));
      b_y = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= 3)) {
        int16_T b_ic[4];
        b_ic[0] = (int16_T)(ic_idx_0 - 1);
        b_ic[2] = (int16_T)(ic_idx_0 + 1);
        b_ic[1] = (int16_T)(ic_idx_1 - 1);
        b_ic[3] = (int16_T)(ic_idx_1 + 1);
        if (icf[b_ic[k]]) {
          b_y = true;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (b_y) {
        real_T xa[4];
        d2 = X[b_i + 1];
        ic[0] = d2;
        xa[0] = muDoubleScalarAbs(d2);
        d3 = X[b_i + 12];
        ic[1] = d3;
        xa[1] = muDoubleScalarAbs(d3);
        d4 = X[b_i + 23];
        ic[2] = d4;
        xa[2] = muDoubleScalarAbs(d4);
        d4 = X[b_i + 34];
        ic[3] = d4;
        xa[3] = muDoubleScalarAbs(d4);
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
        for (val_tmp = 0; val_tmp < 4; val_tmp++) {
          alpha1 = 1.0E-6 * xa[val_tmp];
          ic[val_tmp] += alpha1;
          d4 = ic[0];
          U_tmp = val_tmp << 1;
          Ck[U_tmp] = (d4 - d2) / alpha1;
          d4 = ic[1];
          Ck[U_tmp + 1] = (d4 - d3) / alpha1;
          ic[val_tmp] -= alpha1;
        }
        c[ic_idx_0 - 1] = (runtimedata_OutputMin[b_i] - e) - d2;
        c[ic_idx_1 - 1] = (d - e) - d3;
        c[ic_idx_0 + 1] = (d2 - runtimedata_OutputMax[b_i]) - e;
        c[ic_idx_1 + 1] = (d3 - d1) - e;
        r = _mm_loadu_pd(&Ck[0]);
        r3 = _mm_set1_pd(-1.0);
        _mm_storeu_pd(&b_val[0], _mm_mul_pd(r, r3));
        r = _mm_loadu_pd(&Ck[2]);
        _mm_storeu_pd(&b_val[2], _mm_mul_pd(r, r3));
        r = _mm_loadu_pd(&Ck[4]);
        _mm_storeu_pd(&b_val[4], _mm_mul_pd(r, r3));
        r = _mm_loadu_pd(&Ck[6]);
        _mm_storeu_pd(&b_val[6], _mm_mul_pd(r, r3));
        for (k = 0; k < 4; k++) {
          U_tmp = k << 1;
          c_Jx[((ic_idx_0 + 40 * k) + 160 * b_i) - 1] = b_val[U_tmp];
          c_Jx[((ic_idx_1 + 40 * k) + 160 * b_i) - 1] = b_val[U_tmp + 1];
        }
        for (k = 0; k < 4; k++) {
          U_tmp = k << 1;
          c_Jx[((ic_idx_0 + 40 * k) + 160 * b_i) + 1] = Ck[U_tmp];
          c_Jx[((ic_idx_1 + 40 * k) + 160 * b_i) + 1] = Ck[U_tmp + 1];
        }
        b_Je[ic_idx_0 - 1] = -1;
        b_Je[ic_idx_1 - 1] = -1;
        b_Je[(int8_T)(ic_idx_0 + 2) - 1] = -1;
        b_Je[(int8_T)(ic_idx_1 + 2) - 1] = -1;
      }
      ic_idx_0 = (int8_T)(ic_idx_0 + 4);
      ic_idx_1 = (int8_T)(ic_idx_1 + 4);
    }
    U_tmp = 0;
    for (b_i = 0; b_i < 40; b_i++) {
      if (icf[b_i]) {
        U_tmp++;
      }
    }
    i = r1->size[0];
    r1->size[0] = U_tmp;
    emxEnsureCapacity_int8_T(r1, i);
    r4 = r1->data;
    U_tmp = 0;
    for (b_i = 0; b_i < 40; b_i++) {
      if (icf[b_i]) {
        r4[U_tmp] = (int8_T)b_i;
        U_tmp++;
      }
    }
    i = c_c->size[0];
    c_c->size[0] = r1->size[0];
    emxEnsureCapacity_real_T(c_c, i);
    b_c_data = c_c->data;
    k = r1->size[0];
    for (i = 0; i < k; i++) {
      b_c_data[i] = c[r4[i]];
    }
    i = b_c->size[0] * b_c->size[1];
    b_c->size[0] = r1->size[0];
    b_c->size[1] = 1;
    emxEnsureCapacity_real_T(b_c, i);
    c_data = b_c->data;
    k = r1->size[0];
    for (i = 0; i < k; i++) {
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
      k = r1->size[0] * 20;
      for (i = 0; i < k; i++) {
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
      k = r1->size[0];
      for (i = 0; i < 10; i++) {
        for (i1 = 0; i1 < 4; i1++) {
          for (U_tmp = 0; U_tmp < k; U_tmp++) {
            b_c_data[(U_tmp + b_Jx->size[0] * i1) + b_Jx->size[0] * 4 * i] =
                c_Jx[(r4[U_tmp] + 40 * i1) + 160 * i];
          }
        }
      }
      U_tmp = r1->size[0];
      i = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = 40;
      varargin_1->size[1] = r1->size[0];
      emxEnsureCapacity_real_T(varargin_1, i);
      varargin_1_data = varargin_1->data;
      k = r1->size[0];
      for (i = 0; i < k; i++) {
        for (i1 = 0; i1 < 40; i1++) {
          varargin_1_data[i1 + 40 * i] = b_c_data[i + U_tmp * i1];
        }
      }
      i = varargin_2->size[0] * varargin_2->size[1];
      varargin_2->size[0] = 10;
      varargin_2->size[1] = c_y->size[0];
      emxEnsureCapacity_real_T(varargin_2, i);
      b_c_data = varargin_2->data;
      k = c_y->size[0];
      for (i = 0; i < k; i++) {
        for (i1 = 0; i1 < 10; i1++) {
          b_c_data[i1 + 10 * i] = Jc_data[i + c_y->size[0] * i1];
        }
      }
      U_tmp = varargin_1->size[1];
      if ((varargin_1->size[1] == 0) || (varargin_2->size[1] != 0)) {
        ic_idx_0 = 10;
      } else {
        ic_idx_0 = 0;
      }
      val_tmp = ic_idx_0;
      i = Je->size[0] * Je->size[1];
      Je->size[0] = 1;
      Je->size[1] = r1->size[0];
      emxEnsureCapacity_int8_T(Je, i);
      Je_data = Je->data;
      k = r1->size[0];
      for (i = 0; i < k; i++) {
        Je_data[i] = b_Je[r4[i]];
      }
      i = Jc->size[0] * Jc->size[1];
      Jc->size[0] = ic_idx_0 + 41;
      Jc->size[1] = varargin_1->size[1];
      emxEnsureCapacity_real_T(Jc, i);
      Jc_data = Jc->data;
      for (i = 0; i < U_tmp; i++) {
        for (i1 = 0; i1 < 40; i1++) {
          Jc_data[i1 + Jc->size[0] * i] = varargin_1_data[i1 + 40 * i];
        }
        for (i1 = 0; i1 < val_tmp; i1++) {
          Jc_data[(i1 + Jc->size[0] * i) + 40] = b_c_data[i1 + ic_idx_0 * i];
        }
        Jc_data[(ic_idx_0 + Jc->size[0] * i) + 40] = Je_data[i];
      }
    }
  }
  emxFree_int8_T(&Je);
  emxFree_real_T(&b_Jx);
  emxFree_real_T(&r2);
  emxFree_real_T(&c_c);
  emxFree_real_T(&varargin_2);
  emxFree_real_T(&varargin_1);
  emxFree_real_T(&c_y);
  emxFree_int8_T(&r1);
  b_y = ((b_c->size[0] != 0) && (b_c->size[1] != 0));
  ic_idx_0 = (int8_T)b_c->size[0];
  i = varargout_1->size[0] * varargout_1->size[1];
  varargout_1->size[0] = ic_idx_0;
  U_tmp = b_y;
  varargout_1->size[1] = b_y;
  emxEnsureCapacity_real_T(varargout_1, i);
  b_c_data = varargout_1->data;
  for (i = 0; i < U_tmp; i++) {
    k = ic_idx_0;
    for (i1 = 0; i1 < k; i1++) {
      b_c_data[i1] = c_data[i1];
    }
  }
  emxFree_real_T(&b_c);
  b_y = ((Jc->size[0] != 0) && (Jc->size[1] != 0));
  if (b_y) {
    ic_idx_0 = (int8_T)Jc->size[0];
  } else {
    ic_idx_0 = 0;
  }
  if ((ic_idx_0 == 0) || b_y) {
    ic_idx_1 = (int8_T)Jc->size[1];
  } else {
    ic_idx_1 = 0;
  }
  i = varargout_3->size[0] * varargout_3->size[1];
  varargout_3->size[0] = ic_idx_0;
  varargout_3->size[1] = ic_idx_1;
  emxEnsureCapacity_real_T(varargout_3, i);
  b_c_data = varargout_3->data;
  k = ic_idx_1;
  for (i = 0; i < k; i++) {
    U_tmp = ic_idx_0;
    for (i1 = 0; i1 < U_tmp; i1++) {
      b_c_data[i1 + varargout_3->size[0] * i] = Jc_data[i1 + ic_idx_0 * i];
    }
  }
  emxFree_real_T(&Jc);
  for (i = 0; i < 40; i++) {
    for (i1 = 0; i1 < 40; i1++) {
      varargout_4[i1 + 51 * i] = Jx[i + 40 * i1];
    }
    for (i1 = 0; i1 < 10; i1++) {
      varargout_4[(i1 + 51 * i) + 40] = y[i + 40 * i1];
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
  real_T Out_iterations;
  real_T R_tmp;
  real_T c_expl_temp;
  real_T cost_inputs;
  real_T cost_progress;
  real_T d;
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
    ref->size[1] = 2;
    emxEnsureCapacity_real_T(ref, i);
    ref_data = ref->data;
    for (i = 0; i < 20; i++) {
      ref_data[i] = 0.0;
    }
  } else if (onlinedata->ref->size[0] == 0) {
    ref->size[0] = 0;
    ref->size[1] = 0;
  } else if (onlinedata->ref->size[0] < 10) {
    expl_temp_idx_0 = 10 - onlinedata->ref->size[0];
    i = ref->size[0] * ref->size[1];
    ref->size[0] = onlinedata->ref->size[0] + expl_temp_idx_0;
    ref->size[1] = 2;
    emxEnsureCapacity_real_T(ref, i);
    ref_data = ref->data;
    loop_ub = onlinedata->ref->size[0];
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        ref_data[i1 + ref->size[0] * i] =
            onlinedata->ref->data[i1 + onlinedata->ref->size[0] * i];
      }
    }
    for (i = 0; i < 2; i++) {
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
    ref->size[1] = 2;
    emxEnsureCapacity_real_T(ref, i);
    ref_data = ref->data;
    loop_ub = onlinedata->ref->size[0] << 1;
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
    b_expl_temp.OutputMin[i] = rtMinusInf;
    b_expl_temp.OutputMax[i] = rtInf;
  }
  for (i = 0; i < 40; i++) {
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
    memcpy(&info->Yopt[expl_temp_idx_0 * 11], &Umv[expl_temp_idx_0 * 11],
           11U * sizeof(real_T));
  }
  /*  weights is fed in as an array of  */
  /*  [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL
   * sofConstraints] */
  cost_progress = 0.0;
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 11; expl_temp_idx_0++) {
    /*  Rotation matrix for transforming to the vehicle's local frame */
    cost_inputs = -info->Xopt[expl_temp_idx_0 + 22];
    R_tmp = cost_inputs;
    b_sind(&R_tmp);
    b_cosd(&cost_inputs);
    onlinedata_idx_0 =
        onlinedata->Parameters.f3[0] - info->Xopt[expl_temp_idx_0];
    onlinedata_idx_1 =
        onlinedata->Parameters.f3[3] - info->Xopt[expl_temp_idx_0 + 11];
    target_relative[0] =
        cost_inputs * onlinedata_idx_0 + -R_tmp * onlinedata_idx_1;
    target_relative[1] =
        R_tmp * onlinedata_idx_0 + cost_inputs * onlinedata_idx_1;
    d = target_relative[0] * onlinedata->Parameters.f4[4];
    d += target_relative[1] * onlinedata->Parameters.f4[5];
    cost_inputs = d * target_relative[0];
    d = target_relative[0] * onlinedata->Parameters.f4[6];
    d += target_relative[1] * onlinedata->Parameters.f4[7];
    cost_inputs += d * target_relative[1];
    cost_progress += cost_inputs;
  }
  /*  quadratic cost for inputs */
  cost_inputs = 0.0;
  d = onlinedata->Parameters.f4[0];
  R_tmp = onlinedata->Parameters.f4[1];
  onlinedata_idx_0 = onlinedata->Parameters.f4[2];
  onlinedata_idx_1 = onlinedata->Parameters.f4[3];
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 11; expl_temp_idx_0++) {
    c_expl_temp = info->Yopt[expl_temp_idx_0 + 11];
    Out_iterations = info->Yopt[expl_temp_idx_0];
    cost_inputs +=
        (Out_iterations * d + c_expl_temp * R_tmp) * Out_iterations +
        (Out_iterations * onlinedata_idx_0 + c_expl_temp * onlinedata_idx_1) *
            c_expl_temp;
  }
  cost_inputs += cost_progress;
  if (cost_inputs <= cost_inputs) {
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
  for (i = 0; i < 20; i++) {
    b_expl_temp.MVWeights[i] = 0.0;
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
  expl_temp.NumOfOutputs = 2.0;
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
  }
  d_expl_temp.ECRWeight = 100000.0;
  for (i = 0; i < 20; i++) {
    d_expl_temp.OutputMax[i] = rtInf;
    d_expl_temp.OutputMin[i] = rtMinusInf;
    d_expl_temp.MVRateWeights[i] = 0.1;
    d_expl_temp.MVWeights[i] = 0.0;
    d_expl_temp.OutputWeights[i] = 1.0;
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
  e_expl_temp.NumOfOutputs = 2.0;
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
  info->Cost = fmincon(&b_expl_temp, &expl_temp, z0, ref, B, b_dv, zUB,
                       &d_expl_temp, &e_expl_temp, &cost_progress,
                       &Out_iterations, &cost_inputs, f_expl_temp, &R_tmp,
                       &onlinedata_idx_0, &onlinedata_idx_1, &c_expl_temp);
  emxFreeStruct_struct_T1(&e_expl_temp);
  emxFreeStruct_struct_T(&d_expl_temp);
  emxFreeStruct_struct_T1(&expl_temp);
  emxFreeStruct_struct_T(&b_expl_temp);
  emxFree_real_T(&ref);
  emxFree_real_T(&B);
  if (((int32_T)muDoubleScalarRound(cost_progress) == 0) && (R_tmp > 1.0E-6)) {
    cost_progress = -2.0;
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
  if (cost_progress > 0.0) {
    mv[0] = info->MVopt[0];
    mv[1] = info->MVopt[11];
  } else {
    mv[0] = lastMV[0];
    mv[1] = lastMV[1];
  }
  info->ExitFlag = cost_progress;
  info->Iterations = Out_iterations;
  onlinedata->Slack0 = muDoubleScalarMax(0.0, z0[50]);
  for (expl_temp_idx_0 = 0; expl_temp_idx_0 < 11; expl_temp_idx_0++) {
    info->Yopt[expl_temp_idx_0] = info->Xopt[expl_temp_idx_0];
    info->Yopt[expl_temp_idx_0 + 11] = info->Xopt[expl_temp_idx_0 + 11];
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
