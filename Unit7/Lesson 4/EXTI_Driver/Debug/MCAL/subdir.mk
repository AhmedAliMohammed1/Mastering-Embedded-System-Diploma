################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTI_Driver.c \
../MCAL/GPIO_Driver.c 

OBJS += \
./MCAL/EXTI_Driver.o \
./MCAL/GPIO_Driver.o 

C_DEPS += \
./MCAL/EXTI_Driver.d \
./MCAL/GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXTI_Driver.o: ../MCAL/EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/EXTI_Driver/MCAL/inc" -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/EXTI_Driver/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/GPIO_Driver.o: ../MCAL/GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/EXTI_Driver/MCAL/inc" -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/EXTI_Driver/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

