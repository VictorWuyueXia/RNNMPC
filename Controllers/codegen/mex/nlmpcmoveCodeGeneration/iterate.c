/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * iterate.c
 *
 * Code generation for function 'iterate'
 *
 */

/* Include files */
#include "iterate.h"
#include "addBoundToActiveSetMatrix_.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "deleteColMoveEnd.h"
#include "factorQR.h"
#include "feasibleX0ForWorkingSet.h"
#include "feasibleratiotest.h"
#include "maxConstraintViolation.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "ratiotest.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xgemv.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void iterate(const real_T H[2601], const emxArray_real_T *f,
             c_struct_T *solution, h_struct_T *memspace, d_struct_T *workingset,
             e_struct_T *qrmanager, f_struct_T *cholmanager,
             g_struct_T *objective, const char_T options_SolverName[7],
             real_T options_StepTolerance, real_T options_ConstraintTolerance,
             real_T options_ObjectiveLimit, real_T options_PricingTolerance,
             const m_struct_T *runTimeOptions)
{
  static const char_T b[7] = {'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T normDelta;
  real_T tolDelta;
  int32_T TYPE;
  int32_T activeConstrChangedType;
  int32_T activeSetChangeID;
  int32_T globalActiveConstrIdx;
  int32_T iAw0;
  int32_T idx;
  int32_T localActiveConstrIdx;
  int32_T nVar;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  boolean_T newBlocking;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective->objtype;
  tolDelta = 6.7434957617430445E-7;
  nVar = workingset->nVar;
  globalActiveConstrIdx = 0;
  computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = computeFval_ReuseHx(objective, memspace->workspace_double,
                                        f, solution->xstar);
  if (solution->iterations < runTimeOptions->MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }
  activeConstrChangedType = workingset->mConstrMax;
  for (iAw0 = 0; iAw0 < activeConstrChangedType; iAw0++) {
    solution->lambda->data[iAw0] = 0.0;
  }
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      real_T y;
      int32_T i;
      int32_T i1;
      boolean_T guard1;
      boolean_T guard2;
      guard1 = false;
      guard2 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          squareQ_appendCol(qrmanager, workingset->ATwset,
                            workingset->ldA * (workingset->nActiveConstr - 1) +
                                1);
          break;
        case -1:
          deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;
        default:
          factorQR(qrmanager, workingset->ATwset, nVar,
                   workingset->nActiveConstr, workingset->ldA);
          computeQ_(qrmanager, qrmanager->mrows);
          break;
        }
        compute_deltax(
            H, solution, memspace, qrmanager, cholmanager, objective,
            memcmp((char_T *)&options_SolverName[0], (char_T *)&b[0], 7) == 0);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          if (nVar < 1) {
            normDelta = 0.0;
          } else {
            n_t = (ptrdiff_t)nVar;
            incx_t = (ptrdiff_t)1;
            normDelta = dnrm2(&n_t, &solution->searchDir->data[0], &incx_t);
          }
          if ((normDelta < options_StepTolerance) ||
              (workingset->nActiveConstr >= nVar)) {
            guard2 = true;
          } else {
            updateFval = (TYPE == 5);
            if (updateFval || runTimeOptions->RemainFeasible) {
              normDelta = feasibleratiotest(
                  solution->xstar, solution->searchDir,
                  memspace->workspace_double, workingset->nVar, workingset->ldA,
                  workingset->Aineq, workingset->bineq, workingset->lb,
                  workingset->ub, workingset->indexLB, workingset->indexUB,
                  workingset->sizes, workingset->isActiveIdx,
                  workingset->isActiveConstr, workingset->nWConstr, updateFval,
                  options_ConstraintTolerance, &newBlocking,
                  &activeConstrChangedType, &localActiveConstrIdx);
            } else {
              normDelta = ratiotest(
                  solution->xstar, solution->searchDir,
                  memspace->workspace_double, workingset->nVar, workingset->ldA,
                  workingset->Aineq, workingset->bineq, workingset->lb,
                  workingset->ub, workingset->indexLB, workingset->indexUB,
                  workingset->sizes, workingset->isActiveIdx,
                  workingset->isActiveConstr, workingset->nWConstr,
                  options_ConstraintTolerance, &tolDelta, &newBlocking,
                  &activeConstrChangedType, &localActiveConstrIdx);
            }
            if (newBlocking) {
              switch (activeConstrChangedType) {
              case 3:
                workingset->nWConstr[2]++;
                workingset->isActiveConstr
                    ->data[(workingset->isActiveIdx[2] + localActiveConstrIdx) -
                           2] = true;
                workingset->nActiveConstr++;
                i = workingset->nActiveConstr - 1;
                workingset->Wid->data[i] = 3;
                workingset->Wlocalidx->data[i] = localActiveConstrIdx;
                activeConstrChangedType =
                    workingset->ldA * (localActiveConstrIdx - 1);
                iAw0 = workingset->ldA * i;
                i1 = workingset->nVar - 1;
                for (idx = 0; idx <= i1; idx++) {
                  workingset->ATwset->data[iAw0 + idx] =
                      workingset->Aineq->data[activeConstrChangedType + idx];
                }
                workingset->bwset->data[i] =
                    workingset->bineq->data[localActiveConstrIdx - 1];
                break;
              case 4:
                addBoundToActiveSetMatrix_(workingset, 4, localActiveConstrIdx);
                break;
              default:
                addBoundToActiveSetMatrix_(workingset, 5, localActiveConstrIdx);
                break;
              }
              activeSetChangeID = 1;
            } else {
              if (objective->objtype == 5) {
                if (objective->nvar < 1) {
                  y = 0.0;
                } else {
                  n_t = (ptrdiff_t)objective->nvar;
                  incx_t = (ptrdiff_t)1;
                  y = dnrm2(&n_t, &solution->searchDir->data[0], &incx_t);
                }
                if (y >
                    100.0 * (real_T)objective->nvar * 1.4901161193847656E-8) {
                  solution->state = 3;
                } else {
                  solution->state = 4;
                }
              }
              subProblemChanged = false;
              if (workingset->nActiveConstr == 0) {
                solution->state = 1;
              }
            }
            if (nVar >= 1) {
              n_t = (ptrdiff_t)nVar;
              incx_t = (ptrdiff_t)1;
              incy_t = (ptrdiff_t)1;
              daxpy(&n_t, &normDelta, &solution->searchDir->data[0], &incx_t,
                    &solution->xstar->data[0], &incy_t);
            }
            computeGrad_StoreHx(objective, H, f, solution->xstar);
            updateFval = true;
            guard1 = true;
          }
        }
      } else {
        for (iAw0 = 0; iAw0 < nVar; iAw0++) {
          solution->searchDir->data[iAw0] = 0.0;
        }
        guard2 = true;
      }
      if (guard2) {
        localActiveConstrIdx = qrmanager->ncols;
        if (qrmanager->ncols > 0) {
          boolean_T b_guard1;
          b_guard1 = false;
          if (objective->objtype != 4) {
            normDelta =
                100.0 * (real_T)qrmanager->mrows * 2.2204460492503131E-16;
            if ((qrmanager->mrows > 0) && (qrmanager->ncols > 0)) {
              updateFval = true;
            } else {
              updateFval = false;
            }
            if (updateFval) {
              boolean_T b_guard2;
              idx = localActiveConstrIdx;
              b_guard2 = false;
              if (qrmanager->mrows < qrmanager->ncols) {
                activeConstrChangedType =
                    qrmanager->mrows + qrmanager->ldq * (qrmanager->ncols - 1);
                while ((idx > qrmanager->mrows) &&
                       (muDoubleScalarAbs(
                            qrmanager->QR->data[activeConstrChangedType - 1]) >=
                        normDelta)) {
                  idx--;
                  activeConstrChangedType -= qrmanager->ldq;
                }
                updateFval = (idx == qrmanager->mrows);
                if (updateFval) {
                  b_guard2 = true;
                }
              } else {
                b_guard2 = true;
              }
              if (b_guard2) {
                activeConstrChangedType = idx + qrmanager->ldq * (idx - 1);
                while ((idx >= 1) &&
                       (muDoubleScalarAbs(
                            qrmanager->QR->data[activeConstrChangedType - 1]) >=
                        normDelta)) {
                  idx--;
                  activeConstrChangedType =
                      (activeConstrChangedType - qrmanager->ldq) - 1;
                }
                updateFval = (idx == 0);
              }
            }
            if (!updateFval) {
              solution->state = -7;
            } else {
              b_guard1 = true;
            }
          } else {
            b_guard1 = true;
          }
          if (b_guard1) {
            b_xgemv(qrmanager->mrows, qrmanager->ncols, qrmanager->Q,
                    qrmanager->ldq, objective->grad,
                    memspace->workspace_double);
            if (qrmanager->ncols >= 1) {
              DIAGA1 = 'N';
              TRANSA1 = 'N';
              UPLO1 = 'U';
              n_t = (ptrdiff_t)qrmanager->ncols;
              incy_t = (ptrdiff_t)qrmanager->ldq;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &DIAGA1, &n_t, &qrmanager->QR->data[0],
                    &incy_t, &memspace->workspace_double->data[0], &incx_t);
            }
            activeConstrChangedType = (localActiveConstrIdx / 2) << 1;
            iAw0 = activeConstrChangedType - 2;
            for (idx = 0; idx <= iAw0; idx += 2) {
              __m128d r;
              r = _mm_loadu_pd(&memspace->workspace_double->data[idx]);
              _mm_storeu_pd(&solution->lambda->data[idx],
                            _mm_mul_pd(r, _mm_set1_pd(-1.0)));
            }
            for (idx = activeConstrChangedType; idx < localActiveConstrIdx;
                 idx++) {
              solution->lambda->data[idx] =
                  -memspace->workspace_double->data[idx];
            }
          }
        }
        if ((solution->state != -7) || (workingset->nActiveConstr > nVar)) {
          activeConstrChangedType = 0;
          normDelta = options_PricingTolerance *
                      runTimeOptions->ProbRelTolFactor * (real_T)(TYPE != 5);
          i = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
          i1 = workingset->nActiveConstr;
          for (idx = i; idx <= i1; idx++) {
            y = solution->lambda->data[idx - 1];
            if (y < normDelta) {
              normDelta = y;
              activeConstrChangedType = idx;
            }
          }
          if (activeConstrChangedType == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = activeConstrChangedType;
            subProblemChanged = true;
            removeConstr(workingset, activeConstrChangedType);
            solution->lambda->data[activeConstrChangedType - 1] = 0.0;
          }
        } else {
          activeConstrChangedType = workingset->nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset->nActiveConstr;
          subProblemChanged = true;
          removeConstr(workingset, workingset->nActiveConstr);
          solution->lambda->data[activeConstrChangedType - 1] = 0.0;
        }
        updateFval = false;
        guard1 = true;
      }
      if (guard1) {
        solution->iterations++;
        activeConstrChangedType = objective->nvar;
        if ((solution->iterations >= runTimeOptions->MaxIterations) &&
            ((solution->state != 1) || (objective->objtype == 5))) {
          solution->state = 0;
        }
        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr =
              maxConstraintViolation(workingset, solution->xstar);
          normDelta = solution->maxConstr;
          if (objective->objtype == 5) {
            normDelta = solution->maxConstr -
                        solution->xstar->data[objective->nvar - 1];
          }
          if (normDelta > options_ConstraintTolerance *
                              runTimeOptions->ConstrRelTolFactor) {
            if (objective->nvar >= 1) {
              n_t = (ptrdiff_t)objective->nvar;
              incx_t = (ptrdiff_t)1;
              incy_t = (ptrdiff_t)1;
              dcopy(&n_t, &solution->xstar->data[0], &incx_t,
                    &solution->searchDir->data[0], &incy_t);
            }
            newBlocking = feasibleX0ForWorkingSet(memspace->workspace_double,
                                                  solution->searchDir,
                                                  workingset, qrmanager);
            if ((!newBlocking) && (solution->state != 0)) {
              solution->state = -2;
            }
            activeSetChangeID = 0;
            normDelta = maxConstraintViolation(workingset, solution->searchDir);
            if (normDelta < solution->maxConstr) {
              for (idx = 0; idx < activeConstrChangedType; idx++) {
                solution->xstar->data[idx] = solution->searchDir->data[idx];
              }
              solution->maxConstr = normDelta;
            }
          }
        }
        if (updateFval && (options_ObjectiveLimit > rtMinusInf)) {
          solution->fstar = computeFval_ReuseHx(
              objective, memspace->workspace_double, f, solution->xstar);
          if ((solution->fstar < options_ObjectiveLimit) &&
              ((solution->state != 0) || (objective->objtype != 5))) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = computeFval_ReuseHx(
            objective, memspace->workspace_double, f, solution->xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* End of code generation (iterate.c) */
