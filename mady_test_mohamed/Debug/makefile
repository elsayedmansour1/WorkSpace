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
mady_test_mohamed.lss \

FLASH_IMAGE += \
mady_test_mohamed.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: mady_test_mohamed.elf secondary-outputs

# Tool invocations
mady_test_mohamed.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,mady_test_mohamed.map -mmcu=atmega32 -o "mady_test_mohamed.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

mady_test_mohamed.lss: mady_test_mohamed.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S mady_test_mohamed.elf  >"mady_test_mohamed.lss"
	@echo 'Finished building: $@'
	@echo ' '

mady_test_mohamed.hex: mady_test_mohamed.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex mady_test_mohamed.elf  "mady_test_mohamed.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: mady_test_mohamed.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 mady_test_mohamed.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) mady_test_mohamed.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
