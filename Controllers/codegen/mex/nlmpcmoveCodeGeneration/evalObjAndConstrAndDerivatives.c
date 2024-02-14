/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * evalObjAndConstrAndDerivatives.c
 *
 * Code generation for function 'evalObjAndConstrAndDerivatives'
 *
 */

/* Include files */
#include "evalObjAndConstrAndDerivatives.h"
#include "checkVectorNonFinite.h"
#include "nlmpcmoveCodeGeneration.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "znlmpc_objfun.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T evalObjAndConstrAndDerivatives(
    int32_T c_obj_next_next_next_next_next_,
    const i_struct_T *d_obj_next_next_next_next_next_,
    const k_struct_T *e_obj_next_next_next_next_next_, const real_T x[51],
    emxArray_real_T *grad_workspace, emxArray_real_T *Cineq_workspace,
    int32_T ineq0, real_T Ceq_workspace[40], int32_T eq0,
    emxArray_real_T *JacIneqTrans_workspace, int32_T iJI_col, int32_T ldJI,
    emxArray_real_T *JacEqTrans_workspace, int32_T iJE_col, int32_T ldJE,
    int32_T *status)
{
  static const int8_T b_iv[200] = {
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  __m128d r;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emxArray_real_T *urk;
  emxArray_real_T *varargout_1;
  emxArray_real_T *varargout_3;
  real_T varargout_4[2040];
  real_T varargout_2[51];
  real_T X[44];
  real_T b_X[44];
  real_T b_x[40];
  real_T gfX[40];
  real_T U[22];
  real_T Umv[22];
  real_T b_U[22];
  real_T a[20];
  real_T gfU[20];
  real_T Ck[16];
  real_T b_dv[10];
  real_T xk[4];
  real_T duk[2];
  real_T umvk[2];
  real_T d;
  real_T fs;
  real_T fval;
  real_T *Cineq_workspace_data;
  real_T *JacEqTrans_workspace_data;
  real_T *JacIneqTrans_workspace_data;
  real_T *grad_workspace_data;
  real_T *urk_data;
  int32_T col;
  int32_T col_end;
  int32_T idx_current;
  int32_T idx_mat;
  int8_T ix[4];
  int8_T iu_idx_0;
  int8_T iu_idx_1;
  boolean_T allFinite;
  JacEqTrans_workspace_data = JacEqTrans_workspace->data;
  JacIneqTrans_workspace_data = JacIneqTrans_workspace->data;
  Cineq_workspace_data = Cineq_workspace->data;
  grad_workspace_data = grad_workspace->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  memset(&X[0], 0, 44U * sizeof(real_T));
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (idx_mat = 0; idx_mat < 20; idx_mat++) {
    d = 0.0;
    for (col_end = 0; col_end < 10; col_end++) {
      d += (real_T)iv[idx_mat + 20 * col_end] * x[col_end + 40];
    }
    a[idx_mat] = d;
  }
  for (idx_mat = 0; idx_mat < 2; idx_mat++) {
    for (col_end = 0; col_end < 10; col_end++) {
      Umv[col_end + 11 * idx_mat] = a[idx_mat + (col_end << 1)];
    }
  }
  memcpy(&b_x[0], &x[0], 40U * sizeof(real_T));
  for (idx_mat = 0; idx_mat < 4; idx_mat++) {
    for (col_end = 0; col_end < 10; col_end++) {
      X[(col_end + 11 * idx_mat) + 1] = b_x[idx_mat + (col_end << 2)];
    }
    X[11 * idx_mat] = e_obj_next_next_next_next_next_->runtimedata.x[idx_mat];
  }
  for (col = 0; col < 2; col++) {
    d = Umv[11 * col + 9];
    Umv[11 * col + 10] = d;
    memcpy(&U[col * 11], &Umv[col * 11], 11U * sizeof(real_T));
  }
  memset(&gfX[0], 0, 40U * sizeof(real_T));
  memset(&gfU[0], 0, 20U * sizeof(real_T));
  fs = 0.0;
  ix[0] = 1;
  ix[1] = 2;
  ix[2] = 3;
  ix[3] = 4;
  iu_idx_0 = 1;
  iu_idx_1 = 2;
  for (idx_mat = 0; idx_mat < 11; idx_mat++) {
    idx_current = idx_mat << 2;
    b_X[idx_current] = X[idx_mat];
    b_X[idx_current + 1] = X[idx_mat + 11];
    b_X[idx_current + 2] = X[idx_mat + 22];
    b_X[idx_current + 3] = X[idx_mat + 33];
    idx_current = idx_mat << 1;
    b_U[idx_current] = U[idx_mat];
    b_U[idx_current + 1] = U[idx_mat + 11];
  }
  memcpy(&Umv[0], &b_U[0], 22U * sizeof(real_T));
  emxInit_real_T(&urk, 1);
  for (col = 0; col < 10; col++) {
    __m128d r1;
    real_T xa[4];
    real_T Umv_idx_0;
    real_T b_xk;
    real_T d1;
    real_T dx;
    idx_mat = (col + 1) << 2;
    d = b_X[idx_mat];
    xk[0] = d;
    xa[0] = muDoubleScalarAbs(d);
    d1 = b_X[idx_mat + 1];
    xk[1] = d1;
    xa[1] = muDoubleScalarAbs(d1);
    b_xk = b_X[idx_mat + 2];
    xk[2] = b_xk;
    xa[2] = muDoubleScalarAbs(b_xk);
    Umv_idx_0 = b_X[idx_mat + 3];
    xk[3] = Umv_idx_0;
    xa[3] = muDoubleScalarAbs(Umv_idx_0);
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
    for (idx_current = 0; idx_current < 4; idx_current++) {
      __m128d r2;
      dx = 1.0E-6 * xa[idx_current];
      xk[idx_current] += dx;
      r = _mm_loadu_pd(&xk[0]);
      r1 = _mm_loadu_pd(&b_X[idx_mat]);
      col_end = idx_current << 2;
      r2 = _mm_set1_pd(dx);
      _mm_storeu_pd(&Ck[col_end], _mm_div_pd(_mm_sub_pd(r, r1), r2));
      r = _mm_loadu_pd(&xk[2]);
      r1 = _mm_loadu_pd(&b_X[idx_mat + 2]);
      _mm_storeu_pd(&Ck[col_end + 2], _mm_div_pd(_mm_sub_pd(r, r1), r2));
      xk[idx_current] -= dx;
    }
    if (e_obj_next_next_next_next_next_->runtimedata.ref->size[1] == 4) {
      xk[0] = e_obj_next_next_next_next_next_->runtimedata.OutputWeights[col] *
              (d - e_obj_next_next_next_next_next_->runtimedata.ref->data[col]);
      xk[1] =
          e_obj_next_next_next_next_next_->runtimedata.OutputWeights[col + 10] *
          (d1 - e_obj_next_next_next_next_next_->runtimedata.ref
                    ->data[col + e_obj_next_next_next_next_next_->runtimedata
                                     .ref->size[0]]);
      xk[2] =
          e_obj_next_next_next_next_next_->runtimedata.OutputWeights[col + 20] *
          (b_xk - e_obj_next_next_next_next_next_->runtimedata.ref
                      ->data[col + e_obj_next_next_next_next_next_->runtimedata
                                           .ref->size[0] *
                                       2]);
      xk[3] =
          e_obj_next_next_next_next_next_->runtimedata.OutputWeights[col + 30] *
          (Umv_idx_0 - e_obj_next_next_next_next_next_->runtimedata.ref
                           ->data[col + e_obj_next_next_next_next_next_
                                                ->runtimedata.ref->size[0] *
                                            3]);
    } else {
      binary_expand_op_1(xk, e_obj_next_next_next_next_next_, col, b_X);
    }
    d = xk[0];
    b_xk = d * d;
    d *= e_obj_next_next_next_next_next_->runtimedata.OutputWeights[col];
    xk[0] = d;
    d = xk[1];
    b_xk += d * d;
    d *= e_obj_next_next_next_next_next_->runtimedata.OutputWeights[col + 10];
    xk[1] = d;
    d = xk[2];
    b_xk += d * d;
    d *= e_obj_next_next_next_next_next_->runtimedata.OutputWeights[col + 20];
    xk[2] = d;
    d = xk[3];
    b_xk += d * d;
    d *= e_obj_next_next_next_next_next_->runtimedata.OutputWeights[col + 30];
    xk[3] = d;
    fs += b_xk;
    for (idx_mat = 0; idx_mat < 4; idx_mat++) {
      col_end = idx_mat << 2;
      d = Ck[col_end] * xk[0];
      d += Ck[col_end + 1] * xk[1];
      d += Ck[col_end + 2] * xk[2];
      d += Ck[col_end + 3] * xk[3];
      xa[idx_mat] = gfX[ix[idx_mat] - 1] + d;
    }
    gfX[ix[0] - 1] = xa[0];
    ix[0] = (int8_T)(ix[0] + 4);
    gfX[ix[1] - 1] = xa[1];
    ix[1] = (int8_T)(ix[1] + 4);
    gfX[ix[2] - 1] = xa[2];
    ix[2] = (int8_T)(ix[2] + 4);
    gfX[ix[3] - 1] = xa[3];
    ix[3] = (int8_T)(ix[3] + 4);
    idx_current = col << 1;
    umvk[0] = Umv[idx_current];
    umvk[1] = Umv[idx_current + 1];
    if (col + 1 == 1) {
      r = _mm_loadu_pd(&umvk[0]);
      r1 =
          _mm_loadu_pd(&e_obj_next_next_next_next_next_->runtimedata.lastMV[0]);
      _mm_storeu_pd(&duk[0], _mm_sub_pd(r, r1));
    } else {
      r = _mm_loadu_pd(&umvk[0]);
      r1 = _mm_loadu_pd(&Umv[(col - 1) << 1]);
      _mm_storeu_pd(&duk[0], _mm_sub_pd(r, r1));
    }
    idx_current =
        e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget->size[1];
    if ((e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget->size[0] ==
         0) ||
        (idx_current == 0)) {
      idx_mat = urk->size[0];
      urk->size[0] = 2;
      emxEnsureCapacity_real_T(urk, idx_mat);
      urk_data = urk->data;
      urk_data[0] = 0.0;
      urk_data[1] = 0.0;
    } else {
      idx_mat = urk->size[0];
      urk->size[0] = idx_current;
      emxEnsureCapacity_real_T(urk, idx_mat);
      urk_data = urk->data;
      for (idx_mat = 0; idx_mat < idx_current; idx_mat++) {
        urk_data[idx_mat] =
            e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget
                ->data[col + e_obj_next_next_next_next_next_->runtimedata
                                     .MVScaledTarget->size[0] *
                                 idx_mat];
      }
    }
    if (urk->size[0] == 2) {
      umvk[0] = e_obj_next_next_next_next_next_->runtimedata.MVWeights[col] *
                (umvk[0] - urk_data[0]);
      umvk[1] =
          e_obj_next_next_next_next_next_->runtimedata.MVWeights[col + 10] *
          (umvk[1] - urk_data[1]);
    } else {
      binary_expand_op(umvk, e_obj_next_next_next_next_next_, col, urk);
    }
    d = umvk[0];
    b_xk = d * d;
    Umv_idx_0 = gfU[iu_idx_0 - 1] +
                e_obj_next_next_next_next_next_->runtimedata.MVWeights[col] * d;
    d = umvk[1];
    b_xk += d * d;
    dx = gfU[iu_idx_1 - 1] +
         e_obj_next_next_next_next_next_->runtimedata.MVWeights[col + 10] * d;
    fs += b_xk;
    gfU[iu_idx_0 - 1] = Umv_idx_0;
    d = duk[0];
    d1 = e_obj_next_next_next_next_next_->runtimedata.MVRateWeights[col];
    d *= d1;
    b_xk = d * d;
    d *= d1;
    duk[0] = d;
    gfU[iu_idx_1 - 1] = dx;
    d = duk[1];
    d1 = e_obj_next_next_next_next_next_->runtimedata.MVRateWeights[col + 10];
    d *= d1;
    b_xk += d * d;
    d *= d1;
    duk[1] = d;
    fs += b_xk;
    umvk[0] = gfU[iu_idx_0 - 1] + duk[0];
    umvk[1] = gfU[iu_idx_1 - 1] + duk[1];
    gfU[iu_idx_0 - 1] = umvk[0];
    gfU[iu_idx_1 - 1] = umvk[1];
    if (col + 1 > 1) {
      umvk[0] = gfU[(int8_T)(iu_idx_0 - 2) - 1] - duk[0];
      umvk[1] = gfU[(int8_T)(iu_idx_1 - 2) - 1] - duk[1];
      gfU[(int8_T)(iu_idx_0 - 2) - 1] = umvk[0];
      gfU[(int8_T)(iu_idx_1 - 2) - 1] = umvk[1];
    }
    iu_idx_0 = (int8_T)(iu_idx_0 + 2);
    iu_idx_1 = (int8_T)(iu_idx_1 + 2);
  }
  emxFree_real_T(&urk);
  fval = fs +
         e_obj_next_next_next_next_next_->runtimedata.ECRWeight * x[50] * x[50];
  for (idx_mat = 0; idx_mat <= 38; idx_mat += 2) {
    r = _mm_loadu_pd(&gfX[idx_mat]);
    _mm_storeu_pd(&gfX[idx_mat], _mm_mul_pd(_mm_set1_pd(2.0), r));
  }
  for (idx_mat = 0; idx_mat <= 18; idx_mat += 2) {
    r = _mm_loadu_pd(&gfU[idx_mat]);
    _mm_storeu_pd(&gfU[idx_mat], _mm_mul_pd(_mm_set1_pd(2.0), r));
  }
  for (idx_mat = 0; idx_mat < 10; idx_mat++) {
    d = 0.0;
    for (col_end = 0; col_end < 20; col_end++) {
      d += (real_T)b_iv[idx_mat + 10 * col_end] * gfU[col_end];
    }
    b_dv[idx_mat] = d;
  }
  memcpy(&varargout_2[0], &gfX[0], 40U * sizeof(real_T));
  memcpy(&varargout_2[40], &b_dv[0], 10U * sizeof(real_T));
  varargout_2[50] =
      2.0 * e_obj_next_next_next_next_next_->runtimedata.ECRWeight * x[50];
  for (idx_current = 0; idx_current < 51; idx_current++) {
    grad_workspace_data[idx_current] = varargout_2[idx_current];
  }
  *status = 1;
  allFinite = muDoubleScalarIsNaN(fval);
  if (muDoubleScalarIsInf(fval) || allFinite) {
    if (allFinite) {
      *status = -3;
    } else if (fval < 0.0) {
      *status = -1;
    } else {
      *status = -2;
    }
  } else {
    allFinite = true;
    idx_current = 0;
    while (allFinite && (idx_current + 1 <= 51)) {
      allFinite = ((!muDoubleScalarIsInf(grad_workspace_data[idx_current])) &&
                   (!muDoubleScalarIsNaN(grad_workspace_data[idx_current])));
      idx_current++;
    }
    if (!allFinite) {
      idx_current--;
      if (muDoubleScalarIsNaN(grad_workspace_data[idx_current])) {
        *status = -3;
      } else if (grad_workspace_data[idx_current] < 0.0) {
        *status = -1;
      } else {
        *status = -2;
      }
    }
  }
  if (*status == 1) {
    emxInit_real_T(&varargout_3, 2);
    emxInit_real_T(&varargout_1, 2);
    if (c_obj_next_next_next_next_next_ > 0) {
      c_nlmpcmoveCodeGeneration_anonF(
          d_obj_next_next_next_next_next_->x,
          d_obj_next_next_next_next_next_->OutputMin,
          d_obj_next_next_next_next_next_->OutputMax,
          d_obj_next_next_next_next_next_->Parameters.f1,
          d_obj_next_next_next_next_next_->Parameters.f2, x, varargout_1, gfX,
          varargout_3, varargout_4);
      grad_workspace_data = varargout_3->data;
      urk_data = varargout_1->data;
      n_t = (ptrdiff_t)c_obj_next_next_next_next_next_;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &urk_data[0], &incx_t, &Cineq_workspace_data[ineq0 - 1],
            &incy_t);
      memcpy(&Ceq_workspace[eq0 + -1], &gfX[0], 40U * sizeof(real_T));
      idx_mat = varargout_3->size[0];
      for (idx_current = 0; idx_current < idx_mat; idx_current++) {
        col_end = varargout_3->size[1];
        for (col = 0; col < col_end; col++) {
          JacIneqTrans_workspace_data[idx_current +
                                      ldJI * ((iJI_col + col) - 1)] =
              grad_workspace_data[idx_current + varargout_3->size[0] * col];
        }
      }
      for (idx_current = 0; idx_current < 51; idx_current++) {
        for (col = 0; col < 40; col++) {
          JacEqTrans_workspace_data[idx_current +
                                    ldJE * ((iJE_col + col) - 1)] =
              varargout_4[idx_current + 51 * col];
        }
      }
    } else {
      c_nlmpcmoveCodeGeneration_anonF(
          d_obj_next_next_next_next_next_->x,
          d_obj_next_next_next_next_next_->OutputMin,
          d_obj_next_next_next_next_next_->OutputMax,
          d_obj_next_next_next_next_next_->Parameters.f1,
          d_obj_next_next_next_next_next_->Parameters.f2, x, varargout_1, gfX,
          varargout_3, varargout_4);
      memcpy(&Ceq_workspace[eq0 + -1], &gfX[0], 40U * sizeof(real_T));
      for (idx_current = 0; idx_current < 51; idx_current++) {
        for (col = 0; col < 40; col++) {
          JacEqTrans_workspace_data[idx_current +
                                    ldJE * ((iJE_col + col) - 1)] =
              varargout_4[idx_current + 51 * col];
        }
      }
    }
    emxFree_real_T(&varargout_1);
    emxFree_real_T(&varargout_3);
    *status = checkVectorNonFinite(c_obj_next_next_next_next_next_,
                                   Cineq_workspace, ineq0);
    if (*status == 1) {
      *status = b_checkVectorNonFinite(Ceq_workspace, eq0);
      if (*status == 1) {
        allFinite = true;
        idx_current = -1;
        col = iJI_col;
        col_end = (iJI_col + c_obj_next_next_next_next_next_) - 1;
        while (allFinite && (col <= col_end)) {
          idx_current = -1;
          while (allFinite && (idx_current + 2 <= 51)) {
            idx_mat = (idx_current + ldJI * (col - 1)) + 1;
            allFinite =
                ((!muDoubleScalarIsInf(JacIneqTrans_workspace_data[idx_mat])) &&
                 (!muDoubleScalarIsNaN(JacIneqTrans_workspace_data[idx_mat])));
            idx_current++;
          }
          col++;
        }
        if (!allFinite) {
          idx_mat = idx_current + ldJI * (col - 2);
          if (muDoubleScalarIsNaN(JacIneqTrans_workspace_data[idx_mat])) {
            *status = -3;
          } else if (JacIneqTrans_workspace_data[idx_mat] < 0.0) {
            *status = -1;
          } else {
            *status = -2;
          }
        } else {
          allFinite = true;
          idx_current = -1;
          col = iJE_col;
          while (allFinite && (col <= iJE_col + 39)) {
            idx_current = -1;
            while (allFinite && (idx_current + 2 <= 51)) {
              idx_mat = (idx_current + ldJE * (col - 1)) + 1;
              allFinite =
                  ((!muDoubleScalarIsInf(JacEqTrans_workspace_data[idx_mat])) &&
                   (!muDoubleScalarIsNaN(JacEqTrans_workspace_data[idx_mat])));
              idx_current++;
            }
            col++;
          }
          if (!allFinite) {
            idx_mat = idx_current + ldJE * (col - 2);
            if (muDoubleScalarIsNaN(JacEqTrans_workspace_data[idx_mat])) {
              *status = -3;
            } else if (JacEqTrans_workspace_data[idx_mat] < 0.0) {
              *status = -1;
            } else {
              *status = -2;
            }
          }
        }
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

/* End of code generation (evalObjAndConstrAndDerivatives.c) */
