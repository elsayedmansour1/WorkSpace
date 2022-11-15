/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: elsay
 */

		 /*LIB*/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
		/*MCAL*/
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/ADC/ADC_INT.h"
#include "../MCAL/TWI/TWI_interface.h"
		/*hardware*/
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/Key_pad/Keypad_Interface.h"
#include "../HAL/EEPROM/EERPROM_interface.h"
#include "util/delay.h"


int main(void)
{

	/*u8 Anode[10]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

	u8 counter=0;
	DIO_VidSetPortDirection(DIO_PORTC,0xff);
	while(1)
	{
		DIO_VidSetPortValue(DIO_PORTC,cath[counter]<<2);
		_delay_ms(500);
		counter++;
		if(counter>7)
			counter=0;
	}*/


	u8 keypad_out=0;
	//u16 ADC_OUT=0,ANALOG_VALUE=0;
	u8 Data_EEPROM=0;
	u8 error=0;
	/*set SDA-->C1 &SCL-->C0 AS output */
	DIO_VidSetPinDirection(DIO_PORTC,PIN0,OUTPUT);//SCL
	DIO_VidSetPinDirection(DIO_PORTC,PIN1,OUTPUT);//SDA
	/*EEPROM initialization*/
	EEPROM_voidInit();
	/*LCD initialization*/
	LCD_VidInit();

	/*KEYPAD initialization*/
	KEYPAD_VidInit();
	//DIO_VidSetPinDirection(DIO_PORTA,PIN1,INPUT);
	//ADC_VidINIT();
	//ADC_Select_Channal(1);

	LCD_4Bits_DisplayString("WELCOME BACK");
	_delay_ms(1000);

	LCD_VoidClearDisplay();
	//ADC_Start_Conversion();

	while(1)
	{
		LCD_Vid4Bits_SetPosition(0,0);
		LCD_4Bits_DisplayString("SEND:");
		LCD_Vid4Bits_SetPosition(1,0);
		LCD_4Bits_DisplayString("Receive:");
		keypad_out=6;
		if(keypad_out!=0)
		{
			LCD_Vid4Bits_SetPosition(0,5);
			LCD_4Bits_VidWriteNumber(keypad_out);
			error=EEPROM_u8WriteDataByte(keypad_out,8);//send data that come from UART to Location -->5 In EEPROM.
			/*Get Data from EEPROM in selected location*/
			LCD_Vid4Bits_SetPosition(0,8);
			LCD_4Bits_VidWriteNumber(error);
			EEPROM_u8ReadDataByte(&Data_EEPROM,8);
			LCD_Vid4Bits_SetPosition(1,8);
			LCD_4Bits_VidWriteNumber(Data_EEPROM);
		}
		LCD_Vid4Bits_SetPosition(0,8);
					LCD_4Bits_VidWriteNumber(10);
	//	keypad_out=0;
		//ADC_Get_Result(&ADC_OUT);
		//ANALOG_VALUE=(ADC_OUT*5)/1023;
		//ANALOG_VALUE=(ANALOG_VALUE*100)/4;
		//LCD_4Bits_VidWriteNumber(ADC_OUT);
	//	_delay_ms(500);
	//	LCD_VoidClearDisplay();


	}



	return 0;
}
