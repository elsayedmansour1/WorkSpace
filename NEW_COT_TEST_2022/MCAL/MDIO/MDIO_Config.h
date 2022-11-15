/************************************************************************/
/**************** Name    : Elsayed Mansour Elsayed  ********************/
/**************** Date    :      29/05/2022          ********************/
/**************** SWC     :      DIO config          ********************/
/**************** Version :         1.0              ********************/
/************************************************************************/
#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

/* Options :  1- DIO_u8_INITIAL_INPUT 	  */
/*            2- DIO_u8_INITIAL_OUTPUT    */
		/*Port A Direction*/
#define DIO_u8_PA0_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PA1_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PA2_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PA3_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PA4_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PA5_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PA6_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PA7_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
		/*Port B Direction*/
#define DIO_u8_PB0_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT
#define DIO_u8_PB1_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT
#define DIO_u8_PB2_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT
#define DIO_u8_PB3_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT
#define DIO_u8_PB4_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT
#define DIO_u8_PB5_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT
#define DIO_u8_PB6_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT
#define DIO_u8_PB7_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT
		/*Port C Direction*/
#define DIO_u8_PC0_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PC1_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PC2_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PC3_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PC4_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PC5_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PC6_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
#define DIO_u8_PC7_INITIAL_DIRECTION                      DIO_u8_INITIAL_INPUT 
		/*Port D Direction*/
#define DIO_u8_PD0_INITIAL_DIRECTION                      DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD1_INITIAL_DIRECTION                      DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD2_INITIAL_DIRECTION                      DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD3_INITIAL_DIRECTION                      DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD4_INITIAL_DIRECTION                      DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD5_INITIAL_DIRECTION                      DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD6_INITIAL_DIRECTION                      DIO_u8_INITIAL_OUTPUT
#define DIO_u8_PD7_INITIAL_DIRECTION                      DIO_u8_INITIAL_OUTPUT


/*		 Macros for initial values	 	*/
/* Options = 	1- DIO_u8_INITIAL_INPUT_FLOATING	*/
/*             	2- DIO_u8_INITIAL_INPUT_PULLUP	*/
/*		3- DIO_u8_INITIAL_OUTPUT_LOW		*/
/*		4- DIO_u8_INITIAL_OUTPUT_HIGH		*/
		/*Port A Value*/ 
#define DIO_u8_PA0_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PA1_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PA2_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PA3_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PA4_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PA5_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PA6_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PA7_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
		/*Port B Value*/ 																	  
#define DIO_u8_PB0_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PB1_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PB2_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PB3_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PB4_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PB5_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PB6_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
#define DIO_u8_PB7_INITIAL_VALUE                          DIO_u8_INITIAL_OUTPUT_LOW
		/*Port C Value*/ 																	 
#define DIO_u8_PC0_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PC1_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PC2_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PC3_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PC4_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PC5_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PC6_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PC7_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
		/*Port D Value*/ 																	  
#define DIO_u8_PD0_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PD1_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PD2_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PD3_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PD4_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PD5_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PD6_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING
#define DIO_u8_PD7_INITIAL_VALUE                          DIO_u8_INITIAL_INPUT_FLOATING



#endif
