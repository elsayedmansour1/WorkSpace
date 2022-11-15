/*
 * main.c
 *
 *  Created on: Apr 20, 2022
 *      Author: elsay
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD/LCD_Interface.h"
#include <util/delay.h>


int main()
{

	LCD_VidInit();
	LCD_VidWriteString("Welcome At 2022");

	LCD_GoToXY(1,0);

	LCD_VidWriteString(" START THE GAME");
	LCD_VidWriteCommend(1);
	LCD_VidWriteNumber(300300);
    while(1)
    {

    }
	return 0;
}
