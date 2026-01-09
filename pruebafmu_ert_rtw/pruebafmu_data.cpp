//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pruebafmu_data.cpp
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
#include "pruebafmu.h"

// Block parameters (default storage)
P_pruebafmu_T pruebafmu_P = {
  // Mask Parameter: UDPReceive_localPort
  //  Referenced by: '<Root>/UDP Receive'

  25008,

  // Mask Parameter: UDPSend_remotePort
  //  Referenced by: '<Root>/UDP Send'

  25000,

  // Mask Parameter: UDPSend1_remotePort
  //  Referenced by: '<Root>/UDP Send1'

  25001,

  // Mask Parameter: UDPSend3_remotePort
  //  Referenced by: '<Root>/UDP Send3'

  25003,

  // Mask Parameter: UDPSend4_remotePort
  //  Referenced by: '<Root>/UDP Send4'

  25004,

  // Mask Parameter: UDPSend7_remotePort
  //  Referenced by: '<Root>/UDP Send7'

  25007,

  // Mask Parameter: UDPSend5_remotePort
  //  Referenced by: '<Root>/UDP Send5'

  25005,

  // Mask Parameter: UDPSend6_remotePort
  //  Referenced by: '<Root>/UDP Send6'

  25006,

  // Mask Parameter: UDPSend2_remotePort
  //  Referenced by: '<Root>/UDP Send2'

  25002,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S7>/Out1'

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
  //  Referenced by: '<S6>/Constant'

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
  //  Referenced by: '<S5>/Out1'

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
  //  Referenced by: '<S4>/Constant'

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
  //  Referenced by: '<Root>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant2'

  0.0,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<Root>/Gain'

  0.16F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<Root>/Gain1'

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
