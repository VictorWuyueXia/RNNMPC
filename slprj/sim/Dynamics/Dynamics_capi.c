#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Dynamics_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 19
#endif
#ifndef SS_INT64
#define SS_INT64 20
#endif
#else
#include "builtin_typeid_types.h"
#include "Dynamics.h"
#include "Dynamics_capi.h"
#include "Dynamics_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , 0 ,
TARGET_STRING (
 "Dynamics/Bicycle Model - Force Input/Vehicle Body 3DOF Single Track/state/xdot int/Integrator"
) , TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1
, 0 } , { 1 , 4 , TARGET_STRING (
 "Dynamics/Bicycle Model - Force Input/Vehicle Body 3DOF Single Track/Signal Routing/Signal Routing/state2bus/Integrator"
) , TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 , 1 , - 1
, 0 } , { 0 , - 1 , ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 ,
- 1 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 } ;
#ifndef HOST_CAPI_BUILD
static void Dynamics_InitializeDataAddr ( void * dataAddr [ ] , jyej4afwv4 *
localDW , aws3kc23qp * localX ) { dataAddr [ 0 ] = ( void * ) ( & localX ->
djutwq30mj [ 0 ] ) ; dataAddr [ 1 ] = ( void * ) ( & localX -> pyisz1wc0x [ 0
] ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void Dynamics_InitializeVarDimsAddr ( int32_T * vardimsAddr [ ] ) {
vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void Dynamics_InitializeLoggingFunctions ( RTWLoggingFcnPtr
loggingPtrs [ ] ) { loggingPtrs [ 0 ] = ( NULL ) ; loggingPtrs [ 1 ] = ( NULL
) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
uint_T rtDimensionArray [ ] = { 4 , 1 , 2 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 } ; static rtwCAPI_FixPtMap rtFixPtMap [ ] = {
{ ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , }
; static rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , (
int8_T ) 0 , ( uint8_T ) 0 } } ; static int_T rtContextSystems [ 4 ] ; static
rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ] = { { 0 , 0 , "" , 0 } } ; static
rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = { 4 ,
rtContextSystems , loggingMetaInfo , 0 , ( NULL ) , { 0 , ( NULL ) , ( NULL )
} , 0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL
) , 0 } , { rtBlockStates , 2 } , { rtDataTypeMap , rtDimensionMap ,
rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" ,
{ 1994266779U , 2087255531U , 2644677681U , 362526512U } , &
mmiStaticInfoLogging , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * Dynamics_GetCAPIStaticMap ( void ) { return
& mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void Dynamics_InitializeSystemRan ( gifjn5jgpl * const im1b3ukp2q ,
sysRanDType * systemRan [ ] , jyej4afwv4 * localDW , int_T systemTid [ ] ,
void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER ( im1b3ukp2q ) ;
UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType * )
rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemRan [ 2 ] = ( NULL ) ;
systemRan [ 3 ] = ( NULL ) ; systemTid [ 1 ] = im1b3ukp2q -> Timing .
mdlref_GlobalTID [ 0 ] ; systemTid [ 2 ] = im1b3ukp2q -> Timing .
mdlref_GlobalTID [ 0 ] ; systemTid [ 3 ] = im1b3ukp2q -> Timing .
mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] =
0 ; rtContextSystems [ 1 ] = 0 ; rtContextSystems [ 2 ] = 0 ;
rtContextSystems [ 3 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void Dynamics_InitializeDataMapInfo ( gifjn5jgpl * const im1b3ukp2q ,
jyej4afwv4 * localDW , aws3kc23qp * localX , void * sysRanPtr , int
contextTid ) { rtwCAPI_SetVersion ( im1b3ukp2q -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( im1b3ukp2q -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( im1b3ukp2q -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; Dynamics_InitializeDataAddr ( im1b3ukp2q ->
DataMapInfo . dataAddress , localDW , localX ) ; rtwCAPI_SetDataAddressMap (
im1b3ukp2q -> DataMapInfo . mmi , im1b3ukp2q -> DataMapInfo . dataAddress ) ;
Dynamics_InitializeVarDimsAddr ( im1b3ukp2q -> DataMapInfo . vardimsAddress )
; rtwCAPI_SetVarDimsAddressMap ( im1b3ukp2q -> DataMapInfo . mmi , im1b3ukp2q
-> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetPath ( im1b3ukp2q ->
DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetFullPath ( im1b3ukp2q ->
DataMapInfo . mmi , ( NULL ) ) ; Dynamics_InitializeLoggingFunctions (
im1b3ukp2q -> DataMapInfo . loggingPtrs ) ; rtwCAPI_SetLoggingPtrs (
im1b3ukp2q -> DataMapInfo . mmi , im1b3ukp2q -> DataMapInfo . loggingPtrs ) ;
rtwCAPI_SetInstanceLoggingInfo ( im1b3ukp2q -> DataMapInfo . mmi , &
im1b3ukp2q -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray (
im1b3ukp2q -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen (
im1b3ukp2q -> DataMapInfo . mmi , 0 ) ; Dynamics_InitializeSystemRan (
im1b3ukp2q , im1b3ukp2q -> DataMapInfo . systemRan , localDW , im1b3ukp2q ->
DataMapInfo . systemTid , sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan (
im1b3ukp2q -> DataMapInfo . mmi , im1b3ukp2q -> DataMapInfo . systemRan ) ;
rtwCAPI_SetSystemTid ( im1b3ukp2q -> DataMapInfo . mmi , im1b3ukp2q ->
DataMapInfo . systemTid ) ; rtwCAPI_SetGlobalTIDMap ( im1b3ukp2q ->
DataMapInfo . mmi , & im1b3ukp2q -> Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Dynamics_host_InitializeDataMapInfo ( Dynamics_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
