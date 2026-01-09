//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pruebafmu.h
//
// Code generated for Simulink model 'pruebafmu'.
//
// Model version                  : 12.35
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Fri Jan  9 12:18:50 2026
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
#include "DAHostLib_Network.h"
#include "pruebafmu_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/sensor_gyro.h>
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

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
  real_T DataTypeConversion4;          // '<Root>/Data Type Conversion4'
  real_T DataTypeConversion9;          // '<Root>/Data Type Conversion9'
  real_T DataTypeConversion8;          // '<Root>/Data Type Conversion8'
  real_T ByteUnpack[4];                // '<Root>/Byte Unpack'
  real_T DataTypeConversion1;          // '<Root>/Data Type Conversion1'
  real_T DataTypeConversion6;          // '<Root>/Data Type Conversion6'
  real_T DataTypeConversion7;          // '<Root>/Data Type Conversion7'
  real_T DataTypeConversion5;          // '<Root>/Data Type Conversion5'
  real32_T DataTypeConversion[4];      // '<Root>/Data Type Conversion'
  uint8_T BytePack[8];                 // '<Root>/Byte Pack'
  uint8_T BytePack1[8];                // '<Root>/Byte Pack1'
  uint8_T BytePack2[8];                // '<Root>/Byte Pack2'
  uint8_T BytePack6[8];                // '<Root>/Byte Pack6'
  uint8_T UDPReceive_o1[32];           // '<Root>/UDP Receive'
  uint8_T BytePack3[8];                // '<Root>/Byte Pack3'
  uint8_T BytePack4[8];                // '<Root>/Byte Pack4'
  uint8_T BytePack7[8];                // '<Root>/Byte Pack7'
  uint8_T BytePack5[8];                // '<Root>/Byte Pack5'
};

// Block states (default storage) for system '<Root>'
struct DW_pruebafmu_T {
  px4_internal_block_PX4Actuato_T obj; // '<Root>/PX4 Actuator Write'
  px4_internal_block_Subscriber_T obj_c;// '<S6>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S4>/SourceBlock'
  real_T UDPSend_NetworkLib[137];      // '<Root>/UDP Send'
  real_T UDPSend1_NetworkLib[137];     // '<Root>/UDP Send1'
  real_T UDPSend3_NetworkLib[137];     // '<Root>/UDP Send3'
  real_T UDPSend4_NetworkLib[137];     // '<Root>/UDP Send4'
  real_T UDPReceive_NetworkLib[137];   // '<Root>/UDP Receive'
  real_T UDPSend7_NetworkLib[137];     // '<Root>/UDP Send7'
  real_T UDPSend5_NetworkLib[137];     // '<Root>/UDP Send5'
  real_T UDPSend6_NetworkLib[137];     // '<Root>/UDP Send6'
  real_T UDPSend2_NetworkLib[137];     // '<Root>/UDP Send2'
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<Root>/Scope1'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S6>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_f;// '<S4>/Enabled Subsystem'
  boolean_T doneDoubleBufferReInit;    // '<Root>/quat2eul'
};

// Parameters (default storage)
struct P_pruebafmu_T_ {
  int32_T UDPReceive_localPort;        // Mask Parameter: UDPReceive_localPort
                                          //  Referenced by: '<Root>/UDP Receive'

  int32_T UDPSend_remotePort;          // Mask Parameter: UDPSend_remotePort
                                          //  Referenced by: '<Root>/UDP Send'

  int32_T UDPSend1_remotePort;         // Mask Parameter: UDPSend1_remotePort
                                          //  Referenced by: '<Root>/UDP Send1'

  int32_T UDPSend3_remotePort;         // Mask Parameter: UDPSend3_remotePort
                                          //  Referenced by: '<Root>/UDP Send3'

  int32_T UDPSend4_remotePort;         // Mask Parameter: UDPSend4_remotePort
                                          //  Referenced by: '<Root>/UDP Send4'

  int32_T UDPSend7_remotePort;         // Mask Parameter: UDPSend7_remotePort
                                          //  Referenced by: '<Root>/UDP Send7'

  int32_T UDPSend5_remotePort;         // Mask Parameter: UDPSend5_remotePort
                                          //  Referenced by: '<Root>/UDP Send5'

  int32_T UDPSend6_remotePort;         // Mask Parameter: UDPSend6_remotePort
                                          //  Referenced by: '<Root>/UDP Send6'

  int32_T UDPSend2_remotePort;         // Mask Parameter: UDPSend2_remotePort
                                          //  Referenced by: '<Root>/UDP Send2'

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
//  Block '<Root>/Data Type Conversion10' : Eliminate redundant data type conversion


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
