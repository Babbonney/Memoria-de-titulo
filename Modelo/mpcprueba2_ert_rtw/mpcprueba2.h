//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpcprueba2.h
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
#ifndef mpcprueba2_h_
#define mpcprueba2_h_
#include <cstdio>
#include <cstring>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "mpcprueba2_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <string.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

// Block signals (default storage)
struct B_mpcprueba2_T {
  sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T WorkingSet;
  sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T b_workingset;
  sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T CholRegManager;
  ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T QRManager;
  sFevNsrsl34D5b5aqm3qNjD_mpcpr_T memspace;
  real_T B[1072];
  real_T b_H[225];
  sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T solution;
  real_T work[67];
  real_T vn1[67];
  real_T vn2[67];
  real_T work_m[67];
  real_T b_x[66];
  s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T QPObjective;
  real_T work_c[16];
  real_T uvec[15];
  real_T f[15];
  real_T dv[15];
  real_T b_A[12];
  sqZVQFgLZG74FDpCArykMHB_mpcpr_T expl_temp;
  real_T M[4];
  real_T work_k[4];
  real_T vn1_c[4];
  real_T vn2_b[4];
  real_T dv1[3];
  real_T b_B[3];
  real_T tau[3];
  sIOJhD9KwAkF5sEguPjYquC_mpcpr_T expl_temp_p;
  sIOJhD9KwAkF5sEguPjYquC_mpcpr_T expl_temp_c;
  sIOJhD9KwAkF5sEguPjYquC_mpcpr_T expl_temp_f;
  sIOJhD9KwAkF5sEguPjYquC_mpcpr_T expl_temp_g;
  real_T Saturation;                   // '<Root>/Saturation'
  real_T Saturation1;                  // '<Root>/Saturation1'
  real_T Saturation3;                  // '<Root>/Saturation3'
  real_T Saturation2;                  // '<Root>/Saturation2'
  real_T u[3];                         // '<Root>/MATLAB Function5'
  real_T colSum;
  real_T f_infnrm;
  real_T b_colSum;
  real_T f_g;
  real_T maxConstr_new;
  real_T d;
  real_T tolDelta;
  real_T normDelta;
  real_T minLambda;
  real_T solution_lambda;
  real_T tempMaxConstr;
  real_T constrViolation_basicX;
  real_T temp;
  real_T temp2;
  real_T temp_m;
  real_T s;
  real_T b_atmp;
  real_T tau_n;
  real_T xnorm;
  real_T a;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T temp2_p;
  real_T smax;
  real_T s_l;
  real_T scale_j;
  real_T constrViolation;
  real_T tol;
  real_T qtb;
  real_T b_c;
  real_T constrViolation_d;
  real_T tol_g;
  real_T maxDiag;
  real_T u1;
  real_T c;
  real_T b_SCALED_REG_PRIMAL;
  real_T b_temp;
  real_T u1_l;
  real_T alpha1;
  real_T temp_d;
  real_T p_max;
  real_T denomTol;
  real_T alphaTemp;
  real_T phaseOneCorrectionX;
  real_T phaseOneCorrectionP;
  real_T pk_corrected;
  real_T ratio;
  real_T c_c;
  real_T b_s;
  real_T b_temp_d;
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale_l;
  real_T denomTol_o;
  real_T alphaTemp_b;
  real_T phaseOneCorrectionX_n;
  real_T phaseOneCorrectionP_b;
  real_T pk_corrected_l;
  real_T a_h;
  real_T b;
  real_T s_b;
  real_T temp_da;
  int32_T idxFillStart;
  int32_T colPos;
  int32_T i;
  int32_T mConstr;
  int32_T idxStartIneq;
  int32_T idxEndIneq;
  int32_T b_idxStartIneq;
  int32_T b_idxEndIneq;
  int32_T i_e;
  int32_T activeSetChangeID;
  int32_T nVar;
  int32_T globalActiveConstrIdx;
  int32_T TYPE;
  int32_T iAw0;
  int32_T ix0;
  int32_T iy0;
  int32_T minmn;
  int32_T i_b;
  int32_T nVar_j;
  int32_T mWConstr;
  int32_T nVar_f;
  int32_T offsetQR;
  int32_T rankQR;
  int32_T ldq;
  int32_T jBcol;
  int32_T iAcol;
  int32_T d_a;
  int32_T ix;
  int32_T b_ar;
  int32_T minmn_j;
  int32_T nfxd;
  int32_T mmi;
  int32_T pvt;
  int32_T itemp;
  int32_T ix_j;
  int32_T nVar_o;
  int32_T mTotalWorkingEq;
  int32_T nDepInd;
  int32_T idx_row;
  int32_T idxStartIneq_n;
  int32_T ix0_i;
  int32_T iy0_o;
  int32_T totalRank;
  int32_T nVar_n;
  int32_T mTotalWorkingEq_m;
  int32_T nDepInd_c;
  int32_T idxStartIneq_m;
  int32_T ix0_m;
  int32_T iy0_j;
  int32_T i_h;
  int32_T nActiveConstr;
  int32_T nFixedConstr;
  int32_T nVar_c;
  int32_T b_idx;
  int32_T ix0_c;
  int32_T iy0_p;
  int32_T b_k;
  int32_T nVar_p;
  int32_T mNull;
  int32_T nullStartIdx;
  int32_T b_idx_a;
  int32_T nVars;
  int32_T ldQ;
  int32_T lastColC;
  int32_T br;
  int32_T ar;
  int32_T b_idx_e;
  int32_T ix_a;
  int32_T idx;
  int32_T iy;
};

