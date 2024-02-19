/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nlmpcmoveCodeGeneration_emxutil.c
 *
 * Code generation for function 'nlmpcmoveCodeGeneration_emxutil'
 *
 */

/* Include files */
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void c_emxFreeStruct_anonymous_funct(anonymous_function *pStruct)
{
  emxFreeStruct_struct_T3(&pStruct->workspace);
}

void c_emxFreeStruct_coder_internal_(b_coder_internal_stickyStruct *pStruct)
{
  c_emxFreeStruct_anonymous_funct(&pStruct->value);
  d_emxFreeStruct_coder_internal_(&pStruct->next);
}

void c_emxInitStruct_anonymous_funct(anonymous_function *pStruct)
{
  emxInitStruct_struct_T3(&pStruct->workspace);
}

void c_emxInitStruct_coder_internal_(i_coder_internal_stickyStruct *pStruct)
{
  d_emxInitStruct_coder_internal_(&pStruct->next);
}

void d_emxFreeStruct_coder_internal_(coder_internal_stickyStruct *pStruct)
{
  c_emxFreeStruct_anonymous_funct(&pStruct->value);
}

void d_emxInitStruct_coder_internal_(h_coder_internal_stickyStruct *pStruct)
{
  e_emxInitStruct_coder_internal_(&pStruct->next);
}

void e_emxFreeStruct_coder_internal_(c_coder_internal_stickyStruct *pStruct)
{
  c_emxFreeStruct_coder_internal_(&pStruct->next);
}

void e_emxInitStruct_coder_internal_(g_coder_internal_stickyStruct *pStruct)
{
  f_emxInitStruct_coder_internal_(&pStruct->next);
}

void emxCopyMatrix_real_T(real_T dst[4], const real_T src[4])
{
  int32_T i;
  for (i = 0; i < 4; i++) {
    dst[i] = src[i];
  }
}

void emxCopyMatrix_real_T1(real_T dst[2], const real_T src[2])
{
  int32_T i;
  for (i = 0; i < 2; i++) {
    dst[i] = src[i];
  }
}

void emxCopyMatrix_real_T3(real_T dst[10], const real_T src[10])
{
  memcpy(&dst[0], &src[0], 10U * sizeof(real_T));
}

void emxCopyMatrix_real_T4(real_T dst[20], const real_T src[20])
{
  memcpy(&dst[0], &src[0], 20U * sizeof(real_T));
}

void emxCopyMatrix_real_T5(real_T dst[40], const real_T src[40])
{
  memcpy(&dst[0], &src[0], 40U * sizeof(real_T));
}

void emxCopyStruct_struct_T(i_struct_T *dst, const i_struct_T *src)
{
  emxCopyMatrix_real_T(dst->x, src->x);
  emxCopyMatrix_real_T1(dst->lastMV, src->lastMV);
  emxCopy_real_T(&dst->ref, &src->ref);
  emxCopyMatrix_real_T3(dst->OutputWeights, src->OutputWeights);
  emxCopyMatrix_real_T4(dst->MVWeights, src->MVWeights);
  emxCopyMatrix_real_T4(dst->MVRateWeights, src->MVRateWeights);
  dst->ECRWeight = src->ECRWeight;
  emxCopyMatrix_real_T3(dst->OutputMin, src->OutputMin);
  emxCopyMatrix_real_T3(dst->OutputMax, src->OutputMax);
  emxCopyMatrix_real_T5(dst->StateMin, src->StateMin);
  emxCopyMatrix_real_T5(dst->StateMax, src->StateMax);
  emxCopyMatrix_real_T4(dst->MVMin, src->MVMin);
  emxCopyMatrix_real_T4(dst->MVMax, src->MVMax);
  emxCopyMatrix_real_T4(dst->MVRateMin, src->MVRateMin);
  emxCopyMatrix_real_T4(dst->MVRateMax, src->MVRateMax);
  emxCopy_real_T(&dst->MVScaledTarget, &src->MVScaledTarget);
  dst->Parameters = src->Parameters;
}

