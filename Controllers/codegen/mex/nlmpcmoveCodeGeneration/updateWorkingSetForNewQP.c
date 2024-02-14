/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updateWorkingSetForNewQP.c
 *
 * Code generation for function 'updateWorkingSetForNewQP'
 *
 */

/* Include files */
#include "updateWorkingSetForNewQP.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void b_updateWorkingSetForNewQP(const real_T xk[51], d_struct_T *WorkingSet,
                                int32_T mIneq, int32_T mNonlinIneq,
                                const emxArray_real_T *cIneq, int32_T mEq,
                                int32_T mNonlinEq, const real_T cEq[40],
                                int32_T mLB, const real_T lb[51], int32_T mUB,
                                const real_T ub[51], int32_T mFixed)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  const real_T *cIneq_data;
  real_T d;
  int32_T b_i;
  int32_T i;
  int32_T idx;
  int32_T iw0;
  int32_T mLinEq;
  int32_T nVar;
  cIneq_data = cIneq->data;
  nVar = WorkingSet->nVar;
  for (idx = 0; idx < mEq; idx++) {
    d = -cEq[idx];
    WorkingSet->beq[idx] = d;
    WorkingSet->bwset->data[mFixed + idx] = d;
  }
  mLinEq = mEq - mNonlinEq;
  iw0 = WorkingSet->ldA * (mFixed + mLinEq);
  mLinEq *= WorkingSet->ldA;
  for (idx = 0; idx < mNonlinEq; idx++) {
    i = nVar - 1;
    for (b_i = 0; b_i <= i; b_i++) {
      WorkingSet->ATwset->data[iw0 + b_i] = WorkingSet->Aeq->data[mLinEq + b_i];
    }
    iw0 += WorkingSet->ldA;
    mLinEq += WorkingSet->ldA;
  }
  mLinEq = (mIneq / 2) << 1;
  iw0 = mLinEq - 2;
  for (idx = 0; idx <= iw0; idx += 2) {
    __m128d r;
    r = _mm_loadu_pd(&cIneq_data[idx]);
    _mm_storeu_pd(&WorkingSet->bineq->data[idx],
                  _mm_mul_pd(r, _mm_set1_pd(-1.0)));
  }
  for (idx = mLinEq; idx < mIneq; idx++) {
    WorkingSet->bineq->data[idx] = -cIneq_data[idx];
  }
  for (idx = 0; idx < mLB; idx++) {
    WorkingSet->lb->data[WorkingSet->indexLB->data[idx] - 1] =
        -lb[WorkingSet->indexLB->data[idx] - 1] +
        xk[WorkingSet->indexLB->data[idx] - 1];
  }
  for (idx = 0; idx < mUB; idx++) {
    WorkingSet->ub->data[WorkingSet->indexUB->data[idx] - 1] =
        ub[WorkingSet->indexUB->data[idx] - 1] -
        xk[WorkingSet->indexUB->data[idx] - 1];
  }
  for (idx = 0; idx < mFixed; idx++) {
    d = ub[WorkingSet->indexFixed->data[idx] - 1] -
        xk[WorkingSet->indexFixed->data[idx] - 1];
    WorkingSet->ub->data[WorkingSet->indexFixed->data[idx] - 1] = d;
    WorkingSet->bwset->data[idx] = d;
  }
  i = mFixed + mEq;
  if (WorkingSet->nActiveConstr > i) {
    mLinEq = i + 1;
    mLinEq = muIntScalarMax_sint32(mLinEq, 1);
    i = WorkingSet->nActiveConstr;
    for (idx = mLinEq; idx <= i; idx++) {
      switch (WorkingSet->Wid->data[idx - 1]) {
      case 4:
        WorkingSet->bwset->data[idx - 1] =
            WorkingSet->lb
                ->data[WorkingSet->indexLB
                           ->data[WorkingSet->Wlocalidx->data[idx - 1] - 1] -
                       1];
        break;
      case 5:
        WorkingSet->bwset->data[idx - 1] =
            WorkingSet->ub
                ->data[WorkingSet->indexUB
                           ->data[WorkingSet->Wlocalidx->data[idx - 1] - 1] -
                       1];
        break;
      default:
        iw0 = WorkingSet->Wlocalidx->data[idx - 1];
        WorkingSet->bwset->data[idx - 1] = WorkingSet->bineq->data[iw0 - 1];
        if ((mNonlinIneq > 0) && (iw0 >= mNonlinIneq) && (nVar >= 1)) {
          n_t = (ptrdiff_t)nVar;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t,
                &WorkingSet->Aineq
                     ->data[WorkingSet->ldA *
                            (WorkingSet->Wlocalidx->data[idx - 1] - 1)],
                &incx_t, &WorkingSet->ATwset->data[WorkingSet->ldA * (idx - 1)],
                &incy_t);
        }
        break;
      }
    }
  }
}

