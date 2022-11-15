#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include "MGIE_config.h"
#include "MGIE_Register.h"


void GIE_Vid_Enable (void)
{
	SET_BIT(SREG ,GIE_ENABLE);
}
void GIE_Vid_Disable(void)
{
	CLR_BIT(SREG ,GIE_ENABLE);
}
