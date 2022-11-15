/*
 * main.c
 *
 *  Created on: Apr 23, 2022
 *      Author: elsay
 */
/*introduction to this project
 * in this project i used external interrupt zero as a triggered for ADC Conversion
 * any change of the value of the switch the ADC will Start Conversion*/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/External Interrupt/EX_INT_Int.h"
#include "../MCAL/ADC/ADC_INT.h"
#include "../MCAL/Global Interrupt/GIE_INT.h"
#include <util/delay.h>
void FUNC_CONVERT(void);

//DECALARE VARIABLES
u16 ADC_DIGITAL_RES=10;
u16 ADC_ANALOG_RES=0;
int main()
{
	//dio set direction
	DIO_VidSetPinDirection(DIO_PORTD,PIN2,INPUT);
	//DIO SET PIN VALUE
	DIO_VidSetPinValue(DIO_PORTD,PIN2,HIGH);//PULL UP RESISTOR
	//Global Interrupt enable
	GIE_Vid_Enable();
	//LCD INIT
	LCD_VidInit();
	//LCD WRITE STRING
	LCD_VidWriteString("WELCOME ELSAYED");
	_delay_ms(1000);
	//EXTERNAL INTERRUPT INIT
	EX_INT0_INIT();
	//ADC INIT
	ADC_VidINIT();
	ADC_Select_Channal(7);
	//ADC INTERRUPT ENABLE
	ADC_Interrupt_Enable();
	ADC_SetCallBack(FUNC_CONVERT);
	//ADC_Start_Conversion();
	while(1)
	{


	}

	return 0;
}

void FUNC_CONVERT(void)
{
			//ADC GET ANALOGE VALUE
			ADC_Get_Result(&ADC_DIGITAL_RES);
			//CONVERT ANALOG VALUE TO DIGITAL with mV
			ADC_ANALOG_RES=(5000UL*ADC_DIGITAL_RES)>> 10;//( >> 10 = /1023 )
			//CLEAR LCD
			LCD_VidWriteCommend(1);
			//PRINT THE DIGITAL VALUE ON LCD
			LCD_GoToXY(0,0);
			LCD_VidWriteString("VOLT =");
			LCD_GoToXY(0,6);
			LCD_VidWriteNumber(ADC_ANALOG_RES);
			_delay_ms(500);
}
