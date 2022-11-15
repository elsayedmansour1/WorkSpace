################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/Global\ Interrupt/subdir.mk
-include MCAL/External\ Interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Key_pad/subdir.mk
-include APP/subdir.mk
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
PING_PONG.lss \

FLASH_IMAGE += \
PING_PONG.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: PING_PONG.elf secondary-outputs

# Tool invocations
PING_PONG.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,PING_PONG.map -mmcu=atmega32 -o "PING_PONG.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PING_PONG.lss: PING_PONG.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S PING_PONG.elf  >"PING_PONG.lss"
	@echo 'Finished building: $@'
	@echo ' '

PING_PONG.hex: PING_PONG.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex PING_PONG.elf  "PING_PONG.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: PING_PONG.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 PING_PONG.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) PING_PONG.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
