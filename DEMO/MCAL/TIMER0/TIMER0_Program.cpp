/*
 * TIMER0_Program.c
 *
 *  Created on: Jun 4, 2022
 *      Author: elsay
 */
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "TIMER0_Register.h"
#include "TIMER0_Interface.h"
#include "TIMER0_Config.h"
/*******************************************************************************************************/
/*                                 Global Pointer To Function                                          */
/*******************************************************************************************************/
static void (*TMR_pfTimer0OVF)(void) = NULL;


/*#####################################################################################################*/

u8 Timer0 :: MTMR_u8Timer0OVFSetCallBack(void (*LocalPFunc)(void))
{
	u8 Local_u8_ErrorState = STD_TYPES_OK;
	if(LocalPFunc != NULL)
	{
		TMR_pfTimer0OVF = LocalPFunc;
	}
	else
	{
		Local_u8_ErrorState =STD_TYPES_NOK;
	}
	return Local_u8_ErrorState;
}

ISR_TMR0_OVF()
{
	if(TMR_pfTimer0OVF!=NULL)
	{
		TMR_pfTimer0OVF();
	}
}


////////////////////////////////////////////////////
void Timer0 :: MTMR_voidTimer0Init (void)
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
u8  Timer0 ::  MTMR_u8Timer0GetCounterValue(u16 * Copy_pu16CounterValue)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu16CounterValue != NULL)
	{
		*Copy_pu16CounterValue = TCNT0;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}
void MTMR_voidTimer0SetCompareMatchValue(u8 Copy_u8OCRValue)
{
	OCR0 = Copy_u8OCRValue;
}
u8   Timer0 :: MTMR_u8Timer0GeneratePWM(u8  Copy_u8DutyCycle)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8DutyCycle = 0 ;
	if(Copy_u8DutyCycle <= 100)
	{
		Local_u8DutyCycle = (u8)((Copy_u8DutyCycle*256UL)/100) ;
		MTMR_voidTimer0SetCompareMatchValue(Local_u8DutyCycle);

	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;

}
/*******************************************************************************************************/
