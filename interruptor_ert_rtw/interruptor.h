//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: interruptor.h
//
// Code generated for Simulink model 'interruptor'.
//
// Model version                  : 12.10
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Tue Jan  6 11:44:01 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef interruptor_h_
#define interruptor_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_Actuators.h"
#include "MW_uORB_Read.h"
#include "interruptor_types.h"
#include <uORB/topics/actuator_outputs.h>

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
struct B_interruptor_T {
  px4_Bus_actuator_outputs In1;        // '<S2>/In1'
  px4_Bus_actuator_outputs r;
  real32_T motorValues[12];
  real32_T motorValues_m[12];
  real32_T SignalConversion[4];        // '<Root>/Signal Conversion'
  real32_T DataTypeConversion;         // '<Root>/Data Type Conversion'
};

// Block states (default storage) for system '<Root>'
struct DW_interruptor_T {
  px4_internal_block_PX4Actuato_T obj; // '<Root>/PX4 Actuator Write'
  px4_internal_block_Subscriber_T obj_n;// '<S1>/SourceBlock'
  struct {
    void *LoggedData;
  } Output_PWORK;                      // '<Root>/Output'

  struct {
    void *LoggedData;
  } Input_PWORK;                       // '<Root>/Input'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S1>/Enabled Subsystem'
};

// Parameters (default storage)
struct P_interruptor_T_ {
  px4_Bus_actuator_outputs Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S2>/Out1'

  px4_Bus_actuator_outputs Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S1>/Constant'

  real_T Valormaximo_Value;            // Expression: 0.3
                                          //  Referenced by: '<Root>/Valor maximo'

  real_T Valorminimo_Value;            // Expression: 0
                                          //  Referenced by: '<Root>/Valor minimo'

  boolean_T Armvalue_Value;            // Computed Parameter: Armvalue_Value
                                          //  Referenced by: '<Root>/Arm value'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<Root>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_interruptor_T {
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

  extern P_interruptor_T interruptor_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_interruptor_T interruptor_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_interruptor_T interruptor_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void interruptor_initialize(void);
  extern void interruptor_step(void);
  extern void interruptor_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_interruptor_T *const interruptor_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/NOT' : Unused code path elimination


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
//  '<Root>' : 'interruptor'
//  '<S1>'   : 'interruptor/PX4 uORB Read'
//  '<S2>'   : 'interruptor/PX4 uORB Read/Enabled Subsystem'

#endif                                 // interruptor_h_

//
// File trailer for generated code.
//
// [EOF]
//
