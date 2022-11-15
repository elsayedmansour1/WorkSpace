#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_config.h"

void (*Global_EXTI0_ptr)(void)=NULL;
void (*Global_EXTI1_ptr)(void)=NULL;
void (*Global_EXTI2_ptr)(void)=NULL;

void EXTI1_init(void)
{
    #if sense_mode==low_level
    CLR_BIT(MCUCR_Register,ISC11);
    CLR_BIT(MCUCR_Register,ISC10);
    CLR_BIT(MCUCR_Register,ISC01);
    CLR_BIT(MCUCR_Register,ISC00);
    #elif sense_mode==rising_edge
    CLR_BIT(MCUCR_Register,ISC11);
    SET_BIT(MCUCR_Register,ISC10);
    CLR_BIT(MCUCR_Register,ISC01);
    SET_BIT(MCUCR_Register,ISC00);
    #elif sense_mode==falling_edge
    SET_BIT(MCUCR_Register,ISC11);
    CLR_BIT(MCUCR_Register,ISC10);
    SET_BIT(MCUCR_Register,ISC01);
    CLR_BIT(MCUCR_Register,ISC00);
    #elif sense_mode==any_change
    SET_BIT(MCUCR_Register,ISC11);
    SET_BIT(MCUCR_Register,ISC10);
    SET_BIT(MCUCR_Register,ISC01);
    SET_BIT(MCUCR_Register,ISC00);
    #endif
}

void EXTI0_init(void)
{
    #if sense_mode==low_level
    CLR_BIT(MCUCR_Register,ISC01);
    CLR_BIT(MCUCR_Register,ISC00);
    #elif sense_mode==rising_edge
    CLR_BIT(MCUCR_Register,ISC01);
    SET_BIT(MCUCR_Register,ISC00);
    #elif sense_mode==falling_edge
    SET_BIT(MCUCR_Register,ISC01);
    CLR_BIT(MCUCR_Register,ISC00);
    #elif sense_mode==any_change
    SET_BIT(MCUCR_Register,ISC01);
    SET_BIT(MCUCR_Register,ISC00);
    #endif
}

void EXTI2_init(void)
{
    #if sense_mode==rising_edge
    SET_BIT(MCUSR_Register,ISC2);
    #elif sense_mode==falling_edge
    CLR_BIT(MCUSR_Register,ISC2);
    #endif
}

void EXTI0_enable(void)
{
    SET_BIT(GICR_Register,INT0);
}

void EXTI1_enable(void)
{
    SET_BIT(GICR_Register,INT1);
}

void EXTI2_enable(void)
{
    SET_BIT(GICR_Register,INT2);
}

void EXTI0_disable(void)
{
    CLR_BIT(GICR_Register,INT0);
}

void EXTI1_disable(void)
{
    CLR_BIT(GICR_Register,INT1);
}

void EXTI2_disable(void)
{
    CLR_BIT(GICR_Register,INT2);
}

void EXTI0_Callback(void (*ptr)(void))
{
    Global_EXTI0_ptr=ptr;
}

void EXTI1_Callback(void (*ptr)(void))
{
    Global_EXTI1_ptr=ptr;
}

void EXTI2_Callback(void (*ptr)(void))
{
    Global_EXTI2_ptr=ptr;
}

void __vector_1(void)__attribute__((signal));
void __vector_1()
{
    Global_EXTI0_ptr();
}
void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
    Global_EXTI1_ptr();
}
void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
    Global_EXTI2_ptr();
}
