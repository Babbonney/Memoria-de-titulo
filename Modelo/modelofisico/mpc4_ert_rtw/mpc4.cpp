//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpc4.cpp
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
#include "mpc4.h"
#include "rtwtypes.h"
#include "mpc4_types.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "mpc4_private.h"
#include "rt_defines.h"

// Block signals (default storage)
B_mpc4_T mpc4_B;

// Block states (default storage)
DW_mpc4_T mpc4_DW;

// Real-time model
RT_MODEL_mpc4_T mpc4_M_ = RT_MODEL_mpc4_T();
RT_MODEL_mpc4_T *const mpc4_M = &mpc4_M_;

// Forward declaration for local functions
static boolean_T mpc4_strcmp(const char_T a[8]);
static real_T mpc4_xnrm2(int32_T n, const real_T x[1072], int32_T ix0);
static real_T mpc4_rt_hypotd_snf(real_T u0, real_T u1);
static real_T mpc4_xzlarfg(int32_T n, real_T *alpha1, real_T x[1072], int32_T
  ix0);
static void mpc4_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T C
  [1072], int32_T ic0, real_T work[67]);
static void mpc4_qrf(real_T A[1072], int32_T ia0, int32_T m, int32_T n, int32_T
                     nfxd, real_T tau[16]);
static void mpc4_xgeqp3(real_T A[1072], int32_T m, int32_T n, int32_T jpvt[67],
  real_T tau[16]);
static void mpc4_computeQ_(ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *obj, int32_T nrows);
static int32_T mpc4_ComputeNumDependentEq_(ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T
  *qrmanager, const real_T beqf[67], int32_T mConstr, int32_T nVar);
static void mpc4_IndexOfDependentEq_(int32_T depIdx[67], int32_T mFixed, int32_T
  nDep, ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, int32_T mRows, int32_T nCols);
static void mpc4_countsort(int32_T x[67], int32_T xLen, int32_T workspace[67],
  int32_T xMin, int32_T xMax);
static void mpc4_removeConstr(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj, int32_T
  idx_global);
static void mpc4_removeEqConstr(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj, int32_T
  idx_global);
static void mpc4_RemoveDependentIneq_(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, sFevNsrsl34D5b5aqm3qNjD_mpc4_T
  *memspace, real_T tolfactor);
static int32_T mpc4_rank(const real_T qrmanager_QR[1072], int32_T
  qrmanager_mrows, int32_T qrmanager_ncols);
static void mpc4_xgemv(int32_T m, int32_T n, const real_T A[1056], int32_T lda,
  const real_T x[1072], real_T y[67]);
static real_T mpc4_maxConstraintViolation(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj,
  const real_T x[1072]);
static void mpc4_xgemv_j(int32_T m, int32_T n, const real_T A[1056], int32_T lda,
  const real_T x[1072], real_T y[67]);
static real_T mpc4_maxConstraintViolation_n(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj,
  const real_T x[1072]);
static boolean_T mpc4_feasibleX0ForWorkingSet(real_T workspace[1072], real_T
  xCurrent[16], sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager);
static void mpc4_xgemv_j3(int32_T m, int32_T n, const real_T A[1056], int32_T
  lda, const real_T x[16], real_T y[67]);
static real_T mpc4_maxConstraintViolation_n3(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj,
  const real_T x[16]);
static void mpc4_PresolveWorkingSet(sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution,
  sFevNsrsl34D5b5aqm3qNjD_mpc4_T *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T
  *workingset, const sqZVQFgLZG74FDpCArykMHB_mpc4_T *options,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager);
static void mpc4_modifyOverheadPhaseOne_(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj);
static void mpc4_setProblemType(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj, int32_T
  PROBLEM_TYPE);
static void mpc4_xgemv_j30(int32_T m, int32_T n, const real_T A[225], int32_T
  lda, const real_T x[16], real_T y[15]);
static void mpc4_computeGrad_StoreHx(s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *obj, const
  real_T b_H[225], const real_T f[15], const real_T x[16]);
static real_T mpc4_computeFval_ReuseHx(const s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *obj,
  real_T workspace[1072], const real_T f[15], const real_T x[16]);
static void mpc4_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void mpc4_squareQ_appendCol(ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *obj, const
  real_T vec[1072], int32_T iv0);
static void mpc4_deleteColMoveEnd(ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *obj, int32_T
  idx);
static int32_T mpc4_ixamax(int32_T n, const real_T x[256], int32_T incx);
static void mpc4_fullColLDL2_(sOWFOmKuLvD2kpFwfdM45bG_mpc4_T *obj, int32_T
  LD_offset, int32_T NColsRemain, real_T REG_PRIMAL);
static void mpc4_xgemv_j30b(int32_T m, int32_T n, const real_T A[256], int32_T
  ia0, int32_T lda, const real_T x[1072], real_T y[16]);
static void mpc4_compute_deltax(const real_T b_H[225],
  sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpc4_T
  *memspace, const ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager,
  sOWFOmKuLvD2kpFwfdM45bG_mpc4_T *cholmanager, const
  s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *objective);
static real_T mpc4_xnrm2_l(int32_T n, const real_T x[16]);
static void mpc4_xgemv_j30bu(int32_T m, int32_T n, const real_T A[1056], int32_T
  lda, const real_T x[16], real_T y[1072]);
static void mpc4_xgemv_j30bul(int32_T m, int32_T n, const real_T A[1056],
  int32_T lda, const real_T x[16], real_T y[1072]);
static void mpc4_ratiotest(const real_T solution_xstar[16], const real_T
  solution_searchDir[16], real_T workspace[1072], int32_T workingset_nVar,
  int32_T workingset_ldA, const real_T workingset_Aineq[1056], const real_T
  workingset_bineq[66], const real_T workingset_lb[16], const real_T
  workingset_ub[16], const int32_T workingset_indexLB[16], const int32_T
  workingset_indexUB[16], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[67],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T tolcon,
  real_T *toldelta, real_T *alpha, boolean_T *newBlocking, int32_T *constrType,
  int32_T *constrIdx);
static void mpc4_feasibleratiotest(const real_T solution_xstar[16], const real_T
  solution_searchDir[16], real_T workspace[1072], int32_T workingset_nVar,
  int32_T workingset_ldA, const real_T workingset_Aineq[1056], const real_T
  workingset_bineq[66], const real_T workingset_lb[16], const real_T
  workingset_ub[16], const int32_T workingset_indexLB[16], const int32_T
  workingset_indexUB[16], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[67],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T tolcon,
  real_T *alpha, boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx);
static void mpc4_addBoundToActiveSetMatrix_(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj,
  int32_T TYPE, int32_T idx_local);
static void mpc4_compute_lambda(real_T workspace[1072],
  sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution, const s3c01M66EFWFQJ5qmFcUbmD_mpc4_T
  *objective, const ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager);
static void mpc4_checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f[15], sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution,
  sFevNsrsl34D5b5aqm3qNjD_mpc4_T *memspace, const s3c01M66EFWFQJ5qmFcUbmD_mpc4_T
  *objective, sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, real_T options_ObjectiveLimit,
  real_T options_ConstraintTolerance, int32_T runTimeOptions_MaxIterations,
  real_T runTimeOptions_ConstrRelTolFact, boolean_T *updateFval, boolean_T
  iterDisplayQP);
static void mpc4_computeFirstOrderOpt(sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution,
  const s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *objective, int32_T workingset_nVar,
  int32_T workingset_ldA, const real_T workingset_ATwset[1072], int32_T
  workingset_nActiveConstr, real_T workspace[1072]);
static void mpc4_iterate(const real_T b_H[225], const real_T f[15],
  sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpc4_T
  *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, sOWFOmKuLvD2kpFwfdM45bG_mpc4_T
  *cholmanager, s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *objective, boolean_T
  options_IterDisplayQP, real_T options_ObjectiveLimit, real_T
  options_PricingTolerance, real_T options_ConstraintTolerance, real_T
  options_StepTolerance, const sIOJhD9KwAkF5sEguPjYquC_mpc4_T runTimeOptions);
static void mpc4_PresolveWorkingSet_e(sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution,
  sFevNsrsl34D5b5aqm3qNjD_mpc4_T *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T
  *workingset, ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, const
  sqZVQFgLZG74FDpCArykMHB_mpc4_T *options);
static void mpc4_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar, real_T
  workspace[1072], const real_T b_H[225], const real_T f[15], const real_T x[16]);
static real_T mpc4_computeFval(const s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *obj, real_T
  workspace[1072], const real_T b_H[225], const real_T f[15], const real_T x[16]);
static void mpc4_driver(const real_T b_H[225], const real_T f[15],
  sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpc4_T
  *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *workingset,
  sOWFOmKuLvD2kpFwfdM45bG_mpc4_T *cholmanager, const
  sqZVQFgLZG74FDpCArykMHB_mpc4_T options, int32_T runTimeOptions_MaxIterations,
  real_T runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, s3c01M66EFWFQJ5qmFcUbmD_mpc4_T
  *objective);
static void mpc4_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void mpc4_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(mpc4_M, 1));
}

