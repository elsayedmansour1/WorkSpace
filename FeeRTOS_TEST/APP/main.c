/*
 * main.c
 *
 *  Created on: Dec 6, 2022
 *      Author: .noa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"

#include "../FREE_RTOS/FreeRTOSConfig.h"
#include "../Free_RTOS/FreeRTOS.h"
#include "../FREE_RTOS/task.h"

/*Prototype for tasks*/
void LED_Task1(void *ptr);
void LED_Task2(void *ptr);


int main()
{
	DIO_VidSetPinDirection(DIO_PORTA,PIN0,OUTPUT);//led1
	DIO_VidSetPinDirection(DIO_PORTA,PIN1,OUTPUT);//led2

	xTaskCreate(LED_Task1,NULL,100,NULL,1,NULL);
	xTaskCreate(LED_Task2,NULL,100,NULL,1,NULL);

	vTaskStartScheduler();

	while(1)
	{

	}
	return 0;
}
void LED_Task1(void *ptr)
{
	while(1)
	{
		DIO_u8TogglePinValue(DIO_PORTA,PIN0);
	}

}
void LED_Task2(void *ptr)
{
	while(1)
	{
		DIO_u8TogglePinValue(DIO_PORTA,PIN1);
	}
}
