/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * znlmpc_objfun.h
 *
 * Code generation for function 'znlmpc_objfun'
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
void binary_expand_op(real_T in1[2], const k_struct_T *in2, int32_T in3,
                      const emxArray_real_T *in4);

void binary_expand_op_1(real_T in1[4], const k_struct_T *in2, int32_T in3,
                        const real_T in4[44]);

/* End of code generation (znlmpc_objfun.h) */
