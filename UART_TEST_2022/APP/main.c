/*
 * main.c
 *
 *  Created on: May 14, 2022
 *      Author: elsay
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/UART/UART_Interface.h"
#include "util/delay.h"



void main()
{
	DIO_VidSetPinDirection(DIO_PORTA,PIN0,OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTD,PIN0,INPUT);
	DIO_VidSetPinDirection(DIO_PORTD,PIN1,OUTPUT);

	u8 GetData=0;
	u8 ptr=0;
	/*UART INIT*/
	UART_INIT();
	/*LCD INIT*/
	LCD_VidInit();
	LCD_VidWriteString(("Welcome Elsayed"));
	_delay_ms(1000);
	LCD_VidWriteCommend(1);
	while(1)
	{
		GetData=UART_VoidGetChar();
		if(GetData=='3')
		{
			DIO_VidSetPinValue(DIO_PORTA,PIN0,HIGH);
			UART_VoidSendChar(GetData);
		}
		else if(GetData=='c')
		{
			DIO_VidSetPinValue(DIO_PORTA,PIN0,LOW);
		}
		UART_VoidSendChar(GetData);
		_delay_ms(200);
/*
		ptr=UART_VoidGetChar();
		if (ptr!=NULL)
		{
		//LCD_VidWriteString(ptr)	;
		LCD_VidWriteData(ptr)}*/

		}





}
