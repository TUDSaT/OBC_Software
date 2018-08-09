/**
  ******************************************************************************
  * @file           : cubesatConstants.h
  * @brief          : This file contains different constants that do not
  * 				  change during the entire mission.
  ******************************************************************************
 */

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


#endif /* CUBESATCONSTANTS_H_ */
