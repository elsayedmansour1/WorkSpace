
/*
 * INTERRUPTS_interface.h
 *
 * Created    : 1/23/2022 9:21:04 AM
 * Author     : Ebraheem El-Feshawy
 * Description:
 */ 

#ifndef _INTERRUPTS_INTERFACE_H
#define _INTERRUPTS_INTERFACE_H
#include "INTERRUPTS_config.h"
#include "INTERRUPTS_private.h"


/*##################################################################################
# FUNCTION NAME : EXT_INT_Void_INT0_Init()										   #
# ARGUMENTS     : No arguments needed											   #
# RETURN        : No return expected											   #
# DESCRIPTION   : This function is used to initialize Interrupt 0:				   #
												1- Sense mode					   #
												2- State (Enabled/Disabled)		   #
##################################################################################*/
void EXT_INT_Void_INT0_Init(void);

/*##################################################################################
# FUNCTION NAME : EXT_INT_Void_INT1_Init()										   #
# ARGUMENTS     : No arguments needed											   #
# RETURN        : No return expected											   #
# DESCRIPTION   : This function is used to initialize Interrupt 1:				   #
												1- Sense mode					   #
												2- State (Enabled/Disabled)		   #
##################################################################################*/
void EXT_INT_Void_INT1_Init(void);

/*##################################################################################
# FUNCTION NAME : EXT_INT_Void_INT2_Init()										   #
# ARGUMENTS     : No arguments needed											   #
# RETURN        : No return expected											   #
# DESCRIPTION   : This function is used to initialize Interrupt 2:				   #
												1- Sense mode					   #
												2- State (Enabled/Disabled)		   #
##################################################################################*/
void EXT_INT_Void_INT2_Init(void);
//##################################################################
void __vector_1(void)__attribute__((signal));
void __vector_2(void)__attribute__((signal));
void __vector_3(void)__attribute__((signal));
#endif
