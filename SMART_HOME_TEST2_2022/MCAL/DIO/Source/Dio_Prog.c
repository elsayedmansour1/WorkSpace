/*
 * DIO.c
 *
 *  Created on: Jan 12, 2022
 *      Author: kareem ashraf
 */


#include "../../../SERVICE/Std_Types.h"
#include "../../../SERVICE/Bit_Math.h"
#include "../Header/Dio_Private.h"
#include "../Header/Dio_Config.h"
#include "../Header/Dio_Interface.h"


/******************************************************************************************************/
/*******************************This Function Shall set the direction pin******************************/
/******************************************************************************************************/

void DIO_VoidSetPinDir(uint8 DIO_uint8CopyPort ,uint8 DIO_uint8CopyPin_Id , uint8 DIO_uint8CopyPinDir)
{
	switch(DIO_uint8CopyPort)
	{
	case 0 :
		if(DIO_uint8CopyPinDir==OUTPUT)
		{
			Set_Bit(DDRA_REG,DIO_uint8CopyPin_Id);
		}
		else if(DIO_uint8CopyPinDir==INPUT)
		{
			Clr_Bit(DDRA_REG,DIO_uint8CopyPin_Id);
		}

		break;
	case 1 :
		if(DIO_uint8CopyPinDir==OUTPUT)
		{
			Set_Bit(DDRB_REG,DIO_uint8CopyPin_Id);
		}
		else if(DIO_uint8CopyPinDir==INPUT)
		{
			Clr_Bit(DDRB_REG,DIO_uint8CopyPin_Id);
		}

		break;
	case 2 :
		if(DIO_uint8CopyPinDir==OUTPUT)
		{
			Set_Bit(DDRC_REG,DIO_uint8CopyPin_Id);
		}
		else if(DIO_uint8CopyPinDir==INPUT)
		{
			Clr_Bit(DDRC_REG,DIO_uint8CopyPin_Id);
		}

		break;
	case 3 :
		if(DIO_uint8CopyPinDir==OUTPUT)
		{
			Set_Bit(DDRD_REG,DIO_uint8CopyPin_Id);
		}
		else if(DIO_uint8CopyPinDir==INPUT)
		{
			Clr_Bit(DDRD_REG,DIO_uint8CopyPin_Id);
		}

		break;
	}

}


/******************************************************************************************************/
/*******************************This Function Shall set the Value pin**********************************/
/******************************************************************************************************/

void DIO_VoidSetPinValue(uint8 DIO_uint8SetPort, uint8 DIO_uint8SetPin_Id,uint8 DIO_uint8SetPinValue)
{
	switch(DIO_uint8SetPort)
	{
	case 0 :
		if(DIO_uint8SetPinValue==HIGH)
		{
			Set_Bit(PORTA_REG,DIO_uint8SetPin_Id);
		}
		else if(DIO_uint8SetPinValue==LOW)
		{
			Clr_Bit(PORTA_REG,DIO_uint8SetPin_Id);
		}

		break;
	case 1 :
		if(DIO_uint8SetPinValue==HIGH)
		{
			Set_Bit(PORTB_REG,DIO_uint8SetPin_Id);
		}
		else if(DIO_uint8SetPinValue==LOW)
		{
			Clr_Bit(PORTB_REG,DIO_uint8SetPin_Id);
		}

		break;
	case 2 :
		if(DIO_uint8SetPinValue==HIGH)
		{
			Set_Bit(PORTC_REG,DIO_uint8SetPin_Id);
		}
		else if(DIO_uint8SetPinValue==LOW)
		{
			Clr_Bit(PORTC_REG,DIO_uint8SetPin_Id);
		}

		break;
	case 3 :
		if(DIO_uint8SetPinValue==HIGH)
		{
			Set_Bit(PORTD_REG,DIO_uint8SetPin_Id);
		}
		else if(DIO_uint8SetPinValue==LOW)
		{
			Clr_Bit(PORTD_REG,DIO_uint8SetPin_Id);
		}

		break;
	}


}




/******************************************************************************************************/
/*******************************This Function Shall Read the Value pin**********************************/
/******************************************************************************************************/

uint8 DIO_ReadPinValue(uint8 DIO_uint8ReadPort ,uint8 DIO_uint8ReadPin_Id )
{

	switch(DIO_uint8ReadPort)
	{
	case 0 :
		return Get_Bit(PINA_REG,DIO_uint8ReadPin_Id);

		break;
	case 1 :

		return Get_Bit(PINB_REG,DIO_uint8ReadPin_Id);


		break;
	case 2 :
		return Get_Bit(PINC_REG,DIO_uint8ReadPin_Id);


		break;
	case 3 :
		return Get_Bit(PIND_REG,DIO_uint8ReadPin_Id);

		break;
	}

}





/*****This Function Shall set the direction Port ******/
void DIO_VoidSetAllPortDir(uint8 DIO_uint8CopyPort ,  uint8 DIO_uint8CopyPortDir)
{
	switch(DIO_uint8CopyPort)
	{
	case 0 :
		if(DIO_uint8CopyPortDir==OUTPUT)
		{
			DDRA_REG = 0xFF ;
		}
		else if(DIO_uint8CopyPortDir==INPUT)
		{
			DDRA_REG = 0x00 ;
		}

		break;
	case 1 :
		if(DIO_uint8CopyPortDir==OUTPUT)
		{
			DDRB_REG = 0XFF ;
		}
		else if(DIO_uint8CopyPortDir==INPUT)
		{
			DDRB_REG = 0X00 ;
		}

		break;
	case 2 :
		if(DIO_uint8CopyPortDir==OUTPUT)
		{
			DDRC_REG = 0XFF ;
		}
		else if(DIO_uint8CopyPortDir==INPUT)
		{
			DDRC_REG = 0X00 ;
		}

		break;
	case 3 :
		if(DIO_uint8CopyPortDir==OUTPUT)
		{
			DDRD_REG = 0XFF ;
		}
		else if(DIO_uint8CopyPortDir==INPUT)
		{
			DDRD_REG = 0X00 ;
		}

		break;
	}

}

