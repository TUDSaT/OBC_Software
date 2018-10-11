/**
  ******************************************************************************
  * @file           : cubesatConstants.h
  * @brief          : This file contains different constants that do not
  * 				  change during the entire mission.
  ******************************************************************************
 */
#ifndef CUBESATCONSTANTS_H_
#define CUBESATCONSTANTS_H_

#include "cmsis_os.h"


#define TUDSAT_BUSINTERFACE_TIMOUT  500
#define LOWPOWERTHRESHOLD 42
#define SLEEPCYCLES 42	//Number of cycles to skip when in low power
#define TASKPERIOD 9000	//Set task period
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

#endif /* CUBESATCONSTANTS_H_ */
