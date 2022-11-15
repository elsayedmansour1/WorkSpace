#ifndef _KEYPAD_INTERFACE_H_
#define _KEYPAD_INTERFACE_H_


#define DIO_Keypad_Columns DIO_PORTA
#define DIO_Keypad_Rows    DIO_PORTB
#define				Colum_0         PIN4
#define		        Colum_1         PIN5
#define				Colum_2         PIN6
#define				Colum_3         PIN7



#define				Row_0         PIN4
#define		        Row_1         PIN5
#define				Row_2         PIN6
#define				Row_3         PIN7





void KEYPAD_VidInit(void);

u8 KEYPAD_GET_PressedKey(void);













#endif
