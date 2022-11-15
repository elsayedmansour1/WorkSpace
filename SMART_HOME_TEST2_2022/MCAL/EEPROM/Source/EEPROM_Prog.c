/*
 * EEPROM_Prog.c
 *
 *  Created on: Feb 13, 2022
 *      Author: kareem ashraf
 */


#include "../Header/EEPROM_Interface.h"
#include "../../../MCAL/DIO/Header/Dio_Interface.h"
#include "../../../SERVICE/Bit_Math.h"
#include "../../../SERVICE/Std_Types.h"

void EEPROM_INIT(void)
{
    #if ACTION_MODE   ==   POLLING
	Clr_Bit( EECR_REG , EECR_REG_EERIE ) ;

	#elif  CTION_MODE   ==   ISR
	Set_Bit( EECR_REG , EECR_REG_EERIE ) ;

	#endif
}

uint8 EEPROM_READ(uint32 Addres)
{
	while( Get_Bit(EECR_REG,EECR_REG_EEWE)  ==1);
	EEARL_LOW_HIGH = Addres  ; // ADDERS

	Set_Bit( EECR_REG , EECR_REG_EERE ) ;// READ  ENABLE
	return EEDR_REG ;   // return data
}

               // ADDRES 255 LOCATION
void EEPROM_WRITE(uint32 Addres, uint8 Data)
{
	while(Get_Bit(EECR_REG,EECR_REG_EEWE)  ==1);
	EEARL_LOW_HIGH = Addres  ;
	EEDR_REG       = Data    ;

	Set_Bit( EECR_REG , EECR_REG_EEMWE ) ; //MASTER WRIT ENABLE
	Set_Bit( EECR_REG , EECR_REG_EEWE  ) ; // WRITE ENABLE

}

