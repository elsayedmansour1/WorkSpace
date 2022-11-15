/*
 * main.c
 *
 *  Created on: May 16, 2022
 *      Author: elsay
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/TWI/TWI_interface.h"

#include "../HAL/LCD/LCD_Interface.h"


#include "util/delay.h"

int main ()
{
	/*Variable initialization*/
	u8 Data_Receive=0;
	/*set SDA-->C1 &SCL-->C0 AS input */
	DIO_VidSetPinDirection(DIO_PORTC,PIN0,INPUT);//SCL
	DIO_VidSetPinDirection(DIO_PORTC,PIN1,INPUT);//SDA
	/*LCD initialization*/
	LCD_VidInit();
	LCD_4Bits_DisplayString("I'M the Slave");
	_delay_ms(1000);
	LCD_4Bits_VoidClearDisplay();
	/*TWI initialization as a slave*/
	TWI_u8SlaveInit(0x01);

	while(1)
	{
		TWI_enuReceiveDataByte(&Data_Receive);
		/*send the same data to LCD*/
		LCD_4Bits_DisplayString(&Data_Receive);
		_delay_ms(5000);
	}

	return 0;
}
