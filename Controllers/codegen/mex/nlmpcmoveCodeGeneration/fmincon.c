/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fmincon.c
 *
 * Code generation for function 'fmincon'
 *
 */

/* Include files */
#include "fmincon.h"
#include "driver1.h"
#include "evalObjAndConstrAndDerivatives.h"
#include "factoryConstruct.h"
#include "factoryConstruct1.h"
#include "factoryConstruct2.h"
#include "initActiveSet.h"
#include "nlmpcmoveCodeGeneration.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_emxutil.h"
#include "nlmpcmoveCodeGeneration_internal_types.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "updateWorkingSetForNewQP.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T fmincon(const i_struct_T *fun_workspace_runtimedata,
               const j_struct_T *fun_workspace_userdata, real_T x0[51],
               const emxArray_real_T *Aineq, const emxArray_real_T *bineq,
               const real_T lb[51], const real_T ub[51],
               const i_struct_T *nonlcon_workspace_runtimedata,
               const j_struct_T *nonlcon_workspace_userdata, real_T *exitflag,
               real_T *output_iterations, real_T *output_funcCount,
               char_T output_algorithm[3], real_T *output_constrviolation,
               real_T *output_stepsize, real_T *output_lssteplength,
               real_T *output_firstorderopt)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  c_struct_T TrialState;
  d_struct_T WorkingSet;
  e_struct_T QRManager;
  emxArray_real_T *fscales_cineq_constraint;
  emxArray_real_T *fscales_lineq_constraint;
  emxArray_real_T *varargout_1;
  emxArray_real_T *varargout_3;
  f_struct_T CholManager;
  g_struct_T QPObjective;
  h_struct_T memspace;
  i_coder_internal_stickyStruct FcnEvaluator;
  l_struct_T FiniteDifferences;
  struct_T MeritFunction;
  real_T unusedExpr[2601];
  real_T varargout_4[2040];
  const real_T *Aineq_data;
  const real_T *bineq_data;
  real_T alpha1;
  real_T fval;
  real_T scale;
  real_T *fscales_lineq_constraint_data;
  int32_T i;
  int32_T loop_ub;
  int32_T mConstrMax;
  int32_T mIneq;
  int32_T mNonlinIneq;
  int32_T nVarMax;
  char_T TRANSA;
  boolean_T exitg1;
  bineq_data = bineq->data;
  Aineq_data = Aineq->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  *exitflag = rtInf;
  nVarMax = 0;
  exitg1 = false;
  while ((!exitg1) && (nVarMax < 51)) {
    if (lb[nVarMax] > ub[nVarMax]) {
      *exitflag = -2.0;
      exitg1 = true;
    } else {
      nVarMax++;
    }
  }
  emxInitStruct_struct_T2(&TrialState);
  emxInit_real_T(&varargout_3, 2);
  emxInit_real_T(&varargout_1, 2);
  c_nlmpcmoveCodeGeneration_anonF(nonlcon_workspace_runtimedata->x,
                                  nonlcon_workspace_runtimedata->OutputMin,
                                  nonlcon_workspace_runtimedata->OutputMax,
                                  nonlcon_workspace_runtimedata->Parameters.f1,
                                  nonlcon_workspace_runtimedata->Parameters.f2,
                                  x0, varargout_1, TrialState.cEq, varargout_3,
                                  varargout_4);
  emxFree_real_T(&varargout_3);
  mNonlinIneq = varargout_1->size[0] * varargout_1->size[1];
  emxFree_real_T(&varargout_1);
  mIneq = bineq->size[0] + mNonlinIneq;
  mConstrMax = (mIneq + mIneq) + 223;
  nVarMax = mIneq + 132;
  nVarMax = muIntScalarMax_sint32(nVarMax, mConstrMax);
  if (*exitflag == -2.0) {
    fval = rtInf;
    *output_iterations = 0.0;
    *output_funcCount = 0.0;
    output_algorithm[0] = 's';
    output_algorithm[1] = 'q';
    output_algorithm[2] = 'p';
    *output_constrviolation = rtInf;
    *output_stepsize = rtInf;
    *output_lssteplength = rtInf;
    *output_firstorderopt = rtInf;
  } else {
    int32_T mFixed;
    int32_T mLB;
    int32_T mLinIneq;
    int32_T mUB;
    factoryConstruct(mIneq + 132, mConstrMax, mIneq, mNonlinIneq, &TrialState);
    memcpy(&TrialState.xstarsqp[0], &x0[0], 51U * sizeof(real_T));
    c_emxInitStruct_coder_internal_(&FcnEvaluator);
    FcnEvaluator.next.next.next.next.next.value = mNonlinIneq;
    emxCopyStruct_struct_T(&FcnEvaluator.next.next.next.next.next.next.next.next
                                .value.workspace.runtimedata,
                           fun_workspace_runtimedata);
    emxCopyStruct_struct_T1(&FcnEvaluator.next.next.next.next.next.next.next
                                 .next.value.workspace.userdata,
                            fun_workspace_userdata);
    emxCopyStruct_struct_T(&FcnEvaluator.next.next.next.next.next.next.next
                                .value.workspace.runtimedata,
                           nonlcon_workspace_runtimedata);
    emxCopyStruct_struct_T1(&FcnEvaluator.next.next.next.next.next.next.next
                                 .value.workspace.userdata,
                            nonlcon_workspace_userdata);
    emxInitStruct_struct_T4(&FiniteDifferences);
    b_factoryConstruct(fun_workspace_runtimedata, fun_workspace_userdata,
                       nonlcon_workspace_runtimedata,
                       nonlcon_workspace_userdata, mNonlinIneq, lb, ub,
                       &FiniteDifferences);
    emxInitStruct_struct_T5(&QRManager);
    QRManager.ldq = nVarMax;
    i = QRManager.QR->size[0] * QRManager.QR->size[1];
    QRManager.QR->size[0] = nVarMax;
    QRManager.QR->size[1] = nVarMax;
    emxEnsureCapacity_real_T(QRManager.QR, i);
    i = QRManager.Q->size[0] * QRManager.Q->size[1];
    QRManager.Q->size[0] = nVarMax;
    QRManager.Q->size[1] = nVarMax;
    emxEnsureCapacity_real_T(QRManager.Q, i);
    loop_ub = nVarMax * nVarMax;
    for (i = 0; i < loop_ub; i++) {
      QRManager.Q->data[i] = 0.0;
    }
    i = QRManager.jpvt->size[0];
    QRManager.jpvt->size[0] = nVarMax;
    emxEnsureCapacity_int32_T(QRManager.jpvt, i);
    for (i = 0; i < nVarMax; i++) {
      QRManager.jpvt->data[i] = 0;
    }
    QRManager.mrows = 0;
    QRManager.ncols = 0;
    i = QRManager.tau->size[0];
    QRManager.tau->size[0] = muIntScalarMin_sint32(nVarMax, nVarMax);
    emxEnsureCapacity_real_T(QRManager.tau, i);
    QRManager.minRowCol = 0;
    QRManager.usedPivoting = false;
    emxInitStruct_struct_T6(&CholManager);
    i = CholManager.FMat->size[0] * CholManager.FMat->size[1];
    CholManager.FMat->size[0] = nVarMax;
    CholManager.FMat->size[1] = nVarMax;
    emxEnsureCapacity_real_T(CholManager.FMat, i);
    CholManager.ldm = nVarMax;
    CholManager.ndims = 0;
    CholManager.info = 0;
    CholManager.scaleFactor = 0.0;
    CholManager.ConvexCheck = true;
    CholManager.regTol_ = rtInf;
    CholManager.workspace_ = rtInf;
    CholManager.workspace2_ = rtInf;
    emxInitStruct_struct_T7(&QPObjective);
    i = QPObjective.grad->size[0];
    QPObjective.grad->size[0] = mIneq + 132;
    emxEnsureCapacity_real_T(QPObjective.grad, i);
    i = QPObjective.Hx->size[0];
    QPObjective.Hx->size[0] = mIneq + 131;
    emxEnsureCapacity_real_T(QPObjective.Hx, i);
    QPObjective.maxVar = mIneq + 132;
    QPObjective.beta = 0.0;
    QPObjective.rho = 0.0;
    QPObjective.prev_objtype = 3;
    QPObjective.prev_nvar = 0;
    QPObjective.prev_hasLinear = false;
    QPObjective.gammaScalar = 0.0;
    QPObjective.hasLinear = true;
    QPObjective.nvar = 51;
    QPObjective.objtype = 3;
    emxInitStruct_struct_T8(&memspace);
    i = memspace.workspace_double->size[0] * memspace.workspace_double->size[1];
    memspace.workspace_double->size[0] = nVarMax;
    mLB = mIneq + 132;
    memspace.workspace_double->size[1] = muIntScalarMax_sint32(mLB, 2);
    emxEnsureCapacity_real_T(memspace.workspace_double, i);
    i = memspace.workspace_int->size[0];
    memspace.workspace_int->size[0] = nVarMax;
    emxEnsureCapacity_int32_T(memspace.workspace_int, i);
    i = memspace.workspace_sort->size[0];
    memspace.workspace_sort->size[0] = nVarMax;
    emxEnsureCapacity_int32_T(memspace.workspace_sort, i);
    emxInit_real_T(&fscales_lineq_constraint, 1);
    i = fscales_lineq_constraint->size[0];
    fscales_lineq_constraint->size[0] = bineq->size[0];
    emxEnsureCapacity_real_T(fscales_lineq_constraint, i);
    fscales_lineq_constraint_data = fscales_lineq_constraint->data;
    loop_ub = bineq->size[0];
    for (i = 0; i < loop_ub; i++) {
      fscales_lineq_constraint_data[i] = 1.0;
    }
    emxInit_real_T(&fscales_cineq_constraint, 1);
    i = fscales_cineq_constraint->size[0];
    fscales_cineq_constraint->size[0] = mNonlinIneq;
    emxEnsureCapacity_real_T(fscales_cineq_constraint, i);
    fscales_lineq_constraint_data = fscales_cineq_constraint->data;
    for (i = 0; i < mNonlinIneq; i++) {
      fscales_lineq_constraint_data[i] = 1.0;
    }
    emxInitStruct_struct_T9(&WorkingSet);
    c_factoryConstruct(mIneq, mIneq + 132, mConstrMax, &WorkingSet);
    mLB = 0;
    mUB = 0;
    mFixed = 0;
    for (nVarMax = 0; nVarMax < 51; nVarMax++) {
      boolean_T guard1;
      alpha1 = lb[nVarMax];
      guard1 = false;
      if ((!muDoubleScalarIsInf(alpha1)) && (!muDoubleScalarIsNaN(alpha1))) {
        if (muDoubleScalarAbs(alpha1 - ub[nVarMax]) < 1.0E-6) {
          mFixed++;
          WorkingSet.indexFixed->data[mFixed - 1] = nVarMax + 1;
        } else {
          mLB++;
          WorkingSet.indexLB->data[mLB - 1] = nVarMax + 1;
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        alpha1 = ub[nVarMax];
        if ((!muDoubleScalarIsInf(alpha1)) && (!muDoubleScalarIsNaN(alpha1))) {
          mUB++;
          WorkingSet.indexUB->data[mUB - 1] = nVarMax + 1;
        }
      }
    }
    mLinIneq = bineq->size[0];
    loop_ub = mIneq + mLB;
    nVarMax = ((loop_ub + mUB) + mFixed) + 40;
    WorkingSet.mConstr = nVarMax;
    WorkingSet.mConstrOrig = nVarMax;
    WorkingSet.mConstrMax = mConstrMax;
    WorkingSet.sizes[0] = mFixed;
    WorkingSet.sizes[1] = 40;
    WorkingSet.sizes[2] = mIneq;
    WorkingSet.sizes[3] = mLB;
    WorkingSet.sizes[4] = mUB;
    WorkingSet.sizesPhaseOne[0] = mFixed;
    WorkingSet.sizesPhaseOne[1] = 40;
    WorkingSet.sizesPhaseOne[2] = mIneq;
    WorkingSet.sizesPhaseOne[3] = mLB + 1;
    WorkingSet.sizesPhaseOne[4] = mUB;
    WorkingSet.sizesRegularized[0] = mFixed;
    WorkingSet.sizesRegularized[1] = 40;
    WorkingSet.sizesRegularized[2] = mIneq;
    WorkingSet.sizesRegularized[3] = loop_ub + 80;
    WorkingSet.sizesRegularized[4] = mUB;
    WorkingSet.sizesRegPhaseOne[0] = mFixed;
    WorkingSet.sizesRegPhaseOne[1] = 40;
    WorkingSet.sizesRegPhaseOne[2] = mIneq;
    WorkingSet.sizesRegPhaseOne[3] = loop_ub + 81;
    WorkingSet.sizesRegPhaseOne[4] = mUB;
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 40;
    WorkingSet.isActiveIdxRegPhaseOne[3] = mIneq;
    WorkingSet.isActiveIdxRegPhaseOne[4] = mLB;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (nVarMax = 0; nVarMax < 5; nVarMax++) {
      WorkingSet.sizesNormal[nVarMax] = WorkingSet.sizes[nVarMax];
      WorkingSet.isActiveIdxRegPhaseOne[nVarMax + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[nVarMax];
    }
    for (i = 0; i < 6; i++) {
      WorkingSet.isActiveIdx[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
      WorkingSet.isActiveIdxNormal[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 40;
    WorkingSet.isActiveIdxRegPhaseOne[3] = mIneq;
    WorkingSet.isActiveIdxRegPhaseOne[4] = mLB + 1;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (nVarMax = 0; nVarMax < 5; nVarMax++) {
      WorkingSet.isActiveIdxRegPhaseOne[nVarMax + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[nVarMax];
    }
    for (i = 0; i < 6; i++) {
      WorkingSet.isActiveIdxPhaseOne[i] = WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 40;
    WorkingSet.isActiveIdxRegPhaseOne[3] = mIneq;
    WorkingSet.isActiveIdxRegPhaseOne[4] = loop_ub + 80;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (nVarMax = 0; nVarMax < 5; nVarMax++) {
      WorkingSet.isActiveIdxRegPhaseOne[nVarMax + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[nVarMax];
    }
    for (i = 0; i < 6; i++) {
      WorkingSet.isActiveIdxRegularized[i] =
          WorkingSet.isActiveIdxRegPhaseOne[i];
    }
    WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
    WorkingSet.isActiveIdxRegPhaseOne[2] = 40;
    WorkingSet.isActiveIdxRegPhaseOne[3] = mIneq;
    WorkingSet.isActiveIdxRegPhaseOne[4] = loop_ub + 81;
    WorkingSet.isActiveIdxRegPhaseOne[5] = mUB;
    for (nVarMax = 0; nVarMax < 5; nVarMax++) {
      WorkingSet.isActiveIdxRegPhaseOne[nVarMax + 1] +=
          WorkingSet.isActiveIdxRegPhaseOne[nVarMax];
    }
    if (mIneq > 0) {
      for (nVarMax = 0; nVarMax < mLinIneq; nVarMax++) {
        i = WorkingSet.nVar;
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          WorkingSet.Aineq->data[loop_ub + WorkingSet.ldA * nVarMax] =
              Aineq_data[nVarMax + mLinIneq * loop_ub];
        }
      }
    }
    for (nVarMax = 0; nVarMax < mLB; nVarMax++) {
      TrialState.xstarsqp[WorkingSet.indexLB->data[nVarMax] - 1] =
          muDoubleScalarMax(
              TrialState.xstarsqp[WorkingSet.indexLB->data[nVarMax] - 1],
              lb[WorkingSet.indexLB->data[nVarMax] - 1]);
    }
    for (nVarMax = 0; nVarMax < mUB; nVarMax++) {
      TrialState.xstarsqp[WorkingSet.indexUB->data[nVarMax] - 1] =
          muDoubleScalarMin(
              TrialState.xstarsqp[WorkingSet.indexUB->data[nVarMax] - 1],
              ub[WorkingSet.indexUB->data[nVarMax] - 1]);
    }
    for (nVarMax = 0; nVarMax < mFixed; nVarMax++) {
      TrialState.xstarsqp[WorkingSet.indexFixed->data[nVarMax] - 1] =
          ub[WorkingSet.indexFixed->data[nVarMax] - 1];
    }
    TrialState.sqpFval = evalObjAndConstrAndDerivatives(
        mNonlinIneq, nonlcon_workspace_runtimedata,
        &FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace,
        TrialState.xstarsqp, TrialState.grad, TrialState.cIneq,
        TrialState.iNonIneq0, TrialState.cEq, TrialState.iNonEq0,
        WorkingSet.Aineq, TrialState.iNonIneq0, WorkingSet.ldA, WorkingSet.Aeq,
        TrialState.iNonEq0, WorkingSet.ldA, &nVarMax);
    TrialState.FunctionEvaluations = FiniteDifferences.numEvals + 1;
    if (bineq->size[0] > 0) {
      n_t = (ptrdiff_t)bineq->size[0];
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, (real_T *)&bineq_data[0], &incx_t, &TrialState.cIneq->data[0],
            &incy_t);
      alpha1 = 1.0;
      scale = -1.0;
      TRANSA = 'T';
      m_t = (ptrdiff_t)51;
      n_t = (ptrdiff_t)bineq->size[0];
      lda_t = (ptrdiff_t)WorkingSet.ldA;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dgemv(&TRANSA, &m_t, &n_t, &alpha1, &WorkingSet.Aineq->data[0], &lda_t,
            &TrialState.xstarsqp[0], &incx_t, &scale,
            &TrialState.cIneq->data[0], &incy_t);
    }
    updateWorkingSetForNewQP(x0, &WorkingSet, mIneq, TrialState.mNonlinIneq,
                             TrialState.cIneq, TrialState.mNonlinEq,
                             TrialState.cEq, mLB, lb, mUB, ub, mFixed);
    initActiveSet(&WorkingSet);
    MeritFunction.initFval = TrialState.sqpFval;
    MeritFunction.penaltyParam = 1.0;
    MeritFunction.threshold = 0.0001;
    MeritFunction.nPenaltyDecreases = 0;
    MeritFunction.linearizedConstrViol = 0.0;
    alpha1 = 0.0;
    for (nVarMax = 0; nVarMax < 40; nVarMax++) {
      alpha1 += muDoubleScalarAbs(TrialState.cEq[nVarMax]);
    }
    MeritFunction.initConstrViolationEq = alpha1;
    alpha1 = 0.0;
    for (nVarMax = 0; nVarMax < mIneq; nVarMax++) {
      if (TrialState.cIneq->data[nVarMax] > 0.0) {
        alpha1 += TrialState.cIneq->data[nVarMax];
      }
    }
    MeritFunction.initConstrViolationIneq = alpha1;
    MeritFunction.phi = 0.0;
    MeritFunction.phiPrimePlus = 0.0;
    MeritFunction.phiFullStep = 0.0;
    MeritFunction.feasRelativeFactor = 0.0;
    MeritFunction.nlpPrimalFeasError = 0.0;
    MeritFunction.nlpDualFeasError = 0.0;
    MeritFunction.nlpComplError = 0.0;
    MeritFunction.firstOrderOpt = 0.0;
    MeritFunction.hasObjective = true;
    b_driver(bineq, lb, ub, &TrialState, &MeritFunction, &FcnEvaluator,
             &FiniteDifferences, &memspace, &WorkingSet, &QRManager,
             &CholManager, &QPObjective, fscales_lineq_constraint,
             fscales_cineq_constraint, unusedExpr);
    emxFreeStruct_struct_T9(&WorkingSet);
    emxFree_real_T(&fscales_cineq_constraint);
    emxFree_real_T(&fscales_lineq_constraint);
    emxFreeStruct_struct_T8(&memspace);
    emxFreeStruct_struct_T7(&QPObjective);
    emxFreeStruct_struct_T6(&CholManager);
    emxFreeStruct_struct_T5(&QRManager);
    emxFreeStruct_struct_T4(&FiniteDifferences);
    k_emxFreeStruct_coder_internal_(&FcnEvaluator);
    fval = TrialState.sqpFval;
    *exitflag = TrialState.sqpExitFlag;
    *output_iterations = TrialState.sqpIterations;
    *output_funcCount = TrialState.FunctionEvaluations;
    output_algorithm[0] = 's';
    output_algorithm[1] = 'q';
    output_algorithm[2] = 'p';
    *output_constrviolation = MeritFunction.nlpPrimalFeasError;
    alpha1 = 0.0;
    scale = 3.3121686421112381E-170;
    for (nVarMax = 0; nVarMax < 51; nVarMax++) {
      real_T absxk;
      x0[nVarMax] = TrialState.xstarsqp[nVarMax];
      absxk = muDoubleScalarAbs(TrialState.delta_x->data[nVarMax]);
      if (absxk > scale) {
        real_T t;
        t = scale / absxk;
        alpha1 = alpha1 * t * t + 1.0;
        scale = absxk;
      } else {
        real_T t;
        t = absxk / scale;
        alpha1 += t * t;
      }
    }
    *output_stepsize = scale * muDoubleScalarSqrt(alpha1);
    *output_lssteplength = TrialState.steplength;
    *output_firstorderopt = MeritFunction.firstOrderOpt;
  }
  emxFreeStruct_struct_T2(&TrialState);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

/* End of code generation (fmincon.c) */