void updateWorkingSetForNewQP(const real_T xk[51], d_struct_T *WorkingSet,
                              int32_T mIneq, int32_T mNonlinIneq,
                              const emxArray_real_T *cIneq, int32_T mNonlinEq,
                              const real_T cEq[40], int32_T mLB,
                              const real_T lb[51], int32_T mUB,
                              const real_T ub[51], int32_T mFixed)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  const real_T *cIneq_data;
  real_T d;
  int32_T b_i;
  int32_T i;
  int32_T iEq0;
  int32_T idx;
  int32_T iw0;
  int32_T nVar;
  cIneq_data = cIneq->data;
  nVar = WorkingSet->nVar;
  for (idx = 0; idx < 40; idx++) {
    d = -cEq[idx];
    WorkingSet->beq[idx] = d;
    WorkingSet->bwset->data[mFixed + idx] = d;
  }
  iw0 = WorkingSet->ldA * ((mFixed - mNonlinEq) + 40);
  iEq0 = WorkingSet->ldA * (40 - mNonlinEq);
  for (idx = 0; idx < mNonlinEq; idx++) {
    i = nVar - 1;
    for (b_i = 0; b_i <= i; b_i++) {
      WorkingSet->ATwset->data[iw0 + b_i] = WorkingSet->Aeq->data[iEq0 + b_i];
    }
    iw0 += WorkingSet->ldA;
    iEq0 += WorkingSet->ldA;
  }
  iEq0 = (mIneq / 2) << 1;
  iw0 = iEq0 - 2;
  for (idx = 0; idx <= iw0; idx += 2) {
    __m128d r;
    r = _mm_loadu_pd(&cIneq_data[idx]);
    _mm_storeu_pd(&WorkingSet->bineq->data[idx],
                  _mm_mul_pd(r, _mm_set1_pd(-1.0)));
  }
  for (idx = iEq0; idx < mIneq; idx++) {
    WorkingSet->bineq->data[idx] = -cIneq_data[idx];
  }
  for (idx = 0; idx < mLB; idx++) {
    WorkingSet->lb->data[WorkingSet->indexLB->data[idx] - 1] =
        -lb[WorkingSet->indexLB->data[idx] - 1] +
        xk[WorkingSet->indexLB->data[idx] - 1];
  }
  for (idx = 0; idx < mUB; idx++) {
    WorkingSet->ub->data[WorkingSet->indexUB->data[idx] - 1] =
        ub[WorkingSet->indexUB->data[idx] - 1] -
        xk[WorkingSet->indexUB->data[idx] - 1];
  }
  for (idx = 0; idx < mFixed; idx++) {
    d = ub[WorkingSet->indexFixed->data[idx] - 1] -
        xk[WorkingSet->indexFixed->data[idx] - 1];
    WorkingSet->ub->data[WorkingSet->indexFixed->data[idx] - 1] = d;
    WorkingSet->bwset->data[idx] = d;
  }
  if (WorkingSet->nActiveConstr > mFixed + 40) {
    i = mFixed + 41;
    iEq0 = muIntScalarMax_sint32(i, 1);
    i = WorkingSet->nActiveConstr;
    for (idx = iEq0; idx <= i; idx++) {
      switch (WorkingSet->Wid->data[idx - 1]) {
      case 4:
        WorkingSet->bwset->data[idx - 1] =
            WorkingSet->lb
                ->data[WorkingSet->indexLB
                           ->data[WorkingSet->Wlocalidx->data[idx - 1] - 1] -
                       1];
        break;
      case 5:
        WorkingSet->bwset->data[idx - 1] =
            WorkingSet->ub
                ->data[WorkingSet->indexUB
                           ->data[WorkingSet->Wlocalidx->data[idx - 1] - 1] -
                       1];
        break;
      default:
        iw0 = WorkingSet->Wlocalidx->data[idx - 1];
        WorkingSet->bwset->data[idx - 1] = WorkingSet->bineq->data[iw0 - 1];
        if ((mNonlinIneq > 0) && (iw0 >= mNonlinIneq) && (nVar >= 1)) {
          n_t = (ptrdiff_t)nVar;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t,
                &WorkingSet->Aineq
                     ->data[WorkingSet->ldA *
                            (WorkingSet->Wlocalidx->data[idx - 1] - 1)],
                &incx_t, &WorkingSet->ATwset->data[WorkingSet->ldA * (idx - 1)],
                &incy_t);
        }
        break;
      }
    }
  }
}

/* End of code generation (updateWorkingSetForNewQP.c) */
