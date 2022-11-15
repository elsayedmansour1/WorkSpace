/*
 * ball.c
 *
 *  Created on: May 18, 2022
 *      Author: elsay
 */

		 /*LIB*/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
		/*MCAL*/
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/UART/UART_Interface.h"
		/*hardware*/
#include "../HAL/LCD/LCD_Interface.h"
#include "ball.h"
#include "util/delay.h"
/*Global Variable definition*/
extern u8 curser;
extern u8  ball_down     [8];
extern u8 ball_catch	  [8];
void Player1_send_ball(u8 ball_row)
{
	if(ball_row==1)
		{
		while(curser<16)
		{
			LCD_VidWriteCommend(1);//clear LCD

			curser++;
			/*TO Send the Ball In first ROW row-->0*/
			LCD_VoidWriteSpecialCharacter(ball_down,1,0,curser);

			LCD_VoidWriteSpecialCharacter(ball_catch,2,0,0);

			_delay_ms(300);


		}
		}
	else if(ball_row==2)
	{
		while(curser<16)
		{
			LCD_VidWriteCommend(1);//clear LCD

			curser++;
			/*TO Send the Ball In first ROW row-->0*/
			LCD_VoidWriteSpecialCharacter(ball_down,1,1,curser);

			LCD_VoidWriteSpecialCharacter(ball_catch,2,1,0);

			_delay_ms(300);


		}
	}

}
void player1_receive_ball(u8 ball_row)
{
	if(ball_row==1)
	{
		while(curser>1)
		{
			LCD_VidWriteCommend(1);//clear LCD

			curser--;
			/*TO Send the Ball In first ROW row-->0*/
			LCD_VoidWriteSpecialCharacter(ball_down,1,0,curser);

			LCD_VoidWriteSpecialCharacter(ball_catch,2,0,0);

			_delay_ms(300);


		}
	}
	else if(ball_row==2)
	{
		while(curser>1)
		{
			LCD_VidWriteCommend(1);//clear LCD

			curser--;
			/*TO Send the Ball In second ROW row-->1*/
			LCD_VoidWriteSpecialCharacter(ball_down,1,1,curser);

			LCD_VoidWriteSpecialCharacter(ball_catch,2,1,0);

			_delay_ms(300);


		}
	}
}
