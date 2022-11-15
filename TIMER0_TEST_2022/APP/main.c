/*
 * main.c
 *
 *  Created on: May 1, 2022
 *      Author: elsay
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/Global Interrupt/GIE_INT.h"
#include "../MCAL/TIMER/TIMER_Interface.h"
#include "util/delay.h"






void func_T0(void);
void func_T1(void);
void func_T2(void);

void LCD_Play(void);
void LCD_Play2(void);
u8 count_T0=0;
u8 count_T2=255;
int main()
{
	//Variable Definition
	//u8 count=0;
	//Global Interrupt Enable
	GIE_Vid_Enable();
	//LCD Initialization
	LCD_VidInit();
	LCD_VidWriteString("WELCOME ELSAYED");
	_delay_ms(1000);
	LCD_VidWriteCommend(1);
	//Set Call Back
	//TIMER0_CM_SetCallBack(func_T0);
	TIMER1_CM_A_SetCallBack(func_T1);
	//TIMER2_CM_SetCallBack(func_T0);
	//Timer Zero Initialization
	//TIMER0_INIT();
	TIMER1_INIT();
	//TIMER2_INIT();

	//Super Loop
	while(1)
	{

	}
	return 0;
}
void func_T0(void)
{
	static u16 counter=0;
	if(counter==4000)
	{
		LCD_Play();
		counter=0;
		count_T0++;
	}
	counter++;
}
void func_T1(void)
{
	static u16 counter=0;
	if(counter==15)
	{
		LCD_Play1();
		counter=0;
		count_T0++;
	}
	counter++;
}
void func_T2(void)
{
	static u16 counter2=0;
	if(counter2==3907)
	{
		LCD_Play2();
		counter2=0;
		count_T2--;
	}
	counter2++;
}
void LCD_Play(void)
{
	LCD_GoToXY(0,0);
	LCD_VidWriteString("COUNT0=");
	LCD_GoToXY(0,7);
	LCD_VidWriteNumber(count_T0);
	if(count_T0>255)
	{
		LCD_VidWriteCommend(1);
	}
}
void LCD_Play1(void)
{
	LCD_GoToXY(0,0);
	LCD_VidWriteString("COUNT1=");
	LCD_GoToXY(0,7);
	LCD_VidWriteNumber(count_T0);
	if(count_T0>255)
	{
		LCD_VidWriteCommend(1);
	}
}
void LCD_Play2(void)
{
	LCD_GoToXY(1,0);
	LCD_VidWriteString("COUNT2=");
	LCD_GoToXY(1,7);
	LCD_VidWriteNumber(count_T2);
}
