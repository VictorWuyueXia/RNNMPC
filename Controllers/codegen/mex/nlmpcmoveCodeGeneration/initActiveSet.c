/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * initActiveSet.c
 *
 * Code generation for function 'initActiveSet'
 *
 */

/* Include files */
#include "initActiveSet.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include <string.h>

/* Function Definitions */
void initActiveSet(d_struct_T *obj)
{
  int32_T b_i;
  int32_T i;
  int32_T idxFillStart;
  int32_T idx_global;
  int32_T idx_local;
  int32_T nWFixed;
  setProblemType(obj, 3);
  idxFillStart = obj->isActiveIdx[2];
  i = obj->mConstrMax;
  for (idx_global = idxFillStart; idx_global <= i; idx_global++) {
    obj->isActiveConstr->data[idx_global - 1] = false;
  }
  obj->nWConstr[0] = obj->sizes[0];
  obj->nWConstr[1] = obj->sizes[1];
  obj->nWConstr[2] = 0;
  obj->nWConstr[3] = 0;
  obj->nWConstr[4] = 0;
  obj->nActiveConstr = obj->nWConstr[0] + obj->nWConstr[1];
  nWFixed = obj->sizes[0];
  for (idx_local = 0; idx_local < nWFixed; idx_local++) {
    obj->Wid->data[idx_local] = 1;
    obj->Wlocalidx->data[idx_local] = idx_local + 1;
    obj->isActiveConstr->data[idx_local] = true;
    idxFillStart = obj->ldA * idx_local;
    i = obj->indexFixed->data[idx_local];
    for (b_i = 0; b_i <= i - 2; b_i++) {
      obj->ATwset->data[b_i + idxFillStart] = 0.0;
    }
    obj->ATwset->data[(obj->indexFixed->data[idx_local] + idxFillStart) - 1] =
        1.0;
    i = obj->indexFixed->data[idx_local] + 1;
    idx_global = obj->nVar;
    for (b_i = i; b_i <= idx_global; b_i++) {
      obj->ATwset->data[(b_i + idxFillStart) - 1] = 0.0;
    }
    obj->bwset->data[idx_local] =
        obj->ub->data[obj->indexFixed->data[idx_local] - 1];
  }
  idxFillStart = obj->sizes[1];
  for (idx_local = 0; idx_local < idxFillStart; idx_local++) {
    int32_T iATw0;
    int32_T iAeq0;
    idx_global = nWFixed + idx_local;
    obj->Wid->data[idx_global] = 2;
    obj->Wlocalidx->data[idx_global] = idx_local + 1;
    obj->isActiveConstr->data[idx_global] = true;
    iAeq0 = obj->ldA * idx_local;
    iATw0 = obj->ldA * idx_global;
    i = obj->nVar - 1;
    for (b_i = 0; b_i <= i; b_i++) {
      obj->ATwset->data[iATw0 + b_i] = obj->Aeq->data[iAeq0 + b_i];
    }
    obj->bwset->data[idx_global] = obj->beq[idx_local];
  }
}

/* End of code generation (initActiveSet.c) */
