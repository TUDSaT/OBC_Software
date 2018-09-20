/*
 * powerTask.c
 *
 *  Created on: 13.09.2018
 */
#include "powerTask.h"
#include "cubesatConstants.h"
#include "dataHandler.h"
#include "cmsis_os.h"

void vPowerTaskInit(){

}

void vPowerTaskMain( void *taskParams){
	for(;;){

		// Create type for request to power System
		uint8_t type = xCreateType(commandType, voltageSensorID);

		// Request contains no data
		uint32_t data = 0;

		// create data Packet
		dataPacket *batteryStatusRequest = xDataHandlerPack(obcID, powerID, type, data);

		//send battery status request over bus
		vBusInterfaceSend(batteryStatusRequest, sizeof(batteryStatusRequest), powerID);

		// free memory of data Packet
		free(batteryStatusRequest);
	}
}


