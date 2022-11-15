/*
 * TOMER0_Register.h
 *
 *  Created on: Jun 4, 2022
 *      Author: elsay
 */

#ifndef SMARTHOME_MCAL_TIMER0_TIMER0_REGISTER_H_
#define SMARTHOME_MCAL_TIMER0_TIMER0_REGISTER_H_

             /*TIMER 0*/
#define TCCR0   *((volatile u8*)0x53)

#define TCNT0   *((volatile u8*)0x52)

#define OCR0   *((volatile u8*)0x5C)

#define TIFR   *((volatile u8*)0x58)

#define TIMSK   *((volatile u8*)0x59)

#endif /* SMARTHOME_MCAL_TIMER0_TIMER0_REGISTER_H_ */
