/*
 * asc.c
 *
 *  Created on: Feb 27, 2023
 *      Author: elsayedm
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/TMR0/TMR0_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "Osc.h"


u8 DIO_State=0;
u16 Counter_Value;
static u16 Counter=0;
void Oscilloscope_init()
{
	TIMER0_INIT();

	GIE_Vid_Enable();

	TIMER0_CM_SetCallBack(Oscilloscope_Running);

}

u8 Oscilloscope_Start(u8 Copy_DIO_State)
{
	if(!Copy_DIO_State && !DIO_State)
	{
		TIMER0_Start();
		DIO_State=1;
		Counter=0;
	}
	else
	{

	}
	return DIO_State;
}
void Oscilloscope_Running()
{
	Counter++;
}

u16 Oscilloscope_Stop(void)
{
	DIO_State=0;
	Counter_Value=Counter;
	Counter=0;
	return Counter_Value;
}
u16 Osc_GetTime_ms(void)
{
	u16 Num_count=Oscilloscope_Stop();
	u32 time=((Num_count*250UL)/1000)*1.29;// error =29%

	return ((u16)time);
}
