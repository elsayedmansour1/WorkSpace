################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SmartHome/HAL/DC_Motor/DC_Motor.c 

OBJS += \
./SmartHome/HAL/DC_Motor/DC_Motor.o 

C_DEPS += \
./SmartHome/HAL/DC_Motor/DC_Motor.d 


# Each subdirectory must supply rules for building sources it contributes
SmartHome/HAL/DC_Motor/%.o: ../SmartHome/HAL/DC_Motor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


