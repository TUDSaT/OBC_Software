/**
  ******************************************************************************
  * @file           : powerTask.c
  * @brief          : This Task handles the power subsystem.
  ******************************************************************************
 */


#include "powerTask.h"
#include "cubesatConstants.h"
#include "dataHandler.h"
#include "cmsis_os.h"
#include "busInterface.h"

/**
 * @brief initializes the thread, which runs the power-regulation of the OBC
 */
void vPowerTaskInit() {
	//Create main task with corresponding variables here
	osThreadDef(powerTask, vPowerTaskMain, 1, 1, 128);
	powerTaskHandle = osThreadCreate(osThread(powerTask), NULL);
}

/**
 * @brief Main Task to control the power subsystem.
 * @param taskParams pointer to task parameter
 */
void vPowerTaskMain(void *taskParams) {
	//taskParams not used so far
	//bool isLowPower = false;	//Switch for lowPower-mode
	//int wakeUpCountdown = 0;	//Count-down of sleeping cycles for lowPower

	// Create type for request to power System
	uint8_t requestType = xCreateType(commandPacketType, voltageSensorID);

	// Request contains no data
	uint32_t requestData = 0;

	// create data Packet
	dataPacket *batteryStatusRequest = xDataHandlerPack(obcID, powerID,
					requestType, requestData);
	for (;;) {

		vBusInterfaceSend(batteryStatusRequest);

		osDelay(TASKPERIOD);
	}
}
