/*
 * main.c
 *
 *  Created on: Oct 30, 2022
 *      Author: elsay
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_config.h"
#include "TWI_Interface.h"
#include "avr/delay.h"

int main(void)
{
	//DIO_VidSetPinDirection(DIO_PORTC,PIN1,OUTPUT);//for DATA
	DIO_VidSetPinDirection(DIO_PORTC,PIN0,OUTPUT);//for Cloc k

	TWI_voidMasterInit();
	while(1)
	{
		TWI_voidStartCondition();
		TWI_voidMasterSendSlaveAddWithWrite(1);
		TWI_voidMasterSendData('4');
		TWI_voidStopCondition();
		_delay_ms(1000);
	}
}
