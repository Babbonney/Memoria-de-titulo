//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: multipid.h
//
// Code generated for Simulink model 'multipid'.
//
// Model version                  : 12.33
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jan 28 12:51:51 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef multipid_h_
#define multipid_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_Actuators.h"
#include "MW_uORB_Read.h"
#include "multipid_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/input_rc.h>

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
struct B_multipid_T {
  px4_Bus_vehicle_odometry In1;        // '<S615>/In1'
  px4_Bus_vehicle_odometry r;
  px4_Bus_input_rc In1_k;              // '<S118>/In1'
  px4_Bus_input_rc r1;
  real32_T motorValues[12];
  real32_T motorValues_m[12];
  real32_T servoValues[8];
  real_T y;                            // '<Root>/MATLAB Function1'
  real32_T RateTransition;             // '<S3>/Rate Transition'
  real32_T rollspeed;                  // '<S9>/Signal Copy'
  real32_T RateTransition1;            // '<S3>/Rate Transition1'
  real32_T pitchspeed;                 // '<S9>/Signal Copy1'
  real32_T yawspeed;                   // '<S9>/Signal Copy2'
  real32_T TmpSignalConversionAt_asyncqueu[4];
  // '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To Workspace4Inport1' 
  real32_T M1;                         // '<Root>/MATLAB Function'
  real32_T M2;                         // '<Root>/MATLAB Function'
  real32_T M3;                         // '<Root>/MATLAB Function'
  real32_T M4;                         // '<Root>/MATLAB Function'
  real32_T Product2;                   // '<Root>/Product2'
  real32_T Sum_h;                      // '<S167>/Sum'
  real32_T Tsamp;                      // '<S153>/Tsamp'
  real32_T Saturation;                 // '<S165>/Saturation'
  real32_T Product3;                   // '<Root>/Product3'
  real32_T Sum_o;                      // '<S275>/Sum'
  real32_T Tsamp_j;                    // '<S261>/Tsamp'
  real32_T Saturation_o;               // '<S273>/Saturation'
  real32_T Product;                    // '<Root>/Product'
  real32_T Sum_a;                      // '<S221>/Sum'
  real32_T Tsamp_p;                    // '<S207>/Tsamp'
  real32_T Saturation_m;               // '<S219>/Saturation'
  real32_T Sum_g;                      // '<S332>/Sum'
  real32_T Tsamp_i;                    // '<S318>/Tsamp'
  real32_T Saturation_i;               // '<S330>/Saturation'
  real32_T Sum_k;                      // '<S386>/Sum'
  real32_T Tsamp_f;                    // '<S372>/Tsamp'
  real32_T Saturation_n;               // '<S384>/Saturation'
};

// Block states (default storage) for system '<Root>'
struct DW_multipid_T {
  px4_internal_block_PX4Actuato_T obj; // '<Root>/PX4 Actuator Write'
  px4_internal_block_Subscriber_T obj_c;// '<S614>/SourceBlock'
  px4_internal_block_Subscriber_T obj_l;// '<S117>/SourceBlock'
  real32_T Integrator_DSTATE;          // '<S158>/Integrator'
  real32_T UD_DSTATE;                  // '<S151>/UD'
  real32_T Integrator_DSTATE_f;        // '<S266>/Integrator'
  real32_T UD_DSTATE_l;                // '<S259>/UD'
  real32_T Integrator_DSTATE_n;        // '<S212>/Integrator'
  real32_T UD_DSTATE_a;                // '<S205>/UD'
  real32_T Integrator_DSTATE_fy;       // '<S323>/Integrator'
  real32_T UD_DSTATE_k;                // '<S316>/UD'
  real32_T Integrator_DSTATE_j;        // '<S377>/Integrator'
  real32_T UD_DSTATE_d;                // '<S370>/UD'
  real32_T Integrator_DSTATE_jr;       // '<S431>/Integrator'
  real32_T UD_DSTATE_b;                // '<S424>/UD'
  real32_T Integrator_DSTATE_i;        // '<S488>/Integrator'
  real32_T UD_DSTATE_du;               // '<S481>/UD'
  real32_T Integrator_DSTATE_o;        // '<S542>/Integrator'
  real32_T UD_DSTATE_do;               // '<S535>/UD'
  real32_T Integrator_DSTATE_iu;       // '<S596>/Integrator'
  real32_T UD_DSTATE_h;                // '<S589>/UD'
  real32_T RateTransition_Buffer0;     // '<S3>/Rate Transition'
  real32_T RateTransition1_Buffer0;    // '<S3>/Rate Transition1'
  real32_T TmpRTBAtProportionalGainInport1;// synthesized block
  real32_T TmpRTBAtProportionalGainInpor_b;// synthesized block
  int8_T EnabledSubsystem_SubsysRanBC; // '<S614>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_h;// '<S117>/Enabled Subsystem'
  boolean_T doneDoubleBufferReInit;    // '<Root>/quat2eul'
  boolean_T doneDoubleBufferReInit_e;  // '<Root>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_m;  // '<Root>/MATLAB Function'
};

// Parameters (default storage)
struct P_multipid_T_ {
  real32_T PIDController1_D;           // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S149>/Derivative Gain'

  real32_T PIDController4_D;           // Mask Parameter: PIDController4_D
                                          //  Referenced by: '<S257>/Derivative Gain'

  real32_T PIDController2_D;           // Mask Parameter: PIDController2_D
                                          //  Referenced by: '<S203>/Derivative Gain'

  real32_T PIDController1_D_j;         // Mask Parameter: PIDController1_D_j
                                          //  Referenced by: '<S314>/Derivative Gain'

  real32_T PIDController2_D_m;         // Mask Parameter: PIDController2_D_m
                                          //  Referenced by: '<S368>/Derivative Gain'

  real32_T PIDController3_D;           // Mask Parameter: PIDController3_D
                                          //  Referenced by: '<S422>/Derivative Gain'

  real32_T PIDController_D;            // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S479>/Derivative Gain'

  real32_T PIDController1_D_e;         // Mask Parameter: PIDController1_D_e
                                          //  Referenced by: '<S533>/Derivative Gain'

  real32_T PIDController2_D_d;         // Mask Parameter: PIDController2_D_d
                                          //  Referenced by: '<S587>/Derivative Gain'

  real32_T PIDController1_DifferentiatorIC;
                              // Mask Parameter: PIDController1_DifferentiatorIC
                                 //  Referenced by: '<S151>/UD'

  real32_T PIDController4_DifferentiatorIC;
                              // Mask Parameter: PIDController4_DifferentiatorIC
                                 //  Referenced by: '<S259>/UD'

  real32_T PIDController2_DifferentiatorIC;
                              // Mask Parameter: PIDController2_DifferentiatorIC
                                 //  Referenced by: '<S205>/UD'

  real32_T PIDController1_Differentiator_f;
                              // Mask Parameter: PIDController1_Differentiator_f
                                 //  Referenced by: '<S316>/UD'

  real32_T PIDController2_Differentiator_k;
                              // Mask Parameter: PIDController2_Differentiator_k
                                 //  Referenced by: '<S370>/UD'

  real32_T PIDController3_DifferentiatorIC;
                              // Mask Parameter: PIDController3_DifferentiatorIC
                                 //  Referenced by: '<S424>/UD'

  real32_T PIDController_DifferentiatorICP;
                              // Mask Parameter: PIDController_DifferentiatorICP
                                 //  Referenced by: '<S481>/UD'

  real32_T PIDController1_Differentiator_l;
                              // Mask Parameter: PIDController1_Differentiator_l
                                 //  Referenced by: '<S535>/UD'

  real32_T PIDController2_Differentiator_p;
                              // Mask Parameter: PIDController2_Differentiator_p
                                 //  Referenced by: '<S589>/UD'

  real32_T PIDController3_I;           // Mask Parameter: PIDController3_I
                                          //  Referenced by: '<S428>/Integral Gain'

  real32_T PIDController2_I;           // Mask Parameter: PIDController2_I
                                          //  Referenced by: '<S374>/Integral Gain'

  real32_T PIDController1_I;           // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S320>/Integral Gain'

  real32_T PIDController2_I_p;         // Mask Parameter: PIDController2_I_p
                                          //  Referenced by: '<S209>/Integral Gain'

  real32_T PIDController2_I_h;         // Mask Parameter: PIDController2_I_h
                                          //  Referenced by: '<S593>/Integral Gain'

  real32_T PIDController4_I;           // Mask Parameter: PIDController4_I
                                          //  Referenced by: '<S263>/Integral Gain'

  real32_T PIDController1_I_d;         // Mask Parameter: PIDController1_I_d
                                          //  Referenced by: '<S539>/Integral Gain'

  real32_T PIDController1_I_h;         // Mask Parameter: PIDController1_I_h
                                          //  Referenced by: '<S155>/Integral Gain'

  real32_T PIDController_I;            // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S485>/Integral Gain'

  real32_T PIDController1_InitialCondition;
                              // Mask Parameter: PIDController1_InitialCondition
                                 //  Referenced by: '<S158>/Integrator'

  real32_T PIDController4_InitialCondition;
                              // Mask Parameter: PIDController4_InitialCondition
                                 //  Referenced by: '<S266>/Integrator'

  real32_T PIDController2_InitialCondition;
                              // Mask Parameter: PIDController2_InitialCondition
                                 //  Referenced by: '<S212>/Integrator'

  real32_T PIDController1_InitialConditi_l;
                              // Mask Parameter: PIDController1_InitialConditi_l
                                 //  Referenced by: '<S323>/Integrator'

  real32_T PIDController2_InitialConditi_j;
                              // Mask Parameter: PIDController2_InitialConditi_j
                                 //  Referenced by: '<S377>/Integrator'

  real32_T PIDController3_InitialCondition;
                              // Mask Parameter: PIDController3_InitialCondition
                                 //  Referenced by: '<S431>/Integrator'

