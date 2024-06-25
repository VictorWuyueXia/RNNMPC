#ifndef __c4_Simulation_h__
#define __c4_Simulation_h__

/* Forward Declarations */
struct SFc4_SimulationInstanceStruct;

/* Type Definitions */
#ifndef typedef_c4_SimulationStackData
#define typedef_c4_SimulationStackData

struct c4_SimulationStackData
{
};

#endif                                 /* typedef_c4_SimulationStackData */

#ifndef struct_SFc4_SimulationInstanceStruct
#define struct_SFc4_SimulationInstanceStruct

struct SFc4_SimulationInstanceStruct
{
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_Simulation;
  uint8_T c4_JITStateAnimation[1];
  uint8_T c4_JITTransitionAnimation[1];
  int32_T c4_IsDebuggerActive;
  int32_T c4_IsSequenceViewerPresent;
  int32_T c4_SequenceViewerOptimization;
  int32_T c4_IsHeatMapPresent;
  void *c4_RuntimeVar;
  uint32_T c4_mlFcnLineNumber;
  void *c4_fcnDataPtrs[2];
  const char_T *c4_dataNames[2];
  uint32_T c4_numFcnVars;
  uint32_T c4_ssIds[2];
  uint32_T c4_statuses[2];
  void *c4_outMexFcns[2];
  void *c4_inMexFcns[2];
  CovrtStateflowInstance *c4_covrtInstance;
  void *c4_fEmlrtCtx;
  real_T (*c4_x)[12];
  real_T (*c4_b_x)[12];
};

#endif                                 /* struct_SFc4_SimulationInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_Simulation_get_eml_resolved_functions_info();

/* Function Definitions */
extern void sf_c4_Simulation_get_check_sum(mxArray *plhs[]);
extern void c4_Simulation_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
