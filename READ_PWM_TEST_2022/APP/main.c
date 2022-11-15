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
#include "../MCAL/External Interrupt/EX_INT_Int.h"
#include "../MCAL/TIMER/TIMER_Interface.h"
#include "../MCAL/External Interrupt/EX_INT_Config.h"
#include "util/delay.h"

//implementation of function
void timer2_func(void);
void exter_interrupt_func(void);
//global variable initialization
volatile u8 Ton=0;
volatile u8 Toff=0;
volatile u8 Flag=0;
volatile u8 OV=0;
int main()
{
	//enable global interrupt
	GIE_Vid_Enable();
	//set pin direction
	DIO_VidSetPinDirection(DIO_PORTD,PIN4,OUTPUT);//PIN FOR PWM IN TIMER 1
	//set direction of PIN2 IN PORTD as input
	DIO_VidSetPinDirection(DIO_PORTD,PIN2,INPUT);
	//activity pull up resistor
	DIO_VidSetPinValue(DIO_PORTD,PIN2,HIGH);
	//local variable initialization
	u8 Duty_Cycle=0;
	u8 Freq=0;
	//Use timer 1 as pwm generator
	TIMER1_INIT();
	//use timer 2 as counter
	TIMER2_INIT();
	TIMER2_OV_SetCallBack(timer2_func);
	//initialization of lcd
	LCD_VidInit();
	LCD_VidWriteString("welcome elsayed");
	_delay_ms(1000);
	//initialization of external interrupt 0
	EX_INT0_INIT_Test(Rising_Adge);//PIN
	INT0_SetCallBack(exter_interrupt_func);
	//super loop
	while(1)
	{
		Set_Duty_Cycle_TIMER_1_B(50);
		if(Flag==3)
		{
			LCD_VidWriteCommend(1);
			Duty_Cycle=(Ton/(Ton+Toff))*100;
			//Duty_Cycle=Duty_Cycle*100;
			Freq=1/(Ton+Toff);
			LCD_GoToXY(0,0);
			LCD_VidWriteString("Duty_Cycle=");
			//LCD_GoToXY(0,11);
			LCD_VidWriteNumber(Duty_Cycle);
			LCD_GoToXY(1,0);
			LCD_VidWriteString("Freq=");
			LCD_VidWriteNumber(Freq);
			_delay_ms(500);
			Ton=0;
			Toff=0;
			Flag=0;
		}
	}


	return 0;
}
void timer2_func(void)
{
	OV++;
}
void exter_interrupt_func(void)
{
	if(Flag==0)
	{
		Set_Get_TCNT_2();
		EX_INT0_INIT_Test(Falling_Adge);
		Flag=1;
	}
	else if(Flag==1)
	{
		Ton=Set_Get_TCNT_2()+OV*256;
		EX_INT0_INIT_Test(Rising_Adge);
		Flag=2;
		OV=0;
	}
	else if(Flag==2)
	{
		Toff=Set_Get_TCNT_2()+OV*256;
		Flag=3;
		OV=0;
	}
}
