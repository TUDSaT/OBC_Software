/**
  ******************************************************************************
  * @file           : busInterface.h
  * @brief          : This class defines the interface to communicate with
  *                   the on-board bus using the SPI interface.
  ******************************************************************************
 */

#ifndef BUSINTERFACE_H_
#define BUSINTERFACE_H_
#include "cubesatConstants.h"

/**
 * Sends data from Byte Array data to the Subsystem
 * with the given ID over the on-board bus.
 */
void vBusInterfaceSend(dataPacket * dataPacket);


/**
 * Return received Data from the given subsystem.
 */
dataPacket* xBusInterfaceReceive();

#endif /* BUSINTERFACE_H_ */
