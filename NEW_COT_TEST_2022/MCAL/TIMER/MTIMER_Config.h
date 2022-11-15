/*
 * TIMER_CONFIG.h
 *
 *  Created on: May 1, 2022
 *      Author: elsay
 */

#ifndef MCAL_TIMER_MTIMER_CONFIG_H_
#define MCAL_TIMER_MTIMER_CONFIG_H_




/*make a readable name for every vector Peripherals number*/
/*start of vector table*/
#define ISR_TMR2_Comp()  void __vector_4(void)__attribute__((signal));\
	                     void __vector_4(void)
#define ISR_TMR2_OVF()   void __vector_5(void)__attribute__((signal));\
						 void __vector_5(void)

#define ISR_TMR1_Capt()  void __vector_6(void)__attribute__((signal));\
	                     void __vector_6(void)
#define ISR_TMR1_CompA() void __vector_7(void)__attribute__((signal));\
	                     void __vector_7(void)
#define ISR_TMR1_CompB() void __vector_8(void)__attribute__((signal));\
	                     void __vector_8(void)

#define ISR_TMR1_OVF()   void __vector_9(void)__attribute__((signal));\
	                     void __vector_9(void)

#define ISR_TMR0_Comp()  void __vector_10(void)__attribute__((signal));\
	                     void __vector_10(void)
#define ISR_TMR0_OVF()   void __vector_11(void)__attribute__((signal));\
	                     void __vector_11(void)
/*end of vector table*/

     /*ALL DEFINITIONS YOU WILL NEED IN TIMNER0 */
                  /*START_TIMER0*/
                /*MODES*/
#define Normal_0      	   			CLR_BIT(TCCR0, WGM01);\
									CLR_BIT(TCCR0, WGM00);

#define PWM_Phase_Correct_0  	    CLR_BIT(TCCR0, WGM01);\
									SET_BIT(TCCR0, WGM00);

#define CTC_Mode_0           		SET_BIT(TCCR0, WGM01);\
									CLR_BIT(TCCR0, WGM00);

#define Fast_PWM_0         			SET_BIT(TCCR0, WGM01);\
		                   	   	   	SET_BIT(TCCR0, WGM00);

#define Normal_Timer0_Mode                   0
#define PWM_Phase_Correct_Timer0_Mode        1
#define CTC_Timer0_Mode       				2
#define Fast_PWM_Timer0_Mode	 				3



/********************************/
#define Timer0_Mode  Fast_PWM_Timer0_Mode
/********************************/


/****************************************************************************************************************/
/****************************************************************************************************************/

    /*Compare Output Mode, non-PWM Mode*/
#define Non_PWM_Normal_OC0_disconnected_0         CLR_BIT(TCCR0,COM01);\
	                                    		  CLR_BIT(TCCR0,COM00);

#define Toggle_OC0_on_compare_match_0    		 CLR_BIT(TCCR0,COM01);\
												SET_BIT(TCCR0,COM00);

#define Clear_OC0_on_compare_match_0     		 SET_BIT(TCCR0,COM01);\
										  	  	  CLR_BIT(TCCR0,COM00);

#define Set_OC0_on_compare_match_0        		SET_BIT(TCCR0,COM01);\
												SET_BIT(TCCR0,COM00);
#define OC0_disconnected_Timer0     0
#define Toggle_OC0_Timer0           1
#define Clear_OC0_Timer0            2
#define Set_OC0_Timer0              3





/*********************************************/
#define Compare_Output_Mode_Timer0   OC0_disconnected_Timer0
/*********************************************/



/****************************************************************************************************************/
/****************************************************************************************************************/
             /*Compare Output Mode, Fast PWM Mode*/
#define Normal_OC0_disconnected_0        		          CLR_BIT(TCCR0,COM01);\
	                                                  	  CLR_BIT(TCCR0,COM00);

#define Reserved_0                                      CLR_BIT(TCCR0,COM01);\
	                                                  SET_BIT(TCCR0,COM00);

