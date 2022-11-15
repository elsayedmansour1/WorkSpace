/*
 * main.c
 *
 *  Created on: Apr 19, 2022
 *      Author: elsay
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INT.h"
#include "DIO_config.h"
#include <util/delay.h>


int  main(void)
{
	//pin0===>les
	//pin1===>swtich
	//Set pin0 at port A as output
	DIO_VidSetPinDirection	(DIO_PORTA,PIN0,OUTPUT);
	//Set pin1 at port A as input
	DIO_VidSetPinDirection	(DIO_PORTA,PIN1,INPUT);
	//ACTIVIT PULL UP RESISTOR
	DIO_VidSetPinValue	(DIO_PORTA,PIN1,HIGH);
	//SET pin 0 at port A as low at first
	DIO_VidSetPinValue	(DIO_PORTA,PIN0,LOW);
	while(1)
	{
		if((DIO_u8GetPinValue(DIO_PORTA,PIN1))==0 )
		{
			DIO_VidSetPinValue	(DIO_PORTA,PIN0,HIGH);
		}
		else
		{
			DIO_VidSetPinValue	(DIO_PORTA,PIN0,LOW);
		}
	}

	return 0;
}
