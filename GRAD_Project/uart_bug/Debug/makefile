################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
uart_bug.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
uart_bug.list \

OBJCOPY_HEX += \
uart_bug.hex \

OBJCOPY_BIN += \
uart_bug.bin \

OBJCOPY_SREC += \
uart_bug.srec \


# All Target
all: uart_bug.axf secondary-outputs

# Tool invocations
uart_bug.axf: $(OBJS) $(USER_OBJS) C:\Users\Ahmed\STM32CubeIDE\workspace_1.4.0\GRAD_Project\uart_bug\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "uart_bug.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Ahmed\STM32CubeIDE\workspace_1.4.0\GRAD_Project\uart_bug\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="uart_bug.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

uart_bug.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "uart_bug.list"
	@echo 'Finished building: $@'
	@echo ' '

uart_bug.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "uart_bug.hex"
	@echo 'Finished building: $@'
	@echo ' '

uart_bug.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "uart_bug.bin"
	@echo 'Finished building: $@'
	@echo ' '

uart_bug.srec: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O srec $(EXECUTABLES) "uart_bug.srec"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN) $(OBJCOPY_SREC)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
