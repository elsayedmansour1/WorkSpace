/*
 * TIMER2_Program.c
 *
 *  Created on: Jun 4, 2022
 *      Author: elsay
 */
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "TIMER2_Register.h"
#include "TIMER2_Interface.h"
#include "TIMER2_Config.h"

/*******************************************************************************************************/
/*                                 Global Pointer To Function                                          */
/*******************************************************************************************************/
static void (*TMR_pfTimer2OVF)(void) = NULL;

u8   Timer2 :: MTMR_u8Timer2OVFSetCallBack(void(*LocalPFunc)(void))
{
	u8 Local_u8_ErrorState = STD_TYPES_OK;
	if(LocalPFunc != NULL)
	{
		TMR_pfTimer2OVF = LocalPFunc;
	}
	else
	{
		Local_u8_ErrorState =STD_TYPES_NOK;
	}
	return Local_u8_ErrorState;
}
ISR_TMR2_OVF()
{
	if(TMR_pfTimer2OVF!=NULL)
	{
		TMR_pfTimer2OVF();
	}
}
void Timer2 ::MTMR_voidTimer2Init (void)
{
#if Timer2_Mode==Normal_Timer2_Mode
	TCNT2=192;                              //YOU SHOULD CHANGE THIS BIT
	Normal_2;
	prescaler_clk_8_2;
	Non_PWM_Normal_OC0_disconnected_2;
	Overflow_Interrupt_Enable_2;
#elif Timer2_Mode==CTC_Timer2_Mode
	OCR2=250;                     //YOU SHOULD CHANGE THIS BIT
	CTC_Mode_2;
	prescaler_clk_8_2;
	Non_PWM_Normal_OC0_disconnected_2;
	Compare_Match_Interrupt_Enable_2;
#elif Timer2_Mode==Fast_PWM_Timer2_Mode
	Fast_PWM_2;
	NonInverted_Mode_2;
	prescaler_clk_256_2;
#elif Timer2_Mode==PWM_Phase_Correct_Timer2_Mode
	PWM_Phase_Correct_2;
	prescaler_clk_256_2;

#else
#error "WRONG CHOOSE"

#endif
}

u8  Timer2 :: MTMR_u8Timer2GetCounterValue(u16 * Copy_pu16CounterValue)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu16CounterValue != NULL)
	{
		*Copy_pu16CounterValue = TCNT2;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}
void MTMR_voidTimer2SetCompareMatchValue(u8 Copy_u8OCRValue)
{
	OCR2 = Copy_u8OCRValue;
}
u8   Timer2 :: MTMR_u8Timer2GeneratePWM(u8  Copy_u8DutyCycle)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8DutyCycle = 0 ;
	if(Copy_u8DutyCycle <= 100)
	{
		Local_u8DutyCycle = (u8)((Copy_u8DutyCycle*256UL)/100) ;
		MTMR_voidTimer2SetCompareMatchValue(Local_u8DutyCycle);

	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;

}
