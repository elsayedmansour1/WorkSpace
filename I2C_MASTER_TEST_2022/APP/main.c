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
	u8 error;
	/*set SDA-->C1 &SCL-->C0 AS output */
	DIO_VidSetPinDirection(DIO_PORTC,PIN0,OUTPUT);//SCL
	DIO_VidSetPinDirection(DIO_PORTC,PIN1,OUTPUT);//SDA
	/*LCD initialization*/
	LCD_VidInit();
	LCD_4Bits_DisplayString("I'M the Master");
	_delay_ms(1000);
	LCD_4Bits_VoidClearDisplay();
	/*TWI initialization as a master*/
	TWI_voidMasterInit();

	while(1)
	{
		/* Start Condition */
		error=TWI_enuSendStartCondition();
		LCD_4Bits_VidWriteNumber(error);
		/* Send Slave Address with Write Bit */
		error=TWI_enuSendSlaveWithWrite(0x01);
		LCD_4Bits_VidWriteNumber(error);
		/* Send The Data Byte */
		error=TWI_enuSendDataByte('a');
		LCD_4Bits_VidWriteNumber(error);
		/* Send Stop Condition */
		TWI_voidSendStopCondition();
		/*send the same data to LCD*/
		LCD_4Bits_DisplayCharacter('a');
		_delay_ms(5000);
	}

	return 0;
}
