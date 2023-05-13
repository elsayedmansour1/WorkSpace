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
	    ADC_Select_Channal(ADC7);
	    ADC_Enable();
	    ADC_Start_Conversion();
	    ADC_Wait_Flag();
	    ADC_Get_Result(&ADC_Result_S1);
		vTaskDelay(1000);
	}

}
void Sensor_2(void *ptr)
{
	while(1)
	{
	    ADC_Select_Channal(ADC6);
	    ADC_Enable();
	    ADC_Start_Conversion();
	    ADC_Wait_Flag();
	    ADC_Get_Result(&ADC_Result_S2);
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
			u16 Temperature=5;
			Temperature = ((5000UL*ADC_Result_S1)>> 10) / 10 ;
			LCD_VidWriteNumber(Temperature);
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
			u16 Temperature=5;
			Temperature = ((5000UL*ADC_Result_S2)>> 10) / 10 ;
			LCD_VidWriteNumber(Temperature);
			xSemaphoreGive(ledsem);
		}
		vTaskDelay(1000);
	}
}
