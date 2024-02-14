/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fmincon.h
 *
 * Code generation for function 'fmincon'
 *
 */

#pragma once

/* Include files */
#include "nlmpcmoveCodeGeneration_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T fmincon(const i_struct_T *fun_workspace_runtimedata,
               const j_struct_T *fun_workspace_userdata, real_T x0[51],
               const emxArray_real_T *Aineq, const emxArray_real_T *bineq,
               const real_T lb[51], const real_T ub[51],
               const i_struct_T *nonlcon_workspace_runtimedata,
               const j_struct_T *nonlcon_workspace_userdata, real_T *exitflag,
               real_T *output_iterations, real_T *output_funcCount,
               char_T output_algorithm[3], real_T *output_constrviolation,
               real_T *output_stepsize, real_T *output_lssteplength,
               real_T *output_firstorderopt);

/* End of code generation (fmincon.h) */