/*****This Function Shall set the Value Port ******/
void DIO_VoidSetAllPortValue(uint8 DIO_uint8SetPort , uint8 DIO_uint8SetPortValue)
{
	switch(DIO_uint8SetPort)
	{
	case 0 :
		if(DIO_uint8SetPortValue==HIGH)
		{
			PORTA_REG = 0XFF ;
		}
		else if(DIO_uint8SetPortValue==LOW)
		{
			PORTA_REG = 0X00 ;
		}

		break;
	case 1 :
		if(DIO_uint8SetPortValue==HIGH)
		{
			PORTB_REG = 0XFF ;
		}
		else if(DIO_uint8SetPortValue==LOW)
		{
			PORTB_REG = 0X00 ;
		}

		break;
	case 2 :
		if(DIO_uint8SetPortValue==HIGH)
		{
			PORTC_REG = 0XFF ;
		}
		else if(DIO_uint8SetPortValue==LOW)
		{
			PORTC_REG = 0X00 ;
		}

		break;
	case 3 :
		if(DIO_uint8SetPortValue==HIGH)
		{
			PORTD_REG = 0XFF ;
		}
		else if(DIO_uint8SetPortValue==LOW)
		{
			PORTD_REG = 0X00 ;
		}

		break;
	}

}

/*****This Function Shall Read the Value Port ******/
uint8 DIO_ReadPortValue(uint8 DIO_uint8ReadPort)
{
	switch(DIO_uint8ReadPort)
	{
	case 0 :
		return PORTA_REG ;

		break;
	case 1 :

		return PORTB_REG ;


		break;
	case 2 :
		return PORTC_REG ;


		break;
	case 3 :
		return PORTD_REG ;

		break;
	}
}






/*****This Function Shall Control Pin Pull Up the Value pin ******/
void DIO_VoidControlPinPullUp(uint8 DIO_uint8SetPort , uint8 DIO_uint8SetPin_Id , uint8 Dio_uint8PullUpState)
{
	switch(DIO_uint8SetPort)
	{
	case 0 :
		if(Dio_uint8PullUpState==ENABLE_PULLUP)
		{
			Set_Bit(PORTA_REG,DIO_uint8SetPin_Id);
		}
		else if(Dio_uint8PullUpState==DISABLE_PULLUP)
		{
			Clr_Bit(PORTA_REG,DIO_uint8SetPin_Id);
		}

		break;
	case 1 :
		if(Dio_uint8PullUpState==ENABLE_PULLUP)
		{
			Set_Bit(PORTB_REG,DIO_uint8SetPin_Id);
		}
		else if(Dio_uint8PullUpState==DISABLE_PULLUP)
		{
			Clr_Bit(PORTB_REG,DIO_uint8SetPin_Id);
		}

		break;
	case 2 :
		if(Dio_uint8PullUpState==ENABLE_PULLUP)
		{
			Set_Bit(PORTC_REG,DIO_uint8SetPin_Id);
		}
		else if(Dio_uint8PullUpState==DISABLE_PULLUP)
		{
			Clr_Bit(PORTC_REG,DIO_uint8SetPin_Id);
		}

		break;
	case 3 :
		if(Dio_uint8PullUpState==ENABLE_PULLUP)
		{
			Set_Bit(PORTD_REG,DIO_uint8SetPin_Id);
		}
		else if(Dio_uint8PullUpState==DISABLE_PULLUP)
		{
			Clr_Bit(PORTD_REG,DIO_uint8SetPin_Id);
		}

		break;
	}

}





void DIO_VoidSetSpecialPortDir(uint8 DIO_uint8CopyPort   ,  uint8 DIO_uint8CopyPortDir)
{
	switch(DIO_uint8CopyPort)
	{
	case 0:   DDRA_REG=DIO_uint8CopyPortDir; break;
	case 1:   DDRB_REG=DIO_uint8CopyPortDir; break;
	case 2:   DDRC_REG=DIO_uint8CopyPortDir; break;
	case 3:   DDRD_REG=DIO_uint8CopyPortDir; break;

	}

}


void DIO_VoidSetSpecialPortValue(uint8 DIO_uint8SetPort , uint8 DIO_uint8SetPortValue)
{

	switch(DIO_uint8SetPort)
	{
	case 0:   PORTA_REG=DIO_uint8SetPortValue; break;
	case 1:   PORTB_REG=DIO_uint8SetPortValue; break;
	case 2:   PORTC_REG=DIO_uint8SetPortValue; break;
	case 3:   PORTD_REG=DIO_uint8SetPortValue; break;
	default:								   break;
	}


}



void DIO_VoidSetToggelValue(uint8 DIO_uint8SetPort , uint8 DIO_uint8Setpin_Id)
{

	switch(DIO_uint8SetPort)
	{
	case 0 :
		Toggle_Bit(PORTA_REG,DIO_uint8Setpin_Id);
		break;
	case 1 :
		Toggle_Bit(PORTB_REG,DIO_uint8Setpin_Id);
		break;
	case 2 :
		Toggle_Bit(PORTC_REG,DIO_uint8Setpin_Id);

		break;
	case 3 :
		Toggle_Bit(PORTD_REG,DIO_uint8Setpin_Id);
		break;
	}


}


uint8 DIO_ReadSegmentOfAddress(uint8 Address ,uint8 Segment )
{
	return Get_Bit(Address,Segment);
}


















