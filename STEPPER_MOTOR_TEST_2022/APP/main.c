/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: elsay
 */

		 /*LIB*/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
		/*MCAL*/
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"



		/*hardware*/
#include "../HAL/LCD/LCD_Interface.h"

#include "util/delay.h"


int main(void)
{
	DIO_VidSetPortDirection(DIO_PORTA,OUTPUT);
	while(1)
	{
		/*Step 1*/
		DIO_VidSetPinValue(DIO_PORTA,PIN0,LOW);//blue
		DIO_VidSetPinValue(DIO_PORTA,PIN1,HIGH);//pink
		DIO_VidSetPinValue(DIO_PORTA,PIN2,HIGH);//yellow
		DIO_VidSetPinValue(DIO_PORTA,PIN3,HIGH);//orange
		_delay_ms(2);
		/*Step 2*/
		DIO_VidSetPinValue(DIO_PORTA,PIN0,HIGH);//blue
		DIO_VidSetPinValue(DIO_PORTA,PIN1,LOW);//pink
		DIO_VidSetPinValue(DIO_PORTA,PIN2,HIGH);//yellow
		DIO_VidSetPinValue(DIO_PORTA,PIN3,HIGH);//orange
		_delay_ms(2);
		/*Step 3*/
		DIO_VidSetPinValue(DIO_PORTA,PIN0,HIGH);//blue
		DIO_VidSetPinValue(DIO_PORTA,PIN1,HIGH);//pink
		DIO_VidSetPinValue(DIO_PORTA,PIN2,LOW);//yellow
		DIO_VidSetPinValue(DIO_PORTA,PIN3,HIGH);//orange
		_delay_ms(2);
		/*Step 4*/
		DIO_VidSetPinValue(DIO_PORTA,PIN0,HIGH);//blue
		DIO_VidSetPinValue(DIO_PORTA,PIN1,HIGH);//pink
		DIO_VidSetPinValue(DIO_PORTA,PIN2,HIGH);//yellow
		DIO_VidSetPinValue(DIO_PORTA,PIN3,LOW);//orange
		_delay_ms(2);
	}


	return 0;
}