  real32_T PIDController_InitialConditionF;
                              // Mask Parameter: PIDController_InitialConditionF
                                 //  Referenced by: '<S488>/Integrator'

  real32_T PIDController1_InitialCondit_ls;
                              // Mask Parameter: PIDController1_InitialCondit_ls
                                 //  Referenced by: '<S542>/Integrator'

  real32_T PIDController2_InitialConditi_k;
                              // Mask Parameter: PIDController2_InitialConditi_k
                                 //  Referenced by: '<S596>/Integrator'

  real32_T PIDController3_Kb;          // Mask Parameter: PIDController3_Kb
                                          //  Referenced by: '<S421>/Kb'

  real32_T PIDController2_Kb;          // Mask Parameter: PIDController2_Kb
                                          //  Referenced by: '<S367>/Kb'

  real32_T PIDController1_Kb;          // Mask Parameter: PIDController1_Kb
                                          //  Referenced by: '<S313>/Kb'

  real32_T PIDController2_Kb_j;        // Mask Parameter: PIDController2_Kb_j
                                          //  Referenced by: '<S202>/Kb'

  real32_T PIDController4_Kb;          // Mask Parameter: PIDController4_Kb
                                          //  Referenced by: '<S256>/Kb'

  real32_T PIDController1_Kb_f;        // Mask Parameter: PIDController1_Kb_f
                                          //  Referenced by: '<S148>/Kb'

  real32_T PIDController1_LowerSaturationL;
                              // Mask Parameter: PIDController1_LowerSaturationL
                                 //  Referenced by: '<S165>/Saturation'

  real32_T PIDController4_LowerSaturationL;
                              // Mask Parameter: PIDController4_LowerSaturationL
                                 //  Referenced by: '<S273>/Saturation'

  real32_T PIDController2_LowerSaturationL;
                              // Mask Parameter: PIDController2_LowerSaturationL
                                 //  Referenced by: '<S219>/Saturation'

  real32_T PIDController1_LowerSaturatio_i;
                              // Mask Parameter: PIDController1_LowerSaturatio_i
                                 //  Referenced by: '<S330>/Saturation'

  real32_T PIDController2_LowerSaturatio_j;
                              // Mask Parameter: PIDController2_LowerSaturatio_j
                                 //  Referenced by: '<S384>/Saturation'

  real32_T PIDController3_LowerSaturationL;
                              // Mask Parameter: PIDController3_LowerSaturationL
                                 //  Referenced by: '<S438>/Saturation'

  real32_T PIDController_LowerSaturationLi;
                              // Mask Parameter: PIDController_LowerSaturationLi
                                 //  Referenced by: '<S54>/Saturation'

  real32_T PIDController2_LowerSaturatio_m;
                              // Mask Parameter: PIDController2_LowerSaturatio_m
                                 //  Referenced by: '<S106>/Saturation'

  real32_T PIDController1_P;           // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S163>/Proportional Gain'

  real32_T PIDController4_P;           // Mask Parameter: PIDController4_P
                                          //  Referenced by: '<S271>/Proportional Gain'

  real32_T PIDController2_P;           // Mask Parameter: PIDController2_P
                                          //  Referenced by: '<S217>/Proportional Gain'

  real32_T PIDController1_P_d;         // Mask Parameter: PIDController1_P_d
                                          //  Referenced by: '<S328>/Proportional Gain'

  real32_T PIDController2_P_p;         // Mask Parameter: PIDController2_P_p
                                          //  Referenced by: '<S382>/Proportional Gain'

  real32_T PIDController3_P;           // Mask Parameter: PIDController3_P
                                          //  Referenced by: '<S436>/Proportional Gain'

  real32_T PIDController_P;            // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S493>/Proportional Gain'

  real32_T PIDController1_P_o;         // Mask Parameter: PIDController1_P_o
                                          //  Referenced by: '<S547>/Proportional Gain'

  real32_T PIDController2_P_h;         // Mask Parameter: PIDController2_P_h
                                          //  Referenced by: '<S601>/Proportional Gain'

  real32_T PIDController_P_e;          // Mask Parameter: PIDController_P_e
                                          //  Referenced by: '<S52>/Proportional Gain'

  real32_T PIDController2_P_o;         // Mask Parameter: PIDController2_P_o
                                          //  Referenced by: '<S104>/Proportional Gain'

  real32_T PIDController1_UpperSaturationL;
                              // Mask Parameter: PIDController1_UpperSaturationL
                                 //  Referenced by: '<S165>/Saturation'

  real32_T PIDController4_UpperSaturationL;
                              // Mask Parameter: PIDController4_UpperSaturationL
                                 //  Referenced by: '<S273>/Saturation'

  real32_T PIDController2_UpperSaturationL;
                              // Mask Parameter: PIDController2_UpperSaturationL
                                 //  Referenced by: '<S219>/Saturation'

  real32_T PIDController1_UpperSaturatio_n;
                              // Mask Parameter: PIDController1_UpperSaturatio_n
                                 //  Referenced by: '<S330>/Saturation'

  real32_T PIDController2_UpperSaturatio_n;
                              // Mask Parameter: PIDController2_UpperSaturatio_n
                                 //  Referenced by: '<S384>/Saturation'

  real32_T PIDController3_UpperSaturationL;
                              // Mask Parameter: PIDController3_UpperSaturationL
                                 //  Referenced by: '<S438>/Saturation'

  real32_T PIDController_UpperSaturationLi;
                              // Mask Parameter: PIDController_UpperSaturationLi
                                 //  Referenced by: '<S54>/Saturation'

  real32_T PIDController2_UpperSaturatio_m;
                              // Mask Parameter: PIDController2_UpperSaturatio_m
                                 //  Referenced by: '<S106>/Saturation'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S615>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S614>/Constant'

  px4_Bus_input_rc Out1_Y0_l;          // Computed Parameter: Out1_Y0_l
                                          //  Referenced by: '<S118>/Out1'

  px4_Bus_input_rc Constant_Value_j;   // Computed Parameter: Constant_Value_j
                                          //  Referenced by: '<S117>/Constant'

  real32_T Switch_Threshold;           // Computed Parameter: Switch_Threshold
                                          //  Referenced by: '<Root>/Switch'

  real32_T RateTransition_InitialCondition;
                          // Computed Parameter: RateTransition_InitialCondition
                             //  Referenced by: '<S3>/Rate Transition'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S158>/Integrator'

  real32_T Tsamp_WtEt;                 // Computed Parameter: Tsamp_WtEt
                                          //  Referenced by: '<S153>/Tsamp'

  real32_T RateTransition1_InitialConditio;
                          // Computed Parameter: RateTransition1_InitialConditio
                             //  Referenced by: '<S3>/Rate Transition1'

  real32_T Integrator_gainval_n;     // Computed Parameter: Integrator_gainval_n
                                        //  Referenced by: '<S266>/Integrator'

  real32_T Tsamp_WtEt_f;               // Computed Parameter: Tsamp_WtEt_f
                                          //  Referenced by: '<S261>/Tsamp'

  real32_T DeadZone3_Start;            // Computed Parameter: DeadZone3_Start
                                          //  Referenced by: '<S6>/Dead Zone3'

  real32_T DeadZone3_End;              // Computed Parameter: DeadZone3_End
                                          //  Referenced by: '<S6>/Dead Zone3'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S6>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S6>/Saturation3'

  real32_T Integrator_gainval_g;     // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S212>/Integrator'

  real32_T Tsamp_WtEt_fp;              // Computed Parameter: Tsamp_WtEt_fp
                                          //  Referenced by: '<S207>/Tsamp'

  real32_T Integrator_gainval_i;     // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S323>/Integrator'

  real32_T Tsamp_WtEt_fi;              // Computed Parameter: Tsamp_WtEt_fi
                                          //  Referenced by: '<S318>/Tsamp'

  real32_T Integrator_gainval_p;     // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S377>/Integrator'

  real32_T Tsamp_WtEt_l;               // Computed Parameter: Tsamp_WtEt_l
                                          //  Referenced by: '<S372>/Tsamp'

  real32_T Integrator_gainval_na;   // Computed Parameter: Integrator_gainval_na
                                       //  Referenced by: '<S431>/Integrator'

  real32_T Tsamp_WtEt_n;               // Computed Parameter: Tsamp_WtEt_n
                                          //  Referenced by: '<S426>/Tsamp'

  real32_T Integrator_gainval_a;     // Computed Parameter: Integrator_gainval_a
                                        //  Referenced by: '<S488>/Integrator'

  real32_T Tsamp_WtEt_c;               // Computed Parameter: Tsamp_WtEt_c
                                          //  Referenced by: '<S483>/Tsamp'

  real32_T Integrator_gainval_nl;   // Computed Parameter: Integrator_gainval_nl
                                       //  Referenced by: '<S542>/Integrator'

  real32_T Tsamp_WtEt_g;               // Computed Parameter: Tsamp_WtEt_g
                                          //  Referenced by: '<S537>/Tsamp'

  real32_T Integrator_gainval_c;     // Computed Parameter: Integrator_gainval_c
                                        //  Referenced by: '<S596>/Integrator'

  real32_T Tsamp_WtEt_p;               // Computed Parameter: Tsamp_WtEt_p
                                          //  Referenced by: '<S591>/Tsamp'

  real32_T DeadZone2_Start;            // Computed Parameter: DeadZone2_Start
                                          //  Referenced by: '<S6>/Dead Zone2'

  real32_T DeadZone2_End;              // Computed Parameter: DeadZone2_End
                                          //  Referenced by: '<S6>/Dead Zone2'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S6>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S6>/Saturation2'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<Root>/Gain2'

  real32_T Saturation4_UpperSat;     // Computed Parameter: Saturation4_UpperSat
                                        //  Referenced by: '<Root>/Saturation4'

