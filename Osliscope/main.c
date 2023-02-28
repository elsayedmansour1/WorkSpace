/*
 * main.c
 *
 *  Created on: Feb 27, 2023
 *      Author: elsayedm
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_config.h"
#include "HAL/LCD_Interface.h"
#include "app/Osc.h"
int main()
{
	u8 Loc_State=0;

	LCD_VidInit();
	Oscilloscope_init();

	DIO_VidSetPinDirection(DIO_PORTC,PIN0,INPUT);
	DIO_VidSetPinValue(DIO_PORTC,PIN0,HIGH);

	LCD_DisplayString("welcome elsayed2");
	while(1)
	{
		Loc_State=Oscilloscope_Start(DIO_u8GetPinValue(DIO_PORTC,PIN0));
		if (Loc_State==1 && DIO_u8GetPinValue(DIO_PORTC,PIN0))
		{
			LCD_VoidClearDisplay();
			LCD_VidWriteNumber(Osc_GetTime_ms());
		}

	}

	return 0;
}
