/**
  ******************************************************************************
  * @file           : dataProcessingTask.c
  * @brief          : This Task handles the data processing.
  ******************************************************************************
 */


#include "cubesatConstants.h"
#include "dataHandler.h"
#include "cmsis_os.h"
#include "busInterface.h"
#include "dataProcessingTask.h"
/**
 * @brief initializes the thread, which processes received data
 */
void vDataProcessingTaskInit() {
	//Create main task with corresponding variables here
	osThreadDef(dataProcessingTask, vDataProcessingTaskMain, 1, 1, 128);
	dataProcessingTaskHandle = osThreadCreate(osThread(dataProcessingTask), NULL);
}

/**
 * @brief Main Task to process received data
 * @param taskParams pointer to task parameter
 */
void vDataProcessingTaskMain(void *taskParams) {
	//taskParams not used so far

	dataPacket *pvRecvData = pvPortMalloc(sizeof(dataPacket));
	char output[200];
	for (;;) {

		xQueueReceive(xReceivedDataQueue, pvRecvData, portMAX_DELAY);

		//validateDataPacket(xRecvData); //checksum etc

		// debug

		snprintf(output, 200, "Received: senderID: %x receiverId: %x type: %x time: %x data: %x chksm: %x\r\n",
								(int) pvRecvData->senderID,
								(int) pvRecvData->receiverID,
								(int) pvRecvData->type_sID,
								(int) pvRecvData->timestamp,
								(int) pvRecvData->data,
								(int) pvRecvData->chksum
				);
		HAL_UART_Transmit(&huart2,(uint8_t *) output, 200, 1000);

		if(pvRecvData->senderID == powerID) {
			dataPacket *sendData = xDataHandlerPack(
											powerID,
											communicationID,
											xCreateType(dataPacketType, voltageSensorID),
											pvRecvData->data
											);

			vBusInterfaceSend(sendData);

			// debug
			snprintf(output, 200, "Send: senderID: %d receiverId: %d type: %d data: %d\r\n",
									(int) sendData->senderID,
									(int) sendData->receiverID,
									(int) sendData->type_sID,
									(int) sendData->data
					);
			HAL_UART_Transmit(&huart2, (uint8_t *) output, 200, 1000);
			vPortFree(sendData);
		}


	}
}
