

#include "../../SERVICE/Bit_Math.h"
#include "../../SERVICE/Std_Types.h"

#include "WDT_interface.h"

#define WDT_u8_WDTCR_REG             *((volatile uint8 *)0x41)

void WDT_voidEnable(void)
{
	/* Select Prescaler => 2.1 Sec */
	WDT_u8_WDTCR_REG = 0b00001111;
}

void WDT_voidDisable(void)
{
	/* Turn OFF Enable */
	WDT_u8_WDTCR_REG |= (1<<4)|(1<<3);
	
	WDT_u8_WDTCR_REG = 0x00;
}
