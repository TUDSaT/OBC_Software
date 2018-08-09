/**
  ******************************************************************************
  * @file           : busInterface.h
  * @brief          : This class defines the interface to communicate with
  *                   the on-board bus using the SPI interface.
  ******************************************************************************
 */

#ifndef BUSINTERFACE_H_
#define BUSINTERFACE_H_


/**
 * Sends data from Byte Array data to the Subsystem
 * with the given ID over the on-board bus.
 */
void vBusInterfaceSend(byte *data, int length, subsystemID id);


/**
 * Return received Data from the given subsystem.
 */
byte* xBusInterfaceReceive(subsystemID id);

#endif /* BUSINTERFACE_H_ */