//
//         This function updates active task flag for each subrate
//         and rate transition flags for tasks that exchange data.
//         The function assumes rate-monotonic multitasking scheduler.
//         The function must be called at model base rate so that
//         the generated code self-manages all its subrates and rate
//         transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // To ensure a deterministic data transfer between two rates,
  //  data is transferred at the priority of a fast task and the frequency
  //  of the slow task.  The following flags indicate when the data transfer
  //  happens.  That is, a rate interaction flag is set true when both rates
  //  will run, and false otherwise.


  // tid 0 shares data with slower tid rate: 1
  mpc4_M->Timing.RateInteraction.TID0_1 = (mpc4_M->Timing.TaskCounters.TID[1] ==
    0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (mpc4_M->Timing.TaskCounters.TID[1])++;
  if ((mpc4_M->Timing.TaskCounters.TID[1]) > 4) {// Sample time: [0.05s, 0.0s]
    mpc4_M->Timing.TaskCounters.TID[1] = 0;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static boolean_T mpc4_strcmp(const char_T a[8])
{
  int32_T kstr;
  boolean_T b_bool;
  static const char_T c[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\a', '\b', '\t', '\n', '\v', '\f', '\r', '\x0e', '\x0f', '\x10',
    '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19',
    '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$',
    '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b',
    'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
    '\x7f' };

  static const char_T d[8] = { 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  b_bool = false;
  kstr = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (kstr < 8) {
      if (c[static_cast<int32_T>(static_cast<uint8_T>(a[kstr]) & 127U)] != c[
          static_cast<int32_T>(d[kstr])]) {
        exitg1 = 1;
      } else {
        kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return b_bool;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static real_T mpc4_xnrm2(int32_T n, const real_T x[1072], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      int32_T kend;
      mpc4_B.scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (int32_T k = ix0; k < kend; k++) {
        mpc4_B.absxk = fabs(x[k - 1]);
        if (mpc4_B.absxk > mpc4_B.scale) {
          mpc4_B.t = mpc4_B.scale / mpc4_B.absxk;
          y = y * mpc4_B.t * mpc4_B.t + 1.0;
          mpc4_B.scale = mpc4_B.absxk;
        } else {
          mpc4_B.t = mpc4_B.absxk / mpc4_B.scale;
          y += mpc4_B.t * mpc4_B.t;
        }
      }

      y = mpc4_B.scale * sqrt(y);
    }
  }

  return y;
}

static real_T mpc4_rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T b;
  real_T y;
  mpc4_B.a_b = fabs(u0);
  b = fabs(u1);
  if (mpc4_B.a_b < b) {
    mpc4_B.a_b /= b;
    y = sqrt(mpc4_B.a_b * mpc4_B.a_b + 1.0) * b;
  } else if (mpc4_B.a_b > b) {
    b /= mpc4_B.a_b;
    y = sqrt(b * b + 1.0) * mpc4_B.a_b;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = mpc4_B.a_b * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static real_T mpc4_xzlarfg(int32_T n, real_T *alpha1, real_T x[1072], int32_T
  ix0)
{
  real_T tau;
  int32_T c;
  int32_T d;
  int32_T knt;
  tau = 0.0;
  if (n > 0) {
    mpc4_B.xnorm = mpc4_xnrm2(n - 1, x, ix0);
    if (mpc4_B.xnorm != 0.0) {
      mpc4_B.xnorm = mpc4_rt_hypotd_snf(*alpha1, mpc4_B.xnorm);
      if (*alpha1 >= 0.0) {
        mpc4_B.xnorm = -mpc4_B.xnorm;
      }

      if (fabs(mpc4_B.xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        c = (ix0 + n) - 2;
        do {
          knt++;
          for (d = ix0; d <= c; d++) {
            x[d - 1] *= 9.9792015476736E+291;
          }

          mpc4_B.xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(mpc4_B.xnorm) < 1.0020841800044864E-292) && (knt < 20));

        mpc4_B.xnorm = mpc4_rt_hypotd_snf(*alpha1, mpc4_xnrm2(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          mpc4_B.xnorm = -mpc4_B.xnorm;
        }

        tau = (mpc4_B.xnorm - *alpha1) / mpc4_B.xnorm;
        mpc4_B.a = 1.0 / (*alpha1 - mpc4_B.xnorm);
        for (d = ix0; d <= c; d++) {
          x[d - 1] *= mpc4_B.a;
        }

        for (d = 0; d < knt; d++) {
          mpc4_B.xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = mpc4_B.xnorm;
      } else {
        tau = (mpc4_B.xnorm - *alpha1) / mpc4_B.xnorm;
        mpc4_B.a = 1.0 / (*alpha1 - mpc4_B.xnorm);
        d = (ix0 + n) - 2;
        for (knt = ix0; knt <= d; knt++) {
          x[knt - 1] *= mpc4_B.a;
        }

        *alpha1 = mpc4_B.xnorm;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T C
  [1072], int32_T ic0, real_T work[67])
{
  int32_T b_ia;
  int32_T coltop;
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      coltop = ((lastc - 1) << 4) + ic0;
      b_ia = coltop;
      do {
        exitg1 = 0;
        if (b_ia <= (coltop + lastv) - 1) {
          if (C[b_ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            b_ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    lastc--;
  } else {
    lastv = 0;
    lastc = -1;
  }

  if (lastv > 0) {
    int32_T d;
    int32_T jA;
    if (lastc + 1 != 0) {
      if (lastc >= 0) {
        memset(&work[0], 0, static_cast<uint32_T>(lastc + 1) * sizeof(real_T));
      }

      jA = (lastc << 4) + ic0;
      for (coltop = ic0; coltop <= jA; coltop += 16) {
        mpc4_B.c = 0.0;
        d = coltop + lastv;
        for (b_ia = coltop; b_ia < d; b_ia++) {
          mpc4_B.c += C[((iv0 + b_ia) - coltop) - 1] * C[b_ia - 1];
        }

        b_ia = (coltop - ic0) >> 4;
        work[b_ia] += mpc4_B.c;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      for (coltop = 0; coltop <= lastc; coltop++) {
        mpc4_B.c = work[coltop];
        if (mpc4_B.c != 0.0) {
          mpc4_B.c *= -tau;
          d = lastv + jA;
          for (b_ia = jA; b_ia < d; b_ia++) {
            C[b_ia - 1] += C[((iv0 + b_ia) - jA) - 1] * mpc4_B.c;
          }
        }

        jA += 16;
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_qrf(real_T A[1072], int32_T ia0, int32_T m, int32_T n, int32_T
                     nfxd, real_T tau[16])
{
  int32_T i;
  int32_T ii;
  int32_T mmi;
  memset(&mpc4_B.work_m[0], 0, 67U * sizeof(real_T));
  for (i = 0; i < nfxd; i++) {
    ii = (((i << 4) + ia0) + i) - 1;
    mmi = m - i;
    if (i + 1 < m) {
      mpc4_B.b_atmp = A[ii];
      mpc4_B.tau = mpc4_xzlarfg(mmi, &mpc4_B.b_atmp, A, ii + 2);
      tau[i] = mpc4_B.tau;
      A[ii] = mpc4_B.b_atmp;
    } else {
      mpc4_B.tau = 0.0;
      tau[i] = 0.0;
    }

    if (i + 1 < n) {
      mpc4_B.b_atmp = A[ii];
      A[ii] = 1.0;
      mpc4_xzlarf(mmi, (n - i) - 1, ii + 1, mpc4_B.tau, A, ii + 17,
                  mpc4_B.work_m);
      A[ii] = mpc4_B.b_atmp;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_xgeqp3(real_T A[1072], int32_T m, int32_T n, int32_T jpvt[67],
  real_T tau[16])
{
  int32_T b_temp_tmp;
  int32_T c_ix;
  int32_T i;
  int32_T idxmax;
  int32_T temp_tmp;
  if (m <= n) {
    mpc4_B.minmn_b = m;
  } else {
    mpc4_B.minmn_b = n;
  }

  memset(&tau[0], 0, sizeof(real_T) << 4U);
  if (mpc4_B.minmn_b < 1) {
    for (mpc4_B.minmn_b = 0; mpc4_B.minmn_b < n; mpc4_B.minmn_b++) {
      jpvt[mpc4_B.minmn_b] = mpc4_B.minmn_b + 1;
    }
  } else {
    mpc4_B.nfxd = -1;
    for (i = 0; i < n; i++) {
      if (jpvt[i] != 0) {
        mpc4_B.nfxd++;
        if (i + 1 != mpc4_B.nfxd + 1) {
          mpc4_B.ix_j = i << 4;
          mpc4_B.iy = mpc4_B.nfxd << 4;
          for (mpc4_B.mmi = 0; mpc4_B.mmi < m; mpc4_B.mmi++) {
            temp_tmp = mpc4_B.ix_j + mpc4_B.mmi;
            mpc4_B.temp_g = A[temp_tmp];
            mpc4_B.itemp = mpc4_B.iy + mpc4_B.mmi;
            A[temp_tmp] = A[mpc4_B.itemp];
            A[mpc4_B.itemp] = mpc4_B.temp_g;
          }

          jpvt[i] = jpvt[mpc4_B.nfxd];
          jpvt[mpc4_B.nfxd] = i + 1;
        } else {
          jpvt[i] = i + 1;
        }
      } else {
        jpvt[i] = i + 1;
      }
    }

    if (mpc4_B.nfxd + 1 <= mpc4_B.minmn_b) {
      mpc4_B.nfxd++;
    } else {
      mpc4_B.nfxd = mpc4_B.minmn_b;
    }

    memset(&tau[0], 0, sizeof(real_T) << 4U);
    mpc4_qrf(A, 1, m, n, mpc4_B.nfxd, tau);
    if (mpc4_B.nfxd < mpc4_B.minmn_b) {
      memset(&mpc4_B.work[0], 0, 67U * sizeof(real_T));
      memset(&mpc4_B.vn1[0], 0, 67U * sizeof(real_T));
      memset(&mpc4_B.vn2[0], 0, 67U * sizeof(real_T));
      for (i = mpc4_B.nfxd + 1; i <= n; i++) {
        mpc4_B.temp_g = mpc4_xnrm2(m - mpc4_B.nfxd, A, (((i - 1) << 4) +
          mpc4_B.nfxd) + 1);
        mpc4_B.vn1[i - 1] = mpc4_B.temp_g;
        mpc4_B.vn2[i - 1] = mpc4_B.temp_g;
      }

      for (i = mpc4_B.nfxd + 1; i <= mpc4_B.minmn_b; i++) {
        temp_tmp = (i - 1) << 4;
        mpc4_B.ix_j = (temp_tmp + i) - 1;
        mpc4_B.iy = (n - i) + 1;
        mpc4_B.mmi = m - i;
        if (mpc4_B.iy < 1) {
          idxmax = -2;
        } else {
          idxmax = -1;
          if (mpc4_B.iy > 1) {
            mpc4_B.temp_g = fabs(mpc4_B.vn1[i - 1]);
            for (mpc4_B.itemp = 2; mpc4_B.itemp <= mpc4_B.iy; mpc4_B.itemp++) {
              mpc4_B.s = fabs(mpc4_B.vn1[(i + mpc4_B.itemp) - 2]);
              if (mpc4_B.s > mpc4_B.temp_g) {
                idxmax = mpc4_B.itemp - 2;
                mpc4_B.temp_g = mpc4_B.s;
              }
            }
          }
        }

        mpc4_B.pvt = i + idxmax;
        if (mpc4_B.pvt + 1 != i) {
          c_ix = mpc4_B.pvt << 4;
          for (idxmax = 0; idxmax < m; idxmax++) {
            b_temp_tmp = c_ix + idxmax;
            mpc4_B.temp_g = A[b_temp_tmp];
            mpc4_B.itemp = temp_tmp + idxmax;
            A[b_temp_tmp] = A[mpc4_B.itemp];
            A[mpc4_B.itemp] = mpc4_B.temp_g;
          }

          mpc4_B.itemp = jpvt[mpc4_B.pvt];
          jpvt[mpc4_B.pvt] = jpvt[i - 1];
          jpvt[i - 1] = mpc4_B.itemp;
          mpc4_B.vn1[mpc4_B.pvt] = mpc4_B.vn1[i - 1];
          mpc4_B.vn2[mpc4_B.pvt] = mpc4_B.vn2[i - 1];
        }

        if (i < m) {
          mpc4_B.s = A[mpc4_B.ix_j];
          mpc4_B.temp_g = mpc4_xzlarfg(mpc4_B.mmi + 1, &mpc4_B.s, A, mpc4_B.ix_j
            + 2);
          tau[i - 1] = mpc4_B.temp_g;
          A[mpc4_B.ix_j] = mpc4_B.s;
        } else {
          mpc4_B.temp_g = 0.0;
          tau[i - 1] = 0.0;
        }

        if (i < n) {
          mpc4_B.s = A[mpc4_B.ix_j];
          A[mpc4_B.ix_j] = 1.0;
          mpc4_xzlarf(mpc4_B.mmi + 1, mpc4_B.iy - 1, mpc4_B.ix_j + 1,
                      mpc4_B.temp_g, A, mpc4_B.ix_j + 17, mpc4_B.work);
          A[mpc4_B.ix_j] = mpc4_B.s;
        }

        for (mpc4_B.itemp = i + 1; mpc4_B.itemp <= n; mpc4_B.itemp++) {
          mpc4_B.ix_j = ((mpc4_B.itemp - 1) << 4) + i;
          mpc4_B.temp_g = mpc4_B.vn1[mpc4_B.itemp - 1];
          if (mpc4_B.temp_g != 0.0) {
            mpc4_B.s = fabs(A[mpc4_B.ix_j - 1]) / mpc4_B.temp_g;
            mpc4_B.s = 1.0 - mpc4_B.s * mpc4_B.s;
            if (mpc4_B.s < 0.0) {
              mpc4_B.s = 0.0;
            }

            mpc4_B.temp2 = mpc4_B.temp_g / mpc4_B.vn2[mpc4_B.itemp - 1];
            mpc4_B.temp2 = mpc4_B.temp2 * mpc4_B.temp2 * mpc4_B.s;
            if (mpc4_B.temp2 <= 1.4901161193847656E-8) {
              if (i < m) {
                mpc4_B.temp_g = mpc4_xnrm2(mpc4_B.mmi, A, mpc4_B.ix_j + 1);
                mpc4_B.vn1[mpc4_B.itemp - 1] = mpc4_B.temp_g;
                mpc4_B.vn2[mpc4_B.itemp - 1] = mpc4_B.temp_g;
              } else {
                mpc4_B.vn1[mpc4_B.itemp - 1] = 0.0;
                mpc4_B.vn2[mpc4_B.itemp - 1] = 0.0;
              }
            } else {
              mpc4_B.vn1[mpc4_B.itemp - 1] = mpc4_B.temp_g * sqrt(mpc4_B.s);
            }
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_computeQ_(ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *obj, int32_T nrows)
{
  int32_T b_k;
  int32_T i;
  int32_T iQR0;
  int32_T iaii;
  int32_T idx;
  i = obj->minRowCol;
  for (idx = 0; idx < i; idx++) {
    iQR0 = obj->ldq * idx + idx;
    iaii = obj->mrows - idx;
    if (iaii - 2 >= 0) {
      memcpy(&obj->Q[iQR0 + 1], &obj->QR[iQR0 + 1], static_cast<uint32_T>(iaii -
              1) * sizeof(real_T));
    }
  }

  idx = obj->mrows;
  b_k = obj->ldq;
  if (nrows >= 1) {
    int32_T ia;
    for (iQR0 = i; iQR0 < nrows; iQR0++) {
      ia = iQR0 * b_k;
      if (idx - 1 >= 0) {
        memset(&obj->Q[ia], 0, static_cast<uint32_T>(idx) * sizeof(real_T));
      }

      obj->Q[ia + iQR0] = 1.0;
    }

    iQR0 = obj->minRowCol - 1;
    memset(&mpc4_B.work_c[0], 0, sizeof(real_T) << 4U);
    for (i = obj->minRowCol; i >= 1; i--) {
      int32_T jA;
      iaii = ((i - 1) * b_k + i) - 1;
      if (i < nrows) {
        int32_T c_ia;
        int32_T coltop;
        int32_T lastc;
        obj->Q[iaii] = 1.0;
        lastc = idx - i;
        jA = (iaii + b_k) + 1;
        if (obj->tau[iQR0] != 0.0) {
          boolean_T exitg2;
          ia = lastc + 1;
          lastc += iaii;
          while ((ia > 0) && (obj->Q[lastc] == 0.0)) {
            ia--;
            lastc--;
          }

          lastc = nrows - i;
          exitg2 = false;
          while ((!exitg2) && (lastc > 0)) {
            int32_T exitg1;
            coltop = (lastc - 1) * b_k + jA;
            c_ia = coltop;
            do {
              exitg1 = 0;
              if (c_ia <= (coltop + ia) - 1) {
                if (obj->Q[c_ia - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  c_ia++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          lastc--;
        } else {
          ia = 0;
          lastc = -1;
        }

        if (ia > 0) {
          int32_T iy;
          if (lastc + 1 != 0) {
            int32_T e;
            if (lastc >= 0) {
              memset(&mpc4_B.work_c[0], 0, static_cast<uint32_T>(lastc + 1) *
                     sizeof(real_T));
            }

            iy = 0;
            e = b_k * lastc + jA;
            for (coltop = jA; b_k < 0 ? coltop >= e : coltop <= e; coltop += b_k)
            {
              int32_T f;
              mpc4_B.b_c = 0.0;
              f = coltop + ia;
              for (c_ia = coltop; c_ia < f; c_ia++) {
                mpc4_B.b_c += obj->Q[(iaii + c_ia) - coltop] * obj->Q[c_ia - 1];
              }

              mpc4_B.work_c[iy] += mpc4_B.b_c;
              iy++;
            }
          }

          if (!(-obj->tau[iQR0] == 0.0)) {
            for (coltop = 0; coltop <= lastc; coltop++) {
              mpc4_B.b_c = mpc4_B.work_c[coltop];
              if (mpc4_B.b_c != 0.0) {
                mpc4_B.b_c *= -obj->tau[iQR0];
                iy = ia + jA;
                for (c_ia = jA; c_ia < iy; c_ia++) {
                  obj->Q[c_ia - 1] += obj->Q[(iaii + c_ia) - jA] * mpc4_B.b_c;
                }
              }

              jA += b_k;
            }
          }
        }
      }

      if (i < idx) {
        jA = ((iaii + idx) - i) + 1;
        for (ia = iaii + 2; ia <= jA; ia++) {
          obj->Q[ia - 1] *= -obj->tau[iQR0];
        }
      }

      obj->Q[iaii] = 1.0 - obj->tau[iQR0];
      for (ia = 0; ia <= i - 2; ia++) {
        obj->Q[(iaii - ia) - 1] = 0.0;
      }

      iQR0--;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static int32_T mpc4_ComputeNumDependentEq_(ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T
  *qrmanager, const real_T beqf[67], int32_T mConstr, int32_T nVar)
{
  int32_T numDependent;
  boolean_T exitg1;
  numDependent = mConstr - nVar;
  if (numDependent <= 0) {
    numDependent = 0;
  }

  if (nVar - 1 >= 0) {
    memset(&qrmanager->jpvt[0], 0, static_cast<uint32_T>(nVar) * sizeof(int32_T));
  }

  if (mConstr * nVar == 0) {
    qrmanager->mrows = mConstr;
    qrmanager->ncols = nVar;
    qrmanager->minRowCol = 0;
  } else {
    qrmanager->usedPivoting = true;
    qrmanager->mrows = mConstr;
    qrmanager->ncols = nVar;
    if (mConstr <= nVar) {
      qrmanager->minRowCol = mConstr;
    } else {
      qrmanager->minRowCol = nVar;
    }

    mpc4_xgeqp3(qrmanager->QR, mConstr, nVar, qrmanager->jpvt, qrmanager->tau);
  }

  if (mConstr >= nVar) {
    mpc4_B.totalRank = mConstr;
  } else {
    mpc4_B.totalRank = nVar;
  }

  mpc4_B.tol = 2.2204460492503131E-15 * static_cast<real_T>(mpc4_B.totalRank);
  if (mpc4_B.tol >= 1.4901161193847656E-8) {
    mpc4_B.tol = 1.4901161193847656E-8;
  }

  if (nVar <= mConstr) {
    mpc4_B.totalRank = nVar;
  } else {
    mpc4_B.totalRank = mConstr;
  }

  mpc4_B.totalRank += (mpc4_B.totalRank - 1) * qrmanager->ldq;
  while ((mpc4_B.totalRank > 0) && (fabs(qrmanager->QR[mpc4_B.totalRank - 1]) <=
          mpc4_B.tol * fabs(qrmanager->QR[0]))) {
    mpc4_B.totalRank = (mpc4_B.totalRank - qrmanager->ldq) - 1;
    numDependent++;
  }

  if (numDependent > 0) {
    mpc4_computeQ_(qrmanager, qrmanager->mrows);
    mpc4_B.b_idx = 0;
    exitg1 = false;
    while ((!exitg1) && (mpc4_B.b_idx <= numDependent - 1)) {
      mpc4_B.qtb = 0.0;
      if (mConstr >= 1) {
        mpc4_B.ix_p = ((mConstr - mpc4_B.b_idx) - 1) * qrmanager->ldq;
        for (mpc4_B.totalRank = 0; mpc4_B.totalRank < mConstr; mpc4_B.totalRank
             ++) {
          mpc4_B.qtb += qrmanager->Q[mpc4_B.ix_p + mpc4_B.totalRank] *
            beqf[mpc4_B.totalRank];
        }
      }

      if (fabs(mpc4_B.qtb) >= mpc4_B.tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        mpc4_B.b_idx++;
      }
    }
  }

  return numDependent;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_IndexOfDependentEq_(int32_T depIdx[67], int32_T mFixed, int32_T
  nDep, ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, int32_T mRows, int32_T nCols)
{
  for (mpc4_B.idx = 0; mpc4_B.idx < mFixed; mpc4_B.idx++) {
    qrmanager->jpvt[mpc4_B.idx] = 1;
  }

  if (mFixed + 1 <= nCols) {
    memset(&qrmanager->jpvt[mFixed], 0, static_cast<uint32_T>(nCols - mFixed) *
           sizeof(int32_T));
  }

  if (mRows * nCols == 0) {
    qrmanager->mrows = mRows;
    qrmanager->ncols = nCols;
    qrmanager->minRowCol = 0;
  } else {
    qrmanager->usedPivoting = true;
    qrmanager->mrows = mRows;
    qrmanager->ncols = nCols;
    if (mRows <= nCols) {
      qrmanager->minRowCol = mRows;
    } else {
      qrmanager->minRowCol = nCols;
    }

    mpc4_xgeqp3(qrmanager->QR, mRows, nCols, qrmanager->jpvt, qrmanager->tau);
  }

  for (mpc4_B.idx = 0; mpc4_B.idx < nDep; mpc4_B.idx++) {
    depIdx[mpc4_B.idx] = qrmanager->jpvt[(nCols - nDep) + mpc4_B.idx];
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_countsort(int32_T x[67], int32_T xLen, int32_T workspace[67],
  int32_T xMin, int32_T xMax)
{
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T b;
    int32_T idxEnd;
    int32_T idxFill;
    int32_T idxStart;
    int32_T maxOffset;
    b = xMax - xMin;
    if (b >= 0) {
      memset(&workspace[0], 0, static_cast<uint32_T>(b + 1) * sizeof(int32_T));
    }

    maxOffset = b - 1;
    for (b = 0; b < xLen; b++) {
      idxFill = x[b] - xMin;
      workspace[idxFill]++;
    }

    for (b = 2; b <= maxOffset + 2; b++) {
      workspace[b - 1] += workspace[b - 2];
    }

    idxStart = 1;
    idxEnd = workspace[0];
    for (b = 0; b <= maxOffset; b++) {
      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        x[idxFill - 1] = b + xMin;
      }

      idxStart = workspace[b] + 1;
      idxEnd = workspace[b + 1];
    }

    for (maxOffset = idxStart; maxOffset <= idxEnd; maxOffset++) {
      x[maxOffset - 1] = xMax;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_removeConstr(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj, int32_T
  idx_global)
{
  int32_T TYPE;
  TYPE = obj->Wid[idx_global - 1] - 1;
  obj->isActiveConstr[(obj->isActiveIdx[obj->Wid[idx_global - 1] - 1] +
                       obj->Wlocalidx[idx_global - 1]) - 2] = false;
  if (idx_global < obj->nActiveConstr) {
    int32_T b;
    obj->Wid[idx_global - 1] = obj->Wid[obj->nActiveConstr - 1];
    obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[obj->nActiveConstr - 1];
    b = obj->nVar;
    for (int32_T idx = 0; idx < b; idx++) {
      obj->ATwset[idx + obj->ldA * (idx_global - 1)] = obj->ATwset
        [(obj->nActiveConstr - 1) * obj->ldA + idx];
    }

    obj->bwset[idx_global - 1] = obj->bwset[obj->nActiveConstr - 1];
  }

  obj->nActiveConstr--;
  obj->nWConstr[TYPE]--;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_removeEqConstr(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj, int32_T
  idx_global)
{
  int32_T TYPE;
  int32_T b;
  int32_T idx;
  int32_T totalEq;
  totalEq = (obj->nWConstr[0] + obj->nWConstr[1]) - 1;
  if ((totalEq + 1 != 0) && (idx_global <= totalEq + 1)) {
    if ((totalEq + 1 == obj->nActiveConstr) || (totalEq + 1 == idx_global)) {
      obj->mEqRemoved++;
      mpc4_removeConstr(obj, idx_global);
    } else {
      obj->mEqRemoved++;
      TYPE = obj->Wid[idx_global - 1] - 1;
      obj->isActiveConstr[(obj->isActiveIdx[obj->Wid[idx_global - 1] - 1] +
                           obj->Wlocalidx[idx_global - 1]) - 2] = false;
      obj->Wid[idx_global - 1] = obj->Wid[totalEq];
      obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[totalEq];
      b = obj->nVar;
      for (idx = 0; idx < b; idx++) {
        obj->ATwset[idx + obj->ldA * (idx_global - 1)] = obj->ATwset[obj->ldA *
          totalEq + idx];
      }

      obj->bwset[idx_global - 1] = obj->bwset[totalEq];
      obj->Wid[totalEq] = obj->Wid[obj->nActiveConstr - 1];
      obj->Wlocalidx[totalEq] = obj->Wlocalidx[obj->nActiveConstr - 1];
      b = obj->nVar;
      for (idx = 0; idx < b; idx++) {
        obj->ATwset[idx + obj->ldA * totalEq] = obj->ATwset[(obj->nActiveConstr
          - 1) * obj->ldA + idx];
      }

      obj->bwset[totalEq] = obj->bwset[obj->nActiveConstr - 1];
      obj->nActiveConstr--;
      obj->nWConstr[TYPE]--;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_RemoveDependentIneq_(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, sFevNsrsl34D5b5aqm3qNjD_mpc4_T
  *memspace, real_T tolfactor)
{
  mpc4_B.nActiveConstr = workingset->nActiveConstr;
  mpc4_B.nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  mpc4_B.nVar_m = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    if (workingset->nVar >= workingset->nActiveConstr) {
      mpc4_B.b_idx_m = workingset->nVar;
    } else {
      mpc4_B.b_idx_m = workingset->nActiveConstr;
    }

    mpc4_B.u1 = 2.2204460492503131E-15 * static_cast<real_T>(mpc4_B.b_idx_m);
    if (mpc4_B.u1 >= 1.4901161193847656E-8) {
      mpc4_B.u1 = 1.4901161193847656E-8;
    }

    mpc4_B.tol_m = tolfactor * mpc4_B.u1;
    for (mpc4_B.b_idx_m = 0; mpc4_B.b_idx_m < mpc4_B.nFixedConstr;
         mpc4_B.b_idx_m++) {
      qrmanager->jpvt[mpc4_B.b_idx_m] = 1;
    }

    if (mpc4_B.nFixedConstr + 1 <= mpc4_B.nActiveConstr) {
      memset(&qrmanager->jpvt[mpc4_B.nFixedConstr], 0, static_cast<uint32_T>
             (mpc4_B.nActiveConstr - mpc4_B.nFixedConstr) * sizeof(int32_T));
    }

    for (mpc4_B.b_idx_m = 0; mpc4_B.b_idx_m < mpc4_B.nActiveConstr;
         mpc4_B.b_idx_m++) {
      mpc4_B.iy0_h = qrmanager->ldq * mpc4_B.b_idx_m;
      mpc4_B.ix0_ja = workingset->ldA * mpc4_B.b_idx_m;
      for (mpc4_B.b_k = 0; mpc4_B.b_k < mpc4_B.nVar_m; mpc4_B.b_k++) {
        qrmanager->QR[mpc4_B.iy0_h + mpc4_B.b_k] = workingset->ATwset[mpc4_B.b_k
          + mpc4_B.ix0_ja];
      }
    }

    if (workingset->nVar * workingset->nActiveConstr == 0) {
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      if (workingset->nVar <= workingset->nActiveConstr) {
        qrmanager->minRowCol = workingset->nVar;
      } else {
        qrmanager->minRowCol = workingset->nActiveConstr;
      }

      mpc4_xgeqp3(qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
                  qrmanager->jpvt, qrmanager->tau);
    }

    mpc4_B.nActiveConstr = 0;
    mpc4_B.b_idx_m = workingset->nActiveConstr - 1;
    while (mpc4_B.b_idx_m + 1 > mpc4_B.nVar_m) {
      mpc4_B.nActiveConstr++;
      memspace->workspace_int[mpc4_B.nActiveConstr - 1] = qrmanager->
        jpvt[mpc4_B.b_idx_m];
      mpc4_B.b_idx_m--;
    }

    mpc4_B.maxDiag = fabs(qrmanager->QR[0]);
    for (mpc4_B.nVar_m = 0; mpc4_B.nVar_m < mpc4_B.b_idx_m; mpc4_B.nVar_m++) {
      mpc4_B.u1 = fabs(qrmanager->QR[((mpc4_B.nVar_m + 1) * qrmanager->ldq +
        mpc4_B.nVar_m) + 1]);
      if ((!(mpc4_B.maxDiag >= mpc4_B.u1)) && (!rtIsNaN(mpc4_B.u1))) {
        mpc4_B.maxDiag = mpc4_B.u1;
      }
    }

    if (mpc4_B.b_idx_m + 1 <= workingset->nVar) {
      mpc4_B.nVar_m = qrmanager->ldq * mpc4_B.b_idx_m + mpc4_B.b_idx_m;
      while ((mpc4_B.b_idx_m + 1 > mpc4_B.nFixedConstr) && (fabs(qrmanager->
               QR[mpc4_B.nVar_m]) < mpc4_B.tol_m * mpc4_B.maxDiag)) {
        mpc4_B.nActiveConstr++;
        memspace->workspace_int[mpc4_B.nActiveConstr - 1] = qrmanager->
          jpvt[mpc4_B.b_idx_m];
        mpc4_B.b_idx_m--;
        mpc4_B.nVar_m = (mpc4_B.nVar_m - qrmanager->ldq) - 1;
      }
    }

    mpc4_countsort(memspace->workspace_int, mpc4_B.nActiveConstr,
                   memspace->workspace_sort, mpc4_B.nFixedConstr + 1,
                   workingset->nActiveConstr);
    for (mpc4_B.nFixedConstr = mpc4_B.nActiveConstr; mpc4_B.nFixedConstr >= 1;
         mpc4_B.nFixedConstr--) {
      mpc4_removeConstr(workingset, memspace->workspace_int[mpc4_B.nFixedConstr
                        - 1]);
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static int32_T mpc4_rank(const real_T qrmanager_QR[1072], int32_T
  qrmanager_mrows, int32_T qrmanager_ncols)
{
  int32_T minmn;
  int32_T r;
  r = 0;
  if (qrmanager_mrows <= qrmanager_ncols) {
    minmn = qrmanager_mrows;
  } else {
    minmn = qrmanager_ncols;
  }

  if (minmn > 0) {
    real_T tol;
    int32_T tmp;
    if (qrmanager_mrows >= qrmanager_ncols) {
      tmp = qrmanager_mrows;
    } else {
      tmp = qrmanager_ncols;
    }

    tol = 2.2204460492503131E-15 * static_cast<real_T>(tmp);
    if (tol >= 1.4901161193847656E-8) {
      tol = 1.4901161193847656E-8;
    }

    tol *= fabs(qrmanager_QR[0]);
    while ((r < minmn) && (!(fabs(qrmanager_QR[(r << 4) + r]) <= tol))) {
      r++;
    }
  }

  return r;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_xgemv(int32_T m, int32_T n, const real_T A[1056], int32_T lda,
  const real_T x[1072], real_T y[67])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T iy;
    for (int32_T b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = -y[b_iy];
    }

    iy = 0;
    b = (n - 1) * lda + 1;
    for (int32_T b_iy = 1; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (int32_T ia = b_iy; ia < d; ia++) {
        c += A[ia - 1] * x[ia - b_iy];
      }

      y[iy] += c;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static real_T mpc4_maxConstraintViolation(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj,
  const real_T x[1072])
{
  real_T u1;
  real_T v;
  int32_T k;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    mIneq = obj->sizes[2];
    if (mIneq - 1 >= 0) {
      memcpy(&obj->maxConstrWorkspace[0], &obj->bineq[0], static_cast<uint32_T>
             (mIneq) * sizeof(real_T));
    }

    mpc4_xgemv(obj->nVarOrig, obj->sizes[2], obj->Aineq, obj->ldA, x,
               obj->maxConstrWorkspace);
    for (k = 0; k < mIneq; k++) {
      obj->maxConstrWorkspace[k] -= x[obj->nVarOrig + k];
      u1 = obj->maxConstrWorkspace[k];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  } else {
    v = 0.0;
    mIneq = obj->sizes[2];
    if (mIneq - 1 >= 0) {
      memcpy(&obj->maxConstrWorkspace[0], &obj->bineq[0], static_cast<uint32_T>
             (mIneq) * sizeof(real_T));
    }

    mpc4_xgemv(obj->nVar, obj->sizes[2], obj->Aineq, obj->ldA, x,
               obj->maxConstrWorkspace);
    for (k = 0; k < mIneq; k++) {
      u1 = obj->maxConstrWorkspace[k];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[3] > 0) {
    for (mIneq = 0; mIneq < mLB; mIneq++) {
      u1 = -x[obj->indexLB[mIneq] - 1] - obj->lb[obj->indexLB[mIneq] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[4] > 0) {
    for (mLB = 0; mLB < mUB; mLB++) {
      u1 = x[obj->indexUB[mLB] - 1] - obj->ub[obj->indexUB[mLB] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[0] > 0) {
    for (mUB = 0; mUB < mFixed; mUB++) {
      u1 = fabs(x[obj->indexFixed[mUB] - 1] - obj->ub[obj->indexFixed[mUB] - 1]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  return v;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_xgemv_j(int32_T m, int32_T n, const real_T A[1056], int32_T lda,
  const real_T x[1072], real_T y[67])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T iy;
    for (int32_T b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = -y[b_iy];
    }

    iy = 0;
    b = (n - 1) * lda + 1;
    for (int32_T b_iy = 1; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (int32_T ia = b_iy; ia < d; ia++) {
        c += x[(ia - b_iy) + 67] * A[ia - 1];
      }

      y[iy] += c;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static real_T mpc4_maxConstraintViolation_n(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj,
  const real_T x[1072])
{
  real_T u1;
  real_T v;
  int32_T k;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    mIneq = obj->sizes[2];
    if (mIneq - 1 >= 0) {
      memcpy(&obj->maxConstrWorkspace[0], &obj->bineq[0], static_cast<uint32_T>
             (mIneq) * sizeof(real_T));
    }

    mpc4_xgemv_j(obj->nVarOrig, obj->sizes[2], obj->Aineq, obj->ldA, x,
                 obj->maxConstrWorkspace);
    for (k = 0; k < mIneq; k++) {
      obj->maxConstrWorkspace[k] -= x[(obj->nVarOrig + k) + 67];
      u1 = obj->maxConstrWorkspace[k];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  } else {
    v = 0.0;
    mIneq = obj->sizes[2];
    if (mIneq - 1 >= 0) {
      memcpy(&obj->maxConstrWorkspace[0], &obj->bineq[0], static_cast<uint32_T>
             (mIneq) * sizeof(real_T));
    }

    mpc4_xgemv_j(obj->nVar, obj->sizes[2], obj->Aineq, obj->ldA, x,
                 obj->maxConstrWorkspace);
    for (k = 0; k < mIneq; k++) {
      u1 = obj->maxConstrWorkspace[k];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[3] > 0) {
    for (mIneq = 0; mIneq < mLB; mIneq++) {
      u1 = -x[obj->indexLB[mIneq] + 66] - obj->lb[obj->indexLB[mIneq] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[4] > 0) {
    for (mLB = 0; mLB < mUB; mLB++) {
      u1 = x[obj->indexUB[mLB] + 66] - obj->ub[obj->indexUB[mLB] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[0] > 0) {
    for (mUB = 0; mUB < mFixed; mUB++) {
      u1 = fabs(x[obj->indexFixed[mUB] + 66] - obj->ub[obj->indexFixed[mUB] - 1]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  return v;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static boolean_T mpc4_feasibleX0ForWorkingSet(real_T workspace[1072], real_T
  xCurrent[16], sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager)
{
  int32_T exitg1;
  boolean_T guard1;
  boolean_T nonDegenerateWset;
  mpc4_B.mWConstr = workingset->nActiveConstr;
  mpc4_B.nVar_d = workingset->nVar - 1;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    if (workingset->nActiveConstr >= workingset->nVar) {
      for (mpc4_B.rankQR = 0; mpc4_B.rankQR <= mpc4_B.nVar_d; mpc4_B.rankQR++) {
        mpc4_B.offsetQR = qrmanager->ldq * mpc4_B.rankQR;
        for (mpc4_B.ldq = 0; mpc4_B.ldq < mpc4_B.mWConstr; mpc4_B.ldq++) {
          qrmanager->QR[mpc4_B.ldq + mpc4_B.offsetQR] = workingset->
            ATwset[workingset->ldA * mpc4_B.ldq + mpc4_B.rankQR];
        }

        qrmanager->jpvt[mpc4_B.rankQR] = 0;
      }

      if (workingset->nActiveConstr * workingset->nVar == 0) {
        qrmanager->mrows = workingset->nActiveConstr;
        qrmanager->ncols = workingset->nVar;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nActiveConstr;
        qrmanager->ncols = workingset->nVar;
        if (workingset->nActiveConstr <= workingset->nVar) {
          qrmanager->minRowCol = workingset->nActiveConstr;
        } else {
          qrmanager->minRowCol = workingset->nVar;
        }

        mpc4_xgeqp3(qrmanager->QR, workingset->nActiveConstr, workingset->nVar,
                    qrmanager->jpvt, qrmanager->tau);
      }

      mpc4_computeQ_(qrmanager, qrmanager->mrows);
      mpc4_B.rankQR = mpc4_rank(qrmanager->QR, qrmanager->mrows,
        qrmanager->ncols);
      for (mpc4_B.ldq = 0; mpc4_B.ldq < mpc4_B.mWConstr; mpc4_B.ldq++) {
        workspace[mpc4_B.ldq] = workingset->bwset[mpc4_B.ldq];
        workspace[mpc4_B.ldq + 67] = workingset->bwset[mpc4_B.ldq];
      }

      mpc4_B.ix = workingset->ldA;
      if ((workingset->nVar != 0) && (workingset->nActiveConstr != 0)) {
        mpc4_B.jBcol = 0;
        mpc4_B.iAcol = (workingset->nActiveConstr - 1) * workingset->ldA + 1;
        for (mpc4_B.ldq = 1; mpc4_B.ix < 0 ? mpc4_B.ldq >= mpc4_B.iAcol :
             mpc4_B.ldq <= mpc4_B.iAcol; mpc4_B.ldq += mpc4_B.ix) {
          mpc4_B.temp = 0.0;
          mpc4_B.b_ar = mpc4_B.ldq + mpc4_B.nVar_d;
          for (mpc4_B.offsetQR = mpc4_B.ldq; mpc4_B.offsetQR <= mpc4_B.b_ar;
               mpc4_B.offsetQR++) {
            mpc4_B.temp += workingset->ATwset[mpc4_B.offsetQR - 1] *
              xCurrent[mpc4_B.offsetQR - mpc4_B.ldq];
          }

          workspace[mpc4_B.jBcol] -= mpc4_B.temp;
          mpc4_B.jBcol++;
        }
      }

      mpc4_B.ldq = qrmanager->ldq;
      memcpy(&mpc4_B.B[0], &workspace[0], 1072U * sizeof(real_T));
      if (workingset->nVar != 0) {
        mpc4_B.iAcol = -1;
        for (mpc4_B.offsetQR = 0; mpc4_B.offsetQR <= 67; mpc4_B.offsetQR += 67)
        {
          mpc4_B.jBcol = (mpc4_B.offsetQR + mpc4_B.nVar_d) + 1;
          for (mpc4_B.ix = mpc4_B.offsetQR + 1; mpc4_B.ix <= mpc4_B.jBcol;
               mpc4_B.ix++) {
            workspace[mpc4_B.ix - 1] = 0.0;
          }
        }

        for (mpc4_B.offsetQR = 0; mpc4_B.offsetQR <= 67; mpc4_B.offsetQR += 67)
        {
          mpc4_B.b_ar = -1;
          mpc4_B.d_e = (mpc4_B.offsetQR + mpc4_B.nVar_d) + 1;
          for (mpc4_B.ix = mpc4_B.offsetQR + 1; mpc4_B.ix <= mpc4_B.d_e;
               mpc4_B.ix++) {
            mpc4_B.temp = 0.0;
            for (mpc4_B.jBcol = 0; mpc4_B.jBcol < mpc4_B.mWConstr; mpc4_B.jBcol
                 ++) {
              mpc4_B.temp += qrmanager->Q[(mpc4_B.jBcol + mpc4_B.b_ar) + 1] *
                mpc4_B.B[(mpc4_B.jBcol + mpc4_B.iAcol) + 1];
            }

            workspace[mpc4_B.ix - 1] += mpc4_B.temp;
            mpc4_B.b_ar += mpc4_B.ldq;
          }

          mpc4_B.iAcol += 67;
        }
      }

      for (mpc4_B.mWConstr = 0; mpc4_B.mWConstr < 2; mpc4_B.mWConstr++) {
        mpc4_B.iAcol = 67 * mpc4_B.mWConstr - 1;
        for (mpc4_B.ix = mpc4_B.rankQR; mpc4_B.ix >= 1; mpc4_B.ix--) {
          mpc4_B.b_ar = (mpc4_B.ix - 1) * mpc4_B.ldq;
          mpc4_B.offsetQR = mpc4_B.ix + mpc4_B.iAcol;
          mpc4_B.temp = workspace[mpc4_B.offsetQR];
          if (mpc4_B.temp != 0.0) {
            workspace[mpc4_B.offsetQR] = mpc4_B.temp / qrmanager->QR[(mpc4_B.ix
              + mpc4_B.b_ar) - 1];
            for (mpc4_B.jBcol = 0; mpc4_B.jBcol <= mpc4_B.ix - 2; mpc4_B.jBcol++)
            {
              mpc4_B.d_e = (mpc4_B.jBcol + mpc4_B.iAcol) + 1;
              workspace[mpc4_B.d_e] -= qrmanager->QR[mpc4_B.jBcol + mpc4_B.b_ar]
                * workspace[mpc4_B.offsetQR];
            }
          }
        }
      }

      for (mpc4_B.ldq = mpc4_B.rankQR + 1; mpc4_B.ldq <= mpc4_B.nVar_d + 1;
           mpc4_B.ldq++) {
        workspace[mpc4_B.ldq - 1] = 0.0;
        workspace[mpc4_B.ldq + 66] = 0.0;
      }

      for (mpc4_B.rankQR = 0; mpc4_B.rankQR <= mpc4_B.nVar_d; mpc4_B.rankQR++) {
        workspace[qrmanager->jpvt[mpc4_B.rankQR] + 133] =
          workspace[mpc4_B.rankQR];
      }

      for (mpc4_B.rankQR = 0; mpc4_B.rankQR <= mpc4_B.nVar_d; mpc4_B.rankQR++) {
        workspace[mpc4_B.rankQR] = workspace[mpc4_B.rankQR + 134];
      }

      for (mpc4_B.rankQR = 0; mpc4_B.rankQR <= mpc4_B.nVar_d; mpc4_B.rankQR++) {
        workspace[qrmanager->jpvt[mpc4_B.rankQR] + 133] =
          workspace[mpc4_B.rankQR + 67];
      }

      for (mpc4_B.rankQR = 0; mpc4_B.rankQR <= mpc4_B.nVar_d; mpc4_B.rankQR++) {
        workspace[mpc4_B.rankQR + 67] = workspace[mpc4_B.rankQR + 134];
      }
    } else {
      if (mpc4_B.mWConstr - 1 >= 0) {
        memset(&qrmanager->jpvt[0], 0, static_cast<uint32_T>(mpc4_B.mWConstr) *
               sizeof(int32_T));
      }

      mpc4_B.offsetQR = workingset->nVar * workingset->nActiveConstr;
      guard1 = false;
      if (mpc4_B.offsetQR > 0) {
        for (mpc4_B.rankQR = 0; mpc4_B.rankQR < mpc4_B.mWConstr; mpc4_B.rankQR++)
        {
          mpc4_B.offsetQR = workingset->ldA * mpc4_B.rankQR;
          mpc4_B.ix = qrmanager->ldq * mpc4_B.rankQR;
          for (mpc4_B.ldq = 0; mpc4_B.ldq <= mpc4_B.nVar_d; mpc4_B.ldq++) {
            qrmanager->QR[mpc4_B.ix + mpc4_B.ldq] = workingset->
              ATwset[mpc4_B.offsetQR + mpc4_B.ldq];
          }
        }

        guard1 = true;
      } else if (mpc4_B.offsetQR == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = workingset->nActiveConstr;
        qrmanager->minRowCol = 0;
      } else {
        guard1 = true;
      }

      if (guard1) {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = workingset->nActiveConstr;
        if (workingset->nVar <= workingset->nActiveConstr) {
          qrmanager->minRowCol = workingset->nVar;
        } else {
          qrmanager->minRowCol = workingset->nActiveConstr;
        }

        mpc4_xgeqp3(qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
                    qrmanager->jpvt, qrmanager->tau);
      }

      mpc4_computeQ_(qrmanager, qrmanager->minRowCol);
      mpc4_B.rankQR = mpc4_rank(qrmanager->QR, qrmanager->mrows,
        qrmanager->ncols);
      for (mpc4_B.ldq = 0; mpc4_B.ldq < mpc4_B.mWConstr; mpc4_B.ldq++) {
        mpc4_B.temp = 0.0;
        if (mpc4_B.nVar_d + 1 >= 1) {
          mpc4_B.ix = (qrmanager->jpvt[mpc4_B.ldq] - 1) * workingset->ldA;
          for (mpc4_B.offsetQR = 0; mpc4_B.offsetQR <= mpc4_B.nVar_d;
               mpc4_B.offsetQR++) {
            mpc4_B.temp += workingset->ATwset[mpc4_B.ix + mpc4_B.offsetQR] *
              xCurrent[mpc4_B.offsetQR];
          }
        }

        workspace[mpc4_B.ldq] = workingset->bwset[qrmanager->jpvt[mpc4_B.ldq] -
          1] - mpc4_B.temp;
        workspace[mpc4_B.ldq + 67] = workingset->bwset[qrmanager->
          jpvt[mpc4_B.ldq] - 1];
      }

      mpc4_B.ldq = qrmanager->ldq;
      for (mpc4_B.mWConstr = 0; mpc4_B.mWConstr < 2; mpc4_B.mWConstr++) {
        mpc4_B.jBcol = 67 * mpc4_B.mWConstr;
        for (mpc4_B.offsetQR = 0; mpc4_B.offsetQR < mpc4_B.rankQR;
             mpc4_B.offsetQR++) {
          mpc4_B.iAcol = mpc4_B.ldq * mpc4_B.offsetQR;
          mpc4_B.b_ar = mpc4_B.offsetQR + mpc4_B.jBcol;
          mpc4_B.temp = workspace[mpc4_B.b_ar];
          for (mpc4_B.ix = 0; mpc4_B.ix < mpc4_B.offsetQR; mpc4_B.ix++) {
            mpc4_B.temp -= qrmanager->QR[mpc4_B.ix + mpc4_B.iAcol] *
              workspace[mpc4_B.ix + mpc4_B.jBcol];
          }

          workspace[mpc4_B.b_ar] = mpc4_B.temp / qrmanager->QR[mpc4_B.offsetQR +
            mpc4_B.iAcol];
        }
      }

      memcpy(&mpc4_B.B[0], &workspace[0], 1072U * sizeof(real_T));
      if (workingset->nVar != 0) {
        mpc4_B.jBcol = 1;
        for (mpc4_B.mWConstr = 0; mpc4_B.mWConstr <= 67; mpc4_B.mWConstr += 67)
        {
          mpc4_B.ix = (mpc4_B.mWConstr + mpc4_B.nVar_d) + 1;
          for (mpc4_B.offsetQR = mpc4_B.mWConstr + 1; mpc4_B.offsetQR <=
               mpc4_B.ix; mpc4_B.offsetQR++) {
            workspace[mpc4_B.offsetQR - 1] = 0.0;
          }
        }

        for (mpc4_B.mWConstr = 0; mpc4_B.mWConstr <= 67; mpc4_B.mWConstr += 67)
        {
          mpc4_B.iAcol = -1;
          mpc4_B.b_ar = mpc4_B.jBcol + mpc4_B.rankQR;
          for (mpc4_B.offsetQR = mpc4_B.jBcol; mpc4_B.offsetQR < mpc4_B.b_ar;
               mpc4_B.offsetQR++) {
            mpc4_B.d_e = (mpc4_B.mWConstr + mpc4_B.nVar_d) + 1;
            for (mpc4_B.ix = mpc4_B.mWConstr + 1; mpc4_B.ix <= mpc4_B.d_e;
                 mpc4_B.ix++) {
              workspace[mpc4_B.ix - 1] += qrmanager->Q[(mpc4_B.iAcol + mpc4_B.ix)
                - mpc4_B.mWConstr] * mpc4_B.B[mpc4_B.offsetQR - 1];
            }

            mpc4_B.iAcol += mpc4_B.ldq;
          }

          mpc4_B.jBcol += 67;
        }
      }
    }

    mpc4_B.rankQR = 0;
    do {
      exitg1 = 0;
      if (mpc4_B.rankQR <= mpc4_B.nVar_d) {
        if (rtIsInf(workspace[mpc4_B.rankQR]) || rtIsNaN(workspace[mpc4_B.rankQR]))
        {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else if (rtIsInf(workspace[mpc4_B.rankQR + 67]) || rtIsNaN
                   (workspace[mpc4_B.rankQR + 67])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          mpc4_B.rankQR++;
        }
      } else {
        if (mpc4_B.nVar_d >= 0) {
          for (mpc4_B.rankQR = 0; mpc4_B.rankQR <= mpc4_B.nVar_d; mpc4_B.rankQR
               ++) {
            workspace[mpc4_B.rankQR] += xCurrent[mpc4_B.rankQR];
          }
        }

        mpc4_B.temp = mpc4_maxConstraintViolation(workingset, workspace);
        mpc4_B.constrViolation_basicX = mpc4_maxConstraintViolation_n(workingset,
          workspace);
        if ((mpc4_B.temp <= 2.2204460492503131E-16) || (mpc4_B.temp <
             mpc4_B.constrViolation_basicX)) {
          if (mpc4_B.nVar_d >= 0) {
            memcpy(&xCurrent[0], &workspace[0], static_cast<uint32_T>
                   (mpc4_B.nVar_d + 1) * sizeof(real_T));
          }
        } else if (mpc4_B.nVar_d >= 0) {
          memcpy(&xCurrent[0], &workspace[67], static_cast<uint32_T>
                 (mpc4_B.nVar_d + 1) * sizeof(real_T));
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_xgemv_j3(int32_T m, int32_T n, const real_T A[1056], int32_T
  lda, const real_T x[16], real_T y[67])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T iy;
    for (int32_T b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = -y[b_iy];
    }

    iy = 0;
    b = (n - 1) * lda + 1;
    for (int32_T b_iy = 1; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (int32_T ia = b_iy; ia < d; ia++) {
        c += A[ia - 1] * x[ia - b_iy];
      }

      y[iy] += c;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static real_T mpc4_maxConstraintViolation_n3(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj,
  const real_T x[16])
{
  real_T u1;
  real_T v;
  int32_T k;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    mIneq = obj->sizes[2];
    if (mIneq - 1 >= 0) {
      memcpy(&obj->maxConstrWorkspace[0], &obj->bineq[0], static_cast<uint32_T>
             (mIneq) * sizeof(real_T));
    }

    mpc4_xgemv_j3(obj->nVarOrig, obj->sizes[2], obj->Aineq, obj->ldA, x,
                  obj->maxConstrWorkspace);
    for (k = 0; k < mIneq; k++) {
      obj->maxConstrWorkspace[k] -= x[obj->nVarOrig + k];
      u1 = obj->maxConstrWorkspace[k];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  } else {
    v = 0.0;
    mIneq = obj->sizes[2];
    if (mIneq - 1 >= 0) {
      memcpy(&obj->maxConstrWorkspace[0], &obj->bineq[0], static_cast<uint32_T>
             (mIneq) * sizeof(real_T));
    }

    mpc4_xgemv_j3(obj->nVar, obj->sizes[2], obj->Aineq, obj->ldA, x,
                  obj->maxConstrWorkspace);
    for (k = 0; k < mIneq; k++) {
      u1 = obj->maxConstrWorkspace[k];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[3] > 0) {
    for (mIneq = 0; mIneq < mLB; mIneq++) {
      u1 = -x[obj->indexLB[mIneq] - 1] - obj->lb[obj->indexLB[mIneq] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[4] > 0) {
    for (mLB = 0; mLB < mUB; mLB++) {
      u1 = x[obj->indexUB[mLB] - 1] - obj->ub[obj->indexUB[mLB] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[0] > 0) {
    for (mUB = 0; mUB < mFixed; mUB++) {
      u1 = fabs(x[obj->indexFixed[mUB] - 1] - obj->ub[obj->indexFixed[mUB] - 1]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  return v;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_PresolveWorkingSet(sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution,
  sFevNsrsl34D5b5aqm3qNjD_mpc4_T *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T
  *workingset, const sqZVQFgLZG74FDpCArykMHB_mpc4_T *options,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager)
{
  boolean_T guard1;
  boolean_T okWorkingSet;
  solution->state = 82;
  qrmanager->ldq = 16;
  memset(&qrmanager->QR[0], 0, 1072U * sizeof(real_T));
  memset(&qrmanager->Q[0], 0, sizeof(real_T) << 8U);
  memset(&qrmanager->jpvt[0], 0, 67U * sizeof(int32_T));
  qrmanager->mrows = 0;
  qrmanager->ncols = 0;
  memset(&qrmanager->tau[0], 0, sizeof(real_T) << 4U);
  qrmanager->minRowCol = 0;
  qrmanager->usedPivoting = false;
  mpc4_B.nVar_o = workingset->nVar;
  mpc4_B.mTotalWorkingEq_n = workingset->nWConstr[0] + workingset->nWConstr[1];
  mpc4_B.nDepInd_i = 0;
  if (mpc4_B.mTotalWorkingEq_n > 0) {
    for (mpc4_B.i_c = 0; mpc4_B.i_c < mpc4_B.mTotalWorkingEq_n; mpc4_B.i_c++) {
      for (mpc4_B.idxStartIneq_o = 0; mpc4_B.idxStartIneq_o < mpc4_B.nVar_o;
           mpc4_B.idxStartIneq_o++) {
        qrmanager->QR[mpc4_B.i_c + (mpc4_B.idxStartIneq_o << 4)] =
          workingset->ATwset[workingset->ldA * mpc4_B.i_c +
          mpc4_B.idxStartIneq_o];
      }
    }

    mpc4_B.nDepInd_i = mpc4_ComputeNumDependentEq_(qrmanager, workingset->bwset,
      mpc4_B.mTotalWorkingEq_n, workingset->nVar);
    if (mpc4_B.nDepInd_i > 0) {
      for (mpc4_B.i_c = 0; mpc4_B.i_c < mpc4_B.mTotalWorkingEq_n; mpc4_B.i_c++)
      {
        mpc4_B.iy0_m = qrmanager->ldq * mpc4_B.i_c;
        mpc4_B.ix0_n = workingset->ldA * mpc4_B.i_c;
        for (mpc4_B.idxStartIneq_o = 0; mpc4_B.idxStartIneq_o < mpc4_B.nVar_o;
             mpc4_B.idxStartIneq_o++) {
          qrmanager->QR[mpc4_B.iy0_m + mpc4_B.idxStartIneq_o] =
            workingset->ATwset[mpc4_B.idxStartIneq_o + mpc4_B.ix0_n];
        }
      }

      mpc4_IndexOfDependentEq_(memspace->workspace_int, workingset->nWConstr[0],
        mpc4_B.nDepInd_i, qrmanager, workingset->nVar, mpc4_B.mTotalWorkingEq_n);
      mpc4_countsort(memspace->workspace_int, mpc4_B.nDepInd_i,
                     memspace->workspace_sort, 1, mpc4_B.mTotalWorkingEq_n);
      for (mpc4_B.i_c = mpc4_B.nDepInd_i; mpc4_B.i_c >= 1; mpc4_B.i_c--) {
        mpc4_removeEqConstr(workingset, memspace->workspace_int[mpc4_B.i_c - 1]);
      }
    }
  }

  if ((mpc4_B.nDepInd_i != -1) && (workingset->nActiveConstr <= qrmanager->ldq))
  {
    mpc4_RemoveDependentIneq_(workingset, qrmanager, memspace, 1.0);
    okWorkingSet = mpc4_feasibleX0ForWorkingSet(memspace->workspace_float,
      solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      mpc4_RemoveDependentIneq_(workingset, qrmanager, memspace, 10.0);
      okWorkingSet = mpc4_feasibleX0ForWorkingSet(memspace->workspace_float,
        solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        mpc4_B.constrViolation_g = mpc4_maxConstraintViolation_n3(workingset,
          solution->xstar);
        if (mpc4_B.constrViolation_g > options->ConstraintTolerance) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    mpc4_B.idxStartIneq_o = (workingset->nWConstr[0] + workingset->nWConstr[1])
      + 1;
    mpc4_B.nVar_o = workingset->nActiveConstr;
    for (mpc4_B.i_c = mpc4_B.idxStartIneq_o; mpc4_B.i_c <= mpc4_B.nVar_o;
         mpc4_B.i_c++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[mpc4_B.i_c - 1] - 1] + workingset->Wlocalidx[mpc4_B.i_c - 1]) - 2] =
        false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_modifyOverheadPhaseOne_(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj)
{
  int32_T idxEq;
  int32_T idxStartIneq;
  idxStartIneq = obj->sizes[0];
  for (int32_T idx = 0; idx < idxStartIneq; idx++) {
    obj->ATwset[(obj->nVar + obj->ldA * idx) - 1] = 0.0;
  }

  idxStartIneq = obj->sizes[1];
  for (int32_T idx = 0; idx < idxStartIneq; idx++) {
    obj->ATwset[((obj->ldA * idx + obj->nVar) + obj->ldA * (obj->isActiveIdx[1]
      - 1)) - 1] = 0.0;
  }

  idxStartIneq = obj->sizes[2];
  for (int32_T idx = 0; idx < idxStartIneq; idx++) {
    obj->Aineq[(obj->nVar + obj->ldA * idx) - 1] = -1.0;
  }

  obj->indexLB[obj->sizes[3] - 1] = obj->nVar;
  obj->lb[obj->nVar - 1] = obj->SLACK0;
  idxStartIneq = obj->isActiveIdx[2];
  idxEq = obj->nActiveConstr;
  for (int32_T idx = idxStartIneq; idx <= idxEq; idx++) {
    obj->ATwset[(obj->nVar + obj->ldA * (idx - 1)) - 1] = -1.0;
  }

  idxStartIneq = obj->isActiveIdx[4] - 1;
  if (obj->nWConstr[4] > 0) {
    idxEq = obj->sizesNormal[4];
    for (int32_T idx = idxEq; idx >= 1; idx--) {
      int32_T tmp;
      tmp = idxStartIneq + idx;
      obj->isActiveConstr[tmp] = obj->isActiveConstr[tmp - 1];
    }
  } else {
    obj->isActiveConstr[(obj->isActiveIdx[4] + obj->sizesNormal[4]) - 1] = false;
  }

  obj->isActiveConstr[obj->isActiveIdx[4] - 1] = false;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_setProblemType(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj, int32_T
  PROBLEM_TYPE)
{
  int32_T c;
  int32_T colOffsetATw;
  int32_T colOffsetAineq;
  int32_T idxUpperExisting;
  int32_T mIneq;
  int32_T offsetEq1;
  int32_T offsetEq2;
  int32_T offsetIneq;
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = obj->nVarOrig;
    obj->mConstr = obj->mConstrOrig;
    if (obj->nWConstr[4] > 0) {
      idxUpperExisting = obj->isActiveIdx[4] - 2;
      offsetEq1 = obj->sizesNormal[4];
      for (colOffsetATw = 0; colOffsetATw < offsetEq1; colOffsetATw++) {
        offsetIneq = (colOffsetATw + idxUpperExisting) + 1;
        obj->isActiveConstr[(obj->isActiveIdxNormal[4] + colOffsetATw) - 1] =
          obj->isActiveConstr[offsetIneq];
        obj->isActiveConstr[offsetIneq] = false;
      }
    }

    for (offsetIneq = 0; offsetIneq < 5; offsetIneq++) {
      obj->sizes[offsetIneq] = obj->sizesNormal[offsetIneq];
    }

    for (offsetIneq = 0; offsetIneq < 6; offsetIneq++) {
      obj->isActiveIdx[offsetIneq] = obj->isActiveIdxNormal[offsetIneq];
    }
    break;

   case 1:
    obj->nVar = obj->nVarOrig + 1;
    obj->mConstr = obj->mConstrOrig + 1;
    for (offsetIneq = 0; offsetIneq < 5; offsetIneq++) {
      obj->sizes[offsetIneq] = obj->sizesPhaseOne[offsetIneq];
    }

    mpc4_modifyOverheadPhaseOne_(obj);
    for (offsetIneq = 0; offsetIneq < 6; offsetIneq++) {
      obj->isActiveIdx[offsetIneq] = obj->isActiveIdxPhaseOne[offsetIneq];
    }
    break;

   case 2:
    obj->nVar = obj->nVarMax - 1;
    obj->mConstr = obj->mConstrMax - 1;
    for (offsetIneq = 0; offsetIneq < 5; offsetIneq++) {
      obj->sizes[offsetIneq] = obj->sizesRegularized[offsetIneq];
    }

    if (obj->probType != 4) {
      mIneq = obj->sizes[2];
      idxUpperExisting = obj->sizes[1];
      offsetIneq = obj->nVarOrig + 1;
      offsetEq1 = obj->nVarOrig + obj->sizes[2];
      offsetEq2 = (obj->nVarOrig + obj->sizes[2]) + obj->sizes[1];
      c = obj->sizes[0];
      for (colOffsetAineq = 0; colOffsetAineq < c; colOffsetAineq++) {
        colOffsetATw = obj->ldA * colOffsetAineq;
        if (obj->nVarOrig + 1 <= obj->nVar) {
          memset(&obj->ATwset[((obj->nVarOrig + 1) + colOffsetATw) + -1], 0,
                 static_cast<uint32_T>((((obj->nVar + colOffsetATw) -
                    (obj->nVarOrig + 1)) - colOffsetATw) + 1) * sizeof(real_T));
        }
      }

      for (colOffsetATw = 0; colOffsetATw < mIneq; colOffsetATw++) {
        colOffsetAineq = obj->ldA * colOffsetATw - 1;
        c = offsetIneq + colOffsetATw;
        if (offsetIneq <= c - 1) {
          memset(&obj->Aineq[offsetIneq + colOffsetAineq], 0,
                 static_cast<uint32_T>(((c + colOffsetAineq) - offsetIneq) -
                  colOffsetAineq) * sizeof(real_T));
        }

        obj->Aineq[c + colOffsetAineq] = -1.0;
        c++;
        if (c <= obj->nVar) {
          memset(&obj->Aineq[c + colOffsetAineq], 0, static_cast<uint32_T>
                 ((((obj->nVar + colOffsetAineq) - c) - colOffsetAineq) + 1) *
                 sizeof(real_T));
        }
      }

      for (mIneq = 0; mIneq < idxUpperExisting; mIneq++) {
        colOffsetATw = ((obj->isActiveIdx[1] - 1) + mIneq) * obj->ldA - 1;
        if (offsetIneq <= offsetEq1) {
          memset(&obj->ATwset[offsetIneq + colOffsetATw], 0,
                 static_cast<uint32_T>((((offsetEq1 + colOffsetATw) - offsetIneq)
                   - colOffsetATw) + 1) * sizeof(real_T));
        }

        c = mIneq + offsetEq1;
        if (offsetEq1 + 1 <= (c + 1) - 1) {
          memset(&obj->ATwset[(offsetEq1 + colOffsetATw) + 1], 0,
                 static_cast<uint32_T>(((((c + 1) + colOffsetATw) - offsetEq1) -
                   colOffsetATw) - 1) * sizeof(real_T));
        }

        obj->ATwset[(c + colOffsetATw) + 1] = -1.0;
        c += 2;
        if (c <= offsetEq2) {
          memset(&obj->ATwset[c + colOffsetATw], 0, static_cast<uint32_T>
                 ((((offsetEq2 + colOffsetATw) - c) - colOffsetATw) + 1) *
                 sizeof(real_T));
        }

        c = mIneq + offsetEq2;
        if (offsetEq2 + 1 <= (c + 1) - 1) {
          memset(&obj->ATwset[(offsetEq2 + colOffsetATw) + 1], 0,
                 static_cast<uint32_T>(((((c + 1) + colOffsetATw) - offsetEq2) -
                   colOffsetATw) - 1) * sizeof(real_T));
        }

        obj->ATwset[(c + colOffsetATw) + 1] = 1.0;
        c += 2;
        if (c <= obj->nVar) {
          memset(&obj->ATwset[c + colOffsetATw], 0, static_cast<uint32_T>
                 ((((obj->nVar + colOffsetATw) - c) - colOffsetATw) + 1) *
                 sizeof(real_T));
        }
      }

      idxUpperExisting = obj->nVarOrig;
      offsetEq1 = obj->sizesNormal[3] + 1;
      offsetEq2 = obj->sizesRegularized[3];
      for (colOffsetATw = offsetEq1; colOffsetATw <= offsetEq2; colOffsetATw++)
      {
        idxUpperExisting++;
        obj->indexLB[colOffsetATw - 1] = idxUpperExisting;
      }

      if (obj->nWConstr[4] > 0) {
        idxUpperExisting = obj->sizesRegularized[4];
        for (colOffsetATw = 0; colOffsetATw < idxUpperExisting; colOffsetATw++)
        {
          obj->isActiveConstr[obj->isActiveIdxRegularized[4] + colOffsetATw] =
            obj->isActiveConstr[(obj->isActiveIdx[4] + colOffsetATw) - 1];
        }
      }

      idxUpperExisting = obj->isActiveIdx[4];
      offsetEq1 = obj->isActiveIdxRegularized[4];
      if (idxUpperExisting <= offsetEq1 - 1) {
        memset(&obj->isActiveConstr[idxUpperExisting + -1], 0, static_cast<
               uint32_T>(offsetEq1 - idxUpperExisting) * sizeof(boolean_T));
      }

      offsetEq1 = (obj->nVarOrig + obj->sizes[2]) + (obj->sizes[1] << 1);
      if (obj->nVarOrig + 1 <= offsetEq1) {
        memset(&obj->lb[(obj->nVarOrig + 1) + -1], 0, static_cast<uint32_T>
               ((offsetEq1 - (obj->nVarOrig + 1)) + 1) * sizeof(real_T));
      }

      offsetEq1 = obj->isActiveIdx[2];
      offsetEq2 = obj->nActiveConstr;
      for (idxUpperExisting = offsetEq1; idxUpperExisting <= offsetEq2;
           idxUpperExisting++) {
        colOffsetATw = (idxUpperExisting - 1) * obj->ldA - 1;
        if (obj->Wid[idxUpperExisting - 1] == 3) {
          colOffsetAineq = (obj->Wlocalidx[idxUpperExisting - 1] + offsetIneq) -
            2;
          if (offsetIneq <= colOffsetAineq) {
            memset(&obj->ATwset[offsetIneq + colOffsetATw], 0,
                   static_cast<uint32_T>((((colOffsetAineq + colOffsetATw) -
                      offsetIneq) - colOffsetATw) + 1) * sizeof(real_T));
          }

          obj->ATwset[((offsetIneq + obj->Wlocalidx[idxUpperExisting - 1]) +
                       colOffsetATw) - 1] = -1.0;
          colOffsetAineq = obj->Wlocalidx[idxUpperExisting - 1] + offsetIneq;
          if (colOffsetAineq <= obj->nVar) {
            memset(&obj->ATwset[colOffsetAineq + colOffsetATw], 0,
                   static_cast<uint32_T>((((obj->nVar + colOffsetATw) -
                      colOffsetAineq) - colOffsetATw) + 1) * sizeof(real_T));
          }
        } else if (offsetIneq <= obj->nVar) {
          memset(&obj->ATwset[offsetIneq + colOffsetATw], 0,
                 static_cast<uint32_T>((((obj->nVar + colOffsetATw) - offsetIneq)
                   - colOffsetATw) + 1) * sizeof(real_T));
        }
      }
    }

    for (offsetIneq = 0; offsetIneq < 6; offsetIneq++) {
      obj->isActiveIdx[offsetIneq] = obj->isActiveIdxRegularized[offsetIneq];
    }
    break;

   default:
    obj->nVar = obj->nVarMax;
    obj->mConstr = obj->mConstrMax;
    for (offsetIneq = 0; offsetIneq < 5; offsetIneq++) {
      obj->sizes[offsetIneq] = obj->sizesRegPhaseOne[offsetIneq];
    }

    mpc4_modifyOverheadPhaseOne_(obj);
    for (offsetIneq = 0; offsetIneq < 6; offsetIneq++) {
      obj->isActiveIdx[offsetIneq] = obj->isActiveIdxRegPhaseOne[offsetIneq];
    }
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_xgemv_j30(int32_T m, int32_T n, const real_T A[225], int32_T
  lda, const real_T x[16], real_T y[15])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T ix;
    if (m - 1 >= 0) {
      memset(&y[0], 0, static_cast<uint32_T>(m) * sizeof(real_T));
    }

    ix = 0;
    b = (n - 1) * lda + 1;
    for (int32_T b_iy = 1; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      int32_T c;
      c = b_iy + m;
      for (int32_T ia = b_iy; ia < c; ia++) {
        int32_T tmp;
        tmp = ia - b_iy;
        y[tmp] += A[ia - 1] * x[ix];
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_computeGrad_StoreHx(s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *obj, const
  real_T b_H[225], const real_T f[15], const real_T x[16])
{
  int32_T d;
  int32_T ixlast;
  int32_T maxRegVar;
  switch (obj->objtype) {
   case 5:
    if (obj->nvar - 2 >= 0) {
      memset(&obj->grad[0], 0, static_cast<uint32_T>(obj->nvar - 1) * sizeof
             (real_T));
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    mpc4_xgemv_j30(obj->nvar, obj->nvar, b_H, obj->nvar, x, obj->Hx);
    if (obj->nvar - 1 >= 0) {
      memcpy(&obj->grad[0], &obj->Hx[0], static_cast<uint32_T>(obj->nvar) *
             sizeof(real_T));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      ixlast = obj->nvar;
      for (maxRegVar = 0; maxRegVar < ixlast; maxRegVar++) {
        obj->grad[maxRegVar] += f[maxRegVar];
      }
    }
    break;

   case 4:
    maxRegVar = obj->maxVar - 1;
    mpc4_xgemv_j30(obj->nvar, obj->nvar, b_H, obj->nvar, x, obj->Hx);
    d = obj->nvar + 1;
    for (ixlast = d; ixlast <= maxRegVar; ixlast++) {
      obj->Hx[ixlast - 1] = x[ixlast - 1] * obj->beta;
    }

    if ((obj->maxVar - 1) - 1 >= 0) {
      memcpy(&obj->grad[0], &obj->Hx[0], static_cast<uint32_T>(obj->maxVar - 1) *
             sizeof(real_T));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      ixlast = obj->nvar;
      for (maxRegVar = 0; maxRegVar < ixlast; maxRegVar++) {
        obj->grad[maxRegVar] += f[maxRegVar];
      }
    }

    ixlast = (obj->maxVar - obj->nvar) - 1;
    if (ixlast >= 1) {
      for (maxRegVar = 0; maxRegVar < ixlast; maxRegVar++) {
        d = obj->nvar + maxRegVar;
        obj->grad[d] += obj->rho;
      }
    }
    break;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static real_T mpc4_computeFval_ReuseHx(const s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *obj,
  real_T workspace[1072], const real_T f[15], const real_T x[16])
{
  real_T val;
  val = 0.0;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    {
      if (obj->hasLinear) {
        int32_T ixlast;
        ixlast = obj->nvar;
        for (int32_T maxRegVar = 0; maxRegVar < ixlast; maxRegVar++) {
          workspace[maxRegVar] = 0.5 * obj->Hx[maxRegVar] + f[maxRegVar];
        }

        if (obj->nvar >= 1) {
          ixlast = obj->nvar;
          for (int32_T maxRegVar = 0; maxRegVar < ixlast; maxRegVar++) {
            val += x[maxRegVar] * workspace[maxRegVar];
          }
        }
      } else {
        if (obj->nvar >= 1) {
          int32_T ixlast;
          ixlast = obj->nvar;
          for (int32_T maxRegVar = 0; maxRegVar < ixlast; maxRegVar++) {
            val += x[maxRegVar] * obj->Hx[maxRegVar];
          }
        }

        val *= 0.5;
      }
    }
    break;

   case 4:
    {
      int32_T maxRegVar;
      maxRegVar = obj->maxVar - 1;
      if (obj->hasLinear) {
        int32_T b_ixlast;
        int32_T ixlast;
        if (obj->nvar - 1 >= 0) {
          memcpy(&workspace[0], &f[0], static_cast<uint32_T>(obj->nvar) * sizeof
                 (real_T));
        }

        b_ixlast = obj->maxVar - obj->nvar;
        for (ixlast = 0; ixlast <= b_ixlast - 2; ixlast++) {
          workspace[obj->nvar + ixlast] = obj->rho;
        }

        for (ixlast = 0; ixlast < maxRegVar; ixlast++) {
          workspace[ixlast] += 0.5 * obj->Hx[ixlast];
        }

        if (obj->maxVar - 1 >= 1) {
          ixlast = obj->maxVar;
          for (maxRegVar = 0; maxRegVar <= ixlast - 2; maxRegVar++) {
            val += x[maxRegVar] * workspace[maxRegVar];
          }
        }
      } else {
        int32_T b_ixlast;
        if (obj->maxVar - 1 >= 1) {
          b_ixlast = obj->maxVar;
          for (int32_T ixlast = 0; ixlast <= b_ixlast - 2; ixlast++) {
            val += x[ixlast] * obj->Hx[ixlast];
          }
        }

        val *= 0.5;
        b_ixlast = obj->nvar + 1;
        for (int32_T ixlast = b_ixlast; ixlast <= maxRegVar; ixlast++) {
          val += x[ixlast - 1] * obj->rho;
        }
      }
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  mpc4_B.roe = *b;
  mpc4_B.absa = fabs(*a);
  mpc4_B.absb = fabs(*b);
  if (mpc4_B.absa > mpc4_B.absb) {
    mpc4_B.roe = *a;
  }

  mpc4_B.scale_j = mpc4_B.absa + mpc4_B.absb;
  if (mpc4_B.scale_j == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = mpc4_B.absa / mpc4_B.scale_j;
    bds = mpc4_B.absb / mpc4_B.scale_j;
    mpc4_B.scale_j *= sqrt(ads * ads + bds * bds);
    if (mpc4_B.roe < 0.0) {
      mpc4_B.scale_j = -mpc4_B.scale_j;
    }

    *c = *a / mpc4_B.scale_j;
    *s = *b / mpc4_B.scale_j;
    if (mpc4_B.absa > mpc4_B.absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = mpc4_B.scale_j;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_squareQ_appendCol(ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *obj, const
  real_T vec[1072], int32_T iv0)
{
  real_T b_c;
  int32_T Qk0;
  int32_T b_iy;
  int32_T e;
  int32_T idx;
  int32_T iy;
  int32_T iyend;
  int32_T temp_tmp;
  if (obj->mrows <= obj->ncols + 1) {
    obj->minRowCol = obj->mrows;
  } else {
    obj->minRowCol = obj->ncols + 1;
  }

  b_iy = obj->ldq * obj->ncols;
  idx = obj->ldq;
  if (obj->mrows != 0) {
    iyend = b_iy + obj->mrows;
    if (b_iy + 1 <= iyend) {
      memset(&obj->QR[b_iy], 0, static_cast<uint32_T>(iyend - b_iy) * sizeof
             (real_T));
    }

    iy = (obj->mrows - 1) * obj->ldq + 1;
    for (Qk0 = 1; idx < 0 ? Qk0 >= iy : Qk0 <= iy; Qk0 += idx) {
      b_c = 0.0;
      e = Qk0 + obj->mrows;
      for (iyend = Qk0; iyend < e; iyend++) {
        b_c += vec[((iv0 + iyend) - Qk0) - 1] * obj->Q[iyend - 1];
      }

      obj->QR[b_iy] += b_c;
      b_iy++;
    }
  }

  obj->ncols++;
  obj->jpvt[obj->ncols - 1] = obj->ncols;
  for (idx = obj->mrows - 2; idx + 2 > obj->ncols; idx--) {
    b_iy = (obj->ncols - 1) * obj->ldq + idx;
    mpc4_B.temp_o = obj->QR[b_iy + 1];
    mpc4_xrotg(&obj->QR[b_iy], &mpc4_B.temp_o, &b_c, &mpc4_B.s_l);
    obj->QR[b_iy + 1] = mpc4_B.temp_o;
    Qk0 = obj->ldq * idx;
    iyend = obj->mrows;
    if (obj->mrows >= 1) {
      iy = obj->ldq + Qk0;
      for (b_iy = 0; b_iy < iyend; b_iy++) {
        e = iy + b_iy;
        temp_tmp = Qk0 + b_iy;
        mpc4_B.temp_o = obj->Q[temp_tmp] * b_c + obj->Q[e] * mpc4_B.s_l;
        obj->Q[e] = obj->Q[e] * b_c - obj->Q[temp_tmp] * mpc4_B.s_l;
        obj->Q[temp_tmp] = mpc4_B.temp_o;
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_deleteColMoveEnd(ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *obj, int32_T
  idx)
{
  int32_T QRk0;
  int32_T b_ix;
  int32_T b_n;
  int32_T c_temp_tmp;
  int32_T d_temp_tmp;
  int32_T i;
  int32_T idxRotGCol;
  int32_T ix;
  int32_T k;
  if (obj->usedPivoting) {
    i = 1;
    while ((i <= obj->ncols) && (obj->jpvt[i - 1] != idx)) {
      i++;
    }

    idx = i;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    QRk0 = obj->minRowCol;
    for (i = 0; i < QRk0; i++) {
      obj->QR[i + obj->ldq * (idx - 1)] = obj->QR[(obj->ncols - 1) * obj->ldq +
        i];
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      if (obj->mrows - 1 <= obj->ncols) {
        i = obj->mrows - 1;
      } else {
        i = obj->ncols;
      }

      k = i;
      idxRotGCol = (idx - 1) * obj->ldq;
      while (k >= idx) {
        QRk0 = k + idxRotGCol;
        mpc4_B.b_temp_l = obj->QR[QRk0];
        mpc4_xrotg(&obj->QR[QRk0 - 1], &mpc4_B.b_temp_l, &mpc4_B.c_c,
                   &mpc4_B.b_s);
        obj->QR[QRk0] = mpc4_B.b_temp_l;
        obj->QR[k + obj->ldq * (k - 1)] = 0.0;
        QRk0 = obj->ldq * idx + k;
        b_ix = obj->ncols - idx;
        if (b_ix >= 1) {
          ix = QRk0 - 1;
          for (b_n = 0; b_n < b_ix; b_n++) {
            mpc4_B.b_temp_l = mpc4_B.c_c * obj->QR[ix] + mpc4_B.b_s * obj->
              QR[QRk0];
            obj->QR[QRk0] = mpc4_B.c_c * obj->QR[QRk0] - mpc4_B.b_s * obj->QR[ix];
            obj->QR[ix] = mpc4_B.b_temp_l;
            QRk0 += obj->ldq;
            ix += obj->ldq;
          }
        }

        QRk0 = (k - 1) * obj->ldq;
        b_ix = obj->mrows;
        if (obj->mrows >= 1) {
          ix = obj->ldq + QRk0;
          for (b_n = 0; b_n < b_ix; b_n++) {
            d_temp_tmp = ix + b_n;
            c_temp_tmp = QRk0 + b_n;
            mpc4_B.b_temp_l = obj->Q[c_temp_tmp] * mpc4_B.c_c + obj->
              Q[d_temp_tmp] * mpc4_B.b_s;
            obj->Q[d_temp_tmp] = obj->Q[d_temp_tmp] * mpc4_B.c_c - obj->
              Q[c_temp_tmp] * mpc4_B.b_s;
            obj->Q[c_temp_tmp] = mpc4_B.b_temp_l;
          }
        }

        k--;
      }

      for (k = idx + 1; k <= i; k++) {
        QRk0 = (k - 1) * obj->ldq + k;
        mpc4_B.b_temp_l = obj->QR[QRk0];
        mpc4_xrotg(&obj->QR[QRk0 - 1], &mpc4_B.b_temp_l, &mpc4_B.c_c,
                   &mpc4_B.b_s);
        obj->QR[QRk0] = mpc4_B.b_temp_l;
        QRk0 = (obj->ldq + 1) * k;
        b_n = obj->ncols - k;
        if (b_n >= 1) {
          b_ix = QRk0 - 1;
          for (idxRotGCol = 0; idxRotGCol < b_n; idxRotGCol++) {
            mpc4_B.b_temp_l = mpc4_B.c_c * obj->QR[b_ix] + mpc4_B.b_s * obj->
              QR[QRk0];
            obj->QR[QRk0] = mpc4_B.c_c * obj->QR[QRk0] - mpc4_B.b_s * obj->
              QR[b_ix];
            obj->QR[b_ix] = mpc4_B.b_temp_l;
            QRk0 += obj->ldq;
            b_ix += obj->ldq;
          }
        }

        QRk0 = (k - 1) * obj->ldq;
        b_n = obj->mrows;
        if (obj->mrows >= 1) {
          b_ix = obj->ldq + QRk0;
          for (idxRotGCol = 0; idxRotGCol < b_n; idxRotGCol++) {
            ix = b_ix + idxRotGCol;
            d_temp_tmp = QRk0 + idxRotGCol;
            mpc4_B.b_temp_l = obj->Q[d_temp_tmp] * mpc4_B.c_c + obj->Q[ix] *
              mpc4_B.b_s;
            obj->Q[ix] = obj->Q[ix] * mpc4_B.c_c - obj->Q[d_temp_tmp] *
              mpc4_B.b_s;
            obj->Q[d_temp_tmp] = mpc4_B.b_temp_l;
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static int32_T mpc4_ixamax(int32_T n, const real_T x[256], int32_T incx)
{
  int32_T idxmax;
  if ((n < 1) || (incx < 1)) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      real_T smax;
      smax = fabs(x[0]);
      for (int32_T k = 2; k <= n; k++) {
        real_T s;
        s = fabs(x[(k - 1) * incx]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  return idxmax;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_fullColLDL2_(sOWFOmKuLvD2kpFwfdM45bG_mpc4_T *obj, int32_T
  LD_offset, int32_T NColsRemain, real_T REG_PRIMAL)
{
  int32_T LDimSizeP1;
  int32_T lastDiag;
  LDimSizeP1 = obj->ldm;
  for (lastDiag = 0; lastDiag < NColsRemain; lastDiag++) {
    int32_T LD_diagOffset;
    int32_T b_k;
    int32_T subMatrixDim;
    LD_diagOffset = ((LDimSizeP1 + 1) * lastDiag + LD_offset) - 1;
    if (fabs(obj->FMat[LD_diagOffset]) <= obj->regTol_) {
      obj->FMat[LD_diagOffset] += REG_PRIMAL;
    }

    mpc4_B.alpha1 = -1.0 / obj->FMat[LD_diagOffset];
    subMatrixDim = NColsRemain - lastDiag;
    for (b_k = 0; b_k <= subMatrixDim - 2; b_k++) {
      obj->workspace_[b_k] = obj->FMat[(LD_diagOffset + b_k) + 1];
    }

    if (!(mpc4_B.alpha1 == 0.0)) {
      int32_T jA;
      jA = (LD_diagOffset + LDimSizeP1) + 2;
      for (b_k = 0; b_k <= subMatrixDim - 2; b_k++) {
        mpc4_B.temp_p = obj->workspace_[b_k];
        if (mpc4_B.temp_p != 0.0) {
          int32_T b;
          mpc4_B.temp_p *= mpc4_B.alpha1;
          b = subMatrixDim + jA;
          for (int32_T ijA = jA; ijA <= b - 2; ijA++) {
            obj->FMat[ijA - 1] += obj->workspace_[ijA - jA] * mpc4_B.temp_p;
          }
        }

        jA += obj->ldm;
      }
    }

    mpc4_B.alpha1 = 1.0 / obj->FMat[LD_diagOffset];
    b_k = LD_diagOffset + subMatrixDim;
    for (subMatrixDim = LD_diagOffset + 2; subMatrixDim <= b_k; subMatrixDim++)
    {
      obj->FMat[subMatrixDim - 1] *= mpc4_B.alpha1;
    }
  }

  lastDiag = ((obj->ldm + 1) * (NColsRemain - 1) + LD_offset) - 1;
  if (fabs(obj->FMat[lastDiag]) <= obj->regTol_) {
    obj->FMat[lastDiag] += REG_PRIMAL;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_xgemv_j30b(int32_T m, int32_T n, const real_T A[256], int32_T
  ia0, int32_T lda, const real_T x[1072], real_T y[16])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T ix;
    if (m - 1 >= 0) {
      memset(&y[0], 0, static_cast<uint32_T>(m) * sizeof(real_T));
    }

    ix = 0;
    b = (n - 1) * lda + ia0;
    for (int32_T b_iy = ia0; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      int32_T c;
      c = b_iy + m;
      for (int32_T ia = b_iy; ia < c; ia++) {
        int32_T tmp;
        tmp = ia - b_iy;
        y[tmp] += A[ia - 1] * x[ix];
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_compute_deltax(const real_T b_H[225],
  sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpc4_T
  *memspace, const ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager,
  sOWFOmKuLvD2kpFwfdM45bG_mpc4_T *cholmanager, const
  s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *objective)
{
  int32_T b_jjA;
  int32_T c_ix;
  int32_T exitg1;
  int32_T g;
  int32_T h;
  int32_T i;
  int32_T ic;
  mpc4_B.nVar_c = qrmanager->mrows - 1;
  mpc4_B.mNull = qrmanager->mrows - qrmanager->ncols;
  if (mpc4_B.mNull <= 0) {
    if (mpc4_B.nVar_c >= 0) {
      memset(&solution->searchDir[0], 0, static_cast<uint32_T>(mpc4_B.nVar_c + 1)
             * sizeof(real_T));
    }
  } else {
    for (mpc4_B.b_idx_c = 0; mpc4_B.b_idx_c <= mpc4_B.nVar_c; mpc4_B.b_idx_c++)
    {
      solution->searchDir[mpc4_B.b_idx_c] = -objective->grad[mpc4_B.b_idx_c];
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        mpc4_B.b_SCALED_REG_PRIMAL = 1.4901161193847656E-8 *
          cholmanager->scaleFactor * static_cast<real_T>(qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        for (mpc4_B.mNull = 0; mpc4_B.mNull <= mpc4_B.nVar_c; mpc4_B.mNull++) {
          mpc4_B.nullStartIdx = (mpc4_B.nVar_c + 1) * mpc4_B.mNull;
          mpc4_B.nVars = cholmanager->ldm * mpc4_B.mNull;
          for (mpc4_B.b_idx_c = 0; mpc4_B.b_idx_c <= mpc4_B.nVar_c;
               mpc4_B.b_idx_c++) {
            cholmanager->FMat[mpc4_B.nVars + mpc4_B.b_idx_c] =
              b_H[mpc4_B.b_idx_c + mpc4_B.nullStartIdx];
          }
        }

        mpc4_B.mNull = mpc4_ixamax(qrmanager->mrows, cholmanager->FMat,
          cholmanager->ldm + 1) - 1;
        mpc4_B.b_temp = fabs(cholmanager->FMat[cholmanager->ldm * mpc4_B.mNull +
                             mpc4_B.mNull]) * 2.2204460492503131E-16;
        mpc4_B.u1_n = fabs(mpc4_B.b_SCALED_REG_PRIMAL);
        if ((mpc4_B.b_temp >= mpc4_B.u1_n) || rtIsNaN(mpc4_B.u1_n)) {
          cholmanager->regTol_ = mpc4_B.b_temp;
        } else {
          cholmanager->regTol_ = mpc4_B.u1_n;
        }

        mpc4_fullColLDL2_(cholmanager, 1, qrmanager->mrows,
                          mpc4_B.b_SCALED_REG_PRIMAL);
        if (cholmanager->ConvexCheck) {
          mpc4_B.mNull = 0;
          do {
            exitg1 = 0;
            if (mpc4_B.mNull <= mpc4_B.nVar_c) {
              if (cholmanager->FMat[cholmanager->ldm * mpc4_B.mNull +
                  mpc4_B.mNull] <= 0.0) {
                cholmanager->info = -mpc4_B.mNull - 1;
                exitg1 = 1;
              } else {
                mpc4_B.mNull++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          mpc4_B.nVar_c = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (mpc4_B.mNull = 0; mpc4_B.mNull < mpc4_B.nVar_c; mpc4_B.mNull++)
            {
              mpc4_B.nullStartIdx = mpc4_B.mNull * cholmanager->ldm +
                mpc4_B.mNull;
              mpc4_B.nVars = (mpc4_B.nVar_c - mpc4_B.mNull) - 2;
              for (mpc4_B.b_idx_c = 0; mpc4_B.b_idx_c <= mpc4_B.nVars;
                   mpc4_B.b_idx_c++) {
                b_jjA = (mpc4_B.b_idx_c + mpc4_B.mNull) + 1;
                solution->searchDir[b_jjA] -= cholmanager->FMat[(mpc4_B.b_idx_c
                  + mpc4_B.nullStartIdx) + 1] * solution->searchDir[mpc4_B.mNull];
              }
            }
          }

          mpc4_B.b_idx_c = cholmanager->ndims;
          for (mpc4_B.mNull = 0; mpc4_B.mNull < mpc4_B.b_idx_c; mpc4_B.mNull++)
          {
            solution->searchDir[mpc4_B.mNull] /= cholmanager->FMat
              [cholmanager->ldm * mpc4_B.mNull + mpc4_B.mNull];
          }

          mpc4_B.nVar_c = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (mpc4_B.mNull = mpc4_B.nVar_c; mpc4_B.mNull >= 1; mpc4_B.mNull--)
            {
              mpc4_B.nullStartIdx = (mpc4_B.mNull - 1) * cholmanager->ldm;
              mpc4_B.b_temp = solution->searchDir[mpc4_B.mNull - 1];
              for (mpc4_B.b_idx_c = mpc4_B.nVar_c; mpc4_B.b_idx_c >=
                   mpc4_B.mNull + 1; mpc4_B.b_idx_c--) {
                mpc4_B.b_temp -= cholmanager->FMat[(mpc4_B.nullStartIdx +
                  mpc4_B.b_idx_c) - 1] * solution->searchDir[mpc4_B.b_idx_c - 1];
              }

              solution->searchDir[mpc4_B.mNull - 1] = mpc4_B.b_temp;
            }
          }
        }
      }
    } else {
      mpc4_B.b_idx_c = qrmanager->ldq * qrmanager->ncols;
      mpc4_B.nullStartIdx = mpc4_B.b_idx_c + 1;
      if (objective->objtype == 5) {
        for (mpc4_B.nullStartIdx = 0; mpc4_B.nullStartIdx < mpc4_B.mNull;
             mpc4_B.nullStartIdx++) {
          memspace->workspace_float[mpc4_B.nullStartIdx] = -qrmanager->Q
            [(qrmanager->ncols + mpc4_B.nullStartIdx) * qrmanager->ldq +
            mpc4_B.nVar_c];
        }

        mpc4_xgemv_j30b(qrmanager->mrows, mpc4_B.mNull, qrmanager->Q,
                        mpc4_B.b_idx_c + 1, qrmanager->ldq,
                        memspace->workspace_float, solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          mpc4_B.nVars = qrmanager->mrows;
          b_jjA = cholmanager->ldm;
          mpc4_B.ldQ = qrmanager->ldq;
          if ((qrmanager->mrows != 0) && (mpc4_B.mNull != 0)) {
            mpc4_B.br = mpc4_B.b_idx_c;
            mpc4_B.lastColC = (mpc4_B.mNull - 1) * 67;
            for (c_ix = 0; c_ix <= mpc4_B.lastColC; c_ix += 67) {
              g = c_ix + mpc4_B.nVars;
              for (ic = c_ix + 1; ic <= g; ic++) {
                memspace->workspace_float[ic - 1] = 0.0;
              }
            }

            for (c_ix = 0; c_ix <= mpc4_B.lastColC; c_ix += 67) {
              mpc4_B.ar = -1;
              h = mpc4_B.br + mpc4_B.nVars;
              for (ic = mpc4_B.br + 1; ic <= h; ic++) {
                i = c_ix + mpc4_B.nVars;
                for (g = c_ix + 1; g <= i; g++) {
                  memspace->workspace_float[g - 1] += b_H[(mpc4_B.ar + g) - c_ix]
                    * qrmanager->Q[ic - 1];
                }

                mpc4_B.ar += mpc4_B.nVars;
              }

              mpc4_B.br += mpc4_B.ldQ;
            }
          }

          if (mpc4_B.mNull != 0) {
            mpc4_B.br = -1;
            mpc4_B.lastColC = (mpc4_B.mNull - 1) * cholmanager->ldm;
            for (c_ix = 0; b_jjA < 0 ? c_ix >= mpc4_B.lastColC : c_ix <=
                 mpc4_B.lastColC; c_ix += b_jjA) {
              g = c_ix + mpc4_B.mNull;
              for (ic = c_ix + 1; ic <= g; ic++) {
                cholmanager->FMat[ic - 1] = 0.0;
              }
            }

            for (c_ix = 0; b_jjA < 0 ? c_ix >= mpc4_B.lastColC : c_ix <=
                 mpc4_B.lastColC; c_ix += b_jjA) {
              mpc4_B.ar = mpc4_B.b_idx_c;
              h = c_ix + mpc4_B.mNull;
              for (ic = c_ix + 1; ic <= h; ic++) {
                mpc4_B.b_temp = 0.0;
                for (g = 0; g < mpc4_B.nVars; g++) {
                  mpc4_B.b_temp += memspace->workspace_float[(g + mpc4_B.br) + 1]
                    * qrmanager->Q[g + mpc4_B.ar];
                }

                cholmanager->FMat[ic - 1] += mpc4_B.b_temp;
                mpc4_B.ar += mpc4_B.ldQ;
              }

              mpc4_B.br += 67;
            }
          }
        }

        mpc4_B.b_SCALED_REG_PRIMAL = 1.4901161193847656E-8 *
          cholmanager->scaleFactor * static_cast<real_T>(mpc4_B.mNull);
        cholmanager->ndims = mpc4_B.mNull;
        mpc4_B.nVars = mpc4_ixamax(mpc4_B.mNull, cholmanager->FMat,
          cholmanager->ldm + 1) - 1;
        mpc4_B.b_temp = fabs(cholmanager->FMat[cholmanager->ldm * mpc4_B.nVars +
                             mpc4_B.nVars]) * 2.2204460492503131E-16;
        mpc4_B.u1_n = fabs(mpc4_B.b_SCALED_REG_PRIMAL);
        if ((mpc4_B.b_temp >= mpc4_B.u1_n) || rtIsNaN(mpc4_B.u1_n)) {
          cholmanager->regTol_ = mpc4_B.b_temp;
        } else {
          cholmanager->regTol_ = mpc4_B.u1_n;
        }

        mpc4_fullColLDL2_(cholmanager, 1, mpc4_B.mNull,
                          mpc4_B.b_SCALED_REG_PRIMAL);
        if (cholmanager->ConvexCheck) {
          mpc4_B.nVars = 0;
          do {
            exitg1 = 0;
            if (mpc4_B.nVars <= mpc4_B.mNull - 1) {
              if (cholmanager->FMat[cholmanager->ldm * mpc4_B.nVars +
                  mpc4_B.nVars] <= 0.0) {
                cholmanager->info = -mpc4_B.nVars - 1;
                exitg1 = 1;
              } else {
                mpc4_B.nVars++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          mpc4_B.ldQ = qrmanager->ldq;
          if (qrmanager->mrows != 0) {
            memset(&memspace->workspace_float[0], 0, static_cast<uint32_T>
                   (mpc4_B.mNull) * sizeof(real_T));
            c_ix = 0;
            ic = ((mpc4_B.mNull - 1) * qrmanager->ldq + mpc4_B.b_idx_c) + 1;
            for (mpc4_B.nVars = mpc4_B.nullStartIdx; mpc4_B.ldQ < 0 ?
                 mpc4_B.nVars >= ic : mpc4_B.nVars <= ic; mpc4_B.nVars +=
                 mpc4_B.ldQ) {
              mpc4_B.b_temp = 0.0;
              g = mpc4_B.nVars + mpc4_B.nVar_c;
              for (b_jjA = mpc4_B.nVars; b_jjA <= g; b_jjA++) {
                mpc4_B.b_temp += qrmanager->Q[b_jjA - 1] * objective->grad[b_jjA
                  - mpc4_B.nVars];
              }

              memspace->workspace_float[c_ix] -= mpc4_B.b_temp;
              c_ix++;
            }
          }

          mpc4_B.nVars = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (mpc4_B.nVar_c = 0; mpc4_B.nVar_c < mpc4_B.nVars; mpc4_B.nVar_c
                 ++) {
              b_jjA = mpc4_B.nVar_c * cholmanager->ldm + mpc4_B.nVar_c;
              mpc4_B.ldQ = (mpc4_B.nVars - mpc4_B.nVar_c) - 2;
              for (mpc4_B.nullStartIdx = 0; mpc4_B.nullStartIdx <= mpc4_B.ldQ;
                   mpc4_B.nullStartIdx++) {
                c_ix = (mpc4_B.nullStartIdx + mpc4_B.nVar_c) + 1;
                memspace->workspace_float[c_ix] -= cholmanager->FMat
                  [(mpc4_B.nullStartIdx + b_jjA) + 1] *
                  memspace->workspace_float[mpc4_B.nVar_c];
              }
            }
          }

          mpc4_B.nullStartIdx = cholmanager->ndims;
          for (mpc4_B.nVar_c = 0; mpc4_B.nVar_c < mpc4_B.nullStartIdx;
               mpc4_B.nVar_c++) {
            memspace->workspace_float[mpc4_B.nVar_c] /= cholmanager->
              FMat[cholmanager->ldm * mpc4_B.nVar_c + mpc4_B.nVar_c];
          }

          mpc4_B.nVars = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (mpc4_B.nVar_c = mpc4_B.nVars; mpc4_B.nVar_c >= 1; mpc4_B.nVar_c
                 --) {
              b_jjA = (mpc4_B.nVar_c - 1) * cholmanager->ldm;
              mpc4_B.b_temp = memspace->workspace_float[mpc4_B.nVar_c - 1];
              for (mpc4_B.nullStartIdx = mpc4_B.nVars; mpc4_B.nullStartIdx >=
                   mpc4_B.nVar_c + 1; mpc4_B.nullStartIdx--) {
                mpc4_B.b_temp -= cholmanager->FMat[(b_jjA + mpc4_B.nullStartIdx)
                  - 1] * memspace->workspace_float[mpc4_B.nullStartIdx - 1];
              }

              memspace->workspace_float[mpc4_B.nVar_c - 1] = mpc4_B.b_temp;
            }
          }

          mpc4_xgemv_j30b(qrmanager->mrows, mpc4_B.mNull, qrmanager->Q,
                          mpc4_B.b_idx_c + 1, qrmanager->ldq,
                          memspace->workspace_float, solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static real_T mpc4_xnrm2_l(int32_T n, const real_T x[16])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[0]);
    } else {
      real_T scale;
      scale = 3.3121686421112381E-170;
      for (int32_T k = 0; k < n; k++) {
        real_T absxk;
        absxk = fabs(x[k]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_xgemv_j30bu(int32_T m, int32_T n, const real_T A[1056], int32_T
  lda, const real_T x[16], real_T y[1072])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T iy;
    for (int32_T b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = -y[b_iy];
    }

    iy = 0;
    b = (n - 1) * lda + 1;
    for (int32_T b_iy = 1; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (int32_T ia = b_iy; ia < d; ia++) {
        c += A[ia - 1] * x[ia - b_iy];
      }

      y[iy] += c;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_xgemv_j30bul(int32_T m, int32_T n, const real_T A[1056],
  int32_T lda, const real_T x[16], real_T y[1072])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T iy;
    if (n + 67 >= 68) {
      memset(&y[67], 0, static_cast<uint32_T>(n) * sizeof(real_T));
    }

    iy = 67;
    b = (n - 1) * lda + 1;
    for (int32_T b_iy = 1; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      real_T c;
      int32_T d;
      c = 0.0;
      d = b_iy + m;
      for (int32_T ia = b_iy; ia < d; ia++) {
        c += A[ia - 1] * x[ia - b_iy];
      }

      y[iy] += c;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_ratiotest(const real_T solution_xstar[16], const real_T
  solution_searchDir[16], real_T workspace[1072], int32_T workingset_nVar,
  int32_T workingset_ldA, const real_T workingset_Aineq[1056], const real_T
  workingset_bineq[66], const real_T workingset_lb[16], const real_T
  workingset_ub[16], const int32_T workingset_indexLB[16], const int32_T
  workingset_indexUB[16], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[67],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T tolcon,
  real_T *toldelta, real_T *alpha, boolean_T *newBlocking, int32_T *constrType,
  int32_T *constrIdx)
{
  real_T workspace_0;
  int32_T k;
  int32_T totalIneq;
  int32_T totalUB;
  int32_T workingset_indexLB_0;
  mpc4_B.p_max = 0.0;
  totalIneq = workingset_sizes[2];
  totalUB = workingset_sizes[4];
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  mpc4_B.denomTol = 2.2204460492503131E-13 * mpc4_xnrm2_l(workingset_nVar,
    solution_searchDir);
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    if (totalIneq - 1 >= 0) {
      memcpy(&workspace[0], &workingset_bineq[0], static_cast<uint32_T>
             (totalIneq) * sizeof(real_T));
    }

    mpc4_xgemv_j30bu(workingset_nVar, workingset_sizes[2], workingset_Aineq,
                     workingset_ldA, solution_xstar, workspace);
    mpc4_xgemv_j30bul(workingset_nVar, workingset_sizes[2], workingset_Aineq,
                      workingset_ldA, solution_searchDir, workspace);
    for (k = 0; k < totalIneq; k++) {
      workspace_0 = workspace[k + 67];
      if ((workspace_0 > mpc4_B.denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[2] + k) - 1])) {
        mpc4_B.phaseOneCorrectionX = workspace[k];
        mpc4_B.alphaTemp = fabs(mpc4_B.phaseOneCorrectionX - *toldelta);
        mpc4_B.phaseOneCorrectionP = tolcon - mpc4_B.phaseOneCorrectionX;
        mpc4_B.ratio = mpc4_B.phaseOneCorrectionP + *toldelta;
        if ((mpc4_B.alphaTemp <= mpc4_B.ratio) || rtIsNaN(mpc4_B.ratio)) {
          mpc4_B.ratio = mpc4_B.alphaTemp;
        }

        mpc4_B.alphaTemp = mpc4_B.ratio / workspace_0;
        if ((mpc4_B.alphaTemp <= *alpha) && (fabs(workspace_0) > mpc4_B.p_max))
        {
          *alpha = mpc4_B.alphaTemp;
          *constrType = 3;
          *constrIdx = k + 1;
          *newBlocking = true;
        }

        mpc4_B.alphaTemp = fabs(mpc4_B.phaseOneCorrectionX);
        if ((mpc4_B.alphaTemp <= mpc4_B.phaseOneCorrectionP) || rtIsNaN
            (mpc4_B.phaseOneCorrectionP)) {
          mpc4_B.phaseOneCorrectionP = mpc4_B.alphaTemp;
        }

        mpc4_B.alphaTemp = mpc4_B.phaseOneCorrectionP / workspace_0;
        if (mpc4_B.alphaTemp < *alpha) {
          *alpha = mpc4_B.alphaTemp;
          *constrType = 3;
          *constrIdx = k + 1;
          *newBlocking = true;
          mpc4_B.p_max = fabs(workspace_0);
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    mpc4_B.phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    mpc4_B.phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    totalIneq = workingset_sizes[3];
    for (k = 0; k <= totalIneq - 2; k++) {
      workingset_indexLB_0 = workingset_indexLB[k];
      mpc4_B.pk_corrected = -solution_searchDir[workingset_indexLB_0 - 1] -
        mpc4_B.phaseOneCorrectionP;
      if ((mpc4_B.pk_corrected > mpc4_B.denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] + k) - 1])) {
        workspace_0 = -solution_xstar[workingset_indexLB_0 - 1] -
          workingset_lb[workingset_indexLB_0 - 1];
        mpc4_B.ratio = (workspace_0 - *toldelta) - mpc4_B.phaseOneCorrectionX;
        mpc4_B.alphaTemp = fabs(mpc4_B.ratio);
        mpc4_B.ratio = tolcon - mpc4_B.ratio;
        if ((mpc4_B.alphaTemp <= mpc4_B.ratio) || rtIsNaN(mpc4_B.ratio)) {
          mpc4_B.ratio = mpc4_B.alphaTemp;
        }

        mpc4_B.alphaTemp = mpc4_B.ratio / mpc4_B.pk_corrected;
        if ((mpc4_B.alphaTemp <= *alpha) && (fabs(mpc4_B.pk_corrected) >
             mpc4_B.p_max)) {
          *alpha = mpc4_B.alphaTemp;
          *constrType = 4;
          *constrIdx = k + 1;
          *newBlocking = true;
        }

        mpc4_B.ratio = workspace_0 - mpc4_B.phaseOneCorrectionX;
        mpc4_B.alphaTemp = fabs(mpc4_B.ratio);
        mpc4_B.ratio = tolcon - mpc4_B.ratio;
        if ((mpc4_B.alphaTemp <= mpc4_B.ratio) || rtIsNaN(mpc4_B.ratio)) {
          mpc4_B.ratio = mpc4_B.alphaTemp;
        }

        mpc4_B.alphaTemp = mpc4_B.ratio / mpc4_B.pk_corrected;
        if (mpc4_B.alphaTemp < *alpha) {
          *alpha = mpc4_B.alphaTemp;
          *constrType = 4;
          *constrIdx = k + 1;
          *newBlocking = true;
          mpc4_B.p_max = fabs(mpc4_B.pk_corrected);
        }
      }
    }

    k = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    mpc4_B.phaseOneCorrectionX = solution_searchDir[k];
    if ((-mpc4_B.phaseOneCorrectionX > mpc4_B.denomTol) &&
        (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
          workingset_sizes[3]) - 2])) {
      workspace_0 = -solution_xstar[k] - workingset_lb[k];
      mpc4_B.ratio = workspace_0 - *toldelta;
      mpc4_B.alphaTemp = fabs(mpc4_B.ratio);
      mpc4_B.ratio = tolcon - mpc4_B.ratio;
      if ((mpc4_B.alphaTemp <= mpc4_B.ratio) || rtIsNaN(mpc4_B.ratio)) {
        mpc4_B.ratio = mpc4_B.alphaTemp;
      }

      mpc4_B.alphaTemp = mpc4_B.ratio / -mpc4_B.phaseOneCorrectionX;
      if ((mpc4_B.alphaTemp <= *alpha) && (fabs(mpc4_B.phaseOneCorrectionX) >
           mpc4_B.p_max)) {
        *alpha = mpc4_B.alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      mpc4_B.alphaTemp = fabs(workspace_0);
      mpc4_B.ratio = tolcon - workspace_0;
      if ((mpc4_B.alphaTemp <= mpc4_B.ratio) || rtIsNaN(mpc4_B.ratio)) {
        mpc4_B.ratio = mpc4_B.alphaTemp;
      }

      mpc4_B.alphaTemp = mpc4_B.ratio / -mpc4_B.phaseOneCorrectionX;
      if (mpc4_B.alphaTemp < *alpha) {
        *alpha = mpc4_B.alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        mpc4_B.p_max = fabs(mpc4_B.phaseOneCorrectionX);
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    mpc4_B.phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    mpc4_B.phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    for (k = 0; k < totalUB; k++) {
      totalIneq = workingset_indexUB[k];
      mpc4_B.pk_corrected = solution_searchDir[totalIneq - 1] -
        mpc4_B.phaseOneCorrectionP;
      if ((mpc4_B.pk_corrected > mpc4_B.denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] + k) - 1])) {
        workspace_0 = solution_xstar[totalIneq - 1] - workingset_ub[totalIneq -
          1];
        mpc4_B.ratio = (workspace_0 - *toldelta) - mpc4_B.phaseOneCorrectionX;
        mpc4_B.alphaTemp = fabs(mpc4_B.ratio);
        mpc4_B.ratio = tolcon - mpc4_B.ratio;
        if ((mpc4_B.alphaTemp <= mpc4_B.ratio) || rtIsNaN(mpc4_B.ratio)) {
          mpc4_B.ratio = mpc4_B.alphaTemp;
        }

        mpc4_B.alphaTemp = mpc4_B.ratio / mpc4_B.pk_corrected;
        if ((mpc4_B.alphaTemp <= *alpha) && (fabs(mpc4_B.pk_corrected) >
             mpc4_B.p_max)) {
          *alpha = mpc4_B.alphaTemp;
          *constrType = 5;
          *constrIdx = k + 1;
          *newBlocking = true;
        }

        mpc4_B.ratio = workspace_0 - mpc4_B.phaseOneCorrectionX;
        mpc4_B.alphaTemp = fabs(mpc4_B.ratio);
        mpc4_B.ratio = tolcon - mpc4_B.ratio;
        if ((mpc4_B.alphaTemp <= mpc4_B.ratio) || rtIsNaN(mpc4_B.ratio)) {
          mpc4_B.ratio = mpc4_B.alphaTemp;
        }

        mpc4_B.alphaTemp = mpc4_B.ratio / mpc4_B.pk_corrected;
        if (mpc4_B.alphaTemp < *alpha) {
          *alpha = mpc4_B.alphaTemp;
          *constrType = 5;
          *constrIdx = k + 1;
          *newBlocking = true;
          mpc4_B.p_max = fabs(mpc4_B.pk_corrected);
        }
      }
    }
  }

  *toldelta += 6.608625846508183E-7;
  if (mpc4_B.p_max > 0.0) {
    mpc4_B.ratio = 6.608625846508183E-7 / mpc4_B.p_max;
    if (!(*alpha >= mpc4_B.ratio)) {
      *alpha = mpc4_B.ratio;
    }
  }

  if (isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.7976931348623157E+308))) &&
                    (*newBlocking));
    if (!(*alpha <= 1.7976931348623157E+308)) {
      *alpha = 1.7976931348623157E+308;
    }
  } else {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    if (!(*alpha <= 1.0)) {
      *alpha = 1.0;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_feasibleratiotest(const real_T solution_xstar[16], const real_T
  solution_searchDir[16], real_T workspace[1072], int32_T workingset_nVar,
  int32_T workingset_ldA, const real_T workingset_Aineq[1056], const real_T
  workingset_bineq[66], const real_T workingset_lb[16], const real_T
  workingset_ub[16], const int32_T workingset_indexLB[16], const int32_T
  workingset_indexUB[16], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[67],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T tolcon,
  real_T *alpha, boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  real_T ratio;
  int32_T k;
  int32_T totalIneq;
  int32_T totalUB;
  int32_T workingset_indexLB_0;
  totalIneq = workingset_sizes[2];
  totalUB = workingset_sizes[4];
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  mpc4_B.denomTol_d = 2.2204460492503131E-13 * mpc4_xnrm2_l(workingset_nVar,
    solution_searchDir);
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    if (totalIneq - 1 >= 0) {
      memcpy(&workspace[0], &workingset_bineq[0], static_cast<uint32_T>
             (totalIneq) * sizeof(real_T));
    }

    mpc4_xgemv_j30bu(workingset_nVar, workingset_sizes[2], workingset_Aineq,
                     workingset_ldA, solution_xstar, workspace);
    mpc4_xgemv_j30bul(workingset_nVar, workingset_sizes[2], workingset_Aineq,
                      workingset_ldA, solution_searchDir, workspace);
    for (k = 0; k < totalIneq; k++) {
      mpc4_B.phaseOneCorrectionX_l = workspace[k + 67];
      if ((mpc4_B.phaseOneCorrectionX_l > mpc4_B.denomTol_d) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] + k) - 1])) {
        ratio = workspace[k];
        mpc4_B.alphaTemp_g = fabs(ratio);
        ratio = tolcon - ratio;
        if ((mpc4_B.alphaTemp_g <= ratio) || rtIsNaN(ratio)) {
          ratio = mpc4_B.alphaTemp_g;
        }

        mpc4_B.alphaTemp_g = ratio / mpc4_B.phaseOneCorrectionX_l;
        if (mpc4_B.alphaTemp_g < *alpha) {
          *alpha = mpc4_B.alphaTemp_g;
          *constrType = 3;
          *constrIdx = k + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    mpc4_B.phaseOneCorrectionX_l = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    mpc4_B.phaseOneCorrectionP_d = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    k = workingset_sizes[3];
    for (totalIneq = 0; totalIneq <= k - 2; totalIneq++) {
      workingset_indexLB_0 = workingset_indexLB[totalIneq];
      mpc4_B.pk_corrected_d = -solution_searchDir[workingset_indexLB_0 - 1] -
        mpc4_B.phaseOneCorrectionP_d;
      if ((mpc4_B.pk_corrected_d > mpc4_B.denomTol_d) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] + totalIneq) -
           1])) {
        ratio = (-solution_xstar[workingset_indexLB_0 - 1] -
                 workingset_lb[workingset_indexLB_0 - 1]) -
          mpc4_B.phaseOneCorrectionX_l;
        mpc4_B.alphaTemp_g = fabs(ratio);
        ratio = tolcon - ratio;
        if ((mpc4_B.alphaTemp_g <= ratio) || rtIsNaN(ratio)) {
          ratio = mpc4_B.alphaTemp_g;
        }

        mpc4_B.alphaTemp_g = ratio / mpc4_B.pk_corrected_d;
        if (mpc4_B.alphaTemp_g < *alpha) {
          *alpha = mpc4_B.alphaTemp_g;
          *constrType = 4;
          *constrIdx = totalIneq + 1;
          *newBlocking = true;
        }
      }
    }

    totalIneq = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    mpc4_B.phaseOneCorrectionX_l = -solution_searchDir[totalIneq];
    if ((mpc4_B.phaseOneCorrectionX_l > mpc4_B.denomTol_d) &&
        (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
          workingset_sizes[3]) - 2])) {
      ratio = -solution_xstar[totalIneq] - workingset_lb[totalIneq];
      mpc4_B.alphaTemp_g = fabs(ratio);
      ratio = tolcon - ratio;
      if ((mpc4_B.alphaTemp_g <= ratio) || rtIsNaN(ratio)) {
        ratio = mpc4_B.alphaTemp_g;
      }

      mpc4_B.alphaTemp_g = ratio / mpc4_B.phaseOneCorrectionX_l;
      if (mpc4_B.alphaTemp_g < *alpha) {
        *alpha = mpc4_B.alphaTemp_g;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    mpc4_B.phaseOneCorrectionX_l = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    mpc4_B.phaseOneCorrectionP_d = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    for (totalIneq = 0; totalIneq < totalUB; totalIneq++) {
      k = workingset_indexUB[totalIneq];
      mpc4_B.pk_corrected_d = solution_searchDir[k - 1] -
        mpc4_B.phaseOneCorrectionP_d;
      if ((mpc4_B.pk_corrected_d > mpc4_B.denomTol_d) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] + totalIneq) -
           1])) {
        ratio = (solution_xstar[k - 1] - workingset_ub[k - 1]) -
          mpc4_B.phaseOneCorrectionX_l;
        mpc4_B.alphaTemp_g = fabs(ratio);
        ratio = tolcon - ratio;
        if ((mpc4_B.alphaTemp_g <= ratio) || rtIsNaN(ratio)) {
          ratio = mpc4_B.alphaTemp_g;
        }

        mpc4_B.alphaTemp_g = ratio / mpc4_B.pk_corrected_d;
        if (mpc4_B.alphaTemp_g < *alpha) {
          *alpha = mpc4_B.alphaTemp_g;
          *constrType = 5;
          *constrIdx = totalIneq + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (!isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    if (!(*alpha <= 1.0)) {
      *alpha = 1.0;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_addBoundToActiveSetMatrix_(sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *obj,
  int32_T TYPE, int32_T idx_local)
{
  int32_T colOffset;
  int32_T idx_bnd_local;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid[obj->nActiveConstr - 1] = TYPE;
  obj->Wlocalidx[obj->nActiveConstr - 1] = idx_local;
  colOffset = (obj->nActiveConstr - 1) * obj->ldA - 1;
  if (TYPE == 5) {
    idx_bnd_local = obj->indexUB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->ub[obj->indexUB[idx_local - 1] - 1];
  } else {
    idx_bnd_local = obj->indexLB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->lb[obj->indexLB[idx_local - 1] - 1];
  }

  if (idx_bnd_local - 2 >= 0) {
    memset(&obj->ATwset[colOffset + 1], 0, static_cast<uint32_T>(idx_bnd_local -
            1) * sizeof(real_T));
  }

  obj->ATwset[idx_bnd_local + colOffset] = static_cast<real_T>(TYPE == 5) * 2.0
    - 1.0;
  if (idx_bnd_local + 1 <= obj->nVar) {
    memset(&obj->ATwset[(idx_bnd_local + colOffset) + 1], 0,
           static_cast<uint32_T>(((obj->nVar + colOffset) - idx_bnd_local) -
            colOffset) * sizeof(real_T));
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    obj->ATwset[obj->nVar + colOffset] = -1.0;
    break;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_compute_lambda(real_T workspace[1072],
  sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution, const s3c01M66EFWFQJ5qmFcUbmD_mpc4_T
  *objective, const ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager)
{
  int32_T nActiveConstr;
  nActiveConstr = qrmanager->ncols;
  if (qrmanager->ncols > 0) {
    real_T c;
    int32_T b_idx;
    int32_T idxQR;
    boolean_T guard1;
    guard1 = false;
    if (objective->objtype != 4) {
      boolean_T nonDegenerate;
      if (qrmanager->mrows >= qrmanager->ncols) {
        b_idx = qrmanager->mrows;
      } else {
        b_idx = qrmanager->ncols;
      }

      c = 2.2204460492503131E-15 * static_cast<real_T>(b_idx);
      if (c >= 1.4901161193847656E-8) {
        c = 1.4901161193847656E-8;
      }

      nonDegenerate = ((qrmanager->mrows > 0) && (qrmanager->ncols > 0));
      if (nonDegenerate) {
        boolean_T guard2;
        b_idx = qrmanager->ncols;
        guard2 = false;
        if (qrmanager->mrows < qrmanager->ncols) {
          idxQR = (qrmanager->ncols - 1) * qrmanager->ldq + qrmanager->mrows;
          while ((b_idx > qrmanager->mrows) && (fabs(qrmanager->QR[idxQR - 1]) >=
                  c)) {
            b_idx--;
            idxQR -= qrmanager->ldq;
          }

          nonDegenerate = (b_idx == qrmanager->mrows);
          if (!nonDegenerate) {
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          idxQR = (b_idx - 1) * qrmanager->ldq + b_idx;
          while ((b_idx >= 1) && (fabs(qrmanager->QR[idxQR - 1]) >= c)) {
            b_idx--;
            idxQR = (idxQR - qrmanager->ldq) - 1;
          }

          nonDegenerate = (b_idx == 0);
        }
      }

      if (!nonDegenerate) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      int32_T b_ix;
      int32_T jjA;
      b_idx = qrmanager->ldq;
      if ((qrmanager->mrows != 0) && (qrmanager->ncols != 0)) {
        if (qrmanager->ncols - 1 >= 0) {
          memset(&workspace[0], 0, static_cast<uint32_T>(qrmanager->ncols) *
                 sizeof(real_T));
        }

        jjA = 0;
        b_ix = (qrmanager->ncols - 1) * qrmanager->ldq + 1;
        for (idxQR = 1; b_idx < 0 ? idxQR >= b_ix : idxQR <= b_ix; idxQR +=
             b_idx) {
          int32_T d;
          c = 0.0;
          d = idxQR + qrmanager->mrows;
          for (int32_T ia = idxQR; ia < d; ia++) {
            c += qrmanager->Q[ia - 1] * objective->grad[ia - idxQR];
          }

          workspace[jjA] += c;
          jjA++;
        }
      }

      if (qrmanager->ncols != 0) {
        for (idxQR = nActiveConstr; idxQR >= 1; idxQR--) {
          jjA = ((idxQR - 1) * b_idx + idxQR) - 2;
          workspace[idxQR - 1] /= qrmanager->QR[jjA + 1];
          for (int32_T ia = 0; ia <= idxQR - 2; ia++) {
            b_ix = (idxQR - ia) - 2;
            workspace[b_ix] -= workspace[idxQR - 1] * qrmanager->QR[jjA - ia];
          }
        }
      }

      for (b_idx = 0; b_idx < nActiveConstr; b_idx++) {
        solution->lambda[b_idx] = -workspace[b_idx];
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f[15], sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution,
  sFevNsrsl34D5b5aqm3qNjD_mpc4_T *memspace, const s3c01M66EFWFQJ5qmFcUbmD_mpc4_T
  *objective, sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, real_T options_ObjectiveLimit,
  real_T options_ConstraintTolerance, int32_T runTimeOptions_MaxIterations,
  real_T runTimeOptions_ConstrRelTolFact, boolean_T *updateFval, boolean_T
  iterDisplayQP)
{
  boolean_T nonDegenerateWset;
  solution->iterations++;
  mpc4_B.nVar_b = objective->nvar;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }

  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    mpc4_B.tempMaxConstr = mpc4_maxConstraintViolation_n3(workingset,
      solution->xstar);
    solution->maxConstr = mpc4_B.tempMaxConstr;
    if (objective->objtype == 5) {
      mpc4_B.tempMaxConstr = solution->maxConstr - solution->xstar
        [objective->nvar - 1];
    }

    if (mpc4_B.tempMaxConstr > options_ConstraintTolerance *
        runTimeOptions_ConstrRelTolFact) {
      if (mpc4_B.nVar_b - 1 >= 0) {
        memcpy(&solution->searchDir[0], &solution->xstar[0],
               static_cast<uint32_T>(mpc4_B.nVar_b) * sizeof(real_T));
      }

      nonDegenerateWset = mpc4_feasibleX0ForWorkingSet(memspace->workspace_float,
        solution->searchDir, workingset, qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }

      *activeSetChangeID = 0;
      mpc4_B.tempMaxConstr = mpc4_maxConstraintViolation_n3(workingset,
        solution->searchDir);
      if (mpc4_B.tempMaxConstr < solution->maxConstr) {
        if (mpc4_B.nVar_b - 1 >= 0) {
          memcpy(&solution->xstar[0], &solution->searchDir[0],
                 static_cast<uint32_T>(mpc4_B.nVar_b) * sizeof(real_T));
        }

        solution->maxConstr = mpc4_B.tempMaxConstr;
      }
    }
  }

  if (*updateFval) {
    if ((options_ObjectiveLimit > (rtMinusInf)) || iterDisplayQP) {
      solution->fstar = mpc4_computeFval_ReuseHx(objective,
        memspace->workspace_float, f, solution->xstar);
      if ((options_ObjectiveLimit > (rtMinusInf)) && (solution->fstar <
           options_ObjectiveLimit) && ((solution->state != 0) ||
           (objective->objtype != 5))) {
        solution->state = 2;
      }
    } else {
      *updateFval = false;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_computeFirstOrderOpt(sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution,
  const s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *objective, int32_T workingset_nVar,
  int32_T workingset_ldA, const real_T workingset_ATwset[1072], int32_T
  workingset_nActiveConstr, real_T workspace[1072])
{
  real_T infNorm;
  int32_T k;
  boolean_T exitg1;
  infNorm = 0.0;
  if (workingset_nVar - 1 >= 0) {
    memcpy(&workspace[0], &objective->grad[0], static_cast<uint32_T>
           (workingset_nVar) * sizeof(real_T));
  }

  if ((workingset_nVar != 0) && (workingset_nActiveConstr != 0)) {
    int32_T b;
    int32_T ix;
    ix = 0;
    b = (workingset_nActiveConstr - 1) * workingset_ldA + 1;
    for (k = 1; workingset_ldA < 0 ? k >= b : k <= b; k += workingset_ldA) {
      int32_T d;
      d = k + workingset_nVar;
      for (int32_T ia = k; ia < d; ia++) {
        int32_T tmp;
        tmp = ia - k;
        workspace[tmp] += workingset_ATwset[ia - 1] * solution->lambda[ix];
      }

      ix++;
    }
  }

  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= workingset_nVar - 1)) {
    real_T abs_workspace_i;
    abs_workspace_i = fabs(workspace[k]);
    if (rtIsNaN(abs_workspace_i)) {
      infNorm = (rtNaN);
      exitg1 = true;
    } else {
      if (!(infNorm >= abs_workspace_i)) {
        infNorm = abs_workspace_i;
      }

      k++;
    }
  }

  solution->firstorderopt = infNorm;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_iterate(const real_T b_H[225], const real_T f[15],
  sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpc4_T
  *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, sOWFOmKuLvD2kpFwfdM45bG_mpc4_T
  *cholmanager, s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *objective, boolean_T
  options_IterDisplayQP, real_T options_ObjectiveLimit, real_T
  options_PricingTolerance, real_T options_ConstraintTolerance, real_T
  options_StepTolerance, const sIOJhD9KwAkF5sEguPjYquC_mpc4_T runTimeOptions)
{
  int32_T exitg1;
  boolean_T guard1;
  boolean_T guard11;
  boolean_T newBlocking;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  mpc4_B.activeSetChangeID = 0;
  mpc4_B.TYPE = objective->objtype;
  mpc4_B.tolDelta = 6.7434957617430445E-7;
  mpc4_B.nVar = workingset->nVar;
  mpc4_B.globalActiveConstrIdx = 0;
  mpc4_computeGrad_StoreHx(objective, b_H, f, solution->xstar);
  solution->fstar = mpc4_computeFval_ReuseHx(objective,
    memspace->workspace_float, f, solution->xstar);
  if (solution->iterations < runTimeOptions.MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  mpc4_B.minmn = workingset->mConstrMax;
  if (mpc4_B.minmn - 1 >= 0) {
    memset(&solution->lambda[0], 0, static_cast<uint32_T>(mpc4_B.minmn) * sizeof
           (real_T));
  }

  if ((solution->iterations == 0) && options_IterDisplayQP) {
    std::printf("                                          First-order\n");
    std::fflush(stdout);
    std::printf(" Iter            Fval     Feasibility      Optimality    Norm of step\n");
    std::fflush(stdout);
    std::printf("%5i  %14.6e", solution->iterations, solution->fstar);
    std::fflush(stdout);
    std::printf("\n");
    std::fflush(stdout);
  }

  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard11 = false;
      if (subProblemChanged) {
        switch (mpc4_B.activeSetChangeID) {
         case 1:
          mpc4_squareQ_appendCol(qrmanager, workingset->ATwset, workingset->ldA *
            (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          mpc4_deleteColMoveEnd(qrmanager, mpc4_B.globalActiveConstrIdx);
          break;

         default:
          mpc4_B.iAw0 = workingset->nActiveConstr;
          guard1 = false;
          if (mpc4_B.nVar * workingset->nActiveConstr > 0) {
            for (mpc4_B.i_h = 0; mpc4_B.i_h < mpc4_B.iAw0; mpc4_B.i_h++) {
              mpc4_B.ix0 = workingset->ldA * mpc4_B.i_h;
              mpc4_B.iy0 = qrmanager->ldq * mpc4_B.i_h;
              for (mpc4_B.minmn = 0; mpc4_B.minmn < mpc4_B.nVar; mpc4_B.minmn++)
              {
                qrmanager->QR[mpc4_B.iy0 + mpc4_B.minmn] = workingset->
                  ATwset[mpc4_B.minmn + mpc4_B.ix0];
              }
            }

            guard1 = true;
          } else if (mpc4_B.nVar * workingset->nActiveConstr == 0) {
            qrmanager->mrows = mpc4_B.nVar;
            qrmanager->ncols = workingset->nActiveConstr;
            qrmanager->minRowCol = 0;
          } else {
            guard1 = true;
          }

          if (guard1) {
            qrmanager->usedPivoting = false;
            qrmanager->mrows = mpc4_B.nVar;
            qrmanager->ncols = workingset->nActiveConstr;
            mpc4_B.minmn = workingset->nActiveConstr;
            for (mpc4_B.i_h = 0; mpc4_B.i_h < mpc4_B.minmn; mpc4_B.i_h++) {
              qrmanager->jpvt[mpc4_B.i_h] = mpc4_B.i_h + 1;
            }

            if (mpc4_B.nVar <= workingset->nActiveConstr) {
              qrmanager->minRowCol = mpc4_B.nVar;
            } else {
              qrmanager->minRowCol = workingset->nActiveConstr;
            }

            if (mpc4_B.nVar <= workingset->nActiveConstr) {
              mpc4_B.minmn = mpc4_B.nVar;
            } else {
              mpc4_B.minmn = workingset->nActiveConstr;
            }

            memset(&qrmanager->tau[0], 0, sizeof(real_T) << 4U);
            if (mpc4_B.minmn >= 1) {
              memset(&qrmanager->tau[0], 0, sizeof(real_T) << 4U);
              mpc4_qrf(qrmanager->QR, 1, mpc4_B.nVar, workingset->nActiveConstr,
                       mpc4_B.minmn, qrmanager->tau);
            }
          }

          mpc4_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        mpc4_compute_deltax(b_H, solution, memspace, qrmanager, cholmanager,
                            objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          mpc4_B.normDelta = mpc4_xnrm2_l(mpc4_B.nVar, solution->searchDir);
          guard11 = true;
        }
      } else {
        if (mpc4_B.nVar - 1 >= 0) {
          memset(&solution->searchDir[0], 0, static_cast<uint32_T>(mpc4_B.nVar) *
                 sizeof(real_T));
        }

        mpc4_B.normDelta = 0.0;
        guard11 = true;
      }

      if (guard11) {
        if ((!subProblemChanged) || (mpc4_B.normDelta < options_StepTolerance) ||
            (workingset->nActiveConstr >= mpc4_B.nVar)) {
          mpc4_compute_lambda(memspace->workspace_float, solution, objective,
                              qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr >
               mpc4_B.nVar)) {
            mpc4_B.minmn = 0;
            mpc4_B.minLambda = options_PricingTolerance *
              runTimeOptions.ProbRelTolFactor * static_cast<real_T>(mpc4_B.TYPE
              != 5);
            mpc4_B.iAw0 = (workingset->nWConstr[0] + workingset->nWConstr[1]) +
              1;
            mpc4_B.ix0 = workingset->nActiveConstr;
            for (mpc4_B.i_h = mpc4_B.iAw0; mpc4_B.i_h <= mpc4_B.ix0; mpc4_B.i_h
                 ++) {
              mpc4_B.solution_lambda = solution->lambda[mpc4_B.i_h - 1];
              if (mpc4_B.solution_lambda < mpc4_B.minLambda) {
                mpc4_B.minLambda = mpc4_B.solution_lambda;
                mpc4_B.minmn = mpc4_B.i_h;
              }
            }

            if (mpc4_B.minmn == 0) {
              solution->state = 1;
            } else {
              mpc4_B.activeSetChangeID = -1;
              mpc4_B.globalActiveConstrIdx = mpc4_B.minmn;
              subProblemChanged = true;
              mpc4_removeConstr(workingset, mpc4_B.minmn);
              if (mpc4_B.minmn < workingset->nActiveConstr + 1) {
                solution->lambda[mpc4_B.minmn - 1] = solution->lambda
                  [workingset->nActiveConstr];
              }

              solution->lambda[workingset->nActiveConstr] = 0.0;
            }
          } else {
            mpc4_B.minmn = workingset->nActiveConstr;
            mpc4_B.activeSetChangeID = 0;
            mpc4_B.globalActiveConstrIdx = workingset->nActiveConstr;
            subProblemChanged = true;
            mpc4_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[mpc4_B.minmn - 1] = 0.0;
          }

          updateFval = false;
        } else {
          updateFval = (mpc4_B.TYPE == 5);
          if (updateFval || runTimeOptions.RemainFeasible) {
            mpc4_feasibleratiotest(solution->xstar, solution->searchDir,
              memspace->workspace_float, workingset->nVar, workingset->ldA,
              workingset->Aineq, workingset->bineq, workingset->lb,
              workingset->ub, workingset->indexLB, workingset->indexUB,
              workingset->sizes, workingset->isActiveIdx,
              workingset->isActiveConstr, workingset->nWConstr, updateFval,
              options_ConstraintTolerance, &mpc4_B.minLambda, &newBlocking,
              &mpc4_B.minmn, &mpc4_B.i_h);
          } else {
            mpc4_ratiotest(solution->xstar, solution->searchDir,
                           memspace->workspace_float, workingset->nVar,
                           workingset->ldA, workingset->Aineq, workingset->bineq,
                           workingset->lb, workingset->ub, workingset->indexLB,
                           workingset->indexUB, workingset->sizes,
                           workingset->isActiveIdx, workingset->isActiveConstr,
                           workingset->nWConstr, false,
                           options_ConstraintTolerance, &mpc4_B.tolDelta,
                           &mpc4_B.minLambda, &newBlocking, &mpc4_B.minmn,
                           &mpc4_B.i_h);
          }

          if (newBlocking) {
            switch (mpc4_B.minmn) {
             case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr[(workingset->isActiveIdx[2] +
                mpc4_B.i_h) - 2] = true;
              workingset->nActiveConstr++;
              workingset->Wid[workingset->nActiveConstr - 1] = 3;
              workingset->Wlocalidx[workingset->nActiveConstr - 1] = mpc4_B.i_h;
              mpc4_B.minmn = (mpc4_B.i_h - 1) * workingset->ldA;
              mpc4_B.iAw0 = (workingset->nActiveConstr - 1) * workingset->ldA;
              mpc4_B.ix0 = workingset->nVar;
              for (mpc4_B.activeSetChangeID = 0; mpc4_B.activeSetChangeID <
                   mpc4_B.ix0; mpc4_B.activeSetChangeID++) {
                workingset->ATwset[mpc4_B.iAw0 + mpc4_B.activeSetChangeID] =
                  workingset->Aineq[mpc4_B.minmn + mpc4_B.activeSetChangeID];
              }

              workingset->bwset[workingset->nActiveConstr - 1] =
                workingset->bineq[mpc4_B.i_h - 1];
              break;

             case 4:
              mpc4_addBoundToActiveSetMatrix_(workingset, 4, mpc4_B.i_h);
              break;

             default:
              mpc4_addBoundToActiveSetMatrix_(workingset, 5, mpc4_B.i_h);
              break;
            }

            mpc4_B.activeSetChangeID = 1;
          } else {
            if (objective->objtype == 5) {
              if (mpc4_xnrm2_l(objective->nvar, solution->searchDir) > 100.0 *
                  static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8)
              {
                solution->state = 3;
              } else {
                solution->state = 4;
              }
            }

            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if ((mpc4_B.nVar >= 1) && (!(mpc4_B.minLambda == 0.0))) {
            for (mpc4_B.i_h = 0; mpc4_B.i_h < mpc4_B.nVar; mpc4_B.i_h++) {
              solution->xstar[mpc4_B.i_h] += mpc4_B.minLambda *
                solution->searchDir[mpc4_B.i_h];
            }
          }

          mpc4_computeGrad_StoreHx(objective, b_H, f, solution->xstar);
          updateFval = true;
        }

        mpc4_checkStoppingAndUpdateFval(&mpc4_B.activeSetChangeID, f, solution,
          memspace, objective, workingset, qrmanager, options_ObjectiveLimit,
          options_ConstraintTolerance, runTimeOptions.MaxIterations,
          runTimeOptions.ConstrRelTolFactor, &updateFval, options_IterDisplayQP);
        if (options_IterDisplayQP) {
          if (solution->iterations - solution->iterations / 50 * 50 == 0) {
            std::printf("                                          First-order\n");
            std::fflush(stdout);
            std::printf(" Iter            Fval     Feasibility      Optimality    Norm of step\n");
            std::fflush(stdout);
          } else {
            solution->maxConstr = mpc4_maxConstraintViolation_n3(workingset,
              solution->xstar);
          }

          mpc4_computeFirstOrderOpt(solution, objective, workingset->nVar,
            workingset->ldA, workingset->ATwset, workingset->nActiveConstr,
            memspace->workspace_float);
          std::printf("%5i  %14.6e  %14.6e  %14.6e", solution->iterations,
                      solution->fstar, solution->maxConstr,
                      solution->firstorderopt);
          std::fflush(stdout);
          std::printf("  ");
          std::fflush(stdout);
          std::printf("%14.6e", mpc4_B.normDelta);
          std::fflush(stdout);
          std::printf("\n");
          std::fflush(stdout);
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = mpc4_computeFval_ReuseHx(objective,
          memspace->workspace_float, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_PresolveWorkingSet_e(sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution,
  sFevNsrsl34D5b5aqm3qNjD_mpc4_T *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T
  *workingset, ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, const
  sqZVQFgLZG74FDpCArykMHB_mpc4_T *options)
{
  boolean_T guard1;
  boolean_T okWorkingSet;
  solution->state = 82;
  mpc4_B.nVar_f = workingset->nVar;
  mpc4_B.mTotalWorkingEq = workingset->nWConstr[0] + workingset->nWConstr[1];
  mpc4_B.nDepInd = 0;
  if (mpc4_B.mTotalWorkingEq > 0) {
    for (mpc4_B.idx_row = 0; mpc4_B.idx_row < mpc4_B.mTotalWorkingEq;
         mpc4_B.idx_row++) {
      for (mpc4_B.idxStartIneq_a = 0; mpc4_B.idxStartIneq_a < mpc4_B.nVar_f;
           mpc4_B.idxStartIneq_a++) {
        qrmanager->QR[mpc4_B.idx_row + qrmanager->ldq * mpc4_B.idxStartIneq_a] =
          workingset->ATwset[workingset->ldA * mpc4_B.idx_row +
          mpc4_B.idxStartIneq_a];
      }
    }

    mpc4_B.nDepInd = mpc4_ComputeNumDependentEq_(qrmanager, workingset->bwset,
      mpc4_B.mTotalWorkingEq, workingset->nVar);
    if (mpc4_B.nDepInd > 0) {
      for (mpc4_B.idx_row = 0; mpc4_B.idx_row < mpc4_B.mTotalWorkingEq;
           mpc4_B.idx_row++) {
        mpc4_B.iy0_j = qrmanager->ldq * mpc4_B.idx_row;
        mpc4_B.ix0_j = workingset->ldA * mpc4_B.idx_row;
        for (mpc4_B.idxStartIneq_a = 0; mpc4_B.idxStartIneq_a < mpc4_B.nVar_f;
             mpc4_B.idxStartIneq_a++) {
          qrmanager->QR[mpc4_B.iy0_j + mpc4_B.idxStartIneq_a] =
            workingset->ATwset[mpc4_B.idxStartIneq_a + mpc4_B.ix0_j];
        }
      }

      mpc4_IndexOfDependentEq_(memspace->workspace_int, workingset->nWConstr[0],
        mpc4_B.nDepInd, qrmanager, workingset->nVar, mpc4_B.mTotalWorkingEq);
      mpc4_countsort(memspace->workspace_int, mpc4_B.nDepInd,
                     memspace->workspace_sort, 1, mpc4_B.mTotalWorkingEq);
      for (mpc4_B.idx_row = mpc4_B.nDepInd; mpc4_B.idx_row >= 1; mpc4_B.idx_row
           --) {
        mpc4_removeEqConstr(workingset, memspace->workspace_int[mpc4_B.idx_row -
                            1]);
      }
    }
  }

  if ((mpc4_B.nDepInd != -1) && (workingset->nActiveConstr <= qrmanager->ldq)) {
    mpc4_RemoveDependentIneq_(workingset, qrmanager, memspace, 1.0);
    okWorkingSet = mpc4_feasibleX0ForWorkingSet(memspace->workspace_float,
      solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      mpc4_RemoveDependentIneq_(workingset, qrmanager, memspace, 10.0);
      okWorkingSet = mpc4_feasibleX0ForWorkingSet(memspace->workspace_float,
        solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        mpc4_B.constrViolation = mpc4_maxConstraintViolation_n3(workingset,
          solution->xstar);
        if (mpc4_B.constrViolation > options->ConstraintTolerance) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    mpc4_B.idxStartIneq_a = (workingset->nWConstr[0] + workingset->nWConstr[1])
      + 1;
    mpc4_B.nVar_f = workingset->nActiveConstr;
    for (mpc4_B.idx_row = mpc4_B.idxStartIneq_a; mpc4_B.idx_row <= mpc4_B.nVar_f;
         mpc4_B.idx_row++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[mpc4_B.idx_row - 1] - 1] + workingset->Wlocalidx[mpc4_B.idx_row - 1])
        - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar, real_T
  workspace[1072], const real_T b_H[225], const real_T f[15], const real_T x[16])
{
  int32_T beta1;
  beta1 = 0;
  if (obj_hasLinear) {
    if (obj_nvar - 1 >= 0) {
      memcpy(&workspace[0], &f[0], static_cast<uint32_T>(obj_nvar) * sizeof
             (real_T));
    }

    beta1 = 1;
  }

  if (obj_nvar != 0) {
    int32_T d;
    int32_T ix;
    if ((beta1 != 1) && (obj_nvar - 1 >= 0)) {
      memset(&workspace[0], 0, static_cast<uint32_T>(obj_nvar) * sizeof(real_T));
    }

    ix = 0;
    d = (obj_nvar - 1) * obj_nvar + 1;
    for (beta1 = 1; obj_nvar < 0 ? beta1 >= d : beta1 <= d; beta1 += obj_nvar) {
      real_T c;
      int32_T e;
      c = 0.5 * x[ix];
      e = beta1 + obj_nvar;
      for (int32_T ia = beta1; ia < e; ia++) {
        int32_T tmp;
        tmp = ia - beta1;
        workspace[tmp] += b_H[ia - 1] * c;
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static real_T mpc4_computeFval(const s3c01M66EFWFQJ5qmFcUbmD_mpc4_T *obj, real_T
  workspace[1072], const real_T b_H[225], const real_T f[15], const real_T x[16])
{
  real_T val;
  int32_T c;
  int32_T ixlast;
  int32_T k;
  val = 0.0;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    mpc4_linearForm_(obj->hasLinear, obj->nvar, workspace, b_H, f, x);
    if (obj->nvar >= 1) {
      ixlast = obj->nvar;
      for (k = 0; k < ixlast; k++) {
        val += x[k] * workspace[k];
      }
    }
    break;

   case 4:
    mpc4_linearForm_(obj->hasLinear, obj->nvar, workspace, b_H, f, x);
    ixlast = obj->nvar + 1;
    c = obj->maxVar;
    for (k = ixlast; k < c; k++) {
      workspace[k - 1] = 0.5 * obj->beta * x[k - 1] + obj->rho;
    }

    if (obj->maxVar - 1 >= 1) {
      ixlast = obj->maxVar;
      for (k = 0; k <= ixlast - 2; k++) {
        val += x[k] * workspace[k];
      }
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpc4_driver(const real_T b_H[225], const real_T f[15],
  sqvdR3NQrfOjUOrC18Muj0B_mpc4_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpc4_T
  *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpc4_T *workingset,
  sOWFOmKuLvD2kpFwfdM45bG_mpc4_T *cholmanager, const
  sqZVQFgLZG74FDpCArykMHB_mpc4_T options, int32_T runTimeOptions_MaxIterations,
  real_T runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
  ssq2hyGkLOLhNlUBS6YfcCD_mpc4_T *qrmanager, s3c01M66EFWFQJ5qmFcUbmD_mpc4_T
  *objective)
{
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T runTimeOptions_RemainFeasible;
  boolean_T tmp;
  memset(&objective->grad[0], 0, sizeof(real_T) << 4U);
  memset(&objective->Hx[0], 0, 15U * sizeof(real_T));
  objective->hasLinear = true;
  objective->nvar = 15;
  objective->maxVar = 16;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->objtype = 3;
  objective->prev_objtype = 3;
  objective->prev_nvar = 0;
  objective->prev_hasLinear = false;
  objective->gammaScalar = 0.0;
  qrmanager->ldq = 16;
  memset(&qrmanager->QR[0], 0, 1072U * sizeof(real_T));
  memset(&qrmanager->Q[0], 0, sizeof(real_T) << 8U);
  memset(&qrmanager->jpvt[0], 0, 67U * sizeof(int32_T));
  qrmanager->mrows = 0;
  qrmanager->ncols = 0;
  memset(&qrmanager->tau[0], 0, sizeof(real_T) << 4U);
  qrmanager->minRowCol = 0;
  qrmanager->usedPivoting = false;
  solution->iterations = 0;
  runTimeOptions_RemainFeasible = (options.PricingTolerance <= 0.0);
  mpc4_B.i_l = workingset->nVar;
  tmp = mpc4_strcmp(options.SolverName);
  guard1 = false;
  guard2 = false;
  if (tmp || (workingset->probType == 3)) {
    mpc4_B.idxStartIneq = workingset->sizes[0];
    for (mpc4_B.mConstr = 0; mpc4_B.mConstr < mpc4_B.idxStartIneq;
         mpc4_B.mConstr++) {
      solution->xstar[workingset->indexFixed[mpc4_B.mConstr] - 1] =
        workingset->ub[workingset->indexFixed[mpc4_B.mConstr] - 1];
    }

    mpc4_B.idxStartIneq = workingset->sizes[3];
    for (mpc4_B.mConstr = 0; mpc4_B.mConstr < mpc4_B.idxStartIneq;
         mpc4_B.mConstr++) {
      if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
           mpc4_B.mConstr) - 1]) {
        solution->xstar[workingset->indexLB[mpc4_B.mConstr] - 1] =
          -workingset->lb[workingset->indexLB[mpc4_B.mConstr] - 1];
      }
    }

    mpc4_B.idxStartIneq = workingset->sizes[4];
    for (mpc4_B.mConstr = 0; mpc4_B.mConstr < mpc4_B.idxStartIneq;
         mpc4_B.mConstr++) {
      if (workingset->isActiveConstr[(workingset->isActiveIdx[4] +
           mpc4_B.mConstr) - 1]) {
        solution->xstar[workingset->indexUB[mpc4_B.mConstr] - 1] =
          workingset->ub[workingset->indexUB[mpc4_B.mConstr] - 1];
      }
    }

    mpc4_PresolveWorkingSet(solution, memspace, workingset, &options, qrmanager);
    if (solution->state < 0) {
    } else {
      guard2 = true;
    }
  } else {
    solution->state = 82;
    guard2 = true;
  }

  if (guard2) {
    solution->iterations = 0;
    solution->maxConstr = mpc4_maxConstraintViolation_n3(workingset,
      solution->xstar);
    mpc4_B.d = options.ConstraintTolerance * runTimeOptions_ConstrRelTolFact;
    if (solution->maxConstr > mpc4_B.d) {
      solution->xstar[workingset->nVar] = solution->maxConstr + 1.0;
      mpc4_B.b_workingset = *workingset;
      if (workingset->probType == 3) {
        mpc4_B.idxEndIneq = 1;
      } else {
        mpc4_B.idxEndIneq = 4;
      }

      mpc4_setProblemType(&mpc4_B.b_workingset, mpc4_B.idxEndIneq);
      mpc4_B.idxStartIneq = (mpc4_B.b_workingset.nWConstr[0] +
        mpc4_B.b_workingset.nWConstr[1]) + 1;
      mpc4_B.idxEndIneq = mpc4_B.b_workingset.nActiveConstr;
      for (mpc4_B.mConstr = mpc4_B.idxStartIneq; mpc4_B.mConstr <=
           mpc4_B.idxEndIneq; mpc4_B.mConstr++) {
        mpc4_B.b_workingset.isActiveConstr
          [(mpc4_B.b_workingset.isActiveIdx[mpc4_B.b_workingset.Wid[mpc4_B.mConstr
            - 1] - 1] + mpc4_B.b_workingset.Wlocalidx[mpc4_B.mConstr - 1]) - 2] =
          false;
      }

      mpc4_B.b_workingset.nWConstr[2] = 0;
      mpc4_B.b_workingset.nWConstr[3] = 0;
      mpc4_B.b_workingset.nWConstr[4] = 0;
      mpc4_B.b_workingset.nActiveConstr = mpc4_B.b_workingset.nWConstr[0] +
        mpc4_B.b_workingset.nWConstr[1];
      objective->prev_objtype = 3;
      objective->prev_nvar = 15;
      objective->prev_hasLinear = true;
      objective->objtype = 5;
      objective->nvar = workingset->nVar + 1;
      objective->gammaScalar = 1.0;
      objective->hasLinear = true;
      solution->fstar = solution->xstar[workingset->nVar];
      solution->state = 5;
      mpc4_B.expl_temp_p.ProbRelTolFactor = runTimeOptions_ProbRelTolFactor;
      mpc4_B.expl_temp_p.ConstrRelTolFactor = runTimeOptions_ConstrRelTolFact;
      mpc4_B.expl_temp_p.MaxIterations = runTimeOptions_MaxIterations;
      mpc4_B.expl_temp_p.RemainFeasible = runTimeOptions_RemainFeasible;
      mpc4_iterate(b_H, f, solution, memspace, &mpc4_B.b_workingset, qrmanager,
                   cholmanager, objective, options.IterDisplayQP, mpc4_B.d,
                   options.PricingTolerance, options.ConstraintTolerance,
                   1.4901161193847657E-10, mpc4_B.expl_temp_p);
      if (mpc4_B.b_workingset.isActiveConstr[(mpc4_B.b_workingset.isActiveIdx[3]
           + mpc4_B.b_workingset.sizes[3]) - 2]) {
        mpc4_B.mConstr = mpc4_B.b_workingset.sizes[0] +
          mpc4_B.b_workingset.sizes[1];
        exitg1 = false;
        while ((!exitg1) && (mpc4_B.mConstr + 1 <=
                             mpc4_B.b_workingset.nActiveConstr)) {
          if ((mpc4_B.b_workingset.Wid[mpc4_B.mConstr] == 4) &&
              (mpc4_B.b_workingset.Wlocalidx[mpc4_B.mConstr] ==
               mpc4_B.b_workingset.sizes[3])) {
            mpc4_removeConstr(&mpc4_B.b_workingset, mpc4_B.mConstr + 1);
            exitg1 = true;
          } else {
            mpc4_B.mConstr++;
          }
        }
      }

      mpc4_B.mConstr = mpc4_B.b_workingset.nActiveConstr;
      mpc4_B.idxStartIneq = mpc4_B.b_workingset.sizes[0] +
        mpc4_B.b_workingset.sizes[1];
      while ((mpc4_B.mConstr > mpc4_B.idxStartIneq) && (mpc4_B.mConstr >
              workingset->nVar)) {
        mpc4_removeConstr(&mpc4_B.b_workingset, mpc4_B.mConstr);
        mpc4_B.mConstr--;
      }

      solution->maxConstr = solution->xstar[workingset->nVar];
      mpc4_setProblemType(&mpc4_B.b_workingset, workingset->probType);
      objective->objtype = objective->prev_objtype;
      objective->nvar = objective->prev_nvar;
      objective->hasLinear = objective->prev_hasLinear;
      *workingset = mpc4_B.b_workingset;
      if (solution->state == 0) {
      } else {
        solution->maxConstr = mpc4_maxConstraintViolation_n3
          (&mpc4_B.b_workingset, solution->xstar);
        *workingset = mpc4_B.b_workingset;
        if (solution->maxConstr > mpc4_B.d) {
          mpc4_B.mConstr = mpc4_B.b_workingset.mConstrMax;
          if (mpc4_B.mConstr - 1 >= 0) {
            memset(&solution->lambda[0], 0, static_cast<uint32_T>(mpc4_B.mConstr)
                   * sizeof(real_T));
          }

          solution->fstar = mpc4_computeFval(objective,
            memspace->workspace_float, b_H, f, solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            if (mpc4_B.i_l - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     static_cast<uint32_T>(mpc4_B.i_l) * sizeof(real_T));
            }

            mpc4_PresolveWorkingSet_e(solution, memspace, &mpc4_B.b_workingset,
              qrmanager, &options);
            *workingset = mpc4_B.b_workingset;
            mpc4_B.maxConstr_new = mpc4_maxConstraintViolation_n3(workingset,
              solution->xstar);
            if (mpc4_B.maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = mpc4_B.maxConstr_new;
              if (mpc4_B.i_l - 1 >= 0) {
                memcpy(&solution->xstar[0], &solution->searchDir[0],
                       static_cast<uint32_T>(mpc4_B.i_l) * sizeof(real_T));
              }
            }
          }

          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    mpc4_B.expl_temp_b.ProbRelTolFactor = runTimeOptions_ProbRelTolFactor;
    mpc4_B.expl_temp_b.ConstrRelTolFactor = runTimeOptions_ConstrRelTolFact;
    mpc4_B.expl_temp_b.MaxIterations = runTimeOptions_MaxIterations;
    mpc4_B.expl_temp_b.RemainFeasible = runTimeOptions_RemainFeasible;
    mpc4_iterate(b_H, f, solution, memspace, workingset, qrmanager, cholmanager,
                 objective, options.IterDisplayQP, options.ObjectiveLimit,
                 options.PricingTolerance, options.ConstraintTolerance,
                 options.StepTolerance, mpc4_B.expl_temp_b);
    if (tmp && (solution->state != -6)) {
      solution->maxConstr = mpc4_maxConstraintViolation_n3(workingset,
        solution->xstar);
      mpc4_computeFirstOrderOpt(solution, objective, workingset->nVar,
        workingset->ldA, workingset->ATwset, workingset->nActiveConstr,
        memspace->workspace_float);
      mpc4_B.maxConstr_new = options.OptimalityTolerance *
        runTimeOptions_ProbRelTolFactor;
      if ((solution->iterations < runTimeOptions_MaxIterations) &&
          ((solution->state == -7) || ((solution->state == 1) &&
            ((solution->maxConstr > mpc4_B.d) || (solution->firstorderopt >
              mpc4_B.maxConstr_new))))) {
        mpc4_B.expl_temp_c.ProbRelTolFactor = runTimeOptions_ProbRelTolFactor;
        mpc4_B.expl_temp_c.ConstrRelTolFactor = runTimeOptions_ConstrRelTolFact;
        mpc4_B.expl_temp_c.MaxIterations = runTimeOptions_MaxIterations;
        mpc4_B.expl_temp_c.RemainFeasible = false;
        mpc4_B.expl_temp_f.ProbRelTolFactor = runTimeOptions_ProbRelTolFactor;
        mpc4_B.expl_temp_f.ConstrRelTolFactor = runTimeOptions_ConstrRelTolFact;
        mpc4_B.expl_temp_f.MaxIterations = runTimeOptions_MaxIterations;
        mpc4_B.expl_temp_f.RemainFeasible = false;
      }

      while ((solution->iterations < runTimeOptions_MaxIterations) &&
             ((solution->state == -7) || ((solution->state == 1) &&
               ((solution->maxConstr > mpc4_B.d) || (solution->firstorderopt >
                 mpc4_B.maxConstr_new))))) {
        mpc4_feasibleX0ForWorkingSet(memspace->workspace_float, solution->xstar,
          workingset, qrmanager);
        mpc4_PresolveWorkingSet_e(solution, memspace, workingset, qrmanager,
          &options);
        mpc4_B.i_l = workingset->probType;
        mpc4_B.mConstr = workingset->nVar;
        mpc4_B.idxStartIneq = workingset->nVar;
        solution->xstar[workingset->nVar] = solution->maxConstr + 1.0;
        if (workingset->probType == 3) {
          mpc4_B.idxEndIneq = 1;
        } else {
          mpc4_B.idxEndIneq = 4;
        }

        mpc4_setProblemType(workingset, mpc4_B.idxEndIneq);
        mpc4_B.b_idxStartIneq = (workingset->nWConstr[0] + workingset->nWConstr
          [1]) + 1;
        mpc4_B.b_idxEndIneq = workingset->nActiveConstr;
        for (mpc4_B.idxEndIneq = mpc4_B.b_idxStartIneq; mpc4_B.idxEndIneq <=
             mpc4_B.b_idxEndIneq; mpc4_B.idxEndIneq++) {
          workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
            Wid[mpc4_B.idxEndIneq - 1] - 1] + workingset->
            Wlocalidx[mpc4_B.idxEndIneq - 1]) - 2] = false;
        }

        workingset->nWConstr[2] = 0;
        workingset->nWConstr[3] = 0;
        workingset->nWConstr[4] = 0;
        workingset->nActiveConstr = workingset->nWConstr[0] +
          workingset->nWConstr[1];
        objective->prev_objtype = objective->objtype;
        objective->prev_nvar = objective->nvar;
        objective->prev_hasLinear = objective->hasLinear;
        objective->objtype = 5;
        objective->nvar = mpc4_B.idxStartIneq + 1;
        objective->gammaScalar = 1.0;
        objective->hasLinear = true;
        solution->fstar = solution->xstar[mpc4_B.idxStartIneq];
        solution->state = 5;
        mpc4_iterate(b_H, f, solution, memspace, workingset, qrmanager,
                     cholmanager, objective, options.IterDisplayQP, mpc4_B.d,
                     options.PricingTolerance, options.ConstraintTolerance,
                     1.4901161193847657E-10, mpc4_B.expl_temp_c);
        if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
             workingset->sizes[3]) - 2]) {
          mpc4_B.idxEndIneq = workingset->sizes[0] + workingset->sizes[1];
          exitg1 = false;
          while ((!exitg1) && (mpc4_B.idxEndIneq + 1 <=
                               workingset->nActiveConstr)) {
            if ((workingset->Wid[mpc4_B.idxEndIneq] == 4) &&
                (workingset->Wlocalidx[mpc4_B.idxEndIneq] == workingset->sizes[3]))
            {
              mpc4_removeConstr(workingset, mpc4_B.idxEndIneq + 1);
              exitg1 = true;
            } else {
              mpc4_B.idxEndIneq++;
            }
          }
        }

        mpc4_B.idxEndIneq = workingset->nActiveConstr;
        mpc4_B.b_idxStartIneq = workingset->sizes[0] + workingset->sizes[1];
        while ((mpc4_B.idxEndIneq > mpc4_B.b_idxStartIneq) && (mpc4_B.idxEndIneq
                > mpc4_B.mConstr)) {
          mpc4_removeConstr(workingset, mpc4_B.idxEndIneq);
          mpc4_B.idxEndIneq--;
        }

        solution->maxConstr = solution->xstar[mpc4_B.idxStartIneq];
        mpc4_setProblemType(workingset, mpc4_B.i_l);
        objective->objtype = objective->prev_objtype;
        objective->nvar = objective->prev_nvar;
        objective->hasLinear = objective->prev_hasLinear;
        mpc4_iterate(b_H, f, solution, memspace, workingset, qrmanager,
                     cholmanager, objective, options.IterDisplayQP,
                     options.ObjectiveLimit, options.PricingTolerance,
                     options.ConstraintTolerance, options.StepTolerance,
                     mpc4_B.expl_temp_f);
        solution->maxConstr = mpc4_maxConstraintViolation_n3(workingset,
          solution->xstar);
        mpc4_computeFirstOrderOpt(solution, objective, workingset->nVar,
          workingset->ldA, workingset->ATwset, workingset->nActiveConstr,
          memspace->workspace_float);
      }
    }
  }
}

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

static void mpc4_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj)
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

// Model step function for TID0
void mpc4_step0(void)                  // Sample time: [0.01s, 0.0s]
{
  int8_T ipiv;
  boolean_T b_varargout_1;
  static const int8_T WorkingSet_tmp[5] = { 0, 0, 66, 0, 0 };

  static const int8_T e[5] = { 0, 0, 66, 1, 0 };

  static const int8_T d_varargin_2[6] = { 1, 0, 0, 66, 0, 0 };

  static const int8_T d[5] = { 0, 0, 66, 66, 0 };

  static const int8_T c[5] = { 0, 0, 66, 67, 0 };

  static const int8_T c_varargin_2[6] = { 1, 0, 0, 66, 1, 0 };

  static const int8_T b_varargin_2[6] = { 1, 0, 0, 66, 66, 0 };

  static const int8_T varargin_2[6] = { 1, 0, 0, 66, 67, 0 };

  static const int8_T tmp[16] = { -1, 1, 1, 1, 1, -1, 1, 1, 1, 1, -1, 1, -1, -1,
    -1, 1 };

  {                                    // Sample time: [0.01s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Reset subsysRan breadcrumbs
  srClearBC(mpc4_DW.EnabledSubsystem_SubsysRanBC_p);

  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = uORB_read_step(mpc4_DW.obj_h.orbMetadataObj,
    &mpc4_DW.obj_h.eventStructObj, &mpc4_B.r, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  // Start for MATLABSystem: '<S6>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S7>/In1'
    mpc4_B.In1_m = mpc4_B.r;
    srUpdateBC(mpc4_DW.EnabledSubsystem_SubsysRanBC_p);
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // RateTransition: '<Root>/Rate Transition'
  if (mpc4_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<Root>/Rate Transition'
    mpc4_B.RateTransition[0] = mpc4_DW.RateTransition_Buffer0[0];
    mpc4_B.RateTransition[1] = mpc4_DW.RateTransition_Buffer0[1];
    mpc4_B.RateTransition[2] = mpc4_DW.RateTransition_Buffer0[2];
  }

  // End of RateTransition: '<Root>/Rate Transition'

  // MATLAB Function: '<Root>/MATLAB Function5'
  mpc4_B.x_idx_0 = mpc4_B.In1_m.angular_velocity[0];
  mpc4_B.b_colSum = (mpc4_B.In1_m.angular_velocity[0] - mpc4_B.RateTransition[0])
    * 2.0;
  mpc4_B.x_idx_1 = mpc4_B.In1_m.angular_velocity[1];
  mpc4_B.unnamed_idx_1 = (mpc4_B.In1_m.angular_velocity[1] -
    mpc4_B.RateTransition[1]) * 2.0;
  mpc4_B.f_infnrm = mpc4_B.In1_m.angular_velocity[2];
  mpc4_B.unnamed_idx_2 = (mpc4_B.In1_m.angular_velocity[2] -
    mpc4_B.RateTransition[2]) * 2.0;
  for (mpc4_B.i = 0; mpc4_B.i < 15; mpc4_B.i++) {
    mpc4_B.uvec[mpc4_B.i] = (mpc4_P.F[mpc4_B.i + 15] * mpc4_B.unnamed_idx_1 +
      mpc4_B.b_colSum * mpc4_P.F[mpc4_B.i]) + mpc4_P.F[mpc4_B.i + 30] *
      mpc4_B.unnamed_idx_2;
    mpc4_B.dv[mpc4_B.i] = 0.0;
  }

  for (mpc4_B.i = 0; mpc4_B.i < 15; mpc4_B.i++) {
    mpc4_B.b_colSum = mpc4_B.dv[mpc4_B.i];
    for (mpc4_B.idxFillStart = 0; mpc4_B.idxFillStart < 15; mpc4_B.idxFillStart
         ++) {
      mpc4_B.b_colSum += mpc4_P.Qvec[15 * mpc4_B.i + mpc4_B.idxFillStart] *
        mpc4_B.uvec[mpc4_B.idxFillStart];
    }

    mpc4_B.dv[mpc4_B.i] = mpc4_B.b_colSum;
    mpc4_B.f[mpc4_B.i] = 0.0;
  }

  for (mpc4_B.i = 0; mpc4_B.i < 15; mpc4_B.i++) {
    mpc4_B.b_colSum = mpc4_B.f[mpc4_B.i];
    for (mpc4_B.idxFillStart = 0; mpc4_B.idxFillStart < 15; mpc4_B.idxFillStart
         ++) {
      mpc4_B.b_colSum += mpc4_P.G[15 * mpc4_B.i + mpc4_B.idxFillStart] *
        mpc4_B.dv[mpc4_B.idxFillStart];
    }

    mpc4_B.f[mpc4_B.i] = mpc4_B.b_colSum;
  }

  for (mpc4_B.i = 0; mpc4_B.i < 225; mpc4_B.i++) {
    mpc4_B.b_H[mpc4_B.i] = 2.0 * mpc4_P.H[mpc4_B.i];
  }

  for (mpc4_B.i = 0; mpc4_B.i < 66; mpc4_B.i++) {
    mpc4_B.c_x[mpc4_B.i] = ((mpc4_P.Sc[mpc4_B.i + 66] * mpc4_B.x_idx_1 +
      mpc4_P.Sc[mpc4_B.i] * mpc4_B.x_idx_0) + mpc4_P.Sc[mpc4_B.i + 132] *
      mpc4_B.f_infnrm) + mpc4_P.qc[mpc4_B.i];
  }

  mpc4_B.solution.fstar = 0.0;
  mpc4_B.solution.firstorderopt = 0.0;
  memset(&mpc4_B.solution.lambda[0], 0, 67U * sizeof(real_T));
  mpc4_B.solution.state = 0;
  mpc4_B.solution.maxConstr = 0.0;
  mpc4_B.solution.iterations = 0;
  memset(&mpc4_B.solution.searchDir[0], 0, sizeof(real_T) << 4U);
  memcpy(&mpc4_B.solution.xstar[0], &mpc4_DW.x0[0], 15U * sizeof(real_T));
  mpc4_B.CholRegManager.ldm = 16;
  mpc4_B.CholRegManager.ndims = 0;
  mpc4_B.CholRegManager.info = 0;
  mpc4_B.CholRegManager.ConvexCheck = true;
  mpc4_B.CholRegManager.regTol_ = 0.0;
  mpc4_B.WorkingSet.nVarOrig = 15;
  mpc4_B.WorkingSet.nVarMax = 16;
  mpc4_B.WorkingSet.ldA = 16;
  memset(&mpc4_B.WorkingSet.Aineq[0], 0, 1056U * sizeof(real_T));
  memset(&mpc4_B.WorkingSet.bineq[0], 0, 66U * sizeof(real_T));
  memset(&mpc4_B.WorkingSet.lb[0], 0, sizeof(real_T) << 4U);
  memset(&mpc4_B.WorkingSet.ub[0], 0, sizeof(real_T) << 4U);
  mpc4_B.WorkingSet.mEqRemoved = 0;
  memset(&mpc4_B.WorkingSet.ATwset[0], 0, 1072U * sizeof(real_T));
  memset(&mpc4_B.WorkingSet.bwset[0], 0, 67U * sizeof(real_T));
  memset(&mpc4_B.WorkingSet.maxConstrWorkspace[0], 0, 67U * sizeof(real_T));
  memset(&mpc4_B.WorkingSet.isActiveConstr[0], 0, 67U * sizeof(boolean_T));
  memset(&mpc4_B.WorkingSet.Wid[0], 0, 67U * sizeof(int32_T));
  memset(&mpc4_B.WorkingSet.Wlocalidx[0], 0, 67U * sizeof(int32_T));
  memset(&mpc4_B.WorkingSet.indexLB[0], 0, sizeof(int32_T) << 4U);
  memset(&mpc4_B.WorkingSet.indexUB[0], 0, sizeof(int32_T) << 4U);
  memset(&mpc4_B.WorkingSet.indexFixed[0], 0, sizeof(int32_T) << 4U);
  mpc4_B.WorkingSet.mConstrMax = 67;
  mpc4_B.WorkingSet.mConstrOrig = 66;
  for (mpc4_B.i = 0; mpc4_B.i < 5; mpc4_B.i++) {
    mpc4_B.WorkingSet.sizesNormal[mpc4_B.i] = WorkingSet_tmp[mpc4_B.i];
    mpc4_B.WorkingSet.sizesPhaseOne[mpc4_B.i] = e[mpc4_B.i];
    mpc4_B.WorkingSet.sizesRegularized[mpc4_B.i] = d[mpc4_B.i];
    mpc4_B.WorkingSet.sizesRegPhaseOne[mpc4_B.i] = c[mpc4_B.i];
  }

  for (mpc4_B.i = 0; mpc4_B.i < 6; mpc4_B.i++) {
    mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i] = d_varargin_2[mpc4_B.i];
  }

  for (mpc4_B.colPos = 0; mpc4_B.colPos < 5; mpc4_B.colPos++) {
    mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.colPos + 1] +=
      mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.colPos];
  }

  for (mpc4_B.i = 0; mpc4_B.i < 6; mpc4_B.i++) {
    mpc4_B.WorkingSet.isActiveIdxNormal[mpc4_B.i] =
      mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i];
    mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i] = c_varargin_2[mpc4_B.i];
  }

  for (mpc4_B.i = 0; mpc4_B.i < 5; mpc4_B.i++) {
    mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i + 1] +=
      mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i];
  }

  for (mpc4_B.i = 0; mpc4_B.i < 6; mpc4_B.i++) {
    mpc4_B.WorkingSet.isActiveIdxPhaseOne[mpc4_B.i] =
      mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i];
    mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i] = b_varargin_2[mpc4_B.i];
  }

  for (mpc4_B.i = 0; mpc4_B.i < 5; mpc4_B.i++) {
    mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i + 1] +=
      mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i];
  }

  for (mpc4_B.i = 0; mpc4_B.i < 6; mpc4_B.i++) {
    mpc4_B.WorkingSet.isActiveIdxRegularized[mpc4_B.i] =
      mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i];
    mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i] = varargin_2[mpc4_B.i];
  }

  for (mpc4_B.i = 0; mpc4_B.i < 5; mpc4_B.i++) {
    mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i + 1] +=
      mpc4_B.WorkingSet.isActiveIdxRegPhaseOne[mpc4_B.i];
  }

  for (mpc4_B.i = 0; mpc4_B.i < 15; mpc4_B.i++) {
    for (mpc4_B.idxFillStart = 0; mpc4_B.idxFillStart < 66; mpc4_B.idxFillStart
         ++) {
      mpc4_B.WorkingSet.Aineq[mpc4_B.i + (mpc4_B.idxFillStart << 4)] =
        mpc4_P.Pc[66 * mpc4_B.i + mpc4_B.idxFillStart];
    }
  }

  memcpy(&mpc4_B.WorkingSet.bineq[0], &mpc4_B.c_x[0], 66U * sizeof(real_T));
  mpc4_B.WorkingSet.nVar = 15;
  mpc4_B.WorkingSet.mConstr = 66;
  for (mpc4_B.i = 0; mpc4_B.i < 5; mpc4_B.i++) {
    mpc4_B.WorkingSet.sizes[mpc4_B.i] = mpc4_B.WorkingSet.sizesNormal[mpc4_B.i];
  }

  for (mpc4_B.i = 0; mpc4_B.i < 6; mpc4_B.i++) {
    mpc4_B.WorkingSet.isActiveIdx[mpc4_B.i] =
      mpc4_B.WorkingSet.isActiveIdxNormal[mpc4_B.i];
  }

  mpc4_B.WorkingSet.probType = 3;
  mpc4_B.idxFillStart = mpc4_B.WorkingSet.isActiveIdx[2];
  for (mpc4_B.i = mpc4_B.idxFillStart; mpc4_B.i < 68; mpc4_B.i++) {
    mpc4_B.WorkingSet.isActiveConstr[mpc4_B.i - 1] = false;
  }

  mpc4_B.WorkingSet.nWConstr[0] = 0;
  mpc4_B.WorkingSet.nWConstr[1] = 0;
  mpc4_B.WorkingSet.nWConstr[2] = 0;
  mpc4_B.WorkingSet.nWConstr[3] = 0;
  mpc4_B.WorkingSet.nWConstr[4] = 0;
  mpc4_B.WorkingSet.nActiveConstr = 0;
  mpc4_B.WorkingSet.SLACK0 = 0.0;
  mpc4_B.x_idx_0 = 1.0;
  for (mpc4_B.i = 0; mpc4_B.i < 66; mpc4_B.i++) {
    mpc4_B.x_idx_1 = 0.0;
    mpc4_B.colPos = mpc4_B.i << 4;
    for (mpc4_B.idxFillStart = 0; mpc4_B.idxFillStart < 15; mpc4_B.idxFillStart
         ++) {
      mpc4_B.x_idx_1 += fabs(mpc4_B.WorkingSet.Aineq[mpc4_B.idxFillStart +
        mpc4_B.colPos]);
    }

    if ((!(mpc4_B.x_idx_0 >= mpc4_B.x_idx_1)) && (!rtIsNaN(mpc4_B.x_idx_1))) {
      mpc4_B.x_idx_0 = mpc4_B.x_idx_1;
    }
  }

  mpc4_B.x_idx_1 = 0.0;
  mpc4_B.f_infnrm = 0.0;
  for (mpc4_B.i = 0; mpc4_B.i < 15; mpc4_B.i++) {
    mpc4_B.b_colSum = 0.0;
    for (mpc4_B.idxFillStart = 0; mpc4_B.idxFillStart < 15; mpc4_B.idxFillStart
         ++) {
      mpc4_B.b_colSum += fabs(mpc4_B.b_H[15 * mpc4_B.i + mpc4_B.idxFillStart]);
    }

    if ((!(mpc4_B.x_idx_1 >= mpc4_B.b_colSum)) && (!rtIsNaN(mpc4_B.b_colSum))) {
      mpc4_B.x_idx_1 = mpc4_B.b_colSum;
    }

    mpc4_B.b_colSum = fabs(mpc4_B.f[mpc4_B.i]);
    if ((!(mpc4_B.f_infnrm >= mpc4_B.b_colSum)) && (!rtIsNaN(mpc4_B.b_colSum)))
    {
      mpc4_B.f_infnrm = mpc4_B.b_colSum;
    }
  }

  if (mpc4_B.x_idx_0 >= mpc4_B.f_infnrm) {
    mpc4_B.f_infnrm = mpc4_B.x_idx_0;
  }

  if (mpc4_B.f_infnrm >= mpc4_B.x_idx_1) {
    mpc4_B.x_idx_1 = mpc4_B.f_infnrm;
  }

  mpc4_B.CholRegManager.scaleFactor = mpc4_B.x_idx_1;
  if (mpc4_DW.opts.StepTolerance < 0.0) {
    mpc4_B.expl_temp.StepTolerance = 1.0E-8;
  } else {
    mpc4_B.expl_temp.StepTolerance = mpc4_DW.opts.StepTolerance;
  }

  if (mpc4_DW.opts.OptimalityTolerance < 0.0) {
    mpc4_B.expl_temp.OptimalityTolerance = 1.0E-8;
  } else {
    mpc4_B.expl_temp.OptimalityTolerance = mpc4_DW.opts.OptimalityTolerance;
  }

  if (mpc4_DW.opts.ConstraintTolerance < 0.0) {
    mpc4_B.expl_temp.ConstraintTolerance = 1.0E-8;
  } else {
    mpc4_B.expl_temp.ConstraintTolerance = mpc4_DW.opts.ConstraintTolerance;
  }

  mpc4_B.expl_temp.PricingTolerance = mpc4_DW.opts.PricingTolerance;
  mpc4_B.expl_temp.ObjectiveLimit = mpc4_DW.opts.ObjectiveLimit;
  mpc4_B.expl_temp.IterDisplayQP = mpc4_DW.opts.IterDisplayQP;
  mpc4_B.expl_temp.NonFiniteSupport = mpc4_DW.opts.NonFiniteSupport;
  for (mpc4_B.i = 0; mpc4_B.i < 8; mpc4_B.i++) {
    mpc4_B.expl_temp.SolverName[mpc4_B.i] = mpc4_DW.opts.SolverName[mpc4_B.i];
  }

  if (mpc4_DW.opts.MaxIterations < 0.0) {
    mpc4_B.i = 810;
  } else {
    mpc4_B.i = static_cast<int32_T>(mpc4_DW.opts.MaxIterations);
  }

  mpc4_driver(mpc4_B.b_H, mpc4_B.f, &mpc4_B.solution, &mpc4_B.memspace,
              &mpc4_B.WorkingSet, &mpc4_B.CholRegManager, mpc4_B.expl_temp,
              mpc4_B.i, mpc4_B.x_idx_0, mpc4_B.x_idx_1, &mpc4_B.QRManager,
              &mpc4_B.QPObjective);
  memcpy(&mpc4_B.uvec[0], &mpc4_B.solution.xstar[0], 15U * sizeof(real_T));
  if (mpc4_B.solution.state <= 0) {
    mpc4_computeFval(&mpc4_B.QPObjective, mpc4_B.memspace.workspace_float,
                     mpc4_B.b_H, mpc4_B.f, mpc4_B.solution.xstar);
  }

  switch (mpc4_B.solution.state) {
   case 2:
    mpc4_B.solution.state = -3;
    break;

   case -3:
    mpc4_B.solution.state = -2;
    break;

   case 4:
    mpc4_B.solution.state = -2;
    break;
  }

  if (mpc4_B.solution.state > 0) {
    mpc4_B.u[0] = mpc4_B.uvec[0];
    mpc4_DW.u_prev[0] = mpc4_B.uvec[0];
    mpc4_B.u[1] = mpc4_B.uvec[1];
    mpc4_DW.u_prev[1] = mpc4_B.uvec[1];
    mpc4_B.u[2] = mpc4_B.uvec[2];
    mpc4_DW.u_prev[2] = mpc4_B.uvec[2];
    memcpy(&mpc4_DW.x0[0], &mpc4_B.uvec[0], 15U * sizeof(real_T));
  } else {
    mpc4_B.u[0] = mpc4_DW.u_prev[0];
    mpc4_B.u[1] = mpc4_DW.u_prev[1];
    mpc4_B.u[2] = mpc4_DW.u_prev[2];
  }

  // End of MATLAB Function: '<Root>/MATLAB Function5'
  // MATLAB Function: '<Root>/MATLAB Function'
  mpc4_B.B_c[0] = mpc4_B.u[0];
  mpc4_B.B_c[1] = mpc4_B.u[1];
  mpc4_B.B_c[2] = mpc4_B.u[2];
  mpc4_B.B_c[3] = 0.0;
  for (mpc4_B.i = 0; mpc4_B.i < 16; mpc4_B.i++) {
    mpc4_B.A[mpc4_B.i] = tmp[mpc4_B.i];
  }

  mpc4_B.ipiv[0] = 1;
  mpc4_B.ipiv[1] = 2;
  mpc4_B.ipiv[2] = 3;
  mpc4_B.ipiv[3] = 4;
  for (mpc4_B.i = 0; mpc4_B.i < 3; mpc4_B.i++) {
    mpc4_B.idxFillStart = mpc4_B.i * 5;
    mpc4_B.n = 5 - mpc4_B.i;
    mpc4_B.a_n = 0;
    mpc4_B.x_idx_0 = fabs(mpc4_B.A[mpc4_B.idxFillStart]);
    for (mpc4_B.colPos = 2; mpc4_B.colPos < mpc4_B.n; mpc4_B.colPos++) {
      mpc4_B.x_idx_1 = fabs(mpc4_B.A[(mpc4_B.idxFillStart + mpc4_B.colPos) - 1]);
      if (mpc4_B.x_idx_1 > mpc4_B.x_idx_0) {
        mpc4_B.a_n = mpc4_B.colPos - 1;
        mpc4_B.x_idx_0 = mpc4_B.x_idx_1;
      }
    }

    if (mpc4_B.A[mpc4_B.idxFillStart + mpc4_B.a_n] != 0.0) {
      if (mpc4_B.a_n != 0) {
        mpc4_B.colPos = mpc4_B.i + mpc4_B.a_n;
        mpc4_B.ipiv[mpc4_B.i] = static_cast<int8_T>(mpc4_B.colPos + 1);
        mpc4_B.x_idx_0 = mpc4_B.A[mpc4_B.i];
        mpc4_B.A[mpc4_B.i] = mpc4_B.A[mpc4_B.colPos];
        mpc4_B.A[mpc4_B.colPos] = mpc4_B.x_idx_0;
        mpc4_B.x_idx_0 = mpc4_B.A[mpc4_B.i + 4];
        mpc4_B.A[mpc4_B.i + 4] = mpc4_B.A[mpc4_B.colPos + 4];
        mpc4_B.A[mpc4_B.colPos + 4] = mpc4_B.x_idx_0;
        mpc4_B.x_idx_0 = mpc4_B.A[mpc4_B.i + 8];
        mpc4_B.A[mpc4_B.i + 8] = mpc4_B.A[mpc4_B.colPos + 8];
        mpc4_B.A[mpc4_B.colPos + 8] = mpc4_B.x_idx_0;
        mpc4_B.x_idx_0 = mpc4_B.A[mpc4_B.i + 12];
        mpc4_B.A[mpc4_B.i + 12] = mpc4_B.A[mpc4_B.colPos + 12];
        mpc4_B.A[mpc4_B.colPos + 12] = mpc4_B.x_idx_0;
      }

      mpc4_B.n = (mpc4_B.idxFillStart - mpc4_B.i) + 4;
      for (mpc4_B.colPos = mpc4_B.idxFillStart + 2; mpc4_B.colPos <= mpc4_B.n;
           mpc4_B.colPos++) {
        mpc4_B.A[mpc4_B.colPos - 1] /= mpc4_B.A[mpc4_B.idxFillStart];
      }
    }

    mpc4_B.a_n = 2 - mpc4_B.i;
    mpc4_B.jA = mpc4_B.idxFillStart + 6;
    for (mpc4_B.colPos = 0; mpc4_B.colPos <= mpc4_B.a_n; mpc4_B.colPos++) {
      mpc4_B.b_colSum = mpc4_B.A[((mpc4_B.colPos << 2) + mpc4_B.idxFillStart) +
        4];
      if (mpc4_B.b_colSum != 0.0) {
        mpc4_B.c_b = (mpc4_B.jA - mpc4_B.i) + 2;
        for (mpc4_B.n = mpc4_B.jA; mpc4_B.n <= mpc4_B.c_b; mpc4_B.n++) {
          mpc4_B.A[mpc4_B.n - 1] += mpc4_B.A[((mpc4_B.idxFillStart + mpc4_B.n) -
            mpc4_B.jA) + 1] * -mpc4_B.b_colSum;
        }
      }

      mpc4_B.jA += 4;
    }

    ipiv = mpc4_B.ipiv[mpc4_B.i];
    if (mpc4_B.i + 1 != ipiv) {
      mpc4_B.x_idx_0 = mpc4_B.B_c[mpc4_B.i];
      mpc4_B.B_c[mpc4_B.i] = mpc4_B.B_c[ipiv - 1];
      mpc4_B.B_c[ipiv - 1] = mpc4_B.x_idx_0;
    }
  }

  for (mpc4_B.i = 0; mpc4_B.i < 4; mpc4_B.i++) {
    mpc4_B.colPos = mpc4_B.i << 2;
    if (mpc4_B.B_c[mpc4_B.i] != 0.0) {
      for (mpc4_B.idxFillStart = mpc4_B.i + 2; mpc4_B.idxFillStart < 5;
           mpc4_B.idxFillStart++) {
        mpc4_B.B_c[mpc4_B.idxFillStart - 1] -= mpc4_B.A[(mpc4_B.idxFillStart +
          mpc4_B.colPos) - 1] * mpc4_B.B_c[mpc4_B.i];
      }
    }
  }

  for (mpc4_B.i = 3; mpc4_B.i >= 0; mpc4_B.i--) {
    mpc4_B.colPos = mpc4_B.i << 2;
    mpc4_B.x_idx_0 = mpc4_B.B_c[mpc4_B.i];
    if (mpc4_B.x_idx_0 != 0.0) {
      mpc4_B.B_c[mpc4_B.i] = mpc4_B.x_idx_0 / mpc4_B.A[mpc4_B.i + mpc4_B.colPos];
      for (mpc4_B.idxFillStart = 0; mpc4_B.idxFillStart < mpc4_B.i;
           mpc4_B.idxFillStart++) {
        mpc4_B.B_c[mpc4_B.idxFillStart] -= mpc4_B.A[mpc4_B.idxFillStart +
          mpc4_B.colPos] * mpc4_B.B_c[mpc4_B.i];
      }
    }
  }

  mpc4_B.M4 = mpc4_B.B_c[3] + 0.2548;

  // Saturate: '<Root>/Saturation' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function'

  if (mpc4_B.B_c[0] + 0.1344 > mpc4_P.Saturation_UpperSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion3'
    mpc4_B.DataTypeConversion3 = static_cast<real32_T>
      (mpc4_P.Saturation_UpperSat);
  } else if (mpc4_B.B_c[0] + 0.1344 < mpc4_P.Saturation_LowerSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion3'
    mpc4_B.DataTypeConversion3 = static_cast<real32_T>
      (mpc4_P.Saturation_LowerSat);
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion3'
    mpc4_B.DataTypeConversion3 = static_cast<real32_T>(mpc4_B.B_c[0] + 0.1344);
  }

  // End of Saturate: '<Root>/Saturation'

  // Saturate: '<Root>/Saturation1' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function'

  if (mpc4_B.B_c[1] + 0.2078 > mpc4_P.Saturation1_UpperSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion2'
    mpc4_B.DataTypeConversion2 = static_cast<real32_T>
      (mpc4_P.Saturation1_UpperSat);
  } else if (mpc4_B.B_c[1] + 0.2078 < mpc4_P.Saturation1_LowerSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion2'
    mpc4_B.DataTypeConversion2 = static_cast<real32_T>
      (mpc4_P.Saturation1_LowerSat);
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion2'
    mpc4_B.DataTypeConversion2 = static_cast<real32_T>(mpc4_B.B_c[1] + 0.2078);
  }

  // End of Saturate: '<Root>/Saturation1'

  // Saturate: '<Root>/Saturation2' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function'

  if (mpc4_B.B_c[2] + 0.1551 > mpc4_P.Saturation2_UpperSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion1'
    mpc4_B.DataTypeConversion1 = static_cast<real32_T>
      (mpc4_P.Saturation2_UpperSat);
  } else if (mpc4_B.B_c[2] + 0.1551 < mpc4_P.Saturation2_LowerSat) {
    // DataTypeConversion: '<Root>/Data Type Conversion1'
    mpc4_B.DataTypeConversion1 = static_cast<real32_T>
      (mpc4_P.Saturation2_LowerSat);
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion1'
    mpc4_B.DataTypeConversion1 = static_cast<real32_T>(mpc4_B.B_c[2] + 0.1551);
  }

  // End of Saturate: '<Root>/Saturation2'

  // MATLABSystem: '<Root>/PX4 Actuator Write'
  for (mpc4_B.i = 0; mpc4_B.i < 12; mpc4_B.i++) {
    mpc4_B.motorValues[mpc4_B.i] = (rtNaNF);
  }

  for (mpc4_B.i = 0; mpc4_B.i < 8; mpc4_B.i++) {
    mpc4_B.servoValues[mpc4_B.i] = (rtNaNF);
  }

  mpc4_B.motorValues[0] = mpc4_B.DataTypeConversion3;
  mpc4_B.motorValues[1] = mpc4_B.DataTypeConversion2;
  mpc4_B.motorValues[2] = mpc4_B.DataTypeConversion1;

  // Saturate: '<Root>/Saturation3'
  if (mpc4_B.M4 > mpc4_P.Saturation3_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion'

    mpc4_B.motorValues[3] = static_cast<real32_T>(mpc4_P.Saturation3_UpperSat);
  } else if (mpc4_B.M4 < mpc4_P.Saturation3_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion'

    mpc4_B.motorValues[3] = static_cast<real32_T>(mpc4_P.Saturation3_LowerSat);
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion'

    mpc4_B.motorValues[3] = static_cast<real32_T>(mpc4_B.M4);
  }

  // End of Saturate: '<Root>/Saturation3'

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant1'

  if (mpc4_P.ManualSwitch_CurrentSetting == 1) {
    b_varargout_1 = mpc4_P.Constant_Value_h;
  } else {
    b_varargout_1 = mpc4_P.Constant1_Value;
  }

  // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
  //   ManualSwitch: '<Root>/Manual Switch'

  MW_actuators_set(b_varargout_1, &mpc4_B.motorValues[0], &mpc4_B.servoValues[0]);

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  mpc4_M->Timing.taskTime0 =
    ((time_T)(++mpc4_M->Timing.clockTick0)) * mpc4_M->Timing.stepSize0;
}

// Model step function for TID1
void mpc4_step1(void)                  // Sample time: [0.05s, 0.0s]
{
  boolean_T b_varargout_1;

  // Reset subsysRan breadcrumbs
  srClearBC(mpc4_DW.EnabledSubsystem_SubsysRanBC);

  // MATLABSystem: '<S8>/SourceBlock'
  b_varargout_1 = uORB_read_step(mpc4_DW.obj_l.orbMetadataObj,
    &mpc4_DW.obj_l.eventStructObj, &mpc4_B.r1, false, 1.0);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  // Start for MATLABSystem: '<S8>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S9>/In1'
    mpc4_B.In1 = mpc4_B.r1;
    srUpdateBC(mpc4_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'

  // RateTransition: '<Root>/Rate Transition' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'
  //   Gain: '<Root>/Gain'
  //   Gain: '<Root>/Gain1'
  //   MATLAB Function: '<Root>/quat2eul'
  //   Sum: '<Root>/Sum'
  //   Sum: '<Root>/Sum1'

  mpc4_DW.RateTransition_Buffer0[0] = (mpc4_P.Constant2_Value - rt_atan2f_snf
    ((mpc4_B.In1.q[0] * mpc4_B.In1.q[1] + mpc4_B.In1.q[2] * mpc4_B.In1.q[3]) *
     2.0F, ((mpc4_B.In1.q[0] * mpc4_B.In1.q[0] - mpc4_B.In1.q[1] * mpc4_B.In1.q
             [1]) - mpc4_B.In1.q[2] * mpc4_B.In1.q[2]) + mpc4_B.In1.q[3] *
     mpc4_B.In1.q[3])) * mpc4_P.Gain_Gain;
  mpc4_DW.RateTransition_Buffer0[1] = (mpc4_P.Constant3_Value -
    static_cast<real32_T>(asin(static_cast<real_T>((mpc4_B.In1.q[1] *
    mpc4_B.In1.q[3] - mpc4_B.In1.q[0] * mpc4_B.In1.q[2]) * -2.0F)))) *
    mpc4_P.Gain1_Gain;
  mpc4_DW.RateTransition_Buffer0[2] = mpc4_P.Constant4_Value;

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.05, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  mpc4_M->Timing.clockTick1++;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void mpc4_step(int_T tid)
{
  switch (tid) {
   case 0 :
    mpc4_step0();
    break;

   case 1 :
    mpc4_step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void mpc4_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(mpc4_M, -1);
  mpc4_M->Timing.stepSize0 = 0.01;

  // External mode info
  mpc4_M->Sizes.checksums[0] = (2461377153U);
  mpc4_M->Sizes.checksums[1] = (3449250836U);
  mpc4_M->Sizes.checksums[2] = (3909353088U);
  mpc4_M->Sizes.checksums[3] = (41662716U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    mpc4_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)&mpc4_DW.EnabledSubsystem_SubsysRanBC_p;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)&mpc4_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(mpc4_M->extModeInfo,
      &mpc4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(mpc4_M->extModeInfo, mpc4_M->Sizes.checksums);
    rteiSetTPtr(mpc4_M->extModeInfo, rtmGetTPtr(mpc4_M));
  }

  // block I/O
  (void) memset((static_cast<void *>(&mpc4_B)), 0,
                sizeof(B_mpc4_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&mpc4_DW), 0,
                sizeof(DW_mpc4_T));

  {
    int32_T i;
    static sCBS0Ia3qD76sOwKERvBoFE_mpc4_T tmp = { true,// NonFiniteSupport
      false,                           // IterDisplaySQP
      0.01,                            // InitDamping

      { 'f', 'o', 'r', 'w', 'a', 'r', 'd' },// FiniteDifferenceType
      false,                           // SpecifyObjectiveGradient
      false,                           // ScaleProblem
      false,                           // SpecifyConstraintGradient
      -1.0,                            // FiniteDifferenceStepSize
      -1.0,                            // MaxFunctionEvaluations
      false,                           // IterDisplayQP
      0.0,                             // PricingTolerance

      { 'a', 'c', 't', 'i', 'v', 'e', '-', 's', 'e', 't' },// Algorithm
      -1.0E+20,                        // ObjectiveLimit
      -1.0,                            // ConstraintTolerance
      -1.0,                            // OptimalityTolerance
      -1.0,                            // StepTolerance
      -1.0,                            // MaxIterations
      0.0,                             // FunctionTolerance

      { 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' },// SolverName

      { 'o', 'f', 'f' },               // Display
      false,                           // UseCodegenSolver
      false,                           // CheckGradients

      { 'o', 'f', 'f' },               // Diagnostics
      0.0,                             // DiffMaxChange
      0.0,                             // DiffMinChange

      { 'o', 'f', 'f' },               // FunValCheck
      false,                           // UseParallel

      { 'a', 'u', 't', 'o' },          // LinearSolver

      { 'c', 'g' }                     // SubproblemAlgorithm
    };

    // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function5'
    tmp.DiffMaxChange = (rtInf);
    tmp.FunctionTolerance = (rtInf);

    // Start for RateTransition: '<Root>/Rate Transition'
    mpc4_B.RateTransition[0] = mpc4_P.RateTransition_InitialCondition;
    mpc4_B.RateTransition[1] = mpc4_P.RateTransition_InitialCondition;
    mpc4_B.RateTransition[2] = mpc4_P.RateTransition_InitialCondition;

    // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function5'
    mpc4_DW.opts = tmp;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition'
    mpc4_DW.RateTransition_Buffer0[0] = mpc4_P.RateTransition_InitialCondition;

    // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function5'
    mpc4_DW.u_prev[0] = 0.0;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition'
    mpc4_DW.RateTransition_Buffer0[1] = mpc4_P.RateTransition_InitialCondition;

    // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function5'
    mpc4_DW.u_prev[1] = 0.0;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition'
    mpc4_DW.RateTransition_Buffer0[2] = mpc4_P.RateTransition_InitialCondition;

    // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function5'
    mpc4_DW.u_prev[2] = 0.0;
    memset(&mpc4_DW.x0[0], 0, 15U * sizeof(real_T));

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S7>/In1' incorporates:
    //   Outport: '<S7>/Out1'

    mpc4_B.In1_m = mpc4_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S9>/In1' incorporates:
    //   Outport: '<S9>/Out1'

    mpc4_B.In1 = mpc4_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    mpc4_DW.obj_h.matlabCodegenIsDeleted = false;
    mpc4_DW.obj_h.isSetupComplete = false;
    mpc4_DW.obj_h.isInitialized = 1;
    mpc4_DW.obj_h.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(mpc4_DW.obj_h.orbMetadataObj,
                         &mpc4_DW.obj_h.eventStructObj);
    mpc4_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    for (i = 0; i < 12; i++) {
      mpc4_DW.obj.ValidMotorIdx[i] = false;
    }

    for (i = 0; i < 8; i++) {
      mpc4_DW.obj.ValidServoIdx[i] = false;
    }

    mpc4_DW.obj.matlabCodegenIsDeleted = false;
    mpc4_DW.obj.isSetupComplete = false;
    mpc4_DW.obj.isInitialized = 1;
    mpc4_PX4Actuators_setupImpl(&mpc4_DW.obj);
    mpc4_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/PX4 Actuator Write'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    mpc4_DW.obj_l.matlabCodegenIsDeleted = false;
    mpc4_DW.obj_l.isSetupComplete = false;
    mpc4_DW.obj_l.isInitialized = 1;
    mpc4_DW.obj_l.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(mpc4_DW.obj_l.orbMetadataObj,
                         &mpc4_DW.obj_l.eventStructObj);
    mpc4_DW.obj_l.isSetupComplete = true;
  }
}

// Model terminate function
void mpc4_terminate(void)
{
  int32_T i;
  real32_T servoValues[8];

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!mpc4_DW.obj_h.matlabCodegenIsDeleted) {
    mpc4_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((mpc4_DW.obj_h.isInitialized == 1) && mpc4_DW.obj_h.isSetupComplete) {
      uORB_read_terminate(&mpc4_DW.obj_h.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  if (!mpc4_DW.obj.matlabCodegenIsDeleted) {
    mpc4_DW.obj.matlabCodegenIsDeleted = true;
    if ((mpc4_DW.obj.isInitialized == 1) && mpc4_DW.obj.isSetupComplete) {
      for (i = 0; i < 12; i++) {
        mpc4_B.motorValues_k[i] = (rtNaNF);
      }

      for (i = 0; i < 8; i++) {
        servoValues[i] = (rtNaNF);
      }

      for (i = 0; i < 12; i++) {
        if (mpc4_DW.obj.ValidMotorIdx[i]) {
          mpc4_B.motorValues_k[i] = 0.0F;
        }
      }

      for (i = 0; i < 8; i++) {
        if (mpc4_DW.obj.ValidServoIdx[i]) {
          servoValues[i] = 0.0F;
        }
      }

      MW_actuators_set(false, &mpc4_B.motorValues_k[0], &servoValues[0]);
      MW_actuators_terminate();
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!mpc4_DW.obj_l.matlabCodegenIsDeleted) {
    mpc4_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((mpc4_DW.obj_l.isInitialized == 1) && mpc4_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&mpc4_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
