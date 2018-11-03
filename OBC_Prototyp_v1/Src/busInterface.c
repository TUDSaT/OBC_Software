/**
  ******************************************************************************
  * @file           : busInterface.c
  * @brief          : This class implements HAL_UART instructions to realize
  * 				  communication between the OBC and other satellite-entities via the on-board bus
  ******************************************************************************
 */


#include "busInterface.h"

/**
 * @brief Sends data from Byte Array data to the Subsystem with the given ID over the on-board bus.
 * @param *dataPacket is the dataPacket which is supposed to be sent
 */
void vBusInterfaceSend(dataPacket *data){
	HAL_UART_Transmit(&huart1, data, sizeof(dataPacket),TUDSAT_BUSINTERFACE_TIMEOUT);
}

/*
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	receiveComplete = true;
}
*/

/**
 * @brief writes received Data into the given dataPacket.
 * @param *recvDataPacket is a pointer to where the received dataPacket is supposed to be stored
 * @return the status of the communication as a HAL_StatusTypeDef
 */
HAL_StatusTypeDef xBusInterfaceReceive(dataPacket* recvDataPacket){
	return HAL_UART_Receive(&huart1, recvDataPacket, sizeof(dataPacket),TUDSAT_BUSINTERFACE_TIMEOUT*4);
}
