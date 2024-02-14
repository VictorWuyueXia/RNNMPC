/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * znlmpc_objfun.c
 *
 * Code generation for function 'znlmpc_objfun'
 *
 */

/* Include files */
#include "znlmpc_objfun.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void binary_expand_op(real_T in1[2], const k_struct_T *in2, int32_T in3,
                      const emxArray_real_T *in4)
{
  const real_T *in4_data;
  in4_data = in4->data;
  in1[0] = in2->runtimedata.MVWeights[in3] * (in1[0] - in4_data[0]);
  in1[1] = in2->runtimedata.MVWeights[in3 + 10] *
           (in1[1] - in4_data[in4->size[0] != 1]);
}

void binary_expand_op_1(real_T in1[4], const k_struct_T *in2, int32_T in3,
                        const real_T in4[44])
{
  int32_T i;
  int32_T stride_0_0;
  stride_0_0 = (in2->runtimedata.ref->size[1] != 1);
  i = (in3 + 1) << 2;
  in1[0] = in2->runtimedata.OutputWeights[in3] *
           (in4[i] - in2->runtimedata.ref->data[in3]);
  in1[1] = in2->runtimedata.OutputWeights[in3 + 10] *
           (in4[i + 1] -
            in2->runtimedata.ref
                ->data[in3 + in2->runtimedata.ref->size[0] * stride_0_0]);
  in1[2] =
      in2->runtimedata.OutputWeights[in3 + 20] *
      (in4[i + 2] -
       in2->runtimedata.ref
           ->data[in3 + in2->runtimedata.ref->size[0] * (stride_0_0 << 1)]);
  in1[3] = in2->runtimedata.OutputWeights[in3 + 30] *
           (in4[i + 3] -
            in2->runtimedata.ref
                ->data[in3 + in2->runtimedata.ref->size[0] * (3 * stride_0_0)]);
}

/* End of code generation (znlmpc_objfun.c) */
