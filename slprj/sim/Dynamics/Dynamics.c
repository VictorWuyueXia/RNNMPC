#include "Dynamics.h"
#include "rtwtypes.h"
#include "Dynamics_private.h"
#include "mwmathutil.h"
#include "Dynamics_capi.h"
#include "look1_binlcpw.h"
#include "look1_binlxpw.h"
#include <string.h>
#include "rt_nonfinite.h"
#define kl1s4helq1 (0.1)
static RegMdlInfo rtMdlInfo_Dynamics [ 46 ] = { { "f0nsmguvnxb" ,
MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * ) "Dynamics" } , {
"kpfeekvzgl" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"Dynamics" } , { "hv0fwqq4ln" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 ,
( void * ) "Dynamics" } , { "byikvku4y5" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "Dynamics" } , { "mqqif25a5k" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "Dynamics" } , {
"awog0f0js4" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"Dynamics" } , { "f2ptplqnhr" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 ,
( void * ) "Dynamics" } , { "aws3kc23qp" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "Dynamics" } , { "gk5avfnshu" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "Dynamics" } , {
"ntbjand42c" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"Dynamics" } , { "elg5z0fx5t" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 ,
( void * ) "Dynamics" } , { "nrpuymu3ae" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "Dynamics" } , { "jyej4afwv4" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "Dynamics" } , {
"a5nhmlc3ac" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"Dynamics" } , { "e4tjlbsql4" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 ,
( void * ) "Dynamics" } , { "irbpoiyy1a" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "Dynamics" } , { "cp0brpakub" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "Dynamics" } , {
"dut4aenton" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"Dynamics" } , { "mfwe15whbn" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 ,
( void * ) "Dynamics" } , { "hxd0rjv3jw" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "Dynamics" } , { "d21xpew1m2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "Dynamics" } , {
"eoyw0bspsh" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"Dynamics" } , { "gjr2vlvgbm" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 ,
( void * ) "Dynamics" } , { "lmnzwitjw1" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "Dynamics" } , { "Dynamics" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , { "mjq30lm5yr" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "Dynamics" } , {
"kr1lxa3h33x" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"Dynamics" } , { "kr1lxa3h33" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 ,
( void * ) "Dynamics" } , { "dhbpybftwo" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , - 1 , ( void * ) "Dynamics" } , { "gifjn5jgpl" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "Dynamics" } , {
"BusVehicleStateDerivative" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } ,
{ "BusVehicleState" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , {
"mr_Dynamics_GetSimStateDisallowedBlocks" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "Dynamics" } , {
"mr_Dynamics_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "Dynamics" } , {
"mr_Dynamics_cacheBitFieldToCellArrayWithOffset" , MDL_INFO_ID_MODEL_FCN_NAME
, 0 , - 1 , ( void * ) "Dynamics" } , {
"mr_Dynamics_restoreDataFromMxArrayWithOffset" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "Dynamics" } , {
"mr_Dynamics_cacheDataToMxArrayWithOffset" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "Dynamics" } , { "mr_Dynamics_extractBitFieldFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "Dynamics" } , {
"mr_Dynamics_cacheBitFieldToMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 ,
( void * ) "Dynamics" } , { "mr_Dynamics_restoreDataFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "Dynamics" } , {
"mr_Dynamics_cacheDataAsMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , (
void * ) "Dynamics" } , { "mr_Dynamics_RegisterSimStateChecksum" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "Dynamics" } , {
"mr_Dynamics_SetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * )
"Dynamics" } , { "mr_Dynamics_GetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , -
1 , ( void * ) "Dynamics" } , { "Dynamics.h" , MDL_INFO_MODEL_FILENAME , 0 ,
- 1 , ( NULL ) } , { "Dynamics.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , (
void * ) "Dynamics" } } ; fv1bp5xf2dy fv1bp5xf2d = { 0.0 , 0.3 , 0.1 , 0.1 ,
{ 0.0 , 0.03 , 0.06 , 0.09 , 0.12 , 0.15 , 0.18 , 0.21 , 0.24 , 0.27 , 0.3 ,
0.32999999999999996 , 0.36 , 0.39 , 0.42 , 0.45 , 0.48000000000000004 , 0.51
, 0.54 , 0.57000000000000006 , 0.60000000000000009 , 0.63 , 0.66 ,
0.69000000000000006 , 0.72 , 0.75 , 0.78 , 0.81 , 0.84000000000000008 , 0.87
, 0.9 } , 12000.0 , 11000.0 , { 0.0 , 0.01 , 0.02 , 0.03 , 0.04 , 0.05 , 0.06
, 0.07 , 0.08 , 0.09 , 0.1 , 0.11 , 0.12 , 0.13 , 0.14 , 0.15 ,
0.15999999999999998 , 0.16999999999999998 , 0.18 , 0.19 , 0.19999999999999998
, 0.21 , 0.21999999999999997 , 0.22999999999999998 , 0.24 , 0.25 , 0.26 ,
0.27 , 0.27999999999999997 , 0.29 , 0.3 } , 5000.0 , 4000.0 , 2.0 , 2.0 ,
101325.0 , 287.058 , 0.0 , 0.0 , 273.0 , 0.0 , 0.0 , 1.5 , 1.5 , { 0.0 , 0.01
, 0.02 , 0.03 , 0.04 , 0.05 , 0.06 , 0.07 , 0.08 , 0.09 , 0.1 , 0.11 , 0.12 ,
0.13 , 0.14 , 0.15 , 0.15999999999999998 , 0.16999999999999998 , 0.18 , 0.19
, 0.19999999999999998 , 0.21 , 0.21999999999999997 , 0.22999999999999998 ,
0.24 , 0.25 , 0.26 , 0.27 , 0.27999999999999997 , 0.29 , 0.3 } , 9.81 , 0.35
, 0.0 , 0.0 , 2000.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.01 , 0.0 , 1.0E+6 ,
1.0E+6 , 0.0 , { 1.4 , 1.4 } , 8.0 , - 8.0 , 0.0 , 0.0 , 8.0 , - 15.0 ,
2000.0 , 0.5 , { 0.0 , 0.0 } , { - 1.0 , 1.0 } , { 4.0 , 4.0 , 0.0 } ,
0.52359877559829882 , - 0.52359877559829882 , 0.0 , 0.52359877559829882 , -
0.52359877559829882 , 0.0 , { 0.0 , 0.0 , 1.0 } , 1.0 , 0.0 , 0.2 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 } ; static void cs1nf14dfv ( real_T Ftire_x , real_T
Ftire_y , real_T b_Fxtire_sat , real_T b_Fytire_sat , real_T * Ftire_xs ,
real_T * Ftire_ys ) ; static void mh4l4ok42i ( real_T u [ 2 ] ) ; static void
cs1nf14dfv ( real_T Ftire_x , real_T Ftire_y , real_T b_Fxtire_sat , real_T
b_Fytire_sat , real_T * Ftire_xs , real_T * Ftire_ys ) { real_T Ftire_mag ;
real_T Ftire_y_max ; real_T c_a ; real_T theta_Ftire ; theta_Ftire =
muDoubleScalarAtan2 ( Ftire_x , Ftire_y ) ; Ftire_y_max = muDoubleScalarCos (
theta_Ftire ) ; Ftire_mag = b_Fxtire_sat * Ftire_y_max ; theta_Ftire =
muDoubleScalarSin ( theta_Ftire ) ; c_a = b_Fytire_sat * theta_Ftire ;
Ftire_mag = b_Fxtire_sat * b_Fytire_sat / muDoubleScalarSqrt ( Ftire_mag *
Ftire_mag + c_a * c_a ) ; theta_Ftire *= Ftire_mag ; Ftire_y_max *= Ftire_mag
; * Ftire_xs = Ftire_x ; if ( muDoubleScalarAbs ( Ftire_x ) >
muDoubleScalarAbs ( theta_Ftire ) ) { * Ftire_xs = theta_Ftire ; } * Ftire_ys
= Ftire_y ; if ( muDoubleScalarAbs ( Ftire_y ) > muDoubleScalarAbs (
Ftire_y_max ) ) { * Ftire_ys = Ftire_y_max ; } } static void mh4l4ok42i (
real_T u [ 2 ] ) { int32_T b_ii ; int32_T idx ; int8_T ii_data [ 2 ] ;
boolean_T exitg1 ; idx = 0 ; b_ii = 0 ; exitg1 = false ; while ( ( ! exitg1 )
&& ( b_ii < 2 ) ) { if ( u [ b_ii ] < 0.0 ) { idx ++ ; ii_data [ idx - 1 ] =
( int8_T ) ( b_ii + 1 ) ; if ( idx >= 2 ) { exitg1 = true ; } else { b_ii ++
; } } else { b_ii ++ ; } } if ( idx < 1 ) { b_ii = 0 ; } else { b_ii = idx ;
} for ( idx = 0 ; idx < b_ii ; idx ++ ) { u [ ii_data [ idx ] - 1 ] = 0.0 ; }
} void d21xpew1m2 ( gifjn5jgpl * const im1b3ukp2q , jyej4afwv4 * localDW ,
aws3kc23qp * localX ) { boolean_T tmp ; localDW -> ghybnrppsd = fv1bp5xf2d .
P_40 ; localDW -> jedpsif1qn = 1 ; if ( rtmIsFirstInitCond ( im1b3ukp2q ) ) {
localX -> djutwq30mj [ 0 ] = 0.0 ; localX -> djutwq30mj [ 1 ] = 0.0 ; localX
-> djutwq30mj [ 2 ] = 0.0 ; localX -> djutwq30mj [ 3 ] = 0.0 ; tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp = (
slIsRapidAcceleratorSimulating ( ) ? ssGetGlobalInitialStatesAvailable (
im1b3ukp2q -> _mdlRefSfcnS ) : simTgtGlobalInitialStatesAvailable (
im1b3ukp2q -> _mdlRefSfcnS ) ) ; localDW -> jedpsif1qn = ! tmp ; } else {
localDW -> jedpsif1qn = 1 ; } localX -> pyisz1wc0x [ 0 ] = 0.0 ; localX ->
pyisz1wc0x [ 1 ] = 0.0 ; } localDW -> hyfogyvedl = fv1bp5xf2d . P_51 ;
localDW -> np520qsqbo = 1 ; if ( rtmIsFirstInitCond ( im1b3ukp2q ) ) { tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp = (
slIsRapidAcceleratorSimulating ( ) ? ssGetGlobalInitialStatesAvailable (
im1b3ukp2q -> _mdlRefSfcnS ) : simTgtGlobalInitialStatesAvailable (
im1b3ukp2q -> _mdlRefSfcnS ) ) ; localDW -> np520qsqbo = ! tmp ; } else {
localDW -> np520qsqbo = 1 ; } } } void hxd0rjv3jw ( gifjn5jgpl * const
im1b3ukp2q , jyej4afwv4 * localDW , aws3kc23qp * localX ) { boolean_T tmp ;
localDW -> ghybnrppsd = fv1bp5xf2d . P_40 ; localDW -> jedpsif1qn = 1 ; if (
rtmIsFirstInitCond ( im1b3ukp2q ) ) { localX -> djutwq30mj [ 0 ] = 0.0 ;
localX -> djutwq30mj [ 1 ] = 0.0 ; localX -> djutwq30mj [ 2 ] = 0.0 ; localX
-> djutwq30mj [ 3 ] = 0.0 ; tmp = slIsRapidAcceleratorSimulating ( ) ; if (
tmp ) { tmp = ( slIsRapidAcceleratorSimulating ( ) ?
ssGetGlobalInitialStatesAvailable ( im1b3ukp2q -> _mdlRefSfcnS ) :
simTgtGlobalInitialStatesAvailable ( im1b3ukp2q -> _mdlRefSfcnS ) ) ; localDW
-> jedpsif1qn = ! tmp ; } else { localDW -> jedpsif1qn = 1 ; } localX ->
pyisz1wc0x [ 0 ] = 0.0 ; localX -> pyisz1wc0x [ 1 ] = 0.0 ; } localDW ->
hyfogyvedl = fv1bp5xf2d . P_51 ; localDW -> np520qsqbo = 1 ; if (
rtmIsFirstInitCond ( im1b3ukp2q ) ) { tmp = slIsRapidAcceleratorSimulating (
) ; if ( tmp ) { tmp = ( slIsRapidAcceleratorSimulating ( ) ?
ssGetGlobalInitialStatesAvailable ( im1b3ukp2q -> _mdlRefSfcnS ) :
simTgtGlobalInitialStatesAvailable ( im1b3ukp2q -> _mdlRefSfcnS ) ) ; localDW
-> np520qsqbo = ! tmp ; } else { localDW -> np520qsqbo = 1 ; } } } void
gjr2vlvgbm ( jyej4afwv4 * localDW ) { localDW -> obojwblgr0 = 0 ; } void
Dynamics ( gifjn5jgpl * const im1b3ukp2q , const real_T * kbk4zrsm1h , const
real_T * kitgc3oceb , real_T mkkas1wk0b [ 2 ] , real_T l1nxc1mhxw [ 2 ] ,
real_T * g1vgxxaiji , real_T * ncu1gcngal , real_T ptlxyeaclt [ 2 ] , real_T
atbzzhjgq2 [ 2 ] , real_T * ciatxfcoj0 , real_T * iu3htb3iws , a5nhmlc3ac *
localB , jyej4afwv4 * localDW , aws3kc23qp * localX ) { real_T cj1r12vfrz [ 6
] ; real_T FzCalc [ 2 ] ; real_T B1 ; real_T B1_tmp ; real_T B1_tmp_p ;
real_T B2 ; real_T Fx_f ; real_T Fx_f_tmp ; real_T Fy_f ; real_T Fy_r ;
real_T arfpgtsegp_e ; real_T arfpgtsegp_p ; real_T b0o2vlxoze_idx_0 ; real_T
b0o2vlxoze_idx_1 ; real_T b0o2vlxoze_idx_2 ; real_T b0o2vlxoze_idx_3 ; real_T
eyvxamlnsw_idx_0 ; real_T eyvxamlnsw_idx_1 ; real_T fxersvq2si_idx_0 ; real_T
fxersvq2si_idx_1 ; real_T fxersvq2si_p ; real_T iqs5s3xmxa ; real_T
mkeuoososk ; real_T p44sgkb2xu ; real_T pimtbedm2x_idx_0 ; real_T
pimtbedm2x_idx_1 ; real_T pimtbedm2x_idx_2 ; int32_T iterCnt ; if (
rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 , 0 ) )
{ mkeuoososk = * kbk4zrsm1h - localDW -> ghybnrppsd ; if ( mkeuoososk >
fv1bp5xf2d . P_38 * kl1s4helq1 ) { iqs5s3xmxa = fv1bp5xf2d . P_38 *
kl1s4helq1 + localDW -> ghybnrppsd ; } else if ( mkeuoososk < fv1bp5xf2d .
P_39 * kl1s4helq1 ) { iqs5s3xmxa = fv1bp5xf2d . P_39 * kl1s4helq1 + localDW
-> ghybnrppsd ; } else { iqs5s3xmxa = * kbk4zrsm1h ; } localDW -> ghybnrppsd
= iqs5s3xmxa ; if ( ! ( * kbk4zrsm1h > fv1bp5xf2d . P_41 ) ) { iqs5s3xmxa = *
kbk4zrsm1h ; } if ( iqs5s3xmxa > fv1bp5xf2d . P_42 ) { iqs5s3xmxa =
fv1bp5xf2d . P_42 ; } else if ( iqs5s3xmxa < fv1bp5xf2d . P_43 ) { iqs5s3xmxa
= fv1bp5xf2d . P_43 ; } iqs5s3xmxa = fv1bp5xf2d . P_44 * iqs5s3xmxa *
fv1bp5xf2d . P_45 ; } if ( ssIsModeUpdateTimeStep ( im1b3ukp2q ->
_mdlRefSfcnS ) ) { if ( localDW -> jedpsif1qn != 0 ) { localX -> djutwq30mj [
0 ] = localB -> k4koj0fcom [ 0 ] ; localX -> djutwq30mj [ 1 ] = localB ->
k4koj0fcom [ 1 ] ; localX -> djutwq30mj [ 2 ] = localB -> k4koj0fcom [ 2 ] ;
localX -> djutwq30mj [ 3 ] = localB -> k4koj0fcom [ 3 ] ; } b0o2vlxoze_idx_0
= localX -> djutwq30mj [ 0 ] ; b0o2vlxoze_idx_1 = localX -> djutwq30mj [ 1 ]
; b0o2vlxoze_idx_2 = localX -> djutwq30mj [ 2 ] ; b0o2vlxoze_idx_3 = localX
-> djutwq30mj [ 3 ] ; } else { b0o2vlxoze_idx_0 = localX -> djutwq30mj [ 0 ]
; b0o2vlxoze_idx_1 = localX -> djutwq30mj [ 1 ] ; b0o2vlxoze_idx_2 = localX
-> djutwq30mj [ 2 ] ; b0o2vlxoze_idx_3 = localX -> djutwq30mj [ 3 ] ; }
muDoubleScalarSinCos ( b0o2vlxoze_idx_2 , & mkeuoososk , & p44sgkb2xu ) ;
fxersvq2si_p = b0o2vlxoze_idx_0 - ( p44sgkb2xu * localB -> g4h22xrh2h [ 0 ] +
mkeuoososk * localB -> g4h22xrh2h [ 1 ] ) ; fxersvq2si_idx_0 = fxersvq2si_p ;
pimtbedm2x_idx_0 = fxersvq2si_p * fxersvq2si_p ; fxersvq2si_p =
b0o2vlxoze_idx_1 - ( p44sgkb2xu * localB -> g4h22xrh2h [ 1 ] - mkeuoososk *
localB -> g4h22xrh2h [ 0 ] ) ; fxersvq2si_idx_1 = fxersvq2si_p ;
pimtbedm2x_idx_1 = fxersvq2si_p * fxersvq2si_p ; fxersvq2si_p = fv1bp5xf2d .
P_54 - localB -> g4h22xrh2h [ 2 ] ; p44sgkb2xu = ( pimtbedm2x_idx_0 +
pimtbedm2x_idx_1 ) + fxersvq2si_p * fxersvq2si_p ; if ( rtmIsMajorTimeStep (
im1b3ukp2q ) ) { if ( localDW -> obojwblgr0 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( im1b3ukp2q -> _mdlRefSfcnS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( im1b3ukp2q ->
_mdlRefSfcnS ) ; localDW -> obojwblgr0 = 0 ; } mkeuoososk =
muDoubleScalarSqrt ( p44sgkb2xu ) ; } else if ( p44sgkb2xu < 0.0 ) {
mkeuoososk = - muDoubleScalarSqrt ( muDoubleScalarAbs ( p44sgkb2xu ) ) ;
localDW -> obojwblgr0 = 1 ; } else { mkeuoososk = muDoubleScalarSqrt (
p44sgkb2xu ) ; } p44sgkb2xu = mkeuoososk * mkeuoososk ; cj1r12vfrz [ 0 ] =
fv1bp5xf2d . P_1 ; mkeuoososk = muDoubleScalarAtan2 ( fxersvq2si_idx_1 ,
fxersvq2si_idx_0 ) ; cj1r12vfrz [ 1 ] = look1_binlcpw ( mkeuoososk ,
fv1bp5xf2d . P_21 , fv1bp5xf2d . P_4 , 30U ) ; cj1r12vfrz [ 2 ] = fv1bp5xf2d
. P_2 ; cj1r12vfrz [ 3 ] = look1_binlxpw ( mkeuoososk , fv1bp5xf2d . P_47 ,
fv1bp5xf2d . P_46 , 1U ) ; fxersvq2si_idx_0 = muDoubleScalarTanh ( fv1bp5xf2d
. P_48 [ 0 ] * fxersvq2si_idx_0 ) ; fxersvq2si_idx_1 = muDoubleScalarTanh (
fv1bp5xf2d . P_48 [ 1 ] * fxersvq2si_idx_1 ) ; cj1r12vfrz [ 4 ] =
fxersvq2si_idx_0 * fv1bp5xf2d . P_3 ; cj1r12vfrz [ 5 ] = look1_binlxpw (
mkeuoososk , fv1bp5xf2d . P_21 , fv1bp5xf2d . P_7 , 30U ) ; mkeuoososk = 0.5
* fv1bp5xf2d . P_0 * fv1bp5xf2d . P_12 / fv1bp5xf2d . P_13 ; for ( iterCnt =
0 ; iterCnt < 6 ; iterCnt ++ ) { cj1r12vfrz [ iterCnt ] = p44sgkb2xu *
cj1r12vfrz [ iterCnt ] / fv1bp5xf2d . P_16 * mkeuoososk ; } pimtbedm2x_idx_0
= fv1bp5xf2d . P_19 + fv1bp5xf2d . P_20 ; fxersvq2si_idx_0 = - ( (
fxersvq2si_idx_0 - fv1bp5xf2d . P_55 [ 0 ] ) * cj1r12vfrz [ 0 ] ) ;
pimtbedm2x_idx_1 = - ( cj1r12vfrz [ 4 ] * pimtbedm2x_idx_0 ) ;
fxersvq2si_idx_1 = - ( ( fxersvq2si_idx_1 - fv1bp5xf2d . P_55 [ 1 ] ) *
cj1r12vfrz [ 1 ] ) ; pimtbedm2x_idx_2 = - ( cj1r12vfrz [ 5 ] *
pimtbedm2x_idx_0 ) ; fxersvq2si_p = - ( ( muDoubleScalarTanh ( fv1bp5xf2d .
P_48 [ 2 ] * fxersvq2si_p ) - fv1bp5xf2d . P_55 [ 2 ] ) * cj1r12vfrz [ 2 ] )
; if ( rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 ,
0 ) ) { mkeuoososk = * kitgc3oceb - localDW -> hyfogyvedl ; if ( mkeuoososk >
fv1bp5xf2d . P_49 * kl1s4helq1 ) { p44sgkb2xu = fv1bp5xf2d . P_49 *
kl1s4helq1 + localDW -> hyfogyvedl ; } else if ( mkeuoososk < fv1bp5xf2d .
P_50 * kl1s4helq1 ) { p44sgkb2xu = fv1bp5xf2d . P_50 * kl1s4helq1 + localDW
-> hyfogyvedl ; } else { p44sgkb2xu = * kitgc3oceb ; } localDW -> hyfogyvedl
= p44sgkb2xu ; if ( p44sgkb2xu > fv1bp5xf2d . P_52 ) { localB -> oojjxzyok4 =
fv1bp5xf2d . P_52 ; } else if ( p44sgkb2xu < fv1bp5xf2d . P_53 ) { localB ->
oojjxzyok4 = fv1bp5xf2d . P_53 ; } else { localB -> oojjxzyok4 = p44sgkb2xu ;
} } p44sgkb2xu = muDoubleScalarSin ( b0o2vlxoze_idx_2 ) ; mkeuoososk =
muDoubleScalarCos ( b0o2vlxoze_idx_2 ) ; localB -> kmmor0frkj [ 0 ] =
b0o2vlxoze_idx_0 * mkeuoososk - b0o2vlxoze_idx_1 * p44sgkb2xu ; localB ->
kmmor0frkj [ 1 ] = b0o2vlxoze_idx_0 * p44sgkb2xu + b0o2vlxoze_idx_1 *
mkeuoososk ; if ( ssIsModeUpdateTimeStep ( im1b3ukp2q -> _mdlRefSfcnS ) ) {
if ( localDW -> np520qsqbo != 0 ) { localX -> pyisz1wc0x [ 0 ] = localB ->
mwvube2wct [ 0 ] ; localX -> pyisz1wc0x [ 1 ] = localB -> mwvube2wct [ 1 ] ;
} eyvxamlnsw_idx_0 = localX -> pyisz1wc0x [ 0 ] ; eyvxamlnsw_idx_1 = localX
-> pyisz1wc0x [ 1 ] ; } else { eyvxamlnsw_idx_0 = localX -> pyisz1wc0x [ 0 ]
; eyvxamlnsw_idx_1 = localX -> pyisz1wc0x [ 1 ] ; } if ( rtmIsMajorTimeStep (
im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 , 0 ) ) { localB ->
d55gex5ibo [ 0 ] = iqs5s3xmxa ; localB -> d55gex5ibo [ 1 ] = 0.0 ; localB ->
mdcl3wrwbo [ 0 ] = iqs5s3xmxa ; localB -> mdcl3wrwbo [ 1 ] = 0.0 ; }
mkeuoososk = muDoubleScalarAbs ( b0o2vlxoze_idx_0 ) ; iqs5s3xmxa = mkeuoososk
; if ( mkeuoososk < fv1bp5xf2d . P_32 ) { mkeuoososk /= fv1bp5xf2d . P_32 ;
iqs5s3xmxa = 2.0 * fv1bp5xf2d . P_32 / ( 3.0 - mkeuoososk * mkeuoososk ) ; }
p44sgkb2xu = muDoubleScalarTanh ( 4.0 * b0o2vlxoze_idx_0 ) ; mkeuoososk =
muDoubleScalarAtan2 ( fv1bp5xf2d . P_19 * b0o2vlxoze_idx_3 + b0o2vlxoze_idx_1
, iqs5s3xmxa ) - localB -> oojjxzyok4 * p44sgkb2xu ; p44sgkb2xu =
muDoubleScalarAtan2 ( b0o2vlxoze_idx_1 - fv1bp5xf2d . P_20 * b0o2vlxoze_idx_3
, iqs5s3xmxa ) - 0.0 * p44sgkb2xu ; FzCalc [ 0 ] = 0.0 ; FzCalc [ 1 ] = 0.0 ;
iqs5s3xmxa = muDoubleScalarSin ( localB -> oojjxzyok4 ) ; Fx_f_tmp =
muDoubleScalarCos ( localB -> oojjxzyok4 ) ; arfpgtsegp_p = localB ->
arfpgtsegp [ 0 ] ; arfpgtsegp_e = localB -> arfpgtsegp [ 1 ] ; for ( iterCnt
= 0 ; iterCnt < 6 ; iterCnt ++ ) { if ( iterCnt == 0 ) { B1_tmp = fv1bp5xf2d
. P_26 * fv1bp5xf2d . P_22 ; B1 = ( ( ( fxersvq2si_idx_0 - ( 0.0 -
b0o2vlxoze_idx_3 * 0.0 ) * fv1bp5xf2d . P_26 ) - B1_tmp * 0.0 ) * fv1bp5xf2d
. P_23 - 0.0 * fv1bp5xf2d . P_23 ) - pimtbedm2x_idx_1 ; B2 = - fxersvq2si_p -
B1_tmp ; FzCalc [ 0 ] = - ( - ( B1 - B2 * fv1bp5xf2d . P_20 ) /
pimtbedm2x_idx_0 ) ; FzCalc [ 1 ] = - ( ( B2 * fv1bp5xf2d . P_19 + B1 ) /
pimtbedm2x_idx_0 ) ; mh4l4ok42i ( FzCalc ) ; } Fy_f = - fv1bp5xf2d . P_5 *
mkeuoososk * arfpgtsegp_p * FzCalc [ 0 ] / fv1bp5xf2d . P_8 ; Fy_r = -
fv1bp5xf2d . P_6 * p44sgkb2xu * arfpgtsegp_e * FzCalc [ 1 ] / fv1bp5xf2d .
P_8 ; cs1nf14dfv ( localB -> d55gex5ibo [ 0 ] , Fy_f , fv1bp5xf2d . P_34 *
FzCalc [ 0 ] / fv1bp5xf2d . P_8 , fv1bp5xf2d . P_35 * FzCalc [ 0 ] /
fv1bp5xf2d . P_8 , & Fx_f , & B1_tmp ) ; cs1nf14dfv ( localB -> mdcl3wrwbo [
0 ] , Fy_r , fv1bp5xf2d . P_34 * FzCalc [ 1 ] / fv1bp5xf2d . P_8 , fv1bp5xf2d
. P_35 * FzCalc [ 1 ] / fv1bp5xf2d . P_8 , & B1 , & B2 ) ; Fx_f = Fx_f *
Fx_f_tmp - B1_tmp * iqs5s3xmxa ; Fy_f = - Fx_f * iqs5s3xmxa + Fy_f * Fx_f_tmp
; B1 -= B2 * 0.0 ; Fy_r += - B1 * 0.0 ; B1_tmp = b0o2vlxoze_idx_1 *
b0o2vlxoze_idx_3 ; B1_tmp_p = fv1bp5xf2d . P_26 * fv1bp5xf2d . P_22 * 0.0 ;
B1 = ( ( ( Fx_f + B1 ) - B1_tmp_p ) + fxersvq2si_idx_0 ) / fv1bp5xf2d . P_26
+ B1_tmp ; B2 = ( ( Fy_f + Fy_r ) + fxersvq2si_idx_1 ) / fv1bp5xf2d . P_26 +
- b0o2vlxoze_idx_0 * b0o2vlxoze_idx_3 ; Fy_f = ( ( fv1bp5xf2d . P_19 * Fy_f -
fv1bp5xf2d . P_20 * Fy_r ) + pimtbedm2x_idx_2 ) / fv1bp5xf2d . P_9 ; Fy_r = (
( ( fxersvq2si_idx_0 - ( B1 - B1_tmp ) * fv1bp5xf2d . P_26 ) - B1_tmp_p ) *
fv1bp5xf2d . P_23 - 0.0 * fv1bp5xf2d . P_23 ) - pimtbedm2x_idx_1 ; Fx_f = -
fxersvq2si_p - fv1bp5xf2d . P_26 * fv1bp5xf2d . P_22 ; FzCalc [ 0 ] = - ( - (
Fy_r - Fx_f * fv1bp5xf2d . P_20 ) / pimtbedm2x_idx_0 ) ; FzCalc [ 1 ] = - ( (
Fx_f * fv1bp5xf2d . P_19 + Fy_r ) / pimtbedm2x_idx_0 ) ; mh4l4ok42i ( FzCalc
) ; } localB -> bhzqhtdtuu [ 0 ] = B1 ; localB -> bhzqhtdtuu [ 1 ] = B2 ;
localB -> bhzqhtdtuu [ 2 ] = b0o2vlxoze_idx_3 ; localB -> bhzqhtdtuu [ 3 ] =
Fy_f ; if ( ( rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit (
im1b3ukp2q , 1 , 0 ) ) && ( rtmIsMajorTimeStep ( im1b3ukp2q ) &&
rtmIsSampleHit ( im1b3ukp2q , 2 , 0 ) ) ) { localDW -> gjqpjwgw3u [ 0 ] =
localB -> kmmor0frkj [ 0 ] ; localDW -> gjqpjwgw3u [ 1 ] = localB ->
kmmor0frkj [ 1 ] ; } if ( rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit
( im1b3ukp2q , 2 , 0 ) ) { mkkas1wk0b [ 0 ] = localDW -> gjqpjwgw3u [ 0 ] ;
mkkas1wk0b [ 1 ] = localDW -> gjqpjwgw3u [ 1 ] ; } if ( ( rtmIsMajorTimeStep
( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 1 , 0 ) ) && (
rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 , 0 ) )
) { localDW -> apcd2eaeko [ 0 ] = ( b0o2vlxoze_idx_0 * b0o2vlxoze_idx_3 + B2
) * 0.10197162129779282 * 9.8066500000000012 ; localDW -> apcd2eaeko [ 1 ] =
( B1 - b0o2vlxoze_idx_1 * b0o2vlxoze_idx_3 ) * 0.10197162129779282 *
9.8066500000000012 ; } if ( rtmIsMajorTimeStep ( im1b3ukp2q ) &&
rtmIsSampleHit ( im1b3ukp2q , 2 , 0 ) ) { l1nxc1mhxw [ 0 ] = localDW ->
apcd2eaeko [ 0 ] ; l1nxc1mhxw [ 1 ] = localDW -> apcd2eaeko [ 1 ] ; } if ( (
rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 1 , 0 ) )
&& ( rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 , 0
) ) ) { localDW -> lkwnxbugdr = 57.295779513082323 * b0o2vlxoze_idx_3 ; } if
( rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 , 0 )
) { * g1vgxxaiji = localDW -> lkwnxbugdr ; } if ( rtmIsMajorTimeStep (
im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 1 , 0 ) ) { if (
rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 , 0 ) )
{ localDW -> g4ph0dfu1a = 57.295779513082323 * Fy_f ; } if (
rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 , 0 ) )
{ localDW -> ntj2eqm4bo [ 0 ] = eyvxamlnsw_idx_0 ; localDW -> ntj2eqm4bo [ 1
] = eyvxamlnsw_idx_1 ; } } if ( rtmIsMajorTimeStep ( im1b3ukp2q ) &&
rtmIsSampleHit ( im1b3ukp2q , 2 , 0 ) ) { * ncu1gcngal = localDW ->
g4ph0dfu1a ; } if ( ( rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit (
im1b3ukp2q , 1 , 0 ) ) && ( rtmIsMajorTimeStep ( im1b3ukp2q ) &&
rtmIsSampleHit ( im1b3ukp2q , 2 , 0 ) ) ) { localDW -> eb2i4idyhz [ 0 ] =
localB -> kmmor0frkj [ 0 ] ; localDW -> eb2i4idyhz [ 1 ] = localB ->
kmmor0frkj [ 1 ] ; } if ( rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit
( im1b3ukp2q , 2 , 0 ) ) { ptlxyeaclt [ 0 ] = localDW -> ntj2eqm4bo [ 0 ] ;
ptlxyeaclt [ 1 ] = localDW -> ntj2eqm4bo [ 1 ] ; atbzzhjgq2 [ 0 ] = localDW
-> eb2i4idyhz [ 0 ] ; atbzzhjgq2 [ 1 ] = localDW -> eb2i4idyhz [ 1 ] ; } if (
( rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 1 , 0 )
) && ( rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 ,
0 ) ) ) { localDW -> f4c0gsxadk = 57.295779513082323 * b0o2vlxoze_idx_2 ; }
if ( rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 , 0
) ) { * ciatxfcoj0 = localDW -> f4c0gsxadk ; } if ( ( rtmIsMajorTimeStep (
im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 1 , 0 ) ) && (
rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 , 0 ) )
) { localDW -> aajeczhqaz = 57.295779513082323 * b0o2vlxoze_idx_3 ; } if (
rtmIsMajorTimeStep ( im1b3ukp2q ) && rtmIsSampleHit ( im1b3ukp2q , 2 , 0 ) )
{ * iu3htb3iws = localDW -> aajeczhqaz ; } } void DynamicsTID3 ( a5nhmlc3ac *
localB ) { localB -> mwvube2wct [ 0 ] = fv1bp5xf2d . P_17 ; localB ->
mwvube2wct [ 1 ] = fv1bp5xf2d . P_18 ; localB -> k4koj0fcom [ 0 ] =
fv1bp5xf2d . P_31 ; localB -> k4koj0fcom [ 1 ] = fv1bp5xf2d . P_33 ; localB
-> k4koj0fcom [ 2 ] = fv1bp5xf2d . P_28 ; localB -> k4koj0fcom [ 3 ] =
fv1bp5xf2d . P_29 ; localB -> arfpgtsegp [ 0 ] = fv1bp5xf2d . P_27 ; localB
-> arfpgtsegp [ 1 ] = fv1bp5xf2d . P_27 ; localB -> g4h22xrh2h [ 0 ] = 0.0 ;
localB -> g4h22xrh2h [ 1 ] = 0.0 ; localB -> g4h22xrh2h [ 2 ] = 0.0 ; } void
mfwe15whbn ( gifjn5jgpl * const im1b3ukp2q , jyej4afwv4 * localDW ) { if (
rtmIsMajorTimeStep ( im1b3ukp2q ) ) { if ( memcmp ( im1b3ukp2q ->
nonContDerivSignal [ 0 ] . pCurrVal , im1b3ukp2q -> nonContDerivSignal [ 0 ]
. pPrevVal , im1b3ukp2q -> nonContDerivSignal [ 0 ] . sizeInBytes ) != 0 ) {
( void ) memcpy ( im1b3ukp2q -> nonContDerivSignal [ 0 ] . pPrevVal ,
im1b3ukp2q -> nonContDerivSignal [ 0 ] . pCurrVal , im1b3ukp2q ->
nonContDerivSignal [ 0 ] . sizeInBytes ) ; ssSetSolverNeedsReset ( im1b3ukp2q
-> _mdlRefSfcnS ) ; } if ( memcmp ( im1b3ukp2q -> nonContDerivSignal [ 1 ] .
pCurrVal , im1b3ukp2q -> nonContDerivSignal [ 1 ] . pPrevVal , im1b3ukp2q ->
nonContDerivSignal [ 1 ] . sizeInBytes ) != 0 ) { ( void ) memcpy (
im1b3ukp2q -> nonContDerivSignal [ 1 ] . pPrevVal , im1b3ukp2q ->
nonContDerivSignal [ 1 ] . pCurrVal , im1b3ukp2q -> nonContDerivSignal [ 1 ]
. sizeInBytes ) ; ssSetSolverNeedsReset ( im1b3ukp2q -> _mdlRefSfcnS ) ; } if
( memcmp ( im1b3ukp2q -> nonContDerivSignal [ 2 ] . pCurrVal , im1b3ukp2q ->
nonContDerivSignal [ 2 ] . pPrevVal , im1b3ukp2q -> nonContDerivSignal [ 2 ]
. sizeInBytes ) != 0 ) { ( void ) memcpy ( im1b3ukp2q -> nonContDerivSignal [
2 ] . pPrevVal , im1b3ukp2q -> nonContDerivSignal [ 2 ] . pCurrVal ,
im1b3ukp2q -> nonContDerivSignal [ 2 ] . sizeInBytes ) ;
ssSetSolverNeedsReset ( im1b3ukp2q -> _mdlRefSfcnS ) ; } } localDW ->
jedpsif1qn = 0 ; localDW -> np520qsqbo = 0 ; } void dut4aenton ( a5nhmlc3ac *
localB , f2ptplqnhr * localXdot ) { localXdot -> djutwq30mj [ 0 ] = localB ->
bhzqhtdtuu [ 0 ] ; localXdot -> djutwq30mj [ 1 ] = localB -> bhzqhtdtuu [ 1 ]
; localXdot -> djutwq30mj [ 2 ] = localB -> bhzqhtdtuu [ 2 ] ; localXdot ->
djutwq30mj [ 3 ] = localB -> bhzqhtdtuu [ 3 ] ; localXdot -> pyisz1wc0x [ 0 ]
= localB -> kmmor0frkj [ 0 ] ; localXdot -> pyisz1wc0x [ 1 ] = localB ->
kmmor0frkj [ 1 ] ; } void irbpoiyy1a ( gifjn5jgpl * const im1b3ukp2q ) { if (
! slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( im1b3ukp2q ->
_mdlRefSfcnS , "Dynamics" , "SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ;
} } void eoyw0bspsh ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T
mdlref_TID1 , int_T mdlref_TID2 , int_T mdlref_TID3 , gifjn5jgpl * const
im1b3ukp2q , a5nhmlc3ac * localB , jyej4afwv4 * localDW , aws3kc23qp * localX
, void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI
, const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) {
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( void ) memset ( ( void * )
im1b3ukp2q , 0 , sizeof ( gifjn5jgpl ) ) ; im1b3ukp2q -> Timing .
mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; im1b3ukp2q -> Timing .
mdlref_GlobalTID [ 1 ] = mdlref_TID1 ; im1b3ukp2q -> Timing .
mdlref_GlobalTID [ 2 ] = mdlref_TID2 ; im1b3ukp2q -> Timing .
mdlref_GlobalTID [ 3 ] = mdlref_TID3 ; im1b3ukp2q -> _mdlRefSfcnS = (
_mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( im1b3ukp2q -> _mdlRefSfcnS , "Dynamics" ,
"START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } { localB -> oojjxzyok4 = 0.0
; localB -> d55gex5ibo [ 0 ] = 0.0 ; localB -> d55gex5ibo [ 1 ] = 0.0 ;
localB -> mdcl3wrwbo [ 0 ] = 0.0 ; localB -> mdcl3wrwbo [ 1 ] = 0.0 ; localB
-> k4koj0fcom [ 0 ] = 0.0 ; localB -> k4koj0fcom [ 1 ] = 0.0 ; localB ->
k4koj0fcom [ 2 ] = 0.0 ; localB -> k4koj0fcom [ 3 ] = 0.0 ; localB ->
mwvube2wct [ 0 ] = 0.0 ; localB -> mwvube2wct [ 1 ] = 0.0 ; localB ->
arfpgtsegp [ 0 ] = 0.0 ; localB -> arfpgtsegp [ 1 ] = 0.0 ; localB ->
g4h22xrh2h [ 0 ] = 0.0 ; localB -> g4h22xrh2h [ 1 ] = 0.0 ; localB ->
g4h22xrh2h [ 2 ] = 0.0 ; localB -> bhzqhtdtuu [ 0 ] = 0.0 ; localB ->
bhzqhtdtuu [ 1 ] = 0.0 ; localB -> bhzqhtdtuu [ 2 ] = 0.0 ; localB ->
bhzqhtdtuu [ 3 ] = 0.0 ; localB -> kmmor0frkj [ 0 ] = 0.0 ; localB ->
kmmor0frkj [ 1 ] = 0.0 ; } ( void ) memset ( ( void * ) localDW , 0 , sizeof
( jyej4afwv4 ) ) ; localDW -> ghybnrppsd = 0.0 ; localDW -> hyfogyvedl = 0.0
; localDW -> gjqpjwgw3u [ 0 ] = 0.0 ; localDW -> gjqpjwgw3u [ 1 ] = 0.0 ;
localDW -> apcd2eaeko [ 0 ] = 0.0 ; localDW -> apcd2eaeko [ 1 ] = 0.0 ;
localDW -> lkwnxbugdr = 0.0 ; localDW -> g4ph0dfu1a = 0.0 ; localDW ->
ntj2eqm4bo [ 0 ] = 0.0 ; localDW -> ntj2eqm4bo [ 1 ] = 0.0 ; localDW ->
eb2i4idyhz [ 0 ] = 0.0 ; localDW -> eb2i4idyhz [ 1 ] = 0.0 ; localDW ->
f4c0gsxadk = 0.0 ; localDW -> aajeczhqaz = 0.0 ;
Dynamics_InitializeDataMapInfo ( im1b3ukp2q , localDW , localX , sysRanPtr ,
contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != ( NULL
) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & (
im1b3ukp2q -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( im1b3ukp2q ->
DataMapInfo . mmi , rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex (
im1b3ukp2q -> DataMapInfo . mmi , rt_CSTATEIdx ) ; } im1b3ukp2q ->
nonContDerivSignal [ 0 ] . pPrevVal = ( char_T * ) im1b3ukp2q ->
NonContDerivMemory . mr_nonContSig0 ; im1b3ukp2q -> nonContDerivSignal [ 0 ]
. sizeInBytes = ( 2 * sizeof ( real_T ) ) ; im1b3ukp2q -> nonContDerivSignal
[ 0 ] . pCurrVal = ( char_T * ) ( & localB -> mdcl3wrwbo [ 0 ] ) ; ;
im1b3ukp2q -> nonContDerivSignal [ 1 ] . pPrevVal = ( char_T * ) im1b3ukp2q
-> NonContDerivMemory . mr_nonContSig1 ; im1b3ukp2q -> nonContDerivSignal [ 1
] . sizeInBytes = ( 2 * sizeof ( real_T ) ) ; im1b3ukp2q ->
nonContDerivSignal [ 1 ] . pCurrVal = ( char_T * ) ( & localB -> d55gex5ibo [
0 ] ) ; ; im1b3ukp2q -> nonContDerivSignal [ 2 ] . pPrevVal = ( char_T * )
im1b3ukp2q -> NonContDerivMemory . mr_nonContSig2 ; im1b3ukp2q ->
nonContDerivSignal [ 2 ] . sizeInBytes = ( 1 * sizeof ( real_T ) ) ;
im1b3ukp2q -> nonContDerivSignal [ 2 ] . pCurrVal = ( char_T * ) ( & localB
-> oojjxzyok4 ) ; ; } void mr_Dynamics_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; {
boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo (
mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } *
retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName ,
rtMdlInfo_Dynamics , 46 ) ; * retVal = 1 ; } static void
mr_Dynamics_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_Dynamics_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_Dynamics_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_Dynamics_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_Dynamics_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_Dynamics_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j
, uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_Dynamics_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) ; static uint_T
mr_Dynamics_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_Dynamics_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_Dynamics_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_Dynamics_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_Dynamics_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_Dynamics_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_Dynamics_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
real_T ) fieldVal ) ) ; } static uint_T
mr_Dynamics_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_Dynamics_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T
fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray
, i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; }
mxArray * mr_Dynamics_GetDWork ( const f0nsmguvnxb * mdlrefDW ) { static
const char_T * ssDWFieldNames [ 3 ] = { "rtb" , "rtdw" , "NULL->rtzce" , } ;
mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_Dynamics_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( mdlrefDW
-> rtb ) , sizeof ( mdlrefDW -> rtb ) ) ; { static const char_T *
rtdwDataFieldNames [ 13 ] = { "mdlrefDW->rtdw.ghybnrppsd" ,
"mdlrefDW->rtdw.hyfogyvedl" , "mdlrefDW->rtdw.gjqpjwgw3u" ,
"mdlrefDW->rtdw.apcd2eaeko" , "mdlrefDW->rtdw.lkwnxbugdr" ,
"mdlrefDW->rtdw.g4ph0dfu1a" , "mdlrefDW->rtdw.ntj2eqm4bo" ,
"mdlrefDW->rtdw.eb2i4idyhz" , "mdlrefDW->rtdw.f4c0gsxadk" ,
"mdlrefDW->rtdw.aajeczhqaz" , "mdlrefDW->rtdw.jedpsif1qn" ,
"mdlrefDW->rtdw.np520qsqbo" , "mdlrefDW->rtdw.obojwblgr0" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 13 , rtdwDataFieldNames ) ;
mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & (
mdlrefDW -> rtdw . ghybnrppsd ) , sizeof ( mdlrefDW -> rtdw . ghybnrppsd ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
mdlrefDW -> rtdw . hyfogyvedl ) , sizeof ( mdlrefDW -> rtdw . hyfogyvedl ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
mdlrefDW -> rtdw . gjqpjwgw3u ) , sizeof ( mdlrefDW -> rtdw . gjqpjwgw3u ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
mdlrefDW -> rtdw . apcd2eaeko ) , sizeof ( mdlrefDW -> rtdw . apcd2eaeko ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
mdlrefDW -> rtdw . lkwnxbugdr ) , sizeof ( mdlrefDW -> rtdw . lkwnxbugdr ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
mdlrefDW -> rtdw . g4ph0dfu1a ) , sizeof ( mdlrefDW -> rtdw . g4ph0dfu1a ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
mdlrefDW -> rtdw . ntj2eqm4bo ) , sizeof ( mdlrefDW -> rtdw . ntj2eqm4bo ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
mdlrefDW -> rtdw . eb2i4idyhz ) , sizeof ( mdlrefDW -> rtdw . eb2i4idyhz ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & (
mdlrefDW -> rtdw . f4c0gsxadk ) , sizeof ( mdlrefDW -> rtdw . f4c0gsxadk ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & (
mdlrefDW -> rtdw . aajeczhqaz ) , sizeof ( mdlrefDW -> rtdw . aajeczhqaz ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) & (
mdlrefDW -> rtdw . jedpsif1qn ) , sizeof ( mdlrefDW -> rtdw . jedpsif1qn ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & (
mdlrefDW -> rtdw . np520qsqbo ) , sizeof ( mdlrefDW -> rtdw . np520qsqbo ) )
; mr_Dynamics_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & (
mdlrefDW -> rtdw . obojwblgr0 ) , sizeof ( mdlrefDW -> rtdw . obojwblgr0 ) )
; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } ( void ) mdlrefDW ;
return ssDW ; } void mr_Dynamics_SetDWork ( f0nsmguvnxb * mdlrefDW , const
mxArray * ssDW ) { ( void ) ssDW ; ( void ) mdlrefDW ;
mr_Dynamics_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtb ) , ssDW
, 0 , 0 , sizeof ( mdlrefDW -> rtb ) ) ; { const mxArray * rtdwData =
mxGetFieldByNumber ( ssDW , 0 , 1 ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . ghybnrppsd ) , rtdwData , 0 , 0 , sizeof (
mdlrefDW -> rtdw . ghybnrppsd ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . hyfogyvedl ) , rtdwData , 0 , 1 , sizeof (
mdlrefDW -> rtdw . hyfogyvedl ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . gjqpjwgw3u ) , rtdwData , 0 , 2 , sizeof (
mdlrefDW -> rtdw . gjqpjwgw3u ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . apcd2eaeko ) , rtdwData , 0 , 3 , sizeof (
mdlrefDW -> rtdw . apcd2eaeko ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . lkwnxbugdr ) , rtdwData , 0 , 4 , sizeof (
mdlrefDW -> rtdw . lkwnxbugdr ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . g4ph0dfu1a ) , rtdwData , 0 , 5 , sizeof (
mdlrefDW -> rtdw . g4ph0dfu1a ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . ntj2eqm4bo ) , rtdwData , 0 , 6 , sizeof (
mdlrefDW -> rtdw . ntj2eqm4bo ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . eb2i4idyhz ) , rtdwData , 0 , 7 , sizeof (
mdlrefDW -> rtdw . eb2i4idyhz ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . f4c0gsxadk ) , rtdwData , 0 , 8 , sizeof (
mdlrefDW -> rtdw . f4c0gsxadk ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . aajeczhqaz ) , rtdwData , 0 , 9 , sizeof (
mdlrefDW -> rtdw . aajeczhqaz ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . jedpsif1qn ) , rtdwData , 0 , 10 , sizeof (
mdlrefDW -> rtdw . jedpsif1qn ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . np520qsqbo ) , rtdwData , 0 , 11 , sizeof (
mdlrefDW -> rtdw . np520qsqbo ) ) ; mr_Dynamics_restoreDataFromMxArray ( (
void * ) & ( mdlrefDW -> rtdw . obojwblgr0 ) , rtdwData , 0 , 12 , sizeof (
mdlrefDW -> rtdw . obojwblgr0 ) ) ; } } void
mr_Dynamics_RegisterSimStateChecksum ( SimStruct * S ) { const uint32_T
chksum [ 4 ] = { 704159252U , 363356451U , 3563426156U , 2175338071U , } ;
slmrModelRefRegisterSimStateChecksum ( S , "Dynamics" , & chksum [ 0 ] ) ; }
mxArray * mr_Dynamics_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
