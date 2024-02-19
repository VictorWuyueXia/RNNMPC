/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_nlmpcmoveCodeGeneration_api.c
 *
 * Code generation for function '_coder_nlmpcmoveCodeGeneration_api'
 *
 */

/* Include files */
#include "_coder_nlmpcmoveCodeGeneration_api.h"
#include "nlmpcmoveCodeGeneration.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4];

static const mxArray *b_emlrt_marshallOut(const struct1_T *u);

static real_T (*c_emlrt_marshallIn(const mxArray *nullptr,
                                   const char_T *identifier))[2];

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);

static real_T (*d_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static const mxArray *d_emlrt_marshallOut(const struct2_T *u);

static void e_emlrt_marshallIn(const mxArray *nullptr, const char_T *identifier,
                               struct1_T *y);

static real_T (*emlrt_marshallIn(const mxArray *nullptr,
                                 const char_T *identifier))[4];

static const mxArray *emlrt_marshallOut(const real_T u[2]);

static void f_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct1_T *y);

static void g_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void h_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void i_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_0 *y);

static real_T j_emlrt_marshallIn(const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void k_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6]);

static void l_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[8]);

static void m_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static real_T (*n_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4];

static real_T (*o_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static void p_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void q_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static real_T r_emlrt_marshallIn(const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void s_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6]);

static void t_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[8]);

static void u_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4]
{
  real_T(*y)[4];
  y = n_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const struct1_T *u)
{
  static const int32_T b_iv[2] = {3, 2};
  static const int32_T b_iv1[2] = {1, 8};
  static const char_T *sv[6] = {"ref", "MVTarget", "Parameters",
                                "X0",  "MV0",      "Slack0"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv2[2];
  int32_T b_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateNumericArray(1, &u->ref->size[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u->ref->size[0]; b_i++) {
    pData[i] = u->ref->data[b_i];
    i++;
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "ref", b_y, 0);
  emlrtSetFieldR2017b(y, 0, "MVTarget", c_emlrt_marshallOut(u->MVTarget), 1);
  c_y = NULL;
  i = 4;
  emlrtAssign(&c_y, emlrtCreateCellArrayR2014a(1, &i));
  d_y = NULL;
  m = emlrtCreateDoubleScalar(u->Parameters.f1);
  emlrtAssign(&d_y, m);
  emlrtSetCell(c_y, 0, d_y);
  e_y = NULL;
  m = emlrtCreateDoubleScalar(u->Parameters.f2);
  emlrtAssign(&e_y, m);
  emlrtSetCell(c_y, 1, e_y);
  f_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 2; b_i++) {
    pData[i] = u->Parameters.f3[3 * b_i];
    pData[i + 1] = u->Parameters.f3[3 * b_i + 1];
    pData[i + 2] = u->Parameters.f3[3 * b_i + 2];
    i += 3;
  }
  emlrtAssign(&f_y, m);
  emlrtSetCell(c_y, 2, f_y);
  g_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv1[0], mxDOUBLE_CLASS,
                              mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 8; b_i++) {
    pData[b_i] = u->Parameters.f4[b_i];
  }
  emlrtAssign(&g_y, m);
  emlrtSetCell(c_y, 3, g_y);
  emlrtSetFieldR2017b(y, 0, "Parameters", c_y, 2);
  h_y = NULL;
  iv2[0] = u->X0->size[0];
  iv2[1] = 4;
  m = emlrtCreateNumericArray(2, &iv2[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u->X0->size[0]; b_i++) {
    pData[i] = u->X0->data[b_i];
    i++;
  }
  for (b_i = 0; b_i < u->X0->size[0]; b_i++) {
    pData[i] = u->X0->data[b_i + u->X0->size[0]];
    i++;
  }
  for (b_i = 0; b_i < u->X0->size[0]; b_i++) {
    pData[i] = u->X0->data[b_i + u->X0->size[0] * 2];
    i++;
  }
  for (b_i = 0; b_i < u->X0->size[0]; b_i++) {
    pData[i] = u->X0->data[b_i + u->X0->size[0] * 3];
    i++;
  }
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, "X0", h_y, 3);
  emlrtSetFieldR2017b(y, 0, "MV0", c_emlrt_marshallOut(u->MV0), 4);
  i_y = NULL;
  m = emlrtCreateDoubleScalar(u->Slack0);
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, "Slack0", i_y, 5);
  return y;
}

static real_T (*c_emlrt_marshallIn(const mxArray *nullptr,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  real_T *pData;
  int32_T b_iv[2];
  int32_T b_i;
  int32_T i;
  u_data = u->data;
  y = NULL;
  b_iv[0] = u->size[0];
  b_iv[1] = 2;
  m = emlrtCreateNumericArray(2, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u->size[0]; b_i++) {
    pData[i] = u_data[b_i];
    i++;
  }
  for (b_i = 0; b_i < u->size[0]; b_i++) {
    pData[i] = u_data[b_i + u->size[0]];
    i++;
  }
  emlrtAssign(&y, m);
  return y;
}

static real_T (*d_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = o_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const struct2_T *u)
{
  static const int32_T b_iv[2] = {11, 2};
  static const int32_T b_iv1[2] = {11, 4};
  static const int32_T i1 = 11;
  static const int32_T i2 = 11;
  static const char_T *sv[8] = {"MVopt", "Xopt",     "Yopt",       "Topt",
                                "Slack", "ExitFlag", "Iterations", "Cost"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 2; b_i++) {
    for (c_i = 0; c_i < 11; c_i++) {
      pData[i + c_i] = u->MVopt[c_i + 11 * b_i];
    }
    i += 11;
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "MVopt", b_y, 0);
  c_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv1[0], mxDOUBLE_CLASS,
                              mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 4; b_i++) {
    for (c_i = 0; c_i < 11; c_i++) {
      pData[i + c_i] = u->Xopt[c_i + 11 * b_i];
    }
    i += 11;
  }
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "Xopt", c_y, 1);
  d_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i1, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 11; b_i++) {
    pData[b_i] = u->Yopt[b_i];
  }
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "Yopt", d_y, 2);
  e_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i2, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 11; b_i++) {
    pData[b_i] = u->Topt[b_i];
  }
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "Topt", e_y, 3);
  f_y = NULL;
  m = emlrtCreateDoubleScalar(u->Slack);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "Slack", f_y, 4);
  g_y = NULL;
  m = emlrtCreateDoubleScalar(u->ExitFlag);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, "ExitFlag", g_y, 5);
  h_y = NULL;
  m = emlrtCreateDoubleScalar(u->Iterations);
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, "Iterations", h_y, 6);
  i_y = NULL;
  m = emlrtCreateDoubleScalar(u->Cost);
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, "Cost", i_y, 7);
  return y;
}

