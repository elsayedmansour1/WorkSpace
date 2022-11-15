/*
 * main.c
 *
 *  Created on: Oct 13, 2020
 *      Author: elsay
 */
#include "../LIB/LBIT_MATH.h"
#include "../LIB/LSTD_TYPES.h"

#include "../MCAL/MDIO/MDIO_Interface.h"

#include "avr/delay.h"

#include "../HAL/HLCD/HLCD_Interface.h"
#include "../HAL/HKeypad/HKeypad_Interface.h"
#include "../HAL/HDIP_SWITCH/HDIP_SWITCH_Interface.h"
int main(void)
{
	u8 Keypad_out=1;
	/*LCD INITIALIZATION*/
	HLCD_VidInit();
	HKEYPAD_VidInit();
	HLCD_DisplayString("Welcome elsayed");
	//HLCD_VidWriteData('A');
	_delay_ms(1000);
	HLCD_VoidClearDisplay();
	while(1)
	{
		Keypad_out=HKEYPAD_GET_PressedKey();
		if(Keypad_out!=0)
		{
			HLCD_SetPosition(0,0);
			HLCD_DisplayString("the value=");
			HLCD_VidWriteNumber(Keypad_out);
		}
		Keypad_out=0;
//		Keypad_out=HDIP_u8GetPressedKey(DIO_u8_PORTC,DIO_u8_PIN0);
//		if(Keypad_out==0)
//		{
//			HLCD_VoidClearDisplay();
//			HLCD_DisplayString("you click on dip switch");
//		}
//		Keypad_out=1;
	}


	return 0;
}
