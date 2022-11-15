/*
 * HDIP_SWITCH_Program.c
 *
 *  Created on: May 30, 2022
 *      Author: elsay
 */

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "HDIP_SWITCH_Interface.h"


u8 HDIP_u8GetPressedKey (u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	u8 HDIP_SWITCH_state=0;
	/*set this pin as Input*/
	MDIO_u8SetPinDirection(Copy_u8PortId,Copy_u8PinId,DIO_u8_INPUT);
	/*Activate Pull up resistor*/
	MDIO_u8SetPinValue(Copy_u8PortId,Copy_u8PinId,DIO_u8_HIGH);
	/*to get the state of the selected pin that connect with DIP Switch*/
	MDIO_u8GetPinValue(Copy_u8PortId,Copy_u8PinId,&HDIP_SWITCH_state);
	/*To return the State of DIP Switch*/
	return HDIP_SWITCH_state;

}
u8 HDIP_u8GetPressedKeys (u8 Copy_u8PortId, u8 Copy_u8NumberOfPortPins)
{
	u8 HDIP_SWITCH_state=0;


	return HDIP_SWITCH_state;
}
