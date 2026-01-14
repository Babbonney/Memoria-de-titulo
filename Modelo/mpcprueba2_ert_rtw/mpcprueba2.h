//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpcprueba2.h
//
// Code generated for Simulink model 'mpcprueba2'.
//
// Model version                  : 12.42
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jan 14 15:02:40 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef mpcprueba2_h_
#define mpcprueba2_h_
#include <cstdio>
#include <cstring>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_uORB_Read.h"
#include "MW_PX4_Actuators.h"
#include "mpcprueba2_types.h"
#include <uORB/topics/sensor_gyro.h>

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
struct B_mpcprueba2_T {
  sBSaEu6uV23R8SnQxWoeC5G_mpcpr_T CholRegManager;
  sIxc6e90CRmt17sP6BCIycE_mpcpr_T QRManager;
  shMFFa6ZZiYob3JbcpnnDNC_mpcpr_T WorkingSet;
  shMFFa6ZZiYob3JbcpnnDNC_mpcpr_T b_workingset;
  sDXqx68fEcBxWtF9wVQzAm_mpcpru_T memspace;
  real_T B[703];
  real_T H_tmp[324];
  real_T H_tmp_m[324];
  real_T H_tmp_c[324];
  szTgroxymWCv1wbPz1KDaqC_mpcpr_T solution;
  real_T b[54];
  sSitMryErsR3bMncKlW48mF_mpcpr_T QPObjective;
  int8_T R_big_mat[324];
  real_T work[37];
  real_T vn1[37];
  real_T vn2[37];
  real_T work_k[37];
  real_T work_c[19];
  real_T Ref_seq[18];
  real_T dv[18];
  real_T dv1[18];
  real_T dv2[18];
  real_T A[16];
  real_T dv3[9];
  real_T b_a[9];
  real_T cBuffer[9];
  real_T aBuffer[9];
  real_T cBuffer_b[9];
  real_T b_x[9];
  sqZVQFgLZG74FDpCArykMHB_mpcpr_T expl_temp;
  real32_T motorValues[12];
  real32_T motorValues_p[12];
  px4_Bus_sensor_gyro In1;             // '<S4>/In1'
  px4_Bus_sensor_gyro r;
  real32_T servoValues[8];
  real_T m_final[4];
  int32_T varargin_2_tmp_tmp[6];
  int32_T b_x_tmp[6];
  sIOJhD9KwAkF5sEguPjYquC_mpcpr_T expl_temp_c;
  sIOJhD9KwAkF5sEguPjYquC_mpcpr_T expl_temp_f;
  sIOJhD9KwAkF5sEguPjYquC_mpcpr_T expl_temp_g;
  sIOJhD9KwAkF5sEguPjYquC_mpcpr_T expl_temp_g1;
  real_T rtb_DataTypeConversion12_idx_0;
  real_T rtb_DataTypeConversion12_idx_1;
  real_T rtb_DataTypeConversion12_idx_2;
  real_T d;
  real_T d1;
  real_T d2;
  real_T options_ConstraintTolerance;
  real_T H_infnrm;
  real_T f_infnrm;
  real_T colSum;
  real_T maxConstr_new;
  real_T d3;
  real_T tolDelta;
  real_T normDelta;
  real_T minLambda;
  real_T solution_lambda;
  real_T tempMaxConstr;
  real_T constrViolation_basicX;
  real_T temp;
  real_T temp2;
  real_T temp_m;
  real_T s;
  real_T b_atmp;
  real_T tau;
  real_T xnorm;
  real_T a;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T e;
  real_T ed2;
  real_T d4;
  real_T c;
  real_T c_n;
  real_T absx11;
  real_T constrViolation;
  real_T tol;
  real_T qtb;
  real_T b_c;
  real_T constrViolation_p;
  real_T tol_l;
  real_T maxDiag;
  real_T u1;
  real_T c_j;
  real_T b_SCALED_REG_PRIMAL;
  real_T b_temp;
  real_T u1_d;
  real_T alpha1;
  real_T temp_g;
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
  real_T scale_d;
  real_T denomTol_d;
  real_T alphaTemp_l;
  real_T phaseOneCorrectionX_o;
  real_T phaseOneCorrectionP_b;
  real_T pk_corrected_n;
  real_T s_b;
  real_T temp_l;
  real_T a_h;
  int8_T ipiv[4];
  real32_T x;     // '<S1>/SigConversion_InsertedFor_Bus Selector_at_outport_0'
  real32_T y;     // '<S1>/SigConversion_InsertedFor_Bus Selector_at_outport_1'
  real32_T z;     // '<S1>/SigConversion_InsertedFor_Bus Selector_at_outport_2'
  real32_T TmpSignalConversionAtTAQSigLogg[3];
  // '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux3_at_outport_0Inport1' 
  real32_T Gain3;                      // '<Root>/Gain3'
  real32_T Gain4;                      // '<Root>/Gain4'
  real32_T Gain5;                      // '<Root>/Gain5'
  real32_T TmpSignalConversionAtTAQSigLo_m[3];
  // '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux4_at_outport_0Inport1' 
  real32_T DataTypeConversion7[4];     // '<Root>/Data Type Conversion7'
  int32_T ibcol;
  int32_T itilerow;
  int32_T jA;
  int32_T i;
  int32_T Q_big_tmp;
  int32_T b_tmp;
  int32_T Phi_tmp;
  int32_T mUB;
  int32_T mFixed;
  int32_T idxFillStart;
  int32_T colOffsetATw;
  int32_T c_b;
  int32_T d_d;
  int32_T c_k;
  int32_T i_e;
  int32_T mConstr;
  int32_T idxStartIneq;
  int32_T idxEndIneq;
  int32_T b_idxStartIneq;
  int32_T b_idxEndIneq;
  int32_T i_b;
  int32_T activeSetChangeID;
  int32_T nVar;
  int32_T globalActiveConstrIdx;
  int32_T TYPE;
  int32_T iAw0;
  int32_T ix0;
  int32_T iy0;
  int32_T minmn;
  int32_T i_j;
  int32_T nVar_f;
  int32_T mWConstr;
  int32_T nVar_a;
  int32_T offsetQR;
  int32_T rankQR;
  int32_T ldq;
  int32_T jBcol;
  int32_T iAcol;
  int32_T d_j;
  int32_T ix;
  int32_T b_ar;
  int32_T minmn_j;
  int32_T nfxd;
  int32_T mmi;
  int32_T pvt;
  int32_T itemp;
  int32_T ix_o;
  int32_T iy;
  int32_T nVar_n;
  int32_T mTotalWorkingEq;
  int32_T nDepInd;
  int32_T idx_row;
  int32_T idxStartIneq_i;
  int32_T ix0_o;
  int32_T iy0_n;
  int32_T totalRank;
  int32_T b_idx;
  int32_T nVar_m;
  int32_T mTotalWorkingEq_c;
  int32_T nDepInd_m;
  int32_T idxStartIneq_m;
  int32_T ix0_j;
  int32_T iy0_h;
  int32_T i_c;
  int32_T nActiveConstr;
  int32_T nFixedConstr;
  int32_T nVar_c;
  int32_T b_idx_p;
  int32_T ix0_p;
  int32_T iy0_a;
  int32_T b_k;
  int32_T nVar_e;
  int32_T mNull;
  int32_T nullStartIdx;
  int32_T b_idx_a;
  int32_T nVars;
  int32_T ldQ;
  int32_T lastColC;
  int32_T br;
  int32_T ar;
  int32_T g;
  int32_T idx;
  int32_T ix_a;
  int32_T idxmax;
};

