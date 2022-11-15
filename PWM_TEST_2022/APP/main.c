/*
 * main.c
 *
 *  Created on: May 5, 2022
 *      Author: elsay
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/Global Interrupt/GIE_INT.h"
#include "../MCAL/TIMER/TIMER_Interface.h"
#include "util/delay.h"


int main()
{
	//set pin direction -->port B pin 3
	//DIO_VidSetPinDirection(DIO_PORTD,PIN4,OUTPUT);
	//initialization timer zero
	DIO_VidSetPinDirection(DIO_PORTD,PIN5,OUTPUT);
	TIMER1_INIT();
	//initialization LCD
	LCD_VidInit();
	LCD_VidWriteString("welcome elsayed");
	_delay_ms(1000);
	//Super Loop{
	while(1)
	{

		LCD_VidWriteCommend(1);
	//Set Duty Cycle
		Set_Duty_Cycle_TIMER_1_A(3);
		LCD_VidWriteString("Angle=0");
		_delay_ms(5000);
		LCD_VidWriteCommend(1);
		Set_Duty_Cycle_TIMER_1_A(7.5);
		LCD_VidWriteString("Angle=90");
		_delay_ms(5000);
		LCD_VidWriteCommend(1);
		Set_Duty_Cycle_TIMER_1_A(12.5);
		LCD_VidWriteString("Angle=180");
		_delay_ms(5000);
		/*LCD_VidWriteCommend(1);
		Set_Duty_Cycle_TIMER_2(100);
		LCD_VidWriteString("Rotation=100%");
		_delay_ms(1000);*/
	}


	return 0;
}