  real32_T Saturation4_LowerSat;     // Computed Parameter: Saturation4_LowerSat
                                        //  Referenced by: '<Root>/Saturation4'

  real32_T DeadZone_Start;             // Computed Parameter: DeadZone_Start
                                          //  Referenced by: '<S6>/Dead Zone'

  real32_T DeadZone_End;               // Computed Parameter: DeadZone_End
                                          //  Referenced by: '<S6>/Dead Zone'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S6>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S6>/Saturation'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<Root>/Gain'

  real32_T DeadZone1_Start;            // Computed Parameter: DeadZone1_Start
                                          //  Referenced by: '<S3>/Dead Zone1'

  real32_T DeadZone1_End;              // Computed Parameter: DeadZone1_End
                                          //  Referenced by: '<S3>/Dead Zone1'

  real32_T DeadZone1_Start_a;          // Computed Parameter: DeadZone1_Start_a
                                          //  Referenced by: '<S6>/Dead Zone1'

  real32_T DeadZone1_End_o;            // Computed Parameter: DeadZone1_End_o
                                          //  Referenced by: '<S6>/Dead Zone1'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S6>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S6>/Saturation1'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<Root>/Gain1'

  real32_T DeadZone_Start_i;           // Computed Parameter: DeadZone_Start_i
                                          //  Referenced by: '<S3>/Dead Zone'

  real32_T DeadZone_End_m;             // Computed Parameter: DeadZone_End_m
                                          //  Referenced by: '<S3>/Dead Zone'

  boolean_T Constant1_Value;           // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<Root>/Constant1'

  boolean_T Constant_Value_b;          // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<Root>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_multipid_T {
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