static void e_emlrt_marshallIn(const mxArray *nullptr, const char_T *identifier,
                               struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static real_T (*emlrt_marshallIn(const mxArray *nullptr,
                                 const char_T *identifier))[4]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[2])
{
  static const int32_T i = 0;
  static const int32_T i1 = 2;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[6] = {"ref", "MVTarget", "Parameters",
                                        "X0",  "MV0",      "Slack0"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 6,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "ref";
  g_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0, "ref")),
      &thisId, y->ref);
  thisId.fIdentifier = "MVTarget";
  h_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1, "MVTarget")),
      &thisId, y->MVTarget);
  thisId.fIdentifier = "Parameters";
  i_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
                                                    "Parameters")),
                     &thisId, &y->Parameters);
  thisId.fIdentifier = "X0";
  m_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3, "X0")),
      &thisId, y->X0);
  thisId.fIdentifier = "MV0";
  h_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4, "MV0")),
      &thisId, y->MV0);
  thisId.fIdentifier = "Slack0";
  y->Slack0 = j_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5, "Slack0")),
      &thisId);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  p_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  q_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, cell_0 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T i;
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b = false;
  i = 4;
  emlrtCheckCell(emlrtRootTLSGlobal, parentId, u, 1U, &i, &b);
  thisId.fIdentifier = "1";
  y->f1 = j_emlrt_marshallIn(
      emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 0)), &thisId);
  thisId.fIdentifier = "2";
  y->f2 = j_emlrt_marshallIn(
      emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 1)), &thisId);
  thisId.fIdentifier = "3";
  k_emlrt_marshallIn(
      emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 2)), &thisId,
      y->f3);
  thisId.fIdentifier = "4";
  l_emlrt_marshallIn(
      emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, 3)), &thisId,
      y->f4);
  emlrtDestroyArray(&u);
}

static real_T j_emlrt_marshallIn(const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = r_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void k_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6])
{
  s_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[8])
{
  t_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  u_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*n_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4]
{
  static const int32_T dims = 4;
  real_T(*ret)[4];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*o_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims = 2;
  real_T(*ret)[2];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void p_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims = 10;
  real_T *ret_data;
  int32_T i;
  int32_T i1;
  boolean_T b = true;
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real_T(ret, i1);
  ret_data = ret->data;
  emlrtImportArrayR2015b(emlrtRootTLSGlobal, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {10, 2};
  real_T *ret_data;
  int32_T b_iv[2];
  int32_T i;
  boolean_T bv[2] = {true, false};
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = b_iv[0];
  ret->size[1] = b_iv[1];
  emxEnsureCapacity_real_T(ret, i);
  ret_data = ret->data;
  emlrtImportArrayR2015b(emlrtRootTLSGlobal, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static real_T r_emlrt_marshallIn(const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void s_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6])
{
  static const int32_T dims[2] = {3, 2};
  real_T(*r)[6];
  int32_T i;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[6])emlrtMxGetData(src);
  for (i = 0; i < 6; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[8])
{
  static const int32_T dims[2] = {1, 8};
  real_T(*r)[8];
  int32_T i;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[8])emlrtMxGetData(src);
  for (i = 0; i < 8; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {10, 4};
  real_T *ret_data;
  int32_T b_iv[2];
  int32_T i;
  boolean_T bv[2] = {true, false};
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = b_iv[0];
  ret->size[1] = b_iv[1];
  emxEnsureCapacity_real_T(ret, i);
  ret_data = ret->data;
  emlrtImportArrayR2015b(emlrtRootTLSGlobal, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

void nlmpcmoveCodeGeneration_api(const mxArray *const prhs[3], int32_T nlhs,
                                 const mxArray *plhs[3])
{
  struct1_T onlinedata;
  struct2_T info;
  real_T(*x)[4];
  real_T(*lastMV)[2];
  real_T(*mv)[2];
  mv = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  /* Marshall function inputs */
  x = emlrt_marshallIn(emlrtAlias(prhs[0]), "x");
  lastMV = c_emlrt_marshallIn(emlrtAlias(prhs[1]), "lastMV");
  emxInitStruct_struct1_T(&onlinedata);
  e_emlrt_marshallIn(emlrtAliasP(prhs[2]), "onlinedata", &onlinedata);
  /* Invoke the target function */
  nlmpcmoveCodeGeneration(*x, *lastMV, &onlinedata, *mv, &info);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*mv);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(&onlinedata);
  }
  emxFreeStruct_struct1_T(&onlinedata);
  if (nlhs > 2) {
    plhs[2] = d_emlrt_marshallOut(&info);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (_coder_nlmpcmoveCodeGeneration_api.c) */