#define NonInverted_Mode_0     						  SET_BIT(TCCR0,COM01);\
	                                                  CLR_BIT(TCCR0,COM00);

#define Inverted_Mode_0       						  SET_BIT(TCCR0,COM01);\
	                                                  SET_BIT(TCCR0,COM00);

#define Normal_Mode_Timer0	                               0
#define reserved_mode_Timer0	                           1
#define NonInverted_Mode_Timer0	     			           2
#define Inverted_Mode_Timer0	        		           3





/*************************************/

#define Fast_PWM_MODE_0  NonInverted_Mode_Timer0

/************************************/


/****************************************************************************************************************/
/****************************************************************************************************************/

                    /*Clock Select*/
#define Timer_Counter stopped_0          		 CLR_BIT(TCCR0,CS02);\
	                                         CLR_BIT(TCCR0,CS01);\
					                         CLR_BIT(TCCR0,CS00);

#define No_prescaling_0                 	   	 CLR_BIT(TCCR0,CS02);\
											 CLR_BIT(TCCR0,CS01);\
											 SET_BIT(TCCR0,CS00);

#define prescaler_clk_8_0 	          		 CLR_BIT(TCCR0,CS02);\
	                                         SET_BIT(TCCR0,CS01);\
	                                         CLR_BIT(TCCR0,CS00);

#define prescaler_clk_64_0    			 	 CLR_BIT(TCCR0,CS02);\
	                                         SET_BIT(TCCR0,CS01);\
	                                         SET_BIT(TCCR0,CS00);

#define prescaler_clk_256_0   				 SET_BIT(TCCR0,CS02);\
	                                         CLR_BIT(TCCR0,CS01);\
	                                         CLR_BIT(TCCR0,CS00);

#define prescaler_clk_1024_0 	              	 SET_BIT(TCCR0,CS02);\
	                                         CLR_BIT(TCCR0,CS01);\
					                         SET_BIT(TCCR0,CS00);

#define External_Clock_on_falling_edge_0 	     SET_BIT(TCCR0,CS02);\
	                                         SET_BIT(TCCR0,CS01);\
					                         CLR_BIT(TCCR0,CS00);

#define External_Clock_on_rising_edge_0		 SET_BIT(TCCR0,CS02);\
	                                         SET_BIT(TCCR0,CS01);\
					                         SET_BIT(TCCR0,CS00);

#define 	Timer0_prescaler_0                   0
#define 	Timer0_prescaler_1                   1
#define 	Timer0_prescaler_8                   8
#define 	Timer0_prescaler_64                  64
#define 	Timer0_prescaler_256                 256
#define 	Timer0_prescaler_1024                1024
#define 	Timer0_External_falling_edge         2
#define   Timer0_External_rising_edge	       3




/****************************************/

#define clock_select_0  Timer0_prescaler_256

/****************************************/


/****************************************************************************************************************/
/****************************************************************************************************************/
                    /*INTERRUPT MODE*/
#define Compare_Match_Interrupt_Enable_0        SET_BIT(TIMSK,OCIE0);\
                                              CLR_BIT(TIMSK,TOIE0);

#define Overflow_Interrupt_Enable_0           CLR_BIT(TIMSK,OCIE0);\
                                              SET_BIT(TIMSK,TOIE0);

#define COM_Interrupt_Enable_Timer0    0
#define OVF_Interrupt_Enable_Timer0    1
/*********************************************/

#define INTERRUPT_MODE_TIMER_0  CM_Interrupt_Enable_Timer0

/*********************************************/
                     /*}END_TIMER0*/
    /*ALL DEFINITIONS YOU WILL NEED IN TIMNER1 */
                  /*START_TIMER1{*/

					/*MODES*/
