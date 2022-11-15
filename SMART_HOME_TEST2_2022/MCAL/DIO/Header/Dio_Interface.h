/*
 * DIO.h
 *
 *  Created on: Jan 12, 2022
 *      Author: kareem ashraf
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_




#include "../../../SERVICE/Std_Types.h"

#include <util/delay.h>

/*******************************F_CPU CONFIGERATION****************************************/
/* USER CAN CHOSSE FREQUANSY OF MICROCONTRROLER
								One_MHZ
								TWO_MHZ
								THREE_MHZ
								FOUR_MHZ
								FIVE_MHZ
								SIX_MHZ
								SEVEN_MHZ
								EIGHT_MHZ
								NINE_MHZ
								TEN_MHZ
								ELEVEN_MHZ
								TWOELVE_MHZ
								THRTYEN_MHZ
								FOURTEN_MHZ
								FIFTEN_MHZ
								SIXTEN_MHZ
*/
#define  F_CPU  SIXTEN_MHZ       //16000000 MGH


/*******************************PIN NUMBERS****************************************/
#define PIN_0  0
#define PIN_1  1
#define PIN_2  2
#define PIN_3  3
#define PIN_4  4
#define PIN_5  5
#define PIN_6  6
#define PIN_7  7


/********************************GROUP NAME ***************************************/
#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3



/********************************PIN DIRECTION*************************************/
#define INPUT  0
#define OUTPUT 1


/*******************************PIN VALUE******************************************/
#define LOW  0
#define HIGH 1
#define HIGHHIGH 2


/*******************************PULL-UP STATE*********************************************/
#define DISABLE_PULLUP 0
#define ENABLE_PULLUP  1

/******************************DECLERATION****************************************/



   /******************************************************************************************************/
   /****************************************FUNCTION OF PIN**********************************************/
   /******************************************************************************************************/

/*****This Function Shall set the direction pin ******/
void DIO_VoidSetPinDir(uint8 DIO_uint8CopyPort ,uint8 DIO_uint8CopyPin_Id , uint8 DIO_uint8CopyPinDir);

/*****This Function Shall set the Value pin ******/
void DIO_VoidSetPinValue(uint8 DIO_uint8SetPort, uint8 DIO_uint8SetPin_Id,uint8 DIO_uint8SetPinValue);

/*****This Function Shall Read the Value pin ******/
uint8 DIO_ReadPinValue(uint8 DIO_uint8ReadPort ,uint8 DIO_uint8ReadPin_Id );

/*****This Function Shall Control Pin Toggel the Value pin ******/
void DIO_VoidSetToggelValue(uint8 DIO_uint8SetPort , uint8 DIO_uint8Setpin_Id);



   /******************************************************************************************************/
   /****************************************FUNCTION OF PORT**********************************************/
   /******************************************************************************************************/

/*****This Function Shall set the ******direction****** Port ******/
void DIO_VoidSetAllPortDir(uint8 DIO_uint8CopyPort ,  uint8 DIO_uint8CopyPortDir);

/*****This Function Shall set the ******Value****** Port ******/
void DIO_VoidSetAllPortValue(uint8 DIO_uint8SetPort,uint8 DIO_uint8SetPortValue);

/*****This Function Shall ******Read the Value****** Port ******/

uint8 DIO_ReadPortValue(uint8 DIO_uint8ReadPort);





/*****This Function Shall set the direction Port ******/
void DIO_VoidSetSpecialPortDir(uint8 DIO_uint8CopyPort ,  uint8 DIO_uint8CopyPortDir);

/*****This Function Shall set the Value Port ******/
void DIO_VoidSetSpecialPortValue(uint8 DIO_uint8SetPort,uint8 DIO_uint8SetPortValue);




/*****This Function Shall Control Pin Pull Up the Value pin ******/
void DIO_VoidControlPinPullUp(uint8 DIO_uint8SetPort , uint8 DIO_uint8SetPin_Id , uint8 Dio_uint8PullUpState);


uint8 DIO_ReadSegmentOfAddress(uint8 Address ,uint8 Segment );




#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
