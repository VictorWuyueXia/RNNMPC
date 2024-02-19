/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vehicleDynamics_Simple.c
 *
 * Code generation for function 'vehicleDynamics_Simple'
 *
 */

/* Include files */
#include "vehicleDynamics_Simple.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void vehicleDynamics_Simple(const real_T state[4], const real_T input[2],
                            real_T Ts, real_T L, real_T nextState[4])
{
  real_T absx;
  real_T b_absx;
  real_T b_x;
  real_T x;
  real_T x_tmp;
  int8_T n;
  /*  Unpack the state and input */
  /*  [x_pos, y_pos, yaw_direction, speed] */
  /*  Vehicle dynamics equations - continuous */
  if (muDoubleScalarIsInf(state[2]) || muDoubleScalarIsNaN(state[2])) {
    x = rtNaN;
    absx = rtNaN;
  } else {
    x_tmp = muDoubleScalarRem(state[2], 360.0);
    x = x_tmp;
    absx = muDoubleScalarAbs(x_tmp);
    b_absx = absx;
    if (absx > 180.0) {
      if (x_tmp > 0.0) {
        x = x_tmp - 360.0;
      } else {
        x = x_tmp + 360.0;
      }
      b_absx = muDoubleScalarAbs(x);
    }
    if (b_absx <= 45.0) {
      x *= 0.017453292519943295;
      n = 0;
    } else if (b_absx <= 135.0) {
      if (x > 0.0) {
        x = 0.017453292519943295 * (x - 90.0);
        n = 1;
      } else {
        x = 0.017453292519943295 * (x + 90.0);
        n = -1;
      }
    } else if (x > 0.0) {
      x = 0.017453292519943295 * (x - 180.0);
      n = 2;
    } else {
      x = 0.017453292519943295 * (x + 180.0);
      n = -2;
    }
    if (n == 0) {
      x = muDoubleScalarCos(x);
    } else if (n == 1) {
      x = -muDoubleScalarSin(x);
    } else if (n == -1) {
      x = muDoubleScalarSin(x);
    } else {
      x = -muDoubleScalarCos(x);
    }
    if (absx > 180.0) {
      if (x_tmp > 0.0) {
        x_tmp -= 360.0;
      } else {
        x_tmp += 360.0;
      }
      absx = muDoubleScalarAbs(x_tmp);
    }
    if (absx <= 45.0) {
      x_tmp *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (x_tmp > 0.0) {
        x_tmp = 0.017453292519943295 * (x_tmp - 90.0);
        n = 1;
      } else {
        x_tmp = 0.017453292519943295 * (x_tmp + 90.0);
        n = -1;
      }
    } else if (x_tmp > 0.0) {
      x_tmp = 0.017453292519943295 * (x_tmp - 180.0);
      n = 2;
    } else {
      x_tmp = 0.017453292519943295 * (x_tmp + 180.0);
      n = -2;
    }
    if (n == 0) {
      absx = muDoubleScalarSin(x_tmp);
    } else if (n == 1) {
      absx = muDoubleScalarCos(x_tmp);
    } else if (n == -1) {
      absx = -muDoubleScalarCos(x_tmp);
    } else {
      absx = -muDoubleScalarSin(x_tmp);
    }
  }
  if (muDoubleScalarIsInf(input[0]) || muDoubleScalarIsNaN(input[0])) {
    b_x = rtNaN;
  } else {
    b_x = muDoubleScalarRem(input[0], 360.0);
    b_absx = muDoubleScalarAbs(b_x);
    if (b_absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }
      b_absx = muDoubleScalarAbs(b_x);
    }
    if (b_absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (b_absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = 0.017453292519943295 * (b_x - 90.0);
        n = 1;
      } else {
        b_x = 0.017453292519943295 * (b_x + 90.0);
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = 0.017453292519943295 * (b_x - 180.0);
      n = 2;
    } else {
      b_x = 0.017453292519943295 * (b_x + 180.0);
      n = -2;
    }
    b_x = muDoubleScalarTan(b_x);
    if ((n == 1) || (n == -1)) {
      x_tmp = 1.0 / b_x;
      b_x = -(1.0 / b_x);
      if (muDoubleScalarIsInf(b_x) && (n == 1)) {
        b_x = x_tmp;
      }
    }
  }
  /*  Euler's method */
  /*  Return the next state */
  nextState[0] = state[0] + state[3] * x * Ts;
  nextState[1] = state[1] + state[3] * absx * Ts;
  nextState[2] = state[2] + state[3] * b_x / L * Ts;
  nextState[3] = state[3] + input[1] * Ts;
}

/* End of code generation (vehicleDynamics_Simple.c) */
