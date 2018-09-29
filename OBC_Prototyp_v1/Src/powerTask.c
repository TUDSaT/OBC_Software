/*
 * powerTask.c
 *
 *  Created on: 13.09.2018
 */

#include "powerTask.h"
#include "cubesatConstants.h"
#include "dataHandler.h"
#include "cmsis_os.h"
#include "busInterface.h"


void vPowerTaskInit() {
	//Create main task with corresponding variables here
	osThreadDef(powerTask, vPowerTaskMain, 1, 1, 128);
	powerTaskHandle = osThreadCreate(osThread(powerTask), NULL);
}

void vPowerTaskMain(void *taskParams) {
	//taskParams not used so far
	bool isLowPower = false;	//Switch for lowPower-mode
	int wakeUpCountdown = 0;	//Count-down of sleeping cycles for lowPower
	dataPacket * recvDataPacket = pvPortMalloc(sizeof(dataPacket));

	for (;;) {
		// Create type for request to power System
		uint8_t requestType = xCreateType(commandPacketType, voltageSensorID);

		// Request contains no data
		uint32_t requestData = 0;

		// create data Packet
		dataPacket *batteryStatusRequest = xDataHandlerPack(obcID, powerID,
				requestType, requestData);

		vBusInterfaceSend(batteryStatusRequest);
		//receive data from battery-PyBoard
		HAL_StatusTypeDef status = xBusInterfaceReceive(recvDataPacket);

		//interpret received data
		if (status == HAL_OK) {
			if (recvDataPacket->chksum == xDataPacketCRCSum(recvDataPacket)
					&& recvDataPacket->senderID == powerID
					&& recvDataPacket->type_sID == (0x80 | voltageSensorID)) {
				//debug(&huart2, &(recvDataPacket->data), 4, 500);
				if (recvDataPacket->data < LOWPOWERTHRESHOLD) {
					isLowPower = true;
				} else {
					isLowPower = false;
					wakeUpCountdown = 0;
				}

			}
		}

		if (wakeUpCountdown <= 0) {
			if (status == HAL_OK) {
				if (recvDataPacket->chksum == xDataPacketCRCSum(recvDataPacket)
						&& recvDataPacket->senderID == powerID
						&& recvDataPacket->type_sID
								== (0x80 | voltageSensorID)) {

					//send data to communication
					dataPacket * sendDataPacket = xDataHandlerPack(obcID,
							communicationID,
							xCreateType(commandPacketType, voltageSensorID),
							recvDataPacket->data);
					vBusInterfaceSend(sendDataPacket);
					// free memory of data Packet
					vPortFree(sendDataPacket);
					if (isLowPower) {
						wakeUpCountdown = SLEEPCYCLES;
					}
				}
			}
		} else {
			wakeUpCountdown--;
		}

		vPortFree(batteryStatusRequest);

		osDelay(TASKPERIOD);
	}
}
