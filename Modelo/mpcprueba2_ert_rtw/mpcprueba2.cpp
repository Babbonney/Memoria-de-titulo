//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mpcprueba2.cpp
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
#include "mpcprueba2.h"
#include "rtwtypes.h"
#include "mpcprueba2_types.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "mpcprueba2_private.h"

// Block signals (default storage)
B_mpcprueba2_T mpcprueba2_B;

// Block states (default storage)
DW_mpcprueba2_T mpcprueba2_DW;

// Real-time model
RT_MODEL_mpcprueba2_T mpcprueba2_M_ = RT_MODEL_mpcprueba2_T();
RT_MODEL_mpcprueba2_T *const mpcprueba2_M = &mpcprueba2_M_;

// Forward declaration for local functions
static boolean_T mpcprueba2_strcmp(const char_T a[8]);
static real_T mpcprueba2_xnrm2_l(int32_T n, const real_T x[1072], int32_T ix0);
static real_T mpcprueba2_rt_hypotd_snf(real_T u0, real_T u1);
static real_T mpcprueba2_xzlarfg(int32_T n, real_T *alpha1, real_T x[1072],
  int32_T ix0);
static void mpcprueba2_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C[1072], int32_T ic0, real_T work[67]);
static void mpcprueba2_qrf(real_T A[1072], int32_T ia0, int32_T m, int32_T n,
  int32_T nfxd, real_T tau[16]);
static void mpcprueba2_xgeqp3(real_T A[1072], int32_T m, int32_T n, int32_T
  jpvt[67], real_T tau[16]);
static void mpcprueba2_computeQ_(ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *obj, int32_T
  nrows);
static int32_T mpcprueb_ComputeNumDependentEq_(ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T
  *qrmanager, const real_T beqf[67], int32_T mConstr, int32_T nVar);
static void mpcprueba2_IndexOfDependentEq_(int32_T depIdx[67], int32_T mFixed,
  int32_T nDep, ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager, int32_T mRows,
  int32_T nCols);
static void mpcprueba2_countsort(int32_T x[67], int32_T xLen, int32_T workspace
  [67], int32_T xMin, int32_T xMax);
static void mpcprueba2_removeConstr(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *obj,
  int32_T idx_global);
static void mpcprueba2_removeEqConstr(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *obj,
  int32_T idx_global);
static void mpcprueba2_RemoveDependentIneq_(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
  *workingset, ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager,
  sFevNsrsl34D5b5aqm3qNjD_mpcpr_T *memspace, real_T tolfactor);
static int32_T mpcprueba2_rank(const real_T qrmanager_QR[1072], int32_T
  qrmanager_mrows, int32_T qrmanager_ncols);
static void mpcprueba2_xgemv(int32_T m, int32_T n, const real_T A[1056], int32_T
  lda, const real_T x[1072], real_T y[67]);
static real_T mpcprueb_maxConstraintViolation(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
  *obj, const real_T x[1072]);
static void mpcprueba2_xgemv_j(int32_T m, int32_T n, const real_T A[1056],
  int32_T lda, const real_T x[1072], real_T y[67]);
static real_T mpcpru_maxConstraintViolation_n(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
  *obj, const real_T x[1072]);
static boolean_T mpcprue_feasibleX0ForWorkingSet(real_T workspace[1072], real_T
  xCurrent[16], sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager);
static void mpcprueba2_xgemv_j3(int32_T m, int32_T n, const real_T A[1056],
  int32_T lda, const real_T x[16], real_T y[67]);
static real_T mpcpr_maxConstraintViolation_n3(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
  *obj, const real_T x[16]);
static void mpcprueba2_PresolveWorkingSet(sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T
  *solution, sFevNsrsl34D5b5aqm3qNjD_mpcpr_T *memspace,
  sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *workingset, const
  sqZVQFgLZG74FDpCArykMHB_mpcpr_T *options, ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T
  *qrmanager);
static void mpcprue_modifyOverheadPhaseOne_(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *obj);
static void mpcprueba2_setProblemType(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *obj,
  int32_T PROBLEM_TYPE);
static void mpcprueba2_xgemv_j30(int32_T m, int32_T n, const real_T A[225],
  int32_T lda, const real_T x[16], real_T y[15]);
static void mpcprueba2_computeGrad_StoreHx(s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *obj,
  const real_T b_H[225], const real_T f[15], const real_T x[16]);
static real_T mpcprueba2_computeFval_ReuseHx(const
  s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *obj, real_T workspace[1072], const real_T f
  [15], const real_T x[16]);
static void mpcprueba2_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void mpcprueba2_squareQ_appendCol(ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *obj,
  const real_T vec[1072], int32_T iv0);
static void mpcprueba2_deleteColMoveEnd(ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *obj,
  int32_T idx);
static int32_T mpcprueba2_ixamax(int32_T n, const real_T x[256], int32_T incx);
static void mpcprueba2_fullColLDL2_(sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T *obj,
  int32_T LD_offset, int32_T NColsRemain, real_T REG_PRIMAL);
static void mpcprueba2_xgemv_j30b(int32_T m, int32_T n, const real_T A[256],
  int32_T ia0, int32_T lda, const real_T x[1072], real_T y[16]);
static void mpcprueba2_compute_deltax(const real_T b_H[225],
  sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpcpr_T
  *memspace, const ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager,
  sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T *cholmanager, const
  s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *objective);
static real_T mpcprueba2_xnrm2_ls(int32_T n, const real_T x[16]);
static void mpcprueba2_xgemv_j30bu(int32_T m, int32_T n, const real_T A[1056],
  int32_T lda, const real_T x[16], real_T y[1072]);
static void mpcprueba2_xgemv_j30bul(int32_T m, int32_T n, const real_T A[1056],
  int32_T lda, const real_T x[16], real_T y[1072]);
static void mpcprueba2_ratiotest(const real_T solution_xstar[16], const real_T
  solution_searchDir[16], real_T workspace[1072], int32_T workingset_nVar,
  int32_T workingset_ldA, const real_T workingset_Aineq[1056], const real_T
  workingset_bineq[66], const real_T workingset_lb[16], const real_T
  workingset_ub[16], const int32_T workingset_indexLB[16], const int32_T
  workingset_indexUB[16], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[67],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T tolcon,
  real_T *toldelta, real_T *alpha, boolean_T *newBlocking, int32_T *constrType,
  int32_T *constrIdx);
static void mpcprueba2_feasibleratiotest(const real_T solution_xstar[16], const
  real_T solution_searchDir[16], real_T workspace[1072], int32_T workingset_nVar,
  int32_T workingset_ldA, const real_T workingset_Aineq[1056], const real_T
  workingset_bineq[66], const real_T workingset_lb[16], const real_T
  workingset_ub[16], const int32_T workingset_indexLB[16], const int32_T
  workingset_indexUB[16], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[67],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T tolcon,
  real_T *alpha, boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx);
static void mpcp_addBoundToActiveSetMatrix_(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *obj,
  int32_T TYPE, int32_T idx_local);
static void mpcprueba2_compute_lambda(real_T workspace[1072],
  sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T *solution, const
  s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *objective, const
  ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager);
static void mpcp_checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f[15], sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T *solution,
  sFevNsrsl34D5b5aqm3qNjD_mpcpr_T *memspace, const
  s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *objective, sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
  *workingset, ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager, real_T
  options_ObjectiveLimit, real_T options_ConstraintTolerance, int32_T
  runTimeOptions_MaxIterations, real_T runTimeOptions_ConstrRelTolFact,
  boolean_T *updateFval, boolean_T iterDisplayQP);
static void mpcprueba2_computeFirstOrderOpt(sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T
  *solution, const s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *objective, int32_T
  workingset_nVar, int32_T workingset_ldA, const real_T workingset_ATwset[1072],
  int32_T workingset_nActiveConstr, real_T workspace[1072]);
static void mpcprueba2_iterate(const real_T b_H[225], const real_T f[15],
  sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpcpr_T
  *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager, sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T
  *cholmanager, s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *objective, boolean_T
  options_IterDisplayQP, real_T options_ObjectiveLimit, real_T
  options_PricingTolerance, real_T options_ConstraintTolerance, real_T
  options_StepTolerance, const sIOJhD9KwAkF5sEguPjYquC_mpcpr_T runTimeOptions);
static void mpcprueba2_PresolveWorkingSet_e(sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T
  *solution, sFevNsrsl34D5b5aqm3qNjD_mpcpr_T *memspace,
  sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *workingset, ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T
  *qrmanager, const sqZVQFgLZG74FDpCArykMHB_mpcpr_T *options);
static void mpcprueba2_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace[1072], const real_T b_H[225], const real_T f[15], const
  real_T x[16]);
static real_T mpcprueba2_computeFval(const s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *obj,
  real_T workspace[1072], const real_T b_H[225], const real_T f[15], const
  real_T x[16]);
static void mpcprueba2_driver(const real_T b_H[225], const real_T f[15],
  sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpcpr_T
  *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *workingset,
  sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T *cholmanager, const
  sqZVQFgLZG74FDpCArykMHB_mpcpr_T options, int32_T runTimeOptions_MaxIterations,
  real_T runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
  ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager, s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T
  *objective);
static real_T mpcprueba2_xnrm2(int32_T n, const real_T x[12], int32_T ix0);
static void mpcprueba2_mldivide(const real_T A[12], const real_T B[3], real_T Y
  [4]);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static boolean_T mpcprueba2_strcmp(const char_T a[8])
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
static real_T mpcprueba2_xnrm2_l(int32_T n, const real_T x[1072], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      int32_T kend;
      mpcprueba2_B.scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (int32_T k = ix0; k < kend; k++) {
        mpcprueba2_B.absxk = fabs(x[k - 1]);
        if (mpcprueba2_B.absxk > mpcprueba2_B.scale) {
          mpcprueba2_B.t = mpcprueba2_B.scale / mpcprueba2_B.absxk;
          y = y * mpcprueba2_B.t * mpcprueba2_B.t + 1.0;
          mpcprueba2_B.scale = mpcprueba2_B.absxk;
        } else {
          mpcprueba2_B.t = mpcprueba2_B.absxk / mpcprueba2_B.scale;
          y += mpcprueba2_B.t * mpcprueba2_B.t;
        }
      }

      y = mpcprueba2_B.scale * sqrt(y);
    }
  }

  return y;
}

