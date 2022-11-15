#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
#include"../../MCAL/DIO/DIO_INT.h"
#include"../../MCAL/DIO/DIO_config.h"
#include "LCD_Register.h"
#include "LCD_Interface.h"
#include "avr/delay.h"


void LCD_VidInit(void)
{
	_delay_ms(50);

	  /*set direction*/
		DIO_VidSetPortDirection(LCD_DATA_PORT,0XFF);
		DIO_VidSetPortDirection(LCD_CTRL_PORT,0x07);

		LCD_VidWriteCommend(0B00111000);//function set
		_delay_ms(1);
		LCD_VidWriteCommend(0B00001100);//screen on
	    _delay_ms(1);
		LCD_VidWriteCommend(0B00000001);//clear display
	    _delay_ms(2);
}
void LCD_VidWriteCommend(u8 LCD_u8Commend)
{

	DIO_VidSetPinValue(LCD_CTRL_PORT,PIN0,0);  //RS=0 FOR COMMAND
	DIO_VidSetPinValue(LCD_CTRL_PORT,PIN1,0);  //RW=0 FOR WRITE
	DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Commend); //write commend
			/*FOR ENBLE PULSE*/
	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,1);  //EN=1
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,0);  //EN=0

	_delay_ms(1);     //wait lcd to write letter

}
void LCD_VidWriteData(u8 LCD_u8Data)
{

	DIO_VidSetPinValue(LCD_CTRL_PORT,RS,1);  //RS=1 FOR DATA
	DIO_VidSetPinValue(LCD_CTRL_PORT,RW,0);  //RW=0 FOR WRITE
	DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Data); //write commend
			/*FOR ENBLE PULSE*/
	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,1);  //EN=1
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,0);  //EN=0

	_delay_ms(1);     //wait lcd to write letter

}

void LCD_VidWriteString(u8 *ptr)
{
	for(u8 i=0;i<100;i++)
	{
		if(ptr[i]=='\0')
		    {
		    	break;
		    }
	LCD_VidWriteData(ptr[i]);

	}

}

void LCD_VidWriteNumber(u32 LOC_u32num)
{
	u32 revrese=0;
	u8 ZeroNum;
	u8 counter=0;
	if(LOC_u32num==0)
	{
		LCD_VidWriteData(48);
	}
	while(LOC_u32num>0)
	{
		revrese=(revrese*10)+(LOC_u32num)%10;
		if(revrese==0)
		{
			 ZeroNum=0;
			 counter++;
		}
		LOC_u32num=LOC_u32num/10;
	}
	while(revrese>0)
	{
		u8 res=revrese%10;
		LCD_VidWriteData(res+48);
		revrese=revrese/10;
	}
	if(ZeroNum==0)
	{
		for(u8 i=0;i<counter;i++)
		{
			LCD_VidWriteData(48);
		}
	}
}

void LCD_GoToXY(u8 row,u8 col)
{
	if(row==0)
	{
		LCD_VidWriteCommend(128+col);
	}
	else if (row==1)
	{
		LCD_VidWriteCommend(192+col);
	}
}

