
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
#include <util/delay.h>

u16 LDR_ReturnReading(u8 copy_u8channel);
u16 LM35_ReturnReading(u8 copy_u8channel);

int main (void)
{
	SetPortDirection(PORTC,0XFF);//DATA PORT FOR LCD
	SetPortDirection(PORTD,0X07);//RW & RW & EN
	DIO_voidSetPinDirection(PORTA,PIN0,INPUT);//LDR
	DIO_voidSetPinDirection(PORTA,PIN7,INPUT);//LM35
	ADC_INTI();

	LCD_voidInit();
	LCD_VoidSendString("light:");
	LCD_gotoXy(1,0);
	LCD_VoidSendString("temp:");

while (1)
{
	LCD_gotoXy(0,6);
	LCD_Writenumber(LDR_ReturnReading(channel7));
	LCD_gotoXy(1,5);
	LCD_Writenumber(LM35_ReturnReading(channel0));               //temp

}
}

u16 LM35_ReturnReading(u8 copy_u8channel)
{
	u16 result=0;
	u16 analog=0;
	u16 temp=0;
	set_channel(copy_u8channel);
	result = ADC_GET_RES();
	analog=result*(5000UL/1024);
	temp=analog/10;
	return temp;
}
u16 LDR_ReturnReading(u8 copy_u8channel)
{
	u16 result=0;
	u16 analog=0;
	u16 light=0;
	set_channel(copy_u8channel);
	result = ADC_GET_RES();
	analog=result*(5000UL/1024);        //light
	light=analog/100;
	return light;
}







