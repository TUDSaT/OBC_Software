/**
  ******************************************************************************
  * @file           : testTask.h
  * @brief          : This Task runs all tests.
  ******************************************************************************
 */

#ifndef TESTTASK_H_
#define TESTTASK_H_

#include "cmsis_os.h"

osThreadId testTaskHandle;
/**
 * Period of Powertask
 */
#define TESTTASKPERIOD 5000

/**
 * Define the task and start it.
 */
void vTestTaskInit();

/**
 * Main Task to control all tests.
 */
void vTestTaskMain(void *taskParams);



#endif /* TESTTASK_H_ */
