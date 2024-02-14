/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factoryConstruct1.c
 *
 * Code generation for function 'factoryConstruct1'
 *
 */

/* Include files */
#include "factoryConstruct1.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void b_factoryConstruct(const i_struct_T *objfun_workspace_runtimedata,
                        const j_struct_T *objfun_workspace_userdata,
                        const i_struct_T *nonlin_workspace_runtimedata,
                        const j_struct_T *nonlin_workspace_userdata,
                        int32_T mCineq, const real_T lb[51],
                        const real_T ub[51], l_struct_T *obj)
{
  int32_T idx;
  boolean_T b;
  emxCopyStruct_struct_T(&obj->objfun.workspace.runtimedata,
                         objfun_workspace_runtimedata);
  emxCopyStruct_struct_T1(&obj->objfun.workspace.userdata,
                          objfun_workspace_userdata);
  emxCopyStruct_struct_T(&obj->nonlin.workspace.runtimedata,
                         nonlin_workspace_runtimedata);
  emxCopyStruct_struct_T1(&obj->nonlin.workspace.userdata,
                          nonlin_workspace_userdata);
  idx = obj->cIneq_1->size[0];
  obj->cIneq_1->size[0] = mCineq;
  emxEnsureCapacity_real_T(obj->cIneq_1, idx);
  idx = obj->cIneq_2->size[0];
  obj->cIneq_2->size[0] = mCineq;
  emxEnsureCapacity_real_T(obj->cIneq_2, idx);
  obj->numEvals = 0;
  b = false;
  idx = 0;
  while ((!b) && (idx + 1 <= 51)) {
    obj->hasLB[idx] =
        ((!muDoubleScalarIsInf(lb[idx])) && (!muDoubleScalarIsNaN(lb[idx])));
    obj->hasUB[idx] =
        ((!muDoubleScalarIsInf(ub[idx])) && (!muDoubleScalarIsNaN(ub[idx])));
    if (obj->hasLB[idx] || obj->hasUB[idx]) {
      b = true;
    }
    idx++;
  }
  while (idx + 1 <= 51) {
    obj->hasLB[idx] =
        ((!muDoubleScalarIsInf(lb[idx])) && (!muDoubleScalarIsNaN(lb[idx])));
    obj->hasUB[idx] =
        ((!muDoubleScalarIsInf(ub[idx])) && (!muDoubleScalarIsNaN(ub[idx])));
    idx++;
  }
}

/* End of code generation (factoryConstruct1.c) */
