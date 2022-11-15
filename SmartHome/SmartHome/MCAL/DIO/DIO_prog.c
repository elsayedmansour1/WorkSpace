
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include"DIO_config.h"
#include"DIO_REG.h"







void DIO_VidSetPinDirection	(u8 LOC_u8Port,u8 LOC_u8PinNumber,u8 LOC_u8State)
{
	if(LOC_u8State==OUTPUT)
	{
		switch(LOC_u8Port)
		{
		case DIO_PORTA:SET_BIT(DDRA,LOC_u8PinNumber);break;
		case DIO_PORTB:SET_BIT(DDRB,LOC_u8PinNumber);break;
		case DIO_PORTC:SET_BIT(DDRC,LOC_u8PinNumber);break;
		case DIO_PORTD:SET_BIT(DDRD,LOC_u8PinNumber);break;	
		}
	}
	else if(LOC_u8State==INPUT)
	{
		switch(LOC_u8Port)
		{
		case DIO_PORTA:CLR_BIT(DDRA,LOC_u8PinNumber);break;
		case DIO_PORTB:CLR_BIT(DDRB,LOC_u8PinNumber);break;
		case DIO_PORTC:CLR_BIT(DDRC,LOC_u8PinNumber);break;
		case DIO_PORTD:CLR_BIT(DDRD,LOC_u8PinNumber);break;	
		}	
	}
	else{}
	
}
void DIO_VidSetPinValue	(u8 LOC_u8Port,u8 LOC_u8PinNumber,u8 LOC_u8Value)
{
	if(LOC_u8Value==HIGH)
	{
		switch(LOC_u8Port)
		{
		case DIO_PORTA:SET_BIT(PORTA,LOC_u8PinNumber);break;
		case DIO_PORTB:SET_BIT(PORTB,LOC_u8PinNumber);break;
		case DIO_PORTC:SET_BIT(PORTC,LOC_u8PinNumber);break;
		case DIO_PORTD:SET_BIT(PORTD,LOC_u8PinNumber);break;	
		}
	}
	else if (LOC_u8Value==LOW)
	{
		switch(LOC_u8Port)
		{
		case DIO_PORTA:CLR_BIT(PORTA,LOC_u8PinNumber);break;
		case DIO_PORTB:CLR_BIT(PORTB,LOC_u8PinNumber);break;
		case DIO_PORTC:CLR_BIT(PORTC,LOC_u8PinNumber);break;
		case DIO_PORTD:CLR_BIT(PORTD,LOC_u8PinNumber);break;	
		}	
	}
	else{}	
}
void DIO_VidSetPortDirection	(u8 LOC_u8Port,u8 LOC_u8Value)
{
	switch(LOC_u8Port)
	{
	case DIO_PORTA:DDRA=LOC_u8Value;break;
	case DIO_PORTB:DDRB=LOC_u8Value;break;
	case DIO_PORTC:DDRC=LOC_u8Value;break;
	case DIO_PORTD:DDRD=LOC_u8Value;break;	
	}	
	
}
void DIO_VidSetPortValue	(u8 LOC_u8Port,u8 LOC_u8Value)
{
	switch(LOC_u8Port)
	{
	case DIO_PORTA:PORTA=LOC_u8Value;break;
	case DIO_PORTB:PORTB=LOC_u8Value;break;
	case DIO_PORTC:PORTC=LOC_u8Value;break;
	case DIO_PORTD:PORTD=LOC_u8Value;break;	
	}	
}
u8 DIO_u8GetPinValue	(u8 LOC_u8Port,u8 LOC_u8Pin)
{
	u8 Value=0;
	switch(LOC_u8Port)
	{
	case DIO_PORTA:Value=GET_BIT(PINA,LOC_u8Pin);break;
	case DIO_PORTB:Value=GET_BIT(PINB,LOC_u8Pin);break;
	case DIO_PORTC:Value=GET_BIT(PINC,LOC_u8Pin);break;
	case DIO_PORTD:Value=GET_BIT(PIND,LOC_u8Pin);break;
	}
	return Value;
}
void DIO_u8TogglePinValue   	(u8 LOC_u8Port,u8 LOC_u8Pin)
{
	switch(LOC_u8Port)
	{
	case DIO_PORTA:TOG_BIT(PORTA,LOC_u8Pin);break;
	case DIO_PORTB:TOG_BIT(PORTB,LOC_u8Pin);break;
	case DIO_PORTC:TOG_BIT(PORTC,LOC_u8Pin);break;
	case DIO_PORTD:TOG_BIT(PORTD,LOC_u8Pin);break;	
	}
}
void DIO_SetNippleValue(u8 Copy_u8PinStart,u8 Copy_u8PortNumber,u8 Copy_u8Value)
{

	if(Copy_u8PinStart<=4)
	{
		switch(Copy_u8PortNumber)
		{
		case DIO_PORTA:
			PORTA&=(~(0x0F<<Copy_u8PinStart));
			PORTA|=(Copy_u8Value<<Copy_u8PinStart);
			break;
		case DIO_PORTB:
			PORTB&=(~(0x0F<<Copy_u8PinStart));
			PORTB|=(Copy_u8Value<<Copy_u8PinStart);
			break;
		case DIO_PORTC:
			PORTC&=(~(0x0F<<Copy_u8PinStart));
			PORTC|=(Copy_u8Value<<Copy_u8PinStart);
			break;
		case DIO_PORTD:

			PORTD&=(~(0x0F<<Copy_u8PinStart));
			PORTD|=(Copy_u8Value<<Copy_u8PinStart);
			break;

		}
	}

}
