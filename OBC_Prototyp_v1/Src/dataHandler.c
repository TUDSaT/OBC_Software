/*
 * dataHandler.c
 *
 *  Created on: 19.08.2018
 *      Author: fnbur
 */
#include "dataHandler.h"
#include "crc.h"



/**
 * This class takes in the raw Sensor Data and packs it into
 * a format that can be send to the ground station.
 */
dataPacket *xDataHandlerPack(subsystemID senderID, subsystemID receiverID, uint8_t type, uint32_t data){
	//packing the dataPacket with all known values.
	//TODO check memory allocation
	dataPacket *dataPacket = malloc(sizeof(dataPacket));
	dataPacket->senderID = senderID;
	dataPacket->receiverID= receiverID;
	dataPacket->type= type;
	dataPacket->padding=0;
	//get timestamp from system uptime.
	dataPacket->timestamp= HAL_GetTick();
	dataPacket->data = data;

	//32 bit buffer for calucalting the CRC checksum
	uint32_t buffer[3];
	//for the first 32bit bufferelement combining 4 8bit elements together:
	//		senderID, receiverID, type and 8bit of zeros
	buffer[0] = dataPacket->senderID;
	buffer[0] = buffer[0] << 8;						//shift left 8 times to make room for the next byte
	buffer[0] = buffer[0] | dataPacket->receiverID;
	buffer[0] = buffer[0] << 8;						//shift left 8 times to make room for the next byte
	buffer[0] = buffer[0] | dataPacket->type;
	buffer[0] = buffer[0] << 8;						//shift left 8 times to align correctly, rest are padded wit zeros

	buffer[1] = dataPacket->timestamp;
	buffer[2] = dataPacket->data;
	//calculate the CRC checksum
	dataPacket->chksum=HAL_CRC_Calculate(&hcrc, buffer, 3);
	return dataPacket;
}

