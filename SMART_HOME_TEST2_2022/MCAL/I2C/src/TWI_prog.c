/******************************************************************************/
/******************************************************************************/
/******** Author:    Ebraheem El-Feshawy    ***********************************/
/******** Component: TWI					***********************************/
/******** Layer:     MCAL					***********************************/
/******** Version:   Student				***********************************/
/******************************************************************************/
/******************************************************************************/

#include "../../../SERVICE/Bit_Math.h"
#include "../../../SERVICE/Std_Types.h"
#include "../include/TWI_interface.h"


/*Set master address to 0 if master will not be addressed*/
void TWI_voidInitMaster(uint8 Copy_u8Address)
{
	/*Enable Acknowledge bit*/
	 Set_Bit(TWCR_REG,TWCR_REG_TWEA);
	/*Set SCL frequency to x kHz, with 8Mhz clock frequency*/
	/*1- Set TWBR to x*/ // see page 173 TWBR should be 10 or higher
	// /*Set SCL frequency to 400kHz, with 8Mhz system frequency*/
	/*1- Set TWBR to 2*/
	 TWBR_REG = SCL_EQN_TWBR;
	/*2- Clear the prescaler bits (TWPS)*/
	 #if TWI_PRE_SCALER	    ==	TWI_1_PRESCALER
	     Clr_Bit(TWSR_REG,TWSR_REG_TWPS0);
	     Clr_Bit(TWSR_REG,TWSR_REG_TWPS1);
	 #elif TWI_PRE_SCALER	==	TWI_4_PRESCALER
	     Set_Bit(TWSR_REG,TWSR_REG_TWPS0);
	     Clr_Bit(TWSR_REG,TWSR_REG_TWPS1);
	 #elif TWI_PRE_SCALER	==	TWI_16_PRESCALER
	     Clr_Bit(TWSR_REG,TWSR_REG_TWPS0);
	     Set_Bit(TWSR_REG,TWSR_REG_TWPS1);
	 #elif TWI_PRE_SCALER	==	TWI_64_PRESCALER
	     Set_Bit(TWSR_REG,TWSR_REG_TWPS0);
	     Set_Bit(TWSR_REG,TWSR_REG_TWPS1);
	 #endif

	/*Check if the master node will be addressed*/
	 #if   MSTR_NODE_ADDRESSING	 ==  MSTR_NODE_NOT_ADDRESSABLE
		
	 #elif MSTR_NODE_ADDRESSING	 ==  MSTR_NODE_ADDRESSABLE
		/*Set the required address in the 7 MSB of TWAR*/
		 //TWAR_REG = (TWAR_REG & 0x01)|(Copy_u8Address);
		 TWAR_REG = Copy_u8Address<<1;
	 #endif
	/*Enable TWI*/
	Set_Bit(TWCR_REG,TWCR_REG_TWEN);
}

void TWI_voidInitSlave(uint8 Copy_u8Address)
{
	/*Set the slave address*/
	//TWAR_REG = (TWAR_REG & 0x01)|(Copy_u8Address);
	TWAR_REG = Copy_u8Address<<1;
	/*Enable Acknowledge bit*/
	Set_Bit(TWCR_REG,TWCR_REG_TWEA);
	/*Enable TWI*/
	Set_Bit(TWCR_REG,TWCR_REG_TWEN);
}

TWI_ErrorStatus TWI_SendStartCondition(void)
{
	TWI_ErrorStatus Local_Error= NoError;
	/*set Send start condition bit*/
	 Set_Bit(TWCR_REG,TWCR_REG_TWSTA);
	/*Clear the interrupt flag that is was set to start the previous operation*/
	  Set_Bit(TWCR_REG,TWCR_REG_TWINT);	  // cleared by setting the bit
	/*wait until the operation finishes and the flag is raised*/
	 while(Get_Bit(TWCR_REG,TWCR_REG_TWINT)==0);
	/*Check the operation status*/
	if((TWSR_REG & 0xF8) != START_ACK )
	{
		Local_Error = StartConditionError;
	}
	else
	{
		/*Do nothing*/
		/* start has been sent */
	}
	 //Clr_Bit(TWCR_REG,TWCR_REG_TWSTA);
	return Local_Error;
}

