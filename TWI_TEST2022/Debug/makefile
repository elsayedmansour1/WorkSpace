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
TWI_TEST2022.lss \

FLASH_IMAGE += \
TWI_TEST2022.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TWI_TEST2022.elf secondary-outputs

# Tool invocations
TWI_TEST2022.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TWI_TEST2022.map -mmcu=atmega32 -o "TWI_TEST2022.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TWI_TEST2022.lss: TWI_TEST2022.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TWI_TEST2022.elf  >"TWI_TEST2022.lss"
	@echo 'Finished building: $@'
	@echo ' '

TWI_TEST2022.hex: TWI_TEST2022.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TWI_TEST2022.elf  "TWI_TEST2022.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TWI_TEST2022.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t TWI_TEST2022.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TWI_TEST2022.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
