/*
  ******************************************************************************
  * @file           : dataProcessingTask.h
  * @brief          : This Task handles the power subsystem.
  ******************************************************************************
 */

#ifndef DATAPROCESSINGTASK_H_
#define DATAPROCESSINGTASK_H_

#include "cmsis_os.h"

osThreadId dataProcessingTaskHandle;

/*
 * Initializes the thread, which processes the received data.
 */
void vDataProcessingTaskInit();

/*
 * Main Task to process received data.
 */
void vDataProcessingTaskMain(void *taskParams);



#endif /* DATAPROCESSINGTASK_H_ */
