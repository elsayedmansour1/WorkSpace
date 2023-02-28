/*
 * TMR0_Register.h
 *
 *  Created on: Feb 27, 2023
 *      Author: elsayedm
 */

#ifndef TMR0_REGISTER_H_
#define TMR0_REGISTER_H_

                /*TCCR0 REGISTER*/
#define FOC0      7 //force output compare

#define WGM00     6 //waveform generation mode 00
#define WGM01     3 //waveform generation mode 01

#define COM01     5 //compare output mode 1
#define COM00     4 //compare output mode 0

#define CS02      2 //clock selection 02
#define CS01      1 //clock selection 01
#define CS00      0 //clock selection 00

            /*TIMSK REGISTER*/
#define OCIE2     7  //output compare Interrupt Enable in TIMER 2
#define TOIE2     6  //TIMER 2 overflow Interrupt Enable
#define TICIE1    5  //Input Capture Interrupt Enable in TIMER 1
#define OCIE1A    4  //output compare A Interrupt Enable in TIMER 1
#define OCIE1B    3  //output compare B Interrupt Enable in TIMER 1
#define TOIE1     2  //TIMER 1 overflow Interrupt Enable
#define OCIE0     1  //output compare Interrupt Enable in TIMER 0
#define TOIE0     0  //TIMER 0 overflow Interrupt Enable

             /*TIMER 0*/
#define TCCR0   *((volatile u8*)0x53)

#define TCNT0   *((volatile u8*)0x52)

#define OCR0   *((volatile u8*)0x5C)

#define TIFR   *((volatile u8*)0x58)

#define TIMSK   *((volatile u8*)0x59)

#endif /* TMR0_REGISTER_H_ */
