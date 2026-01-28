//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpcprueba3_types.h
//
// Code generated for Simulink model 'mpcprueba3'.
//
// Model version                  : 12.54
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jan 28 14:19:31 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef mpcprueba3_types_h_
#define mpcprueba3_types_h_
#include "rtwtypes.h"
#include <uORB/topics/vehicle_odometry.h>

// Custom Type definition for MATLAB Function: '<Root>/MATLAB Function5'
#ifndef struct_s53NiOJFNFao3mXDluAcV3_mpcpru_T
#define struct_s53NiOJFNFao3mXDluAcV3_mpcpru_T

struct s53NiOJFNFao3mXDluAcV3_mpcpru_T
{
  real32_T grad[16];
  real32_T Hx[15];
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real32_T beta;
  real32_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real32_T gammaScalar;
};

#endif                                // struct_s53NiOJFNFao3mXDluAcV3_mpcpru_T

#ifndef struct_s84kJ6tHYwvmDUGeqLYD2uB_mpcpr_T
#define struct_s84kJ6tHYwvmDUGeqLYD2uB_mpcpr_T

struct s84kJ6tHYwvmDUGeqLYD2uB_mpcpr_T
{
  real32_T FMat[256];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real32_T scaleFactor;
  boolean_T ConvexCheck;
  real32_T regTol_;
  real32_T workspace_[768];
  real32_T workspace2_[768];
};

#endif                                // struct_s84kJ6tHYwvmDUGeqLYD2uB_mpcpr_T

#ifndef struct_sOIMERIP639G9x3OUDedPv_mpcpru_T
#define struct_sOIMERIP639G9x3OUDedPv_mpcpru_T

struct sOIMERIP639G9x3OUDedPv_mpcpru_T
{
  boolean_T RemainFeasible;
  int32_T MaxIterations;
  real32_T ConstrRelTolFactor;
  real32_T ProbRelTolFactor;
};

#endif                                // struct_sOIMERIP639G9x3OUDedPv_mpcpru_T

#ifndef struct_sbtWOgGGLEmAd335P8Y53FE_mpcpr_T
#define struct_sbtWOgGGLEmAd335P8Y53FE_mpcpr_T

struct sbtWOgGGLEmAd335P8Y53FE_mpcpr_T
{
  real32_T xstar[16];
  real32_T fstar;
  real32_T firstorderopt;
  real32_T lambda[67];
  int32_T state;
  real32_T maxConstr;
  int32_T iterations;
  real32_T searchDir[16];
};

#endif                                // struct_sbtWOgGGLEmAd335P8Y53FE_mpcpr_T

#ifndef struct_d_px4_internal_block_SampleTi_T
#define struct_d_px4_internal_block_SampleTi_T

struct d_px4_internal_block_SampleTi_T
{
  int32_T __dummy;
};

#endif                                // struct_d_px4_internal_block_SampleTi_T

#ifndef struct_px4_internal_block_Subscriber_T
#define struct_px4_internal_block_Subscriber_T

struct px4_internal_block_Subscriber_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_px4_internal_block_SampleTi_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Subscriber_T

// Custom Type definition for MATLAB Function: '<Root>/MATLAB Function5'
#ifndef struct_s9KKbMhkwfdyFmbpWOvu65D_mpcpr_T
#define struct_s9KKbMhkwfdyFmbpWOvu65D_mpcpr_T

struct s9KKbMhkwfdyFmbpWOvu65D_mpcpr_T
{
  char_T SolverName[8];
  boolean_T NonFiniteSupport;
  boolean_T IterDisplayQP;
  real32_T ObjectiveLimit;
  real32_T PricingTolerance;
  real32_T ConstraintTolerance;
  real32_T OptimalityTolerance;
  real32_T StepTolerance;
};

#endif                                // struct_s9KKbMhkwfdyFmbpWOvu65D_mpcpr_T

#ifndef struct_sa62cVcKQKcFBi6rAdMOFyB_mpcpr_T
#define struct_sa62cVcKQKcFBi6rAdMOFyB_mpcpr_T

