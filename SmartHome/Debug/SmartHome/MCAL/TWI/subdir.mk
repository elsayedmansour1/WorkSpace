################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SmartHome/MCAL/TWI/TWI_program.c 

OBJS += \
./SmartHome/MCAL/TWI/TWI_program.o 

C_DEPS += \
./SmartHome/MCAL/TWI/TWI_program.d 


# Each subdirectory must supply rules for building sources it contributes
SmartHome/MCAL/TWI/%.o: ../SmartHome/MCAL/TWI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


