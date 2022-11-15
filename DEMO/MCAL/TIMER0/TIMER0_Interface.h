/*
 * TIMER0_Interface.h
 *
 *  Created on: Jun 4, 2022
 *      Author: elsay
 */

#ifndef SMARTHOME_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define SMARTHOME_MCAL_TIMER0_TIMER0_INTERFACE_H_

                /*TCCR0 REGISTER*/
#define FOC0      7 //force output compare

#define WGM00     6 //waveform generation mode 00
#define WGM01     3 //waveform generation mode 01

#define COM01     5 //compare output mode 1
#define COM00     4 //compare output mode 0

#define CS02      2 //clock selection 02
#define CS01      1 //clock selection 01
#define CS00      0 //clock selection 00
/****************************************************************************************************************/
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
/****************************************************************************************************************/

/*******************************************************************************************************/
/*                                 Prototypes of the Timer driver                                      */
/*******************************************************************************************************/
class Timer0{
private:
	//private variable;
public:
	u8 MTMR_u8Timer0OVFSetCallBack(void (*LocalPFunc)(void));

	void MTMR_voidTimer0Init (void);

	u8   MTMR_u8Timer0GetCounterValue(u16 * Copy_pu16CounterValue);

	u8   MTMR_u8Timer0GeneratePWM(u8  Copy_u8DutyCycle);
};



#endif /* SMARTHOME_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
