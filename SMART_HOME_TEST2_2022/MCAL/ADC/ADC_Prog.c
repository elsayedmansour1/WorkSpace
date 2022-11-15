#include "../../SERVICE/Std_Types.h"
#include "../../SERVICE/Bit_Math.h"
#include"ADC_Config.h"
#include"ADC_Reg.h"


void ADC_VidINIT(void)
{
	/***********ADC VOLTAGE REFFRANCE ***********/
	#if 	ADC_Vref==Vref_turned_off
		Clr_Bit(ADMUX,REFS0);
		Clr_Bit(ADMUX,REFS1);
	#elif	ADC_Vref==Vref_AVCC
		Set_Bit(ADMUX,REFS0);
		Clr_Bit(ADMUX,REFS1);
	#elif 	ADC_Vref==Vref_Internal
		Set_Bit(ADMUX,REFS0);
		Set_Bit(ADMUX,REFS1);
	#endif
	/**************ADC Prescaler ***************/
	#if	ADC_Prescaler==ADC_Prescaler_2
			 Clr_Bit(ADCSRA,ADPS0);\
			 Clr_Bit(ADCSRA,ADPS1);\
			 Clr_Bit(ADCSRA,ADPS2);
	#elif	ADC_Prescaler==ADC_Prescaler_4
			 Clr_Bit(ADCSRA,ADPS0);\
			 Set_Bit(ADCSRA,ADPS1);\
			 Clr_Bit(ADCSRA,ADPS2);
	#elif     ADC_Prescaler==ADC_Prescaler_8
			 Set_Bit(ADCSRA,ADPS0);\
			 Set_Bit(ADCSRA,ADPS1);\
			 Clr_Bit(ADCSRA,ADPS2);
	#elif     ADC_Prescaler==ADC_Prescaler_16
			 Clr_Bit(ADCSRA,ADPS0);\
			 Clr_Bit(ADCSRA,ADPS1);\
			 Set_Bit(ADCSRA,ADPS2);
	#elif     ADC_Prescaler==ADC_Prescaler_32
			 Set_Bit(ADCSRA,ADPS0);\
			 Clr_Bit(ADCSRA,ADPS1);\
			 Set_Bit(ADCSRA,ADPS2);
	#elif     ADC_Prescaler==ADC_Prescaler_64
			 Clr_Bit(ADCSRA,ADPS0);
			 Set_Bit(ADCSRA,ADPS1);
			 Set_Bit(ADCSRA,ADPS2);
	#elif     ADC_Prescaler==ADC_Prescaler_128
			 Set_Bit(ADCSRA,ADPS0);\
			 Set_Bit(ADCSRA,ADPS1);\
			 Set_Bit(ADCSRA,ADPS2);
	#endif

	/************ ADC SAVE FROM **************/
	#if  	ADC_SAVE_FROM==Right_Adjust
		Clr_Bit(ADMUX,ADLAR);
	#elif	ADC_SAVE_FROM==Left_Adjust
		Set_Bit(ADMUX,ADLAR);

	#endif
	/***************ADC MODE******************/
	#if	ADC_Mode==ADC_Single_Conversion
		Clr_Bit(ADCSRA,ADATE);
	#elif	ADC_Mode==ADC_Free_Running
		Set_Bit(ADCSRA,ADATE);
		Clr_Bit(SFIOR,ADTS0);
		Clr_Bit(SFIOR,ADTS1);
		Clr_Bit(SFIOR,ADTS2);
	#elif	ADC_Mode==ADC_External_Interrupt_0_Trigger
		Set_Bit(ADCSRA,ADATE);
		Clr_Bit(SFIOR,ADTS0);
		Set_Bit(SFIOR,ADTS1);
		Clr_Bit(SFIOR,ADTS2);
	
	#endif
		/************ADC ENABLE ******************/
		Set_Bit(ADCSRA,ADEN);
}
void ADC_Start_Conversion(void)
{
	Set_Bit(ADCSRA,ADSC);
}
void ADC_Select_Channal(uint8 Channal)
{
	ADMUX&=0B11100000;
	ADMUX|=Channal;
}
void ADC_Interrupt_Enable(void)
{
	Set_Bit(ADCSRA,ADIE);
}
void ADC_Wait_Flag(void)
{
	while(Get_Bit(ADCSRA,ADIF)!=1); //WAIT UNTILL FLAG=1
	Set_Bit(ADCSRA,ADIF);	  //CLEAR FLAG
}
void ADC_Get_Result(uint16 *ptr)
{
	*ptr=ADC;
}




