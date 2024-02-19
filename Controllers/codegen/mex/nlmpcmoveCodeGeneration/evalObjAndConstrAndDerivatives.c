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
#include "cosd.h"
#include "nlmpcmoveCodeGeneration.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include "blas.h"
#include "mwmathutil.h"
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
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emxArray_real_T *varargout_1;
  emxArray_real_T *varargout_3;
  real_T varargout_4[2040];
  real_T varargout_2[51];
  real_T X[44];
  real_T xa[44];
  real_T b_x[40];
  real_T U[22];
  real_T Umv[22];
  real_T a[20];
  real_T b_dv[10];
  real_T R_tmp;
  real_T cost_inputs;
  real_T cost_progress;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T dx;
  real_T f_obj_next_next_next_next_next_;
  real_T fval;
  real_T g_obj_next_next_next_next_next_;
  real_T target_relative_idx_0;
  real_T *Cineq_workspace_data;
  real_T *JacEqTrans_workspace_data;
  real_T *JacIneqTrans_workspace_data;
  real_T *grad_workspace_data;
  real_T *varargout_1_data;
  int32_T col;
  int32_T col_end;
  int32_T idx_current;
  int32_T idx_mat;
  int32_T j;
  boolean_T allFinite;
  JacEqTrans_workspace_data = JacEqTrans_workspace->data;
  JacIneqTrans_workspace_data = JacIneqTrans_workspace->data;
  Cineq_workspace_data = Cineq_workspace->data;
  grad_workspace_data = grad_workspace->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  memset(&X[0], 0, 44U * sizeof(real_T));
  memset(&Umv[0], 0, 22U * sizeof(real_T));
  for (idx_current = 0; idx_current < 20; idx_current++) {
    d = 0.0;
    for (col = 0; col < 10; col++) {
      d += (real_T)iv[idx_current + 20 * col] * x[col + 40];
    }
    a[idx_current] = d;
  }
  for (idx_current = 0; idx_current < 2; idx_current++) {
    for (col = 0; col < 10; col++) {
      Umv[col + 11 * idx_current] = a[idx_current + (col << 1)];
    }
  }
  memcpy(&b_x[0], &x[0], 40U * sizeof(real_T));
  for (idx_current = 0; idx_current < 4; idx_current++) {
    for (col = 0; col < 10; col++) {
      X[(col + 11 * idx_current) + 1] = b_x[idx_current + (col << 2)];
    }
    X[11 * idx_current] =
        e_obj_next_next_next_next_next_->runtimedata.x[idx_current];
  }
  for (idx_mat = 0; idx_mat < 2; idx_mat++) {
    Umv[11 * idx_mat + 10] = Umv[11 * idx_mat + 9];
    memcpy(&U[idx_mat * 11], &Umv[idx_mat * 11], 11U * sizeof(real_T));
  }
  /*  weights is fed in as an array of  */
  /*  [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL
   * sofConstraints] */
  cost_progress = 0.0;
  for (idx_mat = 0; idx_mat < 11; idx_mat++) {
    /*  Rotation matrix for transforming to the vehicle's local frame */
    cost_inputs = -X[idx_mat + 22];
    R_tmp = cost_inputs;
    b_sind(&R_tmp);
    b_cosd(&cost_inputs);
    f_obj_next_next_next_next_next_ =
        e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[0] -
        X[idx_mat];
    g_obj_next_next_next_next_next_ =
        e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[3] -
        X[idx_mat + 11];
    target_relative_idx_0 = cost_inputs * f_obj_next_next_next_next_next_ +
                            -R_tmp * g_obj_next_next_next_next_next_;
    d = R_tmp * f_obj_next_next_next_next_next_ +
        cost_inputs * g_obj_next_next_next_next_next_;
    cost_progress +=
        (target_relative_idx_0 *
             e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[4] +
         d * e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[5]) *
            target_relative_idx_0 +
        (target_relative_idx_0 *
             e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[6] +
         d * e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[7]) *
            d;
  }
  /*  quadratic cost for inputs */
  cost_inputs = 0.0;
  d = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[0];
  d1 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[1];
  d2 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[2];
  d3 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[3];
  for (idx_mat = 0; idx_mat < 11; idx_mat++) {
    f_obj_next_next_next_next_next_ = U[idx_mat + 11];
    R_tmp = U[idx_mat];
    cost_inputs += (R_tmp * d + f_obj_next_next_next_next_next_ * d1) * R_tmp +
                   (R_tmp * d2 + f_obj_next_next_next_next_next_ * d3) *
                       f_obj_next_next_next_next_next_;
  }
  fval = cost_progress + cost_inputs;
  memset(&a[0], 0, 20U * sizeof(real_T));
  for (idx_current = 0; idx_current < 44; idx_current++) {
    d = muDoubleScalarAbs(X[idx_current]);
    xa[idx_current] = d;
    if (d < 1.0) {
      xa[idx_current] = 1.0;
    }
  }
  d = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[0];
  d1 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[1];
  d2 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[2];
  d3 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[3];
  for (idx_mat = 0; idx_mat < 10; idx_mat++) {
    for (j = 0; j < 4; j++) {
      dx = 1.0E-6 * xa[j];
      idx_current = (idx_mat + 11 * j) + 1;
      X[idx_current] += dx;
      /*  weights is fed in as an array of  */
      /*  [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL
       * sofConstraints] */
      cost_progress = 0.0;
      for (col_end = 0; col_end < 11; col_end++) {
        /*  Rotation matrix for transforming to the vehicle's local frame */
        cost_inputs = -X[col_end + 22];
        R_tmp = cost_inputs;
        b_sind(&R_tmp);
        b_cosd(&cost_inputs);
        f_obj_next_next_next_next_next_ =
            e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[0] -
            X[col_end];
        g_obj_next_next_next_next_next_ =
            e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[3] -
            X[col_end + 11];
        target_relative_idx_0 = cost_inputs * f_obj_next_next_next_next_next_ +
                                -R_tmp * g_obj_next_next_next_next_next_;
        f_obj_next_next_next_next_next_ =
            R_tmp * f_obj_next_next_next_next_next_ +
            cost_inputs * g_obj_next_next_next_next_next_;
        cost_progress +=
            (target_relative_idx_0 *
                 e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[4] +
             f_obj_next_next_next_next_next_ *
                 e_obj_next_next_next_next_next_->runtimedata.Parameters
                     .f4[5]) *
                target_relative_idx_0 +
            (target_relative_idx_0 *
                 e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[6] +
             f_obj_next_next_next_next_next_ *
                 e_obj_next_next_next_next_next_->runtimedata.Parameters
                     .f4[7]) *
                f_obj_next_next_next_next_next_;
      }
      /*  quadratic cost for inputs */
      cost_inputs = 0.0;
      for (col_end = 0; col_end < 11; col_end++) {
        f_obj_next_next_next_next_next_ = U[col_end + 11];
        R_tmp = U[col_end];
        cost_inputs +=
            (R_tmp * d + f_obj_next_next_next_next_next_ * d1) * R_tmp +
            (R_tmp * d2 + f_obj_next_next_next_next_next_ * d3) *
                f_obj_next_next_next_next_next_;
      }
      X[idx_current] -= dx;
      b_x[j + (idx_mat << 2)] = ((cost_progress + cost_inputs) - fval) / dx;
    }
  }
  for (idx_current = 0; idx_current < 22; idx_current++) {
    d = muDoubleScalarAbs(U[idx_current]);
    Umv[idx_current] = d;
    if (d < 1.0) {
      Umv[idx_current] = 1.0;
    }
  }
  d = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[0];
  d1 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[1];
  d2 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[2];
  d3 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[3];
  for (idx_mat = 0; idx_mat < 9; idx_mat++) {
    for (j = 0; j < 2; j++) {
      dx = 1.0E-6 * Umv[j];
      col = idx_mat + 11 * j;
      U[col] += dx;
      /*  weights is fed in as an array of  */
      /*  [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL
       * sofConstraints] */
      cost_progress = 0.0;
      for (col_end = 0; col_end < 11; col_end++) {
        /*  Rotation matrix for transforming to the vehicle's local frame */
        cost_inputs = -X[col_end + 22];
        R_tmp = cost_inputs;
        b_sind(&R_tmp);
        b_cosd(&cost_inputs);
        f_obj_next_next_next_next_next_ =
            e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[0] -
            X[col_end];
        g_obj_next_next_next_next_next_ =
            e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[3] -
            X[col_end + 11];
        target_relative_idx_0 = cost_inputs * f_obj_next_next_next_next_next_ +
                                -R_tmp * g_obj_next_next_next_next_next_;
        f_obj_next_next_next_next_next_ =
            R_tmp * f_obj_next_next_next_next_next_ +
            cost_inputs * g_obj_next_next_next_next_next_;
        cost_progress +=
            (target_relative_idx_0 *
                 e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[4] +
             f_obj_next_next_next_next_next_ *
                 e_obj_next_next_next_next_next_->runtimedata.Parameters
                     .f4[5]) *
                target_relative_idx_0 +
            (target_relative_idx_0 *
                 e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[6] +
             f_obj_next_next_next_next_next_ *
                 e_obj_next_next_next_next_next_->runtimedata.Parameters
                     .f4[7]) *
                f_obj_next_next_next_next_next_;
      }
      /*  quadratic cost for inputs */
      cost_inputs = 0.0;
      for (col_end = 0; col_end < 11; col_end++) {
        f_obj_next_next_next_next_next_ = U[col_end + 11];
        R_tmp = U[col_end];
        cost_inputs +=
            (R_tmp * d + f_obj_next_next_next_next_next_ * d1) * R_tmp +
            (R_tmp * d2 + f_obj_next_next_next_next_next_ * d3) *
                f_obj_next_next_next_next_next_;
      }
      U[col] -= dx;
      a[j + (idx_mat << 1)] = ((cost_progress + cost_inputs) - fval) / dx;
    }
  }
  d = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[0];
  d1 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[1];
  d2 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[2];
  d3 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[3];
  for (j = 0; j < 2; j++) {
    dx = 1.0E-6 * Umv[j];
    col = 11 * j + 9;
    U[col] += dx;
    idx_current = 11 * j + 10;
    U[idx_current] += dx;
    /*  weights is fed in as an array of  */
    /*  [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL
     * sofConstraints] */
    cost_progress = 0.0;
    for (idx_mat = 0; idx_mat < 11; idx_mat++) {
      /*  Rotation matrix for transforming to the vehicle's local frame */
      cost_inputs = -X[idx_mat + 22];
      R_tmp = cost_inputs;
      b_sind(&R_tmp);
      b_cosd(&cost_inputs);
      f_obj_next_next_next_next_next_ =
          e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[0] -
          X[idx_mat];
      g_obj_next_next_next_next_next_ =
          e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[3] -
          X[idx_mat + 11];
      target_relative_idx_0 = cost_inputs * f_obj_next_next_next_next_next_ +
                              -R_tmp * g_obj_next_next_next_next_next_;
      f_obj_next_next_next_next_next_ =
          R_tmp * f_obj_next_next_next_next_next_ +
          cost_inputs * g_obj_next_next_next_next_next_;
      cost_progress +=
          (target_relative_idx_0 *
               e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[4] +
           f_obj_next_next_next_next_next_ *
               e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[5]) *
              target_relative_idx_0 +
          (target_relative_idx_0 *
               e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[6] +
           f_obj_next_next_next_next_next_ *
               e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[7]) *
              f_obj_next_next_next_next_next_;
    }
    /*  quadratic cost for inputs */
    cost_inputs = 0.0;
    for (idx_mat = 0; idx_mat < 11; idx_mat++) {
      f_obj_next_next_next_next_next_ = U[idx_mat + 11];
      R_tmp = U[idx_mat];
      cost_inputs +=
          (R_tmp * d + f_obj_next_next_next_next_next_ * d1) * R_tmp +
          (R_tmp * d2 + f_obj_next_next_next_next_next_ * d3) *
              f_obj_next_next_next_next_next_;
    }
    U[col] -= dx;
    U[idx_current] -= dx;
    a[j + 18] = ((cost_progress + cost_inputs) - fval) / dx;
  }
  /*  weights is fed in as an array of  */
  /*  [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL
   * sofConstraints] */
  cost_progress = 0.0;
  for (idx_mat = 0; idx_mat < 11; idx_mat++) {
    /*  Rotation matrix for transforming to the vehicle's local frame */
    cost_inputs = -X[idx_mat + 22];
    R_tmp = cost_inputs;
    b_sind(&R_tmp);
    b_cosd(&cost_inputs);
    f_obj_next_next_next_next_next_ =
        e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[0] -
        X[idx_mat];
    g_obj_next_next_next_next_next_ =
        e_obj_next_next_next_next_next_->runtimedata.Parameters.f3[3] -
        X[idx_mat + 11];
    target_relative_idx_0 = cost_inputs * f_obj_next_next_next_next_next_ +
                            -R_tmp * g_obj_next_next_next_next_next_;
    d = R_tmp * f_obj_next_next_next_next_next_ +
        cost_inputs * g_obj_next_next_next_next_next_;
    cost_progress +=
        (target_relative_idx_0 *
             e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[4] +
         d * e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[5]) *
            target_relative_idx_0 +
        (target_relative_idx_0 *
             e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[6] +
         d * e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[7]) *
            d;
  }
  /*  quadratic cost for inputs */
  cost_inputs = 0.0;
  d = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[0];
  d1 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[1];
  d2 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[2];
  d3 = e_obj_next_next_next_next_next_->runtimedata.Parameters.f4[3];
  for (idx_mat = 0; idx_mat < 11; idx_mat++) {
    f_obj_next_next_next_next_next_ = U[idx_mat + 11];
    R_tmp = U[idx_mat];
    cost_inputs += (R_tmp * d + f_obj_next_next_next_next_next_ * d1) * R_tmp +
                   (R_tmp * d2 + f_obj_next_next_next_next_next_ * d3) *
                       f_obj_next_next_next_next_next_;
  }
  cost_inputs += cost_progress;
  for (idx_current = 0; idx_current < 10; idx_current++) {
    d = 0.0;
    for (col = 0; col < 20; col++) {
      d += (real_T)b_iv[idx_current + 10 * col] * a[col];
    }
    b_dv[idx_current] = d;
  }
  memcpy(&varargout_2[0], &b_x[0], 40U * sizeof(real_T));
  memcpy(&varargout_2[40], &b_dv[0], 10U * sizeof(real_T));
  varargout_2[50] =
      (cost_inputs - cost_inputs) /
      (2.0 * (muDoubleScalarMax(1.0E-6, muDoubleScalarAbs(x[50])) * 1.0E-6));
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
          d_obj_next_next_next_next_next_->Parameters.f2, x, varargout_1, b_x,
          varargout_3, varargout_4);
      grad_workspace_data = varargout_3->data;
      varargout_1_data = varargout_1->data;
      n_t = (ptrdiff_t)c_obj_next_next_next_next_next_;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &varargout_1_data[0], &incx_t,
            &Cineq_workspace_data[ineq0 - 1], &incy_t);
      memcpy(&Ceq_workspace[eq0 + -1], &b_x[0], 40U * sizeof(real_T));
      idx_current = varargout_3->size[0];
      for (col_end = 0; col_end < idx_current; col_end++) {
        col = varargout_3->size[1];
        for (idx_mat = 0; idx_mat < col; idx_mat++) {
          JacIneqTrans_workspace_data[col_end +
                                      ldJI * ((iJI_col + idx_mat) - 1)] =
              grad_workspace_data[col_end + varargout_3->size[0] * idx_mat];
        }
      }
      for (col_end = 0; col_end < 51; col_end++) {
        for (idx_mat = 0; idx_mat < 40; idx_mat++) {
          JacEqTrans_workspace_data[col_end +
                                    ldJE * ((iJE_col + idx_mat) - 1)] =
              varargout_4[col_end + 51 * idx_mat];
        }
      }
    } else {
      c_nlmpcmoveCodeGeneration_anonF(
          d_obj_next_next_next_next_next_->x,
          d_obj_next_next_next_next_next_->OutputMin,
          d_obj_next_next_next_next_next_->OutputMax,
          d_obj_next_next_next_next_next_->Parameters.f1,
          d_obj_next_next_next_next_next_->Parameters.f2, x, varargout_1, b_x,
          varargout_3, varargout_4);
      memcpy(&Ceq_workspace[eq0 + -1], &b_x[0], 40U * sizeof(real_T));
      for (col_end = 0; col_end < 51; col_end++) {
        for (idx_mat = 0; idx_mat < 40; idx_mat++) {
          JacEqTrans_workspace_data[col_end +
                                    ldJE * ((iJE_col + idx_mat) - 1)] =
              varargout_4[col_end + 51 * idx_mat];
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
