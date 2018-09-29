/*
 * busInterface.c
 *
 *  Created on: 27.09.2018
 *      Author: fnbur
 */
#include "busInterface.h"
#include "usart.h"
#include "cubesatConstants.h"
/**
 * Sends dataPacket the Subsystem defined in the dataPacket Protocol.
 */
void vBusInterfaceSend(dataPacket *dataPacket){
	HAL_UART_Transmit(&huart2, dataPacket, sizeof(dataPacket),BUSINTERFACETIMEOUT);
}

/*
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	receiveComplete = true;
}
*/
/**
 * Return received Data as pointer to a dataPacket.
 */
/*
dataPacket* xBusInterfaceReceive(){
	dataPacket *dataPacket = malloc(sizeof(dataPacket));
	HAL_UART_Receive_IT(&huart1, dataPacket, sizeof(dataPacket));
	return dataPacket;
}
*/
