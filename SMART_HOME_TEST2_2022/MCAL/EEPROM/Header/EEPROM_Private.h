/*
 * EEPROM_Private.h
 *
 *  Created on: Feb 13, 2022
 *      Author: kareem ashraf
 */

#ifndef MCAL_EEPROM_HEADER_EEPROM_PRIVATE_H_
#define MCAL_EEPROM_HEADER_EEPROM_PRIVATE_H_



/***************************ACTION_MODE*************************/
#define ISR     1
#define POLLING 2
/****************************************************************/



#define EEARH_REG       *( (volatile uint8* )0x3F)
#define EEARL_REG       *( (volatile uint8* )0x3E)
#define EEARL_LOW_HIGH  *( (volatile uint16*)0x3E)
#define EEDR_REG        *( (volatile uint8* )0x3D)



/****************************************************************/
#define EECR_REG        *( (volatile uint8*)0x3C)

    //#define  –     7
    //#define  –     6
    //#define  –     5
    //#define  –     4
    #define EECR_REG_EERIE  3
    #define EECR_REG_EEMWE  2
    #define EECR_REG_EEWE   1
    #define EECR_REG_EERE   0

/****************************************************************/
#endif /* MCAL_EEPROM_HEADER_EEPROM_PRIVATE_H_ */
