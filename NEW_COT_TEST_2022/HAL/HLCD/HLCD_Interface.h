/*
 * LCD_Interface.h
 *
 *  Created on: Aug 21, 2020
 *      Author: ELSAYED
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define HCLCD_FUNCTION_SET 	0b00101000
#define	HCLCD_DISPLAY_ON_OFF  0b00001100
#define DISPLAY_CLEAR			0b00000001
#define HCLCD_ENTRY_MODE_SET	0b00000110

/* LCD data length MODE select */
#define MODE 8

/* LCD HW Pins */
#define RS DIO_u8_PIN0
#define RW DIO_u8_PIN1
#define EN DIO_u8_PIN2
#define LCD_CTRL_PORT DIO_u8_PORTB

/*LCD DATA PINS*/
#define D4 DIO_u8_PIN4
#define D5 DIO_u8_PIN5
#define D6 DIO_u8_PIN6
#define D7 DIO_u8_PIN7
#define LCD_DATA_PORT DIO_u8_PORTD
/*LCD LINE NUMBER*/
#define LCD_u8_LINE0	0
#define LCD_u8_LINE1	1

 /* functions  */
void LCD_VidPulseEnable(void);

void HLCD_VidInit(void);

void HLCD_VidWriteCommend(u8 LOC_u8command);

void HLCD_VoidClearDisplay(void);
void HLCD_DisplayCharacter(u8 Copy_u8Data);
void HLCD_DisplayString(u8* PCopy_u8String);
void HLCD_VidWriteNumber(u32 LOC_u32num);
void HLCD_SetPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber);
#endif /* LCD_INTERFACE_H_ */
