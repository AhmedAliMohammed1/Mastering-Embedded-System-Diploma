################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MCAL/subdir.mk
-include HALL/subdir.mk
-include FreeRTOS/portable/MemMang/subdir.mk
-include FreeRTOS/portable/ARM_CM3/subdir.mk
-include FreeRTOS/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := DR_SOLIMAN_ELNGAR
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
DR_SOLIMAN_ELNGAR.axf \

MAP_FILES += \
DR_SOLIMAN_ELNGAR.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
DR_SOLIMAN_ELNGAR.list \

OBJCOPY_HEX += \
DR_SOLIMAN_ELNGAR.hex \

OBJCOPY_BIN += \
DR_SOLIMAN_ELNGAR.bin \


# All Target
all: main-build

# Main-build Target
main-build: DR_SOLIMAN_ELNGAR.axf secondary-outputs

# Tool invocations
DR_SOLIMAN_ELNGAR.axf DR_SOLIMAN_ELNGAR.map: $(OBJS) $(USER_OBJS) C:\Users\medoo\Desktop\WorkSpace\DR_SOLIMAN_ELNGAR\STM32F103CBTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -gdwarf-2 -o "DR_SOLIMAN_ELNGAR.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\medoo\Desktop\WorkSpace\DR_SOLIMAN_ELNGAR\STM32F103CBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="DR_SOLIMAN_ELNGAR.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

DR_SOLIMAN_ELNGAR.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "DR_SOLIMAN_ELNGAR.list"
	@echo 'Finished building: $@'
	@echo ' '

DR_SOLIMAN_ELNGAR.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "DR_SOLIMAN_ELNGAR.hex"
	@echo 'Finished building: $@'
	@echo ' '

DR_SOLIMAN_ELNGAR.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "DR_SOLIMAN_ELNGAR.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) DR_SOLIMAN_ELNGAR.axf DR_SOLIMAN_ELNGAR.bin DR_SOLIMAN_ELNGAR.hex DR_SOLIMAN_ELNGAR.list DR_SOLIMAN_ELNGAR.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
