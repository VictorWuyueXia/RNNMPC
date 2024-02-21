/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * znlmpc_reformJacobian.c
 *
 * Code generation for function 'znlmpc_reformJacobian'
 *
 */

/* Include files */
#include "znlmpc_reformJacobian.h"
#include "mtimes.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void znlmpc_reformJacobian(const emxArray_real_T *Jx,
                           const emxArray_real_T *Jmv,
                           const emxArray_real_T *Je, emxArray_real_T *Jc)
{
  emxArray_real_T b_Jmv;
  emxArray_real_T *b_Je;
  emxArray_real_T *varargin_1;
  emxArray_real_T *varargin_2;
  emxArray_real_T *y;
  const real_T *Je_data;
  const real_T *Jx_data;
  real_T *Jc_data;
  real_T *b_Je_data;
  real_T *varargin_1_data;
  real_T *varargin_2_data;
  int32_T b_Jx[2];
  int32_T i;
  int32_T i1;
  Je_data = Je->data;
  Jx_data = Jx->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  if (Jx->size[0] == 0) {
    Jc->size[0] = 0;
    Jc->size[1] = 0;
  } else {
    int32_T Jx_idx_0;
    int32_T loop_ub;
    int32_T sizes_tmp;
    Jx_idx_0 = Jx->size[0];
    b_Jmv = *Jmv;
    b_Jx[0] = Jx_idx_0;
    b_Jx[1] = 20;
    b_Jmv.size = &b_Jx[0];
    b_Jmv.numDimensions = 2;
    emxInit_real_T(&y, 2);
    mtimes(&b_Jmv, y);
    Jc_data = y->data;
    Jx_idx_0 = Jx->size[0];
    emxInit_real_T(&varargin_1, 2);
    i = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 40;
    varargin_1->size[1] = Jx->size[0];
    emxEnsureCapacity_real_T(varargin_1, i);
    varargin_1_data = varargin_1->data;
    loop_ub = Jx->size[0];
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < 40; i1++) {
        varargin_1_data[i1 + 40 * i] = Jx_data[i + Jx_idx_0 * i1];
      }
    }
    emxInit_real_T(&varargin_2, 2);
    i = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 10;
    varargin_2->size[1] = y->size[0];
    emxEnsureCapacity_real_T(varargin_2, i);
    varargin_2_data = varargin_2->data;
    loop_ub = y->size[0];
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < 10; i1++) {
        varargin_2_data[i1 + 10 * i] = Jc_data[i + y->size[0] * i1];
      }
    }
    emxFree_real_T(&y);
    if (varargin_2->size[1] != 0) {
      Jx_idx_0 = 10;
    } else {
      Jx_idx_0 = 0;
    }
    emxInit_real_T(&b_Je, 2);
    i = b_Je->size[0] * b_Je->size[1];
    b_Je->size[0] = 1;
    b_Je->size[1] = Je->size[0];
    emxEnsureCapacity_real_T(b_Je, i);
    b_Je_data = b_Je->data;
    loop_ub = Je->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_Je_data[i] = Je_data[i];
    }
    sizes_tmp = (Je->size[0] != 0);
    i = Jc->size[0] * Jc->size[1];
    Jc->size[0] = (Jx_idx_0 + sizes_tmp) + 40;
    Jc->size[1] = varargin_1->size[1];
    emxEnsureCapacity_real_T(Jc, i);
    Jc_data = Jc->data;
    loop_ub = varargin_1->size[1];
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < 40; i1++) {
        Jc_data[i1 + Jc->size[0] * i] = varargin_1_data[i1 + 40 * i];
      }
      for (i1 = 0; i1 < Jx_idx_0; i1++) {
        Jc_data[(i1 + Jc->size[0] * i) + 40] =
            varargin_2_data[i1 + Jx_idx_0 * i];
      }
      for (i1 = 0; i1 < sizes_tmp; i1++) {
        Jc_data[(Jx_idx_0 + Jc->size[0] * i) + 40] = b_Je_data[sizes_tmp * i];
      }
    }
    emxFree_real_T(&b_Je);
    emxFree_real_T(&varargin_2);
    emxFree_real_T(&varargin_1);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (znlmpc_reformJacobian.c) */
