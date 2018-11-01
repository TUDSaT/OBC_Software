/**
  ******************************************************************************
  * @file           : testTask.c
  * @brief          : This Task handles all tests.
  ******************************************************************************
  *  Created on: 13.09.2018
 */


#include "testTask.h"
#include "cubesatConstants.h"
#include "dataHandler.h"
#include "cmsis_os.h"
#include "busInterface.h"

/**
 * @brief initializes the thread, which runs the communication test on the OBC
 */
void vTestTaskInit() {
	//Create main task with corresponding variables here
	osThreadDef(testTask, vTestTaskMain, 1, 1, 128);
	testTaskHandle = osThreadCreate(osThread(testTask), NULL);
}

void vTestTaskMain(void *taskParams) {
	//taskParams not used so far
//	bool isLowPower = false;	//Switch for lowPower-mode
//	int wakeUpCountdown = 0;	//Count-down of sleeping cycles for lowPower
	//dataPacket * recvDataPacket = pvPortMalloc(sizeof(dataPacket));

	for (;;) {
		// Create type for request to power System
		uint8_t requestType = xCreateType(commandPacketType, testSensorID);

		// Request contains no data
		uint32_t testData = 42;

		// create data Packet
		dataPacket *TestRequest = xDataHandlerPack(obcID, communicationID,
				requestType, testData);

		vBusInterfaceSend(TestRequest);
		//receive data from battery-PyBoard
		//HAL_StatusTypeDef status = xBusInterfaceReceive(recvDataPacket);

		//interpret received data (send only)
//		if (status == HAL_OK) {
//			if (recvDataPacket->chksum == xDataPacketCRCSum(recvDataPacket)
//					&& recvDataPacket->senderID == communicationID
//					&& recvDataPacket->type_sID == (0x80 | testSensorID)) {
//				//debug(&huart2, &(recvDataPacket->data), 4, 500);
//				if (recvDataPacket->data < LOWPOWERTHRESHOLD) {
//					isLowPower = true;
//				} else {
//					isLowPower = false;
//					wakeUpCountdown = 0;
//				}
//
//			}
//		}

//		if (wakeUpCountdown <= 0) {
//			if (status == HAL_OK) {
//				if (recvDataPacket->chksum == xDataPacketCRCSum(recvDataPacket)
//						&& recvDataPacket->senderID == powerID
//						&& recvDataPacket->type_sID
//								== (0x80 | voltageSensorID)) {
//
//					//send data to communication
//					dataPacket * sendDataPacket = xDataHandlerPack(obcID,
//							communicationID,
//							xCreateType(commandPacketType, voltageSensorID),
//							recvDataPacket->data);
//					vBusInterfaceSend(sendDataPacket);
//					// free memory of data Packet
//					vPortFree(sendDataPacket);
//					if (isLowPower) {
//						wakeUpCountdown = SLEEPCYCLES;
//					}
//				}
//			}
//		} else {
//			wakeUpCountdown--;
//		}

		vPortFree(TestRequest);

		osDelay(TASKPERIOD);
	}
}
