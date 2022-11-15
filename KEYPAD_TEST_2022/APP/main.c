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
		/*hardware*/
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/Key_pad/Keypad_Interface.h"
#include "util/delay.h"
int main()
{
	/*variable initialization*/
	u8 Keypad_output_value=0;
	/*lcd initialization*/
	LCD_VidInit();
	/*keypad initialization*/
	KEYPAD_VidInit();
	/*test lcd*/
	LCD_VidWriteString("Welcome elsayed");
	_delay_ms(500);
	LCD_VoidClearDisplay();
	/*super loop*/
	while(1)
	{
		Keypad_output_value=KEYPAD_GET_PressedKey();
		if(Keypad_output_value!=NULL)
		{
			LCD_GoToXY(0,0);
			LCD_VidWriteString("you entered:");
			LCD_VidWriteNumber(Keypad_output_value);
		}


	}


	return 0;
}
