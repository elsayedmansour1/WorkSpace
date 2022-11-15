/*
 * TIMER1_Program.c
 *
 *  Created on: Jun 4, 2022
 *      Author: elsay
 */
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "TIMER1_Register.h"
#include "TIMER1_Interface.h"
#include "TIMER1_Config.h"
static void (*GPFunc_T1)(void)=NULL;
////////////////////////////////////////////////////
void TIMER1_OV_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T1=LocalPFunc;
}
void TIMER1_CM_A_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T1=LocalPFunc;
}
void TIMER1_CM_B_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T1=LocalPFunc;
}
////////////////////////////////////////////////////
////////////////////////////////////////////////////
ISR_TMR1_OVF()
{
	if(GPFunc_T1!=NULL)
		{
			GPFunc_T1();
		}
}
ISR_TMR1_CompA()
{
	if(GPFunc_T1!=NULL)
		{
			GPFunc_T1();
		}
}
ISR_TMR1_CompB()
{
	if(GPFunc_T1!=NULL)
		{
			GPFunc_T1();
		}
}
////////////////////////////////////////////////////
/*******************************************************************************************************/
void TIMER1_INIT(void)
{
#if Timer1_Mode==NORMAL_Timer_1

	NORMAL;
	prescaler_clk_8_1;
	Normal_port_operation_1;
	TCNT1=0;
	Overflow_Interrupt_Enable_1;
#elif Timer1_Mode==PWM_Phase_Correct_8_bit_Timer_1
#elif Timer1_Mode==PWM_Phase_Correct_9_bit_Timer_1
#elif Timer1_Mode==PWM_Phase_Correct_10_bit_Timer_1
#elif Timer1_Mode==CTC_1_Timer_1
	/*IN CTC MODE YOU CAN ONLY WORK WITH OCR1A
	 * YOU CAN'T WORK OUTPUT COMPARE MATCH B*/
	OCR1A=62500;
	CTC_1;
	prescaler_clk_8_1;
	Normal_port_operation_1;
	Compare_A_Match_Interrupt_Enable_1;
#elif Timer1_Mode==Fast_PWM_8_bit_Timer_1
#elif Timer1_Mode==Fast_PWM_9_bit_Timer_1
#elif Timer1_Mode==Fast_PWM_10_bit_Timer_1
#elif Timer1_Mode==PWM_Phase_and_Frequency_Correct_1_Timer_1
#elif Timer1_Mode==PWM_Phase_and_Frequency_Correct_2_Timer_1
#elif Timer1_Mode==PWM_Phase_Correct_0_Timer_1
#elif Timer1_Mode==PWM_Phase_Correct_1_Timer_1
#elif Timer1_Mode==CTC_2_Timer_1

#elif Timer1_Mode==Reserved_Timer_1
#elif Timer1_Mode==Fast_PWM_ICR1_Timer_1
	ICR1=19999;		// For 50 Hz for servo motor
	prescaler_clk_8_1;
	Fast_PWM_ICR1;
	PWM_Non_Inverted_1;
#elif Timer1_Mode==Fast_PWM_OCR1A_Timer_1
#else
#error "WRONG CHOOSE"
#endif

}
/********************************************************************************************************/
void TIMER1_Input_Capture_Enterrupt_Enable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
/********************************************************************************************************/
void Set_Duty_Cycle_TIMER_1_A(f32 percentage_Value)
{
#if Timer1_Mode==Normal_Timer1_Mode
	percentage_Value=percentage_Value/100;
	OCR1A=(percentage_Value*65535)-1;
#elif Timer1_Mode==Fast_PWM_8_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A=(percentage_Value*256)-1;
#elif Timer1_Mode==Fast_PWM_9_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A=(percentage_Value*512)-1;
#elif Timer1_Mode==Fast_PWM_10_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A=(percentage_Value*1024)-1;
#elif Timer1_Mode==Fast_PWM_ICR1_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A=(percentage_Value*ICR1)-1;
#else
#error "WRONG CHOOSE"

#endif

}
void Set_Duty_Cycle_TIMER_1_B(f32 percentage_Value)
{
#if Timer1_Mode==Normal_Timer1_Mode
	percentage_Value=percentage_Value/100;
	OCR1B=(percentage_Value*65535)-1;
#elif Timer1_Mode==Fast_PWM_8_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B=(percentage_Value*256)-1;
#elif Timer1_Mode==Fast_PWM_9_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B=(percentage_Value*512)-1;
#elif Timer1_Mode==Fast_PWM_10_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B=(percentage_Value*1024)-1;
#elif Timer1_Mode==Fast_PWM_ICR1_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B=(percentage_Value*ICR1)-1;
#else
#error "WRONG CHOOSE"

#endif

}
u16 Timer1_U16GetTCNT1Value(void)
{

	return TCNT1;
}
