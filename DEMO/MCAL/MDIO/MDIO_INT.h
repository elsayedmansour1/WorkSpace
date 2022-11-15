/*
 * DIO_INT.h
 *
 *  Created on: Jun 11, 2022
 *      Author: Adel Khaled
 */

#ifndef MDIO_INT_H_
#define MDIO_INT_H_

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PINA_ID 0
#define PINB_ID 1
#define PINC_ID 2
#define PIND_ID 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define HIGH 1
#define LOW 0

#define INPUT 0
#define OUTPUT 1

class DIO{
	private:
		// private variable
	public:
		DIO();
		void MDIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue);
		void MDIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_PinStatus);

};

#endif /* MDIO_INT_H_ */
