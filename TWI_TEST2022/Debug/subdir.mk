################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../EEPROM_Program.c \
../LCD_Program.c \
../TWI_Program.c \
../main.c 

OBJS += \
./DIO_Program.o \
./EEPROM_Program.o \
./LCD_Program.o \
./TWI_Program.o \
./main.o 

C_DEPS += \
./DIO_Program.d \
./EEPROM_Program.d \
./LCD_Program.d \
./TWI_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


