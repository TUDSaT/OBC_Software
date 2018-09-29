/**
  ******************************************************************************
  * @file           : cubesatConstants.h
  * @brief          : This file contains different constants that do not
  * 				  change during the entire mission.
  ******************************************************************************
 */
#include "cmsis_os.h"
#ifndef CUBESATCONSTANTS_H_
#define CUBESATCONSTANTS_H_

/**
 * IDs of the different Subsystem used to identify them on the BUS.
 */
typedef enum {
	powerID,
	communicationID,
	obcID
} subsystemID;

typedef enum{
	commandPacketType = 0,
	dataPacketType = 1
}packetType;

typedef struct {
	subsystemID senderID;
	subsystemID receiverID;
	uint8_t type_sID;
	uint8_t padding;
	uint32_t timestamp;
	uint32_t data;
	uint32_t chksum;
} dataPacket;

typedef enum{
	false,
	true
} bool;

typedef enum{
	voltageSensorID
} globalSensorID;
const uint32_t BUSINTERFACETIMEOUT = 500;
#endif /* CUBESATCONSTANTS_H_ */
