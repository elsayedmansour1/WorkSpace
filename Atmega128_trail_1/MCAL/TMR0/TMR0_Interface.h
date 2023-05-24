/*
 * TMR0.h
 *
 *  Created on: Feb 27, 2023
 *      Author: elsayedm
 */

#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_


		/***************************************
		 * set call back function of timer Zero*
		 ***************************************/
void TIMER0_OV_SetCallBack(void (*LocalPFunc)(void));
void TIMER0_CM_SetCallBack(void (*LocalPFunc)(void));
		/****************************************
		 * Initialization function of timer Zero*
		 ****************************************/
void TIMER0_INIT(void);
		/****************************************
		 * Set Duty Cycle function of timer Zero*
		 ****************************************/
void Set_Duty_Cycle_TIMER_0(f32 percentage_Value);

void TIMER1_Interrupt_Enable(void);

void TIMER1_Interrupt_Disable(void);

void TIMER0_Start(void);
#endif /* TMR0_INTERFACE_H_ */
