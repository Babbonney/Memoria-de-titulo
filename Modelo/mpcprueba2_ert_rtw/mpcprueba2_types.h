//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpcprueba2_types.h
//
// Code generated for Simulink model 'mpcprueba2'.
//
// Model version                  : 12.49
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Fri Jan 23 15:03:24 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef mpcprueba2_types_h_
#define mpcprueba2_types_h_
#include "rtwtypes.h"

// Custom Type definition for MATLAB Function: '<Root>/MATLAB Function5'
#ifndef struct_sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T
#define struct_sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T

struct sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T
{
  real_T xstar[16];
  real_T fstar;
  real_T firstorderopt;
  real_T lambda[67];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[16];
};

#endif                                // struct_sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T

#ifndef struct_s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T
#define struct_s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T

struct s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T
{
  real_T grad[16];
  real_T Hx[15];
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

#endif                                // struct_s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T

#ifndef struct_sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T
#define struct_sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T

struct sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T
{
  real_T FMat[256];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_[768];
  real_T workspace2_[768];
};

#endif                                // struct_sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T

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

#ifndef struct_ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T
#define struct_ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T

struct ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T
{
  int32_T ldq;
  real_T QR[1072];
  real_T Q[256];
  int32_T jpvt[67];
  int32_T mrows;
  int32_T ncols;
  real_T tau[16];
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                // struct_ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T

#ifndef struct_sFevNsrsl34D5b5aqm3qNjD_mpcpr_T
#define struct_sFevNsrsl34D5b5aqm3qNjD_mpcpr_T

struct sFevNsrsl34D5b5aqm3qNjD_mpcpr_T
{
  real_T workspace_float[1072];
  int32_T workspace_int[67];
  int32_T workspace_sort[67];
};

#endif                                // struct_sFevNsrsl34D5b5aqm3qNjD_mpcpr_T

#ifndef struct_sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
#define struct_sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T

struct sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real_T Aineq[1056];
  real_T bineq[66];
  real_T lb[16];
  real_T ub[16];
  int32_T indexLB[16];
  int32_T indexUB[16];
  int32_T indexFixed[16];
  int32_T mEqRemoved;
  real_T ATwset[1072];
  real_T bwset[67];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[67];
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
  real_T SLACK0;
};

#endif                                // struct_sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T

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
typedef struct P_mpcprueba2_T_ P_mpcprueba2_T;

// Forward declaration for rtModel
typedef struct tag_RTM_mpcprueba2_T RT_MODEL_mpcprueba2_T;

#endif                                 // mpcprueba2_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
