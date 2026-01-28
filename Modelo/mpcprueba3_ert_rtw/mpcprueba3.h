//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpcprueba3.h
//
// Code generated for Simulink model 'mpcprueba3'.
//
// Model version                  : 12.54
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jan 28 14:19:31 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef mpcprueba3_h_
#define mpcprueba3_h_
#include <cstdio>
#include <cstring>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_Actuators.h"
#include "MW_uORB_Read.h"
#include "mpcprueba3_types.h"
#include <uORB/topics/vehicle_odometry.h>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <string.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

// Block signals (default storage)
struct B_mpcprueba3_T {
  sCkfVcG7AQFySWWMtM4hccH_mpcpr_T WorkingSet;
  sCkfVcG7AQFySWWMtM4hccH_mpcpr_T b_workingset;
  s84kJ6tHYwvmDUGeqLYD2uB_mpcpr_T CholRegManager;
  sa62cVcKQKcFBi6rAdMOFyB_mpcpr_T QRManager;
  s1ukn1KZwe8HKOg95SKgssB_mpcpr_T memspace;
  real32_T B[1072];
  real_T b_H[225];
  sbtWOgGGLEmAd335P8Y53FE_mpcpr_T solution;
  real32_T work[67];
  real32_T vn1[67];
  real32_T vn2[67];
  real32_T work_m[67];
  real32_T b_x[66];
  s53NiOJFNFao3mXDluAcV3_mpcpru_T QPObjective;
  real_T A[16];
  px4_Bus_vehicle_odometry In1;        // '<S5>/In1'
  px4_Bus_vehicle_odometry r;
  real32_T work_c[16];
  real32_T uvec[15];
  real32_T f[15];
  real32_T fv[15];
  real32_T motorValues[12];
  real32_T motorValues_k[12];
  real32_T servoValues[8];
  real_T B_c[4];
  s9KKbMhkwfdyFmbpWOvu65D_mpcpr_T expl_temp;
  real_T u[3];                         // '<Root>/MATLAB Function5'
  sOIMERIP639G9x3OUDedPv_mpcpru_T expl_temp_b;
  sOIMERIP639G9x3OUDedPv_mpcpru_T expl_temp_p;
  sOIMERIP639G9x3OUDedPv_mpcpru_T expl_temp_c;
  sOIMERIP639G9x3OUDedPv_mpcpru_T expl_temp_f;
  real_T M4;                           // '<Root>/MATLAB Function'
  real_T smax;
  real_T s;
  int8_T ipiv[4];
  real32_T DataTypeConversion3;        // '<Root>/Data Type Conversion3'
  real32_T DataTypeConversion2;        // '<Root>/Data Type Conversion2'
  real32_T DataTypeConversion1;        // '<Root>/Data Type Conversion1'
  real32_T colSum;
  real32_T f_infnrm;
  real32_T b_colSum;
  real32_T In1_angular_velocity;
  real32_T u0;
  real32_T u0_g;
  real32_T f_g;
  real32_T tolDelta;
  real32_T normDelta;
  real32_T minLambda;
  real32_T solution_lambda;
  real32_T tempMaxConstr;
  real32_T constrViolation_basicX;
  real32_T temp;
  real32_T temp2;
  real32_T temp_m;
  real32_T s_n;
  real32_T constrViolation;
  real32_T tol;
  real32_T qtb;
  real32_T constrViolation_p;
  real32_T tol_l;
  real32_T maxDiag;
  real32_T u1;
  real32_T b_SCALED_REG_PRIMAL;
  real32_T p_max;
  real32_T denomTol;
  int32_T idxFillStart;
  int32_T colPos;
  int32_T a;
  int32_T n;
  int32_T jA;
  int32_T c;
  int32_T i;
  int32_T mConstr;
  int32_T idxStartIneq;
  int32_T idxEndIneq;
  int32_T b_idxStartIneq;
  int32_T b_idxEndIneq;
  int32_T i_j;
  int32_T activeSetChangeID;
  int32_T nVar;
  int32_T globalActiveConstrIdx;
  int32_T TYPE;
  int32_T iAw0;
  int32_T ix0;
  int32_T iy0;
  int32_T minmn;
  int32_T i_d;
  int32_T nVar_g;
  int32_T mWConstr;
  int32_T nVar_l;
  int32_T offsetQR;
  int32_T rankQR;
  int32_T ldq;
  int32_T jBcol;
  int32_T iAcol;
  int32_T d;
  int32_T ix;
  int32_T b_ar;
  int32_T minmn_d;
  int32_T nfxd;
  int32_T mmi;
  int32_T pvt;
  int32_T itemp;
  int32_T ix_d;
  int32_T iy;
  int32_T idxmax;
  int32_T c_ix;
  int32_T i_l;
  int32_T temp_tmp;
  int32_T b_temp_tmp;
  int32_T ii;
  int32_T nVar_o;
  int32_T mTotalWorkingEq;
  int32_T nDepInd;
  int32_T idx_row;
  int32_T idxStartIneq_b;
  int32_T ix0_n;
  int32_T iy0_b;
  int32_T totalRank;
  int32_T b_idx;
  int32_T ix_l;
  int32_T nVar_h;
  int32_T mTotalWorkingEq_b;
  int32_T nDepInd_d;
  int32_T idxStartIneq_e;
  int32_T ix0_b;
  int32_T iy0_j;
  int32_T i_f;
  int32_T nActiveConstr;
  int32_T nFixedConstr;
  int32_T nVar_a;
  int32_T b_idx_j;
  int32_T ix0_j;
  int32_T iy0_o;
  int32_T b_k;
  int32_T nVar_n;
  int32_T mNull;
  int32_T nullStartIdx;
  int32_T b_idx_i;
  int32_T nVars;
  int32_T ldQ;
  int32_T lastColC;
  int32_T br;
  int32_T ar;
  int32_T g;
  int32_T ic;
  int32_T h;
  int32_T i_o;
  int32_T totalIneq;
  int32_T totalUB;
  int32_T i_n;
  int32_T k;
  int32_T idxRotGCol;
  int32_T QRk0;
  int32_T totalIneq_m;
  int32_T totalUB_c;
  int32_T idx;
  int32_T Qk0;
  int32_T idx_m;
};

