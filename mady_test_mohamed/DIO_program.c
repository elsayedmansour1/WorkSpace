#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Register.h"






void DIO_voidSetPinDirection  (u8 copy_u8PORTID ,u8 copy_u8PINID,u8 copy_u8Direction)
{
	if(OUTPUT == copy_u8Direction)
	{
		switch(copy_u8PORTID)
		{
			case PORTA: SET_BIT(DDRA_REG,copy_u8PINID); break;
			case PORTB: SET_BIT(DDRB_REG,copy_u8PINID); break;
			case PORTC: SET_BIT(DDRC_REG,copy_u8PINID); break;
			case PORTD: SET_BIT(DDRD_REG,copy_u8PINID); break;
		}
	}
	else if (INPUT == copy_u8Direction)
	{
		switch (copy_u8PORTID)
		{
	    	case PORTA : CLR_BIT(DDRA_REG,copy_u8PINID); break;
			case PORTB : CLR_BIT(DDRB_REG,copy_u8PINID); break;
			case PORTC : CLR_BIT(DDRC_REG,copy_u8PINID); break;
			case PORTD : CLR_BIT(DDRD_REG,copy_u8PINID); break;
		}
	}
}
void DIO_voidSetPinValue  (u8 copy_u8PORTID ,u8 copy_u8PINID,u8 copy_u8Value)
{
	if(HIGH == copy_u8Value)
	{
		switch(copy_u8PORTID)
		{
			case PORTA: SET_BIT(PORTA_REG,copy_u8PINID); break;
			case PORTB: SET_BIT(PORTB_REG,copy_u8PINID); break;
			case PORTC: SET_BIT(PORTC_REG,copy_u8PINID); break;
			case PORTD: SET_BIT(PORTD_REG,copy_u8PINID); break;
		}
	}
	else if (LOW == copy_u8Value)
	{
		switch (copy_u8PORTID)
		{
	    	case PORTA : CLR_BIT(PORTA_REG,copy_u8PINID); break;
			case PORTB : CLR_BIT(PORTB_REG,copy_u8PINID); break;
			case PORTC : CLR_BIT(PORTC_REG,copy_u8PINID); break;
			case PORTD : CLR_BIT(PORTD_REG,copy_u8PINID); break;
		}
	}
}
u8 DIO_GetPinValue (u8 copy_u8PORTID ,u8 copy_u8PINID)
{
	u8 result=0;
	switch(copy_u8PORTID)
	{
		case PORTA : result = GET_BIT (PINA_REG,copy_u8PINID);break;
		case PORTB : result = GET_BIT (PINB_REG,copy_u8PINID);break;
		case PORTC : result = GET_BIT (PINC_REG,copy_u8PINID);break;
		case PORTD : result = GET_BIT (PIND_REG,copy_u8PINID);break;
	}
	return result;
	
}

void SetPortDirection(u8 copy_u8PORTID,u8 copy_u8Direction)
{
	
	switch (copy_u8PORTID)
	{
		case PORTA :DDRA_REG = copy_u8Direction;break;
		case PORTB :DDRB_REG = copy_u8Direction;break;
		case PORTC :DDRC_REG = copy_u8Direction;break;
		case PORTD :DDRD_REG = copy_u8Direction;break;
	}

}

void SetPortValue(u8 copy_u8PORTID,u8 copy_u8Value)
{
	
	switch (copy_u8PORTID)
	{
		case PORTA :PORTA_REG = copy_u8Value;break;
		case PORTB :PORTB_REG = copy_u8Value;break;
		case PORTC :PORTC_REG = copy_u8Value;break;
		case PORTD :PORTD_REG = copy_u8Value;break;
	}

}
