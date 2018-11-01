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
 * This method takes in the raw Sensor Data and packs it into
 * 			a format that can be used for internal communication or
 * 			transmission to a ground station.
 */
dataPacket *xDataHandlerPack(subsystemID senderID, subsystemID reciverID, uint8_t type_sID, uint32_t data);

/**
 * This method calculates the 32 bit CRC checksum of a dataHandler given as pointer.
 */
uint32_t xDataPacketCRCSum(dataPacket *dataPacket);

/**
 * This method creates a correct type_sID byte from a packetType and a globalSensorID.
 */
uint8_t xCreateType(packetType packetType, uint8_t sensorID);
#endif /* DATAHANDLER_H_ */
