#ifndef __c2_Simulation_h__
#define __c2_Simulation_h__

/* Forward Declarations */
struct SFc2_SimulationInstanceStruct;

/* Type Definitions */
#ifndef typedef_c2_SimulationStackData
#define typedef_c2_SimulationStackData

struct c2_SimulationStackData
{
};

#endif                                 /* typedef_c2_SimulationStackData */

#ifndef struct_SFc2_SimulationInstanceStruct
#define struct_SFc2_SimulationInstanceStruct

struct SFc2_SimulationInstanceStruct
{
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_Simulation;
  uint8_T c2_JITStateAnimation[1];
  uint8_T c2_JITTransitionAnimation[1];
  int32_T c2_IsDebuggerActive;
  int32_T c2_IsSequenceViewerPresent;
  int32_T c2_SequenceViewerOptimization;
  int32_T c2_IsHeatMapPresent;
  void *c2_RuntimeVar;
  uint32_T c2_mlFcnLineNumber;
  void *c2_fcnDataPtrs[9];
  const char_T *c2_dataNames[9];
  uint32_T c2_numFcnVars;
  uint32_T c2_ssIds[9];
  uint32_T c2_statuses[9];
  void *c2_outMexFcns[9];
  void *c2_inMexFcns[9];
  CovrtStateflowInstance *c2_covrtInstance;
  void *c2_fEmlrtCtx;
  real_T (*c2_pos)[3];
  real_T (*c2_newWaypoints)[12];
  real_T (*c2_vel)[3];
  real_T (*c2_waypoints)[12];
};

#endif                                 /* struct_SFc2_SimulationInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_Simulation_get_eml_resolved_functions_info();

/* Function Definitions */
extern void sf_c2_Simulation_get_check_sum(mxArray *plhs[]);
extern void c2_Simulation_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
