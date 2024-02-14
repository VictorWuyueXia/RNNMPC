/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver.h
 *
 * Code generation for function 'driver'
 *
 */

#pragma once

/* Include files */
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void driver(const real_T H[2601], const emxArray_real_T *f,
            c_struct_T *solution, h_struct_T *memspace, d_struct_T *workingset,
            e_struct_T *qrmanager, f_struct_T *cholmanager,
            g_struct_T *objective, const m_struct_T *options,
            m_struct_T *runTimeOptions);

/* End of code generation (driver.h) */
