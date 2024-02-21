/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * evalObjAndConstr.h
 *
 * Code generation for function 'evalObjAndConstr'
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
real_T evalObjAndConstr(int32_T c_obj_next_next_next_next_next_,
                        const i_struct_T *d_obj_next_next_next_next_next_,
                        const j_struct_T *e_obj_next_next_next_next_next_,
                        const k_struct_T *f_obj_next_next_next_next_next_,
                        const real_T x[51], emxArray_real_T *Cineq_workspace,
                        int32_T ineq0, real_T Ceq_workspace[40], int32_T eq0,
                        int32_T *status);

/* End of code generation (evalObjAndConstr.h) */
