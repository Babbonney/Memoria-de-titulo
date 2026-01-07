//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controladorpruebaio.h
//
// Code generated for Simulink model 'controladorpruebaio'.
//
// Model version                  : 12.27
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Tue Jan  6 11:56:41 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef controladorpruebaio_h_
#define controladorpruebaio_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_uORB_Read.h"
#include "MW_PX4_Actuators.h"
#include "controladorpruebaio_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

// Block signals (default storage)
struct B_controladorpruebaio_T {
  px4_Bus_vehicle_odometry In1;        // '<S225>/In1'
  px4_Bus_vehicle_odometry r;
  real32_T motorValues[12];
  real32_T motorValues_m[12];
  px4_Bus_sensor_gyro In1_e;           // '<S7>/In1'
  px4_Bus_sensor_gyro r1;
  real32_T servoValues[8];
  real32_T RateTransition;             // '<S3>/Rate Transition'
  real32_T x;     // '<S1>/SigConversion_InsertedFor_Bus Selector_at_outport_0'
  real32_T Saturation;                 // '<S107>/Saturation'
  real32_T RateTransition1;            // '<S3>/Rate Transition1'
  real32_T DataTypeConversion[4];      // '<Root>/Data Type Conversion'
  real32_T Gain1;                      // '<Root>/Gain1'
  real32_T Gain;                       // '<Root>/Gain'
  real32_T Sum;                        // '<S3>/Sum'
  real32_T phi;                        // '<Root>/quat2eul'
  real32_T theta;                      // '<Root>/quat2eul'
};

// Block states (default storage) for system '<Root>'
struct DW_controladorpruebaio_T {
  px4_internal_block_PX4Actuato_T obj; // '<Root>/PX4 Actuator Write'
  px4_internal_block_Subscriber_T obj_c;// '<S224>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S6>/SourceBlock'
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<Root>/Scope1'

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      // '<S3>/Scope3'

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      // '<S3>/Scope2'

  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<S3>/Scope'

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      // '<S3>/Scope7'

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      // '<S3>/Scope5'

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      // '<S3>/Scope6'

  struct {
    void *LoggedData;
  } Scope1_PWORK_d;                    // '<S3>/Scope1'

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      // '<S3>/Scope4'

  real32_T Integrator_DSTATE;          // '<S100>/Integrator'
  real32_T UD_DSTATE;                  // '<S93>/UD'
  real32_T Integrator_DSTATE_o;        // '<S206>/Integrator'
  real32_T UD_DSTATE_k;                // '<S199>/UD'
  real32_T RateTransition_Buffer0;     // '<S3>/Rate Transition'
  real32_T RateTransition1_Buffer0;    // '<S3>/Rate Transition1'
  real32_T TmpRTBAtProportionalGainInport1;// synthesized block
  real32_T TmpRTBAtProportionalGainInpor_b;// synthesized block
  int8_T EnabledSubsystem_SubsysRanBC; // '<S224>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_f;// '<S6>/Enabled Subsystem'
  boolean_T doneDoubleBufferReInit;    // '<Root>/quat2eul'
  boolean_T doneDoubleBufferReInit_m;  // '<Root>/MATLAB Function'
};

// Parameters (default storage)
struct P_controladorpruebaio_T_ {
  real32_T PIDController1_D;           // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S91>/Derivative Gain'

  real32_T PIDController3_D;           // Mask Parameter: PIDController3_D
                                          //  Referenced by: '<S197>/Derivative Gain'

  real32_T PIDController1_DifferentiatorIC;
                              // Mask Parameter: PIDController1_DifferentiatorIC
                                 //  Referenced by: '<S93>/UD'

  real32_T PIDController3_DifferentiatorIC;
                              // Mask Parameter: PIDController3_DifferentiatorIC
                                 //  Referenced by: '<S199>/UD'

  real32_T PIDController3_I;           // Mask Parameter: PIDController3_I
                                          //  Referenced by: '<S203>/Integral Gain'

  real32_T PIDController1_I;           // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S97>/Integral Gain'

