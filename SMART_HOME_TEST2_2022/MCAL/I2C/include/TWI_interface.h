/*********************************************************************/
/*********************************************************************/
/******** Author:    Ebraheem Elfishawy    ***************************/
/******** Component: TWI                   ***************************/
/******** Layer:     MCAL                  ***************************/
/*********************************************************************/
/*********************************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_
#include "TWI_private.h"
#include "TWI_config.h"
#include "../../../SERVICE/Std_Types.h"
typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteError,
	MasterReadByteError,
}TWI_ErrorStatus;

void 		    TWI_voidInitMaster(uint8 Copy_u8Address);

void		    TWI_voidInitSlave(uint8 Copy_u8Address);

TWI_ErrorStatus TWI_SendStartCondition(void);
	   
TWI_ErrorStatus TWI_SendRepeatedStart(void);
	   
TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress);
	   
TWI_ErrorStatus TWI_SendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress);
	   
TWI_ErrorStatus TWI_MasterWriteDataByte(uint8 Copy_u8DataByte);
	   
TWI_ErrorStatus TWI_MasterReadDataByte(uint8* Copy_pu8DataByte);

TWI_ErrorStatus TWI_SlaveReadDataByte(uint8* Copy_pu8DataByte);

void 			TWI_SendStopCondition(void);


#endif
