//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
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
#include <stdio.h>
#include <stdlib.h>
#include "pruebafmu.h"
#include "pruebafmu_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "ext_mode.h"
#include "MW_PX4_TaskControl.h"
#include "nuttxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

// Function prototype declaration
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
extmodeErrorCode_T errorCode;
px4_sem_t stopSem;
px4_sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
pthread_t backgroundThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(pruebafmu_M) == (NULL)) && !rtmGetStopRequested
    (pruebafmu_M);
  while (runModel) {
    px4_sem_wait(&baserateTaskSem);
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      pruebafmu_M->Timing.taskTime0;
    pruebafmu_step();

    // Get model outputs here

    // Trigger External Mode event
    extmodeEvent(0, currentTime);
    stopRequested = !((rtmGetErrorStatus(pruebafmu_M) == (NULL)) &&
                      !rtmGetStopRequested(pruebafmu_M));
    runModel = !stopRequested && !extmodeSimulationComplete() &&
      !extmodeStopRequested();
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(pruebafmu_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;

    // Wait for background task to complete
    CHECK_STATUS(pthread_join(backgroundThread, &threadJoinStatus), 0,
                 "pthread_join");
  }

  MW_PX4_Terminate();

  // Terminate model
  pruebafmu_terminate();
  extmodeReset();
  px4_sem_post(&stopSem);
  return NULL;
}

void *backgroundTask(void *arg)
{
  while (runModel) {
    // Run External Mode background activities
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS && errorCode != EXTMODE_EMPTY) {
      // Code to handle External Mode background task errors
      // may be added here
    }
  }

  pthread_exit((void *)0);
  return NULL;
}

int px4_simulink_app_task_main (int argc, char *argv[])
{
  px4_simulink_app_control_MAVLink();
  rtmSetErrorStatus(pruebafmu_M, 0);

  // Parse External Mode command line arguments
  errorCode = extmodeParseArgs(argc, (const char_T **)argv);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  // Initialize model
  pruebafmu_initialize();

  // External Mode initialization
  errorCode = extmodeInit(pruebafmu_M->extModeInfo, &rtmGetTFinal(pruebafmu_M));
  if (errorCode != EXTMODE_SUCCESS) {
    // Code to handle External Mode initialization errors
    // may be added here
  }

  if (errorCode == EXTMODE_SUCCESS) {
    // Wait until a Start or Stop Request has been received from the Host
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(pruebafmu_M, true);
    }
  }

  // Call RTOS Initialization function
  nuttxRTOSInit(0.001, 0);

  // Wait for stop semaphore
  px4_sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(px4_sem_destroy(&timerTaskSem[i]), 0, "px4_sem_destroy");
    }
  }

#endif

  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
