#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H

#define SPI_u8_MASTER_MODE                     0
#define SPI_u8_SLAVE_MODE                      1

#define SPDR                *((volatile u8*)0x2F)
#define SPSR                *((volatile u8*)0x2E)
#define SPCR                *((volatile u8*)0x2D)



#endif