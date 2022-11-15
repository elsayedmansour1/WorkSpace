
/*
 * INTERRUPTS_config.h
 *
 * Created: 1/23/2022 9:20:51 AM
 *  Author: Ebraheem El-Feshawy
 */ 
#ifndef _INTERRUPTS_CONFIG_H
#define _INTERRUPTS_CONFIG_H
#include "INTERRUPTS_private.h"

/**** SELECT SENSE MODE for every INTERRUPT you are using:
													1- EXT_ENABLED
													2- EXT_DISABLED
													*/
#define EXT_INT0_STATE			EXT_ENABLED
#define EXT_INT1_STATE			EXT_ENABLED
#define EXT_INT2_STATE			EXT_ENABLED

/**** SELECT SENSE MODE for every INTERRUPT you are using:
													1- LOW_LEVEL	 
													2- ON_CHANGE	
													3- RISING_EDGE
													4- FALING_EDGE
													*/
#define INT0_SENSE_MODE			LOW_LEVEL    // Choose (1 or 2 or 3 or 4)
#define INT1_SENSE_MODE			LOW_LEVEL	 // Choose (1 or 2 or 3 or 4)
#define INT2_SENSE_MODE			FALING_EDGE  // Choose (3 or 4)

#endif