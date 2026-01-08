//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pruebafmu.h
//
// Code generated for Simulink model 'pruebafmu'.
//
// Model version                  : 12.34
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Thu Jan  8 12:17:43 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef pruebafmu_h_
#define pruebafmu_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_uORB_Read.h"
#include "MW_PX4_Actuators.h"
#include "pruebafmu_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/sensor_gyro.h>

extern "C"
{

#include "rt_nonfinite.h"

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
struct B_pruebafmu_T {
  px4_Bus_vehicle_odometry In1;        // '<S7>/In1'
  px4_Bus_vehicle_odometry r;
  real32_T motorValues[12];
  real32_T motorValues_m[12];
  px4_Bus_sensor_gyro In1_e;           // '<S5>/In1'
  px4_Bus_sensor_gyro r1;
  real32_T servoValues[8];
  real_T FMU[4];                       // '<Root>/FMU'
  real32_T DataTypeConversion[4];      // '<Root>/Data Type Conversion'
};

// Block states (default storage) for system '<Root>'
struct DW_pruebafmu_T {
  px4_internal_block_PX4Actuato_T obj; // '<Root>/PX4 Actuator Write'
  px4_internal_block_Subscriber_T obj_c;// '<S6>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S4>/SourceBlock'
  real_T FMU_FmuPrevTime;              // '<Root>/FMU'
  real_T FMU_slPrevTime;               // '<Root>/FMU'
  real_T FMU_ValContInReal[8];         // '<Root>/FMU'
  real_T FMU_ValOutReal[4];            // '<Root>/FMU'
  void* FMU_FmuStruct2;                // '<Root>/FMU'
  void *FMU_PWORK[3];                  // '<Root>/FMU'
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<Root>/Scope1'

  int32_T FMU_FmuIsInitialized;        // '<Root>/FMU'
  int32_T FMU_FmuParamIdxToOffset;     // '<Root>/FMU'
  int32_T FMU_FmuEnumValueList;        // '<Root>/FMU'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S6>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_f;// '<S4>/Enabled Subsystem'
  boolean_T doneDoubleBufferReInit;    // '<Root>/quat2eul'
};

// Parameters (default storage)
struct P_pruebafmu_T_ {
  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S7>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S6>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_c;       // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S5>/Out1'

  px4_Bus_sensor_gyro Constant_Value_a;// Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S4>/Constant'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant4'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant3'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant2'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<Root>/Gain'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<Root>/Gain1'

  uint32_T FMU_VRContInReal[8];        // Computed Parameter: FMU_VRContInReal
                                          //  Referenced by: '<Root>/FMU'

  uint32_T FMU_VROutReal[4];           // Computed Parameter: FMU_VROutReal
                                          //  Referenced by: '<Root>/FMU'

  boolean_T Constant1_Value;           // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<Root>/Constant1'

  boolean_T Constant_Value_b;          // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<Root>/Constant'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<Root>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_pruebafmu_T {
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

  extern P_pruebafmu_T pruebafmu_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_pruebafmu_T pruebafmu_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_pruebafmu_T pruebafmu_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void pruebafmu_initialize(void);
  extern void pruebafmu_step(void);
  extern void pruebafmu_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_pruebafmu_T *const pruebafmu_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S4>/NOT' : Unused code path elimination
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S2>/Signal Copy' : Unused code path elimination
//  Block '<S2>/Signal Copy1' : Unused code path elimination
//  Block '<S2>/Signal Copy2' : Unused code path elimination


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
//  '<Root>' : 'pruebafmu'
//  '<S1>'   : 'pruebafmu/Gyroscope'
//  '<S2>'   : 'pruebafmu/Vehicle Attitude'
//  '<S3>'   : 'pruebafmu/quat2eul'
//  '<S4>'   : 'pruebafmu/Gyroscope/PX4 uORB Read'
//  '<S5>'   : 'pruebafmu/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S6>'   : 'pruebafmu/Vehicle Attitude/PX4 uORB Read'
//  '<S7>'   : 'pruebafmu/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // pruebafmu_h_

//
// File trailer for generated code.
//
// [EOF]
//
