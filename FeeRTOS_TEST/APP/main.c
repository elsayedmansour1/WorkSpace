/*
 * main.c
 *
 *  Created on: Dec 6, 2022
 *      Author: .noa
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/ADC/ADC_Config.h"

#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LM35/LM35_Interface.h"

#include "../FREE_RTOS/FreeRTOSConfig.h"
#include "../Free_RTOS/FreeRTOS.h"
#include "../FREE_RTOS/task.h"
#include "../FREE_RTOS/semphr.h"

#include "avr/delay.h"
#include "../MCAL/DIO/DIO_Interface.h"

/*Prototype for tasks*/
void Sensor_1(void *ptr);
void Sensor_2(void *ptr);
void LCD_MonitoringTask1(void *ptr);
void LCD_MonitoringTask2(void *ptr);
xSemaphoreHandle ledsem;

u16 ADC_Result_S1=0;
u16 ADC_Result_S2=0;
int main()
{
	DIO_VidSetPinDirection(DIO_PORTA,PIN7,INPUT);//LM35_1
	DIO_VidSetPinDirection(DIO_PORTA,PIN6,INPUT);//LM35_2

	LCD_VidInit();

	ADC_VidINIT();

	LCD_VidWriteString("WELCOME ELSAYED");
	_delay_ms(1000);
	LCD_VoidClearDisplay();

	vSemaphoreCreateBinary(ledsem);

	xTaskCreate(Sensor_1,NULL,150,NULL,4,NULL);
	xTaskCreate(Sensor_2,NULL,150,NULL,3,NULL);
	xTaskCreate(LCD_MonitoringTask1,NULL,250,NULL,1,NULL);
	xTaskCreate(LCD_MonitoringTask2,NULL,250,NULL,0,NULL);

	vTaskStartScheduler();

	while(1);
	return 0;
}
void Sensor_1(void *ptr)
{
	while(1)
	{
		LM35_ReadTemperture(ADC6,&ADC_Result_S1);
		vTaskDelay(1000);
	}

}
void Sensor_2(void *ptr)
{
	while(1)
	{
	    LM35_ReadTemperture(ADC7,&ADC_Result_S2);
		vTaskDelay(1000);
	}

}
void LCD_MonitoringTask1(void *ptr)
{
	LCD_GoToXY(0,0);
	LCD_VidWriteString("Sensor1=");
	while(1)
	{
		if(xSemaphoreTake(ledsem,0))
		{
			LCD_GoToXY(0,8);
			LCD_VidWriteNumber(ADC_Result_S1);
			xSemaphoreGive(ledsem);
		}
		vTaskDelay(1000);
	}
}
void LCD_MonitoringTask2(void *ptr)
{
	LCD_GoToXY(1,0);
	LCD_VidWriteString("Sensor2=");
	while(1)
	{
		if(xSemaphoreTake(ledsem,0))
		{
			LCD_GoToXY(1,8);
			LCD_VidWriteNumber(ADC_Result_S2);
			xSemaphoreGive(ledsem);
		}
		vTaskDelay(1000);
	}
}
