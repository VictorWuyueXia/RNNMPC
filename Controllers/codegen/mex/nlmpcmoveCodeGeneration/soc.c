/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * soc.c
 *
 * Code generation for function 'soc'
 *
 */

/* Include files */
#include "soc.h"
#include "addAeqConstr.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "blas.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
boolean_T soc(const real_T Hessian[2601], const emxArray_real_T *grad,
              c_struct_T *TrialState, h_struct_T *memspace,
              d_struct_T *WorkingSet, e_struct_T *QRManager,
              f_struct_T *CholManager, g_struct_T *QPObjective,
              const m_struct_T *qpoptions)
{
  __m128d r;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  m_struct_T b_qpoptions;
  real_T alpha1;
  real_T oldDirIdx;
  int32_T i;
  int32_T idx;
  int32_T idxIneqOffset;
  int32_T idx_Aineq;
  int32_T idx_Partition;
  int32_T idx_lower;
  int32_T idx_upper;
  int32_T mConstrMax;
  int32_T mIneq;
  int32_T nVar;
  int32_T nWIneq_old;
  int32_T nWLower_old;
  int32_T nWUpper_old;
  char_T TRANSA;
  boolean_T success;
  nWIneq_old = WorkingSet->nWConstr[2];
  nWLower_old = WorkingSet->nWConstr[3];
  nWUpper_old = WorkingSet->nWConstr[4];
  nVar = WorkingSet->nVar;
  mConstrMax = WorkingSet->mConstrMax;
  for (idx_Aineq = 0; idx_Aineq < nVar; idx_Aineq++) {
    TrialState->xstarsqp[idx_Aineq] = TrialState->xstarsqp_old[idx_Aineq];
    TrialState->socDirection->data[idx_Aineq] =
        TrialState->xstar->data[idx_Aineq];
  }
  if (WorkingSet->mConstrMax >= 1) {
    n_t = (ptrdiff_t)WorkingSet->mConstrMax;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &TrialState->lambda->data[0], &incx_t,
          &TrialState->lambdaStopTest->data[0], &incy_t);
  }
  idx_upper = WorkingSet->sizes[1] - 1;
  mIneq = WorkingSet->sizes[2];
  idxIneqOffset = WorkingSet->isActiveIdx[2];
  if (WorkingSet->sizes[1] > 0) {
    idx_Aineq = ((idx_upper + 1) / 2) << 1;
    idx_lower = idx_Aineq - 2;
    for (idx = 0; idx <= idx_lower; idx += 2) {
      r = _mm_loadu_pd(&TrialState->cEq[idx]);
      _mm_storeu_pd(&WorkingSet->beq[idx], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idx = idx_Aineq; idx <= idx_upper; idx++) {
      WorkingSet->beq[idx] = -TrialState->cEq[idx];
    }
    if (WorkingSet->nVar >= 1) {
      alpha1 = 1.0;
      oldDirIdx = 1.0;
      TRANSA = 'T';
      m_t = (ptrdiff_t)WorkingSet->nVar;
      n_t = (ptrdiff_t)WorkingSet->sizes[1];
      lda_t = (ptrdiff_t)WorkingSet->ldA;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dgemv(&TRANSA, &m_t, &n_t, &alpha1, &WorkingSet->Aeq->data[0], &lda_t,
            &TrialState->searchDir->data[0], &incx_t, &oldDirIdx,
            &WorkingSet->beq[0], &incy_t);
    }
    for (idx_Aineq = 0; idx_Aineq <= idx_upper; idx_Aineq++) {
      WorkingSet->bwset->data[WorkingSet->sizes[0] + idx_Aineq] =
          WorkingSet->beq[idx_Aineq];
    }
  }
  if (WorkingSet->sizes[2] > 0) {
    idx_Aineq = (mIneq / 2) << 1;
    idx_lower = idx_Aineq - 2;
    for (idx = 0; idx <= idx_lower; idx += 2) {
      r = _mm_loadu_pd(&TrialState->cIneq->data[idx]);
      _mm_storeu_pd(&WorkingSet->bineq->data[idx],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idx = idx_Aineq; idx < mIneq; idx++) {
      WorkingSet->bineq->data[idx] = -TrialState->cIneq->data[idx];
    }
    if (WorkingSet->nVar >= 1) {
      alpha1 = 1.0;
      oldDirIdx = 1.0;
      TRANSA = 'T';
      m_t = (ptrdiff_t)WorkingSet->nVar;
      n_t = (ptrdiff_t)WorkingSet->sizes[2];
      lda_t = (ptrdiff_t)WorkingSet->ldA;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dgemv(&TRANSA, &m_t, &n_t, &alpha1, &WorkingSet->Aineq->data[0], &lda_t,
            &TrialState->searchDir->data[0], &incx_t, &oldDirIdx,
            &WorkingSet->bineq->data[0], &incy_t);
    }
    idx_Aineq = 1;
    idx_lower = WorkingSet->sizes[2] + 1;
    idx_upper = (WorkingSet->sizes[2] + WorkingSet->sizes[3]) + 1;
    i = WorkingSet->nActiveConstr;
    for (idx = idxIneqOffset; idx <= i; idx++) {
      switch (WorkingSet->Wid->data[idx - 1]) {
      case 3:
        idx_Partition = idx_Aineq;
        idx_Aineq++;
        WorkingSet->bwset->data[idx - 1] =
            WorkingSet->bineq->data[WorkingSet->Wlocalidx->data[idx - 1] - 1];
        break;
      case 4:
        idx_Partition = idx_lower;
        idx_lower++;
        break;
      default:
        idx_Partition = idx_upper;
        idx_upper++;
        break;
      }
      TrialState->workingset_old->data[idx_Partition - 1] =
          WorkingSet->Wlocalidx->data[idx - 1];
    }
  }
  for (idx_Aineq = 0; idx_Aineq < nVar; idx_Aineq++) {
    TrialState->xstar->data[idx_Aineq] = TrialState->xstarsqp[idx_Aineq];
  }
  b_qpoptions = *qpoptions;
  driver(Hessian, grad, TrialState, memspace, WorkingSet, QRManager,
         CholManager, QPObjective, qpoptions, &b_qpoptions);
  while ((WorkingSet->mEqRemoved > 0) &&
         (WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1] >=
          TrialState->iNonEq0)) {
    addAeqConstr(WorkingSet,
                 WorkingSet->indexEqRemoved[WorkingSet->mEqRemoved - 1]);
    WorkingSet->mEqRemoved--;
  }
  idx_Aineq = (nVar / 2) << 1;
  idx_lower = idx_Aineq - 2;
  for (idx = 0; idx <= idx_lower; idx += 2) {
    __m128d r1;
    r = _mm_loadu_pd(&TrialState->socDirection->data[idx]);
    r1 = _mm_loadu_pd(&TrialState->xstar->data[idx]);
    _mm_storeu_pd(&TrialState->socDirection->data[idx], _mm_sub_pd(r1, r));
    _mm_storeu_pd(&TrialState->xstar->data[idx], r);
  }
  for (idx = idx_Aineq; idx < nVar; idx++) {
    alpha1 = TrialState->socDirection->data[idx];
    oldDirIdx = alpha1;
    alpha1 = TrialState->xstar->data[idx] - alpha1;
    TrialState->socDirection->data[idx] = alpha1;
    TrialState->xstar->data[idx] = oldDirIdx;
  }
  if (nVar < 1) {
    alpha1 = 0.0;
    oldDirIdx = 0.0;
  } else {
    n_t = (ptrdiff_t)nVar;
    incx_t = (ptrdiff_t)1;
    alpha1 = dnrm2(&n_t, &TrialState->socDirection->data[0], &incx_t);
    n_t = (ptrdiff_t)nVar;
    incx_t = (ptrdiff_t)1;
    oldDirIdx = dnrm2(&n_t, &TrialState->xstar->data[0], &incx_t);
  }
  success = (alpha1 <= 2.0 * oldDirIdx);
  i = WorkingSet->sizes[1] - 1;
  mIneq = WorkingSet->sizes[2];
  nVar = WorkingSet->sizes[3];
  if (WorkingSet->sizes[1] > 0) {
    idx_Aineq = ((i + 1) / 2) << 1;
    idx_lower = idx_Aineq - 2;
    for (idx = 0; idx <= idx_lower; idx += 2) {
      r = _mm_loadu_pd(&TrialState->cEq[idx]);
      _mm_storeu_pd(&WorkingSet->beq[idx], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idx = idx_Aineq; idx <= i; idx++) {
      WorkingSet->beq[idx] = -TrialState->cEq[idx];
    }
    for (idx_Aineq = 0; idx_Aineq <= i; idx_Aineq++) {
      WorkingSet->bwset->data[WorkingSet->sizes[0] + idx_Aineq] =
          WorkingSet->beq[idx_Aineq];
    }
  }
  if (WorkingSet->sizes[2] > 0) {
    idx_Aineq = (mIneq / 2) << 1;
    idx_lower = idx_Aineq - 2;
    for (idx = 0; idx <= idx_lower; idx += 2) {
      r = _mm_loadu_pd(&TrialState->cIneq->data[idx]);
      _mm_storeu_pd(&WorkingSet->bineq->data[idx],
                    _mm_mul_pd(r, _mm_set1_pd(-1.0)));
    }
    for (idx = idx_Aineq; idx < mIneq; idx++) {
      WorkingSet->bineq->data[idx] = -TrialState->cIneq->data[idx];
    }
    if (!success) {
      idx_upper = WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1];
      idx_Aineq = idx_upper + 1;
      idx_lower = WorkingSet->nActiveConstr;
      for (idx_Partition = idx_Aineq; idx_Partition <= idx_lower;
           idx_Partition++) {
        WorkingSet->isActiveConstr
            ->data[(WorkingSet->isActiveIdx
                        [WorkingSet->Wid->data[idx_Partition - 1] - 1] +
                    WorkingSet->Wlocalidx->data[idx_Partition - 1]) -
                   2] = false;
      }
      WorkingSet->nWConstr[2] = 0;
      WorkingSet->nWConstr[3] = 0;
      WorkingSet->nWConstr[4] = 0;
      WorkingSet->nActiveConstr = idx_upper;
      for (idx = 0; idx < nWIneq_old; idx++) {
        idx_Aineq = TrialState->workingset_old->data[idx];
        WorkingSet->nWConstr[2]++;
        WorkingSet->isActiveConstr
            ->data[(WorkingSet->isActiveIdx[2] + idx_Aineq) - 2] = true;
        WorkingSet->nActiveConstr++;
        i = WorkingSet->nActiveConstr - 1;
        WorkingSet->Wid->data[i] = 3;
        WorkingSet->Wlocalidx->data[i] = idx_Aineq;
        idx_lower = WorkingSet->ldA * (idx_Aineq - 1);
        idx_upper = WorkingSet->ldA * i;
        idx_Partition = WorkingSet->nVar - 1;
        for (idxIneqOffset = 0; idxIneqOffset <= idx_Partition;
             idxIneqOffset++) {
          WorkingSet->ATwset->data[idx_upper + idxIneqOffset] =
              WorkingSet->Aineq->data[idx_lower + idxIneqOffset];
        }
        WorkingSet->bwset->data[i] = WorkingSet->bineq->data[idx_Aineq - 1];
      }
      for (idx = 0; idx < nWLower_old; idx++) {
        addBoundToActiveSetMatrix_(
            WorkingSet, 4, TrialState->workingset_old->data[idx + mIneq]);
      }
      for (idx = 0; idx < nWUpper_old; idx++) {
        addBoundToActiveSetMatrix_(
            WorkingSet, 5,
            TrialState->workingset_old->data[(idx + mIneq) + nVar]);
      }
    }
  }
  if (!success) {
    if (mConstrMax >= 1) {
      n_t = (ptrdiff_t)mConstrMax;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &TrialState->lambdaStopTest->data[0], &incx_t,
            &TrialState->lambda->data[0], &incy_t);
    }
  } else {
    sortLambdaQP(TrialState->lambda, WorkingSet->nActiveConstr,
                 WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
                 WorkingSet->Wlocalidx, memspace->workspace_double);
  }
  return success;
}

/* End of code generation (soc.c) */
