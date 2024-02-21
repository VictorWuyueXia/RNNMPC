/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver1.c
 *
 * Code generation for function 'driver1'
 *
 */

/* Include files */
#include "driver1.h"
#include "BFGSUpdate.h"
#include "computeLinearResiduals.h"
#include "evalObjAndConstr.h"
#include "evalObjAndConstrAndDerivatives.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "saveJacobian.h"
#include "saveState.h"
#include "step.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include "xgemv.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void b_driver(const emxArray_real_T *bineq, const real_T lb[51],
              const real_T ub[51], c_struct_T *TrialState,
              struct_T *MeritFunction,
              const i_coder_internal_stickyStruct *FcnEvaluator,
              const l_struct_T *FiniteDifferences, h_struct_T *memspace,
              d_struct_T *WorkingSet, e_struct_T *QRManager,
              f_struct_T *CholManager, g_struct_T *QPObjective,
              const emxArray_real_T *fscales_lineq_constraint,
              const emxArray_real_T *fscales_cineq_constraint,
              real_T Hessian[2601])
{
  static const char_T qpoptions_SolverName[7] = {'f', 'm', 'i', 'n',
                                                 'c', 'o', 'n'};
  static const int8_T b_iv[2601] = {
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1};
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  b_struct_T Flags;
  m_struct_T b_expl_temp;
  m_struct_T expl_temp;
  real_T constrViolationEq;
  real_T constrViolationIneq;
  int32_T b_mLinIneq;
  int32_T i;
  int32_T k;
  int32_T mConstr;
  int32_T mConstr_tmp;
  int32_T mEq;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mLinEq;
  int32_T mLinIneq;
  int32_T mUB;
  int32_T nVar_tmp_tmp;
  int32_T qpoptions_MaxIterations;
  int32_T y;
  char_T TRANSA;
  for (i = 0; i < 2601; i++) {
    Hessian[i] = b_iv[i];
  }
  nVar_tmp_tmp = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mEq = WorkingSet->sizes[1];
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mConstr_tmp = WorkingSet->sizes[0] + WorkingSet->sizes[1];
  mConstr = ((mConstr_tmp + WorkingSet->sizes[2]) + WorkingSet->sizes[3]) +
            WorkingSet->sizes[4];
  mLinIneq = WorkingSet->sizes[2] - TrialState->mNonlinIneq;
  mLinEq = WorkingSet->sizes[1] - TrialState->mNonlinEq;
  y = ((WorkingSet->sizes[2] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
      (WorkingSet->sizes[0] << 1);
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet->nVar, y);
  TrialState->steplength = 1.0;
  Flags.gradOK =
      test_exit(memspace, MeritFunction, fscales_lineq_constraint,
                fscales_cineq_constraint, WorkingSet, TrialState, QRManager, lb,
                ub, &Flags.fevalOK, &Flags.done, &Flags.stepAccepted,
                &Flags.failedLineSearch, &Flags.stepType);
  saveJacobian(TrialState, nVar_tmp_tmp, mIneq, WorkingSet->Aineq,
               TrialState->iNonIneq0, mEq, WorkingSet->Aeq, TrialState->iNonEq0,
               WorkingSet->ldA);
  saveState(TrialState);
  if (!Flags.done) {
    TrialState->sqpIterations++;
  }
  while (!Flags.done) {
    __m128d r;
    real_T d;
    int32_T vectorUB;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      if (Flags.stepType != 3) {
        b_updateWorkingSetForNewQP(TrialState->xstarsqp, WorkingSet, mIneq,
                                   TrialState->mNonlinIneq, TrialState->cIneq,
                                   mEq, TrialState->mNonlinEq, TrialState->cEq,
                                   mLB, lb, mUB, ub, mFixed);
      }
      expl_temp.RemainFeasible = false;
      expl_temp.ProbRelTolFactor = 1.0;
      expl_temp.ConstrRelTolFactor = 1.0;
      expl_temp.PricingTolerance = 0.0;
      expl_temp.ObjectiveLimit = rtMinusInf;
      expl_temp.ConstraintTolerance = 1.0E-6;
      expl_temp.StepTolerance = 1.0E-6;
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i = 0; i < 7; i++) {
        expl_temp.SolverName[i] = qpoptions_SolverName[i];
      }
      b_expl_temp = expl_temp;
      Flags.stepAccepted = step(&Flags.stepType, Hessian, lb, ub, TrialState,
                                MeritFunction, memspace, WorkingSet, QRManager,
                                CholManager, QPObjective, &b_expl_temp);
      if (Flags.stepAccepted) {
        for (b_mLinIneq = 0; b_mLinIneq < nVar_tmp_tmp; b_mLinIneq++) {
          TrialState->xstarsqp[b_mLinIneq] +=
              TrialState->delta_x->data[b_mLinIneq];
        }
        TrialState->sqpFval = evalObjAndConstr(
            FcnEvaluator->next.next.next.next.next.value,
            &FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                 .runtimedata,
            &FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                 .userdata,
            &FcnEvaluator->next.next.next.next.next.next.next.next.value
                 .workspace,
            TrialState->xstarsqp, TrialState->cIneq, TrialState->iNonIneq0,
            TrialState->cEq, TrialState->iNonEq0, &y);
        Flags.fevalOK = (y == 1);
        TrialState->FunctionEvaluations++;
        computeLinearResiduals(TrialState->xstarsqp, nVar_tmp_tmp,
                               TrialState->cIneq, mLinIneq, WorkingSet->Aineq,
                               bineq, WorkingSet->ldA, TrialState->cEq, mLinEq,
                               WorkingSet->Aeq, WorkingSet->ldA);
        if (Flags.fevalOK) {
          constrViolationEq = 0.0;
          if (mEq >= 1) {
            for (k = 0; k < mEq; k++) {
              constrViolationEq += muDoubleScalarAbs(TrialState->cEq[k]);
            }
          }
          constrViolationIneq = 0.0;
          for (k = 0; k < mIneq; k++) {
            d = TrialState->cIneq->data[k];
            if (d > 0.0) {
              constrViolationIneq += d;
            }
          }
          MeritFunction->phiFullStep =
              TrialState->sqpFval +
              MeritFunction->penaltyParam *
                  (constrViolationEq + constrViolationIneq);
        } else {
          MeritFunction->phiFullStep = rtInf;
        }
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (MeritFunction->phi < MeritFunction->phiFullStep) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        real_T alpha;
        int32_T b_mLinEq;
        int32_T exitflagLnSrch;
        boolean_T evalWellDefined;
        boolean_T socTaken;
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        evalWellDefined = Flags.fevalOK;
        i = WorkingSet->nVar;
        b_mLinIneq = TrialState->mIneq - TrialState->mNonlinIneq;
        b_mLinEq = TrialState->mEq - TrialState->mNonlinEq;
        alpha = 1.0;
        exitflagLnSrch = 1;
        constrViolationEq = MeritFunction->phiFullStep;
        if (WorkingSet->nVar >= 1) {
          n_t = (ptrdiff_t)WorkingSet->nVar;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &TrialState->delta_x->data[0], &incx_t,
                &TrialState->searchDir->data[0], &incy_t);
        }
        int32_T exitg1;
        do {
          exitg1 = 0;
          if (TrialState->FunctionEvaluations < 5100) {
            if (evalWellDefined &&
                (constrViolationEq <=
                 MeritFunction->phi +
                     alpha * 0.0001 * MeritFunction->phiPrimePlus)) {
              exitg1 = 1;
            } else {
              boolean_T exitg2;
              boolean_T tooSmallX;
              alpha *= 0.7;
              y = (i / 2) << 1;
              vectorUB = y - 2;
              for (k = 0; k <= vectorUB; k += 2) {
                r = _mm_loadu_pd(&TrialState->xstar->data[k]);
                _mm_storeu_pd(&TrialState->delta_x->data[k],
                              _mm_mul_pd(_mm_set1_pd(alpha), r));
              }
              for (k = y; k < i; k++) {
                TrialState->delta_x->data[k] =
                    alpha * TrialState->xstar->data[k];
              }
              if (socTaken) {
                constrViolationEq = alpha * alpha;
                if (i >= 1) {
                  n_t = (ptrdiff_t)i;
                  incx_t = (ptrdiff_t)1;
                  incy_t = (ptrdiff_t)1;
                  daxpy(&n_t, &constrViolationEq,
                        &TrialState->socDirection->data[0], &incx_t,
                        &TrialState->delta_x->data[0], &incy_t);
                }
              }
              tooSmallX = true;
              k = 0;
              exitg2 = false;
              while ((!exitg2) && (k <= i - 1)) {
                if (1.0E-6 *
                        muDoubleScalarMax(
                            1.0, muDoubleScalarAbs(TrialState->xstarsqp[k])) <=
                    muDoubleScalarAbs(TrialState->delta_x->data[k])) {
                  tooSmallX = false;
                  exitg2 = true;
                } else {
                  k++;
                }
              }
              if (tooSmallX) {
                exitflagLnSrch = -2;
                exitg1 = 1;
              } else {
                for (k = 0; k < i; k++) {
                  TrialState->xstarsqp[k] = TrialState->xstarsqp_old[k] +
                                            TrialState->delta_x->data[k];
                }
                TrialState->sqpFval = evalObjAndConstr(
                    FcnEvaluator->next.next.next.next.next.value,
                    &FcnEvaluator->next.next.next.next.next.next.next.value
                         .workspace.runtimedata,
                    &FcnEvaluator->next.next.next.next.next.next.next.value
                         .workspace.userdata,
                    &FcnEvaluator->next.next.next.next.next.next.next.next.value
                         .workspace,
                    TrialState->xstarsqp, TrialState->cIneq,
                    TrialState->iNonIneq0, TrialState->cEq, TrialState->iNonEq0,
                    &y);
                computeLinearResiduals(
                    TrialState->xstarsqp, i, TrialState->cIneq, b_mLinIneq,
                    WorkingSet->Aineq, bineq, WorkingSet->ldA, TrialState->cEq,
                    b_mLinEq, WorkingSet->Aeq, WorkingSet->ldA);
                TrialState->FunctionEvaluations++;
                evalWellDefined = (y == 1);
                vectorUB = TrialState->mIneq;
                y = TrialState->mEq;
                if (evalWellDefined) {
                  constrViolationEq = 0.0;
                  if (TrialState->mEq >= 1) {
                    for (k = 0; k < y; k++) {
                      constrViolationEq +=
                          muDoubleScalarAbs(TrialState->cEq[k]);
                    }
                  }
                  constrViolationIneq = 0.0;
                  for (k = 0; k < vectorUB; k++) {
                    d = TrialState->cIneq->data[k];
                    if (d > 0.0) {
                      constrViolationIneq += d;
                    }
                  }
                  constrViolationEq =
                      TrialState->sqpFval +
                      MeritFunction->penaltyParam *
                          (constrViolationEq + constrViolationIneq);
                } else {
                  constrViolationEq = rtInf;
                }
              }
            }
          } else {
            exitflagLnSrch = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
        Flags.fevalOK = evalWellDefined;
        TrialState->steplength = alpha;
        if (exitflagLnSrch > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      for (k = 0; k < nVar_tmp_tmp; k++) {
        TrialState->xstarsqp[k] =
            TrialState->xstarsqp_old[k] + TrialState->delta_x->data[k];
      }
      y = (mConstr / 2) << 1;
      vectorUB = y - 2;
      for (k = 0; k <= vectorUB; k += 2) {
        __m128d r1;
        r = _mm_loadu_pd(&TrialState->lambda->data[k]);
        r1 = _mm_loadu_pd(&TrialState->lambdasqp->data[k]);
        _mm_storeu_pd(
            &TrialState->lambdasqp->data[k],
            _mm_add_pd(r1, _mm_mul_pd(_mm_set1_pd(TrialState->steplength),
                                      _mm_sub_pd(r, r1))));
      }
      for (k = y; k < mConstr; k++) {
        d = TrialState->lambdasqp->data[k];
        d += TrialState->steplength * (TrialState->lambda->data[k] - d);
        TrialState->lambdasqp->data[k] = d;
      }
      saveState(TrialState);
      Flags.gradOK = true;
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
      TrialState->sqpFval = evalObjAndConstrAndDerivatives(
          FcnEvaluator->next.next.next.next.next.value,
          &FcnEvaluator->next.next.next.next.next.next.next.value.workspace
               .runtimedata,
          &FcnEvaluator->next.next.next.next.next.next.next.value.workspace
               .userdata,
          &FcnEvaluator->next.next.next.next.next.next.next.next.value
               .workspace,
          TrialState->xstarsqp, TrialState->grad, TrialState->cIneq,
          TrialState->iNonIneq0, TrialState->cEq, TrialState->iNonEq0,
          WorkingSet->Aineq, TrialState->iNonIneq0, WorkingSet->ldA,
          WorkingSet->Aeq, TrialState->iNonEq0, WorkingSet->ldA, &y);
      TrialState->FunctionEvaluations++;
      Flags.fevalOK = (y == 1);
    } else {
      TrialState->sqpFval = TrialState->sqpFval_old;
      memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0],
             51U * sizeof(real_T));
      if (TrialState->mIneq >= 1) {
        n_t = (ptrdiff_t)TrialState->mIneq;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &TrialState->cIneq_old->data[0], &incx_t,
              &TrialState->cIneq->data[0], &incy_t);
      }
      y = TrialState->mEq;
      if (y - 1 >= 0) {
        memcpy(&TrialState->cEq[0], &TrialState->cEq_old[0],
               (uint32_T)y * sizeof(real_T));
      }
    }
    b_test_exit(&Flags, memspace, MeritFunction, fscales_lineq_constraint,
                fscales_cineq_constraint, WorkingSet, TrialState, QRManager, lb,
                ub);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      y = mConstr_tmp + TrialState->iNonIneq0;
      vectorUB = mFixed + TrialState->iNonEq0;
      for (b_mLinIneq = 0; b_mLinIneq < nVar_tmp_tmp; b_mLinIneq++) {
        TrialState->delta_gradLag->data[b_mLinIneq] =
            TrialState->grad->data[b_mLinIneq];
      }
      if (nVar_tmp_tmp >= 1) {
        constrViolationEq = -1.0;
        n_t = (ptrdiff_t)nVar_tmp_tmp;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        daxpy(&n_t, &constrViolationEq, &TrialState->grad_old->data[0], &incx_t,
              &TrialState->delta_gradLag->data[0], &incy_t);
      }
      if (TrialState->mNonlinEq > 0) {
        h_xgemv(nVar_tmp_tmp, TrialState->mNonlinEq, WorkingSet->Aeq,
                WorkingSet->ldA * (TrialState->iNonEq0 - 1) + 1,
                WorkingSet->ldA, TrialState->lambdasqp, vectorUB,
                TrialState->delta_gradLag);
        if (nVar_tmp_tmp >= 1) {
          constrViolationEq = -1.0;
          constrViolationIneq = 1.0;
          TRANSA = 'N';
          m_t = (ptrdiff_t)nVar_tmp_tmp;
          n_t = (ptrdiff_t)TrialState->mNonlinEq;
          lda_t = (ptrdiff_t)WorkingSet->ldA;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dgemv(&TRANSA, &m_t, &n_t, &constrViolationEq,
                &TrialState->JacCeqTrans_old->data[0], &lda_t,
                &TrialState->lambdasqp->data[vectorUB - 1], &incx_t,
                &constrViolationIneq, &TrialState->delta_gradLag->data[0],
                &incy_t);
        }
      }
      if (TrialState->mNonlinIneq > 0) {
        h_xgemv(nVar_tmp_tmp, TrialState->mNonlinIneq, WorkingSet->Aineq,
                WorkingSet->ldA * (TrialState->iNonIneq0 - 1) + 1,
                WorkingSet->ldA, TrialState->lambdasqp, y,
                TrialState->delta_gradLag);
        if (nVar_tmp_tmp >= 1) {
          constrViolationEq = -1.0;
          constrViolationIneq = 1.0;
          TRANSA = 'N';
          m_t = (ptrdiff_t)nVar_tmp_tmp;
          n_t = (ptrdiff_t)TrialState->mNonlinIneq;
          lda_t = (ptrdiff_t)WorkingSet->ldA;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dgemv(&TRANSA, &m_t, &n_t, &constrViolationEq,
                &TrialState->JacCineqTrans_old->data[0], &lda_t,
                &TrialState->lambdasqp->data[y - 1], &incx_t,
                &constrViolationIneq, &TrialState->delta_gradLag->data[0],
                &incy_t);
        }
      }
      saveJacobian(TrialState, nVar_tmp_tmp, mIneq, WorkingSet->Aineq,
                   TrialState->iNonIneq0, mEq, WorkingSet->Aeq,
                   TrialState->iNonEq0, WorkingSet->ldA);
      BFGSUpdate(nVar_tmp_tmp, Hessian, TrialState->delta_x,
                 TrialState->delta_gradLag, memspace->workspace_double);
      TrialState->sqpIterations++;
    }
  }
}

/* End of code generation (driver1.c) */
