/*
 * TIMER1_Interface.h
 *
 *  Created on: Jun 4, 2022
 *      Author: elsay
 */

#ifndef SMARTHOME_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define SMARTHOME_MCAL_TIMER1_TIMER1_INTERFACE_H_

/*Timer/Counter1 Control Register A  TCCR1A*/
#define COM1A1   7
#define COM1A0   6
#define COM1B1   5
#define COM1B0   4
#define FOC1A    3
#define FOC1B    2
#define WGM11    1
#define WGM10    0

/*Timer/Counter1 Control Register B TCCR1B*/
#define ICNC1     7
#define ICES1     6
#define WGM13     4
#define WGM12     3
#define CS12      2
#define CS11      1
#define CS10      0
/****************************************************************************************************************/
            /*TIMSK REGISTER*/
#define OCIE2     7  //output compare Interrupt Enable in TIMER 2
#define TOIE2     6  //TIMER 2 overflow Interrupt Enable
#define TICIE1    5  //Input Capture Interrupt Enable in TIMER 1
#define OCIE1A    4  //output compare A Interrupt Enable in TIMER 1
#define OCIE1B    3  //output compare B Interrupt Enable in TIMER 1
#define TOIE1     2  //TIMER 1 overflow Interrupt Enable
#define OCIE0     1  //output compare Interrupt Enable in TIMER 0
#define TOIE0     0  //TIMER 0 overflow Interrupt Enable

/****************************************************************************************************************/
void TIMER1_OV_SetCallBack(void (*LocalPFunc)(void));
void TIMER1_CM_A_SetCallBack(void (*LocalPFunc)(void));
void TIMER1_CM_B_SetCallBack(void (*LocalPFunc)(void));

void TIMER1_INIT(void);

void Set_Duty_Cycle_TIMER_1_A(f32 percentage_Value);
void Set_Duty_Cycle_TIMER_1_B(f32 percentage_Value);

void TIMER1_Input_Capture_Enterrupt_Enable(void);

u16 Timer1_U16GetTCNT1Value(void);
#endif /* SMARTHOME_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
