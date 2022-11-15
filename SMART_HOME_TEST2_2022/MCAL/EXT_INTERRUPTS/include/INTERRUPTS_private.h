
/*
 * INTERRUPTS_private.h
 *
 * Created: 1/23/2022 9:20:37 AM
 *  Author: Ebraheem El-Feshawy
 */ 
#ifndef _INTERRUPTS_PRIVATE_H
#define _INTERRUPTS_PRIVATE_H
#include "INTERRUPTS_config.h"
#include "../../GIE/Header/GIE_Interface.h"
#include "../../DIO/Header/Dio_Interface.h"


/***** EXTERNAL INTERRUPTS AVAILABLE PORTS & PINS**/
#define INT0_PORT					PORT_D
#define INT0_PIN					PIN_2 // pin 2 in port D

#define INT1_PORT					PORT_D
#define INT1_PIN					PIN_3 // pin 3 in port D

#define INT2_PORT					PORT_B
#define INT2_PIN					PIN_2 // pin 3 in port B


/******************************************** REGISTERS **********************/
  /******** REGISTERS ADDRESSES and PINS *****/
     /***************SREG**********/
	 // General Interrupt Control Register
     #define EXT_SREG_REG			*((volatile uint8 *)0X5F) //enable or disable I_Bit for ALL INTERRUPTs
       #define SREG_I_BIT			7 //This bit is in SREG Register and used to enable or disable I_Bit for ALL INTERRUPTs
     
     #define EXT_OCR0_REG			*((volatile uint8 *)0X5C)
     
     /***************GICR**********/
     #define EXT_GICR_REG			*((volatile uint8 *)0X5B)
     
       #define GICR_INT0			6 // in GICR Register and This bit is used to enable or disable INTERRUPT 0
       #define GICR_INT1			7 // in GICR Register and This bit is used to enable or disable INTERRUPT 1
       #define GICR_INT2			5 // in GICR Register and This bit is used to enable or disable INTERRUPT 2
     
     /**************GIFR**********/
     #define EXT_GIFR_REG			*((volatile uint8 *)0X5A)
	 
	 #define GIFR_INT0				6 // in GIFR Register and This bit is used to read INTERRUPT 0
	 #define GIFR_INT1				7 // in GIFR Register and This bit is used to read INTERRUPT 1
	 #define GIFR_INT2				5 // in GIFR Register and This bit is used to read INTERRUPT 2
	 
     
     /**************MCUCR FOR INT0, INT1**********/
     #define EXT_MCUCR_REG			*((volatile uint8 *)0X55) //used to select interrupt sense control mode
     
        /*For INT0*/
        #define MCUCR_ISC00			0 /*At MCUCR Register Those two bits are used to select interrupt sense control mode*/
        #define MCUCR_ISC01			1 /*for interrupt 0 (check data sheet)*/
        /*For INT1*/
        #define MCUCR_ISC10			2 /*At MCUCR Register Those two bits are used to select interrupt sense control mode*/
        #define MCUCR_ISC11			3 /*for interrupt 1 (check data sheet)*/
     
     /************** MCUCRS FOR INT2**********/
     #define EXT_MCUCSR_REG			*((volatile uint8 *)0X54)
        /*For INT2*/
        #define MCUCSR_ISC_2		6 /*At MCUCSR Register This bit is used to select interrupt sense control mode*/
								      /* for interrupt 2 (check data sheet)*/


/**************************************** ALL ABOUT SENSE MODE **************/
/*Defining Sense Modes*/
#define LOW_LEVEL					1
#define ON_CHANGE					2
#define FALING_EDGE					3
#define RISING_EDGE					4
/*********/
#define EXT_ENABLED					1
#define EXT_DISABLED				2

/******************************************** VECTOR TABLE *****************/
#define RESET_VECTOR				((volatile u8 *)0X00)
#define INT0_VECTOR					((volatile u8 *)0X02)
#define INT1_VECTOR					((volatile u8 *)0X04)
#define INT2_VECTOR					((volatile u8 *)0X06)
#define	TIMER2_COMP_VECTOR			((volatile u8 *)0X08)
#define	TIMER2_OVF_VECTOR			((volatile u8 *)0X0A)
#define	TIMER1_CAPT_VECTOR			((volatile u8 *)0X0C)
#define	TIMER1_COMPA_VECTOR			((volatile u8 *)0X0E)
#define	TIMER1_COMPB_VECTOR			((volatile u8 *)0X10)
#define	TIMER1_OVF_VECTOR			((volatile u8 *)0X12)
#define	TIMER0_COMP_VECTOR			((volatile u8 *)0X14)
#define	TIMER0_OVF_VECTOR			((volatile u8 *)0X16)
#define	SPI_STC_VECTOR				((volatile u8 *)0X18)
#define	USART_RXC_VECTOR			((volatile u8 *)0X1A)
#define USART_UDRE_VECTOR			((volatile u8 *)0X1C)
#define USART_TXC_VECTOR			((volatile u8 *)0X1E)
#define ADC_VECTOR					((volatile u8 *)0X20)
#define EE_RDY_VECTOR				((volatile u8 *)0X22)
#define ANA_COMP_VECTOR				((volatile u8 *)0X24)
#define TWI_VECTOR					((volatile u8 *)0X26)
#define SPM_RDY_VECTOR				((volatile u8 *)0X28)
#endif




