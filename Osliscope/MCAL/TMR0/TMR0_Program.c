/*
 * TMR0.c
 *
 *  Created on: Feb 27, 2023
 *      Author: elsayedm
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TMR0_Config.h"
#include "TMR0_Interface.h"
#include "TMR0_Register.h"


/*Make a Global Function for every Set Call Back Function*/
static void (*GPFunc_T0)(void)=NULL;

/*Make a Set Call Back Function for every Interrupt peripherals in timer*/
			/*Set Call Back Functions for timer zero*/
void TIMER0_OV_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T0=LocalPFunc;
}
void TIMER0_CM_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T0=LocalPFunc;
}

ISR_TMR0_Comp()
{
	if(GPFunc_T0!=NULL)
	{
		GPFunc_T0();
	}
}
ISR_TMR0_OVF()
{
	if(GPFunc_T0!=NULL)
	{
		GPFunc_T0();
	}
}
void TIMER0_Start(void)
{
	TCNT0=0;

}

void TIMER0_INIT(void)
{
#if Timer0_Mode==Normal_Timer0_Mode
	TCNT0=192;                       //YOU SHOULD CHANGE THIS BIT
	Normal_0;
	prescaler_clk_8_0;
	Non_PWM_Normal_OC0_disconnected_0;
	Overflow_Interrupt_Enable_0;
#elif Timer0_Mode==CTC_Timer0_Mode
	OCR0=250;                     //YOU SHOULD CHANGE THIS BIT
	CTC_Mode_0;
	prescaler_clk_8_0;
	Non_PWM_Normal_OC0_disconnected_0;
	Compare_Match_Interrupt_Enable_0;
#elif Timer0_Mode==Fast_PWM_Timer0_Mode
	Fast_PWM_0;
	NonInverted_Mode_0;
	prescaler_clk_256_0;
#elif Timer0_Mode==PWM_Phase_Correct_Timer0_Mode
	PWM_Phase_Correct_0;
	prescaler_clk_256_0;

#else
#error "WRONG CHOOSE"
#endif

}
/********************************************************************************************************/
void TIMER1_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
/********************************************************************************************************/
void TIMER1_Interrupt_Disable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Set_Duty_Cycle_TIMER_0(f32 percentage_Value)
{
	percentage_Value=percentage_Value/100;
	OCR0=(percentage_Value*255)-1;

}
