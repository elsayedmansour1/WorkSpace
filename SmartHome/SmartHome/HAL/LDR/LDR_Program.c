/*
 * LDR_Program.c
 *
 *  Created on: May 27, 2022
 *      Author: elsay
 */

		 /*LIB*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
			/*MCAL*/
#include "../../MCAL/DIO/DIO_INT.h"
#include "../../MCAL/DIO/DIO_config.h"
#include "../../MCAL/Global Interrupt/GIE_INT.h"
#include "../../MCAL/ADC/ADC_INT.h"
		/*hardware*/



#include "util/delay.h"
#include "LDR_Interface.h"
extern u8 Flag;
u16 LDR_Value=0;

void LDR_u8Init(u8 Copy_u8DIO_Pin,void(*func)(void))
{
	GIE_Vid_Enable();
	DIO_VidSetPinDirection(DIO_PORTA,Copy_u8DIO_Pin,INPUT);
	ADC_SetCallBack(func);
	ADC_VidINIT();
	ADC_Interrupt_Enable();

}
u16 LDR_u8Channal(u8 Copy_u8Channal)
{

	Flag=2;
	ADC_Select_Channal(Copy_u8Channal);

	ADC_Start_Conversion();
	LDR_Value=LDR_Value/10;
	return LDR_Value;

}