  real32_T PIDController1_InitialCondition;
                              // Mask Parameter: PIDController1_InitialCondition
                                 //  Referenced by: '<S100>/Integrator'

  real32_T PIDController3_InitialCondition;
                              // Mask Parameter: PIDController3_InitialCondition
                                 //  Referenced by: '<S206>/Integrator'

  real32_T PIDController3_Kb;          // Mask Parameter: PIDController3_Kb
                                          //  Referenced by: '<S196>/Kb'

  real32_T PIDController1_Kb;          // Mask Parameter: PIDController1_Kb
                                          //  Referenced by: '<S90>/Kb'

  real32_T PIDController1_LowerSaturationL;
                              // Mask Parameter: PIDController1_LowerSaturationL
                                 //  Referenced by: '<S107>/Saturation'

  real32_T PIDController3_LowerSaturationL;
                              // Mask Parameter: PIDController3_LowerSaturationL
                                 //  Referenced by: '<S213>/Saturation'

  real32_T PIDController_LowerSaturationLi;
                              // Mask Parameter: PIDController_LowerSaturationLi
                                 //  Referenced by: '<S53>/Saturation'

  real32_T PIDController2_LowerSaturationL;
                              // Mask Parameter: PIDController2_LowerSaturationL
                                 //  Referenced by: '<S159>/Saturation'

  real32_T PIDController1_P;           // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S105>/Proportional Gain'

  real32_T PIDController3_P;           // Mask Parameter: PIDController3_P
                                          //  Referenced by: '<S211>/Proportional Gain'

  real32_T PIDController_P;            // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S51>/Proportional Gain'

  real32_T PIDController2_P;           // Mask Parameter: PIDController2_P
                                          //  Referenced by: '<S157>/Proportional Gain'

  real32_T PIDController1_UpperSaturationL;
                              // Mask Parameter: PIDController1_UpperSaturationL
                                 //  Referenced by: '<S107>/Saturation'

  real32_T PIDController3_UpperSaturationL;
                              // Mask Parameter: PIDController3_UpperSaturationL
                                 //  Referenced by: '<S213>/Saturation'

  real32_T PIDController_UpperSaturationLi;
                              // Mask Parameter: PIDController_UpperSaturationLi
                                 //  Referenced by: '<S53>/Saturation'

  real32_T PIDController2_UpperSaturationL;
                              // Mask Parameter: PIDController2_UpperSaturationL
                                 //  Referenced by: '<S159>/Saturation'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S225>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S224>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_c;       // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S7>/Out1'

  px4_Bus_sensor_gyro Constant_Value_a;// Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S6>/Constant'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant4'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant2'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant3'

  real32_T RateTransition_InitialCondition;
                          // Computed Parameter: RateTransition_InitialCondition
                             //  Referenced by: '<S3>/Rate Transition'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S100>/Integrator'

  real32_T Tsamp_WtEt;                 // Computed Parameter: Tsamp_WtEt
                                          //  Referenced by: '<S95>/Tsamp'

  real32_T RateTransition1_InitialConditio;
                          // Computed Parameter: RateTransition1_InitialConditio
                             //  Referenced by: '<S3>/Rate Transition1'

  real32_T Integrator_gainval_k;     // Computed Parameter: Integrator_gainval_k
                                        //  Referenced by: '<S206>/Integrator'

  real32_T Tsamp_WtEt_k;               // Computed Parameter: Tsamp_WtEt_k
                                          //  Referenced by: '<S201>/Tsamp'

  real32_T Saturation4_UpperSat;     // Computed Parameter: Saturation4_UpperSat
                                        //  Referenced by: '<Root>/Saturation4'

  real32_T Saturation4_LowerSat;     // Computed Parameter: Saturation4_LowerSat
                                        //  Referenced by: '<Root>/Saturation4'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<Root>/Gain1'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<Root>/Gain'

  boolean_T Constant1_Value;           // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<Root>/Constant1'

