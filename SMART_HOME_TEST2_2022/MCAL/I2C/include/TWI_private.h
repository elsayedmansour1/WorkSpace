/*******************************************************************/
/*******************************************************************/
/******** Author:    Ebraheem Elfishawy  ***************************/
/******** Component: TWI				 ***************************/
/******** Layer:     MCAL				 ***************************/
/*******************************************************************/
/*******************************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_


#include "../../../SERVICE/Std_Types.h"


#define TWCR_REG			*((volatile uint8*)0x56)	/*TWI Control Register*/
	#define TWCR_REG_TWINT	7						/*Interrupt Flag*/
	#define TWCR_REG_TWEA	6                       /*Enable Acknowledge*/
	#define TWCR_REG_TWSTA	5                       /*Start Condition*/
	#define TWCR_REG_TWSTO	4                       /*Stop Condition*/
	#define TWCR_REG_TWWC	3                       /*Write Collision*/
	#define TWCR_REG_TWEN	2                       /*Enable TWI*/
	#define TWCR_REG_TWIE	0                       /*Interrupt Enable*/

#define TWDR_REG 			*((volatile uint8*)0x23)   /*TWI Data Register*/

#define	TWAR_REG			*((volatile uint8*)0x22)   /*TWI Address Register*/
#define TWAR__REG_TWGCE		0						/*General Call recognition Enable*/

#define TWBR_REG			*((volatile uint8*)0x20)   /*TWI Bit Rate Register*/

#define TWSR_REG			*((volatile uint8*)0x21)   /*TWI Status Register*/
	#define TWSR_REG_TWPS0	0						/*Prescaler Bit0*/
	#define TWSR_REG_TWPS1	1						/*Prescaler Bit1*/
	
	#define START_ACK                0x08 /* start has been sent */
	#define REP_START_ACK            0x10 /* repeated start */
	#define SLAVE_ADD_AND_WR_ACK     0x18 /* Master transmit ( slave address + Write request ) ACK */
	#define SLAVE_ADD_AND_RD_ACK     0x40 /* Master transmit ( slave address + Read request ) ACK */
	#define MSTR_WR_BYTE_ACK         0x28 /* Master transmit data ACK */
	#define MSTR_RD_BYTE_WITH_ACK    0x50 /* Master received data with ACK */
	#define MSTR_RD_BYTE_WITH_NACK   0x58 /* Master received data with not ACK */
	#define SLAVE_ADD_RCVD_RD_REQ    0xA8 /* means that slave address is received with read request */
	#define SLAVE_ADD_RCVD_WR_REQ    0x60 /* means that slave address is received with write request */
	#define SLAVE_DATA_RECEIVED      0x80 /* means that a byte is received */
	#define SLAVE_BYTE_TRANSMITTED   0xB8 /* means that the written byte is transmitted */


 #define TWI_1_PRESCALER	1
 #define TWI_4_PRESCALER	4
 #define TWI_16_PRESCALER	16
 #define TWI_64_PRESCALER	64
 
 #define MSTR_NODE_ADDRESSABLE		1
 #define MSTR_NODE_NOT_ADDRESSABLE	2
#endif /* TWI_REG_H_ */
