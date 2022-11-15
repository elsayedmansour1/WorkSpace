/*
 * main.c
 *
 *  Created on: May 18, 2022
 *      Author: elsay
 */
		 /*LIB*/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
		/*MCAL*/
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/UART/UART_Interface.h"
#include "../MCAL/External Interrupt/EX_INT_Int.h"
#include "../MCAL/Global Interrupt/GIE_INT.h"
		/*hardware*/
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/Key_pad/Keypad_Interface.h"
#include "util/delay.h"

#include "ball.h"

void ex_interruput0(void);
void ex_interruput1(void);
/*Global Variable definition*/
u8 curser=3;
u8  ball_down     [8]= { 0x00, 0x00,  0x00,  0x00,  0x0E,  0x1F,  0x1F,  0x0E   };
u8 ball_catch	  [8]={0x00,0x0E,0X0E,0X0E,0X04,0X04,0X00,0X00};
u8 score_player1=0;
u8 score_player2=0;
/*Variable definition*/
u8 output_keypad=0;
int main()
{
	/*Variable definition*/
u8 UART_receive=0;

	/*LCD INIT*/
LCD_VidInit();
/*enable global interrupt*/
	GIE_Vid_Enable();
	/*keypad init*/
//set direction of b2 in  portb as input
	DIO_VidSetPinDirection(DIO_PORTD,PIN2,INPUT);//int0
	DIO_VidSetPinDirection(DIO_PORTD,PIN3,INPUT);//int2
	/*eternal interrupt init*/

//activity pull up resistor
	DIO_VidSetPinValue(DIO_PORTD,PIN2,HIGH);
	DIO_VidSetPinValue(DIO_PORTD,PIN3,HIGH);
	 EX_INT0_INIT();

	 EX_INT1_INIT();
	/*set call back*/
	 INT0_SetCallBack(ex_interruput1);
	 INT1_SetCallBack(ex_interruput0);
	/*UART INIT*/
UART_INIT();

LCD_VidWriteString("WLECOME");
_delay_ms(1000);
LCD_VidWriteCommend(1);

while(1)
{
	if(output_keypad==1)
	{
		output_keypad=0;
		curser=0;
		/*player 1 send ball*/
		 Player1_send_ball(1);
		/*this state for transfer the ball to another screen*/
		if(curser==16)
		{
			UART_VoidSendChar('1');
			LCD_CLEAR(0,2,16);//clear LCD
			/*this state when micro2 send */
			UART_receive=UART_VoidGetChar();
			if(UART_receive=='1')//for row one
			{

				/*player 1 receive ball in row1*/
				 player1_receive_ball(1);

				 if(output_keypad==1)
				 {
					 output_keypad=0;
					 LCD_VoidWriteSpecialCharacter(ball_catch,2,0,0);
				 }
				 else if(output_keypad==2)
				 {
					 output_keypad=0;
					 LCD_VoidWriteSpecialCharacter(ball_catch,2,1,0);
					 score_player2++;
				 }
			}
			else if(UART_receive=='2')//for two two
			{
				/*player 1 receive ball in row2*/
				 player1_receive_ball(2);
			}
		}



	}

	if(output_keypad==2)
	{
		output_keypad=0;
		curser=0;
		/*player 1 receive ball in row1*/
		 Player1_send_ball(2);
		LCD_CLEAR(0,2,16);
		if(curser==16)
				{
					UART_VoidSendChar('1');
					LCD_CLEAR(0,2,16);//clear LCD
					/*this state when micro2 send */
					UART_receive=UART_VoidGetChar();
					if(UART_receive=='1')//for row one
					{
						/*player 1 receive ball in row1*/
						 player1_receive_ball(1);

						 if(output_keypad==1)
						 {
							 output_keypad=0;
							 LCD_VoidWriteSpecialCharacter(ball_catch,2,0,0);
						 }
						 else if(output_keypad==2)
						 {
							 output_keypad=0;
							 LCD_VoidWriteSpecialCharacter(ball_catch,2,1,0);
							 score_player2++;
						 }
					}
					else if(UART_receive=='2')//for two two
					{
						/*player 1 receive ball in row2*/
						 player1_receive_ball(2);
					}
				}
	}
}


	return 0;
}
void ex_interruput0(void)
{

 output_keypad=1;
}
void ex_interruput1(void)
{
	output_keypad=2;
}
