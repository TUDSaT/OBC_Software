/*
  ******************************************************************************
  * @file           : dataHandler.h
  * @brief          : This handler provides functionality to pack rawdata into
  * 				  data packets.
  ******************************************************************************
 */
#ifndef DATAHANDLER_H_
#define DATAHANDLER_H_

#include "cmsis_os.h"
#include "cubesatConstants.h"

/**
 * This method takes the given values of senderID, receiverID, type and data and
 * stores them in given dataPacket localDataPacket. The necessary crc checksum is
 * also calculated.
 */
xDataHandlerPack(dataPacket *localDataPacket, subsystemID senderID, subsystemID receiverID,
		uint8_t type_sID, uint32_t data) 
/**
 * This method calculates the 32 bit CRC checksum of a dataHandler given as pointer.
 * Note: It uses the hardware CRC-Calculator of the chip. 
 * Note: The CRC checksum is MPEG-2. 
 */
uint32_t xDataPacketCRCSum(dataPacket *dataPacket);

/**
 * This method creates a correct type_sID byte from a packetType and a globalSensorID.
 */
uint8_t xCreateType(packetType packetType, uint8_t sensorID);
#endif /* DATAHANDLER_H_ */
