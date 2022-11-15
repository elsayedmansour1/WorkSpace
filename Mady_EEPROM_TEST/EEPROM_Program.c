/*
 * EEPROM_Program.c
 *
 *  Created on: Nov 11, 2022
 *      Author: elsay
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EEPROM_Interface.h"
#include "EEPROM_Config.h"
#include "TWI_Interface.h"
#include "avr/delay.h"

void EEPROM_voidInit()
{
	/*TWI initialization*/
	TWI_voidMasterInit();
}
void EEPROM_voidSendData(u8 Copy_u8Data,u16 Copy_u16Address)
{
	/*Start Condition*/
	TWI_voidStartCondition();
	/*send Unique address + A2 + 2 MSB +Write operation*/
	TWI_voidMasterSendSlaveAddWithWrite(Unique_Address|(A2<<2)|((u8)Copy_u16Address>>8));
	/*send data-->> the reset of wanted location*/
	TWI_voidMasterSendData((u8)Copy_u16Address);
	/*send data*/
	TWI_voidMasterSendData(Copy_u8Data);
	/*Send stop condition*/
	TWI_voidStopCondition();
	_delay_ms(50);

}
void EEPROM_voidReceiveData(u8 *Copy_u8Data,u16 Copy_u16Address)
{
	/*Start Condition*/
	TWI_voidStartCondition();
	/*send Unique address + A2 + 2 MSB +Write operation*/
	TWI_voidMasterSendSlaveAddWithWrite(Unique_Address|(A2<<2)|((u8)Copy_u16Address>>8));
	/*send data-->> the reset of wanted location*/
	TWI_voidMasterSendData((u8)Copy_u16Address);
	/*send repeated start */
	TWI_voidSendRepeatedStart();
	/*send slave address with read operation*/
	TWI_voidMasterSendSlaveAddWithRead(Unique_Address|(A2<<2)|((u8)Copy_u16Address>>8));
	/*receive data form the selected location*/
	TWI_u8MasterReceiveData(Copy_u8Data);
	/*send stop condition*/
	TWI_voidStopCondition();

}









