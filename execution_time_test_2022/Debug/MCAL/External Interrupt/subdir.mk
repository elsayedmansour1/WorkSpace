################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/External\ Interrupt/MEXTI_Program.c 

OBJS += \
./MCAL/External\ Interrupt/MEXTI_Program.o 

C_DEPS += \
./MCAL/External\ Interrupt/MEXTI_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/External\ Interrupt/MEXTI_Program.o: ../MCAL/External\ Interrupt/MEXTI_Program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"MCAL/External Interrupt/MEXTI_Program.d" -MT"MCAL/External\ Interrupt/MEXTI_Program.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


