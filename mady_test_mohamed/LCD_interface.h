#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H





void LCD_voidWriteCommand(u8 Copy_u8command);

void LCD_voidWriteData(u8 Copy_u8Data);

void LCD_voidInit(void);

void LCD_gotoXy(u8 y,u8 x);

void LCD_VoidSendString(u8 *copy_u8Data);

void LCD_Writenumber(u32 number);


//LCD_VoidSendString("mohamed khaled");
/* void LCD_voidSendCommand(u8 Copy_u8command);
void LCD_voidInit(void);
void LCD_voidSendstring(u8 *copy_u8Data);
void LCD_voidSetPosition(u8 Copy_u8LineNum,u8 copy_u8col); */




#endif
