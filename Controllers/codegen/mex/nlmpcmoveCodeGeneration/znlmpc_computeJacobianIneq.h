/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * znlmpc_computeJacobianIneq.h
 *
 * Code generation for function 'znlmpc_computeJacobianIneq'
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
void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                      real_T in3);

void binary_expand_op_3(emxArray_real_T *in1, const emxArray_real_T *in2,
                        const emxArray_real_T *in3, const emxArray_real_T *in4,
                        real_T in5);

/* End of code generation (znlmpc_computeJacobianIneq.h) */