/*Waveform Generation Mode Bit Description*/
#define NORMAL                                    CLR_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define PWM_Phase_Correct_8_bit                   SET_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define PWM_Phase_Correct_9_bit                   CLR_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define PWM_Phase_Correct_10_bit                  SET_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define CTC_1                                     CLR_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define Fast_PWM_8_bit                            SET_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define Fast_PWM_9_bit                            CLR_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define Fast_PWM_10_bit                           SET_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define PWM_Phase_and_Frequency_Correct_1         CLR_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define PWM_Phase_and_Frequency_Correct_2         SET_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define PWM_Phase_Correct_10                      CLR_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define PWM_Phase_Correct_11                      SET_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define CTC_2                                  	  CLR_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define Reserved                                  SET_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define Fast_PWM_ICR1                             CLR_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define Fast_PWM_OCRA1                            SET_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
											  	  SET_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define NORMAL_Timer_1                              		        0

#define PWM_Phase_Correct_8_bit_Timer_1                             1

#define PWM_Phase_Correct_9_bit_Timer_1                             2

#define PWM_Phase_Correct_10_bit_Timer_1                            3

#define CTC_1_Timer_1                                               4

#define Fast_PWM_8_bit_Timer_1                                      5

#define Fast_PWM_9_bit_Timer_1                                      6

#define Fast_PWM_10_bit_Timer_1                                     7

#define PWM_Phase_and_Frequency_Correct_1_Timer_1                   8

#define PWM_Phase_and_Frequency_Correct_2_Timer_1                   9

#define PWM_Phase_Correct_0_Timer_1									10

#define PWM_Phase_Correct_1_Timer_1									11

#define CTC_2_Timer_1                                               12

#define Reserved_Timer_1                                            13

#define Fast_PWM_ICR1_Timer_1                                          14

#define Fast_PWM_OCR1A_Timer_1                                          15

/********************************/
#define Timer1_Mode  Fast_PWM_ICR1_Timer_1
/********************************/


/****************************************************************************************************************/
/****************************************************************************************************************/

				/*Compare Output Mode, Non-PWM*/
#define Normal_port_operation_1       CLR_BIT(TCCR1A, COM1A0);\
	                                  CLR_BIT(TCCR1A, COM1A1);\
	                                  CLR_BIT(TCCR1A, COM1B0);\
	                                  CLR_BIT(TCCR1A, COM1B1);

#define Toggle_OC1A_OC1B_1            SET_BIT(TCCR1A, COM1A0);\
									  CLR_BIT(TCCR1A, COM1A1);\
	                            	  SET_BIT(TCCR1A, COM1B0);\
	                            	  CLR_BIT(TCCR1A, COM1B1);

#define Non_Inverted_1                CLR_BIT(TCCR1A, COM1A0);\
									  SET_BIT(TCCR1A, COM1A1);\
									  CLR_BIT(TCCR1A, COM1B0);\
									  SET_BIT(TCCR1A, COM1B1);

#define Inverted_1                    SET_BIT(TCCR1A, COM1A0);\
									  SET_BIT(TCCR1A, COM1A1);\
									  SET_BIT(TCCR1A, COM1B0);\
									  SET_BIT(TCCR1A, COM1B1);

#define Normal_port_operation_Timer1	0

#define Toggle_OC1A_OC1B_Timer1         1

#define Non_Inverted_Timer1             2

#define Inverted_Timer1                 3

/***********************************************/
#define Compare_Output_Mode  Non_Inverted_Timer1
/**********************************************/

/****************************************************************************************************************/
/****************************************************************************************************************/


			/*Compare Output Mode, Fast PWM*/
#define PWM_Normal_port_operation_1          CLR_BIT(TCCR1A, COM1A0);\
											 CLR_BIT(TCCR1A, COM1A1);\
											 CLR_BIT(TCCR1A, COM1B0);\
											 CLR_BIT(TCCR1A, COM1B1);

#define PWM_Toggle_OC1A_OC1B_1      		 SET_BIT(TCCR1A, COM1A0);\
											 CLR_BIT(TCCR1A, COM1A1);\
											 SET_BIT(TCCR1A, COM1B0);\
											 CLR_BIT(TCCR1A, COM1B1);

