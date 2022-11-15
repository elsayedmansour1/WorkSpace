/*
 * main.c
 *
 *  Created on: Oct 29, 2022
 *      Author: elsay
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_config.h"
#include "TWI_Interface.h"


int main()
{
	DIO_VidSetPinDirection(DIO_PORTC,PIN0,OUTPUT);//for DATA
	DIO_VidSetPinDirection(DIO_PORTC,PIN1,OUTPUT);//for Clock

	TWI_voidMasterInit();
	while(1)
	{
		TWI_voidStartCondition();
		TWI_voidSendSlaveWithWrite(1);
		TWI_voidMasterSendData('a');
		TWI_voidStopCondition();
	}



	return 0;
}
