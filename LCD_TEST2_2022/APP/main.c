/*
 * main.c
 *
 *  Created on: May 14, 2022
 *      Author: elsay
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../HAL/LCD/LCD_Interface.h"

#include "util/delay.h"



int main()
{
		LCD_VidInit();
		LCD_VidWriteString("welcome 2elsayed");
		while(1)
		{

		}
return 0;
}
