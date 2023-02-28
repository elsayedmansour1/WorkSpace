/*
 * osc.h
 *
 *  Created on: Feb 27, 2023
 *      Author: elsayedm
 */

#ifndef APP_OSC_H_
#define APP_OSC_H_

void Oscilloscope_init(void);

void Oscilloscope_Running(void);

u8 Oscilloscope_Start(u8 Copy_DIO_State);

u16 Oscilloscope_Stop(void);

u16 Osc_GetTime_ms(void);

#endif /* APP_OSC_H_ */
