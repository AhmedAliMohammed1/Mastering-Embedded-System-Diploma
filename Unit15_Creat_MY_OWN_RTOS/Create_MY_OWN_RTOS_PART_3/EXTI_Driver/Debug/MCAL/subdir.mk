################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
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
MCAL/%.o MCAL/%.su MCAL/%.cyclo: ../MCAL/%.c MCAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/Lesson 4/EXTI_Driver/Ahmed_RTOS/inc" -I"C:/Users/medoo/Desktop/WorkSpace/Lesson 4/EXTI_Driver/CMSIS" -I"C:/Users/medoo/Desktop/WorkSpace/Lesson 4/EXTI_Driver/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/Lesson 4/EXTI_Driver/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/EXTI_Driver.cyclo ./MCAL/EXTI_Driver.d ./MCAL/EXTI_Driver.o ./MCAL/EXTI_Driver.su ./MCAL/GPIO_Driver.cyclo ./MCAL/GPIO_Driver.d ./MCAL/GPIO_Driver.o ./MCAL/GPIO_Driver.su

.PHONY: clean-MCAL

