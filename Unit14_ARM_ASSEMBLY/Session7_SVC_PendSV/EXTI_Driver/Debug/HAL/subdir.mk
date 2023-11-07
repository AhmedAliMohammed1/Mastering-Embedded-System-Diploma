################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEYPAD.c \
../HAL/LCD.c 

OBJS += \
./HAL/KEYPAD.o \
./HAL/LCD.o 

C_DEPS += \
./HAL/KEYPAD.d \
./HAL/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o HAL/%.su HAL/%.cyclo: ../HAL/%.c HAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/Lesson 4/EXTI_Driver/CMSIS" -I"C:/Users/medoo/Desktop/WorkSpace/Lesson 4/EXTI_Driver/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/Lesson 4/EXTI_Driver/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL

clean-HAL:
	-$(RM) ./HAL/KEYPAD.cyclo ./HAL/KEYPAD.d ./HAL/KEYPAD.o ./HAL/KEYPAD.su ./HAL/LCD.cyclo ./HAL/LCD.d ./HAL/LCD.o ./HAL/LCD.su

.PHONY: clean-HAL

