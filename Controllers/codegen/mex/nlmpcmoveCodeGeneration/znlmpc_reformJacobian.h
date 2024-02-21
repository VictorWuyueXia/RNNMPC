/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * znlmpc_reformJacobian.h
 *
 * Code generation for function 'znlmpc_reformJacobian'
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
void znlmpc_reformJacobian(const emxArray_real_T *Jx,
                           const emxArray_real_T *Jmv,
                           const emxArray_real_T *Je, emxArray_real_T *Jc);

/* End of code generation (znlmpc_reformJacobian.h) */
