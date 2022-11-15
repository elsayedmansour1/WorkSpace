/*
 * Dio-Private.h
 *
 *  Created on: Jan 12, 2022
 *      Author: kareem ashraf
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/********************************REGISTER DEFINATION *****************************/
#include "../../../SERVICE/Std_Types.h"


/*******************************GROUP A****************************************/
#define PORTA_REG *((volatile uint8 *)0x3B)
#define DDRA_REG  *((volatile uint8 *)0x3A)
#define PINA_REG  *((volatile uint8 *)0x39)


/*******************************GROUP B****************************************/
#define PORTB_REG *((volatile uint8 *)0x38)
#define DDRB_REG  *((volatile uint8 *)0x37)
#define PINB_REG  *((volatile uint8 *)0x36)



/*******************************GROUP C****************************************/
#define PORTC_REG *((volatile uint8 *)0x35)
#define DDRC_REG  *((volatile uint8 *)0x34)
#define PINC_REG  *((volatile uint8 *)0x33)



/*******************************GROUP D****************************************/
#define PORTD_REG *((volatile uint8 *)0x32)
#define DDRD_REG  *((volatile uint8 *)0x31)
#define PIND_REG  *((volatile uint8 *)0x30)

/*********************************Frequancy*************************************/










#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
