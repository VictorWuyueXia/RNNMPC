/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver1.h
 *
 * Code generation for function 'driver1'
 *
 */

#pragma once

/* Include files */
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_driver(const emxArray_real_T *bineq, const real_T lb[51],
              const real_T ub[51], c_struct_T *TrialState,
              struct_T *MeritFunction,
              const i_coder_internal_stickyStruct *FcnEvaluator,
              const l_struct_T *FiniteDifferences, h_struct_T *memspace,
              d_struct_T *WorkingSet, e_struct_T *QRManager,
              f_struct_T *CholManager, g_struct_T *QPObjective,
              const emxArray_real_T *fscales_lineq_constraint,
              const emxArray_real_T *fscales_cineq_constraint,
              real_T Hessian[2601]);

/* End of code generation (driver1.h) */