#define PWM_Non_Inverted_1           		 CLR_BIT(TCCR1A, COM1A0);\
											 SET_BIT(TCCR1A, COM1A1);\
											 CLR_BIT(TCCR1A, COM1B0);\
											 SET_BIT(TCCR1A, COM1B1);

#define PWM_Inverted_1              		 SET_BIT(TCCR1A, COM1A0);\
											 SET_BIT(TCCR1A, COM1A1);\
											 SET_BIT(TCCR1A, COM1B0);\
											 SET_BIT(TCCR1A, COM1B1);

#define PWM_Normal_port_operation_Timer1		  0

#define PWM_Toggle_OC1A_OC1B_Timer1               1

#define PWM_Non_Inverted_Timer1                   2

#define PWM_Inverted_Timer1                       3

/****************************************************/
#define PWM_Compare_Output_Mode  Non_Inverted_Timer1
/****************************************************/


/****************************************************************************************************************/
/****************************************************************************************************************/


/*Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM*/
#define PHC_PWM_Normal_port_operation_1         CLR_BIT(TCCR1A, COM1A0);\
												CLR_BIT(TCCR1A, COM1A1);\
												CLR_BIT(TCCR1A, COM1B0);\
												CLR_BIT(TCCR1A, COM1B1);

#define PHC_PWM_Toggle_OC1A_OC1B_1              SET_BIT(TCCR1A, COM1A0);\
												CLR_BIT(TCCR1A, COM1A1);\
												SET_BIT(TCCR1A, COM1B0);\
												CLR_BIT(TCCR1A, COM1B1);

#define PHC_PWM_Non_Inverted_1                  CLR_BIT(TCCR1A, COM1A0);\
												SET_BIT(TCCR1A, COM1A1);\
												CLR_BIT(TCCR1A, COM1B0);\
												SET_BIT(TCCR1A, COM1B1);

#define PHC_PWM_Inverted_1                      SET_BIT(TCCR1A, COM1A0);\
												SET_BIT(TCCR1A, COM1A1);\
												SET_BIT(TCCR1A, COM1B0);\
												SET_BIT(TCCR1A, COM1B1);

#define PHC_PWM_Normal_port_operation_Timer1	      0

#define PHC_PWM_Toggle_OC1A_OC1B_Timer1               1

#define PHC_PWM_Non_Inverted_Timer1                   2

#define PHC_PWM_Inverted_Timer1                       3

/****************************************************/
#define PHC_PWM_Compare_Output_Mode  Non_Inverted_Timer1
/****************************************************/

/****************************************************************************************************************/
/****************************************************************************************************************/

                    /*Clock Select*/
#define Timer_Counter_stopped_1          			  CLR_BIT(TCCR1B,CS12);\
	                                                  CLR_BIT(TCCR1B,CS11);\
	                                                  CLR_BIT(TCCR1B,CS10);

#define No_prescaling_1                 	   	 	  CLR_BIT(TCCR1B,CS12);\
													  CLR_BIT(TCCR1B,CS11);\
													  SET_BIT(TCCR1B,CS10);

#define prescaler_clk_8_1 	          				  CLR_BIT(TCCR1B,CS12);\
													  SET_BIT(TCCR1B,CS11);\
													  CLR_BIT(TCCR1B,CS10);

#define prescaler_clk_64_1    						  CLR_BIT(TCCR1B,CS12);\
	                                                  SET_BIT(TCCR1B,CS11);\
	                                                  SET_BIT(TCCR1B,CS10);

#define prescaler_clk_256_1   		                  SET_BIT(TCCR1B,CS12);\
													  CLR_BIT(TCCR1B,CS11);\
													  CLR_BIT(TCCR1B,CS10);

#define prescaler_clk_1024_1 	              	 	  SET_BIT(TCCR1B,CS12);\
													  CLR_BIT(TCCR1B,CS11);\
													  SET_BIT(TCCR1B,CS10);

