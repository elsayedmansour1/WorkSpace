/*
 * GIE_Prog.c
 *
 *  Created on: Jan 23, 2022
 *      Author: kareem ashraf
 */

#include "../../../SERVICE/Bit_Math.h"
#include "../../../SERVICE/Std_Types.h"
#include "../../../MCAL/DIO/Header/Dio_Interface.h"
#include "../Header/GIE_Interface.h"
#include "../Header/GIE_Private.h"

void GIE_VoidEnable()
{
	GIE_SREG |=  (1<<GIE_SREG_I) ;

}
void GIE_VoidDisable()
{
	GIE_SREG &=~ (1<<GIE_SREG_I) ;
}
