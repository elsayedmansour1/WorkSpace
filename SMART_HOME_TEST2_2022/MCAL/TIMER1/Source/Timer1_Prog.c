/*
 * Timer0_Prog.c
 *
 *  Created on: Jan 30, 2022
 *      Author: kareem ashraf
 */


#include "../../../SERVICE/Bit_Math.h"
#include "../../../MCAL/DIO/Header/Dio_Interface.h"
#include "../../../MCAL/DIO/Header/Dio_Private.h"
#include "../Header/Timer1_Interface.h"
#include "../Header/Timer1_Config.h"
#include "../Header/Timer1_Private.h"


#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>	/* Include Delay header file */



static volatile void (*pointer_IC)(void) = NULL_Ptr  ;

void TIMER1_VoidInit()
{


#if TIMER1_MODE == Normal

#elif TIMER1_MODE == PWM_Phase_Correct_8_bit
				Set_Bit(TCCR1A,TCCR1A_WGM10);//FAST PWM ICR1


#elif TIMER1_MODE == PWM_Phase_Correct_9_bit
				Set_Bit(TCCR1A,TCCR1A_WGM11);//FAST PWM ICR1


#elif TIMER1_MODE == PWM_Phase_Correct_10_bit
				Set_Bit(TCCR1A,TCCR1A_WGM10);//FAST PWM ICR1
				Set_Bit(TCCR1A,TCCR1A_WGM11);//FAST PWM ICR1

#elif TIMER1_MODE == CTC_OCR1A
				Set_Bit(TCCR1B,TCCR1A_WGM11);//FAST PWM ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM12);//FAST PWM ICR1

#elif TIMER1_MODE == Fast_PWM_8_bit
				Set_Bit(TCCR1A,TCCR1A_WGM10);//FAST PWM ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM12);//FAST PWM ICR1

#elif TIMER1_MODE == Fast_PWM_9_bit
				Set_Bit(TCCR1A,TCCR1A_WGM11);//FAST PWM ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM12);//FAST PWM ICR1

#elif TIMER1_MODE == Fast_PWM_10_bit
				Set_Bit(TCCR1A,TCCR1A_WGM10);//FAST PWM ICR1
				Set_Bit(TCCR1A,TCCR1A_WGM11);//FAST PWM ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM12);//FAST PWM ICR1
#elif TIMER1_MODE == PWM_Phase_and_Frequency_Correct_ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM13);//FAST PWM ICR1


#elif TIMER1_MODE == PWM_Phase_and_Frequency_Correct_OCR1A
				Set_Bit(TCCR1A,TCCR1A_WGM10);//FAST PWM ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM13);//FAST PWM ICR1


#elif TIMER1_MODE == PWM_Phase_Correct_ICR1
				Set_Bit(TCCR1A,TCCR1A_WGM11);//FAST PWM ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM13);//FAST PWM ICR1


#elif TIMER1_MODE == PWM_Phase_Correct_OCR1A
				Set_Bit(TCCR1A,TCCR1A_WGM10);//FAST PWM OCR1A
				Set_Bit(TCCR1A,TCCR1A_WGM11);//FAST PWM OCR1A
				Set_Bit(TCCR1B,TCCR1B_WGM13);//FAST PWM OCR1A

#elif TIMER1_MODE == CTC_ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM12);//FAST PWM ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM13);//FAST PWM ICR1


#elif TIMER1_MODE == Reserved
				Set_Bit(TCCR1A,TCCR1A_WGM10);//FAST PWM ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM12);//FAST PWM ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM13);//FAST PWM ICR1

#elif TIMER1_MODE == Fast_PWM_ICR1
				Set_Bit(TCCR1A,TCCR1A_WGM11);//FAST PWM ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM12);//FAST PWM ICR1
				Set_Bit(TCCR1B,TCCR1B_WGM13);//FAST PWM ICR1

				OCR1AH =Time_On_Value>>Register_Time_On_Shift;
				OCR1AL =Time_On_Value;


			//Set_Bit(TCCR1B,TCCR1B_ICES1);//ICR1 Edge Select

#elif TIMER1_MODE == Fast_PWM_OCR1A
			Set_Bit(TCCR1A,TCCR1A_WGM10);//FAST PWM ICR1
			Set_Bit(TCCR1A,TCCR1A_WGM11);//FAST PWM ICR1
			Set_Bit(TCCR1B,TCCR1B_WGM12);//FAST PWM ICR1
			Set_Bit(TCCR1B,TCCR1B_WGM13);//FAST PWM ICR1

#endif

#if TIMER1_PRE == NO_PRE

	#elif TIMER1_PRE == PRE_1
	Set_Bit(TCCR1B,TCCR1B_CS10);

	#elif TIMER1_PRE == PRE_8
	Set_Bit(TCCR1B,TCCR1B_CS11);

	#elif TIMER1_PRE == PRE_64

	Set_Bit(TCCR1B,TCCR1B_CS10);
	Set_Bit(TCCR1B,TCCR1B_CS11);


	#elif TIMER1_PRE == PRE_256
	Set_Bit(TCCR1B,TCCR1B_CS12);

    #elif TIMER1_PRE == PRE_1024
	Set_Bit(TCCR1B,TCCR1B_CS10);
	Set_Bit(TCCR1B,TCCR1B_CS12);

    #elif TIMER1_PRE == PRE_ExternalClock_FallingEdge
	Set_Bit(TCCR1B,TCCR1B_CS11);
	Set_Bit(TCCR1B,TCCR1B_CS12);

    #elif TIMER1_PRE == PRE_ExternalClock_RisingEdge
	Set_Bit(TCCR1B,TCCR1B_CS10);
	Set_Bit(TCCR1B,TCCR1B_CS11);
	Set_Bit(TCCR1B,TCCR1B_CS12);

#endif




/*************************************************************/
#if   IC_OF_ON == IC_OFF


#elif IC_OF_ON == IC_ON

	DDRD_REG &=~ (1<<PIN_6   );  //INPUT PIN6 PPORT D INPUT CUPTHER

#endif

/**************************************************************/


/*************************************************************/
#if   IC_RISING_FALLING == READ_FALLING_IC


#elif IC_RISING_FALLING == READ_RASING_IC

      Set_Bit(TCCR1B,TCCR1B_ICES1);

#endif
/**************************************************************/

#if PIN_HARDWARE_DIRACTION == OUTPUT

	DDRD_REG |= (1<<PIN_5);    //IN

#elif PIN_HARDWARE_DIRACTION == INPUT
	DDRD_REG &=~ (1<<PIN_5   );    //IN

#endif

#if MODE_OF_INVERTAL == Non_invertal_mode

	Set_Bit(TCCR1A,TCCR1A_COM1A1); //Non invertal mode

#elif MODE_OF_INVERTAL == invertal_mode

	DDRA_REG &=~ (1<<PIN_3   );    //IN
#endif






#if TYPE_ISR == I_C_FLAG

	Set_Bit(TCCR1A,TCCR1A_COM1A1);//Non invertal mode

#elif TYPE_ISR == CTC_A_FLAG

	DDRA_REG &=~ (1<<PIN_3   );    //IN

#elif TYPE_ISR == CTC_B_FLAG

	DDRA_REG &=~ (1<<PIN_3   );    //IN

#elif TYPE_ISR == Overflow_ISR

	DDRA_REG &=~ (1<<PIN_3   );    //IN

#elif TYPE_ISR == ISR_OFF


#endif



#if TYPE_ISR == I_C_ISR

	Set_Bit(TCCR1A,TCCR1A_COM1A1);//Non invertal mode

#elif TYPE_ISR == CTC_A_ISR

	DDRA_REG &=~ (1<<PIN_3   );    //IN
#elif TYPE_ISR == CTC_B_ISR

	DDRA_REG &=~ (1<<PIN_3   );    //IN
#elif TYPE_ISR == Overflow_ISR

	DDRA_REG &=~ (1<<PIN_3   );    //IN

#elif TYPE_ISR == ISR_OFF

#endif

}

