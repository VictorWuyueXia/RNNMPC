/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mpcCostFunction.c
 *
 * Code generation for function 'mpcCostFunction'
 *
 */

/* Include files */
#include "mpcCostFunction.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T mpcCostFunction(const real_T X[44], const real_T U[22], real_T e,
                       const real_T waypoints[6], const real_T weights[14])
{
  real_T cost_inputs;
  real_T cost_progress;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  int32_T i;
  /*  Unpack */
  /*  weights is fed in as an array of  */
  /*  [progress_x progress_y input_acc input_steer obsAvoid LaneKeeping RL
   * sofConstraints] */
  /*  waypoints are in body frame */
  cost_progress = 0.0;
  /*  quadratic cost for inputs */
  cost_inputs = 0.0;
  d = waypoints[0];
  d1 = waypoints[3];
  d2 = weights[4];
  d3 = weights[0];
  d4 = weights[1];
  d5 = weights[2];
  d6 = weights[3];
  for (i = 0; i < 11; i++) {
    real_T absxk;
    real_T distance;
    real_T scale;
    real_T t;
    scale = 3.3121686421112381E-170;
    absxk = muDoubleScalarAbs(d - X[i]);
    if (absxk > 3.3121686421112381E-170) {
      distance = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      distance = t * t;
    }
    absxk = muDoubleScalarAbs(d1 - X[i + 11]);
    if (absxk > scale) {
      t = scale / absxk;
      distance = distance * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      distance += t * t;
    }
    distance = scale * muDoubleScalarSqrt(distance);
    cost_progress += distance * d2 * distance;
    scale = U[i + 11];
    absxk = U[i];
    cost_inputs +=
        (absxk * d3 + scale * d4) * absxk + (absxk * d5 + scale * d6) * scale;
  }
  return (cost_progress + cost_inputs) + e * weights[12];
}

/* End of code generation (mpcCostFunction.c) */
