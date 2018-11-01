/*
  ******************************************************************************
  * @file           : powerTask.h
  * @brief          : This Task handles the power subsystem.
  ******************************************************************************
 */

#ifndef POWERTASK_H_
#define POWERTASK_H_

#include "cmsis_os.h"

osThreadId powerTaskHandle;

/*
 * Initializes the thread, which runs the power-regulation of the OBC.
 */
void vPowerTaskInit();

/*
 * Main Task to control the power subsystem.
 */
void vPowerTaskMain(void *taskParams);



#endif /* POWERTASK_H_ */
