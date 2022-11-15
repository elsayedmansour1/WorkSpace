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

#include "../HAL/LCD/LCD_Interface.h"

#include "../HAL/EEPROM/EERPROM_interface.h"

#include "../MCAL/UART/UART_Interface.h"

#include "util/delay.h"

int main ()
{
	/*Variable initialization*/
	u8 Data=0;
	u8 UART_Value=0;
	/*set SDA-->C1 &SCL-->C0 AS output */
	DIO_VidSetPinDirection(DIO_PORTC,PIN0,OUTPUT);//SCL
	DIO_VidSetPinDirection(DIO_PORTC,PIN1,OUTPUT);//SDA
	/*LCD initialization*/
	LCD_VidInit();
	LCD_4Bits_DisplayString("WELCOME BACK");
	_delay_ms(1000);

	LCD_VoidClearDisplay();
	/*UART initialization*/
	//UART_INIT();
	/*EEPROM initialization*/
	EEPROM_voidInit();

	while(1)
	{
		//LCD_VidWriteCommend(1);
			LCD_Vid4Bits_SetPosition(0,0);
			LCD_4Bits_DisplayString("SEND:");
			LCD_Vid4Bits_SetPosition(1,0);
			LCD_4Bits_DisplayString("Receive:");
		UART_Value=5;
		EEPROM_u8WriteDataByte(UART_Value,5);//send data that come from UART to Location -->5 In EEPROM.
		LCD_Vid4Bits_SetPosition(0,5);
		LCD_4Bits_VidWriteNumber(UART_Value);
		/*Get Data from EEPROM in selected location*/
		EEPROM_u8ReadDataByte(&Data,5);
		LCD_Vid4Bits_SetPosition(1,8);
		LCD_4Bits_VidWriteNumber(Data);
	}

	return 0;
}
