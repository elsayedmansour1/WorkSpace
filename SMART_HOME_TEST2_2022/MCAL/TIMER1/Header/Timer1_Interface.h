/*
 * Timer0_Interface.h
 *
 *  Created on: Jan 30, 2022
 *      Author: kareem ashraf
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

#include "Timer1_Config.h"
#include "Timer1_Private.h"

void TIMER1_VoidInit();
void TIMER1_VoidSetTCNT1(uint16 TIMER1_u8CopyTcntVal);
void TIMER1_VoidClearTCNT1();
void Duty_Cycle1(uint16 value);
void TIMER1_ICR1H(int ICR1_H_VALUET);

void Set_Call_Back_IC(void (*pointer_Call_IC)(void));

void Timer1_Fast_PWM_Init(unsigned short duty_cycle);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
