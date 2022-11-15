/*
 * EEPROM_Interface.h
 *
 *  Created on: Feb 13, 2022
 *      Author: kareem ashraf
 */

#ifndef MCAL_EEPROM_HEADER_EEPROM_INTERFACE_H_
#define MCAL_EEPROM_HEADER_EEPROM_INTERFACE_H_

#include "EEPROM_Config.h"
#include "../../../SERVICE/Std_Types.h"

void EEPROM_INIT(void);
uint8 EEPROM_READ(uint32 Addres);
void EEPROM_WRITE(uint32 Addres , uint8 Data);





#endif /* MCAL_EEPROM_HEADER_EEPROM_INTERFACE_H_ */




