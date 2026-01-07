//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controladorpruebaio.cpp
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
#include "controladorpruebaio.h"
#include "controladorpruebaio_types.h"
#include "controladorpruebaio_private.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

// Block signals (default storage)
B_controladorpruebaio_T controladorpruebaio_B;

// Block states (default storage)
DW_controladorpruebaio_T controladorpruebaio_DW;

// Real-time model
RT_MODEL_controladorpruebaio_T controladorpruebaio_M_ =
  RT_MODEL_controladorpruebaio_T();
RT_MODEL_controladorpruebaio_T *const controladorpruebaio_M =
  &controladorpruebaio_M_;

// Forward declaration for local functions
static void controla_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void controladorpruebaio_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(controladorpruebaio_M, 1));
}

//
//         This function updates active task flag for each subrate
//         and rate transition flags for tasks that exchange data.
//         The function assumes rate-monotonic multitasking scheduler.
//         The function must be called at model base rate so that
//         the generated code self-manages all its subrates and rate
//         transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // To ensure a deterministic data transfer between two rates,
  //  data is transferred at the priority of a fast task and the frequency
  //  of the slow task.  The following flags indicate when the data transfer
  //  happens.  That is, a rate interaction flag is set true when both rates
  //  will run, and false otherwise.


  // tid 0 shares data with slower tid rate: 1
  controladorpruebaio_M->Timing.RateInteraction.TID0_1 =
    (controladorpruebaio_M->Timing.TaskCounters.TID[1] == 0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (controladorpruebaio_M->Timing.TaskCounters.TID[1])++;
  if ((controladorpruebaio_M->Timing.TaskCounters.TID[1]) > 4) {// Sample time: [0.005s, 0.0s] 
    controladorpruebaio_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = static_cast<real32_T>(atan2(static_cast<real_T>(static_cast<real32_T>
      (tmp)), static_cast<real_T>(static_cast<real32_T>(tmp_0))));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = static_cast<real32_T>(atan2(static_cast<real_T>(u0), static_cast<real_T>
      (u1)));
  }

  return y;
}

static void controla_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj)
{
  int32_T n;
  int32_T n_0;
  obj->ValidMotorIdx[0] = true;
  obj->ValidMotorIdx[1] = true;
  obj->ValidMotorIdx[2] = true;
  obj->ValidMotorIdx[3] = true;
  n = 0;
  for (int32_T b_k = 0; b_k < 12; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    if (obj->ValidMotorIdx[b_k]) {
      n++;
    }
  }

  n_0 = 0;
  for (int32_T b_k = 0; b_k < 8; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    if (obj->ValidServoIdx[b_k]) {
      n_0++;
    }
  }

  // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
  obj->QSize = static_cast<uint8_T>(n + n_0);
  MW_actuators_init(obj->QSize);
}

