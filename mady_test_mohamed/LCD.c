#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "avr/delay.h"







void LCD_voidWriteCommand(u8 Copy_u8command)
{
	
	DIO_voidSetPinValue(RS,LOW);
   
	DIO_voidSetPinValue(RW,LOW);
	
	SetPortValue(PORTC,Copy_u8command);
	
	DIO_voidSetPinValue(Enable,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(Enable,LOW);
	_delay_ms(1);
	
}


void LCD_voidWriteData(u8 Copy_u8Data)
{
	
	DIO_voidSetPinValue(RS,HIGH);
   
	DIO_voidSetPinValue(RW,LOW);
	
	SetPortValue(PORTC,Copy_u8Data);
	
	DIO_voidSetPinValue(Enable,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(Enable,LOW);
	_delay_ms(1);
	
}


void LCD_voidInit(void)
{
	
	
	_delay_ms(35);
	LCD_voidWriteCommand(Function_Set);
	_delay_ms(40);
	LCD_voidWriteCommand(DIS_ON_OFF);
	_delay_ms(1);
	LCD_voidWriteCommand(CLR_LCD);
	_delay_ms(2);
	//LCD_voidWriteCommand(Intry_Mode);
	

}


void LCD_gotoXy(u8 y,u8 x)
{
	if(y==0)
	{
		LCD_voidWriteCommand(128+x);
	}
	else if(y==1)
	{
		LCD_voidWriteCommand(128+0X40+x);
	}
}



void LCD_VoidSendString(u8 *copy_u8Data)
{
	while ((*copy_u8Data)!='\0')
	{
		LCD_voidWriteData(*copy_u8Data++);
	}

}
void LCD_Writenumber(u32 number)
 {
	 u8 counter=0;
	 s8 i=0;
	 u8 arr[10];

	 while(number!=0)
	 {
		 arr[counter]=number%10;
		 counter++;
		 number=number/10;
	 }
	 for (i=counter-1;i>=0;i--)
	 {
		 LCD_voidWriteData(arr[i]+48);
	 }

 }
