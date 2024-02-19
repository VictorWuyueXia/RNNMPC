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
  emxArray_real_T *varargout_1;
  emxArray_real_T *varargout_3;
  emxArray_real_T *wtYerr;
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
  real_T b_dv[10];
  real_T duk[2];
  real_T umvk[2];
  real_T fs;
  real_T fval;
  real_T xa_idx_3;
  real_T *Cineq_workspace_data;
  real_T *JacEqTrans_workspace_data;
  real_T *JacIneqTrans_workspace_data;
  real_T *grad_workspace_data;
  real_T *wtYerr_data;
  int32_T b_i;
  int32_T col;
  int32_T col_end;
  int32_T i;
  int32_T idx_current;
  int32_T idx_mat;
  int8_T iu_idx_0;
  int8_T iu_idx_1;
  int8_T ix_idx_0;
  int8_T ix_idx_1;
  int8_T ix_idx_2;
  int8_T ix_idx_3;
  boolean_T allFinite;
  JacEqTrans_workspace_data = JacEqTrans_workspace->data;
  JacIneqTrans_workspace_data = JacIneqTrans_workspace->data;
  Cineq_workspace_data = Cineq_workspace->data;
  grad_workspace_data = grad_workspace->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&wtYerr, 1);
  memset(&X[0], 0, 44U * sizeof(real_T));
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (i = 0; i < 20; i++) {
    xa_idx_3 = 0.0;
    for (idx_current = 0; idx_current < 10; idx_current++) {
      xa_idx_3 += (real_T)iv[i + 20 * idx_current] * x[idx_current + 40];
    }
    a[i] = xa_idx_3;
  }
  for (i = 0; i < 2; i++) {
    for (idx_current = 0; idx_current < 10; idx_current++) {
      Umv[idx_current + 11 * i] = a[i + (idx_current << 1)];
    }
  }
  memcpy(&b_x[0], &x[0], 40U * sizeof(real_T));
  for (i = 0; i < 4; i++) {
    for (idx_current = 0; idx_current < 10; idx_current++) {
      X[(idx_current + 11 * i) + 1] = b_x[i + (idx_current << 2)];
    }
    X[11 * i] = e_obj_next_next_next_next_next_->runtimedata.x[i];
  }
  for (b_i = 0; b_i < 2; b_i++) {
    xa_idx_3 = Umv[11 * b_i + 9];
    Umv[11 * b_i + 10] = xa_idx_3;
    memcpy(&U[b_i * 11], &Umv[b_i * 11], 11U * sizeof(real_T));
  }
  memset(&gfX[0], 0, 40U * sizeof(real_T));
  memset(&gfU[0], 0, 20U * sizeof(real_T));
  fs = 0.0;
  ix_idx_0 = 1;
  ix_idx_1 = 2;
  ix_idx_2 = 3;
  ix_idx_3 = 4;
  iu_idx_0 = 1;
  iu_idx_1 = 2;
  for (i = 0; i < 11; i++) {
    idx_current = i << 2;
    b_X[idx_current] = X[i];
    b_X[idx_current + 1] = X[i + 11];
    b_X[idx_current + 2] = X[i + 22];
    b_X[idx_current + 3] = X[i + 33];
    idx_current = i << 1;
    b_U[idx_current] = U[i];
    b_U[idx_current + 1] = U[i + 11];
  }
  memcpy(&Umv[0], &b_U[0], 22U * sizeof(real_T));
  idx_mat = e_obj_next_next_next_next_next_->runtimedata.ref->size[1];
  for (b_i = 0; b_i < 10; b_i++) {
    real_T b_wtYerr;
    real_T xa_idx_0;
    real_T xa_idx_1;
    real_T xa_idx_2;
    xa_idx_0 = e_obj_next_next_next_next_next_->runtimedata.OutputWeights[b_i];
    i = wtYerr->size[0];
    wtYerr->size[0] = e_obj_next_next_next_next_next_->runtimedata.ref->size[1];
    emxEnsureCapacity_real_T(wtYerr, i);
    wtYerr_data = wtYerr->data;
    for (i = 0; i < idx_mat; i++) {
      wtYerr_data[i] =
          xa_idx_0 *
          (0.0 - e_obj_next_next_next_next_next_->runtimedata.ref
                     ->data[b_i + e_obj_next_next_next_next_next_->runtimedata
                                          .ref->size[0] *
                                      i]);
    }
    if (wtYerr->size[0] < 1) {
      xa_idx_0 = 0.0;
    } else {
      n_t = (ptrdiff_t)wtYerr->size[0];
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      xa_idx_0 = ddot(&n_t, &wtYerr_data[0], &incx_t, &wtYerr_data[0], &incy_t);
    }
    fs += xa_idx_0;
    xa_idx_0 = e_obj_next_next_next_next_next_->runtimedata.OutputWeights[b_i];
    idx_current = wtYerr->size[0];
    col = (idx_current / 2) << 1;
    col_end = col - 2;
    for (i = 0; i <= col_end; i += 2) {
      r = _mm_loadu_pd(&wtYerr_data[i]);
      _mm_storeu_pd(&wtYerr_data[i], _mm_mul_pd(_mm_set1_pd(xa_idx_0), r));
    }
    for (i = col; i < idx_current; i++) {
      wtYerr_data[i] *= xa_idx_0;
    }
    idx_current = (b_i + 1) << 2;
    xa_idx_0 = muDoubleScalarAbs(b_X[idx_current]);
    xa_idx_1 = muDoubleScalarAbs(b_X[idx_current + 1]);
    xa_idx_2 = muDoubleScalarAbs(b_X[idx_current + 2]);
    xa_idx_3 = muDoubleScalarAbs(b_X[idx_current + 3]);
    if (xa_idx_0 < 1.0) {
      xa_idx_0 = 1.0;
    }
    if (xa_idx_1 < 1.0) {
      xa_idx_1 = 1.0;
    }
    if (xa_idx_2 < 1.0) {
      xa_idx_2 = 1.0;
    }
    if (xa_idx_3 < 1.0) {
      xa_idx_3 = 1.0;
    }
    b_wtYerr = wtYerr_data[0];
    xa_idx_0 = gfX[ix_idx_0 - 1] + 0.0 / (1.0E-6 * xa_idx_0) * b_wtYerr;
    xa_idx_1 = gfX[ix_idx_1 - 1] + 0.0 / (1.0E-6 * xa_idx_1) * b_wtYerr;
    xa_idx_2 = gfX[ix_idx_2 - 1] + 0.0 / (1.0E-6 * xa_idx_2) * b_wtYerr;
    xa_idx_3 = gfX[ix_idx_3 - 1] + 0.0 / (1.0E-6 * xa_idx_3) * b_wtYerr;
    gfX[ix_idx_0 - 1] = xa_idx_0;
    ix_idx_0 = (int8_T)(ix_idx_0 + 4);
    gfX[ix_idx_1 - 1] = xa_idx_1;
    ix_idx_1 = (int8_T)(ix_idx_1 + 4);
    gfX[ix_idx_2 - 1] = xa_idx_2;
    ix_idx_2 = (int8_T)(ix_idx_2 + 4);
    gfX[ix_idx_3 - 1] = xa_idx_3;
    ix_idx_3 = (int8_T)(ix_idx_3 + 4);
    idx_current = b_i << 1;
    umvk[0] = Umv[idx_current];
    umvk[1] = Umv[idx_current + 1];
    if (b_i + 1 == 1) {
      __m128d r1;
      r = _mm_loadu_pd(&umvk[0]);
      r1 =
          _mm_loadu_pd(&e_obj_next_next_next_next_next_->runtimedata.lastMV[0]);
      _mm_storeu_pd(&duk[0], _mm_sub_pd(r, r1));
    } else {
      __m128d r1;
      r = _mm_loadu_pd(&umvk[0]);
      r1 = _mm_loadu_pd(&Umv[(b_i - 1) << 1]);
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
      idx_current =
          e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget->size[1];
      for (i = 0; i < idx_current; i++) {
        wtYerr_data[i] =
            e_obj_next_next_next_next_next_->runtimedata.MVScaledTarget
                ->data[b_i + e_obj_next_next_next_next_next_->runtimedata
                                     .MVScaledTarget->size[0] *
                                 i];
      }
    }
    if (wtYerr->size[0] == 2) {
      umvk[0] = e_obj_next_next_next_next_next_->runtimedata.MVWeights[b_i] *
                (umvk[0] - wtYerr_data[0]);
      umvk[1] =
          e_obj_next_next_next_next_next_->runtimedata.MVWeights[b_i + 10] *
          (umvk[1] - wtYerr_data[1]);
    } else {
      binary_expand_op(umvk, e_obj_next_next_next_next_next_, b_i, wtYerr);
    }
    xa_idx_3 = umvk[0];
    xa_idx_0 = xa_idx_3 * xa_idx_3;
    xa_idx_1 =
        gfU[iu_idx_0 - 1] +
        e_obj_next_next_next_next_next_->runtimedata.MVWeights[b_i] * xa_idx_3;
    xa_idx_3 = umvk[1];
    xa_idx_0 += xa_idx_3 * xa_idx_3;
    xa_idx_2 =
        gfU[iu_idx_1 - 1] +
        e_obj_next_next_next_next_next_->runtimedata.MVWeights[b_i + 10] *
            xa_idx_3;
    fs += xa_idx_0;
    gfU[iu_idx_0 - 1] = xa_idx_1;
    xa_idx_3 = duk[0];
    xa_idx_0 = e_obj_next_next_next_next_next_->runtimedata.MVRateWeights[b_i];
    xa_idx_3 *= xa_idx_0;
    xa_idx_1 = xa_idx_3 * xa_idx_3;
    xa_idx_3 *= xa_idx_0;
    duk[0] = xa_idx_3;
    gfU[iu_idx_1 - 1] = xa_idx_2;
    xa_idx_3 = duk[1];
    xa_idx_0 =
        e_obj_next_next_next_next_next_->runtimedata.MVRateWeights[b_i + 10];
    xa_idx_3 *= xa_idx_0;
    xa_idx_1 += xa_idx_3 * xa_idx_3;
    xa_idx_3 *= xa_idx_0;
    duk[1] = xa_idx_3;
    fs += xa_idx_1;
    umvk[0] = gfU[iu_idx_0 - 1] + duk[0];
    umvk[1] = gfU[iu_idx_1 - 1] + duk[1];
    gfU[iu_idx_0 - 1] = umvk[0];
    gfU[iu_idx_1 - 1] = umvk[1];
    if (b_i + 1 > 1) {
      umvk[0] = gfU[(int8_T)(iu_idx_0 - 2) - 1] - duk[0];
      umvk[1] = gfU[(int8_T)(iu_idx_1 - 2) - 1] - duk[1];
      gfU[(int8_T)(iu_idx_0 - 2) - 1] = umvk[0];
      gfU[(int8_T)(iu_idx_1 - 2) - 1] = umvk[1];
    }
    iu_idx_0 = (int8_T)(iu_idx_0 + 2);
    iu_idx_1 = (int8_T)(iu_idx_1 + 2);
  }
  fval = fs +
         e_obj_next_next_next_next_next_->runtimedata.ECRWeight * x[50] * x[50];
  for (i = 0; i <= 38; i += 2) {
    r = _mm_loadu_pd(&gfX[i]);
    _mm_storeu_pd(&gfX[i], _mm_mul_pd(_mm_set1_pd(2.0), r));
  }
  for (i = 0; i <= 18; i += 2) {
    r = _mm_loadu_pd(&gfU[i]);
    _mm_storeu_pd(&gfU[i], _mm_mul_pd(_mm_set1_pd(2.0), r));
  }
  for (i = 0; i < 10; i++) {
    xa_idx_3 = 0.0;
    for (idx_current = 0; idx_current < 20; idx_current++) {
      xa_idx_3 += (real_T)b_iv[i + 10 * idx_current] * gfU[idx_current];
    }
    b_dv[i] = xa_idx_3;
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
      wtYerr_data = varargout_1->data;
      n_t = (ptrdiff_t)c_obj_next_next_next_next_next_;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &wtYerr_data[0], &incx_t, &Cineq_workspace_data[ineq0 - 1],
            &incy_t);
      memcpy(&Ceq_workspace[eq0 + -1], &gfX[0], 40U * sizeof(real_T));
      i = varargout_3->size[0];
      for (col = 0; col < i; col++) {
        idx_current = varargout_3->size[1];
        for (col_end = 0; col_end < idx_current; col_end++) {
          JacIneqTrans_workspace_data[col + ldJI * ((iJI_col + col_end) - 1)] =
              grad_workspace_data[col + varargout_3->size[0] * col_end];
        }
      }
      for (col = 0; col < 51; col++) {
        for (col_end = 0; col_end < 40; col_end++) {
          JacEqTrans_workspace_data[col + ldJE * ((iJE_col + col_end) - 1)] =
              varargout_4[col + 51 * col_end];
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
      for (col = 0; col < 51; col++) {
        for (col_end = 0; col_end < 40; col_end++) {
          JacEqTrans_workspace_data[col + ldJE * ((iJE_col + col_end) - 1)] =
              varargout_4[col + 51 * col_end];
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
  emxFree_real_T(&wtYerr);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

/* End of code generation (evalObjAndConstrAndDerivatives.c) */
