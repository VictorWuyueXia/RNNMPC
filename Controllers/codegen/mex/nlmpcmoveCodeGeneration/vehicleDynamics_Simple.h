/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vehicleDynamics_Simple.h
 *
 * Code generation for function 'vehicleDynamics_Simple'
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
void vehicleDynamics_Simple(const real_T state[4], const real_T input[2],
                            real_T Ts, real_T L, real_T nextState[4]);

/* End of code generation (vehicleDynamics_Simple.h) */