void TIMER1_VoidSetTCNT1(uint16 TIMER1_u8CopyTcntVal)
{
	TCNT1L = TIMER1_u8CopyTcntVal ;
}

void TIMER1_VoidClearTCNT1()
{
	TCNT1L = ZERO ;
}


void Duty_Cycle1(uint16 value)
{

	OCR1AH  = value >> 8;
	OCR1AL  = value ;

}


void TIMER1_ICR1H(int ICR1_H_VALUET)
{
	ICR1H = ICR1_H_VALUET>>Register_Time_On_Shift ; //Value of
	ICR1L = ICR1_H_VALUET ;

}






/************************************************************** ISR ****************************************************/


void __vector_6(void) __attribute__((signal)); //IC
void __vector_6(void)
{
  if( pointer_IC != NULL_Ptr )
  {
	  pointer_IC();
  }
}


void Set_Call_Back_IC(void (*pointer_Call_IC)(void))
{
	pointer_IC = pointer_Call_IC   ;
}




void Timer1_Fast_PWM_Init(unsigned short duty_cycle)
{
	//TCNT1 = 0;		/* Set timer1 initial count to zero */
	ICR1 = 19999;	/* Set TOP count for timer1 in ICR1 register */

	OCR1A = duty_cycle; /* Set the compare value */

	/* Configure timer control register TCCR1A
     * 1. Clear OC1A on compare match (non inverting mode) COM1A1=1 COM1A0=0
     * 2. Disconnect OC1B  COM1B0=0 COM1B1=0
     * 3. FOC1A=0 FOC1B=0 because these bits are only active in case non-pwm mode
     * 4. Fast Pwm Mode with the TOP in ICR1 WGM10=0 WGM11=1 (Mode Number 14)
	 */
	TCCR1A = (1<<WGM11) | (1<<COM1A1);

	/* Configure timer control register TCCR1A
	 * 1. Fast Pwm Mode with the TOP in ICR1 WGM12=1 WGM13=1 (Mode Number 14)
	 * 2. Prescaler = F_CPU/8
     */
	TCCR1B = (1<<WGM12) | (1<<WGM13) | (1<<CS11);
}




