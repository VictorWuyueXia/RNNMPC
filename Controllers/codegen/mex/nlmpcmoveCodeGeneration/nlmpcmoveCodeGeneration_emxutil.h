/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nlmpcmoveCodeGeneration_emxutil.h
 *
 * Code generation for function 'nlmpcmoveCodeGeneration_emxutil'
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
void c_emxFreeStruct_anonymous_funct(anonymous_function *pStruct);

void c_emxFreeStruct_coder_internal_(b_coder_internal_stickyStruct *pStruct);

void c_emxInitStruct_anonymous_funct(anonymous_function *pStruct);

void c_emxInitStruct_coder_internal_(i_coder_internal_stickyStruct *pStruct);

void d_emxFreeStruct_coder_internal_(coder_internal_stickyStruct *pStruct);

void d_emxInitStruct_coder_internal_(h_coder_internal_stickyStruct *pStruct);

void e_emxFreeStruct_coder_internal_(c_coder_internal_stickyStruct *pStruct);

void e_emxInitStruct_coder_internal_(g_coder_internal_stickyStruct *pStruct);

void emxCopyMatrix_real_T(real_T dst[4], const real_T src[4]);

void emxCopyMatrix_real_T1(real_T dst[2], const real_T src[2]);

void emxCopyMatrix_real_T3(real_T dst[40], const real_T src[40]);

void emxCopyMatrix_real_T4(real_T dst[20], const real_T src[20]);

void emxCopyStruct_struct_T(i_struct_T *dst, const i_struct_T *src);

void emxCopyStruct_struct_T1(j_struct_T *dst, const j_struct_T *src);

void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src);

void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                 int32_T oldNumel);

void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int32_T oldNumel);

void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int32_T oldNumel);

void emxEnsureCapacity_ptrdiff_t(emxArray_ptrdiff_t *emxArray,
                                 int32_T oldNumel);

void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);

void emxFreeStruct_struct1_T(struct1_T *pStruct);

void emxFreeStruct_struct_T(i_struct_T *pStruct);

void emxFreeStruct_struct_T1(j_struct_T *pStruct);

void emxFreeStruct_struct_T2(c_struct_T *pStruct);

void emxFreeStruct_struct_T3(k_struct_T *pStruct);

void emxFreeStruct_struct_T4(l_struct_T *pStruct);

void emxFreeStruct_struct_T5(e_struct_T *pStruct);

void emxFreeStruct_struct_T6(f_struct_T *pStruct);

void emxFreeStruct_struct_T7(g_struct_T *pStruct);

void emxFreeStruct_struct_T8(h_struct_T *pStruct);

void emxFreeStruct_struct_T9(d_struct_T *pStruct);

void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

void emxFree_int32_T(emxArray_int32_T **pEmxArray);

void emxFree_int8_T(emxArray_int8_T **pEmxArray);

void emxFree_ptrdiff_t(emxArray_ptrdiff_t **pEmxArray);

void emxFree_real_T(emxArray_real_T **pEmxArray);

void emxInitStruct_struct1_T(struct1_T *pStruct);

void emxInitStruct_struct_T(i_struct_T *pStruct);

void emxInitStruct_struct_T1(j_struct_T *pStruct);

void emxInitStruct_struct_T2(c_struct_T *pStruct);

void emxInitStruct_struct_T3(k_struct_T *pStruct);

void emxInitStruct_struct_T4(l_struct_T *pStruct);

void emxInitStruct_struct_T5(e_struct_T *pStruct);

void emxInitStruct_struct_T6(f_struct_T *pStruct);

void emxInitStruct_struct_T7(g_struct_T *pStruct);

void emxInitStruct_struct_T8(h_struct_T *pStruct);

void emxInitStruct_struct_T9(d_struct_T *pStruct);

void emxInit_boolean_T(emxArray_boolean_T **pEmxArray);

void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions);

void emxInit_int8_T(emxArray_int8_T **pEmxArray, int32_T numDimensions);

void emxInit_ptrdiff_t(emxArray_ptrdiff_t **pEmxArray);

void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);

void f_emxFreeStruct_coder_internal_(d_coder_internal_stickyStruct *pStruct);

void f_emxInitStruct_coder_internal_(f_coder_internal_stickyStruct *pStruct);

void g_emxFreeStruct_coder_internal_(e_coder_internal_stickyStruct *pStruct);

void g_emxInitStruct_coder_internal_(e_coder_internal_stickyStruct *pStruct);

void h_emxFreeStruct_coder_internal_(f_coder_internal_stickyStruct *pStruct);

void h_emxInitStruct_coder_internal_(d_coder_internal_stickyStruct *pStruct);

void i_emxFreeStruct_coder_internal_(g_coder_internal_stickyStruct *pStruct);

void i_emxInitStruct_coder_internal_(c_coder_internal_stickyStruct *pStruct);

void j_emxFreeStruct_coder_internal_(h_coder_internal_stickyStruct *pStruct);

void j_emxInitStruct_coder_internal_(b_coder_internal_stickyStruct *pStruct);

void k_emxFreeStruct_coder_internal_(i_coder_internal_stickyStruct *pStruct);

void k_emxInitStruct_coder_internal_(coder_internal_stickyStruct *pStruct);

/* End of code generation (nlmpcmoveCodeGeneration_emxutil.h) */
