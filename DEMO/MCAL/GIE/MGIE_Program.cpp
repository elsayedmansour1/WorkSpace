#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include "MGIE_Interface.h"
#include "MGIE_config.h"
#include "MGIE_Register.h"


void GIE :: MGIE_voidEnable (void)
{
	SET_BIT(SREG ,GIE_ENABLE);
}
void GIE :: MGIE_voidDisable (void)
{
	CLR_BIT(SREG ,GIE_ENABLE);
}
