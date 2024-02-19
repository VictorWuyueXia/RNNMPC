/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_nlmpcmoveCodeGeneration_info.c
 *
 * Code generation for function 'nlmpcmoveCodeGeneration'
 *
 */

/* Include files */
#include "_coder_nlmpcmoveCodeGeneration_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[7] = {
      "789ced59cb6ed340147550410809f08a2fe812451548a5eab2ee2bd03c68525aa8abd41e"
      "4f5ab7f308f6386a11ffc02fb064c9127e8325df003b3e80d893491c"
      "2b232776704935574ac657c7bee778e239ba9e68a54ab5a469da238dc7b7a77c7c38c8f5"
      "c178471b8f245e1a8cf713b988bbdad2d87502ff341801250c5e319e",
      "100bc3e1950ec52eb1086b5d77a1e6419fa21e7422a4e322d872316cc6935a98e1ed1834"
      "4c42283c36ce21b86c0658f3cefd9142144f86f3f15572bf4b53cec7"
      "9e643ef4047e5cd93a59c6164396ed51ca964d4629b2e99589bb20fa10d4ffc6b4070dea"
      "c01d48a067319792322e9d41b61d101066bb1671108cebbfcaa9ff49",
      "8a7e81f7e0b90b10dcbceeff762ef0db4d1777432542c769461dc990e910317c8e33f289"
      "fa07297c023fde3a31d6cd031f7abef9c6058c7ae62605018684f966"
      "c3a31710f40ff66bb56ac3308dfe43ee5184c293c37cf2a495b1963e6f8fa7bc8fe4383a"
      "9fafd4dff6cf082a8aefe3afefed22f944dc145f51eb6fc75fb97cbe",
      "f2eac83e38ba3e7cf67aad76d8da5f35463a1a293c693a34495e54fd45f7e16e4efd0f52"
      "f40b9c06ac1b443a787e53fe9bf7f7aaa4f0093c97ff8e262bf2dcb8"
      "fe5389be79f9c46abb58df2dfff9512f924fc46df7ddb3ea9edf59bb806f8f9ae09d0dbc"
      "17c8eb54776e8fef7e915c3fed3c6e4aeaeb093ccd7703e622dffc10",
      "b96fbbffb2d00942cbf599c5e0568fa22074ddb8ee45ef7b05ef3da90e8e3834b0e37caa"
      "ef9d3c8ece577d6f117caaef9d4ffdbcfe6b48eaeb097c46ffc5fdbe"
      "09beb400b55d8b3443171e7450ca7ff3f129fffd377cca7f7928ff9dad7e5effdd90d4d7"
      "1378b6fe97bfc06ed08038feb8ee45dd6fc8eabb6abf61b27eb5df50",
      "0c9fda6f984ffdff74bf61acdfad47cb982f61e5b7d9f894dfce974ff92d0fe5b7b3d5cf"
      "ebb7bb92fa7a029fc96fa97dc1fbdbf781e584ffaf81ba1d2e74b707"
      "95df66e3537e3b5f3ee5b73c94dfce56ffb3e4fa69e7715d525f4fe059fadb0ae950b170"
      "95cf66e3533e3b5f3ee5b33c94cf4e57ff2fa542dae6",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 11472U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  boolean_T *inputsData0;
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  inputsData0 = emlrtMxGetLogicals(xInputs);
  inputsData0[0] = true;
  emlrtSetField(xEntryPoints, 0, "Name",
                emlrtMxCreateString("nlmpcmoveCodeGeneration"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath",
                emlrtMxCreateString("C:\\Program "
                                    "Files\\MATLAB\\R2023b\\toolbox\\mpc\\mpc\\"
                                    "nlmpcmoveCodeGeneration.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739085.6637152778));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2428915 (R2023b) Update 4"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("IroVQ5kBoPyh4j8aAvZFaB"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_nlmpcmoveCodeGeneration_info.c) */
