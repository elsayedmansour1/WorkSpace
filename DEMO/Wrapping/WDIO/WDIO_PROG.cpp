/*
 * DIO_PROG.cpp
 *
 *  Created on: Jun 11, 2022
 *      Author: Adel Khaled
 */

#include "../../LIB/LBIT_MATH.h"
#include "../../LIB/LSTD_TYPES.h"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "WDIO_INT.h"



u8 WDIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue){

	DIO Dio_object;
	Dio_object.MDIO_u8SetPinValue(Copy_u8PortId,Copy_u8PinId,Copy_u8PinValue);
	return 0;
}

u8 WDIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_PinStatus){

	DIO Dio_object;
	Dio_object.MDIO_u8SetPinDirection(Copy_u8PortId,Copy_u8PinId,Copy_PinStatus);
	return 0;
}
