/*
 * Timer0_Config.h
 *
 *  Created on: Jan 30, 2022
 *      Author: kareem ashraf
 */

#ifndef MCAL_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER0_TIMER0_CONFIG_H_



#include "Timer1_Private.h"

/**************** TIMER0 CONFIGURATIONS **************/

/*************************************************/
#define ICR1_H_VALUE 		2000
#define ICR1_L_VALUE 		2000
#define Shift_HIGH_VALUE    8
/*************************************************/


/*************************************************/
#define TYPE_ISR  ISR_OFF
/*************************************************/

/*************************************************/
#define TYPE_FLAG  ISR_OFF
/*************************************************/

/*************************************************/

#define IC_RISING_FALLING      READ_RASING_IC

/*************************************************/

/*************************************************/
#define IC_OF_ON     IC_OFF
/*************************************************/

/*************************************************/

#define TIMER1_MODE		          Fast_PWM_ICR1
#define MODE_OF_INVERTAL          Non_invertal_mode

/*************************************************/
#define TIMER1_OC_MODE	            OC1_LOW
#define TIMER1_PRE_LOAD             192
#define TIMER1_PRE		            PRE_64

#define TIMER1_NUMBER_OF_CTC        4000
#define TIMER1_NUMBER_OFOVERFLOWS   3907

#define OCR1_VALUE                  50

#define PIN_HARDWARE_DIRACTION       OUTPUT


/**************************************************/



#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