void emxCopyStruct_struct_T1(j_struct_T *dst, const j_struct_T *src)
{
  dst->Ts = src->Ts;
  emxCopyMatrix_real_T(dst->CurrentStates, src->CurrentStates);
  emxCopyMatrix_real_T1(dst->LastMV, src->LastMV);
  emxCopy_real_T(&dst->References, &src->References);
  emxCopy_real_T(&dst->MVTarget, &src->MVTarget);
  dst->PredictionHorizon = src->PredictionHorizon;
  dst->NumOfStates = src->NumOfStates;
  dst->NumOfOutputs = src->NumOfOutputs;
  dst->NumOfInputs = src->NumOfInputs;
  emxCopyMatrix_real_T1(dst->MVIndex, src->MVIndex);
  dst->InputPassivityIndex = src->InputPassivityIndex;
  dst->OutputPassivityIndex = src->OutputPassivityIndex;
  dst->PassivityUsePredictedX = src->PassivityUsePredictedX;
}

void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src)
{
  int32_T i;
  int32_T numElDst;
  int32_T numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  emxEnsureCapacity_real_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(int32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(int8_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int8_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (int8_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_ptrdiff_t(emxArray_ptrdiff_t *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(ptrdiff_t));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(ptrdiff_t) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (ptrdiff_t *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxFreeStruct_struct1_T(struct1_T *pStruct)
{
  emxFree_real_T(&pStruct->ref);
  emxFree_real_T(&pStruct->MVTarget);
  emxFree_real_T(&pStruct->X0);
  emxFree_real_T(&pStruct->MV0);
}

void emxFreeStruct_struct_T(i_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->ref);
  emxFree_real_T(&pStruct->MVScaledTarget);
}

void emxFreeStruct_struct_T1(j_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->References);
  emxFree_real_T(&pStruct->MVTarget);
}

void emxFreeStruct_struct_T2(c_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->cIneq);
  emxFree_real_T(&pStruct->cIneq_old);
  emxFree_real_T(&pStruct->grad);
  emxFree_real_T(&pStruct->grad_old);
  emxFree_real_T(&pStruct->lambdasqp);
  emxFree_real_T(&pStruct->lambdaStopTest);
  emxFree_real_T(&pStruct->lambdaStopTestPrev);
  emxFree_real_T(&pStruct->delta_x);
  emxFree_real_T(&pStruct->socDirection);
  emxFree_int32_T(&pStruct->workingset_old);
  emxFree_real_T(&pStruct->JacCineqTrans_old);
  emxFree_real_T(&pStruct->JacCeqTrans_old);
  emxFree_real_T(&pStruct->gradLag);
  emxFree_real_T(&pStruct->delta_gradLag);
  emxFree_real_T(&pStruct->xstar);
  emxFree_real_T(&pStruct->lambda);
  emxFree_real_T(&pStruct->searchDir);
}

void emxFreeStruct_struct_T3(k_struct_T *pStruct)
{
  emxFreeStruct_struct_T(&pStruct->runtimedata);
  emxFreeStruct_struct_T1(&pStruct->userdata);
}

void emxFreeStruct_struct_T4(l_struct_T *pStruct)
{
  c_emxFreeStruct_anonymous_funct(&pStruct->objfun);
  c_emxFreeStruct_anonymous_funct(&pStruct->nonlin);
  emxFree_real_T(&pStruct->cIneq_1);
  emxFree_real_T(&pStruct->cIneq_2);
}

void emxFreeStruct_struct_T5(e_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->QR);
  emxFree_real_T(&pStruct->Q);
  emxFree_int32_T(&pStruct->jpvt);
  emxFree_real_T(&pStruct->tau);
}

void emxFreeStruct_struct_T6(f_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->FMat);
}

void emxFreeStruct_struct_T7(g_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->grad);
  emxFree_real_T(&pStruct->Hx);
}

void emxFreeStruct_struct_T8(h_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->workspace_double);
  emxFree_int32_T(&pStruct->workspace_int);
  emxFree_int32_T(&pStruct->workspace_sort);
}

void emxFreeStruct_struct_T9(d_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->Aineq);
  emxFree_real_T(&pStruct->bineq);
  emxFree_real_T(&pStruct->Aeq);
  emxFree_real_T(&pStruct->lb);
  emxFree_real_T(&pStruct->ub);
  emxFree_int32_T(&pStruct->indexLB);
  emxFree_int32_T(&pStruct->indexUB);
  emxFree_int32_T(&pStruct->indexFixed);
  emxFree_real_T(&pStruct->ATwset);
  emxFree_real_T(&pStruct->bwset);
  emxFree_real_T(&pStruct->maxConstrWorkspace);
  emxFree_boolean_T(&pStruct->isActiveConstr);
  emxFree_int32_T(&pStruct->Wid);
  emxFree_int32_T(&pStruct->Wlocalidx);
}

