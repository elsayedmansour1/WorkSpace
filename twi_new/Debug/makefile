################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
twi_new.lss \

FLASH_IMAGE += \
twi_new.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: twi_new.elf secondary-outputs

# Tool invocations
twi_new.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,twi_new.map -mmcu=atmega32 -o "twi_new.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

twi_new.lss: twi_new.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S twi_new.elf  >"twi_new.lss"
	@echo 'Finished building: $@'
	@echo ' '

twi_new.hex: twi_new.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex twi_new.elf  "twi_new.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: twi_new.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 twi_new.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) twi_new.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
