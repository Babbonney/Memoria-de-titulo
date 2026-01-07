//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: interruptor.cpp
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
#include "interruptor.h"
#include "interruptor_types.h"
#include "rtwtypes.h"
#include "interruptor_private.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

// Block signals (default storage)
B_interruptor_T interruptor_B;

// Block states (default storage)
DW_interruptor_T interruptor_DW;

// Real-time model
RT_MODEL_interruptor_T interruptor_M_ = RT_MODEL_interruptor_T();
RT_MODEL_interruptor_T *const interruptor_M = &interruptor_M_;

// Forward declaration for local functions
static void interrup_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);
static void interrup_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj)
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
void interruptor_step(void)
{
  int32_T i;
  real32_T servoValues[8];
  boolean_T b_varargout_1;

  // Reset subsysRan breadcrumbs
  srClearBC(interruptor_DW.EnabledSubsystem_SubsysRanBC);

  // MATLABSystem: '<S1>/SourceBlock'
  b_varargout_1 = uORB_read_step(interruptor_DW.obj_n.orbMetadataObj,
    &interruptor_DW.obj_n.eventStructObj, &interruptor_B.r, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S2>/Enable'

  // Start for MATLABSystem: '<S1>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S2>/In1'
    interruptor_B.In1 = interruptor_B.r;
    srUpdateBC(interruptor_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S1>/Enabled Subsystem'

  // SignalConversion: '<Root>/Signal Conversion'
  interruptor_B.SignalConversion[0] = interruptor_B.In1.output[0];
  interruptor_B.SignalConversion[1] = interruptor_B.In1.output[1];
  interruptor_B.SignalConversion[2] = interruptor_B.In1.output[2];
  interruptor_B.SignalConversion[3] = interruptor_B.In1.output[3];

  // ManualSwitch: '<Root>/Manual Switch'
  if (interruptor_P.ManualSwitch_CurrentSetting == 1) {
    // DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
    //   Constant: '<Root>/Valor maximo'

    interruptor_B.DataTypeConversion = static_cast<real32_T>
      (interruptor_P.Valormaximo_Value);
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
    //   Constant: '<Root>/Valor minimo'

    interruptor_B.DataTypeConversion = static_cast<real32_T>
      (interruptor_P.Valorminimo_Value);
  }

  // End of ManualSwitch: '<Root>/Manual Switch'
  // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
  //   Constant: '<Root>/Arm value'

  for (i = 0; i < 12; i++) {
    interruptor_B.motorValues[i] = (rtNaNF);
  }

  for (i = 0; i < 8; i++) {
    servoValues[i] = (rtNaNF);
  }

  interruptor_B.motorValues[0] = interruptor_B.DataTypeConversion;
  interruptor_B.motorValues[1] = interruptor_B.DataTypeConversion;
  interruptor_B.motorValues[2] = interruptor_B.DataTypeConversion;
  interruptor_B.motorValues[3] = interruptor_B.DataTypeConversion;
  MW_actuators_set(interruptor_P.Armvalue_Value, &interruptor_B.motorValues[0],
                   &servoValues[0]);

  // End of MATLABSystem: '<Root>/PX4 Actuator Write'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  interruptor_M->Timing.taskTime0 =
    ((time_T)(++interruptor_M->Timing.clockTick0)) *
    interruptor_M->Timing.stepSize0;
}

// Model initialize function
void interruptor_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(interruptor_M, -1);
  interruptor_M->Timing.stepSize0 = 0.001;

  // External mode info
  interruptor_M->Sizes.checksums[0] = (1560255261U);
  interruptor_M->Sizes.checksums[1] = (4179751558U);
  interruptor_M->Sizes.checksums[2] = (2397837558U);
  interruptor_M->Sizes.checksums[3] = (3588773961U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    interruptor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&interruptor_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(interruptor_M->extModeInfo,
      &interruptor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(interruptor_M->extModeInfo,
                        interruptor_M->Sizes.checksums);
    rteiSetTPtr(interruptor_M->extModeInfo, rtmGetTPtr(interruptor_M));
  }

  // block I/O
  (void) memset((static_cast<void *>(&interruptor_B)), 0,
                sizeof(B_interruptor_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&interruptor_DW), 0,
                sizeof(DW_interruptor_T));

  {
    int32_T i;

    // SystemInitialize for Enabled SubSystem: '<S1>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S2>/In1' incorporates:
    //   Outport: '<S2>/Out1'

    interruptor_B.In1 = interruptor_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem'

    // Start for MATLABSystem: '<S1>/SourceBlock'
    interruptor_DW.obj_n.matlabCodegenIsDeleted = false;
    interruptor_DW.obj_n.isSetupComplete = false;
    interruptor_DW.obj_n.isInitialized = 1;
    interruptor_DW.obj_n.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(interruptor_DW.obj_n.orbMetadataObj,
                         &interruptor_DW.obj_n.eventStructObj);
    interruptor_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    for (i = 0; i < 12; i++) {
      interruptor_DW.obj.ValidMotorIdx[i] = false;
    }

    for (i = 0; i < 8; i++) {
      interruptor_DW.obj.ValidServoIdx[i] = false;
    }

    interruptor_DW.obj.matlabCodegenIsDeleted = false;
    interruptor_DW.obj.isSetupComplete = false;
    interruptor_DW.obj.isInitialized = 1;
    interrup_PX4Actuators_setupImpl(&interruptor_DW.obj);
    interruptor_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/PX4 Actuator Write'
  }
}

// Model terminate function
void interruptor_terminate(void)
{
  int32_T i;
  real32_T servoValues[8];

  // Terminate for MATLABSystem: '<S1>/SourceBlock'
  if (!interruptor_DW.obj_n.matlabCodegenIsDeleted) {
    interruptor_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((interruptor_DW.obj_n.isInitialized == 1) &&
        interruptor_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&interruptor_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1>/SourceBlock'
  // Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  if (!interruptor_DW.obj.matlabCodegenIsDeleted) {
    interruptor_DW.obj.matlabCodegenIsDeleted = true;
    if ((interruptor_DW.obj.isInitialized == 1) &&
        interruptor_DW.obj.isSetupComplete) {
      for (i = 0; i < 12; i++) {
        interruptor_B.motorValues_m[i] = (rtNaNF);
      }

      for (i = 0; i < 8; i++) {
        servoValues[i] = (rtNaNF);
      }

      for (i = 0; i < 12; i++) {
        if (interruptor_DW.obj.ValidMotorIdx[i]) {
          interruptor_B.motorValues_m[i] = 0.0F;
        }
      }

      for (i = 0; i < 8; i++) {
        if (interruptor_DW.obj.ValidServoIdx[i]) {
          servoValues[i] = 0.0F;
        }
      }

      MW_actuators_set(false, &interruptor_B.motorValues_m[0], &servoValues[0]);
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
