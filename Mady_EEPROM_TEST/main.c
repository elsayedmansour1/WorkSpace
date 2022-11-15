/*
 * main.c
 *
 *  Created on: Nov 11, 2022
 *      Author: elsay
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_config.h"
#include "EEPROM_Interface.h"
#include "avr/delay.h"
int main ()
{
	DIO_VidSetPinDirection(DIO_PORTA,PIN0,OUTPUT);
	/*EEPROM Initialization*/
	EEPROM_voidInit();
	u8 Loc_u8Data=0;
	while(1)
	{
		/*send data=5 to EEPROM at Location =10*/
		EEPROM_voidSendData(5,10);
		/*receive unknown data form Location =10*/
		EEPROM_voidReceiveData(&Loc_u8Data,10);
		if (Loc_u8Data==5)
		{
			DIO_VidSetPinValue(DIO_PORTA,PIN0,HIGH);
		}

	}

	return 0;
}
