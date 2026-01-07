//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controladorpruebaio_data.cpp
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

// Block parameters (default storage)
P_controladorpruebaio_T controladorpruebaio_P = {
  // Mask Parameter: PIDController1_D
  //  Referenced by: '<S91>/Derivative Gain'

  0.0001F,

  // Mask Parameter: PIDController3_D
  //  Referenced by: '<S197>/Derivative Gain'

  0.0001F,

  // Mask Parameter: PIDController1_DifferentiatorIC
  //  Referenced by: '<S93>/UD'

  0.0F,

  // Mask Parameter: PIDController3_DifferentiatorIC
  //  Referenced by: '<S199>/UD'

  0.0F,

  // Mask Parameter: PIDController3_I
  //  Referenced by: '<S203>/Integral Gain'

  0.0453F,

  // Mask Parameter: PIDController1_I
  //  Referenced by: '<S97>/Integral Gain'

  0.0453F,

  // Mask Parameter: PIDController1_InitialCondition
  //  Referenced by: '<S100>/Integrator'

  0.0F,

  // Mask Parameter: PIDController3_InitialCondition
  //  Referenced by: '<S206>/Integrator'

  0.0F,

  // Mask Parameter: PIDController3_Kb
  //  Referenced by: '<S196>/Kb'

  1.0F,

  // Mask Parameter: PIDController1_Kb
  //  Referenced by: '<S90>/Kb'

  1.0F,

  // Mask Parameter: PIDController1_LowerSaturationL
  //  Referenced by: '<S107>/Saturation'

  -1.0F,

  // Mask Parameter: PIDController3_LowerSaturationL
  //  Referenced by: '<S213>/Saturation'

  -1.0F,

  // Mask Parameter: PIDController_LowerSaturationLi
  //  Referenced by: '<S53>/Saturation'

  -3.8F,

  // Mask Parameter: PIDController2_LowerSaturationL
  //  Referenced by: '<S159>/Saturation'

  -3.8F,

  // Mask Parameter: PIDController1_P
  //  Referenced by: '<S105>/Proportional Gain'

  0.2306F,

  // Mask Parameter: PIDController3_P
  //  Referenced by: '<S211>/Proportional Gain'

  0.2306F,

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S51>/Proportional Gain'

  1.0F,

  // Mask Parameter: PIDController2_P
  //  Referenced by: '<S157>/Proportional Gain'

  1.0F,

  // Mask Parameter: PIDController1_UpperSaturationL
  //  Referenced by: '<S107>/Saturation'

  1.0F,

  // Mask Parameter: PIDController3_UpperSaturationL
  //  Referenced by: '<S213>/Saturation'

  1.0F,

  // Mask Parameter: PIDController_UpperSaturationLi
  //  Referenced by: '<S53>/Saturation'

  3.8F,

  // Mask Parameter: PIDController2_UpperSaturationL
  //  Referenced by: '<S159>/Saturation'

  3.8F,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S225>/Out1'

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
  //  Referenced by: '<S224>/Constant'

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

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S7>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S6>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Expression: 0
  //  Referenced by: '<Root>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant3'

  0.0,

  // Computed Parameter: RateTransition_InitialCondition
  //  Referenced by: '<S3>/Rate Transition'

  0.0F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S100>/Integrator'

  0.001F,

  // Computed Parameter: Tsamp_WtEt
  //  Referenced by: '<S95>/Tsamp'

  1000.0F,

  // Computed Parameter: RateTransition1_InitialConditio
  //  Referenced by: '<S3>/Rate Transition1'

  0.0F,

  // Computed Parameter: Integrator_gainval_k
  //  Referenced by: '<S206>/Integrator'

  0.001F,

  // Computed Parameter: Tsamp_WtEt_k
  //  Referenced by: '<S201>/Tsamp'

  1000.0F,

  // Computed Parameter: Saturation4_UpperSat
  //  Referenced by: '<Root>/Saturation4'

  1.0F,

  // Computed Parameter: Saturation4_LowerSat
  //  Referenced by: '<Root>/Saturation4'

  0.0F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<Root>/Gain1'

  0.16F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<Root>/Gain'

  0.16F,

  // Computed Parameter: Constant1_Value
  //  Referenced by: '<Root>/Constant1'

  true,

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<Root>/Constant'

  false,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
