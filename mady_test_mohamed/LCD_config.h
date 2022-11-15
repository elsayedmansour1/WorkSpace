#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H


#define LCD_u8LINE1        0
#define LCD_u8LINE2        1
#define LCD_Data_PORT  PORTC
#define RS             PORTD,PIN0
#define RW             PORTD,PIN1
#define Enable         PORTD,PIN2



#define Function_Set       0b00111000
#define DIS_ON_OFF         0b00001100
#define CLR_LCD            0b00000001
#define Intry_Mode         0b00000110


#endif
