//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: multipid.cpp
//
// Code generated for Simulink model 'multipid'.
//
// Model version                  : 12.32
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Tue Jan 27 15:06:23 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "multipid.h"
#include "multipid_types.h"
#include "multipid_private.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

// Block signals (default storage)
B_multipid_T multipid_B;

// Block states (default storage)
DW_multipid_T multipid_DW;

// Real-time model
RT_MODEL_multipid_T multipid_M_ = RT_MODEL_multipid_T();
RT_MODEL_multipid_T *const multipid_M = &multipid_M_;

// Forward declaration for local functions
static void multipid_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void multipid_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(multipid_M, 1));
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
  multipid_M->Timing.RateInteraction.TID0_1 =
    (multipid_M->Timing.TaskCounters.TID[1] == 0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (multipid_M->Timing.TaskCounters.TID[1])++;
  if ((multipid_M->Timing.TaskCounters.TID[1]) > 4) {// Sample time: [0.005s, 0.0s] 
    multipid_M->Timing.TaskCounters.TID[1] = 0;
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

static void multipid_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj)
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
void multipid_step0(void)              // Sample time: [0.001s, 0.0s]
{
  int32_T i;
  real32_T M1_tmp;
  real32_T M1_tmp_0;
  real32_T rtb_DeadZone;
  real32_T rtb_Gain2;
  real32_T rtb_MultiportSwitch_idx_0;
  real32_T rtb_MultiportSwitch_idx_1;
  real32_T rtb_MultiportSwitch_idx_2;
  real32_T rtb_Saturation_lx;
  real32_T rtb_Tsamp_ac;
  real32_T rtb_Tsamp_ct;
  real32_T rtb_Tsamp_g;
  real32_T rtb_Tsamp_l;
  boolean_T b_varargout_1;
  boolean_T rtb_Switch;
  boolean_T tmp;

  {                                    // Sample time: [0.001s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Reset subsysRan breadcrumbs
  srClearBC(multipid_DW.EnabledSubsystem_SubsysRanBC_h);

  // Reset subsysRan breadcrumbs
  srClearBC(multipid_DW.EnabledSubsystem_SubsysRanBC);

  // MATLABSystem: '<S117>/SourceBlock'
  b_varargout_1 = uORB_read_step(multipid_DW.obj_l.orbMetadataObj,
    &multipid_DW.obj_l.eventStructObj, &multipid_B.r1, false, 5000.0);

  // Outputs for Enabled SubSystem: '<S117>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S118>/Enable'

  // Start for MATLABSystem: '<S117>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S118>/In1'
    multipid_B.In1_k = multipid_B.r1;
    srUpdateBC(multipid_DW.EnabledSubsystem_SubsysRanBC_h);
  }

  // End of Outputs for SubSystem: '<S117>/Enabled Subsystem'

  // MATLAB Function: '<Root>/MATLAB Function1'
  if ((multipid_B.In1_k.values[4] > 1000) && (multipid_B.In1_k.values[4] < 1200))
  {
    multipid_B.y = 1.0;
  } else if ((multipid_B.In1_k.values[4] >= 1200) && (multipid_B.In1_k.values[4]
              < 1400)) {
    multipid_B.y = 2.0;
  } else {
    multipid_B.y = 3.0;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function1'

  // Switch: '<Root>/Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant1'
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  if (multipid_B.In1_k.values[7] > multipid_P.Switch_Threshold) {
    rtb_Switch = multipid_P.Constant1_Value;
  } else {
    rtb_Switch = multipid_P.Constant_Value_b;
  }

  // End of Switch: '<Root>/Switch'

  // RateTransition: '<S3>/Rate Transition' incorporates:
  //   RateTransition generated from: '<S104>/Proportional Gain'
  //   RateTransition: '<S3>/Rate Transition1'
  //   RateTransition generated from: '<S52>/Proportional Gain'

  tmp = multipid_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    // RateTransition: '<S3>/Rate Transition'
    multipid_B.RateTransition = multipid_DW.RateTransition_Buffer0;
  }

  // End of RateTransition: '<S3>/Rate Transition'

  // MATLABSystem: '<S614>/SourceBlock'
  b_varargout_1 = uORB_read_step(multipid_DW.obj_c.orbMetadataObj,
    &multipid_DW.obj_c.eventStructObj, &multipid_B.r, false, 1.0);

  // Outputs for Enabled SubSystem: '<S614>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S615>/Enable'

  // Start for MATLABSystem: '<S614>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S615>/In1'
    multipid_B.In1 = multipid_B.r;
    srUpdateBC(multipid_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S614>/Enabled Subsystem'

  // SignalConversion: '<S9>/Signal Copy'
  multipid_B.rollspeed = multipid_B.In1.angular_velocity[0];

  // Product: '<Root>/Product2' incorporates:
  //   Sum: '<S3>/Sum1'

  multipid_B.Product2 = (multipid_B.RateTransition - multipid_B.rollspeed) *
    static_cast<real32_T>(rtb_Switch);

  // SampleTimeMath: '<S153>/Tsamp' incorporates:
  //   Gain: '<S149>/Derivative Gain'
  //
  //  About '<S153>/Tsamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  multipid_B.Tsamp = multipid_P.PIDController1_D * multipid_B.Product2 *
    multipid_P.Tsamp_WtEt;

  // Sum: '<S167>/Sum' incorporates:
  //   Delay: '<S151>/UD'
  //   DiscreteIntegrator: '<S158>/Integrator'
  //   Gain: '<S163>/Proportional Gain'
  //   Sum: '<S151>/Diff'

  multipid_B.Sum_h = (multipid_P.PIDController1_P * multipid_B.Product2 +
                      multipid_DW.Integrator_DSTATE) + (multipid_B.Tsamp -
    multipid_DW.UD_DSTATE);

  // Saturate: '<S165>/Saturation'
  if (multipid_B.Sum_h > multipid_P.PIDController1_UpperSaturationL) {
    multipid_B.Saturation = multipid_P.PIDController1_UpperSaturationL;
  } else if (multipid_B.Sum_h < multipid_P.PIDController1_LowerSaturationL) {
    multipid_B.Saturation = multipid_P.PIDController1_LowerSaturationL;
  } else {
    multipid_B.Saturation = multipid_B.Sum_h;
  }

  // End of Saturate: '<S165>/Saturation'

  // RateTransition: '<S3>/Rate Transition1'
  if (tmp) {
    // RateTransition: '<S3>/Rate Transition1'
    multipid_B.RateTransition1 = multipid_DW.RateTransition1_Buffer0;
  }

  // SignalConversion: '<S9>/Signal Copy1'
  multipid_B.pitchspeed = multipid_B.In1.angular_velocity[1];

  // Product: '<Root>/Product3' incorporates:
  //   Sum: '<S3>/Sum3'

  multipid_B.Product3 = (multipid_B.RateTransition1 - multipid_B.pitchspeed) *
    static_cast<real32_T>(rtb_Switch);

  // SampleTimeMath: '<S261>/Tsamp' incorporates:
  //   Gain: '<S257>/Derivative Gain'
  //
  //  About '<S261>/Tsamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  multipid_B.Tsamp_j = multipid_P.PIDController4_D * multipid_B.Product3 *
    multipid_P.Tsamp_WtEt_f;

  // Sum: '<S275>/Sum' incorporates:
  //   Delay: '<S259>/UD'
  //   DiscreteIntegrator: '<S266>/Integrator'
  //   Gain: '<S271>/Proportional Gain'
  //   Sum: '<S259>/Diff'

  multipid_B.Sum_o = (multipid_P.PIDController4_P * multipid_B.Product3 +
                      multipid_DW.Integrator_DSTATE_f) + (multipid_B.Tsamp_j -
    multipid_DW.UD_DSTATE_l);

  // Saturate: '<S273>/Saturation'
  if (multipid_B.Sum_o > multipid_P.PIDController4_UpperSaturationL) {
    multipid_B.Saturation_o = multipid_P.PIDController4_UpperSaturationL;
  } else if (multipid_B.Sum_o < multipid_P.PIDController4_LowerSaturationL) {
    multipid_B.Saturation_o = multipid_P.PIDController4_LowerSaturationL;
  } else {
    multipid_B.Saturation_o = multipid_B.Sum_o;
  }

  // End of Saturate: '<S273>/Saturation'

  // SignalConversion: '<S9>/Signal Copy2'
  multipid_B.yawspeed = multipid_B.In1.angular_velocity[2];

  // DeadZone: '<S6>/Dead Zone3' incorporates:
  //   DataTypeConversion: '<S6>/Data Type Conversion2'

  if (multipid_B.In1_k.values[3] > multipid_P.DeadZone3_End) {
    M1_tmp_0 = static_cast<real32_T>(multipid_B.In1_k.values[3]) -
      multipid_P.DeadZone3_End;
  } else if (multipid_B.In1_k.values[3] >= multipid_P.DeadZone3_Start) {
    M1_tmp_0 = 0.0F;
  } else {
    M1_tmp_0 = static_cast<real32_T>(multipid_B.In1_k.values[3]) -
      multipid_P.DeadZone3_Start;
  }

  // Fcn: '<S6>/Fcn3' incorporates:
  //   DeadZone: '<S6>/Dead Zone3'

  rtb_DeadZone = (M1_tmp_0 - 1494.0F) / 409.5F;

  // Saturate: '<S6>/Saturation3'
  if (rtb_DeadZone > multipid_P.Saturation3_UpperSat) {
    rtb_DeadZone = multipid_P.Saturation3_UpperSat;
  } else if (rtb_DeadZone < multipid_P.Saturation3_LowerSat) {
    rtb_DeadZone = multipid_P.Saturation3_LowerSat;
  }

  // Product: '<Root>/Product' incorporates:
  //   Saturate: '<S6>/Saturation3'
  //   Sum: '<Root>/Sum1'

  multipid_B.Product = (rtb_DeadZone - multipid_B.yawspeed) * static_cast<
    real32_T>(rtb_Switch);

  // SampleTimeMath: '<S207>/Tsamp' incorporates:
  //   Gain: '<S203>/Derivative Gain'
  //
  //  About '<S207>/Tsamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  multipid_B.Tsamp_p = multipid_P.PIDController2_D * multipid_B.Product *
    multipid_P.Tsamp_WtEt_fp;

  // Sum: '<S221>/Sum' incorporates:
  //   Delay: '<S205>/UD'
  //   DiscreteIntegrator: '<S212>/Integrator'
  //   Gain: '<S217>/Proportional Gain'
  //   Sum: '<S205>/Diff'

  multipid_B.Sum_a = (multipid_P.PIDController2_P * multipid_B.Product +
                      multipid_DW.Integrator_DSTATE_n) + (multipid_B.Tsamp_p -
    multipid_DW.UD_DSTATE_a);

  // Saturate: '<S219>/Saturation'
  if (multipid_B.Sum_a > multipid_P.PIDController2_UpperSaturationL) {
    multipid_B.Saturation_m = multipid_P.PIDController2_UpperSaturationL;
  } else if (multipid_B.Sum_a < multipid_P.PIDController2_LowerSaturationL) {
    multipid_B.Saturation_m = multipid_P.PIDController2_LowerSaturationL;
  } else {
    multipid_B.Saturation_m = multipid_B.Sum_a;
  }

  // End of Saturate: '<S219>/Saturation'

  // SampleTimeMath: '<S318>/Tsamp' incorporates:
  //   Gain: '<S314>/Derivative Gain'
  //
  //  About '<S318>/Tsamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  multipid_B.Tsamp_i = multipid_P.PIDController1_D_j * multipid_B.Product2 *
    multipid_P.Tsamp_WtEt_fi;

  // Sum: '<S332>/Sum' incorporates:
  //   Delay: '<S316>/UD'
  //   DiscreteIntegrator: '<S323>/Integrator'
  //   Gain: '<S328>/Proportional Gain'
  //   Sum: '<S316>/Diff'

  multipid_B.Sum_g = (multipid_P.PIDController1_P_d * multipid_B.Product2 +
                      multipid_DW.Integrator_DSTATE_fy) + (multipid_B.Tsamp_i -
    multipid_DW.UD_DSTATE_k);

  // Saturate: '<S330>/Saturation'
  if (multipid_B.Sum_g > multipid_P.PIDController1_UpperSaturatio_n) {
    multipid_B.Saturation_i = multipid_P.PIDController1_UpperSaturatio_n;
  } else if (multipid_B.Sum_g < multipid_P.PIDController1_LowerSaturatio_i) {
    multipid_B.Saturation_i = multipid_P.PIDController1_LowerSaturatio_i;
  } else {
    multipid_B.Saturation_i = multipid_B.Sum_g;
  }

  // End of Saturate: '<S330>/Saturation'

  // SampleTimeMath: '<S372>/Tsamp' incorporates:
  //   Gain: '<S368>/Derivative Gain'
  //
  //  About '<S372>/Tsamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  multipid_B.Tsamp_f = multipid_P.PIDController2_D_m * multipid_B.Product3 *
    multipid_P.Tsamp_WtEt_l;

  // Sum: '<S386>/Sum' incorporates:
  //   Delay: '<S370>/UD'
  //   DiscreteIntegrator: '<S377>/Integrator'
  //   Gain: '<S382>/Proportional Gain'
  //   Sum: '<S370>/Diff'

  multipid_B.Sum_k = (multipid_P.PIDController2_P_p * multipid_B.Product3 +
                      multipid_DW.Integrator_DSTATE_j) + (multipid_B.Tsamp_f -
    multipid_DW.UD_DSTATE_d);

  // Saturate: '<S384>/Saturation'
  if (multipid_B.Sum_k > multipid_P.PIDController2_UpperSaturatio_n) {
    multipid_B.Saturation_n = multipid_P.PIDController2_UpperSaturatio_n;
  } else if (multipid_B.Sum_k < multipid_P.PIDController2_LowerSaturatio_j) {
    multipid_B.Saturation_n = multipid_P.PIDController2_LowerSaturatio_j;
  } else {
    multipid_B.Saturation_n = multipid_B.Sum_k;
  }

  // End of Saturate: '<S384>/Saturation'

  // SampleTimeMath: '<S426>/Tsamp' incorporates:
  //   Gain: '<S422>/Derivative Gain'
  //
  //  About '<S426>/Tsamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_Tsamp_g = multipid_P.PIDController3_D * multipid_B.Product *
    multipid_P.Tsamp_WtEt_n;

  // Sum: '<S440>/Sum' incorporates:
  //   Delay: '<S424>/UD'
  //   DiscreteIntegrator: '<S431>/Integrator'
  //   Gain: '<S436>/Proportional Gain'
  //   Sum: '<S424>/Diff'

  rtb_DeadZone = (multipid_P.PIDController3_P * multipid_B.Product +
                  multipid_DW.Integrator_DSTATE_jr) + (rtb_Tsamp_g -
    multipid_DW.UD_DSTATE_b);

  // Saturate: '<S438>/Saturation'
  if (rtb_DeadZone > multipid_P.PIDController3_UpperSaturationL) {
    rtb_Saturation_lx = multipid_P.PIDController3_UpperSaturationL;
  } else if (rtb_DeadZone < multipid_P.PIDController3_LowerSaturationL) {
    rtb_Saturation_lx = multipid_P.PIDController3_LowerSaturationL;
  } else {
    rtb_Saturation_lx = rtb_DeadZone;
  }

  // End of Saturate: '<S438>/Saturation'

  // SampleTimeMath: '<S483>/Tsamp' incorporates:
  //   Gain: '<S479>/Derivative Gain'
  //
  //  About '<S483>/Tsamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_Tsamp_ct = multipid_P.PIDController_D * multipid_B.Product2 *
    multipid_P.Tsamp_WtEt_c;

  // SampleTimeMath: '<S537>/Tsamp' incorporates:
  //   Gain: '<S533>/Derivative Gain'
  //
  //  About '<S537>/Tsamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_Tsamp_l = multipid_P.PIDController1_D_e * multipid_B.Product3 *
    multipid_P.Tsamp_WtEt_g;

  // SampleTimeMath: '<S591>/Tsamp' incorporates:
  //   Gain: '<S587>/Derivative Gain'
  //
  //  About '<S591>/Tsamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_Tsamp_ac = multipid_P.PIDController2_D_d * multipid_B.Product *
    multipid_P.Tsamp_WtEt_p;

  // MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
  //   Delay: '<S481>/UD'
  //   Delay: '<S535>/UD'
  //   Delay: '<S589>/UD'
  //   DiscreteIntegrator: '<S488>/Integrator'
  //   DiscreteIntegrator: '<S542>/Integrator'
  //   DiscreteIntegrator: '<S596>/Integrator'
  //   Gain: '<S493>/Proportional Gain'
  //   Gain: '<S547>/Proportional Gain'
  //   Gain: '<S601>/Proportional Gain'
  //   Sum: '<S481>/Diff'
  //   Sum: '<S497>/Sum'
  //   Sum: '<S535>/Diff'
  //   Sum: '<S551>/Sum'
  //   Sum: '<S589>/Diff'
  //   Sum: '<S605>/Sum'

  switch (static_cast<int32_T>(multipid_B.y)) {
   case 1:
    rtb_MultiportSwitch_idx_0 = multipid_B.Saturation;
    rtb_MultiportSwitch_idx_1 = multipid_B.Saturation_o;
    rtb_MultiportSwitch_idx_2 = multipid_B.Saturation_m;
    break;

   case 2:
    rtb_MultiportSwitch_idx_0 = multipid_B.Saturation_i;
    rtb_MultiportSwitch_idx_1 = multipid_B.Saturation_n;
    rtb_MultiportSwitch_idx_2 = rtb_Saturation_lx;
    break;

   default:
    rtb_MultiportSwitch_idx_0 = (multipid_P.PIDController_P *
      multipid_B.Product2 + multipid_DW.Integrator_DSTATE_i) + (rtb_Tsamp_ct -
      multipid_DW.UD_DSTATE_du);
    rtb_MultiportSwitch_idx_1 = (multipid_P.PIDController1_P_o *
      multipid_B.Product3 + multipid_DW.Integrator_DSTATE_o) + (rtb_Tsamp_l -
      multipid_DW.UD_DSTATE_do);
    rtb_MultiportSwitch_idx_2 = (multipid_P.PIDController2_P_h *
      multipid_B.Product + multipid_DW.Integrator_DSTATE_iu) + (rtb_Tsamp_ac -
      multipid_DW.UD_DSTATE_h);
    break;
  }

  // End of MultiPortSwitch: '<Root>/Multiport Switch'

  // DeadZone: '<S6>/Dead Zone2' incorporates:
  //   DataTypeConversion: '<S6>/Data Type Conversion5'

  if (multipid_B.In1_k.values[2] > multipid_P.DeadZone2_End) {
    M1_tmp_0 = static_cast<real32_T>(multipid_B.In1_k.values[2]) -
      multipid_P.DeadZone2_End;
  } else if (multipid_B.In1_k.values[2] >= multipid_P.DeadZone2_Start) {
    M1_tmp_0 = 0.0F;
  } else {
    M1_tmp_0 = static_cast<real32_T>(multipid_B.In1_k.values[2]) -
      multipid_P.DeadZone2_Start;
  }

  // Fcn: '<S6>/Fcn2' incorporates:
  //   DeadZone: '<S6>/Dead Zone2'

  multipid_B.Saturation2 = (M1_tmp_0 - 1084.0F) / 819.0F;

  // Saturate: '<S6>/Saturation2'
  if (multipid_B.Saturation2 > multipid_P.Saturation2_UpperSat) {
    // Fcn: '<S6>/Fcn2' incorporates:
    //   Saturate: '<S6>/Saturation2'

    multipid_B.Saturation2 = multipid_P.Saturation2_UpperSat;
  } else if (multipid_B.Saturation2 < multipid_P.Saturation2_LowerSat) {
    // Fcn: '<S6>/Fcn2' incorporates:
    //   Saturate: '<S6>/Saturation2'

    multipid_B.Saturation2 = multipid_P.Saturation2_LowerSat;
  }

  // End of Saturate: '<S6>/Saturation2'

  // Gain: '<Root>/Gain2'
  rtb_Gain2 = multipid_P.Gain2_Gain * multipid_B.Saturation2;

  // MATLAB Function: '<Root>/MATLAB Function'
  M1_tmp = 0.707107F * rtb_MultiportSwitch_idx_0;
  M1_tmp_0 = 0.707107F * rtb_MultiportSwitch_idx_1;
  rtb_MultiportSwitch_idx_0 = rtb_Gain2 - M1_tmp;
  multipid_B.M1 = (rtb_MultiportSwitch_idx_0 + M1_tmp_0) +
    rtb_MultiportSwitch_idx_2;
  rtb_Gain2 += M1_tmp;
  multipid_B.M2 = (rtb_Gain2 - M1_tmp_0) + rtb_MultiportSwitch_idx_2;
  multipid_B.M3 = (rtb_Gain2 + M1_tmp_0) - rtb_MultiportSwitch_idx_2;
  multipid_B.M4 = (rtb_MultiportSwitch_idx_0 - M1_tmp_0) -
    rtb_MultiportSwitch_idx_2;

  // SignalConversion generated from: '<Root>/To Workspace4'
  multipid_B.TmpSignalConversionAt_asyncqueu[0] = multipid_B.M1;
  multipid_B.TmpSignalConversionAt_asyncqueu[1] = multipid_B.M2;
  multipid_B.TmpSignalConversionAt_asyncqueu[2] = multipid_B.M3;
  multipid_B.TmpSignalConversionAt_asyncqueu[3] = multipid_B.M4;

  // MATLABSystem: '<Root>/PX4 Actuator Write'
  for (i = 0; i < 12; i++) {
    multipid_B.motorValues[i] = (rtNaNF);
  }

  for (i = 0; i < 8; i++) {
    multipid_B.servoValues[i] = (rtNaNF);
  }

  // Saturate: '<Root>/Saturation4'
  if (multipid_B.TmpSignalConversionAt_asyncqueu[0] >
      multipid_P.Saturation4_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[0] = multipid_P.Saturation4_UpperSat;
  } else if (multipid_B.TmpSignalConversionAt_asyncqueu[0] <
             multipid_P.Saturation4_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[0] = multipid_P.Saturation4_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[0] = multipid_B.TmpSignalConversionAt_asyncqueu[0];
  }

  if (multipid_B.TmpSignalConversionAt_asyncqueu[1] >
      multipid_P.Saturation4_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[1] = multipid_P.Saturation4_UpperSat;
  } else if (multipid_B.TmpSignalConversionAt_asyncqueu[1] <
             multipid_P.Saturation4_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[1] = multipid_P.Saturation4_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[1] = multipid_B.TmpSignalConversionAt_asyncqueu[1];
  }

  if (multipid_B.TmpSignalConversionAt_asyncqueu[2] >
      multipid_P.Saturation4_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[2] = multipid_P.Saturation4_UpperSat;
  } else if (multipid_B.TmpSignalConversionAt_asyncqueu[2] <
             multipid_P.Saturation4_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[2] = multipid_P.Saturation4_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[2] = multipid_B.TmpSignalConversionAt_asyncqueu[2];
  }

  if (multipid_B.TmpSignalConversionAt_asyncqueu[3] >
      multipid_P.Saturation4_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[3] = multipid_P.Saturation4_UpperSat;
  } else if (multipid_B.TmpSignalConversionAt_asyncqueu[3] <
             multipid_P.Saturation4_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[3] = multipid_P.Saturation4_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    multipid_B.motorValues[3] = multipid_B.TmpSignalConversionAt_asyncqueu[3];
  }

  // End of Saturate: '<Root>/Saturation4'

  // MATLABSystem: '<Root>/PX4 Actuator Write'
  MW_actuators_set(rtb_Switch, &multipid_B.motorValues[0],
                   &multipid_B.servoValues[0]);

  // Gain: '<S421>/Kb' incorporates:
  //   Sum: '<S421>/SumI2'

  rtb_Saturation_lx = (rtb_Saturation_lx - rtb_DeadZone) *
    multipid_P.PIDController3_Kb;

  // DeadZone: '<S6>/Dead Zone' incorporates:
  //   DataTypeConversion: '<S6>/Data Type Conversion3'

  if (multipid_B.In1_k.values[0] > multipid_P.DeadZone_End) {
    M1_tmp_0 = static_cast<real32_T>(multipid_B.In1_k.values[0]) -
      multipid_P.DeadZone_End;
  } else if (multipid_B.In1_k.values[0] >= multipid_P.DeadZone_Start) {
    M1_tmp_0 = 0.0F;
  } else {
    M1_tmp_0 = static_cast<real32_T>(multipid_B.In1_k.values[0]) -
      multipid_P.DeadZone_Start;
  }

  // Fcn: '<S6>/Fcn' incorporates:
  //   DeadZone: '<S6>/Dead Zone'

  rtb_DeadZone = (M1_tmp_0 - 1494.0F) / 409.5F;

  // Saturate: '<S6>/Saturation'
  if (rtb_DeadZone > multipid_P.Saturation_UpperSat) {
    rtb_DeadZone = multipid_P.Saturation_UpperSat;
  } else if (rtb_DeadZone < multipid_P.Saturation_LowerSat) {
    rtb_DeadZone = multipid_P.Saturation_LowerSat;
  }

  // Sum: '<S3>/Sum' incorporates:
  //   Gain: '<Root>/Gain'
  //   MATLAB Function: '<Root>/quat2eul'
  //   Saturate: '<S6>/Saturation'

  rtb_DeadZone = multipid_P.Gain_Gain * rtb_DeadZone - rt_atan2f_snf
    ((multipid_B.In1.q[0] * multipid_B.In1.q[1] + multipid_B.In1.q[2] *
      multipid_B.In1.q[3]) * 2.0F, ((multipid_B.In1.q[0] * multipid_B.In1.q[0] -
       multipid_B.In1.q[1] * multipid_B.In1.q[1]) - multipid_B.In1.q[2] *
      multipid_B.In1.q[2]) + multipid_B.In1.q[3] * multipid_B.In1.q[3]);

  // DeadZone: '<S3>/Dead Zone1'
  if (rtb_DeadZone > multipid_P.DeadZone1_End) {
    rtb_DeadZone -= multipid_P.DeadZone1_End;
  } else if (rtb_DeadZone >= multipid_P.DeadZone1_Start) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= multipid_P.DeadZone1_Start;
  }

  // End of DeadZone: '<S3>/Dead Zone1'

  // RateTransition generated from: '<S52>/Proportional Gain'
  if (tmp) {
    multipid_DW.TmpRTBAtProportionalGainInport1 = rtb_DeadZone;
  }

  // DeadZone: '<S6>/Dead Zone1' incorporates:
  //   DataTypeConversion: '<S6>/Data Type Conversion4'

  if (multipid_B.In1_k.values[1] > multipid_P.DeadZone1_End_o) {
    M1_tmp_0 = static_cast<real32_T>(multipid_B.In1_k.values[1]) -
      multipid_P.DeadZone1_End_o;
  } else if (multipid_B.In1_k.values[1] >= multipid_P.DeadZone1_Start_a) {
    M1_tmp_0 = 0.0F;
  } else {
    M1_tmp_0 = static_cast<real32_T>(multipid_B.In1_k.values[1]) -
      multipid_P.DeadZone1_Start_a;
  }

  // Fcn: '<S6>/Fcn1' incorporates:
  //   DeadZone: '<S6>/Dead Zone1'

  rtb_DeadZone = (M1_tmp_0 - 1496.0F) / 409.5F;

  // Saturate: '<S6>/Saturation1'
  if (rtb_DeadZone > multipid_P.Saturation1_UpperSat) {
    rtb_DeadZone = multipid_P.Saturation1_UpperSat;
  } else if (rtb_DeadZone < multipid_P.Saturation1_LowerSat) {
    rtb_DeadZone = multipid_P.Saturation1_LowerSat;
  }

  // Sum: '<S3>/Sum2' incorporates:
  //   Gain: '<Root>/Gain1'
  //   MATLAB Function: '<Root>/quat2eul'
  //   Saturate: '<S6>/Saturation1'

  rtb_DeadZone = multipid_P.Gain1_Gain * rtb_DeadZone - static_cast<real32_T>
    (asin(static_cast<real_T>((multipid_B.In1.q[1] * multipid_B.In1.q[3] -
        multipid_B.In1.q[0] * multipid_B.In1.q[2]) * -2.0F)));

  // DeadZone: '<S3>/Dead Zone'
  if (rtb_DeadZone > multipid_P.DeadZone_End_m) {
    rtb_DeadZone -= multipid_P.DeadZone_End_m;
  } else if (rtb_DeadZone >= multipid_P.DeadZone_Start_i) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= multipid_P.DeadZone_Start_i;
  }

  // End of DeadZone: '<S3>/Dead Zone'

  // RateTransition generated from: '<S104>/Proportional Gain'
  if (tmp) {
    multipid_DW.TmpRTBAtProportionalGainInpor_b = rtb_DeadZone;
  }

  // Update for DiscreteIntegrator: '<S158>/Integrator' incorporates:
  //   Gain: '<S148>/Kb'
  //   Gain: '<S155>/Integral Gain'
  //   Sum: '<S148>/SumI2'
  //   Sum: '<S148>/SumI4'

  multipid_DW.Integrator_DSTATE += ((multipid_B.Saturation - multipid_B.Sum_h) *
    multipid_P.PIDController1_Kb_f + multipid_P.PIDController1_I_h *
    multipid_B.Product2) * multipid_P.Integrator_gainval;

  // Update for Delay: '<S151>/UD'
  multipid_DW.UD_DSTATE = multipid_B.Tsamp;

  // Update for DiscreteIntegrator: '<S266>/Integrator' incorporates:
  //   Gain: '<S256>/Kb'
  //   Gain: '<S263>/Integral Gain'
  //   Sum: '<S256>/SumI2'
  //   Sum: '<S256>/SumI4'

  multipid_DW.Integrator_DSTATE_f += ((multipid_B.Saturation_o -
    multipid_B.Sum_o) * multipid_P.PIDController4_Kb +
    multipid_P.PIDController4_I * multipid_B.Product3) *
    multipid_P.Integrator_gainval_n;

  // Update for Delay: '<S259>/UD'
  multipid_DW.UD_DSTATE_l = multipid_B.Tsamp_j;

  // Update for DiscreteIntegrator: '<S212>/Integrator' incorporates:
  //   Gain: '<S202>/Kb'
  //   Gain: '<S209>/Integral Gain'
  //   Sum: '<S202>/SumI2'
  //   Sum: '<S202>/SumI4'

  multipid_DW.Integrator_DSTATE_n += ((multipid_B.Saturation_m -
    multipid_B.Sum_a) * multipid_P.PIDController2_Kb_j +
    multipid_P.PIDController2_I_p * multipid_B.Product) *
    multipid_P.Integrator_gainval_g;

  // Update for Delay: '<S205>/UD'
  multipid_DW.UD_DSTATE_a = multipid_B.Tsamp_p;

  // Update for DiscreteIntegrator: '<S323>/Integrator' incorporates:
  //   Gain: '<S313>/Kb'
  //   Gain: '<S320>/Integral Gain'
  //   Sum: '<S313>/SumI2'
  //   Sum: '<S313>/SumI4'

  multipid_DW.Integrator_DSTATE_fy += ((multipid_B.Saturation_i -
    multipid_B.Sum_g) * multipid_P.PIDController1_Kb +
    multipid_P.PIDController1_I * multipid_B.Product2) *
    multipid_P.Integrator_gainval_i;

  // Update for Delay: '<S316>/UD'
  multipid_DW.UD_DSTATE_k = multipid_B.Tsamp_i;

  // Update for DiscreteIntegrator: '<S377>/Integrator' incorporates:
  //   Gain: '<S367>/Kb'
  //   Gain: '<S374>/Integral Gain'
  //   Sum: '<S367>/SumI2'
  //   Sum: '<S367>/SumI4'

  multipid_DW.Integrator_DSTATE_j += ((multipid_B.Saturation_n -
    multipid_B.Sum_k) * multipid_P.PIDController2_Kb +
    multipid_P.PIDController2_I * multipid_B.Product3) *
    multipid_P.Integrator_gainval_p;

  // Update for Delay: '<S370>/UD'
  multipid_DW.UD_DSTATE_d = multipid_B.Tsamp_f;

  // Update for DiscreteIntegrator: '<S431>/Integrator' incorporates:
  //   Gain: '<S428>/Integral Gain'
  //   Sum: '<S421>/SumI4'

  multipid_DW.Integrator_DSTATE_jr += (multipid_P.PIDController3_I *
    multipid_B.Product + rtb_Saturation_lx) * multipid_P.Integrator_gainval_na;

  // Update for Delay: '<S424>/UD'
  multipid_DW.UD_DSTATE_b = rtb_Tsamp_g;

  // Update for DiscreteIntegrator: '<S488>/Integrator' incorporates:
  //   Gain: '<S485>/Integral Gain'

  multipid_DW.Integrator_DSTATE_i += multipid_P.PIDController_I *
    multipid_B.Product2 * multipid_P.Integrator_gainval_a;

  // Update for Delay: '<S481>/UD'
  multipid_DW.UD_DSTATE_du = rtb_Tsamp_ct;

  // Update for DiscreteIntegrator: '<S542>/Integrator' incorporates:
  //   Gain: '<S539>/Integral Gain'

  multipid_DW.Integrator_DSTATE_o += multipid_P.PIDController1_I_d *
    multipid_B.Product3 * multipid_P.Integrator_gainval_nl;

  // Update for Delay: '<S535>/UD'
  multipid_DW.UD_DSTATE_do = rtb_Tsamp_l;

  // Update for DiscreteIntegrator: '<S596>/Integrator' incorporates:
  //   Gain: '<S593>/Integral Gain'

  multipid_DW.Integrator_DSTATE_iu += multipid_P.PIDController2_I_h *
    multipid_B.Product * multipid_P.Integrator_gainval_c;

  // Update for Delay: '<S589>/UD'
  multipid_DW.UD_DSTATE_h = rtb_Tsamp_ac;

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  multipid_M->Timing.taskTime0 =
    ((time_T)(++multipid_M->Timing.clockTick0)) * multipid_M->Timing.stepSize0;
}

