/*
 * main.c
 *
 *  Created on: May 22, 2022
 *      Author: elsay
 */

		 /*LIB*/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
		/*MCAL*/
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/ADC/ADC_INT.h"
#include "../MCAL/TIMER/TIMER_Interface.h"
		/*hardware*/
#include "util/delay.h"


int main()
{
	u16 ADC_OUT=0;
	u16 ANLOG_VALUE=0;
	u8 Analog_TO_Persentage=0;
	/*dio set pin direction*/
	/*ADC CHANNAL 7 FOR Potentiometer*/
	DIO_VidSetPinDirection(DIO_PORTA,PIN3,INPUT);
	/*FOR SERVO*/
	DIO_VidSetPinDirection(DIO_PORTD,PIN5,OUTPUT);
	/*ADC Initialization*/
	ADC_VidINIT();
	ADC_Select_Channal(3);
	/*ADC Start Conversion*/
	ADC_Start_Conversion();
	/*TIMER1 Initialization*/
	TIMER1_INIT();
	/*super loop*/
	while(1)
	{
		ADC_Get_Result(&ADC_OUT);
		ANLOG_VALUE=(ADC_OUT*5000UL)/1023;
		Analog_TO_Persentage=(ANLOG_VALUE*100)/4995;
		Set_Duty_Cycle_TIMER_1_A(Analog_TO_Persentage);


	}
	return 0;
}