void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference(emlrtRootTLSGlobal, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference(emlrtRootTLSGlobal, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

void emxFree_int8_T(emxArray_int8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int8_T *)NULL) {
    if (((*pEmxArray)->data != (int8_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference(emlrtRootTLSGlobal, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_int8_T *)NULL;
  }
}

void emxFree_ptrdiff_t(emxArray_ptrdiff_t **pEmxArray)
{
  if (*pEmxArray != (emxArray_ptrdiff_t *)NULL) {
    if (((*pEmxArray)->data != (ptrdiff_t *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference(emlrtRootTLSGlobal, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_ptrdiff_t *)NULL;
  }
}

void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference(emlrtRootTLSGlobal, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

void emxInitStruct_struct1_T(struct1_T *pStruct)
{
  emxInit_real_T(&pStruct->ref, 1);
  emxInit_real_T(&pStruct->MVTarget, 2);
  emxInit_real_T(&pStruct->X0, 2);
  emxInit_real_T(&pStruct->MV0, 2);
}

void emxInitStruct_struct_T(i_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->ref, 2);
  emxInit_real_T(&pStruct->MVScaledTarget, 2);
}

void emxInitStruct_struct_T1(j_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->References, 2);
  emxInit_real_T(&pStruct->MVTarget, 2);
}

void emxInitStruct_struct_T2(c_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->cIneq, 1);
  emxInit_real_T(&pStruct->cIneq_old, 1);
  emxInit_real_T(&pStruct->grad, 1);
  emxInit_real_T(&pStruct->grad_old, 1);
  emxInit_real_T(&pStruct->lambdasqp, 1);
  emxInit_real_T(&pStruct->lambdaStopTest, 1);
  emxInit_real_T(&pStruct->lambdaStopTestPrev, 1);
  emxInit_real_T(&pStruct->delta_x, 1);
  emxInit_real_T(&pStruct->socDirection, 1);
  emxInit_int32_T(&pStruct->workingset_old, 1);
  emxInit_real_T(&pStruct->JacCineqTrans_old, 2);
  emxInit_real_T(&pStruct->JacCeqTrans_old, 2);
  emxInit_real_T(&pStruct->gradLag, 1);
  emxInit_real_T(&pStruct->delta_gradLag, 1);
  emxInit_real_T(&pStruct->xstar, 1);
  emxInit_real_T(&pStruct->lambda, 1);
  emxInit_real_T(&pStruct->searchDir, 1);
}

void emxInitStruct_struct_T3(k_struct_T *pStruct)
{
  emxInitStruct_struct_T(&pStruct->runtimedata);
  emxInitStruct_struct_T1(&pStruct->userdata);
}

void emxInitStruct_struct_T4(l_struct_T *pStruct)
{
  c_emxInitStruct_anonymous_funct(&pStruct->objfun);
  c_emxInitStruct_anonymous_funct(&pStruct->nonlin);
  emxInit_real_T(&pStruct->cIneq_1, 1);
  emxInit_real_T(&pStruct->cIneq_2, 1);
}

void emxInitStruct_struct_T5(e_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->QR, 2);
  emxInit_real_T(&pStruct->Q, 2);
  emxInit_int32_T(&pStruct->jpvt, 1);
  emxInit_real_T(&pStruct->tau, 1);
}

void emxInitStruct_struct_T6(f_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->FMat, 2);
}

void emxInitStruct_struct_T7(g_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->grad, 1);
  emxInit_real_T(&pStruct->Hx, 1);
}

void emxInitStruct_struct_T8(h_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->workspace_double, 2);
  emxInit_int32_T(&pStruct->workspace_int, 1);
  emxInit_int32_T(&pStruct->workspace_sort, 1);
}

void emxInitStruct_struct_T9(d_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->Aineq, 1);
  emxInit_real_T(&pStruct->bineq, 1);
  emxInit_real_T(&pStruct->Aeq, 1);
  emxInit_real_T(&pStruct->lb, 1);
  emxInit_real_T(&pStruct->ub, 1);
  emxInit_int32_T(&pStruct->indexLB, 1);
  emxInit_int32_T(&pStruct->indexUB, 1);
  emxInit_int32_T(&pStruct->indexFixed, 1);
  emxInit_real_T(&pStruct->ATwset, 1);
  emxInit_real_T(&pStruct->bwset, 1);
  emxInit_real_T(&pStruct->maxConstrWorkspace, 1);
  emxInit_boolean_T(&pStruct->isActiveConstr);
  emxInit_int32_T(&pStruct->Wid, 1);
  emxInit_int32_T(&pStruct->Wlocalidx, 1);
}