#define External_Clock_on_falling_edge_1 	          SET_BIT(TCCR1B,CS12);\
	                                                  SET_BIT(TCCR1B,CS11);\
	                                                  CLR_BIT(TCCR1B,CS10);

#define External_Clock_on_rising_edge_1		 	      SET_BIT(TCCR1B,CS12);\
												   	  SET_BIT(TCCR1B,CS11);\
													  SET_BIT(TCCR1B,CS10);

#define 	Timer1_prescaler_0                   0
#define 	Timer1_prescaler_1                   1
#define 	Timer1_prescaler_8                   8
#define 	Timer1_prescaler_64                  64
#define 	Timer1_prescaler_256                 256
#define 	Timer1_prescaler_1024                1024
#define 	Timer1_External_falling_edge         2
#define   Timer1_External_rising_edge	     	 3




/****************************************/

#define clock_select_Timer1  Timer1_prescaler_256

/****************************************/

/****************************************************************************************************************/
/****************************************************************************************************************/


                    /*INTERRUPT MODE*/

#define Input_Capture_Interrupt_Enable          SET_BIT(TIMSK,TICIE1);

#define Compare_A_Match_Interrupt_Enable_1      SET_BIT(TIMSK,OCIE1A);


#define Compare_B_Match_Interrupt_Enable_1      SET_BIT(TIMSK,OCIE1B);


#define Overflow_Interrupt_Enable_1            	SET_BIT(TIMSK,TOIE1);


#define COM_Interrupt_Enable_Timer1    0
#define OVF_Interrupt_Enable_Timer1    1
/**********************************************/

#define INTERRUPT_MODE_Timer1  CM_Interrupt_Enable_Timer1

/*********************************************/
		/*}END_TIMER1*/

    /*ALL DEFINITIONS YOU WILL NEED IN TIMNER2 */
                  /*START_TIMER2{*/
                /*MODES*/
#define Normal_2      	     CLR_BIT(TCCR2, WGM21);\
	                         CLR_BIT(TCCR2, WGM20);

#define PWM_Phase_Correct_2  CLR_BIT(TCCR2, WGM21);\
	                         SET_BIT(TCCR2, WGM20);

#define CTC_Mode_2           SET_BIT(TCCR2, WGM21);\
	                         CLR_BIT(TCCR2, WGM20);

#define Fast_PWM_2           SET_BIT(TCCR2, WGM21);\
		                     SET_BIT(TCCR2, WGM20);

#define Normal_Timer2_Mode                   0
#define PWM_Phase_Correct_Timer2_Mode        1
#define CTC_Timer2_Mode       				2
#define Fast_PWM_Timer2_Mode	 				3



/********************************/
#define Timer2_Mode  Fast_PWM_Timer2_Mode
/********************************/


/****************************************************************************************************************/
/****************************************************************************************************************/

    /*Compare Output Mode, non-PWM Mode*/
#define Non_PWM_Normal_OC0_disconnected_2       CLR_BIT(TCCR2,COM21);\
	                                    CLR_BIT(TCCR2,COM20);

#define Toggle_OC0_on_compare_match_2   CLR_BIT(TCCR2,COM21);\
										SET_BIT(TCCR2,COM20);

#define Clear_OC0_on_compare_match_2    SET_BIT(TCCR2,COM21);\
										CLR_BIT(TCCR2,COM20);

#define Set_OC0_on_compare_match_2      SET_BIT(TCCR2,COM21);\
										SET_BIT(TCCR2,COM20);
#define OC0_disconnected_Timer2     0
#define Toggle_OC0_Timer2           1
#define Clear_OC0_Timer2            2
#define Set_OC0_Timer2              3





/*********************************************/
#define Compare_Output_Mode_Timer2 	OC0_disconnected_Timer2
/*********************************************/



/****************************************************************************************************************/
/****************************************************************************************************************/


				/*Compare Output Mode, Fast PWM Mode*/
