/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * div.c
 *
 * Code generation for function 'div'
 *
 */

/* Include files */
#include "div.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void binary_expand_op_4(real_T in1[10], const real_T in2[44], int32_T in3,
                        int32_T in4, real_T in5)
{
  int32_T i;
  int32_T stride_0_0;
  stride_0_0 = ((in4 - in3) + 1 != 1);
  for (i = 0; i < 10; i++) {
    in1[i] = in2[(in3 + i * stride_0_0) + 33] /
             (0.017453292519943295 * in1[i] / in5);
  }
}

/* End of code generation (div.c) */