// Model step function for TID1
void multipid_step1(void)              // Sample time: [0.005s, 0.0s]
{
  real32_T rtb_Saturation_f;

  // Gain: '<S52>/Proportional Gain' incorporates:
  //   RateTransition generated from: '<S52>/Proportional Gain'

  rtb_Saturation_f = multipid_P.PIDController_P_e *
    multipid_DW.TmpRTBAtProportionalGainInport1;

  // Saturate: '<S54>/Saturation'
  if (rtb_Saturation_f > multipid_P.PIDController_UpperSaturationLi) {
    rtb_Saturation_f = multipid_P.PIDController_UpperSaturationLi;
  } else if (rtb_Saturation_f < multipid_P.PIDController_LowerSaturationLi) {
    rtb_Saturation_f = multipid_P.PIDController_LowerSaturationLi;
  }

  // End of Saturate: '<S54>/Saturation'

  // RateTransition: '<S3>/Rate Transition'
  multipid_DW.RateTransition_Buffer0 = rtb_Saturation_f;

  // Gain: '<S104>/Proportional Gain' incorporates:
  //   RateTransition generated from: '<S104>/Proportional Gain'

  rtb_Saturation_f = multipid_P.PIDController2_P_o *
    multipid_DW.TmpRTBAtProportionalGainInpor_b;

  // Saturate: '<S106>/Saturation'
  if (rtb_Saturation_f > multipid_P.PIDController2_UpperSaturatio_m) {
    rtb_Saturation_f = multipid_P.PIDController2_UpperSaturatio_m;
  } else if (rtb_Saturation_f < multipid_P.PIDController2_LowerSaturatio_m) {
    rtb_Saturation_f = multipid_P.PIDController2_LowerSaturatio_m;
  }

  // End of Saturate: '<S106>/Saturation'

  // RateTransition: '<S3>/Rate Transition1'
  multipid_DW.RateTransition1_Buffer0 = rtb_Saturation_f;

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.005, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  multipid_M->Timing.clockTick1++;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void multipid_step(int_T tid)
{
  switch (tid) {
   case 0 :
    multipid_step0();
    break;

   case 1 :
    multipid_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void multipid_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(multipid_M, -1);
  multipid_M->Timing.stepSize0 = 0.001;

  // External mode info
  multipid_M->Sizes.checksums[0] = (262225863U);
  multipid_M->Sizes.checksums[1] = (647992779U);
  multipid_M->Sizes.checksums[2] = (4014823054U);
  multipid_M->Sizes.checksums[3] = (1682627951U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    multipid_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&multipid_DW.EnabledSubsystem_SubsysRanBC_h;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)&multipid_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(multipid_M->extModeInfo,
      &multipid_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(multipid_M->extModeInfo, multipid_M->Sizes.checksums);
    rteiSetTPtr(multipid_M->extModeInfo, rtmGetTPtr(multipid_M));
  }

  // block I/O
  (void) memset((static_cast<void *>(&multipid_B)), 0,
                sizeof(B_multipid_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&multipid_DW), 0,
                sizeof(DW_multipid_T));

  {
    int32_T i;

    // Start for RateTransition: '<S3>/Rate Transition'
    multipid_B.RateTransition = multipid_P.RateTransition_InitialCondition;

    // Start for RateTransition: '<S3>/Rate Transition1'
    multipid_B.RateTransition1 = multipid_P.RateTransition1_InitialConditio;

    // InitializeConditions for RateTransition: '<S3>/Rate Transition'
    multipid_DW.RateTransition_Buffer0 =
      multipid_P.RateTransition_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S158>/Integrator'
    multipid_DW.Integrator_DSTATE = multipid_P.PIDController1_InitialCondition;

    // InitializeConditions for Delay: '<S151>/UD'
    multipid_DW.UD_DSTATE = multipid_P.PIDController1_DifferentiatorIC;

    // InitializeConditions for RateTransition: '<S3>/Rate Transition1'
    multipid_DW.RateTransition1_Buffer0 =
      multipid_P.RateTransition1_InitialConditio;

    // InitializeConditions for DiscreteIntegrator: '<S266>/Integrator'
    multipid_DW.Integrator_DSTATE_f = multipid_P.PIDController4_InitialCondition;

    // InitializeConditions for Delay: '<S259>/UD'
    multipid_DW.UD_DSTATE_l = multipid_P.PIDController4_DifferentiatorIC;

    // InitializeConditions for DiscreteIntegrator: '<S212>/Integrator'
    multipid_DW.Integrator_DSTATE_n = multipid_P.PIDController2_InitialCondition;

    // InitializeConditions for Delay: '<S205>/UD'
    multipid_DW.UD_DSTATE_a = multipid_P.PIDController2_DifferentiatorIC;

    // InitializeConditions for DiscreteIntegrator: '<S323>/Integrator'
    multipid_DW.Integrator_DSTATE_fy =
      multipid_P.PIDController1_InitialConditi_l;

    // InitializeConditions for Delay: '<S316>/UD'
    multipid_DW.UD_DSTATE_k = multipid_P.PIDController1_Differentiator_f;

    // InitializeConditions for DiscreteIntegrator: '<S377>/Integrator'
    multipid_DW.Integrator_DSTATE_j = multipid_P.PIDController2_InitialConditi_j;

    // InitializeConditions for Delay: '<S370>/UD'
    multipid_DW.UD_DSTATE_d = multipid_P.PIDController2_Differentiator_k;

    // InitializeConditions for DiscreteIntegrator: '<S431>/Integrator'
    multipid_DW.Integrator_DSTATE_jr =
      multipid_P.PIDController3_InitialCondition;

    // InitializeConditions for Delay: '<S424>/UD'
    multipid_DW.UD_DSTATE_b = multipid_P.PIDController3_DifferentiatorIC;

    // InitializeConditions for DiscreteIntegrator: '<S488>/Integrator'
    multipid_DW.Integrator_DSTATE_i = multipid_P.PIDController_InitialConditionF;

    // InitializeConditions for Delay: '<S481>/UD'
    multipid_DW.UD_DSTATE_du = multipid_P.PIDController_DifferentiatorICP;

    // InitializeConditions for DiscreteIntegrator: '<S542>/Integrator'
    multipid_DW.Integrator_DSTATE_o = multipid_P.PIDController1_InitialCondit_ls;

    // InitializeConditions for Delay: '<S535>/UD'
    multipid_DW.UD_DSTATE_do = multipid_P.PIDController1_Differentiator_l;

    // InitializeConditions for DiscreteIntegrator: '<S596>/Integrator'
    multipid_DW.Integrator_DSTATE_iu =
      multipid_P.PIDController2_InitialConditi_k;

    // InitializeConditions for Delay: '<S589>/UD'
    multipid_DW.UD_DSTATE_h = multipid_P.PIDController2_Differentiator_p;

    // SystemInitialize for Enabled SubSystem: '<S117>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S118>/In1' incorporates:
    //   Outport: '<S118>/Out1'

    multipid_B.In1_k = multipid_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S117>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S614>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S615>/In1' incorporates:
    //   Outport: '<S615>/Out1'

    multipid_B.In1 = multipid_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S614>/Enabled Subsystem'

    // Start for MATLABSystem: '<S117>/SourceBlock'
    multipid_DW.obj_l.matlabCodegenIsDeleted = false;
    multipid_DW.obj_l.isSetupComplete = false;
    multipid_DW.obj_l.isInitialized = 1;
    multipid_DW.obj_l.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(multipid_DW.obj_l.orbMetadataObj,
                         &multipid_DW.obj_l.eventStructObj);
    multipid_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S614>/SourceBlock'
    multipid_DW.obj_c.matlabCodegenIsDeleted = false;
    multipid_DW.obj_c.isSetupComplete = false;
    multipid_DW.obj_c.isInitialized = 1;
    multipid_DW.obj_c.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(multipid_DW.obj_c.orbMetadataObj,
                         &multipid_DW.obj_c.eventStructObj);
    multipid_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    for (i = 0; i < 12; i++) {
      multipid_DW.obj.ValidMotorIdx[i] = false;
    }

    for (i = 0; i < 8; i++) {
      multipid_DW.obj.ValidServoIdx[i] = false;
    }

    multipid_DW.obj.matlabCodegenIsDeleted = false;
    multipid_DW.obj.isSetupComplete = false;
    multipid_DW.obj.isInitialized = 1;
    multipid_PX4Actuators_setupImpl(&multipid_DW.obj);
    multipid_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/PX4 Actuator Write'
  }
}

// Model terminate function
void multipid_terminate(void)
{
  int32_T i;
  real32_T servoValues[8];

  // Terminate for MATLABSystem: '<S117>/SourceBlock'
  if (!multipid_DW.obj_l.matlabCodegenIsDeleted) {
    multipid_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((multipid_DW.obj_l.isInitialized == 1) &&
        multipid_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&multipid_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S117>/SourceBlock'

  // Terminate for MATLABSystem: '<S614>/SourceBlock'
  if (!multipid_DW.obj_c.matlabCodegenIsDeleted) {
    multipid_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((multipid_DW.obj_c.isInitialized == 1) &&
        multipid_DW.obj_c.isSetupComplete) {
      uORB_read_terminate(&multipid_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S614>/SourceBlock'
  // Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  if (!multipid_DW.obj.matlabCodegenIsDeleted) {
    multipid_DW.obj.matlabCodegenIsDeleted = true;
    if ((multipid_DW.obj.isInitialized == 1) && multipid_DW.obj.isSetupComplete)
    {
      for (i = 0; i < 12; i++) {
        multipid_B.motorValues_m[i] = (rtNaNF);
      }

      for (i = 0; i < 8; i++) {
        servoValues[i] = (rtNaNF);
      }

      for (i = 0; i < 12; i++) {
        if (multipid_DW.obj.ValidMotorIdx[i]) {
          multipid_B.motorValues_m[i] = 0.0F;
        }
      }

      for (i = 0; i < 8; i++) {
        if (multipid_DW.obj.ValidServoIdx[i]) {
          servoValues[i] = 0.0F;
        }
      }

      MW_actuators_set(false, &multipid_B.motorValues_m[0], &servoValues[0]);
      MW_actuators_terminate();
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
}

//
// File trailer for generated code.
//
// [EOF]
//
