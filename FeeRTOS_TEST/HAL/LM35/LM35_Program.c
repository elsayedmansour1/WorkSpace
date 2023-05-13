/*
 * LM35_Program.c
 *
 *  Created on: May 13, 2023
 *      Author: user
 */
#include "../../LIB/STD_TYPES.h"
#include "LM35_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/ADC/ADC_Config.h"

void LM35_ReadTemperture(u8 ADC_Channel ,u16 *ADC_Result)
{
    ADC_Select_Channal(ADC_Channel);
    ADC_Enable();
    ADC_Start_Conversion();
    ADC_Wait_Flag();
    ADC_Get_Result(ADC_Result);
    *ADC_Result = ((5000UL*(*ADC_Result))>> 10) / 10 ;
}
