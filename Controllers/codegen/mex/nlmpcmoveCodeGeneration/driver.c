/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver.c
 *
 * Code generation for function 'driver'
 *
 */

/* Include files */
#include "driver.h"
#include "PresolveWorkingSet.h"
#include "computeFval.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void driver(const real_T H[2601], const emxArray_real_T *f,
            c_struct_T *solution, h_struct_T *memspace, d_struct_T *workingset,
            e_struct_T *qrmanager, f_struct_T *cholmanager,
            g_struct_T *objective, const m_struct_T *options,
            m_struct_T *runTimeOptions)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  int32_T idxStartIneq;
  int32_T idx_global;
  int32_T mConstr;
  int32_T nVar_tmp;
  boolean_T guard1;
  solution->iterations = 0;
  runTimeOptions->RemainFeasible = (options->PricingTolerance <= 0.0);
  nVar_tmp = workingset->nVar;
  guard1 = false;
  if (workingset->probType == 3) {
    mConstr = workingset->sizes[0];
    for (idxStartIneq = 0; idxStartIneq < mConstr; idxStartIneq++) {
      solution->xstar->data[workingset->indexFixed->data[idxStartIneq] - 1] =
          workingset->ub->data[workingset->indexFixed->data[idxStartIneq] - 1];
    }
    mConstr = workingset->sizes[3];
    for (idxStartIneq = 0; idxStartIneq < mConstr; idxStartIneq++) {
      if (workingset->isActiveConstr
              ->data[(workingset->isActiveIdx[3] + idxStartIneq) - 1]) {
        solution->xstar->data[workingset->indexLB->data[idxStartIneq] - 1] =
            -workingset->lb->data[workingset->indexLB->data[idxStartIneq] - 1];
      }
    }
    mConstr = workingset->sizes[4];
    for (idxStartIneq = 0; idxStartIneq < mConstr; idxStartIneq++) {
      if (workingset->isActiveConstr
              ->data[(workingset->isActiveIdx[4] + idxStartIneq) - 1]) {
        solution->xstar->data[workingset->indexUB->data[idxStartIneq] - 1] =
            workingset->ub->data[workingset->indexUB->data[idxStartIneq] - 1];
      }
    }
    PresolveWorkingSet(solution, memspace, workingset, qrmanager, options);
    if (solution->state >= 0) {
      guard1 = true;
    }
  } else {
    solution->state = 82;
    guard1 = true;
  }
  if (guard1) {
    real_T maxConstr_new;
    solution->iterations = 0;
    solution->maxConstr = maxConstraintViolation(workingset, solution->xstar);
    maxConstr_new =
        options->ConstraintTolerance * runTimeOptions->ConstrRelTolFactor;
    if (solution->maxConstr > maxConstr_new) {
      int32_T PROBTYPE_ORIG;
      int32_T idxEndIneq_tmp_tmp;
      PROBTYPE_ORIG = workingset->probType;
      solution->xstar->data[workingset->nVar] = solution->maxConstr + 1.0;
      if (workingset->probType == 3) {
        mConstr = 1;
      } else {
        mConstr = 4;
      }
      setProblemType(workingset, mConstr);
      mConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
      idxStartIneq = mConstr + 1;
      idxEndIneq_tmp_tmp = workingset->nActiveConstr;
      for (idx_global = idxStartIneq; idx_global <= idxEndIneq_tmp_tmp;
           idx_global++) {
        workingset->isActiveConstr
            ->data[(workingset->isActiveIdx
                        [workingset->Wid->data[idx_global - 1] - 1] +
                    workingset->Wlocalidx->data[idx_global - 1]) -
                   2] = false;
      }
      workingset->nWConstr[2] = 0;
      workingset->nWConstr[3] = 0;
      workingset->nWConstr[4] = 0;
      workingset->nActiveConstr = mConstr;
      objective->prev_objtype = objective->objtype;
      objective->prev_nvar = objective->nvar;
      objective->prev_hasLinear = objective->hasLinear;
      objective->objtype = 5;
      objective->nvar = nVar_tmp + 1;
      objective->gammaScalar = 1.0;
      objective->hasLinear = true;
      solution->fstar = computeFval(objective, memspace->workspace_double, H, f,
                                    solution->xstar);
      solution->state = 5;
      iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
              objective, options->SolverName, 1.4901161193847657E-10,
              options->ConstraintTolerance, maxConstr_new,
              options->PricingTolerance, runTimeOptions);
      if (workingset->isActiveConstr
              ->data[(workingset->isActiveIdx[3] + workingset->sizes[3]) - 2]) {
        boolean_T exitg1;
        idxStartIneq = workingset->sizes[0] + workingset->sizes[1];
        exitg1 = false;
        while ((!exitg1) && (idxStartIneq + 1 <= workingset->nActiveConstr)) {
          if ((workingset->Wid->data[idxStartIneq] == 4) &&
              (workingset->Wlocalidx->data[idxStartIneq] ==
               workingset->sizes[3])) {
            removeConstr(workingset, idxStartIneq + 1);
            exitg1 = true;
          } else {
            idxStartIneq++;
          }
        }
      }
      mConstr = workingset->nActiveConstr;
      idxStartIneq = workingset->sizes[0] + workingset->sizes[1];
      while ((mConstr > idxStartIneq) && (mConstr > nVar_tmp)) {
        removeConstr(workingset, mConstr);
        mConstr--;
      }
      solution->maxConstr = solution->xstar->data[nVar_tmp];
      setProblemType(workingset, PROBTYPE_ORIG);
      objective->objtype = objective->prev_objtype;
      objective->nvar = objective->prev_nvar;
      objective->hasLinear = objective->prev_hasLinear;
      if (solution->state != 0) {
        solution->maxConstr =
            maxConstraintViolation(workingset, solution->xstar);
        if (solution->maxConstr > maxConstr_new) {
          mConstr = workingset->mConstrMax;
          for (idxStartIneq = 0; idxStartIneq < mConstr; idxStartIneq++) {
            solution->lambda->data[idxStartIneq] = 0.0;
          }
          solution->fstar = computeFval(objective, memspace->workspace_double,
                                        H, f, solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            if (nVar_tmp >= 1) {
              n_t = (ptrdiff_t)nVar_tmp;
              incx_t = (ptrdiff_t)1;
              incy_t = (ptrdiff_t)1;
              dcopy(&n_t, &solution->xstar->data[0], &incx_t,
                    &solution->searchDir->data[0], &incy_t);
            }
            PresolveWorkingSet(solution, memspace, workingset, qrmanager,
                               options);
            maxConstr_new = maxConstraintViolation(workingset, solution->xstar);
            if (maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = maxConstr_new;
              if (nVar_tmp >= 1) {
                n_t = (ptrdiff_t)nVar_tmp;
                incx_t = (ptrdiff_t)1;
                incy_t = (ptrdiff_t)1;
                dcopy(&n_t, &solution->searchDir->data[0], &incx_t,
                      &solution->xstar->data[0], &incy_t);
              }
            }
          }
          iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
                  objective, options->SolverName, options->StepTolerance,
                  options->ConstraintTolerance, options->ObjectiveLimit,
                  options->PricingTolerance, runTimeOptions);
        }
      }
    } else {
      iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
              objective, options->SolverName, options->StepTolerance,
              options->ConstraintTolerance, options->ObjectiveLimit,
              options->PricingTolerance, runTimeOptions);
    }
  }
}

/* End of code generation (driver.c) */
