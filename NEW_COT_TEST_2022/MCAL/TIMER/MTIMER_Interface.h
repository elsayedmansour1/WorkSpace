#ifndef _TCNT0_INTERFACE_H_
#define _TCNT0_INTERFACE_H_


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
             /*TCCR2*/
#define FOC2     7   //force output compare
#define WGM20    6   //waveform generation mode 20
#define COM21    5   //compare output mode 1
#define COM20    4   //compare output mode 0
#define WGM21    3   //waveform generation mode 21
#define CS22     2   //clock selection 22
#define CS21     1   //clock selection 21
#define CS20     0   //clock selection 20

/****************************************************************************************************************/
/****************************************************************************************************************/
/****************************************************************************************************************/
/****************************************************************************************************************/

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

                /*TCCR2*/
#define FOC2     7   //force output compare
#define WGM20    6   //waveform generation mode 20
#define COM21    5   //compare output mode 1
#define COM20    4   //compare output mode 0
#define WGM21    3   //waveform generation mode 21
#define CS22     2   //clock selection 22
#define CS21     1   //clock selection 21
#define CS20     0   //clock selection 20



/************************************************************************************************************************************/
/************************************************************************************************************************************/
/************************************************************************
 * the implementation for every set call back function i used in timers**
 * **********************************************************************
 */
		/***************************************
		 * set call back function of timer Zero*
		 ***************************************/
void TIMER0_OV_SetCallBack(void (*LocalPFunc)(void));
void TIMER0_CM_SetCallBack(void (*LocalPFunc)(void));
		/***************************************
		 * set call back function of timer One*
		 ***************************************/
void TIMER1_OV_SetCallBack(void (*LocalPFunc)(void));
void TIMER1_CM_A_SetCallBack(void (*LocalPFunc)(void));
void TIMER1_CM_B_SetCallBack(void (*LocalPFunc)(void));
		/***************************************
		 * set call back function of timer Two*
		 ***************************************/
void TIMER2_OV_SetCallBack(void (*LocalPFunc)(void));
void TIMER2_CM_SetCallBack(void (*LocalPFunc)(void));
/**************************************************************************
 * the implementation for every Initialization functions i used in timers**
 * ************************************************************************
 */
			/****************************************
			 * Initialization function of timer Zero*
			 ****************************************/
void TIMER0_INIT(void);
			/****************************************
			 * Initialization function of timer One*
			 ****************************************/
void TIMER1_INIT(void);
			/****************************************
			 * Initialization function of timer Two*
			 ****************************************/
void TIMER2_INIT(void);

/**************************************************************************
 * the implementation for every Set Duty Cycle functions i used in timers**
 * ************************************************************************
 */
			/****************************************
			 * Set Duty Cycle function of timer Zero*
			 ****************************************/
void Set_Duty_Cycle_TIMER_0(f32 percentage_Value);
			/*****************************************
			 * Set Duty Cycle function of timer One A*
			 *****************************************/
void Set_Duty_Cycle_TIMER_1_A(f32 percentage_Value);
			/*****************************************
			 * Set Duty Cycle function of timer One B*
			 *****************************************/
void Set_Duty_Cycle_TIMER_1_B(f32 percentage_Value);
			/****************************************
			 * Set Duty Cycle function of timer Two*
			 ****************************************/
void Set_Duty_Cycle_TIMER_2(f32 percentage_Value);
/**************************************************************************
 * the implementation ICU Interrupt Enable I used in timer1**
 * ************************************************************************
 */
void TIMER1_Input_Capture_Interrupt_Enable(void);
















#endif
