/*
 * main.c
 *
 *  Created on: May 21, 2022
 *      Author: elsayed mansour
 *      project: read pwm using ICU
 */

		 /*LIB*/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
		/*MCAL*/
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/UART/UART_Interface.h"
#include "../MCAL/Global Interrupt/GIE_INT.h"
#include "../MCAL/TIMER/TIMER_Interface.h"
#include "../MCAL/TIMER/TIMER1_Define.h"
		/*hardware*/
#include "../HAL/LCD/LCD_Interface.h"
#include "util/delay.h"

void ICU_func(void);
void timer1_OV(void);

volatile u16 ICR1_Value=0;
volatile u16 ICR2_Value=0;
volatile u16 ICR3_Value=0;
u8 Flag=0;
u8 OV=0;
int main()
{
	/*1-Variable definition*/
	u16 Ton=0;
	u16 Toff=0;
	//set pin direction
	DIO_VidSetPinDirection(DIO_PORTD,PIN7,OUTPUT);//PIN FOR PWM IN TIMER 1
	//set direction of PIN2 IN PORTD as input
	DIO_VidSetPinDirection(DIO_PORTD,PIN6,INPUT);
	//activity pull up resistor
	DIO_VidSetPinValue(DIO_PORTD,PIN6,HIGH);
	/*2-lcd initialization*/
	LCD_VidInit();
	LCD_VidWriteString("Welcome elsayed");
	_delay_ms(1000);
	/*3-global interrupt enable*/
	GIE_Vid_Enable();
	/*7-set call back function*/
	TIMER1_ICU_SetCallBack(ICU_func);
	TIMER1_OV_SetCallBack(timer1_OV);
	/*4-timer two initialization*/
	TIMER2_INIT();
	/*5-timer one initialization*/
	TIMER1_INIT();

	/*ICU edge select*/
	TIMER1_ICU_EdgeSelect(Rising_edge);

	/*8-ICU interrupt enable*/
	TIMER1_Input_Capture_Enterrupt_Enable();
	/*9-super loop*/
	while(1)
	{
		if(Flag==3)
		{
			/*6-set duty cycle of timer two*/
			Set_Duty_Cycle_TIMER_2(90);
			/*to clear lcd*/
			LCD_VidWriteCommend(1);
			Ton =(u8)ICR2_Value-(u8)ICR1_Value;
			Toff=(u8)ICR3_Value-(u8)ICR2_Value;
			LCD_VidWriteString("Ton=");
			LCD_VidWriteNumber((u8)Ton);
			LCD_GoToXY(1,0);
			LCD_VidWriteString("Toff=");
			LCD_VidWriteNumber((u8)Toff);
			_delay_ms(300);
			Flag=0;
			Ton=0;
			Toff=0;
		}
	}
	return 0;
}
void ICU_func(void)
{
	if(Flag==0)
	{
	ICR1_Value= Get_Value_From_ICREG();
	OV=0;
	Flag=1;
	TIMER1_ICU_EdgeSelect(Falling_edge);
	}
	else if(Flag==1)
	{
	ICR2_Value= Get_Value_From_ICREG()+OV*65535;
	OV=0;
	Flag=2;
	TIMER1_ICU_EdgeSelect(Rising_edge);
	}
	else if(Flag==2)
	{
	ICR3_Value= Get_Value_From_ICREG()+OV*65535;
	OV=0;
	Flag=3;
	}



}
void timer1_OV(void)
{
	OV++;
}
