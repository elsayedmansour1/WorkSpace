#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "GIE_config.h"
#include "GIE_Register.h"


void GIE_Vid_Enable (void)
{
	SET_BIT(SREG ,GIE_ENABLE);
}
void GIE_Vid_Disable(void)
{
	CLR_BIT(SREG ,GIE_ENABLE);
}
