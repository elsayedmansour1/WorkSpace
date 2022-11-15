/*
 * EEPROM_Program.c
 *
 *  Created on: Nov 3, 2022
 *      Author: elsay
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_Interface.h"
#include "EEPROM_Interface.h"

#define Unique_address 0b10100000

void EEPROM_voidInit(void)
{
	/*Initialization the TWI Peripherals*/
	TWI_voidMasterInit();
}
void EEPRoM_voidWriteData(u8 Copy_u8Data,u16 Copy_u16Address)
{
	/*Start the communication*/
	TWI_voidStartCondition();
	/*send slave address + Write operation + MSB 2 bits*/
	TWI_voidMasterSendSlaveAddWithWrite(Unique_address|Copy_u16Address>>7);
	/*Send the reset of the location*/
	TWI_voidMasterSendData(Copy_u16Address<<8);
	/*send Data*/
	TWI_voidMasterSendData(Copy_u8Data);
	/*Stop the communication*/
	TWI_voidStopCondition();
}
void EEPRoM_voidReadData(u8 *Copy_u8Data,u16 Copy_u16Address)
{

}
