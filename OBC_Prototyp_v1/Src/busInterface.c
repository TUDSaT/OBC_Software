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
	HAL_UART_Transmit(&huart1,(uint8_t *) data, sizeof(dataPacket),TUDSAT_BUSINTERFACE_TIMEOUT);

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	xQueueSendFromISR(xReceivedDataQueue, pvRecvDataPacket, NULL);
	HAL_UART_Receive_IT(&huart1, (uint8_t *) pvRecvDataPacket, sizeof(dataPacket));
}
/**
 * @brief Initialize bus interface and receive interrupt.
 */
void vInitBusInterface() {
	xReceivedDataQueue = xQueueCreate(10, sizeof(dataPacket));
	pvRecvDataPacket = pvPortMalloc(sizeof(dataPacket));
	HAL_UART_Receive_IT(&huart1,(uint8_t *) pvRecvDataPacket, sizeof(dataPacket));

}
