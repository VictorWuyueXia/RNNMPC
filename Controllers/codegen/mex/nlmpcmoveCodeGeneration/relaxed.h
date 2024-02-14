/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * relaxed.h
 *
 * Code generation for function 'relaxed'
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
void relaxed(const real_T Hessian[2601], const emxArray_real_T *grad,
             c_struct_T *TrialState, struct_T *MeritFunction,
             h_struct_T *memspace, d_struct_T *WorkingSet,
             e_struct_T *QRManager, f_struct_T *CholManager,
             g_struct_T *QPObjective, m_struct_T *qpoptions);

/* End of code generation (relaxed.h) */
