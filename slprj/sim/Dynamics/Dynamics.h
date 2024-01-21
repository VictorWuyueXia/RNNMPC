#ifndef RTW_HEADER_Dynamics_h_
#define RTW_HEADER_Dynamics_h_
#ifndef Dynamics_COMMON_INCLUDES_
#define Dynamics_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "Dynamics_types.h"
#include <string.h>
#include "model_reference_types.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_nonfinite.h"
#include <stddef.h>
typedef struct { real_T oojjxzyok4 ; real_T d55gex5ibo [ 2 ] ; real_T
mdcl3wrwbo [ 2 ] ; real_T k4koj0fcom [ 4 ] ; real_T mwvube2wct [ 2 ] ; real_T
arfpgtsegp [ 2 ] ; real_T g4h22xrh2h [ 3 ] ; real_T bhzqhtdtuu [ 4 ] ; real_T
kmmor0frkj [ 2 ] ; } a5nhmlc3ac ; typedef struct { real_T ghybnrppsd ; real_T
hyfogyvedl ; real_T gjqpjwgw3u [ 2 ] ; real_T apcd2eaeko [ 2 ] ; real_T
lkwnxbugdr ; real_T g4ph0dfu1a ; real_T ntj2eqm4bo [ 2 ] ; real_T eb2i4idyhz
[ 2 ] ; real_T f4c0gsxadk ; real_T aajeczhqaz ; int_T jedpsif1qn ; int_T
np520qsqbo ; int8_T obojwblgr0 ; } jyej4afwv4 ; typedef struct { real_T
djutwq30mj [ 4 ] ; real_T pyisz1wc0x [ 2 ] ; } aws3kc23qp ; typedef struct {
real_T djutwq30mj [ 4 ] ; real_T pyisz1wc0x [ 2 ] ; } f2ptplqnhr ; typedef
struct { boolean_T djutwq30mj [ 4 ] ; boolean_T pyisz1wc0x [ 2 ] ; }
awog0f0js4 ; typedef struct { real_T djutwq30mj [ 4 ] ; real_T pyisz1wc0x [ 2
] ; } mqqif25a5k ; typedef struct { real_T djutwq30mj [ 4 ] ; real_T
pyisz1wc0x [ 2 ] ; } byikvku4y5 ; typedef struct { real_T djutwq30mj [ 4 ] ;
real_T pyisz1wc0x [ 2 ] ; } hv0fwqq4ln ; struct fv1bp5xf2dy_ { real_T P_0 ;
real_T P_1 ; real_T P_2 ; real_T P_3 ; real_T P_4 [ 31 ] ; real_T P_5 ;
real_T P_6 ; real_T P_7 [ 31 ] ; real_T P_8 ; real_T P_9 ; real_T P_10 ;
real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T P_15 ; real_T
P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ; real_T P_21 [
31 ] ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T P_26 ;
real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ; real_T P_31 ; real_T
P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T P_36 ; real_T P_37 [
2 ] ; real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ; real_T P_42 ;
real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 [ 2 ] ; real_T P_47 [ 2
] ; real_T P_48 [ 3 ] ; real_T P_49 ; real_T P_50 ; real_T P_51 ; real_T P_52
; real_T P_53 ; real_T P_54 ; real_T P_55 [ 3 ] ; real_T P_56 ; real_T P_57 ;
real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T P_61 ; real_T P_62 ; real_T
P_63 ; } ; struct dhbpybftwo { struct SimStruct_tag * _mdlRefSfcnS ; struct {
real_T mr_nonContSig0 [ 2 ] ; real_T mr_nonContSig1 [ 2 ] ; real_T
mr_nonContSig2 [ 1 ] ; } NonContDerivMemory ; ssNonContDerivSigInfo
nonContDerivSignal [ 3 ] ; const rtTimingBridge * timingBridge ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 2 ] ; int32_T * vardimsAddress [ 2
] ; RTWLoggingFcnPtr loggingPtrs [ 2 ] ; sysRanDType * systemRan [ 4 ] ;
int_T systemTid [ 4 ] ; } DataMapInfo ; struct { int_T mdlref_GlobalTID [ 4 ]
; time_T tStart ; } Timing ; } ; typedef struct { a5nhmlc3ac rtb ; jyej4afwv4
rtdw ; gifjn5jgpl rtm ; } f0nsmguvnxb ; extern void eoyw0bspsh ( SimStruct *
_mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , int_T mdlref_TID2 ,
int_T mdlref_TID3 , gifjn5jgpl * const im1b3ukp2q , a5nhmlc3ac * localB ,
jyej4afwv4 * localDW , aws3kc23qp * localX , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_Dynamics_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName ,
int_T * retVal ) ; extern mxArray * mr_Dynamics_GetDWork ( const f0nsmguvnxb
* mdlrefDW ) ; extern void mr_Dynamics_SetDWork ( f0nsmguvnxb * mdlrefDW ,
const mxArray * ssDW ) ; extern void mr_Dynamics_RegisterSimStateChecksum (
SimStruct * S ) ; extern mxArray * mr_Dynamics_GetSimStateDisallowedBlocks (
) ; extern const rtwCAPI_ModelMappingStaticInfo * Dynamics_GetCAPIStaticMap (
void ) ; extern void d21xpew1m2 ( gifjn5jgpl * const im1b3ukp2q , jyej4afwv4
* localDW , aws3kc23qp * localX ) ; extern void hxd0rjv3jw ( gifjn5jgpl *
const im1b3ukp2q , jyej4afwv4 * localDW , aws3kc23qp * localX ) ; extern void
gjr2vlvgbm ( jyej4afwv4 * localDW ) ; extern void dut4aenton ( a5nhmlc3ac *
localB , f2ptplqnhr * localXdot ) ; extern void mfwe15whbn ( gifjn5jgpl *
const im1b3ukp2q , jyej4afwv4 * localDW ) ; extern void Dynamics ( gifjn5jgpl
* const im1b3ukp2q , const real_T * kbk4zrsm1h , const real_T * kitgc3oceb ,
real_T mkkas1wk0b [ 2 ] , real_T l1nxc1mhxw [ 2 ] , real_T * g1vgxxaiji ,
real_T * ncu1gcngal , real_T ptlxyeaclt [ 2 ] , real_T atbzzhjgq2 [ 2 ] ,
real_T * ciatxfcoj0 , real_T * iu3htb3iws , a5nhmlc3ac * localB , jyej4afwv4
* localDW , aws3kc23qp * localX ) ; extern void DynamicsTID3 ( a5nhmlc3ac *
localB ) ; extern void irbpoiyy1a ( gifjn5jgpl * const im1b3ukp2q ) ;
#endif
