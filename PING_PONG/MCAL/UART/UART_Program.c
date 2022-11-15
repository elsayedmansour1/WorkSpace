#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
#include <avr/delay.h>
#include"UART_Register.h"
#include"UART_Interface.h"
#include"UART_Configuration.h"

u8 Temporary_REG=0;
u8 arr[5];
void UART_INIT(void)
{

	UBRRH=0;
	UBRRL=51;
	/*USART Control and Status Register B – UCSRB */
	Receiver_Enable;
	Transmitter_Enable;
	/*Character Size*/
	Eight_Bit;
	/*Register Select*/
	SET_BIT( Temporary_REG , URSEL );
	/*USART Mode Select*/
	CLR_BIT( Temporary_REG , UMSEL );
	/*Parity Mode*/
	CLR_BIT( Temporary_REG ,  UPM1 );
	CLR_BIT( Temporary_REG ,  UPM0 );
	/*Stop Bit Select*/
	CLR_BIT( Temporary_REG ,  USBS );
	/*Clock Polarity*/
	CLR_BIT( Temporary_REG , UCPOL );
	/*MOVING DATA*/
	USCRC=Temporary_REG;
	

}
void UART_VoidSendChar(u8 u8Data)
{
	/*wait until Transmitter be Empty*/
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR=u8Data;

}
u8 UART_VoidGetChar(void)
{
	u8 u8Result=0;
	/*wait until Receive Complete*/
	while(GET_BIT(UCSRA,RXC)==0);
	/**/
	u8Result=UDR;
	/*Clear Flag*/
	Trasmit_Complete;


	return u8Result;
}
u8* UART_VoidGetString(void)
{

	for(u8 count=0;count<3;count++)
	{
		arr[count]=UART_VoidGetChar();
	}
	return arr;
}
