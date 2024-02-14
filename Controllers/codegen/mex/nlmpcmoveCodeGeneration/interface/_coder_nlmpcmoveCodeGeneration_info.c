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
      "789ced59dd8ed240182d6635c6446d62e2136cbc321bf7c244f74efe04232c59d855b2dd"
      "b0fd19a4383fd84e2bf812be82975e7a69bcf029bcf2ca4791761828"
      "0d93428b5dd9cc97c0f4cb69bf733a744ebe0e4aa1de28288a724f61f1fd311befce7275"
      "36de5096238e1766e3ed58cee3a6b2b7741dc73fcf4693600ac69425",
      "5847607ea545908d754c3b9311501ce012e8032b44fa36041d1b817634690619aa46a079"
      "1240c1716900ccf76d0f29cec05d2884d1643e1fdf04f7bbb7e67cbc"
      "16cc871ac3cfeb958b7da453a81b0e21745fa38440838c353432c30f86d36f447c502216"
      "78093070746a137c800aef00ad7ad80cb29a8e2d08a2fac719f53f4c",
      "d0cf711f0c6c1382f264fadbd9a6db6bdb681428e13a2e53ea888748078ff9739c928fd7"
      "3f4de0e3f879e5a274a49dbac071b533dba4c4d1cac4f410c0d4d55a"
      "0e1902737a70d26c365a25ad347dc81d0261707290af9eb403a424cfdbfd35ef233e2ece"
      "672bf5b0f73b84f2e2fbf1e0d1cf3cf9785c155f5eebefad63380e9c",
      "20d4406f86b4f9bc6b76277671a1a395c093a44311e479d5df751f1e65d47f27413fc789"
      "47475ea883e557e5bf597faf7a021fc733f9ef62b242cf8deabf14e8"
      "db55df05d55f7ff2e4e371dd7df769d37f824e5ed42a871fcffae36ebfd279d66e94af8f"
      "ef7e155cbfee3c9605f5d5189ee4bb1eb5a1ab7d0addb7377d59e87b",
      "81e5ba54a7a0e213e805ae1bd5bdeb7d2fe7bd25d4c1108b7846944ff6bdabc7c5f9b2ef"
      "cd834ff6bddba99fd57f4b82fa6a0cdfd07fd1b46f02af749318b68e"
      "db810bcf3a28e9bfd9f8a4fffe1b3ee9bf2ca4ff6e563fabff1605f5d5189eaeff652fb0"
      "45e261cb5dd6bdabfb0d697d57ee37acd62ff71bf2e193fb0ddba9ff",
      "9fee372cf5bbc7e132664b58fa6d3a3ee9b7dbe5937ecb42faed66f5b3fa6d4d505f8de1"
      "1bf92d3186acbffde0e956f0ff9a796c040bddf681f4db747cd26fb7"
      "cb27fd9685f4dbcdea7f115cbfee3c1e09eaab313c4d7f5bc77dc217aef4d9747cd267b7"
      "cb277d9685f4d9f5eaff055d95d799",
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
                emlrtMxCreateString("fjZGUNdpVQQ8A3zPLg8MTC"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_nlmpcmoveCodeGeneration_info.c) */
