#ifndef _DIO_REG_H
#define _DIO_REG_H


/*****************************************************************************/
/*********************   Definitions of DIO Registers    *********************/
/*****************************************************************************/

#define PORTA 	*((volatile u8*) 0x3B)
#define DDRA  	*((volatile u8*) 0x3A)
#define PINA  	*((volatile u8*) 0x39)

#define PORTB 	*((volatile u8*) 0x38)
#define DDRB  	*((volatile u8*) 0x37)
#define PINB  	*((volatile u8*) 0x36)

#define PORTC 	*((volatile u8*) 0x35)
#define DDRC  	*((volatile u8*) 0x34)
#define PINC  	*((volatile u8*) 0x33)

#define PORTD 	*((volatile u8*) 0x32)
#define DDRD  	*((volatile u8*) 0x31)
#define PIND  	*((volatile u8*) 0x30)

#define PORTE 	*((volatile u8*) 0x23)
#define DDRE 	*((volatile u8*) 0x22)
#define PINE  	*((volatile u8*) 0x21)

#define PORTF 	*((volatile u8*) 0x62)
#define DDRF 	*((volatile u8*) 0x20)
#define PINF  	*((volatile u8*) 0x61)

#define PORTG 	*((volatile u8*) 0x65)
#define DDRG 	*((volatile u8*) 0x64)
#define PING 	*((volatile u8*) 0x63)













#endif
