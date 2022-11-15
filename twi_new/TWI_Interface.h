/*
 * TWI_Interface.h
 *
 *  Created on: Oct 29, 2022
 *      Author: elsay
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

void TWI_voidMasterInit(void);
void TWI_voidSlaveInit(void);
void TWI_voidStartCondition(void);
void TWI_voidSendSlaveWithWrite(u8 copy_u8Address);
void TWI_voidSendSlaveWithRead(u8 copy_u8Address);
void TWI_voidMasterSendData(u8 Copy_u8Data);
//void TWI_voidMasteReceiveData(u8 Copy_u8Data);
void TWI_voidStopCondition(void);
#endif /* TWI_INTERFACE_H_ */

