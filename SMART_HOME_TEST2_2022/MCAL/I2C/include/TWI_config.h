/*******************************************************************/
/*******************************************************************/
/******** Author:    Ebraheem Elfishawy  ***************************/
/******** Component: TWI				 ***************************/
/******** Layer:     MCAL				 ***************************/
/*******************************************************************/
/*******************************************************************/

#ifndef TWI_CONFIG_H_
#define TWI_CONFIG_H_
// page 173:
// SCL frequency = (CPU freq)/(16+(2*(TWBR)*4^TWPS)
// We need to get max SCL frequency which is 400kHz
#define SCL_EQN_TWBR	2	 // TWPR=
#define TWI_PRE_SCALER	TWI_1_PRESCALER // TWPS=
// SCL frequency = (8Mhz)/(16+(2*(10)*4^) = 100KHz

#define MSTR_NODE_ADDRESSING	MSTR_NODE_ADDRESSABLE
//#define MSTR_ADDRESS	11110000 // only MSB 7bits are master address if addressable

/*Slave addresses*/
 //#define SLAVE1_ADDRESS	11111000

#endif /* TWI_PRIVATE_H_ */