static real_T mpcprueba2_rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  mpcprueba2_B.a_h = fabs(u0);
  mpcprueba2_B.b = fabs(u1);
  if (mpcprueba2_B.a_h < mpcprueba2_B.b) {
    mpcprueba2_B.a_h /= mpcprueba2_B.b;
    y = sqrt(mpcprueba2_B.a_h * mpcprueba2_B.a_h + 1.0) * mpcprueba2_B.b;
  } else if (mpcprueba2_B.a_h > mpcprueba2_B.b) {
    mpcprueba2_B.b /= mpcprueba2_B.a_h;
    y = sqrt(mpcprueba2_B.b * mpcprueba2_B.b + 1.0) * mpcprueba2_B.a_h;
  } else if (rtIsNaN(mpcprueba2_B.b)) {
    y = (rtNaN);
  } else {
    y = mpcprueba2_B.a_h * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static real_T mpcprueba2_xzlarfg(int32_T n, real_T *alpha1, real_T x[1072],
  int32_T ix0)
{
  real_T tau;
  int32_T c;
  int32_T d;
  int32_T knt;
  tau = 0.0;
  if (n > 0) {
    mpcprueba2_B.xnorm = mpcprueba2_xnrm2_l(n - 1, x, ix0);
    if (mpcprueba2_B.xnorm != 0.0) {
      mpcprueba2_B.xnorm = mpcprueba2_rt_hypotd_snf(*alpha1, mpcprueba2_B.xnorm);
      if (*alpha1 >= 0.0) {
        mpcprueba2_B.xnorm = -mpcprueba2_B.xnorm;
      }

      if (fabs(mpcprueba2_B.xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        c = (ix0 + n) - 2;
        do {
          knt++;
          for (d = ix0; d <= c; d++) {
            x[d - 1] *= 9.9792015476736E+291;
          }

          mpcprueba2_B.xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(mpcprueba2_B.xnorm) < 1.0020841800044864E-292) && (knt <
                  20));

        mpcprueba2_B.xnorm = mpcprueba2_rt_hypotd_snf(*alpha1,
          mpcprueba2_xnrm2_l(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          mpcprueba2_B.xnorm = -mpcprueba2_B.xnorm;
        }

        tau = (mpcprueba2_B.xnorm - *alpha1) / mpcprueba2_B.xnorm;
        mpcprueba2_B.a = 1.0 / (*alpha1 - mpcprueba2_B.xnorm);
        for (d = ix0; d <= c; d++) {
          x[d - 1] *= mpcprueba2_B.a;
        }

        for (d = 0; d < knt; d++) {
          mpcprueba2_B.xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = mpcprueba2_B.xnorm;
      } else {
        tau = (mpcprueba2_B.xnorm - *alpha1) / mpcprueba2_B.xnorm;
        mpcprueba2_B.a = 1.0 / (*alpha1 - mpcprueba2_B.xnorm);
        d = (ix0 + n) - 2;
        for (knt = ix0; knt <= d; knt++) {
          x[knt - 1] *= mpcprueba2_B.a;
        }

        *alpha1 = mpcprueba2_B.xnorm;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C[1072], int32_T ic0, real_T work[67])
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
        mpcprueba2_B.c = 0.0;
        d = coltop + lastv;
        for (b_ia = coltop; b_ia < d; b_ia++) {
          mpcprueba2_B.c += C[((iv0 + b_ia) - coltop) - 1] * C[b_ia - 1];
        }

        b_ia = (coltop - ic0) >> 4;
        work[b_ia] += mpcprueba2_B.c;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      for (coltop = 0; coltop <= lastc; coltop++) {
        mpcprueba2_B.c = work[coltop];
        if (mpcprueba2_B.c != 0.0) {
          mpcprueba2_B.c *= -tau;
          d = lastv + jA;
          for (b_ia = jA; b_ia < d; b_ia++) {
            C[b_ia - 1] += C[((iv0 + b_ia) - jA) - 1] * mpcprueba2_B.c;
          }
        }

        jA += 16;
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_qrf(real_T A[1072], int32_T ia0, int32_T m, int32_T n,
  int32_T nfxd, real_T tau[16])
{
  int32_T i;
  int32_T ii;
  int32_T mmi;
  memset(&mpcprueba2_B.work_m[0], 0, 67U * sizeof(real_T));
  for (i = 0; i < nfxd; i++) {
    ii = (((i << 4) + ia0) + i) - 1;
    mmi = m - i;
    if (i + 1 < m) {
      mpcprueba2_B.b_atmp = A[ii];
      mpcprueba2_B.tau_n = mpcprueba2_xzlarfg(mmi, &mpcprueba2_B.b_atmp, A, ii +
        2);
      tau[i] = mpcprueba2_B.tau_n;
      A[ii] = mpcprueba2_B.b_atmp;
    } else {
      mpcprueba2_B.tau_n = 0.0;
      tau[i] = 0.0;
    }

    if (i + 1 < n) {
      mpcprueba2_B.b_atmp = A[ii];
      A[ii] = 1.0;
      mpcprueba2_xzlarf(mmi, (n - i) - 1, ii + 1, mpcprueba2_B.tau_n, A, ii + 17,
                        mpcprueba2_B.work_m);
      A[ii] = mpcprueba2_B.b_atmp;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_xgeqp3(real_T A[1072], int32_T m, int32_T n, int32_T
  jpvt[67], real_T tau[16])
{
  int32_T b_temp_tmp;
  int32_T c_ix;
  int32_T i;
  int32_T idxmax;
  int32_T temp_tmp;
  if (m <= n) {
    mpcprueba2_B.minmn_j = m;
  } else {
    mpcprueba2_B.minmn_j = n;
  }

  memset(&tau[0], 0, sizeof(real_T) << 4U);
  if (mpcprueba2_B.minmn_j < 1) {
    for (mpcprueba2_B.minmn_j = 0; mpcprueba2_B.minmn_j < n;
         mpcprueba2_B.minmn_j++) {
      jpvt[mpcprueba2_B.minmn_j] = mpcprueba2_B.minmn_j + 1;
    }
  } else {
    mpcprueba2_B.nfxd = -1;
    for (i = 0; i < n; i++) {
      if (jpvt[i] != 0) {
        mpcprueba2_B.nfxd++;
        if (i + 1 != mpcprueba2_B.nfxd + 1) {
          mpcprueba2_B.ix_j = i << 4;
          mpcprueba2_B.iy = mpcprueba2_B.nfxd << 4;
          for (mpcprueba2_B.mmi = 0; mpcprueba2_B.mmi < m; mpcprueba2_B.mmi++) {
            temp_tmp = mpcprueba2_B.ix_j + mpcprueba2_B.mmi;
            mpcprueba2_B.temp_m = A[temp_tmp];
            mpcprueba2_B.itemp = mpcprueba2_B.iy + mpcprueba2_B.mmi;
            A[temp_tmp] = A[mpcprueba2_B.itemp];
            A[mpcprueba2_B.itemp] = mpcprueba2_B.temp_m;
          }

          jpvt[i] = jpvt[mpcprueba2_B.nfxd];
          jpvt[mpcprueba2_B.nfxd] = i + 1;
        } else {
          jpvt[i] = i + 1;
        }
      } else {
        jpvt[i] = i + 1;
      }
    }

    if (mpcprueba2_B.nfxd + 1 <= mpcprueba2_B.minmn_j) {
      mpcprueba2_B.nfxd++;
    } else {
      mpcprueba2_B.nfxd = mpcprueba2_B.minmn_j;
    }

    memset(&tau[0], 0, sizeof(real_T) << 4U);
    mpcprueba2_qrf(A, 1, m, n, mpcprueba2_B.nfxd, tau);
    if (mpcprueba2_B.nfxd < mpcprueba2_B.minmn_j) {
      memset(&mpcprueba2_B.work[0], 0, 67U * sizeof(real_T));
      memset(&mpcprueba2_B.vn1[0], 0, 67U * sizeof(real_T));
      memset(&mpcprueba2_B.vn2[0], 0, 67U * sizeof(real_T));
      for (i = mpcprueba2_B.nfxd + 1; i <= n; i++) {
        mpcprueba2_B.temp_m = mpcprueba2_xnrm2_l(m - mpcprueba2_B.nfxd, A, (((i
          - 1) << 4) + mpcprueba2_B.nfxd) + 1);
        mpcprueba2_B.vn1[i - 1] = mpcprueba2_B.temp_m;
        mpcprueba2_B.vn2[i - 1] = mpcprueba2_B.temp_m;
      }

      for (i = mpcprueba2_B.nfxd + 1; i <= mpcprueba2_B.minmn_j; i++) {
        temp_tmp = (i - 1) << 4;
        mpcprueba2_B.ix_j = (temp_tmp + i) - 1;
        mpcprueba2_B.iy = (n - i) + 1;
        mpcprueba2_B.mmi = m - i;
        if (mpcprueba2_B.iy < 1) {
          idxmax = -2;
        } else {
          idxmax = -1;
          if (mpcprueba2_B.iy > 1) {
            mpcprueba2_B.temp_m = fabs(mpcprueba2_B.vn1[i - 1]);
            for (mpcprueba2_B.itemp = 2; mpcprueba2_B.itemp <= mpcprueba2_B.iy;
                 mpcprueba2_B.itemp++) {
              mpcprueba2_B.s = fabs(mpcprueba2_B.vn1[(i + mpcprueba2_B.itemp) -
                                    2]);
              if (mpcprueba2_B.s > mpcprueba2_B.temp_m) {
                idxmax = mpcprueba2_B.itemp - 2;
                mpcprueba2_B.temp_m = mpcprueba2_B.s;
              }
            }
          }
        }

        mpcprueba2_B.pvt = i + idxmax;
        if (mpcprueba2_B.pvt + 1 != i) {
          c_ix = mpcprueba2_B.pvt << 4;
          for (idxmax = 0; idxmax < m; idxmax++) {
            b_temp_tmp = c_ix + idxmax;
            mpcprueba2_B.temp_m = A[b_temp_tmp];
            mpcprueba2_B.itemp = temp_tmp + idxmax;
            A[b_temp_tmp] = A[mpcprueba2_B.itemp];
            A[mpcprueba2_B.itemp] = mpcprueba2_B.temp_m;
          }

          mpcprueba2_B.itemp = jpvt[mpcprueba2_B.pvt];
          jpvt[mpcprueba2_B.pvt] = jpvt[i - 1];
          jpvt[i - 1] = mpcprueba2_B.itemp;
          mpcprueba2_B.vn1[mpcprueba2_B.pvt] = mpcprueba2_B.vn1[i - 1];
          mpcprueba2_B.vn2[mpcprueba2_B.pvt] = mpcprueba2_B.vn2[i - 1];
        }

        if (i < m) {
          mpcprueba2_B.s = A[mpcprueba2_B.ix_j];
          mpcprueba2_B.temp_m = mpcprueba2_xzlarfg(mpcprueba2_B.mmi + 1,
            &mpcprueba2_B.s, A, mpcprueba2_B.ix_j + 2);
          tau[i - 1] = mpcprueba2_B.temp_m;
          A[mpcprueba2_B.ix_j] = mpcprueba2_B.s;
        } else {
          mpcprueba2_B.temp_m = 0.0;
          tau[i - 1] = 0.0;
        }

        if (i < n) {
          mpcprueba2_B.s = A[mpcprueba2_B.ix_j];
          A[mpcprueba2_B.ix_j] = 1.0;
          mpcprueba2_xzlarf(mpcprueba2_B.mmi + 1, mpcprueba2_B.iy - 1,
                            mpcprueba2_B.ix_j + 1, mpcprueba2_B.temp_m, A,
                            mpcprueba2_B.ix_j + 17, mpcprueba2_B.work);
          A[mpcprueba2_B.ix_j] = mpcprueba2_B.s;
        }

        for (mpcprueba2_B.itemp = i + 1; mpcprueba2_B.itemp <= n;
             mpcprueba2_B.itemp++) {
          mpcprueba2_B.ix_j = ((mpcprueba2_B.itemp - 1) << 4) + i;
          mpcprueba2_B.temp_m = mpcprueba2_B.vn1[mpcprueba2_B.itemp - 1];
          if (mpcprueba2_B.temp_m != 0.0) {
            mpcprueba2_B.s = fabs(A[mpcprueba2_B.ix_j - 1]) /
              mpcprueba2_B.temp_m;
            mpcprueba2_B.s = 1.0 - mpcprueba2_B.s * mpcprueba2_B.s;
            if (mpcprueba2_B.s < 0.0) {
              mpcprueba2_B.s = 0.0;
            }

            mpcprueba2_B.temp2 = mpcprueba2_B.temp_m /
              mpcprueba2_B.vn2[mpcprueba2_B.itemp - 1];
            mpcprueba2_B.temp2 = mpcprueba2_B.temp2 * mpcprueba2_B.temp2 *
              mpcprueba2_B.s;
            if (mpcprueba2_B.temp2 <= 1.4901161193847656E-8) {
              if (i < m) {
                mpcprueba2_B.temp_m = mpcprueba2_xnrm2_l(mpcprueba2_B.mmi, A,
                  mpcprueba2_B.ix_j + 1);
                mpcprueba2_B.vn1[mpcprueba2_B.itemp - 1] = mpcprueba2_B.temp_m;
                mpcprueba2_B.vn2[mpcprueba2_B.itemp - 1] = mpcprueba2_B.temp_m;
              } else {
                mpcprueba2_B.vn1[mpcprueba2_B.itemp - 1] = 0.0;
                mpcprueba2_B.vn2[mpcprueba2_B.itemp - 1] = 0.0;
              }
            } else {
              mpcprueba2_B.vn1[mpcprueba2_B.itemp - 1] = mpcprueba2_B.temp_m *
                sqrt(mpcprueba2_B.s);
            }
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_computeQ_(ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *obj, int32_T
  nrows)
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
    memset(&mpcprueba2_B.work_c[0], 0, sizeof(real_T) << 4U);
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
              memset(&mpcprueba2_B.work_c[0], 0, static_cast<uint32_T>(lastc + 1)
                     * sizeof(real_T));
            }

            iy = 0;
            e = b_k * lastc + jA;
            for (coltop = jA; b_k < 0 ? coltop >= e : coltop <= e; coltop += b_k)
            {
              int32_T f;
              mpcprueba2_B.b_c = 0.0;
              f = coltop + ia;
              for (c_ia = coltop; c_ia < f; c_ia++) {
                mpcprueba2_B.b_c += obj->Q[(iaii + c_ia) - coltop] * obj->Q[c_ia
                  - 1];
              }

              mpcprueba2_B.work_c[iy] += mpcprueba2_B.b_c;
              iy++;
            }
          }

          if (!(-obj->tau[iQR0] == 0.0)) {
            for (coltop = 0; coltop <= lastc; coltop++) {
              mpcprueba2_B.b_c = mpcprueba2_B.work_c[coltop];
              if (mpcprueba2_B.b_c != 0.0) {
                mpcprueba2_B.b_c *= -obj->tau[iQR0];
                iy = ia + jA;
                for (c_ia = jA; c_ia < iy; c_ia++) {
                  obj->Q[c_ia - 1] += obj->Q[(iaii + c_ia) - jA] *
                    mpcprueba2_B.b_c;
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
static int32_T mpcprueb_ComputeNumDependentEq_(ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T
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

    mpcprueba2_xgeqp3(qrmanager->QR, mConstr, nVar, qrmanager->jpvt,
                      qrmanager->tau);
  }

  if (mConstr >= nVar) {
    mpcprueba2_B.totalRank = mConstr;
  } else {
    mpcprueba2_B.totalRank = nVar;
  }

  mpcprueba2_B.tol = 2.2204460492503131E-15 * static_cast<real_T>
    (mpcprueba2_B.totalRank);
  if (mpcprueba2_B.tol >= 1.4901161193847656E-8) {
    mpcprueba2_B.tol = 1.4901161193847656E-8;
  }

  if (nVar <= mConstr) {
    mpcprueba2_B.totalRank = nVar;
  } else {
    mpcprueba2_B.totalRank = mConstr;
  }

  mpcprueba2_B.totalRank += (mpcprueba2_B.totalRank - 1) * qrmanager->ldq;
  while ((mpcprueba2_B.totalRank > 0) && (fabs(qrmanager->
           QR[mpcprueba2_B.totalRank - 1]) <= mpcprueba2_B.tol * fabs
          (qrmanager->QR[0]))) {
    mpcprueba2_B.totalRank = (mpcprueba2_B.totalRank - qrmanager->ldq) - 1;
    numDependent++;
  }

  if (numDependent > 0) {
    mpcprueba2_computeQ_(qrmanager, qrmanager->mrows);
    mpcprueba2_B.b_idx_e = 0;
    exitg1 = false;
    while ((!exitg1) && (mpcprueba2_B.b_idx_e <= numDependent - 1)) {
      mpcprueba2_B.qtb = 0.0;
      if (mConstr >= 1) {
        mpcprueba2_B.ix_a = ((mConstr - mpcprueba2_B.b_idx_e) - 1) *
          qrmanager->ldq;
        for (mpcprueba2_B.totalRank = 0; mpcprueba2_B.totalRank < mConstr;
             mpcprueba2_B.totalRank++) {
          mpcprueba2_B.qtb += qrmanager->Q[mpcprueba2_B.ix_a +
            mpcprueba2_B.totalRank] * beqf[mpcprueba2_B.totalRank];
        }
      }

      if (fabs(mpcprueba2_B.qtb) >= mpcprueba2_B.tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        mpcprueba2_B.b_idx_e++;
      }
    }
  }

  return numDependent;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_IndexOfDependentEq_(int32_T depIdx[67], int32_T mFixed,
  int32_T nDep, ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager, int32_T mRows,
  int32_T nCols)
{
  for (mpcprueba2_B.idx = 0; mpcprueba2_B.idx < mFixed; mpcprueba2_B.idx++) {
    qrmanager->jpvt[mpcprueba2_B.idx] = 1;
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

    mpcprueba2_xgeqp3(qrmanager->QR, mRows, nCols, qrmanager->jpvt,
                      qrmanager->tau);
  }

  for (mpcprueba2_B.idx = 0; mpcprueba2_B.idx < nDep; mpcprueba2_B.idx++) {
    depIdx[mpcprueba2_B.idx] = qrmanager->jpvt[(nCols - nDep) + mpcprueba2_B.idx];
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_countsort(int32_T x[67], int32_T xLen, int32_T workspace
  [67], int32_T xMin, int32_T xMax)
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
static void mpcprueba2_removeConstr(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *obj,
  int32_T idx_global)
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
static void mpcprueba2_removeEqConstr(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *obj,
  int32_T idx_global)
{
  int32_T TYPE;
  int32_T b;
  int32_T idx;
  int32_T totalEq;
  totalEq = (obj->nWConstr[0] + obj->nWConstr[1]) - 1;
  if ((totalEq + 1 != 0) && (idx_global <= totalEq + 1)) {
    if ((totalEq + 1 == obj->nActiveConstr) || (totalEq + 1 == idx_global)) {
      obj->mEqRemoved++;
      mpcprueba2_removeConstr(obj, idx_global);
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
static void mpcprueba2_RemoveDependentIneq_(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
  *workingset, ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager,
  sFevNsrsl34D5b5aqm3qNjD_mpcpr_T *memspace, real_T tolfactor)
{
  mpcprueba2_B.nActiveConstr = workingset->nActiveConstr;
  mpcprueba2_B.nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  mpcprueba2_B.nVar_c = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    if (workingset->nVar >= workingset->nActiveConstr) {
      mpcprueba2_B.b_idx = workingset->nVar;
    } else {
      mpcprueba2_B.b_idx = workingset->nActiveConstr;
    }

    mpcprueba2_B.u1 = 2.2204460492503131E-15 * static_cast<real_T>
      (mpcprueba2_B.b_idx);
    if (mpcprueba2_B.u1 >= 1.4901161193847656E-8) {
      mpcprueba2_B.u1 = 1.4901161193847656E-8;
    }

    mpcprueba2_B.tol_g = tolfactor * mpcprueba2_B.u1;
    for (mpcprueba2_B.b_idx = 0; mpcprueba2_B.b_idx < mpcprueba2_B.nFixedConstr;
         mpcprueba2_B.b_idx++) {
      qrmanager->jpvt[mpcprueba2_B.b_idx] = 1;
    }

    if (mpcprueba2_B.nFixedConstr + 1 <= mpcprueba2_B.nActiveConstr) {
      memset(&qrmanager->jpvt[mpcprueba2_B.nFixedConstr], 0,
             static_cast<uint32_T>(mpcprueba2_B.nActiveConstr -
              mpcprueba2_B.nFixedConstr) * sizeof(int32_T));
    }

    for (mpcprueba2_B.b_idx = 0; mpcprueba2_B.b_idx < mpcprueba2_B.nActiveConstr;
         mpcprueba2_B.b_idx++) {
      mpcprueba2_B.iy0_p = qrmanager->ldq * mpcprueba2_B.b_idx;
      mpcprueba2_B.ix0_c = workingset->ldA * mpcprueba2_B.b_idx;
      for (mpcprueba2_B.b_k = 0; mpcprueba2_B.b_k < mpcprueba2_B.nVar_c;
           mpcprueba2_B.b_k++) {
        qrmanager->QR[mpcprueba2_B.iy0_p + mpcprueba2_B.b_k] =
          workingset->ATwset[mpcprueba2_B.b_k + mpcprueba2_B.ix0_c];
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

      mpcprueba2_xgeqp3(qrmanager->QR, workingset->nVar,
                        workingset->nActiveConstr, qrmanager->jpvt,
                        qrmanager->tau);
    }

    mpcprueba2_B.nActiveConstr = 0;
    mpcprueba2_B.b_idx = workingset->nActiveConstr - 1;
    while (mpcprueba2_B.b_idx + 1 > mpcprueba2_B.nVar_c) {
      mpcprueba2_B.nActiveConstr++;
      memspace->workspace_int[mpcprueba2_B.nActiveConstr - 1] = qrmanager->
        jpvt[mpcprueba2_B.b_idx];
      mpcprueba2_B.b_idx--;
    }

    mpcprueba2_B.maxDiag = fabs(qrmanager->QR[0]);
    for (mpcprueba2_B.nVar_c = 0; mpcprueba2_B.nVar_c < mpcprueba2_B.b_idx;
         mpcprueba2_B.nVar_c++) {
      mpcprueba2_B.u1 = fabs(qrmanager->QR[((mpcprueba2_B.nVar_c + 1) *
        qrmanager->ldq + mpcprueba2_B.nVar_c) + 1]);
      if ((!(mpcprueba2_B.maxDiag >= mpcprueba2_B.u1)) && (!rtIsNaN
           (mpcprueba2_B.u1))) {
        mpcprueba2_B.maxDiag = mpcprueba2_B.u1;
      }
    }

    if (mpcprueba2_B.b_idx + 1 <= workingset->nVar) {
      mpcprueba2_B.nVar_c = qrmanager->ldq * mpcprueba2_B.b_idx +
        mpcprueba2_B.b_idx;
      while ((mpcprueba2_B.b_idx + 1 > mpcprueba2_B.nFixedConstr) && (fabs
              (qrmanager->QR[mpcprueba2_B.nVar_c]) < mpcprueba2_B.tol_g *
              mpcprueba2_B.maxDiag)) {
        mpcprueba2_B.nActiveConstr++;
        memspace->workspace_int[mpcprueba2_B.nActiveConstr - 1] =
          qrmanager->jpvt[mpcprueba2_B.b_idx];
        mpcprueba2_B.b_idx--;
        mpcprueba2_B.nVar_c = (mpcprueba2_B.nVar_c - qrmanager->ldq) - 1;
      }
    }

    mpcprueba2_countsort(memspace->workspace_int, mpcprueba2_B.nActiveConstr,
                         memspace->workspace_sort, mpcprueba2_B.nFixedConstr + 1,
                         workingset->nActiveConstr);
    for (mpcprueba2_B.nFixedConstr = mpcprueba2_B.nActiveConstr;
         mpcprueba2_B.nFixedConstr >= 1; mpcprueba2_B.nFixedConstr--) {
      mpcprueba2_removeConstr(workingset, memspace->
        workspace_int[mpcprueba2_B.nFixedConstr - 1]);
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static int32_T mpcprueba2_rank(const real_T qrmanager_QR[1072], int32_T
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
static void mpcprueba2_xgemv(int32_T m, int32_T n, const real_T A[1056], int32_T
  lda, const real_T x[1072], real_T y[67])
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
static real_T mpcprueb_maxConstraintViolation(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
  *obj, const real_T x[1072])
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

    mpcprueba2_xgemv(obj->nVarOrig, obj->sizes[2], obj->Aineq, obj->ldA, x,
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

    mpcprueba2_xgemv(obj->nVar, obj->sizes[2], obj->Aineq, obj->ldA, x,
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
static void mpcprueba2_xgemv_j(int32_T m, int32_T n, const real_T A[1056],
  int32_T lda, const real_T x[1072], real_T y[67])
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
static real_T mpcpru_maxConstraintViolation_n(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
  *obj, const real_T x[1072])
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

    mpcprueba2_xgemv_j(obj->nVarOrig, obj->sizes[2], obj->Aineq, obj->ldA, x,
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

    mpcprueba2_xgemv_j(obj->nVar, obj->sizes[2], obj->Aineq, obj->ldA, x,
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
static boolean_T mpcprue_feasibleX0ForWorkingSet(real_T workspace[1072], real_T
  xCurrent[16], sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager)
{
  int32_T exitg1;
  boolean_T guard1;
  boolean_T nonDegenerateWset;
  mpcprueba2_B.mWConstr = workingset->nActiveConstr;
  mpcprueba2_B.nVar_f = workingset->nVar - 1;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    if (workingset->nActiveConstr >= workingset->nVar) {
      for (mpcprueba2_B.rankQR = 0; mpcprueba2_B.rankQR <= mpcprueba2_B.nVar_f;
           mpcprueba2_B.rankQR++) {
        mpcprueba2_B.offsetQR = qrmanager->ldq * mpcprueba2_B.rankQR;
        for (mpcprueba2_B.ldq = 0; mpcprueba2_B.ldq < mpcprueba2_B.mWConstr;
             mpcprueba2_B.ldq++) {
          qrmanager->QR[mpcprueba2_B.ldq + mpcprueba2_B.offsetQR] =
            workingset->ATwset[workingset->ldA * mpcprueba2_B.ldq +
            mpcprueba2_B.rankQR];
        }

        qrmanager->jpvt[mpcprueba2_B.rankQR] = 0;
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

        mpcprueba2_xgeqp3(qrmanager->QR, workingset->nActiveConstr,
                          workingset->nVar, qrmanager->jpvt, qrmanager->tau);
      }

      mpcprueba2_computeQ_(qrmanager, qrmanager->mrows);
      mpcprueba2_B.rankQR = mpcprueba2_rank(qrmanager->QR, qrmanager->mrows,
        qrmanager->ncols);
      for (mpcprueba2_B.ldq = 0; mpcprueba2_B.ldq < mpcprueba2_B.mWConstr;
           mpcprueba2_B.ldq++) {
        workspace[mpcprueba2_B.ldq] = workingset->bwset[mpcprueba2_B.ldq];
        workspace[mpcprueba2_B.ldq + 67] = workingset->bwset[mpcprueba2_B.ldq];
      }

      mpcprueba2_B.ix = workingset->ldA;
      if ((workingset->nVar != 0) && (workingset->nActiveConstr != 0)) {
        mpcprueba2_B.jBcol = 0;
        mpcprueba2_B.iAcol = (workingset->nActiveConstr - 1) * workingset->ldA +
          1;
        for (mpcprueba2_B.ldq = 1; mpcprueba2_B.ix < 0 ? mpcprueba2_B.ldq >=
             mpcprueba2_B.iAcol : mpcprueba2_B.ldq <= mpcprueba2_B.iAcol;
             mpcprueba2_B.ldq += mpcprueba2_B.ix) {
          mpcprueba2_B.temp = 0.0;
          mpcprueba2_B.b_ar = mpcprueba2_B.ldq + mpcprueba2_B.nVar_f;
          for (mpcprueba2_B.offsetQR = mpcprueba2_B.ldq; mpcprueba2_B.offsetQR <=
               mpcprueba2_B.b_ar; mpcprueba2_B.offsetQR++) {
            mpcprueba2_B.temp += workingset->ATwset[mpcprueba2_B.offsetQR - 1] *
              xCurrent[mpcprueba2_B.offsetQR - mpcprueba2_B.ldq];
          }

          workspace[mpcprueba2_B.jBcol] -= mpcprueba2_B.temp;
          mpcprueba2_B.jBcol++;
        }
      }

      mpcprueba2_B.ldq = qrmanager->ldq;
      memcpy(&mpcprueba2_B.B[0], &workspace[0], 1072U * sizeof(real_T));
      if (workingset->nVar != 0) {
        mpcprueba2_B.iAcol = -1;
        for (mpcprueba2_B.offsetQR = 0; mpcprueba2_B.offsetQR <= 67;
             mpcprueba2_B.offsetQR += 67) {
          mpcprueba2_B.jBcol = (mpcprueba2_B.offsetQR + mpcprueba2_B.nVar_f) + 1;
          for (mpcprueba2_B.ix = mpcprueba2_B.offsetQR + 1; mpcprueba2_B.ix <=
               mpcprueba2_B.jBcol; mpcprueba2_B.ix++) {
            workspace[mpcprueba2_B.ix - 1] = 0.0;
          }
        }

        for (mpcprueba2_B.offsetQR = 0; mpcprueba2_B.offsetQR <= 67;
             mpcprueba2_B.offsetQR += 67) {
          mpcprueba2_B.b_ar = -1;
          mpcprueba2_B.d_a = (mpcprueba2_B.offsetQR + mpcprueba2_B.nVar_f) + 1;
          for (mpcprueba2_B.ix = mpcprueba2_B.offsetQR + 1; mpcprueba2_B.ix <=
               mpcprueba2_B.d_a; mpcprueba2_B.ix++) {
            mpcprueba2_B.temp = 0.0;
            for (mpcprueba2_B.jBcol = 0; mpcprueba2_B.jBcol <
                 mpcprueba2_B.mWConstr; mpcprueba2_B.jBcol++) {
              mpcprueba2_B.temp += qrmanager->Q[(mpcprueba2_B.jBcol +
                mpcprueba2_B.b_ar) + 1] * mpcprueba2_B.B[(mpcprueba2_B.jBcol +
                mpcprueba2_B.iAcol) + 1];
            }

            workspace[mpcprueba2_B.ix - 1] += mpcprueba2_B.temp;
            mpcprueba2_B.b_ar += mpcprueba2_B.ldq;
          }

          mpcprueba2_B.iAcol += 67;
        }
      }

      for (mpcprueba2_B.mWConstr = 0; mpcprueba2_B.mWConstr < 2;
           mpcprueba2_B.mWConstr++) {
        mpcprueba2_B.iAcol = 67 * mpcprueba2_B.mWConstr - 1;
        for (mpcprueba2_B.ix = mpcprueba2_B.rankQR; mpcprueba2_B.ix >= 1;
             mpcprueba2_B.ix--) {
          mpcprueba2_B.b_ar = (mpcprueba2_B.ix - 1) * mpcprueba2_B.ldq;
          mpcprueba2_B.offsetQR = mpcprueba2_B.ix + mpcprueba2_B.iAcol;
          mpcprueba2_B.temp = workspace[mpcprueba2_B.offsetQR];
          if (mpcprueba2_B.temp != 0.0) {
            workspace[mpcprueba2_B.offsetQR] = mpcprueba2_B.temp / qrmanager->
              QR[(mpcprueba2_B.ix + mpcprueba2_B.b_ar) - 1];
            for (mpcprueba2_B.jBcol = 0; mpcprueba2_B.jBcol <= mpcprueba2_B.ix -
                 2; mpcprueba2_B.jBcol++) {
              mpcprueba2_B.d_a = (mpcprueba2_B.jBcol + mpcprueba2_B.iAcol) + 1;
              workspace[mpcprueba2_B.d_a] -= qrmanager->QR[mpcprueba2_B.jBcol +
                mpcprueba2_B.b_ar] * workspace[mpcprueba2_B.offsetQR];
            }
          }
        }
      }

      for (mpcprueba2_B.ldq = mpcprueba2_B.rankQR + 1; mpcprueba2_B.ldq <=
           mpcprueba2_B.nVar_f + 1; mpcprueba2_B.ldq++) {
        workspace[mpcprueba2_B.ldq - 1] = 0.0;
        workspace[mpcprueba2_B.ldq + 66] = 0.0;
      }

      for (mpcprueba2_B.rankQR = 0; mpcprueba2_B.rankQR <= mpcprueba2_B.nVar_f;
           mpcprueba2_B.rankQR++) {
        workspace[qrmanager->jpvt[mpcprueba2_B.rankQR] + 133] =
          workspace[mpcprueba2_B.rankQR];
      }

      for (mpcprueba2_B.rankQR = 0; mpcprueba2_B.rankQR <= mpcprueba2_B.nVar_f;
           mpcprueba2_B.rankQR++) {
        workspace[mpcprueba2_B.rankQR] = workspace[mpcprueba2_B.rankQR + 134];
      }

      for (mpcprueba2_B.rankQR = 0; mpcprueba2_B.rankQR <= mpcprueba2_B.nVar_f;
           mpcprueba2_B.rankQR++) {
        workspace[qrmanager->jpvt[mpcprueba2_B.rankQR] + 133] =
          workspace[mpcprueba2_B.rankQR + 67];
      }

      for (mpcprueba2_B.rankQR = 0; mpcprueba2_B.rankQR <= mpcprueba2_B.nVar_f;
           mpcprueba2_B.rankQR++) {
        workspace[mpcprueba2_B.rankQR + 67] = workspace[mpcprueba2_B.rankQR +
          134];
      }
    } else {
      if (mpcprueba2_B.mWConstr - 1 >= 0) {
        memset(&qrmanager->jpvt[0], 0, static_cast<uint32_T>
               (mpcprueba2_B.mWConstr) * sizeof(int32_T));
      }

      mpcprueba2_B.offsetQR = workingset->nVar * workingset->nActiveConstr;
      guard1 = false;
      if (mpcprueba2_B.offsetQR > 0) {
        for (mpcprueba2_B.rankQR = 0; mpcprueba2_B.rankQR <
             mpcprueba2_B.mWConstr; mpcprueba2_B.rankQR++) {
          mpcprueba2_B.offsetQR = workingset->ldA * mpcprueba2_B.rankQR;
          mpcprueba2_B.ix = qrmanager->ldq * mpcprueba2_B.rankQR;
          for (mpcprueba2_B.ldq = 0; mpcprueba2_B.ldq <= mpcprueba2_B.nVar_f;
               mpcprueba2_B.ldq++) {
            qrmanager->QR[mpcprueba2_B.ix + mpcprueba2_B.ldq] =
              workingset->ATwset[mpcprueba2_B.offsetQR + mpcprueba2_B.ldq];
          }
        }

        guard1 = true;
      } else if (mpcprueba2_B.offsetQR == 0) {
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

        mpcprueba2_xgeqp3(qrmanager->QR, workingset->nVar,
                          workingset->nActiveConstr, qrmanager->jpvt,
                          qrmanager->tau);
      }

      mpcprueba2_computeQ_(qrmanager, qrmanager->minRowCol);
      mpcprueba2_B.rankQR = mpcprueba2_rank(qrmanager->QR, qrmanager->mrows,
        qrmanager->ncols);
      for (mpcprueba2_B.ldq = 0; mpcprueba2_B.ldq < mpcprueba2_B.mWConstr;
           mpcprueba2_B.ldq++) {
        mpcprueba2_B.temp = 0.0;
        if (mpcprueba2_B.nVar_f + 1 >= 1) {
          mpcprueba2_B.ix = (qrmanager->jpvt[mpcprueba2_B.ldq] - 1) *
            workingset->ldA;
          for (mpcprueba2_B.offsetQR = 0; mpcprueba2_B.offsetQR <=
               mpcprueba2_B.nVar_f; mpcprueba2_B.offsetQR++) {
            mpcprueba2_B.temp += workingset->ATwset[mpcprueba2_B.ix +
              mpcprueba2_B.offsetQR] * xCurrent[mpcprueba2_B.offsetQR];
          }
        }

        workspace[mpcprueba2_B.ldq] = workingset->bwset[qrmanager->
          jpvt[mpcprueba2_B.ldq] - 1] - mpcprueba2_B.temp;
        workspace[mpcprueba2_B.ldq + 67] = workingset->bwset[qrmanager->
          jpvt[mpcprueba2_B.ldq] - 1];
      }

      mpcprueba2_B.ldq = qrmanager->ldq;
      for (mpcprueba2_B.mWConstr = 0; mpcprueba2_B.mWConstr < 2;
           mpcprueba2_B.mWConstr++) {
        mpcprueba2_B.jBcol = 67 * mpcprueba2_B.mWConstr;
        for (mpcprueba2_B.offsetQR = 0; mpcprueba2_B.offsetQR <
             mpcprueba2_B.rankQR; mpcprueba2_B.offsetQR++) {
          mpcprueba2_B.iAcol = mpcprueba2_B.ldq * mpcprueba2_B.offsetQR;
          mpcprueba2_B.b_ar = mpcprueba2_B.offsetQR + mpcprueba2_B.jBcol;
          mpcprueba2_B.temp = workspace[mpcprueba2_B.b_ar];
          for (mpcprueba2_B.ix = 0; mpcprueba2_B.ix < mpcprueba2_B.offsetQR;
               mpcprueba2_B.ix++) {
            mpcprueba2_B.temp -= qrmanager->QR[mpcprueba2_B.ix +
              mpcprueba2_B.iAcol] * workspace[mpcprueba2_B.ix +
              mpcprueba2_B.jBcol];
          }

          workspace[mpcprueba2_B.b_ar] = mpcprueba2_B.temp / qrmanager->
            QR[mpcprueba2_B.offsetQR + mpcprueba2_B.iAcol];
        }
      }

      memcpy(&mpcprueba2_B.B[0], &workspace[0], 1072U * sizeof(real_T));
      if (workingset->nVar != 0) {
        mpcprueba2_B.jBcol = 1;
        for (mpcprueba2_B.mWConstr = 0; mpcprueba2_B.mWConstr <= 67;
             mpcprueba2_B.mWConstr += 67) {
          mpcprueba2_B.ix = (mpcprueba2_B.mWConstr + mpcprueba2_B.nVar_f) + 1;
          for (mpcprueba2_B.offsetQR = mpcprueba2_B.mWConstr + 1;
               mpcprueba2_B.offsetQR <= mpcprueba2_B.ix; mpcprueba2_B.offsetQR++)
          {
            workspace[mpcprueba2_B.offsetQR - 1] = 0.0;
          }
        }

        for (mpcprueba2_B.mWConstr = 0; mpcprueba2_B.mWConstr <= 67;
             mpcprueba2_B.mWConstr += 67) {
          mpcprueba2_B.iAcol = -1;
          mpcprueba2_B.b_ar = mpcprueba2_B.jBcol + mpcprueba2_B.rankQR;
          for (mpcprueba2_B.offsetQR = mpcprueba2_B.jBcol; mpcprueba2_B.offsetQR
               < mpcprueba2_B.b_ar; mpcprueba2_B.offsetQR++) {
            mpcprueba2_B.d_a = (mpcprueba2_B.mWConstr + mpcprueba2_B.nVar_f) + 1;
            for (mpcprueba2_B.ix = mpcprueba2_B.mWConstr + 1; mpcprueba2_B.ix <=
                 mpcprueba2_B.d_a; mpcprueba2_B.ix++) {
              workspace[mpcprueba2_B.ix - 1] += qrmanager->Q[(mpcprueba2_B.iAcol
                + mpcprueba2_B.ix) - mpcprueba2_B.mWConstr] *
                mpcprueba2_B.B[mpcprueba2_B.offsetQR - 1];
            }

            mpcprueba2_B.iAcol += mpcprueba2_B.ldq;
          }

          mpcprueba2_B.jBcol += 67;
        }
      }
    }

    mpcprueba2_B.rankQR = 0;
    do {
      exitg1 = 0;
      if (mpcprueba2_B.rankQR <= mpcprueba2_B.nVar_f) {
        if (rtIsInf(workspace[mpcprueba2_B.rankQR]) || rtIsNaN
            (workspace[mpcprueba2_B.rankQR])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else if (rtIsInf(workspace[mpcprueba2_B.rankQR + 67]) || rtIsNaN
                   (workspace[mpcprueba2_B.rankQR + 67])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          mpcprueba2_B.rankQR++;
        }
      } else {
        if (mpcprueba2_B.nVar_f >= 0) {
          for (mpcprueba2_B.rankQR = 0; mpcprueba2_B.rankQR <=
               mpcprueba2_B.nVar_f; mpcprueba2_B.rankQR++) {
            workspace[mpcprueba2_B.rankQR] += xCurrent[mpcprueba2_B.rankQR];
          }
        }

        mpcprueba2_B.temp = mpcprueb_maxConstraintViolation(workingset,
          workspace);
        mpcprueba2_B.constrViolation_basicX = mpcpru_maxConstraintViolation_n
          (workingset, workspace);
        if ((mpcprueba2_B.temp <= 2.2204460492503131E-16) || (mpcprueba2_B.temp <
             mpcprueba2_B.constrViolation_basicX)) {
          if (mpcprueba2_B.nVar_f >= 0) {
            memcpy(&xCurrent[0], &workspace[0], static_cast<uint32_T>
                   (mpcprueba2_B.nVar_f + 1) * sizeof(real_T));
          }
        } else if (mpcprueba2_B.nVar_f >= 0) {
          memcpy(&xCurrent[0], &workspace[67], static_cast<uint32_T>
                 (mpcprueba2_B.nVar_f + 1) * sizeof(real_T));
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_xgemv_j3(int32_T m, int32_T n, const real_T A[1056],
  int32_T lda, const real_T x[16], real_T y[67])
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
static real_T mpcpr_maxConstraintViolation_n3(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
  *obj, const real_T x[16])
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

    mpcprueba2_xgemv_j3(obj->nVarOrig, obj->sizes[2], obj->Aineq, obj->ldA, x,
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

    mpcprueba2_xgemv_j3(obj->nVar, obj->sizes[2], obj->Aineq, obj->ldA, x,
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
static void mpcprueba2_PresolveWorkingSet(sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T
  *solution, sFevNsrsl34D5b5aqm3qNjD_mpcpr_T *memspace,
  sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *workingset, const
  sqZVQFgLZG74FDpCArykMHB_mpcpr_T *options, ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T
  *qrmanager)
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
  mpcprueba2_B.nVar_n = workingset->nVar;
  mpcprueba2_B.mTotalWorkingEq_m = workingset->nWConstr[0] +
    workingset->nWConstr[1];
  mpcprueba2_B.nDepInd_c = 0;
  if (mpcprueba2_B.mTotalWorkingEq_m > 0) {
    for (mpcprueba2_B.i_h = 0; mpcprueba2_B.i_h < mpcprueba2_B.mTotalWorkingEq_m;
         mpcprueba2_B.i_h++) {
      for (mpcprueba2_B.idxStartIneq_m = 0; mpcprueba2_B.idxStartIneq_m <
           mpcprueba2_B.nVar_n; mpcprueba2_B.idxStartIneq_m++) {
        qrmanager->QR[mpcprueba2_B.i_h + (mpcprueba2_B.idxStartIneq_m << 4)] =
          workingset->ATwset[workingset->ldA * mpcprueba2_B.i_h +
          mpcprueba2_B.idxStartIneq_m];
      }
    }

    mpcprueba2_B.nDepInd_c = mpcprueb_ComputeNumDependentEq_(qrmanager,
      workingset->bwset, mpcprueba2_B.mTotalWorkingEq_m, workingset->nVar);
    if (mpcprueba2_B.nDepInd_c > 0) {
      for (mpcprueba2_B.i_h = 0; mpcprueba2_B.i_h <
           mpcprueba2_B.mTotalWorkingEq_m; mpcprueba2_B.i_h++) {
        mpcprueba2_B.iy0_j = qrmanager->ldq * mpcprueba2_B.i_h;
        mpcprueba2_B.ix0_m = workingset->ldA * mpcprueba2_B.i_h;
        for (mpcprueba2_B.idxStartIneq_m = 0; mpcprueba2_B.idxStartIneq_m <
             mpcprueba2_B.nVar_n; mpcprueba2_B.idxStartIneq_m++) {
          qrmanager->QR[mpcprueba2_B.iy0_j + mpcprueba2_B.idxStartIneq_m] =
            workingset->ATwset[mpcprueba2_B.idxStartIneq_m + mpcprueba2_B.ix0_m];
        }
      }

      mpcprueba2_IndexOfDependentEq_(memspace->workspace_int,
        workingset->nWConstr[0], mpcprueba2_B.nDepInd_c, qrmanager,
        workingset->nVar, mpcprueba2_B.mTotalWorkingEq_m);
      mpcprueba2_countsort(memspace->workspace_int, mpcprueba2_B.nDepInd_c,
                           memspace->workspace_sort, 1,
                           mpcprueba2_B.mTotalWorkingEq_m);
      for (mpcprueba2_B.i_h = mpcprueba2_B.nDepInd_c; mpcprueba2_B.i_h >= 1;
           mpcprueba2_B.i_h--) {
        mpcprueba2_removeEqConstr(workingset, memspace->
          workspace_int[mpcprueba2_B.i_h - 1]);
      }
    }
  }

  if ((mpcprueba2_B.nDepInd_c != -1) && (workingset->nActiveConstr <=
       qrmanager->ldq)) {
    mpcprueba2_RemoveDependentIneq_(workingset, qrmanager, memspace, 1.0);
    okWorkingSet = mpcprue_feasibleX0ForWorkingSet(memspace->workspace_float,
      solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      mpcprueba2_RemoveDependentIneq_(workingset, qrmanager, memspace, 10.0);
      okWorkingSet = mpcprue_feasibleX0ForWorkingSet(memspace->workspace_float,
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
        mpcprueba2_B.constrViolation_d = mpcpr_maxConstraintViolation_n3
          (workingset, solution->xstar);
        if (mpcprueba2_B.constrViolation_d > options->ConstraintTolerance) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    mpcprueba2_B.idxStartIneq_m = (workingset->nWConstr[0] +
      workingset->nWConstr[1]) + 1;
    mpcprueba2_B.nVar_n = workingset->nActiveConstr;
    for (mpcprueba2_B.i_h = mpcprueba2_B.idxStartIneq_m; mpcprueba2_B.i_h <=
         mpcprueba2_B.nVar_n; mpcprueba2_B.i_h++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[mpcprueba2_B.i_h - 1] - 1] + workingset->Wlocalidx[mpcprueba2_B.i_h
        - 1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprue_modifyOverheadPhaseOne_(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *obj)
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
static void mpcprueba2_setProblemType(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *obj,
  int32_T PROBLEM_TYPE)
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

    mpcprue_modifyOverheadPhaseOne_(obj);
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

    mpcprue_modifyOverheadPhaseOne_(obj);
    for (offsetIneq = 0; offsetIneq < 6; offsetIneq++) {
      obj->isActiveIdx[offsetIneq] = obj->isActiveIdxRegPhaseOne[offsetIneq];
    }
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_xgemv_j30(int32_T m, int32_T n, const real_T A[225],
  int32_T lda, const real_T x[16], real_T y[15])
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
static void mpcprueba2_computeGrad_StoreHx(s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *obj,
  const real_T b_H[225], const real_T f[15], const real_T x[16])
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
    mpcprueba2_xgemv_j30(obj->nvar, obj->nvar, b_H, obj->nvar, x, obj->Hx);
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
    mpcprueba2_xgemv_j30(obj->nvar, obj->nvar, b_H, obj->nvar, x, obj->Hx);
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
static real_T mpcprueba2_computeFval_ReuseHx(const
  s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *obj, real_T workspace[1072], const real_T f
  [15], const real_T x[16])
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
static void mpcprueba2_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  mpcprueba2_B.roe = *b;
  mpcprueba2_B.absa = fabs(*a);
  mpcprueba2_B.absb = fabs(*b);
  if (mpcprueba2_B.absa > mpcprueba2_B.absb) {
    mpcprueba2_B.roe = *a;
  }

  mpcprueba2_B.scale_l = mpcprueba2_B.absa + mpcprueba2_B.absb;
  if (mpcprueba2_B.scale_l == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = mpcprueba2_B.absa / mpcprueba2_B.scale_l;
    bds = mpcprueba2_B.absb / mpcprueba2_B.scale_l;
    mpcprueba2_B.scale_l *= sqrt(ads * ads + bds * bds);
    if (mpcprueba2_B.roe < 0.0) {
      mpcprueba2_B.scale_l = -mpcprueba2_B.scale_l;
    }

    *c = *a / mpcprueba2_B.scale_l;
    *s = *b / mpcprueba2_B.scale_l;
    if (mpcprueba2_B.absa > mpcprueba2_B.absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = mpcprueba2_B.scale_l;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_squareQ_appendCol(ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *obj,
  const real_T vec[1072], int32_T iv0)
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
    mpcprueba2_B.temp_da = obj->QR[b_iy + 1];
    mpcprueba2_xrotg(&obj->QR[b_iy], &mpcprueba2_B.temp_da, &b_c,
                     &mpcprueba2_B.s_b);
    obj->QR[b_iy + 1] = mpcprueba2_B.temp_da;
    Qk0 = obj->ldq * idx;
    iyend = obj->mrows;
    if (obj->mrows >= 1) {
      iy = obj->ldq + Qk0;
      for (b_iy = 0; b_iy < iyend; b_iy++) {
        e = iy + b_iy;
        temp_tmp = Qk0 + b_iy;
        mpcprueba2_B.temp_da = obj->Q[temp_tmp] * b_c + obj->Q[e] *
          mpcprueba2_B.s_b;
        obj->Q[e] = obj->Q[e] * b_c - obj->Q[temp_tmp] * mpcprueba2_B.s_b;
        obj->Q[temp_tmp] = mpcprueba2_B.temp_da;
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_deleteColMoveEnd(ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *obj,
  int32_T idx)
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
        mpcprueba2_B.b_temp_d = obj->QR[QRk0];
        mpcprueba2_xrotg(&obj->QR[QRk0 - 1], &mpcprueba2_B.b_temp_d,
                         &mpcprueba2_B.c_c, &mpcprueba2_B.b_s);
        obj->QR[QRk0] = mpcprueba2_B.b_temp_d;
        obj->QR[k + obj->ldq * (k - 1)] = 0.0;
        QRk0 = obj->ldq * idx + k;
        b_ix = obj->ncols - idx;
        if (b_ix >= 1) {
          ix = QRk0 - 1;
          for (b_n = 0; b_n < b_ix; b_n++) {
            mpcprueba2_B.b_temp_d = mpcprueba2_B.c_c * obj->QR[ix] +
              mpcprueba2_B.b_s * obj->QR[QRk0];
            obj->QR[QRk0] = mpcprueba2_B.c_c * obj->QR[QRk0] - mpcprueba2_B.b_s *
              obj->QR[ix];
            obj->QR[ix] = mpcprueba2_B.b_temp_d;
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
            mpcprueba2_B.b_temp_d = obj->Q[c_temp_tmp] * mpcprueba2_B.c_c +
              obj->Q[d_temp_tmp] * mpcprueba2_B.b_s;
            obj->Q[d_temp_tmp] = obj->Q[d_temp_tmp] * mpcprueba2_B.c_c - obj->
              Q[c_temp_tmp] * mpcprueba2_B.b_s;
            obj->Q[c_temp_tmp] = mpcprueba2_B.b_temp_d;
          }
        }

        k--;
      }

      for (k = idx + 1; k <= i; k++) {
        QRk0 = (k - 1) * obj->ldq + k;
        mpcprueba2_B.b_temp_d = obj->QR[QRk0];
        mpcprueba2_xrotg(&obj->QR[QRk0 - 1], &mpcprueba2_B.b_temp_d,
                         &mpcprueba2_B.c_c, &mpcprueba2_B.b_s);
        obj->QR[QRk0] = mpcprueba2_B.b_temp_d;
        QRk0 = (obj->ldq + 1) * k;
        b_n = obj->ncols - k;
        if (b_n >= 1) {
          b_ix = QRk0 - 1;
          for (idxRotGCol = 0; idxRotGCol < b_n; idxRotGCol++) {
            mpcprueba2_B.b_temp_d = mpcprueba2_B.c_c * obj->QR[b_ix] +
              mpcprueba2_B.b_s * obj->QR[QRk0];
            obj->QR[QRk0] = mpcprueba2_B.c_c * obj->QR[QRk0] - mpcprueba2_B.b_s *
              obj->QR[b_ix];
            obj->QR[b_ix] = mpcprueba2_B.b_temp_d;
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
            mpcprueba2_B.b_temp_d = obj->Q[d_temp_tmp] * mpcprueba2_B.c_c +
              obj->Q[ix] * mpcprueba2_B.b_s;
            obj->Q[ix] = obj->Q[ix] * mpcprueba2_B.c_c - obj->Q[d_temp_tmp] *
              mpcprueba2_B.b_s;
            obj->Q[d_temp_tmp] = mpcprueba2_B.b_temp_d;
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static int32_T mpcprueba2_ixamax(int32_T n, const real_T x[256], int32_T incx)
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
static void mpcprueba2_fullColLDL2_(sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T *obj,
  int32_T LD_offset, int32_T NColsRemain, real_T REG_PRIMAL)
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

    mpcprueba2_B.alpha1 = -1.0 / obj->FMat[LD_diagOffset];
    subMatrixDim = NColsRemain - lastDiag;
    for (b_k = 0; b_k <= subMatrixDim - 2; b_k++) {
      obj->workspace_[b_k] = obj->FMat[(LD_diagOffset + b_k) + 1];
    }

    if (!(mpcprueba2_B.alpha1 == 0.0)) {
      int32_T jA;
      jA = (LD_diagOffset + LDimSizeP1) + 2;
      for (b_k = 0; b_k <= subMatrixDim - 2; b_k++) {
        mpcprueba2_B.temp_d = obj->workspace_[b_k];
        if (mpcprueba2_B.temp_d != 0.0) {
          int32_T b;
          mpcprueba2_B.temp_d *= mpcprueba2_B.alpha1;
          b = subMatrixDim + jA;
          for (int32_T ijA = jA; ijA <= b - 2; ijA++) {
            obj->FMat[ijA - 1] += obj->workspace_[ijA - jA] *
              mpcprueba2_B.temp_d;
          }
        }

        jA += obj->ldm;
      }
    }

    mpcprueba2_B.alpha1 = 1.0 / obj->FMat[LD_diagOffset];
    b_k = LD_diagOffset + subMatrixDim;
    for (subMatrixDim = LD_diagOffset + 2; subMatrixDim <= b_k; subMatrixDim++)
    {
      obj->FMat[subMatrixDim - 1] *= mpcprueba2_B.alpha1;
    }
  }

  lastDiag = ((obj->ldm + 1) * (NColsRemain - 1) + LD_offset) - 1;
  if (fabs(obj->FMat[lastDiag]) <= obj->regTol_) {
    obj->FMat[lastDiag] += REG_PRIMAL;
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_xgemv_j30b(int32_T m, int32_T n, const real_T A[256],
  int32_T ia0, int32_T lda, const real_T x[1072], real_T y[16])
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
static void mpcprueba2_compute_deltax(const real_T b_H[225],
  sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpcpr_T
  *memspace, const ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager,
  sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T *cholmanager, const
  s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *objective)
{
  int32_T b_jjA;
  int32_T c_ix;
  int32_T exitg1;
  int32_T g;
  int32_T h;
  int32_T i;
  int32_T ic;
  mpcprueba2_B.nVar_p = qrmanager->mrows - 1;
  mpcprueba2_B.mNull = qrmanager->mrows - qrmanager->ncols;
  if (mpcprueba2_B.mNull <= 0) {
    if (mpcprueba2_B.nVar_p >= 0) {
      memset(&solution->searchDir[0], 0, static_cast<uint32_T>
             (mpcprueba2_B.nVar_p + 1) * sizeof(real_T));
    }
  } else {
    for (mpcprueba2_B.b_idx_a = 0; mpcprueba2_B.b_idx_a <= mpcprueba2_B.nVar_p;
         mpcprueba2_B.b_idx_a++) {
      solution->searchDir[mpcprueba2_B.b_idx_a] = -objective->
        grad[mpcprueba2_B.b_idx_a];
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        mpcprueba2_B.b_SCALED_REG_PRIMAL = 1.4901161193847656E-8 *
          cholmanager->scaleFactor * static_cast<real_T>(qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        for (mpcprueba2_B.mNull = 0; mpcprueba2_B.mNull <= mpcprueba2_B.nVar_p;
             mpcprueba2_B.mNull++) {
          mpcprueba2_B.nullStartIdx = (mpcprueba2_B.nVar_p + 1) *
            mpcprueba2_B.mNull;
          mpcprueba2_B.nVars = cholmanager->ldm * mpcprueba2_B.mNull;
          for (mpcprueba2_B.b_idx_a = 0; mpcprueba2_B.b_idx_a <=
               mpcprueba2_B.nVar_p; mpcprueba2_B.b_idx_a++) {
            cholmanager->FMat[mpcprueba2_B.nVars + mpcprueba2_B.b_idx_a] =
              b_H[mpcprueba2_B.b_idx_a + mpcprueba2_B.nullStartIdx];
          }
        }

        mpcprueba2_B.mNull = mpcprueba2_ixamax(qrmanager->mrows,
          cholmanager->FMat, cholmanager->ldm + 1) - 1;
        mpcprueba2_B.b_temp = fabs(cholmanager->FMat[cholmanager->ldm *
          mpcprueba2_B.mNull + mpcprueba2_B.mNull]) * 2.2204460492503131E-16;
        mpcprueba2_B.u1_l = fabs(mpcprueba2_B.b_SCALED_REG_PRIMAL);
        if ((mpcprueba2_B.b_temp >= mpcprueba2_B.u1_l) || rtIsNaN
            (mpcprueba2_B.u1_l)) {
          cholmanager->regTol_ = mpcprueba2_B.b_temp;
        } else {
          cholmanager->regTol_ = mpcprueba2_B.u1_l;
        }

        mpcprueba2_fullColLDL2_(cholmanager, 1, qrmanager->mrows,
          mpcprueba2_B.b_SCALED_REG_PRIMAL);
        if (cholmanager->ConvexCheck) {
          mpcprueba2_B.mNull = 0;
          do {
            exitg1 = 0;
            if (mpcprueba2_B.mNull <= mpcprueba2_B.nVar_p) {
              if (cholmanager->FMat[cholmanager->ldm * mpcprueba2_B.mNull +
                  mpcprueba2_B.mNull] <= 0.0) {
                cholmanager->info = -mpcprueba2_B.mNull - 1;
                exitg1 = 1;
              } else {
                mpcprueba2_B.mNull++;
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
          mpcprueba2_B.nVar_p = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (mpcprueba2_B.mNull = 0; mpcprueba2_B.mNull <
                 mpcprueba2_B.nVar_p; mpcprueba2_B.mNull++) {
              mpcprueba2_B.nullStartIdx = mpcprueba2_B.mNull * cholmanager->ldm
                + mpcprueba2_B.mNull;
              mpcprueba2_B.nVars = (mpcprueba2_B.nVar_p - mpcprueba2_B.mNull) -
                2;
              for (mpcprueba2_B.b_idx_a = 0; mpcprueba2_B.b_idx_a <=
                   mpcprueba2_B.nVars; mpcprueba2_B.b_idx_a++) {
                b_jjA = (mpcprueba2_B.b_idx_a + mpcprueba2_B.mNull) + 1;
                solution->searchDir[b_jjA] -= cholmanager->FMat
                  [(mpcprueba2_B.b_idx_a + mpcprueba2_B.nullStartIdx) + 1] *
                  solution->searchDir[mpcprueba2_B.mNull];
              }
            }
          }

          mpcprueba2_B.b_idx_a = cholmanager->ndims;
          for (mpcprueba2_B.mNull = 0; mpcprueba2_B.mNull < mpcprueba2_B.b_idx_a;
               mpcprueba2_B.mNull++) {
            solution->searchDir[mpcprueba2_B.mNull] /= cholmanager->
              FMat[cholmanager->ldm * mpcprueba2_B.mNull + mpcprueba2_B.mNull];
          }

          mpcprueba2_B.nVar_p = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (mpcprueba2_B.mNull = mpcprueba2_B.nVar_p; mpcprueba2_B.mNull >=
                 1; mpcprueba2_B.mNull--) {
              mpcprueba2_B.nullStartIdx = (mpcprueba2_B.mNull - 1) *
                cholmanager->ldm;
              mpcprueba2_B.b_temp = solution->searchDir[mpcprueba2_B.mNull - 1];
              for (mpcprueba2_B.b_idx_a = mpcprueba2_B.nVar_p;
                   mpcprueba2_B.b_idx_a >= mpcprueba2_B.mNull + 1;
                   mpcprueba2_B.b_idx_a--) {
                mpcprueba2_B.b_temp -= cholmanager->FMat
                  [(mpcprueba2_B.nullStartIdx + mpcprueba2_B.b_idx_a) - 1] *
                  solution->searchDir[mpcprueba2_B.b_idx_a - 1];
              }

              solution->searchDir[mpcprueba2_B.mNull - 1] = mpcprueba2_B.b_temp;
            }
          }
        }
      }
    } else {
      mpcprueba2_B.b_idx_a = qrmanager->ldq * qrmanager->ncols;
      mpcprueba2_B.nullStartIdx = mpcprueba2_B.b_idx_a + 1;
      if (objective->objtype == 5) {
        for (mpcprueba2_B.nullStartIdx = 0; mpcprueba2_B.nullStartIdx <
             mpcprueba2_B.mNull; mpcprueba2_B.nullStartIdx++) {
          memspace->workspace_float[mpcprueba2_B.nullStartIdx] = -qrmanager->Q
            [(qrmanager->ncols + mpcprueba2_B.nullStartIdx) * qrmanager->ldq +
            mpcprueba2_B.nVar_p];
        }

        mpcprueba2_xgemv_j30b(qrmanager->mrows, mpcprueba2_B.mNull, qrmanager->Q,
                              mpcprueba2_B.b_idx_a + 1, qrmanager->ldq,
                              memspace->workspace_float, solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          mpcprueba2_B.nVars = qrmanager->mrows;
          b_jjA = cholmanager->ldm;
          mpcprueba2_B.ldQ = qrmanager->ldq;
          if ((qrmanager->mrows != 0) && (mpcprueba2_B.mNull != 0)) {
            mpcprueba2_B.br = mpcprueba2_B.b_idx_a;
            mpcprueba2_B.lastColC = (mpcprueba2_B.mNull - 1) * 67;
            for (c_ix = 0; c_ix <= mpcprueba2_B.lastColC; c_ix += 67) {
              g = c_ix + mpcprueba2_B.nVars;
              for (ic = c_ix + 1; ic <= g; ic++) {
                memspace->workspace_float[ic - 1] = 0.0;
              }
            }

            for (c_ix = 0; c_ix <= mpcprueba2_B.lastColC; c_ix += 67) {
              mpcprueba2_B.ar = -1;
              h = mpcprueba2_B.br + mpcprueba2_B.nVars;
              for (ic = mpcprueba2_B.br + 1; ic <= h; ic++) {
                i = c_ix + mpcprueba2_B.nVars;
                for (g = c_ix + 1; g <= i; g++) {
                  memspace->workspace_float[g - 1] += b_H[(mpcprueba2_B.ar + g)
                    - c_ix] * qrmanager->Q[ic - 1];
                }

                mpcprueba2_B.ar += mpcprueba2_B.nVars;
              }

              mpcprueba2_B.br += mpcprueba2_B.ldQ;
            }
          }

          if (mpcprueba2_B.mNull != 0) {
            mpcprueba2_B.br = -1;
            mpcprueba2_B.lastColC = (mpcprueba2_B.mNull - 1) * cholmanager->ldm;
            for (c_ix = 0; b_jjA < 0 ? c_ix >= mpcprueba2_B.lastColC : c_ix <=
                 mpcprueba2_B.lastColC; c_ix += b_jjA) {
              g = c_ix + mpcprueba2_B.mNull;
              for (ic = c_ix + 1; ic <= g; ic++) {
                cholmanager->FMat[ic - 1] = 0.0;
              }
            }

            for (c_ix = 0; b_jjA < 0 ? c_ix >= mpcprueba2_B.lastColC : c_ix <=
                 mpcprueba2_B.lastColC; c_ix += b_jjA) {
              mpcprueba2_B.ar = mpcprueba2_B.b_idx_a;
              h = c_ix + mpcprueba2_B.mNull;
              for (ic = c_ix + 1; ic <= h; ic++) {
                mpcprueba2_B.b_temp = 0.0;
                for (g = 0; g < mpcprueba2_B.nVars; g++) {
                  mpcprueba2_B.b_temp += memspace->workspace_float[(g +
                    mpcprueba2_B.br) + 1] * qrmanager->Q[g + mpcprueba2_B.ar];
                }

                cholmanager->FMat[ic - 1] += mpcprueba2_B.b_temp;
                mpcprueba2_B.ar += mpcprueba2_B.ldQ;
              }

              mpcprueba2_B.br += 67;
            }
          }
        }

        mpcprueba2_B.b_SCALED_REG_PRIMAL = 1.4901161193847656E-8 *
          cholmanager->scaleFactor * static_cast<real_T>(mpcprueba2_B.mNull);
        cholmanager->ndims = mpcprueba2_B.mNull;
        mpcprueba2_B.nVars = mpcprueba2_ixamax(mpcprueba2_B.mNull,
          cholmanager->FMat, cholmanager->ldm + 1) - 1;
        mpcprueba2_B.b_temp = fabs(cholmanager->FMat[cholmanager->ldm *
          mpcprueba2_B.nVars + mpcprueba2_B.nVars]) * 2.2204460492503131E-16;
        mpcprueba2_B.u1_l = fabs(mpcprueba2_B.b_SCALED_REG_PRIMAL);
        if ((mpcprueba2_B.b_temp >= mpcprueba2_B.u1_l) || rtIsNaN
            (mpcprueba2_B.u1_l)) {
          cholmanager->regTol_ = mpcprueba2_B.b_temp;
        } else {
          cholmanager->regTol_ = mpcprueba2_B.u1_l;
        }

        mpcprueba2_fullColLDL2_(cholmanager, 1, mpcprueba2_B.mNull,
          mpcprueba2_B.b_SCALED_REG_PRIMAL);
        if (cholmanager->ConvexCheck) {
          mpcprueba2_B.nVars = 0;
          do {
            exitg1 = 0;
            if (mpcprueba2_B.nVars <= mpcprueba2_B.mNull - 1) {
              if (cholmanager->FMat[cholmanager->ldm * mpcprueba2_B.nVars +
                  mpcprueba2_B.nVars] <= 0.0) {
                cholmanager->info = -mpcprueba2_B.nVars - 1;
                exitg1 = 1;
              } else {
                mpcprueba2_B.nVars++;
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
          mpcprueba2_B.ldQ = qrmanager->ldq;
          if (qrmanager->mrows != 0) {
            memset(&memspace->workspace_float[0], 0, static_cast<uint32_T>
                   (mpcprueba2_B.mNull) * sizeof(real_T));
            c_ix = 0;
            ic = ((mpcprueba2_B.mNull - 1) * qrmanager->ldq +
                  mpcprueba2_B.b_idx_a) + 1;
            for (mpcprueba2_B.nVars = mpcprueba2_B.nullStartIdx;
                 mpcprueba2_B.ldQ < 0 ? mpcprueba2_B.nVars >= ic :
                 mpcprueba2_B.nVars <= ic; mpcprueba2_B.nVars +=
                 mpcprueba2_B.ldQ) {
              mpcprueba2_B.b_temp = 0.0;
              g = mpcprueba2_B.nVars + mpcprueba2_B.nVar_p;
              for (b_jjA = mpcprueba2_B.nVars; b_jjA <= g; b_jjA++) {
                mpcprueba2_B.b_temp += qrmanager->Q[b_jjA - 1] * objective->
                  grad[b_jjA - mpcprueba2_B.nVars];
              }

              memspace->workspace_float[c_ix] -= mpcprueba2_B.b_temp;
              c_ix++;
            }
          }

          mpcprueba2_B.nVars = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (mpcprueba2_B.nVar_p = 0; mpcprueba2_B.nVar_p <
                 mpcprueba2_B.nVars; mpcprueba2_B.nVar_p++) {
              b_jjA = mpcprueba2_B.nVar_p * cholmanager->ldm +
                mpcprueba2_B.nVar_p;
              mpcprueba2_B.ldQ = (mpcprueba2_B.nVars - mpcprueba2_B.nVar_p) - 2;
              for (mpcprueba2_B.nullStartIdx = 0; mpcprueba2_B.nullStartIdx <=
                   mpcprueba2_B.ldQ; mpcprueba2_B.nullStartIdx++) {
                c_ix = (mpcprueba2_B.nullStartIdx + mpcprueba2_B.nVar_p) + 1;
                memspace->workspace_float[c_ix] -= cholmanager->FMat
                  [(mpcprueba2_B.nullStartIdx + b_jjA) + 1] *
                  memspace->workspace_float[mpcprueba2_B.nVar_p];
              }
            }
          }

          mpcprueba2_B.nullStartIdx = cholmanager->ndims;
          for (mpcprueba2_B.nVar_p = 0; mpcprueba2_B.nVar_p <
               mpcprueba2_B.nullStartIdx; mpcprueba2_B.nVar_p++) {
            memspace->workspace_float[mpcprueba2_B.nVar_p] /= cholmanager->
              FMat[cholmanager->ldm * mpcprueba2_B.nVar_p + mpcprueba2_B.nVar_p];
          }

          mpcprueba2_B.nVars = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (mpcprueba2_B.nVar_p = mpcprueba2_B.nVars; mpcprueba2_B.nVar_p >=
                 1; mpcprueba2_B.nVar_p--) {
              b_jjA = (mpcprueba2_B.nVar_p - 1) * cholmanager->ldm;
              mpcprueba2_B.b_temp = memspace->
                workspace_float[mpcprueba2_B.nVar_p - 1];
              for (mpcprueba2_B.nullStartIdx = mpcprueba2_B.nVars;
                   mpcprueba2_B.nullStartIdx >= mpcprueba2_B.nVar_p + 1;
                   mpcprueba2_B.nullStartIdx--) {
                mpcprueba2_B.b_temp -= cholmanager->FMat[(b_jjA +
                  mpcprueba2_B.nullStartIdx) - 1] * memspace->
                  workspace_float[mpcprueba2_B.nullStartIdx - 1];
              }

              memspace->workspace_float[mpcprueba2_B.nVar_p - 1] =
                mpcprueba2_B.b_temp;
            }
          }

          mpcprueba2_xgemv_j30b(qrmanager->mrows, mpcprueba2_B.mNull,
                                qrmanager->Q, mpcprueba2_B.b_idx_a + 1,
                                qrmanager->ldq, memspace->workspace_float,
                                solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static real_T mpcprueba2_xnrm2_ls(int32_T n, const real_T x[16])
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
static void mpcprueba2_xgemv_j30bu(int32_T m, int32_T n, const real_T A[1056],
  int32_T lda, const real_T x[16], real_T y[1072])
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
static void mpcprueba2_xgemv_j30bul(int32_T m, int32_T n, const real_T A[1056],
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
static void mpcprueba2_ratiotest(const real_T solution_xstar[16], const real_T
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
  mpcprueba2_B.p_max = 0.0;
  totalIneq = workingset_sizes[2];
  totalUB = workingset_sizes[4];
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  mpcprueba2_B.denomTol = 2.2204460492503131E-13 * mpcprueba2_xnrm2_ls
    (workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    if (totalIneq - 1 >= 0) {
      memcpy(&workspace[0], &workingset_bineq[0], static_cast<uint32_T>
             (totalIneq) * sizeof(real_T));
    }

    mpcprueba2_xgemv_j30bu(workingset_nVar, workingset_sizes[2],
      workingset_Aineq, workingset_ldA, solution_xstar, workspace);
    mpcprueba2_xgemv_j30bul(workingset_nVar, workingset_sizes[2],
      workingset_Aineq, workingset_ldA, solution_searchDir, workspace);
    for (k = 0; k < totalIneq; k++) {
      workspace_0 = workspace[k + 67];
      if ((workspace_0 > mpcprueba2_B.denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[2] + k) - 1])) {
        mpcprueba2_B.phaseOneCorrectionX = workspace[k];
        mpcprueba2_B.alphaTemp = fabs(mpcprueba2_B.phaseOneCorrectionX -
          *toldelta);
        mpcprueba2_B.phaseOneCorrectionP = tolcon -
          mpcprueba2_B.phaseOneCorrectionX;
        mpcprueba2_B.ratio = mpcprueba2_B.phaseOneCorrectionP + *toldelta;
        if ((mpcprueba2_B.alphaTemp <= mpcprueba2_B.ratio) || rtIsNaN
            (mpcprueba2_B.ratio)) {
          mpcprueba2_B.ratio = mpcprueba2_B.alphaTemp;
        }

        mpcprueba2_B.alphaTemp = mpcprueba2_B.ratio / workspace_0;
        if ((mpcprueba2_B.alphaTemp <= *alpha) && (fabs(workspace_0) >
             mpcprueba2_B.p_max)) {
          *alpha = mpcprueba2_B.alphaTemp;
          *constrType = 3;
          *constrIdx = k + 1;
          *newBlocking = true;
        }

        mpcprueba2_B.alphaTemp = fabs(mpcprueba2_B.phaseOneCorrectionX);
        if ((mpcprueba2_B.alphaTemp <= mpcprueba2_B.phaseOneCorrectionP) ||
            rtIsNaN(mpcprueba2_B.phaseOneCorrectionP)) {
          mpcprueba2_B.phaseOneCorrectionP = mpcprueba2_B.alphaTemp;
        }

        mpcprueba2_B.alphaTemp = mpcprueba2_B.phaseOneCorrectionP / workspace_0;
        if (mpcprueba2_B.alphaTemp < *alpha) {
          *alpha = mpcprueba2_B.alphaTemp;
          *constrType = 3;
          *constrIdx = k + 1;
          *newBlocking = true;
          mpcprueba2_B.p_max = fabs(workspace_0);
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    mpcprueba2_B.phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    mpcprueba2_B.phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    totalIneq = workingset_sizes[3];
    for (k = 0; k <= totalIneq - 2; k++) {
      workingset_indexLB_0 = workingset_indexLB[k];
      mpcprueba2_B.pk_corrected = -solution_searchDir[workingset_indexLB_0 - 1]
        - mpcprueba2_B.phaseOneCorrectionP;
      if ((mpcprueba2_B.pk_corrected > mpcprueba2_B.denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] + k) - 1])) {
        workspace_0 = -solution_xstar[workingset_indexLB_0 - 1] -
          workingset_lb[workingset_indexLB_0 - 1];
        mpcprueba2_B.ratio = (workspace_0 - *toldelta) -
          mpcprueba2_B.phaseOneCorrectionX;
        mpcprueba2_B.alphaTemp = fabs(mpcprueba2_B.ratio);
        mpcprueba2_B.ratio = tolcon - mpcprueba2_B.ratio;
        if ((mpcprueba2_B.alphaTemp <= mpcprueba2_B.ratio) || rtIsNaN
            (mpcprueba2_B.ratio)) {
          mpcprueba2_B.ratio = mpcprueba2_B.alphaTemp;
        }

        mpcprueba2_B.alphaTemp = mpcprueba2_B.ratio / mpcprueba2_B.pk_corrected;
        if ((mpcprueba2_B.alphaTemp <= *alpha) && (fabs
             (mpcprueba2_B.pk_corrected) > mpcprueba2_B.p_max)) {
          *alpha = mpcprueba2_B.alphaTemp;
          *constrType = 4;
          *constrIdx = k + 1;
          *newBlocking = true;
        }

        mpcprueba2_B.ratio = workspace_0 - mpcprueba2_B.phaseOneCorrectionX;
        mpcprueba2_B.alphaTemp = fabs(mpcprueba2_B.ratio);
        mpcprueba2_B.ratio = tolcon - mpcprueba2_B.ratio;
        if ((mpcprueba2_B.alphaTemp <= mpcprueba2_B.ratio) || rtIsNaN
            (mpcprueba2_B.ratio)) {
          mpcprueba2_B.ratio = mpcprueba2_B.alphaTemp;
        }

        mpcprueba2_B.alphaTemp = mpcprueba2_B.ratio / mpcprueba2_B.pk_corrected;
        if (mpcprueba2_B.alphaTemp < *alpha) {
          *alpha = mpcprueba2_B.alphaTemp;
          *constrType = 4;
          *constrIdx = k + 1;
          *newBlocking = true;
          mpcprueba2_B.p_max = fabs(mpcprueba2_B.pk_corrected);
        }
      }
    }

    k = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    mpcprueba2_B.phaseOneCorrectionX = solution_searchDir[k];
    if ((-mpcprueba2_B.phaseOneCorrectionX > mpcprueba2_B.denomTol) &&
        (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
          workingset_sizes[3]) - 2])) {
      workspace_0 = -solution_xstar[k] - workingset_lb[k];
      mpcprueba2_B.ratio = workspace_0 - *toldelta;
      mpcprueba2_B.alphaTemp = fabs(mpcprueba2_B.ratio);
      mpcprueba2_B.ratio = tolcon - mpcprueba2_B.ratio;
      if ((mpcprueba2_B.alphaTemp <= mpcprueba2_B.ratio) || rtIsNaN
          (mpcprueba2_B.ratio)) {
        mpcprueba2_B.ratio = mpcprueba2_B.alphaTemp;
      }

      mpcprueba2_B.alphaTemp = mpcprueba2_B.ratio /
        -mpcprueba2_B.phaseOneCorrectionX;
      if ((mpcprueba2_B.alphaTemp <= *alpha) && (fabs
           (mpcprueba2_B.phaseOneCorrectionX) > mpcprueba2_B.p_max)) {
        *alpha = mpcprueba2_B.alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      mpcprueba2_B.alphaTemp = fabs(workspace_0);
      mpcprueba2_B.ratio = tolcon - workspace_0;
      if ((mpcprueba2_B.alphaTemp <= mpcprueba2_B.ratio) || rtIsNaN
          (mpcprueba2_B.ratio)) {
        mpcprueba2_B.ratio = mpcprueba2_B.alphaTemp;
      }

      mpcprueba2_B.alphaTemp = mpcprueba2_B.ratio /
        -mpcprueba2_B.phaseOneCorrectionX;
      if (mpcprueba2_B.alphaTemp < *alpha) {
        *alpha = mpcprueba2_B.alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        mpcprueba2_B.p_max = fabs(mpcprueba2_B.phaseOneCorrectionX);
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    mpcprueba2_B.phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    mpcprueba2_B.phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    for (k = 0; k < totalUB; k++) {
      totalIneq = workingset_indexUB[k];
      mpcprueba2_B.pk_corrected = solution_searchDir[totalIneq - 1] -
        mpcprueba2_B.phaseOneCorrectionP;
      if ((mpcprueba2_B.pk_corrected > mpcprueba2_B.denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] + k) - 1])) {
        workspace_0 = solution_xstar[totalIneq - 1] - workingset_ub[totalIneq -
          1];
        mpcprueba2_B.ratio = (workspace_0 - *toldelta) -
          mpcprueba2_B.phaseOneCorrectionX;
        mpcprueba2_B.alphaTemp = fabs(mpcprueba2_B.ratio);
        mpcprueba2_B.ratio = tolcon - mpcprueba2_B.ratio;
        if ((mpcprueba2_B.alphaTemp <= mpcprueba2_B.ratio) || rtIsNaN
            (mpcprueba2_B.ratio)) {
          mpcprueba2_B.ratio = mpcprueba2_B.alphaTemp;
        }

        mpcprueba2_B.alphaTemp = mpcprueba2_B.ratio / mpcprueba2_B.pk_corrected;
        if ((mpcprueba2_B.alphaTemp <= *alpha) && (fabs
             (mpcprueba2_B.pk_corrected) > mpcprueba2_B.p_max)) {
          *alpha = mpcprueba2_B.alphaTemp;
          *constrType = 5;
          *constrIdx = k + 1;
          *newBlocking = true;
        }

        mpcprueba2_B.ratio = workspace_0 - mpcprueba2_B.phaseOneCorrectionX;
        mpcprueba2_B.alphaTemp = fabs(mpcprueba2_B.ratio);
        mpcprueba2_B.ratio = tolcon - mpcprueba2_B.ratio;
        if ((mpcprueba2_B.alphaTemp <= mpcprueba2_B.ratio) || rtIsNaN
            (mpcprueba2_B.ratio)) {
          mpcprueba2_B.ratio = mpcprueba2_B.alphaTemp;
        }

        mpcprueba2_B.alphaTemp = mpcprueba2_B.ratio / mpcprueba2_B.pk_corrected;
        if (mpcprueba2_B.alphaTemp < *alpha) {
          *alpha = mpcprueba2_B.alphaTemp;
          *constrType = 5;
          *constrIdx = k + 1;
          *newBlocking = true;
          mpcprueba2_B.p_max = fabs(mpcprueba2_B.pk_corrected);
        }
      }
    }
  }

  *toldelta += 6.608625846508183E-7;
  if (mpcprueba2_B.p_max > 0.0) {
    mpcprueba2_B.ratio = 6.608625846508183E-7 / mpcprueba2_B.p_max;
    if (!(*alpha >= mpcprueba2_B.ratio)) {
      *alpha = mpcprueba2_B.ratio;
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
static void mpcprueba2_feasibleratiotest(const real_T solution_xstar[16], const
  real_T solution_searchDir[16], real_T workspace[1072], int32_T workingset_nVar,
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
  mpcprueba2_B.denomTol_o = 2.2204460492503131E-13 * mpcprueba2_xnrm2_ls
    (workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    if (totalIneq - 1 >= 0) {
      memcpy(&workspace[0], &workingset_bineq[0], static_cast<uint32_T>
             (totalIneq) * sizeof(real_T));
    }

    mpcprueba2_xgemv_j30bu(workingset_nVar, workingset_sizes[2],
      workingset_Aineq, workingset_ldA, solution_xstar, workspace);
    mpcprueba2_xgemv_j30bul(workingset_nVar, workingset_sizes[2],
      workingset_Aineq, workingset_ldA, solution_searchDir, workspace);
    for (k = 0; k < totalIneq; k++) {
      mpcprueba2_B.phaseOneCorrectionX_n = workspace[k + 67];
      if ((mpcprueba2_B.phaseOneCorrectionX_n > mpcprueba2_B.denomTol_o) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] + k) - 1])) {
        ratio = workspace[k];
        mpcprueba2_B.alphaTemp_b = fabs(ratio);
        ratio = tolcon - ratio;
        if ((mpcprueba2_B.alphaTemp_b <= ratio) || rtIsNaN(ratio)) {
          ratio = mpcprueba2_B.alphaTemp_b;
        }

        mpcprueba2_B.alphaTemp_b = ratio / mpcprueba2_B.phaseOneCorrectionX_n;
        if (mpcprueba2_B.alphaTemp_b < *alpha) {
          *alpha = mpcprueba2_B.alphaTemp_b;
          *constrType = 3;
          *constrIdx = k + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    mpcprueba2_B.phaseOneCorrectionX_n = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    mpcprueba2_B.phaseOneCorrectionP_b = solution_searchDir[workingset_nVar - 1]
      * static_cast<real_T>(isPhaseOne);
    k = workingset_sizes[3];
    for (totalIneq = 0; totalIneq <= k - 2; totalIneq++) {
      workingset_indexLB_0 = workingset_indexLB[totalIneq];
      mpcprueba2_B.pk_corrected_l = -solution_searchDir[workingset_indexLB_0 - 1]
        - mpcprueba2_B.phaseOneCorrectionP_b;
      if ((mpcprueba2_B.pk_corrected_l > mpcprueba2_B.denomTol_o) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] + totalIneq) -
           1])) {
        ratio = (-solution_xstar[workingset_indexLB_0 - 1] -
                 workingset_lb[workingset_indexLB_0 - 1]) -
          mpcprueba2_B.phaseOneCorrectionX_n;
        mpcprueba2_B.alphaTemp_b = fabs(ratio);
        ratio = tolcon - ratio;
        if ((mpcprueba2_B.alphaTemp_b <= ratio) || rtIsNaN(ratio)) {
          ratio = mpcprueba2_B.alphaTemp_b;
        }

        mpcprueba2_B.alphaTemp_b = ratio / mpcprueba2_B.pk_corrected_l;
        if (mpcprueba2_B.alphaTemp_b < *alpha) {
          *alpha = mpcprueba2_B.alphaTemp_b;
          *constrType = 4;
          *constrIdx = totalIneq + 1;
          *newBlocking = true;
        }
      }
    }

    totalIneq = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    mpcprueba2_B.phaseOneCorrectionX_n = -solution_searchDir[totalIneq];
    if ((mpcprueba2_B.phaseOneCorrectionX_n > mpcprueba2_B.denomTol_o) &&
        (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
          workingset_sizes[3]) - 2])) {
      ratio = -solution_xstar[totalIneq] - workingset_lb[totalIneq];
      mpcprueba2_B.alphaTemp_b = fabs(ratio);
      ratio = tolcon - ratio;
      if ((mpcprueba2_B.alphaTemp_b <= ratio) || rtIsNaN(ratio)) {
        ratio = mpcprueba2_B.alphaTemp_b;
      }

      mpcprueba2_B.alphaTemp_b = ratio / mpcprueba2_B.phaseOneCorrectionX_n;
      if (mpcprueba2_B.alphaTemp_b < *alpha) {
        *alpha = mpcprueba2_B.alphaTemp_b;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    mpcprueba2_B.phaseOneCorrectionX_n = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    mpcprueba2_B.phaseOneCorrectionP_b = solution_searchDir[workingset_nVar - 1]
      * static_cast<real_T>(isPhaseOne);
    for (totalIneq = 0; totalIneq < totalUB; totalIneq++) {
      k = workingset_indexUB[totalIneq];
      mpcprueba2_B.pk_corrected_l = solution_searchDir[k - 1] -
        mpcprueba2_B.phaseOneCorrectionP_b;
      if ((mpcprueba2_B.pk_corrected_l > mpcprueba2_B.denomTol_o) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] + totalIneq) -
           1])) {
        ratio = (solution_xstar[k - 1] - workingset_ub[k - 1]) -
          mpcprueba2_B.phaseOneCorrectionX_n;
        mpcprueba2_B.alphaTemp_b = fabs(ratio);
        ratio = tolcon - ratio;
        if ((mpcprueba2_B.alphaTemp_b <= ratio) || rtIsNaN(ratio)) {
          ratio = mpcprueba2_B.alphaTemp_b;
        }

        mpcprueba2_B.alphaTemp_b = ratio / mpcprueba2_B.pk_corrected_l;
        if (mpcprueba2_B.alphaTemp_b < *alpha) {
          *alpha = mpcprueba2_B.alphaTemp_b;
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
static void mpcp_addBoundToActiveSetMatrix_(sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *obj,
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
static void mpcprueba2_compute_lambda(real_T workspace[1072],
  sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T *solution, const
  s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *objective, const
  ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager)
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
static void mpcp_checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f[15], sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T *solution,
  sFevNsrsl34D5b5aqm3qNjD_mpcpr_T *memspace, const
  s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *objective, sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T
  *workingset, ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager, real_T
  options_ObjectiveLimit, real_T options_ConstraintTolerance, int32_T
  runTimeOptions_MaxIterations, real_T runTimeOptions_ConstrRelTolFact,
  boolean_T *updateFval, boolean_T iterDisplayQP)
{
  boolean_T nonDegenerateWset;
  solution->iterations++;
  mpcprueba2_B.nVar_j = objective->nvar;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }

  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    mpcprueba2_B.tempMaxConstr = mpcpr_maxConstraintViolation_n3(workingset,
      solution->xstar);
    solution->maxConstr = mpcprueba2_B.tempMaxConstr;
    if (objective->objtype == 5) {
      mpcprueba2_B.tempMaxConstr = solution->maxConstr - solution->
        xstar[objective->nvar - 1];
    }

    if (mpcprueba2_B.tempMaxConstr > options_ConstraintTolerance *
        runTimeOptions_ConstrRelTolFact) {
      if (mpcprueba2_B.nVar_j - 1 >= 0) {
        memcpy(&solution->searchDir[0], &solution->xstar[0],
               static_cast<uint32_T>(mpcprueba2_B.nVar_j) * sizeof(real_T));
      }

      nonDegenerateWset = mpcprue_feasibleX0ForWorkingSet
        (memspace->workspace_float, solution->searchDir, workingset, qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }

      *activeSetChangeID = 0;
      mpcprueba2_B.tempMaxConstr = mpcpr_maxConstraintViolation_n3(workingset,
        solution->searchDir);
      if (mpcprueba2_B.tempMaxConstr < solution->maxConstr) {
        if (mpcprueba2_B.nVar_j - 1 >= 0) {
          memcpy(&solution->xstar[0], &solution->searchDir[0],
                 static_cast<uint32_T>(mpcprueba2_B.nVar_j) * sizeof(real_T));
        }

        solution->maxConstr = mpcprueba2_B.tempMaxConstr;
      }
    }
  }

  if (*updateFval) {
    if ((options_ObjectiveLimit > (rtMinusInf)) || iterDisplayQP) {
      solution->fstar = mpcprueba2_computeFval_ReuseHx(objective,
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
static void mpcprueba2_computeFirstOrderOpt(sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T
  *solution, const s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *objective, int32_T
  workingset_nVar, int32_T workingset_ldA, const real_T workingset_ATwset[1072],
  int32_T workingset_nActiveConstr, real_T workspace[1072])
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
static void mpcprueba2_iterate(const real_T b_H[225], const real_T f[15],
  sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpcpr_T
  *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *workingset,
  ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager, sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T
  *cholmanager, s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *objective, boolean_T
  options_IterDisplayQP, real_T options_ObjectiveLimit, real_T
  options_PricingTolerance, real_T options_ConstraintTolerance, real_T
  options_StepTolerance, const sIOJhD9KwAkF5sEguPjYquC_mpcpr_T runTimeOptions)
{
  int32_T exitg1;
  boolean_T guard1;
  boolean_T guard11;
  boolean_T newBlocking;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  mpcprueba2_B.activeSetChangeID = 0;
  mpcprueba2_B.TYPE = objective->objtype;
  mpcprueba2_B.tolDelta = 6.7434957617430445E-7;
  mpcprueba2_B.nVar = workingset->nVar;
  mpcprueba2_B.globalActiveConstrIdx = 0;
  mpcprueba2_computeGrad_StoreHx(objective, b_H, f, solution->xstar);
  solution->fstar = mpcprueba2_computeFval_ReuseHx(objective,
    memspace->workspace_float, f, solution->xstar);
  if (solution->iterations < runTimeOptions.MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  mpcprueba2_B.minmn = workingset->mConstrMax;
  if (mpcprueba2_B.minmn - 1 >= 0) {
    memset(&solution->lambda[0], 0, static_cast<uint32_T>(mpcprueba2_B.minmn) *
           sizeof(real_T));
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
        switch (mpcprueba2_B.activeSetChangeID) {
         case 1:
          mpcprueba2_squareQ_appendCol(qrmanager, workingset->ATwset,
            workingset->ldA * (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          mpcprueba2_deleteColMoveEnd(qrmanager,
            mpcprueba2_B.globalActiveConstrIdx);
          break;

         default:
          mpcprueba2_B.iAw0 = workingset->nActiveConstr;
          guard1 = false;
          if (mpcprueba2_B.nVar * workingset->nActiveConstr > 0) {
            for (mpcprueba2_B.i_b = 0; mpcprueba2_B.i_b < mpcprueba2_B.iAw0;
                 mpcprueba2_B.i_b++) {
              mpcprueba2_B.ix0 = workingset->ldA * mpcprueba2_B.i_b;
              mpcprueba2_B.iy0 = qrmanager->ldq * mpcprueba2_B.i_b;
              for (mpcprueba2_B.minmn = 0; mpcprueba2_B.minmn <
                   mpcprueba2_B.nVar; mpcprueba2_B.minmn++) {
                qrmanager->QR[mpcprueba2_B.iy0 + mpcprueba2_B.minmn] =
                  workingset->ATwset[mpcprueba2_B.minmn + mpcprueba2_B.ix0];
              }
            }

            guard1 = true;
          } else if (mpcprueba2_B.nVar * workingset->nActiveConstr == 0) {
            qrmanager->mrows = mpcprueba2_B.nVar;
            qrmanager->ncols = workingset->nActiveConstr;
            qrmanager->minRowCol = 0;
          } else {
            guard1 = true;
          }

          if (guard1) {
            qrmanager->usedPivoting = false;
            qrmanager->mrows = mpcprueba2_B.nVar;
            qrmanager->ncols = workingset->nActiveConstr;
            mpcprueba2_B.minmn = workingset->nActiveConstr;
            for (mpcprueba2_B.i_b = 0; mpcprueba2_B.i_b < mpcprueba2_B.minmn;
                 mpcprueba2_B.i_b++) {
              qrmanager->jpvt[mpcprueba2_B.i_b] = mpcprueba2_B.i_b + 1;
            }

            if (mpcprueba2_B.nVar <= workingset->nActiveConstr) {
              qrmanager->minRowCol = mpcprueba2_B.nVar;
            } else {
              qrmanager->minRowCol = workingset->nActiveConstr;
            }

            if (mpcprueba2_B.nVar <= workingset->nActiveConstr) {
              mpcprueba2_B.minmn = mpcprueba2_B.nVar;
            } else {
              mpcprueba2_B.minmn = workingset->nActiveConstr;
            }

            memset(&qrmanager->tau[0], 0, sizeof(real_T) << 4U);
            if (mpcprueba2_B.minmn >= 1) {
              memset(&qrmanager->tau[0], 0, sizeof(real_T) << 4U);
              mpcprueba2_qrf(qrmanager->QR, 1, mpcprueba2_B.nVar,
                             workingset->nActiveConstr, mpcprueba2_B.minmn,
                             qrmanager->tau);
            }
          }

          mpcprueba2_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        mpcprueba2_compute_deltax(b_H, solution, memspace, qrmanager,
          cholmanager, objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          mpcprueba2_B.normDelta = mpcprueba2_xnrm2_ls(mpcprueba2_B.nVar,
            solution->searchDir);
          guard11 = true;
        }
      } else {
        if (mpcprueba2_B.nVar - 1 >= 0) {
          memset(&solution->searchDir[0], 0, static_cast<uint32_T>
                 (mpcprueba2_B.nVar) * sizeof(real_T));
        }

        mpcprueba2_B.normDelta = 0.0;
        guard11 = true;
      }

      if (guard11) {
        if ((!subProblemChanged) || (mpcprueba2_B.normDelta <
             options_StepTolerance) || (workingset->nActiveConstr >=
             mpcprueba2_B.nVar)) {
          mpcprueba2_compute_lambda(memspace->workspace_float, solution,
            objective, qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr >
               mpcprueba2_B.nVar)) {
            mpcprueba2_B.minmn = 0;
            mpcprueba2_B.minLambda = options_PricingTolerance *
              runTimeOptions.ProbRelTolFactor * static_cast<real_T>
              (mpcprueba2_B.TYPE != 5);
            mpcprueba2_B.iAw0 = (workingset->nWConstr[0] + workingset->nWConstr
                                 [1]) + 1;
            mpcprueba2_B.ix0 = workingset->nActiveConstr;
            for (mpcprueba2_B.i_b = mpcprueba2_B.iAw0; mpcprueba2_B.i_b <=
                 mpcprueba2_B.ix0; mpcprueba2_B.i_b++) {
              mpcprueba2_B.solution_lambda = solution->lambda[mpcprueba2_B.i_b -
                1];
              if (mpcprueba2_B.solution_lambda < mpcprueba2_B.minLambda) {
                mpcprueba2_B.minLambda = mpcprueba2_B.solution_lambda;
                mpcprueba2_B.minmn = mpcprueba2_B.i_b;
              }
            }

            if (mpcprueba2_B.minmn == 0) {
              solution->state = 1;
            } else {
              mpcprueba2_B.activeSetChangeID = -1;
              mpcprueba2_B.globalActiveConstrIdx = mpcprueba2_B.minmn;
              subProblemChanged = true;
              mpcprueba2_removeConstr(workingset, mpcprueba2_B.minmn);
              if (mpcprueba2_B.minmn < workingset->nActiveConstr + 1) {
                solution->lambda[mpcprueba2_B.minmn - 1] = solution->
                  lambda[workingset->nActiveConstr];
              }

              solution->lambda[workingset->nActiveConstr] = 0.0;
            }
          } else {
            mpcprueba2_B.minmn = workingset->nActiveConstr;
            mpcprueba2_B.activeSetChangeID = 0;
            mpcprueba2_B.globalActiveConstrIdx = workingset->nActiveConstr;
            subProblemChanged = true;
            mpcprueba2_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[mpcprueba2_B.minmn - 1] = 0.0;
          }

          updateFval = false;
        } else {
          updateFval = (mpcprueba2_B.TYPE == 5);
          if (updateFval || runTimeOptions.RemainFeasible) {
            mpcprueba2_feasibleratiotest(solution->xstar, solution->searchDir,
              memspace->workspace_float, workingset->nVar, workingset->ldA,
              workingset->Aineq, workingset->bineq, workingset->lb,
              workingset->ub, workingset->indexLB, workingset->indexUB,
              workingset->sizes, workingset->isActiveIdx,
              workingset->isActiveConstr, workingset->nWConstr, updateFval,
              options_ConstraintTolerance, &mpcprueba2_B.minLambda, &newBlocking,
              &mpcprueba2_B.minmn, &mpcprueba2_B.i_b);
          } else {
            mpcprueba2_ratiotest(solution->xstar, solution->searchDir,
                                 memspace->workspace_float, workingset->nVar,
                                 workingset->ldA, workingset->Aineq,
                                 workingset->bineq, workingset->lb,
                                 workingset->ub, workingset->indexLB,
                                 workingset->indexUB, workingset->sizes,
                                 workingset->isActiveIdx,
                                 workingset->isActiveConstr,
                                 workingset->nWConstr, false,
                                 options_ConstraintTolerance,
                                 &mpcprueba2_B.tolDelta, &mpcprueba2_B.minLambda,
                                 &newBlocking, &mpcprueba2_B.minmn,
                                 &mpcprueba2_B.i_b);
          }

          if (newBlocking) {
            switch (mpcprueba2_B.minmn) {
             case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr[(workingset->isActiveIdx[2] +
                mpcprueba2_B.i_b) - 2] = true;
              workingset->nActiveConstr++;
              workingset->Wid[workingset->nActiveConstr - 1] = 3;
              workingset->Wlocalidx[workingset->nActiveConstr - 1] =
                mpcprueba2_B.i_b;
              mpcprueba2_B.minmn = (mpcprueba2_B.i_b - 1) * workingset->ldA;
              mpcprueba2_B.iAw0 = (workingset->nActiveConstr - 1) *
                workingset->ldA;
              mpcprueba2_B.ix0 = workingset->nVar;
              for (mpcprueba2_B.activeSetChangeID = 0;
                   mpcprueba2_B.activeSetChangeID < mpcprueba2_B.ix0;
                   mpcprueba2_B.activeSetChangeID++) {
                workingset->ATwset[mpcprueba2_B.iAw0 +
                  mpcprueba2_B.activeSetChangeID] = workingset->
                  Aineq[mpcprueba2_B.minmn + mpcprueba2_B.activeSetChangeID];
              }

              workingset->bwset[workingset->nActiveConstr - 1] =
                workingset->bineq[mpcprueba2_B.i_b - 1];
              break;

             case 4:
              mpcp_addBoundToActiveSetMatrix_(workingset, 4, mpcprueba2_B.i_b);
              break;

             default:
              mpcp_addBoundToActiveSetMatrix_(workingset, 5, mpcprueba2_B.i_b);
              break;
            }

            mpcprueba2_B.activeSetChangeID = 1;
          } else {
            if (objective->objtype == 5) {
              if (mpcprueba2_xnrm2_ls(objective->nvar, solution->searchDir) >
                  100.0 * static_cast<real_T>(objective->nvar) *
                  1.4901161193847656E-8) {
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

          if ((mpcprueba2_B.nVar >= 1) && (!(mpcprueba2_B.minLambda == 0.0))) {
            for (mpcprueba2_B.i_b = 0; mpcprueba2_B.i_b < mpcprueba2_B.nVar;
                 mpcprueba2_B.i_b++) {
              solution->xstar[mpcprueba2_B.i_b] += mpcprueba2_B.minLambda *
                solution->searchDir[mpcprueba2_B.i_b];
            }
          }

          mpcprueba2_computeGrad_StoreHx(objective, b_H, f, solution->xstar);
          updateFval = true;
        }

        mpcp_checkStoppingAndUpdateFval(&mpcprueba2_B.activeSetChangeID, f,
          solution, memspace, objective, workingset, qrmanager,
          options_ObjectiveLimit, options_ConstraintTolerance,
          runTimeOptions.MaxIterations, runTimeOptions.ConstrRelTolFactor,
          &updateFval, options_IterDisplayQP);
        if (options_IterDisplayQP) {
          if (solution->iterations - solution->iterations / 50 * 50 == 0) {
            std::printf("                                          First-order\n");
            std::fflush(stdout);
            std::printf(" Iter            Fval     Feasibility      Optimality    Norm of step\n");
            std::fflush(stdout);
          } else {
            solution->maxConstr = mpcpr_maxConstraintViolation_n3(workingset,
              solution->xstar);
          }

          mpcprueba2_computeFirstOrderOpt(solution, objective, workingset->nVar,
            workingset->ldA, workingset->ATwset, workingset->nActiveConstr,
            memspace->workspace_float);
          std::printf("%5i  %14.6e  %14.6e  %14.6e", solution->iterations,
                      solution->fstar, solution->maxConstr,
                      solution->firstorderopt);
          std::fflush(stdout);
          std::printf("  ");
          std::fflush(stdout);
          std::printf("%14.6e", mpcprueba2_B.normDelta);
          std::fflush(stdout);
          std::printf("\n");
          std::fflush(stdout);
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = mpcprueba2_computeFval_ReuseHx(objective,
          memspace->workspace_float, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_PresolveWorkingSet_e(sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T
  *solution, sFevNsrsl34D5b5aqm3qNjD_mpcpr_T *memspace,
  sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *workingset, ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T
  *qrmanager, const sqZVQFgLZG74FDpCArykMHB_mpcpr_T *options)
{
  boolean_T guard1;
  boolean_T okWorkingSet;
  solution->state = 82;
  mpcprueba2_B.nVar_o = workingset->nVar;
  mpcprueba2_B.mTotalWorkingEq = workingset->nWConstr[0] + workingset->nWConstr
    [1];
  mpcprueba2_B.nDepInd = 0;
  if (mpcprueba2_B.mTotalWorkingEq > 0) {
    for (mpcprueba2_B.idx_row = 0; mpcprueba2_B.idx_row <
         mpcprueba2_B.mTotalWorkingEq; mpcprueba2_B.idx_row++) {
      for (mpcprueba2_B.idxStartIneq_n = 0; mpcprueba2_B.idxStartIneq_n <
           mpcprueba2_B.nVar_o; mpcprueba2_B.idxStartIneq_n++) {
        qrmanager->QR[mpcprueba2_B.idx_row + qrmanager->ldq *
          mpcprueba2_B.idxStartIneq_n] = workingset->ATwset[workingset->ldA *
          mpcprueba2_B.idx_row + mpcprueba2_B.idxStartIneq_n];
      }
    }

    mpcprueba2_B.nDepInd = mpcprueb_ComputeNumDependentEq_(qrmanager,
      workingset->bwset, mpcprueba2_B.mTotalWorkingEq, workingset->nVar);
    if (mpcprueba2_B.nDepInd > 0) {
      for (mpcprueba2_B.idx_row = 0; mpcprueba2_B.idx_row <
           mpcprueba2_B.mTotalWorkingEq; mpcprueba2_B.idx_row++) {
        mpcprueba2_B.iy0_o = qrmanager->ldq * mpcprueba2_B.idx_row;
        mpcprueba2_B.ix0_i = workingset->ldA * mpcprueba2_B.idx_row;
        for (mpcprueba2_B.idxStartIneq_n = 0; mpcprueba2_B.idxStartIneq_n <
             mpcprueba2_B.nVar_o; mpcprueba2_B.idxStartIneq_n++) {
          qrmanager->QR[mpcprueba2_B.iy0_o + mpcprueba2_B.idxStartIneq_n] =
            workingset->ATwset[mpcprueba2_B.idxStartIneq_n + mpcprueba2_B.ix0_i];
        }
      }

      mpcprueba2_IndexOfDependentEq_(memspace->workspace_int,
        workingset->nWConstr[0], mpcprueba2_B.nDepInd, qrmanager,
        workingset->nVar, mpcprueba2_B.mTotalWorkingEq);
      mpcprueba2_countsort(memspace->workspace_int, mpcprueba2_B.nDepInd,
                           memspace->workspace_sort, 1,
                           mpcprueba2_B.mTotalWorkingEq);
      for (mpcprueba2_B.idx_row = mpcprueba2_B.nDepInd; mpcprueba2_B.idx_row >=
           1; mpcprueba2_B.idx_row--) {
        mpcprueba2_removeEqConstr(workingset, memspace->
          workspace_int[mpcprueba2_B.idx_row - 1]);
      }
    }
  }

  if ((mpcprueba2_B.nDepInd != -1) && (workingset->nActiveConstr <=
       qrmanager->ldq)) {
    mpcprueba2_RemoveDependentIneq_(workingset, qrmanager, memspace, 1.0);
    okWorkingSet = mpcprue_feasibleX0ForWorkingSet(memspace->workspace_float,
      solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      mpcprueba2_RemoveDependentIneq_(workingset, qrmanager, memspace, 10.0);
      okWorkingSet = mpcprue_feasibleX0ForWorkingSet(memspace->workspace_float,
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
        mpcprueba2_B.constrViolation = mpcpr_maxConstraintViolation_n3
          (workingset, solution->xstar);
        if (mpcprueba2_B.constrViolation > options->ConstraintTolerance) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    mpcprueba2_B.idxStartIneq_n = (workingset->nWConstr[0] +
      workingset->nWConstr[1]) + 1;
    mpcprueba2_B.nVar_o = workingset->nActiveConstr;
    for (mpcprueba2_B.idx_row = mpcprueba2_B.idxStartIneq_n;
         mpcprueba2_B.idx_row <= mpcprueba2_B.nVar_o; mpcprueba2_B.idx_row++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[mpcprueba2_B.idx_row - 1] - 1] + workingset->
        Wlocalidx[mpcprueba2_B.idx_row - 1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function5'
static void mpcprueba2_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace[1072], const real_T b_H[225], const real_T f[15], const
  real_T x[16])
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
static real_T mpcprueba2_computeFval(const s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T *obj,
  real_T workspace[1072], const real_T b_H[225], const real_T f[15], const
  real_T x[16])
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
    mpcprueba2_linearForm_(obj->hasLinear, obj->nvar, workspace, b_H, f, x);
    if (obj->nvar >= 1) {
      ixlast = obj->nvar;
      for (k = 0; k < ixlast; k++) {
        val += x[k] * workspace[k];
      }
    }
    break;

   case 4:
    mpcprueba2_linearForm_(obj->hasLinear, obj->nvar, workspace, b_H, f, x);
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
static void mpcprueba2_driver(const real_T b_H[225], const real_T f[15],
  sqvdR3NQrfOjUOrC18Muj0B_mpcpr_T *solution, sFevNsrsl34D5b5aqm3qNjD_mpcpr_T
  *memspace, sbYdmyzq7l8Oes4F6y6cc2C_mpcpr_T *workingset,
  sOWFOmKuLvD2kpFwfdM45bG_mpcpr_T *cholmanager, const
  sqZVQFgLZG74FDpCArykMHB_mpcpr_T options, int32_T runTimeOptions_MaxIterations,
  real_T runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
  ssq2hyGkLOLhNlUBS6YfcCD_mpcpr_T *qrmanager, s3c01M66EFWFQJ5qmFcUbmD_mpcpr_T
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
  mpcprueba2_B.i_e = workingset->nVar;
  tmp = mpcprueba2_strcmp(options.SolverName);
  guard1 = false;
  guard2 = false;
  if (tmp || (workingset->probType == 3)) {
    mpcprueba2_B.idxStartIneq = workingset->sizes[0];
    for (mpcprueba2_B.mConstr = 0; mpcprueba2_B.mConstr <
         mpcprueba2_B.idxStartIneq; mpcprueba2_B.mConstr++) {
      solution->xstar[workingset->indexFixed[mpcprueba2_B.mConstr] - 1] =
        workingset->ub[workingset->indexFixed[mpcprueba2_B.mConstr] - 1];
    }

    mpcprueba2_B.idxStartIneq = workingset->sizes[3];
    for (mpcprueba2_B.mConstr = 0; mpcprueba2_B.mConstr <
         mpcprueba2_B.idxStartIneq; mpcprueba2_B.mConstr++) {
      if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
           mpcprueba2_B.mConstr) - 1]) {
        solution->xstar[workingset->indexLB[mpcprueba2_B.mConstr] - 1] =
          -workingset->lb[workingset->indexLB[mpcprueba2_B.mConstr] - 1];
      }
    }

    mpcprueba2_B.idxStartIneq = workingset->sizes[4];
    for (mpcprueba2_B.mConstr = 0; mpcprueba2_B.mConstr <
         mpcprueba2_B.idxStartIneq; mpcprueba2_B.mConstr++) {
      if (workingset->isActiveConstr[(workingset->isActiveIdx[4] +
           mpcprueba2_B.mConstr) - 1]) {
        solution->xstar[workingset->indexUB[mpcprueba2_B.mConstr] - 1] =
          workingset->ub[workingset->indexUB[mpcprueba2_B.mConstr] - 1];
      }
    }

    mpcprueba2_PresolveWorkingSet(solution, memspace, workingset, &options,
      qrmanager);
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
    solution->maxConstr = mpcpr_maxConstraintViolation_n3(workingset,
      solution->xstar);
    mpcprueba2_B.d = options.ConstraintTolerance *
      runTimeOptions_ConstrRelTolFact;
    if (solution->maxConstr > mpcprueba2_B.d) {
      solution->xstar[workingset->nVar] = solution->maxConstr + 1.0;
      mpcprueba2_B.b_workingset = *workingset;
      if (workingset->probType == 3) {
        mpcprueba2_B.idxEndIneq = 1;
      } else {
        mpcprueba2_B.idxEndIneq = 4;
      }

      mpcprueba2_setProblemType(&mpcprueba2_B.b_workingset,
        mpcprueba2_B.idxEndIneq);
      mpcprueba2_B.idxStartIneq = (mpcprueba2_B.b_workingset.nWConstr[0] +
        mpcprueba2_B.b_workingset.nWConstr[1]) + 1;
      mpcprueba2_B.idxEndIneq = mpcprueba2_B.b_workingset.nActiveConstr;
      for (mpcprueba2_B.mConstr = mpcprueba2_B.idxStartIneq;
           mpcprueba2_B.mConstr <= mpcprueba2_B.idxEndIneq; mpcprueba2_B.mConstr
           ++) {
        mpcprueba2_B.b_workingset.isActiveConstr
          [(mpcprueba2_B.b_workingset.isActiveIdx[mpcprueba2_B.b_workingset.Wid[mpcprueba2_B.mConstr
            - 1] - 1] + mpcprueba2_B.b_workingset.Wlocalidx[mpcprueba2_B.mConstr
            - 1]) - 2] = false;
      }

      mpcprueba2_B.b_workingset.nWConstr[2] = 0;
      mpcprueba2_B.b_workingset.nWConstr[3] = 0;
      mpcprueba2_B.b_workingset.nWConstr[4] = 0;
      mpcprueba2_B.b_workingset.nActiveConstr =
        mpcprueba2_B.b_workingset.nWConstr[0] +
        mpcprueba2_B.b_workingset.nWConstr[1];
      objective->prev_objtype = 3;
      objective->prev_nvar = 15;
      objective->prev_hasLinear = true;
      objective->objtype = 5;
      objective->nvar = workingset->nVar + 1;
      objective->gammaScalar = 1.0;
      objective->hasLinear = true;
      solution->fstar = solution->xstar[workingset->nVar];
      solution->state = 5;
      mpcprueba2_B.expl_temp_c.ProbRelTolFactor =
        runTimeOptions_ProbRelTolFactor;
      mpcprueba2_B.expl_temp_c.ConstrRelTolFactor =
        runTimeOptions_ConstrRelTolFact;
      mpcprueba2_B.expl_temp_c.MaxIterations = runTimeOptions_MaxIterations;
      mpcprueba2_B.expl_temp_c.RemainFeasible = runTimeOptions_RemainFeasible;
      mpcprueba2_iterate(b_H, f, solution, memspace, &mpcprueba2_B.b_workingset,
                         qrmanager, cholmanager, objective,
                         options.IterDisplayQP, mpcprueba2_B.d,
                         options.PricingTolerance, options.ConstraintTolerance,
                         1.4901161193847657E-10, mpcprueba2_B.expl_temp_c);
      if (mpcprueba2_B.b_workingset.isActiveConstr
          [(mpcprueba2_B.b_workingset.isActiveIdx[3] +
            mpcprueba2_B.b_workingset.sizes[3]) - 2]) {
        mpcprueba2_B.mConstr = mpcprueba2_B.b_workingset.sizes[0] +
          mpcprueba2_B.b_workingset.sizes[1];
        exitg1 = false;
        while ((!exitg1) && (mpcprueba2_B.mConstr + 1 <=
                             mpcprueba2_B.b_workingset.nActiveConstr)) {
          if ((mpcprueba2_B.b_workingset.Wid[mpcprueba2_B.mConstr] == 4) &&
              (mpcprueba2_B.b_workingset.Wlocalidx[mpcprueba2_B.mConstr] ==
               mpcprueba2_B.b_workingset.sizes[3])) {
            mpcprueba2_removeConstr(&mpcprueba2_B.b_workingset,
              mpcprueba2_B.mConstr + 1);
            exitg1 = true;
          } else {
            mpcprueba2_B.mConstr++;
          }
        }
      }

      mpcprueba2_B.mConstr = mpcprueba2_B.b_workingset.nActiveConstr;
      mpcprueba2_B.idxStartIneq = mpcprueba2_B.b_workingset.sizes[0] +
        mpcprueba2_B.b_workingset.sizes[1];
      while ((mpcprueba2_B.mConstr > mpcprueba2_B.idxStartIneq) &&
             (mpcprueba2_B.mConstr > workingset->nVar)) {
        mpcprueba2_removeConstr(&mpcprueba2_B.b_workingset, mpcprueba2_B.mConstr);
        mpcprueba2_B.mConstr--;
      }

      solution->maxConstr = solution->xstar[workingset->nVar];
      mpcprueba2_setProblemType(&mpcprueba2_B.b_workingset, workingset->probType);
      objective->objtype = objective->prev_objtype;
      objective->nvar = objective->prev_nvar;
      objective->hasLinear = objective->prev_hasLinear;
      *workingset = mpcprueba2_B.b_workingset;
      if (solution->state == 0) {
      } else {
        solution->maxConstr = mpcpr_maxConstraintViolation_n3
          (&mpcprueba2_B.b_workingset, solution->xstar);
        *workingset = mpcprueba2_B.b_workingset;
        if (solution->maxConstr > mpcprueba2_B.d) {
          mpcprueba2_B.mConstr = mpcprueba2_B.b_workingset.mConstrMax;
          if (mpcprueba2_B.mConstr - 1 >= 0) {
            memset(&solution->lambda[0], 0, static_cast<uint32_T>
                   (mpcprueba2_B.mConstr) * sizeof(real_T));
          }

          solution->fstar = mpcprueba2_computeFval(objective,
            memspace->workspace_float, b_H, f, solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            if (mpcprueba2_B.i_e - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     static_cast<uint32_T>(mpcprueba2_B.i_e) * sizeof(real_T));
            }

            mpcprueba2_PresolveWorkingSet_e(solution, memspace,
              &mpcprueba2_B.b_workingset, qrmanager, &options);
            *workingset = mpcprueba2_B.b_workingset;
            mpcprueba2_B.maxConstr_new = mpcpr_maxConstraintViolation_n3
              (workingset, solution->xstar);
            if (mpcprueba2_B.maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = mpcprueba2_B.maxConstr_new;
              if (mpcprueba2_B.i_e - 1 >= 0) {
                memcpy(&solution->xstar[0], &solution->searchDir[0],
                       static_cast<uint32_T>(mpcprueba2_B.i_e) * sizeof(real_T));
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
    mpcprueba2_B.expl_temp_p.ProbRelTolFactor = runTimeOptions_ProbRelTolFactor;
    mpcprueba2_B.expl_temp_p.ConstrRelTolFactor =
      runTimeOptions_ConstrRelTolFact;
    mpcprueba2_B.expl_temp_p.MaxIterations = runTimeOptions_MaxIterations;
    mpcprueba2_B.expl_temp_p.RemainFeasible = runTimeOptions_RemainFeasible;
    mpcprueba2_iterate(b_H, f, solution, memspace, workingset, qrmanager,
                       cholmanager, objective, options.IterDisplayQP,
                       options.ObjectiveLimit, options.PricingTolerance,
                       options.ConstraintTolerance, options.StepTolerance,
                       mpcprueba2_B.expl_temp_p);
    if (tmp && (solution->state != -6)) {
      solution->maxConstr = mpcpr_maxConstraintViolation_n3(workingset,
        solution->xstar);
      mpcprueba2_computeFirstOrderOpt(solution, objective, workingset->nVar,
        workingset->ldA, workingset->ATwset, workingset->nActiveConstr,
        memspace->workspace_float);
      mpcprueba2_B.maxConstr_new = options.OptimalityTolerance *
        runTimeOptions_ProbRelTolFactor;
      if ((solution->iterations < runTimeOptions_MaxIterations) &&
          ((solution->state == -7) || ((solution->state == 1) &&
            ((solution->maxConstr > mpcprueba2_B.d) || (solution->firstorderopt >
              mpcprueba2_B.maxConstr_new))))) {
        mpcprueba2_B.expl_temp_f.ProbRelTolFactor =
          runTimeOptions_ProbRelTolFactor;
        mpcprueba2_B.expl_temp_f.ConstrRelTolFactor =
          runTimeOptions_ConstrRelTolFact;
        mpcprueba2_B.expl_temp_f.MaxIterations = runTimeOptions_MaxIterations;
        mpcprueba2_B.expl_temp_f.RemainFeasible = false;
        mpcprueba2_B.expl_temp_g.ProbRelTolFactor =
          runTimeOptions_ProbRelTolFactor;
        mpcprueba2_B.expl_temp_g.ConstrRelTolFactor =
          runTimeOptions_ConstrRelTolFact;
        mpcprueba2_B.expl_temp_g.MaxIterations = runTimeOptions_MaxIterations;
        mpcprueba2_B.expl_temp_g.RemainFeasible = false;
      }

      while ((solution->iterations < runTimeOptions_MaxIterations) &&
             ((solution->state == -7) || ((solution->state == 1) &&
               ((solution->maxConstr > mpcprueba2_B.d) ||
                (solution->firstorderopt > mpcprueba2_B.maxConstr_new))))) {
        mpcprue_feasibleX0ForWorkingSet(memspace->workspace_float,
          solution->xstar, workingset, qrmanager);
        mpcprueba2_PresolveWorkingSet_e(solution, memspace, workingset,
          qrmanager, &options);
        mpcprueba2_B.i_e = workingset->probType;
        mpcprueba2_B.mConstr = workingset->nVar;
        mpcprueba2_B.idxStartIneq = workingset->nVar;
        solution->xstar[workingset->nVar] = solution->maxConstr + 1.0;
        if (workingset->probType == 3) {
          mpcprueba2_B.idxEndIneq = 1;
        } else {
          mpcprueba2_B.idxEndIneq = 4;
        }

        mpcprueba2_setProblemType(workingset, mpcprueba2_B.idxEndIneq);
        mpcprueba2_B.b_idxStartIneq = (workingset->nWConstr[0] +
          workingset->nWConstr[1]) + 1;
        mpcprueba2_B.b_idxEndIneq = workingset->nActiveConstr;
        for (mpcprueba2_B.idxEndIneq = mpcprueba2_B.b_idxStartIneq;
             mpcprueba2_B.idxEndIneq <= mpcprueba2_B.b_idxEndIneq;
             mpcprueba2_B.idxEndIneq++) {
          workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
            Wid[mpcprueba2_B.idxEndIneq - 1] - 1] + workingset->
            Wlocalidx[mpcprueba2_B.idxEndIneq - 1]) - 2] = false;
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
        objective->nvar = mpcprueba2_B.idxStartIneq + 1;
        objective->gammaScalar = 1.0;
        objective->hasLinear = true;
        solution->fstar = solution->xstar[mpcprueba2_B.idxStartIneq];
        solution->state = 5;
        mpcprueba2_iterate(b_H, f, solution, memspace, workingset, qrmanager,
                           cholmanager, objective, options.IterDisplayQP,
                           mpcprueba2_B.d, options.PricingTolerance,
                           options.ConstraintTolerance, 1.4901161193847657E-10,
                           mpcprueba2_B.expl_temp_f);
        if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
             workingset->sizes[3]) - 2]) {
          mpcprueba2_B.idxEndIneq = workingset->sizes[0] + workingset->sizes[1];
          exitg1 = false;
          while ((!exitg1) && (mpcprueba2_B.idxEndIneq + 1 <=
                               workingset->nActiveConstr)) {
            if ((workingset->Wid[mpcprueba2_B.idxEndIneq] == 4) &&
                (workingset->Wlocalidx[mpcprueba2_B.idxEndIneq] ==
                 workingset->sizes[3])) {
              mpcprueba2_removeConstr(workingset, mpcprueba2_B.idxEndIneq + 1);
              exitg1 = true;
            } else {
              mpcprueba2_B.idxEndIneq++;
            }
          }
        }

        mpcprueba2_B.idxEndIneq = workingset->nActiveConstr;
        mpcprueba2_B.b_idxStartIneq = workingset->sizes[0] + workingset->sizes[1];
        while ((mpcprueba2_B.idxEndIneq > mpcprueba2_B.b_idxStartIneq) &&
               (mpcprueba2_B.idxEndIneq > mpcprueba2_B.mConstr)) {
          mpcprueba2_removeConstr(workingset, mpcprueba2_B.idxEndIneq);
          mpcprueba2_B.idxEndIneq--;
        }

        solution->maxConstr = solution->xstar[mpcprueba2_B.idxStartIneq];
        mpcprueba2_setProblemType(workingset, mpcprueba2_B.i_e);
        objective->objtype = objective->prev_objtype;
        objective->nvar = objective->prev_nvar;
        objective->hasLinear = objective->prev_hasLinear;
        mpcprueba2_iterate(b_H, f, solution, memspace, workingset, qrmanager,
                           cholmanager, objective, options.IterDisplayQP,
                           options.ObjectiveLimit, options.PricingTolerance,
                           options.ConstraintTolerance, options.StepTolerance,
                           mpcprueba2_B.expl_temp_g);
        solution->maxConstr = mpcpr_maxConstraintViolation_n3(workingset,
          solution->xstar);
        mpcprueba2_computeFirstOrderOpt(solution, objective, workingset->nVar,
          workingset->ldA, workingset->ATwset, workingset->nActiveConstr,
          memspace->workspace_float);
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
static real_T mpcprueba2_xnrm2(int32_T n, const real_T x[12], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      int32_T kend;
      mpcprueba2_B.scale_j = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (int32_T k = ix0; k < kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > mpcprueba2_B.scale_j) {
          real_T t;
          t = mpcprueba2_B.scale_j / absxk;
          y = y * t * t + 1.0;
          mpcprueba2_B.scale_j = absxk;
        } else {
          real_T t;
          t = absxk / mpcprueba2_B.scale_j;
          y += t * t;
        }
      }

      y = mpcprueba2_B.scale_j * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
static void mpcprueba2_mldivide(const real_T A[12], const real_T B[3], real_T Y
  [4])
{
  int32_T b_ix;
  int32_T e;
  int32_T e_k;
  int32_T exitg1;
  int32_T ia;
  int32_T ii;
  int32_T iy;
  int32_T pvt;
  int32_T rankA;
  int8_T jpvt[4];
  int8_T jpvt_0;
  boolean_T exitg2;
  mpcprueba2_B.b_B[0] = B[0];
  mpcprueba2_B.b_B[1] = B[1];
  mpcprueba2_B.b_B[2] = B[2];
  jpvt[0] = 1;
  jpvt[1] = 2;
  jpvt[2] = 3;
  jpvt[3] = 4;
  memcpy(&mpcprueba2_B.b_A[0], &A[0], 12U * sizeof(real_T));
  mpcprueba2_B.tau[0] = 0.0;
  mpcprueba2_B.tau[1] = 0.0;
  mpcprueba2_B.tau[2] = 0.0;
  mpcprueba2_B.work_k[0] = 0.0;
  mpcprueba2_B.smax = mpcprueba2_xnrm2(3, A, 1);
  mpcprueba2_B.vn1_c[0] = mpcprueba2_B.smax;
  mpcprueba2_B.vn2_b[0] = mpcprueba2_B.smax;
  mpcprueba2_B.work_k[1] = 0.0;
  mpcprueba2_B.smax = mpcprueba2_xnrm2(3, A, 4);
  mpcprueba2_B.vn1_c[1] = mpcprueba2_B.smax;
  mpcprueba2_B.vn2_b[1] = mpcprueba2_B.smax;
  mpcprueba2_B.work_k[2] = 0.0;
  mpcprueba2_B.smax = mpcprueba2_xnrm2(3, A, 7);
  mpcprueba2_B.vn1_c[2] = mpcprueba2_B.smax;
  mpcprueba2_B.vn2_b[2] = mpcprueba2_B.smax;
  mpcprueba2_B.work_k[3] = 0.0;
  mpcprueba2_B.smax = mpcprueba2_xnrm2(3, A, 10);
  mpcprueba2_B.vn1_c[3] = mpcprueba2_B.smax;
  mpcprueba2_B.vn2_b[3] = mpcprueba2_B.smax;
  for (rankA = 0; rankA < 3; rankA++) {
    ii = rankA * 3 + rankA;
    pvt = 5 - rankA;
    b_ix = 0;
    mpcprueba2_B.smax = fabs(mpcprueba2_B.vn1_c[rankA]);
    for (iy = 2; iy < pvt; iy++) {
      mpcprueba2_B.s_l = fabs(mpcprueba2_B.vn1_c[(rankA + iy) - 1]);
      if (mpcprueba2_B.s_l > mpcprueba2_B.smax) {
        b_ix = iy - 1;
        mpcprueba2_B.smax = mpcprueba2_B.s_l;
      }
    }

    pvt = rankA + b_ix;
    if (pvt != rankA) {
      b_ix = pvt * 3;
      iy = rankA * 3;
      mpcprueba2_B.smax = mpcprueba2_B.b_A[b_ix];
      mpcprueba2_B.b_A[b_ix] = mpcprueba2_B.b_A[iy];
      mpcprueba2_B.b_A[iy] = mpcprueba2_B.smax;
      mpcprueba2_B.smax = mpcprueba2_B.b_A[b_ix + 1];
      mpcprueba2_B.b_A[b_ix + 1] = mpcprueba2_B.b_A[iy + 1];
      mpcprueba2_B.b_A[iy + 1] = mpcprueba2_B.smax;
      mpcprueba2_B.smax = mpcprueba2_B.b_A[b_ix + 2];
      mpcprueba2_B.b_A[b_ix + 2] = mpcprueba2_B.b_A[iy + 2];
      mpcprueba2_B.b_A[iy + 2] = mpcprueba2_B.smax;
      b_ix = jpvt[pvt];
      jpvt[pvt] = jpvt[rankA];
      jpvt[rankA] = static_cast<int8_T>(b_ix);
      mpcprueba2_B.vn1_c[pvt] = mpcprueba2_B.vn1_c[rankA];
      mpcprueba2_B.vn2_b[pvt] = mpcprueba2_B.vn2_b[rankA];
    }

    if (rankA + 1 < 3) {
      mpcprueba2_B.s_l = mpcprueba2_B.b_A[ii];
      pvt = ii + 2;
      mpcprueba2_B.tau[rankA] = 0.0;
      mpcprueba2_B.smax = mpcprueba2_xnrm2(2 - rankA, mpcprueba2_B.b_A, ii + 2);
      if (mpcprueba2_B.smax != 0.0) {
        mpcprueba2_B.temp2_p = mpcprueba2_B.b_A[ii];
        mpcprueba2_B.smax = mpcprueba2_rt_hypotd_snf(mpcprueba2_B.temp2_p,
          mpcprueba2_B.smax);
        if (mpcprueba2_B.temp2_p >= 0.0) {
          mpcprueba2_B.smax = -mpcprueba2_B.smax;
        }

        if (fabs(mpcprueba2_B.smax) < 1.0020841800044864E-292) {
          b_ix = 0;
          iy = (ii - rankA) + 3;
          do {
            b_ix++;
            for (e_k = pvt; e_k <= iy; e_k++) {
              mpcprueba2_B.b_A[e_k - 1] *= 9.9792015476736E+291;
            }

            mpcprueba2_B.smax *= 9.9792015476736E+291;
            mpcprueba2_B.s_l *= 9.9792015476736E+291;
          } while ((fabs(mpcprueba2_B.smax) < 1.0020841800044864E-292) && (b_ix <
                    20));

          mpcprueba2_B.smax = mpcprueba2_rt_hypotd_snf(mpcprueba2_B.s_l,
            mpcprueba2_xnrm2(2 - rankA, mpcprueba2_B.b_A, ii + 2));
          if (mpcprueba2_B.s_l >= 0.0) {
            mpcprueba2_B.smax = -mpcprueba2_B.smax;
          }

          mpcprueba2_B.tau[rankA] = (mpcprueba2_B.smax - mpcprueba2_B.s_l) /
            mpcprueba2_B.smax;
          mpcprueba2_B.s_l = 1.0 / (mpcprueba2_B.s_l - mpcprueba2_B.smax);
          for (e_k = pvt; e_k <= iy; e_k++) {
            mpcprueba2_B.b_A[e_k - 1] *= mpcprueba2_B.s_l;
          }

          for (pvt = 0; pvt < b_ix; pvt++) {
            mpcprueba2_B.smax *= 1.0020841800044864E-292;
          }

          mpcprueba2_B.s_l = mpcprueba2_B.smax;
        } else {
          mpcprueba2_B.tau[rankA] = (mpcprueba2_B.smax - mpcprueba2_B.temp2_p) /
            mpcprueba2_B.smax;
          mpcprueba2_B.s_l = 1.0 / (mpcprueba2_B.temp2_p - mpcprueba2_B.smax);
          b_ix = (ii - rankA) + 3;
          for (iy = pvt; iy <= b_ix; iy++) {
            mpcprueba2_B.b_A[iy - 1] *= mpcprueba2_B.s_l;
          }

          mpcprueba2_B.s_l = mpcprueba2_B.smax;
        }
      }

      mpcprueba2_B.b_A[ii] = mpcprueba2_B.s_l;
    } else {
      mpcprueba2_B.tau[2] = 0.0;
    }

    mpcprueba2_B.smax = mpcprueba2_B.b_A[ii];
    mpcprueba2_B.b_A[ii] = 1.0;
    if (mpcprueba2_B.tau[rankA] != 0.0) {
      pvt = 3 - rankA;
      b_ix = (ii - rankA) + 2;
      while ((pvt > 0) && (mpcprueba2_B.b_A[b_ix] == 0.0)) {
        pvt--;
        b_ix--;
      }

      b_ix = 3 - rankA;
      exitg2 = false;
      while ((!exitg2) && (b_ix > 0)) {
        iy = ((b_ix - 1) * 3 + ii) + 3;
        e_k = iy;
        do {
          exitg1 = 0;
          if (e_k + 1 <= iy + pvt) {
            if (mpcprueba2_B.b_A[e_k] != 0.0) {
              exitg1 = 1;
            } else {
              e_k++;
            }
          } else {
            b_ix--;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      b_ix--;
    } else {
      pvt = 0;
      b_ix = -1;
    }

    if (pvt > 0) {
      if (b_ix + 1 != 0) {
        memset(&mpcprueba2_B.work_k[0], 0, static_cast<uint32_T>(b_ix + 1) *
               sizeof(real_T));
        iy = (3 * b_ix + ii) + 4;
        for (e_k = ii + 4; e_k <= iy; e_k += 3) {
          mpcprueba2_B.s_l = 0.0;
          e = e_k + pvt;
          for (ia = e_k; ia < e; ia++) {
            mpcprueba2_B.s_l += mpcprueba2_B.b_A[(ii + ia) - e_k] *
              mpcprueba2_B.b_A[ia - 1];
          }

          e = div_nde_s32_floor((e_k - ii) - 4, 3);
          mpcprueba2_B.work_k[e] += mpcprueba2_B.s_l;
        }
      }

      if (!(-mpcprueba2_B.tau[rankA] == 0.0)) {
        iy = ii + 4;
        for (e_k = 0; e_k <= b_ix; e_k++) {
          mpcprueba2_B.s_l = mpcprueba2_B.work_k[e_k];
          if (mpcprueba2_B.s_l != 0.0) {
            mpcprueba2_B.s_l *= -mpcprueba2_B.tau[rankA];
            e = pvt + iy;
            for (ia = iy; ia < e; ia++) {
              mpcprueba2_B.b_A[ia - 1] += mpcprueba2_B.b_A[(ii + ia) - iy] *
                mpcprueba2_B.s_l;
            }
          }

          iy += 3;
        }
      }
    }

    mpcprueba2_B.b_A[ii] = mpcprueba2_B.smax;
    for (ii = rankA + 2; ii < 5; ii++) {
      pvt = (ii - 1) * 3 + rankA;
      mpcprueba2_B.smax = mpcprueba2_B.vn1_c[ii - 1];
      if (mpcprueba2_B.smax != 0.0) {
        mpcprueba2_B.s_l = fabs(mpcprueba2_B.b_A[pvt]) / mpcprueba2_B.smax;
        mpcprueba2_B.s_l = 1.0 - mpcprueba2_B.s_l * mpcprueba2_B.s_l;
        if (mpcprueba2_B.s_l < 0.0) {
          mpcprueba2_B.s_l = 0.0;
        }

        mpcprueba2_B.temp2_p = mpcprueba2_B.smax / mpcprueba2_B.vn2_b[ii - 1];
        mpcprueba2_B.temp2_p = mpcprueba2_B.temp2_p * mpcprueba2_B.temp2_p *
          mpcprueba2_B.s_l;
        if (mpcprueba2_B.temp2_p <= 1.4901161193847656E-8) {
          if (rankA + 1 < 3) {
            mpcprueba2_B.smax = mpcprueba2_xnrm2(2 - rankA, mpcprueba2_B.b_A,
              pvt + 2);
            mpcprueba2_B.vn1_c[ii - 1] = mpcprueba2_B.smax;
            mpcprueba2_B.vn2_b[ii - 1] = mpcprueba2_B.smax;
          } else {
            mpcprueba2_B.vn1_c[ii - 1] = 0.0;
            mpcprueba2_B.vn2_b[ii - 1] = 0.0;
          }
        } else {
          mpcprueba2_B.vn1_c[ii - 1] = mpcprueba2_B.smax * sqrt(mpcprueba2_B.s_l);
        }
      }
    }
  }

  rankA = 0;
  mpcprueba2_B.smax = 8.8817841970012523E-15 * fabs(mpcprueba2_B.b_A[0]);
  while ((rankA < 3) && (!(fabs(mpcprueba2_B.b_A[3 * rankA + rankA]) <=
           mpcprueba2_B.smax))) {
    rankA++;
  }

  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  Y[3] = 0.0;
  for (ii = 0; ii < 3; ii++) {
    if (mpcprueba2_B.tau[ii] != 0.0) {
      mpcprueba2_B.smax = mpcprueba2_B.b_B[ii];
      for (pvt = ii + 2; pvt < 4; pvt++) {
        mpcprueba2_B.smax += mpcprueba2_B.b_A[(3 * ii + pvt) - 1] *
          mpcprueba2_B.b_B[pvt - 1];
      }

      mpcprueba2_B.smax *= mpcprueba2_B.tau[ii];
      if (mpcprueba2_B.smax != 0.0) {
        mpcprueba2_B.b_B[ii] -= mpcprueba2_B.smax;
        for (pvt = ii + 2; pvt < 4; pvt++) {
          mpcprueba2_B.b_B[pvt - 1] -= mpcprueba2_B.b_A[(3 * ii + pvt) - 1] *
            mpcprueba2_B.smax;
        }
      }
    }
  }

  for (ii = 0; ii < rankA; ii++) {
    Y[jpvt[ii] - 1] = mpcprueba2_B.b_B[ii];
  }

  for (ii = rankA; ii >= 1; ii--) {
    jpvt_0 = jpvt[ii - 1];
    pvt = (ii - 1) * 3;
    Y[jpvt_0 - 1] /= mpcprueba2_B.b_A[(pvt + ii) - 1];
    for (b_ix = 0; b_ix <= ii - 2; b_ix++) {
      iy = jpvt[b_ix] - 1;
      Y[iy] -= mpcprueba2_B.b_A[pvt + b_ix] * Y[jpvt_0 - 1];
    }
  }
}

// Model step function
void mpcprueba2_step(void)
{
  static const int8_T WorkingSet_tmp[5] = { 0, 0, 66, 0, 0 };

  static const int8_T e[5] = { 0, 0, 66, 1, 0 };

  static const int8_T d_varargin_2[6] = { 1, 0, 0, 66, 0, 0 };

  static const int8_T d[5] = { 0, 0, 66, 66, 0 };

  static const int8_T c[5] = { 0, 0, 66, 67, 0 };

  static const int8_T c_varargin_2[6] = { 1, 0, 0, 66, 1, 0 };

  static const int8_T b_varargin_2[6] = { 1, 0, 0, 66, 66, 0 };

  static const int8_T varargin_2[6] = { 1, 0, 0, 66, 67, 0 };

  static const real_T tmp[12] = { 1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0,
    -1.0, 1.0, -1.0, -1.0 };

  // MATLAB Function: '<Root>/MATLAB Function5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant5'

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 15; mpcprueba2_B.i++) {
    mpcprueba2_B.uvec[mpcprueba2_B.i] = (2.0 * mpcprueba2_P.Constant2_Value *
      mpcprueba2_P.F[mpcprueba2_B.i] + 2.0 * mpcprueba2_P.Constant4_Value *
      mpcprueba2_P.F[mpcprueba2_B.i + 15]) + 2.0 * mpcprueba2_P.Constant5_Value *
      mpcprueba2_P.F[mpcprueba2_B.i + 30];
    mpcprueba2_B.dv[mpcprueba2_B.i] = 0.0;
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 15; mpcprueba2_B.i++) {
    mpcprueba2_B.f_g = mpcprueba2_B.dv[mpcprueba2_B.i];
    for (mpcprueba2_B.idxFillStart = 0; mpcprueba2_B.idxFillStart < 15;
         mpcprueba2_B.idxFillStart++) {
      mpcprueba2_B.f_g += mpcprueba2_P.Qvec[15 * mpcprueba2_B.i +
        mpcprueba2_B.idxFillStart] * mpcprueba2_B.uvec[mpcprueba2_B.idxFillStart];
    }

    mpcprueba2_B.dv[mpcprueba2_B.i] = mpcprueba2_B.f_g;
    mpcprueba2_B.f[mpcprueba2_B.i] = 0.0;
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 15; mpcprueba2_B.i++) {
    mpcprueba2_B.f_g = mpcprueba2_B.f[mpcprueba2_B.i];
    for (mpcprueba2_B.idxFillStart = 0; mpcprueba2_B.idxFillStart < 15;
         mpcprueba2_B.idxFillStart++) {
      mpcprueba2_B.f_g += mpcprueba2_P.G[15 * mpcprueba2_B.i +
        mpcprueba2_B.idxFillStart] * mpcprueba2_B.dv[mpcprueba2_B.idxFillStart];
    }

    mpcprueba2_B.f[mpcprueba2_B.i] = mpcprueba2_B.f_g;
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 225; mpcprueba2_B.i++) {
    mpcprueba2_B.b_H[mpcprueba2_B.i] = 2.0 * mpcprueba2_P.H[mpcprueba2_B.i];
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 66; mpcprueba2_B.i++) {
    mpcprueba2_B.b_x[mpcprueba2_B.i] = ((mpcprueba2_P.Sc[mpcprueba2_B.i + 66] *
      mpcprueba2_P.Constant4_Value + mpcprueba2_P.Sc[mpcprueba2_B.i] *
      mpcprueba2_P.Constant2_Value) + mpcprueba2_P.Sc[mpcprueba2_B.i + 132] *
      mpcprueba2_P.Constant5_Value) + mpcprueba2_P.qc[mpcprueba2_B.i];
  }

  mpcprueba2_B.solution.fstar = 0.0;
  mpcprueba2_B.solution.firstorderopt = 0.0;
  memset(&mpcprueba2_B.solution.lambda[0], 0, 67U * sizeof(real_T));
  mpcprueba2_B.solution.state = 0;
  mpcprueba2_B.solution.maxConstr = 0.0;
  mpcprueba2_B.solution.iterations = 0;
  memset(&mpcprueba2_B.solution.searchDir[0], 0, sizeof(real_T) << 4U);
  memcpy(&mpcprueba2_B.solution.xstar[0], &mpcprueba2_DW.x0[0], 15U * sizeof
         (real_T));
  mpcprueba2_B.CholRegManager.ldm = 16;
  mpcprueba2_B.CholRegManager.ndims = 0;
  mpcprueba2_B.CholRegManager.info = 0;
  mpcprueba2_B.CholRegManager.ConvexCheck = true;
  mpcprueba2_B.CholRegManager.regTol_ = 0.0;
  mpcprueba2_B.WorkingSet.nVarOrig = 15;
  mpcprueba2_B.WorkingSet.nVarMax = 16;
  mpcprueba2_B.WorkingSet.ldA = 16;
  memset(&mpcprueba2_B.WorkingSet.Aineq[0], 0, 1056U * sizeof(real_T));
  memset(&mpcprueba2_B.WorkingSet.bineq[0], 0, 66U * sizeof(real_T));
  memset(&mpcprueba2_B.WorkingSet.lb[0], 0, sizeof(real_T) << 4U);
  memset(&mpcprueba2_B.WorkingSet.ub[0], 0, sizeof(real_T) << 4U);
  mpcprueba2_B.WorkingSet.mEqRemoved = 0;
  memset(&mpcprueba2_B.WorkingSet.ATwset[0], 0, 1072U * sizeof(real_T));
  memset(&mpcprueba2_B.WorkingSet.bwset[0], 0, 67U * sizeof(real_T));
  memset(&mpcprueba2_B.WorkingSet.maxConstrWorkspace[0], 0, 67U * sizeof(real_T));
  memset(&mpcprueba2_B.WorkingSet.isActiveConstr[0], 0, 67U * sizeof(boolean_T));
  memset(&mpcprueba2_B.WorkingSet.Wid[0], 0, 67U * sizeof(int32_T));
  memset(&mpcprueba2_B.WorkingSet.Wlocalidx[0], 0, 67U * sizeof(int32_T));
  memset(&mpcprueba2_B.WorkingSet.indexLB[0], 0, sizeof(int32_T) << 4U);
  memset(&mpcprueba2_B.WorkingSet.indexUB[0], 0, sizeof(int32_T) << 4U);
  memset(&mpcprueba2_B.WorkingSet.indexFixed[0], 0, sizeof(int32_T) << 4U);
  mpcprueba2_B.WorkingSet.mConstrMax = 67;
  mpcprueba2_B.WorkingSet.mConstrOrig = 66;
  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 5; mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.sizesNormal[mpcprueba2_B.i] =
      WorkingSet_tmp[mpcprueba2_B.i];
    mpcprueba2_B.WorkingSet.sizesPhaseOne[mpcprueba2_B.i] = e[mpcprueba2_B.i];
    mpcprueba2_B.WorkingSet.sizesRegularized[mpcprueba2_B.i] = d[mpcprueba2_B.i];
    mpcprueba2_B.WorkingSet.sizesRegPhaseOne[mpcprueba2_B.i] = c[mpcprueba2_B.i];
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 6; mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i] =
      d_varargin_2[mpcprueba2_B.i];
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 5; mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i + 1] +=
      mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i];
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 6; mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.isActiveIdxNormal[mpcprueba2_B.i] =
      mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i];
    mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i] =
      c_varargin_2[mpcprueba2_B.i];
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 5; mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i + 1] +=
      mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i];
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 6; mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.isActiveIdxPhaseOne[mpcprueba2_B.i] =
      mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i];
    mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i] =
      b_varargin_2[mpcprueba2_B.i];
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 5; mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i + 1] +=
      mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i];
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 6; mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.isActiveIdxRegularized[mpcprueba2_B.i] =
      mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i];
    mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i] =
      varargin_2[mpcprueba2_B.i];
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 5; mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i + 1] +=
      mpcprueba2_B.WorkingSet.isActiveIdxRegPhaseOne[mpcprueba2_B.i];
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 15; mpcprueba2_B.i++) {
    for (mpcprueba2_B.idxFillStart = 0; mpcprueba2_B.idxFillStart < 66;
         mpcprueba2_B.idxFillStart++) {
      mpcprueba2_B.WorkingSet.Aineq[mpcprueba2_B.i + (mpcprueba2_B.idxFillStart <<
        4)] = mpcprueba2_P.Pc[66 * mpcprueba2_B.i + mpcprueba2_B.idxFillStart];
    }
  }

  memcpy(&mpcprueba2_B.WorkingSet.bineq[0], &mpcprueba2_B.b_x[0], 66U * sizeof
         (real_T));
  mpcprueba2_B.WorkingSet.nVar = 15;
  mpcprueba2_B.WorkingSet.mConstr = 66;
  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 5; mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.sizes[mpcprueba2_B.i] =
      mpcprueba2_B.WorkingSet.sizesNormal[mpcprueba2_B.i];
  }

  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 6; mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.isActiveIdx[mpcprueba2_B.i] =
      mpcprueba2_B.WorkingSet.isActiveIdxNormal[mpcprueba2_B.i];
  }

  mpcprueba2_B.WorkingSet.probType = 3;
  mpcprueba2_B.idxFillStart = mpcprueba2_B.WorkingSet.isActiveIdx[2];
  for (mpcprueba2_B.i = mpcprueba2_B.idxFillStart; mpcprueba2_B.i < 68;
       mpcprueba2_B.i++) {
    mpcprueba2_B.WorkingSet.isActiveConstr[mpcprueba2_B.i - 1] = false;
  }

  mpcprueba2_B.WorkingSet.nWConstr[0] = 0;
  mpcprueba2_B.WorkingSet.nWConstr[1] = 0;
  mpcprueba2_B.WorkingSet.nWConstr[2] = 0;
  mpcprueba2_B.WorkingSet.nWConstr[3] = 0;
  mpcprueba2_B.WorkingSet.nWConstr[4] = 0;
  mpcprueba2_B.WorkingSet.nActiveConstr = 0;
  mpcprueba2_B.WorkingSet.SLACK0 = 0.0;
  mpcprueba2_B.f_g = 1.0;
  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 66; mpcprueba2_B.i++) {
    mpcprueba2_B.colSum = 0.0;
    mpcprueba2_B.colPos = mpcprueba2_B.i << 4;
    for (mpcprueba2_B.idxFillStart = 0; mpcprueba2_B.idxFillStart < 15;
         mpcprueba2_B.idxFillStart++) {
      mpcprueba2_B.colSum += fabs
        (mpcprueba2_B.WorkingSet.Aineq[mpcprueba2_B.idxFillStart +
         mpcprueba2_B.colPos]);
    }

    if ((!(mpcprueba2_B.f_g >= mpcprueba2_B.colSum)) && (!rtIsNaN
         (mpcprueba2_B.colSum))) {
      mpcprueba2_B.f_g = mpcprueba2_B.colSum;
    }
  }

  mpcprueba2_B.colSum = 0.0;
  mpcprueba2_B.f_infnrm = 0.0;
  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 15; mpcprueba2_B.i++) {
    mpcprueba2_B.b_colSum = 0.0;
    for (mpcprueba2_B.idxFillStart = 0; mpcprueba2_B.idxFillStart < 15;
         mpcprueba2_B.idxFillStart++) {
      mpcprueba2_B.b_colSum += fabs(mpcprueba2_B.b_H[15 * mpcprueba2_B.i +
        mpcprueba2_B.idxFillStart]);
    }

    if ((!(mpcprueba2_B.colSum >= mpcprueba2_B.b_colSum)) && (!rtIsNaN
         (mpcprueba2_B.b_colSum))) {
      mpcprueba2_B.colSum = mpcprueba2_B.b_colSum;
    }

    mpcprueba2_B.b_colSum = fabs(mpcprueba2_B.f[mpcprueba2_B.i]);
    if ((!(mpcprueba2_B.f_infnrm >= mpcprueba2_B.b_colSum)) && (!rtIsNaN
         (mpcprueba2_B.b_colSum))) {
      mpcprueba2_B.f_infnrm = mpcprueba2_B.b_colSum;
    }
  }

  if (mpcprueba2_B.f_g >= mpcprueba2_B.f_infnrm) {
    mpcprueba2_B.f_infnrm = mpcprueba2_B.f_g;
  }

  if (mpcprueba2_B.f_infnrm >= mpcprueba2_B.colSum) {
    mpcprueba2_B.colSum = mpcprueba2_B.f_infnrm;
  }

  mpcprueba2_B.CholRegManager.scaleFactor = mpcprueba2_B.colSum;
  if (mpcprueba2_DW.opts.StepTolerance < 0.0) {
    mpcprueba2_B.expl_temp.StepTolerance = 1.0E-8;
  } else {
    mpcprueba2_B.expl_temp.StepTolerance = mpcprueba2_DW.opts.StepTolerance;
  }

  if (mpcprueba2_DW.opts.OptimalityTolerance < 0.0) {
    mpcprueba2_B.expl_temp.OptimalityTolerance = 1.0E-8;
  } else {
    mpcprueba2_B.expl_temp.OptimalityTolerance =
      mpcprueba2_DW.opts.OptimalityTolerance;
  }

  if (mpcprueba2_DW.opts.ConstraintTolerance < 0.0) {
    mpcprueba2_B.expl_temp.ConstraintTolerance = 1.0E-8;
  } else {
    mpcprueba2_B.expl_temp.ConstraintTolerance =
      mpcprueba2_DW.opts.ConstraintTolerance;
  }

  mpcprueba2_B.expl_temp.PricingTolerance = mpcprueba2_DW.opts.PricingTolerance;
  mpcprueba2_B.expl_temp.ObjectiveLimit = mpcprueba2_DW.opts.ObjectiveLimit;
  mpcprueba2_B.expl_temp.IterDisplayQP = mpcprueba2_DW.opts.IterDisplayQP;
  mpcprueba2_B.expl_temp.NonFiniteSupport = mpcprueba2_DW.opts.NonFiniteSupport;
  for (mpcprueba2_B.i = 0; mpcprueba2_B.i < 8; mpcprueba2_B.i++) {
    mpcprueba2_B.expl_temp.SolverName[mpcprueba2_B.i] =
      mpcprueba2_DW.opts.SolverName[mpcprueba2_B.i];
  }

  if (mpcprueba2_DW.opts.MaxIterations < 0.0) {
    mpcprueba2_B.i = 810;
  } else {
    mpcprueba2_B.i = static_cast<int32_T>(mpcprueba2_DW.opts.MaxIterations);
  }

  mpcprueba2_driver(mpcprueba2_B.b_H, mpcprueba2_B.f, &mpcprueba2_B.solution,
                    &mpcprueba2_B.memspace, &mpcprueba2_B.WorkingSet,
                    &mpcprueba2_B.CholRegManager, mpcprueba2_B.expl_temp,
                    mpcprueba2_B.i, mpcprueba2_B.f_g, mpcprueba2_B.colSum,
                    &mpcprueba2_B.QRManager, &mpcprueba2_B.QPObjective);
  memcpy(&mpcprueba2_B.uvec[0], &mpcprueba2_B.solution.xstar[0], 15U * sizeof
         (real_T));
  if (mpcprueba2_B.solution.state <= 0) {
    mpcprueba2_computeFval(&mpcprueba2_B.QPObjective,
      mpcprueba2_B.memspace.workspace_float, mpcprueba2_B.b_H, mpcprueba2_B.f,
      mpcprueba2_B.solution.xstar);
  }

  switch (mpcprueba2_B.solution.state) {
   case 2:
    mpcprueba2_B.solution.state = -3;
    break;

   case -3:
    mpcprueba2_B.solution.state = -2;
    break;

   case 4:
    mpcprueba2_B.solution.state = -2;
    break;
  }

  if (mpcprueba2_B.solution.state > 0) {
    mpcprueba2_B.u[0] = mpcprueba2_B.uvec[0];
    mpcprueba2_DW.u_prev[0] = mpcprueba2_B.uvec[0];
    mpcprueba2_B.u[1] = mpcprueba2_B.uvec[1];
    mpcprueba2_DW.u_prev[1] = mpcprueba2_B.uvec[1];
    mpcprueba2_B.u[2] = mpcprueba2_B.uvec[2];
    mpcprueba2_DW.u_prev[2] = mpcprueba2_B.uvec[2];
    memcpy(&mpcprueba2_DW.x0[0], &mpcprueba2_B.uvec[0], 15U * sizeof(real_T));
  } else {
    mpcprueba2_B.u[0] = mpcprueba2_DW.u_prev[0];
    mpcprueba2_B.u[1] = mpcprueba2_DW.u_prev[1];
    mpcprueba2_B.u[2] = mpcprueba2_DW.u_prev[2];
  }

  // End of MATLAB Function: '<Root>/MATLAB Function5'
  // MATLAB Function: '<Root>/MATLAB Function'
  mpcprueba2_B.dv1[0] = mpcprueba2_B.u[0];
  mpcprueba2_B.dv1[1] = mpcprueba2_B.u[1];
  mpcprueba2_B.dv1[2] = mpcprueba2_B.u[2];
  mpcprueba2_mldivide(tmp, mpcprueba2_B.dv1, mpcprueba2_B.M);

  // Saturate: '<Root>/Saturation' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function'

  if (mpcprueba2_B.M[0] + 0.2691 > mpcprueba2_P.Saturation_UpperSat) {
    // Saturate: '<Root>/Saturation'
    mpcprueba2_B.Saturation = mpcprueba2_P.Saturation_UpperSat;
  } else if (mpcprueba2_B.M[0] + 0.2691 < mpcprueba2_P.Saturation_LowerSat) {
    // Saturate: '<Root>/Saturation'
    mpcprueba2_B.Saturation = mpcprueba2_P.Saturation_LowerSat;
  } else {
    // Saturate: '<Root>/Saturation'
    mpcprueba2_B.Saturation = mpcprueba2_B.M[0] + 0.2691;
  }

  // End of Saturate: '<Root>/Saturation'
  // Saturate: '<Root>/Saturation1' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function'

  if (mpcprueba2_B.M[1] + 0.3501 > mpcprueba2_P.Saturation1_UpperSat) {
    // Saturate: '<Root>/Saturation1'
    mpcprueba2_B.Saturation1 = mpcprueba2_P.Saturation1_UpperSat;
  } else if (mpcprueba2_B.M[1] + 0.3501 < mpcprueba2_P.Saturation1_LowerSat) {
    // Saturate: '<Root>/Saturation1'
    mpcprueba2_B.Saturation1 = mpcprueba2_P.Saturation1_LowerSat;
  } else {
    // Saturate: '<Root>/Saturation1'
    mpcprueba2_B.Saturation1 = mpcprueba2_B.M[1] + 0.3501;
  }

  // End of Saturate: '<Root>/Saturation1'
  // Saturate: '<Root>/Saturation3' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function'

  if (mpcprueba2_B.M[3] + 0.3462 > mpcprueba2_P.Saturation3_UpperSat) {
    // Saturate: '<Root>/Saturation3'
    mpcprueba2_B.Saturation3 = mpcprueba2_P.Saturation3_UpperSat;
  } else if (mpcprueba2_B.M[3] + 0.3462 < mpcprueba2_P.Saturation3_LowerSat) {
    // Saturate: '<Root>/Saturation3'
    mpcprueba2_B.Saturation3 = mpcprueba2_P.Saturation3_LowerSat;
  } else {
    // Saturate: '<Root>/Saturation3'
    mpcprueba2_B.Saturation3 = mpcprueba2_B.M[3] + 0.3462;
  }

  // End of Saturate: '<Root>/Saturation3'
  // Saturate: '<Root>/Saturation2' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function'

  if (mpcprueba2_B.M[2] + 0.2498 > mpcprueba2_P.Saturation2_UpperSat) {
    // Saturate: '<Root>/Saturation2'
    mpcprueba2_B.Saturation2 = mpcprueba2_P.Saturation2_UpperSat;
  } else if (mpcprueba2_B.M[2] + 0.2498 < mpcprueba2_P.Saturation2_LowerSat) {
    // Saturate: '<Root>/Saturation2'
    mpcprueba2_B.Saturation2 = mpcprueba2_P.Saturation2_LowerSat;
  } else {
    // Saturate: '<Root>/Saturation2'
    mpcprueba2_B.Saturation2 = mpcprueba2_B.M[2] + 0.2498;
  }

  // End of Saturate: '<Root>/Saturation2'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  mpcprueba2_M->Timing.taskTime0 =
    ((time_T)(++mpcprueba2_M->Timing.clockTick0)) *
    mpcprueba2_M->Timing.stepSize0;
}

// Model initialize function
void mpcprueba2_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(mpcprueba2_M, -1);
  mpcprueba2_M->Timing.stepSize0 = 0.0201;

  // External mode info
  mpcprueba2_M->Sizes.checksums[0] = (252222445U);
  mpcprueba2_M->Sizes.checksums[1] = (2844505063U);
  mpcprueba2_M->Sizes.checksums[2] = (323806627U);
  mpcprueba2_M->Sizes.checksums[3] = (1810865430U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    mpcprueba2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(mpcprueba2_M->extModeInfo,
      &mpcprueba2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(mpcprueba2_M->extModeInfo, mpcprueba2_M->Sizes.checksums);
    rteiSetTPtr(mpcprueba2_M->extModeInfo, rtmGetTPtr(mpcprueba2_M));
  }

  // block I/O
  (void) memset((static_cast<void *>(&mpcprueba2_B)), 0,
                sizeof(B_mpcprueba2_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&mpcprueba2_DW), 0,
                sizeof(DW_mpcprueba2_T));

  {
    static sCBS0Ia3qD76sOwKERvBoFE_mpcpr_T tmp = { true,// NonFiniteSupport
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

    // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function5'
    mpcprueba2_DW.opts = tmp;
    mpcprueba2_DW.u_prev[0] = 0.0;
    mpcprueba2_DW.u_prev[1] = 0.0;
    mpcprueba2_DW.u_prev[2] = 0.0;
    memset(&mpcprueba2_DW.x0[0], 0, 15U * sizeof(real_T));
  }
}

// Model terminate function
void mpcprueba2_terminate(void)
{
  // (no terminate code required)
}

//
// File trailer for generated code.
//
// [EOF]
//