  extern P_multipid_T multipid_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_multipid_T multipid_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_multipid_T multipid_DW;

// External function called from main
#ifdef __cplusplus

extern "C"
{

#endif

  extern void multipid_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void multipid_initialize(void);
  extern void multipid_step0(void);    // Sample time: [0.001s, 0.0s]
  extern void multipid_step1(void);    // Sample time: [0.005s, 0.0s]
  extern void multipid_step(int_T tid);
  extern void multipid_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_multipid_T *const multipid_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S4>/Bitwise Operator' : Unused code path elimination
//  Block '<S4>/Data Type Conversion' : Unused code path elimination
//  Block '<S4>/Data Type Conversion1' : Unused code path elimination
//  Block '<S4>/Data Type Conversion2' : Unused code path elimination
//  Block '<S4>/Gain' : Unused code path elimination
//  Block '<S4>/Gain1' : Unused code path elimination
//  Block '<S117>/NOT' : Unused code path elimination
//  Block '<S4>/Signal Copy5' : Unused code path elimination
//  Block '<S4>/Signal Copy6' : Unused code path elimination
//  Block '<S151>/DTDup' : Unused code path elimination
//  Block '<S205>/DTDup' : Unused code path elimination
//  Block '<S259>/DTDup' : Unused code path elimination
//  Block '<S316>/DTDup' : Unused code path elimination
//  Block '<S370>/DTDup' : Unused code path elimination
//  Block '<S424>/DTDup' : Unused code path elimination
//  Block '<S481>/DTDup' : Unused code path elimination
//  Block '<S535>/DTDup' : Unused code path elimination
//  Block '<S589>/DTDup' : Unused code path elimination
//  Block '<S614>/NOT' : Unused code path elimination
//  Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S4>/Signal Copy' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy1' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy2' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy3' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy4' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy7' : Eliminate redundant signal conversion block


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
//  '<Root>' : 'multipid'
//  '<S1>'   : 'multipid/MATLAB Function'
//  '<S2>'   : 'multipid/MATLAB Function1'
//  '<S3>'   : 'multipid/P roll pitch'
//  '<S4>'   : 'multipid/Radio Control Transmitter'
//  '<S5>'   : 'multipid/Subsystem'
//  '<S6>'   : 'multipid/Subsystem1'
//  '<S7>'   : 'multipid/Subsystem2'
//  '<S8>'   : 'multipid/Subsystem3'
//  '<S9>'   : 'multipid/Vehicle Attitude'
//  '<S10>'  : 'multipid/quat2eul'
//  '<S11>'  : 'multipid/P roll pitch/PID Controller'
//  '<S12>'  : 'multipid/P roll pitch/PID Controller2'
//  '<S13>'  : 'multipid/P roll pitch/PID Controller/Anti-windup'
//  '<S14>'  : 'multipid/P roll pitch/PID Controller/D Gain'
//  '<S15>'  : 'multipid/P roll pitch/PID Controller/External Derivative'
//  '<S16>'  : 'multipid/P roll pitch/PID Controller/Filter'
//  '<S17>'  : 'multipid/P roll pitch/PID Controller/Filter ICs'
//  '<S18>'  : 'multipid/P roll pitch/PID Controller/I Gain'
//  '<S19>'  : 'multipid/P roll pitch/PID Controller/Ideal P Gain'
//  '<S20>'  : 'multipid/P roll pitch/PID Controller/Ideal P Gain Fdbk'
//  '<S21>'  : 'multipid/P roll pitch/PID Controller/Integrator'
//  '<S22>'  : 'multipid/P roll pitch/PID Controller/Integrator ICs'
//  '<S23>'  : 'multipid/P roll pitch/PID Controller/N Copy'
//  '<S24>'  : 'multipid/P roll pitch/PID Controller/N Gain'
//  '<S25>'  : 'multipid/P roll pitch/PID Controller/P Copy'
//  '<S26>'  : 'multipid/P roll pitch/PID Controller/Parallel P Gain'
//  '<S27>'  : 'multipid/P roll pitch/PID Controller/Reset Signal'
//  '<S28>'  : 'multipid/P roll pitch/PID Controller/Saturation'
//  '<S29>'  : 'multipid/P roll pitch/PID Controller/Saturation Fdbk'
//  '<S30>'  : 'multipid/P roll pitch/PID Controller/Sum'
//  '<S31>'  : 'multipid/P roll pitch/PID Controller/Sum Fdbk'
//  '<S32>'  : 'multipid/P roll pitch/PID Controller/Tracking Mode'
//  '<S33>'  : 'multipid/P roll pitch/PID Controller/Tracking Mode Sum'
//  '<S34>'  : 'multipid/P roll pitch/PID Controller/Tsamp - Integral'
//  '<S35>'  : 'multipid/P roll pitch/PID Controller/Tsamp - Ngain'
//  '<S36>'  : 'multipid/P roll pitch/PID Controller/postSat Signal'
//  '<S37>'  : 'multipid/P roll pitch/PID Controller/preInt Signal'
//  '<S38>'  : 'multipid/P roll pitch/PID Controller/preSat Signal'
//  '<S39>'  : 'multipid/P roll pitch/PID Controller/Anti-windup/Disabled'
//  '<S40>'  : 'multipid/P roll pitch/PID Controller/D Gain/Disabled'
//  '<S41>'  : 'multipid/P roll pitch/PID Controller/External Derivative/Disabled'
//  '<S42>'  : 'multipid/P roll pitch/PID Controller/Filter/Disabled'
//  '<S43>'  : 'multipid/P roll pitch/PID Controller/Filter ICs/Disabled'
//  '<S44>'  : 'multipid/P roll pitch/PID Controller/I Gain/Disabled'
//  '<S45>'  : 'multipid/P roll pitch/PID Controller/Ideal P Gain/Passthrough'
//  '<S46>'  : 'multipid/P roll pitch/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S47>'  : 'multipid/P roll pitch/PID Controller/Integrator/Disabled'
//  '<S48>'  : 'multipid/P roll pitch/PID Controller/Integrator ICs/Disabled'
//  '<S49>'  : 'multipid/P roll pitch/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S50>'  : 'multipid/P roll pitch/PID Controller/N Gain/Disabled'
//  '<S51>'  : 'multipid/P roll pitch/PID Controller/P Copy/Disabled'
//  '<S52>'  : 'multipid/P roll pitch/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S53>'  : 'multipid/P roll pitch/PID Controller/Reset Signal/Disabled'
//  '<S54>'  : 'multipid/P roll pitch/PID Controller/Saturation/Enabled'
//  '<S55>'  : 'multipid/P roll pitch/PID Controller/Saturation Fdbk/Disabled'
//  '<S56>'  : 'multipid/P roll pitch/PID Controller/Sum/Passthrough_P'
//  '<S57>'  : 'multipid/P roll pitch/PID Controller/Sum Fdbk/Disabled'
//  '<S58>'  : 'multipid/P roll pitch/PID Controller/Tracking Mode/Disabled'
//  '<S59>'  : 'multipid/P roll pitch/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S60>'  : 'multipid/P roll pitch/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S61>'  : 'multipid/P roll pitch/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S62>'  : 'multipid/P roll pitch/PID Controller/postSat Signal/Forward_Path'
//  '<S63>'  : 'multipid/P roll pitch/PID Controller/preInt Signal/Internal PreInt'
//  '<S64>'  : 'multipid/P roll pitch/PID Controller/preSat Signal/Forward_Path'
//  '<S65>'  : 'multipid/P roll pitch/PID Controller2/Anti-windup'
//  '<S66>'  : 'multipid/P roll pitch/PID Controller2/D Gain'
//  '<S67>'  : 'multipid/P roll pitch/PID Controller2/External Derivative'
//  '<S68>'  : 'multipid/P roll pitch/PID Controller2/Filter'
//  '<S69>'  : 'multipid/P roll pitch/PID Controller2/Filter ICs'
//  '<S70>'  : 'multipid/P roll pitch/PID Controller2/I Gain'
//  '<S71>'  : 'multipid/P roll pitch/PID Controller2/Ideal P Gain'
//  '<S72>'  : 'multipid/P roll pitch/PID Controller2/Ideal P Gain Fdbk'
//  '<S73>'  : 'multipid/P roll pitch/PID Controller2/Integrator'
//  '<S74>'  : 'multipid/P roll pitch/PID Controller2/Integrator ICs'
//  '<S75>'  : 'multipid/P roll pitch/PID Controller2/N Copy'
//  '<S76>'  : 'multipid/P roll pitch/PID Controller2/N Gain'
//  '<S77>'  : 'multipid/P roll pitch/PID Controller2/P Copy'
//  '<S78>'  : 'multipid/P roll pitch/PID Controller2/Parallel P Gain'
//  '<S79>'  : 'multipid/P roll pitch/PID Controller2/Reset Signal'
//  '<S80>'  : 'multipid/P roll pitch/PID Controller2/Saturation'
//  '<S81>'  : 'multipid/P roll pitch/PID Controller2/Saturation Fdbk'
//  '<S82>'  : 'multipid/P roll pitch/PID Controller2/Sum'
//  '<S83>'  : 'multipid/P roll pitch/PID Controller2/Sum Fdbk'
//  '<S84>'  : 'multipid/P roll pitch/PID Controller2/Tracking Mode'
//  '<S85>'  : 'multipid/P roll pitch/PID Controller2/Tracking Mode Sum'
//  '<S86>'  : 'multipid/P roll pitch/PID Controller2/Tsamp - Integral'
//  '<S87>'  : 'multipid/P roll pitch/PID Controller2/Tsamp - Ngain'
//  '<S88>'  : 'multipid/P roll pitch/PID Controller2/postSat Signal'
//  '<S89>'  : 'multipid/P roll pitch/PID Controller2/preInt Signal'
//  '<S90>'  : 'multipid/P roll pitch/PID Controller2/preSat Signal'
//  '<S91>'  : 'multipid/P roll pitch/PID Controller2/Anti-windup/Disabled'
//  '<S92>'  : 'multipid/P roll pitch/PID Controller2/D Gain/Disabled'
//  '<S93>'  : 'multipid/P roll pitch/PID Controller2/External Derivative/Disabled'
//  '<S94>'  : 'multipid/P roll pitch/PID Controller2/Filter/Disabled'
//  '<S95>'  : 'multipid/P roll pitch/PID Controller2/Filter ICs/Disabled'
//  '<S96>'  : 'multipid/P roll pitch/PID Controller2/I Gain/Disabled'
//  '<S97>'  : 'multipid/P roll pitch/PID Controller2/Ideal P Gain/Passthrough'
//  '<S98>'  : 'multipid/P roll pitch/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S99>'  : 'multipid/P roll pitch/PID Controller2/Integrator/Disabled'
//  '<S100>' : 'multipid/P roll pitch/PID Controller2/Integrator ICs/Disabled'
//  '<S101>' : 'multipid/P roll pitch/PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S102>' : 'multipid/P roll pitch/PID Controller2/N Gain/Disabled'
//  '<S103>' : 'multipid/P roll pitch/PID Controller2/P Copy/Disabled'
//  '<S104>' : 'multipid/P roll pitch/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S105>' : 'multipid/P roll pitch/PID Controller2/Reset Signal/Disabled'
//  '<S106>' : 'multipid/P roll pitch/PID Controller2/Saturation/Enabled'
//  '<S107>' : 'multipid/P roll pitch/PID Controller2/Saturation Fdbk/Disabled'
//  '<S108>' : 'multipid/P roll pitch/PID Controller2/Sum/Passthrough_P'
//  '<S109>' : 'multipid/P roll pitch/PID Controller2/Sum Fdbk/Disabled'
//  '<S110>' : 'multipid/P roll pitch/PID Controller2/Tracking Mode/Disabled'
//  '<S111>' : 'multipid/P roll pitch/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S112>' : 'multipid/P roll pitch/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S113>' : 'multipid/P roll pitch/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S114>' : 'multipid/P roll pitch/PID Controller2/postSat Signal/Forward_Path'
//  '<S115>' : 'multipid/P roll pitch/PID Controller2/preInt Signal/Internal PreInt'
//  '<S116>' : 'multipid/P roll pitch/PID Controller2/preSat Signal/Forward_Path'
//  '<S117>' : 'multipid/Radio Control Transmitter/PX4 uORB Read'
//  '<S118>' : 'multipid/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S119>' : 'multipid/Subsystem/PID Controller1'
//  '<S120>' : 'multipid/Subsystem/PID Controller2'
//  '<S121>' : 'multipid/Subsystem/PID Controller4'
//  '<S122>' : 'multipid/Subsystem/PID Controller1/Anti-windup'
//  '<S123>' : 'multipid/Subsystem/PID Controller1/D Gain'
//  '<S124>' : 'multipid/Subsystem/PID Controller1/External Derivative'
//  '<S125>' : 'multipid/Subsystem/PID Controller1/Filter'
//  '<S126>' : 'multipid/Subsystem/PID Controller1/Filter ICs'
//  '<S127>' : 'multipid/Subsystem/PID Controller1/I Gain'
//  '<S128>' : 'multipid/Subsystem/PID Controller1/Ideal P Gain'
//  '<S129>' : 'multipid/Subsystem/PID Controller1/Ideal P Gain Fdbk'
//  '<S130>' : 'multipid/Subsystem/PID Controller1/Integrator'
//  '<S131>' : 'multipid/Subsystem/PID Controller1/Integrator ICs'
//  '<S132>' : 'multipid/Subsystem/PID Controller1/N Copy'
//  '<S133>' : 'multipid/Subsystem/PID Controller1/N Gain'
//  '<S134>' : 'multipid/Subsystem/PID Controller1/P Copy'
//  '<S135>' : 'multipid/Subsystem/PID Controller1/Parallel P Gain'
//  '<S136>' : 'multipid/Subsystem/PID Controller1/Reset Signal'
//  '<S137>' : 'multipid/Subsystem/PID Controller1/Saturation'
//  '<S138>' : 'multipid/Subsystem/PID Controller1/Saturation Fdbk'
//  '<S139>' : 'multipid/Subsystem/PID Controller1/Sum'
//  '<S140>' : 'multipid/Subsystem/PID Controller1/Sum Fdbk'
//  '<S141>' : 'multipid/Subsystem/PID Controller1/Tracking Mode'
//  '<S142>' : 'multipid/Subsystem/PID Controller1/Tracking Mode Sum'
//  '<S143>' : 'multipid/Subsystem/PID Controller1/Tsamp - Integral'
//  '<S144>' : 'multipid/Subsystem/PID Controller1/Tsamp - Ngain'
//  '<S145>' : 'multipid/Subsystem/PID Controller1/postSat Signal'
//  '<S146>' : 'multipid/Subsystem/PID Controller1/preInt Signal'
//  '<S147>' : 'multipid/Subsystem/PID Controller1/preSat Signal'
//  '<S148>' : 'multipid/Subsystem/PID Controller1/Anti-windup/Back Calculation'
//  '<S149>' : 'multipid/Subsystem/PID Controller1/D Gain/Internal Parameters'
//  '<S150>' : 'multipid/Subsystem/PID Controller1/External Derivative/Error'
//  '<S151>' : 'multipid/Subsystem/PID Controller1/Filter/Differentiator'
//  '<S152>' : 'multipid/Subsystem/PID Controller1/Filter/Differentiator/Tsamp'
//  '<S153>' : 'multipid/Subsystem/PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S154>' : 'multipid/Subsystem/PID Controller1/Filter ICs/Internal IC - Differentiator'
//  '<S155>' : 'multipid/Subsystem/PID Controller1/I Gain/Internal Parameters'
//  '<S156>' : 'multipid/Subsystem/PID Controller1/Ideal P Gain/Passthrough'
//  '<S157>' : 'multipid/Subsystem/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S158>' : 'multipid/Subsystem/PID Controller1/Integrator/Discrete'
//  '<S159>' : 'multipid/Subsystem/PID Controller1/Integrator ICs/Internal IC'
//  '<S160>' : 'multipid/Subsystem/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S161>' : 'multipid/Subsystem/PID Controller1/N Gain/Passthrough'
//  '<S162>' : 'multipid/Subsystem/PID Controller1/P Copy/Disabled'
//  '<S163>' : 'multipid/Subsystem/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S164>' : 'multipid/Subsystem/PID Controller1/Reset Signal/Disabled'
//  '<S165>' : 'multipid/Subsystem/PID Controller1/Saturation/Enabled'
//  '<S166>' : 'multipid/Subsystem/PID Controller1/Saturation Fdbk/Disabled'
//  '<S167>' : 'multipid/Subsystem/PID Controller1/Sum/Sum_PID'
//  '<S168>' : 'multipid/Subsystem/PID Controller1/Sum Fdbk/Disabled'
//  '<S169>' : 'multipid/Subsystem/PID Controller1/Tracking Mode/Disabled'
//  '<S170>' : 'multipid/Subsystem/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S171>' : 'multipid/Subsystem/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S172>' : 'multipid/Subsystem/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S173>' : 'multipid/Subsystem/PID Controller1/postSat Signal/Forward_Path'
//  '<S174>' : 'multipid/Subsystem/PID Controller1/preInt Signal/Internal PreInt'
//  '<S175>' : 'multipid/Subsystem/PID Controller1/preSat Signal/Forward_Path'
//  '<S176>' : 'multipid/Subsystem/PID Controller2/Anti-windup'
//  '<S177>' : 'multipid/Subsystem/PID Controller2/D Gain'
//  '<S178>' : 'multipid/Subsystem/PID Controller2/External Derivative'
//  '<S179>' : 'multipid/Subsystem/PID Controller2/Filter'
//  '<S180>' : 'multipid/Subsystem/PID Controller2/Filter ICs'
//  '<S181>' : 'multipid/Subsystem/PID Controller2/I Gain'
//  '<S182>' : 'multipid/Subsystem/PID Controller2/Ideal P Gain'
//  '<S183>' : 'multipid/Subsystem/PID Controller2/Ideal P Gain Fdbk'
//  '<S184>' : 'multipid/Subsystem/PID Controller2/Integrator'
//  '<S185>' : 'multipid/Subsystem/PID Controller2/Integrator ICs'
//  '<S186>' : 'multipid/Subsystem/PID Controller2/N Copy'
//  '<S187>' : 'multipid/Subsystem/PID Controller2/N Gain'
//  '<S188>' : 'multipid/Subsystem/PID Controller2/P Copy'
//  '<S189>' : 'multipid/Subsystem/PID Controller2/Parallel P Gain'
//  '<S190>' : 'multipid/Subsystem/PID Controller2/Reset Signal'
//  '<S191>' : 'multipid/Subsystem/PID Controller2/Saturation'
//  '<S192>' : 'multipid/Subsystem/PID Controller2/Saturation Fdbk'
//  '<S193>' : 'multipid/Subsystem/PID Controller2/Sum'
//  '<S194>' : 'multipid/Subsystem/PID Controller2/Sum Fdbk'
//  '<S195>' : 'multipid/Subsystem/PID Controller2/Tracking Mode'
//  '<S196>' : 'multipid/Subsystem/PID Controller2/Tracking Mode Sum'
//  '<S197>' : 'multipid/Subsystem/PID Controller2/Tsamp - Integral'
//  '<S198>' : 'multipid/Subsystem/PID Controller2/Tsamp - Ngain'
//  '<S199>' : 'multipid/Subsystem/PID Controller2/postSat Signal'
//  '<S200>' : 'multipid/Subsystem/PID Controller2/preInt Signal'
//  '<S201>' : 'multipid/Subsystem/PID Controller2/preSat Signal'
//  '<S202>' : 'multipid/Subsystem/PID Controller2/Anti-windup/Back Calculation'
//  '<S203>' : 'multipid/Subsystem/PID Controller2/D Gain/Internal Parameters'
//  '<S204>' : 'multipid/Subsystem/PID Controller2/External Derivative/Error'
//  '<S205>' : 'multipid/Subsystem/PID Controller2/Filter/Differentiator'
//  '<S206>' : 'multipid/Subsystem/PID Controller2/Filter/Differentiator/Tsamp'
//  '<S207>' : 'multipid/Subsystem/PID Controller2/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S208>' : 'multipid/Subsystem/PID Controller2/Filter ICs/Internal IC - Differentiator'
//  '<S209>' : 'multipid/Subsystem/PID Controller2/I Gain/Internal Parameters'
//  '<S210>' : 'multipid/Subsystem/PID Controller2/Ideal P Gain/Passthrough'
//  '<S211>' : 'multipid/Subsystem/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S212>' : 'multipid/Subsystem/PID Controller2/Integrator/Discrete'
//  '<S213>' : 'multipid/Subsystem/PID Controller2/Integrator ICs/Internal IC'
//  '<S214>' : 'multipid/Subsystem/PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S215>' : 'multipid/Subsystem/PID Controller2/N Gain/Passthrough'
//  '<S216>' : 'multipid/Subsystem/PID Controller2/P Copy/Disabled'
//  '<S217>' : 'multipid/Subsystem/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S218>' : 'multipid/Subsystem/PID Controller2/Reset Signal/Disabled'
//  '<S219>' : 'multipid/Subsystem/PID Controller2/Saturation/Enabled'
//  '<S220>' : 'multipid/Subsystem/PID Controller2/Saturation Fdbk/Disabled'
//  '<S221>' : 'multipid/Subsystem/PID Controller2/Sum/Sum_PID'
//  '<S222>' : 'multipid/Subsystem/PID Controller2/Sum Fdbk/Disabled'
//  '<S223>' : 'multipid/Subsystem/PID Controller2/Tracking Mode/Disabled'
//  '<S224>' : 'multipid/Subsystem/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S225>' : 'multipid/Subsystem/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S226>' : 'multipid/Subsystem/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S227>' : 'multipid/Subsystem/PID Controller2/postSat Signal/Forward_Path'
//  '<S228>' : 'multipid/Subsystem/PID Controller2/preInt Signal/Internal PreInt'
//  '<S229>' : 'multipid/Subsystem/PID Controller2/preSat Signal/Forward_Path'
//  '<S230>' : 'multipid/Subsystem/PID Controller4/Anti-windup'
//  '<S231>' : 'multipid/Subsystem/PID Controller4/D Gain'
//  '<S232>' : 'multipid/Subsystem/PID Controller4/External Derivative'
//  '<S233>' : 'multipid/Subsystem/PID Controller4/Filter'
//  '<S234>' : 'multipid/Subsystem/PID Controller4/Filter ICs'
//  '<S235>' : 'multipid/Subsystem/PID Controller4/I Gain'
//  '<S236>' : 'multipid/Subsystem/PID Controller4/Ideal P Gain'
//  '<S237>' : 'multipid/Subsystem/PID Controller4/Ideal P Gain Fdbk'
//  '<S238>' : 'multipid/Subsystem/PID Controller4/Integrator'
//  '<S239>' : 'multipid/Subsystem/PID Controller4/Integrator ICs'
//  '<S240>' : 'multipid/Subsystem/PID Controller4/N Copy'
//  '<S241>' : 'multipid/Subsystem/PID Controller4/N Gain'
//  '<S242>' : 'multipid/Subsystem/PID Controller4/P Copy'
//  '<S243>' : 'multipid/Subsystem/PID Controller4/Parallel P Gain'
//  '<S244>' : 'multipid/Subsystem/PID Controller4/Reset Signal'
//  '<S245>' : 'multipid/Subsystem/PID Controller4/Saturation'
//  '<S246>' : 'multipid/Subsystem/PID Controller4/Saturation Fdbk'
//  '<S247>' : 'multipid/Subsystem/PID Controller4/Sum'
//  '<S248>' : 'multipid/Subsystem/PID Controller4/Sum Fdbk'
//  '<S249>' : 'multipid/Subsystem/PID Controller4/Tracking Mode'
//  '<S250>' : 'multipid/Subsystem/PID Controller4/Tracking Mode Sum'
//  '<S251>' : 'multipid/Subsystem/PID Controller4/Tsamp - Integral'
//  '<S252>' : 'multipid/Subsystem/PID Controller4/Tsamp - Ngain'
//  '<S253>' : 'multipid/Subsystem/PID Controller4/postSat Signal'
//  '<S254>' : 'multipid/Subsystem/PID Controller4/preInt Signal'
//  '<S255>' : 'multipid/Subsystem/PID Controller4/preSat Signal'
//  '<S256>' : 'multipid/Subsystem/PID Controller4/Anti-windup/Back Calculation'
//  '<S257>' : 'multipid/Subsystem/PID Controller4/D Gain/Internal Parameters'
//  '<S258>' : 'multipid/Subsystem/PID Controller4/External Derivative/Error'
//  '<S259>' : 'multipid/Subsystem/PID Controller4/Filter/Differentiator'
//  '<S260>' : 'multipid/Subsystem/PID Controller4/Filter/Differentiator/Tsamp'
//  '<S261>' : 'multipid/Subsystem/PID Controller4/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S262>' : 'multipid/Subsystem/PID Controller4/Filter ICs/Internal IC - Differentiator'
//  '<S263>' : 'multipid/Subsystem/PID Controller4/I Gain/Internal Parameters'
//  '<S264>' : 'multipid/Subsystem/PID Controller4/Ideal P Gain/Passthrough'
//  '<S265>' : 'multipid/Subsystem/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S266>' : 'multipid/Subsystem/PID Controller4/Integrator/Discrete'
//  '<S267>' : 'multipid/Subsystem/PID Controller4/Integrator ICs/Internal IC'
//  '<S268>' : 'multipid/Subsystem/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S269>' : 'multipid/Subsystem/PID Controller4/N Gain/Passthrough'
//  '<S270>' : 'multipid/Subsystem/PID Controller4/P Copy/Disabled'
//  '<S271>' : 'multipid/Subsystem/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S272>' : 'multipid/Subsystem/PID Controller4/Reset Signal/Disabled'
//  '<S273>' : 'multipid/Subsystem/PID Controller4/Saturation/Enabled'
//  '<S274>' : 'multipid/Subsystem/PID Controller4/Saturation Fdbk/Disabled'
//  '<S275>' : 'multipid/Subsystem/PID Controller4/Sum/Sum_PID'
//  '<S276>' : 'multipid/Subsystem/PID Controller4/Sum Fdbk/Disabled'
//  '<S277>' : 'multipid/Subsystem/PID Controller4/Tracking Mode/Disabled'
//  '<S278>' : 'multipid/Subsystem/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S279>' : 'multipid/Subsystem/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S280>' : 'multipid/Subsystem/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S281>' : 'multipid/Subsystem/PID Controller4/postSat Signal/Forward_Path'
//  '<S282>' : 'multipid/Subsystem/PID Controller4/preInt Signal/Internal PreInt'
//  '<S283>' : 'multipid/Subsystem/PID Controller4/preSat Signal/Forward_Path'
//  '<S284>' : 'multipid/Subsystem2/PID Controller1'
//  '<S285>' : 'multipid/Subsystem2/PID Controller2'
//  '<S286>' : 'multipid/Subsystem2/PID Controller3'
//  '<S287>' : 'multipid/Subsystem2/PID Controller1/Anti-windup'
//  '<S288>' : 'multipid/Subsystem2/PID Controller1/D Gain'
//  '<S289>' : 'multipid/Subsystem2/PID Controller1/External Derivative'
//  '<S290>' : 'multipid/Subsystem2/PID Controller1/Filter'
//  '<S291>' : 'multipid/Subsystem2/PID Controller1/Filter ICs'
//  '<S292>' : 'multipid/Subsystem2/PID Controller1/I Gain'
//  '<S293>' : 'multipid/Subsystem2/PID Controller1/Ideal P Gain'
//  '<S294>' : 'multipid/Subsystem2/PID Controller1/Ideal P Gain Fdbk'
//  '<S295>' : 'multipid/Subsystem2/PID Controller1/Integrator'
//  '<S296>' : 'multipid/Subsystem2/PID Controller1/Integrator ICs'
//  '<S297>' : 'multipid/Subsystem2/PID Controller1/N Copy'
//  '<S298>' : 'multipid/Subsystem2/PID Controller1/N Gain'
//  '<S299>' : 'multipid/Subsystem2/PID Controller1/P Copy'
//  '<S300>' : 'multipid/Subsystem2/PID Controller1/Parallel P Gain'
//  '<S301>' : 'multipid/Subsystem2/PID Controller1/Reset Signal'
//  '<S302>' : 'multipid/Subsystem2/PID Controller1/Saturation'
//  '<S303>' : 'multipid/Subsystem2/PID Controller1/Saturation Fdbk'
//  '<S304>' : 'multipid/Subsystem2/PID Controller1/Sum'
//  '<S305>' : 'multipid/Subsystem2/PID Controller1/Sum Fdbk'
//  '<S306>' : 'multipid/Subsystem2/PID Controller1/Tracking Mode'
//  '<S307>' : 'multipid/Subsystem2/PID Controller1/Tracking Mode Sum'
//  '<S308>' : 'multipid/Subsystem2/PID Controller1/Tsamp - Integral'
//  '<S309>' : 'multipid/Subsystem2/PID Controller1/Tsamp - Ngain'
//  '<S310>' : 'multipid/Subsystem2/PID Controller1/postSat Signal'
//  '<S311>' : 'multipid/Subsystem2/PID Controller1/preInt Signal'
//  '<S312>' : 'multipid/Subsystem2/PID Controller1/preSat Signal'
//  '<S313>' : 'multipid/Subsystem2/PID Controller1/Anti-windup/Back Calculation'
//  '<S314>' : 'multipid/Subsystem2/PID Controller1/D Gain/Internal Parameters'
//  '<S315>' : 'multipid/Subsystem2/PID Controller1/External Derivative/Error'
//  '<S316>' : 'multipid/Subsystem2/PID Controller1/Filter/Differentiator'
//  '<S317>' : 'multipid/Subsystem2/PID Controller1/Filter/Differentiator/Tsamp'
//  '<S318>' : 'multipid/Subsystem2/PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S319>' : 'multipid/Subsystem2/PID Controller1/Filter ICs/Internal IC - Differentiator'
//  '<S320>' : 'multipid/Subsystem2/PID Controller1/I Gain/Internal Parameters'
//  '<S321>' : 'multipid/Subsystem2/PID Controller1/Ideal P Gain/Passthrough'
//  '<S322>' : 'multipid/Subsystem2/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S323>' : 'multipid/Subsystem2/PID Controller1/Integrator/Discrete'
//  '<S324>' : 'multipid/Subsystem2/PID Controller1/Integrator ICs/Internal IC'
//  '<S325>' : 'multipid/Subsystem2/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S326>' : 'multipid/Subsystem2/PID Controller1/N Gain/Passthrough'
//  '<S327>' : 'multipid/Subsystem2/PID Controller1/P Copy/Disabled'
//  '<S328>' : 'multipid/Subsystem2/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S329>' : 'multipid/Subsystem2/PID Controller1/Reset Signal/Disabled'
//  '<S330>' : 'multipid/Subsystem2/PID Controller1/Saturation/Enabled'
//  '<S331>' : 'multipid/Subsystem2/PID Controller1/Saturation Fdbk/Disabled'
//  '<S332>' : 'multipid/Subsystem2/PID Controller1/Sum/Sum_PID'
//  '<S333>' : 'multipid/Subsystem2/PID Controller1/Sum Fdbk/Disabled'
//  '<S334>' : 'multipid/Subsystem2/PID Controller1/Tracking Mode/Disabled'
//  '<S335>' : 'multipid/Subsystem2/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S336>' : 'multipid/Subsystem2/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S337>' : 'multipid/Subsystem2/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S338>' : 'multipid/Subsystem2/PID Controller1/postSat Signal/Forward_Path'
//  '<S339>' : 'multipid/Subsystem2/PID Controller1/preInt Signal/Internal PreInt'
//  '<S340>' : 'multipid/Subsystem2/PID Controller1/preSat Signal/Forward_Path'
//  '<S341>' : 'multipid/Subsystem2/PID Controller2/Anti-windup'
//  '<S342>' : 'multipid/Subsystem2/PID Controller2/D Gain'
//  '<S343>' : 'multipid/Subsystem2/PID Controller2/External Derivative'
//  '<S344>' : 'multipid/Subsystem2/PID Controller2/Filter'
//  '<S345>' : 'multipid/Subsystem2/PID Controller2/Filter ICs'
//  '<S346>' : 'multipid/Subsystem2/PID Controller2/I Gain'
//  '<S347>' : 'multipid/Subsystem2/PID Controller2/Ideal P Gain'
//  '<S348>' : 'multipid/Subsystem2/PID Controller2/Ideal P Gain Fdbk'
//  '<S349>' : 'multipid/Subsystem2/PID Controller2/Integrator'
//  '<S350>' : 'multipid/Subsystem2/PID Controller2/Integrator ICs'
//  '<S351>' : 'multipid/Subsystem2/PID Controller2/N Copy'
//  '<S352>' : 'multipid/Subsystem2/PID Controller2/N Gain'
//  '<S353>' : 'multipid/Subsystem2/PID Controller2/P Copy'
//  '<S354>' : 'multipid/Subsystem2/PID Controller2/Parallel P Gain'
//  '<S355>' : 'multipid/Subsystem2/PID Controller2/Reset Signal'
//  '<S356>' : 'multipid/Subsystem2/PID Controller2/Saturation'
//  '<S357>' : 'multipid/Subsystem2/PID Controller2/Saturation Fdbk'
//  '<S358>' : 'multipid/Subsystem2/PID Controller2/Sum'
//  '<S359>' : 'multipid/Subsystem2/PID Controller2/Sum Fdbk'
//  '<S360>' : 'multipid/Subsystem2/PID Controller2/Tracking Mode'
//  '<S361>' : 'multipid/Subsystem2/PID Controller2/Tracking Mode Sum'
//  '<S362>' : 'multipid/Subsystem2/PID Controller2/Tsamp - Integral'
//  '<S363>' : 'multipid/Subsystem2/PID Controller2/Tsamp - Ngain'
//  '<S364>' : 'multipid/Subsystem2/PID Controller2/postSat Signal'
//  '<S365>' : 'multipid/Subsystem2/PID Controller2/preInt Signal'
//  '<S366>' : 'multipid/Subsystem2/PID Controller2/preSat Signal'
//  '<S367>' : 'multipid/Subsystem2/PID Controller2/Anti-windup/Back Calculation'
//  '<S368>' : 'multipid/Subsystem2/PID Controller2/D Gain/Internal Parameters'
//  '<S369>' : 'multipid/Subsystem2/PID Controller2/External Derivative/Error'
//  '<S370>' : 'multipid/Subsystem2/PID Controller2/Filter/Differentiator'
//  '<S371>' : 'multipid/Subsystem2/PID Controller2/Filter/Differentiator/Tsamp'
//  '<S372>' : 'multipid/Subsystem2/PID Controller2/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S373>' : 'multipid/Subsystem2/PID Controller2/Filter ICs/Internal IC - Differentiator'
//  '<S374>' : 'multipid/Subsystem2/PID Controller2/I Gain/Internal Parameters'
//  '<S375>' : 'multipid/Subsystem2/PID Controller2/Ideal P Gain/Passthrough'
//  '<S376>' : 'multipid/Subsystem2/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S377>' : 'multipid/Subsystem2/PID Controller2/Integrator/Discrete'
//  '<S378>' : 'multipid/Subsystem2/PID Controller2/Integrator ICs/Internal IC'
//  '<S379>' : 'multipid/Subsystem2/PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S380>' : 'multipid/Subsystem2/PID Controller2/N Gain/Passthrough'
//  '<S381>' : 'multipid/Subsystem2/PID Controller2/P Copy/Disabled'
//  '<S382>' : 'multipid/Subsystem2/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S383>' : 'multipid/Subsystem2/PID Controller2/Reset Signal/Disabled'
//  '<S384>' : 'multipid/Subsystem2/PID Controller2/Saturation/Enabled'
//  '<S385>' : 'multipid/Subsystem2/PID Controller2/Saturation Fdbk/Disabled'
//  '<S386>' : 'multipid/Subsystem2/PID Controller2/Sum/Sum_PID'
//  '<S387>' : 'multipid/Subsystem2/PID Controller2/Sum Fdbk/Disabled'
//  '<S388>' : 'multipid/Subsystem2/PID Controller2/Tracking Mode/Disabled'
//  '<S389>' : 'multipid/Subsystem2/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S390>' : 'multipid/Subsystem2/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S391>' : 'multipid/Subsystem2/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S392>' : 'multipid/Subsystem2/PID Controller2/postSat Signal/Forward_Path'
//  '<S393>' : 'multipid/Subsystem2/PID Controller2/preInt Signal/Internal PreInt'
//  '<S394>' : 'multipid/Subsystem2/PID Controller2/preSat Signal/Forward_Path'
//  '<S395>' : 'multipid/Subsystem2/PID Controller3/Anti-windup'
//  '<S396>' : 'multipid/Subsystem2/PID Controller3/D Gain'
//  '<S397>' : 'multipid/Subsystem2/PID Controller3/External Derivative'
//  '<S398>' : 'multipid/Subsystem2/PID Controller3/Filter'
//  '<S399>' : 'multipid/Subsystem2/PID Controller3/Filter ICs'
//  '<S400>' : 'multipid/Subsystem2/PID Controller3/I Gain'
//  '<S401>' : 'multipid/Subsystem2/PID Controller3/Ideal P Gain'
//  '<S402>' : 'multipid/Subsystem2/PID Controller3/Ideal P Gain Fdbk'
//  '<S403>' : 'multipid/Subsystem2/PID Controller3/Integrator'
//  '<S404>' : 'multipid/Subsystem2/PID Controller3/Integrator ICs'
//  '<S405>' : 'multipid/Subsystem2/PID Controller3/N Copy'
//  '<S406>' : 'multipid/Subsystem2/PID Controller3/N Gain'
//  '<S407>' : 'multipid/Subsystem2/PID Controller3/P Copy'
//  '<S408>' : 'multipid/Subsystem2/PID Controller3/Parallel P Gain'
//  '<S409>' : 'multipid/Subsystem2/PID Controller3/Reset Signal'
//  '<S410>' : 'multipid/Subsystem2/PID Controller3/Saturation'
//  '<S411>' : 'multipid/Subsystem2/PID Controller3/Saturation Fdbk'
//  '<S412>' : 'multipid/Subsystem2/PID Controller3/Sum'
//  '<S413>' : 'multipid/Subsystem2/PID Controller3/Sum Fdbk'
//  '<S414>' : 'multipid/Subsystem2/PID Controller3/Tracking Mode'
//  '<S415>' : 'multipid/Subsystem2/PID Controller3/Tracking Mode Sum'
//  '<S416>' : 'multipid/Subsystem2/PID Controller3/Tsamp - Integral'
//  '<S417>' : 'multipid/Subsystem2/PID Controller3/Tsamp - Ngain'
//  '<S418>' : 'multipid/Subsystem2/PID Controller3/postSat Signal'
//  '<S419>' : 'multipid/Subsystem2/PID Controller3/preInt Signal'
//  '<S420>' : 'multipid/Subsystem2/PID Controller3/preSat Signal'
//  '<S421>' : 'multipid/Subsystem2/PID Controller3/Anti-windup/Back Calculation'
//  '<S422>' : 'multipid/Subsystem2/PID Controller3/D Gain/Internal Parameters'
//  '<S423>' : 'multipid/Subsystem2/PID Controller3/External Derivative/Error'
//  '<S424>' : 'multipid/Subsystem2/PID Controller3/Filter/Differentiator'
//  '<S425>' : 'multipid/Subsystem2/PID Controller3/Filter/Differentiator/Tsamp'
//  '<S426>' : 'multipid/Subsystem2/PID Controller3/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S427>' : 'multipid/Subsystem2/PID Controller3/Filter ICs/Internal IC - Differentiator'
//  '<S428>' : 'multipid/Subsystem2/PID Controller3/I Gain/Internal Parameters'
//  '<S429>' : 'multipid/Subsystem2/PID Controller3/Ideal P Gain/Passthrough'
//  '<S430>' : 'multipid/Subsystem2/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S431>' : 'multipid/Subsystem2/PID Controller3/Integrator/Discrete'
//  '<S432>' : 'multipid/Subsystem2/PID Controller3/Integrator ICs/Internal IC'
//  '<S433>' : 'multipid/Subsystem2/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S434>' : 'multipid/Subsystem2/PID Controller3/N Gain/Passthrough'
//  '<S435>' : 'multipid/Subsystem2/PID Controller3/P Copy/Disabled'
//  '<S436>' : 'multipid/Subsystem2/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S437>' : 'multipid/Subsystem2/PID Controller3/Reset Signal/Disabled'
//  '<S438>' : 'multipid/Subsystem2/PID Controller3/Saturation/Enabled'
//  '<S439>' : 'multipid/Subsystem2/PID Controller3/Saturation Fdbk/Disabled'
//  '<S440>' : 'multipid/Subsystem2/PID Controller3/Sum/Sum_PID'
//  '<S441>' : 'multipid/Subsystem2/PID Controller3/Sum Fdbk/Disabled'
//  '<S442>' : 'multipid/Subsystem2/PID Controller3/Tracking Mode/Disabled'
//  '<S443>' : 'multipid/Subsystem2/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S444>' : 'multipid/Subsystem2/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S445>' : 'multipid/Subsystem2/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S446>' : 'multipid/Subsystem2/PID Controller3/postSat Signal/Forward_Path'
//  '<S447>' : 'multipid/Subsystem2/PID Controller3/preInt Signal/Internal PreInt'
//  '<S448>' : 'multipid/Subsystem2/PID Controller3/preSat Signal/Forward_Path'
//  '<S449>' : 'multipid/Subsystem3/PID Controller'
//  '<S450>' : 'multipid/Subsystem3/PID Controller1'
//  '<S451>' : 'multipid/Subsystem3/PID Controller2'
//  '<S452>' : 'multipid/Subsystem3/PID Controller/Anti-windup'
//  '<S453>' : 'multipid/Subsystem3/PID Controller/D Gain'
//  '<S454>' : 'multipid/Subsystem3/PID Controller/External Derivative'
//  '<S455>' : 'multipid/Subsystem3/PID Controller/Filter'
//  '<S456>' : 'multipid/Subsystem3/PID Controller/Filter ICs'
//  '<S457>' : 'multipid/Subsystem3/PID Controller/I Gain'
//  '<S458>' : 'multipid/Subsystem3/PID Controller/Ideal P Gain'
//  '<S459>' : 'multipid/Subsystem3/PID Controller/Ideal P Gain Fdbk'
//  '<S460>' : 'multipid/Subsystem3/PID Controller/Integrator'
//  '<S461>' : 'multipid/Subsystem3/PID Controller/Integrator ICs'
//  '<S462>' : 'multipid/Subsystem3/PID Controller/N Copy'
//  '<S463>' : 'multipid/Subsystem3/PID Controller/N Gain'
//  '<S464>' : 'multipid/Subsystem3/PID Controller/P Copy'
//  '<S465>' : 'multipid/Subsystem3/PID Controller/Parallel P Gain'
//  '<S466>' : 'multipid/Subsystem3/PID Controller/Reset Signal'
//  '<S467>' : 'multipid/Subsystem3/PID Controller/Saturation'
//  '<S468>' : 'multipid/Subsystem3/PID Controller/Saturation Fdbk'
//  '<S469>' : 'multipid/Subsystem3/PID Controller/Sum'
//  '<S470>' : 'multipid/Subsystem3/PID Controller/Sum Fdbk'
//  '<S471>' : 'multipid/Subsystem3/PID Controller/Tracking Mode'
//  '<S472>' : 'multipid/Subsystem3/PID Controller/Tracking Mode Sum'
//  '<S473>' : 'multipid/Subsystem3/PID Controller/Tsamp - Integral'
//  '<S474>' : 'multipid/Subsystem3/PID Controller/Tsamp - Ngain'
//  '<S475>' : 'multipid/Subsystem3/PID Controller/postSat Signal'
//  '<S476>' : 'multipid/Subsystem3/PID Controller/preInt Signal'
//  '<S477>' : 'multipid/Subsystem3/PID Controller/preSat Signal'
//  '<S478>' : 'multipid/Subsystem3/PID Controller/Anti-windup/Passthrough'
//  '<S479>' : 'multipid/Subsystem3/PID Controller/D Gain/Internal Parameters'
//  '<S480>' : 'multipid/Subsystem3/PID Controller/External Derivative/Error'
//  '<S481>' : 'multipid/Subsystem3/PID Controller/Filter/Differentiator'
//  '<S482>' : 'multipid/Subsystem3/PID Controller/Filter/Differentiator/Tsamp'
//  '<S483>' : 'multipid/Subsystem3/PID Controller/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S484>' : 'multipid/Subsystem3/PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S485>' : 'multipid/Subsystem3/PID Controller/I Gain/Internal Parameters'
//  '<S486>' : 'multipid/Subsystem3/PID Controller/Ideal P Gain/Passthrough'
//  '<S487>' : 'multipid/Subsystem3/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S488>' : 'multipid/Subsystem3/PID Controller/Integrator/Discrete'
//  '<S489>' : 'multipid/Subsystem3/PID Controller/Integrator ICs/Internal IC'
//  '<S490>' : 'multipid/Subsystem3/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S491>' : 'multipid/Subsystem3/PID Controller/N Gain/Passthrough'
//  '<S492>' : 'multipid/Subsystem3/PID Controller/P Copy/Disabled'
//  '<S493>' : 'multipid/Subsystem3/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S494>' : 'multipid/Subsystem3/PID Controller/Reset Signal/Disabled'
//  '<S495>' : 'multipid/Subsystem3/PID Controller/Saturation/Passthrough'
//  '<S496>' : 'multipid/Subsystem3/PID Controller/Saturation Fdbk/Disabled'
//  '<S497>' : 'multipid/Subsystem3/PID Controller/Sum/Sum_PID'
//  '<S498>' : 'multipid/Subsystem3/PID Controller/Sum Fdbk/Disabled'
//  '<S499>' : 'multipid/Subsystem3/PID Controller/Tracking Mode/Disabled'
//  '<S500>' : 'multipid/Subsystem3/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S501>' : 'multipid/Subsystem3/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S502>' : 'multipid/Subsystem3/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S503>' : 'multipid/Subsystem3/PID Controller/postSat Signal/Forward_Path'
//  '<S504>' : 'multipid/Subsystem3/PID Controller/preInt Signal/Internal PreInt'
//  '<S505>' : 'multipid/Subsystem3/PID Controller/preSat Signal/Forward_Path'
//  '<S506>' : 'multipid/Subsystem3/PID Controller1/Anti-windup'
//  '<S507>' : 'multipid/Subsystem3/PID Controller1/D Gain'
//  '<S508>' : 'multipid/Subsystem3/PID Controller1/External Derivative'
//  '<S509>' : 'multipid/Subsystem3/PID Controller1/Filter'
//  '<S510>' : 'multipid/Subsystem3/PID Controller1/Filter ICs'
//  '<S511>' : 'multipid/Subsystem3/PID Controller1/I Gain'
//  '<S512>' : 'multipid/Subsystem3/PID Controller1/Ideal P Gain'
//  '<S513>' : 'multipid/Subsystem3/PID Controller1/Ideal P Gain Fdbk'
//  '<S514>' : 'multipid/Subsystem3/PID Controller1/Integrator'
//  '<S515>' : 'multipid/Subsystem3/PID Controller1/Integrator ICs'
//  '<S516>' : 'multipid/Subsystem3/PID Controller1/N Copy'
//  '<S517>' : 'multipid/Subsystem3/PID Controller1/N Gain'
//  '<S518>' : 'multipid/Subsystem3/PID Controller1/P Copy'
//  '<S519>' : 'multipid/Subsystem3/PID Controller1/Parallel P Gain'
//  '<S520>' : 'multipid/Subsystem3/PID Controller1/Reset Signal'
//  '<S521>' : 'multipid/Subsystem3/PID Controller1/Saturation'
//  '<S522>' : 'multipid/Subsystem3/PID Controller1/Saturation Fdbk'
//  '<S523>' : 'multipid/Subsystem3/PID Controller1/Sum'
//  '<S524>' : 'multipid/Subsystem3/PID Controller1/Sum Fdbk'
//  '<S525>' : 'multipid/Subsystem3/PID Controller1/Tracking Mode'
//  '<S526>' : 'multipid/Subsystem3/PID Controller1/Tracking Mode Sum'
//  '<S527>' : 'multipid/Subsystem3/PID Controller1/Tsamp - Integral'
//  '<S528>' : 'multipid/Subsystem3/PID Controller1/Tsamp - Ngain'
//  '<S529>' : 'multipid/Subsystem3/PID Controller1/postSat Signal'
//  '<S530>' : 'multipid/Subsystem3/PID Controller1/preInt Signal'
//  '<S531>' : 'multipid/Subsystem3/PID Controller1/preSat Signal'
//  '<S532>' : 'multipid/Subsystem3/PID Controller1/Anti-windup/Passthrough'
//  '<S533>' : 'multipid/Subsystem3/PID Controller1/D Gain/Internal Parameters'
//  '<S534>' : 'multipid/Subsystem3/PID Controller1/External Derivative/Error'
//  '<S535>' : 'multipid/Subsystem3/PID Controller1/Filter/Differentiator'
//  '<S536>' : 'multipid/Subsystem3/PID Controller1/Filter/Differentiator/Tsamp'
//  '<S537>' : 'multipid/Subsystem3/PID Controller1/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S538>' : 'multipid/Subsystem3/PID Controller1/Filter ICs/Internal IC - Differentiator'
//  '<S539>' : 'multipid/Subsystem3/PID Controller1/I Gain/Internal Parameters'
//  '<S540>' : 'multipid/Subsystem3/PID Controller1/Ideal P Gain/Passthrough'
//  '<S541>' : 'multipid/Subsystem3/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S542>' : 'multipid/Subsystem3/PID Controller1/Integrator/Discrete'
//  '<S543>' : 'multipid/Subsystem3/PID Controller1/Integrator ICs/Internal IC'
//  '<S544>' : 'multipid/Subsystem3/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S545>' : 'multipid/Subsystem3/PID Controller1/N Gain/Passthrough'
//  '<S546>' : 'multipid/Subsystem3/PID Controller1/P Copy/Disabled'
//  '<S547>' : 'multipid/Subsystem3/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S548>' : 'multipid/Subsystem3/PID Controller1/Reset Signal/Disabled'
//  '<S549>' : 'multipid/Subsystem3/PID Controller1/Saturation/Passthrough'
//  '<S550>' : 'multipid/Subsystem3/PID Controller1/Saturation Fdbk/Disabled'
//  '<S551>' : 'multipid/Subsystem3/PID Controller1/Sum/Sum_PID'
//  '<S552>' : 'multipid/Subsystem3/PID Controller1/Sum Fdbk/Disabled'
//  '<S553>' : 'multipid/Subsystem3/PID Controller1/Tracking Mode/Disabled'
//  '<S554>' : 'multipid/Subsystem3/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S555>' : 'multipid/Subsystem3/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S556>' : 'multipid/Subsystem3/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S557>' : 'multipid/Subsystem3/PID Controller1/postSat Signal/Forward_Path'
//  '<S558>' : 'multipid/Subsystem3/PID Controller1/preInt Signal/Internal PreInt'
//  '<S559>' : 'multipid/Subsystem3/PID Controller1/preSat Signal/Forward_Path'
//  '<S560>' : 'multipid/Subsystem3/PID Controller2/Anti-windup'
//  '<S561>' : 'multipid/Subsystem3/PID Controller2/D Gain'
//  '<S562>' : 'multipid/Subsystem3/PID Controller2/External Derivative'
//  '<S563>' : 'multipid/Subsystem3/PID Controller2/Filter'
//  '<S564>' : 'multipid/Subsystem3/PID Controller2/Filter ICs'
//  '<S565>' : 'multipid/Subsystem3/PID Controller2/I Gain'
//  '<S566>' : 'multipid/Subsystem3/PID Controller2/Ideal P Gain'
//  '<S567>' : 'multipid/Subsystem3/PID Controller2/Ideal P Gain Fdbk'
//  '<S568>' : 'multipid/Subsystem3/PID Controller2/Integrator'
//  '<S569>' : 'multipid/Subsystem3/PID Controller2/Integrator ICs'
//  '<S570>' : 'multipid/Subsystem3/PID Controller2/N Copy'
//  '<S571>' : 'multipid/Subsystem3/PID Controller2/N Gain'
//  '<S572>' : 'multipid/Subsystem3/PID Controller2/P Copy'
//  '<S573>' : 'multipid/Subsystem3/PID Controller2/Parallel P Gain'
//  '<S574>' : 'multipid/Subsystem3/PID Controller2/Reset Signal'
//  '<S575>' : 'multipid/Subsystem3/PID Controller2/Saturation'
//  '<S576>' : 'multipid/Subsystem3/PID Controller2/Saturation Fdbk'
//  '<S577>' : 'multipid/Subsystem3/PID Controller2/Sum'
//  '<S578>' : 'multipid/Subsystem3/PID Controller2/Sum Fdbk'
//  '<S579>' : 'multipid/Subsystem3/PID Controller2/Tracking Mode'
//  '<S580>' : 'multipid/Subsystem3/PID Controller2/Tracking Mode Sum'
//  '<S581>' : 'multipid/Subsystem3/PID Controller2/Tsamp - Integral'
//  '<S582>' : 'multipid/Subsystem3/PID Controller2/Tsamp - Ngain'
//  '<S583>' : 'multipid/Subsystem3/PID Controller2/postSat Signal'
//  '<S584>' : 'multipid/Subsystem3/PID Controller2/preInt Signal'
//  '<S585>' : 'multipid/Subsystem3/PID Controller2/preSat Signal'
//  '<S586>' : 'multipid/Subsystem3/PID Controller2/Anti-windup/Passthrough'
//  '<S587>' : 'multipid/Subsystem3/PID Controller2/D Gain/Internal Parameters'
//  '<S588>' : 'multipid/Subsystem3/PID Controller2/External Derivative/Error'
//  '<S589>' : 'multipid/Subsystem3/PID Controller2/Filter/Differentiator'
//  '<S590>' : 'multipid/Subsystem3/PID Controller2/Filter/Differentiator/Tsamp'
//  '<S591>' : 'multipid/Subsystem3/PID Controller2/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S592>' : 'multipid/Subsystem3/PID Controller2/Filter ICs/Internal IC - Differentiator'
//  '<S593>' : 'multipid/Subsystem3/PID Controller2/I Gain/Internal Parameters'
//  '<S594>' : 'multipid/Subsystem3/PID Controller2/Ideal P Gain/Passthrough'
//  '<S595>' : 'multipid/Subsystem3/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S596>' : 'multipid/Subsystem3/PID Controller2/Integrator/Discrete'
//  '<S597>' : 'multipid/Subsystem3/PID Controller2/Integrator ICs/Internal IC'
//  '<S598>' : 'multipid/Subsystem3/PID Controller2/N Copy/Disabled wSignal Specification'
//  '<S599>' : 'multipid/Subsystem3/PID Controller2/N Gain/Passthrough'
//  '<S600>' : 'multipid/Subsystem3/PID Controller2/P Copy/Disabled'
//  '<S601>' : 'multipid/Subsystem3/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S602>' : 'multipid/Subsystem3/PID Controller2/Reset Signal/Disabled'
//  '<S603>' : 'multipid/Subsystem3/PID Controller2/Saturation/Passthrough'
//  '<S604>' : 'multipid/Subsystem3/PID Controller2/Saturation Fdbk/Disabled'
//  '<S605>' : 'multipid/Subsystem3/PID Controller2/Sum/Sum_PID'
//  '<S606>' : 'multipid/Subsystem3/PID Controller2/Sum Fdbk/Disabled'
//  '<S607>' : 'multipid/Subsystem3/PID Controller2/Tracking Mode/Disabled'
//  '<S608>' : 'multipid/Subsystem3/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S609>' : 'multipid/Subsystem3/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S610>' : 'multipid/Subsystem3/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S611>' : 'multipid/Subsystem3/PID Controller2/postSat Signal/Forward_Path'
//  '<S612>' : 'multipid/Subsystem3/PID Controller2/preInt Signal/Internal PreInt'
//  '<S613>' : 'multipid/Subsystem3/PID Controller2/preSat Signal/Forward_Path'
//  '<S614>' : 'multipid/Vehicle Attitude/PX4 uORB Read'
//  '<S615>' : 'multipid/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // multipid_h_

//
// File trailer for generated code.
//
// [EOF]
//
