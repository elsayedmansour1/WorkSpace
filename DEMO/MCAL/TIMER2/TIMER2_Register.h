/*
 * TOMER2_Register.h
 *
 *  Created on: Jun 4, 2022
 *      Author: elsay
 */

#ifndef SMARTHOME_MCAL_TIMER2_TIMER2_REGISTER_H_
#define SMARTHOME_MCAL_TIMER2_TIMER2_REGISTER_H_

            /*TIMER 2*/
#define TCCR2   *((volatile u8*)0x45)

#define TCNT2   *((volatile u8*)0x44)

#define OCR2   *((volatile u8*)0x43)
#define TIFR   *((volatile u8*)0x58)
#define TIMSK   *((volatile u8*)0x59)

#endif /* SMARTHOME_MCAL_TIMER2_TIMER2_REGISTER_H_ */
