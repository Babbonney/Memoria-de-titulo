//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: multipid_data.cpp
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

// Block parameters (default storage)
P_multipid_T multipid_P = {
  // Mask Parameter: PIDController1_D
  //  Referenced by: '<S149>/Derivative Gain'

  0.0002F,

  // Mask Parameter: PIDController4_D
  //  Referenced by: '<S257>/Derivative Gain'

  0.0002F,

  // Mask Parameter: PIDController2_D
  //  Referenced by: '<S203>/Derivative Gain'

  0.0002F,

  // Mask Parameter: PIDController1_D_j
  //  Referenced by: '<S314>/Derivative Gain'

  0.0001F,

  // Mask Parameter: PIDController2_D_m
  //  Referenced by: '<S368>/Derivative Gain'

  0.0001F,

  // Mask Parameter: PIDController3_D
  //  Referenced by: '<S422>/Derivative Gain'

  0.0001F,

  // Mask Parameter: PIDController_D
  //  Referenced by: '<S479>/Derivative Gain'

  0.0001F,

  // Mask Parameter: PIDController1_D_e
  //  Referenced by: '<S533>/Derivative Gain'

  0.0001F,

  // Mask Parameter: PIDController2_D_d
  //  Referenced by: '<S587>/Derivative Gain'

  0.0001F,

  // Mask Parameter: PIDController1_DifferentiatorIC
  //  Referenced by: '<S151>/UD'

  0.0F,

  // Mask Parameter: PIDController4_DifferentiatorIC
  //  Referenced by: '<S259>/UD'

  0.0F,

  // Mask Parameter: PIDController2_DifferentiatorIC
  //  Referenced by: '<S205>/UD'

  0.0F,

  // Mask Parameter: PIDController1_Differentiator_f
  //  Referenced by: '<S316>/UD'

  0.0F,

  // Mask Parameter: PIDController2_Differentiator_k
  //  Referenced by: '<S370>/UD'

  0.0F,

  // Mask Parameter: PIDController3_DifferentiatorIC
  //  Referenced by: '<S424>/UD'

  0.0F,

  // Mask Parameter: PIDController_DifferentiatorICP
  //  Referenced by: '<S481>/UD'

  0.0F,

  // Mask Parameter: PIDController1_Differentiator_l
  //  Referenced by: '<S535>/UD'

  0.0F,

  // Mask Parameter: PIDController2_Differentiator_p
  //  Referenced by: '<S589>/UD'

  0.0F,

  // Mask Parameter: PIDController3_I
  //  Referenced by: '<S428>/Integral Gain'

  0.0302F,

  // Mask Parameter: PIDController2_I
  //  Referenced by: '<S374>/Integral Gain'

  0.0302F,

  // Mask Parameter: PIDController1_I
  //  Referenced by: '<S320>/Integral Gain'

  0.0302F,

  // Mask Parameter: PIDController2_I_p
  //  Referenced by: '<S209>/Integral Gain'

  0.0643F,

  // Mask Parameter: PIDController2_I_h
  //  Referenced by: '<S593>/Integral Gain'

  0.0482F,

  // Mask Parameter: PIDController4_I
  //  Referenced by: '<S263>/Integral Gain'

  0.0643F,

  // Mask Parameter: PIDController1_I_d
  //  Referenced by: '<S539>/Integral Gain'

  0.0482F,

  // Mask Parameter: PIDController1_I_h
  //  Referenced by: '<S155>/Integral Gain'

  0.0643F,

  // Mask Parameter: PIDController_I
  //  Referenced by: '<S485>/Integral Gain'

  0.0482F,

  // Mask Parameter: PIDController1_InitialCondition
  //  Referenced by: '<S158>/Integrator'

  0.0F,

  // Mask Parameter: PIDController4_InitialCondition
  //  Referenced by: '<S266>/Integrator'

  0.0F,

  // Mask Parameter: PIDController2_InitialCondition
  //  Referenced by: '<S212>/Integrator'

  0.0F,

  // Mask Parameter: PIDController1_InitialConditi_l
  //  Referenced by: '<S323>/Integrator'

  0.0F,

  // Mask Parameter: PIDController2_InitialConditi_j
  //  Referenced by: '<S377>/Integrator'

  0.0F,

  // Mask Parameter: PIDController3_InitialCondition
  //  Referenced by: '<S431>/Integrator'

  0.0F,

  // Mask Parameter: PIDController_InitialConditionF
  //  Referenced by: '<S488>/Integrator'

  0.0F,

  // Mask Parameter: PIDController1_InitialCondit_ls
  //  Referenced by: '<S542>/Integrator'

  0.0F,

  // Mask Parameter: PIDController2_InitialConditi_k
  //  Referenced by: '<S596>/Integrator'

  0.0F,

  // Mask Parameter: PIDController3_Kb
  //  Referenced by: '<S421>/Kb'

  1.0F,

  // Mask Parameter: PIDController2_Kb
  //  Referenced by: '<S367>/Kb'

  1.0F,

  // Mask Parameter: PIDController1_Kb
  //  Referenced by: '<S313>/Kb'

  1.0F,

  // Mask Parameter: PIDController2_Kb_j
  //  Referenced by: '<S202>/Kb'

  1.0F,

  // Mask Parameter: PIDController4_Kb
  //  Referenced by: '<S256>/Kb'

  1.0F,

  // Mask Parameter: PIDController1_Kb_f
  //  Referenced by: '<S148>/Kb'

  1.0F,

  // Mask Parameter: PIDController1_LowerSaturationL
  //  Referenced by: '<S165>/Saturation'

  -1.0F,

  // Mask Parameter: PIDController4_LowerSaturationL
  //  Referenced by: '<S273>/Saturation'

  -1.0F,

  // Mask Parameter: PIDController2_LowerSaturationL
  //  Referenced by: '<S219>/Saturation'

  -1.0F,

  // Mask Parameter: PIDController1_LowerSaturatio_i
  //  Referenced by: '<S330>/Saturation'

  -1.0F,

  // Mask Parameter: PIDController2_LowerSaturatio_j
  //  Referenced by: '<S384>/Saturation'

  -1.0F,

  // Mask Parameter: PIDController3_LowerSaturationL
  //  Referenced by: '<S438>/Saturation'

  -1.0F,

  // Mask Parameter: PIDController_LowerSaturationLi
  //  Referenced by: '<S54>/Saturation'

  -3.8F,

  // Mask Parameter: PIDController2_LowerSaturatio_m
  //  Referenced by: '<S106>/Saturation'

  -3.8F,

  // Mask Parameter: PIDController1_P
  //  Referenced by: '<S163>/Proportional Gain'

  0.3271F,

  // Mask Parameter: PIDController4_P
  //  Referenced by: '<S271>/Proportional Gain'

  0.3271F,

  // Mask Parameter: PIDController2_P
  //  Referenced by: '<S217>/Proportional Gain'

  0.3271F,

  // Mask Parameter: PIDController1_P_d
  //  Referenced by: '<S328>/Proportional Gain'

  0.1538F,

  // Mask Parameter: PIDController2_P_p
  //  Referenced by: '<S382>/Proportional Gain'

  0.1538F,

  // Mask Parameter: PIDController3_P
  //  Referenced by: '<S436>/Proportional Gain'

  0.1538F,

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S493>/Proportional Gain'

  0.2454F,

  // Mask Parameter: PIDController1_P_o
  //  Referenced by: '<S547>/Proportional Gain'

  0.2454F,

  // Mask Parameter: PIDController2_P_h
  //  Referenced by: '<S601>/Proportional Gain'

  0.2454F,

  // Mask Parameter: PIDController_P_e
  //  Referenced by: '<S52>/Proportional Gain'

  2.25F,

  // Mask Parameter: PIDController2_P_o
  //  Referenced by: '<S104>/Proportional Gain'

  2.25F,

  // Mask Parameter: PIDController1_UpperSaturationL
  //  Referenced by: '<S165>/Saturation'

  1.0F,

  // Mask Parameter: PIDController4_UpperSaturationL
  //  Referenced by: '<S273>/Saturation'

  1.0F,

  // Mask Parameter: PIDController2_UpperSaturationL
  //  Referenced by: '<S219>/Saturation'

  1.0F,

  // Mask Parameter: PIDController1_UpperSaturatio_n
  //  Referenced by: '<S330>/Saturation'

  1.0F,

  // Mask Parameter: PIDController2_UpperSaturatio_n
  //  Referenced by: '<S384>/Saturation'

  1.0F,

  // Mask Parameter: PIDController3_UpperSaturationL
  //  Referenced by: '<S438>/Saturation'

  1.0F,

  // Mask Parameter: PIDController_UpperSaturationLi
  //  Referenced by: '<S54>/Saturation'

  3.8F,

  // Mask Parameter: PIDController2_UpperSaturatio_m
  //  Referenced by: '<S106>/Saturation'

  3.8F,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S615>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // angular_velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // orientation_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity_variance
    0U,                                // pose_frame
    0U,                                // velocity_frame
    0U,                                // reset_counter
    0,                                 // quality

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S614>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // angular_velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // orientation_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity_variance
    0U,                                // pose_frame
    0U,                                // velocity_frame
    0U,                                // reset_counter
    0,                                 // quality

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S118>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S117>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Switch_Threshold
  //  Referenced by: '<Root>/Switch'

  1500.0F,

  // Computed Parameter: RateTransition_InitialCondition
  //  Referenced by: '<S3>/Rate Transition'

  0.0F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S158>/Integrator'

  0.001F,

  // Computed Parameter: Tsamp_WtEt
  //  Referenced by: '<S153>/Tsamp'

  1000.0F,

  // Computed Parameter: RateTransition1_InitialConditio
  //  Referenced by: '<S3>/Rate Transition1'

  0.0F,

  // Computed Parameter: Integrator_gainval_n
  //  Referenced by: '<S266>/Integrator'

  0.001F,

  // Computed Parameter: Tsamp_WtEt_f
  //  Referenced by: '<S261>/Tsamp'

  1000.0F,

  // Computed Parameter: DeadZone3_Start
  //  Referenced by: '<S6>/Dead Zone3'

  -10.0F,

  // Computed Parameter: DeadZone3_End
  //  Referenced by: '<S6>/Dead Zone3'

  10.0F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: '<S6>/Saturation3'

  1.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: '<S6>/Saturation3'

  -1.0F,

  // Computed Parameter: Integrator_gainval_g
  //  Referenced by: '<S212>/Integrator'

  0.001F,

  // Computed Parameter: Tsamp_WtEt_fp
  //  Referenced by: '<S207>/Tsamp'

  1000.0F,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S323>/Integrator'

  0.001F,

  // Computed Parameter: Tsamp_WtEt_fi
  //  Referenced by: '<S318>/Tsamp'

  1000.0F,

  // Computed Parameter: Integrator_gainval_p
  //  Referenced by: '<S377>/Integrator'

  0.001F,

  // Computed Parameter: Tsamp_WtEt_l
  //  Referenced by: '<S372>/Tsamp'

  1000.0F,

  // Computed Parameter: Integrator_gainval_na
  //  Referenced by: '<S431>/Integrator'

  0.001F,

  // Computed Parameter: Tsamp_WtEt_n
  //  Referenced by: '<S426>/Tsamp'

  1000.0F,

  // Computed Parameter: Integrator_gainval_a
  //  Referenced by: '<S488>/Integrator'

  0.001F,

  // Computed Parameter: Tsamp_WtEt_c
  //  Referenced by: '<S483>/Tsamp'

  1000.0F,

  // Computed Parameter: Integrator_gainval_nl
  //  Referenced by: '<S542>/Integrator'

  0.001F,

  // Computed Parameter: Tsamp_WtEt_g
  //  Referenced by: '<S537>/Tsamp'

  1000.0F,

  // Computed Parameter: Integrator_gainval_c
  //  Referenced by: '<S596>/Integrator'

  0.001F,

  // Computed Parameter: Tsamp_WtEt_p
  //  Referenced by: '<S591>/Tsamp'

  1000.0F,

  // Computed Parameter: DeadZone2_Start
  //  Referenced by: '<S6>/Dead Zone2'

  -5.0F,

  // Computed Parameter: DeadZone2_End
  //  Referenced by: '<S6>/Dead Zone2'

  5.0F,

  // Computed Parameter: Saturation2_UpperSat
  //  Referenced by: '<S6>/Saturation2'

  1.0F,

  // Computed Parameter: Saturation2_LowerSat
  //  Referenced by: '<S6>/Saturation2'

  0.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<Root>/Gain2'

  0.2F,

  // Computed Parameter: Saturation4_UpperSat
  //  Referenced by: '<Root>/Saturation4'

  1.0F,

  // Computed Parameter: Saturation4_LowerSat
  //  Referenced by: '<Root>/Saturation4'

  0.0F,

  // Computed Parameter: DeadZone_Start
  //  Referenced by: '<S6>/Dead Zone'

  -10.0F,

  // Computed Parameter: DeadZone_End
  //  Referenced by: '<S6>/Dead Zone'

  10.0F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S6>/Saturation'

  1.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S6>/Saturation'

  -1.0F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<Root>/Gain'

  0.16F,

  // Computed Parameter: DeadZone1_Start
  //  Referenced by: '<S3>/Dead Zone1'

  -0.02F,

  // Computed Parameter: DeadZone1_End
  //  Referenced by: '<S3>/Dead Zone1'

  0.02F,

  // Computed Parameter: DeadZone1_Start_a
  //  Referenced by: '<S6>/Dead Zone1'

  -10.0F,

  // Computed Parameter: DeadZone1_End_o
  //  Referenced by: '<S6>/Dead Zone1'

  10.0F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S6>/Saturation1'

  1.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S6>/Saturation1'

  -1.0F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<Root>/Gain1'

  0.16F,

  // Computed Parameter: DeadZone_Start_i
  //  Referenced by: '<S3>/Dead Zone'

  -0.02F,

  // Computed Parameter: DeadZone_End_m
  //  Referenced by: '<S3>/Dead Zone'

  0.02F,

  // Computed Parameter: Constant1_Value
  //  Referenced by: '<Root>/Constant1'

  true,

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<Root>/Constant'

  false
};

//
// File trailer for generated code.
//
// [EOF]
//
