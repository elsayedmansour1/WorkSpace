################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SmartHome/MCAL/TIMER/TIMER_Program.c 

OBJS += \
./SmartHome/MCAL/TIMER/TIMER_Program.o 

C_DEPS += \
./SmartHome/MCAL/TIMER/TIMER_Program.d 


# Each subdirectory must supply rules for building sources it contributes
SmartHome/MCAL/TIMER/%.o: ../SmartHome/MCAL/TIMER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

