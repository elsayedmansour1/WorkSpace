/*
 * TIMER2_Interface.h
 *
 *  Created on: Jun 4, 2022
 *      Author: elsay
 */

#ifndef SMARTHOME_MCAL_TIMER2_TIMER2_INTERFACE_H_
#define SMARTHOME_MCAL_TIMER2_TIMER2_INTERFACE_H_
             /*TCCR2*/
#define FOC2     7   //force output compare
#define WGM20    6   //waveform generation mode 20
#define COM21    5   //compare output mode 1
#define COM20    4   //compare output mode 0
#define WGM21    3   //waveform generation mode 21
#define CS22     2   //clock selection 22
#define CS21     1   //clock selection 21
#define CS20     0   //clock selection 20
            /*TIMSK REGISTER*/
#define OCIE2     7  //output compare Interrupt Enable in TIMER 2
#define TOIE2     6  //TIMER 2 overflow Interrupt Enable
#define TICIE1    5  //Input Capture Interrupt Enable in TIMER 1
#define OCIE1A    4  //output compare A Interrupt Enable in TIMER 1
#define OCIE1B    3  //output compare B Interrupt Enable in TIMER 1
#define TOIE1     2  //TIMER 1 overflow Interrupt Enable
#define OCIE0     1  //output compare Interrupt Enable in TIMER 0
#define TOIE0     0  //TIMER 0 overflow Interrupt Enable
/*******************************************************************************************************/
/*                                 Prototypes of the Timer driver                                      */
/*******************************************************************************************************/

class Timer2{
private:
	//private variable;
public:
	u8   MTMR_u8Timer2OVFSetCallBack(void(*LocalPFunc)(void));

	void MTMR_voidTimer2Init (void);

	u8   MTMR_u8Timer2GetCounterValue(u16 * Copy_pu16CounterValue);

	u8   MTMR_u8Timer2GeneratePWM(u8  Copy_u8DutyCycle);
};

#endif /* SMARTHOME_MCAL_TIMER2_TIMER2_INTERFACE_H_ */
