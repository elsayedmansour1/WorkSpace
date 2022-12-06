#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "SPI_interface.h"
#include "SPI_Register.h"
#include "SPI_config.h"

void SPI_voidInit(void)
{
	#if (SPI_u8_MODE == SPI_u8_MASTER_MODE)
	/* Data Order = MSB First */
	CLR_BIT(SPCR,5);
	/* Select Master Mode */
	SET_BIT(SPCR,4);
    /* Clock Polatity Falling/Rising  Clock Phase Setup/Sample */
	SET_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	/* Select Clock Fosc/64 */
	SET_BIT(SPCR,1);
	CLR_BIT(SPCR,0);
		
	#elif (SPI_u8_MODE == SPI_u8_SLAVE_MODE)
	/* Data Order = MSB First */
	CLR_BIT(SPCR,5);
	/* Select Master Mode */
	SET_BIT(SPCR,4);
	/* Clock Polatity Falling/Rising  Clock Phase Setup/Sample */
	SET_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	#else
		#error "Wrong Choice"
	#endif

	/* Enable SPI */
	SET_BIT(SPCR,6);
	
}

u8   SPI_u8TransRecive(u8 Copy_u8DataByte ,u8 * Copy_pu8RecievedData)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu8RecievedData != NULL)
	{
		/* Send Data Byte */
		SPDR = Copy_u8DataByte;
		/* Check The Flag */
		while(!GET_BIT(SPDR,7));
		/* Read The Input Data */
		*Copy_pu8RecievedData = SPDR;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}
