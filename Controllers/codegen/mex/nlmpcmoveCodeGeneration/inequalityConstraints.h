/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * inequalityConstraints.h
 *
 * Code generation for function 'inequalityConstraints'
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
void inequalityConstraints(const real_T X[44], const real_T U[22], real_T e,
                           real_T data_PredictionHorizon, real_T Ts,
                           const real_T limits[6],
                           emxArray_real_T *constraints);

/* End of code generation (inequalityConstraints.h) */
