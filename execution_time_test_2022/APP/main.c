/*
 * main.c
 *
 *  Created on: Oct 13, 2020
 *      Author: elsay
 */
#include "../LIB/LBIT_MATH.h"
#include "../LIB/LSTD_TYPES.h"

#include "../MCAL/MDIO/MDIO_Interface.h"

#include "../MCAL/TIMER1/TIMER1_Interface.h"
#include "../MCAL/GIE/MGIE_Interface.h"

#include "../HAL/HLCD/HLCD_Interface.h"
#include "avr/delay.h"
void Timer_OV(void);
u8 Counter=0;
int main(void)
{
	/*Global interrupt enable*/
	GIE_Vid_Enable();
	/*Local Variable Definition*/
	u16 Local_TCNT_Value=0;
	TIMER1_OV_SetCallBack(Timer_OV);
	/*LCD INITIALIZATION*/
		HLCD_VidInit();

	/*Timer 1 Initialization*/
	TIMER1_INIT();
	MDIO_u8SetPortDirection(DIO_u8_PORTB,DIO_u8_OUTPUT);
	MDIO_u8SetPortValue(DIO_u8_PORTB,DIO_u8_HIGH);
	MDIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_INPUT);
	MDIO_u8SetPortDirection(DIO_u8_PORTB,DIO_u8_OUTPUT);
	MDIO_u8SetPortValue(DIO_u8_PORTB,DIO_u8_HIGH);
	MDIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_INPUT);
	Local_TCNT_Value=Timer1_U16GetTCNT1Value();
	GIE_Vid_Disable();
	HLCD_SetPosition(0,0);
	HLCD_VidWriteNumber(Local_TCNT_Value);
	HLCD_SetPosition(1,0);
	HLCD_VidWriteNumber(Counter);

	while(1)
	{

	}
	return 0;
}
void Timer_OV(void)
{
	Counter++;
}
