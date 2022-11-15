/*
 * TWI_Program.c
 *
 *  Created on: Oct 29, 2022
 *      Author: elsay
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "TWI_Interface.h"
#include "TWI_Register.h"


void TWI_voidMasterInit(void)
{
	//those setting for 400kHZ
	TWBR=2;
	TWSR=0x00;
	//enable for TWI
	SET_BIT(TWCR,2);

}
void TWI_voidSlaveInit(void)
{

}
void TWI_voidStartCondition(void)
{
	//make sure your flag is clear
	SET_BIT(TWCR,7);
	//sent start condition
	SET_BIT(TWCR,5);
	//enable for TWI
	SET_BIT(TWCR,2);
	//wait until the start condition send
	while(GET_BIT(TWCR,7)==0);
	//to check the start condition send correctly
	if(TWSR&0xf8!=0x08)
	{
		//send error
	}

}
void TWI_voidSendSlaveWithWrite(u8 copy_u8Address)
{
	//to send slave address
	TWDR=copy_u8Address<<1;
	//to send write Operation by clear it
	CLR_BIT(TWDR,0);
	//make sure your flag is clear
	SET_BIT(TWCR,7);
	//enable for TWI
	SET_BIT(TWCR,2);
	//wait until the Slave address with write to be send
	while(GET_BIT(TWCR,7)==0);
	//to check the Slave address send correctly
	if((TWSR & 0xf8)!=0x18)
	{
		//send error
	}

}
void TWI_voidSendSlaveWithRead(u8 copy_u8Address)
{
	//to send slave address
	TWDR=copy_u8Address<<1;
	//to send write Operation by clear it
	SET_BIT(TWDR,0);
	//make sure your flag is clear
	SET_BIT(TWCR,7);
	//enable for TWI
	SET_BIT(TWCR,2);
	//wait until the Slave address with read to be send
	while(GET_BIT(TWCR,7)==0);
	//to check the Slave address send correctly
	if((TWSR & 0xf8)!=0x40)
	{
		//send error
	}
}
void TWI_voidMasterSendData(u8 Copy_u8Data)
{
	//send Data
	TWDR=Copy_u8Data;
	//make sure your flag is clear
	SET_BIT(TWCR,7);
	//enable for TWI
	SET_BIT(TWCR,2);
	//wait until Data to be send
	while(GET_BIT(TWCR,7)==0);
	//to check the Data send correctly
	if(TWSR&0xf8!=0x28)
	{
		//send error
	}
}
void TWI_voidMasteReceiveData(u8 *Copy_u8Data)
{
	//make sure your flag is clear
	SET_BIT(TWCR,7);
	//enable for TWI
	SET_BIT(TWCR,2);
	//wait until Data to be Receive
	while(GET_BIT(TWCR,7)==0);
	//to check the Data send correctly
	if((TWSR & 0xf8)!=0x50)
	{
		//send error
	}
	else
	{
		//to get the received data
		*Copy_u8Data=TWDR;
	}

}
void TWI_voidStopCondition(void)
{
	//make sure your flag is clear
	SET_BIT(TWCR,7);
	//enable for TWI
	SET_BIT(TWCR,2);
	//send stop condition
	SET_BIT(TWCR,5);
}