// Block states (default storage) for system '<Root>'
struct DW_mpcprueba2_T {
  sCBS0Ia3qD76sOwKERvBoFE_mpcpr_T opts;// '<Root>/MATLAB Function5'
  real_T x0[15];                       // '<Root>/MATLAB Function5'
  real_T u_prev[3];                    // '<Root>/MATLAB Function5'
  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<Root>/Scope'

  boolean_T doneDoubleBufferReInit;    // '<Root>/MATLAB Function5'
  boolean_T doneDoubleBufferReInit_h;  // '<Root>/MATLAB Function'
};

// Parameters (default storage)
struct P_mpcprueba2_T_ {
  real_T F[45];                        // Variable: F
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T G[225];                       // Variable: G
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T H[225];                       // Variable: H
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T Pc[990];                      // Variable: Pc
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T Qvec[225];                    // Variable: Qvec
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T Sc[198];                      // Variable: Sc
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T qc[66];                       // Variable: qc
                                          //  Referenced by: '<Root>/MATLAB Function5'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant2'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant4'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant5'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<Root>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: 0
                                          //  Referenced by: '<Root>/Saturation1'

  real_T Saturation3_UpperSat;         // Expression: 1
                                          //  Referenced by: '<Root>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: 0
                                          //  Referenced by: '<Root>/Saturation3'

  real_T Saturation2_UpperSat;         // Expression: 1
                                          //  Referenced by: '<Root>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: 0
                                          //  Referenced by: '<Root>/Saturation2'

};

// Real-time Model Data Structure
struct tag_RTM_mpcprueba2_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_mpcprueba2_T mpcprueba2_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_mpcprueba2_T mpcprueba2_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_mpcprueba2_T mpcprueba2_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void mpcprueba2_initialize(void);
  extern void mpcprueba2_step(void);
  extern void mpcprueba2_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_mpcprueba2_T *const mpcprueba2_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'mpcprueba2'
//  '<S1>'   : 'mpcprueba2/MATLAB Function'
//  '<S2>'   : 'mpcprueba2/MATLAB Function5'

#endif                                 // mpcprueba2_h_

//
// File trailer for generated code.
//
// [EOF]
//
