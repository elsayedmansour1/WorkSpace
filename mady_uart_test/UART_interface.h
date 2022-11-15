
 
#ifndef UART_INTERFACE_H
#define	UART_INTERFACE_H
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_reg.h"

void UART_Init();
void UART_Transmit(u8 data);
u8 UART_Receive();
#endif	

