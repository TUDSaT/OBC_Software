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


/**
 * IDs for the different sensors
 */
typedef enum {
	voltageSensorID
} sensorIDs;

typedef struct {
	subsystemID senderID;
	subsystemID receiverID;
	uint8_t type;
	uint8_t padding;
	uint32_t timestamp;
	uint32_t data;
	uint32_t chksum;
} dataPacket;


#endif /* CUBESATCONSTANTS_H_ */