TWI_ErrorStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrorStatus Local_Error= NoError;
	/*Send start condition*/
	 Set_Bit(TWCR_REG,TWCR_REG_TWSTA);
	/*Clear the interrupt flag to start the previous operation*/
	Set_Bit(TWCR_REG,TWCR_REG_TWINT);	  // cleared by setting the bit
	/*wait until the operation finishes and the flag is raised*/
	while(Get_Bit(TWCR_REG,TWCR_REG_TWINT)==0);
	/*Check the operation status*/
	if((TWSR_REG & 0xF8) != REP_START_ACK )
	{
		Local_Error = RepeatedStartError;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_Error;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus Local_Error= NoError;
	/*send the 7bit slave address to the bus*/
	//TWDR_REG = Copy_u8SlaveAddress | 0x00;
	TWDR_REG = Copy_u8SlaveAddress <<1 ;

	/*set the write request in the LSB in the data register*/
	  Clr_Bit(TWDR_REG,0);/* Master transmit ( slave address + Write request ) ACK */
	/*Clear the start condition bit*/
	  Clr_Bit(TWCR_REG,TWCR_REG_TWSTA);
	/*Clear the interrupt flag to start the previous operation*/
	  Set_Bit(TWCR_REG,TWCR_REG_TWINT);	  // cleared by setting the bit
	/*wait until the operation finishes and the flag is raised*/
	  while(Get_Bit(TWCR_REG,TWCR_REG_TWINT) ==0);
	/*Check the operation status*/
		  

	if((TWSR_REG & 0xF8) != SLAVE_ADD_AND_WR_ACK )
	{
		Local_Error = SlaveAddressWithWriteError;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_Error;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus Local_Error= NoError;
	/*send the 7bit slave address to the bus*/
	TWDR_REG = Copy_u8SlaveAddress <<1;

	/*set the write request in the LSB in the data register*/
	Set_Bit(TWDR_REG,0);/* Master transmit ( slave address + Write request ) ACK */
	/*Clear the start condition bit*/
	  Clr_Bit(TWCR_REG,TWCR_REG_TWSTA);
	/*Clear the interrupt flag to start the previous operation*/
	  Set_Bit(TWCR_REG,TWCR_REG_TWINT);	  // cleared by setting the bit
	/*wait until the operation finishes and the flag is raised*/
	  while(Get_Bit(TWCR_REG,TWCR_REG_TWINT)==0);
	/*Check the operation status*/
	if((TWSR_REG & 0xF8) != SLAVE_ADD_AND_RD_ACK )
	{
		Local_Error = SlaveAddressWithReadError;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_Error;
}

TWI_ErrorStatus TWI_MasterWriteDataByte(uint8 Copy_u8DataByte)
{
	TWI_ErrorStatus Local_Error= NoError;
	/*Write the data byte on the bus*/
	  TWDR_REG = Copy_u8DataByte;
	/*Clear the interrupt flag to start the previous operation*/
	  Set_Bit(TWCR_REG,TWCR_REG_TWINT);	  // cleared by setting the bit
	/*wait until the operation finishes and the flag is raised*/
	  while(Get_Bit(TWCR_REG,TWCR_REG_TWINT)==0);
	  
	/*Check the operation status*/
	if((TWSR_REG & 0xF8) !=  MSTR_WR_BYTE_ACK)
	{
		Local_Error = MasterWriteByteError;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_Error;
}

TWI_ErrorStatus TWI_MasterReadDataByte(uint8* Copy_pu8DataByte)
{
	TWI_ErrorStatus Local_Error= NoError;
	/*Clear the interrupt flag to allow the slave send the data*/
	  Set_Bit(TWCR_REG,TWCR_REG_TWINT);	  // cleared by setting the bit
	/*wait until the operation finishes and the flag is raised*/
	  while(Get_Bit(TWCR_REG,TWCR_REG_TWINT)==0);
	/*Check the operation status*/
	if((TWSR_REG & 0xF8) !=  MSTR_RD_BYTE_WITH_ACK)
	{
		Local_Error = MasterReadByteError;
	}
	else
	{
		/*Read the received data*/
		*Copy_pu8DataByte = TWDR_REG;
	}

	return Local_Error;
}
TWI_ErrorStatus TWI_SlaveReadDataByte(uint8* Copy_pu8DataByte)
{
	TWI_ErrorStatus Local_Error= NoError;
	/*Clear the interrupt flag to allow the slave send the data*/
	Set_Bit(TWCR_REG,TWCR_REG_TWINT);	  // cleared by setting the bit
	/*wait until the operation finishes and the flag is raised*/
	while(!Get_Bit(TWCR_REG,TWCR_REG_TWINT));
	/*Check the operation status*/
	if((TWSR_REG & 0xF8) !=  MSTR_RD_BYTE_WITH_ACK)
	{
		Local_Error = MasterReadByteError;
	}
	else
	{
		/*Read the received data*/
		*Copy_pu8DataByte = TWDR_REG;
	}

	return Local_Error;
}
void TWI_SendStopCondition(void)
{	 
	/*Send a stop condition on the bus*/
	 Set_Bit(TWCR_REG,TWCR_REG_TWSTO);
	/*Clear the interrupt flag to start the previous operation*/
	  Set_Bit(TWCR_REG,TWCR_REG_TWINT);	  // cleared by setting the bit
}





