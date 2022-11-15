/*
 * DIO_INT.h
 *
 *  Created on: Jun 11, 2022
 *      Author: Adel Khaled
 */

#ifndef WDIO_INT_H_
#define WDIO_INT_H_

		#define PORTA_ID 	0
		#define PORTB_ID 	1
		#define PORTC_ID 	2
		#define PORTD_ID 	3

		#define PINA_ID 	0
		#define PINB_ID 	1
		#define PINC_ID 	2
		#define PIND_ID 	3

		#define PIN0 		0
		#define PIN1 		1
		#define PIN2 		2
		#define PIN3 		3
		#define PIN4 		4
		#define PIN5 		5
		#define PIN6 		6
		#define PIN7 		7

		#define HIGH 		1
		#define LOW 		0

		#define INPUT 		0
		#define OUTPUT 		1

/*
 * Defining a C++ function as extern "C", tells the compiler to generate function
 * names and function calls that are compatible with the old "C" standard.
 * This way a C program can call C++ programs and the other way round.
 */
#ifdef __cplusplus
extern "C" {
#endif

		u8 WDIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue);
		u8 WDIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_PinStatus);

#ifdef __cplusplus
}
#endif

#endif /* WDIO_INT_H_ */