  boolean_T Constant_Value_b;          // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<Root>/Constant'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<Root>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_controladorpruebaio_T {
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
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_controladorpruebaio_T controladorpruebaio_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_controladorpruebaio_T controladorpruebaio_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_controladorpruebaio_T controladorpruebaio_DW;

// External function called from main
#ifdef __cplusplus

extern "C"
{

#endif

  extern void controladorpruebaio_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void controladorpruebaio_initialize(void);
  extern void controladorpruebaio_step0(void);// Sample time: [0.001s, 0.0s]
  extern void controladorpruebaio_step1(void);// Sample time: [0.005s, 0.0s]
  extern void controladorpruebaio_step(int_T tid);
  extern void controladorpruebaio_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_controladorpruebaio_T *const controladorpruebaio_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S93>/DTDup' : Unused code path elimination
//  Block '<S199>/DTDup' : Unused code path elimination
//  Block '<S224>/NOT' : Unused code path elimination
//  Block '<S4>/Signal Copy' : Unused code path elimination
//  Block '<S4>/Signal Copy1' : Unused code path elimination
//  Block '<S4>/Signal Copy2' : Unused code path elimination


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
//  '<Root>' : 'controladorpruebaio'
//  '<S1>'   : 'controladorpruebaio/Gyroscope'
//  '<S2>'   : 'controladorpruebaio/MATLAB Function'
//  '<S3>'   : 'controladorpruebaio/Subsystem'
//  '<S4>'   : 'controladorpruebaio/Vehicle Attitude'
//  '<S5>'   : 'controladorpruebaio/quat2eul'
//  '<S6>'   : 'controladorpruebaio/Gyroscope/PX4 uORB Read'
//  '<S7>'   : 'controladorpruebaio/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S8>'   : 'controladorpruebaio/Subsystem/PID Controller'
//  '<S9>'   : 'controladorpruebaio/Subsystem/PID Controller1'
//  '<S10>'  : 'controladorpruebaio/Subsystem/PID Controller2'
//  '<S11>'  : 'controladorpruebaio/Subsystem/PID Controller3'
//  '<S12>'  : 'controladorpruebaio/Subsystem/PID Controller/Anti-windup'
//  '<S13>'  : 'controladorpruebaio/Subsystem/PID Controller/D Gain'
//  '<S14>'  : 'controladorpruebaio/Subsystem/PID Controller/External Derivative'
//  '<S15>'  : 'controladorpruebaio/Subsystem/PID Controller/Filter'
//  '<S16>'  : 'controladorpruebaio/Subsystem/PID Controller/Filter ICs'
//  '<S17>'  : 'controladorpruebaio/Subsystem/PID Controller/I Gain'
//  '<S18>'  : 'controladorpruebaio/Subsystem/PID Controller/Ideal P Gain'
//  '<S19>'  : 'controladorpruebaio/Subsystem/PID Controller/Ideal P Gain Fdbk'
//  '<S20>'  : 'controladorpruebaio/Subsystem/PID Controller/Integrator'
//  '<S21>'  : 'controladorpruebaio/Subsystem/PID Controller/Integrator ICs'
//  '<S22>'  : 'controladorpruebaio/Subsystem/PID Controller/N Copy'
//  '<S23>'  : 'controladorpruebaio/Subsystem/PID Controller/N Gain'
//  '<S24>'  : 'controladorpruebaio/Subsystem/PID Controller/P Copy'
//  '<S25>'  : 'controladorpruebaio/Subsystem/PID Controller/Parallel P Gain'
//  '<S26>'  : 'controladorpruebaio/Subsystem/PID Controller/Reset Signal'
//  '<S27>'  : 'controladorpruebaio/Subsystem/PID Controller/Saturation'
//  '<S28>'  : 'controladorpruebaio/Subsystem/PID Controller/Saturation Fdbk'
//  '<S29>'  : 'controladorpruebaio/Subsystem/PID Controller/Sum'
//  '<S30>'  : 'controladorpruebaio/Subsystem/PID Controller/Sum Fdbk'
//  '<S31>'  : 'controladorpruebaio/Subsystem/PID Controller/Tracking Mode'
//  '<S32>'  : 'controladorpruebaio/Subsystem/PID Controller/Tracking Mode Sum'
//  '<S33>'  : 'controladorpruebaio/Subsystem/PID Controller/Tsamp - Integral'
//  '<S34>'  : 'controladorpruebaio/Subsystem/PID Controller/Tsamp - Ngain'
//  '<S35>'  : 'controladorpruebaio/Subsystem/PID Controller/postSat Signal'
//  '<S36>'  : 'controladorpruebaio/Subsystem/PID Controller/preInt Signal'
//  '<S37>'  : 'controladorpruebaio/Subsystem/PID Controller/preSat Signal'
//  '<S38>'  : 'controladorpruebaio/Subsystem/PID Controller/Anti-windup/Disabled'
//  '<S39>'  : 'controladorpruebaio/Subsystem/PID Controller/D Gain/Disabled'
//  '<S40>'  : 'controladorpruebaio/Subsystem/PID Controller/External Derivative/Disabled'
//  '<S41>'  : 'controladorpruebaio/Subsystem/PID Controller/Filter/Disabled'
//  '<S42>'  : 'controladorpruebaio/Subsystem/PID Controller/Filter ICs/Disabled'
//  '<S43>'  : 'controladorpruebaio/Subsystem/PID Controller/I Gain/Disabled'
//  '<S44>'  : 'controladorpruebaio/Subsystem/PID Controller/Ideal P Gain/Passthrough'
//  '<S45>'  : 'controladorpruebaio/Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S46>'  : 'controladorpruebaio/Subsystem/PID Controller/Integrator/Disabled'
//  '<S47>'  : 'controladorpruebaio/Subsystem/PID Controller/Integrator ICs/Disabled'
//  '<S48>'  : 'controladorpruebaio/Subsystem/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S49>'  : 'controladorpruebaio/Subsystem/PID Controller/N Gain/Disabled'
//  '<S50>'  : 'controladorpruebaio/Subsystem/PID Controller/P Copy/Disabled'
//  '<S51>'  : 'controladorpruebaio/Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S52>'  : 'controladorpruebaio/Subsystem/PID Controller/Reset Signal/Disabled'
//  '<S53>'  : 'controladorpruebaio/Subsystem/PID Controller/Saturation/Enabled'
//  '<S54>'  : 'controladorpruebaio/Subsystem/PID Controller/Saturation Fdbk/Disabled'
//  '<S55>'  : 'controladorpruebaio/Subsystem/PID Controller/Sum/Passthrough_P'
//  '<S56>'  : 'controladorpruebaio/Subsystem/PID Controller/Sum Fdbk/Disabled'
//  '<S57>'  : 'controladorpruebaio/Subsystem/PID Controller/Tracking Mode/Disabled'
//  '<S58>'  : 'controladorpruebaio/Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S59>'  : 'controladorpruebaio/Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S60>'  : 'controladorpruebaio/Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S61>'  : 'controladorpruebaio/Subsystem/PID Controller/postSat Signal/Forward_Path'
//  '<S62>'  : 'controladorpruebaio/Subsystem/PID Controller/preInt Signal/Internal PreInt'
//  '<S63>'  : 'controladorpruebaio/Subsystem/PID Controller/preSat Signal/Forward_Path'
//  '<S64>'  : 'controladorpruebaio/Subsystem/PID Controller1/Anti-windup'
//  '<S65>'  : 'controladorpruebaio/Subsystem/PID Controller1/D Gain'
//  '<S66>'  : 'controladorpruebaio/Subsystem/PID Controller1/External Derivative'
//  '<S67>'  : 'controladorpruebaio/Subsystem/PID Controller1/Filter'
//  '<S68>'  : 'controladorpruebaio/Subsystem/PID Controller1/Filter ICs'
//  '<S69>'  : 'controladorpruebaio/Subsystem/PID Controller1/I Gain'
//  '<S70>'  : 'controladorpruebaio/Subsystem/PID Controller1/Ideal P Gain'
//  '<S71>'  : 'controladorpruebaio/Subsystem/PID Controller1/Ideal P Gain Fdbk'
//  '<S72>'  : 'controladorpruebaio/Subsystem/PID Controller1/Integrator'
//  '<S73>'  : 'controladorpruebaio/Subsystem/PID Controller1/Integrator ICs'
//  '<S74>'  : 'controladorpruebaio/Subsystem/PID Controller1/N Copy'
//  '<S75>'  : 'controladorpruebaio/Subsystem/PID Controller1/N Gain'
//  '<S76>'  : 'controladorpruebaio/Subsystem/PID Controller1/P Copy'
//  '<S77>'  : 'controladorpruebaio/Subsystem/PID Controller1/Parallel P Gain'
//  '<S78>'  : 'controladorpruebaio/Subsystem/PID Controller1/Reset Signal'
//  '<S79>'  : 'controladorpruebaio/Subsystem/PID Controller1/Saturation'
//  '<S80>'  : 'controladorpruebaio/Subsystem/PID Controller1/Saturation Fdbk'
//  '<S81>'  : 'controladorpruebaio/Subsystem/PID Controller1/Sum'
//  '<S82>'  : 'controladorpruebaio/Subsystem/PID Controller1/Sum Fdbk'
//  '<S83>'  : 'controladorpruebaio/Subsystem/PID Controller1/Tracking Mode'
//  '<S84>'  : 'controladorpruebaio/Subsystem/PID Controller1/Tracking Mode Sum'
//  '<S85>'  : 'controladorpruebaio/Subsystem/PID Controller1/Tsamp - Integral'
//  '<S86>'  : 'controladorpruebaio/Subsystem/PID Controller1/Tsamp - Ngain'
//  '<S87>'  : 'controladorpruebaio/Subsystem/PID Controller1/postSat Signal'
//  '<S88>'  : 'controladorpruebaio/Subsystem/PID Controller1/preInt Signal'
//  '<S89>'  : 'controladorpruebaio/Subsystem/PID Controller1/preSat Signal'
//  '<S90>'  : 'controladorpruebaio/Subsystem/PID Controller1/Anti-windup/Back Calculation'
//  '<S91>'  : 'controladorpruebaio/Subsystem/PID Controller1/D Gain/Internal Parameters'
//  '<S92>'  : 'controladorpruebaio/Subsystem/PID Controller1/External Derivative/Error'
//  '<S93>'  : 'controladorpruebaio/Subsystem/PID Controller1/Filter/Differentiator'
//  '<S94>'  : 'controladorpruebaio/Subsystem/PID Controller1/Filter/Differentiator/Tsamp'
//  '<S95>'  : 'controladorpruebaio/Subsystem/PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S96>'  : 'controladorpruebaio/Subsystem/PID Controller1/Filter ICs/Internal IC - Differentiator'
//  '<S97>'  : 'controladorpruebaio/Subsystem/PID Controller1/I Gain/Internal Parameters'
//  '<S98>'  : 'controladorpruebaio/Subsystem/PID Controller1/Ideal P Gain/Passthrough'
//  '<S99>'  : 'controladorpruebaio/Subsystem/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S100>' : 'controladorpruebaio/Subsystem/PID Controller1/Integrator/Discrete'
//  '<S101>' : 'controladorpruebaio/Subsystem/PID Controller1/Integrator ICs/Internal IC'
//  '<S102>' : 'controladorpruebaio/Subsystem/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S103>' : 'controladorpruebaio/Subsystem/PID Controller1/N Gain/Passthrough'
//  '<S104>' : 'controladorpruebaio/Subsystem/PID Controller1/P Copy/Disabled'
//  '<S105>' : 'controladorpruebaio/Subsystem/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S106>' : 'controladorpruebaio/Subsystem/PID Controller1/Reset Signal/Disabled'
//  '<S107>' : 'controladorpruebaio/Subsystem/PID Controller1/Saturation/Enabled'
//  '<S108>' : 'controladorpruebaio/Subsystem/PID Controller1/Saturation Fdbk/Disabled'
//  '<S109>' : 'controladorpruebaio/Subsystem/PID Controller1/Sum/Sum_PID'
//  '<S110>' : 'controladorpruebaio/Subsystem/PID Controller1/Sum Fdbk/Disabled'
//  '<S111>' : 'controladorpruebaio/Subsystem/PID Controller1/Tracking Mode/Disabled'
//  '<S112>' : 'controladorpruebaio/Subsystem/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S113>' : 'controladorpruebaio/Subsystem/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S114>' : 'controladorpruebaio/Subsystem/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S115>' : 'controladorpruebaio/Subsystem/PID Controller1/postSat Signal/Forward_Path'
//  '<S116>' : 'controladorpruebaio/Subsystem/PID Controller1/preInt Signal/Internal PreInt'
//  '<S117>' : 'controladorpruebaio/Subsystem/PID Controller1/preSat Signal/Forward_Path'
//  '<S118>' : 'controladorpruebaio/Subsystem/PID Controller2/Anti-windup'
//  '<S119>' : 'controladorpruebaio/Subsystem/PID Controller2/D Gain'
//  '<S120>' : 'controladorpruebaio/Subsystem/PID Controller2/External Derivative'
//  '<S121>' : 'controladorpruebaio/Subsystem/PID Controller2/Filter'
//  '<S122>' : 'controladorpruebaio/Subsystem/PID Controller2/Filter ICs'
//  '<S123>' : 'controladorpruebaio/Subsystem/PID Controller2/I Gain'
//  '<S124>' : 'controladorpruebaio/Subsystem/PID Controller2/Ideal P Gain'
//  '<S125>' : 'controladorpruebaio/Subsystem/PID Controller2/Ideal P Gain Fdbk'
//  '<S126>' : 'controladorpruebaio/Subsystem/PID Controller2/Integrator'
//  '<S127>' : 'controladorpruebaio/Subsystem/PID Controller2/Integrator ICs'
//  '<S128>' : 'controladorpruebaio/Subsystem/PID Controller2/N Copy'
//  '<S129>' : 'controladorpruebaio/Subsystem/PID Controller2/N Gain'
//  '<S130>' : 'controladorpruebaio/Subsystem/PID Controller2/P Copy'
//  '<S131>' : 'controladorpruebaio/Subsystem/PID Controller2/Parallel P Gain'
//  '<S132>' : 'controladorpruebaio/Subsystem/PID Controller2/Reset Signal'
//  '<S133>' : 'controladorpruebaio/Subsystem/PID Controller2/Saturation'
//  '<S134>' : 'controladorpruebaio/Subsystem/PID Controller2/Saturation Fdbk'
//  '<S135>' : 'controladorpruebaio/Subsystem/PID Controller2/Sum'
//  '<S136>' : 'controladorpruebaio/Subsystem/PID Controller2/Sum Fdbk'
//  '<S137>' : 'controladorpruebaio/Subsystem/PID Controller2/Tracking Mode'
//  '<S138>' : 'controladorpruebaio/Subsystem/PID Controller2/Tracking Mode Sum'
//  '<S139>' : 'controladorpruebaio/Subsystem/PID Controller2/Tsamp - Integral'
//  '<S140>' : 'controladorpruebaio/Subsystem/PID Controller2/Tsamp - Ngain'
//  '<S141>' : 'controladorpruebaio/Subsystem/PID Controller2/postSat Signal'
//  '<S142>' : 'controladorpruebaio/Subsystem/PID Controller2/preInt Signal'
//  '<S143>' : 'controladorpruebaio/Subsystem/PID Controller2/preSat Signal'
//  '<S144>' : 'controladorpruebaio/Subsystem/PID Controller2/Anti-windup/Disabled'
//  '<S145>' : 'controladorpruebaio/Subsystem/PID Controller2/D Gain/Disabled'
//  '<S146>' : 'controladorpruebaio/Subsystem/PID Controller2/External Derivative/Disabled'
//  '<S147>' : 'controladorpruebaio/Subsystem/PID Controller2/Filter/Disabled'
//  '<S148>' : 'controladorpruebaio/Subsystem/PID Controller2/Filter ICs/Disabled'
//  '<S149>' : 'controladorpruebaio/Subsystem/PID Controller2/I Gain/Disabled'
//  '<S150>' : 'controladorpruebaio/Subsystem/PID Controller2/Ideal P Gain/Passthrough'
//  '<S151>' : 'controladorpruebaio/Subsystem/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S152>' : 'controladorpruebaio/Subsystem/PID Controller2/Integrator/Disabled'
//  '<S153>' : 'controladorpruebaio/Subsystem/PID Controller2/Integrator ICs/Disabled'
//  '<S154>' : 'controladorpruebaio/Subsystem/PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S155>' : 'controladorpruebaio/Subsystem/PID Controller2/N Gain/Disabled'
//  '<S156>' : 'controladorpruebaio/Subsystem/PID Controller2/P Copy/Disabled'
//  '<S157>' : 'controladorpruebaio/Subsystem/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S158>' : 'controladorpruebaio/Subsystem/PID Controller2/Reset Signal/Disabled'
//  '<S159>' : 'controladorpruebaio/Subsystem/PID Controller2/Saturation/Enabled'
//  '<S160>' : 'controladorpruebaio/Subsystem/PID Controller2/Saturation Fdbk/Disabled'
//  '<S161>' : 'controladorpruebaio/Subsystem/PID Controller2/Sum/Passthrough_P'
//  '<S162>' : 'controladorpruebaio/Subsystem/PID Controller2/Sum Fdbk/Disabled'
//  '<S163>' : 'controladorpruebaio/Subsystem/PID Controller2/Tracking Mode/Disabled'
//  '<S164>' : 'controladorpruebaio/Subsystem/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S165>' : 'controladorpruebaio/Subsystem/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S166>' : 'controladorpruebaio/Subsystem/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S167>' : 'controladorpruebaio/Subsystem/PID Controller2/postSat Signal/Forward_Path'
//  '<S168>' : 'controladorpruebaio/Subsystem/PID Controller2/preInt Signal/Internal PreInt'
//  '<S169>' : 'controladorpruebaio/Subsystem/PID Controller2/preSat Signal/Forward_Path'
//  '<S170>' : 'controladorpruebaio/Subsystem/PID Controller3/Anti-windup'
//  '<S171>' : 'controladorpruebaio/Subsystem/PID Controller3/D Gain'
//  '<S172>' : 'controladorpruebaio/Subsystem/PID Controller3/External Derivative'
//  '<S173>' : 'controladorpruebaio/Subsystem/PID Controller3/Filter'
//  '<S174>' : 'controladorpruebaio/Subsystem/PID Controller3/Filter ICs'
//  '<S175>' : 'controladorpruebaio/Subsystem/PID Controller3/I Gain'
//  '<S176>' : 'controladorpruebaio/Subsystem/PID Controller3/Ideal P Gain'
//  '<S177>' : 'controladorpruebaio/Subsystem/PID Controller3/Ideal P Gain Fdbk'
//  '<S178>' : 'controladorpruebaio/Subsystem/PID Controller3/Integrator'
//  '<S179>' : 'controladorpruebaio/Subsystem/PID Controller3/Integrator ICs'
//  '<S180>' : 'controladorpruebaio/Subsystem/PID Controller3/N Copy'
//  '<S181>' : 'controladorpruebaio/Subsystem/PID Controller3/N Gain'
//  '<S182>' : 'controladorpruebaio/Subsystem/PID Controller3/P Copy'
//  '<S183>' : 'controladorpruebaio/Subsystem/PID Controller3/Parallel P Gain'
//  '<S184>' : 'controladorpruebaio/Subsystem/PID Controller3/Reset Signal'
//  '<S185>' : 'controladorpruebaio/Subsystem/PID Controller3/Saturation'
//  '<S186>' : 'controladorpruebaio/Subsystem/PID Controller3/Saturation Fdbk'
//  '<S187>' : 'controladorpruebaio/Subsystem/PID Controller3/Sum'
//  '<S188>' : 'controladorpruebaio/Subsystem/PID Controller3/Sum Fdbk'
//  '<S189>' : 'controladorpruebaio/Subsystem/PID Controller3/Tracking Mode'
//  '<S190>' : 'controladorpruebaio/Subsystem/PID Controller3/Tracking Mode Sum'
//  '<S191>' : 'controladorpruebaio/Subsystem/PID Controller3/Tsamp - Integral'
//  '<S192>' : 'controladorpruebaio/Subsystem/PID Controller3/Tsamp - Ngain'
//  '<S193>' : 'controladorpruebaio/Subsystem/PID Controller3/postSat Signal'
//  '<S194>' : 'controladorpruebaio/Subsystem/PID Controller3/preInt Signal'
//  '<S195>' : 'controladorpruebaio/Subsystem/PID Controller3/preSat Signal'
//  '<S196>' : 'controladorpruebaio/Subsystem/PID Controller3/Anti-windup/Back Calculation'
//  '<S197>' : 'controladorpruebaio/Subsystem/PID Controller3/D Gain/Internal Parameters'
//  '<S198>' : 'controladorpruebaio/Subsystem/PID Controller3/External Derivative/Error'
//  '<S199>' : 'controladorpruebaio/Subsystem/PID Controller3/Filter/Differentiator'
//  '<S200>' : 'controladorpruebaio/Subsystem/PID Controller3/Filter/Differentiator/Tsamp'
//  '<S201>' : 'controladorpruebaio/Subsystem/PID Controller3/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S202>' : 'controladorpruebaio/Subsystem/PID Controller3/Filter ICs/Internal IC - Differentiator'
//  '<S203>' : 'controladorpruebaio/Subsystem/PID Controller3/I Gain/Internal Parameters'
//  '<S204>' : 'controladorpruebaio/Subsystem/PID Controller3/Ideal P Gain/Passthrough'
//  '<S205>' : 'controladorpruebaio/Subsystem/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S206>' : 'controladorpruebaio/Subsystem/PID Controller3/Integrator/Discrete'
//  '<S207>' : 'controladorpruebaio/Subsystem/PID Controller3/Integrator ICs/Internal IC'
//  '<S208>' : 'controladorpruebaio/Subsystem/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S209>' : 'controladorpruebaio/Subsystem/PID Controller3/N Gain/Passthrough'
//  '<S210>' : 'controladorpruebaio/Subsystem/PID Controller3/P Copy/Disabled'
//  '<S211>' : 'controladorpruebaio/Subsystem/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S212>' : 'controladorpruebaio/Subsystem/PID Controller3/Reset Signal/Disabled'
//  '<S213>' : 'controladorpruebaio/Subsystem/PID Controller3/Saturation/Enabled'
//  '<S214>' : 'controladorpruebaio/Subsystem/PID Controller3/Saturation Fdbk/Disabled'
//  '<S215>' : 'controladorpruebaio/Subsystem/PID Controller3/Sum/Sum_PID'
//  '<S216>' : 'controladorpruebaio/Subsystem/PID Controller3/Sum Fdbk/Disabled'
//  '<S217>' : 'controladorpruebaio/Subsystem/PID Controller3/Tracking Mode/Disabled'
//  '<S218>' : 'controladorpruebaio/Subsystem/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S219>' : 'controladorpruebaio/Subsystem/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S220>' : 'controladorpruebaio/Subsystem/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S221>' : 'controladorpruebaio/Subsystem/PID Controller3/postSat Signal/Forward_Path'
//  '<S222>' : 'controladorpruebaio/Subsystem/PID Controller3/preInt Signal/Internal PreInt'
//  '<S223>' : 'controladorpruebaio/Subsystem/PID Controller3/preSat Signal/Forward_Path'
//  '<S224>' : 'controladorpruebaio/Vehicle Attitude/PX4 uORB Read'
//  '<S225>' : 'controladorpruebaio/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // controladorpruebaio_h_

//
// File trailer for generated code.
//
// [EOF]
//