// Block states (default storage) for system '<Root>'
struct DW_mpcprueba2_T {
  sCBS0Ia3qD76sOwKERvBoFE_mpcpr_T options;// '<Root>/MATLAB Function5'
  px4_internal_block_PX4Actuato_T obj; // '<Root>/PX4 Actuator Write1'
  px4_internal_block_Subscriber_T obj_i;// '<S3>/SourceBlock'
  real_T Phi[324];                     // '<Root>/MATLAB Function5'
  real_T F_f[54];                      // '<Root>/MATLAB Function5'
  real_T H[324];                       // '<Root>/MATLAB Function5'
  real_T M[16];                        // '<Root>/MATLAB Function5'
  real_T lb[18];                       // '<Root>/MATLAB Function5'
  real_T ub[18];                       // '<Root>/MATLAB Function5'
  real_T Q_big[324];                   // '<Root>/MATLAB Function5'
  struct {
    void *LoggedData;
  } Scope4_PWORK;                      // '<Root>/Scope4'

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      // '<Root>/Scope5'

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      // '<Root>/Scope2'

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      // '<Root>/Scope3'

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      // '<Root>/Scope6'

  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<Root>/Scope'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S3>/Enabled Subsystem'
  boolean_T doneDoubleBufferReInit;    // '<Root>/MATLAB Function5'
  boolean_T A_not_empty;               // '<Root>/MATLAB Function5'
};

// Parameters (default storage)
struct P_mpcprueba2_T_ {
  px4_Bus_sensor_gyro Out1_Y0;         // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S4>/Out1'

  px4_Bus_sensor_gyro Constant_Value;  // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S3>/Constant'

  real_T Constant9_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant9'

  real_T Constant8_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant8'

  real_T Constant11_Value;             // Expression: 0
                                          //  Referenced by: '<Root>/Constant11'

  real_T Constant10_Value;             // Expression: 0.3606542355797865
                                          //  Referenced by: '<Root>/Constant10'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<Root>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: 0
                                          //  Referenced by: '<Root>/Saturation1'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<Root>/Gain3'

  real32_T Gain4_Gain;                 // Computed Parameter: Gain4_Gain
                                          //  Referenced by: '<Root>/Gain4'

  real32_T Gain5_Gain;                 // Computed Parameter: Gain5_Gain
                                          //  Referenced by: '<Root>/Gain5'

  boolean_T Constant7_Value;           // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<Root>/Constant7'

  boolean_T Constant6_Value;           // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<Root>/Constant6'

  uint8_T ManualSwitch1_CurrentSetting;
                             // Computed Parameter: ManualSwitch1_CurrentSetting
                                //  Referenced by: '<Root>/Manual Switch1'

};

// Real-time Model Data Structure
struct tag_RTM_mpcprueba2_T {
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

  extern P_mpcprueba2_T mpcprueba2_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_mpcprueba2_T mpcprueba2_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_mpcprueba2_T mpcprueba2_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void mpcprueba2_initialize(void);
  extern void mpcprueba2_step(void);
  extern void mpcprueba2_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_mpcprueba2_T *const mpcprueba2_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/NOT' : Unused code path elimination
//  Block '<Root>/Data Type Conversion13' : Eliminate redundant data type conversion


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
//  '<Root>' : 'mpcprueba2'
//  '<S1>'   : 'mpcprueba2/Gyroscope1'
//  '<S2>'   : 'mpcprueba2/MATLAB Function5'
//  '<S3>'   : 'mpcprueba2/Gyroscope1/PX4 uORB Read'
//  '<S4>'   : 'mpcprueba2/Gyroscope1/PX4 uORB Read/Enabled Subsystem'

#endif                                 // mpcprueba2_h_

//
// File trailer for generated code.
//
// [EOF]
//
