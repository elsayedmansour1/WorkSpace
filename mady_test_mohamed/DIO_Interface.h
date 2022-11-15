# ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
#include "STD_TYPES.h"

#define DDRA    0
#define DDRB    1
#define DDRC    2
#define DDRD    3



#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3


/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/* PIN Value Options */
#define HIGH   1
#define LOW    0




void DIO_voidSetPinDirection  (u8 copy_u8PORTID ,u8 copy_u8PINID,u8 copy_u8Direction);

void DIO_voidSetPinValue  (u8 copy_u8PORTID ,u8 copy_u8PINID,u8 copy_u8Value);

u8 DIO_GetPinValue (u8 copy_u8PORTID ,u8 copy_u8PINID);

void SetPortDirection(u8 copy_u8PORTID,u8 copy_u8Direction);

void SetPortValue(u8 copy_u8PORTID,u8 copy_u8Value);

#endif