// Block states (default storage) for system '<Root>'
struct DW_mpcprueba3_T {
  sCBS0Ia3qD76sOwKERvBoFE_mpcpr_T opts;// '<Root>/MATLAB Function5'
  px4_internal_block_PX4Actuato_T obj; // '<Root>/PX4 Actuator Write'
  px4_internal_block_Subscriber_T obj_h;// '<S4>/SourceBlock'
  real_T x0[15];                       // '<Root>/MATLAB Function5'
  real_T u_prev[3];                    // '<Root>/MATLAB Function5'
  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<Root>/Scope'

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      // '<Root>/Scope3'

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<Root>/Scope1'

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      // '<Root>/Scope2'

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      // '<Root>/Scope4'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S4>/Enabled Subsystem'
  boolean_T doneDoubleBufferReInit;    // '<Root>/MATLAB Function5'
  boolean_T doneDoubleBufferReInit_h;  // '<Root>/MATLAB Function'
};

// Parameters (default storage)
struct P_mpcprueba3_T_ {
  real_T F[45];                        // Variable: F
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T G[225];                       // Variable: G
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T H[225];                       // Variable: H
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T Pc[990];                      // Variable: Pc
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T Qvec[225];                    // Variable: Qvec
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T Sc[198];                      // Variable: Sc
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T qc[66];                       // Variable: qc
                                          //  Referenced by: '<Root>/MATLAB Function5'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S5>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S4>/Constant'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<Root>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: 0
                                          //  Referenced by: '<Root>/Saturation1'

  real_T Saturation2_UpperSat;         // Expression: 1
                                          //  Referenced by: '<Root>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: 0
                                          //  Referenced by: '<Root>/Saturation2'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<Root>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: 0
                                          //  Referenced by: '<Root>/Saturation3'

  boolean_T Constant_Value_h;          // Computed Parameter: Constant_Value_h
                                          //  Referenced by: '<Root>/Constant'

  boolean_T Constant1_Value;           // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<Root>/Constant1'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<Root>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_mpcprueba3_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_mpcprueba3_T mpcprueba3_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_mpcprueba3_T mpcprueba3_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_mpcprueba3_T mpcprueba3_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void mpcprueba3_initialize(void);
  extern void mpcprueba3_step(void);
  extern void mpcprueba3_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_mpcprueba3_T *const mpcprueba3_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S4>/NOT' : Unused code path elimination
//  Block '<S3>/Signal Copy' : Eliminate redundant signal conversion block
//  Block '<S3>/Signal Copy1' : Eliminate redundant signal conversion block
//  Block '<S3>/Signal Copy2' : Eliminate redundant signal conversion block


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'mpcprueba3'
//  '<S1>'   : 'mpcprueba3/MATLAB Function'
//  '<S2>'   : 'mpcprueba3/MATLAB Function5'
//  '<S3>'   : 'mpcprueba3/Vehicle Attitude'
//  '<S4>'   : 'mpcprueba3/Vehicle Attitude/PX4 uORB Read'
//  '<S5>'   : 'mpcprueba3/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // mpcprueba3_h_

//
// File trailer for generated code.
//
// [EOF]
//
