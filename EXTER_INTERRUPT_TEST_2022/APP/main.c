/*
 * main.c
 *
 *  Created on: Apr 22, 2022
 *      Author: elsay
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/External Interrupt/EX_INT_Int.h"
#include "../MCAL/Global Interrupt/GIE_INT.h"
#include <util/delay.h>

void EX_FUNC(void);
int main()
{
//lcd initialization
	LCD_VidInit();
	LCD_VidWriteString("START INIT====>");
		//STEP 1
//set direction of b2 in  portb as input
	DIO_VidSetPinDirection(DIO_PORTB,PIN2,INPUT);
//activity pull up resistor
	DIO_VidSetPinValue(DIO_PORTB,PIN2,HIGH);
		//STEP 2
//enable external interrupt with falling edge detector
		EX_INT2_INIT();
		//STEP 3
//enable global interrupt
		GIE_Vid_Enable();

//SetCallBack FUNCTION
		INT2_SetCallBack(&EX_FUNC);
while(1)
{

}


	return 0;
}
void EX_FUNC(void)
{
	LCD_VidWriteCommend(1);
	LCD_VidWriteString("GOOD JOB ELSAYED");
}
