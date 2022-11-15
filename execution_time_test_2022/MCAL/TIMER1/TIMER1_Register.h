/*
 * TOMER0_Register.h
 *
 *  Created on: Jun 4, 2022
 *      Author: elsay
 */

#ifndef SMARTHOME_MCAL_TIMER1_TIMER1_REGISTER_H_
#define SMARTHOME_MCAL_TIMER1_TIMER1_REGISTER_H_


#define TIMSK   *((volatile u8*)0x59)
            /*TIMER 1*/
#define TCCR1A   *((volatile u8*)0x4F)

#define TCCR1B   *((volatile u8*)0x4E)

#define TCNT1   *((volatile u16*)0x4C)

#define OCR1A   *((volatile u16*)0x4A)

#define OCR1B   *((volatile u16*)0x48)

#define ICR1    *((volatile u16*)0x46)


#endif /* SMARTHOME_MCAL_TIMER1_TIMER1_REGISTER_H_ */
