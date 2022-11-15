################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SmartHome/MCAL/External\ Interrupt/EX_INT_Prog.c 

OBJS += \
./SmartHome/MCAL/External\ Interrupt/EX_INT_Prog.o 

C_DEPS += \
./SmartHome/MCAL/External\ Interrupt/EX_INT_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
SmartHome/MCAL/External\ Interrupt/EX_INT_Prog.o: ../SmartHome/MCAL/External\ Interrupt/EX_INT_Prog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"SmartHome/MCAL/External Interrupt/EX_INT_Prog.d" -MT"SmartHome/MCAL/External\ Interrupt/EX_INT_Prog.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


