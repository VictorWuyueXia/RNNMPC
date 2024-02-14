/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factoryConstruct1.h
 *
 * Code generation for function 'factoryConstruct1'
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
void b_factoryConstruct(const i_struct_T *objfun_workspace_runtimedata,
                        const j_struct_T *objfun_workspace_userdata,
                        const i_struct_T *nonlin_workspace_runtimedata,
                        const j_struct_T *nonlin_workspace_userdata,
                        int32_T mCineq, const real_T lb[51],
                        const real_T ub[51], l_struct_T *obj);

/* End of code generation (factoryConstruct1.h) */
