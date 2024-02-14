/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * PresolveWorkingSet.c
 *
 * Code generation for function 'PresolveWorkingSet'
 *
 */

/* Include files */
#include "PresolveWorkingSet.h"
#include "computeQ_.h"
#include "countsort.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void PresolveWorkingSet(c_struct_T *solution, h_struct_T *memspace,
                        d_struct_T *workingset, e_struct_T *qrmanager,
                        const m_struct_T *options)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T tol;
  int32_T TYPE;
  int32_T i;
  int32_T idxDiag;
  int32_T idx_col;
  int32_T mTotalWorkingEq_tmp_tmp;
  int32_T mWorkingFixed;
  int32_T nDepInd;
  int32_T nVar_tmp;
  solution->state = 82;
  nVar_tmp = workingset->nVar;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq_tmp_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp_tmp > 0) {
    for (TYPE = 0; TYPE < mTotalWorkingEq_tmp_tmp; TYPE++) {
      for (idx_col = 0; idx_col < nVar_tmp; idx_col++) {
        qrmanager->QR->data[TYPE + qrmanager->ldq * idx_col] =
            workingset->ATwset->data[idx_col + workingset->ldA * TYPE];
      }
    }
    TYPE = mTotalWorkingEq_tmp_tmp - workingset->nVar;
    nDepInd = muIntScalarMax_sint32(0, TYPE);
    for (idx_col = 0; idx_col < nVar_tmp; idx_col++) {
      qrmanager->jpvt->data[idx_col] = 0;
    }
    i = mTotalWorkingEq_tmp_tmp * workingset->nVar;
    if (i == 0) {
      qrmanager->mrows = mTotalWorkingEq_tmp_tmp;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = mTotalWorkingEq_tmp_tmp;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol =
          muIntScalarMin_sint32(mTotalWorkingEq_tmp_tmp, workingset->nVar);
      xgeqp3(qrmanager->QR, mTotalWorkingEq_tmp_tmp, workingset->nVar,
             qrmanager->jpvt, qrmanager->tau);
    }
    tol = 100.0 * (real_T)workingset->nVar * 2.2204460492503131E-16;
    TYPE = muIntScalarMin_sint32(workingset->nVar, mTotalWorkingEq_tmp_tmp);
    idxDiag = TYPE + qrmanager->ldq * (TYPE - 1);
    while ((idxDiag > 0) &&
           (muDoubleScalarAbs(qrmanager->QR->data[idxDiag - 1]) < tol)) {
      idxDiag = (idxDiag - qrmanager->ldq) - 1;
      nDepInd++;
    }
    if (nDepInd > 0) {
      boolean_T exitg1;
      computeQ_(qrmanager, qrmanager->mrows);
      idx_col = 0;
      exitg1 = false;
      while ((!exitg1) && (idx_col <= nDepInd - 1)) {
        real_T x;
        n_t = (ptrdiff_t)mTotalWorkingEq_tmp_tmp;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        x = ddot(&n_t,
                 &qrmanager->Q->data[qrmanager->ldq *
                                     ((mTotalWorkingEq_tmp_tmp - idx_col) - 1)],
                 &incx_t, &workingset->bwset->data[0], &incy_t);
        if (muDoubleScalarAbs(x) >= tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          idx_col++;
        }
      }
    }
    if (nDepInd > 0) {
      for (idx_col = 0; idx_col < mTotalWorkingEq_tmp_tmp; idx_col++) {
        if (nVar_tmp >= 1) {
          n_t = (ptrdiff_t)nVar_tmp;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &workingset->ATwset->data[workingset->ldA * idx_col],
                &incx_t, &qrmanager->QR->data[qrmanager->ldq * idx_col],
                &incy_t);
        }
      }
      for (idx_col = 0; idx_col < mWorkingFixed; idx_col++) {
        qrmanager->jpvt->data[idx_col] = 1;
      }
      idxDiag = workingset->nWConstr[0] + 1;
      for (idx_col = idxDiag; idx_col <= mTotalWorkingEq_tmp_tmp; idx_col++) {
        qrmanager->jpvt->data[idx_col - 1] = 0;
      }
      if (i == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp_tmp;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp_tmp;
        qrmanager->minRowCol = TYPE;
        xgeqp3(qrmanager->QR, workingset->nVar, mTotalWorkingEq_tmp_tmp,
               qrmanager->jpvt, qrmanager->tau);
      }
      for (idx_col = 0; idx_col < nDepInd; idx_col++) {
        memspace->workspace_int->data[idx_col] =
            qrmanager->jpvt
                ->data[(mTotalWorkingEq_tmp_tmp - nDepInd) + idx_col];
      }
      countsort(memspace->workspace_int, nDepInd, memspace->workspace_sort, 1,
                mTotalWorkingEq_tmp_tmp);
      for (idx_col = nDepInd; idx_col >= 1; idx_col--) {
        i = workingset->nWConstr[0] + workingset->nWConstr[1];
        if (i != 0) {
          idxDiag = memspace->workspace_int->data[idx_col - 1];
          if (idxDiag <= i) {
            if ((workingset->nActiveConstr == i) || (idxDiag == i)) {
              workingset->mEqRemoved++;
              workingset->indexEqRemoved[workingset->mEqRemoved - 1] =
                  workingset->Wlocalidx->data[idxDiag - 1];
              removeConstr(workingset, idxDiag);
            } else {
              workingset->mEqRemoved++;
              TYPE = workingset->Wid->data[idxDiag - 1] - 1;
              workingset->indexEqRemoved[workingset->mEqRemoved - 1] =
                  workingset->Wlocalidx->data[idxDiag - 1];
              workingset->isActiveConstr
                  ->data[(workingset->isActiveIdx
                              [workingset->Wid->data[idxDiag - 1] - 1] +
                          workingset->Wlocalidx->data[idxDiag - 1]) -
                         2] = false;
              workingset->Wid->data[idxDiag - 1] = workingset->Wid->data[i - 1];
              workingset->Wlocalidx->data[idxDiag - 1] =
                  workingset->Wlocalidx->data[i - 1];
              for (mWorkingFixed = 0; mWorkingFixed < nVar_tmp;
                   mWorkingFixed++) {
                workingset->ATwset
                    ->data[mWorkingFixed + workingset->ldA * (idxDiag - 1)] =
                    workingset->ATwset
                        ->data[mWorkingFixed + workingset->ldA * (i - 1)];
              }
              workingset->bwset->data[idxDiag - 1] =
                  workingset->bwset->data[i - 1];
              workingset->Wid->data[i - 1] =
                  workingset->Wid->data[workingset->nActiveConstr - 1];
              workingset->Wlocalidx->data[i - 1] =
                  workingset->Wlocalidx->data[workingset->nActiveConstr - 1];
              for (mWorkingFixed = 0; mWorkingFixed < nVar_tmp;
                   mWorkingFixed++) {
                workingset->ATwset
                    ->data[mWorkingFixed + workingset->ldA * (i - 1)] =
                    workingset->ATwset
                        ->data[mWorkingFixed +
                               workingset->ldA *
                                   (workingset->nActiveConstr - 1)];
              }
              workingset->bwset->data[i - 1] =
                  workingset->bwset->data[workingset->nActiveConstr - 1];
              workingset->nActiveConstr--;
              workingset->nWConstr[TYPE]--;
            }
          }
        }
      }
    }
  }
  if ((nDepInd != -1) && (workingset->nActiveConstr <= qrmanager->ldq)) {
    boolean_T guard1;
    boolean_T okWorkingSet;
    TYPE = workingset->nActiveConstr;
    i = workingset->nWConstr[0] + workingset->nWConstr[1];
    if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
            workingset->nWConstr[4] >
        0) {
      tol = 100.0 * (real_T)workingset->nVar * 2.2204460492503131E-16;
      for (idx_col = 0; idx_col < i; idx_col++) {
        qrmanager->jpvt->data[idx_col] = 1;
      }
      idxDiag = i + 1;
      for (idx_col = idxDiag; idx_col <= TYPE; idx_col++) {
        qrmanager->jpvt->data[idx_col - 1] = 0;
      }
      idxDiag = workingset->nActiveConstr;
      for (idx_col = 0; idx_col < idxDiag; idx_col++) {
        if (nVar_tmp >= 1) {
          n_t = (ptrdiff_t)nVar_tmp;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &workingset->ATwset->data[workingset->ldA * idx_col],
                &incx_t, &qrmanager->QR->data[qrmanager->ldq * idx_col],
                &incy_t);
        }
      }
      if (workingset->nVar * workingset->nActiveConstr == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = workingset->nActiveConstr;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = workingset->nActiveConstr;
        qrmanager->minRowCol =
            muIntScalarMin_sint32(workingset->nVar, workingset->nActiveConstr);
        xgeqp3(qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
               qrmanager->jpvt, qrmanager->tau);
      }
      TYPE = 0;
      for (idx_col = workingset->nActiveConstr - 1; idx_col + 1 > nVar_tmp;
           idx_col--) {
        TYPE++;
        memspace->workspace_int->data[TYPE - 1] =
            qrmanager->jpvt->data[idx_col];
      }
      if (idx_col + 1 <= workingset->nVar) {
        idxDiag = idx_col + qrmanager->ldq * idx_col;
        while ((idx_col + 1 > i) &&
               (muDoubleScalarAbs(qrmanager->QR->data[idxDiag]) < tol)) {
          TYPE++;
          memspace->workspace_int->data[TYPE - 1] =
              qrmanager->jpvt->data[idx_col];
          idx_col--;
          idxDiag = (idxDiag - qrmanager->ldq) - 1;
        }
      }
      countsort(memspace->workspace_int, TYPE, memspace->workspace_sort, i + 1,
                workingset->nActiveConstr);
      for (idx_col = TYPE; idx_col >= 1; idx_col--) {
        removeConstr(workingset, memspace->workspace_int->data[idx_col - 1]);
      }
    }
    okWorkingSet = feasibleX0ForWorkingSet(
        memspace->workspace_double, solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      TYPE = workingset->nActiveConstr;
      i = workingset->nWConstr[0] + workingset->nWConstr[1];
      if ((workingset->nWConstr[2] + workingset->nWConstr[3]) +
              workingset->nWConstr[4] >
          0) {
        tol = 1000.0 * (real_T)workingset->nVar * 2.2204460492503131E-16;
        for (idx_col = 0; idx_col < i; idx_col++) {
          qrmanager->jpvt->data[idx_col] = 1;
        }
        idxDiag = i + 1;
        for (idx_col = idxDiag; idx_col <= TYPE; idx_col++) {
          qrmanager->jpvt->data[idx_col - 1] = 0;
        }
        idxDiag = workingset->nActiveConstr;
        for (idx_col = 0; idx_col < idxDiag; idx_col++) {
          if (nVar_tmp >= 1) {
            n_t = (ptrdiff_t)nVar_tmp;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dcopy(&n_t, &workingset->ATwset->data[workingset->ldA * idx_col],
                  &incx_t, &qrmanager->QR->data[qrmanager->ldq * idx_col],
                  &incy_t);
          }
        }
        if (workingset->nVar * workingset->nActiveConstr == 0) {
          qrmanager->mrows = workingset->nVar;
          qrmanager->ncols = workingset->nActiveConstr;
          qrmanager->minRowCol = 0;
        } else {
          qrmanager->usedPivoting = true;
          qrmanager->mrows = workingset->nVar;
          qrmanager->ncols = workingset->nActiveConstr;
          qrmanager->minRowCol = muIntScalarMin_sint32(
              workingset->nVar, workingset->nActiveConstr);
          xgeqp3(qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
                 qrmanager->jpvt, qrmanager->tau);
        }
        TYPE = 0;
        for (idx_col = workingset->nActiveConstr - 1; idx_col + 1 > nVar_tmp;
             idx_col--) {
          TYPE++;
          memspace->workspace_int->data[TYPE - 1] =
              qrmanager->jpvt->data[idx_col];
        }
        if (idx_col + 1 <= workingset->nVar) {
          idxDiag = idx_col + qrmanager->ldq * idx_col;
          while ((idx_col + 1 > i) &&
                 (muDoubleScalarAbs(qrmanager->QR->data[idxDiag]) < tol)) {
            TYPE++;
            memspace->workspace_int->data[TYPE - 1] =
                qrmanager->jpvt->data[idx_col];
            idx_col--;
            idxDiag = (idxDiag - qrmanager->ldq) - 1;
          }
        }
        countsort(memspace->workspace_int, TYPE, memspace->workspace_sort,
                  i + 1, workingset->nActiveConstr);
        for (idx_col = TYPE; idx_col >= 1; idx_col--) {
          removeConstr(workingset, memspace->workspace_int->data[idx_col - 1]);
        }
      }
      okWorkingSet = feasibleX0ForWorkingSet(
          memspace->workspace_double, solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 && (workingset->nWConstr[0] + workingset->nWConstr[1] ==
                   workingset->nVar)) {
      tol = maxConstraintViolation(workingset, solution->xstar);
      if (tol > options->ConstraintTolerance) {
        solution->state = -2;
      }
    }
  } else {
    solution->state = -3;
    TYPE = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
    idxDiag = workingset->nActiveConstr;
    for (mWorkingFixed = TYPE; mWorkingFixed <= idxDiag; mWorkingFixed++) {
      workingset->isActiveConstr
          ->data[(workingset->isActiveIdx
                      [workingset->Wid->data[mWorkingFixed - 1] - 1] +
                  workingset->Wlocalidx->data[mWorkingFixed - 1]) -
                 2] = false;
    }
    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr =
        workingset->nWConstr[0] + workingset->nWConstr[1];
  }
}

/* End of code generation (PresolveWorkingSet.c) */
