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
  const char_T *data[10] = {
      "789ced5acb6edb4614a58a24280a346116edb69b2c8b204065d8c9ae7ad9522cd9b1ec24"
      "9219387c8c24dae40c4d0e15dbab00f9802cbac932cb2cb3ec32dfd1"
      "6dba29fa1325351a596433e0d37a10738178323ee43d9733e4c1f59d2b949aed92200877"
      "05627fb6c9f8e3742e4ec7ef84a085f1d274bc1b9a53bb2ddc0adc47",
      "f1f7d3514510830b4c265036c1ec4e0d993a94213ebcb4806003071963a04d90816e8043"
      "dd04ddf949c79f998d396836f121ffffd51150cfbaae29d823e73a42"
      "637e327b8ecf8ce7bd15733d7619eb2186f0e366fdd50353c686acd808e1071246c850d0"
      "85645aeae41f34bc9f261a832ad2c03680c096b18ee043b33404b8e1",
      "42d59fedc85033c07cfc1719e3ff39227e8a8fc148570d50bbf4f64e579d93ae6e5a7e24"
      "348ed729e3081b2b0e6ab3f738251ff57f10c147f1e3faabea13e9c8"
      "01b623fdae796faaee606f67902deddbe814a8d8910e3a9df67e55aa7a6fb88d0cc3bfd2"
      "9f7f7bc51e9ac1e778cd88f35ecce7088fd7d77f3f19fbda5fa545f2",
      "6dfcfa8fb0483e6acbe2cbfafdfdc4e01343f86f5be797e6f640dd51e04bfdac0ce1b3e1"
      "e8f15c1cfb113c5171088cf9a2fcafbb0e5b19e3ff21227e8a23175b"
      "ee240e325f96fe7e4ac947fd3722f8289e5e7faf57cad75caeb7f9f0515b57bd8d9bef3c"
      "da196c8e515b19f6b5f3b39e023af87cd3ae73bd2d8adede0bcdc3f1",
      "53dc0bae8a9c59206b9bef1e46f0513cbddeaad36592424b4632dea2eaefd7fdbf8545f2"
      "512bbafeb6cadae0a0e2964dd41b1eb54757630bb6361a5c7f57457f"
      "df668cff9788f829feedbfa24f5ab28a145d5e9e1e7f49c947fd1f47f0513ceffac36ce5"
      "a68588a2eaf2bb3ffe1516c947ade8ba5ced6ff46b4fb5766fd0dcc2",
      "f5e7b25bd96c1d548aa3cb1f19f7c75dc7c70cff62088fd26517eb86235d4dd4f9c453e2"
      "7e05b9507368f970edf360ca7787c94f104fed5c15f33c78d5f596e7"
      "c1c4781e9ccc7f51bee7acefc3fd88e7a0b865a3a10d1ce7848635fdfda2f45843ae327f"
      "ee9775ff9e33f982780efbf7bfa52b725d98eb31b1bcf578bb31e8a0",
      "a17e858e36f7caf253755739c7a735aec7aba6c759f362569f8b18c27568b9784e8cd755"
      "87bb4cbe209ec3be0597ace07508aec3c4f2d6e1ad5eabfba2592f5b"
      "7ba0567e7361ef6a3da75ca0bc38ebf97a8de15f0ce189ea102a8203d72f0d3b58c6a03e"
      "46863b2906088bdfff9bea475b96fef27eb49be1e3fd11c4783f5a32",
      "ffebaabf6f33c6bd2ae7726975f84b463e7e2e77b37cfc5c8e183f974be63fab1e5718fe"
      "c5109e4e8f49af2939a20bc69db50eb1acbee0b4facbfb82c3d7f3bc"
      "77117cbc2f381fff2b9af79ade270b688ab437f982f3adf7729d0d5ec775361e1fd75962"
      "5c6793f9ffc0b83fee3a6e30fc8b213c91ce22e57492cf0af9e92aef",
      "2f0b5ec7fbcbd2f1f1733462bcbf2c99ff15ad1b04f259ff2b0e9fc370dd4dc6c775f766"
      "f8b8ee12e3ba9bccff47c6fd71d7f109c3bf18c2d3e86e130e50de7a"
      "cbeb07c1eb78fd201e1faf1f10e3f58378feff0318a5fd5d",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 19920U, &nameCaptureInfo);
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
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString(
          "C:\\MATLAB\\R2023b\\toolbox\\mpc\\mpc\\nlmpcmoveCodeGeneration.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739085.83038194443));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2485118 (R2023b) Update 6"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("DMI2vpuEwnHbixyxsVaAfH"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_nlmpcmoveCodeGeneration_info.c) */