struct sa62cVcKQKcFBi6rAdMOFyB_mpcpr_T
{
  int32_T ldq;
  real32_T QR[1072];
  real32_T Q[256];
  int32_T jpvt[67];
  int32_T mrows;
  int32_T ncols;
  real32_T tau[16];
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                // struct_sa62cVcKQKcFBi6rAdMOFyB_mpcpr_T

#ifndef struct_s1ukn1KZwe8HKOg95SKgssB_mpcpr_T
#define struct_s1ukn1KZwe8HKOg95SKgssB_mpcpr_T

struct s1ukn1KZwe8HKOg95SKgssB_mpcpr_T
{
  real32_T workspace_float[1072];
  int32_T workspace_int[67];
  int32_T workspace_sort[67];
};

#endif                                // struct_s1ukn1KZwe8HKOg95SKgssB_mpcpr_T

#ifndef struct_px4_internal_block_PX4Actuato_T
#define struct_px4_internal_block_PX4Actuato_T

struct px4_internal_block_PX4Actuato_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  uint8_T QSize;
  boolean_T ValidMotorIdx[12];
  boolean_T ValidServoIdx[8];
};

#endif                                // struct_px4_internal_block_PX4Actuato_T

// Custom Type definition for MATLAB Function: '<Root>/MATLAB Function5'
#ifndef struct_sCkfVcG7AQFySWWMtM4hccH_mpcpr_T
#define struct_sCkfVcG7AQFySWWMtM4hccH_mpcpr_T

struct sCkfVcG7AQFySWWMtM4hccH_mpcpr_T
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real32_T Aineq[1056];
  real32_T bineq[66];
  real32_T lb[16];
  real32_T ub[16];
  int32_T indexLB[16];
  int32_T indexUB[16];
  int32_T indexFixed[16];
  int32_T mEqRemoved;
  real32_T ATwset[1072];
  real32_T bwset[67];
  int32_T nActiveConstr;
  real32_T maxConstrWorkspace[67];
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[67];
  int32_T Wid[67];
  int32_T Wlocalidx[67];
  int32_T nWConstr[5];
  int32_T probType;
  real32_T SLACK0;
};

#endif                                // struct_sCkfVcG7AQFySWWMtM4hccH_mpcpr_T

#ifndef struct_sCBS0Ia3qD76sOwKERvBoFE_mpcpr_T
#define struct_sCBS0Ia3qD76sOwKERvBoFE_mpcpr_T

struct sCBS0Ia3qD76sOwKERvBoFE_mpcpr_T
{
  boolean_T NonFiniteSupport;
  boolean_T IterDisplaySQP;
  real_T InitDamping;
  char_T FiniteDifferenceType[7];
  boolean_T SpecifyObjectiveGradient;
  boolean_T ScaleProblem;
  boolean_T SpecifyConstraintGradient;
  real_T FiniteDifferenceStepSize;
  real_T MaxFunctionEvaluations;
  boolean_T IterDisplayQP;
  real_T PricingTolerance;
  char_T Algorithm[10];
  real_T ObjectiveLimit;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T StepTolerance;
  real_T MaxIterations;
  real_T FunctionTolerance;
  char_T SolverName[8];
  char_T Display[3];
  boolean_T UseCodegenSolver;
  boolean_T CheckGradients;
  char_T Diagnostics[3];
  real_T DiffMaxChange;
  real_T DiffMinChange;
  char_T FunValCheck[3];
  boolean_T UseParallel;
  char_T LinearSolver[4];
  char_T SubproblemAlgorithm[2];
};

#endif                                // struct_sCBS0Ia3qD76sOwKERvBoFE_mpcpr_T

// Parameters (default storage)
typedef struct P_mpcprueba3_T_ P_mpcprueba3_T;

// Forward declaration for rtModel
typedef struct tag_RTM_mpcprueba3_T RT_MODEL_mpcprueba3_T;

#endif                                 // mpcprueba3_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
