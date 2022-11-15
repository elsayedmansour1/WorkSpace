################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SmartHome/MCAL/TWI/subdir.mk
-include SmartHome/MCAL/TIMER/subdir.mk
-include SmartHome/MCAL/Global\ Interrupt/subdir.mk
-include SmartHome/MCAL/External\ Interrupt/subdir.mk
-include SmartHome/MCAL/DIO/subdir.mk
-include SmartHome/MCAL/ADC/subdir.mk
-include SmartHome/HAL/Servo/subdir.mk
-include SmartHome/HAL/LM35/subdir.mk
-include SmartHome/HAL/LDR/subdir.mk
-include SmartHome/HAL/LCD/subdir.mk
-include SmartHome/HAL/Key_pad/subdir.mk
-include SmartHome/HAL/EEPROM/subdir.mk
-include SmartHome/HAL/DC_Motor/subdir.mk
-include SmartHome/HAL/Buzzer/subdir.mk
-include SmartHome/Debug/MCAL/TWI/subdir.mk
-include SmartHome/Debug/MCAL/Global\ Interrupt/subdir.mk
-include SmartHome/Debug/MCAL/External\ Interrupt/subdir.mk
-include SmartHome/Debug/MCAL/DIO/subdir.mk
-include SmartHome/Debug/MCAL/ADC/subdir.mk
-include SmartHome/Debug/HAL/LCD/subdir.mk
-include SmartHome/Debug/HAL/Key_pad/subdir.mk
-include SmartHome/Debug/HAL/EEPROM/subdir.mk
-include SmartHome/Debug/APP/subdir.mk
-include SmartHome/APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SmartHome.lss \

FLASH_IMAGE += \
SmartHome.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SmartHome.elf secondary-outputs

# Tool invocations
SmartHome.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SmartHome.map -mmcu=atmega32 -o "SmartHome.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SmartHome.lss: SmartHome.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SmartHome.elf  >"SmartHome.lss"
	@echo 'Finished building: $@'
	@echo ' '

SmartHome.hex: SmartHome.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SmartHome.elf  "SmartHome.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SmartHome.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SmartHome.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SmartHome.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
