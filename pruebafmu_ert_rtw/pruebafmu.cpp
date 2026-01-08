//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pruebafmu.cpp
//
// Code generated for Simulink model 'pruebafmu'.
//
// Model version                  : 12.34
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Thu Jan  8 12:17:43 2026
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
#include <stddef.h>
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

// user code (top of source file)
#include "RTWCG_FMU2_target.h"

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
  real_T currentTime;
  real_T stepError;
  real_T stepsize;
  int32_T i;
  real32_T phi;
  real32_T rtb_pitch;
  real32_T rtb_pitch_f;
  real32_T theta;
  boolean_T b_varargout_1;
  boolean_T rtb_ManualSwitch;

  // Reset subsysRan breadcrumbs
  srClearBC(pruebafmu_DW.EnabledSubsystem_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(pruebafmu_DW.EnabledSubsystem_SubsysRanBC);

  // Gain: '<Root>/Gain' incorporates:
  //   Constant: '<Root>/Constant3'
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  rtb_pitch = pruebafmu_P.Gain_Gain * static_cast<real32_T>
    (pruebafmu_P.Constant3_Value);

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

  // MATLAB Function: '<Root>/quat2eul'
  phi = rt_atan2f_snf((pruebafmu_B.In1.q[0] * pruebafmu_B.In1.q[1] +
                       pruebafmu_B.In1.q[2] * pruebafmu_B.In1.q[3]) * 2.0F,
                      ((pruebafmu_B.In1.q[0] * pruebafmu_B.In1.q[0] -
                        pruebafmu_B.In1.q[1] * pruebafmu_B.In1.q[1]) -
                       pruebafmu_B.In1.q[2] * pruebafmu_B.In1.q[2]) +
                      pruebafmu_B.In1.q[3] * pruebafmu_B.In1.q[3]);
  theta = static_cast<real32_T>(asin(static_cast<real_T>((pruebafmu_B.In1.q[1] *
    pruebafmu_B.In1.q[3] - pruebafmu_B.In1.q[0] * pruebafmu_B.In1.q[2]) * -2.0F)));

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant1'

  if (pruebafmu_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch = pruebafmu_P.Constant1_Value;
  } else {
    rtb_ManualSwitch = pruebafmu_P.Constant_Value_b;
  }

  // End of ManualSwitch: '<Root>/Manual Switch'

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

  // Gain: '<Root>/Gain1' incorporates:
  //   Constant: '<Root>/Constant2'
  //   DataTypeConversion: '<Root>/Data Type Conversion2'

  rtb_pitch_f = pruebafmu_P.Gain1_Gain * static_cast<real32_T>
    (pruebafmu_P.Constant2_Value);

  // FMU: '<Root>/FMU' incorporates:
  //   Constant: '<Root>/Constant4'
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   DataTypeConversion: '<Root>/Data Type Conversion4'
  //   DataTypeConversion: '<Root>/Data Type Conversion5'
  //   DataTypeConversion: '<Root>/Data Type Conversion6'
  //   DataTypeConversion: '<Root>/Data Type Conversion7'
  //   DataTypeConversion: '<Root>/Data Type Conversion8'
  //   DataTypeConversion: '<Root>/Data Type Conversion9'

  if (pruebafmu_DW.FMU_FmuIsInitialized == 0) {
    pruebafmu_DW.FMU_FmuPrevTime = pruebafmu_M->Timing.taskTime0;
    pruebafmu_DW.FMU_slPrevTime = pruebafmu_DW.FMU_FmuPrevTime;
    FMU2_enterInitializationMode(&pruebafmu_DW.FMU_FmuStruct2);
    pruebafmu_DW.FMU_ValContInReal[0] = pruebafmu_P.Constant4_Value;
    pruebafmu_DW.FMU_ValContInReal[1] = rtb_pitch;
    pruebafmu_DW.FMU_ValContInReal[2] = phi;
    pruebafmu_DW.FMU_ValContInReal[3] = rtb_ManualSwitch;
    pruebafmu_DW.FMU_ValContInReal[4] = pruebafmu_B.In1_e.x;
    pruebafmu_DW.FMU_ValContInReal[5] = rtb_pitch_f;
    pruebafmu_DW.FMU_ValContInReal[6] = theta;
    pruebafmu_DW.FMU_ValContInReal[7] = pruebafmu_B.In1_e.y;
    FMU2_setReal(&pruebafmu_DW.FMU_FmuStruct2, pruebafmu_P.FMU_VRContInReal, 8,
                 pruebafmu_DW.FMU_ValContInReal);
    FMU2_exitInitializationMode(&pruebafmu_DW.FMU_FmuStruct2);
    pruebafmu_DW.FMU_FmuIsInitialized = 1;
    FMU2_getReal(&pruebafmu_DW.FMU_FmuStruct2, pruebafmu_P.FMU_VROutReal, 4,
                 pruebafmu_DW.FMU_ValOutReal);
    pruebafmu_B.FMU[0] = pruebafmu_DW.FMU_ValOutReal[0];
    pruebafmu_B.FMU[1] = pruebafmu_DW.FMU_ValOutReal[1];
    pruebafmu_B.FMU[2] = pruebafmu_DW.FMU_ValOutReal[2];
    pruebafmu_B.FMU[3] = pruebafmu_DW.FMU_ValOutReal[3];
  } else {
    currentTime = pruebafmu_M->Timing.taskTime0;
    stepsize = currentTime - pruebafmu_DW.FMU_slPrevTime;
    if (stepsize > 0.0) {
      stepError = stepsize - 0.001;
      if (stepsize - 0.001 < 0.0) {
        stepError = 0.001 - stepsize;
      }

      if (stepError < 1.1920928955078125E-7) {
        stepsize = 0.001;
      }

      FMU2_doStep(&pruebafmu_DW.FMU_FmuStruct2, pruebafmu_DW.FMU_FmuPrevTime,
                  stepsize, 1);
      pruebafmu_DW.FMU_FmuPrevTime += stepsize;
      pruebafmu_DW.FMU_slPrevTime = currentTime;
      FMU2_getReal(&pruebafmu_DW.FMU_FmuStruct2, pruebafmu_P.FMU_VROutReal, 4,
                   pruebafmu_DW.FMU_ValOutReal);
      pruebafmu_B.FMU[0] = pruebafmu_DW.FMU_ValOutReal[0];
      pruebafmu_B.FMU[1] = pruebafmu_DW.FMU_ValOutReal[1];
      pruebafmu_B.FMU[2] = pruebafmu_DW.FMU_ValOutReal[2];
      pruebafmu_B.FMU[3] = pruebafmu_DW.FMU_ValOutReal[3];
    }
  }

  // End of FMU: '<Root>/FMU'

  // DataTypeConversion: '<Root>/Data Type Conversion'
  pruebafmu_B.DataTypeConversion[0] = static_cast<real32_T>(pruebafmu_B.FMU[0]);
  pruebafmu_B.DataTypeConversion[1] = static_cast<real32_T>(pruebafmu_B.FMU[1]);
  pruebafmu_B.DataTypeConversion[2] = static_cast<real32_T>(pruebafmu_B.FMU[2]);
  pruebafmu_B.DataTypeConversion[3] = static_cast<real32_T>(pruebafmu_B.FMU[3]);

  // MATLABSystem: '<Root>/PX4 Actuator Write'
  for (i = 0; i < 12; i++) {
    pruebafmu_B.motorValues[i] = (rtNaNF);
  }

  for (i = 0; i < 8; i++) {
    pruebafmu_B.servoValues[i] = (rtNaNF);
  }

  pruebafmu_B.motorValues[0] = pruebafmu_B.DataTypeConversion[0];
  pruebafmu_B.motorValues[1] = pruebafmu_B.DataTypeConversion[1];
  pruebafmu_B.motorValues[2] = pruebafmu_B.DataTypeConversion[2];
  pruebafmu_B.motorValues[3] = pruebafmu_B.DataTypeConversion[3];
  MW_actuators_set(rtb_ManualSwitch, &pruebafmu_B.motorValues[0],
                   &pruebafmu_B.servoValues[0]);

  // End of MATLABSystem: '<Root>/PX4 Actuator Write'
  // Update for FMU: '<Root>/FMU' incorporates:
  //   Constant: '<Root>/Constant4'
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   DataTypeConversion: '<Root>/Data Type Conversion4'
  //   DataTypeConversion: '<Root>/Data Type Conversion5'
  //   DataTypeConversion: '<Root>/Data Type Conversion6'
  //   DataTypeConversion: '<Root>/Data Type Conversion7'
  //   DataTypeConversion: '<Root>/Data Type Conversion8'
  //   DataTypeConversion: '<Root>/Data Type Conversion9'

  pruebafmu_DW.FMU_ValContInReal[0] = pruebafmu_P.Constant4_Value;
  pruebafmu_DW.FMU_ValContInReal[1] = rtb_pitch;
  pruebafmu_DW.FMU_ValContInReal[2] = phi;
  pruebafmu_DW.FMU_ValContInReal[3] = rtb_ManualSwitch;
  pruebafmu_DW.FMU_ValContInReal[4] = pruebafmu_B.In1_e.x;
  pruebafmu_DW.FMU_ValContInReal[5] = rtb_pitch_f;
  pruebafmu_DW.FMU_ValContInReal[6] = theta;
  pruebafmu_DW.FMU_ValContInReal[7] = pruebafmu_B.In1_e.y;
  FMU2_setReal(&pruebafmu_DW.FMU_FmuStruct2, pruebafmu_P.FMU_VRContInReal, 8,
               pruebafmu_DW.FMU_ValContInReal);

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
  pruebafmu_M->Sizes.checksums[0] = (145060191U);
  pruebafmu_M->Sizes.checksums[1] = (2407075206U);
  pruebafmu_M->Sizes.checksums[2] = (2578620505U);
  pruebafmu_M->Sizes.checksums[3] = (1398927061U);

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

    // SetupRuntimeResources for FMU: '<Root>/FMU'
    pruebafmu_DW.FMU_FmuStruct2 = FMU2_fmuInitializeCS(
      "C:\\Users\\aero\\Desktop\\Proyecto control AMPC-DMPC\\repositorios\\Memoria-de-titulo\\slprj\\_fmu\\f2ec0e234a2d00d638c54fa383704903\\pruebafmu2\\binaries\\win64\\pruebafmu2.dll",
      "pruebafmu2", "{d8171cd2-137a-3ec8-ba53-d804d5f9fdb9}",
      "file:///C:/Users/aero/Desktop/Proyecto%20control%20AMPC-DMPC/repositorios/Memoria-de-titulo/slprj/_fmu/f2ec0e234a2d00d638c54fa383704903/pruebafmu2/resources",
      NULL, 1, 1, 0, NULL, false, false);
    createParamIdxToOffset(&pruebafmu_DW.FMU_FmuStruct2, 0);
    createEnumValueList(&pruebafmu_DW.FMU_FmuStruct2, 0);

    // InitializeConditions for FMU: '<Root>/FMU'
    pruebafmu_DW.FMU_FmuIsInitialized = 0;
    FMU2_setupExperiment(&pruebafmu_DW.FMU_FmuStruct2, false, 0.001,
                         pruebafmu_M->Timing.taskTime0, false, 1000.0);

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

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!pruebafmu_DW.obj_c.matlabCodegenIsDeleted) {
    pruebafmu_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((pruebafmu_DW.obj_c.isInitialized == 1) &&
        pruebafmu_DW.obj_c.isSetupComplete) {
      uORB_read_terminate(&pruebafmu_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!pruebafmu_DW.obj_d.matlabCodegenIsDeleted) {
    pruebafmu_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((pruebafmu_DW.obj_d.isInitialized == 1) &&
        pruebafmu_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&pruebafmu_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'

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
  // CleanupRuntimeResources for FMU: '<Root>/FMU'
  if (pruebafmu_DW.FMU_FmuStruct2 != NULL) {
    FMU2_terminate(&pruebafmu_DW.FMU_FmuStruct2);
  }

  // End of CleanupRuntimeResources for FMU: '<Root>/FMU'
}

//
// File trailer for generated code.
//
// [EOF]
//
