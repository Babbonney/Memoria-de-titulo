//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpc4_private.h
//
// Code generated for Simulink model 'mpc4'.
//
// Model version                  : 12.57
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Thu Jan 29 13:15:41 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef mpc4_private_h_
#define mpc4_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "mpc4_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);

#endif                                 // mpc4_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
