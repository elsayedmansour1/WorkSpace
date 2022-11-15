/*
 * Math.h
 *
 *  Created on: Aug 23, 2019
 *      Author: adel1
 */

#ifndef MATH_H_
#define MATH_H_

#define Toggle_BIT(var,bitNo) (var ^= (1<<bitNo)) // this macro for toggling specific bit
#define SET_BIT(var,bitNo) var |= (1<<bitNo)    // this macro for putting one in specific bit
#define CLR(var,bitNo) var &= (~(1<<bitNo))		// this macro for putting zero in specific bit
#define Read_BIT(var,bitNo) (var & (1<<bitNo))	// this macro for reading specific bit

#endif /* MATH_H_ */