// Model step function for TID0
void controladorpruebaio_step0(void)   // Sample time: [0.001s, 0.0s]
{
  int32_T i;
  real32_T rtb_DataTypeConversion3;
  real32_T rtb_Product3;
  real32_T rtb_Saturation;
  real32_T rtb_Sum;
  real32_T rtb_Sum2;
  real32_T rtb_Tsamp;
  real32_T rtb_Tsamp_e;
  real32_T u0;
  real32_T u0_tmp;
  real32_T u0_tmp_0;
  real32_T u0_tmp_1;
  boolean_T b_varargout_1;
  boolean_T rtb_ManualSwitch;
  boolean_T tmp;

  {                                    // Sample time: [0.001s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Reset subsysRan breadcrumbs
  srClearBC(controladorpruebaio_DW.EnabledSubsystem_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(controladorpruebaio_DW.EnabledSubsystem_SubsysRanBC);

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant1'

  if (controladorpruebaio_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch = controladorpruebaio_P.Constant1_Value;
  } else {
    rtb_ManualSwitch = controladorpruebaio_P.Constant_Value_b;
  }

  // End of ManualSwitch: '<Root>/Manual Switch'

  // RateTransition: '<S3>/Rate Transition' incorporates:
  //   RateTransition generated from: '<S157>/Proportional Gain'
  //   RateTransition: '<S3>/Rate Transition1'
  //   RateTransition generated from: '<S51>/Proportional Gain'

  tmp = controladorpruebaio_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    // RateTransition: '<S3>/Rate Transition'
    controladorpruebaio_B.RateTransition =
      controladorpruebaio_DW.RateTransition_Buffer0;
  }

  // End of RateTransition: '<S3>/Rate Transition'

  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = uORB_read_step(controladorpruebaio_DW.obj_d.orbMetadataObj,
    &controladorpruebaio_DW.obj_d.eventStructObj, &controladorpruebaio_B.r1,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  // Start for MATLABSystem: '<S6>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S7>/In1'
    controladorpruebaio_B.In1_e = controladorpruebaio_B.r1;
    srUpdateBC(controladorpruebaio_DW.EnabledSubsystem_SubsysRanBC_f);
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // SignalConversion generated from: '<S1>/Bus Selector'
  controladorpruebaio_B.x = controladorpruebaio_B.In1_e.x;

  // Product: '<S3>/Product3' incorporates:
  //   Sum: '<S3>/Sum1'

  rtb_Product3 = (controladorpruebaio_B.RateTransition - controladorpruebaio_B.x)
    * static_cast<real32_T>(rtb_ManualSwitch);

  // SampleTimeMath: '<S95>/Tsamp' incorporates:
  //   Gain: '<S91>/Derivative Gain'
  //
  //  About '<S95>/Tsamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_Tsamp = controladorpruebaio_P.PIDController1_D * rtb_Product3 *
    controladorpruebaio_P.Tsamp_WtEt;

  // Sum: '<S109>/Sum' incorporates:
  //   Delay: '<S93>/UD'
  //   DiscreteIntegrator: '<S100>/Integrator'
  //   Gain: '<S105>/Proportional Gain'
  //   Sum: '<S93>/Diff'

  rtb_Sum = (controladorpruebaio_P.PIDController1_P * rtb_Product3 +
             controladorpruebaio_DW.Integrator_DSTATE) + (rtb_Tsamp -
    controladorpruebaio_DW.UD_DSTATE);

  // Saturate: '<S107>/Saturation'
  if (rtb_Sum > controladorpruebaio_P.PIDController1_UpperSaturationL) {
    // Saturate: '<S107>/Saturation'
    controladorpruebaio_B.Saturation =
      controladorpruebaio_P.PIDController1_UpperSaturationL;
  } else if (rtb_Sum < controladorpruebaio_P.PIDController1_LowerSaturationL) {
    // Saturate: '<S107>/Saturation'
    controladorpruebaio_B.Saturation =
      controladorpruebaio_P.PIDController1_LowerSaturationL;
  } else {
    // Saturate: '<S107>/Saturation'
    controladorpruebaio_B.Saturation = rtb_Sum;
  }

  // End of Saturate: '<S107>/Saturation'

  // RateTransition: '<S3>/Rate Transition1'
  if (tmp) {
    // RateTransition: '<S3>/Rate Transition1'
    controladorpruebaio_B.RateTransition1 =
      controladorpruebaio_DW.RateTransition1_Buffer0;
  }

  // Product: '<S3>/Product1' incorporates:
  //   Sum: '<S3>/Sum3'

  rtb_DataTypeConversion3 = (controladorpruebaio_B.RateTransition1 -
    controladorpruebaio_B.In1_e.y) * static_cast<real32_T>(rtb_ManualSwitch);

  // SampleTimeMath: '<S201>/Tsamp' incorporates:
  //   Gain: '<S197>/Derivative Gain'
  //
  //  About '<S201>/Tsamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_Tsamp_e = controladorpruebaio_P.PIDController3_D * rtb_DataTypeConversion3
    * controladorpruebaio_P.Tsamp_WtEt_k;

  // Sum: '<S215>/Sum' incorporates:
  //   Delay: '<S199>/UD'
  //   DiscreteIntegrator: '<S206>/Integrator'
  //   Gain: '<S211>/Proportional Gain'
  //   Sum: '<S199>/Diff'

  rtb_Sum2 = (controladorpruebaio_P.PIDController3_P * rtb_DataTypeConversion3 +
              controladorpruebaio_DW.Integrator_DSTATE_o) + (rtb_Tsamp_e -
    controladorpruebaio_DW.UD_DSTATE_k);

  // Saturate: '<S213>/Saturation'
  if (rtb_Sum2 > controladorpruebaio_P.PIDController3_UpperSaturationL) {
    rtb_Saturation = controladorpruebaio_P.PIDController3_UpperSaturationL;
  } else if (rtb_Sum2 < controladorpruebaio_P.PIDController3_LowerSaturationL) {
    rtb_Saturation = controladorpruebaio_P.PIDController3_LowerSaturationL;
  } else {
    rtb_Saturation = rtb_Sum2;
  }

  // End of Saturate: '<S213>/Saturation'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Constant: '<Root>/Constant4'

  u0_tmp = 0.707107F * controladorpruebaio_B.Saturation;
  u0_tmp_0 = 0.707107F * rtb_Saturation;
  u0_tmp_1 = static_cast<real32_T>(controladorpruebaio_P.Constant4_Value) -
    u0_tmp;
  u0 = u0_tmp_1 + u0_tmp_0;

  // Saturate: '<Root>/Saturation4'
  if (u0 > controladorpruebaio_P.Saturation4_UpperSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[0] =
      controladorpruebaio_P.Saturation4_UpperSat;
  } else if (u0 < controladorpruebaio_P.Saturation4_LowerSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[0] =
      controladorpruebaio_P.Saturation4_LowerSat;
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[0] = u0;
  }

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Constant: '<Root>/Constant4'

  u0_tmp += static_cast<real32_T>(controladorpruebaio_P.Constant4_Value);
  u0 = u0_tmp - u0_tmp_0;

  // Saturate: '<Root>/Saturation4'
  if (u0 > controladorpruebaio_P.Saturation4_UpperSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[1] =
      controladorpruebaio_P.Saturation4_UpperSat;
  } else if (u0 < controladorpruebaio_P.Saturation4_LowerSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[1] =
      controladorpruebaio_P.Saturation4_LowerSat;
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[1] = u0;
  }

  // MATLAB Function: '<Root>/MATLAB Function'
  u0 = u0_tmp + u0_tmp_0;

  // Saturate: '<Root>/Saturation4'
  if (u0 > controladorpruebaio_P.Saturation4_UpperSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[2] =
      controladorpruebaio_P.Saturation4_UpperSat;
  } else if (u0 < controladorpruebaio_P.Saturation4_LowerSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[2] =
      controladorpruebaio_P.Saturation4_LowerSat;
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[2] = u0;
  }

  // MATLAB Function: '<Root>/MATLAB Function'
  u0 = u0_tmp_1 - u0_tmp_0;

  // Saturate: '<Root>/Saturation4'
  if (u0 > controladorpruebaio_P.Saturation4_UpperSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[3] =
      controladorpruebaio_P.Saturation4_UpperSat;
  } else if (u0 < controladorpruebaio_P.Saturation4_LowerSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[3] =
      controladorpruebaio_P.Saturation4_LowerSat;
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    controladorpruebaio_B.DataTypeConversion[3] = u0;
  }

  // MATLABSystem: '<Root>/PX4 Actuator Write'
  for (i = 0; i < 12; i++) {
    controladorpruebaio_B.motorValues[i] = (rtNaNF);
  }

  for (i = 0; i < 8; i++) {
    controladorpruebaio_B.servoValues[i] = (rtNaNF);
  }

  controladorpruebaio_B.motorValues[0] =
    controladorpruebaio_B.DataTypeConversion[0];
  controladorpruebaio_B.motorValues[1] =
    controladorpruebaio_B.DataTypeConversion[1];
  controladorpruebaio_B.motorValues[2] =
    controladorpruebaio_B.DataTypeConversion[2];
  controladorpruebaio_B.motorValues[3] =
    controladorpruebaio_B.DataTypeConversion[3];
  MW_actuators_set(rtb_ManualSwitch, &controladorpruebaio_B.motorValues[0],
                   &controladorpruebaio_B.servoValues[0]);

  // End of MATLABSystem: '<Root>/PX4 Actuator Write'
  // Gain: '<Root>/Gain1' incorporates:
  //   Constant: '<Root>/Constant2'
  //   DataTypeConversion: '<Root>/Data Type Conversion2'

  controladorpruebaio_B.Gain1 = controladorpruebaio_P.Gain1_Gain *
    static_cast<real32_T>(controladorpruebaio_P.Constant2_Value);

  // MATLABSystem: '<S224>/SourceBlock'
  b_varargout_1 = uORB_read_step(controladorpruebaio_DW.obj_c.orbMetadataObj,
    &controladorpruebaio_DW.obj_c.eventStructObj, &controladorpruebaio_B.r,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S224>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S225>/Enable'

  // Start for MATLABSystem: '<S224>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S225>/In1'
    controladorpruebaio_B.In1 = controladorpruebaio_B.r;
    srUpdateBC(controladorpruebaio_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S224>/Enabled Subsystem'

  // MATLAB Function: '<Root>/quat2eul'
  controladorpruebaio_B.phi = rt_atan2f_snf((controladorpruebaio_B.In1.q[0] *
    controladorpruebaio_B.In1.q[1] + controladorpruebaio_B.In1.q[2] *
    controladorpruebaio_B.In1.q[3]) * 2.0F, ((controladorpruebaio_B.In1.q[0] *
    controladorpruebaio_B.In1.q[0] - controladorpruebaio_B.In1.q[1] *
    controladorpruebaio_B.In1.q[1]) - controladorpruebaio_B.In1.q[2] *
    controladorpruebaio_B.In1.q[2]) + controladorpruebaio_B.In1.q[3] *
    controladorpruebaio_B.In1.q[3]);
  controladorpruebaio_B.theta = (controladorpruebaio_B.In1.q[1] *
    controladorpruebaio_B.In1.q[3] - controladorpruebaio_B.In1.q[0] *
    controladorpruebaio_B.In1.q[2]) * -2.0F;
  controladorpruebaio_B.theta = static_cast<real32_T>(asin(static_cast<real_T>
    (controladorpruebaio_B.theta)));

  // RateTransition generated from: '<S157>/Proportional Gain' incorporates:
  //   Sum: '<S3>/Sum2'

  if (tmp) {
    controladorpruebaio_DW.TmpRTBAtProportionalGainInport1 =
      controladorpruebaio_B.Gain1 - controladorpruebaio_B.theta;
  }

  // Gain: '<Root>/Gain' incorporates:
  //   Constant: '<Root>/Constant3'
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  controladorpruebaio_B.Gain = controladorpruebaio_P.Gain_Gain * static_cast<
    real32_T>(controladorpruebaio_P.Constant3_Value);

  // Sum: '<S3>/Sum'
  controladorpruebaio_B.Sum = controladorpruebaio_B.Gain -
    controladorpruebaio_B.phi;

  // RateTransition generated from: '<S51>/Proportional Gain'
  if (tmp) {
    controladorpruebaio_DW.TmpRTBAtProportionalGainInpor_b =
      controladorpruebaio_B.Sum;
  }

  // Update for DiscreteIntegrator: '<S100>/Integrator' incorporates:
  //   Gain: '<S90>/Kb'
  //   Gain: '<S97>/Integral Gain'
  //   Sum: '<S90>/SumI2'
  //   Sum: '<S90>/SumI4'

  controladorpruebaio_DW.Integrator_DSTATE += ((controladorpruebaio_B.Saturation
    - rtb_Sum) * controladorpruebaio_P.PIDController1_Kb +
    controladorpruebaio_P.PIDController1_I * rtb_Product3) *
    controladorpruebaio_P.Integrator_gainval;

  // Update for Delay: '<S93>/UD'
  controladorpruebaio_DW.UD_DSTATE = rtb_Tsamp;

  // Update for DiscreteIntegrator: '<S206>/Integrator' incorporates:
  //   Gain: '<S196>/Kb'
  //   Gain: '<S203>/Integral Gain'
  //   Sum: '<S196>/SumI2'
  //   Sum: '<S196>/SumI4'

  controladorpruebaio_DW.Integrator_DSTATE_o += ((rtb_Saturation - rtb_Sum2) *
    controladorpruebaio_P.PIDController3_Kb +
    controladorpruebaio_P.PIDController3_I * rtb_DataTypeConversion3) *
    controladorpruebaio_P.Integrator_gainval_k;

  // Update for Delay: '<S199>/UD'
  controladorpruebaio_DW.UD_DSTATE_k = rtb_Tsamp_e;

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  controladorpruebaio_M->Timing.taskTime0 =
    ((time_T)(++controladorpruebaio_M->Timing.clockTick0)) *
    controladorpruebaio_M->Timing.stepSize0;
}

// Model step function for TID1
void controladorpruebaio_step1(void)   // Sample time: [0.005s, 0.0s]
{
  real32_T rtb_Saturation;

  // Gain: '<S51>/Proportional Gain' incorporates:
  //   RateTransition generated from: '<S51>/Proportional Gain'

  rtb_Saturation = controladorpruebaio_P.PIDController_P *
    controladorpruebaio_DW.TmpRTBAtProportionalGainInpor_b;

  // Saturate: '<S53>/Saturation'
  if (rtb_Saturation > controladorpruebaio_P.PIDController_UpperSaturationLi) {
    rtb_Saturation = controladorpruebaio_P.PIDController_UpperSaturationLi;
  } else if (rtb_Saturation <
             controladorpruebaio_P.PIDController_LowerSaturationLi) {
    rtb_Saturation = controladorpruebaio_P.PIDController_LowerSaturationLi;
  }

  // End of Saturate: '<S53>/Saturation'

  // RateTransition: '<S3>/Rate Transition'
  controladorpruebaio_DW.RateTransition_Buffer0 = rtb_Saturation;

  // Gain: '<S157>/Proportional Gain' incorporates:
  //   RateTransition generated from: '<S157>/Proportional Gain'

  rtb_Saturation = controladorpruebaio_P.PIDController2_P *
    controladorpruebaio_DW.TmpRTBAtProportionalGainInport1;

  // Saturate: '<S159>/Saturation'
  if (rtb_Saturation > controladorpruebaio_P.PIDController2_UpperSaturationL) {
    rtb_Saturation = controladorpruebaio_P.PIDController2_UpperSaturationL;
  } else if (rtb_Saturation <
             controladorpruebaio_P.PIDController2_LowerSaturationL) {
    rtb_Saturation = controladorpruebaio_P.PIDController2_LowerSaturationL;
  }

  // End of Saturate: '<S159>/Saturation'

  // RateTransition: '<S3>/Rate Transition1'
  controladorpruebaio_DW.RateTransition1_Buffer0 = rtb_Saturation;

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.005, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  controladorpruebaio_M->Timing.clockTick1++;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void controladorpruebaio_step(int_T tid)
{
  switch (tid) {
   case 0 :
    controladorpruebaio_step0();
    break;

   case 1 :
    controladorpruebaio_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void controladorpruebaio_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(controladorpruebaio_M, -1);
  controladorpruebaio_M->Timing.stepSize0 = 0.001;

  // External mode info
  controladorpruebaio_M->Sizes.checksums[0] = (514761425U);
  controladorpruebaio_M->Sizes.checksums[1] = (3118904662U);
  controladorpruebaio_M->Sizes.checksums[2] = (4032959609U);
  controladorpruebaio_M->Sizes.checksums[3] = (742505429U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    controladorpruebaio_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &controladorpruebaio_DW.EnabledSubsystem_SubsysRanBC_f;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)
      &controladorpruebaio_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(controladorpruebaio_M->extModeInfo,
      &controladorpruebaio_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controladorpruebaio_M->extModeInfo,
                        controladorpruebaio_M->Sizes.checksums);
    rteiSetTPtr(controladorpruebaio_M->extModeInfo, rtmGetTPtr
                (controladorpruebaio_M));
  }

  // block I/O
  (void) memset((static_cast<void *>(&controladorpruebaio_B)), 0,
                sizeof(B_controladorpruebaio_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&controladorpruebaio_DW), 0,
                sizeof(DW_controladorpruebaio_T));

  {
    int32_T i;

    // Start for RateTransition: '<S3>/Rate Transition'
    controladorpruebaio_B.RateTransition =
      controladorpruebaio_P.RateTransition_InitialCondition;

    // Start for RateTransition: '<S3>/Rate Transition1'
    controladorpruebaio_B.RateTransition1 =
      controladorpruebaio_P.RateTransition1_InitialConditio;

    // InitializeConditions for RateTransition: '<S3>/Rate Transition'
    controladorpruebaio_DW.RateTransition_Buffer0 =
      controladorpruebaio_P.RateTransition_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S100>/Integrator'
    controladorpruebaio_DW.Integrator_DSTATE =
      controladorpruebaio_P.PIDController1_InitialCondition;

    // InitializeConditions for Delay: '<S93>/UD'
    controladorpruebaio_DW.UD_DSTATE =
      controladorpruebaio_P.PIDController1_DifferentiatorIC;

    // InitializeConditions for RateTransition: '<S3>/Rate Transition1'
    controladorpruebaio_DW.RateTransition1_Buffer0 =
      controladorpruebaio_P.RateTransition1_InitialConditio;

    // InitializeConditions for DiscreteIntegrator: '<S206>/Integrator'
    controladorpruebaio_DW.Integrator_DSTATE_o =
      controladorpruebaio_P.PIDController3_InitialCondition;

    // InitializeConditions for Delay: '<S199>/UD'
    controladorpruebaio_DW.UD_DSTATE_k =
      controladorpruebaio_P.PIDController3_DifferentiatorIC;

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S7>/In1' incorporates:
    //   Outport: '<S7>/Out1'

    controladorpruebaio_B.In1_e = controladorpruebaio_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S224>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S225>/In1' incorporates:
    //   Outport: '<S225>/Out1'

    controladorpruebaio_B.In1 = controladorpruebaio_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S224>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    controladorpruebaio_DW.obj_d.matlabCodegenIsDeleted = false;
    controladorpruebaio_DW.obj_d.isSetupComplete = false;
    controladorpruebaio_DW.obj_d.isInitialized = 1;
    controladorpruebaio_DW.obj_d.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(controladorpruebaio_DW.obj_d.orbMetadataObj,
                         &controladorpruebaio_DW.obj_d.eventStructObj);
    controladorpruebaio_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    for (i = 0; i < 12; i++) {
      controladorpruebaio_DW.obj.ValidMotorIdx[i] = false;
    }

    for (i = 0; i < 8; i++) {
      controladorpruebaio_DW.obj.ValidServoIdx[i] = false;
    }

    controladorpruebaio_DW.obj.matlabCodegenIsDeleted = false;
    controladorpruebaio_DW.obj.isSetupComplete = false;
    controladorpruebaio_DW.obj.isInitialized = 1;
    controla_PX4Actuators_setupImpl(&controladorpruebaio_DW.obj);
    controladorpruebaio_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/PX4 Actuator Write'

    // Start for MATLABSystem: '<S224>/SourceBlock'
    controladorpruebaio_DW.obj_c.matlabCodegenIsDeleted = false;
    controladorpruebaio_DW.obj_c.isSetupComplete = false;
    controladorpruebaio_DW.obj_c.isInitialized = 1;
    controladorpruebaio_DW.obj_c.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(controladorpruebaio_DW.obj_c.orbMetadataObj,
                         &controladorpruebaio_DW.obj_c.eventStructObj);
    controladorpruebaio_DW.obj_c.isSetupComplete = true;
  }
}

// Model terminate function
void controladorpruebaio_terminate(void)
{
  int32_T i;
  real32_T servoValues[8];

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!controladorpruebaio_DW.obj_d.matlabCodegenIsDeleted) {
    controladorpruebaio_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((controladorpruebaio_DW.obj_d.isInitialized == 1) &&
        controladorpruebaio_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&controladorpruebaio_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  if (!controladorpruebaio_DW.obj.matlabCodegenIsDeleted) {
    controladorpruebaio_DW.obj.matlabCodegenIsDeleted = true;
    if ((controladorpruebaio_DW.obj.isInitialized == 1) &&
        controladorpruebaio_DW.obj.isSetupComplete) {
      for (i = 0; i < 12; i++) {
        controladorpruebaio_B.motorValues_m[i] = (rtNaNF);
      }

      for (i = 0; i < 8; i++) {
        servoValues[i] = (rtNaNF);
      }

      for (i = 0; i < 12; i++) {
        if (controladorpruebaio_DW.obj.ValidMotorIdx[i]) {
          controladorpruebaio_B.motorValues_m[i] = 0.0F;
        }
      }

      for (i = 0; i < 8; i++) {
        if (controladorpruebaio_DW.obj.ValidServoIdx[i]) {
          servoValues[i] = 0.0F;
        }
      }

      MW_actuators_set(false, &controladorpruebaio_B.motorValues_m[0],
                       &servoValues[0]);
      MW_actuators_terminate();
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  // Terminate for MATLABSystem: '<S224>/SourceBlock'
  if (!controladorpruebaio_DW.obj_c.matlabCodegenIsDeleted) {
    controladorpruebaio_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((controladorpruebaio_DW.obj_c.isInitialized == 1) &&
        controladorpruebaio_DW.obj_c.isSetupComplete) {
      uORB_read_terminate(&controladorpruebaio_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S224>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
