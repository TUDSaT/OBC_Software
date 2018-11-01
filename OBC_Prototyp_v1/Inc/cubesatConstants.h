/**
  ******************************************************************************
  * @file             cubesatConstants.h
  * @brief            This file contains different constants that do not
  * 				  change during the entire mission.
  ******************************************************************************
 */
#ifndef CUBESATCONSTANTS_H_
#define CUBESATCONSTANTS_H_

#include "cmsis_os.h"


/**
 * Timeout for waiting on the bus
 */
#define TUDSAT_BUSINTERFACE_TIMEOUT  500
/**
 * Battery threshold to go to Low power mode
 */

#define LOWPOWERTHRESHOLD 42
/**
 *  Number of cycles to skip when in low power
 */
#define SLEEPCYCLES 42
/**
 * Period of Powertask
 */
#define TASKPERIOD 9000

/**
 * IDs of the different Subsystem used to identify them on the bus.
 */
typedef enum {
	powerID,
	communicationID,
	obcID
} subsystemID;

/**
 * PacketType used to differentiate between Command and Data Packets on the Bus
 */
typedef enum{
	commandPacketType = 0, /** 0 */
	dataPacketType = 1     /** 1 */
}packetType;

/**
 * This structure represents the DataPackets send over the Bus.
 */
typedef struct {
	/** The subsystemID of the Sender */
	subsystemID senderID;

	/** The subsystemID of the Receiver */
	subsystemID receiverID;

	/** The Type of the Packet, can be either Command or Data. Lower 7 bits contain Sensor ID */
	uint8_t type_sID;

	/** Padding, not used */
	uint8_t padding;

	/** Generation time of packet, in milliseconds since boot */
	uint32_t timestamp;

	/** Payload data of the packet */
	uint32_t data;

	/** CRC32 Checksum */
	uint32_t chksum;
} dataPacket;

/**
 * Boolean Type
 */
typedef enum{
	false,
	true
} bool;

/**
 * Enum containing all the Sensor IDs
 */
typedef enum{
	voltageSensorID,
	testSensorID
} globalSensorID;

#endif /* CUBESATCONSTANTS_H_ */
