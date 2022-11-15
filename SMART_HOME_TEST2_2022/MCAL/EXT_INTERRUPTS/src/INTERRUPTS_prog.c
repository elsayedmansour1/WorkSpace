
/*
 * INTERRUPTS_prog.c
 *
 * Created: 1/23/2022 9:21:57 AM
 *  Author: Ebraheem El-Feshawy
 */ 

#include "../include/INTERRUPTS_interface.h"
#include "../../GIE/Header/GIE_Interface.h"
#include "../../../SERVICE/Bit_Math.h"

void EXT_INT_Void_INT0_Init(void)
{					  
	/*1* SELECTING SENSE CONTROL MODE***/
	#if   INT0_SENSE_MODE == LOW_LEVEL     
	    Clr_Bit(EXT_MCUCR_REG,MCUCR_ISC00);
	    Clr_Bit(EXT_MCUCR_REG,MCUCR_ISC01);
	#elif INT0_SENSE_MODE == ON_CHANGE
	    Set_Bit(EXT_MCUCR_REG,MCUCR_ISC00);
		Clr_Bit(EXT_MCUCR_REG,MCUCR_ISC01);
	#elif INT0_SENSE_MODE == FALING_EDGE
		Clr_Bit(EXT_MCUCR_REG,MCUCR_ISC00);
		Set_Bit(EXT_MCUCR_REG,MCUCR_ISC01);
	#elif INT0_SENSE_MODE == RISING_EDGE
		Set_Bit(EXT_MCUCR_REG,MCUCR_ISC00);
		Set_Bit(EXT_MCUCR_REG,MCUCR_ISC01);
	#else
		#error "Error: WRONG INT0_SENSE_MODE Configuration option"
	#endif
	/*2*Check peripheral  interrupt enable initial state*/
	#if   EXT_INT0_STATE == EXT_ENABLED			// Enable external interrupt pin INT0
		Set_Bit(EXT_GICR_REG, GICR_INT0 );
	#elif EXT_INT0_STATE == EXT_DISABLED		// Disable external interrupt pin INT0
		Clr_Bit(EXT_GICR_REG, GICR_INT0 );
	#else
		#error "Error: WRONG EXT_INT0_STATE Configuration option"
	#endif
}

void EXT_INT_Void_INT1_Init(void)
{
	/*1* SELECTING SENSE CONTROL MODE***/
	#if   INT1_SENSE_MODE == LOW_LEVEL
	Clr_Bit(EXT_MCUCR_REG,MCUCR_ISC10);
	Clr_Bit(EXT_MCUCR_REG,MCUCR_ISC11);
	#elif INT1_SENSE_MODE == ON_CHANGE
	Set_Bit(EXT_MCUCR_REG,MCUCR_ISC10);
	Clr_Bit(EXT_MCUCR_REG,MCUCR_ISC11);
	#elif INT1_SENSE_MODE == FALING_EDGE
	Clr_Bit(EXT_MCUCR_REG,MCUCR_ISC10);
	Set_Bit(EXT_MCUCR_REG,MCUCR_ISC11);
	#elif INT1_SENSE_MODE == RISING_EDGE
	Set_Bit(EXT_MCUCR_REG,MCUCR_ISC10);
	Set_Bit(EXT_MCUCR_REG,MCUCR_ISC11);
	#else
		#error "Error: WRONG INT1_SENSE_MODE Configuration option"
	#endif
	
	/*2*Check peripheral  interrupt enable initial state*/
	#if   EXT_INT1_STATE == EXT_ENABLED
	Set_Bit(EXT_GICR_REG, GICR_INT1 );		// Enable external interrupt pin INT1
	#elif EXT_INT1_STATE == EXT_DISABLED
	Clr_Bit(EXT_GICR_REG, GICR_INT1 );		// Disable external interrupt pin INT1
	#else
		#error "Error: WRONG EXT_INT1_STATE Configuration option"
	#endif
}

void EXT_INT_Void_INT2_Init(void)
{
	/*1* SELECTING SENSE CONTROL MODE***/
	#if INT2_SENSE_MODE   == FALING_EDGE
	Clr_Bit(EXT_MCUCR_REG,MCUCSR_ISC_2);
	#elif INT2_SENSE_MODE == RISING_EDGE
	Set_Bit(EXT_MCUCR_REG,MCUCSR_ISC_2);
	#else
		//#error "Error: WRONG INT2_SENSE_MODE Configuration option"
	#endif
	
	/*2*Check peripheral  interrupt enable initial state*/
	#if   EXT_INT2_STATE == EXT_ENABLED
	Set_Bit(EXT_GICR_REG, GICR_INT2 );		// Enable external interrupt pin INT2
	#elif EXT_INT0_STATE == EXT_DISABLED
	Clr_Bit(EXT_GICR_REG, GICR_INT2 );		// Disable external interrupt pin INT2
	#else
		#error "Error: WRONG EXT_INT2_STATE Configuration option"
	#endif
	
}

