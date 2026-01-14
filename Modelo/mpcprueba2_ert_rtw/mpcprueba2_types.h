//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpcprueba2_types.h
//
// Code generated for Simulink model 'mpcprueba2'.
//
// Model version                  : 12.42
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jan 14 15:02:40 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef mpcprueba2_types_h_
#define mpcprueba2_types_h_
#include "rtwtypes.h"
#include <uORB/topics/sensor_gyro.h>
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
#ifndef struct_szTgroxymWCv1wbPz1KDaqC_mpcpr_T
#define struct_szTgroxymWCv1wbPz1KDaqC_mpcpr_T

struct szTgroxymWCv1wbPz1KDaqC_mpcpr_T
{
  real_T xstar[19];
  real_T fstar;
  real_T firstorderopt;
  real_T lambda[37];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[19];
};

#endif                                // struct_szTgroxymWCv1wbPz1KDaqC_mpcpr_T

#ifndef struct_sSitMryErsR3bMncKlW48mF_mpcpr_T
#define struct_sSitMryErsR3bMncKlW48mF_mpcpr_T

struct sSitMryErsR3bMncKlW48mF_mpcpr_T
{
  real_T grad[19];
  real_T Hx[18];
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                                // struct_sSitMryErsR3bMncKlW48mF_mpcpr_T

#ifndef struct_sBSaEu6uV23R8SnQxWoeC5G_mpcpr_T
#define struct_sBSaEu6uV23R8SnQxWoeC5G_mpcpr_T

struct sBSaEu6uV23R8SnQxWoeC5G_mpcpr_T
{
  real_T FMat[361];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_[912];
  real_T workspace2_[912];
};

#endif                                // struct_sBSaEu6uV23R8SnQxWoeC5G_mpcpr_T

#ifndef struct_sIOJhD9KwAkF5sEguPjYquC_mpcpr_T
#define struct_sIOJhD9KwAkF5sEguPjYquC_mpcpr_T

struct sIOJhD9KwAkF5sEguPjYquC_mpcpr_T
{
  boolean_T RemainFeasible;
  int32_T MaxIterations;
  real_T ConstrRelTolFactor;
  real_T ProbRelTolFactor;
};

#endif                                // struct_sIOJhD9KwAkF5sEguPjYquC_mpcpr_T

#ifndef struct_sqZVQFgLZG74FDpCArykMHB_mpcpr_T
#define struct_sqZVQFgLZG74FDpCArykMHB_mpcpr_T

struct sqZVQFgLZG74FDpCArykMHB_mpcpr_T
{
  char_T SolverName[8];
  boolean_T NonFiniteSupport;
  boolean_T IterDisplayQP;
  real_T ObjectiveLimit;
  real_T PricingTolerance;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T StepTolerance;
};

#endif                                // struct_sqZVQFgLZG74FDpCArykMHB_mpcpr_T

#ifndef struct_sIxc6e90CRmt17sP6BCIycE_mpcpr_T
#define struct_sIxc6e90CRmt17sP6BCIycE_mpcpr_T

struct sIxc6e90CRmt17sP6BCIycE_mpcpr_T
{
  int32_T ldq;
  real_T QR[703];
  real_T Q[361];
  int32_T jpvt[37];
  int32_T mrows;
  int32_T ncols;
  real_T tau[19];
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                // struct_sIxc6e90CRmt17sP6BCIycE_mpcpr_T

#ifndef struct_sDXqx68fEcBxWtF9wVQzAm_mpcpru_T
#define struct_sDXqx68fEcBxWtF9wVQzAm_mpcpru_T

struct sDXqx68fEcBxWtF9wVQzAm_mpcpru_T
{
  real_T workspace_float[703];
  int32_T workspace_int[37];
  int32_T workspace_sort[37];
};

#endif                                // struct_sDXqx68fEcBxWtF9wVQzAm_mpcpru_T

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

#ifndef struct_shMFFa6ZZiYob3JbcpnnDNC_mpcpr_T
#define struct_shMFFa6ZZiYob3JbcpnnDNC_mpcpr_T

struct shMFFa6ZZiYob3JbcpnnDNC_mpcpr_T
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real_T lb[19];
  real_T ub[19];
  int32_T indexLB[19];
  int32_T indexUB[19];
  int32_T indexFixed[19];
  int32_T mEqRemoved;
  real_T ATwset[703];
  real_T bwset[37];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[37];
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
  boolean_T isActiveConstr[37];
  int32_T Wid[37];
  int32_T Wlocalidx[37];
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                // struct_shMFFa6ZZiYob3JbcpnnDNC_mpcpr_T

// Parameters (default storage)
typedef struct P_mpcprueba2_T_ P_mpcprueba2_T;

// Forward declaration for rtModel
typedef struct tag_RTM_mpcprueba2_T RT_MODEL_mpcprueba2_T;

#endif                                 // mpcprueba2_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
