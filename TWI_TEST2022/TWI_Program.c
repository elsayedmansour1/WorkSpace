#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_Interface.h"
#include "TWI_Register.h"


void TWI_voidMasterInit(void)
{
	//Frequency 400KHZ
	TWBR=2;
	TWSR=0X00;
	/* Enable ACKnowledgemnet */
	SET_BIT(TWCR,6);
	//Enable TWI
	SET_BIT(TWCR,2);
	//Address of master With disable General call
	TWAR=0B00000100;

}
void TWI_voidSlaveInit(void)
{

	/* Enable ACKnowledgemnet */
	SET_BIT(TWCR,6);
	//Address of master With disable General call
	TWAR=0B00000010;
	//Enable TWI
	SET_BIT(TWCR,2);
}
void TWI_voidStartCondition(void)
{
	//send Start Condition
	SET_BIT(TWCR,5);
	//make sure flag is clear
	SET_BIT(TWCR,7);
	//Enable TWI
	//SET_BIT(TWCR,2);
	//wait until flag of start condition to be set_new_handler
	while(GET_BIT(TWCR,7)==0);
	//check the start condition done correctly
	if((TWSR &  0xf8)!=0x08)
	{
		//return error
	}
}
void TWI_voidMasterSendSlaveAddWithWrite(u8 copy_u8Address)
{	
	//send Slave address
	TWDR=copy_u8Address<<1;
	//set Write operation
	CLR_BIT(TWDR,0);
	//Disable Start Condition
	CLR_BIT(TWCR,5);
	//make sure flag is clear
	SET_BIT(TWCR,7);
	//Enable TWI
	//SET_BIT(TWCR,2);
	//wait until flag of Slave address to be set_new_handler
	while(GET_BIT(TWCR,7)==0);
	//check the Slave address done correctly
	if((TWSR & 0xf8)!=0x18)
	{
		//return error
	}
}
void TWI_voidMasterSendSlaveAddWithRead(u8 copy_u8Address)
{
	//send Slave address
	TWDR=copy_u8Address<<1;
	//set Read operation
	SET_BIT(TWDR,0);
	//Disable Start Condition
	CLR_BIT(TWCR,5);
	//make sure flag is clear
	SET_BIT(TWCR,7);
	//Enable TWI
	//SET_BIT(TWCR,2);
	//wait until flag of Slave address to be set_new_handler
	while(GET_BIT(TWCR,7)==0);
	//check the Slave address done correctly
	if((TWSR & 0xf8)!=0x40)
	{
		//return error
	}
}
void TWI_voidMasterSendData(u8 copy_u8Data)
{
	//master send Data
	TWDR=copy_u8Data;
	//make sure flag is clear
	SET_BIT(TWCR,7);
	//Enable TWI
	//SET_BIT(TWCR,2);
	//wait until flag of Slave address to be set_new_handler
	while(GET_BIT(TWCR,7)==0);
	//check the send data done correctly
	if((TWSR & 0xf8)!=0x28)
	{
		//return error
	}
}
u8 	 TWI_u8MasterReceiveData(void)
{
	//make sure flag is clear
	SET_BIT(TWCR,7);
	//Enable TWI
	//SET_BIT(TWCR,2);
	//wait until flag of master receive data to be set
	while(GET_BIT(TWCR,7)==0);
	//check the send data done correctly
	if((TWSR &0xf8 )!=0x50)
	{
		//return error
	}

		return TWDR;
}
void TWI_voidStopCondition(void)
{
	//make sure flag is clear
	SET_BIT(TWCR,7);
	//Enable TWI
	//SET_BIT(TWCR,2);
	//send Stop Condition
	SET_BIT(TWCR,4);
}
u8 TWI_u8SlaveReceiveData(void)
{

	/* Enable ACKnowledgemnet */
	SET_BIT(TWCR,6);
	//make sure flag is clear
	SET_BIT(TWCR,7);
	//wait until flag of master receive data to be set
	while(GET_BIT(TWCR,7)==0);
	//while((TWSR &0xf8 )!=0x60);
	//check the send data done correctly
	if((TWSR &0xf8 )!=0x60)
	{
		//return error
	}

	return TWDR;


}
