#ifndef _EXTI_REGISTER_H
#define _EXTI_REGISTER_H

#define MCUCR_Register  *((volatile u8*)0x55)
#define MCUCSR_Register  *((volatile u8*)0x54)
#define GICR_Register  *((volatile u8*)0x5B)
#define GIFR_Register  *((volatile u8*)0x5B)

#endif