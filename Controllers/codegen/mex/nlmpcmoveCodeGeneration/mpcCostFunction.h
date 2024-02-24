/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mpcCostFunction.h
 *
 * Code generation for function 'mpcCostFunction'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T mpcCostFunction(const real_T X[44], const real_T U[22], real_T e,
                       const real_T waypoints[6], const real_T weights[14]);

/* End of code generation (mpcCostFunction.h) */
