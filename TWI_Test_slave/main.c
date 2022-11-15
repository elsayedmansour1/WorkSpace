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
#include "TWI_Interface.h"
#include "LCD_Interface.h"
#include "avr/delay.h"

int main(void)
{
	//DIO_VidSetPinDirection(DIO_PORTC,PIN1,INPUT);//for DATA
	DIO_VidSetPinDirection(DIO_PORTC,PIN0,INPUT);//for Clock
	DIO_VidSetPinDirection(DIO_PORTC,PIN2,OUTPUT);
	LCD_VidInit();
	//LCD_DisplayString("welcome elsayed1");
	//_delay_ms(1000);
	LCD_VoidClearDisplay();
	TWI_voidSlaveInit();

	u8 data=0;
	while(1)
	{
		data=TWI_u8SlaveReceiveData();
		LCD_DisplayString(&data);
		_delay_ms(500);
		if(data=='v')
		{
			DIO_VidSetPinValue(DIO_PORTC,PIN2,HIGH);

		}
		_delay_ms(10);
	}
}
