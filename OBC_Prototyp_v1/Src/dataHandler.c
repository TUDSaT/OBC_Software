/**
 ******************************************************************************
 * @file           : dataHandler.c
 * @brief          : This handler provides functionality to pack rawdata into
 * 				  data packets.
 ******************************************************************************
 */
#include "dataHandler.h"
#include "crc.h"

/**
 * @brief This method takes in the raw Sensor Data and packs it into
 * 			a format that can be used for internal communication or
 * 			transmission to a ground station.
 * @param senderID subsystemID of the sender
 * @param receiverID subsystemID of the receiver
 * @param type_sID defines if command or data and contains the globalSensorID
 * @param data data to be send
 * @return returns a dataPacket pointer to the created dataPacket
 */
dataPacket *xDataHandlerPack(subsystemID senderID, subsystemID receiverID,
		uint8_t type_sID, uint32_t data) {
	//packing the dataPacket with all known values.
	//TODO check memory allocation
	dataPacket *localDataPacket = pvPortMalloc(sizeof(dataPacket));
	localDataPacket->senderID = senderID;
	localDataPacket->receiverID = receiverID;
	localDataPacket->type_sID = type_sID;
	localDataPacket->padding = 0;
	//get timestamp from system uptime.
	localDataPacket->timestamp = HAL_GetTick();
	localDataPacket->data = data;

	//calculate the CRC checksum
	localDataPacket->chksum = xDataPacketCRCSum(localDataPacket);
	return localDataPacket;
}

/**
 * @brief This method calculates the 32 bit CRC checksum of a dataHandler given as pointer.
 * @param dataPacket pointer to the dataPacket
 * @return returns the 32 bit CRC checksum
 */
uint32_t xDataPacketCRCSum(dataPacket *dataPacket) {
	//32 bit buffer for calucalting the CRC checksum
	uint32_t buffer[3];
	//for the first 32bit bufferelement combining 4 8bit elements together:
	//		senderID, receiverID, type and 8bit of zeros
	buffer[0] = dataPacket->senderID;
	buffer[0] = buffer[0] << 8;	//shift left 8 times to make room for the next byte
	buffer[0] = buffer[0] | dataPacket->receiverID;
	buffer[0] = buffer[0] << 8;	//shift left 8 times to make room for the next byte
	buffer[0] = buffer[0] | dataPacket->type_sID;
	buffer[0] = buffer[0] << 8;	//shift left 8 times to align correctly, rest are padded wit zeros

	buffer[1] = dataPacket->timestamp;
	buffer[2] = dataPacket->data;
	//calculate the 32 bit CRC checksum
	return HAL_CRC_Calculate(&hcrc, buffer, 3);

}

/**
 * @brief This method checks whether the checksum corresponds to the dataPacket
 * @param dataPacket pointer to the dataPacket
 * @return true if the checksum is set accordingly or false if something went wrong during communication
 */
bool xVerifyCheckSum(dataPacket *dataPacket) {
	return dataPacket->chksum == xDataPacketCRCSum(dataPacket);
}

/**
 * @brief This method creates a correct type_sID byte from a packetType and a globalSensorID.
 * @param packetType which defines whether it is a command or data
 * @param sensorID globalSensorID
 * @return returns the type
 */
uint8_t xCreateType(packetType packetType, uint8_t sensorID) {
	sensorID = sensorID & 0x7F; 	//cut MSB from sensorID
	uint8_t pT = packetType << 7;//shift bit of packetType 7 times to the left so that it is the MSB
	pT = sensorID | pT;		//MSB from packetType, all other bits from sensorID

	return pT;
}
