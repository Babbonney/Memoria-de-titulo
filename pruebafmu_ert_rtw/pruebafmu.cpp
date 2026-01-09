//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pruebafmu.cpp
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
#include "pruebafmu_types.h"
#include "pruebafmu_private.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

// Block signals (default storage)
B_pruebafmu_T pruebafmu_B;

// Block states (default storage)
DW_pruebafmu_T pruebafmu_DW;

// Real-time model
RT_MODEL_pruebafmu_T pruebafmu_M_ = RT_MODEL_pruebafmu_T();
RT_MODEL_pruebafmu_T *const pruebafmu_M = &pruebafmu_M_;

// Forward declaration for local functions
static void pruebafm_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);
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

static void pruebafm_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj)
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

// Model step function
void pruebafmu_step(void)
{
  int32_T i;
  int32_T samplesRead;
  real32_T servoValues[8];
  char_T *sErr;
  boolean_T b_varargout_1;
  boolean_T rtb_ManualSwitch;

  // Reset subsysRan breadcrumbs
  srClearBC(pruebafmu_DW.EnabledSubsystem_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(pruebafmu_DW.EnabledSubsystem_SubsysRanBC);

  // S-Function (any2byte): '<Root>/Byte Pack' incorporates:
  //   Constant: '<Root>/Constant4'


  // Pack: <Root>/Byte Pack
  (void) memcpy(&pruebafmu_B.BytePack[0], &pruebafmu_P.Constant4_Value,
                8);

  // DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
  //   Constant: '<Root>/Constant3'
  //   DataTypeConversion: '<Root>/Data Type Conversion3'
  //   Gain: '<Root>/Gain'

  pruebafmu_B.DataTypeConversion4 = pruebafmu_P.Gain_Gain * static_cast<real32_T>
    (pruebafmu_P.Constant3_Value);

  // S-Function (any2byte): '<Root>/Byte Pack1'

  // Pack: <Root>/Byte Pack1
  (void) memcpy(&pruebafmu_B.BytePack1[0], &pruebafmu_B.DataTypeConversion4,
                8);

  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = uORB_read_step(pruebafmu_DW.obj_c.orbMetadataObj,
    &pruebafmu_DW.obj_c.eventStructObj, &pruebafmu_B.r, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  // Start for MATLABSystem: '<S6>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S7>/In1'
    pruebafmu_B.In1 = pruebafmu_B.r;
    srUpdateBC(pruebafmu_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // DataTypeConversion: '<Root>/Data Type Conversion9' incorporates:
  //   MATLAB Function: '<Root>/quat2eul'

  pruebafmu_B.DataTypeConversion9 = rt_atan2f_snf((pruebafmu_B.In1.q[0] *
    pruebafmu_B.In1.q[1] + pruebafmu_B.In1.q[2] * pruebafmu_B.In1.q[3]) * 2.0F,
    ((pruebafmu_B.In1.q[0] * pruebafmu_B.In1.q[0] - pruebafmu_B.In1.q[1] *
      pruebafmu_B.In1.q[1]) - pruebafmu_B.In1.q[2] * pruebafmu_B.In1.q[2]) +
    pruebafmu_B.In1.q[3] * pruebafmu_B.In1.q[3]);

  // S-Function (any2byte): '<Root>/Byte Pack2'

  // Pack: <Root>/Byte Pack2
  (void) memcpy(&pruebafmu_B.BytePack2[0], &pruebafmu_B.DataTypeConversion9,
                8);

  // DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
  //   MATLAB Function: '<Root>/quat2eul'

  pruebafmu_B.DataTypeConversion8 = static_cast<real32_T>(asin
    (static_cast<real_T>((pruebafmu_B.In1.q[1] * pruebafmu_B.In1.q[3] -
    pruebafmu_B.In1.q[0] * pruebafmu_B.In1.q[2]) * -2.0F)));

  // S-Function (any2byte): '<Root>/Byte Pack6'

  // Pack: <Root>/Byte Pack6
  (void) memcpy(&pruebafmu_B.BytePack6[0], &pruebafmu_B.DataTypeConversion8,
                8);

  // S-Function (sdspFromNetwork): '<Root>/UDP Receive'
  sErr = GetErrorBuffer(&pruebafmu_DW.UDPReceive_NetworkLib[0U]);
  samplesRead = 32;
  LibOutputs_Network(&pruebafmu_DW.UDPReceive_NetworkLib[0U],
                     &pruebafmu_B.UDPReceive_o1[0U], &samplesRead);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  // End of S-Function (sdspFromNetwork): '<Root>/UDP Receive'

  // S-Function (byte2any): '<Root>/Byte Unpack'

  // Unpack: <Root>/Byte Unpack
  (void) memcpy(&pruebafmu_B.ByteUnpack[0], &pruebafmu_B.UDPReceive_o1[0],
                32);

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant1'

  if (pruebafmu_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch = pruebafmu_P.Constant1_Value;
  } else {
    rtb_ManualSwitch = pruebafmu_P.Constant_Value_b;
  }

  // End of ManualSwitch: '<Root>/Manual Switch'

  // DataTypeConversion: '<Root>/Data Type Conversion1'
  pruebafmu_B.DataTypeConversion1 = rtb_ManualSwitch;

  // S-Function (any2byte): '<Root>/Byte Pack3'

  // Pack: <Root>/Byte Pack3
  (void) memcpy(&pruebafmu_B.BytePack3[0], &pruebafmu_B.DataTypeConversion1,
                8);

  // MATLABSystem: '<S4>/SourceBlock'
  b_varargout_1 = uORB_read_step(pruebafmu_DW.obj_d.orbMetadataObj,
    &pruebafmu_DW.obj_d.eventStructObj, &pruebafmu_B.r1, false, 1.0);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S5>/Enable'

  // Start for MATLABSystem: '<S4>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S5>/In1'
    pruebafmu_B.In1_e = pruebafmu_B.r1;
    srUpdateBC(pruebafmu_DW.EnabledSubsystem_SubsysRanBC_f);
  }

  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'

  // DataTypeConversion: '<Root>/Data Type Conversion6'
  pruebafmu_B.DataTypeConversion6 = pruebafmu_B.In1_e.x;

  // S-Function (any2byte): '<Root>/Byte Pack4'

  // Pack: <Root>/Byte Pack4
  (void) memcpy(&pruebafmu_B.BytePack4[0], &pruebafmu_B.DataTypeConversion6,
                8);

  // DataTypeConversion: '<Root>/Data Type Conversion7'
  pruebafmu_B.DataTypeConversion7 = pruebafmu_B.In1_e.y;

  // S-Function (any2byte): '<Root>/Byte Pack7'

  // Pack: <Root>/Byte Pack7
  (void) memcpy(&pruebafmu_B.BytePack7[0], &pruebafmu_B.DataTypeConversion7,
                8);

  // DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   DataTypeConversion: '<Root>/Data Type Conversion2'
  //   Gain: '<Root>/Gain1'

  pruebafmu_B.DataTypeConversion5 = pruebafmu_P.Gain1_Gain *
    static_cast<real32_T>(pruebafmu_P.Constant2_Value);

  // S-Function (any2byte): '<Root>/Byte Pack5'

  // Pack: <Root>/Byte Pack5
  (void) memcpy(&pruebafmu_B.BytePack5[0], &pruebafmu_B.DataTypeConversion5,
                8);

  // DataTypeConversion: '<Root>/Data Type Conversion'
  pruebafmu_B.DataTypeConversion[0] = static_cast<real32_T>
    (pruebafmu_B.ByteUnpack[0]);
  pruebafmu_B.DataTypeConversion[1] = static_cast<real32_T>
    (pruebafmu_B.ByteUnpack[1]);
  pruebafmu_B.DataTypeConversion[2] = static_cast<real32_T>
    (pruebafmu_B.ByteUnpack[2]);
  pruebafmu_B.DataTypeConversion[3] = static_cast<real32_T>
    (pruebafmu_B.ByteUnpack[3]);

  // MATLABSystem: '<Root>/PX4 Actuator Write'
  for (i = 0; i < 12; i++) {
    pruebafmu_B.motorValues[i] = (rtNaNF);
  }

  for (i = 0; i < 8; i++) {
    servoValues[i] = (rtNaNF);
  }

  pruebafmu_B.motorValues[0] = pruebafmu_B.DataTypeConversion[0];
  pruebafmu_B.motorValues[1] = pruebafmu_B.DataTypeConversion[1];
  pruebafmu_B.motorValues[2] = pruebafmu_B.DataTypeConversion[2];
  pruebafmu_B.motorValues[3] = pruebafmu_B.DataTypeConversion[3];
  MW_actuators_set(rtb_ManualSwitch, &pruebafmu_B.motorValues[0], &servoValues[0]);

  // End of MATLABSystem: '<Root>/PX4 Actuator Write'
  // Update for S-Function (sdspToNetwork): '<Root>/UDP Send' incorporates:
  //   S-Function (any2byte): '<Root>/Byte Pack'

  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&pruebafmu_DW.UDPSend_NetworkLib[0U], &pruebafmu_B.BytePack
                    [0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  // End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send'

  // Update for S-Function (sdspToNetwork): '<Root>/UDP Send1' incorporates:
  //   S-Function (any2byte): '<Root>/Byte Pack1'

  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend1_NetworkLib[0U]);
  LibUpdate_Network(&pruebafmu_DW.UDPSend1_NetworkLib[0U],
                    &pruebafmu_B.BytePack1[0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  // End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send1'

  // Update for S-Function (sdspToNetwork): '<Root>/UDP Send3' incorporates:
  //   S-Function (any2byte): '<Root>/Byte Pack2'

  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend3_NetworkLib[0U]);
  LibUpdate_Network(&pruebafmu_DW.UDPSend3_NetworkLib[0U],
                    &pruebafmu_B.BytePack2[0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  // End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send3'

  // Update for S-Function (sdspToNetwork): '<Root>/UDP Send4' incorporates:
  //   S-Function (any2byte): '<Root>/Byte Pack6'

  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend4_NetworkLib[0U]);
  LibUpdate_Network(&pruebafmu_DW.UDPSend4_NetworkLib[0U],
                    &pruebafmu_B.BytePack6[0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  // End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send4'

  // Update for S-Function (sdspToNetwork): '<Root>/UDP Send7' incorporates:
  //   S-Function (any2byte): '<Root>/Byte Pack3'

  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend7_NetworkLib[0U]);
  LibUpdate_Network(&pruebafmu_DW.UDPSend7_NetworkLib[0U],
                    &pruebafmu_B.BytePack3[0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  // End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send7'

  // Update for S-Function (sdspToNetwork): '<Root>/UDP Send5' incorporates:
  //   S-Function (any2byte): '<Root>/Byte Pack4'

  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend5_NetworkLib[0U]);
  LibUpdate_Network(&pruebafmu_DW.UDPSend5_NetworkLib[0U],
                    &pruebafmu_B.BytePack4[0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  // End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send5'

  // Update for S-Function (sdspToNetwork): '<Root>/UDP Send6' incorporates:
  //   S-Function (any2byte): '<Root>/Byte Pack7'

  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend6_NetworkLib[0U]);
  LibUpdate_Network(&pruebafmu_DW.UDPSend6_NetworkLib[0U],
                    &pruebafmu_B.BytePack7[0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  // End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send6'

  // Update for S-Function (sdspToNetwork): '<Root>/UDP Send2' incorporates:
  //   S-Function (any2byte): '<Root>/Byte Pack5'

  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend2_NetworkLib[0U]);
  LibUpdate_Network(&pruebafmu_DW.UDPSend2_NetworkLib[0U],
                    &pruebafmu_B.BytePack5[0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  // End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send2'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  pruebafmu_M->Timing.taskTime0 =
    ((time_T)(++pruebafmu_M->Timing.clockTick0)) * pruebafmu_M->Timing.stepSize0;
}

// Model initialize function
void pruebafmu_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(pruebafmu_M, -1);
  pruebafmu_M->Timing.stepSize0 = 0.001;

  // External mode info
  pruebafmu_M->Sizes.checksums[0] = (1914125787U);
  pruebafmu_M->Sizes.checksums[1] = (2508544175U);
  pruebafmu_M->Sizes.checksums[2] = (2580103916U);
  pruebafmu_M->Sizes.checksums[3] = (3688143659U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    pruebafmu_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&pruebafmu_DW.EnabledSubsystem_SubsysRanBC_f;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)&pruebafmu_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pruebafmu_M->extModeInfo,
      &pruebafmu_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pruebafmu_M->extModeInfo, pruebafmu_M->Sizes.checksums);
    rteiSetTPtr(pruebafmu_M->extModeInfo, rtmGetTPtr(pruebafmu_M));
  }

  // block I/O
  (void) memset((static_cast<void *>(&pruebafmu_B)), 0,
                sizeof(B_pruebafmu_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&pruebafmu_DW), 0,
                sizeof(DW_pruebafmu_T));

  {
    int32_T i;
    char_T *sErr;

    // Start for S-Function (sdspToNetwork): '<Root>/UDP Send'
    sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&pruebafmu_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&pruebafmu_DW.UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", pruebafmu_P.UDPSend_remotePort, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&pruebafmu_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&pruebafmu_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(pruebafmu_M, sErr);
        rtmSetStopRequested(pruebafmu_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send'

    // Start for S-Function (sdspToNetwork): '<Root>/UDP Send1'
    sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend1_NetworkLib[0U]);
    CreateUDPInterface(&pruebafmu_DW.UDPSend1_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&pruebafmu_DW.UDPSend1_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", pruebafmu_P.UDPSend1_remotePort, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&pruebafmu_DW.UDPSend1_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&pruebafmu_DW.UDPSend1_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(pruebafmu_M, sErr);
        rtmSetStopRequested(pruebafmu_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send1'

    // Start for S-Function (sdspToNetwork): '<Root>/UDP Send3'
    sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend3_NetworkLib[0U]);
    CreateUDPInterface(&pruebafmu_DW.UDPSend3_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&pruebafmu_DW.UDPSend3_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", pruebafmu_P.UDPSend3_remotePort, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&pruebafmu_DW.UDPSend3_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&pruebafmu_DW.UDPSend3_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(pruebafmu_M, sErr);
        rtmSetStopRequested(pruebafmu_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send3'

    // Start for S-Function (sdspToNetwork): '<Root>/UDP Send4'
    sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend4_NetworkLib[0U]);
    CreateUDPInterface(&pruebafmu_DW.UDPSend4_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&pruebafmu_DW.UDPSend4_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", pruebafmu_P.UDPSend4_remotePort, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&pruebafmu_DW.UDPSend4_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&pruebafmu_DW.UDPSend4_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(pruebafmu_M, sErr);
        rtmSetStopRequested(pruebafmu_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send4'

    // Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive'
    sErr = GetErrorBuffer(&pruebafmu_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&pruebafmu_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&pruebafmu_DW.UDPReceive_NetworkLib[0U], 0, "0.0.0.0",
                        pruebafmu_P.UDPReceive_localPort, "0.0.0.0", -1, 8192, 1,
                        0);
    }

    if (*sErr == 0) {
      LibStart(&pruebafmu_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&pruebafmu_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(pruebafmu_M, sErr);
        rtmSetStopRequested(pruebafmu_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive'

    // Start for S-Function (sdspToNetwork): '<Root>/UDP Send7'
    sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend7_NetworkLib[0U]);
    CreateUDPInterface(&pruebafmu_DW.UDPSend7_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&pruebafmu_DW.UDPSend7_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", pruebafmu_P.UDPSend7_remotePort, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&pruebafmu_DW.UDPSend7_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&pruebafmu_DW.UDPSend7_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(pruebafmu_M, sErr);
        rtmSetStopRequested(pruebafmu_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send7'

    // Start for S-Function (sdspToNetwork): '<Root>/UDP Send5'
    sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend5_NetworkLib[0U]);
    CreateUDPInterface(&pruebafmu_DW.UDPSend5_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&pruebafmu_DW.UDPSend5_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", pruebafmu_P.UDPSend5_remotePort, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&pruebafmu_DW.UDPSend5_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&pruebafmu_DW.UDPSend5_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(pruebafmu_M, sErr);
        rtmSetStopRequested(pruebafmu_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send5'

    // Start for S-Function (sdspToNetwork): '<Root>/UDP Send6'
    sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend6_NetworkLib[0U]);
    CreateUDPInterface(&pruebafmu_DW.UDPSend6_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&pruebafmu_DW.UDPSend6_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", pruebafmu_P.UDPSend6_remotePort, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&pruebafmu_DW.UDPSend6_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&pruebafmu_DW.UDPSend6_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(pruebafmu_M, sErr);
        rtmSetStopRequested(pruebafmu_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send6'

    // Start for S-Function (sdspToNetwork): '<Root>/UDP Send2'
    sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend2_NetworkLib[0U]);
    CreateUDPInterface(&pruebafmu_DW.UDPSend2_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&pruebafmu_DW.UDPSend2_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", pruebafmu_P.UDPSend2_remotePort, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&pruebafmu_DW.UDPSend2_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&pruebafmu_DW.UDPSend2_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(pruebafmu_M, sErr);
        rtmSetStopRequested(pruebafmu_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send2'

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S7>/In1' incorporates:
    //   Outport: '<S7>/Out1'

    pruebafmu_B.In1 = pruebafmu_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S5>/In1' incorporates:
    //   Outport: '<S5>/Out1'

    pruebafmu_B.In1_e = pruebafmu_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    pruebafmu_DW.obj_c.matlabCodegenIsDeleted = false;
    pruebafmu_DW.obj_c.isSetupComplete = false;
    pruebafmu_DW.obj_c.isInitialized = 1;
    pruebafmu_DW.obj_c.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(pruebafmu_DW.obj_c.orbMetadataObj,
                         &pruebafmu_DW.obj_c.eventStructObj);
    pruebafmu_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S4>/SourceBlock'
    pruebafmu_DW.obj_d.matlabCodegenIsDeleted = false;
    pruebafmu_DW.obj_d.isSetupComplete = false;
    pruebafmu_DW.obj_d.isInitialized = 1;
    pruebafmu_DW.obj_d.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(pruebafmu_DW.obj_d.orbMetadataObj,
                         &pruebafmu_DW.obj_d.eventStructObj);
    pruebafmu_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    for (i = 0; i < 12; i++) {
      pruebafmu_DW.obj.ValidMotorIdx[i] = false;
    }

    for (i = 0; i < 8; i++) {
      pruebafmu_DW.obj.ValidServoIdx[i] = false;
    }

    pruebafmu_DW.obj.matlabCodegenIsDeleted = false;
    pruebafmu_DW.obj.isSetupComplete = false;
    pruebafmu_DW.obj.isInitialized = 1;
    pruebafm_PX4Actuators_setupImpl(&pruebafmu_DW.obj);
    pruebafmu_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/PX4 Actuator Write'
  }
}

// Model terminate function
void pruebafmu_terminate(void)
{
  int32_T i;
  real32_T servoValues[8];
  char_T *sErr;

  // Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send'
  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&pruebafmu_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  LibDestroy(&pruebafmu_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&pruebafmu_DW.UDPSend_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send'

  // Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send1'
  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend1_NetworkLib[0U]);
  LibTerminate(&pruebafmu_DW.UDPSend1_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  LibDestroy(&pruebafmu_DW.UDPSend1_NetworkLib[0U], 1);
  DestroyUDPInterface(&pruebafmu_DW.UDPSend1_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send1'

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!pruebafmu_DW.obj_c.matlabCodegenIsDeleted) {
    pruebafmu_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((pruebafmu_DW.obj_c.isInitialized == 1) &&
        pruebafmu_DW.obj_c.isSetupComplete) {
      uORB_read_terminate(&pruebafmu_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send3'
  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend3_NetworkLib[0U]);
  LibTerminate(&pruebafmu_DW.UDPSend3_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  LibDestroy(&pruebafmu_DW.UDPSend3_NetworkLib[0U], 1);
  DestroyUDPInterface(&pruebafmu_DW.UDPSend3_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send3'

  // Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send4'
  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend4_NetworkLib[0U]);
  LibTerminate(&pruebafmu_DW.UDPSend4_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  LibDestroy(&pruebafmu_DW.UDPSend4_NetworkLib[0U], 1);
  DestroyUDPInterface(&pruebafmu_DW.UDPSend4_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send4'

  // Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive'
  sErr = GetErrorBuffer(&pruebafmu_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&pruebafmu_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  LibDestroy(&pruebafmu_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&pruebafmu_DW.UDPReceive_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive'

  // Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send7'
  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend7_NetworkLib[0U]);
  LibTerminate(&pruebafmu_DW.UDPSend7_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  LibDestroy(&pruebafmu_DW.UDPSend7_NetworkLib[0U], 1);
  DestroyUDPInterface(&pruebafmu_DW.UDPSend7_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send7'

  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!pruebafmu_DW.obj_d.matlabCodegenIsDeleted) {
    pruebafmu_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((pruebafmu_DW.obj_d.isInitialized == 1) &&
        pruebafmu_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&pruebafmu_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'

  // Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send5'
  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend5_NetworkLib[0U]);
  LibTerminate(&pruebafmu_DW.UDPSend5_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  LibDestroy(&pruebafmu_DW.UDPSend5_NetworkLib[0U], 1);
  DestroyUDPInterface(&pruebafmu_DW.UDPSend5_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send5'

  // Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send6'
  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend6_NetworkLib[0U]);
  LibTerminate(&pruebafmu_DW.UDPSend6_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  LibDestroy(&pruebafmu_DW.UDPSend6_NetworkLib[0U], 1);
  DestroyUDPInterface(&pruebafmu_DW.UDPSend6_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send6'

  // Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send2'
  sErr = GetErrorBuffer(&pruebafmu_DW.UDPSend2_NetworkLib[0U]);
  LibTerminate(&pruebafmu_DW.UDPSend2_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(pruebafmu_M, sErr);
    rtmSetStopRequested(pruebafmu_M, 1);
  }

  LibDestroy(&pruebafmu_DW.UDPSend2_NetworkLib[0U], 1);
  DestroyUDPInterface(&pruebafmu_DW.UDPSend2_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send2'

  // Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  if (!pruebafmu_DW.obj.matlabCodegenIsDeleted) {
    pruebafmu_DW.obj.matlabCodegenIsDeleted = true;
    if ((pruebafmu_DW.obj.isInitialized == 1) &&
        pruebafmu_DW.obj.isSetupComplete) {
      for (i = 0; i < 12; i++) {
        pruebafmu_B.motorValues_m[i] = (rtNaNF);
      }

      for (i = 0; i < 8; i++) {
        servoValues[i] = (rtNaNF);
      }

      for (i = 0; i < 12; i++) {
        if (pruebafmu_DW.obj.ValidMotorIdx[i]) {
          pruebafmu_B.motorValues_m[i] = 0.0F;
        }
      }

      for (i = 0; i < 8; i++) {
        if (pruebafmu_DW.obj.ValidServoIdx[i]) {
          servoValues[i] = 0.0F;
        }
      }

      MW_actuators_set(false, &pruebafmu_B.motorValues_m[0], &servoValues[0]);
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
