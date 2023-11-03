################################################################################
# Automatically-generated file. Do not edit!
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
HAL/KEYPAD.o: ../HAL/KEYPAD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/EXTI_Driver/MCAL/inc" -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/EXTI_Driver/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KEYPAD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/EXTI_Driver/MCAL/inc" -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/EXTI_Driver/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

