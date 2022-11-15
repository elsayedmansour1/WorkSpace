/*
 * EEPROM_Interface.h
 *
 *  Created on: Nov 11, 2022
 *      Author: elsay
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidInit();
void EEPROM_voidSendData(u8 Copy_u8Data,u16 Copy_u16Address);
void EEPROM_voidReceiveData(u8 *Copy_u8Data,u16 Copy_u16Address);

#endif /* EEPROM_INTERFACE_H_ */
