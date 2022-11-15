#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"../GIE/MGIE_config.h"
#include "MEXTI_Config.h"
#include "MEXTI_Register.h"

/*Make a Global Pointer To Function for every Set Call Back Function*/
static void (*GPFunc0)(void)=NULL;
static void (*GPFunc1)(void)=NULL;
static void (*GPFunc2)(void)=NULL;
/******************************************************************/
/*Make a Set Call Back Function for every Interrupt peripherals in External Interrupts*/
			/*Set Call Back Functions for External Interrupt zero*/
void INT0_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc0=LocPFunc;	
}
/*Set Call Back Functions for External Interrupt one*/

void INT1_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc1=LocPFunc;	
}
/*Set Call Back Functions for External Interrupt two*/

void INT2_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc2=LocPFunc;	
}
/***************************************************************************/
/*Make a ISR Function for every Interrupt peripherals in External Interrupt*/
			/*ISR Functions for External Interrupt Zero*/
ISR(__vector_1)
{
	if(GPFunc0!=NULL)
	{
		GPFunc0();
	}
}
			/*ISR Functions for External Interrupt Zero*/
ISR(__vector_2)
{
	if(GPFunc1!=NULL)
	{
		GPFunc1();
	}
}
			/*ISR Functions for External Interrupt Zero*/
ISR(__vector_3)
{
	if(GPFunc2!=NULL)
	{
		GPFunc2();
	}
}


void EX_INT0_INIT(void)
{
	/*ENABLE EXTERNAL ENTERRUPT 0*/
	SET_BIT(GICR ,INT0);
	/*CHOOSE MODE*/
	#if   MODE_INT0==Falling_Adge
	CLR_BIT(MCUCR ,ISC00);
	SET_BIT(MCUCR ,ISC01);
	#elif MODE_INT0==Rising_Adge
	SET_BIT(MCUCR ,ISC00);
	SET_BIT(MCUCR ,ISC01);
	#elif MODE_INT0==Low_Level
	CLR_BIT(MCUCR ,ISC00);
	CLR_BIT(MCUCR ,ISC01);
	#elif MODE_INT0==Any_Change
	SET_BIT(MCUCR ,ISC00);
	CLR_BIT(MCUCR ,ISC01);
	#endif
}
void EX_INT1_INIT(void)
{
	/*ENABLE EXTERNAL ENTERRUPT 1*/
	SET_BIT(GICR ,INT1);
	/*CHOOSE MODE*/
	#if   MODE_INT1==Falling_Adge
	CLR_BIT(MCUCR ,ISC10);
	SET_BIT(MCUCR ,ISC11);
	#elif MODE_INT1==Rising_Adge
	SET_BIT(MCUCR ,ISC10);
	SET_BIT(MCUCR ,ISC11);
	#elif MODE_INT1==Low_Level
	CLR_BIT(MCUCR ,ISC10);
	CLR_BIT(MCUCR ,ISC11);
	#elif MODE_INT1==Any_Change
	SET_BIT(MCUCR ,ISC10);
	CLR_BIT(MCUCR ,ISC11);

	#endif	
}
void EX_INT2_INIT(void)
{
	/*ENABLE EXTERNAL ENTERRUPT 2*/
	SET_BIT(GICR ,INT2);
	/*CHOOSE MODE*/
	#if   MODE_INT2==Falling_Adge
	CLR_BIT(MCUCSR ,ISC2);
	#elif MODE_INT2==Rising_Adge
	SET_BIT(MCUCSR ,ISC2);

	#endif
}
