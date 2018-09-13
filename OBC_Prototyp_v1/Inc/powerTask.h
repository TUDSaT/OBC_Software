/**
  ******************************************************************************
  * @file           : powerTask.h
  * @brief          : This Task handles the power subsystem.
  ******************************************************************************
 */

#ifndef POWERTASK_H_
#define POWERTASK_H_


/**
 * Define the task and start it.
 */
void vPowerTaskInit();

/**
 * Main Task to control the power subsystem.
 */
void vPowerTaskMain(void *taskParams);



#endif /* POWERTASK_H_ */
