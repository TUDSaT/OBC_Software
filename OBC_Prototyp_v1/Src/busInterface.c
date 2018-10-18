/*
 * busInterface.c
 *
 *  Created on: 27.09.2018
 *      Author: fnbur
 */
#include "busInterface.h"
/**
 * Sends dataPacket the Subsystem defined in the dataPacket Protocol.
 */
void vBusInterfaceSend(dataPacket *dataPacket){
	HAL_UART_Transmit(&huart1, dataPacket, sizeof(dataPacket),TUDSAT_BUSINTERFACE_TIMEOUT);
}

/*
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	receiveComplete = true;
}
*/

/**
 * Writes received Data into the given dataPacket.
 * Returns HAL_StatusTypeDef.
 */
HAL_StatusTypeDef xBusInterfaceReceive(dataPacket* recvDataPacket){
	return HAL_UART_Receive(&huart1, recvDataPacket, sizeof(dataPacket),TUDSAT_BUSINTERFACE_TIMEOUT*4);
}

