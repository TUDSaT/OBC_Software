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
		//TODO define type and data - create method to easily build type information
		uint8_t type = 0;
		uint32_t data = 0;

		dataPacket *batteryStatusRequest = xDataHandlerPack(obcID,powerID,type, data);
		//TODO generate size
		vBusInterfaceSend(batteryStatusRequest, NULL, powerID);
	}
}


