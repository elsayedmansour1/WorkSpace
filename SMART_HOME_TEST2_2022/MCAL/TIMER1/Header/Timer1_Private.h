/*
 * Timer0_Private.h
 *
 *  Created on: Jan 30, 2022
 *      Author: kareem ashraf
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_

#include "../../../SERVICE/Std_Types.h"

/**************** Clear TCNT0 *******************/
#define ZERO       0
/*************************************************/


/*************************************************/
#define Non_invertal_mode 1
#define invertal_mode     2
/*************************************************/

#define NULL_Ptr ((void*)0)

/**************************************************/
#define Time_On_Value  750
#define Register_Time_On_Shift 8
/**************************************************/

/**************************************************/
#define READ_FALLING_IC  1
#define READ_RASING_IC   2
/**************************************************/


/*************************************************/
#define OUTPUT 1
#define INPUT  2
/*************************************************/


/******************ISR MODE***********************/
#define  I_C_ISR         	1
#define  CTC_A_ISR  		2
#define  CTC_B_ISR 			3
#define  Overflow_ISR       4
#define  ISR_OFF 			5
/*******************FLAG MODE**********************/


/*************************************************/
#define  I_C_FLAG       			 1
#define  CTC_A_FLAG   	 			 2
#define  CTC_B_FLAG  		  		 3
#define  Overflow_FLAG 				 4
#define  FLAG_OFF 					 5
/*************************************************/


/*************************************************/
#define IC_ON 1
#define IC_OFF  2
/*************************************************/

/**************** TIMER MODES *******************/
#define Normal                        	    	1
#define PWM_Phase_Correct_8_bit 				2
#define PWM_Phase_Correct_9_bit 				3
#define PWM_Phase_Correct_10_bit 				4
#define CTC_OCR1A								5
#define Fast_PWM_8_bit 							6
#define Fast_PWM_9_bit 							7
#define Fast_PWM_10_bit 						8
#define PWM_Phase_and_Frequency_Correct_ICR1 	9
#define PWM_Phase_and_Frequency_Correct_OCR1A	10
#define PWM_Phase_Correct_ICR1 					11
#define PWM_Phase_Correct_OCR1A 				12
#define CTC_ICR1 								13
#define Reserved 							    14
#define Fast_PWM_ICR1 							15
#define Fast_PWM_OCR1A 							16
/*************************************************/


/***************** OC0 PIN MODE ******************/
#define OC1_LOW		1
#define OC1_HIGH	2
#define OC1_TOGGLE	3
#define OC1_OFF		4
/*************************************************/


/***************** PRESCALER VALUE ********************/
#define NO_PRE		  					1
#define	PRE_8							2
#define PRE_64							3
#define PRE_265							4
#define PRE_1024						5
#define PRE_ExternalClock_FallingEdge 	6
#define PRE_ExternalClock_RisingEdge 	7
/*******************************************************/



/*************************TCCR1A*************************/
#define TCCR1A   *( (volatile uint8*)0x4F)
       #define TCCR1A_COM1A1 7
       #define TCCR1A_COM1A0 6
       #define TCCR1A_COM1B1 5
       #define TCCR1A_COM1B0 4
       #define TCCR1A_FOC1A  3
       #define TCCR1A_FOC1B  2
       #define TCCR1A_WGM11  1
       #define TCCR1A_WGM10  0
/*//////////////////////////////////////////////////////*/


/*************************TCCR1B*************************/
#define TCCR1B   *( (volatile uint8*)0x4E)

       #define TCCR1B_ICNC1 7
       #define TCCR1B_ICES1 6
       //bit5   Reserved
       #define TCCR1B_WGM13 4
       #define TCCR1B_WGM12 3
       #define TCCR1B_CS12  2
       #define TCCR1B_CS11  1
       #define TCCR1B_CS10  0

/*//////////////////////////////////////////////////////*/

/*************************TIMSK*************************/
#define	TIMSK *( (volatile uint8*)0x59)

       #define TIMSK_OCIE2  7
       #define TIMSK_TOIE2  6
       #define TIMSK_TICIE1 5
       #define TIMSK_OCIE1A 4
       #define TIMSK_OCIE1B 3
       #define TIMSK_TOIE1  2
       #define TIMSK_OCIE0  1
       #define TIMSK_TOIE0  0

/*//////////////////////////////////////////////////////*/

/**************************TIFR**************************/
#define	TIFR  *( (volatile uint8*)0x58)

       #define TIFR_OCF2  7
       #define TIFR_TOV2  6
       #define TIFR_ICF1  5
       #define TIFR_OCF1A 4
       #define TIFR_OCF1B 3
       #define TIFR_TOV1  2
       #define TIFR_OCF0  1
       #define TIFR_TOV0  0

/*//////////////////////////////////////////////////////*/

/*************************TCNT1 ( H - L )****************/
#define TCNT1H *( (volatile uint8*)0x4D)
#define	TCNT1L *( (volatile uint8*)0x4C)
/*//////////////////////////////////////////////////////*/

/*************************OCR1A ( H - L )****************/
#define	OCR1AH *( (volatile uint8*)0x4B)
#define	OCR1AL *( (volatile uint8*)0x4A)
/*//////////////////////////////////////////////////////*/

/*************************OCR1B ( H - L )****************/
#define	OCR1BH *( (volatile uint8*)0x49)
#define	OCR1BL *( (volatile uint8*)0x48)
/*//////////////////////////////////////////////////////*/

/*************************ICR1  ( H - L )****************/
#define	ICR1H  *( (volatile uint8*)0x47)
#define	ICR1L  *( (volatile uint8*)0x46)
#define	ICR1ALL  *( (volatile uint16*)0x46)
/*//////////////////////////////////////////////////////*/



#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
