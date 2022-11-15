#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

#define  ISC2  6
#define  ISC11 3
#define  ISC10 2
#define  ISC01 1
#define  ISC00 0

#define  INT0 6
#define  INT1 7
#define  INT2 5

void EXTI1_init(void);
void EXTI0_init(void);
void EXTI2_init(void);

void EXTI1_enable(void);
void EXTI0_enable(void);
void EXTI2_enable(void);

void EXTI1_disable(void);
void EXTI0_disable(void);
void EXTI2_disable(void);

void EXTI1_Callback(void (*ptr)(void));
void EXTI0_Callback(void (*ptr)(void));
void EXTI2_Callback(void (*ptr)(void));



#endif
