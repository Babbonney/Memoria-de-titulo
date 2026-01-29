//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpc5.h
//
// Code generated for Simulink model 'mpc5'.
//
// Model version                  : 12.58
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Thu Jan 29 13:23:40 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef mpc5_h_
#define mpc5_h_
#include <cstdio>
#include <cstring>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_Actuators.h"
#include "MW_uORB_Read.h"
#include "mpc5_types.h"
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
struct B_mpc5_T {
  sbYdmyzq7l8Oes4F6y6cc2C_mpc5_T WorkingSet;
  sbYdmyzq7l8Oes4F6y6cc2C_mpc5_T b_workingset;
  sOWFOmKuLvD2kpFwfdM45bG_mpc5_T CholRegManager;
  ssq2hyGkLOLhNlUBS6YfcCD_mpc5_T QRManager;
  sFevNsrsl34D5b5aqm3qNjD_mpc5_T memspace;
  real_T B[1072];
  real_T b_H[225];
  sqvdR3NQrfOjUOrC18Muj0B_mpc5_T solution;
  real_T work[67];
  real_T vn1[67];
  real_T vn2[67];
  real_T work_m[67];
  real_T c_x[66];
  s3c01M66EFWFQJ5qmFcUbmD_mpc5_T QPObjective;
  real_T A[16];
  real_T work_c[16];
  real_T uvec[15];
  real_T f[15];
  real_T dv[15];
  px4_Bus_vehicle_odometry In1;        // '<S5>/In1'
  px4_Bus_vehicle_odometry r;
  sqZVQFgLZG74FDpCArykMHB_mpc5_T expl_temp;
  real32_T motorValues[12];
  real32_T motorValues_k[12];
  real32_T servoValues[8];
  real_T B_c[4];
  real_T u[3];                         // '<Root>/MATLAB Function5'
  sIOJhD9KwAkF5sEguPjYquC_mpc5_T expl_temp_b;
  sIOJhD9KwAkF5sEguPjYquC_mpc5_T expl_temp_p;
  sIOJhD9KwAkF5sEguPjYquC_mpc5_T expl_temp_c;
  sIOJhD9KwAkF5sEguPjYquC_mpc5_T expl_temp_f;
  real_T M4;                           // '<Root>/MATLAB Function'
  real_T b_colSum;
  real_T x_idx_0;
  real_T x_idx_1;
  real_T x_idx_2;
  real_T maxConstr_new;
  real_T d;
  real_T tolDelta;
  real_T normDelta;
  real_T minLambda;
  real_T solution_lambda;
  real_T tempMaxConstr;
  real_T constrViolation_basicX;
  real_T temp;
  real_T temp2;
  real_T temp_g;
  real_T s;
  real_T b_atmp;
  real_T tau;
  real_T xnorm;
  real_T a;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T constrViolation;
  real_T tol;
  real_T qtb;
  real_T b_c;
  real_T constrViolation_g;
  real_T tol_m;
  real_T maxDiag;
  real_T u1;
  real_T c;
  real_T b_SCALED_REG_PRIMAL;
  real_T b_temp;
  real_T u1_n;
  real_T alpha1;
  real_T temp_p;
  real_T p_max;
  real_T denomTol;
  real_T alphaTemp;
  real_T phaseOneCorrectionX;
  real_T phaseOneCorrectionP;
  real_T pk_corrected;
  real_T ratio;
  real_T c_c;
  real_T b_s;
  real_T b_temp_l;
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale_j;
  real_T denomTol_d;
  real_T alphaTemp_g;
  real_T phaseOneCorrectionX_l;
  real_T phaseOneCorrectionP_d;
  real_T pk_corrected_d;
  real_T s_l;
  real_T temp_o;
  real_T a_b;
  int8_T ipiv[4];
  real32_T DataTypeConversion3;        // '<Root>/Data Type Conversion3'
  real32_T DataTypeConversion2;        // '<Root>/Data Type Conversion2'
  real32_T DataTypeConversion1;        // '<Root>/Data Type Conversion1'
  int32_T idxFillStart;
  int32_T colPos;
  int32_T a_n;
  int32_T n;
  int32_T jA;
  int32_T c_b;
  int32_T i;
  int32_T mConstr;
  int32_T idxStartIneq;
  int32_T idxEndIneq;
  int32_T b_idxStartIneq;
  int32_T b_idxEndIneq;
  int32_T i_l;
  int32_T activeSetChangeID;
  int32_T nVar;
  int32_T globalActiveConstrIdx;
  int32_T TYPE;
  int32_T iAw0;
  int32_T ix0;
  int32_T iy0;
  int32_T minmn;
  int32_T i_h;
  int32_T nVar_b;
  int32_T mWConstr;
  int32_T nVar_d;
  int32_T offsetQR;
  int32_T rankQR;
  int32_T ldq;
  int32_T jBcol;
  int32_T iAcol;
  int32_T d_e;
  int32_T ix;
  int32_T b_ar;
  int32_T minmn_b;
  int32_T nfxd;
  int32_T mmi;
  int32_T pvt;
  int32_T itemp;
  int32_T ix_j;
  int32_T nVar_f;
  int32_T mTotalWorkingEq;
  int32_T nDepInd;
  int32_T idx_row;
  int32_T idxStartIneq_a;
  int32_T ix0_j;
  int32_T iy0_j;
  int32_T totalRank;
  int32_T b_idx;
  int32_T nVar_o;
  int32_T mTotalWorkingEq_n;
  int32_T nDepInd_i;
  int32_T idxStartIneq_o;
  int32_T ix0_n;
  int32_T iy0_m;
  int32_T i_c;
  int32_T nActiveConstr;
  int32_T nFixedConstr;
  int32_T nVar_m;
  int32_T b_idx_m;
  int32_T ix0_ja;
  int32_T iy0_h;
  int32_T b_k;
  int32_T iy;
  int32_T nVar_c;
  int32_T mNull;
  int32_T nullStartIdx;
  int32_T b_idx_c;
  int32_T nVars;
  int32_T ldQ;
  int32_T lastColC;
  int32_T br;
  int32_T ar;
  int32_T idx;
  int32_T ix_p;
};

// Block states (default storage) for system '<Root>'
struct DW_mpc5_T {
  sCBS0Ia3qD76sOwKERvBoFE_mpc5_T opts; // '<Root>/MATLAB Function5'
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
struct P_mpc5_T_ {
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
struct tag_RTM_mpc5_T {
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

  extern P_mpc5_T mpc5_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_mpc5_T mpc5_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_mpc5_T mpc5_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void mpc5_initialize(void);
  extern void mpc5_step(void);
  extern void mpc5_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_mpc5_T *const mpc5_M;

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
//  '<Root>' : 'mpc5'
//  '<S1>'   : 'mpc5/MATLAB Function'
//  '<S2>'   : 'mpc5/MATLAB Function5'
//  '<S3>'   : 'mpc5/Vehicle Attitude'
//  '<S4>'   : 'mpc5/Vehicle Attitude/PX4 uORB Read'
//  '<S5>'   : 'mpc5/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // mpc5_h_

//
// File trailer for generated code.
//
// [EOF]
//