#define Normal_OC0_disconnected_2        		      CLR_BIT(TCCR2,COM21);\
	                                                  CLR_BIT(TCCR2,COM20);

#define Reserved_2                                    CLR_BIT(TCCR2,COM21);\
	                                                  SET_BIT(TCCR2,COM20);

#define NonInverted_Mode_2     						  SET_BIT(TCCR2,COM21);\
	                                                  CLR_BIT(TCCR2,COM20);

#define Inverted_Mode_2       						  SET_BIT(TCCR2,COM21);\
	                                                  SET_BIT(TCCR2,COM20);

#define Normal_Mode_Timer2	                               0
#define reserved_mode_Timer2	                           1
#define NonInverted_Mode_Timer2	     			           2
#define Inverted_Mode_Timer2	        		           3





/*************************************/

#define Fast_PWM_MODE_2  NonInverted_Mode_Timer2

/************************************/


/****************************************************************************************************************/
/****************************************************************************************************************/

                    /*Clock Select*/
#define Timer_Counter_stopped_2              CLR_BIT(TCCR2,CS22);\
	                                         CLR_BIT(TCCR2,CS21);\
					                         CLR_BIT(TCCR2,CS20);

#define No_prescaling_2                 	 CLR_BIT(TCCR2,CS22);\
											 CLR_BIT(TCCR2,CS21);\
											 SET_BIT(TCCR2,CS20);

#define prescaler_clk_8_2 	          		 CLR_BIT(TCCR2,CS22);\
	                                         SET_BIT(TCCR2,CS21);\
	                                         CLR_BIT(TCCR2,CS20);

#define prescaler_clk_64_2    			 	 CLR_BIT(TCCR2,CS22);\
	                                         SET_BIT(TCCR2,CS21);\
	                                         SET_BIT(TCCR2,CS20);

#define prescaler_clk_256_2   				 SET_BIT(TCCR2,CS22);\
	                                         CLR_BIT(TCCR2,CS21);\
	                                         CLR_BIT(TCCR2,CS20);

#define prescaler_clk_1024_2	             SET_BIT(TCCR2,CS22);\
	                                         CLR_BIT(TCCR2,CS21);\
					                         SET_BIT(TCCR2,CS20);

#define External_Clock_on_falling_edge_2 	 SET_BIT(TCCR2,CS22);\
	                                         SET_BIT(TCCR2,CS21);\
					                         CLR_BIT(TCCR2,CS20);

#define External_Clock_on_rising_edge_2		 SET_BIT(TCCR2,CS22);\
	                                         SET_BIT(TCCR2,CS21);\
					                         SET_BIT(TCCR2,CS20);
#define 	Timer2_prescaler_0                   0
#define 	Timer2_prescaler_1                   1
#define 	Timer2_prescaler_8                   8
#define 	Timer2_prescaler_64                  64
#define 	Timer2_prescaler_256                 256
#define 	Timer2_prescaler_1024                1024
#define 	Timer2_External_falling_edge         2
#define     Timer2_External_rising_edge	      3




/****************************************/

#define clock_select_2  Timer2_prescaler_256

/****************************************/


/****************************************************************************************************************/
/****************************************************************************************************************/
                    /*INTERRUPT MODE*/
#define Compare_Match_Interrupt_Enable_2      SET_BIT(TIMSK,OCIE2);\
                                              CLR_BIT(TIMSK,TOIE2);

#define Overflow_Interrupt_Enable_2           CLR_BIT(TIMSK,OCIE2);\
                                              SET_BIT(TIMSK,TOIE2);

#define COM_Interrupt_Enable_Timer2    0
#define OVF_Interrupt_Enable_Timer2    1
/**********************************************/

#define INTERRUPT_MODETIMER_2  CM_Interrupt_Enable_Timer2

/*********************************************/
                     /*}END_TIMER2*/
#endif /* MCAL_TIMER_MTIMER_CONFIG_H_ */
