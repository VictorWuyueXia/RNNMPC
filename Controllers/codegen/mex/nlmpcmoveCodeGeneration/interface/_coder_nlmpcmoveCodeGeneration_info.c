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
  const char_T *data[11] = {
      "789ced5abf6fdb4614a68ba4280a246187b463176f05dc0091613ba37ed89662c98e1d3b"
      "95c3d4e18f93449bbca3c9a3621b1dfc1f64c9902948b64c81c7a2e8"
      "90bfa163a6a0ff43f78aa44e16991c2892d24922ee01367dfec8f73dbe133f3c3d3e61a1"
      "5a5f1004e1b610d8e77a70bcd55f8bfde33742d8a2f842ff783bb226",
      "7653b811ba8ee02ffb4715410cce70b080b20906576ac8d4a10cf1e3730b08367090d105"
      "9a8fb474033cd64db037bc68782b737d081a2c3cc8fbbbd401eac99e"
      "6b0a76c7b98ed0185e0ceee38a72bf3746ccc716251f62047f5aad3c5b34656cc88a8d10"
      "5e9430428682ce24d352fd1f68f47e9ba80b4a48031b00025bc63a82",
      "4be6421be07517aade6a53869a0186e33fcb18ff8f31f113bc0b3aba6a80f2796fef74d5"
      "39dad34dcb8b84c4f13c651c51a3c5418cf0fd99928ff8df8fe123f8"
      "d3cab3d20369df01b6231de82a46b65446aa6b02881d69c746c740edfdb1db68d4774a52"
      "a9f721b7916178277bebaf276dc914e2f37667c4fb881eafcfffce3f",
      "2eaa9f7c8815df9af4b7cb928fd8b4f8b23e7f77297c6204bfbf7a7a6e6eb4d44d05fea6"
      "9f14207cd4eeac0dc5b113c31317874059b3f23fef3a6c658cfffb98"
      "f8098e5c6cb97e1cc17a5afa9b75bfaa317c04cfa4bfd7c9f2357738fee794f8c6a513bf"
      "30d65de9eebb4b967cc4e6557747ad7bee6db656baa8aeb40fb5d393",
      "a6021af874c5ae70ddcd8beede89aca3f113bc175c09398340e6b6ee7d12c347f04cbaab"
      "f6332545b2d65361567a719fb1fe6e5dfd5363c9472ceffa5b2b68ad"
      "dda25b3051b3bd5fef5c742d585b5ee7fa3b2bfa7b9931fe9f63e227f8d7bf4a1fd56415"
      "29ba3c3d3dfe98928ff8ff3d868fe013e8430c92e715c7ac74e457c6",
      "babcf4eaaf3f58f211cbbb2e970e970fcb0fb57ab3555dc59503d92daed4768bf9d1e5b7"
      "94eb47cde31ac5bf18c1e374d9c5bae14817be3a1ff594f8b0885ca8"
      "395f7c9f9dd73a98f07d4be50f1007dbae8a791dccebe0301fb1bceb6ddeebe0bc3ccf59"
      "3f0f3fc4dc07c12d1bb56de0384724a6feff59e9b1865c65f8fddfc7",
      "8c7c4d2a5f181fcffe7d913de6fde102635dfe20ffb7ca928f58de757963bdd5406dfd02"
      "edaf6c17e487ea96728a8fcb5c97674d97b3d6c7b4b9173182ebd072"
      "f190284f4b8fb3eedb01952f8c8f67dfc25963d98f605d1fbf59fbe95f967cc4f2aec3ab"
      "cddade936aa5606d8372e1c599bda5359d428eeae3f794eb47cd6399",
      "e25f8ce089fa112a822dd76b113b58c6a0d24586eb370504f6fb3fa9f9b469e92f9f4f9b"
      "0c1f9f4f0b8ccfa725f33faffa7b9931ee59793f37adbe047f3f3759"
      "3efe7e2e30fe7e2e99ffac7a5ca4f81723783a3d0e064f835775e1b8b3f621a635279c56"
      "7faf32f2f139e1f1f2f139e1c0f89c7032ff335aff9abde716903a69",
      "db7f8c834798eb6d3a3eaeb7e3e5e37a1b18d7db64fe5f53ae1f358fcb14ff62044fa4b7"
      "4839f6eb5b617cfacae7cec2e7f1b9b3747c7cee2c303e7796ccff8c"
      "f6114275adf708934289eb6e3a3eaebb93e1e3ba1b18d7dd64fedf52ae1f358f0f28fec5"
      "089e4677abb085c6adb7bc8f103e8ff71192f1f13e4260bc8f309aff",
      "ff01b1c30fcf",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 19960U, &nameCaptureInfo);
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
                emlrtMxCreateString("DMI2vpuEwnHbixyxsVaAfH"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_nlmpcmoveCodeGeneration_info.c) */
