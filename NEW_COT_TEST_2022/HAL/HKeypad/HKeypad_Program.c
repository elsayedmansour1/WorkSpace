#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "../../MCAL/MDIO/MDIO_Config.h"
#include "../../MCAL/MDIO/MDIO_Private.h"
#include <avr/delay.h>

#include "HKeypad_Interface.h"



void HKEYPAD_VidInit(void)
{
	/*we will set the first 4-pins as output by set 1 in direction*/
	 /*and set the second 4-pins as input by set 0 in direction*/
	MDIO_u8SetPortDirection ( DIO_Keypad,0b00001111);
	/*the 4 input pins we will activate pull up resistor */
	/*the 4 output pins we will set value as 1*/
	MDIO_u8SetPortValue	( DIO_Keypad, 0b11111111);
}
u8 HKEYPAD_GET_PressedKey(void)
{   u8 keypad_array[4][4]={{ 1, 2, 3, 4},
		                   { 5, 6, 7, 8},
						   { 9,10,11,12},
						   {13,14,15,16}};
	/*Columns for output pins*/
	 /*Rows for input pins*/
	u8 col,row;
	/*keypad_out variable for Get the pressed switch*/
	u8 keypad_out=0;
	u8 copy_u8CheckPressed=1;
	for(col=0;col<4;col++)
	{
		/*we will activate only one column at time*/
			/*by change his value from 1 to 0*/
		MDIO_u8SetPinValue	( DIO_Keypad, col, 0);
		for(row=4;row<8;row++)
		{
			/*every time you change the column value */
			     /*you will check all Rows */
			/*if any Row his value changed that mean*/
				/*there is key is pressed*/
			MDIO_u8GetPinValue(DIO_Keypad,row,&copy_u8CheckPressed);
			if(copy_u8CheckPressed==0)
			{
				/*we will mapping between the pressed key*/
					/*and the value in keypad array*/
				keypad_out= keypad_array[row-4][col];
				/* if the key is still pressed you will not  */
				      /* go to for the next instruction*/

				while(copy_u8CheckPressed==0)
				{
					MDIO_u8GetPinValue(DIO_Keypad,row,&copy_u8CheckPressed);
				}


				_delay_ms(50);
			}



		}
			  /*if you check in all rows in this column*/
		/*you need to deactivate it to go to the next column*/
		MDIO_u8SetPinValue	( DIO_Keypad, col, 1);
	}
/*if there is any switch is pressed the value of keypad_out variable*/
	/*will change from 0 to the mapping value in keypad_array*/
return keypad_out;
}

