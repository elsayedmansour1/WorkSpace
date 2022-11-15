/*
 * main.c
 *
 *  Created on: Oct 28, 2022
 *      Author: engso
 */
#define F_CPU 8000000
#include <avr/delay.h>
#include "UART_interface.h"
#include "DioInterface.h"

#define ledport PORTA
#define led  0

void main(void) {
  DioSetPinDirection(PORTD,0,INPUT);
  DioSetPinDirection(PORTD,1,OUTPUT);
  //DioSetPinValue(PORTD,1,0);
 UART_Init();
  DioSetPinDirection(PORTA,0,OUTPUT);
  DioSetPinValue(PORTA,0,0);
 while(1)
 {
	 u8 data=UART_Receive();
    if(data=='a')
    {
        DioSetPinValue(PORTA,0,1);
    }
    UART_Transmit(data);

 }

}


