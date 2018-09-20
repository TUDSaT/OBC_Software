/**
  ******************************************************************************
  * @file           : dataHandler.h
  * @brief          : This handler provides functionality to pack rawdata into
  * 				  data packets.
  ******************************************************************************
 */
#include "cmsis_os.h"
#include "cubesatConstants.h"
#ifndef DATAHANDLER_H_
#define DATAHANDLER_H_

/**
 * This method takes in the raw Sensor Data and packs it into
 * a format that can be send to the ground station.
 */
dataPacket *xDataHandlerPack(subsystemID senderID, subsystemID reciverID, uint8_t type_sID, uint32_t data);

/**
 * This method creates a correct type_sID byte from a packetType and a sensorID.
 */
uint8_t xCreateType(packetType packetType, uint8_t sensorID);
#endif /* DATAHANDLER_H_ */
