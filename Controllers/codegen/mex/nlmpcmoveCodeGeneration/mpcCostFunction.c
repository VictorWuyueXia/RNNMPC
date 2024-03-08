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
                       const real_T waypoints[12], const real_T weights[14],
                       const real_T laneCoords[22])
{
  real_T cost_inputs;
  real_T cost_laneKeeping;
  real_T cost_progress;
  int32_T i;
  int32_T pointPair;
  /*  Unpack */
  /*  weights is fed in as an 2xN array of  */
  /*  [input(2x2) progress(2x1) laneKeeping(2x1) obsAvoid(2x1) RL(2x1)
   * softConstraintPenalty(2x1)] */
  /*  waypoints are in body frame */
  cost_progress = 0.0;
  /*  quadratic cost for inputs */
  cost_inputs = 0.0;
  /*  quadratic cost for difference in distance from each boundary */
  cost_laneKeeping = 0.0;
  pointPair = 1;
  for (i = 0; i < 11; i++) {
    real_T Distance_l;
    real_T Distance_r;
    real_T absxk;
    real_T absxk_tmp;
    real_T b_scale;
    real_T d;
    real_T d1;
    real_T distance;
    real_T scale;
    real_T t;
    real_T totalDistance;
    boolean_T exitg1;
    scale = 3.3121686421112381E-170;
    d = X[i];
    absxk = muDoubleScalarAbs(waypoints[0] - d);
    if (absxk > 3.3121686421112381E-170) {
      distance = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      distance = t * t;
    }
    d1 = X[i + 11];
    absxk = muDoubleScalarAbs(waypoints[6] - d1);
    if (absxk > scale) {
      t = scale / absxk;
      distance = distance * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      distance += t * t;
    }
    distance = scale * muDoubleScalarSqrt(distance);
    cost_progress += distance * weights[4] * distance;
    distance = U[i + 11];
    Distance_r = U[i];
    cost_inputs +=
        (Distance_r * weights[0] + distance * weights[1]) * Distance_r +
        (Distance_r * weights[2] + distance * weights[3]) * distance;
    /*  one state */
    /*  The current lane boundaries points pair */
    scale = 3.3121686421112381E-170;
    b_scale = 3.3121686421112381E-170;
    absxk_tmp = laneCoords[pointPair - 1];
    absxk = muDoubleScalarAbs(absxk_tmp - d);
    if (absxk > 3.3121686421112381E-170) {
      Distance_l = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      Distance_l = t * t;
    }
    distance = laneCoords[pointPair + 10];
    absxk = muDoubleScalarAbs(distance - d);
    if (absxk > 3.3121686421112381E-170) {
      Distance_r = 1.0;
      b_scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      Distance_r = t * t;
    }
    absxk = muDoubleScalarAbs(absxk_tmp - d1);
    if (absxk > scale) {
      t = scale / absxk;
      Distance_l = Distance_l * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      Distance_l += t * t;
    }
    absxk = muDoubleScalarAbs(distance - d1);
    if (absxk > b_scale) {
      t = b_scale / absxk;
      Distance_r = Distance_r * t * t + 1.0;
      b_scale = absxk;
    } else {
      t = absxk / b_scale;
      Distance_r += t * t;
    }
    Distance_l = scale * muDoubleScalarSqrt(Distance_l);
    Distance_r = b_scale * muDoubleScalarSqrt(Distance_r);
    totalDistance = Distance_l + Distance_r;
    Distance_l -= Distance_r;
    /*  Find the nearest point pair */
    exitg1 = false;
    while ((!exitg1) && (pointPair < 11)) {
      real_T Distance_l_next;
      /*  if the last pair, stop;  */
      /*  The next lane boundaries points pair */
      scale = 3.3121686421112381E-170;
      b_scale = 3.3121686421112381E-170;
      d = X[i];
      absxk = muDoubleScalarAbs(laneCoords[pointPair] - d);
      if (absxk > 3.3121686421112381E-170) {
        Distance_l_next = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        Distance_l_next = t * t;
      }
      absxk_tmp = laneCoords[pointPair + 11];
      absxk = muDoubleScalarAbs(absxk_tmp - d);
      if (absxk > 3.3121686421112381E-170) {
        distance = 1.0;
        b_scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        distance = t * t;
      }
      absxk = muDoubleScalarAbs(laneCoords[pointPair] - d1);
      if (absxk > scale) {
        t = scale / absxk;
        Distance_l_next = Distance_l_next * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        Distance_l_next += t * t;
      }
      absxk = muDoubleScalarAbs(absxk_tmp - d1);
      if (absxk > b_scale) {
        t = b_scale / absxk;
        distance = distance * t * t + 1.0;
        b_scale = absxk;
      } else {
        t = absxk / b_scale;
        distance += t * t;
      }
      Distance_l_next = scale * muDoubleScalarSqrt(Distance_l_next);
      distance = b_scale * muDoubleScalarSqrt(distance);
      Distance_r = Distance_l_next + distance;
      if (muDoubleScalarIsNaN(Distance_r) || (!(Distance_r < totalDistance))) {
        /*  if next is NaN, stop;  */
        /*  if next is further, stop;  */
        exitg1 = true;
      } else {
        totalDistance = Distance_r;
        Distance_l = Distance_l_next - distance;
        pointPair++;
      }
    }
    cost_laneKeeping += Distance_l * Distance_l * weights[6];
  }
  return ((cost_progress + cost_inputs) + cost_laneKeeping) + e * weights[12];
}

/* End of code generation (mpcCostFunction.c) */
