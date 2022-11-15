/*
 * main.c
 *
 *  Created on: Oct 30, 2022
 *      Author: elsay
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_config.h"
#include "EEPROM_Interface.h"
#include "avr/delay.h"

int main(void)
{
	DIO_VidSetPinDirection(DIO_PORTC,PIN0,OUTPUT);//SCL

	DIO_VidSetPinDirection(DIO_PORTA,PIN0,OUTPUT);
	EEPROM_voidInit();

	u8 data=0;
	while(1)
	{
		EEPRoM_voidWriteData(5,10);
		_delay_ms(500);
		EEPRoM_voidReadData(&data,10);
		if (data==5)
		{
			DIO_VidSetPinValue(DIO_PORTA,PIN0,HIGH);
		}
		_delay_ms(1000);
	}
}
