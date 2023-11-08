################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ahmed_RTOS/Cortex_Mx_Os_Porting.c \
../Ahmed_RTOS/MY_RTOS_fifo.c \
../Ahmed_RTOS/scheduler.c 

OBJS += \
./Ahmed_RTOS/Cortex_Mx_Os_Porting.o \
./Ahmed_RTOS/MY_RTOS_fifo.o \
./Ahmed_RTOS/scheduler.o 

C_DEPS += \
./Ahmed_RTOS/Cortex_Mx_Os_Porting.d \
./Ahmed_RTOS/MY_RTOS_fifo.d \
./Ahmed_RTOS/scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
Ahmed_RTOS/%.o Ahmed_RTOS/%.su Ahmed_RTOS/%.cyclo: ../Ahmed_RTOS/%.c Ahmed_RTOS/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/Lesson 4/EXTI_Driver/Ahmed_RTOS/inc" -I"C:/Users/medoo/Desktop/WorkSpace/Lesson 4/EXTI_Driver/CMSIS" -I"C:/Users/medoo/Desktop/WorkSpace/Lesson 4/EXTI_Driver/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/Lesson 4/EXTI_Driver/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Ahmed_RTOS

clean-Ahmed_RTOS:
	-$(RM) ./Ahmed_RTOS/Cortex_Mx_Os_Porting.cyclo ./Ahmed_RTOS/Cortex_Mx_Os_Porting.d ./Ahmed_RTOS/Cortex_Mx_Os_Porting.o ./Ahmed_RTOS/Cortex_Mx_Os_Porting.su ./Ahmed_RTOS/MY_RTOS_fifo.cyclo ./Ahmed_RTOS/MY_RTOS_fifo.d ./Ahmed_RTOS/MY_RTOS_fifo.o ./Ahmed_RTOS/MY_RTOS_fifo.su ./Ahmed_RTOS/scheduler.cyclo ./Ahmed_RTOS/scheduler.d ./Ahmed_RTOS/scheduler.o ./Ahmed_RTOS/scheduler.su

.PHONY: clean-Ahmed_RTOS

