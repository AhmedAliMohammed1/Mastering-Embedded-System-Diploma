################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/MemMang/heap_1.c 

OBJS += \
./FreeRTOS/portable/MemMang/heap_1.o 

C_DEPS += \
./FreeRTOS/portable/MemMang/heap_1.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/MemMang/heap_1.o: ../FreeRTOS/portable/MemMang/heap_1.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/Ahmed/Desktop/EmbeddedSys/Mastering-Embedded-System-Diploma/GRAD_Project/Graduation_Project_Final/MCAL/inc" -I"C:/Users/Ahmed/Desktop/EmbeddedSys/Mastering-Embedded-System-Diploma/GRAD_Project/Graduation_Project_Final/HAL/inc" -I"C:/Users/Ahmed/Desktop/EmbeddedSys/Mastering-Embedded-System-Diploma/GRAD_Project/Graduation_Project_Final/FreeRTOS/include" -I"C:/Users/Ahmed/Desktop/EmbeddedSys/Mastering-Embedded-System-Diploma/GRAD_Project/Graduation_Project_Final/FreeRTOS/portable/ARM_CM3" -I"C:/Users/Ahmed/Desktop/EmbeddedSys/Mastering-Embedded-System-Diploma/GRAD_Project/Graduation_Project_Final/FreeRTOS/portable/MemMang" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FreeRTOS/portable/MemMang/heap_1.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

