/*
 * main.c
 *
 *  Created on: Jun 11, 2022
 *      Author: Adel Khaled
 */
#include "../LIB/LBIT_MATH.h"
#include "../LIB/LSTD_TYPES.h"
#include "../Wrapping/WDIO/WDIO_INT.h"
#include <util/delay.h>
int main(void){

	WDIO_voidSetPinDirection(PORTB_ID, PIN1, OUTPUT);

	while(1){
		WDIO_voidSetPinValue(PORTB_ID, PIN1, HIGH);
		_delay_ms(100);
		WDIO_voidSetPinValue(PORTB_ID, PIN1, LOW);
		_delay_ms(100);
	}
return 0;
}
