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
void Sensor_3(void *ptr);
void LCD_MonitoringTask1(void *ptr);
void LCD_MonitoringTask2(void *ptr);
void LCD_MonitoringTask3(void *ptr);

xSemaphoreHandle ledsem;
xSemaphoreHandle ADCsem;

u16 ADC_Result_S1=0;
u16 ADC_Result_S2=0;
u16 ADC_Result_S3=0;
f32 Volt=0;
f32 Current=0.0;
f32 Offset=2502;
f32 Sensitivity=185;
int main()
{

	vSemaphoreCreateBinary(ledsem);
	vSemaphoreCreateBinary(ADCsem);

	ADC_VidINIT();

	LCD_VidInit();

	LCD_VidWriteString("WELCOME ELSAYED");
	_delay_ms(1000);
	LCD_VoidClearDisplay();

	xTaskCreate(Sensor_1,NULL,100,NULL,6,NULL);
	xTaskCreate(Sensor_2,NULL,100,NULL,5,NULL);
	xTaskCreate(Sensor_3,NULL,100,NULL,4,NULL);
	xTaskCreate(LCD_MonitoringTask1,NULL,100,NULL,3,NULL);
	xTaskCreate(LCD_MonitoringTask2,NULL,100,NULL,2,NULL);
	xTaskCreate(LCD_MonitoringTask3,NULL,100,NULL,1,NULL);

	vTaskStartScheduler();

	while(1);
	return 0;
}

void Sensor_1(void *ptr)
{
	while(1)
	{
		if(xSemaphoreTake(ADCsem,0))
		{
		LM35_ReadTemperture(ADC0,&ADC_Result_S1);
		xSemaphoreGive(ADCsem);
		}
		vTaskDelay(1000);
	}

}

void Sensor_2(void *ptr)
{
	while(1)
	{
		if(xSemaphoreTake(ADCsem,0))
		{
	    LM35_ReadTemperture(ADC1,&ADC_Result_S2);
	    xSemaphoreGive(ADCsem);
		}
		vTaskDelay(1000);
	}

}

void Sensor_3(void *ptr)
{
	while(1)
	{
		if(xSemaphoreTake(ADCsem,0))
		{
	    ADC_Select_Channal(ADC2);
	    ADC_Enable();
	    ADC_Start_Conversion();
	    ADC_Wait_Flag();
	    ADC_Get_Result(&ADC_Result_S3);
	    Volt = (5000UL*(ADC_Result_S3))/1023 ;
	    Current =(f32)((Volt-Offset)/Sensitivity);
	    Current=Current*1000;
		xSemaphoreGive(ADCsem);
		}
		vTaskDelay(1000);
	}
}
void LCD_MonitoringTask1(void *ptr)
{
	LCD_GoToXY(0,0);
	LCD_VidWriteString("S1=");
	while(1)
	{

		if(xSemaphoreTake(ledsem,0))
		{
			LCD_GoToXY(0,3);
			LCD_VidWriteNumber(ADC_Result_S1);
			xSemaphoreGive(ledsem);
		}
		vTaskDelay(1000);
	}
}
void LCD_MonitoringTask2(void *ptr)
{
	LCD_GoToXY(1,0);
	LCD_VidWriteString("S2=");
	while(1)
	{
		if(xSemaphoreTake(ledsem,0))
		{
			LCD_GoToXY(1,3);
			LCD_VidWriteNumber(ADC_Result_S2);
			xSemaphoreGive(ledsem);
		}
		vTaskDelay(1000);
	}
}
void LCD_MonitoringTask3(void *ptr)
{
	LCD_GoToXY(0,8);
	LCD_VidWriteString("S3=");
	while(1)
	{
		if(xSemaphoreTake(ledsem,0))
		{
			LCD_GoToXY(0,11);
			LCD_VidWriteNumber(Current);
			xSemaphoreGive(ledsem);
		}
		vTaskDelay(1000);
	}
}