void emxInit_boolean_T(emxArray_boolean_T **pEmxArray)
{
  emxArray_boolean_T *emxArray;
  *pEmxArray =
      (emxArray_boolean_T *)emlrtMallocEmxArray(sizeof(emxArray_boolean_T));
  emlrtPushHeapReferenceStackEmxArray(
      emlrtRootTLSGlobal, false, (void *)pEmxArray, (void *)&emxFree_boolean_T,
      NULL, NULL, NULL);
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int32_T *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_int32_T *)emlrtMallocEmxArray(sizeof(emxArray_int32_T));
  emlrtPushHeapReferenceStackEmxArray(
      emlrtRootTLSGlobal, false, (void *)pEmxArray, (void *)&emxFree_int32_T,
      NULL, NULL, NULL);
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size =
      (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int8_T(emxArray_int8_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int8_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int8_T *)emlrtMallocEmxArray(sizeof(emxArray_int8_T));
  emlrtPushHeapReferenceStackEmxArray(
      emlrtRootTLSGlobal, false, (void *)pEmxArray, (void *)&emxFree_int8_T,
      NULL, NULL, NULL);
  emxArray = *pEmxArray;
  emxArray->data = (int8_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size =
      (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_ptrdiff_t(emxArray_ptrdiff_t **pEmxArray)
{
  emxArray_ptrdiff_t *emxArray;
  *pEmxArray =
      (emxArray_ptrdiff_t *)emlrtMallocEmxArray(sizeof(emxArray_ptrdiff_t));
  emlrtPushHeapReferenceStackEmxArray(
      emlrtRootTLSGlobal, false, (void *)pEmxArray, (void *)&emxFree_ptrdiff_t,
      NULL, NULL, NULL);
  emxArray = *pEmxArray;
  emxArray->data = (ptrdiff_t *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocEmxArray(sizeof(emxArray_real_T));
  emlrtPushHeapReferenceStackEmxArray(
      emlrtRootTLSGlobal, false, (void *)pEmxArray, (void *)&emxFree_real_T,
      NULL, NULL, NULL);
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size =
      (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void f_emxFreeStruct_coder_internal_(d_coder_internal_stickyStruct *pStruct)
{
  e_emxFreeStruct_coder_internal_(&pStruct->next);
}

void f_emxInitStruct_coder_internal_(f_coder_internal_stickyStruct *pStruct)
{
  g_emxInitStruct_coder_internal_(&pStruct->next);
}

void g_emxFreeStruct_coder_internal_(e_coder_internal_stickyStruct *pStruct)
{
  f_emxFreeStruct_coder_internal_(&pStruct->next);
}

void g_emxInitStruct_coder_internal_(e_coder_internal_stickyStruct *pStruct)
{
  h_emxInitStruct_coder_internal_(&pStruct->next);
}

void h_emxFreeStruct_coder_internal_(f_coder_internal_stickyStruct *pStruct)
{
  g_emxFreeStruct_coder_internal_(&pStruct->next);
}

void h_emxInitStruct_coder_internal_(d_coder_internal_stickyStruct *pStruct)
{
  i_emxInitStruct_coder_internal_(&pStruct->next);
}

void i_emxFreeStruct_coder_internal_(g_coder_internal_stickyStruct *pStruct)
{
  h_emxFreeStruct_coder_internal_(&pStruct->next);
}

void i_emxInitStruct_coder_internal_(c_coder_internal_stickyStruct *pStruct)
{
  j_emxInitStruct_coder_internal_(&pStruct->next);
}

void j_emxFreeStruct_coder_internal_(h_coder_internal_stickyStruct *pStruct)
{
  i_emxFreeStruct_coder_internal_(&pStruct->next);
}

void j_emxInitStruct_coder_internal_(b_coder_internal_stickyStruct *pStruct)
{
  c_emxInitStruct_anonymous_funct(&pStruct->value);
  k_emxInitStruct_coder_internal_(&pStruct->next);
}

void k_emxFreeStruct_coder_internal_(i_coder_internal_stickyStruct *pStruct)
{
  j_emxFreeStruct_coder_internal_(&pStruct->next);
}

void k_emxInitStruct_coder_internal_(coder_internal_stickyStruct *pStruct)
{
  c_emxInitStruct_anonymous_funct(&pStruct->value);
}

/* End of code generation (nlmpcmoveCodeGeneration_emxutil.c) */
