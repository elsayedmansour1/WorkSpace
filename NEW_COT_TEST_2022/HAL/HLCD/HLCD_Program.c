#include "../../LIB/LBIT_MATH.h"
#include "../../LIB/LSTD_TYPES.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"../../MCAL/MDIO/MDIO_Config.h"
#include "avr/delay.h"

#include "HLCD_Interface.h"
#include "HLCD_Register.h"




void HLCD_VidInit(void)
{
	_delay_ms(50);
#if MODE==4
	//DIO_VidSetPortDirection(LCD_CTRL_PORT,0x07);  /* Configure the control pins(E,RS,RW) as output pins */
	MDIO_u8SetPinDirection(LCD_CTRL_PORT,RS,DIO_u8_OUTPUT);
	MDIO_u8SetPinDirection(LCD_CTRL_PORT,RW,DIO_u8_OUTPUT);
	MDIO_u8SetPinDirection(LCD_CTRL_PORT,EN,DIO_u8_OUTPUT);
	//_delay_ms(1);


		// set only PORT 4~7 pins as outputs
		//DIO_VidSetPortDirection(LCD_DATA_PORT,0xF0);  /* Configure the data port as output port */
	MDIO_u8SetPinDirection(LCD_DATA_PORT,DIO_u8_PIN4,DIO_u8_OUTPUT);
	MDIO_u8SetPinDirection(LCD_DATA_PORT,DIO_u8_PIN5,DIO_u8_OUTPUT);
	MDIO_u8SetPinDirection(LCD_DATA_PORT,DIO_u8_PIN6,DIO_u8_OUTPUT);
	MDIO_u8SetPinDirection(LCD_DATA_PORT,DIO_u8_PIN7,DIO_u8_OUTPUT);
		/*send function set command*/
		HLCD_VidWriteCommend(HCLCD_FUNCTION_SET>>4);
		HLCD_VidWriteCommend(HCLCD_FUNCTION_SET>>4);
		HLCD_VidWriteCommend(HCLCD_FUNCTION_SET);
			_delay_ms(1);
			/*send Display on/off  command*/
			HLCD_VidWriteCommend(HCLCD_DISPLAY_ON_OFF>>4);
			HLCD_VidWriteCommend(HCLCD_DISPLAY_ON_OFF);
			_delay_ms(1);
			/*send Display Clear  command*/
			HLCD_VidWriteCommend(DISPLAY_CLEAR>>4);
			HLCD_VidWriteCommend(DISPLAY_CLEAR);
			_delay_ms(2);
			/*send Entry Mode  set command*/
			HLCD_VidWriteCommend(HCLCD_ENTRY_MODE_SET>>4);
			HLCD_VidWriteCommend(HCLCD_ENTRY_MODE_SET);

#elif MODE==8
	  /*set direction*/
			MDIO_u8SetPinDirection(LCD_CTRL_PORT,RS,DIO_u8_OUTPUT);
			MDIO_u8SetPinDirection(LCD_CTRL_PORT,RW,DIO_u8_OUTPUT);
			MDIO_u8SetPinDirection(LCD_CTRL_PORT,EN,DIO_u8_OUTPUT);
			MDIO_u8SetPortDirection(LCD_DATA_PORT,0XFF);



		HLCD_VidWriteCommend(0B00111000);//function set
		_delay_ms(1);
		HLCD_VidWriteCommend(0B00001100);//screen on
	    _delay_ms(1);
	    HLCD_VidWriteCommend(0B00000001);//clear display
	    _delay_ms(2);
		HLCD_VidWriteCommend(0B00000010);//Return Home
#else
#error "WRONG CHOOSE THE MODE"
#endif

}
void HLCD_VidWriteCommend(u8 LCD_u8Commend)
{
#if MODE==4
		MDIO_u8SetPinValue(LCD_CTRL_PORT,RS,0); /* Instruction Mode RS=0 */
		MDIO_u8SetPinValue(LCD_CTRL_PORT,RW,0);/* write data to LCD so RW=0 */
		_delay_ms(1);

		//send MOST SIGNIFICANT 4-bits
		MDIO_u8Set4PinsValue(LCD_DATA_PORT,4,LCD_u8Commend); /* out the required command to the data bus D0 --> D7 */
		_delay_ms(1);
		MDIO_u8SetPinValue(LCD_CTRL_PORT,EN,1); /* Enable LCD E=1 */
		_delay_ms(2);
		MDIO_u8SetPinValue(LCD_CTRL_PORT,EN,0); /* disable LCD E=0 */

#elif MODE==8
		MDIO_u8SetPinValue(LCD_CTRL_PORT,RS,0);  //RS=0
		MDIO_u8SetPinValue(LCD_CTRL_PORT,RW,0);  //RW=0
		MDIO_u8SetPortValue(LCD_DATA_PORT,LCD_u8Commend); //write commend

		MDIO_u8SetPinValue(LCD_CTRL_PORT,EN,1);  //EN=1
		_delay_ms(2);
		MDIO_u8SetPinValue(LCD_CTRL_PORT,EN,0);  //EN=0
		_delay_ms(1);     //wait lcd to write letter
#else
#error "WRONG CHOOSE THE MODE"
#endif


}
void HLCD_VidWriteData(u8 LCD_u8Data)
{
#if MODE==4
		MDIO_u8SetPinValue(LCD_CTRL_PORT,RS,1); /* Instruction Mode RS=0 */
		MDIO_u8SetPinValue(LCD_CTRL_PORT,RW,0);/* write data to LCD so RW=0 */
		_delay_ms(1);

		//send MOST SIGNIFICANT 4-bits
		MDIO_u8Set4PinsValue(LCD_DATA_PORT,4,LCD_u8Data);
		MDIO_u8SetPinValue(LCD_CTRL_PORT,EN,1); /* Enable LCD E=1 */
		_delay_ms(2);
		MDIO_u8SetPinValue(LCD_CTRL_PORT,EN,0); /* disable LCD E=0 */
#elif MODE==8
		MDIO_u8SetPinValue(LCD_CTRL_PORT,RS,1);  //RS=1
		MDIO_u8SetPinValue(LCD_CTRL_PORT,RW,0);  //RW=0
		MDIO_u8SetPortValue(LCD_DATA_PORT,LCD_u8Data); //write commend

		MDIO_u8SetPinValue(LCD_CTRL_PORT,EN,1);  //EN=1
		_delay_ms(2);
		MDIO_u8SetPinValue(LCD_CTRL_PORT,EN,0);  //EN=0
		_delay_ms(1);     //wait lcd to write letter
#else
#error "WRONG CHOOSE THE MODE"
#endif

}
void HLCD_VoidClearDisplay(void)
{
#if	MODE==4
	HLCD_VidWriteCommend(0x01>>4);
	HLCD_VidWriteCommend(0x01);
#elif MODE==8
	HLCD_VidWriteCommend(0x01);
	_delay_ms(20);
#else
#error "WRONG CHOOSE THE MODE"
#endif

}
void HLCD_DisplayCharacter(u8 Copy_u8Data)
{
#if	MODE==4
	HLCD_VidWriteData(Copy_u8Data>>4);
	HLCD_VidWriteData(Copy_u8Data);
#elif MODE==8
	HLCD_VidWriteData(Copy_u8Data);
#else
#error "WRONG CHOOSE THE MODE"
#endif
}
void HLCD_DisplayString(u8* PCopy_u8String)
{

	u8 Loc_u8Count=0;
	while(PCopy_u8String[Loc_u8Count]!=NULL)
	{
		HLCD_DisplayCharacter(PCopy_u8String[Loc_u8Count]);
		Loc_u8Count++;
	}


}
void HLCD_VidWriteNumber(u32 LOC_u32num)
{ 	u32 revrese=0;
u8 y;
u8 counter=0;
if(LOC_u32num==0)
{
	HLCD_DisplayCharacter(48);
}
while(LOC_u32num>0)
{
	revrese=(revrese*10)+(LOC_u32num)%10;
	if(revrese==0)
	{
		 y=0;
		 counter++;
	}
	LOC_u32num=LOC_u32num/10;
}
while(revrese>0)
{
	u8 res=revrese%10;
	HLCD_DisplayCharacter(res+48);
	revrese=revrese/10;
}
if(y==0)
{
	for(u8 i=0;i<counter;i++)
	{
		HLCD_DisplayCharacter(48);
	}
}
}
void HLCD_SetPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber)
{
	if((Copy_u8LineNumber<=0)&&(Copy_u8PositionNumber<= 39))
	{
#if	MODE==4
		switch(Copy_u8LineNumber)
		{
		case LCD_u8_LINE0 :
			HLCD_VidWriteCommend((128+Copy_u8PositionNumber)>>4);
			HLCD_VidWriteCommend((128+Copy_u8PositionNumber));
			break;
		case LCD_u8_LINE1 :
			HLCD_VidWriteCommend((192+Copy_u8PositionNumber)>>4);
			HLCD_VidWriteCommend((192+Copy_u8PositionNumber));
			break;
		}

#elif MODE==8
		switch(Copy_u8LineNumber)
				{

				case LCD_u8_LINE0 : HLCD_VidWriteCommend(0x80 + Copy_u8PositionNumber);break;

				case LCD_u8_LINE1 : HLCD_VidWriteCommend(0xC0 + Copy_u8PositionNumber);break;
				}
#else
#error "WRONG CHOOSE THE MODE"
#endif

	}


}
