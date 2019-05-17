/*
  ******************************************************************************
  * @file           : busInterface.h
  * @brief          : This class defines the interface to communicate with
  *                   the on-board bus
  ******************************************************************************
 */



#ifndef BUSINTERFACE_H_
#define BUSINTERFACE_H_

#include "cubesatConstants.h"
#include "usart.h"
/*
 * Queue holds unprocessed received data
 */
QueueHandle_t xReceivedDataQueue;

/*
 * Buffer stores datapacket for interrupt
 */
dataPacket *pvRecvDataPacket;


/*
 * Sends data from Byte Array data to the Subsystem
 * with the given ID over the on-board bus.
 */
void vBusInterfaceSend(dataPacket * dataPacket);

/*
 * Init Businterface
 */
void vInitBusInterface();

#endif /* BUSINTERFACE_H_ */
