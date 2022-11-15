
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Interface.h"
#include "ADC_Register.h"
#include"avr/delay.h"



void ADC_INTI(void)
{
	
	//Voltage Reference
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	//Right Adjust Result
	CLR_BIT(ADMUX,5);
	
	//ADC Prescaler Select Bits (8)
	CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

	//ADC ENABLE
	SET_BIT(ADCSRA,7);
}

u16 ADC_GET_RES (void)
{
	//ADC Start Conversion
	SET_BIT(ADCSRA,6);

	while (GET_BIT(ADCSRA,4)==0)
	{
	}
	//ADC Interrupt Flag
	SET_BIT(ADCSRA,4);

	return ADC ;

}

void set_channel(u8 channel_id)
{

	ADMUX =ADMUX &0B11100000;
	
	ADMUX=ADMUX|channel_id;
	
	
}











