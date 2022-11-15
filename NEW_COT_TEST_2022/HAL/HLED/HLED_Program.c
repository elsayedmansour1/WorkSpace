/*
 * HLED_Program.c
 *
 *  Created on: May 30, 2022
 *      Author: elsay
 */

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../../MCAL/MDIO/MDIO_Interface.h"

#include "HLED_Interface.h"

void HLED_voidTurnOn (u8 Copy_u8LedPortId, u8 Copy_u8LedPinId)
{
	MDIO_u8SetPinDirection(Copy_u8LedPortId,Copy_u8LedPinId,DIO_u8_HIGH);
	MDIO_u8SetPinValue(Copy_u8LedPortId,Copy_u8LedPinId,DIO_u8_HIGH);

}
void HLED_voidTurnOff (u8 Copy_u8LedPortId, u8 Copy_u8LedPinId)
{
	MDIO_u8SetPinDirection(Copy_u8LedPortId,Copy_u8LedPinId,DIO_u8_LOW);
	MDIO_u8SetPinValue(Copy_u8LedPortId,Copy_u8LedPinId,DIO_u8_LOW);
}
