/*
 * DIO_PROG.cpp
 *
 *  Created on: Jun 11, 2022
 *      Author: Adel Khaled
 */

#include "../../LIB/MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "MDIO_REG.h"
#include "MDIO_INT.h"


DIO :: DIO(){
	//Constructor
}
void DIO :: MDIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue){
	if(Copy_u8PinValue==HIGH){
			switch(Copy_u8PortId){
				case PORTA_ID:
					SET_BIT(PORTA,Copy_u8PinId);
					break;
				case PORTB_ID:
					SET_BIT(PORTB,Copy_u8PinId);
					break;
				case PORTC_ID:
					SET_BIT(PORTC,Copy_u8PinId);
					break;
				case PORTD_ID:
					SET_BIT(PORTD,Copy_u8PinId);
					break;
				default:
					break;
			}
		}else{
			switch(Copy_u8PortId){
				case PORTA_ID:
					CLR(PORTA,Copy_u8PinId);
					break;
				case PORTB_ID:
					CLR(PORTB,Copy_u8PinId);
					break;
				case PORTC_ID:
					CLR(PORTC,Copy_u8PinId);
					break;
				case PORTD_ID:
					CLR(PORTD,Copy_u8PinId);
					break;
				default:
					break;
				}
		}
}
void DIO :: MDIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_PinStatus){
	if(Copy_PinStatus==INPUT){
		switch(Copy_u8PortId){
			case PORTA_ID:
				CLR(PORTA,Copy_u8PinId);
				break;
			case PORTB_ID:
				CLR(PORTB,Copy_u8PinId);
				break;
			case PORTC_ID:
				CLR(PORTC,Copy_u8PinId);
				break;
			case PORTD_ID:
				CLR(PORTD,Copy_u8PinId);
				break;
			default:
				break;
		}
	}else{
		switch(Copy_u8PortId){
			case PORTA_ID:
				SET_BIT(PORTA,Copy_u8PinId);
				break;
			case PORTB_ID:
				SET_BIT(PORTB,Copy_u8PinId);
				break;
			case PORTC_ID:
				SET_BIT(PORTC,Copy_u8PinId);
				break;
			case PORTD_ID:
				SET_BIT(PORTD,Copy_u8PinId);
				break;
			default:
				break;
		}
	}
}
