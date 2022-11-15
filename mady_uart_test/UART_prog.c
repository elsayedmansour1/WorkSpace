/*
 * UART_prog.c
 *
 *  Created on: Oct 28, 2022
 *      Author: engso
 */
/*
 * File:   UART_prog.c
 * Author: Ingi
 *
 * Created on October 22, 2022, 1:45 PM
 */

/*
             UART using polling

 */

//com4
#include "UART_interface.h"
u8 temp=0; //used to map values once to UCSRC

void UART_Init() {
    // RX,TX enable
    SET_BIT(UCSRB, 4);
    SET_BIT(UCSRB, 3);
    //no of data bits=8
    // *CLR bit 2 UCSRB
    CLR_BIT(UCSRB, 2);
   // *SET bit 1,0 UCSRC
    SET_BIT(temp, 2);
    SET_BIT(temp, 1);
    //UCSRC
    SET_BIT(temp, 7);
    //asynchronous
    CLR_BIT(temp, 6);
    //no parity
    CLR_BIT(temp, 5);
    CLR_BIT(temp, 4);
    // one stop bit
    CLR_BIT(temp, 3);

    UCSRC=temp;
    //baud rate=9600  with 8MHZ freq
    UCSRC=0x00;
    UBRRL=51;
}
void UART_Transmit(u8 data){
    UDR=data;
    while(GET_BIT(UCSRA,6)==0); //wait until flag is set (transmission done))
    SET_BIT(UCSRA,6);           //clear flag
}

u8 UART_Receive(){
    u8 data=0;
    while(GET_BIT(UCSRA,7)==0);
    data=UDR;
    return data;
}


